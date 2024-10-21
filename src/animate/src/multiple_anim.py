#!/usr/bin/env python

import rospy
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

L1 = 0.675 * 2  # Length of Link 1
L2 = 0.675 * 2  # Length of Link 2
L3 = 0.467      # Length of Link 3

def inverse_kinematics_with_orientation(x, y, phi):
    x_wrist = x - L3 * np.cos(phi)
    y_wrist = y - L3 * np.sin(phi)

    D = (x_wrist**2 + y_wrist**2 - L1**2 - L2**2) / (2 * L1 * L2)

    if abs(D) > 1:
        raise ValueError("Target is outside of the reachable workspace.")

    q2 = np.arctan2(np.sqrt(1 - D**2), D)  # Elbow-up solution
    q1 = np.arctan2(y_wrist, x_wrist) - np.arctan2(L2 * np.sin(q2), L1 + L2 * np.cos(q2))
    q3 = phi - q1 - q2

    return q1, q2, q3

def cubic_polynomial(q0, qf, v0, vf, t0, tf, t):
    M = np.array([[1, t0, t0**2, t0**3],
                  [0, 1, 2*t0, 3*t0**2],
                  [1, tf, tf**2, tf**3],
                  [0, 1, 2*tf, 3*tf**2]])
    
    b = np.array([q0, v0, qf, vf])
    a = np.linalg.solve(M, b)
    return a[0] + a[1]*t + a[2]*t**2 + a[3]*t**3

def forward_kinematics(q1, q2, q3):
    x = (L1 * np.cos(q1) +
         L2 * np.cos(q1 + q2) +
         L3 * np.cos(q1 + q2 + q3))
    y = (L1 * np.sin(q1) +
         L2 * np.sin(q1 + q2) +
         L3 * np.sin(q1 + q2 + q3))
    return x, y

def generate_trajectory(via_points, time_intervals):
    joint_trajectory = []
    for i in range(len(via_points) - 1):
        q0 = via_points[i]
        qf = via_points[i + 1]
        t0 = sum(time_intervals[:i])
        tf = t0 + time_intervals[i]

        for t in np.linspace(t0, tf, 50):
            q1 = cubic_polynomial(q0[0], qf[0], 0, 0, t0, tf, t)
            q2 = cubic_polynomial(q0[1], qf[1], 0, 0, t0, tf, t)
            q3 = cubic_polynomial(q0[2], qf[2], 0, 0, t0, tf, t)
            joint_trajectory.append((q1, q2, q3))

    return joint_trajectory

def animate(i, trajectory, line1, line2, line3, end_effector, traj_line, x_trajectory, y_trajectory):
    q1, q2, q3 = trajectory[i]

    x0, y0 = 0, 0
    x1, y1 = L1 * np.cos(q1), L1 * np.sin(q1)
    x2, y2 = x1 + L2 * np.cos(q1 + q2), y1 + L2 * np.sin(q1 + q2)
    x3, y3 = x2 + L3 * np.cos(q1 + q2 + q3), y2 + L3 * np.sin(q1 + q2 + q3)

    line1.set_data([x0, x1], [y0, y1])
    line2.set_data([x1, x2], [y1, y2])
    line3.set_data([x2, x3], [y2, y3])
    end_effector.set_data(x3, y3)

    x_trajectory.append(x3)
    y_trajectory.append(y3)
    traj_line.set_data(x_trajectory, y_trajectory)

    return line1, line2, line3, end_effector, traj_line

def run_animation():
    #via points in Cartesian space
    via_points_cartesian = [
        (2.5, 0.5, np.pi/4),
        (2, 1.5, np.pi/6),
        (1.5, 2.5, np.pi/3),
        (0.5, 2, np.pi/2),
        (-0.5, 2.5, np.pi/2)
    ]

    #time intervals between each via point
    time_intervals = [3, 3, 3, 3]

    via_points = []
    for point in via_points_cartesian:
        x, y, phi = point[0], point[1], point[2]
        try:
            q1, q2, q3 = inverse_kinematics_with_orientation(x, y, phi)
            via_points.append((q1, q2, q3))
        except ValueError as e:
            rospy.logerr(f"Error: Point ({x}, {y}) is outside of the reachable workspace: {e}")

    joint_trajectory = generate_trajectory(via_points, time_intervals)

    fig, ax = plt.subplots()
    ax.set_xlim(-2, 4)
    ax.set_ylim(-2, 4)
    ax.set_aspect('equal')
    ax.grid(True)

    for x, y, _ in via_points_cartesian:
        ax.plot(x, y, 'ko', label='Via Point', markersize=8)

    line1, = ax.plot([], [], 'ro-', lw=2, label='Link 1')
    line2, = ax.plot([], [], 'go-', lw=2, label='Link 2')
    line3, = ax.plot([], [], 'bo-', lw=2, label='Link 3')
    end_effector, = ax.plot([], [], 'mo', label='End Effector', markersize=8)
    traj_line, = ax.plot([], [], 'c--', lw=1, label='Trajectory')

    x_trajectory, y_trajectory = [], []

    anim = FuncAnimation(fig, animate, frames=len(joint_trajectory),
                         fargs=(joint_trajectory, line1, line2, line3, end_effector, traj_line, x_trajectory, y_trajectory),
                         interval=100, blit=True, repeat = False)

    plt.legend()
    plt.show()

def main():
    rospy.init_node('animation_node')
    rospy.loginfo("Starting the animation node")
    run_animation()

if __name__ == '__main__':
    main()


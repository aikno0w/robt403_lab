import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


L1 = 0.675 * 2  
L2 = 0.675 * 2  
L3 = 0.467  

def inverse_kinematics_with_orientation(x, y, phi):
    
    x_wrist = x - L3 * np.cos(phi)
    y_wrist = y - L3 * np.sin(phi)

    D = (x_wrist**2 + y_wrist**2 - L1**2 - L2**2) / (2 * L1 * L2)

    if abs(D) > 1:
        raise ValueError("Target is outside of the reachable workspace.")
    q2 = np.arctan2(np.sqrt(1 - D**2), D)
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

def plot_manipulator_with_orientation(q1, q2, q3, ax):
    x0, y0 = 0, 0
    x1, y1 = L1 * np.cos(q1), L1 * np.sin(q1)
    x2, y2 = x1 + L2 * np.cos(q1 + q2), y1 + L2 * np.sin(q1 + q2)
    x3, y3 = x2 + L3 * np.cos(q1 + q2 + q3), y2 + L3 * np.sin(q1 + q2 + q3)

    ax.plot([x0, x1], [y0, y1], 'ro-', label='Link 1' if len(ax.lines) == 0 else "")
    ax.plot([x1, x2], [y1, y2], 'go-', label='Link 2' if len(ax.lines) == 0 else "")
    ax.plot([x2, x3], [y2, y3], 'bo-', label='Link 3' if len(ax.lines) == 0 else "")
    ax.plot(x3, y3, 'mo', label='End Effector' if len(ax.lines) == 0 else "")

    return x3, y3 

def animate_trajectory(target_cartesian, time_interval):
   
    fig, ax = plt.subplots(figsize=(8, 8))
    ax.set_title('Manipulator Trajectory to Target Pose')
    ax.set_xlabel('X Position')
    ax.set_ylabel('Y Position')
    ax.grid(True)
    ax.set_aspect('equal')

    trajectory_x, trajectory_y = [], []

    x_target, y_target, phi_target = target_cartesian
    try:
        q_target = inverse_kinematics_with_orientation(x_target, y_target, phi_target)
    except ValueError as e:
        print(f"Error: Target pose ({x_target}, {y_target}) is outside the workspace: {e}")
        return

    q_init = (0, 0, 0)

    def update(frame):
        ax.clear()
        ax.grid(True)
        ax.set_aspect('equal')
        ax.set_title('Manipulator Trajectory to Target Pose')
        ax.set_xlabel('X Position')
        ax.set_ylabel('Y Position')

        t0, tf = 0, time_interval
        t = np.linspace(t0, tf, 100)[frame]

        q1 = cubic_polynomial(q_init[0], q_target[0], 0, 0, t0, tf, t)
        q2 = cubic_polynomial(q_init[1], q_target[1], 0, 0, t0, tf, t)
        q3 = cubic_polynomial(q_init[2], q_target[2], 0, 0, t0, tf, t)

        x3, y3 = plot_manipulator_with_orientation(q1, q2, q3, ax)
        trajectory_x.append(x3)
        trajectory_y.append(y3)
        ax.plot(trajectory_x, trajectory_y, 'b-', label='Path')
        ax.plot(x_target, y_target, 'ro', label='Target Pose')
        ax.legend()

    ani = FuncAnimation(fig, update, frames=100, repeat=False)
    plt.show()

if __name__ == '__main__':
    target_cartesian = (1, 2.5, np.pi/4)

    time_interval = 5 
    animate_trajectory(target_cartesian, time_interval)


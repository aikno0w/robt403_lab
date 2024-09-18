// Generated by gencpp from file robot_control/fsrInput.msg
// DO NOT EDIT!


#ifndef ROBOT_CONTROL_MESSAGE_FSRINPUT_H
#define ROBOT_CONTROL_MESSAGE_FSRINPUT_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace robot_control
{
template <class ContainerAllocator>
struct fsrInput_
{
  typedef fsrInput_<ContainerAllocator> Type;

  fsrInput_()
    : header()
    , i0(0.0)  {
    }
  fsrInput_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , i0(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef float _i0_type;
  _i0_type i0;





  typedef boost::shared_ptr< ::robot_control::fsrInput_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_control::fsrInput_<ContainerAllocator> const> ConstPtr;

}; // struct fsrInput_

typedef ::robot_control::fsrInput_<std::allocator<void> > fsrInput;

typedef boost::shared_ptr< ::robot_control::fsrInput > fsrInputPtr;
typedef boost::shared_ptr< ::robot_control::fsrInput const> fsrInputConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_control::fsrInput_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_control::fsrInput_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robot_control::fsrInput_<ContainerAllocator1> & lhs, const ::robot_control::fsrInput_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.i0 == rhs.i0;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robot_control::fsrInput_<ContainerAllocator1> & lhs, const ::robot_control::fsrInput_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robot_control

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::robot_control::fsrInput_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_control::fsrInput_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_control::fsrInput_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_control::fsrInput_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_control::fsrInput_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_control::fsrInput_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_control::fsrInput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1db789e6c32ded981786123f2972369c";
  }

  static const char* value(const ::robot_control::fsrInput_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1db789e6c32ded98ULL;
  static const uint64_t static_value2 = 0x1786123f2972369cULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_control::fsrInput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_control/fsrInput";
  }

  static const char* value(const ::robot_control::fsrInput_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_control::fsrInput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"float32 i0\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::robot_control::fsrInput_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_control::fsrInput_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.i0);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct fsrInput_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_control::fsrInput_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_control::fsrInput_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "i0: ";
    Printer<float>::stream(s, indent + "  ", v.i0);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_CONTROL_MESSAGE_FSRINPUT_H

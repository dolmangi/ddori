// Generated by gencpp from file ddori/servo_control.msg
// DO NOT EDIT!


#ifndef DDORI_MESSAGE_SERVO_CONTROL_H
#define DDORI_MESSAGE_SERVO_CONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ddori
{
template <class ContainerAllocator>
struct servo_control_
{
  typedef servo_control_<ContainerAllocator> Type;

  servo_control_()
    : no(0)
    , pos(0)  {
    }
  servo_control_(const ContainerAllocator& _alloc)
    : no(0)
    , pos(0)  {
    }



   typedef int8_t _no_type;
  _no_type no;

   typedef int8_t _pos_type;
  _pos_type pos;




  typedef boost::shared_ptr< ::ddori::servo_control_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ddori::servo_control_<ContainerAllocator> const> ConstPtr;

}; // struct servo_control_

typedef ::ddori::servo_control_<std::allocator<void> > servo_control;

typedef boost::shared_ptr< ::ddori::servo_control > servo_controlPtr;
typedef boost::shared_ptr< ::ddori::servo_control const> servo_controlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ddori::servo_control_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ddori::servo_control_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ddori

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'ddori': ['/home/dolmangi/catkin_ws/src/ddori/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ddori::servo_control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ddori::servo_control_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ddori::servo_control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ddori::servo_control_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ddori::servo_control_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ddori::servo_control_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ddori::servo_control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4114c64d431d2563f07d4a38968e12ce";
  }

  static const char* value(const ::ddori::servo_control_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4114c64d431d2563ULL;
  static const uint64_t static_value2 = 0xf07d4a38968e12ceULL;
};

template<class ContainerAllocator>
struct DataType< ::ddori::servo_control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ddori/servo_control";
  }

  static const char* value(const ::ddori::servo_control_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ddori::servo_control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
int8  no\n\
int8  pos\n\
";
  }

  static const char* value(const ::ddori::servo_control_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ddori::servo_control_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.no);
      stream.next(m.pos);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct servo_control_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ddori::servo_control_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ddori::servo_control_<ContainerAllocator>& v)
  {
    s << indent << "no: ";
    Printer<int8_t>::stream(s, indent + "  ", v.no);
    s << indent << "pos: ";
    Printer<int8_t>::stream(s, indent + "  ", v.pos);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DDORI_MESSAGE_SERVO_CONTROL_H
// Generated by gencpp from file ddori/ddori_sensor.msg
// DO NOT EDIT!


#ifndef DDORI_MESSAGE_DDORI_SENSOR_H
#define DDORI_MESSAGE_DDORI_SENSOR_H


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
struct ddori_sensor_
{
  typedef ddori_sensor_<ContainerAllocator> Type;

  ddori_sensor_()
    : time_stamp(0)
    , bumper(0)
    , left_currentSpeed(0)
    , right_currentSpeed(0)
    , left_encoder(0)
    , right_encoder(0)
    , left_pwm(0)
    , right_pwm(0)
    , buttons(0)
    , charger(0)
    , voltage(0)
    , current(0)
    , temp1(0)
    , temp2(0)
    , temp3(0)
    , co(0)
    , gas(0)
    , air(0)
    , barometer(0)
    , pir(0)
    , prx_1(0)
    , prx_2(0)
    , prx_3(0)
    , als(0)  {
    }
  ddori_sensor_(const ContainerAllocator& _alloc)
    : time_stamp(0)
    , bumper(0)
    , left_currentSpeed(0)
    , right_currentSpeed(0)
    , left_encoder(0)
    , right_encoder(0)
    , left_pwm(0)
    , right_pwm(0)
    , buttons(0)
    , charger(0)
    , voltage(0)
    , current(0)
    , temp1(0)
    , temp2(0)
    , temp3(0)
    , co(0)
    , gas(0)
    , air(0)
    , barometer(0)
    , pir(0)
    , prx_1(0)
    , prx_2(0)
    , prx_3(0)
    , als(0)  {
    }



   typedef uint16_t _time_stamp_type;
  _time_stamp_type time_stamp;

   typedef uint8_t _bumper_type;
  _bumper_type bumper;

   typedef int16_t _left_currentSpeed_type;
  _left_currentSpeed_type left_currentSpeed;

   typedef int16_t _right_currentSpeed_type;
  _right_currentSpeed_type right_currentSpeed;

   typedef int16_t _left_encoder_type;
  _left_encoder_type left_encoder;

   typedef int16_t _right_encoder_type;
  _right_encoder_type right_encoder;

   typedef int8_t _left_pwm_type;
  _left_pwm_type left_pwm;

   typedef int8_t _right_pwm_type;
  _right_pwm_type right_pwm;

   typedef uint8_t _buttons_type;
  _buttons_type buttons;

   typedef uint8_t _charger_type;
  _charger_type charger;

   typedef int16_t _voltage_type;
  _voltage_type voltage;

   typedef int16_t _current_type;
  _current_type current;

   typedef int16_t _temp1_type;
  _temp1_type temp1;

   typedef int16_t _temp2_type;
  _temp2_type temp2;

   typedef int16_t _temp3_type;
  _temp3_type temp3;

   typedef int16_t _co_type;
  _co_type co;

   typedef int16_t _gas_type;
  _gas_type gas;

   typedef int16_t _air_type;
  _air_type air;

   typedef int16_t _barometer_type;
  _barometer_type barometer;

   typedef int8_t _pir_type;
  _pir_type pir;

   typedef int8_t _prx_1_type;
  _prx_1_type prx_1;

   typedef int8_t _prx_2_type;
  _prx_2_type prx_2;

   typedef int8_t _prx_3_type;
  _prx_3_type prx_3;

   typedef int16_t _als_type;
  _als_type als;




  typedef boost::shared_ptr< ::ddori::ddori_sensor_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ddori::ddori_sensor_<ContainerAllocator> const> ConstPtr;

}; // struct ddori_sensor_

typedef ::ddori::ddori_sensor_<std::allocator<void> > ddori_sensor;

typedef boost::shared_ptr< ::ddori::ddori_sensor > ddori_sensorPtr;
typedef boost::shared_ptr< ::ddori::ddori_sensor const> ddori_sensorConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ddori::ddori_sensor_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ddori::ddori_sensor_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ddori::ddori_sensor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ddori::ddori_sensor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ddori::ddori_sensor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ddori::ddori_sensor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ddori::ddori_sensor_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ddori::ddori_sensor_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ddori::ddori_sensor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2a2e66d6238d872ec6adc450437b5561";
  }

  static const char* value(const ::ddori::ddori_sensor_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2a2e66d6238d872eULL;
  static const uint64_t static_value2 = 0xc6adc450437b5561ULL;
};

template<class ContainerAllocator>
struct DataType< ::ddori::ddori_sensor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ddori/ddori_sensor";
  }

  static const char* value(const ::ddori::ddori_sensor_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ddori::ddori_sensor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
uint16 time_stamp      # milliseconds starting when turning on Kobuki (max. 65536, then starts from 0 again)\n\
uint8  bumper          	# see bumper states\n\
int16 left_currentSpeed\n\
int16 right_currentSpeed\n\
#int16 left_move\n\
#int16 right_move\n\
int16 left_encoder    # accumulated ticks left wheel starting with turning on Kobuki (max. 32767)\n\
int16 right_encoder   # accumulated ticks right wheel starting with turning on Kobuki (max. 32767)\n\
int8   left_pwm        	# % of applied maximum voltage left wheel: -100 (max. voltage backward) to +100 (max. voltage forward)\n\
int8   right_pwm       # % of applied maximum voltage right wheel: -100 (max. voltage backward) to +100 (max. voltage forward)\n\
uint8  buttons         # see button states\n\
uint8  charger         # see charger states\n\
int16  voltage         # Battery voltage \n\
int16  current         # Load currnet(Power consumption)\n\
\n\
int16 temp1 			#Temperature Sensor 1\n\
int16 temp2			#Temperature Sensor 1\n\
int16 temp3			#Temperature Sensor 1\n\
\n\
int16 co				#CO gas sensor\n\
int16 gas				#Butan Gas Sensor\n\
int16 air				#Air Quality Sensor\n\
\n\
int16 barometer	#Air Pressure Sensor\n\
\n\
int8 pir					#Human body detector\n\
\n\
int8 prx_1				#proximity sensor\n\
int8 prx_2				#proximity sensor\n\
int8 prx_3				#proximity sensor\n\
\n\
int16 als				#Ambient Light Sensor\n\
\n\
\n\
#uint8  wheel_drop      # see wheel drop sensor states\n\
#uint8  cliff           # see cliff sensor states\n\
";
  }

  static const char* value(const ::ddori::ddori_sensor_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ddori::ddori_sensor_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time_stamp);
      stream.next(m.bumper);
      stream.next(m.left_currentSpeed);
      stream.next(m.right_currentSpeed);
      stream.next(m.left_encoder);
      stream.next(m.right_encoder);
      stream.next(m.left_pwm);
      stream.next(m.right_pwm);
      stream.next(m.buttons);
      stream.next(m.charger);
      stream.next(m.voltage);
      stream.next(m.current);
      stream.next(m.temp1);
      stream.next(m.temp2);
      stream.next(m.temp3);
      stream.next(m.co);
      stream.next(m.gas);
      stream.next(m.air);
      stream.next(m.barometer);
      stream.next(m.pir);
      stream.next(m.prx_1);
      stream.next(m.prx_2);
      stream.next(m.prx_3);
      stream.next(m.als);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ddori_sensor_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ddori::ddori_sensor_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ddori::ddori_sensor_<ContainerAllocator>& v)
  {
    s << indent << "time_stamp: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.time_stamp);
    s << indent << "bumper: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.bumper);
    s << indent << "left_currentSpeed: ";
    Printer<int16_t>::stream(s, indent + "  ", v.left_currentSpeed);
    s << indent << "right_currentSpeed: ";
    Printer<int16_t>::stream(s, indent + "  ", v.right_currentSpeed);
    s << indent << "left_encoder: ";
    Printer<int16_t>::stream(s, indent + "  ", v.left_encoder);
    s << indent << "right_encoder: ";
    Printer<int16_t>::stream(s, indent + "  ", v.right_encoder);
    s << indent << "left_pwm: ";
    Printer<int8_t>::stream(s, indent + "  ", v.left_pwm);
    s << indent << "right_pwm: ";
    Printer<int8_t>::stream(s, indent + "  ", v.right_pwm);
    s << indent << "buttons: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.buttons);
    s << indent << "charger: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.charger);
    s << indent << "voltage: ";
    Printer<int16_t>::stream(s, indent + "  ", v.voltage);
    s << indent << "current: ";
    Printer<int16_t>::stream(s, indent + "  ", v.current);
    s << indent << "temp1: ";
    Printer<int16_t>::stream(s, indent + "  ", v.temp1);
    s << indent << "temp2: ";
    Printer<int16_t>::stream(s, indent + "  ", v.temp2);
    s << indent << "temp3: ";
    Printer<int16_t>::stream(s, indent + "  ", v.temp3);
    s << indent << "co: ";
    Printer<int16_t>::stream(s, indent + "  ", v.co);
    s << indent << "gas: ";
    Printer<int16_t>::stream(s, indent + "  ", v.gas);
    s << indent << "air: ";
    Printer<int16_t>::stream(s, indent + "  ", v.air);
    s << indent << "barometer: ";
    Printer<int16_t>::stream(s, indent + "  ", v.barometer);
    s << indent << "pir: ";
    Printer<int8_t>::stream(s, indent + "  ", v.pir);
    s << indent << "prx_1: ";
    Printer<int8_t>::stream(s, indent + "  ", v.prx_1);
    s << indent << "prx_2: ";
    Printer<int8_t>::stream(s, indent + "  ", v.prx_2);
    s << indent << "prx_3: ";
    Printer<int8_t>::stream(s, indent + "  ", v.prx_3);
    s << indent << "als: ";
    Printer<int16_t>::stream(s, indent + "  ", v.als);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DDORI_MESSAGE_DDORI_SENSOR_H

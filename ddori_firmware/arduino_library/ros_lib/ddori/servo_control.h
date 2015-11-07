#ifndef _ROS_ddori_servo_control_h
#define _ROS_ddori_servo_control_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ddori
{

  class servo_control : public ros::Msg
  {
    public:
      int8_t no;
      int8_t pos;

    servo_control():
      no(0),
      pos(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_no;
      u_no.real = this->no;
      *(outbuffer + offset + 0) = (u_no.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->no);
      union {
        int8_t real;
        uint8_t base;
      } u_pos;
      u_pos.real = this->pos;
      *(outbuffer + offset + 0) = (u_pos.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pos);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_no;
      u_no.base = 0;
      u_no.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->no = u_no.real;
      offset += sizeof(this->no);
      union {
        int8_t real;
        uint8_t base;
      } u_pos;
      u_pos.base = 0;
      u_pos.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pos = u_pos.real;
      offset += sizeof(this->pos);
     return offset;
    }

    const char * getType(){ return "ddori/servo_control"; };
    const char * getMD5(){ return "4114c64d431d2563f07d4a38968e12ce"; };

  };

}
#endif
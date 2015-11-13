#ifndef _ROS_ddori_motor_speed_h
#define _ROS_ddori_motor_speed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ddori
{

  class motor_speed : public ros::Msg
  {
    public:
      int16_t left_speed;
      int16_t right_speed;

    motor_speed():
      left_speed(0),
      right_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_speed;
      u_left_speed.real = this->left_speed;
      *(outbuffer + offset + 0) = (u_left_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_speed.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_right_speed;
      u_right_speed.real = this->right_speed;
      *(outbuffer + offset + 0) = (u_right_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_speed.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_speed;
      u_left_speed.base = 0;
      u_left_speed.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_speed.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_speed = u_left_speed.real;
      offset += sizeof(this->left_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_right_speed;
      u_right_speed.base = 0;
      u_right_speed.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_speed.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_speed = u_right_speed.real;
      offset += sizeof(this->right_speed);
     return offset;
    }

    const char * getType(){ return "ddori/motor_speed"; };
    const char * getMD5(){ return "2a2b9f3363ceb5fe214f65d78ffc689d"; };

  };

}
#endif
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
      uint8_t left_speed;
      uint8_t left_dir;
      uint8_t right_speed;
      uint8_t right_dir;

    motor_speed():
      left_speed(0),
      left_dir(0),
      right_speed(0),
      right_dir(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->left_speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_speed);
      *(outbuffer + offset + 0) = (this->left_dir >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_dir);
      *(outbuffer + offset + 0) = (this->right_speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_speed);
      *(outbuffer + offset + 0) = (this->right_dir >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_dir);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->left_speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->left_speed);
      this->left_dir =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->left_dir);
      this->right_speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->right_speed);
      this->right_dir =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->right_dir);
     return offset;
    }

    const char * getType(){ return "ddori/motor_speed"; };
    const char * getMD5(){ return "621b34f25ac94b760c1ddd9f2c38ce75"; };

  };

}
#endif
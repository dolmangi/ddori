#ifndef _ROS_ddori_msgs_display_h
#define _ROS_ddori_msgs_display_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ddori_msgs
{

  class display : public ros::Msg
  {
    public:
      const char* command;
      const char* arg1;
      uint32_t arg2;
      uint32_t arg3;

    display():
      command(""),
      arg1(""),
      arg2(0),
      arg3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_command = strlen(this->command);
      memcpy(outbuffer + offset, &length_command, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
      uint32_t length_arg1 = strlen(this->arg1);
      memcpy(outbuffer + offset, &length_arg1, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->arg1, length_arg1);
      offset += length_arg1;
      *(outbuffer + offset + 0) = (this->arg2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->arg2 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->arg2 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->arg2 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg2);
      *(outbuffer + offset + 0) = (this->arg3 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->arg3 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->arg3 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->arg3 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_command;
      memcpy(&length_command, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
      uint32_t length_arg1;
      memcpy(&length_arg1, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arg1; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arg1-1]=0;
      this->arg1 = (char *)(inbuffer + offset-1);
      offset += length_arg1;
      this->arg2 =  ((uint32_t) (*(inbuffer + offset)));
      this->arg2 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->arg2 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->arg2 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->arg2);
      this->arg3 =  ((uint32_t) (*(inbuffer + offset)));
      this->arg3 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->arg3 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->arg3 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->arg3);
     return offset;
    }

    const char * getType(){ return "ddori_msgs/display"; };
    const char * getMD5(){ return "d74adb9c8acb80302b8299c27ebc5c42"; };

  };

}
#endif
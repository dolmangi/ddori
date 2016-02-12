#ifndef _ROS_rosjava_test_msgs_TestHeader_h
#define _ROS_rosjava_test_msgs_TestHeader_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rosjava_test_msgs
{

  class TestHeader : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* caller_id;
      const char* orig_caller_id;
      int8_t auto_header;

    TestHeader():
      header(),
      caller_id(""),
      orig_caller_id(""),
      auto_header(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_caller_id = strlen(this->caller_id);
      memcpy(outbuffer + offset, &length_caller_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->caller_id, length_caller_id);
      offset += length_caller_id;
      uint32_t length_orig_caller_id = strlen(this->orig_caller_id);
      memcpy(outbuffer + offset, &length_orig_caller_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->orig_caller_id, length_orig_caller_id);
      offset += length_orig_caller_id;
      union {
        int8_t real;
        uint8_t base;
      } u_auto_header;
      u_auto_header.real = this->auto_header;
      *(outbuffer + offset + 0) = (u_auto_header.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_header);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_caller_id;
      memcpy(&length_caller_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_caller_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_caller_id-1]=0;
      this->caller_id = (char *)(inbuffer + offset-1);
      offset += length_caller_id;
      uint32_t length_orig_caller_id;
      memcpy(&length_orig_caller_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_orig_caller_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_orig_caller_id-1]=0;
      this->orig_caller_id = (char *)(inbuffer + offset-1);
      offset += length_orig_caller_id;
      union {
        int8_t real;
        uint8_t base;
      } u_auto_header;
      u_auto_header.base = 0;
      u_auto_header.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_header = u_auto_header.real;
      offset += sizeof(this->auto_header);
     return offset;
    }

    const char * getType(){ return "rosjava_test_msgs/TestHeader"; };
    const char * getMD5(){ return "4b5a00f536da2f756ba6aebcf795a967"; };

  };

}
#endif
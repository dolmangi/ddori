#ifndef _ROS_rosjava_test_msgs_TestString_h
#define _ROS_rosjava_test_msgs_TestString_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosjava_test_msgs
{

  class TestString : public ros::Msg
  {
    public:
      const char* caller_id;
      const char* orig_caller_id;
      const char* data;

    TestString():
      caller_id(""),
      orig_caller_id(""),
      data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      uint32_t length_data = strlen(this->data);
      memcpy(outbuffer + offset, &length_data, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_data);
      offset += length_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint32_t length_data;
      memcpy(&length_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data-1]=0;
      this->data = (char *)(inbuffer + offset-1);
      offset += length_data;
     return offset;
    }

    const char * getType(){ return "rosjava_test_msgs/TestString"; };
    const char * getMD5(){ return "334ff4377be93faa44ebc66d23d40fd3"; };

  };

}
#endif
#ifndef _ROS_rocon_device_msgs_HueArray_h
#define _ROS_rocon_device_msgs_HueArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_device_msgs/Hue.h"

namespace rocon_device_msgs
{

  class HueArray : public ros::Msg
  {
    public:
      uint8_t hue_list_length;
      rocon_device_msgs::Hue st_hue_list;
      rocon_device_msgs::Hue * hue_list;

    HueArray():
      hue_list_length(0), hue_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = hue_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < hue_list_length; i++){
      offset += this->hue_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t hue_list_lengthT = *(inbuffer + offset++);
      if(hue_list_lengthT > hue_list_length)
        this->hue_list = (rocon_device_msgs::Hue*)realloc(this->hue_list, hue_list_lengthT * sizeof(rocon_device_msgs::Hue));
      offset += 3;
      hue_list_length = hue_list_lengthT;
      for( uint8_t i = 0; i < hue_list_length; i++){
      offset += this->st_hue_list.deserialize(inbuffer + offset);
        memcpy( &(this->hue_list[i]), &(this->st_hue_list), sizeof(rocon_device_msgs::Hue));
      }
     return offset;
    }

    const char * getType(){ return "rocon_device_msgs/HueArray"; };
    const char * getMD5(){ return "ac7d5d01d5d83c6c14384ec4d7c8d7da"; };

  };

}
#endif
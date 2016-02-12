#ifndef _ROS_SERVICE_GetDeviceList_h
#define _ROS_SERVICE_GetDeviceList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_device_msgs/Device.h"

namespace rocon_device_msgs
{

static const char GETDEVICELIST[] = "rocon_device_msgs/GetDeviceList";

  class GetDeviceListRequest : public ros::Msg
  {
    public:

    GetDeviceListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETDEVICELIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetDeviceListResponse : public ros::Msg
  {
    public:
      uint8_t devices_length;
      rocon_device_msgs::Device st_devices;
      rocon_device_msgs::Device * devices;

    GetDeviceListResponse():
      devices_length(0), devices(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = devices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < devices_length; i++){
      offset += this->devices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t devices_lengthT = *(inbuffer + offset++);
      if(devices_lengthT > devices_length)
        this->devices = (rocon_device_msgs::Device*)realloc(this->devices, devices_lengthT * sizeof(rocon_device_msgs::Device));
      offset += 3;
      devices_length = devices_lengthT;
      for( uint8_t i = 0; i < devices_length; i++){
      offset += this->st_devices.deserialize(inbuffer + offset);
        memcpy( &(this->devices[i]), &(this->st_devices), sizeof(rocon_device_msgs::Device));
      }
     return offset;
    }

    const char * getType(){ return GETDEVICELIST; };
    const char * getMD5(){ return "47ac4241194bb5519686779949c9843b"; };

  };

  class GetDeviceList {
    public:
    typedef GetDeviceListRequest Request;
    typedef GetDeviceListResponse Response;
  };

}
#endif

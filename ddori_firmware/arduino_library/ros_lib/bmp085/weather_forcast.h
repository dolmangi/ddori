#ifndef _ROS_SERVICE_weather_forcast_h
#define _ROS_SERVICE_weather_forcast_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bmp085
{

static const char WEATHER_FORCAST[] = "bmp085/weather_forcast";

  class weather_forcastRequest : public ros::Msg
  {
    public:

    weather_forcastRequest()
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

    const char * getType(){ return WEATHER_FORCAST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class weather_forcastResponse : public ros::Msg
  {
    public:

    weather_forcastResponse()
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

    const char * getType(){ return WEATHER_FORCAST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class weather_forcast {
    public:
    typedef weather_forcastRequest Request;
    typedef weather_forcastResponse Response;
  };

}
#endif

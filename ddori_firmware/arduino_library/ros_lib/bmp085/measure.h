#ifndef _ROS_SERVICE_measure_h
#define _ROS_SERVICE_measure_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bmp085
{

static const char MEASURE[] = "bmp085/measure";

  class measureRequest : public ros::Msg
  {
    public:

    measureRequest()
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

    const char * getType(){ return MEASURE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class measureResponse : public ros::Msg
  {
    public:

    measureResponse()
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

    const char * getType(){ return MEASURE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class measure {
    public:
    typedef measureRequest Request;
    typedef measureResponse Response;
  };

}
#endif

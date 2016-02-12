#ifndef _ROS_cob_perception_msgs_PointCloud2Array_h
#define _ROS_cob_perception_msgs_PointCloud2Array_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"

namespace cob_perception_msgs
{

  class PointCloud2Array : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t segments_length;
      sensor_msgs::PointCloud2 st_segments;
      sensor_msgs::PointCloud2 * segments;

    PointCloud2Array():
      header(),
      segments_length(0), segments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = segments_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < segments_length; i++){
      offset += this->segments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t segments_lengthT = *(inbuffer + offset++);
      if(segments_lengthT > segments_length)
        this->segments = (sensor_msgs::PointCloud2*)realloc(this->segments, segments_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      segments_length = segments_lengthT;
      for( uint8_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return "cob_perception_msgs/PointCloud2Array"; };
    const char * getMD5(){ return "bd792288e56da8dc0e9d1696ac4e856d"; };

  };

}
#endif
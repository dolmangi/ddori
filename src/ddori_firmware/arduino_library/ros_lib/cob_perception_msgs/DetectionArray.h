#ifndef _ROS_cob_perception_msgs_DetectionArray_h
#define _ROS_cob_perception_msgs_DetectionArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_perception_msgs/Detection.h"

namespace cob_perception_msgs
{

  class DetectionArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t detections_length;
      cob_perception_msgs::Detection st_detections;
      cob_perception_msgs::Detection * detections;

    DetectionArray():
      header(),
      detections_length(0), detections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = detections_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t detections_lengthT = *(inbuffer + offset++);
      if(detections_lengthT > detections_length)
        this->detections = (cob_perception_msgs::Detection*)realloc(this->detections, detections_lengthT * sizeof(cob_perception_msgs::Detection));
      offset += 3;
      detections_length = detections_lengthT;
      for( uint8_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(cob_perception_msgs::Detection));
      }
     return offset;
    }

    const char * getType(){ return "cob_perception_msgs/DetectionArray"; };
    const char * getMD5(){ return "dded0419353379cce5ec01a67569f42d"; };

  };

}
#endif
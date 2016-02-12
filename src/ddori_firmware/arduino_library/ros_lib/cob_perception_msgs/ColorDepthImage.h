#ifndef _ROS_cob_perception_msgs_ColorDepthImage_h
#define _ROS_cob_perception_msgs_ColorDepthImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_perception_msgs/Rect.h"
#include "sensor_msgs/Image.h"

namespace cob_perception_msgs
{

  class ColorDepthImage : public ros::Msg
  {
    public:
      cob_perception_msgs::Rect head_detection;
      sensor_msgs::Image color_image;
      sensor_msgs::Image depth_image;
      uint8_t face_detections_length;
      cob_perception_msgs::Rect st_face_detections;
      cob_perception_msgs::Rect * face_detections;

    ColorDepthImage():
      head_detection(),
      color_image(),
      depth_image(),
      face_detections_length(0), face_detections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->head_detection.serialize(outbuffer + offset);
      offset += this->color_image.serialize(outbuffer + offset);
      offset += this->depth_image.serialize(outbuffer + offset);
      *(outbuffer + offset++) = face_detections_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < face_detections_length; i++){
      offset += this->face_detections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->head_detection.deserialize(inbuffer + offset);
      offset += this->color_image.deserialize(inbuffer + offset);
      offset += this->depth_image.deserialize(inbuffer + offset);
      uint8_t face_detections_lengthT = *(inbuffer + offset++);
      if(face_detections_lengthT > face_detections_length)
        this->face_detections = (cob_perception_msgs::Rect*)realloc(this->face_detections, face_detections_lengthT * sizeof(cob_perception_msgs::Rect));
      offset += 3;
      face_detections_length = face_detections_lengthT;
      for( uint8_t i = 0; i < face_detections_length; i++){
      offset += this->st_face_detections.deserialize(inbuffer + offset);
        memcpy( &(this->face_detections[i]), &(this->st_face_detections), sizeof(cob_perception_msgs::Rect));
      }
     return offset;
    }

    const char * getType(){ return "cob_perception_msgs/ColorDepthImage"; };
    const char * getMD5(){ return "03f1995e7c816d8ab016aa6ceb57208a"; };

  };

}
#endif
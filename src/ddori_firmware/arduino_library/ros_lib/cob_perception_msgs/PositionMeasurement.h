#ifndef _ROS_cob_perception_msgs_PositionMeasurement_h
#define _ROS_cob_perception_msgs_PositionMeasurement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace cob_perception_msgs
{

  class PositionMeasurement : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* name;
      const char* object_id;
      geometry_msgs::Point pos;
      geometry_msgs::Vector3 vel;
      float reliability;
      float covariance[9];
      int8_t initialization;

    PositionMeasurement():
      header(),
      name(""),
      object_id(""),
      pos(),
      vel(),
      reliability(0),
      covariance(),
      initialization(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_object_id = strlen(this->object_id);
      memcpy(outbuffer + offset, &length_object_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_id, length_object_id);
      offset += length_object_id;
      offset += this->pos.serialize(outbuffer + offset);
      offset += this->vel.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->reliability);
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariance[i]);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_initialization;
      u_initialization.real = this->initialization;
      *(outbuffer + offset + 0) = (u_initialization.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->initialization);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_object_id;
      memcpy(&length_object_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_id-1]=0;
      this->object_id = (char *)(inbuffer + offset-1);
      offset += length_object_id;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += this->vel.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->reliability));
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariance[i]));
      }
      union {
        int8_t real;
        uint8_t base;
      } u_initialization;
      u_initialization.base = 0;
      u_initialization.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->initialization = u_initialization.real;
      offset += sizeof(this->initialization);
     return offset;
    }

    const char * getType(){ return "cob_perception_msgs/PositionMeasurement"; };
    const char * getMD5(){ return "a1ad9f58d180ee0dd8bd6c516af86714"; };

  };

}
#endif
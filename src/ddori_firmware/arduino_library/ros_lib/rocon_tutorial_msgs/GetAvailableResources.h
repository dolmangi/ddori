#ifndef _ROS_SERVICE_GetAvailableResources_h
#define _ROS_SERVICE_GetAvailableResources_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_tutorial_msgs
{

static const char GETAVAILABLERESOURCES[] = "rocon_tutorial_msgs/GetAvailableResources";

  class GetAvailableResourcesRequest : public ros::Msg
  {
    public:
      const char* rapp;
      int16_t priority;

    GetAvailableResourcesRequest():
      rapp(""),
      priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_rapp = strlen(this->rapp);
      memcpy(outbuffer + offset, &length_rapp, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rapp, length_rapp);
      offset += length_rapp;
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_priority.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_rapp;
      memcpy(&length_rapp, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rapp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rapp-1]=0;
      this->rapp = (char *)(inbuffer + offset-1);
      offset += length_rapp;
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
     return offset;
    }

    const char * getType(){ return GETAVAILABLERESOURCES; };
    const char * getMD5(){ return "d6acea3bcb7fdb592ecb7ffc748c29b2"; };

  };

  class GetAvailableResourcesResponse : public ros::Msg
  {
    public:
      uint8_t available_resources_length;
      char* st_available_resources;
      char* * available_resources;
      uint8_t preemptible_resources_length;
      char* st_preemptible_resources;
      char* * preemptible_resources;

    GetAvailableResourcesResponse():
      available_resources_length(0), available_resources(NULL),
      preemptible_resources_length(0), preemptible_resources(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = available_resources_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < available_resources_length; i++){
      uint32_t length_available_resourcesi = strlen(this->available_resources[i]);
      memcpy(outbuffer + offset, &length_available_resourcesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->available_resources[i], length_available_resourcesi);
      offset += length_available_resourcesi;
      }
      *(outbuffer + offset++) = preemptible_resources_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < preemptible_resources_length; i++){
      uint32_t length_preemptible_resourcesi = strlen(this->preemptible_resources[i]);
      memcpy(outbuffer + offset, &length_preemptible_resourcesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->preemptible_resources[i], length_preemptible_resourcesi);
      offset += length_preemptible_resourcesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t available_resources_lengthT = *(inbuffer + offset++);
      if(available_resources_lengthT > available_resources_length)
        this->available_resources = (char**)realloc(this->available_resources, available_resources_lengthT * sizeof(char*));
      offset += 3;
      available_resources_length = available_resources_lengthT;
      for( uint8_t i = 0; i < available_resources_length; i++){
      uint32_t length_st_available_resources;
      memcpy(&length_st_available_resources, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_available_resources; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_available_resources-1]=0;
      this->st_available_resources = (char *)(inbuffer + offset-1);
      offset += length_st_available_resources;
        memcpy( &(this->available_resources[i]), &(this->st_available_resources), sizeof(char*));
      }
      uint8_t preemptible_resources_lengthT = *(inbuffer + offset++);
      if(preemptible_resources_lengthT > preemptible_resources_length)
        this->preemptible_resources = (char**)realloc(this->preemptible_resources, preemptible_resources_lengthT * sizeof(char*));
      offset += 3;
      preemptible_resources_length = preemptible_resources_lengthT;
      for( uint8_t i = 0; i < preemptible_resources_length; i++){
      uint32_t length_st_preemptible_resources;
      memcpy(&length_st_preemptible_resources, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_preemptible_resources; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_preemptible_resources-1]=0;
      this->st_preemptible_resources = (char *)(inbuffer + offset-1);
      offset += length_st_preemptible_resources;
        memcpy( &(this->preemptible_resources[i]), &(this->st_preemptible_resources), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETAVAILABLERESOURCES; };
    const char * getMD5(){ return "4211656ed7da3f4d2a05064e9d6a2241"; };

  };

  class GetAvailableResources {
    public:
    typedef GetAvailableResourcesRequest Request;
    typedef GetAvailableResourcesResponse Response;
  };

}
#endif

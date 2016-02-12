#ifndef _ROS_cob_perception_msgs_People_h
#define _ROS_cob_perception_msgs_People_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_perception_msgs/Person.h"

namespace cob_perception_msgs
{

  class People : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t people_length;
      cob_perception_msgs::Person st_people;
      cob_perception_msgs::Person * people;

    People():
      header(),
      people_length(0), people(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = people_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < people_length; i++){
      offset += this->people[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t people_lengthT = *(inbuffer + offset++);
      if(people_lengthT > people_length)
        this->people = (cob_perception_msgs::Person*)realloc(this->people, people_lengthT * sizeof(cob_perception_msgs::Person));
      offset += 3;
      people_length = people_lengthT;
      for( uint8_t i = 0; i < people_length; i++){
      offset += this->st_people.deserialize(inbuffer + offset);
        memcpy( &(this->people[i]), &(this->st_people), sizeof(cob_perception_msgs::Person));
      }
     return offset;
    }

    const char * getType(){ return "cob_perception_msgs/People"; };
    const char * getMD5(){ return "e3b3272edc8f72e2c8c666fbaeaa5f7b"; };

  };

}
#endif
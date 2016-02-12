#ifndef _ROS_rosjava_test_msgs_Composite_h
#define _ROS_rosjava_test_msgs_Composite_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosjava_test_msgs/CompositeA.h"
#include "rosjava_test_msgs/CompositeB.h"

namespace rosjava_test_msgs
{

  class Composite : public ros::Msg
  {
    public:
      rosjava_test_msgs::CompositeA a;
      rosjava_test_msgs::CompositeB b;

    Composite():
      a(),
      b()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->a.serialize(outbuffer + offset);
      offset += this->b.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->a.deserialize(inbuffer + offset);
      offset += this->b.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rosjava_test_msgs/Composite"; };
    const char * getMD5(){ return "d8fb6eb869ad3956b50e8737d96dc9fa"; };

  };

}
#endif
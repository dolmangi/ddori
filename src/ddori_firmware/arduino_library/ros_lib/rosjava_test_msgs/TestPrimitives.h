#ifndef _ROS_rosjava_test_msgs_TestPrimitives_h
#define _ROS_rosjava_test_msgs_TestPrimitives_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "ros/duration.h"

namespace rosjava_test_msgs
{

  class TestPrimitives : public ros::Msg
  {
    public:
      const char* caller_id;
      const char* orig_caller_id;
      const char* str;
      int8_t b;
      int16_t int16;
      int32_t int32;
      int64_t int64;
      uint8_t c;
      uint16_t uint16;
      uint32_t uint32;
      uint64_t uint64;
      float float32;
      float float64;
      ros::Time t;
      ros::Duration d;

    TestPrimitives():
      caller_id(""),
      orig_caller_id(""),
      str(""),
      b(0),
      int16(0),
      int32(0),
      int64(0),
      c(0),
      uint16(0),
      uint32(0),
      uint64(0),
      float32(0),
      float64(0),
      t(),
      d()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_caller_id = strlen(this->caller_id);
      memcpy(outbuffer + offset, &length_caller_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->caller_id, length_caller_id);
      offset += length_caller_id;
      uint32_t length_orig_caller_id = strlen(this->orig_caller_id);
      memcpy(outbuffer + offset, &length_orig_caller_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->orig_caller_id, length_orig_caller_id);
      offset += length_orig_caller_id;
      uint32_t length_str = strlen(this->str);
      memcpy(outbuffer + offset, &length_str, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->str, length_str);
      offset += length_str;
      union {
        int8_t real;
        uint8_t base;
      } u_b;
      u_b.real = this->b;
      *(outbuffer + offset + 0) = (u_b.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b);
      union {
        int16_t real;
        uint16_t base;
      } u_int16;
      u_int16.real = this->int16;
      *(outbuffer + offset + 0) = (u_int16.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_int16.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->int16);
      union {
        int32_t real;
        uint32_t base;
      } u_int32;
      u_int32.real = this->int32;
      *(outbuffer + offset + 0) = (u_int32.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_int32.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_int32.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_int32.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->int32);
      union {
        int64_t real;
        uint64_t base;
      } u_int64;
      u_int64.real = this->int64;
      *(outbuffer + offset + 0) = (u_int64.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_int64.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_int64.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_int64.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_int64.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_int64.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_int64.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_int64.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->int64);
      *(outbuffer + offset + 0) = (this->c >> (8 * 0)) & 0xFF;
      offset += sizeof(this->c);
      *(outbuffer + offset + 0) = (this->uint16 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uint16 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->uint16);
      *(outbuffer + offset + 0) = (this->uint32 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uint32 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uint32 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uint32 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uint32);
      union {
        uint64_t real;
        uint32_t base;
      } u_uint64;
      u_uint64.real = this->uint64;
      *(outbuffer + offset + 0) = (u_uint64.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uint64.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uint64.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uint64.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uint64);
      union {
        float real;
        uint32_t base;
      } u_float32;
      u_float32.real = this->float32;
      *(outbuffer + offset + 0) = (u_float32.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_float32.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_float32.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_float32.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->float32);
      offset += serializeAvrFloat64(outbuffer + offset, this->float64);
      *(outbuffer + offset + 0) = (this->t.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->t.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->t.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->t.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t.sec);
      *(outbuffer + offset + 0) = (this->t.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->t.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->t.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->t.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t.nsec);
      *(outbuffer + offset + 0) = (this->d.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->d.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->d.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->d.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d.sec);
      *(outbuffer + offset + 0) = (this->d.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->d.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->d.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->d.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_caller_id;
      memcpy(&length_caller_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_caller_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_caller_id-1]=0;
      this->caller_id = (char *)(inbuffer + offset-1);
      offset += length_caller_id;
      uint32_t length_orig_caller_id;
      memcpy(&length_orig_caller_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_orig_caller_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_orig_caller_id-1]=0;
      this->orig_caller_id = (char *)(inbuffer + offset-1);
      offset += length_orig_caller_id;
      uint32_t length_str;
      memcpy(&length_str, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_str; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_str-1]=0;
      this->str = (char *)(inbuffer + offset-1);
      offset += length_str;
      union {
        int8_t real;
        uint8_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->b = u_b.real;
      offset += sizeof(this->b);
      union {
        int16_t real;
        uint16_t base;
      } u_int16;
      u_int16.base = 0;
      u_int16.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_int16.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->int16 = u_int16.real;
      offset += sizeof(this->int16);
      union {
        int32_t real;
        uint32_t base;
      } u_int32;
      u_int32.base = 0;
      u_int32.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_int32.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_int32.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_int32.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->int32 = u_int32.real;
      offset += sizeof(this->int32);
      union {
        int64_t real;
        uint64_t base;
      } u_int64;
      u_int64.base = 0;
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_int64.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->int64 = u_int64.real;
      offset += sizeof(this->int64);
      this->c =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->c);
      this->uint16 =  ((uint16_t) (*(inbuffer + offset)));
      this->uint16 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->uint16);
      this->uint32 =  ((uint32_t) (*(inbuffer + offset)));
      this->uint32 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uint32 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uint32 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uint32);
      union {
        uint64_t real;
        uint32_t base;
      } u_uint64;
      u_uint64.base = 0;
      u_uint64.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uint64.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uint64.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uint64.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->uint64 = u_uint64.real;
      offset += sizeof(this->uint64);
      union {
        float real;
        uint32_t base;
      } u_float32;
      u_float32.base = 0;
      u_float32.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_float32.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_float32.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_float32.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->float32 = u_float32.real;
      offset += sizeof(this->float32);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->float64));
      this->t.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->t.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->t.sec);
      this->t.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->t.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->t.nsec);
      this->d.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->d.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->d.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->d.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->d.sec);
      this->d.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->d.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->d.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->d.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->d.nsec);
     return offset;
    }

    const char * getType(){ return "rosjava_test_msgs/TestPrimitives"; };
    const char * getMD5(){ return "3e70f428a22c0d26ca67f87802c8e00f"; };

  };

}
#endif
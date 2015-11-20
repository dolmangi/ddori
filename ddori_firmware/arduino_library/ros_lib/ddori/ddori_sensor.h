#ifndef _ROS_ddori_ddori_sensor_h
#define _ROS_ddori_ddori_sensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ddori
{

  class ddori_sensor : public ros::Msg
  {
    public:
      uint16_t time_stamp;
      uint8_t bumper;
      int16_t left_encoder;
      int16_t right_encoder;
      uint8_t buttons;
      uint8_t charger;
      int16_t voltage;
      int16_t current;
      int16_t temp1;
      int16_t temp2;
      int16_t temp3;
      int16_t co;
      int16_t gas;
      int16_t air;
      int16_t barometer;
      int8_t pir;
      int8_t prx_1;
      int8_t prx_2;
      int8_t prx_3;
      int16_t als;

    ddori_sensor():
      time_stamp(0),
      bumper(0),
      left_encoder(0),
      right_encoder(0),
      buttons(0),
      charger(0),
      voltage(0),
      current(0),
      temp1(0),
      temp2(0),
      temp3(0),
      co(0),
      gas(0),
      air(0),
      barometer(0),
      pir(0),
      prx_1(0),
      prx_2(0),
      prx_3(0),
      als(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->time_stamp >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_stamp >> (8 * 1)) & 0xFF;
      offset += sizeof(this->time_stamp);
      *(outbuffer + offset + 0) = (this->bumper >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bumper);
      union {
        int16_t real;
        uint16_t base;
      } u_left_encoder;
      u_left_encoder.real = this->left_encoder;
      *(outbuffer + offset + 0) = (u_left_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_encoder.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_encoder);
      union {
        int16_t real;
        uint16_t base;
      } u_right_encoder;
      u_right_encoder.real = this->right_encoder;
      *(outbuffer + offset + 0) = (u_right_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_encoder.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_encoder);
      *(outbuffer + offset + 0) = (this->buttons >> (8 * 0)) & 0xFF;
      offset += sizeof(this->buttons);
      *(outbuffer + offset + 0) = (this->charger >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger);
      union {
        int16_t real;
        uint16_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current);
      union {
        int16_t real;
        uint16_t base;
      } u_temp1;
      u_temp1.real = this->temp1;
      *(outbuffer + offset + 0) = (u_temp1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->temp1);
      union {
        int16_t real;
        uint16_t base;
      } u_temp2;
      u_temp2.real = this->temp2;
      *(outbuffer + offset + 0) = (u_temp2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp2.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->temp2);
      union {
        int16_t real;
        uint16_t base;
      } u_temp3;
      u_temp3.real = this->temp3;
      *(outbuffer + offset + 0) = (u_temp3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp3.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->temp3);
      union {
        int16_t real;
        uint16_t base;
      } u_co;
      u_co.real = this->co;
      *(outbuffer + offset + 0) = (u_co.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_co.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->co);
      union {
        int16_t real;
        uint16_t base;
      } u_gas;
      u_gas.real = this->gas;
      *(outbuffer + offset + 0) = (u_gas.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gas.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gas);
      union {
        int16_t real;
        uint16_t base;
      } u_air;
      u_air.real = this->air;
      *(outbuffer + offset + 0) = (u_air.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_air.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->air);
      union {
        int16_t real;
        uint16_t base;
      } u_barometer;
      u_barometer.real = this->barometer;
      *(outbuffer + offset + 0) = (u_barometer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_barometer.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->barometer);
      union {
        int8_t real;
        uint8_t base;
      } u_pir;
      u_pir.real = this->pir;
      *(outbuffer + offset + 0) = (u_pir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pir);
      union {
        int8_t real;
        uint8_t base;
      } u_prx_1;
      u_prx_1.real = this->prx_1;
      *(outbuffer + offset + 0) = (u_prx_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->prx_1);
      union {
        int8_t real;
        uint8_t base;
      } u_prx_2;
      u_prx_2.real = this->prx_2;
      *(outbuffer + offset + 0) = (u_prx_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->prx_2);
      union {
        int8_t real;
        uint8_t base;
      } u_prx_3;
      u_prx_3.real = this->prx_3;
      *(outbuffer + offset + 0) = (u_prx_3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->prx_3);
      union {
        int16_t real;
        uint16_t base;
      } u_als;
      u_als.real = this->als;
      *(outbuffer + offset + 0) = (u_als.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_als.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->als);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->time_stamp =  ((uint16_t) (*(inbuffer + offset)));
      this->time_stamp |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->time_stamp);
      this->bumper =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bumper);
      union {
        int16_t real;
        uint16_t base;
      } u_left_encoder;
      u_left_encoder.base = 0;
      u_left_encoder.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_encoder.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_encoder = u_left_encoder.real;
      offset += sizeof(this->left_encoder);
      union {
        int16_t real;
        uint16_t base;
      } u_right_encoder;
      u_right_encoder.base = 0;
      u_right_encoder.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_encoder.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_encoder = u_right_encoder.real;
      offset += sizeof(this->right_encoder);
      this->buttons =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->buttons);
      this->charger =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->charger);
      union {
        int16_t real;
        uint16_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        int16_t real;
        uint16_t base;
      } u_temp1;
      u_temp1.base = 0;
      u_temp1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->temp1 = u_temp1.real;
      offset += sizeof(this->temp1);
      union {
        int16_t real;
        uint16_t base;
      } u_temp2;
      u_temp2.base = 0;
      u_temp2.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp2.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->temp2 = u_temp2.real;
      offset += sizeof(this->temp2);
      union {
        int16_t real;
        uint16_t base;
      } u_temp3;
      u_temp3.base = 0;
      u_temp3.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp3.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->temp3 = u_temp3.real;
      offset += sizeof(this->temp3);
      union {
        int16_t real;
        uint16_t base;
      } u_co;
      u_co.base = 0;
      u_co.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_co.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->co = u_co.real;
      offset += sizeof(this->co);
      union {
        int16_t real;
        uint16_t base;
      } u_gas;
      u_gas.base = 0;
      u_gas.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gas.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gas = u_gas.real;
      offset += sizeof(this->gas);
      union {
        int16_t real;
        uint16_t base;
      } u_air;
      u_air.base = 0;
      u_air.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_air.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->air = u_air.real;
      offset += sizeof(this->air);
      union {
        int16_t real;
        uint16_t base;
      } u_barometer;
      u_barometer.base = 0;
      u_barometer.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_barometer.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->barometer = u_barometer.real;
      offset += sizeof(this->barometer);
      union {
        int8_t real;
        uint8_t base;
      } u_pir;
      u_pir.base = 0;
      u_pir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pir = u_pir.real;
      offset += sizeof(this->pir);
      union {
        int8_t real;
        uint8_t base;
      } u_prx_1;
      u_prx_1.base = 0;
      u_prx_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->prx_1 = u_prx_1.real;
      offset += sizeof(this->prx_1);
      union {
        int8_t real;
        uint8_t base;
      } u_prx_2;
      u_prx_2.base = 0;
      u_prx_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->prx_2 = u_prx_2.real;
      offset += sizeof(this->prx_2);
      union {
        int8_t real;
        uint8_t base;
      } u_prx_3;
      u_prx_3.base = 0;
      u_prx_3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->prx_3 = u_prx_3.real;
      offset += sizeof(this->prx_3);
      union {
        int16_t real;
        uint16_t base;
      } u_als;
      u_als.base = 0;
      u_als.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_als.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->als = u_als.real;
      offset += sizeof(this->als);
     return offset;
    }

    const char * getType(){ return "ddori/ddori_sensor"; };
    const char * getMD5(){ return "3676e7aa50bcd8c89f9c5ae2f526915b"; };

  };

}
#endif
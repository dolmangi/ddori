#ifndef _ROS_ddori_msgs_ddori_sensor_h
#define _ROS_ddori_msgs_ddori_sensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ddori_msgs
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
      int16_t gas_co;
      int16_t gas_lpg;
      int16_t gas_smoke;
      int16_t air_quality;
      int16_t dust_sensor;
      int8_t pir;
      int8_t prx_1;
      int8_t prx_2;
      int8_t prx_3;
      int16_t als;
      int16_t sonar_front;
      int16_t sonar_left;
      int16_t sonar_right;
      int16_t sonar_rear;

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
      gas_co(0),
      gas_lpg(0),
      gas_smoke(0),
      air_quality(0),
      dust_sensor(0),
      pir(0),
      prx_1(0),
      prx_2(0),
      prx_3(0),
      als(0),
      sonar_front(0),
      sonar_left(0),
      sonar_right(0),
      sonar_rear(0)
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
      } u_gas_co;
      u_gas_co.real = this->gas_co;
      *(outbuffer + offset + 0) = (u_gas_co.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gas_co.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gas_co);
      union {
        int16_t real;
        uint16_t base;
      } u_gas_lpg;
      u_gas_lpg.real = this->gas_lpg;
      *(outbuffer + offset + 0) = (u_gas_lpg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gas_lpg.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gas_lpg);
      union {
        int16_t real;
        uint16_t base;
      } u_gas_smoke;
      u_gas_smoke.real = this->gas_smoke;
      *(outbuffer + offset + 0) = (u_gas_smoke.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gas_smoke.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gas_smoke);
      union {
        int16_t real;
        uint16_t base;
      } u_air_quality;
      u_air_quality.real = this->air_quality;
      *(outbuffer + offset + 0) = (u_air_quality.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_air_quality.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->air_quality);
      union {
        int16_t real;
        uint16_t base;
      } u_dust_sensor;
      u_dust_sensor.real = this->dust_sensor;
      *(outbuffer + offset + 0) = (u_dust_sensor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dust_sensor.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->dust_sensor);
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
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_front;
      u_sonar_front.real = this->sonar_front;
      *(outbuffer + offset + 0) = (u_sonar_front.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sonar_front.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sonar_front);
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_left;
      u_sonar_left.real = this->sonar_left;
      *(outbuffer + offset + 0) = (u_sonar_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sonar_left.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sonar_left);
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_right;
      u_sonar_right.real = this->sonar_right;
      *(outbuffer + offset + 0) = (u_sonar_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sonar_right.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sonar_right);
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_rear;
      u_sonar_rear.real = this->sonar_rear;
      *(outbuffer + offset + 0) = (u_sonar_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sonar_rear.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sonar_rear);
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
      } u_gas_co;
      u_gas_co.base = 0;
      u_gas_co.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gas_co.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gas_co = u_gas_co.real;
      offset += sizeof(this->gas_co);
      union {
        int16_t real;
        uint16_t base;
      } u_gas_lpg;
      u_gas_lpg.base = 0;
      u_gas_lpg.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gas_lpg.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gas_lpg = u_gas_lpg.real;
      offset += sizeof(this->gas_lpg);
      union {
        int16_t real;
        uint16_t base;
      } u_gas_smoke;
      u_gas_smoke.base = 0;
      u_gas_smoke.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gas_smoke.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gas_smoke = u_gas_smoke.real;
      offset += sizeof(this->gas_smoke);
      union {
        int16_t real;
        uint16_t base;
      } u_air_quality;
      u_air_quality.base = 0;
      u_air_quality.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_air_quality.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->air_quality = u_air_quality.real;
      offset += sizeof(this->air_quality);
      union {
        int16_t real;
        uint16_t base;
      } u_dust_sensor;
      u_dust_sensor.base = 0;
      u_dust_sensor.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dust_sensor.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->dust_sensor = u_dust_sensor.real;
      offset += sizeof(this->dust_sensor);
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
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_front;
      u_sonar_front.base = 0;
      u_sonar_front.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sonar_front.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sonar_front = u_sonar_front.real;
      offset += sizeof(this->sonar_front);
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_left;
      u_sonar_left.base = 0;
      u_sonar_left.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sonar_left.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sonar_left = u_sonar_left.real;
      offset += sizeof(this->sonar_left);
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_right;
      u_sonar_right.base = 0;
      u_sonar_right.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sonar_right.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sonar_right = u_sonar_right.real;
      offset += sizeof(this->sonar_right);
      union {
        int16_t real;
        uint16_t base;
      } u_sonar_rear;
      u_sonar_rear.base = 0;
      u_sonar_rear.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sonar_rear.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sonar_rear = u_sonar_rear.real;
      offset += sizeof(this->sonar_rear);
     return offset;
    }

    const char * getType(){ return "ddori_msgs/ddori_sensor"; };
    const char * getMD5(){ return "3994f8a26616342a29407bb201c13537"; };

  };

}
#endif
/** \mainpage BMP085 Barometric Pressure Sensor API
 * Copyright (C) 2012 Robert Bosch LLC
 *
 * \section intro_sec Introduction
 * The BMP085 API enables quick access to Bosch Sensortec's digital barometric pressure sensor and altimeter.
 *
 * \section license_sec License
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in 
 * compliance with the License and the following stipulations. The Apache License , Version 2.0 is applicable unless 
 * otherwise stated by the stipulations of the disclaimer below. 
 * 
 * You may obtain a copy of the License at 
 * http://www.apache.org/licenses/LICENSE-2.0 
 *
 * \section disclaimer_sec Disclaimer 
 *
 * Common:
 * This Work is developed for the consumer goods industry. It may only be used 
 * within the parameters of the respective valid product data sheet.  The Work 
 * provided with the express understanding that there is no warranty of fitness for a particular purpose. 
 * It is not fit for use in life-sustaining, safety or security sensitive systems or any system or device 
 * that may lead to bodily harm or property damage if the system or device malfunctions. In addition, 
 * the Work is not fit for use in products which interact with motor vehicle systems.  
 * The resale and/or use of the Work are at the purchaser's own risk and his own responsibility. The 
 * examination of fitness for the intended use is the sole responsibility of the Purchaser. 
 *
 * The purchaser shall indemnify Bosch Sensortec from all third party claims, including any claims for 
 * incidental, or consequential damages, arising from any Work or Derivative Work use not covered by the parameters of 
 * the respective valid product data sheet or not approved by Bosch Sensortec and reimburse Bosch 
 * Sensortec for all costs in connection with such claims.
 *
 * The purchaser must monitor the market for the purchased Work and Derivative Works, particularly with regard to 
 * product safety and inform Bosch Sensortec without delay of all security relevant incidents.
 *
 * Engineering Samples are marked with an asterisk (*) or (e). Samples may vary from the valid 
 * technical specifications of the product series. They are therefore not intended or fit for resale to third 
 * parties or for use in end products. Their sole purpose is internal client testing. The testing of an 
 * engineering sample may in no way replace the testing of a product series. Bosch Sensortec 
 * assumes no liability for the use of engineering samples. By accepting the engineering samples, the 
 * Purchaser agrees to indemnify Bosch Sensortec from all claims arising from the use of engineering 
 * samples.
 *
 * Special:
 * This Work and any related information (hereinafter called "Information") is provided free of charge 
 * for the sole purpose to support your application work. The Woek and Information is subject to the 
 * following terms and conditions: 
 *
 * The Work is specifically designed for the exclusive use for Bosch Sensortec products by 
 * personnel who have special experience and training. Do not use this Work or Derivative Works if you do not have the 
 * proper experience or training. Do not use this Work or Derivative Works fot other products than Bosch Sensortec products.  
 *
 * The Information provided is believed to be accurate and reliable. Bosch Sensortec assumes no 
 * responsibility for the consequences of use of such Information nor for any infringement of patents or 
 * other rights of third parties which may result from its use. No license is granted by implication or 
 * otherwise under any patent or patent rights of Bosch. Specifications mentioned in the Information are 
 * subject to change without notice.
 *
 */


//\Author Philip Roan, Robert Bosch LLC
//
//
// dolmangi@naver.com 11/27/2015 modified for ddori project.
//  - catkin build is applied
//  - used bmp180
// -  worked on raspberry pi 2



//ROS Headers
#include <ros/ros.h>
#include <ros/time.h>

#include "bmp085/bmp085_measurement.h" //message

extern "C"{
#include "linux_glue.h"
#include "bmp085/bmp085_bst.h"
}

//* Write to the BMP085 over I2C using the Sub20 device.
BMP085_BUS_WR_RETURN_TYPE sub20_bmp085_write( unsigned char device_addr, unsigned char register_addr, unsigned char* register_data, unsigned char write_length )
{
  int error_code = 0;
  error_code = linux_i2c_write(device_addr,register_addr,write_length,register_data);
  return (char)error_code;
}

//* Write to the BMP085 over I2C using the Sub20 device.
BMP085_BUS_RD_RETURN_TYPE sub20_bmp085_read( unsigned char device_addr, unsigned char register_addr, unsigned char* register_data, unsigned char read_length )
{
  int error_code = 0;
  error_code = linux_i2c_read(device_addr, register_addr, read_length, register_data);
  return (char)error_code;
}

//* Have the node sleep while waiting for the conversion to complete
BMP085_MDELAY_RETURN_TYPE bmp085_delay( BMP085_MDELAY_DATA_TYPE milliseconds)
{
  ros::Duration( milliseconds / 1e3 ).sleep();
}


int main( int argc, char** argv )
{

  // ROS init
  ros::init(argc, argv, "BMP085");
  ros::NodeHandle nh;
  
  // Create an instance of the sensor
  bmp085_t sensor;
  // Set function pointers
  sensor.bus_write = &sub20_bmp085_write;
  sensor.bus_read = &sub20_bmp085_read;
  sensor.delay_msec = &bmp085_delay;

  // Turn into ROS parameters
  bool run_continuous_ = true;


  // Create a publisher node
  ros::Publisher sensor_pub = nh.advertise<bmp085::bmp085_measurement> ("BMP085_measurements", 100);
  // Create message
  bmp085::bmp085_measurement msg;

  // Create service handles
  //ros::ServiceServer sensor_service1 = nh.advertiseService("bmp085/get_temperature", &bmp085_::

  int   i2c_bus=1;
  linux_set_i2c_bus(i2c_bus);

  
  // Wait for BMP085 to be attached and configured (1 Hz loop rate)
  ros::Rate wait_interval(1);
  while( nh.ok() )
  {
    int return_value = 0;

    return_value = bmp085_init( &sensor );

    ROS_INFO("Tried BMP085 initialization: %d", return_value );
    ROS_INFO("Sensor type: %d", sensor.sensortype);
  
    if( return_value == 0 )
    {
      break;
    }
    else
    {
      msg.is_connected = false;
      msg.header.stamp = ros::Time::now();
    
      sensor_pub.publish( msg );
      ros::spinOnce();
      wait_interval.sleep();
    }
  }

  long T, P;
  unsigned long ut, up;
  
  while( run_continuous_ && nh.ok() )
  {
    msg.is_connected = true;

    // get measurement here
    ut = bmp085_get_ut();
    up = bmp085_get_up();

    T = bmp085_get_temperature( ut );
    P = bmp085_get_pressure( up );


    msg.header.stamp = ros::Time::now();
    msg.temperature = T / 10.0; // [C]
    msg.pressure = P / 1e2; // [hPa]
    
    sensor_pub.publish( msg );
    ros::spinOnce();

    wait_interval.sleep();
  }

  return 0;
}

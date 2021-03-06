/*
 * Copyright (c) 2012, Yujin Robot.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Yujin Robot nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file /include/teleop_core/keyop_core.hpp
 *
 * @brief The controlling node for remote operations on robot_core.
 *
 **/

/*****************************************************************************
 ** Ifdefs
 *****************************************************************************/

#ifndef KEYOP_CORE_NODE_HPP_
#define KEYOP_CORE_NODE_HPP_

/*****************************************************************************
 ** Includes
 *****************************************************************************/

#include <ros/ros.h>
#include <termios.h> // for keyboard input
#include <ecl/threads.hpp>
#include <geometry_msgs/Twist.h>  // for velocity commands
#include <geometry_msgs/TwistStamped.h>  // for velocity commands
#include <ddori_msgs/KeyboardInput.h> // keycodes from remote teleops.
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>

/*****************************************************************************
 ** Namespaces
 *****************************************************************************/

namespace keyop_core
{

/*****************************************************************************
 ** Interface
 *****************************************************************************/
/**
 * @brief Keyboard remote control for our robot core (mobile base).
 *
 */
class KeyOpCore
{
public:
  /*********************
   ** C&D
   **********************/
  KeyOpCore();
  ~KeyOpCore();
  bool init();

  /*********************
   ** Runtime
   **********************/
  void spin();

private:
  ros::Subscriber keyinput_subscriber;
  ros::Publisher velocity_publisher_;
  ros::Publisher motor_power_publisher_;
  bool last_zero_vel_sent;
  bool accept_incoming;
  bool power_status;
  bool wait_for_connection_;
  geometry_msgs::TwistPtr cmd;
  geometry_msgs::TwistStampedPtr cmd_stamped;
  double linear_vel_step, linear_vel_max;
  double angular_vel_step, angular_vel_max;
  std::string name;


  ros::Publisher lightonoff_publisher_;
  ros::Publisher gasens_onoff_publisher_;
  ros::Publisher sonar_power_publisher_;
  ros::Publisher phone_power_publisher_;
  ros::Publisher armservo_power_publisher_;
  ros::Publisher arms_hug_publisher_;
  ros::Publisher arms_pos_publisher_;
  ros::Publisher cam_pos_publisher_;


  std_msgs::Int8 light_on; 
  std_msgs::Int8 ArmServoPower ;
  std_msgs::Int8 ArmsPos ;
  std_msgs::Int8 ArmsHug ;
  std_msgs::Int8 PhonePower ;
  std_msgs::Int8 GasSensorPower; 
  std_msgs::Int16 SonarPower; 



  /*********************
   ** Commands
   **********************/
  void enable();
  void disable();
  void incrementLinearVelocity();
  void decrementLinearVelocity();
  void incrementAngularVelocity();
  void decrementAngularVelocity();
  void resetVelocity();
  void enableLight();
  void enableGasSensor();
  void enableSonar(char ch);
  void ArmServoPowerOn();
  void ArmServoPowerOff();
  void ArmsUp();
  void ArmsDown();
  void ArmsOpen();
  void ArmsClose();
  void SetPhonePower(char pwr);
  void CamDown();
  void CamUp();


  /*********************
   ** Keylogging
   **********************/

  void keyboardInputLoop();
  void processKeyboardInput(char c);
  void remoteKeyInputReceived(const ddori_msgs::KeyboardInput& key);
  void restoreTerminal();
  bool quit_requested;
  int key_file_descriptor;
  struct termios original_terminal_state;
  ecl::Thread thread;
};

} // namespace keyop_core

#endif /* KEYOP_CORE_NODE_HPP_ */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "std_msgs/UInt16.h"
#include "ddori_msgs/ddori_sensor.h"
#include "ddori_msgs/servo_control.h"
#include "ddori_msgs/motor_speed.h"


#include <termios.h> // for keyboard input
#include <ecl/threads.hpp>
#include <geometry_msgs/Twist.h>  // for velocity commands
#include <geometry_msgs/TwistStamped.h>  // for velocity commands
#include <ddori_msgs/MotorPower.h>

#define  KeyCode_Right		67	//     # 0x43
#define  KeyCode_Left		68	 //    # 0x44
#define  KeyCode_Up		65 	 //   # 0x41
#define  KeyCode_Down		66   //  # 0x42
#define  KeyCode_Space		32    // # 0x20
#define  KeyCode_Enable	101   // # 0x65, 'e'
#define  KeyCode_Disable	100   // # 0x64, 'd'

#define ROBOT_WIDTH		0.2		//20cm

geometry_msgs::TwistPtr cmd;
geometry_msgs::TwistStampedPtr cmd_stamped;
double linear_vel_step, linear_vel_max;
char thread_run=1;
double tgt_speed_left=0;
double tgt_speed_right=0;
bool motor_on=false;

unsigned char servo_pos[10]={0};

std_msgs::Int8 light_on; 
std_msgs::Int8 ArmServoPower ;
std_msgs::Int8 GasSensorPower; 
std_msgs::Int8 PhonePower; 
std_msgs::Int8 FoscamPower; 
std_msgs::Int8 CamServoPos; 
std_msgs::Int8 ArmsPos; 
std_msgs::Int8 ArmsHug; 



ros::Subscriber sensor_subscriber;
ros::Subscriber velocity_subscriber;
 ros::Subscriber motor_power_subscriber_;

  
ros::Publisher light_control_publisher;
ros::Publisher WheelPWM_publisher;
ros::Publisher ArmServoPower_publisher;
ros::Publisher ArmServoPos_publisher;
ros::Publisher GasSensorPower_publisher;
ros::Publisher PhonePower_publisher;
ros::Publisher FoscamPower_publisher;
ros::Publisher CamServoPos_publisher;
ros::Publisher Stop_publisher;
ros::Publisher AllOff_publisher;
ros::Publisher ArmsPos_publisher;
ros::Publisher ArmsHug_publisher;
ros::Publisher LeftPwm_publisher;
ros::Publisher RightPwm_publisher;



ecl::Thread thread;
int key_file_descriptor=0;
struct termios original_terminal_state;
	
void processKeyboardInput(char c);
void keyboardInputThread();
void send_speed(int left, int  right);


// Motor Spec : 50RPM , 4.5Kg tork
// encoder ticks  - 14 ticks per 1 revolution
// Gear Ratio 90:1
// Wheel radius 36mm
// circumference =(2.0 * 3.1415926 * 36) = 226.2 mm
// mm per 1tick =  ((2.0 * 3.1415926 * 36)  / (90.0*14) ) = 0.17952


#define ONETICK_MM  ((2.0 * 3.1415926 * 36)  / (90.0*14) )
ddori_msgs::ddori_sensor prev;
double spd_ms_l=0;
double spd_ms_r=0;
double last_err_l=0;
double last_err_r=0;
double Kp=50;
double Kd=5;
int16_t last_pwm_l=0;
int16_t last_pwm_r=0;

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
void sensor_Callback(const ddori_msgs::ddori_sensor::ConstPtr& msg)
{
	char display=0;
	uint16_t tick_diff=(msg->time_stamp - prev.time_stamp) & 0xffff;
	int16_t diff_enc_l=msg->left_encoder-prev.left_encoder;
	int16_t diff_enc_r=msg->right_encoder-prev.right_encoder;
	double move_l=ONETICK_MM * diff_enc_l  ;
	double move_r= ONETICK_MM * diff_enc_r;
	double spd_l = move_l *  (1000.0/tick_diff); // mm /s
	double spd_r = move_r *  (1000.0/tick_diff) ; // mm/s
	
	spd_ms_l =spd_l / 1000;	// m/s
	spd_ms_r =spd_r / 1000;	// m/s
	

	double error, pidTerm;
	int16_t pwm_l=0;
	int16_t pwm_r=0;

	if (motor_on && (tgt_speed_left !=0  || tgt_speed_right !=0 ))
	{

		error = tgt_speed_left - spd_ms_l;
		pidTerm = (Kp * error) + (Kd * (error -last_err_l));
		pwm_l = constrain((int16_t)(last_pwm_l+pidTerm) , -255, 255);
		last_err_l=error;


		error = tgt_speed_right -spd_ms_r;
		pidTerm = (Kp * error) + (Kd * (error -last_err_r));
		pwm_r = constrain((int16_t)(last_pwm_r+pidTerm) , -255, 255);
		last_err_r=error;

		//if (tgt_speed_left<0 && pwm_l>0  || tgt_speed_left>0 && pwm_l<0) pwm_l=0;
		//if (tgt_speed_right<0 && pwm_r>0  || tgt_speed_right>0 && pwm_r<0) pwm_r=0;
		
		send_speed(pwm_l , pwm_r );



	}
	else 
	{

			send_speed(0 , 0 );

	}
		
/*
	if (display) {
#if 0		
		ROS_INFO("%d: %6.2f[V] %d[mA]   PIR:%d  pwm=%u,%u   enc=%d,%d    speed=%d,%d   CO=%d  GAS=%d  AIR=%d ", msg->time_stamp, msg->voltage/100.0, msg->current, msg->pir, 
			(unsigned char)msg->left_pwm, (unsigned char)msg->right_pwm,
			msg->left_encoder,msg->right_encoder,
			tgt_speed_left,tgt_speed_right,
			msg->co, msg->gas, msg->air);
#else
		ROS_INFO("%d: %6.2f[V] %d[mA]  PIR:%d pwm=%d,%d enc=%d(%d),%d(%d)  curspd=%6.3f,%6.3f  err=%6.3f,%6.3f  tickdiff=%d  ", 
			msg->time_stamp, msg->voltage/100.0, msg->current, msg->pir, 
			pwm_l, pwm_r,
			msg->left_encoder,diff_enc_l, msg->right_encoder, diff_enc_r,
			spd_ms_l,spd_ms_r,
			last_err_l,last_err_r,
			tick_diff
			);

#endif
	}
*/
	prev = *msg;
	last_pwm_l=pwm_l;
	last_pwm_r=pwm_r;

	

}

void velocity_Callback(const geometry_msgs::Twist::ConstPtr& msg)
{

	tgt_speed_left = msg->linear.x - msg->angular.z*ROBOT_WIDTH/2 ;
	tgt_speed_right = msg->linear.x + msg->angular.z*ROBOT_WIDTH/2;
	ROS_INFO_STREAM("ddori : target_speed left=" <<tgt_speed_left << "    rigght=" << tgt_speed_right);
}

void motorPower_Callback(const ddori_msgs::MotorPower::ConstPtr& msg)
{
	if (msg->state == ddori_msgs::MotorPower::ON)
	{
		ROS_INFO("ddori : Firing up the motors. [ ]");
		motor_on=true;
		//kobuki.enable();
		//odometry.resetTimeout();
	}
	else if (msg->state == ddori_msgs::MotorPower::OFF)
	{
		//kobuki.disable();
		ROS_INFO("ddori : Shutting down the motors. [] ");
		motor_on=false;
		send_speed(0,0);
		//odometry.resetTimeout();
	}
	else
	{
		ROS_ERROR_STREAM("ddori : Motor power command specifies unknown state '" << (unsigned int)msg->state
		<< "'. []");
	}
}


void send_speed(int left, int  right)
{
       ddori_msgs::motor_speed ms;
       ms.left_speed=left;
       ms.right_speed=right;

       WheelPWM_publisher.publish(ms);

}


// Motor  37mm - 50 RPM, Tork=4.5Kg
// encoder - 1 revolution  1050 tick
// wheel radius 35mm(including TankTrack Thickness),  diameter - 70mm
// circumference = 2 pi r = 2*3.14159*35 = 220mm 
// 1 tick = 0.2095 mm


//void sendMotorPwm();
         

int main(int argc, char **argv)
{
	/**
	* The ros::init() function needs to see argc and argv so that it can perform
	* any ROS arguments and name remapping that were provided at the command line.
	* For programmatic remappings you can use a different version of init() which takes
	* remappings directly, but for most command-line programs, passing argc and argv is
	* the easiest way to do it.  The third argument to init() is the name of the node.
	*
	* You must call one of the versions of ros::init() before using any other
	* part of the ROS system.
	*/
	ros::init(argc, argv, "ddori_main");

	/**
	* NodeHandle is the main access point to communications with the ROS system.
	* The first NodeHandle constructed will fully initialize this node, and the last
	* NodeHandle destructed will close down the node.
	*/
	ros::NodeHandle n;

	/**
	* The subscribe() call is how you tell ROS that you want to receive messages
	* on a given topic.  This invokes a call to the ROS
	* master node, which keeps a registry of who is publishing and who
	* is subscribing.  Messages are passed to a callback function, here
	* called chatterCallback.  subscribe() returns a Subscriber object that you
	* must hold on to until you want to unsubscribe.  When all copies of the Subscriber
	* object go out of scope, this callback will automatically be unsubscribed from
	* this topic.
	*
	* The second parameter to the subscribe() function is the size of the message
	* queue.  If messages are arriving faster than they are being processed, this
	* is the number of messages that will be buffered up before beginning to throw
	* away the oldest ones.
	*/
	sensor_subscriber = n.subscribe("ddori_sensor", 1000, sensor_Callback);
	velocity_subscriber = n.subscribe("cmd_vel", 1, velocity_Callback);
	motor_power_subscriber_= n.subscribe("motor_power", 1, motorPower_Callback);
	
	WheelPWM_publisher        = n.advertise<ddori_msgs::motor_speed>("cmd_pwm", 1);

	GasSensorPower.data=0;
	light_on.data=0;
	ArmsPos.data=30;
	ArmsHug.data=30;

	ros::Rate r(10); // 10 hz
	while (ros::ok() && thread_run)
	{
		//sendMotorPwm();
		/**
		* ros::spin() will enter a loop, pumping callbacks.  With this version, all
		* callbacks will be called from within this thread (the main one).  ros::spin()
		* will exit when Ctrl-C is pressed, or the node is shutdown by the master.
		*/		
		ros::spinOnce();
		r.sleep();	
	}

	ROS_INFO("Good Bye!");
	return 0;
}




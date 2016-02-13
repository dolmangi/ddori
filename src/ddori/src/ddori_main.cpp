#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "std_msgs/UInt16.h"
#include "ddori_msgs/ddori_sensor.h"
#include "ddori_msgs/servo_control.h"
#include "ddori_msgs/motor_speed.h"
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/JointState.h>

#include <termios.h> // for keyboard input
#include <ecl/threads.hpp>
#include <geometry_msgs/Twist.h>  // for velocity commands
#include <geometry_msgs/TwistStamped.h>  // for velocity commands
#include <ddori_msgs/MotorPower.h>
#include <face_recognition/FaceRecognitionAction.h>

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


std_msgs::Int8 PhonePower; 
std_msgs::Int8 FoscamPower; 
std_msgs::Int8 CamServoPos; 
std_msgs::Int8 ArmsPos; 
std_msgs::Int8 ArmsHug; 



ros::Subscriber sensor_subscriber;
ros::Subscriber velocity_subscriber;
ros::Subscriber motor_power_subscriber_;
ros::Subscriber face_recog_feedback_subscriber_;


  
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
ros::Publisher dolchatter_publisher;

ros::Publisher odom_pub ;
ros::Publisher joint_pub;


ecl::Thread thread;
int key_file_descriptor=0;
struct termios original_terminal_state;
	
void processKeyboardInput(char c);
void keyboardInputThread();
void send_speed(int left, int  right);



double x = 0.0;
double y = 0.0;
double th = 0.0;

// Motor Spec : 50RPM , 4.5Kg tork
// encoder ticks  - 14 ticks per 1 revolution
// Gear Ratio 90:1
// Wheel radius 36mm
// circumference =(2.0 * 3.1415926 * 36) = 226.2 mm
// mm per 1tick =  ((2.0 * 3.1415926 * 36)  / (90.0*14) ) = 0.17952

#define ONETICK_MM  ((2.0 * 3.1415926 * 36)  / (90.0*14) )
#define ONETICK_METER  ((2.0 * 3.1415926 * 0.036)  / (90.0*14) )
#define TICKS_METER (1.0 / ONETICK_METER)	
ddori_msgs::ddori_sensor prev;
double spd_ms_l=0;
double spd_ms_r=0;
double last_err_l=0;
double last_err_r=0;
double Kp=50;
double Kd=5;
int16_t last_pwm_l=0;
int16_t last_pwm_r=0;



#define WHEEL_RADIUS	0.036
#define WHEEL_BASE	0.20



void diff_drive(double dleft, double dright,  double tick_df)
{
	double dt,ds,delta_th,delta_x,delta_y;
	dleft=dleft/TICKS_METER;
	dright=dright/TICKS_METER;

	ros::Time current_time=ros::Time::now();
	dt = tick_df/1000;
	ds = (dleft+dright)/2.0;
	delta_th = (dright-dleft)/WHEEL_BASE;
	delta_x = ds * cos(delta_th);
	delta_y = ds * -sin(delta_th);

	x = x + cos(th)*delta_x - sin(th)*delta_y ;
	y = y + sin(th)*delta_x + cos(th)*delta_y ;
	th += delta_th;

	sensor_msgs::JointState joint_state;
	tf::TransformBroadcaster odom_broadcaster;


        //update joint_state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(3);
        joint_state.position.resize(3);
        joint_state.name[0] ="left_arm";
        joint_state.position[0] = 0;
        joint_state.name[1] ="right_arm";
        joint_state.position[1] = 0;
        joint_state.name[2] ="head";
        joint_state.position[2] = 0;

	joint_pub.publish(joint_state);




	//since all odometry is 6DOF we'll need a quaternion created from yaw
	geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

	//first, we'll publish the transform over tf
	geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.stamp = current_time;
	odom_trans.header.frame_id = "odom";
	odom_trans.child_frame_id = "base_link";

	odom_trans.transform.translation.x = x;
	odom_trans.transform.translation.y = y;
	odom_trans.transform.translation.z = 0.0;
	odom_trans.transform.rotation = odom_quat;

	//send the transform
	odom_broadcaster.sendTransform(odom_trans);

	//next, we'll publish the odometry message over ROS
	nav_msgs::Odometry odom;
	odom.header.stamp = current_time;
	odom.header.frame_id = "odom";

	//set the position
	odom.pose.pose.position.x = x;
	odom.pose.pose.position.y = y;
	odom.pose.pose.position.z = 0.0;
	odom.pose.pose.orientation = odom_quat;

	//set the velocity
	odom.child_frame_id = "base_link";
	odom.twist.twist.linear.x = ds/dt;
	odom.twist.twist.linear.y = 0;
	odom.twist.twist.angular.z = delta_th/dt;


	//publish the message
	odom_pub.publish(odom);
}





// Motor  37mm - 50 RPM, Tork=4.5Kg
// encoder - 1 revolution  1050 tick
// wheel radius 35mm(including TankTrack Thickness),  diameter - 70mm
// circumference = 2 pi r = 2*3.14159*35 = 220mm 
// 1 tick = 0.2095 mm
// tick_to_rad	 2*pi/1050
#define TICK_TO_RAD	(2*3.14159/1050)
char first_run=0;

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
void sensor_Callback(const ddori_msgs::ddori_sensor::ConstPtr& msg)
{

	if (first_run==0)
	{
		prev = *msg;
		first_run=1;
	}
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
	diff_drive(  diff_enc_l,  diff_enc_r, tick_diff); 
		
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

void face_recog_feedback_Callback(const  face_recognition::FaceRecognitionActionFeedback::ConstPtr & msg)
{
	std_msgs::String chat_msg;


	chat_msg.data=msg->feedback.names[0].c_str();
	ROS_ERROR_STREAM("ddori :Face Detected :  " <<chat_msg.data );

	if (chat_msg.data=="dolmangi" || chat_msg.data=="seokwang")
	{
		chat_msg.data="김서광님 안녕하세요?";
		ROS_ERROR_STREAM("ddori :Face Detected :  " <<chat_msg.data );
	}
	else if (chat_msg.data=="hyunji")
	{
		chat_msg.data="김현지님 안녕하세요?";
		ROS_ERROR_STREAM("ddori :Face Detected :  " <<chat_msg.data );
	}
	else if (chat_msg.data=="juha")
	{
		chat_msg.data="김주하님 안녕하세요?";
		ROS_ERROR_STREAM("ddori :Face Detected :  " <<chat_msg.data );
	}
	
	dolchatter_publisher.publish(chat_msg);
}



void send_speed(int left, int  right)
{
       ddori_msgs::motor_speed ms;
       ms.left_speed=left;
       ms.right_speed=right;

       WheelPWM_publisher.publish(ms);

}




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

	std_msgs::String chat_msg;

	sensor_subscriber = n.subscribe("ddori_sensor", 1000, sensor_Callback);
	velocity_subscriber = n.subscribe("cmd_vel", 1, velocity_Callback);
	motor_power_subscriber_= n.subscribe("motor_power", 1, motorPower_Callback);

	face_recog_feedback_subscriber_= n.subscribe("face_recognition/feedback", 1, face_recog_feedback_Callback);


	
	WheelPWM_publisher        = n.advertise<ddori_msgs::motor_speed>("cmd_pwm", 1);


	odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
	joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);

	dolchatter_publisher = n.advertise<std_msgs::String>("dolchatter", 10);
	


	ArmsPos.data=30;
	ArmsHug.data=30;

	int first=true;
	ros::Rate r(10); // 10 hz
	while (ros::ok() && thread_run)
	{
		if (first)
		{
			if (dolchatter_publisher.getNumSubscribers()>0)
			{
				first=false;
				//chat_msg.data="?덈뀞?섏꽭??, ????먮━ ?낅땲??, 諛섍컩?듬땲??;
				//ROS_INFO_STREAM("ddori : greeting :" << chat_msg.data);
				//dolchatter_publisher.publish(chat_msg);
			}
		}
		//sendMotorPwm();
		/**
		* ros::spin() will enter a loop, pumping callbacks.  With this version, all
		* callbacks will be called from within this thread (the main one).  ros::spin()
		* will exit when Ctrl-C is pressed, or the node is shutdown by the master.
		*/		
		ros::spinOnce();
		r.sleep();	
	}

	chat_msg.data="Good Bye!";
	ROS_INFO_STREAM("ddori : " << chat_msg.data);
	dolchatter_publisher.publish(chat_msg);
	return 0;
}




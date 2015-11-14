#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "std_msgs/UInt16.h"
#include "ddori/ddori_sensor.h"
#include "ddori/servo_control.h"
#include "ddori/motor_speed.h"


#include <termios.h> // for keyboard input
#include <ecl/threads.hpp>
#include <geometry_msgs/Twist.h>  // for velocity commands
#include <geometry_msgs/TwistStamped.h>  // for velocity commands


#define  KeyCode_Right		67	//     # 0x43
#define  KeyCode_Left		68	 //    # 0x44
#define  KeyCode_Up		65 	 //   # 0x41
#define  KeyCode_Down		66   //  # 0x42
#define  KeyCode_Space		32    // # 0x20
#define  KeyCode_Enable	101   // # 0x65, 'e'
#define  KeyCode_Disable	100   // # 0x64, 'd'



geometry_msgs::TwistPtr cmd;
geometry_msgs::TwistStampedPtr cmd_stamped;
double linear_vel_step, linear_vel_max;
char thread_run=1;

unsigned char servo_pos[10]={0};
float tgt_speed_left=0;
float tgt_speed_right=0;

std_msgs::Int8 light_on; 
std_msgs::Int8 ArmServoPower ;
std_msgs::Int8 GasSensorPower; 
std_msgs::Int8 PhonePower; 
std_msgs::Int8 FoscamPower; 
std_msgs::Int8 CamServoPos; 
std_msgs::Int8 ArmsPos; 
std_msgs::Int8 ArmsHug; 



ros::Subscriber sensor_subscriber;
ros::Publisher velocity_publisher;

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
ddori::ddori_sensor prev;
float spd_ms_l=0;
float spd_ms_r=0;
float last_err_l=0;
float last_err_r=0;
float Kp=500;
float Kd=50;
int16_t last_pwm_l=0;
int16_t last_pwm_r=0;

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
void sensor_Callback(const ddori::ddori_sensor::ConstPtr& msg)
{
	char display=0;
	uint16_t tick_diff=(msg->time_stamp - prev.time_stamp) & 0xffff;
	int16_t diff_enc_l=msg->left_encoder-prev.left_encoder;
	int16_t diff_enc_r=msg->right_encoder-prev.right_encoder;
	float move_l=ONETICK_MM * diff_enc_l  ;
	float move_r= ONETICK_MM * diff_enc_r;
	float spd_l = move_l *  (1000.0/tick_diff); // mm /s
	float spd_r = move_r *  (1000.0/tick_diff) ; // mm/s
	
	spd_ms_l =spd_l / 1000;	// m/s
	spd_ms_r =spd_r / 1000;	// m/s
	
	if (msg->voltage*1.0 > prev.voltage*1.05 || msg->voltage*1.0 < prev.voltage*0.95)  display=1;
	if (msg->current*1.0 > prev.current*1.05 || msg->current*1.0 < prev.current*0.95)  display=1;
//	if (msg->left_pwm != prev.left_pwm  || msg->right_pwm != prev.right_pwm ) display=1;
	if (msg->left_encoder != prev.left_encoder  || msg->right_encoder != prev.right_encoder ) display=1;
	if (msg->pir != prev.pir ) display=1;

	float error, pidTerm;
	int16_t pwm_l,pwm_r;

	if (tgt_speed_left==0) 
	{
		pwm_l=0;
	}
	else
	{
		error = tgt_speed_left - spd_ms_l;
		pidTerm = (Kp * error) + (Kd * (error -last_err_l));
		pwm_l = constrain((int16_t)(last_pwm_l+pidTerm) , -255, 255);
		last_err_l=error;
	}


	if (tgt_speed_left==0) 
	{
		pwm_r=0;
	}
	else
	{
		error = tgt_speed_right -spd_ms_r;
		pidTerm = (Kp * error) + (Kd * (error -last_err_r));
		pwm_r = constrain((int16_t)(last_pwm_r+pidTerm) , -255, 255);
		last_err_r=error;
	}
	if (tgt_speed_left<0 && pwm_l>0  || tgt_speed_left>0 && pwm_l<0) pwm_l=0;
	if (tgt_speed_right<0 && pwm_r>0  || tgt_speed_right>0 && pwm_r<0) pwm_r=0;
	
	send_speed(pwm_l , pwm_r );
		
	if (display) {
#if 0		
		ROS_INFO("%d: %6.2f[V] %d[mA]   PIR:%d  pwm=%u,%u   enc=%d,%d    speed=%d,%d   CO=%d  GAS=%d  AIR=%d ", msg->time_stamp, msg->voltage/100.0, msg->current, msg->pir, 
			(unsigned char)msg->left_pwm, (unsigned char)msg->right_pwm,
			msg->left_encoder,msg->right_encoder,
			tgt_speed_left,tgt_speed_right,
			msg->co, msg->gas, msg->air);
#else
		ROS_INFO("%d: %6.2f[V] %d[mA]  PIR:%d pwm=%d,%d enc=%d(%d),%d(%d)  tgtspd=%6.3f,%6.3f  curspd=%6.3f,%6.3f  err=%6.3f,%6.3f  tickdiff=%d  ", 
			msg->time_stamp, msg->voltage/100.0, msg->current, msg->pir, 
			pwm_l, pwm_r,
			msg->left_encoder,diff_enc_l, msg->right_encoder, diff_enc_r,
			tgt_speed_left,tgt_speed_right,
			spd_ms_l,spd_ms_r,
			last_err_l,last_err_r,
			tick_diff
			);

#endif
	}


	prev = *msg;
	last_pwm_l=pwm_l;
	last_pwm_r=pwm_r;

	

}


// Motor  37mm - 50 RPM, Tork=4.5Kg
// encoder - 1 revolution  1050 tick
// wheel radius 35mm(including TankTrack Thickness),  diameter - 70mm
// circumference = 2 pi r = 2*3.14159*35 = 220mm 
// 1 tick = 0.2095 mm


void sendMotorPwm();
         

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
	velocity_publisher = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
	light_control_publisher = n.advertise<std_msgs::Int8>("cmd_light", 1);

	ArmServoPower_publisher	= n.advertise<std_msgs::Int8>("cmd_armservo_power", 1);
	ArmServoPos_publisher	= n.advertise<ddori::servo_control>("cmd_armservo_pos", 1);
	ArmsPos_publisher			= n.advertise<std_msgs::Int8>("cmd_armspos", 1);
	ArmsHug_publisher		= n.advertise<std_msgs::Int8>("cmd_armshug", 1);
	
	GasSensorPower_publisher= n.advertise<std_msgs::Int8>("cmd_gassesnsor_power", 1);
	PhonePower_publisher		= n.advertise<std_msgs::Int8>("cmd_phone_power", 1);
	FoscamPower_publisher	= n.advertise<std_msgs::Int8>("cmd_foscam_power", 1);
	
	CamServoPos_publisher	= n.advertise<std_msgs::Int8>("cmd_camservo_pos", 1);
	WheelPWM_publisher		= n.advertise<ddori::motor_speed>("cmd_pwm", 1);
	Stop_publisher				= n.advertise<std_msgs::Int8>("cmd_stop", 1);
	AllOff_publisher			= n.advertise<std_msgs::Int8>("cmd_alloff", 1);
	LeftPwm_publisher			= n.advertise<std_msgs::Int16>("cmd_lpwm", 1);
	RightPwm_publisher		= n.advertise<std_msgs::Int16>("cmd_rpwm", 1);


	GasSensorPower.data=0;
	light_on.data=0;
	ArmsPos.data=30;
	ArmsHug.data=30;

	
	tcgetattr(key_file_descriptor, &original_terminal_state); // get terminal properties

	thread.start(&keyboardInputThread);


	ros::Rate r(10); // 10 hz
	while (ros::ok() && thread_run)
	{
		sendMotorPwm();
		/**
		* ros::spin() will enter a loop, pumping callbacks.  With this version, all
		* callbacks will be called from within this thread (the main one).  ros::spin()
		* will exit when Ctrl-C is pressed, or the node is shutdown by the master.
		*/		
		ros::spinOnce();
		r.sleep();	
	}
	thread_run=0;
	thread.cancel();
	thread.join();
	tcsetattr(key_file_descriptor, TCSANOW, &original_terminal_state);

	ROS_INFO("Good Bye!");
	return 0;
}

void sendMotorPwm()
{


}

void keyboardInputThread()
{
	struct termios raw;
	memcpy(&raw, &original_terminal_state, sizeof(struct termios));
	ros::Rate loop_rate(100);		//100Hz

	raw.c_lflag &= ~(ICANON | ECHO);
	
	// Setting a new line, then end of file
	raw.c_cc[VEOL] = 1;
	raw.c_cc[VEOF] = 2;
	tcsetattr(key_file_descriptor, TCSANOW, &raw);

	ROS_INFO("Reading from keyboard");
	ROS_INFO("---------------------------");
	ROS_INFO("Forward/back arrows : linear velocity incr/decr.");
	ROS_INFO("Right/left arrows : angular velocity incr/decr.");
	ROS_INFO("Spacebar : reset linear/angular velocities.");
	ROS_INFO("l : light on/off");
	ROS_INFO("d : disable motors.");
	ROS_INFO("e : enable motors.");
	ROS_INFO("g : gas sensor power on/off.");
	ROS_INFO("q : quit.");
	char c;

	while (ros::ok() && thread_run)
	{
		if (read(key_file_descriptor, &c, 1) < 0)
		{
			ROS_ERROR("read char failed():");
			return;
		}
		processKeyboardInput(c);
		loop_rate.sleep();
	}
}
void send_speed(int left, int  right)
{
	ddori::motor_speed ms;
	ms.left_speed=left;
	ms.right_speed=right;
	
	WheelPWM_publisher.publish(ms);		
	
}

void processKeyboardInput(char c)
{
	/*
	* Arrow keys are a bit special, they are escape characters - meaning they
	* trigger a sequence of keycodes. In this case, 'esc-[-Keycode_xxx'. We
	* ignore the esc-[ and just parse the last one. So long as we avoid using
	* the last one for its actual purpose (e.g. left arrow corresponds to
	* esc-[-D) we can keep the parsing simple.
	*/
	switch (c)
	{
		case KeyCode_Left:
		{
			if (tgt_speed_left >-0.1) tgt_speed_left-=0.01;
			if (tgt_speed_right<0.1) tgt_speed_right+=0.01;
			//incrementAngularVelocity();
			ROS_INFO("incrementAngularVelocity");
			break;
		}
		
		case KeyCode_Right:
		{
			if (tgt_speed_left <0.1) tgt_speed_left+=0.01;
			if (tgt_speed_right>-0.1) tgt_speed_right-=0.01;

			//decrementAngularVelocity();
			ROS_INFO("decrementAngularVelocity");
			break;
		}
		case KeyCode_Up:
		{
			if (tgt_speed_left <0.1) tgt_speed_left+=0.01;
			if (tgt_speed_right<0.1) tgt_speed_right+=0.01;

			//incrementLinearVelocity();
			ROS_INFO("incrementLinearVelocity");
			break;
		}
		case KeyCode_Down:
		{
			if (tgt_speed_left >-0.1) tgt_speed_left-=0.01;
			if (tgt_speed_right>-0.1) tgt_speed_right-=0.01;
			//decrementLinearVelocity();
			ROS_INFO("decrementLinearVelocity");
			break;
		}
		case KeyCode_Space:
		{
			std_msgs::Int8 Stop; 
			Stop.data=0;
			tgt_speed_left = tgt_speed_right = 0;
			send_speed(0,0 );
			//resetVelocity();
			ROS_INFO("resetVelocity");
			Stop_publisher.publish(Stop);			
			break;
		}
		case 'q':
		{
			thread_run = 0;
			std_msgs::Int8 AllOff; 
			AllOff.data=0;
			ROS_INFO("quit_requested");
			AllOff_publisher.publish(AllOff);
			break;
		}
		case 'd':
		{
			ROS_INFO("disable");
			break;
		}
		case 'a':
		{
			ArmsPos.data++;
			if (ArmsPos.data>100) ArmsPos.data=100;
			ArmsPos_publisher.publish(ArmsPos);	
			ROS_INFO("pos=%d hug=%d", ArmsPos.data, ArmsHug.data);
			break;
		}
		case 'z':
		{
			ArmsPos.data--;
			if (ArmsPos.data<0) ArmsPos.data=0;
			ArmsPos_publisher.publish(ArmsPos);	
			ROS_INFO("pos=%d hug=%d", ArmsPos.data, ArmsHug.data);
			break;
		}
		case 's':
		{
			ArmsHug.data++;
			if (ArmsHug.data>100) ArmsHug.data=100;
			ArmsHug_publisher.publish(ArmsHug);	
			ROS_INFO("pos=%d hug=%d", ArmsPos.data, ArmsHug.data);
			break;
		}
		case 'x':
		{
			ArmsHug.data--;
			if (ArmsHug.data<0) ArmsHug.data=0;
			ArmsHug_publisher.publish(ArmsHug);	
			ROS_INFO("pos=%d hug=%d", ArmsPos.data, ArmsHug.data);
			break;
		}
		case '`':
		{
			ArmServoPower.data = !ArmServoPower.data;
			
			ROS_INFO("ARM Power :%d", ArmServoPower.data);
			ArmServoPower_publisher.publish(ArmServoPower);
			break;
		}		
		case 'l':
		{
			//disable();
			light_on.data = !light_on.data;
			
			ROS_INFO("Light :%d", light_on.data);
			light_control_publisher.publish(light_on);
			break;
		}		
		case 'g':
		{
			GasSensorPower.data = !GasSensorPower.data;
			
			ROS_INFO("GAS Sensor Power :%d", GasSensorPower.data);
			GasSensorPower_publisher.publish(GasSensorPower);
			break;
		}		
		case 'u':
		{
			tgt_speed_left+=1;
			
			std_msgs::Int16 spd; 
			spd.data=tgt_speed_left;			
			ROS_INFO("Left Speed :%d", spd.data);
			LeftPwm_publisher.publish(spd);
			break;
		}
		case 'j':
		{
			tgt_speed_left-=1;
			
			std_msgs::Int16 spd; 
			spd.data=tgt_speed_left;
			
			ROS_INFO("Left Speed :%d", spd.data);
			LeftPwm_publisher.publish(spd);
			break;
		}		
		case 'i':
		{
			tgt_speed_right+=1;
			
			std_msgs::Int16 spd; 
			spd.data=tgt_speed_right;
			
			ROS_INFO("Right Speed :%d", spd.data);
			RightPwm_publisher.publish(spd);
			break;
		}
		case 'k':
		{
			tgt_speed_right-=1;
			
			std_msgs::Int16 spd; 
			spd.data=tgt_speed_right;
			
			ROS_INFO("Right Speed :%d", spd.data);
			RightPwm_publisher.publish(spd);
			break;
		}	
		case 'e':
		{
			//enable();
			ROS_INFO("enable");
			break;
		}
		default:
		{
			break;
		}
	}
}



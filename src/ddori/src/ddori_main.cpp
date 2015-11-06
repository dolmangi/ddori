#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "ddori/ddori_sensor.h"


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
std_msgs::Int8 light_on; 
ros::Publisher light_control_publisher;
ros::Subscriber sensor_subscriber;
ros::Publisher velocity_publisher;
ecl::Thread thread;
int key_file_descriptor=0;
struct termios original_terminal_state;
	
void processKeyboardInput(char c);
void keyboardInputThread();


void sensor_Callback(const ddori::ddori_sensor::ConstPtr& msg)
{
	ROS_INFO("BATTERY : %d[v] %d[a]   PIR:%d", msg->voltage, msg->current, msg->pir);
}



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
	light_on.data=0;
	
	tcgetattr(key_file_descriptor, &original_terminal_state); // get terminal properties

	thread.start(&keyboardInputThread);


	/**
	* ros::spin() will enter a loop, pumping callbacks.  With this version, all
	* callbacks will be called from within this thread (the main one).  ros::spin()
	* will exit when Ctrl-C is pressed, or the node is shutdown by the master.
	*/
	ros::spin();

	
	thread_run=0;
	thread.cancel();
	thread.join();
	tcsetattr(key_file_descriptor, TCSANOW, &original_terminal_state);

	ROS_INFO("Good Bye!");
	return 0;
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
			//incrementAngularVelocity();
			ROS_INFO("incrementAngularVelocity");
			break;
		}
		case KeyCode_Right:
		{
			//decrementAngularVelocity();
			ROS_INFO("decrementAngularVelocity");
			break;
		}
		case KeyCode_Up:
		{
			//incrementLinearVelocity();
			ROS_INFO("incrementLinearVelocity");
			break;
		}
		case KeyCode_Down:
		{
			//decrementLinearVelocity();
			ROS_INFO("decrementLinearVelocity");
			break;
		}
		case KeyCode_Space:
		{
			//resetVelocity();
			ROS_INFO("resetVelocity");
			break;
		}
		case 'q':
		{
			thread_run = 0;
			ROS_INFO("quit_requested");
			break;
		}
		case 'd':
		{
			//disable();
			ROS_INFO("disable");
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



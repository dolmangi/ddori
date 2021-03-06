

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/Int32.h>
#include <ddori_msgs/ddori_sensor.h>
#include <ddori_msgs/servo_control.h>
#include <ddori_msgs/motor_speed.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <servo.h>
#include <stdarg.h>



#define PRINTF_BUF 200 // define the tmp buffer size (change if desired)
#define MOTOR_ON_CNT 10

#define ROS
#define EYE_SLEEP_CNT_MAX		20

typedef enum _MOTOR {
	MOTOR_RIGHT=0,
	MOTOR_LEFT
} MotorSelect;

typedef enum _MOTOR_DIRECTION {
	MOTOR_BACKWARD=0,
	MOTOR_FORWARD
} MotorDirection;


typedef struct _motor_data
{
	int pwm;
	float targetSpeed;
	float last_error;
	long prev_cnt;
	int on_cnt;
} MotorData;


#define PWM_i2c_SCL   21
#define PWM_i2c_SDA   20

#define PWM0_LOW  150
#define PWM0_HIGH 600
#define PWM1_LOW  320
#define PWM1_HIGH 600
#define PWM4_LOW  150
#define PWM4_HIGH 600
#define PWM5_LOW  150
#define PWM5_HIGH 420


#define ONE_WIRE_BUS 35

#define LOOPTIME        100
//#define NUMREADINGS     10
//int readings[NUMREADINGS];   


const int right_tr1_pin = 46;
const int right_tr2_pin = 47;
const int left_tr1_pin = 45;
const int left_tr2_pin = 44;
const int front_light_pin = 49;


const int pir_det1_pin = 39;
const int pir_det2_pin = 38;
const int pir_det3_pin = 37;
const int pir_det4_pin = 36;
const int pir_power_pin = 35;

const int power_led1_pin = 42;
const int power_led2_pin = 43;
const int power_led3_pin = 40;
const int power_led4_pin = 41;

/*
const int power_camera_pin = 29;
*/
const int power_gassensor_pin = 32;


const int sonar_f_trig_pin = 30;		//front
const int sonar_f_echo_pin = 33;		//
const int sonar_l_trig_pin = 28;		//left
const int sonar_l_echo_pin = 31;
const int sonar_r_trig_pin = 26;		//right
const int sonar_r_echo_pin = 29;
const int sonar_b_trig_pin = 24;		//rear(back)
const int sonar_b_echo_pin = 27;


const int dust_sensor_pin = 25;	//Dust Sensor( Praticle sensor)
const int air_q_sensor_pin = 23;	//Air Quality Sensor

const int power_phone_pin = 50;

//const int encoder_r1_pin = 3;		//Encoder Input pin 
const int encoder_r2_pin = 16;		//Encoder Input pin 
const int encoder_r1_interrupt = 1;		//Interrupt 0


//const int encoder_l1_pin = 2;		//Encoder Input pin 
const int encoder_l2_pin = 17;		//Encoder Input pin 
const int encoder_l1_interrupt = 0;		//Interrupt 1


const int servo_arm_l_pin = 11;
const int servo_arm_r_pin = 12;

const int servo_eye_pos_pin = 4;


const int pwm_servo_output_power = 15;

const int adc_battery_V_pin = 0;    //Analog pin 0
const int adc_battery_A_pin = 1;    //Analog pin 1
const int adc_gas_senror1_pin = 2;    //Analog pin 2
const int adc_gas_senror2_pin = 3;    //Analog pin 3
const int adc_gas_senror3_pin = 4;    //Analog pin 4




MotorData m_l = { 0 };
MotorData m_r = { 0 };

int light_on = 0;
int16_t sonar_power = 0;

void getMotorData();
void SetMotorDirection(MotorSelect m, MotorDirection dir);

int arm_pos = 30;
int arm_hug = 19;
int left_arm_position = 0;
int right_arm_position = 0;
int arm_power_on = 0;
int left_arm_target = 0;
int right_arm_target = 0;

Servo eye_servo; 
int eye_servo_on = 0;
int eye_position = 150;
int eye_position_target = 0;
int eyesrvo_sleep_cnt = EYE_SLEEP_CNT_MAX;

unsigned long systick = 0;


int servo_pos[] = { 150,150,150,150,150,150,150,150 };


float Kp = 2;          //setting Kp  
float Kd = 5;            //setting Kd


#define  BAT_V_AVG_CNT  20
#define  BAT_V_R1     6.2
#define  BAT_V_R2     11
#define  UNIT_VOLT   (5.0/1024)        
#define  SENS_GAIN    50
#define  SENS_R         0.05
static int bat_v[BAT_V_AVG_CNT];
static int bat_a[BAT_V_AVG_CNT];
static int bat_v_pos = 0;

unsigned long lastMilli = 0;
unsigned long last_arm_milli = 0;


void ros_init();
void light_commandCb(const std_msgs::Int8& light_cmd);
void armservo_power_commandCb(const std_msgs::Int8& cmd);
void armservo_pos_commandCb(const ddori_msgs::servo_control& cmd);
void arms_pos_commandCb(const std_msgs::Int8& cmd);
void gassensor_power_commandCb(const std_msgs::Int8& cmd);
void arms_hug_commandCb(const std_msgs::Int8& cmd);
void phone_power_commandCb(const std_msgs::Int8& cmd);
void foscam_power_commandCb(const std_msgs::Int8& cmd);
void camservo_pos_commandCb(const std_msgs::Int16& cmd);
void wheel_stop_commandCb(const std_msgs::Int8& cmd);
void alloff_commandCb(const std_msgs::Int8& cmd);
//void wheel_pwm_commandCb(const ddori_msgs::motor_speed& cmd);
//void leftpwm_commandCb(const std_msgs::Int16& cmd);
//void rightpwm_commandCb(const std_msgs::Int16& cmd);
void sonar_power_commandCb(const std_msgs::Int16& cmd);
void powerled_onoff(int ledno, int onoff);
void SetMotorPWM(byte left, byte right);
void InitPWM();
void stop();

void rmotor_cmd_cb(const std_msgs::Int16& cmd);
void lmotor_cmd_cb(const std_msgs::Int16& cmd);









// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature temp_sensors(&oneWire);

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


ddori_msgs::ddori_sensor  sensor_msg_data;
std_msgs::String dbg_data;
std_msgs::Int16 lwheel;
std_msgs::Int16 rwheel;
void dbgprint(const char *format, ...);



#ifdef ROS
//////////////////////////////////////////////////////////////////////////////////////////////
// ROS Initialization
////////////////////////////////////////////////////////////////////////////////////////////////
class NewHardware : public ArduinoHardware
{
public:
	NewHardware() :ArduinoHardware(&Serial1, 115200) {};
};

ros::NodeHandle_<NewHardware>  nh;
ros::Publisher pub_dbg("ddori_dbg", &dbg_data);
ros::Publisher pub_ddori_sensor("ddori_sensor", &sensor_msg_data);
ros::Publisher pub_left_wheel_encoder("lwheel", &lwheel);
ros::Publisher pub_right_wheel_encoder("rwheel", &rwheel);

ros::Subscriber<std_msgs::Int16> sub_lmotor_cmd("lmotor_cmd", lmotor_cmd_cb);
ros::Subscriber<std_msgs::Int16> sub_rmotor_cmd("rmotor_cmd", rmotor_cmd_cb);

ros::Subscriber<std_msgs::Int8> subLight_cmd("cmd_light", light_commandCb);
ros::Subscriber<std_msgs::Int8> subArmServoPower_cmd("cmd_armservo_power", armservo_power_commandCb);
ros::Subscriber<ddori_msgs::servo_control> subArmServoPos_cmd("cmd_armservo_pos", armservo_pos_commandCb);
ros::Subscriber<std_msgs::Int8> subGasSensorPower_cmd("cmd_gassesnsor_power", gassensor_power_commandCb);
ros::Subscriber<std_msgs::Int8> subPhonePower_cmd("cmd_phone_power", phone_power_commandCb);
ros::Subscriber<std_msgs::Int8> subFoscamPower_cmd("cmd_foscam_power", foscam_power_commandCb);
ros::Subscriber<std_msgs::Int16> subCamservoPos_cmd("cmd_camservo_pos", camservo_pos_commandCb);
ros::Subscriber<std_msgs::Int8> subStop_cmd("cmd_stop", wheel_stop_commandCb);
ros::Subscriber<std_msgs::Int8> subAllOff_cmd("cmd_alloff", alloff_commandCb);
ros::Subscriber<std_msgs::Int8> subArmsHug_cmd("cmd_armshug", arms_hug_commandCb);
ros::Subscriber<std_msgs::Int8> subArmsPos_cmd("cmd_armspos", arms_pos_commandCb);
//ros::Subscriber<ddori_msgs::motor_speed> subPWM_cmd("cmd_pwm", wheel_pwm_commandCb);
//ros::Subscriber<std_msgs::Int16> subLeftPwm_cmd("cmd_lpwm", leftpwm_commandCb);
//ros::Subscriber<std_msgs::Int16> subRightPwm_cmd("cmd_rpwm", rightpwm_commandCb);
ros::Subscriber<std_msgs::Int16> subSonarPower_cmd("cmd_sonar_power", sonar_power_commandCb);

#endif

int eye_servo_power_control(int onoff)
{
	eye_servo_on = onoff;
	if (onoff == 1)
	{
		eye_servo.attach(servo_eye_pos_pin);
	}
	else
	{
		eye_servo.detach();
	}
	return onoff;
}

void light_commandCb(const std_msgs::Int8& light_cmd) 
{

	if (light_cmd.data == 1)
	{
		powerled_onoff(2, 1);

		dbgprint("light=%d", light_cmd.data);
	}
	else
	{
		powerled_onoff(2, 0);

		dbgprint("light=%d", light_cmd.data);
	}
}



void armservo_power_commandCb(const std_msgs::Int8& cmd) 
{
	if (cmd.data)    digitalWrite(pwm_servo_output_power, LOW);
	else             digitalWrite(pwm_servo_output_power, HIGH);
	dbgprint("armservo_power_commandCb=%d", cmd.data);
//	pwm.reset();
//	pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

}

void armservo_pos_commandCb(const ddori_msgs::servo_control& cmd)
{
	pwm.setPWM(cmd.no, 0, cmd.pos);
	dbgprint("armservo_pos_commandCb=%d", cmd.pos);
}
void arms_pos_commandCb(const std_msgs::Int8& cmd)
{
	pwm.setPWM(0, 0, map(cmd.data, 0, 100, PWM0_LOW, PWM0_HIGH));
	pwm.setPWM(4, 0, map(cmd.data, 0, 100, PWM4_HIGH, PWM4_LOW));
	dbgprint("arms_pos_commandCb=%d", cmd.data);
}
void arms_hug_commandCb(const std_msgs::Int8& cmd)
{
	pwm.setPWM(1, 0, map(cmd.data, 0, 100, PWM1_LOW, PWM1_HIGH));
	pwm.setPWM(5, 0, map(cmd.data, 0, 100, PWM5_HIGH, PWM5_LOW));
	pwm.setPWM(2, 0, map(cmd.data, 0, 100, PWM1_LOW, PWM1_HIGH));
	pwm.setPWM(6, 0, map(cmd.data, 0, 100, PWM1_LOW, PWM1_HIGH));
	dbgprint("arms_hug_commandCb=%d", cmd.data);
}

void gassensor_power_commandCb(const std_msgs::Int8& cmd)
{
	if (cmd.data)
		digitalWrite(power_gassensor_pin, LOW);
	else
		digitalWrite(power_gassensor_pin, HIGH);

	dbgprint("gassensor_power = %d", cmd.data);
}
void phone_power_commandCb(const std_msgs::Int8& cmd) 
{
	if (cmd.data)
		digitalWrite(power_phone_pin, HIGH);
	else
		digitalWrite(power_phone_pin, LOW);
	dbgprint("phone_power = %d", cmd.data);
}

void foscam_power_commandCb(const std_msgs::Int8& cmd) 
{
}

void camservo_pos_commandCb(const std_msgs::Int16& cmd) 
{
	if (!eye_servo_on) {
		eye_servo_power_control(1);
	}
	eye_position = cmd.data;
	eye_servo.write(eye_position);
	eyesrvo_sleep_cnt = EYE_SLEEP_CNT_MAX;

	dbgprint("camservo_pos = %d", eye_position);
}

void set_motor_cmd(bool right, int16_t cmd)
{
	int8_t pwm = abs(cmd);
	if (right)
	{
		if (cmd<0) SetMotorDirection(MOTOR_RIGHT, MOTOR_BACKWARD);
		else SetMotorDirection(MOTOR_RIGHT, MOTOR_FORWARD);
		OCR2B = pwm;  //right; 		// send PWM to motor
		if (cmd) dbgprint("wheel R PWM = %d", cmd);
	}
	else
	{
		if (cmd<0) SetMotorDirection(MOTOR_LEFT, MOTOR_BACKWARD);
		else SetMotorDirection(MOTOR_LEFT, MOTOR_FORWARD);
		OCR2A = pwm;  //left;		// send PWM to motor
		if (cmd) dbgprint("wheel L PWM = %d", cmd);
	}
}


void lmotor_cmd_cb(const std_msgs::Int16& cmd)
{
	m_l.pwm = cmd.data;
	m_l.on_cnt = MOTOR_ON_CNT;
	//set_motor_cmd(false,cmd.data);
}

void rmotor_cmd_cb(const std_msgs::Int16& cmd)
{
	m_r.pwm = cmd.data;
	m_r.on_cnt = MOTOR_ON_CNT;
	//set_motor_cmd(true, cmd.data);
}



void wheel_stop_commandCb(const std_msgs::Int8& cmd) {
	m_l.pwm = 0;
	m_r.pwm = 0;
	stop();
}

void alloff_commandCb(const std_msgs::Int8& cmd) {
	m_l.pwm = 0;
	m_r.pwm = 0;
	stop();
	powerled_onoff(2, 0);
	digitalWrite(pwm_servo_output_power, HIGH);
}
/*
void wheel_pwm_commandCb(const ddori_msgs::motor_speed& cmd)
{
m_l.pwm = abs(cmd.left_speed);
m_r.pwm = abs(cmd.right_speed);
SetMotorPWM(m_l.pwm, m_r.pwm);

if (cmd.left_speed<0) SetMotorDirection(MOTOR_RIGHT, MOTOR_BACKWARD);
else SetMotorDirection(MOTOR_RIGHT, MOTOR_FORWARD);

if (cmd.right_speed<0) SetMotorDirection(MOTOR_LEFT, MOTOR_BACKWARD);
else SetMotorDirection(MOTOR_LEFT, MOTOR_FORWARD);

if (cmd.left_speed || cmd.right_speed)
{
dbgprint("wheel_pwm_command = %d %d", cmd.left_speed, cmd.right_speed);
}
}
void leftpwm_commandCb(const std_msgs::Int16& cmd)
{
	m_l.pwm = cmd.data;
	SetMotorPWM(m_l.pwm, m_r.pwm);
	if (cmd.data < 0) SetMotorDirection(MOTOR_RIGHT, MOTOR_BACKWARD);
	else SetMotorDirection(MOTOR_RIGHT, MOTOR_FORWARD);
}

void rightpwm_commandCb(const std_msgs::Int16& cmd)
{
	m_r.pwm = cmd.data;
	SetMotorPWM(m_l.pwm, m_r.pwm);
	if (cmd.data < 0) SetMotorDirection(MOTOR_LEFT, MOTOR_BACKWARD);
	else SetMotorDirection(MOTOR_LEFT, MOTOR_FORWARD);
}
*/
void sonar_power_commandCb(const std_msgs::Int16& cmd)
{
	sonar_power = cmd.data;
}


//=======================================
// SETUP
//=======================================
void setup() {

#ifndef ROS
	Serial1.begin(115200);
	Serial1.println("ddori starting...");
#endif

	// set the digital pin as output:
	m_l.pwm = 0;	
	m_r.pwm = 0;

	analogRead(adc_battery_V_pin);
	analogRead(adc_battery_A_pin);

	analogRead(adc_gas_senror1_pin);
	analogRead(adc_gas_senror2_pin);
	analogRead(adc_gas_senror3_pin);


	pinMode(front_light_pin, OUTPUT);
	digitalWrite(front_light_pin, LOW);

	pinMode(pir_det1_pin, INPUT);        //PIR SENSOR
	pinMode(pir_det2_pin, INPUT);        //PIR SENSOR
	pinMode(pir_det3_pin, INPUT);        //PIR SENSOR
	pinMode(pir_det4_pin, INPUT);        //PIR SENSOR

//	pinMode(encoder_r1_pin, INPUT);      //encoder
	pinMode(encoder_r2_pin, INPUT);        //encoder

//	pinMode(encoder_l1_pin, INPUT);      //encoder
	pinMode(encoder_l2_pin, INPUT);        //encoder
										   
	//internal pullup for encoders
//	digitalWrite(encoder_r1_pin, HIGH);
	digitalWrite(encoder_r2_pin, HIGH);
//	digitalWrite(encoder_l1_pin, HIGH);
	digitalWrite(encoder_l2_pin, HIGH);

	attachInterrupt(encoder_r1_interrupt, isr_encoder_right, RISING);  //set pin no 2 as interrupt pin (INTERRUPT 0) 
	attachInterrupt(encoder_l1_interrupt, isr_encoder_left, RISING);  //set pin no 3 as interrupt pin (INTERRUPT 1) 
	//	for(int i=0; i<NUMREADINGS; i++)   readings[i] = 0;  

	pinMode(power_led1_pin, OUTPUT);
	pinMode(power_led2_pin, OUTPUT);
	pinMode(power_led3_pin, OUTPUT);
	pinMode(power_led4_pin, OUTPUT);
	digitalWrite(power_led1_pin, LOW);
	digitalWrite(power_led2_pin, LOW);
	digitalWrite(power_led3_pin, LOW);
	digitalWrite(power_led4_pin, LOW);

	pinMode(sonar_f_trig_pin, OUTPUT);
	digitalWrite(sonar_f_trig_pin, LOW);
	pinMode(sonar_f_echo_pin, INPUT);
	digitalWrite(sonar_f_echo_pin, LOW);

	pinMode(sonar_l_trig_pin, OUTPUT);
	digitalWrite(sonar_l_trig_pin, LOW);
	pinMode(sonar_l_echo_pin, INPUT);
	digitalWrite(sonar_l_echo_pin, LOW);

	pinMode(sonar_r_trig_pin, OUTPUT);
	digitalWrite(sonar_r_trig_pin, LOW);
	pinMode(sonar_r_echo_pin, INPUT);
	digitalWrite(sonar_r_echo_pin, LOW);

	pinMode(sonar_b_trig_pin, OUTPUT);
	digitalWrite(sonar_b_trig_pin, LOW);
	pinMode(sonar_b_echo_pin, INPUT);
	digitalWrite(sonar_b_echo_pin, LOW);

	pinMode(dust_sensor_pin, INPUT);
	digitalWrite(sonar_b_echo_pin, HIGH);
	pinMode(air_q_sensor_pin, INPUT);
	digitalWrite(sonar_b_echo_pin, HIGH);


	pinMode(power_phone_pin, OUTPUT);
	digitalWrite(power_phone_pin, HIGH);

/*
	pinMode(power_camera_pin, OUTPUT);
	digitalWrite(power_camera_pin, HIGH);
*/
	pinMode(power_gassensor_pin, OUTPUT);
	digitalWrite(power_gassensor_pin, HIGH);


	pinMode(pwm_servo_output_power, OUTPUT);
	digitalWrite(pwm_servo_output_power, HIGH);


	pinMode(10, OUTPUT);
	pinMode(9, OUTPUT);
	

	//init motor (Wheel) 
	pinMode(right_tr1_pin, OUTPUT);
	pinMode(right_tr2_pin, OUTPUT);
	pinMode(left_tr1_pin, OUTPUT);
	pinMode(left_tr2_pin, OUTPUT);

	digitalWrite(right_tr1_pin, HIGH);
	digitalWrite(right_tr2_pin, LOW);
	digitalWrite(left_tr1_pin, HIGH);
	digitalWrite(left_tr2_pin, LOW);


	InitPWM();
	SetMotorPWM(0, 0);


	//Init servo
	pwm.begin();
	pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

	// Start up the library
	temp_sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
	
#ifdef ROS
	ros_init();
#endif

	eye_servo_power_control(1);
	eye_servo.write(eye_position);
}






#ifdef ROS
void ros_init()
{
	//////////////////////////////////////////////////////////////////////////////////////////////
	// ROS 
	////////////////////////////////////////////////////////////////////////////////////////////////
	nh.initNode();
	nh.advertise(pub_ddori_sensor);
	nh.advertise(pub_dbg);
	nh.advertise(pub_left_wheel_encoder);
	nh.advertise(pub_right_wheel_encoder);


	nh.subscribe(sub_lmotor_cmd);
	nh.subscribe(sub_rmotor_cmd);


	nh.subscribe(subLight_cmd);
	nh.subscribe(subArmServoPower_cmd);
	nh.subscribe(subArmServoPos_cmd);
	nh.subscribe(subGasSensorPower_cmd);
	nh.subscribe(subPhonePower_cmd);
	nh.subscribe(subFoscamPower_cmd);
	nh.subscribe(subCamservoPos_cmd);

	nh.subscribe(subStop_cmd);
	nh.subscribe(subAllOff_cmd);

	nh.subscribe(subArmsHug_cmd);
	nh.subscribe(subArmsPos_cmd);

//	nh.subscribe(subPWM_cmd);
//	nh.subscribe(subLeftPwm_cmd);
//	nh.subscribe(subRightPwm_cmd);

	nh.subscribe(subSonarPower_cmd);
}
#endif

void ros_report(unsigned long cur_millis)
{

	//////////////////////////////////////////////////////////////////////////////////////////////
	// ROS 
	////////////////////////////////////////////////////////////////////////////////////////////////
	sensor_msg_data.voltage = get_battery_mv();
	sensor_msg_data.current = get_battery_ma();

	sensor_msg_data.time_stamp = cur_millis;
	sensor_msg_data.left_encoder = lwheel.data;
	sensor_msg_data.right_encoder = rwheel.data;
#ifndef ROS
	Serial1.print(" enc_l:");
	Serial1.print(sensor_msg_data.left_encoder);
	Serial1.print(" enc_r:");
	Serial1.print(sensor_msg_data.right_encoder);
#endif

	sensor_msg_data.gas_co = analogRead(adc_gas_senror3_pin);
	sensor_msg_data.gas_smoke = analogRead(adc_gas_senror2_pin);
	sensor_msg_data.gas_lpg = analogRead(adc_gas_senror1_pin);

#ifndef ROS
	Serial1.print(" co:");
	Serial1.print(sensor_msg_data.gas_co);
	Serial1.print(" smoke:");
	Serial1.print(sensor_msg_data.gas_smoke);
	Serial1.print(" lpg:");
	Serial1.print(sensor_msg_data.gas_lpg);
#endif
	sensor_msg_data.pir = 0;
	sensor_msg_data.pir |= digitalRead(pir_det1_pin) ? 1 : 0;
	sensor_msg_data.pir |= digitalRead(pir_det2_pin) ? 2 : 0;
	sensor_msg_data.pir |= digitalRead(pir_det3_pin) ? 4 : 0;
	sensor_msg_data.pir |= digitalRead(pir_det4_pin) ? 8 : 0;
	

#ifdef ROS
	pub_ddori_sensor.publish(&sensor_msg_data);
#else
	Serial1.print(" pir=");
	Serial1.println(sensor_msg_data.pir);
#endif

}

void motor_cmd()
{
	if (m_l.on_cnt>0)
	{
		m_l.on_cnt--;
		set_motor_cmd(false, m_l.pwm);
	}

	if (m_r.on_cnt>0)
	{
		m_r.on_cnt--;
		set_motor_cmd(true, m_r.pwm);
	}

	if (m_l.on_cnt <= 0) set_motor_cmd(false, 0);
	if (m_r.on_cnt <= 0) set_motor_cmd(true, 0);
}

void  report_enc()
{
	static int16_t prev_enc_l = 0;
	static int16_t prev_enc_r = 0;

	if (prev_enc_l != lwheel.data || prev_enc_r != rwheel.data)
	{
		pub_left_wheel_encoder.publish(&lwheel);
		pub_right_wheel_encoder.publish(&rwheel);
		dbgprint("enc=[%d, %d]", lwheel.data, rwheel.data);
	}

	prev_enc_l = lwheel.data;
	prev_enc_r = rwheel.data;
}

//=======================================
// LOOP
//=======================================
void loop()
{
	unsigned long cur_millis = millis();
#ifndef ROS
	getParam();                                                                 // check keyboard
#endif

	//if (arm_power_on && (cur_millis - last_arm_milli >= 10))
	//{
//		last_arm_milli = cur_millis;
//	}

	if (cur_millis - last_arm_milli >= 30)
	{
		last_arm_milli = cur_millis;
		report_enc();
	}

	if ((cur_millis - lastMilli) >= LOOPTIME)
	{                                                                                 // enter timed loop
		lastMilli = cur_millis;
		/*
		if (!sonar_power) 
			sensor_msg_data.als = 0;

		if (sonar_power & 0x01)
		{
			uint32_t duration;
			digitalWrite(sonar_f_trig_pin, LOW);
			delayMicroseconds(2);
			digitalWrite(sonar_f_trig_pin, HIGH);
			delayMicroseconds(10);
			digitalWrite(sonar_f_trig_pin, LOW);

			duration = pulseIn(sonar_f_echo_pin, HIGH, 100000);
			sensor_msg_data.sonar_front = duration / 29.41 / 2;
		}
		if (sonar_power & 0x02)
		{
			uint32_t duration;
			digitalWrite(sonar_l_trig_pin, LOW);
			delayMicroseconds(2);
			digitalWrite(sonar_l_trig_pin, HIGH);
			delayMicroseconds(10);
			digitalWrite(sonar_l_trig_pin, LOW);

			duration = pulseIn(sonar_l_echo_pin, HIGH, 100000);
			sensor_msg_data.sonar_left = duration / 29.41 / 2;
		}
		if (sonar_power & 0x04)
		{
			uint32_t duration;
			digitalWrite(sonar_r_trig_pin, LOW);
			delayMicroseconds(2);
			digitalWrite(sonar_r_trig_pin, HIGH);
			delayMicroseconds(10);
			digitalWrite(sonar_r_trig_pin, LOW);

			duration = pulseIn(sonar_r_echo_pin, HIGH, 100000);
			sensor_msg_data.sonar_right = duration / 29.41 / 2;
		}
		if (sonar_power & 0x08)
		{
			uint32_t duration;
			digitalWrite(sonar_b_trig_pin, LOW);
			delayMicroseconds(2);
			digitalWrite(sonar_b_trig_pin, HIGH);
			delayMicroseconds(10);
			digitalWrite(sonar_b_trig_pin, LOW);

			duration = pulseIn(sonar_b_echo_pin, HIGH, 100000);
			sensor_msg_data.sonar_rear = duration / 29.41 / 2;
		}
		*/
		// display data
		check_battery();

		motor_cmd();
		ros_report(cur_millis);

#ifdef ROS
		nh.spinOnce();
#endif
		if (eye_servo_on)
		{
			if (--eyesrvo_sleep_cnt < 0)
			{
				eyesrvo_sleep_cnt = EYE_SLEEP_CNT_MAX;
				eye_servo_power_control(0);

			}
		}
	}
#ifdef ROS
	nh.spinOnce();
#endif
	delay(1);
}


#ifndef ROS
String inString = "";    // string to hold input
int getParam()
{
	static std_msgs::Int8 light_cmd;
	static std_msgs::Int8 arm_powr;
	char param, cmd;
	if (!Serial1.available())    return 0;
	int inChar = Serial1.read();
	switch (inChar)
	{
	case 'l':
		light_cmd.data = light_cmd.data ? 0 : 1;
		light_commandCb(light_cmd);
		Serial1.print("Light ");
		Serial1.println(light_cmd.data);
		break;
	case ' ':
		stop();
		Serial1.print("stop!!! v=");
		Serial1.print(get_battery_mv());
		Serial1.print(",a=");
		Serial1.println(get_battery_ma());
		break;
	case 'p':
		arm_powr.data = 0;
		armservo_power_commandCb(arm_powr);
		Serial1.print("Arm Servo Power ");
		Serial1.println(arm_powr.data);
		break;
	case 'P':
		arm_powr.data = 1;
		armservo_power_commandCb(arm_powr);
		Serial1.print("Arm Servo Power ");
		Serial1.println(arm_powr.data);
		break;
	}
	/*
		void armservo_power_commandCb(const std_msgs::Int8& cmd);
		void armservo_pos_commandCb(const ddori_msgs::servo_control& cmd);
		void arms_pos_commandCb(const std_msgs::Int8& cmd);
		void gassensor_power_commandCb(const std_msgs::Int8& cmd);
		void arms_hug_commandCb(const std_msgs::Int8& cmd);
		void phone_power_commandCb(const std_msgs::Int8& cmd);
		void foscam_power_commandCb(const std_msgs::Int8& cmd);
		void camservo_pos_commandCb(const std_msgs::Int16& cmd);
		void wheel_pwm_commandCb(const ddori_msgs::motor_speed& cmd);
		void wheel_stop_commandCb(const std_msgs::Int8& cmd);
		void alloff_commandCb(const std_msgs::Int8& cmd);
		void leftpwm_commandCb(const std_msgs::Int16& cmd);
		void rightpwm_commandCb(const std_msgs::Int16& cmd);
		void sonar_power_commandCb(const std_msgs::Int16& cmd);
	*/
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void isr_encoder_right() {         //Read Encoder
	if (digitalRead(encoder_r2_pin) == HIGH)
	{
		rwheel.data--;
	}
	else {
		rwheel.data++;
	}

}
void isr_encoder_left() {         //Read Encoder
	if (digitalRead(encoder_l2_pin) == LOW)
	{
		lwheel.data--;
	}
	else {
		lwheel.data++;
	}
}


int check_battery()
{
	int pos = bat_v_pos++ % BAT_V_AVG_CNT;
	bat_v[pos] = analogRead(adc_battery_V_pin);
	bat_a[pos] = analogRead(adc_battery_A_pin);
}


///////////////****************************************************//////////////////
int get_battery_mv()
{
	int i = 0;
	float tot = 0.0;
	float avg = 0.0;
	float vsens = 0.0;
	int vout = 0;
	int cnt = bat_v_pos > BAT_V_AVG_CNT ? BAT_V_AVG_CNT : bat_v_pos;

	if (cnt == 0)
		return 0;

	for (i = 0; i < cnt; i++)
		tot += bat_v[i];

	avg = tot / cnt;
	vsens = avg * UNIT_VOLT;
	vout = (int)(100 * vsens*(BAT_V_R1 + BAT_V_R2) / BAT_V_R1);
	return vout;
}

int get_battery_ma()
{
	int i = 0;
	float tot = 0.0;
	float avg = 0.0;
	float vsens = 0.0;
	int iout = 0;
	int cnt = bat_v_pos > BAT_V_AVG_CNT ? BAT_V_AVG_CNT : bat_v_pos;

	if (cnt == 0)
		return 0;

	for (i = 0; i < cnt; i++)
		tot += bat_a[i];

	avg = tot / cnt;
	vsens = avg * UNIT_VOLT / SENS_GAIN;
	iout = (int)(1000 * vsens / SENS_R);
	return iout;
}



void stop()
{
	digitalWrite(right_tr1_pin, LOW);
	digitalWrite(right_tr2_pin, LOW);
	digitalWrite(left_tr1_pin, LOW);
	digitalWrite(left_tr2_pin, LOW);
	SetMotorPWM(0, 0); // send PWM to motor
}

void powerled_onoff(int ledno, int onoff)
{
	switch (ledno)
	{
	case 1:
		digitalWrite(power_led1_pin, (onoff ? HIGH : LOW));
		break;
	case 2:
		digitalWrite(power_led2_pin, (onoff ? HIGH : LOW));
		break;
	case 3:
		digitalWrite(power_led3_pin, (onoff ? HIGH : LOW));
		break;
	case 4:
		digitalWrite(power_led4_pin, (onoff ? HIGH : LOW));
		break;
	}
}



void SetMotorDirection(MotorSelect m, MotorDirection dir)
{
	if (m == MOTOR_RIGHT)
	{
		if (dir == MOTOR_BACKWARD)
		{
			digitalWrite(right_tr1_pin, HIGH);
			digitalWrite(right_tr2_pin, LOW);
		}
		else
		{
			digitalWrite(right_tr1_pin, LOW);
			digitalWrite(right_tr2_pin, HIGH);
		}
	}
	else
	{
		if (dir == MOTOR_BACKWARD)
		{
			digitalWrite(left_tr1_pin, HIGH);
			digitalWrite(left_tr2_pin, LOW);
		}
		else
		{
			digitalWrite(left_tr1_pin, LOW);
			digitalWrite(left_tr2_pin, HIGH);
		}

	}
}

void InitPWM()
{
	TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);

	int myEraser = 7;             // this is 111 in binary and is used as an eraser
	TCCR2B &= ~myEraser;   // this operation (AND plus NOT),  set the three bits in TCCR2B to 0


						   //TCCR2B
						   //              7 bit     6 bit       5 bit     4 bit       3 bit       2 bit         1 bit        0 bit 
						   //TCCR2B    FOC2A	FOC2B     -         -           WGM22   CS22        CS21        CS20 

						   //CS22	 CS21 	 CS20 	 DESCRIPTION
						   //0	0 	0 	 Timer/Counter2 Disabled 
						   //0	0 	1 	 No Prescaling
						   //0	1 	0 	 Clock / 8
						   //0	1 	1 	 Clock / 32
						   //1	0 	0 	 Clock / 64
						   //1	0 	1 	 Clock / 128
						   //1	1 	0 	 Clock / 256
						   //1	1 	1 	 Clock / 1024
	int myPrescaler = 1;         // this could be a number in [1 , 6]. In this case, 3 corresponds in binary to 011.   
	TCCR2B |= myPrescaler;  //this operation (OR), replaces the last three bits in TCCR2B with our new value 011

}

void SetMotorPWM(byte left, byte right)
{
	OCR2B = right; 		// send PWM to motor
	OCR2A = left;		// send PWM to motor
}

void dbgprint(const char *format, ...)
{
	char dbgbuf[PRINTF_BUF];
	va_list ap;
	va_start(ap, format);
	vsnprintf(dbgbuf, sizeof(dbgbuf), format, ap);

#ifdef ROS
	dbg_data.data = dbgbuf;
	pub_dbg.publish(&dbg_data);
#else
#endif
	va_end(ap);

}

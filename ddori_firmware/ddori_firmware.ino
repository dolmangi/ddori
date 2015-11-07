

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/Int32.h>
#include <ddori/ddori_sensor.h>
#include <ddori/servo_control.h>
#include <ddori/motor_speed.h>
//#include <Servo.h> 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <OneWire.h>
#include <DallasTemperature.h>


const int left_tr1_pin  = 46;
const int left_tr2_pin  = 47;
const int right_tr1_pin  = 45;
const int right_tr2_pin  = 44;
const int front_light_pin = 49;


const int pir_det1_pin  = 39;
const int pir_det2_pin  = 38;
const int pir_det3_pin  = 37;
const int pir_det4_pin  = 36;
const int pir_power_pin  = 35;

const int power_led1_pin = 42;
const int power_led2_pin = 43;
const int power_led3_pin = 40;
const int power_led4_pin = 41;

const int power_phone_pin = 28;
const int power_camera_pin = 29;

const int encoder_r1_pin = 2;		//Encoder Input pin 
const int encoder_r2_pin = 17;		//Encoder Input pin 
const int encoder_r1_interrupt = 0;		//Interrupt 0


const int encoder_l1_pin = 3;		//Encoder Input pin 
const int encoder_l2_pin = 16;		//Encoder Input pin 
const int encoder_l1_interrupt = 1;		//Interrupt 1


const int servo_arm_l_pin 	= 11;
const int servo_arm_r_pin 	= 12;
const int servo_eye_pos_pin = 4;  


#define PWM_i2c_SCL   21
#define PWM_i2c_SDA   20
const int pwm_servo_output_power = 15;  

const int adc_battery_V_pin       = 0;    //Analog pin 0
const int adc_battery_A_pin       = 1;    //Analog pin 1


#define PWM0_LOW  150
#define PWM0_HIGH 600
#define PWM1_LOW  320
#define PWM1_HIGH 600
#define PWM4_LOW  150
#define PWM4_HIGH 600
#define PWM5_LOW  150
#define PWM5_HIGH 420


#define ONE_WIRE_BUS 34


// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature temp_sensors(&oneWire);

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int arm_pos=30;
int arm_hug=19;
int left_arm_position=0;
int right_arm_position=0;
int arm_power_on=0;
int left_arm_target=0;
int right_arm_target=0;

int eye_servo_on=0;
int eye_position=150;
int eye_position_target=0;

unsigned long systick=0;

#define LOOPTIME        100                 
//#define NUMREADINGS     10
//int readings[NUMREADINGS];   

int speed_req_l = 0;                            // Set Point)
int speed_req_r = 0;                            // Set Point)

int speed_act_l = 0;                              //actual value
int speed_act_r = 0;                              //actual value

int PWM_val_l = 0;                             
int PWM_val_r = 0;                             

int servo_pos[]={150,150,150,150,150,150,150,150};

volatile long count_l = 0; // revolution counter
volatile long count_r = 0; // revolution counter

//volatile int count1_l = 0; // revolution counter for position
//volatile int count1_r = 0; // revolution counter for position
//volatile int count1_l = 0; // revolution counter for position
//volatile int count1_r = 0; // revolution counter for position


float Kp = 0.1;          //setting Kp  
float Kd = 1;            //setting Kd


String inString = "";    // string to hold input
int current_running=0;
int current_speed=100;
int light_on=0;

int updatePid_l(int command, int targetValue, int currentValue);   
void getMotorData();


//////////////////////////////////////////////////////////////////////////////////////////////
// ROS Initialization
////////////////////////////////////////////////////////////////////////////////////////////////
class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial1, 115200){};
};
ros::NodeHandle_<NewHardware>  nh;
ddori::ddori_sensor  sensor_msg_data;

ros::Publisher pub_ddori_sensor("ddori_sensor", &sensor_msg_data);


void light_commandCb( const std_msgs::Int8& light_cmd){
    if (light_cmd.data==1)
        powerled_onoff( 2,1);
     else
        powerled_onoff( 2,0);
}


void armservo_power_commandCb( const std_msgs::Int8& cmd){
    if (cmd.data)    digitalWrite(pwm_servo_output_power, LOW);
    else             digitalWrite(pwm_servo_output_power, HIGH);
}

void armservo_pos_commandCb( const ddori::servo_control& cmd) {
    pwm.setPWM(cmd.no, 0, cmd.pos);
}
void arms_pos_commandCb( const std_msgs::Int8& cmd)
{
    pwm.setPWM(0, 0, map(cmd.data,0,100,PWM0_LOW, PWM0_HIGH));
    pwm.setPWM(4, 0, map(cmd.data,0,100,PWM4_HIGH, PWM4_LOW));      
}
void arms_hug_commandCb( const std_msgs::Int8& cmd)
{
    pwm.setPWM(1, 0, map(cmd.data,0,100,PWM1_LOW, PWM1_HIGH));
    pwm.setPWM(5, 0, map(cmd.data,0,100,PWM5_HIGH, PWM5_LOW));        
}

void gassensor_power_commandCb( const std_msgs::Int8& cmd){
}
void phone_power_commandCb( const std_msgs::Int8& cmd){
}
void foscam_power_commandCb( const std_msgs::Int8& cmd){
}
void camservo_pos_commandCb( const std_msgs::Int8& cmd){
}

void wheel_pwm_commandCb( const ddori::motor_speed& cmd)  {

    if (cmd.left_dir) {
        digitalWrite(left_tr1_pin, LOW);
        digitalWrite(left_tr2_pin, HIGH);
    }   else {
        digitalWrite(left_tr1_pin, HIGH);
        digitalWrite(left_tr2_pin, LOW);
    }

    if (cmd.right_dir) {
        digitalWrite(right_tr1_pin, LOW);
        digitalWrite(right_tr2_pin, HIGH);      
    }   else {
        digitalWrite(right_tr1_pin, HIGH);
        digitalWrite(right_tr2_pin, LOW);      
    }
    speed_req_l=cmd.left_speed;
    speed_req_r=cmd.right_speed;
}

void wheel_stop_commandCb( const std_msgs::Int8& cmd){
    speed_req_l = 0;
    speed_req_r = 0;
    stop();
}

void alloff_commandCb( const std_msgs::Int8& cmd){
    speed_req_l = 0;
    speed_req_r = 0;
    stop();
    powerled_onoff( 2,0);    
    digitalWrite(pwm_servo_output_power, HIGH);
}


ros::Subscriber<std_msgs::Int8> subLight_cmd("cmd_light", light_commandCb );
ros::Subscriber<std_msgs::Int8> subArmServoPower_cmd("cmd_armservo_power", armservo_power_commandCb   );
ros::Subscriber<ddori::servo_control> subArmServoPos_cmd("cmd_armservo_pos",   armservo_pos_commandCb );
ros::Subscriber<std_msgs::Int8> subGasSensorPower_cmd("cmd_gassesnsor_power", gassensor_power_commandCb   );
ros::Subscriber<std_msgs::Int8> subPhonePower_cmd("cmd_phone_power",   phone_power_commandCb );
ros::Subscriber<std_msgs::Int8> subFoscamPower_cmd("cmd_foscam_power",   foscam_power_commandCb );
ros::Subscriber<std_msgs::Int8> subCamservoPos_cmd("cmd_camservo_pos",   camservo_pos_commandCb );
ros::Subscriber<ddori::motor_speed> subPWM_cmd("cmd_pwm",   wheel_pwm_commandCb );
ros::Subscriber<std_msgs::Int8> subStop_cmd("cmd_stop",   wheel_stop_commandCb );
ros::Subscriber<std_msgs::Int8> subAllOff_cmd("cmd_alloff",   alloff_commandCb );
ros::Subscriber<std_msgs::Int8> subArmsHug_cmd("cmd_armshug",   arms_hug_commandCb );
ros::Subscriber<std_msgs::Int8> subArmsPos_cmd("cmd_armspos",   arms_pos_commandCb );




//=======================================
// SETUP
//=======================================
void setup() {
    // set the digital pin as output:

    analogRead(adc_battery_V_pin); 
    analogRead(adc_battery_A_pin); 


    pinMode(left_tr1_pin, OUTPUT);      
    pinMode(left_tr2_pin, OUTPUT);      
    pinMode(right_tr1_pin, OUTPUT);      
    pinMode(right_tr2_pin, OUTPUT);     

    pinMode(front_light_pin, OUTPUT);      

    pinMode(encoder_r1_pin, INPUT);      //encoder
    pinMode(encoder_r2_pin, INPUT);        //encoder

    pinMode(encoder_l1_pin, INPUT);      //encoder
    pinMode(encoder_l2_pin, INPUT);        //encoder

    pinMode(pir_det1_pin, INPUT);        //PIR SENSOR
    pinMode(pir_det2_pin, INPUT);        //PIR SENSOR
    pinMode(pir_det3_pin, INPUT);        //PIR SENSOR
    pinMode(pir_det4_pin, INPUT);        //PIR SENSOR
  
    //internal pullup for encoders
    digitalWrite(encoder_r1_pin, HIGH);                      
    digitalWrite(encoder_r2_pin, HIGH);
    digitalWrite(encoder_l1_pin, HIGH);                      
    digitalWrite(encoder_l2_pin, HIGH);

    attachInterrupt(encoder_r1_interrupt, rencoder_r1, RISING );  //set pin no 2 as interrupt pin (INTERRUPT 0) 
    attachInterrupt(encoder_l1_interrupt, rencoder_l1, RISING );  //set pin no 3 as interrupt pin (INTERRUPT 1) 
    //	for(int i=0; i<NUMREADINGS; i++)   readings[i] = 0;  

    pinMode(power_led1_pin, OUTPUT);      
    pinMode(power_led2_pin, OUTPUT);      
    pinMode(power_led3_pin, OUTPUT);      
    pinMode(power_led4_pin, OUTPUT);    
    digitalWrite(power_led1_pin, LOW);
    digitalWrite(power_led2_pin, LOW);
    digitalWrite(power_led3_pin, LOW);
    digitalWrite(power_led4_pin, LOW);

    pinMode(power_phone_pin, OUTPUT);    
    digitalWrite(power_phone_pin, HIGH);

    pinMode(power_camera_pin, OUTPUT);    
    digitalWrite(power_camera_pin, HIGH);

    
    pinMode(pwm_servo_output_power, OUTPUT);    
    digitalWrite(pwm_servo_output_power, HIGH);


    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);

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

    digitalWrite(left_tr1_pin, HIGH);
    digitalWrite(left_tr2_pin, LOW);
    digitalWrite(right_tr1_pin, HIGH);
    digitalWrite(right_tr2_pin, LOW);
    digitalWrite(front_light_pin, LOW);



    pwm.begin();
    pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
    
    // Start up the library
    temp_sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement

    //////////////////////////////////////////////////////////////////////////////////////////////
    // ROS 
    ////////////////////////////////////////////////////////////////////////////////////////////////
    nh.initNode();
    nh.advertise(pub_ddori_sensor);

    nh.subscribe(subLight_cmd);   
    nh.subscribe(subArmServoPower_cmd);
    nh.subscribe(subArmServoPos_cmd);
    nh.subscribe(subGasSensorPower_cmd);
    nh.subscribe(subPhonePower_cmd);
    nh.subscribe(subFoscamPower_cmd);
    nh.subscribe(subCamservoPos_cmd);
    nh.subscribe(subPWM_cmd);
    nh.subscribe(subStop_cmd);
    nh.subscribe(subAllOff_cmd);    
    nh.subscribe(subArmsHug_cmd);
    nh.subscribe(subArmsPos_cmd);
    
    
    //	Serial1.begin(57600);
    //Serial1.println("ddori starting...");	
}



long enc_cnt_diff_l=0;
long enc_cnt_diff_r=0;
unsigned long lastMilli = 0;                   
unsigned long lastMilliPrint = 0;     
static int ld=0;
static int rd=0;
int off_flag=0;
unsigned long last_arm_milli = 0;     
//=======================================
// LOOP
//=======================================
void loop()
{
	unsigned long cur_millis=millis();
	//getParam();                                                                 // check keyboard

	if (arm_power_on && (cur_millis-last_arm_milli >= 10))
	{
		last_arm_milli=cur_millis;
	}	

	if((cur_millis-lastMilli) >= LOOPTIME)   
	{                                                                                 // enter timed loop
		lastMilli = cur_millis;
		
		getMotorData();                                                          // calculate speed

		PWM_val_l= updatePid(PWM_val_l, speed_req_l, speed_act_l, 0);         // compute PWM value
		PWM_val_r= updatePid(PWM_val_r, speed_req_r, speed_act_r, 1);         // compute PWM value

		OCR2B = PWM_val_l; 		// send PWM to motor
		OCR2A = PWM_val_r;		// send PWM to motor
		
                
    // display data
    check_battery();
            
    //////////////////////////////////////////////////////////////////////////////////////////////
    // ROS 
    ////////////////////////////////////////////////////////////////////////////////////////////////
    sensor_msg_data.voltage= get_battery_mv();
    sensor_msg_data.current=get_battery_ma();
    
    sensor_msg_data.time_stamp=cur_millis;
    sensor_msg_data.left_encoder=speed_act_l;
    sensor_msg_data.right_encoder=speed_act_r;
    sensor_msg_data.left_pwm=PWM_val_l;
    sensor_msg_data.right_pwm=PWM_val_r;
    
    sensor_msg_data.pir = 0;
    sensor_msg_data.pir |= digitalRead(pir_det1_pin) ? 1 : 0;
    sensor_msg_data.pir |= digitalRead(pir_det2_pin) ? 2 : 0;
    sensor_msg_data.pir |= digitalRead(pir_det3_pin) ? 4 : 0;
    sensor_msg_data.pir |= digitalRead(pir_det4_pin) ? 8 : 0;
    //Serial1.print("pir="); Serial1.println(sensor_msg_data.pir);
      
    pub_ddori_sensor.publish(&sensor_msg_data);

/*    

    Serial1.print("Requesting temperatures...");
    temp_sensors.requestTemperatures();         // Send the command to get temperatures
    Serial1.println("DONE");
    Serial1.print("Temperature for Device 1 is: ");
    Serial1.print(temp_sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
*/
/*
    Serial1.print("SP:");			Serial1.print(speed_req_l);  	Serial1.print(",");		Serial1.print(speed_req_r); 
    Serial1.print("  RPM:");		Serial1.print(speed_act_l);		Serial1.print(",");		Serial1.print(speed_act_r); 
    Serial1.print("  PWM:");		Serial1.print(PWM_val_l);   	Serial1.print(",");		Serial1.print(PWM_val_r); 
    Serial1.print("  ENC:");	Serial1.print(enc_cnt_diff_l);  		Serial1.print(",");		Serial1.print(enc_cnt_diff_r); 
    Serial1.print("  DIR:");	Serial1.print(ld==1?"F":"B");  		Serial1.print(",");		Serial1.print(rd==1?"F":"B"); 
    Serial1.print("  kp:");			Serial1.print(Kp);
    Serial1.print("  kd:");			Serial1.println(Kd);          
    //        printMotorInfo();                            
*/

  }
  nh.spinOnce();
  delay(1);
}

#define  BAT_V_AVG_CNT  20
#define  BAT_V_R1     6.2
#define  BAT_V_R2     11
#define  UNIT_VOLT   (5.0/1024)        
#define  SENS_GAIN    50
#define  SENS_R         0.05
static int bat_v[BAT_V_AVG_CNT];
static int bat_a[BAT_V_AVG_CNT];
static int bat_v_pos=0;

int check_battery()
{
    int pos=bat_v_pos++ % BAT_V_AVG_CNT;
    bat_v[pos]=analogRead(adc_battery_V_pin); 
    bat_a[pos]=analogRead(adc_battery_A_pin); 
}


///////////////****************************************************//////////////////
int get_battery_mv()
{
    int i=0;
    float tot=0.0;
    float avg=0.0;
    float vsens=0.0;
    int vout=0;
    int cnt= bat_v_pos > BAT_V_AVG_CNT ? BAT_V_AVG_CNT : bat_v_pos;
    
    if (cnt==0)
        return 0;
        
    for (i=0;i<cnt;i++)
        tot += bat_v[i];
    
    avg=tot/cnt;
    vsens = avg * UNIT_VOLT;
    vout = (int) (100 * vsens*(BAT_V_R1+BAT_V_R2)/BAT_V_R1);
    return vout;    
}

int get_battery_ma()
{
    int i=0;
    float tot=0.0;
    float avg=0.0;
    float vsens=0.0;
    int iout=0;
    int cnt= bat_v_pos > BAT_V_AVG_CNT ? BAT_V_AVG_CNT : bat_v_pos;
    
    if (cnt==0)
        return 0;
        
    for (i=0;i<cnt;i++)
        tot += bat_a[i];
    
    avg=tot/cnt;
    vsens = avg * UNIT_VOLT / SENS_GAIN;
    iout = (int) (1000 * vsens/SENS_R );
    return iout;    
}


/*
void getMotorData()  {                                                        // calculate speed, volts and Amps
static long countAnt = 0;                                                   // last count
  speed_act = ((count - countAnt)*(60*(1000/LOOPTIME)))/(16*29);          // 16 pulses X 29 gear ratio = 464 counts per output shaft rev
  countAnt = count;                  
  voltage = int(analogRead(Vpin) * 3.22 * 12.2/2.2);                          // battery voltage: mV=ADC*3300/1024, voltage divider 10K+2K
  current = int(analogRead(Apin) * 3.22 * .77 *(1000.0/132.0));               // motor current - output: 130mV per Amp
  current = digital_smooth(current, readings);                                // remove signal noise
}
*/


//encoder 12 counts per revolution
//gearbox 34:1
void getMotorData()  
{                                       // calculate speed

    static long prev_count_l=0;
    static long prev_count_r=0;
    
	//Calculating the speed using encoder count
    enc_cnt_diff_l=count_l-prev_count_l;
	speed_act_l = (enc_cnt_diff_l*(60*(1000/LOOPTIME)))/(34*12);   
    prev_count_l = count_l;
	//count_l = 0;                                           //setting count value to last count

    enc_cnt_diff_r=count_r-prev_count_r;
	speed_act_r  = (enc_cnt_diff_r*(60*(1000/LOOPTIME)))/(34*12);           
	prev_count_r = count_r ;                                           //setting count value to last count

}

int updatePid(int command, int targetValue, int currentValue, int right)   
{      // compute PWM value

	float pidTerm = 0;                                                           // PID correction
	int error=0;                                  
	static int last_error_l=0;                             
	static int last_error_r=0;      
	int ret=0;	
	
	error = abs(targetValue) - abs(currentValue); 
	if (right==0)
	{
		pidTerm = (Kp * error) + (Kd * (error - last_error_l));                            
		last_error_l = error;
	}
	else
	{
		pidTerm = (Kp * error) + (Kd * (error - last_error_r));                            
		last_error_r = error;
	}
	
	ret=constrain(command + int(pidTerm), 0, 255);
	if ((speed_req_l==0 && right==0) || (speed_req_r==0 && right==1)) 		
		ret=0;
		
	if (0) //right==0)
	{
		char buf[200];
		sprintf(buf,"targetValue:%3d currentValue:%4d error:%4d command:%3d pidTerm:%3.2f ret:%3d ",
						targetValue,
						currentValue,
						error,
						command,
						pidTerm,
						ret );
		Serial1.print(buf);
	}
	
	return ret;
}


void printMotorInfo()  
{                                                     // display data
//	if((millis()-lastMilliPrint) >= LOOPTIME)   
//	{                     
//		lastMilliPrint = millis();
//		int pwm_value = PWM_val_l;
//		pwm_value = map(pwm_value, 0, 255, 0, 100);

		Serial1.print("SP:");			Serial1.print(speed_req_l);  	Serial1.print(",");		Serial1.print(speed_req_r); 
		// Serial1.print("  RPM:");		Serial1.print(speed_act_l);		Serial1.print(",");		Serial1.print(speed_act_r); 
		// Serial1.print("  PWM:");		Serial1.print(PWM_val_l);   	Serial1.print(",");		Serial1.print(PWM_val_r); 
		// Serial1.print("  ENC:");	Serial1.print(count_l);  		Serial1.print(",");		Serial1.print(count_r); 
		// Serial1.print("  DIR:");	Serial1.print(ld==1?"F":"B");  		Serial1.print(",");		Serial1.print(rd==1?"F":"B"); 
		// Serial1.print("  kp:");			Serial1.print(z`);
		// Serial1.print("  kd:");			Serial1.println(Kd);            
//	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void rencoder_r1()  {         //Read Encoder
    if (digitalRead(encoder_r2_pin)==HIGH)
    {
        count_r++;               
    }
    else {
        count_r--;               
    }
	
}
void rencoder_l1()  {         //Read Encoder
    if (digitalRead(encoder_l2_pin)==LOW)
    {
        count_l++;               
    }
    else {
        count_l--;               
    }
}


void stop()
{
	digitalWrite(left_tr1_pin, LOW);
	digitalWrite(left_tr2_pin, LOW);
	digitalWrite(right_tr1_pin, LOW);
	digitalWrite(right_tr2_pin, LOW);
	speed_req_l = 0;
	speed_req_r = 0;
	OCR2A = 0;		// send PWM to motor
	OCR2B = 0; 		// send PWM to motor
	Serial1.println("stop motor"); 
}

void powerled_onoff(int ledno,int onoff)
{
	switch(ledno)
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
int last_dir=0;
////////////////////////////////////////////////////////////////////////////////////////////////////////

int getParam()  
{
    char param, cmd;
    if(!Serial1.available())    return 0;
	int inChar = Serial1.read();
	// convert the incoming byte to a char 
	// and add it to the string:
    if (inChar=='i') {
        if (last_dir != 1) {
            digitalWrite(left_tr1_pin, LOW);
            digitalWrite(left_tr2_pin, HIGH);
            digitalWrite(right_tr1_pin, LOW);
            digitalWrite(right_tr2_pin, HIGH);           
            speed_req_l = 0;
            speed_req_r = 0;
        } 
        else {
            speed_req_l=speed_req_l+10;
            if (speed_req_l>255)    
                speed_req_l=255;
            speed_req_r=speed_req_r+10;
            if (speed_req_r>255)    
                speed_req_r=255;

        }
        last_dir=1;
    }
    else if (inChar=='m') {
        if (last_dir != 2) {
            digitalWrite(left_tr1_pin, HIGH);
            digitalWrite(left_tr2_pin, LOW);
            digitalWrite(right_tr1_pin, HIGH);
            digitalWrite(right_tr2_pin, LOW);                
            speed_req_l = 0;
            speed_req_r = 0;
        } 
        else {
            speed_req_l=speed_req_l-10;
            if (speed_req_l<-255)    
                speed_req_l=-255;
            
            speed_req_r=speed_req_r-10;
            if (speed_req_r<-255)    
                speed_req_r=-255;
        }
        last_dir=2;
    }
    else if (inChar=='k') {
        if (last_dir != 3) {
            digitalWrite(left_tr1_pin, LOW);
            digitalWrite(left_tr2_pin, HIGH);
            digitalWrite(right_tr1_pin, HIGH);
            digitalWrite(right_tr2_pin, LOW );         
            speed_req_l = 0;
            speed_req_r = 0;
        } 
        else {
            speed_req_l=speed_req_l-10;
            if (speed_req_l<-255)    
                speed_req_l=-255;

            speed_req_r=speed_req_r+10;
            if (speed_req_r>255)    
                speed_req_r=255;
        }
        last_dir=3;
    }
    else if (inChar=='j') {
        if (last_dir != 4) {
            digitalWrite(left_tr1_pin, HIGH);
            digitalWrite(left_tr2_pin, LOW);
            digitalWrite(right_tr1_pin, LOW);
            digitalWrite(right_tr2_pin, HIGH);        
            speed_req_l = 0;
            speed_req_r = 0;
        } 
        else {
            speed_req_l=speed_req_l+10;
            if (speed_req_l>255)    
                speed_req_l=255;

            speed_req_r=speed_req_r-10;
            if (speed_req_r<-255)    
                speed_req_r=-255;
        }
        last_dir=4;
    }
    /*
    else if (inChar=='a') {
        Kd=Kd+0.01;
    }    
    else if (inChar=='A') {
        Kd=Kd-0.01;
    }    
    else if (inChar=='z') {
        Kp=Kp+0.01;
    }    
    else if (inChar=='Z') {
        Kp=Kp-0.01;
    }   
    */ 
    else if (inChar=='l') {
       light_on = !light_on;
       if (light_on) {
          powerled_onoff( 2,1);
          Serial1.println("Light On!");         
       }
       else {
          powerled_onoff( 2,0);
          Serial1.println("Light Off!");         
       }
        
       
    }  
    else if (inChar=='`') {
             Serial1.println("SERVO Power On!");         
             digitalWrite(pwm_servo_output_power, LOW);
    }   
    else if (inChar=='~') {
             Serial1.println("SERVO Power OFF");         
             digitalWrite(pwm_servo_output_power, HIGH);
    }   
    else if (inChar=='1') {
          servo_pos[0]+=10;
          if (servo_pos[0]>600) servo_pos[0]=600;
          Serial1.print("Servo[0]");    Serial1.println(  servo_pos[0]);      
         pwm.setPWM(0, 0, servo_pos[0]);
    }   
    else if (inChar=='!') {
          servo_pos[0]-=10;
          if (servo_pos[0]<150) servo_pos[0]=150;
          Serial1.print("Servo[0]");    Serial1.println(  servo_pos[0]);      
         pwm.setPWM(0, 0, servo_pos[0]);
    }
    else if (inChar=='2') {
          servo_pos[1]+=10;
          if (servo_pos[1]>600) servo_pos[1]=600;
          Serial1.print("Servo[1]");    Serial1.println(  servo_pos[1]);      
         pwm.setPWM(1, 0, servo_pos[1]);
    }   
    else if (inChar=='@') {
          servo_pos[1]-=10;
          if (servo_pos[1]<150) servo_pos[1]=150;
          Serial1.print("Servo[1]");    Serial1.println(  servo_pos[1]);      
         pwm.setPWM(1, 0, servo_pos[1]);
    }  
     else if (inChar=='3') {
          servo_pos[2]+=10;
          if (servo_pos[2]>600) servo_pos[2]=600;
          Serial1.print("Servo[4]");    Serial1.println(  servo_pos[2]);      
         pwm.setPWM(4, 0, servo_pos[2]);
    }   
    else if (inChar=='#') {
          servo_pos[2]-=10;
          if (servo_pos[2]<150) servo_pos[2]=150;
          Serial1.print("Servo[4]");    Serial1.println(  servo_pos[2]);      
         pwm.setPWM(4, 0, servo_pos[2]);
    }   
    else if (inChar=='4') {
          servo_pos[3]+=10;
          if (servo_pos[3]>600) servo_pos[3]=600;
          Serial1.print("Servo[5]");    Serial1.println(  servo_pos[3]);      
         pwm.setPWM(5, 0, servo_pos[3]);
    }   
    else if (inChar=='$') {
          servo_pos[3]-=10;
          if (servo_pos[3]<150) servo_pos[3]=150;
          Serial1.print("Servo[5]");    Serial1.println(  servo_pos[3]);      
         pwm.setPWM(5, 0, servo_pos[3]);
    } 
    else if (inChar=='5') {
      eye_position -= 10;
      if ( eye_position < 150)  eye_position =150;
      pwm.setPWM(8, 0, eye_position);
      Serial1.print("CAMERA POS : ");  Serial1.println(  eye_position);      
    }   
    else if (inChar=='%') {
      eye_position += 10;
      if ( eye_position > 500)  eye_position = 500;
      pwm.setPWM(8, 0, eye_position);
      Serial1.print("CAMERA POS : ");  Serial1.println(  eye_position);      
    } 
    else if (inChar=='a') {
      arm_pos += 1;
      if ( arm_pos > 100)  arm_pos = 100;
      Serial1.print("ARM POS : ");  Serial1.println(  arm_pos);      
      pwm.setPWM(0, 0, map(arm_pos,0,100,PWM0_LOW, PWM0_HIGH));
      pwm.setPWM(4, 0, map(arm_pos,0,100,PWM4_HIGH, PWM4_LOW));
    } 
    else if (inChar=='z') {
      arm_pos -= 1;
      if ( arm_pos < 0)  arm_pos = 0;
      Serial1.print("ARM POS : ");  Serial1.println(  arm_pos);      
      pwm.setPWM(0, 0, map(arm_pos,0,100,PWM0_LOW, PWM0_HIGH));
      pwm.setPWM(4, 0, map(arm_pos,0,100,PWM4_HIGH, PWM4_LOW));      
    }     
    else if (inChar=='s') {
      arm_hug += 1;
      if ( arm_hug > 100)  arm_hug = 100;
      Serial1.print("ARM HUG : ");  Serial1.println(  arm_hug);      
      pwm.setPWM(1, 0, map(arm_hug,0,100,PWM1_LOW, PWM1_HIGH));
      pwm.setPWM(5, 0, map(arm_hug,0,100,PWM5_HIGH, PWM5_LOW));
    } 
    else if (inChar=='x') {
      arm_hug -= 1;
      if ( arm_hug < 0)  arm_hug = 0;
      Serial1.print("ARM HUG : ");  Serial1.println(  arm_hug);      
      pwm.setPWM(1, 0, map(arm_hug,0,100,PWM1_LOW, PWM1_HIGH));
      pwm.setPWM(5, 0, map(arm_hug,0,100,PWM5_HIGH, PWM5_LOW));      
    }     

    else {
        speed_req_l = 0;
        speed_req_r = 0;
        last_dir=0;

    }
}


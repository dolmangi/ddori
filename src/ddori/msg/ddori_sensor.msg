
uint16 time_stamp      # milliseconds starting when turning on Kobuki (max. 65536, then starts from 0 again)
uint8  bumper          	# see bumper states
int16 left_encoder    # accumulated ticks left wheel starting with turning on Kobuki (max. 32767)
int16 right_encoder   # accumulated ticks right wheel starting with turning on Kobuki (max. 32767)
int8   left_pwm        	# % of applied maximum voltage left wheel: -100 (max. voltage backward) to +100 (max. voltage forward)
int8   right_pwm       # % of applied maximum voltage right wheel: -100 (max. voltage backward) to +100 (max. voltage forward)
uint8  buttons         # see button states
uint8  charger         # see charger states
int16  voltage         # Battery voltage 
int16  current         # Load currnet(Power consumption)

int16 temp1 			#Temperature Sensor 1
int16 temp2			#Temperature Sensor 1
int16 temp3			#Temperature Sensor 1

int16 co				#CO gas sensor
int16 gas				#Butan Gas Sensor
int16 air				#Air Quality Sensor

int16 barometer	#Air Pressure Sensor

int8 pir					#Human body detector

int8 prx_1				#proximity sensor
int8 prx_2				#proximity sensor
int8 prx_3				#proximity sensor

int16 als				#Ambient Light Sensor


#uint8  wheel_drop      # see wheel drop sensor states
#uint8  cliff           # see cliff sensor states


uint16 time_stamp      # milliseconds starting when turning on Kobuki (max. 65536, then starts from 0 again)
uint8  bumper          	# see bumper states
int16 left_encoder    # accumulated ticks left wheel starting with turning on Kobuki (max. 32767)
int16 right_encoder   # accumulated ticks right wheel starting with turning on Kobuki (max. 32767)
uint8  buttons         # see button states
uint8  charger         # see charger states
int16  voltage         # Battery voltage 
int16  current         # Load currnet(Power consumption)

int16 temp1 			#Temperature Sensor 1
int16 temp2			#Temperature Sensor 1
int16 temp3			#Temperature Sensor 1

int16 gas_co				#CO gas sensor
int16 gas_lpg				#LPG/Butan Gas Sensor
int16 gas_smoke			#SmokeSensor
int16 air_quality			#air quality sensor
int16 dust_sensor			#dust sensor

int8 pir					#Human body detector

int8 prx_1				#proximity sensor
int8 prx_2				#proximity sensor
int8 prx_3				#proximity sensor

int16 als				#Ambient Light Sensor

int16 sonar_front
int16 sonar_left
int16 sonar_right
int16 sonar_rear


#uint8  wheel_drop      # see wheel drop sensor states
#uint8  cliff           # see cliff sensor states

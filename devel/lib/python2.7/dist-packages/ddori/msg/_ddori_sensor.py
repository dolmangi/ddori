"""autogenerated by genpy from ddori/ddori_sensor.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class ddori_sensor(genpy.Message):
  _md5sum = "19b6bb5c07861f2868728e7e06e515a5"
  _type = "ddori/ddori_sensor"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """
uint16 time_stamp      # milliseconds starting when turning on Kobuki (max. 65536, then starts from 0 again)
uint8  bumper          	# see bumper states
uint16 left_encoder    # accumulated ticks left wheel starting with turning on Kobuki (max. 65535)
uint16 right_encoder   # accumulated ticks right wheel starting with turning on Kobuki (max. 65535)
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

"""
  __slots__ = ['time_stamp','bumper','left_encoder','right_encoder','left_pwm','right_pwm','buttons','charger','voltage','current','temp1','temp2','temp3','co','gas','air','barometer','pir','prx_1','prx_2','prx_3','als']
  _slot_types = ['uint16','uint8','uint16','uint16','int8','int8','uint8','uint8','int16','int16','int16','int16','int16','int16','int16','int16','int16','int8','int8','int8','int8','int16']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       time_stamp,bumper,left_encoder,right_encoder,left_pwm,right_pwm,buttons,charger,voltage,current,temp1,temp2,temp3,co,gas,air,barometer,pir,prx_1,prx_2,prx_3,als

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ddori_sensor, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.time_stamp is None:
        self.time_stamp = 0
      if self.bumper is None:
        self.bumper = 0
      if self.left_encoder is None:
        self.left_encoder = 0
      if self.right_encoder is None:
        self.right_encoder = 0
      if self.left_pwm is None:
        self.left_pwm = 0
      if self.right_pwm is None:
        self.right_pwm = 0
      if self.buttons is None:
        self.buttons = 0
      if self.charger is None:
        self.charger = 0
      if self.voltage is None:
        self.voltage = 0
      if self.current is None:
        self.current = 0
      if self.temp1 is None:
        self.temp1 = 0
      if self.temp2 is None:
        self.temp2 = 0
      if self.temp3 is None:
        self.temp3 = 0
      if self.co is None:
        self.co = 0
      if self.gas is None:
        self.gas = 0
      if self.air is None:
        self.air = 0
      if self.barometer is None:
        self.barometer = 0
      if self.pir is None:
        self.pir = 0
      if self.prx_1 is None:
        self.prx_1 = 0
      if self.prx_2 is None:
        self.prx_2 = 0
      if self.prx_3 is None:
        self.prx_3 = 0
      if self.als is None:
        self.als = 0
    else:
      self.time_stamp = 0
      self.bumper = 0
      self.left_encoder = 0
      self.right_encoder = 0
      self.left_pwm = 0
      self.right_pwm = 0
      self.buttons = 0
      self.charger = 0
      self.voltage = 0
      self.current = 0
      self.temp1 = 0
      self.temp2 = 0
      self.temp3 = 0
      self.co = 0
      self.gas = 0
      self.air = 0
      self.barometer = 0
      self.pir = 0
      self.prx_1 = 0
      self.prx_2 = 0
      self.prx_3 = 0
      self.als = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_HB2H2b2B9h4bh.pack(_x.time_stamp, _x.bumper, _x.left_encoder, _x.right_encoder, _x.left_pwm, _x.right_pwm, _x.buttons, _x.charger, _x.voltage, _x.current, _x.temp1, _x.temp2, _x.temp3, _x.co, _x.gas, _x.air, _x.barometer, _x.pir, _x.prx_1, _x.prx_2, _x.prx_3, _x.als))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 35
      (_x.time_stamp, _x.bumper, _x.left_encoder, _x.right_encoder, _x.left_pwm, _x.right_pwm, _x.buttons, _x.charger, _x.voltage, _x.current, _x.temp1, _x.temp2, _x.temp3, _x.co, _x.gas, _x.air, _x.barometer, _x.pir, _x.prx_1, _x.prx_2, _x.prx_3, _x.als,) = _struct_HB2H2b2B9h4bh.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_HB2H2b2B9h4bh.pack(_x.time_stamp, _x.bumper, _x.left_encoder, _x.right_encoder, _x.left_pwm, _x.right_pwm, _x.buttons, _x.charger, _x.voltage, _x.current, _x.temp1, _x.temp2, _x.temp3, _x.co, _x.gas, _x.air, _x.barometer, _x.pir, _x.prx_1, _x.prx_2, _x.prx_3, _x.als))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 35
      (_x.time_stamp, _x.bumper, _x.left_encoder, _x.right_encoder, _x.left_pwm, _x.right_pwm, _x.buttons, _x.charger, _x.voltage, _x.current, _x.temp1, _x.temp2, _x.temp3, _x.co, _x.gas, _x.air, _x.barometer, _x.pir, _x.prx_1, _x.prx_2, _x.prx_3, _x.als,) = _struct_HB2H2b2B9h4bh.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_HB2H2b2B9h4bh = struct.Struct("<HB2H2b2B9h4bh")

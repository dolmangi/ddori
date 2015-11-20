; Auto-generated. Do not edit!


(cl:in-package ddori_msgs-msg)


;//! \htmlinclude ddori_sensor.msg.html

(cl:defclass <ddori_sensor> (roslisp-msg-protocol:ros-message)
  ((time_stamp
    :reader time_stamp
    :initarg :time_stamp
    :type cl:fixnum
    :initform 0)
   (bumper
    :reader bumper
    :initarg :bumper
    :type cl:fixnum
    :initform 0)
   (left_encoder
    :reader left_encoder
    :initarg :left_encoder
    :type cl:fixnum
    :initform 0)
   (right_encoder
    :reader right_encoder
    :initarg :right_encoder
    :type cl:fixnum
    :initform 0)
   (buttons
    :reader buttons
    :initarg :buttons
    :type cl:fixnum
    :initform 0)
   (charger
    :reader charger
    :initarg :charger
    :type cl:fixnum
    :initform 0)
   (voltage
    :reader voltage
    :initarg :voltage
    :type cl:fixnum
    :initform 0)
   (current
    :reader current
    :initarg :current
    :type cl:fixnum
    :initform 0)
   (temp1
    :reader temp1
    :initarg :temp1
    :type cl:fixnum
    :initform 0)
   (temp2
    :reader temp2
    :initarg :temp2
    :type cl:fixnum
    :initform 0)
   (temp3
    :reader temp3
    :initarg :temp3
    :type cl:fixnum
    :initform 0)
   (co
    :reader co
    :initarg :co
    :type cl:fixnum
    :initform 0)
   (gas
    :reader gas
    :initarg :gas
    :type cl:fixnum
    :initform 0)
   (air
    :reader air
    :initarg :air
    :type cl:fixnum
    :initform 0)
   (barometer
    :reader barometer
    :initarg :barometer
    :type cl:fixnum
    :initform 0)
   (pir
    :reader pir
    :initarg :pir
    :type cl:fixnum
    :initform 0)
   (prx_1
    :reader prx_1
    :initarg :prx_1
    :type cl:fixnum
    :initform 0)
   (prx_2
    :reader prx_2
    :initarg :prx_2
    :type cl:fixnum
    :initform 0)
   (prx_3
    :reader prx_3
    :initarg :prx_3
    :type cl:fixnum
    :initform 0)
   (als
    :reader als
    :initarg :als
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ddori_sensor (<ddori_sensor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ddori_sensor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ddori_sensor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ddori_msgs-msg:<ddori_sensor> is deprecated: use ddori_msgs-msg:ddori_sensor instead.")))

(cl:ensure-generic-function 'time_stamp-val :lambda-list '(m))
(cl:defmethod time_stamp-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:time_stamp-val is deprecated.  Use ddori_msgs-msg:time_stamp instead.")
  (time_stamp m))

(cl:ensure-generic-function 'bumper-val :lambda-list '(m))
(cl:defmethod bumper-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:bumper-val is deprecated.  Use ddori_msgs-msg:bumper instead.")
  (bumper m))

(cl:ensure-generic-function 'left_encoder-val :lambda-list '(m))
(cl:defmethod left_encoder-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:left_encoder-val is deprecated.  Use ddori_msgs-msg:left_encoder instead.")
  (left_encoder m))

(cl:ensure-generic-function 'right_encoder-val :lambda-list '(m))
(cl:defmethod right_encoder-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:right_encoder-val is deprecated.  Use ddori_msgs-msg:right_encoder instead.")
  (right_encoder m))

(cl:ensure-generic-function 'buttons-val :lambda-list '(m))
(cl:defmethod buttons-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:buttons-val is deprecated.  Use ddori_msgs-msg:buttons instead.")
  (buttons m))

(cl:ensure-generic-function 'charger-val :lambda-list '(m))
(cl:defmethod charger-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:charger-val is deprecated.  Use ddori_msgs-msg:charger instead.")
  (charger m))

(cl:ensure-generic-function 'voltage-val :lambda-list '(m))
(cl:defmethod voltage-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:voltage-val is deprecated.  Use ddori_msgs-msg:voltage instead.")
  (voltage m))

(cl:ensure-generic-function 'current-val :lambda-list '(m))
(cl:defmethod current-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:current-val is deprecated.  Use ddori_msgs-msg:current instead.")
  (current m))

(cl:ensure-generic-function 'temp1-val :lambda-list '(m))
(cl:defmethod temp1-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:temp1-val is deprecated.  Use ddori_msgs-msg:temp1 instead.")
  (temp1 m))

(cl:ensure-generic-function 'temp2-val :lambda-list '(m))
(cl:defmethod temp2-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:temp2-val is deprecated.  Use ddori_msgs-msg:temp2 instead.")
  (temp2 m))

(cl:ensure-generic-function 'temp3-val :lambda-list '(m))
(cl:defmethod temp3-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:temp3-val is deprecated.  Use ddori_msgs-msg:temp3 instead.")
  (temp3 m))

(cl:ensure-generic-function 'co-val :lambda-list '(m))
(cl:defmethod co-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:co-val is deprecated.  Use ddori_msgs-msg:co instead.")
  (co m))

(cl:ensure-generic-function 'gas-val :lambda-list '(m))
(cl:defmethod gas-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:gas-val is deprecated.  Use ddori_msgs-msg:gas instead.")
  (gas m))

(cl:ensure-generic-function 'air-val :lambda-list '(m))
(cl:defmethod air-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:air-val is deprecated.  Use ddori_msgs-msg:air instead.")
  (air m))

(cl:ensure-generic-function 'barometer-val :lambda-list '(m))
(cl:defmethod barometer-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:barometer-val is deprecated.  Use ddori_msgs-msg:barometer instead.")
  (barometer m))

(cl:ensure-generic-function 'pir-val :lambda-list '(m))
(cl:defmethod pir-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:pir-val is deprecated.  Use ddori_msgs-msg:pir instead.")
  (pir m))

(cl:ensure-generic-function 'prx_1-val :lambda-list '(m))
(cl:defmethod prx_1-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:prx_1-val is deprecated.  Use ddori_msgs-msg:prx_1 instead.")
  (prx_1 m))

(cl:ensure-generic-function 'prx_2-val :lambda-list '(m))
(cl:defmethod prx_2-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:prx_2-val is deprecated.  Use ddori_msgs-msg:prx_2 instead.")
  (prx_2 m))

(cl:ensure-generic-function 'prx_3-val :lambda-list '(m))
(cl:defmethod prx_3-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:prx_3-val is deprecated.  Use ddori_msgs-msg:prx_3 instead.")
  (prx_3 m))

(cl:ensure-generic-function 'als-val :lambda-list '(m))
(cl:defmethod als-val ((m <ddori_sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:als-val is deprecated.  Use ddori_msgs-msg:als instead.")
  (als m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ddori_sensor>) ostream)
  "Serializes a message object of type '<ddori_sensor>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time_stamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time_stamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bumper)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'left_encoder)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'right_encoder)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buttons)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charger)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'voltage)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'temp1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'temp2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'temp3)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'co)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gas)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'air)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'barometer)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'pir)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'prx_1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'prx_2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'prx_3)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'als)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ddori_sensor>) istream)
  "Deserializes a message object of type '<ddori_sensor>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time_stamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time_stamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bumper)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'left_encoder) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'right_encoder) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buttons)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charger)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'voltage) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'current) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temp1) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temp2) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temp3) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'co) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gas) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'air) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'barometer) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pir) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'prx_1) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'prx_2) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'prx_3) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'als) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ddori_sensor>)))
  "Returns string type for a message object of type '<ddori_sensor>"
  "ddori_msgs/ddori_sensor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ddori_sensor)))
  "Returns string type for a message object of type 'ddori_sensor"
  "ddori_msgs/ddori_sensor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ddori_sensor>)))
  "Returns md5sum for a message object of type '<ddori_sensor>"
  "3676e7aa50bcd8c89f9c5ae2f526915b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ddori_sensor)))
  "Returns md5sum for a message object of type 'ddori_sensor"
  "3676e7aa50bcd8c89f9c5ae2f526915b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ddori_sensor>)))
  "Returns full string definition for message of type '<ddori_sensor>"
  (cl:format cl:nil "~%uint16 time_stamp      # milliseconds starting when turning on Kobuki (max. 65536, then starts from 0 again)~%uint8  bumper          	# see bumper states~%int16 left_encoder    # accumulated ticks left wheel starting with turning on Kobuki (max. 32767)~%int16 right_encoder   # accumulated ticks right wheel starting with turning on Kobuki (max. 32767)~%uint8  buttons         # see button states~%uint8  charger         # see charger states~%int16  voltage         # Battery voltage ~%int16  current         # Load currnet(Power consumption)~%~%int16 temp1 			#Temperature Sensor 1~%int16 temp2			#Temperature Sensor 1~%int16 temp3			#Temperature Sensor 1~%~%int16 co				#CO gas sensor~%int16 gas				#Butan Gas Sensor~%int16 air				#Air Quality Sensor~%~%int16 barometer	#Air Pressure Sensor~%~%int8 pir					#Human body detector~%~%int8 prx_1				#proximity sensor~%int8 prx_2				#proximity sensor~%int8 prx_3				#proximity sensor~%~%int16 als				#Ambient Light Sensor~%~%~%#uint8  wheel_drop      # see wheel drop sensor states~%#uint8  cliff           # see cliff sensor states~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ddori_sensor)))
  "Returns full string definition for message of type 'ddori_sensor"
  (cl:format cl:nil "~%uint16 time_stamp      # milliseconds starting when turning on Kobuki (max. 65536, then starts from 0 again)~%uint8  bumper          	# see bumper states~%int16 left_encoder    # accumulated ticks left wheel starting with turning on Kobuki (max. 32767)~%int16 right_encoder   # accumulated ticks right wheel starting with turning on Kobuki (max. 32767)~%uint8  buttons         # see button states~%uint8  charger         # see charger states~%int16  voltage         # Battery voltage ~%int16  current         # Load currnet(Power consumption)~%~%int16 temp1 			#Temperature Sensor 1~%int16 temp2			#Temperature Sensor 1~%int16 temp3			#Temperature Sensor 1~%~%int16 co				#CO gas sensor~%int16 gas				#Butan Gas Sensor~%int16 air				#Air Quality Sensor~%~%int16 barometer	#Air Pressure Sensor~%~%int8 pir					#Human body detector~%~%int8 prx_1				#proximity sensor~%int8 prx_2				#proximity sensor~%int8 prx_3				#proximity sensor~%~%int16 als				#Ambient Light Sensor~%~%~%#uint8  wheel_drop      # see wheel drop sensor states~%#uint8  cliff           # see cliff sensor states~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ddori_sensor>))
  (cl:+ 0
     2
     1
     2
     2
     1
     1
     2
     2
     2
     2
     2
     2
     2
     2
     2
     1
     1
     1
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ddori_sensor>))
  "Converts a ROS message object to a list"
  (cl:list 'ddori_sensor
    (cl:cons ':time_stamp (time_stamp msg))
    (cl:cons ':bumper (bumper msg))
    (cl:cons ':left_encoder (left_encoder msg))
    (cl:cons ':right_encoder (right_encoder msg))
    (cl:cons ':buttons (buttons msg))
    (cl:cons ':charger (charger msg))
    (cl:cons ':voltage (voltage msg))
    (cl:cons ':current (current msg))
    (cl:cons ':temp1 (temp1 msg))
    (cl:cons ':temp2 (temp2 msg))
    (cl:cons ':temp3 (temp3 msg))
    (cl:cons ':co (co msg))
    (cl:cons ':gas (gas msg))
    (cl:cons ':air (air msg))
    (cl:cons ':barometer (barometer msg))
    (cl:cons ':pir (pir msg))
    (cl:cons ':prx_1 (prx_1 msg))
    (cl:cons ':prx_2 (prx_2 msg))
    (cl:cons ':prx_3 (prx_3 msg))
    (cl:cons ':als (als msg))
))

; Auto-generated. Do not edit!


(cl:in-package ddori-msg)


;//! \htmlinclude pir_sensor_msg.msg.html

(cl:defclass <pir_sensor_msg> (roslisp-msg-protocol:ros-message)
  ((pir_det
    :reader pir_det
    :initarg :pir_det
    :type cl:fixnum
    :initform 0))
)

(cl:defclass pir_sensor_msg (<pir_sensor_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pir_sensor_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pir_sensor_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ddori-msg:<pir_sensor_msg> is deprecated: use ddori-msg:pir_sensor_msg instead.")))

(cl:ensure-generic-function 'pir_det-val :lambda-list '(m))
(cl:defmethod pir_det-val ((m <pir_sensor_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:pir_det-val is deprecated.  Use ddori-msg:pir_det instead.")
  (pir_det m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pir_sensor_msg>) ostream)
  "Serializes a message object of type '<pir_sensor_msg>"
  (cl:let* ((signed (cl:slot-value msg 'pir_det)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pir_sensor_msg>) istream)
  "Deserializes a message object of type '<pir_sensor_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pir_det) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pir_sensor_msg>)))
  "Returns string type for a message object of type '<pir_sensor_msg>"
  "ddori/pir_sensor_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pir_sensor_msg)))
  "Returns string type for a message object of type 'pir_sensor_msg"
  "ddori/pir_sensor_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pir_sensor_msg>)))
  "Returns md5sum for a message object of type '<pir_sensor_msg>"
  "93bcdcb8db8db5a0d8f5bbfee92c9470")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pir_sensor_msg)))
  "Returns md5sum for a message object of type 'pir_sensor_msg"
  "93bcdcb8db8db5a0d8f5bbfee92c9470")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pir_sensor_msg>)))
  "Returns full string definition for message of type '<pir_sensor_msg>"
  (cl:format cl:nil "int16 pir_det ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pir_sensor_msg)))
  "Returns full string definition for message of type 'pir_sensor_msg"
  (cl:format cl:nil "int16 pir_det ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pir_sensor_msg>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pir_sensor_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'pir_sensor_msg
    (cl:cons ':pir_det (pir_det msg))
))

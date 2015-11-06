; Auto-generated. Do not edit!


(cl:in-package ddori-msg)


;//! \htmlinclude battery_msg.msg.html

(cl:defclass <battery_msg> (roslisp-msg-protocol:ros-message)
  ((voltage
    :reader voltage
    :initarg :voltage
    :type cl:fixnum
    :initform 0)
   (current
    :reader current
    :initarg :current
    :type cl:fixnum
    :initform 0))
)

(cl:defclass battery_msg (<battery_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <battery_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'battery_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ddori-msg:<battery_msg> is deprecated: use ddori-msg:battery_msg instead.")))

(cl:ensure-generic-function 'voltage-val :lambda-list '(m))
(cl:defmethod voltage-val ((m <battery_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:voltage-val is deprecated.  Use ddori-msg:voltage instead.")
  (voltage m))

(cl:ensure-generic-function 'current-val :lambda-list '(m))
(cl:defmethod current-val ((m <battery_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:current-val is deprecated.  Use ddori-msg:current instead.")
  (current m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <battery_msg>) ostream)
  "Serializes a message object of type '<battery_msg>"
  (cl:let* ((signed (cl:slot-value msg 'voltage)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <battery_msg>) istream)
  "Deserializes a message object of type '<battery_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'voltage) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'current) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<battery_msg>)))
  "Returns string type for a message object of type '<battery_msg>"
  "ddori/battery_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'battery_msg)))
  "Returns string type for a message object of type 'battery_msg"
  "ddori/battery_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<battery_msg>)))
  "Returns md5sum for a message object of type '<battery_msg>"
  "bd3d37c458ffb8eedfe783df816f558b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'battery_msg)))
  "Returns md5sum for a message object of type 'battery_msg"
  "bd3d37c458ffb8eedfe783df816f558b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<battery_msg>)))
  "Returns full string definition for message of type '<battery_msg>"
  (cl:format cl:nil "int16 voltage~%int16 current~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'battery_msg)))
  "Returns full string definition for message of type 'battery_msg"
  (cl:format cl:nil "int16 voltage~%int16 current~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <battery_msg>))
  (cl:+ 0
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <battery_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'battery_msg
    (cl:cons ':voltage (voltage msg))
    (cl:cons ':current (current msg))
))

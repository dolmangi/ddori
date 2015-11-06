; Auto-generated. Do not edit!


(cl:in-package ddori-msg)


;//! \htmlinclude temperature_msg.msg.html

(cl:defclass <temperature_msg> (roslisp-msg-protocol:ros-message)
  ((temperature_1
    :reader temperature_1
    :initarg :temperature_1
    :type cl:fixnum
    :initform 0)
   (temperature_2
    :reader temperature_2
    :initarg :temperature_2
    :type cl:fixnum
    :initform 0)
   (temperature_3
    :reader temperature_3
    :initarg :temperature_3
    :type cl:fixnum
    :initform 0))
)

(cl:defclass temperature_msg (<temperature_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <temperature_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'temperature_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ddori-msg:<temperature_msg> is deprecated: use ddori-msg:temperature_msg instead.")))

(cl:ensure-generic-function 'temperature_1-val :lambda-list '(m))
(cl:defmethod temperature_1-val ((m <temperature_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:temperature_1-val is deprecated.  Use ddori-msg:temperature_1 instead.")
  (temperature_1 m))

(cl:ensure-generic-function 'temperature_2-val :lambda-list '(m))
(cl:defmethod temperature_2-val ((m <temperature_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:temperature_2-val is deprecated.  Use ddori-msg:temperature_2 instead.")
  (temperature_2 m))

(cl:ensure-generic-function 'temperature_3-val :lambda-list '(m))
(cl:defmethod temperature_3-val ((m <temperature_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:temperature_3-val is deprecated.  Use ddori-msg:temperature_3 instead.")
  (temperature_3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <temperature_msg>) ostream)
  "Serializes a message object of type '<temperature_msg>"
  (cl:let* ((signed (cl:slot-value msg 'temperature_1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'temperature_2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'temperature_3)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <temperature_msg>) istream)
  "Deserializes a message object of type '<temperature_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temperature_1) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temperature_2) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temperature_3) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<temperature_msg>)))
  "Returns string type for a message object of type '<temperature_msg>"
  "ddori/temperature_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'temperature_msg)))
  "Returns string type for a message object of type 'temperature_msg"
  "ddori/temperature_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<temperature_msg>)))
  "Returns md5sum for a message object of type '<temperature_msg>"
  "1a517f950068fd79d1237ea6fbcec900")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'temperature_msg)))
  "Returns md5sum for a message object of type 'temperature_msg"
  "1a517f950068fd79d1237ea6fbcec900")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<temperature_msg>)))
  "Returns full string definition for message of type '<temperature_msg>"
  (cl:format cl:nil "int16 temperature_1 ~%int16 temperature_2~%int16 temperature_3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'temperature_msg)))
  "Returns full string definition for message of type 'temperature_msg"
  (cl:format cl:nil "int16 temperature_1 ~%int16 temperature_2~%int16 temperature_3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <temperature_msg>))
  (cl:+ 0
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <temperature_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'temperature_msg
    (cl:cons ':temperature_1 (temperature_1 msg))
    (cl:cons ':temperature_2 (temperature_2 msg))
    (cl:cons ':temperature_3 (temperature_3 msg))
))

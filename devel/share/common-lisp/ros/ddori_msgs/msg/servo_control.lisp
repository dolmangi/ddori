; Auto-generated. Do not edit!


(cl:in-package ddori_msgs-msg)


;//! \htmlinclude servo_control.msg.html

(cl:defclass <servo_control> (roslisp-msg-protocol:ros-message)
  ((no
    :reader no
    :initarg :no
    :type cl:fixnum
    :initform 0)
   (pos
    :reader pos
    :initarg :pos
    :type cl:fixnum
    :initform 0))
)

(cl:defclass servo_control (<servo_control>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo_control>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo_control)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ddori_msgs-msg:<servo_control> is deprecated: use ddori_msgs-msg:servo_control instead.")))

(cl:ensure-generic-function 'no-val :lambda-list '(m))
(cl:defmethod no-val ((m <servo_control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:no-val is deprecated.  Use ddori_msgs-msg:no instead.")
  (no m))

(cl:ensure-generic-function 'pos-val :lambda-list '(m))
(cl:defmethod pos-val ((m <servo_control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori_msgs-msg:pos-val is deprecated.  Use ddori_msgs-msg:pos instead.")
  (pos m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo_control>) ostream)
  "Serializes a message object of type '<servo_control>"
  (cl:let* ((signed (cl:slot-value msg 'no)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'pos)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo_control>) istream)
  "Deserializes a message object of type '<servo_control>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'no) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pos) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo_control>)))
  "Returns string type for a message object of type '<servo_control>"
  "ddori_msgs/servo_control")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_control)))
  "Returns string type for a message object of type 'servo_control"
  "ddori_msgs/servo_control")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo_control>)))
  "Returns md5sum for a message object of type '<servo_control>"
  "4114c64d431d2563f07d4a38968e12ce")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo_control)))
  "Returns md5sum for a message object of type 'servo_control"
  "4114c64d431d2563f07d4a38968e12ce")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo_control>)))
  "Returns full string definition for message of type '<servo_control>"
  (cl:format cl:nil "~%int8  no~%int8  pos~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo_control)))
  "Returns full string definition for message of type 'servo_control"
  (cl:format cl:nil "~%int8  no~%int8  pos~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo_control>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo_control>))
  "Converts a ROS message object to a list"
  (cl:list 'servo_control
    (cl:cons ':no (no msg))
    (cl:cons ':pos (pos msg))
))

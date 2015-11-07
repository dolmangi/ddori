; Auto-generated. Do not edit!


(cl:in-package ddori-msg)


;//! \htmlinclude motor_speed.msg.html

(cl:defclass <motor_speed> (roslisp-msg-protocol:ros-message)
  ((left_speed
    :reader left_speed
    :initarg :left_speed
    :type cl:fixnum
    :initform 0)
   (left_dir
    :reader left_dir
    :initarg :left_dir
    :type cl:fixnum
    :initform 0)
   (right_speed
    :reader right_speed
    :initarg :right_speed
    :type cl:fixnum
    :initform 0)
   (right_dir
    :reader right_dir
    :initarg :right_dir
    :type cl:fixnum
    :initform 0))
)

(cl:defclass motor_speed (<motor_speed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motor_speed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motor_speed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ddori-msg:<motor_speed> is deprecated: use ddori-msg:motor_speed instead.")))

(cl:ensure-generic-function 'left_speed-val :lambda-list '(m))
(cl:defmethod left_speed-val ((m <motor_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:left_speed-val is deprecated.  Use ddori-msg:left_speed instead.")
  (left_speed m))

(cl:ensure-generic-function 'left_dir-val :lambda-list '(m))
(cl:defmethod left_dir-val ((m <motor_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:left_dir-val is deprecated.  Use ddori-msg:left_dir instead.")
  (left_dir m))

(cl:ensure-generic-function 'right_speed-val :lambda-list '(m))
(cl:defmethod right_speed-val ((m <motor_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:right_speed-val is deprecated.  Use ddori-msg:right_speed instead.")
  (right_speed m))

(cl:ensure-generic-function 'right_dir-val :lambda-list '(m))
(cl:defmethod right_dir-val ((m <motor_speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ddori-msg:right_dir-val is deprecated.  Use ddori-msg:right_dir instead.")
  (right_dir m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motor_speed>) ostream)
  "Serializes a message object of type '<motor_speed>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_speed)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_dir)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_speed)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_dir)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motor_speed>) istream)
  "Deserializes a message object of type '<motor_speed>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_speed)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_dir)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_speed)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_dir)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motor_speed>)))
  "Returns string type for a message object of type '<motor_speed>"
  "ddori/motor_speed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motor_speed)))
  "Returns string type for a message object of type 'motor_speed"
  "ddori/motor_speed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motor_speed>)))
  "Returns md5sum for a message object of type '<motor_speed>"
  "621b34f25ac94b760c1ddd9f2c38ce75")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motor_speed)))
  "Returns md5sum for a message object of type 'motor_speed"
  "621b34f25ac94b760c1ddd9f2c38ce75")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motor_speed>)))
  "Returns full string definition for message of type '<motor_speed>"
  (cl:format cl:nil "~%uint8 left_speed~%uint8 left_dir~%uint8 right_speed~%uint8 right_dir~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motor_speed)))
  "Returns full string definition for message of type 'motor_speed"
  (cl:format cl:nil "~%uint8 left_speed~%uint8 left_dir~%uint8 right_speed~%uint8 right_dir~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motor_speed>))
  (cl:+ 0
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motor_speed>))
  "Converts a ROS message object to a list"
  (cl:list 'motor_speed
    (cl:cons ':left_speed (left_speed msg))
    (cl:cons ':left_dir (left_dir msg))
    (cl:cons ':right_speed (right_speed msg))
    (cl:cons ':right_dir (right_dir msg))
))

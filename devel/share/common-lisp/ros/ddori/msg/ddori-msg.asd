
(cl:in-package :asdf)

(defsystem "ddori-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "servo_control" :depends-on ("_package_servo_control"))
    (:file "_package_servo_control" :depends-on ("_package"))
    (:file "motor_speed" :depends-on ("_package_motor_speed"))
    (:file "_package_motor_speed" :depends-on ("_package"))
    (:file "MotorPower" :depends-on ("_package_MotorPower"))
    (:file "_package_MotorPower" :depends-on ("_package"))
    (:file "ddori_sensor" :depends-on ("_package_ddori_sensor"))
    (:file "_package_ddori_sensor" :depends-on ("_package"))
  ))
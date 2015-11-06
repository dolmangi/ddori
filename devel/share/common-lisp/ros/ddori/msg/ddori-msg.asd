
(cl:in-package :asdf)

(defsystem "ddori-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "pir_sensor_msg" :depends-on ("_package_pir_sensor_msg"))
    (:file "_package_pir_sensor_msg" :depends-on ("_package"))
    (:file "battery_msg" :depends-on ("_package_battery_msg"))
    (:file "_package_battery_msg" :depends-on ("_package"))
    (:file "temperature_msg" :depends-on ("_package_temperature_msg"))
    (:file "_package_temperature_msg" :depends-on ("_package"))
  ))
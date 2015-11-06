
(cl:in-package :asdf)

(defsystem "ddori-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ddori_sensor" :depends-on ("_package_ddori_sensor"))
    (:file "_package_ddori_sensor" :depends-on ("_package"))
  ))
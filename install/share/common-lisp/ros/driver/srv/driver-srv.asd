
(cl:in-package :asdf)

(defsystem "driver-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "config_arm" :depends-on ("_package_config_arm"))
    (:file "_package_config_arm" :depends-on ("_package"))
    (:file "control_arm" :depends-on ("_package_control_arm"))
    (:file "_package_control_arm" :depends-on ("_package"))
  ))
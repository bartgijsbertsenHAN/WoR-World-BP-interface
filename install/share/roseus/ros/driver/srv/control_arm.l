;; Auto-generated. Do not edit!


(when (boundp 'driver::control_arm)
  (if (not (find-package "DRIVER"))
    (make-package "DRIVER"))
  (shadow 'control_arm (find-package "DRIVER")))
(unless (find-package "DRIVER::CONTROL_ARM")
  (make-package "DRIVER::CONTROL_ARM"))
(unless (find-package "DRIVER::CONTROL_ARMREQUEST")
  (make-package "DRIVER::CONTROL_ARMREQUEST"))
(unless (find-package "DRIVER::CONTROL_ARMRESPONSE")
  (make-package "DRIVER::CONTROL_ARMRESPONSE"))

(in-package "ROS")





(defclass driver::control_armRequest
  :super ros::object
  :slots (_base_angle _base_speed _shoulder_angle _shoulder_speed _elbow_angle _elbow_speed _wrist_angle _wrist_speed _gripper_angle _gripper_speed _wrist_rotate_angle _wrist_rotate_speed _time ))

(defmethod driver::control_armRequest
  (:init
   (&key
    ((:base_angle __base_angle) 0)
    ((:base_speed __base_speed) 0)
    ((:shoulder_angle __shoulder_angle) 0)
    ((:shoulder_speed __shoulder_speed) 0)
    ((:elbow_angle __elbow_angle) 0)
    ((:elbow_speed __elbow_speed) 0)
    ((:wrist_angle __wrist_angle) 0)
    ((:wrist_speed __wrist_speed) 0)
    ((:gripper_angle __gripper_angle) 0)
    ((:gripper_speed __gripper_speed) 0)
    ((:wrist_rotate_angle __wrist_rotate_angle) 0)
    ((:wrist_rotate_speed __wrist_rotate_speed) 0)
    ((:time __time) 0)
    )
   (send-super :init)
   (setq _base_angle (round __base_angle))
   (setq _base_speed (round __base_speed))
   (setq _shoulder_angle (round __shoulder_angle))
   (setq _shoulder_speed (round __shoulder_speed))
   (setq _elbow_angle (round __elbow_angle))
   (setq _elbow_speed (round __elbow_speed))
   (setq _wrist_angle (round __wrist_angle))
   (setq _wrist_speed (round __wrist_speed))
   (setq _gripper_angle (round __gripper_angle))
   (setq _gripper_speed (round __gripper_speed))
   (setq _wrist_rotate_angle (round __wrist_rotate_angle))
   (setq _wrist_rotate_speed (round __wrist_rotate_speed))
   (setq _time (round __time))
   self)
  (:base_angle
   (&optional __base_angle)
   (if __base_angle (setq _base_angle __base_angle)) _base_angle)
  (:base_speed
   (&optional __base_speed)
   (if __base_speed (setq _base_speed __base_speed)) _base_speed)
  (:shoulder_angle
   (&optional __shoulder_angle)
   (if __shoulder_angle (setq _shoulder_angle __shoulder_angle)) _shoulder_angle)
  (:shoulder_speed
   (&optional __shoulder_speed)
   (if __shoulder_speed (setq _shoulder_speed __shoulder_speed)) _shoulder_speed)
  (:elbow_angle
   (&optional __elbow_angle)
   (if __elbow_angle (setq _elbow_angle __elbow_angle)) _elbow_angle)
  (:elbow_speed
   (&optional __elbow_speed)
   (if __elbow_speed (setq _elbow_speed __elbow_speed)) _elbow_speed)
  (:wrist_angle
   (&optional __wrist_angle)
   (if __wrist_angle (setq _wrist_angle __wrist_angle)) _wrist_angle)
  (:wrist_speed
   (&optional __wrist_speed)
   (if __wrist_speed (setq _wrist_speed __wrist_speed)) _wrist_speed)
  (:gripper_angle
   (&optional __gripper_angle)
   (if __gripper_angle (setq _gripper_angle __gripper_angle)) _gripper_angle)
  (:gripper_speed
   (&optional __gripper_speed)
   (if __gripper_speed (setq _gripper_speed __gripper_speed)) _gripper_speed)
  (:wrist_rotate_angle
   (&optional __wrist_rotate_angle)
   (if __wrist_rotate_angle (setq _wrist_rotate_angle __wrist_rotate_angle)) _wrist_rotate_angle)
  (:wrist_rotate_speed
   (&optional __wrist_rotate_speed)
   (if __wrist_rotate_speed (setq _wrist_rotate_speed __wrist_rotate_speed)) _wrist_rotate_speed)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:serialization-length
   ()
   (+
    ;; int16 _base_angle
    2
    ;; uint8 _base_speed
    1
    ;; int16 _shoulder_angle
    2
    ;; uint8 _shoulder_speed
    1
    ;; int16 _elbow_angle
    2
    ;; uint8 _elbow_speed
    1
    ;; int16 _wrist_angle
    2
    ;; uint8 _wrist_speed
    1
    ;; int16 _gripper_angle
    2
    ;; uint8 _gripper_speed
    1
    ;; int16 _wrist_rotate_angle
    2
    ;; uint8 _wrist_rotate_speed
    1
    ;; uint16 _time
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _base_angle
       (write-word _base_angle s)
     ;; uint8 _base_speed
       (write-byte _base_speed s)
     ;; int16 _shoulder_angle
       (write-word _shoulder_angle s)
     ;; uint8 _shoulder_speed
       (write-byte _shoulder_speed s)
     ;; int16 _elbow_angle
       (write-word _elbow_angle s)
     ;; uint8 _elbow_speed
       (write-byte _elbow_speed s)
     ;; int16 _wrist_angle
       (write-word _wrist_angle s)
     ;; uint8 _wrist_speed
       (write-byte _wrist_speed s)
     ;; int16 _gripper_angle
       (write-word _gripper_angle s)
     ;; uint8 _gripper_speed
       (write-byte _gripper_speed s)
     ;; int16 _wrist_rotate_angle
       (write-word _wrist_rotate_angle s)
     ;; uint8 _wrist_rotate_speed
       (write-byte _wrist_rotate_speed s)
     ;; uint16 _time
       (write-word _time s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _base_angle
     (setq _base_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _base_speed
     (setq _base_speed (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _shoulder_angle
     (setq _shoulder_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _shoulder_speed
     (setq _shoulder_speed (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _elbow_angle
     (setq _elbow_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _elbow_speed
     (setq _elbow_speed (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _wrist_angle
     (setq _wrist_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _wrist_speed
     (setq _wrist_speed (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _gripper_angle
     (setq _gripper_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _gripper_speed
     (setq _gripper_speed (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _wrist_rotate_angle
     (setq _wrist_rotate_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _wrist_rotate_speed
     (setq _wrist_rotate_speed (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _time
     (setq _time (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass driver::control_armResponse
  :super ros::object
  :slots (_succes ))

(defmethod driver::control_armResponse
  (:init
   (&key
    ((:succes __succes) nil)
    )
   (send-super :init)
   (setq _succes __succes)
   self)
  (:succes
   (&optional __succes)
   (if __succes (setq _succes __succes)) _succes)
  (:serialization-length
   ()
   (+
    ;; bool _succes
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _succes
       (if _succes (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _succes
     (setq _succes (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass driver::control_arm
  :super ros::object
  :slots ())

(setf (get driver::control_arm :md5sum-) "2830068845fb2505b4060ad2eb804a4f")
(setf (get driver::control_arm :datatype-) "driver/control_arm")
(setf (get driver::control_arm :request) driver::control_armRequest)
(setf (get driver::control_arm :response) driver::control_armResponse)

(defmethod driver::control_armRequest
  (:response () (instance driver::control_armResponse :init)))

(setf (get driver::control_armRequest :md5sum-) "2830068845fb2505b4060ad2eb804a4f")
(setf (get driver::control_armRequest :datatype-) "driver/control_armRequest")
(setf (get driver::control_armRequest :definition-)
      "int16 base_angle
uint8 base_speed
int16 shoulder_angle
uint8 shoulder_speed
int16 elbow_angle
uint8 elbow_speed
int16 wrist_angle
uint8 wrist_speed
int16 gripper_angle
uint8 gripper_speed
int16 wrist_rotate_angle
uint8 wrist_rotate_speed
uint16 time
---
bool succes
")

(setf (get driver::control_armResponse :md5sum-) "2830068845fb2505b4060ad2eb804a4f")
(setf (get driver::control_armResponse :datatype-) "driver/control_armResponse")
(setf (get driver::control_armResponse :definition-)
      "int16 base_angle
uint8 base_speed
int16 shoulder_angle
uint8 shoulder_speed
int16 elbow_angle
uint8 elbow_speed
int16 wrist_angle
uint8 wrist_speed
int16 gripper_angle
uint8 gripper_speed
int16 wrist_rotate_angle
uint8 wrist_rotate_speed
uint16 time
---
bool succes
")



(provide :driver/control_arm "2830068845fb2505b4060ad2eb804a4f")



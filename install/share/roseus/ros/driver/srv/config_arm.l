;; Auto-generated. Do not edit!


(when (boundp 'driver::config_arm)
  (if (not (find-package "DRIVER"))
    (make-package "DRIVER"))
  (shadow 'config_arm (find-package "DRIVER")))
(unless (find-package "DRIVER::CONFIG_ARM")
  (make-package "DRIVER::CONFIG_ARM"))
(unless (find-package "DRIVER::CONFIG_ARMREQUEST")
  (make-package "DRIVER::CONFIG_ARMREQUEST"))
(unless (find-package "DRIVER::CONFIG_ARMRESPONSE")
  (make-package "DRIVER::CONFIG_ARMRESPONSE"))

(in-package "ROS")





(defclass driver::config_armRequest
  :super ros::object
  :slots (_angle_offsets ))

(defmethod driver::config_armRequest
  (:init
   (&key
    ((:angle_offsets __angle_offsets) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _angle_offsets __angle_offsets)
   self)
  (:angle_offsets
   (&optional __angle_offsets)
   (if __angle_offsets (setq _angle_offsets __angle_offsets)) _angle_offsets)
  (:serialization-length
   ()
   (+
    ;; int8[] _angle_offsets
    (* 1    (length _angle_offsets)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8[] _angle_offsets
     (write-long (length _angle_offsets) s)
     (dotimes (i (length _angle_offsets))
       (write-byte (elt _angle_offsets i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8[] _angle_offsets
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _angle_offsets (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _angle_offsets i) (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> (elt _angle_offsets i) 127) (setf (elt _angle_offsets i) (- (elt _angle_offsets i) 256)))
     ))
   ;;
   self)
  )

(defclass driver::config_armResponse
  :super ros::object
  :slots (_succes ))

(defmethod driver::config_armResponse
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

(defclass driver::config_arm
  :super ros::object
  :slots ())

(setf (get driver::config_arm :md5sum-) "437dcc9253614fa63d9b9cff189a86cc")
(setf (get driver::config_arm :datatype-) "driver/config_arm")
(setf (get driver::config_arm :request) driver::config_armRequest)
(setf (get driver::config_arm :response) driver::config_armResponse)

(defmethod driver::config_armRequest
  (:response () (instance driver::config_armResponse :init)))

(setf (get driver::config_armRequest :md5sum-) "437dcc9253614fa63d9b9cff189a86cc")
(setf (get driver::config_armRequest :datatype-) "driver/config_armRequest")
(setf (get driver::config_armRequest :definition-)
      "int8[] angle_offsets
---
bool succes
")

(setf (get driver::config_armResponse :md5sum-) "437dcc9253614fa63d9b9cff189a86cc")
(setf (get driver::config_armResponse :datatype-) "driver/config_armResponse")
(setf (get driver::config_armResponse :definition-)
      "int8[] angle_offsets
---
bool succes
")



(provide :driver/config_arm "437dcc9253614fa63d9b9cff189a86cc")



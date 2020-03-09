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
  :slots (_angles _speeds _time ))

(defmethod driver::control_armRequest
  (:init
   (&key
    ((:angles __angles) (make-array 0 :initial-element 0 :element-type :integer))
    ((:speeds __speeds) (make-array 0 :initial-element 0 :element-type :char))
    ((:time __time) 0)
    )
   (send-super :init)
   (setq _angles __angles)
   (setq _speeds __speeds)
   (setq _time (round __time))
   self)
  (:angles
   (&optional __angles)
   (if __angles (setq _angles __angles)) _angles)
  (:speeds
   (&optional __speeds)
   (if __speeds (setq _speeds __speeds)) _speeds)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:serialization-length
   ()
   (+
    ;; int16[] _angles
    (* 2    (length _angles)) 4
    ;; uint8[] _speeds
    (* 1    (length _speeds)) 4
    ;; uint16 _time
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16[] _angles
     (write-long (length _angles) s)
     (dotimes (i (length _angles))
       (write-word (elt _angles i) s)
       )
     ;; uint8[] _speeds
     (write-long (length _speeds) s)
     (princ _speeds s)
     ;; uint16 _time
       (write-word _time s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16[] _angles
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _angles (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _angles i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; uint8[] _speeds
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _speeds (make-array n :element-type :char))
     (replace _speeds buf :start2 ptr-) (incf ptr- n))
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

(setf (get driver::control_arm :md5sum-) "9f92a49c54ce202a35ae4e75b5fee653")
(setf (get driver::control_arm :datatype-) "driver/control_arm")
(setf (get driver::control_arm :request) driver::control_armRequest)
(setf (get driver::control_arm :response) driver::control_armResponse)

(defmethod driver::control_armRequest
  (:response () (instance driver::control_armResponse :init)))

(setf (get driver::control_armRequest :md5sum-) "9f92a49c54ce202a35ae4e75b5fee653")
(setf (get driver::control_armRequest :datatype-) "driver/control_armRequest")
(setf (get driver::control_armRequest :definition-)
      "int16[] angles
uint8[] speeds
uint16 time
---
bool succes
")

(setf (get driver::control_armResponse :md5sum-) "9f92a49c54ce202a35ae4e75b5fee653")
(setf (get driver::control_armResponse :datatype-) "driver/control_armResponse")
(setf (get driver::control_armResponse :definition-)
      "int16[] angles
uint8[] speeds
uint16 time
---
bool succes
")



(provide :driver/control_arm "9f92a49c54ce202a35ae4e75b5fee653")



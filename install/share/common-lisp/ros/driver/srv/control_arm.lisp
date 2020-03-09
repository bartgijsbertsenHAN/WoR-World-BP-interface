; Auto-generated. Do not edit!


(cl:in-package driver-srv)


;//! \htmlinclude control_arm-request.msg.html

(cl:defclass <control_arm-request> (roslisp-msg-protocol:ros-message)
  ((angles
    :reader angles
    :initarg :angles
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (speeds
    :reader speeds
    :initarg :speeds
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (time
    :reader time
    :initarg :time
    :type cl:fixnum
    :initform 0))
)

(cl:defclass control_arm-request (<control_arm-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <control_arm-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'control_arm-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name driver-srv:<control_arm-request> is deprecated: use driver-srv:control_arm-request instead.")))

(cl:ensure-generic-function 'angles-val :lambda-list '(m))
(cl:defmethod angles-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:angles-val is deprecated.  Use driver-srv:angles instead.")
  (angles m))

(cl:ensure-generic-function 'speeds-val :lambda-list '(m))
(cl:defmethod speeds-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:speeds-val is deprecated.  Use driver-srv:speeds instead.")
  (speeds m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:time-val is deprecated.  Use driver-srv:time instead.")
  (time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <control_arm-request>) ostream)
  "Serializes a message object of type '<control_arm-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'angles))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    ))
   (cl:slot-value msg 'angles))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'speeds))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'speeds))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <control_arm-request>) istream)
  "Deserializes a message object of type '<control_arm-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'angles) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'angles)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536)))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'speeds) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'speeds)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<control_arm-request>)))
  "Returns string type for a service object of type '<control_arm-request>"
  "driver/control_armRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'control_arm-request)))
  "Returns string type for a service object of type 'control_arm-request"
  "driver/control_armRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<control_arm-request>)))
  "Returns md5sum for a message object of type '<control_arm-request>"
  "9f92a49c54ce202a35ae4e75b5fee653")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'control_arm-request)))
  "Returns md5sum for a message object of type 'control_arm-request"
  "9f92a49c54ce202a35ae4e75b5fee653")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<control_arm-request>)))
  "Returns full string definition for message of type '<control_arm-request>"
  (cl:format cl:nil "int16[] angles~%uint8[] speeds~%uint16 time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'control_arm-request)))
  "Returns full string definition for message of type 'control_arm-request"
  (cl:format cl:nil "int16[] angles~%uint8[] speeds~%uint16 time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <control_arm-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'speeds) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <control_arm-request>))
  "Converts a ROS message object to a list"
  (cl:list 'control_arm-request
    (cl:cons ':angles (angles msg))
    (cl:cons ':speeds (speeds msg))
    (cl:cons ':time (time msg))
))
;//! \htmlinclude control_arm-response.msg.html

(cl:defclass <control_arm-response> (roslisp-msg-protocol:ros-message)
  ((succes
    :reader succes
    :initarg :succes
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass control_arm-response (<control_arm-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <control_arm-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'control_arm-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name driver-srv:<control_arm-response> is deprecated: use driver-srv:control_arm-response instead.")))

(cl:ensure-generic-function 'succes-val :lambda-list '(m))
(cl:defmethod succes-val ((m <control_arm-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:succes-val is deprecated.  Use driver-srv:succes instead.")
  (succes m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <control_arm-response>) ostream)
  "Serializes a message object of type '<control_arm-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'succes) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <control_arm-response>) istream)
  "Deserializes a message object of type '<control_arm-response>"
    (cl:setf (cl:slot-value msg 'succes) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<control_arm-response>)))
  "Returns string type for a service object of type '<control_arm-response>"
  "driver/control_armResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'control_arm-response)))
  "Returns string type for a service object of type 'control_arm-response"
  "driver/control_armResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<control_arm-response>)))
  "Returns md5sum for a message object of type '<control_arm-response>"
  "9f92a49c54ce202a35ae4e75b5fee653")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'control_arm-response)))
  "Returns md5sum for a message object of type 'control_arm-response"
  "9f92a49c54ce202a35ae4e75b5fee653")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<control_arm-response>)))
  "Returns full string definition for message of type '<control_arm-response>"
  (cl:format cl:nil "bool succes~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'control_arm-response)))
  "Returns full string definition for message of type 'control_arm-response"
  (cl:format cl:nil "bool succes~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <control_arm-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <control_arm-response>))
  "Converts a ROS message object to a list"
  (cl:list 'control_arm-response
    (cl:cons ':succes (succes msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'control_arm)))
  'control_arm-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'control_arm)))
  'control_arm-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'control_arm)))
  "Returns string type for a service object of type '<control_arm>"
  "driver/control_arm")
; Auto-generated. Do not edit!


(cl:in-package driver-srv)


;//! \htmlinclude config_arm-request.msg.html

(cl:defclass <config_arm-request> (roslisp-msg-protocol:ros-message)
  ((angle_offsets
    :reader angle_offsets
    :initarg :angle_offsets
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass config_arm-request (<config_arm-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <config_arm-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'config_arm-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name driver-srv:<config_arm-request> is deprecated: use driver-srv:config_arm-request instead.")))

(cl:ensure-generic-function 'angle_offsets-val :lambda-list '(m))
(cl:defmethod angle_offsets-val ((m <config_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:angle_offsets-val is deprecated.  Use driver-srv:angle_offsets instead.")
  (angle_offsets m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <config_arm-request>) ostream)
  "Serializes a message object of type '<config_arm-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'angle_offsets))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    ))
   (cl:slot-value msg 'angle_offsets))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <config_arm-request>) istream)
  "Deserializes a message object of type '<config_arm-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'angle_offsets) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'angle_offsets)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<config_arm-request>)))
  "Returns string type for a service object of type '<config_arm-request>"
  "driver/config_armRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'config_arm-request)))
  "Returns string type for a service object of type 'config_arm-request"
  "driver/config_armRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<config_arm-request>)))
  "Returns md5sum for a message object of type '<config_arm-request>"
  "437dcc9253614fa63d9b9cff189a86cc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'config_arm-request)))
  "Returns md5sum for a message object of type 'config_arm-request"
  "437dcc9253614fa63d9b9cff189a86cc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<config_arm-request>)))
  "Returns full string definition for message of type '<config_arm-request>"
  (cl:format cl:nil "int8[] angle_offsets~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'config_arm-request)))
  "Returns full string definition for message of type 'config_arm-request"
  (cl:format cl:nil "int8[] angle_offsets~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <config_arm-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'angle_offsets) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <config_arm-request>))
  "Converts a ROS message object to a list"
  (cl:list 'config_arm-request
    (cl:cons ':angle_offsets (angle_offsets msg))
))
;//! \htmlinclude config_arm-response.msg.html

(cl:defclass <config_arm-response> (roslisp-msg-protocol:ros-message)
  ((succes
    :reader succes
    :initarg :succes
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass config_arm-response (<config_arm-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <config_arm-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'config_arm-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name driver-srv:<config_arm-response> is deprecated: use driver-srv:config_arm-response instead.")))

(cl:ensure-generic-function 'succes-val :lambda-list '(m))
(cl:defmethod succes-val ((m <config_arm-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:succes-val is deprecated.  Use driver-srv:succes instead.")
  (succes m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <config_arm-response>) ostream)
  "Serializes a message object of type '<config_arm-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'succes) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <config_arm-response>) istream)
  "Deserializes a message object of type '<config_arm-response>"
    (cl:setf (cl:slot-value msg 'succes) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<config_arm-response>)))
  "Returns string type for a service object of type '<config_arm-response>"
  "driver/config_armResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'config_arm-response)))
  "Returns string type for a service object of type 'config_arm-response"
  "driver/config_armResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<config_arm-response>)))
  "Returns md5sum for a message object of type '<config_arm-response>"
  "437dcc9253614fa63d9b9cff189a86cc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'config_arm-response)))
  "Returns md5sum for a message object of type 'config_arm-response"
  "437dcc9253614fa63d9b9cff189a86cc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<config_arm-response>)))
  "Returns full string definition for message of type '<config_arm-response>"
  (cl:format cl:nil "bool succes~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'config_arm-response)))
  "Returns full string definition for message of type 'config_arm-response"
  (cl:format cl:nil "bool succes~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <config_arm-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <config_arm-response>))
  "Converts a ROS message object to a list"
  (cl:list 'config_arm-response
    (cl:cons ':succes (succes msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'config_arm)))
  'config_arm-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'config_arm)))
  'config_arm-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'config_arm)))
  "Returns string type for a service object of type '<config_arm>"
  "driver/config_arm")
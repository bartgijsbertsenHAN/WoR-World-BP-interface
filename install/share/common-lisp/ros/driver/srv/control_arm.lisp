; Auto-generated. Do not edit!


(cl:in-package driver-srv)


;//! \htmlinclude control_arm-request.msg.html

(cl:defclass <control_arm-request> (roslisp-msg-protocol:ros-message)
  ((base_angle
    :reader base_angle
    :initarg :base_angle
    :type cl:fixnum
    :initform 0)
   (base_speed
    :reader base_speed
    :initarg :base_speed
    :type cl:fixnum
    :initform 0)
   (shoulder_angle
    :reader shoulder_angle
    :initarg :shoulder_angle
    :type cl:fixnum
    :initform 0)
   (shoulder_speed
    :reader shoulder_speed
    :initarg :shoulder_speed
    :type cl:fixnum
    :initform 0)
   (elbow_angle
    :reader elbow_angle
    :initarg :elbow_angle
    :type cl:fixnum
    :initform 0)
   (elbow_speed
    :reader elbow_speed
    :initarg :elbow_speed
    :type cl:fixnum
    :initform 0)
   (wrist_angle
    :reader wrist_angle
    :initarg :wrist_angle
    :type cl:fixnum
    :initform 0)
   (wrist_speed
    :reader wrist_speed
    :initarg :wrist_speed
    :type cl:fixnum
    :initform 0)
   (gripper_angle
    :reader gripper_angle
    :initarg :gripper_angle
    :type cl:fixnum
    :initform 0)
   (gripper_speed
    :reader gripper_speed
    :initarg :gripper_speed
    :type cl:fixnum
    :initform 0)
   (wrist_rotate_angle
    :reader wrist_rotate_angle
    :initarg :wrist_rotate_angle
    :type cl:fixnum
    :initform 0)
   (wrist_rotate_speed
    :reader wrist_rotate_speed
    :initarg :wrist_rotate_speed
    :type cl:fixnum
    :initform 0)
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

(cl:ensure-generic-function 'base_angle-val :lambda-list '(m))
(cl:defmethod base_angle-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:base_angle-val is deprecated.  Use driver-srv:base_angle instead.")
  (base_angle m))

(cl:ensure-generic-function 'base_speed-val :lambda-list '(m))
(cl:defmethod base_speed-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:base_speed-val is deprecated.  Use driver-srv:base_speed instead.")
  (base_speed m))

(cl:ensure-generic-function 'shoulder_angle-val :lambda-list '(m))
(cl:defmethod shoulder_angle-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:shoulder_angle-val is deprecated.  Use driver-srv:shoulder_angle instead.")
  (shoulder_angle m))

(cl:ensure-generic-function 'shoulder_speed-val :lambda-list '(m))
(cl:defmethod shoulder_speed-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:shoulder_speed-val is deprecated.  Use driver-srv:shoulder_speed instead.")
  (shoulder_speed m))

(cl:ensure-generic-function 'elbow_angle-val :lambda-list '(m))
(cl:defmethod elbow_angle-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:elbow_angle-val is deprecated.  Use driver-srv:elbow_angle instead.")
  (elbow_angle m))

(cl:ensure-generic-function 'elbow_speed-val :lambda-list '(m))
(cl:defmethod elbow_speed-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:elbow_speed-val is deprecated.  Use driver-srv:elbow_speed instead.")
  (elbow_speed m))

(cl:ensure-generic-function 'wrist_angle-val :lambda-list '(m))
(cl:defmethod wrist_angle-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:wrist_angle-val is deprecated.  Use driver-srv:wrist_angle instead.")
  (wrist_angle m))

(cl:ensure-generic-function 'wrist_speed-val :lambda-list '(m))
(cl:defmethod wrist_speed-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:wrist_speed-val is deprecated.  Use driver-srv:wrist_speed instead.")
  (wrist_speed m))

(cl:ensure-generic-function 'gripper_angle-val :lambda-list '(m))
(cl:defmethod gripper_angle-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:gripper_angle-val is deprecated.  Use driver-srv:gripper_angle instead.")
  (gripper_angle m))

(cl:ensure-generic-function 'gripper_speed-val :lambda-list '(m))
(cl:defmethod gripper_speed-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:gripper_speed-val is deprecated.  Use driver-srv:gripper_speed instead.")
  (gripper_speed m))

(cl:ensure-generic-function 'wrist_rotate_angle-val :lambda-list '(m))
(cl:defmethod wrist_rotate_angle-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:wrist_rotate_angle-val is deprecated.  Use driver-srv:wrist_rotate_angle instead.")
  (wrist_rotate_angle m))

(cl:ensure-generic-function 'wrist_rotate_speed-val :lambda-list '(m))
(cl:defmethod wrist_rotate_speed-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:wrist_rotate_speed-val is deprecated.  Use driver-srv:wrist_rotate_speed instead.")
  (wrist_rotate_speed m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <control_arm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader driver-srv:time-val is deprecated.  Use driver-srv:time instead.")
  (time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <control_arm-request>) ostream)
  "Serializes a message object of type '<control_arm-request>"
  (cl:let* ((signed (cl:slot-value msg 'base_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'base_speed)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'shoulder_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shoulder_speed)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'elbow_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'elbow_speed)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'wrist_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wrist_speed)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'gripper_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gripper_speed)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'wrist_rotate_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wrist_rotate_speed)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <control_arm-request>) istream)
  "Deserializes a message object of type '<control_arm-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'base_angle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'base_speed)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'shoulder_angle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'shoulder_speed)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'elbow_angle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'elbow_speed)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'wrist_angle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wrist_speed)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gripper_angle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gripper_speed)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'wrist_rotate_angle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wrist_rotate_speed)) (cl:read-byte istream))
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
  "2830068845fb2505b4060ad2eb804a4f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'control_arm-request)))
  "Returns md5sum for a message object of type 'control_arm-request"
  "2830068845fb2505b4060ad2eb804a4f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<control_arm-request>)))
  "Returns full string definition for message of type '<control_arm-request>"
  (cl:format cl:nil "int16 base_angle~%uint8 base_speed~%int16 shoulder_angle~%uint8 shoulder_speed~%int16 elbow_angle~%uint8 elbow_speed~%int16 wrist_angle~%uint8 wrist_speed~%int16 gripper_angle~%uint8 gripper_speed~%int16 wrist_rotate_angle~%uint8 wrist_rotate_speed~%uint16 time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'control_arm-request)))
  "Returns full string definition for message of type 'control_arm-request"
  (cl:format cl:nil "int16 base_angle~%uint8 base_speed~%int16 shoulder_angle~%uint8 shoulder_speed~%int16 elbow_angle~%uint8 elbow_speed~%int16 wrist_angle~%uint8 wrist_speed~%int16 gripper_angle~%uint8 gripper_speed~%int16 wrist_rotate_angle~%uint8 wrist_rotate_speed~%uint16 time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <control_arm-request>))
  (cl:+ 0
     2
     1
     2
     1
     2
     1
     2
     1
     2
     1
     2
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <control_arm-request>))
  "Converts a ROS message object to a list"
  (cl:list 'control_arm-request
    (cl:cons ':base_angle (base_angle msg))
    (cl:cons ':base_speed (base_speed msg))
    (cl:cons ':shoulder_angle (shoulder_angle msg))
    (cl:cons ':shoulder_speed (shoulder_speed msg))
    (cl:cons ':elbow_angle (elbow_angle msg))
    (cl:cons ':elbow_speed (elbow_speed msg))
    (cl:cons ':wrist_angle (wrist_angle msg))
    (cl:cons ':wrist_speed (wrist_speed msg))
    (cl:cons ':gripper_angle (gripper_angle msg))
    (cl:cons ':gripper_speed (gripper_speed msg))
    (cl:cons ':wrist_rotate_angle (wrist_rotate_angle msg))
    (cl:cons ':wrist_rotate_speed (wrist_rotate_speed msg))
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
  "2830068845fb2505b4060ad2eb804a4f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'control_arm-response)))
  "Returns md5sum for a message object of type 'control_arm-response"
  "2830068845fb2505b4060ad2eb804a4f")
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
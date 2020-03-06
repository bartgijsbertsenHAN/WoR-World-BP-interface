// Auto-generated. Do not edit!

// (in-package driver.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class control_armRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.base_angle = null;
      this.base_speed = null;
      this.shoulder_angle = null;
      this.shoulder_speed = null;
      this.elbow_angle = null;
      this.elbow_speed = null;
      this.wrist_angle = null;
      this.wrist_speed = null;
      this.gripper_angle = null;
      this.gripper_speed = null;
      this.wrist_rotate_angle = null;
      this.wrist_rotate_speed = null;
      this.time = null;
    }
    else {
      if (initObj.hasOwnProperty('base_angle')) {
        this.base_angle = initObj.base_angle
      }
      else {
        this.base_angle = 0;
      }
      if (initObj.hasOwnProperty('base_speed')) {
        this.base_speed = initObj.base_speed
      }
      else {
        this.base_speed = 0;
      }
      if (initObj.hasOwnProperty('shoulder_angle')) {
        this.shoulder_angle = initObj.shoulder_angle
      }
      else {
        this.shoulder_angle = 0;
      }
      if (initObj.hasOwnProperty('shoulder_speed')) {
        this.shoulder_speed = initObj.shoulder_speed
      }
      else {
        this.shoulder_speed = 0;
      }
      if (initObj.hasOwnProperty('elbow_angle')) {
        this.elbow_angle = initObj.elbow_angle
      }
      else {
        this.elbow_angle = 0;
      }
      if (initObj.hasOwnProperty('elbow_speed')) {
        this.elbow_speed = initObj.elbow_speed
      }
      else {
        this.elbow_speed = 0;
      }
      if (initObj.hasOwnProperty('wrist_angle')) {
        this.wrist_angle = initObj.wrist_angle
      }
      else {
        this.wrist_angle = 0;
      }
      if (initObj.hasOwnProperty('wrist_speed')) {
        this.wrist_speed = initObj.wrist_speed
      }
      else {
        this.wrist_speed = 0;
      }
      if (initObj.hasOwnProperty('gripper_angle')) {
        this.gripper_angle = initObj.gripper_angle
      }
      else {
        this.gripper_angle = 0;
      }
      if (initObj.hasOwnProperty('gripper_speed')) {
        this.gripper_speed = initObj.gripper_speed
      }
      else {
        this.gripper_speed = 0;
      }
      if (initObj.hasOwnProperty('wrist_rotate_angle')) {
        this.wrist_rotate_angle = initObj.wrist_rotate_angle
      }
      else {
        this.wrist_rotate_angle = 0;
      }
      if (initObj.hasOwnProperty('wrist_rotate_speed')) {
        this.wrist_rotate_speed = initObj.wrist_rotate_speed
      }
      else {
        this.wrist_rotate_speed = 0;
      }
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type control_armRequest
    // Serialize message field [base_angle]
    bufferOffset = _serializer.int16(obj.base_angle, buffer, bufferOffset);
    // Serialize message field [base_speed]
    bufferOffset = _serializer.uint8(obj.base_speed, buffer, bufferOffset);
    // Serialize message field [shoulder_angle]
    bufferOffset = _serializer.int16(obj.shoulder_angle, buffer, bufferOffset);
    // Serialize message field [shoulder_speed]
    bufferOffset = _serializer.uint8(obj.shoulder_speed, buffer, bufferOffset);
    // Serialize message field [elbow_angle]
    bufferOffset = _serializer.int16(obj.elbow_angle, buffer, bufferOffset);
    // Serialize message field [elbow_speed]
    bufferOffset = _serializer.uint8(obj.elbow_speed, buffer, bufferOffset);
    // Serialize message field [wrist_angle]
    bufferOffset = _serializer.int16(obj.wrist_angle, buffer, bufferOffset);
    // Serialize message field [wrist_speed]
    bufferOffset = _serializer.uint8(obj.wrist_speed, buffer, bufferOffset);
    // Serialize message field [gripper_angle]
    bufferOffset = _serializer.int16(obj.gripper_angle, buffer, bufferOffset);
    // Serialize message field [gripper_speed]
    bufferOffset = _serializer.uint8(obj.gripper_speed, buffer, bufferOffset);
    // Serialize message field [wrist_rotate_angle]
    bufferOffset = _serializer.int16(obj.wrist_rotate_angle, buffer, bufferOffset);
    // Serialize message field [wrist_rotate_speed]
    bufferOffset = _serializer.uint8(obj.wrist_rotate_speed, buffer, bufferOffset);
    // Serialize message field [time]
    bufferOffset = _serializer.uint16(obj.time, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type control_armRequest
    let len;
    let data = new control_armRequest(null);
    // Deserialize message field [base_angle]
    data.base_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [base_speed]
    data.base_speed = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [shoulder_angle]
    data.shoulder_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [shoulder_speed]
    data.shoulder_speed = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [elbow_angle]
    data.elbow_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [elbow_speed]
    data.elbow_speed = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [wrist_angle]
    data.wrist_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [wrist_speed]
    data.wrist_speed = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [gripper_angle]
    data.gripper_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gripper_speed]
    data.gripper_speed = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [wrist_rotate_angle]
    data.wrist_rotate_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [wrist_rotate_speed]
    data.wrist_rotate_speed = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [time]
    data.time = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a service object
    return 'driver/control_armRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cd10510da7b0daa1c1d87a003f9b006d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 base_angle
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new control_armRequest(null);
    if (msg.base_angle !== undefined) {
      resolved.base_angle = msg.base_angle;
    }
    else {
      resolved.base_angle = 0
    }

    if (msg.base_speed !== undefined) {
      resolved.base_speed = msg.base_speed;
    }
    else {
      resolved.base_speed = 0
    }

    if (msg.shoulder_angle !== undefined) {
      resolved.shoulder_angle = msg.shoulder_angle;
    }
    else {
      resolved.shoulder_angle = 0
    }

    if (msg.shoulder_speed !== undefined) {
      resolved.shoulder_speed = msg.shoulder_speed;
    }
    else {
      resolved.shoulder_speed = 0
    }

    if (msg.elbow_angle !== undefined) {
      resolved.elbow_angle = msg.elbow_angle;
    }
    else {
      resolved.elbow_angle = 0
    }

    if (msg.elbow_speed !== undefined) {
      resolved.elbow_speed = msg.elbow_speed;
    }
    else {
      resolved.elbow_speed = 0
    }

    if (msg.wrist_angle !== undefined) {
      resolved.wrist_angle = msg.wrist_angle;
    }
    else {
      resolved.wrist_angle = 0
    }

    if (msg.wrist_speed !== undefined) {
      resolved.wrist_speed = msg.wrist_speed;
    }
    else {
      resolved.wrist_speed = 0
    }

    if (msg.gripper_angle !== undefined) {
      resolved.gripper_angle = msg.gripper_angle;
    }
    else {
      resolved.gripper_angle = 0
    }

    if (msg.gripper_speed !== undefined) {
      resolved.gripper_speed = msg.gripper_speed;
    }
    else {
      resolved.gripper_speed = 0
    }

    if (msg.wrist_rotate_angle !== undefined) {
      resolved.wrist_rotate_angle = msg.wrist_rotate_angle;
    }
    else {
      resolved.wrist_rotate_angle = 0
    }

    if (msg.wrist_rotate_speed !== undefined) {
      resolved.wrist_rotate_speed = msg.wrist_rotate_speed;
    }
    else {
      resolved.wrist_rotate_speed = 0
    }

    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0
    }

    return resolved;
    }
};

class control_armResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.succes = null;
    }
    else {
      if (initObj.hasOwnProperty('succes')) {
        this.succes = initObj.succes
      }
      else {
        this.succes = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type control_armResponse
    // Serialize message field [succes]
    bufferOffset = _serializer.bool(obj.succes, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type control_armResponse
    let len;
    let data = new control_armResponse(null);
    // Deserialize message field [succes]
    data.succes = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'driver/control_armResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '509793171e494962cd366ecf60e100e4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool succes
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new control_armResponse(null);
    if (msg.succes !== undefined) {
      resolved.succes = msg.succes;
    }
    else {
      resolved.succes = false
    }

    return resolved;
    }
};

module.exports = {
  Request: control_armRequest,
  Response: control_armResponse,
  md5sum() { return '2830068845fb2505b4060ad2eb804a4f'; },
  datatype() { return 'driver/control_arm'; }
};

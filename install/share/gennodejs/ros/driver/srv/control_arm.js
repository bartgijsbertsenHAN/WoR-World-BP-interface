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
      this.angles = null;
      this.speeds = null;
      this.time = null;
    }
    else {
      if (initObj.hasOwnProperty('angles')) {
        this.angles = initObj.angles
      }
      else {
        this.angles = [];
      }
      if (initObj.hasOwnProperty('speeds')) {
        this.speeds = initObj.speeds
      }
      else {
        this.speeds = [];
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
    // Serialize message field [angles]
    bufferOffset = _arraySerializer.int16(obj.angles, buffer, bufferOffset, null);
    // Serialize message field [speeds]
    bufferOffset = _arraySerializer.uint8(obj.speeds, buffer, bufferOffset, null);
    // Serialize message field [time]
    bufferOffset = _serializer.uint16(obj.time, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type control_armRequest
    let len;
    let data = new control_armRequest(null);
    // Deserialize message field [angles]
    data.angles = _arrayDeserializer.int16(buffer, bufferOffset, null)
    // Deserialize message field [speeds]
    data.speeds = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [time]
    data.time = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 2 * object.angles.length;
    length += object.speeds.length;
    return length + 10;
  }

  static datatype() {
    // Returns string type for a service object
    return 'driver/control_armRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f2060963bec26b478635ecaf1f13b9fd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16[] angles
    uint8[] speeds
    uint16 time
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new control_armRequest(null);
    if (msg.angles !== undefined) {
      resolved.angles = msg.angles;
    }
    else {
      resolved.angles = []
    }

    if (msg.speeds !== undefined) {
      resolved.speeds = msg.speeds;
    }
    else {
      resolved.speeds = []
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
  md5sum() { return '9f92a49c54ce202a35ae4e75b5fee653'; },
  datatype() { return 'driver/control_arm'; }
};

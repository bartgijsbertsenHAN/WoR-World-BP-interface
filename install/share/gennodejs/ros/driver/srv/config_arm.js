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

class config_armRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.angle_offsets = null;
    }
    else {
      if (initObj.hasOwnProperty('angle_offsets')) {
        this.angle_offsets = initObj.angle_offsets
      }
      else {
        this.angle_offsets = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type config_armRequest
    // Serialize message field [angle_offsets]
    bufferOffset = _arraySerializer.int8(obj.angle_offsets, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type config_armRequest
    let len;
    let data = new config_armRequest(null);
    // Deserialize message field [angle_offsets]
    data.angle_offsets = _arrayDeserializer.int8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.angle_offsets.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'driver/config_armRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4c19c548d8915eb1b329adf0e59179cb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8[] angle_offsets
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new config_armRequest(null);
    if (msg.angle_offsets !== undefined) {
      resolved.angle_offsets = msg.angle_offsets;
    }
    else {
      resolved.angle_offsets = []
    }

    return resolved;
    }
};

class config_armResponse {
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
    // Serializes a message object of type config_armResponse
    // Serialize message field [succes]
    bufferOffset = _serializer.bool(obj.succes, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type config_armResponse
    let len;
    let data = new config_armResponse(null);
    // Deserialize message field [succes]
    data.succes = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'driver/config_armResponse';
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
    const resolved = new config_armResponse(null);
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
  Request: config_armRequest,
  Response: config_armResponse,
  md5sum() { return '437dcc9253614fa63d9b9cff189a86cc'; },
  datatype() { return 'driver/config_arm'; }
};

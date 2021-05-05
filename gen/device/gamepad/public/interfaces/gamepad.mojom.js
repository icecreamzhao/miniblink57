// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/gamepad/public/interfaces/gamepad.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var GamepadHand = {};
  GamepadHand.GamepadHandNone = 0;
  GamepadHand.GamepadHandLeft = 1;
  GamepadHand.GamepadHandRight = 2;

  GamepadHand.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  GamepadHand.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function GamepadQuaternion(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadQuaternion.prototype.initDefaults_ = function() {
    this.x = 0;
    this.y = 0;
    this.z = 0;
    this.w = 0;
  };
  GamepadQuaternion.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadQuaternion.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;





    return validator.validationError.NONE;
  };

  GamepadQuaternion.encodedSize = codec.kStructHeaderSize + 16;

  GamepadQuaternion.decode = function(decoder) {
    var packed;
    var val = new GamepadQuaternion();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.x = decoder.decodeStruct(codec.Float);
    val.y = decoder.decodeStruct(codec.Float);
    val.z = decoder.decodeStruct(codec.Float);
    val.w = decoder.decodeStruct(codec.Float);
    return val;
  };

  GamepadQuaternion.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadQuaternion.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.x);
    encoder.encodeStruct(codec.Float, val.y);
    encoder.encodeStruct(codec.Float, val.z);
    encoder.encodeStruct(codec.Float, val.w);
  };
  function GamepadVector(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadVector.prototype.initDefaults_ = function() {
    this.x = 0;
    this.y = 0;
    this.z = 0;
  };
  GamepadVector.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadVector.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  GamepadVector.encodedSize = codec.kStructHeaderSize + 16;

  GamepadVector.decode = function(decoder) {
    var packed;
    var val = new GamepadVector();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.x = decoder.decodeStruct(codec.Float);
    val.y = decoder.decodeStruct(codec.Float);
    val.z = decoder.decodeStruct(codec.Float);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GamepadVector.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadVector.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.x);
    encoder.encodeStruct(codec.Float, val.y);
    encoder.encodeStruct(codec.Float, val.z);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GamepadButton(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadButton.prototype.initDefaults_ = function() {
    this.pressed = false;
    this.touched = false;
    this.value = 0;
  };
  GamepadButton.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadButton.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  GamepadButton.encodedSize = codec.kStructHeaderSize + 16;

  GamepadButton.decode = function(decoder) {
    var packed;
    var val = new GamepadButton();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.pressed = (packed >> 0) & 1 ? true : false;
    val.touched = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.value = decoder.decodeStruct(codec.Double);
    return val;
  };

  GamepadButton.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadButton.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.pressed & 1) << 0
    packed |= (val.touched & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Double, val.value);
  };
  function GamepadPose(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadPose.prototype.initDefaults_ = function() {
    this.orientation = null;
    this.position = null;
    this.angular_velocity = null;
    this.linear_velocity = null;
    this.angular_acceleration = null;
    this.linear_acceleration = null;
  };
  GamepadPose.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadPose.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 56}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadPose.orientation
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, GamepadQuaternion, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadPose.position
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, GamepadVector, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadPose.angular_velocity
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, GamepadVector, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadPose.linear_velocity
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, GamepadVector, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadPose.angular_acceleration
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, GamepadVector, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadPose.linear_acceleration
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, GamepadVector, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadPose.encodedSize = codec.kStructHeaderSize + 48;

  GamepadPose.decode = function(decoder) {
    var packed;
    var val = new GamepadPose();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.orientation = decoder.decodeStructPointer(GamepadQuaternion);
    val.position = decoder.decodeStructPointer(GamepadVector);
    val.angular_velocity = decoder.decodeStructPointer(GamepadVector);
    val.linear_velocity = decoder.decodeStructPointer(GamepadVector);
    val.angular_acceleration = decoder.decodeStructPointer(GamepadVector);
    val.linear_acceleration = decoder.decodeStructPointer(GamepadVector);
    return val;
  };

  GamepadPose.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadPose.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(GamepadQuaternion, val.orientation);
    encoder.encodeStructPointer(GamepadVector, val.position);
    encoder.encodeStructPointer(GamepadVector, val.angular_velocity);
    encoder.encodeStructPointer(GamepadVector, val.linear_velocity);
    encoder.encodeStructPointer(GamepadVector, val.angular_acceleration);
    encoder.encodeStructPointer(GamepadVector, val.linear_acceleration);
  };
  function Gamepad(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Gamepad.prototype.initDefaults_ = function() {
    this.connected = false;
    this.hand = 0;
    this.id = null;
    this.timestamp = 0;
    this.axes = null;
    this.buttons = null;
    this.mapping = null;
    this.pose = null;
    this.display_id = 0;
  };
  Gamepad.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Gamepad.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 72}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate Gamepad.id
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 2, codec.Uint16, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate Gamepad.axes
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 24, 8, codec.Double, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gamepad.buttons
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 32, 8, new codec.PointerTo(GamepadButton), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gamepad.mapping
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 40, 2, codec.Uint16, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gamepad.pose
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 48, GamepadPose, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gamepad.hand
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, GamepadHand);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  Gamepad.encodedSize = codec.kStructHeaderSize + 64;

  Gamepad.decode = function(decoder) {
    var packed;
    var val = new Gamepad();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.connected = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.hand = decoder.decodeStruct(codec.Int32);
    val.id = decoder.decodeArrayPointer(codec.Uint16);
    val.timestamp = decoder.decodeStruct(codec.Uint64);
    val.axes = decoder.decodeArrayPointer(codec.Double);
    val.buttons = decoder.decodeArrayPointer(new codec.PointerTo(GamepadButton));
    val.mapping = decoder.decodeArrayPointer(codec.Uint16);
    val.pose = decoder.decodeStructPointer(GamepadPose);
    val.display_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Gamepad.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Gamepad.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.connected & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.hand);
    encoder.encodeArrayPointer(codec.Uint16, val.id);
    encoder.encodeStruct(codec.Uint64, val.timestamp);
    encoder.encodeArrayPointer(codec.Double, val.axes);
    encoder.encodeArrayPointer(new codec.PointerTo(GamepadButton), val.buttons);
    encoder.encodeArrayPointer(codec.Uint16, val.mapping);
    encoder.encodeStructPointer(GamepadPose, val.pose);
    encoder.encodeStruct(codec.Uint32, val.display_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GamepadObserver_GamepadConnected_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadObserver_GamepadConnected_Params.prototype.initDefaults_ = function() {
    this.index = 0;
    this.gamepad = null;
  };
  GamepadObserver_GamepadConnected_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadObserver_GamepadConnected_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate GamepadObserver_GamepadConnected_Params.gamepad
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, Gamepad, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadObserver_GamepadConnected_Params.encodedSize = codec.kStructHeaderSize + 16;

  GamepadObserver_GamepadConnected_Params.decode = function(decoder) {
    var packed;
    var val = new GamepadObserver_GamepadConnected_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.index = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.gamepad = decoder.decodeStructPointer(Gamepad);
    return val;
  };

  GamepadObserver_GamepadConnected_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadObserver_GamepadConnected_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.index);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(Gamepad, val.gamepad);
  };
  function GamepadObserver_GamepadDisconnected_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadObserver_GamepadDisconnected_Params.prototype.initDefaults_ = function() {
    this.index = 0;
    this.gamepad = null;
  };
  GamepadObserver_GamepadDisconnected_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadObserver_GamepadDisconnected_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate GamepadObserver_GamepadDisconnected_Params.gamepad
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, Gamepad, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadObserver_GamepadDisconnected_Params.encodedSize = codec.kStructHeaderSize + 16;

  GamepadObserver_GamepadDisconnected_Params.decode = function(decoder) {
    var packed;
    var val = new GamepadObserver_GamepadDisconnected_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.index = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.gamepad = decoder.decodeStructPointer(Gamepad);
    return val;
  };

  GamepadObserver_GamepadDisconnected_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadObserver_GamepadDisconnected_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.index);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(Gamepad, val.gamepad);
  };
  function GamepadMonitor_GamepadStartPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadMonitor_GamepadStartPolling_Params.prototype.initDefaults_ = function() {
  };
  GamepadMonitor_GamepadStartPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadMonitor_GamepadStartPolling_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadMonitor_GamepadStartPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  GamepadMonitor_GamepadStartPolling_Params.decode = function(decoder) {
    var packed;
    var val = new GamepadMonitor_GamepadStartPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  GamepadMonitor_GamepadStartPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadMonitor_GamepadStartPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function GamepadMonitor_GamepadStartPolling_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadMonitor_GamepadStartPolling_ResponseParams.prototype.initDefaults_ = function() {
    this.memory_handle = null;
  };
  GamepadMonitor_GamepadStartPolling_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadMonitor_GamepadStartPolling_ResponseParams.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 16}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadMonitor_GamepadStartPolling_ResponseParams.memory_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadMonitor_GamepadStartPolling_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  GamepadMonitor_GamepadStartPolling_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new GamepadMonitor_GamepadStartPolling_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.memory_handle = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GamepadMonitor_GamepadStartPolling_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadMonitor_GamepadStartPolling_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.memory_handle);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GamepadMonitor_GamepadStopPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadMonitor_GamepadStopPolling_Params.prototype.initDefaults_ = function() {
  };
  GamepadMonitor_GamepadStopPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadMonitor_GamepadStopPolling_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadMonitor_GamepadStopPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  GamepadMonitor_GamepadStopPolling_Params.decode = function(decoder) {
    var packed;
    var val = new GamepadMonitor_GamepadStopPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  GamepadMonitor_GamepadStopPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadMonitor_GamepadStopPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function GamepadMonitor_GamepadStopPolling_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadMonitor_GamepadStopPolling_ResponseParams.prototype.initDefaults_ = function() {
  };
  GamepadMonitor_GamepadStopPolling_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadMonitor_GamepadStopPolling_ResponseParams.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadMonitor_GamepadStopPolling_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  GamepadMonitor_GamepadStopPolling_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new GamepadMonitor_GamepadStopPolling_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  GamepadMonitor_GamepadStopPolling_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadMonitor_GamepadStopPolling_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  function GamepadMonitor_SetObserver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GamepadMonitor_SetObserver_Params.prototype.initDefaults_ = function() {
    this.gamepad_observer = new GamepadObserverPtr();
  };
  GamepadMonitor_SetObserver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GamepadMonitor_SetObserver_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 16}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GamepadMonitor_SetObserver_Params.gamepad_observer
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GamepadMonitor_SetObserver_Params.encodedSize = codec.kStructHeaderSize + 8;

  GamepadMonitor_SetObserver_Params.decode = function(decoder) {
    var packed;
    var val = new GamepadMonitor_SetObserver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.gamepad_observer = decoder.decodeStruct(new codec.Interface(GamepadObserverPtr));
    return val;
  };

  GamepadMonitor_SetObserver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GamepadMonitor_SetObserver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(GamepadObserverPtr), val.gamepad_observer);
  };
  var kGamepadObserver_GamepadConnected_Name = 0;
  var kGamepadObserver_GamepadDisconnected_Name = 1;

  function GamepadObserverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(GamepadObserver,
                                                   handleOrPtrInfo);
  }

  function GamepadObserverProxy(receiver) {
    this.receiver_ = receiver;
  }
  GamepadObserverPtr.prototype.gamepadConnected = function() {
    return GamepadObserverProxy.prototype.gamepadConnected
        .apply(this.ptr.getProxy(), arguments);
  };

  GamepadObserverProxy.prototype.gamepadConnected = function(index, gamepad) {
    var params = new GamepadObserver_GamepadConnected_Params();
    params.index = index;
    params.gamepad = gamepad;
    var builder = new codec.MessageBuilder(
        kGamepadObserver_GamepadConnected_Name,
        codec.align(GamepadObserver_GamepadConnected_Params.encodedSize));
    builder.encodeStruct(GamepadObserver_GamepadConnected_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GamepadObserverPtr.prototype.gamepadDisconnected = function() {
    return GamepadObserverProxy.prototype.gamepadDisconnected
        .apply(this.ptr.getProxy(), arguments);
  };

  GamepadObserverProxy.prototype.gamepadDisconnected = function(index, gamepad) {
    var params = new GamepadObserver_GamepadDisconnected_Params();
    params.index = index;
    params.gamepad = gamepad;
    var builder = new codec.MessageBuilder(
        kGamepadObserver_GamepadDisconnected_Name,
        codec.align(GamepadObserver_GamepadDisconnected_Params.encodedSize));
    builder.encodeStruct(GamepadObserver_GamepadDisconnected_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function GamepadObserverStub(delegate) {
    this.delegate_ = delegate;
  }
  GamepadObserverStub.prototype.gamepadConnected = function(index, gamepad) {
    return this.delegate_ && this.delegate_.gamepadConnected && this.delegate_.gamepadConnected(index, gamepad);
  }
  GamepadObserverStub.prototype.gamepadDisconnected = function(index, gamepad) {
    return this.delegate_ && this.delegate_.gamepadDisconnected && this.delegate_.gamepadDisconnected(index, gamepad);
  }

  GamepadObserverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGamepadObserver_GamepadConnected_Name:
      var params = reader.decodeStruct(GamepadObserver_GamepadConnected_Params);
      this.gamepadConnected(params.index, params.gamepad);
      return true;
    case kGamepadObserver_GamepadDisconnected_Name:
      var params = reader.decodeStruct(GamepadObserver_GamepadDisconnected_Params);
      this.gamepadDisconnected(params.index, params.gamepad);
      return true;
    default:
      return false;
    }
  };

  GamepadObserverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateGamepadObserverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kGamepadObserver_GamepadConnected_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GamepadObserver_GamepadConnected_Params;
      break;
      case kGamepadObserver_GamepadDisconnected_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GamepadObserver_GamepadDisconnected_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateGamepadObserverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var GamepadObserver = {
    name: 'device::mojom::GamepadObserver',
    ptrClass: GamepadObserverPtr,
    proxyClass: GamepadObserverProxy,
    stubClass: GamepadObserverStub,
    validateRequest: validateGamepadObserverRequest,
    validateResponse: null,
  };
  GamepadObserverStub.prototype.validator = validateGamepadObserverRequest;
  GamepadObserverProxy.prototype.validator = null;
  var kGamepadMonitor_GamepadStartPolling_Name = 0;
  var kGamepadMonitor_GamepadStopPolling_Name = 1;
  var kGamepadMonitor_SetObserver_Name = 2;

  function GamepadMonitorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(GamepadMonitor,
                                                   handleOrPtrInfo);
  }

  function GamepadMonitorProxy(receiver) {
    this.receiver_ = receiver;
  }
  GamepadMonitorPtr.prototype.gamepadStartPolling = function() {
    return GamepadMonitorProxy.prototype.gamepadStartPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  GamepadMonitorProxy.prototype.gamepadStartPolling = function() {
    var params = new GamepadMonitor_GamepadStartPolling_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kGamepadMonitor_GamepadStartPolling_Name,
          codec.align(GamepadMonitor_GamepadStartPolling_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(GamepadMonitor_GamepadStartPolling_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(GamepadMonitor_GamepadStartPolling_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  GamepadMonitorPtr.prototype.gamepadStopPolling = function() {
    return GamepadMonitorProxy.prototype.gamepadStopPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  GamepadMonitorProxy.prototype.gamepadStopPolling = function() {
    var params = new GamepadMonitor_GamepadStopPolling_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kGamepadMonitor_GamepadStopPolling_Name,
          codec.align(GamepadMonitor_GamepadStopPolling_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(GamepadMonitor_GamepadStopPolling_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(GamepadMonitor_GamepadStopPolling_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  GamepadMonitorPtr.prototype.setObserver = function() {
    return GamepadMonitorProxy.prototype.setObserver
        .apply(this.ptr.getProxy(), arguments);
  };

  GamepadMonitorProxy.prototype.setObserver = function(gamepad_observer) {
    var params = new GamepadMonitor_SetObserver_Params();
    params.gamepad_observer = gamepad_observer;
    var builder = new codec.MessageBuilder(
        kGamepadMonitor_SetObserver_Name,
        codec.align(GamepadMonitor_SetObserver_Params.encodedSize));
    builder.encodeStruct(GamepadMonitor_SetObserver_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function GamepadMonitorStub(delegate) {
    this.delegate_ = delegate;
  }
  GamepadMonitorStub.prototype.gamepadStartPolling = function() {
    return this.delegate_ && this.delegate_.gamepadStartPolling && this.delegate_.gamepadStartPolling();
  }
  GamepadMonitorStub.prototype.gamepadStopPolling = function() {
    return this.delegate_ && this.delegate_.gamepadStopPolling && this.delegate_.gamepadStopPolling();
  }
  GamepadMonitorStub.prototype.setObserver = function(gamepad_observer) {
    return this.delegate_ && this.delegate_.setObserver && this.delegate_.setObserver(gamepad_observer);
  }

  GamepadMonitorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGamepadMonitor_SetObserver_Name:
      var params = reader.decodeStruct(GamepadMonitor_SetObserver_Params);
      this.setObserver(params.gamepad_observer);
      return true;
    default:
      return false;
    }
  };

  GamepadMonitorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGamepadMonitor_GamepadStartPolling_Name:
      var params = reader.decodeStruct(GamepadMonitor_GamepadStartPolling_Params);
      return this.gamepadStartPolling().then(function(response) {
        var responseParams =
            new GamepadMonitor_GamepadStartPolling_ResponseParams();
        responseParams.memory_handle = response.memory_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kGamepadMonitor_GamepadStartPolling_Name,
            codec.align(GamepadMonitor_GamepadStartPolling_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(GamepadMonitor_GamepadStartPolling_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kGamepadMonitor_GamepadStopPolling_Name:
      var params = reader.decodeStruct(GamepadMonitor_GamepadStopPolling_Params);
      return this.gamepadStopPolling().then(function(response) {
        var responseParams =
            new GamepadMonitor_GamepadStopPolling_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kGamepadMonitor_GamepadStopPolling_Name,
            codec.align(GamepadMonitor_GamepadStopPolling_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(GamepadMonitor_GamepadStopPolling_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateGamepadMonitorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kGamepadMonitor_GamepadStartPolling_Name:
        if (message.expectsResponse())
          paramsClass = GamepadMonitor_GamepadStartPolling_Params;
      break;
      case kGamepadMonitor_GamepadStopPolling_Name:
        if (message.expectsResponse())
          paramsClass = GamepadMonitor_GamepadStopPolling_Params;
      break;
      case kGamepadMonitor_SetObserver_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GamepadMonitor_SetObserver_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateGamepadMonitorResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kGamepadMonitor_GamepadStartPolling_Name:
        if (message.isResponse())
          paramsClass = GamepadMonitor_GamepadStartPolling_ResponseParams;
        break;
      case kGamepadMonitor_GamepadStopPolling_Name:
        if (message.isResponse())
          paramsClass = GamepadMonitor_GamepadStopPolling_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var GamepadMonitor = {
    name: 'device::mojom::GamepadMonitor',
    ptrClass: GamepadMonitorPtr,
    proxyClass: GamepadMonitorProxy,
    stubClass: GamepadMonitorStub,
    validateRequest: validateGamepadMonitorRequest,
    validateResponse: validateGamepadMonitorResponse,
  };
  GamepadMonitorStub.prototype.validator = validateGamepadMonitorRequest;
  GamepadMonitorProxy.prototype.validator = validateGamepadMonitorResponse;

  var exports = {};
  exports.GamepadHand = GamepadHand;
  exports.GamepadQuaternion = GamepadQuaternion;
  exports.GamepadVector = GamepadVector;
  exports.GamepadButton = GamepadButton;
  exports.GamepadPose = GamepadPose;
  exports.Gamepad = Gamepad;
  exports.GamepadObserver = GamepadObserver;
  exports.GamepadObserverPtr = GamepadObserverPtr;
  exports.GamepadMonitor = GamepadMonitor;
  exports.GamepadMonitorPtr = GamepadMonitorPtr;

  return exports;
});
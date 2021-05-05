// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/events/mojo/event.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/events/mojo/event_constants.mojom",
    "ui/events/mojo/keyboard_codes.mojom",
], function(bindings, codec, core, validator, event_constants$, keyboard_codes$) {

  function KeyData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  KeyData.prototype.initDefaults_ = function() {
    this.key_code = 0;
    this.is_char = false;
    this.character = 0;
    this.windows_key_code = 0;
    this.native_key_code = 0;
    this.text = 0;
    this.unmodified_text = 0;
  };
  KeyData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  KeyData.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 32}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;





    
    // validate KeyData.windows_key_code
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, keyboard_codes$.KeyboardCode);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  KeyData.encodedSize = codec.kStructHeaderSize + 24;

  KeyData.decode = function(decoder) {
    var packed;
    var val = new KeyData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key_code = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.is_char = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    val.character = decoder.decodeStruct(codec.Uint16);
    val.windows_key_code = decoder.decodeStruct(codec.Int32);
    val.native_key_code = decoder.decodeStruct(codec.Int32);
    val.text = decoder.decodeStruct(codec.Uint16);
    val.unmodified_text = decoder.decodeStruct(codec.Uint16);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  KeyData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(KeyData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.key_code);
    packed = 0;
    packed |= (val.is_char & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint16, val.character);
    encoder.encodeStruct(codec.Int32, val.windows_key_code);
    encoder.encodeStruct(codec.Int32, val.native_key_code);
    encoder.encodeStruct(codec.Uint16, val.text);
    encoder.encodeStruct(codec.Uint16, val.unmodified_text);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LocationData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LocationData.prototype.initDefaults_ = function() {
    this.x = 0;
    this.y = 0;
    this.screen_x = 0;
    this.screen_y = 0;
  };
  LocationData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LocationData.validate = function(messageValidator, offset) {
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

  LocationData.encodedSize = codec.kStructHeaderSize + 16;

  LocationData.decode = function(decoder) {
    var packed;
    var val = new LocationData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.x = decoder.decodeStruct(codec.Float);
    val.y = decoder.decodeStruct(codec.Float);
    val.screen_x = decoder.decodeStruct(codec.Float);
    val.screen_y = decoder.decodeStruct(codec.Float);
    return val;
  };

  LocationData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LocationData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.x);
    encoder.encodeStruct(codec.Float, val.y);
    encoder.encodeStruct(codec.Float, val.screen_x);
    encoder.encodeStruct(codec.Float, val.screen_y);
  };
  function PointerData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PointerData.prototype.initDefaults_ = function() {
    this.pointer_id = 0;
    this.changed_button_flags = 0;
    this.kind = 0;
    this.location = null;
    this.brush_data = null;
    this.wheel_data = null;
  };
  PointerData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PointerData.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 48}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;




    
    // validate PointerData.kind
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, event_constants$.PointerKind);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PointerData.location
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, LocationData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PointerData.brush_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, BrushData, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PointerData.wheel_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, WheelData, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PointerData.encodedSize = codec.kStructHeaderSize + 40;

  PointerData.decode = function(decoder) {
    var packed;
    var val = new PointerData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.pointer_id = decoder.decodeStruct(codec.Int32);
    val.changed_button_flags = decoder.decodeStruct(codec.Int32);
    val.kind = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.location = decoder.decodeStructPointer(LocationData);
    val.brush_data = decoder.decodeStructPointer(BrushData);
    val.wheel_data = decoder.decodeStructPointer(WheelData);
    return val;
  };

  PointerData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PointerData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.pointer_id);
    encoder.encodeStruct(codec.Int32, val.changed_button_flags);
    encoder.encodeStruct(codec.Int32, val.kind);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(LocationData, val.location);
    encoder.encodeStructPointer(BrushData, val.brush_data);
    encoder.encodeStructPointer(WheelData, val.wheel_data);
  };
  function WheelData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WheelData.prototype.initDefaults_ = function() {
    this.mode = 0;
    this.delta_x = 0;
    this.delta_y = 0;
    this.delta_z = 0;
  };
  WheelData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WheelData.validate = function(messageValidator, offset) {
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


    
    // validate WheelData.mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, event_constants$.WheelMode);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  WheelData.encodedSize = codec.kStructHeaderSize + 16;

  WheelData.decode = function(decoder) {
    var packed;
    var val = new WheelData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.mode = decoder.decodeStruct(codec.Int32);
    val.delta_x = decoder.decodeStruct(codec.Float);
    val.delta_y = decoder.decodeStruct(codec.Float);
    val.delta_z = decoder.decodeStruct(codec.Float);
    return val;
  };

  WheelData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WheelData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.mode);
    encoder.encodeStruct(codec.Float, val.delta_x);
    encoder.encodeStruct(codec.Float, val.delta_y);
    encoder.encodeStruct(codec.Float, val.delta_z);
  };
  function BrushData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BrushData.prototype.initDefaults_ = function() {
    this.width = 0;
    this.height = 0;
    this.pressure = 0;
    this.tilt_x = 0;
    this.tilt_y = 0;
  };
  BrushData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BrushData.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 32}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;






    return validator.validationError.NONE;
  };

  BrushData.encodedSize = codec.kStructHeaderSize + 24;

  BrushData.decode = function(decoder) {
    var packed;
    var val = new BrushData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.width = decoder.decodeStruct(codec.Float);
    val.height = decoder.decodeStruct(codec.Float);
    val.pressure = decoder.decodeStruct(codec.Float);
    val.tilt_x = decoder.decodeStruct(codec.Float);
    val.tilt_y = decoder.decodeStruct(codec.Float);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  BrushData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BrushData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.width);
    encoder.encodeStruct(codec.Float, val.height);
    encoder.encodeStruct(codec.Float, val.pressure);
    encoder.encodeStruct(codec.Float, val.tilt_x);
    encoder.encodeStruct(codec.Float, val.tilt_y);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Event(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Event.prototype.initDefaults_ = function() {
    this.action = 0;
    this.flags = 0;
    this.time_stamp = 0;
    this.key_data = null;
    this.pointer_data = null;
  };
  Event.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Event.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 40}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Event.action
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, event_constants$.EventType);
    if (err !== validator.validationError.NONE)
        return err;




    
    // validate Event.key_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, KeyData, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Event.pointer_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, PointerData, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Event.encodedSize = codec.kStructHeaderSize + 32;

  Event.decode = function(decoder) {
    var packed;
    var val = new Event();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.action = decoder.decodeStruct(codec.Int32);
    val.flags = decoder.decodeStruct(codec.Int32);
    val.time_stamp = decoder.decodeStruct(codec.Int64);
    val.key_data = decoder.decodeStructPointer(KeyData);
    val.pointer_data = decoder.decodeStructPointer(PointerData);
    return val;
  };

  Event.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Event.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.action);
    encoder.encodeStruct(codec.Int32, val.flags);
    encoder.encodeStruct(codec.Int64, val.time_stamp);
    encoder.encodeStructPointer(KeyData, val.key_data);
    encoder.encodeStructPointer(PointerData, val.pointer_data);
  };

  var exports = {};
  exports.KeyData = KeyData;
  exports.LocationData = LocationData;
  exports.PointerData = PointerData;
  exports.WheelData = WheelData;
  exports.BrushData = BrushData;
  exports.Event = Event;

  return exports;
});
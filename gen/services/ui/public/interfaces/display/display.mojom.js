// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/display/display.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, geometry$) {
  var Rotation = {};
  Rotation.VALUE_0 = 0;
  Rotation.VALUE_90 = Rotation.VALUE_0 + 1;
  Rotation.VALUE_180 = Rotation.VALUE_90 + 1;
  Rotation.VALUE_270 = Rotation.VALUE_180 + 1;

  Rotation.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  Rotation.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var TouchSupport = {};
  TouchSupport.UNKNOWN = 0;
  TouchSupport.AVAILABLE = TouchSupport.UNKNOWN + 1;
  TouchSupport.UNAVAILABLE = TouchSupport.AVAILABLE + 1;

  TouchSupport.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  TouchSupport.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function Display(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Display.prototype.initDefaults_ = function() {
    this.id = 0;
    this.bounds = null;
    this.work_area = null;
    this.device_scale_factor = 0;
    this.rotation = 0;
    this.touch_support = 0;
    this.maximum_cursor_size = null;
  };
  Display.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Display.validate = function(messageValidator, offset) {
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



    
    // validate Display.bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Display.work_area
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate Display.rotation
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 28, Rotation);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Display.touch_support
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 32, TouchSupport);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Display.maximum_cursor_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Display.encodedSize = codec.kStructHeaderSize + 48;

  Display.decode = function(decoder) {
    var packed;
    var val = new Display();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Int64);
    val.bounds = decoder.decodeStructPointer(geometry$.Rect);
    val.work_area = decoder.decodeStructPointer(geometry$.Rect);
    val.device_scale_factor = decoder.decodeStruct(codec.Float);
    val.rotation = decoder.decodeStruct(codec.Int32);
    val.touch_support = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.maximum_cursor_size = decoder.decodeStructPointer(geometry$.Size);
    return val;
  };

  Display.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Display.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.id);
    encoder.encodeStructPointer(geometry$.Rect, val.bounds);
    encoder.encodeStructPointer(geometry$.Rect, val.work_area);
    encoder.encodeStruct(codec.Float, val.device_scale_factor);
    encoder.encodeStruct(codec.Int32, val.rotation);
    encoder.encodeStruct(codec.Int32, val.touch_support);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Size, val.maximum_cursor_size);
  };

  var exports = {};
  exports.Rotation = Rotation;
  exports.TouchSupport = TouchSupport;
  exports.Display = Display;

  return exports;
});
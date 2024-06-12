// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/window_tree_constants.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, geometry$) {
  var kDropEffectNone = 0;
  var kDropEffectMove = 1;
  var kDropEffectCopy = 2;
  var kDropEffectLink = 4;
  var kEmbedFlagEmbedderInterceptsEvents = 0x01;
  var EventResult = {};
  EventResult.HANDLED = 0;
  EventResult.UNHANDLED = EventResult.HANDLED + 1;

  EventResult.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  EventResult.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function WindowData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowData.prototype.initDefaults_ = function() {
    this.parent_id = 0;
    this.window_id = 0;
    this.transient_parent_id = 0;
    this.visible = false;
    this.bounds = null;
    this.properties = null;
  };
  WindowData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowData.validate = function(messageValidator, offset) {
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





    
    // validate WindowData.bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowData.properties
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 24, false, codec.String, new codec.ArrayOf(codec.Uint8), false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowData.encodedSize = codec.kStructHeaderSize + 32;

  WindowData.decode = function(decoder) {
    var packed;
    var val = new WindowData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.parent_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.transient_parent_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.visible = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.bounds = decoder.decodeStructPointer(geometry$.Rect);
    val.properties = decoder.decodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8));
    return val;
  };

  WindowData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.parent_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Uint32, val.transient_parent_id);
    packed = 0;
    packed |= (val.visible & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Rect, val.bounds);
    encoder.encodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8), val.properties);
  };

  var exports = {};
  exports.kDropEffectNone = kDropEffectNone;
  exports.kDropEffectMove = kDropEffectMove;
  exports.kDropEffectCopy = kDropEffectCopy;
  exports.kDropEffectLink = kDropEffectLink;
  exports.kEmbedFlagEmbedderInterceptsEvents = kEmbedFlagEmbedderInterceptsEvents;
  exports.EventResult = EventResult;
  exports.WindowData = WindowData;

  return exports;
});
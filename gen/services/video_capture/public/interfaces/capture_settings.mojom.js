// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/video_capture/public/interfaces/capture_settings.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/capture/mojo/video_capture_types.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, video_capture_types$, geometry$) {

  function I420CaptureFormat(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  I420CaptureFormat.prototype.initDefaults_ = function() {
    this.frame_size = null;
    this.frame_rate = 0;
  };
  I420CaptureFormat.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  I420CaptureFormat.validate = function(messageValidator, offset) {
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


    
    // validate I420CaptureFormat.frame_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  I420CaptureFormat.encodedSize = codec.kStructHeaderSize + 16;

  I420CaptureFormat.decode = function(decoder) {
    var packed;
    var val = new I420CaptureFormat();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_size = decoder.decodeStructPointer(geometry$.Size);
    val.frame_rate = decoder.decodeStruct(codec.Float);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  I420CaptureFormat.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(I420CaptureFormat.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.Size, val.frame_size);
    encoder.encodeStruct(codec.Float, val.frame_rate);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function CaptureSettings(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CaptureSettings.prototype.initDefaults_ = function() {
    this.format = null;
    this.resolution_change_policy = 0;
    this.power_line_frequency = 0;
  };
  CaptureSettings.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CaptureSettings.validate = function(messageValidator, offset) {
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


    
    // validate CaptureSettings.format
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, I420CaptureFormat, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CaptureSettings.resolution_change_policy
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, video_capture_types$.ResolutionChangePolicy);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CaptureSettings.power_line_frequency
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 12, video_capture_types$.PowerLineFrequency);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  CaptureSettings.encodedSize = codec.kStructHeaderSize + 16;

  CaptureSettings.decode = function(decoder) {
    var packed;
    var val = new CaptureSettings();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.format = decoder.decodeStructPointer(I420CaptureFormat);
    val.resolution_change_policy = decoder.decodeStruct(codec.Int32);
    val.power_line_frequency = decoder.decodeStruct(codec.Int32);
    return val;
  };

  CaptureSettings.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CaptureSettings.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(I420CaptureFormat, val.format);
    encoder.encodeStruct(codec.Int32, val.resolution_change_policy);
    encoder.encodeStruct(codec.Int32, val.power_line_frequency);
  };

  var exports = {};
  exports.I420CaptureFormat = I420CaptureFormat;
  exports.CaptureSettings = CaptureSettings;

  return exports;
});
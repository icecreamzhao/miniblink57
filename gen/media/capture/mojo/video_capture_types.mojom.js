// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/capture/mojo/video_capture_types.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/media_types.mojom",
    "mojo/common/time.mojom",
    "mojo/common/values.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, media_types$, time$, values$, geometry$) {
  var ResolutionChangePolicy = {};
  ResolutionChangePolicy.FIXED_RESOLUTION = 0;
  ResolutionChangePolicy.FIXED_ASPECT_RATIO = ResolutionChangePolicy.FIXED_RESOLUTION + 1;
  ResolutionChangePolicy.ANY_WITHIN_LIMIT = ResolutionChangePolicy.FIXED_ASPECT_RATIO + 1;

  ResolutionChangePolicy.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  ResolutionChangePolicy.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PowerLineFrequency = {};
  PowerLineFrequency.DEFAULT = 0;
  PowerLineFrequency.HZ_50 = PowerLineFrequency.DEFAULT + 1;
  PowerLineFrequency.HZ_60 = PowerLineFrequency.HZ_50 + 1;

  PowerLineFrequency.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  PowerLineFrequency.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var VideoPixelStorage = {};
  VideoPixelStorage.CPU = 0;
  VideoPixelStorage.GPUMEMORYBUFFER = VideoPixelStorage.CPU + 1;

  VideoPixelStorage.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  VideoPixelStorage.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var VideoCaptureApi = {};
  VideoCaptureApi.LINUX_V4L2_SINGLE_PLANE = 0;
  VideoCaptureApi.WIN_MEDIA_FOUNDATION = VideoCaptureApi.LINUX_V4L2_SINGLE_PLANE + 1;
  VideoCaptureApi.WIN_DIRECT_SHOW = VideoCaptureApi.WIN_MEDIA_FOUNDATION + 1;
  VideoCaptureApi.MACOSX_AVFOUNDATION = VideoCaptureApi.WIN_DIRECT_SHOW + 1;
  VideoCaptureApi.MACOSX_DECKLINK = VideoCaptureApi.MACOSX_AVFOUNDATION + 1;
  VideoCaptureApi.ANDROID_API1 = VideoCaptureApi.MACOSX_DECKLINK + 1;
  VideoCaptureApi.ANDROID_API2_LEGACY = VideoCaptureApi.ANDROID_API1 + 1;
  VideoCaptureApi.ANDROID_API2_FULL = VideoCaptureApi.ANDROID_API2_LEGACY + 1;
  VideoCaptureApi.ANDROID_API2_LIMITED = VideoCaptureApi.ANDROID_API2_FULL + 1;
  VideoCaptureApi.ANDROID_TANGO = VideoCaptureApi.ANDROID_API2_LIMITED + 1;
  VideoCaptureApi.UNKNOWN = VideoCaptureApi.ANDROID_TANGO + 1;

  VideoCaptureApi.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      return true;
    }
    return false;
  };

  VideoCaptureApi.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var VideoCaptureTransportType = {};
  VideoCaptureTransportType.MACOSX_USB_OR_BUILT_IN = 0;
  VideoCaptureTransportType.OTHER_TRANSPORT = VideoCaptureTransportType.MACOSX_USB_OR_BUILT_IN + 1;

  VideoCaptureTransportType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  VideoCaptureTransportType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function VideoCaptureFormat(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoCaptureFormat.prototype.initDefaults_ = function() {
    this.frame_size = null;
    this.frame_rate = 0;
    this.pixel_format = 0;
    this.pixel_storage = 0;
  };
  VideoCaptureFormat.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoCaptureFormat.validate = function(messageValidator, offset) {
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


    
    // validate VideoCaptureFormat.frame_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate VideoCaptureFormat.pixel_format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 12, media_types$.VideoPixelFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoCaptureFormat.pixel_storage
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, VideoPixelStorage);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoCaptureFormat.encodedSize = codec.kStructHeaderSize + 24;

  VideoCaptureFormat.decode = function(decoder) {
    var packed;
    var val = new VideoCaptureFormat();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_size = decoder.decodeStructPointer(geometry$.Size);
    val.frame_rate = decoder.decodeStruct(codec.Float);
    val.pixel_format = decoder.decodeStruct(codec.Int32);
    val.pixel_storage = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VideoCaptureFormat.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoCaptureFormat.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.Size, val.frame_size);
    encoder.encodeStruct(codec.Float, val.frame_rate);
    encoder.encodeStruct(codec.Int32, val.pixel_format);
    encoder.encodeStruct(codec.Int32, val.pixel_storage);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VideoCaptureParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoCaptureParams.prototype.initDefaults_ = function() {
    this.requested_format = null;
    this.resolution_change_policy = 0;
    this.power_line_frequency = 0;
  };
  VideoCaptureParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoCaptureParams.validate = function(messageValidator, offset) {
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


    
    // validate VideoCaptureParams.requested_format
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, VideoCaptureFormat, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoCaptureParams.resolution_change_policy
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, ResolutionChangePolicy);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoCaptureParams.power_line_frequency
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 12, PowerLineFrequency);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoCaptureParams.encodedSize = codec.kStructHeaderSize + 16;

  VideoCaptureParams.decode = function(decoder) {
    var packed;
    var val = new VideoCaptureParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.requested_format = decoder.decodeStructPointer(VideoCaptureFormat);
    val.resolution_change_policy = decoder.decodeStruct(codec.Int32);
    val.power_line_frequency = decoder.decodeStruct(codec.Int32);
    return val;
  };

  VideoCaptureParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoCaptureParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(VideoCaptureFormat, val.requested_format);
    encoder.encodeStruct(codec.Int32, val.resolution_change_policy);
    encoder.encodeStruct(codec.Int32, val.power_line_frequency);
  };
  function VideoFrameInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoFrameInfo.prototype.initDefaults_ = function() {
    this.timestamp = null;
    this.metadata = null;
    this.pixel_format = 0;
    this.storage_type = 0;
    this.coded_size = null;
    this.visible_rect = null;
  };
  VideoFrameInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoFrameInfo.validate = function(messageValidator, offset) {
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


    
    // validate VideoFrameInfo.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrameInfo.metadata
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, values$.DictionaryValue, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrameInfo.pixel_format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, media_types$.VideoPixelFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrameInfo.storage_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 20, VideoPixelStorage);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrameInfo.coded_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrameInfo.visible_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoFrameInfo.encodedSize = codec.kStructHeaderSize + 40;

  VideoFrameInfo.decode = function(decoder) {
    var packed;
    var val = new VideoFrameInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.timestamp = decoder.decodeStructPointer(time$.TimeDelta);
    val.metadata = decoder.decodeStructPointer(values$.DictionaryValue);
    val.pixel_format = decoder.decodeStruct(codec.Int32);
    val.storage_type = decoder.decodeStruct(codec.Int32);
    val.coded_size = decoder.decodeStructPointer(geometry$.Size);
    val.visible_rect = decoder.decodeStructPointer(geometry$.Rect);
    return val;
  };

  VideoFrameInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoFrameInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(time$.TimeDelta, val.timestamp);
    encoder.encodeStructPointer(values$.DictionaryValue, val.metadata);
    encoder.encodeStruct(codec.Int32, val.pixel_format);
    encoder.encodeStruct(codec.Int32, val.storage_type);
    encoder.encodeStructPointer(geometry$.Size, val.coded_size);
    encoder.encodeStructPointer(geometry$.Rect, val.visible_rect);
  };

  var exports = {};
  exports.ResolutionChangePolicy = ResolutionChangePolicy;
  exports.PowerLineFrequency = PowerLineFrequency;
  exports.VideoPixelStorage = VideoPixelStorage;
  exports.VideoCaptureApi = VideoCaptureApi;
  exports.VideoCaptureTransportType = VideoCaptureTransportType;
  exports.VideoCaptureFormat = VideoCaptureFormat;
  exports.VideoCaptureParams = VideoCaptureParams;
  exports.VideoFrameInfo = VideoFrameInfo;

  return exports;
});
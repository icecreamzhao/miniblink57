// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/video_capture/public/interfaces/device_descriptor.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
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

  function DeviceDescriptor(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceDescriptor.prototype.initDefaults_ = function() {
    this.display_name = null;
    this.device_id = null;
    this.model_id = null;
    this.capture_api = 0;
    this.transport_type = 0;
  };
  DeviceDescriptor.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceDescriptor.validate = function(messageValidator, offset) {
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


    
    // validate DeviceDescriptor.display_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceDescriptor.device_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceDescriptor.model_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceDescriptor.capture_api
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 24, VideoCaptureApi);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceDescriptor.transport_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 28, VideoCaptureTransportType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DeviceDescriptor.encodedSize = codec.kStructHeaderSize + 32;

  DeviceDescriptor.decode = function(decoder) {
    var packed;
    var val = new DeviceDescriptor();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.display_name = decoder.decodeStruct(codec.String);
    val.device_id = decoder.decodeStruct(codec.String);
    val.model_id = decoder.decodeStruct(codec.String);
    val.capture_api = decoder.decodeStruct(codec.Int32);
    val.transport_type = decoder.decodeStruct(codec.Int32);
    return val;
  };

  DeviceDescriptor.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceDescriptor.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.display_name);
    encoder.encodeStruct(codec.String, val.device_id);
    encoder.encodeStruct(codec.String, val.model_id);
    encoder.encodeStruct(codec.Int32, val.capture_api);
    encoder.encodeStruct(codec.Int32, val.transport_type);
  };

  var exports = {};
  exports.VideoCaptureApi = VideoCaptureApi;
  exports.VideoCaptureTransportType = VideoCaptureTransportType;
  exports.DeviceDescriptor = DeviceDescriptor;

  return exports;
});
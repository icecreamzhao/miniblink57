// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/video_capture/public/interfaces/device.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/capture/mojo/video_capture_types.mojom",
    "services/video_capture/public/interfaces/capture_settings.mojom",
    "services/video_capture/public/interfaces/receiver.mojom",
], function(bindings, codec, core, validator, video_capture_types$, capture_settings$, receiver$) {

  function Device_Start_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_Start_Params.prototype.initDefaults_ = function() {
    this.requested_settings = null;
    this.receiver = new receiver$.ReceiverPtr();
  };
  Device_Start_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_Start_Params.validate = function(messageValidator, offset) {
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


    
    // validate Device_Start_Params.requested_settings
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, capture_settings$.CaptureSettings, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Device_Start_Params.receiver
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_Start_Params.encodedSize = codec.kStructHeaderSize + 16;

  Device_Start_Params.decode = function(decoder) {
    var packed;
    var val = new Device_Start_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.requested_settings = decoder.decodeStructPointer(capture_settings$.CaptureSettings);
    val.receiver = decoder.decodeStruct(new codec.Interface(receiver$.ReceiverPtr));
    return val;
  };

  Device_Start_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_Start_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(capture_settings$.CaptureSettings, val.requested_settings);
    encoder.encodeStruct(new codec.Interface(receiver$.ReceiverPtr), val.receiver);
  };
  var kDevice_Start_Name = 0;

  function DevicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Device,
                                                   handleOrPtrInfo);
  }

  function DeviceProxy(receiver) {
    this.receiver_ = receiver;
  }
  DevicePtr.prototype.start = function() {
    return DeviceProxy.prototype.start
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.start = function(requested_settings, receiver) {
    var params = new Device_Start_Params();
    params.requested_settings = requested_settings;
    params.receiver = receiver;
    var builder = new codec.MessageBuilder(
        kDevice_Start_Name,
        codec.align(Device_Start_Params.encodedSize));
    builder.encodeStruct(Device_Start_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DeviceStub(delegate) {
    this.delegate_ = delegate;
  }
  DeviceStub.prototype.start = function(requested_settings, receiver) {
    return this.delegate_ && this.delegate_.start && this.delegate_.start(requested_settings, receiver);
  }

  DeviceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDevice_Start_Name:
      var params = reader.decodeStruct(Device_Start_Params);
      this.start(params.requested_settings, params.receiver);
      return true;
    default:
      return false;
    }
  };

  DeviceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDeviceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDevice_Start_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Device_Start_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDeviceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var Device = {
    name: 'video_capture::mojom::Device',
    ptrClass: DevicePtr,
    proxyClass: DeviceProxy,
    stubClass: DeviceStub,
    validateRequest: validateDeviceRequest,
    validateResponse: null,
  };
  DeviceStub.prototype.validator = validateDeviceRequest;
  DeviceProxy.prototype.validator = null;

  var exports = {};
  exports.Device = Device;
  exports.DevicePtr = DevicePtr;

  return exports;
});
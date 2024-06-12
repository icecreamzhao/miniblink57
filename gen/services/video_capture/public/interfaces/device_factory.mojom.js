// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/video_capture/public/interfaces/device_factory.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/capture/mojo/video_capture_types.mojom",
    "services/video_capture/public/interfaces/device_descriptor.mojom",
    "services/video_capture/public/interfaces/device.mojom",
    "services/video_capture/public/interfaces/capture_settings.mojom",
], function(bindings, codec, core, validator, video_capture_types$, device_descriptor$, device$, capture_settings$) {
  var DeviceAccessResultCode = {};
  DeviceAccessResultCode.NOT_INITIALIZED = 0;
  DeviceAccessResultCode.SUCCESS = DeviceAccessResultCode.NOT_INITIALIZED + 1;
  DeviceAccessResultCode.ERROR_DEVICE_NOT_FOUND = DeviceAccessResultCode.SUCCESS + 1;

  DeviceAccessResultCode.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  DeviceAccessResultCode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function DeviceFactory_EnumerateDeviceDescriptors_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceFactory_EnumerateDeviceDescriptors_Params.prototype.initDefaults_ = function() {
  };
  DeviceFactory_EnumerateDeviceDescriptors_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceFactory_EnumerateDeviceDescriptors_Params.validate = function(messageValidator, offset) {
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

  DeviceFactory_EnumerateDeviceDescriptors_Params.encodedSize = codec.kStructHeaderSize + 0;

  DeviceFactory_EnumerateDeviceDescriptors_Params.decode = function(decoder) {
    var packed;
    var val = new DeviceFactory_EnumerateDeviceDescriptors_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DeviceFactory_EnumerateDeviceDescriptors_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceFactory_EnumerateDeviceDescriptors_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DeviceFactory_EnumerateDeviceDescriptors_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.prototype.initDefaults_ = function() {
    this.descriptors = null;
  };
  DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.descriptors
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(device_descriptor$.DeviceDescriptor), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new DeviceFactory_EnumerateDeviceDescriptors_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.descriptors = decoder.decodeArrayPointer(new codec.PointerTo(device_descriptor$.DeviceDescriptor));
    return val;
  };

  DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(device_descriptor$.DeviceDescriptor), val.descriptors);
  };
  function DeviceFactory_GetSupportedFormats_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceFactory_GetSupportedFormats_Params.prototype.initDefaults_ = function() {
    this.device_id = null;
  };
  DeviceFactory_GetSupportedFormats_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceFactory_GetSupportedFormats_Params.validate = function(messageValidator, offset) {
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


    
    // validate DeviceFactory_GetSupportedFormats_Params.device_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DeviceFactory_GetSupportedFormats_Params.encodedSize = codec.kStructHeaderSize + 8;

  DeviceFactory_GetSupportedFormats_Params.decode = function(decoder) {
    var packed;
    var val = new DeviceFactory_GetSupportedFormats_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.device_id = decoder.decodeStruct(codec.String);
    return val;
  };

  DeviceFactory_GetSupportedFormats_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceFactory_GetSupportedFormats_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.device_id);
  };
  function DeviceFactory_GetSupportedFormats_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceFactory_GetSupportedFormats_ResponseParams.prototype.initDefaults_ = function() {
    this.supported_formats = null;
  };
  DeviceFactory_GetSupportedFormats_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceFactory_GetSupportedFormats_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate DeviceFactory_GetSupportedFormats_ResponseParams.supported_formats
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(capture_settings$.I420CaptureFormat), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DeviceFactory_GetSupportedFormats_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  DeviceFactory_GetSupportedFormats_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new DeviceFactory_GetSupportedFormats_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.supported_formats = decoder.decodeArrayPointer(new codec.PointerTo(capture_settings$.I420CaptureFormat));
    return val;
  };

  DeviceFactory_GetSupportedFormats_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceFactory_GetSupportedFormats_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(capture_settings$.I420CaptureFormat), val.supported_formats);
  };
  function DeviceFactory_CreateDevice_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceFactory_CreateDevice_Params.prototype.initDefaults_ = function() {
    this.device_id = null;
    this.device_request = new bindings.InterfaceRequest();
  };
  DeviceFactory_CreateDevice_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceFactory_CreateDevice_Params.validate = function(messageValidator, offset) {
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


    
    // validate DeviceFactory_CreateDevice_Params.device_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceFactory_CreateDevice_Params.device_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DeviceFactory_CreateDevice_Params.encodedSize = codec.kStructHeaderSize + 16;

  DeviceFactory_CreateDevice_Params.decode = function(decoder) {
    var packed;
    var val = new DeviceFactory_CreateDevice_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.device_id = decoder.decodeStruct(codec.String);
    val.device_request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  DeviceFactory_CreateDevice_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceFactory_CreateDevice_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.device_id);
    encoder.encodeStruct(codec.InterfaceRequest, val.device_request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function DeviceFactory_CreateDevice_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceFactory_CreateDevice_ResponseParams.prototype.initDefaults_ = function() {
    this.result_code = 0;
  };
  DeviceFactory_CreateDevice_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceFactory_CreateDevice_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate DeviceFactory_CreateDevice_ResponseParams.result_code
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DeviceAccessResultCode);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DeviceFactory_CreateDevice_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  DeviceFactory_CreateDevice_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new DeviceFactory_CreateDevice_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result_code = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  DeviceFactory_CreateDevice_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceFactory_CreateDevice_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.result_code);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kDeviceFactory_EnumerateDeviceDescriptors_Name = 0;
  var kDeviceFactory_GetSupportedFormats_Name = 1;
  var kDeviceFactory_CreateDevice_Name = 2;

  function DeviceFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DeviceFactory,
                                                   handleOrPtrInfo);
  }

  function DeviceFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  DeviceFactoryPtr.prototype.enumerateDeviceDescriptors = function() {
    return DeviceFactoryProxy.prototype.enumerateDeviceDescriptors
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceFactoryProxy.prototype.enumerateDeviceDescriptors = function() {
    var params = new DeviceFactory_EnumerateDeviceDescriptors_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDeviceFactory_EnumerateDeviceDescriptors_Name,
          codec.align(DeviceFactory_EnumerateDeviceDescriptors_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(DeviceFactory_EnumerateDeviceDescriptors_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(DeviceFactory_EnumerateDeviceDescriptors_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DeviceFactoryPtr.prototype.getSupportedFormats = function() {
    return DeviceFactoryProxy.prototype.getSupportedFormats
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceFactoryProxy.prototype.getSupportedFormats = function(device_id) {
    var params = new DeviceFactory_GetSupportedFormats_Params();
    params.device_id = device_id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDeviceFactory_GetSupportedFormats_Name,
          codec.align(DeviceFactory_GetSupportedFormats_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(DeviceFactory_GetSupportedFormats_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(DeviceFactory_GetSupportedFormats_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DeviceFactoryPtr.prototype.createDevice = function() {
    return DeviceFactoryProxy.prototype.createDevice
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceFactoryProxy.prototype.createDevice = function(device_id, device_request) {
    var params = new DeviceFactory_CreateDevice_Params();
    params.device_id = device_id;
    params.device_request = device_request;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDeviceFactory_CreateDevice_Name,
          codec.align(DeviceFactory_CreateDevice_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(DeviceFactory_CreateDevice_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(DeviceFactory_CreateDevice_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function DeviceFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  DeviceFactoryStub.prototype.enumerateDeviceDescriptors = function() {
    return this.delegate_ && this.delegate_.enumerateDeviceDescriptors && this.delegate_.enumerateDeviceDescriptors();
  }
  DeviceFactoryStub.prototype.getSupportedFormats = function(device_id) {
    return this.delegate_ && this.delegate_.getSupportedFormats && this.delegate_.getSupportedFormats(device_id);
  }
  DeviceFactoryStub.prototype.createDevice = function(device_id, device_request) {
    return this.delegate_ && this.delegate_.createDevice && this.delegate_.createDevice(device_id, device_request);
  }

  DeviceFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  DeviceFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDeviceFactory_EnumerateDeviceDescriptors_Name:
      var params = reader.decodeStruct(DeviceFactory_EnumerateDeviceDescriptors_Params);
      return this.enumerateDeviceDescriptors().then(function(response) {
        var responseParams =
            new DeviceFactory_EnumerateDeviceDescriptors_ResponseParams();
        responseParams.descriptors = response.descriptors;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDeviceFactory_EnumerateDeviceDescriptors_Name,
            codec.align(DeviceFactory_EnumerateDeviceDescriptors_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(DeviceFactory_EnumerateDeviceDescriptors_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDeviceFactory_GetSupportedFormats_Name:
      var params = reader.decodeStruct(DeviceFactory_GetSupportedFormats_Params);
      return this.getSupportedFormats(params.device_id).then(function(response) {
        var responseParams =
            new DeviceFactory_GetSupportedFormats_ResponseParams();
        responseParams.supported_formats = response.supported_formats;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDeviceFactory_GetSupportedFormats_Name,
            codec.align(DeviceFactory_GetSupportedFormats_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(DeviceFactory_GetSupportedFormats_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDeviceFactory_CreateDevice_Name:
      var params = reader.decodeStruct(DeviceFactory_CreateDevice_Params);
      return this.createDevice(params.device_id, params.device_request).then(function(response) {
        var responseParams =
            new DeviceFactory_CreateDevice_ResponseParams();
        responseParams.result_code = response.result_code;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDeviceFactory_CreateDevice_Name,
            codec.align(DeviceFactory_CreateDevice_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(DeviceFactory_CreateDevice_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDeviceFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDeviceFactory_EnumerateDeviceDescriptors_Name:
        if (message.expectsResponse())
          paramsClass = DeviceFactory_EnumerateDeviceDescriptors_Params;
      break;
      case kDeviceFactory_GetSupportedFormats_Name:
        if (message.expectsResponse())
          paramsClass = DeviceFactory_GetSupportedFormats_Params;
      break;
      case kDeviceFactory_CreateDevice_Name:
        if (message.expectsResponse())
          paramsClass = DeviceFactory_CreateDevice_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDeviceFactoryResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kDeviceFactory_EnumerateDeviceDescriptors_Name:
        if (message.isResponse())
          paramsClass = DeviceFactory_EnumerateDeviceDescriptors_ResponseParams;
        break;
      case kDeviceFactory_GetSupportedFormats_Name:
        if (message.isResponse())
          paramsClass = DeviceFactory_GetSupportedFormats_ResponseParams;
        break;
      case kDeviceFactory_CreateDevice_Name:
        if (message.isResponse())
          paramsClass = DeviceFactory_CreateDevice_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var DeviceFactory = {
    name: 'video_capture::mojom::DeviceFactory',
    ptrClass: DeviceFactoryPtr,
    proxyClass: DeviceFactoryProxy,
    stubClass: DeviceFactoryStub,
    validateRequest: validateDeviceFactoryRequest,
    validateResponse: validateDeviceFactoryResponse,
  };
  DeviceFactoryStub.prototype.validator = validateDeviceFactoryRequest;
  DeviceFactoryProxy.prototype.validator = validateDeviceFactoryResponse;

  var exports = {};
  exports.DeviceAccessResultCode = DeviceAccessResultCode;
  exports.DeviceFactory = DeviceFactory;
  exports.DeviceFactoryPtr = DeviceFactoryPtr;

  return exports;
});
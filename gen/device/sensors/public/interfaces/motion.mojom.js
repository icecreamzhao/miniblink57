// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/sensors/public/interfaces/motion.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function MotionSensor_StartPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MotionSensor_StartPolling_Params.prototype.initDefaults_ = function() {
  };
  MotionSensor_StartPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MotionSensor_StartPolling_Params.validate = function(messageValidator, offset) {
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

  MotionSensor_StartPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  MotionSensor_StartPolling_Params.decode = function(decoder) {
    var packed;
    var val = new MotionSensor_StartPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  MotionSensor_StartPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MotionSensor_StartPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function MotionSensor_StartPolling_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MotionSensor_StartPolling_ResponseParams.prototype.initDefaults_ = function() {
    this.memory_handle = null;
  };
  MotionSensor_StartPolling_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MotionSensor_StartPolling_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate MotionSensor_StartPolling_ResponseParams.memory_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MotionSensor_StartPolling_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  MotionSensor_StartPolling_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new MotionSensor_StartPolling_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.memory_handle = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  MotionSensor_StartPolling_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MotionSensor_StartPolling_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.memory_handle);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function MotionSensor_StopPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MotionSensor_StopPolling_Params.prototype.initDefaults_ = function() {
  };
  MotionSensor_StopPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MotionSensor_StopPolling_Params.validate = function(messageValidator, offset) {
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

  MotionSensor_StopPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  MotionSensor_StopPolling_Params.decode = function(decoder) {
    var packed;
    var val = new MotionSensor_StopPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  MotionSensor_StopPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MotionSensor_StopPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kMotionSensor_StartPolling_Name = 0;
  var kMotionSensor_StopPolling_Name = 1;

  function MotionSensorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(MotionSensor,
                                                   handleOrPtrInfo);
  }

  function MotionSensorProxy(receiver) {
    this.receiver_ = receiver;
  }
  MotionSensorPtr.prototype.startPolling = function() {
    return MotionSensorProxy.prototype.startPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  MotionSensorProxy.prototype.startPolling = function() {
    var params = new MotionSensor_StartPolling_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kMotionSensor_StartPolling_Name,
          codec.align(MotionSensor_StartPolling_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(MotionSensor_StartPolling_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(MotionSensor_StartPolling_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  MotionSensorPtr.prototype.stopPolling = function() {
    return MotionSensorProxy.prototype.stopPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  MotionSensorProxy.prototype.stopPolling = function() {
    var params = new MotionSensor_StopPolling_Params();
    var builder = new codec.MessageBuilder(
        kMotionSensor_StopPolling_Name,
        codec.align(MotionSensor_StopPolling_Params.encodedSize));
    builder.encodeStruct(MotionSensor_StopPolling_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function MotionSensorStub(delegate) {
    this.delegate_ = delegate;
  }
  MotionSensorStub.prototype.startPolling = function() {
    return this.delegate_ && this.delegate_.startPolling && this.delegate_.startPolling();
  }
  MotionSensorStub.prototype.stopPolling = function() {
    return this.delegate_ && this.delegate_.stopPolling && this.delegate_.stopPolling();
  }

  MotionSensorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kMotionSensor_StopPolling_Name:
      var params = reader.decodeStruct(MotionSensor_StopPolling_Params);
      this.stopPolling();
      return true;
    default:
      return false;
    }
  };

  MotionSensorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kMotionSensor_StartPolling_Name:
      var params = reader.decodeStruct(MotionSensor_StartPolling_Params);
      return this.startPolling().then(function(response) {
        var responseParams =
            new MotionSensor_StartPolling_ResponseParams();
        responseParams.memory_handle = response.memory_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kMotionSensor_StartPolling_Name,
            codec.align(MotionSensor_StartPolling_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(MotionSensor_StartPolling_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateMotionSensorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kMotionSensor_StartPolling_Name:
        if (message.expectsResponse())
          paramsClass = MotionSensor_StartPolling_Params;
      break;
      case kMotionSensor_StopPolling_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MotionSensor_StopPolling_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateMotionSensorResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kMotionSensor_StartPolling_Name:
        if (message.isResponse())
          paramsClass = MotionSensor_StartPolling_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var MotionSensor = {
    name: 'device::mojom::MotionSensor',
    ptrClass: MotionSensorPtr,
    proxyClass: MotionSensorProxy,
    stubClass: MotionSensorStub,
    validateRequest: validateMotionSensorRequest,
    validateResponse: validateMotionSensorResponse,
  };
  MotionSensorStub.prototype.validator = validateMotionSensorRequest;
  MotionSensorProxy.prototype.validator = validateMotionSensorResponse;

  var exports = {};
  exports.MotionSensor = MotionSensor;
  exports.MotionSensorPtr = MotionSensorPtr;

  return exports;
});
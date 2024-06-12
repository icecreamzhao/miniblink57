// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/sensors/public/interfaces/orientation.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function OrientationAbsoluteSensor_StartPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OrientationAbsoluteSensor_StartPolling_Params.prototype.initDefaults_ = function() {
  };
  OrientationAbsoluteSensor_StartPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OrientationAbsoluteSensor_StartPolling_Params.validate = function(messageValidator, offset) {
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

  OrientationAbsoluteSensor_StartPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  OrientationAbsoluteSensor_StartPolling_Params.decode = function(decoder) {
    var packed;
    var val = new OrientationAbsoluteSensor_StartPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  OrientationAbsoluteSensor_StartPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OrientationAbsoluteSensor_StartPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function OrientationAbsoluteSensor_StartPolling_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OrientationAbsoluteSensor_StartPolling_ResponseParams.prototype.initDefaults_ = function() {
    this.memory_handle = null;
  };
  OrientationAbsoluteSensor_StartPolling_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OrientationAbsoluteSensor_StartPolling_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate OrientationAbsoluteSensor_StartPolling_ResponseParams.memory_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  OrientationAbsoluteSensor_StartPolling_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  OrientationAbsoluteSensor_StartPolling_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new OrientationAbsoluteSensor_StartPolling_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.memory_handle = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  OrientationAbsoluteSensor_StartPolling_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OrientationAbsoluteSensor_StartPolling_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.memory_handle);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function OrientationAbsoluteSensor_StopPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OrientationAbsoluteSensor_StopPolling_Params.prototype.initDefaults_ = function() {
  };
  OrientationAbsoluteSensor_StopPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OrientationAbsoluteSensor_StopPolling_Params.validate = function(messageValidator, offset) {
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

  OrientationAbsoluteSensor_StopPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  OrientationAbsoluteSensor_StopPolling_Params.decode = function(decoder) {
    var packed;
    var val = new OrientationAbsoluteSensor_StopPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  OrientationAbsoluteSensor_StopPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OrientationAbsoluteSensor_StopPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function OrientationSensor_StartPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OrientationSensor_StartPolling_Params.prototype.initDefaults_ = function() {
  };
  OrientationSensor_StartPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OrientationSensor_StartPolling_Params.validate = function(messageValidator, offset) {
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

  OrientationSensor_StartPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  OrientationSensor_StartPolling_Params.decode = function(decoder) {
    var packed;
    var val = new OrientationSensor_StartPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  OrientationSensor_StartPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OrientationSensor_StartPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function OrientationSensor_StartPolling_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OrientationSensor_StartPolling_ResponseParams.prototype.initDefaults_ = function() {
    this.memory_handle = null;
  };
  OrientationSensor_StartPolling_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OrientationSensor_StartPolling_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate OrientationSensor_StartPolling_ResponseParams.memory_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  OrientationSensor_StartPolling_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  OrientationSensor_StartPolling_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new OrientationSensor_StartPolling_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.memory_handle = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  OrientationSensor_StartPolling_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OrientationSensor_StartPolling_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.memory_handle);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function OrientationSensor_StopPolling_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OrientationSensor_StopPolling_Params.prototype.initDefaults_ = function() {
  };
  OrientationSensor_StopPolling_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OrientationSensor_StopPolling_Params.validate = function(messageValidator, offset) {
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

  OrientationSensor_StopPolling_Params.encodedSize = codec.kStructHeaderSize + 0;

  OrientationSensor_StopPolling_Params.decode = function(decoder) {
    var packed;
    var val = new OrientationSensor_StopPolling_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  OrientationSensor_StopPolling_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OrientationSensor_StopPolling_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kOrientationAbsoluteSensor_StartPolling_Name = 0;
  var kOrientationAbsoluteSensor_StopPolling_Name = 1;

  function OrientationAbsoluteSensorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(OrientationAbsoluteSensor,
                                                   handleOrPtrInfo);
  }

  function OrientationAbsoluteSensorProxy(receiver) {
    this.receiver_ = receiver;
  }
  OrientationAbsoluteSensorPtr.prototype.startPolling = function() {
    return OrientationAbsoluteSensorProxy.prototype.startPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  OrientationAbsoluteSensorProxy.prototype.startPolling = function() {
    var params = new OrientationAbsoluteSensor_StartPolling_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kOrientationAbsoluteSensor_StartPolling_Name,
          codec.align(OrientationAbsoluteSensor_StartPolling_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(OrientationAbsoluteSensor_StartPolling_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(OrientationAbsoluteSensor_StartPolling_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  OrientationAbsoluteSensorPtr.prototype.stopPolling = function() {
    return OrientationAbsoluteSensorProxy.prototype.stopPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  OrientationAbsoluteSensorProxy.prototype.stopPolling = function() {
    var params = new OrientationAbsoluteSensor_StopPolling_Params();
    var builder = new codec.MessageBuilder(
        kOrientationAbsoluteSensor_StopPolling_Name,
        codec.align(OrientationAbsoluteSensor_StopPolling_Params.encodedSize));
    builder.encodeStruct(OrientationAbsoluteSensor_StopPolling_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function OrientationAbsoluteSensorStub(delegate) {
    this.delegate_ = delegate;
  }
  OrientationAbsoluteSensorStub.prototype.startPolling = function() {
    return this.delegate_ && this.delegate_.startPolling && this.delegate_.startPolling();
  }
  OrientationAbsoluteSensorStub.prototype.stopPolling = function() {
    return this.delegate_ && this.delegate_.stopPolling && this.delegate_.stopPolling();
  }

  OrientationAbsoluteSensorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOrientationAbsoluteSensor_StopPolling_Name:
      var params = reader.decodeStruct(OrientationAbsoluteSensor_StopPolling_Params);
      this.stopPolling();
      return true;
    default:
      return false;
    }
  };

  OrientationAbsoluteSensorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOrientationAbsoluteSensor_StartPolling_Name:
      var params = reader.decodeStruct(OrientationAbsoluteSensor_StartPolling_Params);
      return this.startPolling().then(function(response) {
        var responseParams =
            new OrientationAbsoluteSensor_StartPolling_ResponseParams();
        responseParams.memory_handle = response.memory_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kOrientationAbsoluteSensor_StartPolling_Name,
            codec.align(OrientationAbsoluteSensor_StartPolling_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(OrientationAbsoluteSensor_StartPolling_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateOrientationAbsoluteSensorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kOrientationAbsoluteSensor_StartPolling_Name:
        if (message.expectsResponse())
          paramsClass = OrientationAbsoluteSensor_StartPolling_Params;
      break;
      case kOrientationAbsoluteSensor_StopPolling_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = OrientationAbsoluteSensor_StopPolling_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateOrientationAbsoluteSensorResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kOrientationAbsoluteSensor_StartPolling_Name:
        if (message.isResponse())
          paramsClass = OrientationAbsoluteSensor_StartPolling_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var OrientationAbsoluteSensor = {
    name: 'device::mojom::OrientationAbsoluteSensor',
    ptrClass: OrientationAbsoluteSensorPtr,
    proxyClass: OrientationAbsoluteSensorProxy,
    stubClass: OrientationAbsoluteSensorStub,
    validateRequest: validateOrientationAbsoluteSensorRequest,
    validateResponse: validateOrientationAbsoluteSensorResponse,
  };
  OrientationAbsoluteSensorStub.prototype.validator = validateOrientationAbsoluteSensorRequest;
  OrientationAbsoluteSensorProxy.prototype.validator = validateOrientationAbsoluteSensorResponse;
  var kOrientationSensor_StartPolling_Name = 0;
  var kOrientationSensor_StopPolling_Name = 1;

  function OrientationSensorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(OrientationSensor,
                                                   handleOrPtrInfo);
  }

  function OrientationSensorProxy(receiver) {
    this.receiver_ = receiver;
  }
  OrientationSensorPtr.prototype.startPolling = function() {
    return OrientationSensorProxy.prototype.startPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  OrientationSensorProxy.prototype.startPolling = function() {
    var params = new OrientationSensor_StartPolling_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kOrientationSensor_StartPolling_Name,
          codec.align(OrientationSensor_StartPolling_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(OrientationSensor_StartPolling_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(OrientationSensor_StartPolling_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  OrientationSensorPtr.prototype.stopPolling = function() {
    return OrientationSensorProxy.prototype.stopPolling
        .apply(this.ptr.getProxy(), arguments);
  };

  OrientationSensorProxy.prototype.stopPolling = function() {
    var params = new OrientationSensor_StopPolling_Params();
    var builder = new codec.MessageBuilder(
        kOrientationSensor_StopPolling_Name,
        codec.align(OrientationSensor_StopPolling_Params.encodedSize));
    builder.encodeStruct(OrientationSensor_StopPolling_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function OrientationSensorStub(delegate) {
    this.delegate_ = delegate;
  }
  OrientationSensorStub.prototype.startPolling = function() {
    return this.delegate_ && this.delegate_.startPolling && this.delegate_.startPolling();
  }
  OrientationSensorStub.prototype.stopPolling = function() {
    return this.delegate_ && this.delegate_.stopPolling && this.delegate_.stopPolling();
  }

  OrientationSensorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOrientationSensor_StopPolling_Name:
      var params = reader.decodeStruct(OrientationSensor_StopPolling_Params);
      this.stopPolling();
      return true;
    default:
      return false;
    }
  };

  OrientationSensorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOrientationSensor_StartPolling_Name:
      var params = reader.decodeStruct(OrientationSensor_StartPolling_Params);
      return this.startPolling().then(function(response) {
        var responseParams =
            new OrientationSensor_StartPolling_ResponseParams();
        responseParams.memory_handle = response.memory_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kOrientationSensor_StartPolling_Name,
            codec.align(OrientationSensor_StartPolling_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(OrientationSensor_StartPolling_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateOrientationSensorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kOrientationSensor_StartPolling_Name:
        if (message.expectsResponse())
          paramsClass = OrientationSensor_StartPolling_Params;
      break;
      case kOrientationSensor_StopPolling_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = OrientationSensor_StopPolling_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateOrientationSensorResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kOrientationSensor_StartPolling_Name:
        if (message.isResponse())
          paramsClass = OrientationSensor_StartPolling_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var OrientationSensor = {
    name: 'device::mojom::OrientationSensor',
    ptrClass: OrientationSensorPtr,
    proxyClass: OrientationSensorProxy,
    stubClass: OrientationSensorStub,
    validateRequest: validateOrientationSensorRequest,
    validateResponse: validateOrientationSensorResponse,
  };
  OrientationSensorStub.prototype.validator = validateOrientationSensorRequest;
  OrientationSensorProxy.prototype.validator = validateOrientationSensorResponse;

  var exports = {};
  exports.OrientationAbsoluteSensor = OrientationAbsoluteSensor;
  exports.OrientationAbsoluteSensorPtr = OrientationAbsoluteSensorPtr;
  exports.OrientationSensor = OrientationSensor;
  exports.OrientationSensorPtr = OrientationSensorPtr;

  return exports;
});
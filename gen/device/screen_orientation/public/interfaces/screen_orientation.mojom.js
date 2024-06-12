// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/screen_orientation/public/interfaces/screen_orientation.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "device/screen_orientation/public/interfaces/screen_orientation_lock_types.mojom",
], function(bindings, codec, core, validator, screen_orientation_lock_types$) {

  function ScreenOrientation_LockOrientation_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ScreenOrientation_LockOrientation_Params.prototype.initDefaults_ = function() {
    this.orientation = 0;
  };
  ScreenOrientation_LockOrientation_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ScreenOrientation_LockOrientation_Params.validate = function(messageValidator, offset) {
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


    
    // validate ScreenOrientation_LockOrientation_Params.orientation
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, screen_orientation_lock_types$.ScreenOrientationLockType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ScreenOrientation_LockOrientation_Params.encodedSize = codec.kStructHeaderSize + 8;

  ScreenOrientation_LockOrientation_Params.decode = function(decoder) {
    var packed;
    var val = new ScreenOrientation_LockOrientation_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.orientation = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  ScreenOrientation_LockOrientation_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ScreenOrientation_LockOrientation_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.orientation);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function ScreenOrientation_LockOrientation_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ScreenOrientation_LockOrientation_ResponseParams.prototype.initDefaults_ = function() {
    this.result = 0;
  };
  ScreenOrientation_LockOrientation_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ScreenOrientation_LockOrientation_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate ScreenOrientation_LockOrientation_ResponseParams.result
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, screen_orientation_lock_types$.ScreenOrientationLockResult);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ScreenOrientation_LockOrientation_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  ScreenOrientation_LockOrientation_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new ScreenOrientation_LockOrientation_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  ScreenOrientation_LockOrientation_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ScreenOrientation_LockOrientation_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.result);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function ScreenOrientation_UnlockOrientation_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ScreenOrientation_UnlockOrientation_Params.prototype.initDefaults_ = function() {
  };
  ScreenOrientation_UnlockOrientation_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ScreenOrientation_UnlockOrientation_Params.validate = function(messageValidator, offset) {
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

  ScreenOrientation_UnlockOrientation_Params.encodedSize = codec.kStructHeaderSize + 0;

  ScreenOrientation_UnlockOrientation_Params.decode = function(decoder) {
    var packed;
    var val = new ScreenOrientation_UnlockOrientation_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  ScreenOrientation_UnlockOrientation_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ScreenOrientation_UnlockOrientation_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function ScreenOrientationListener_Start_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ScreenOrientationListener_Start_Params.prototype.initDefaults_ = function() {
  };
  ScreenOrientationListener_Start_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ScreenOrientationListener_Start_Params.validate = function(messageValidator, offset) {
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

  ScreenOrientationListener_Start_Params.encodedSize = codec.kStructHeaderSize + 0;

  ScreenOrientationListener_Start_Params.decode = function(decoder) {
    var packed;
    var val = new ScreenOrientationListener_Start_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  ScreenOrientationListener_Start_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ScreenOrientationListener_Start_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function ScreenOrientationListener_Stop_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ScreenOrientationListener_Stop_Params.prototype.initDefaults_ = function() {
  };
  ScreenOrientationListener_Stop_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ScreenOrientationListener_Stop_Params.validate = function(messageValidator, offset) {
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

  ScreenOrientationListener_Stop_Params.encodedSize = codec.kStructHeaderSize + 0;

  ScreenOrientationListener_Stop_Params.decode = function(decoder) {
    var packed;
    var val = new ScreenOrientationListener_Stop_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  ScreenOrientationListener_Stop_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ScreenOrientationListener_Stop_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kScreenOrientation_LockOrientation_Name = 0;
  var kScreenOrientation_UnlockOrientation_Name = 1;

  function ScreenOrientationPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ScreenOrientation,
                                                   handleOrPtrInfo);
  }

  function ScreenOrientationProxy(receiver) {
    this.receiver_ = receiver;
  }
  ScreenOrientationPtr.prototype.lockOrientation = function() {
    return ScreenOrientationProxy.prototype.lockOrientation
        .apply(this.ptr.getProxy(), arguments);
  };

  ScreenOrientationProxy.prototype.lockOrientation = function(orientation) {
    var params = new ScreenOrientation_LockOrientation_Params();
    params.orientation = orientation;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kScreenOrientation_LockOrientation_Name,
          codec.align(ScreenOrientation_LockOrientation_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(ScreenOrientation_LockOrientation_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(ScreenOrientation_LockOrientation_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ScreenOrientationPtr.prototype.unlockOrientation = function() {
    return ScreenOrientationProxy.prototype.unlockOrientation
        .apply(this.ptr.getProxy(), arguments);
  };

  ScreenOrientationProxy.prototype.unlockOrientation = function() {
    var params = new ScreenOrientation_UnlockOrientation_Params();
    var builder = new codec.MessageBuilder(
        kScreenOrientation_UnlockOrientation_Name,
        codec.align(ScreenOrientation_UnlockOrientation_Params.encodedSize));
    builder.encodeStruct(ScreenOrientation_UnlockOrientation_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ScreenOrientationStub(delegate) {
    this.delegate_ = delegate;
  }
  ScreenOrientationStub.prototype.lockOrientation = function(orientation) {
    return this.delegate_ && this.delegate_.lockOrientation && this.delegate_.lockOrientation(orientation);
  }
  ScreenOrientationStub.prototype.unlockOrientation = function() {
    return this.delegate_ && this.delegate_.unlockOrientation && this.delegate_.unlockOrientation();
  }

  ScreenOrientationStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kScreenOrientation_UnlockOrientation_Name:
      var params = reader.decodeStruct(ScreenOrientation_UnlockOrientation_Params);
      this.unlockOrientation();
      return true;
    default:
      return false;
    }
  };

  ScreenOrientationStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kScreenOrientation_LockOrientation_Name:
      var params = reader.decodeStruct(ScreenOrientation_LockOrientation_Params);
      return this.lockOrientation(params.orientation).then(function(response) {
        var responseParams =
            new ScreenOrientation_LockOrientation_ResponseParams();
        responseParams.result = response.result;
        var builder = new codec.MessageWithRequestIDBuilder(
            kScreenOrientation_LockOrientation_Name,
            codec.align(ScreenOrientation_LockOrientation_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(ScreenOrientation_LockOrientation_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateScreenOrientationRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kScreenOrientation_LockOrientation_Name:
        if (message.expectsResponse())
          paramsClass = ScreenOrientation_LockOrientation_Params;
      break;
      case kScreenOrientation_UnlockOrientation_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ScreenOrientation_UnlockOrientation_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateScreenOrientationResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kScreenOrientation_LockOrientation_Name:
        if (message.isResponse())
          paramsClass = ScreenOrientation_LockOrientation_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var ScreenOrientation = {
    name: 'device::mojom::ScreenOrientation',
    ptrClass: ScreenOrientationPtr,
    proxyClass: ScreenOrientationProxy,
    stubClass: ScreenOrientationStub,
    validateRequest: validateScreenOrientationRequest,
    validateResponse: validateScreenOrientationResponse,
  };
  ScreenOrientationStub.prototype.validator = validateScreenOrientationRequest;
  ScreenOrientationProxy.prototype.validator = validateScreenOrientationResponse;
  var kScreenOrientationListener_Start_Name = 0;
  var kScreenOrientationListener_Stop_Name = 1;

  function ScreenOrientationListenerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ScreenOrientationListener,
                                                   handleOrPtrInfo);
  }

  function ScreenOrientationListenerProxy(receiver) {
    this.receiver_ = receiver;
  }
  ScreenOrientationListenerPtr.prototype.start = function() {
    return ScreenOrientationListenerProxy.prototype.start
        .apply(this.ptr.getProxy(), arguments);
  };

  ScreenOrientationListenerProxy.prototype.start = function() {
    var params = new ScreenOrientationListener_Start_Params();
    var builder = new codec.MessageBuilder(
        kScreenOrientationListener_Start_Name,
        codec.align(ScreenOrientationListener_Start_Params.encodedSize));
    builder.encodeStruct(ScreenOrientationListener_Start_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ScreenOrientationListenerPtr.prototype.stop = function() {
    return ScreenOrientationListenerProxy.prototype.stop
        .apply(this.ptr.getProxy(), arguments);
  };

  ScreenOrientationListenerProxy.prototype.stop = function() {
    var params = new ScreenOrientationListener_Stop_Params();
    var builder = new codec.MessageBuilder(
        kScreenOrientationListener_Stop_Name,
        codec.align(ScreenOrientationListener_Stop_Params.encodedSize));
    builder.encodeStruct(ScreenOrientationListener_Stop_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ScreenOrientationListenerStub(delegate) {
    this.delegate_ = delegate;
  }
  ScreenOrientationListenerStub.prototype.start = function() {
    return this.delegate_ && this.delegate_.start && this.delegate_.start();
  }
  ScreenOrientationListenerStub.prototype.stop = function() {
    return this.delegate_ && this.delegate_.stop && this.delegate_.stop();
  }

  ScreenOrientationListenerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kScreenOrientationListener_Start_Name:
      var params = reader.decodeStruct(ScreenOrientationListener_Start_Params);
      this.start();
      return true;
    case kScreenOrientationListener_Stop_Name:
      var params = reader.decodeStruct(ScreenOrientationListener_Stop_Params);
      this.stop();
      return true;
    default:
      return false;
    }
  };

  ScreenOrientationListenerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateScreenOrientationListenerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kScreenOrientationListener_Start_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ScreenOrientationListener_Start_Params;
      break;
      case kScreenOrientationListener_Stop_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ScreenOrientationListener_Stop_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateScreenOrientationListenerResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var ScreenOrientationListener = {
    name: 'device::mojom::ScreenOrientationListener',
    ptrClass: ScreenOrientationListenerPtr,
    proxyClass: ScreenOrientationListenerProxy,
    stubClass: ScreenOrientationListenerStub,
    validateRequest: validateScreenOrientationListenerRequest,
    validateResponse: null,
  };
  ScreenOrientationListenerStub.prototype.validator = validateScreenOrientationListenerRequest;
  ScreenOrientationListenerProxy.prototype.validator = null;

  var exports = {};
  exports.ScreenOrientation = ScreenOrientation;
  exports.ScreenOrientationPtr = ScreenOrientationPtr;
  exports.ScreenOrientationListener = ScreenOrientationListener;
  exports.ScreenOrientationListenerPtr = ScreenOrientationListenerPtr;

  return exports;
});
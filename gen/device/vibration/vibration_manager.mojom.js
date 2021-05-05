// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/vibration/vibration_manager.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function VibrationManager_Vibrate_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VibrationManager_Vibrate_Params.prototype.initDefaults_ = function() {
    this.milliseconds = 0;
  };
  VibrationManager_Vibrate_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VibrationManager_Vibrate_Params.validate = function(messageValidator, offset) {
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


    return validator.validationError.NONE;
  };

  VibrationManager_Vibrate_Params.encodedSize = codec.kStructHeaderSize + 8;

  VibrationManager_Vibrate_Params.decode = function(decoder) {
    var packed;
    var val = new VibrationManager_Vibrate_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.milliseconds = decoder.decodeStruct(codec.Int64);
    return val;
  };

  VibrationManager_Vibrate_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VibrationManager_Vibrate_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.milliseconds);
  };
  function VibrationManager_Vibrate_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VibrationManager_Vibrate_ResponseParams.prototype.initDefaults_ = function() {
  };
  VibrationManager_Vibrate_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VibrationManager_Vibrate_ResponseParams.validate = function(messageValidator, offset) {
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

  VibrationManager_Vibrate_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  VibrationManager_Vibrate_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VibrationManager_Vibrate_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VibrationManager_Vibrate_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VibrationManager_Vibrate_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  function VibrationManager_Cancel_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VibrationManager_Cancel_Params.prototype.initDefaults_ = function() {
  };
  VibrationManager_Cancel_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VibrationManager_Cancel_Params.validate = function(messageValidator, offset) {
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

  VibrationManager_Cancel_Params.encodedSize = codec.kStructHeaderSize + 0;

  VibrationManager_Cancel_Params.decode = function(decoder) {
    var packed;
    var val = new VibrationManager_Cancel_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VibrationManager_Cancel_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VibrationManager_Cancel_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VibrationManager_Cancel_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VibrationManager_Cancel_ResponseParams.prototype.initDefaults_ = function() {
  };
  VibrationManager_Cancel_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VibrationManager_Cancel_ResponseParams.validate = function(messageValidator, offset) {
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

  VibrationManager_Cancel_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  VibrationManager_Cancel_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VibrationManager_Cancel_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VibrationManager_Cancel_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VibrationManager_Cancel_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  var kVibrationManager_Vibrate_Name = 0;
  var kVibrationManager_Cancel_Name = 1;

  function VibrationManagerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VibrationManager,
                                                   handleOrPtrInfo);
  }

  function VibrationManagerProxy(receiver) {
    this.receiver_ = receiver;
  }
  VibrationManagerPtr.prototype.vibrate = function() {
    return VibrationManagerProxy.prototype.vibrate
        .apply(this.ptr.getProxy(), arguments);
  };

  VibrationManagerProxy.prototype.vibrate = function(milliseconds) {
    var params = new VibrationManager_Vibrate_Params();
    params.milliseconds = milliseconds;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVibrationManager_Vibrate_Name,
          codec.align(VibrationManager_Vibrate_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VibrationManager_Vibrate_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VibrationManager_Vibrate_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  VibrationManagerPtr.prototype.cancel = function() {
    return VibrationManagerProxy.prototype.cancel
        .apply(this.ptr.getProxy(), arguments);
  };

  VibrationManagerProxy.prototype.cancel = function() {
    var params = new VibrationManager_Cancel_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVibrationManager_Cancel_Name,
          codec.align(VibrationManager_Cancel_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VibrationManager_Cancel_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VibrationManager_Cancel_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function VibrationManagerStub(delegate) {
    this.delegate_ = delegate;
  }
  VibrationManagerStub.prototype.vibrate = function(milliseconds) {
    return this.delegate_ && this.delegate_.vibrate && this.delegate_.vibrate(milliseconds);
  }
  VibrationManagerStub.prototype.cancel = function() {
    return this.delegate_ && this.delegate_.cancel && this.delegate_.cancel();
  }

  VibrationManagerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  VibrationManagerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVibrationManager_Vibrate_Name:
      var params = reader.decodeStruct(VibrationManager_Vibrate_Params);
      return this.vibrate(params.milliseconds).then(function(response) {
        var responseParams =
            new VibrationManager_Vibrate_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kVibrationManager_Vibrate_Name,
            codec.align(VibrationManager_Vibrate_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VibrationManager_Vibrate_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kVibrationManager_Cancel_Name:
      var params = reader.decodeStruct(VibrationManager_Cancel_Params);
      return this.cancel().then(function(response) {
        var responseParams =
            new VibrationManager_Cancel_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kVibrationManager_Cancel_Name,
            codec.align(VibrationManager_Cancel_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VibrationManager_Cancel_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVibrationManagerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVibrationManager_Vibrate_Name:
        if (message.expectsResponse())
          paramsClass = VibrationManager_Vibrate_Params;
      break;
      case kVibrationManager_Cancel_Name:
        if (message.expectsResponse())
          paramsClass = VibrationManager_Cancel_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVibrationManagerResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kVibrationManager_Vibrate_Name:
        if (message.isResponse())
          paramsClass = VibrationManager_Vibrate_ResponseParams;
        break;
      case kVibrationManager_Cancel_Name:
        if (message.isResponse())
          paramsClass = VibrationManager_Cancel_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var VibrationManager = {
    name: 'device::VibrationManager',
    ptrClass: VibrationManagerPtr,
    proxyClass: VibrationManagerProxy,
    stubClass: VibrationManagerStub,
    validateRequest: validateVibrationManagerRequest,
    validateResponse: validateVibrationManagerResponse,
  };
  VibrationManagerStub.prototype.validator = validateVibrationManagerRequest;
  VibrationManagerProxy.prototype.validator = validateVibrationManagerResponse;

  var exports = {};
  exports.VibrationManager = VibrationManager;
  exports.VibrationManagerPtr = VibrationManagerPtr;

  return exports;
});
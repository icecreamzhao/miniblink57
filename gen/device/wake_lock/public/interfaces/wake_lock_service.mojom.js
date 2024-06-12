// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/wake_lock/public/interfaces/wake_lock_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function WakeLockService_RequestWakeLock_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WakeLockService_RequestWakeLock_Params.prototype.initDefaults_ = function() {
  };
  WakeLockService_RequestWakeLock_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WakeLockService_RequestWakeLock_Params.validate = function(messageValidator, offset) {
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

  WakeLockService_RequestWakeLock_Params.encodedSize = codec.kStructHeaderSize + 0;

  WakeLockService_RequestWakeLock_Params.decode = function(decoder) {
    var packed;
    var val = new WakeLockService_RequestWakeLock_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  WakeLockService_RequestWakeLock_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WakeLockService_RequestWakeLock_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function WakeLockService_CancelWakeLock_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WakeLockService_CancelWakeLock_Params.prototype.initDefaults_ = function() {
  };
  WakeLockService_CancelWakeLock_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WakeLockService_CancelWakeLock_Params.validate = function(messageValidator, offset) {
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

  WakeLockService_CancelWakeLock_Params.encodedSize = codec.kStructHeaderSize + 0;

  WakeLockService_CancelWakeLock_Params.decode = function(decoder) {
    var packed;
    var val = new WakeLockService_CancelWakeLock_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  WakeLockService_CancelWakeLock_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WakeLockService_CancelWakeLock_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kWakeLockService_RequestWakeLock_Name = 0;
  var kWakeLockService_CancelWakeLock_Name = 1;

  function WakeLockServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WakeLockService,
                                                   handleOrPtrInfo);
  }

  function WakeLockServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  WakeLockServicePtr.prototype.requestWakeLock = function() {
    return WakeLockServiceProxy.prototype.requestWakeLock
        .apply(this.ptr.getProxy(), arguments);
  };

  WakeLockServiceProxy.prototype.requestWakeLock = function() {
    var params = new WakeLockService_RequestWakeLock_Params();
    var builder = new codec.MessageBuilder(
        kWakeLockService_RequestWakeLock_Name,
        codec.align(WakeLockService_RequestWakeLock_Params.encodedSize));
    builder.encodeStruct(WakeLockService_RequestWakeLock_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WakeLockServicePtr.prototype.cancelWakeLock = function() {
    return WakeLockServiceProxy.prototype.cancelWakeLock
        .apply(this.ptr.getProxy(), arguments);
  };

  WakeLockServiceProxy.prototype.cancelWakeLock = function() {
    var params = new WakeLockService_CancelWakeLock_Params();
    var builder = new codec.MessageBuilder(
        kWakeLockService_CancelWakeLock_Name,
        codec.align(WakeLockService_CancelWakeLock_Params.encodedSize));
    builder.encodeStruct(WakeLockService_CancelWakeLock_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function WakeLockServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  WakeLockServiceStub.prototype.requestWakeLock = function() {
    return this.delegate_ && this.delegate_.requestWakeLock && this.delegate_.requestWakeLock();
  }
  WakeLockServiceStub.prototype.cancelWakeLock = function() {
    return this.delegate_ && this.delegate_.cancelWakeLock && this.delegate_.cancelWakeLock();
  }

  WakeLockServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWakeLockService_RequestWakeLock_Name:
      var params = reader.decodeStruct(WakeLockService_RequestWakeLock_Params);
      this.requestWakeLock();
      return true;
    case kWakeLockService_CancelWakeLock_Name:
      var params = reader.decodeStruct(WakeLockService_CancelWakeLock_Params);
      this.cancelWakeLock();
      return true;
    default:
      return false;
    }
  };

  WakeLockServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWakeLockServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWakeLockService_RequestWakeLock_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WakeLockService_RequestWakeLock_Params;
      break;
      case kWakeLockService_CancelWakeLock_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WakeLockService_CancelWakeLock_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWakeLockServiceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var WakeLockService = {
    name: 'device::mojom::WakeLockService',
    ptrClass: WakeLockServicePtr,
    proxyClass: WakeLockServiceProxy,
    stubClass: WakeLockServiceStub,
    validateRequest: validateWakeLockServiceRequest,
    validateResponse: null,
  };
  WakeLockServiceStub.prototype.validator = validateWakeLockServiceRequest;
  WakeLockServiceProxy.prototype.validator = null;

  var exports = {};
  exports.WakeLockService = WakeLockService;
  exports.WakeLockServicePtr = WakeLockServicePtr;

  return exports;
});
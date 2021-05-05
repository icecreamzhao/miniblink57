// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/service_manager/public/interfaces/service_control.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function ServiceControl_RequestQuit_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ServiceControl_RequestQuit_Params.prototype.initDefaults_ = function() {
  };
  ServiceControl_RequestQuit_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ServiceControl_RequestQuit_Params.validate = function(messageValidator, offset) {
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

  ServiceControl_RequestQuit_Params.encodedSize = codec.kStructHeaderSize + 0;

  ServiceControl_RequestQuit_Params.decode = function(decoder) {
    var packed;
    var val = new ServiceControl_RequestQuit_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  ServiceControl_RequestQuit_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ServiceControl_RequestQuit_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kServiceControl_RequestQuit_Name = 0;

  function ServiceControlPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ServiceControl,
                                                   handleOrPtrInfo);
  }

  function ServiceControlProxy(receiver) {
    this.receiver_ = receiver;
  }
  ServiceControlPtr.prototype.requestQuit = function() {
    return ServiceControlProxy.prototype.requestQuit
        .apply(this.ptr.getProxy(), arguments);
  };

  ServiceControlProxy.prototype.requestQuit = function() {
    var params = new ServiceControl_RequestQuit_Params();
    var builder = new codec.MessageBuilder(
        kServiceControl_RequestQuit_Name,
        codec.align(ServiceControl_RequestQuit_Params.encodedSize));
    builder.encodeStruct(ServiceControl_RequestQuit_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ServiceControlStub(delegate) {
    this.delegate_ = delegate;
  }
  ServiceControlStub.prototype.requestQuit = function() {
    return this.delegate_ && this.delegate_.requestQuit && this.delegate_.requestQuit();
  }

  ServiceControlStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kServiceControl_RequestQuit_Name:
      var params = reader.decodeStruct(ServiceControl_RequestQuit_Params);
      this.requestQuit();
      return true;
    default:
      return false;
    }
  };

  ServiceControlStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateServiceControlRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kServiceControl_RequestQuit_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ServiceControl_RequestQuit_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateServiceControlResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var ServiceControl = {
    name: 'service_manager::mojom::ServiceControl',
    ptrClass: ServiceControlPtr,
    proxyClass: ServiceControlProxy,
    stubClass: ServiceControlStub,
    validateRequest: validateServiceControlRequest,
    validateResponse: null,
  };
  ServiceControlStub.prototype.validator = validateServiceControlRequest;
  ServiceControlProxy.prototype.validator = null;

  var exports = {};
  exports.ServiceControl = ServiceControl;
  exports.ServiceControlPtr = ServiceControlPtr;

  return exports;
});
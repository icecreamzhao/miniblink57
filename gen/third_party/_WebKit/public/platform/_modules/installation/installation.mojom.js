// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/installation/installation.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function InstallationService_OnInstall_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InstallationService_OnInstall_Params.prototype.initDefaults_ = function() {
  };
  InstallationService_OnInstall_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InstallationService_OnInstall_Params.validate = function(messageValidator, offset) {
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

  InstallationService_OnInstall_Params.encodedSize = codec.kStructHeaderSize + 0;

  InstallationService_OnInstall_Params.decode = function(decoder) {
    var packed;
    var val = new InstallationService_OnInstall_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  InstallationService_OnInstall_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InstallationService_OnInstall_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kInstallationService_OnInstall_Name = 0;

  function InstallationServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(InstallationService,
                                                   handleOrPtrInfo);
  }

  function InstallationServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  InstallationServicePtr.prototype.onInstall = function() {
    return InstallationServiceProxy.prototype.onInstall
        .apply(this.ptr.getProxy(), arguments);
  };

  InstallationServiceProxy.prototype.onInstall = function() {
    var params = new InstallationService_OnInstall_Params();
    var builder = new codec.MessageBuilder(
        kInstallationService_OnInstall_Name,
        codec.align(InstallationService_OnInstall_Params.encodedSize));
    builder.encodeStruct(InstallationService_OnInstall_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function InstallationServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  InstallationServiceStub.prototype.onInstall = function() {
    return this.delegate_ && this.delegate_.onInstall && this.delegate_.onInstall();
  }

  InstallationServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kInstallationService_OnInstall_Name:
      var params = reader.decodeStruct(InstallationService_OnInstall_Params);
      this.onInstall();
      return true;
    default:
      return false;
    }
  };

  InstallationServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateInstallationServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kInstallationService_OnInstall_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InstallationService_OnInstall_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateInstallationServiceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var InstallationService = {
    name: 'blink::mojom::InstallationService',
    ptrClass: InstallationServicePtr,
    proxyClass: InstallationServiceProxy,
    stubClass: InstallationServiceStub,
    validateRequest: validateInstallationServiceRequest,
    validateResponse: null,
  };
  InstallationServiceStub.prototype.validator = validateInstallationServiceRequest;
  InstallationServiceProxy.prototype.validator = null;

  var exports = {};
  exports.InstallationService = InstallationService;
  exports.InstallationServicePtr = InstallationServicePtr;

  return exports;
});
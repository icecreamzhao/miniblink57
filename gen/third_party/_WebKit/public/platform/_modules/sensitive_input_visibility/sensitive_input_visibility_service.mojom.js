// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/sensitive_input_visibility/sensitive_input_visibility_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.prototype.initDefaults_ = function() {
  };
  SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.validate = function(messageValidator, offset) {
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

  SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.encodedSize = codec.kStructHeaderSize + 0;

  SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.decode = function(decoder) {
    var packed;
    var val = new SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.prototype.initDefaults_ = function() {
  };
  SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.validate = function(messageValidator, offset) {
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

  SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.encodedSize = codec.kStructHeaderSize + 0;

  SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.decode = function(decoder) {
    var packed;
    var val = new SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name = 0;
  var kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name = 1;

  function SensitiveInputVisibilityServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(SensitiveInputVisibilityService,
                                                   handleOrPtrInfo);
  }

  function SensitiveInputVisibilityServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  SensitiveInputVisibilityServicePtr.prototype.passwordFieldVisibleInInsecureContext = function() {
    return SensitiveInputVisibilityServiceProxy.prototype.passwordFieldVisibleInInsecureContext
        .apply(this.ptr.getProxy(), arguments);
  };

  SensitiveInputVisibilityServiceProxy.prototype.passwordFieldVisibleInInsecureContext = function() {
    var params = new SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params();
    var builder = new codec.MessageBuilder(
        kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name,
        codec.align(SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params.encodedSize));
    builder.encodeStruct(SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  SensitiveInputVisibilityServicePtr.prototype.allPasswordFieldsInInsecureContextInvisible = function() {
    return SensitiveInputVisibilityServiceProxy.prototype.allPasswordFieldsInInsecureContextInvisible
        .apply(this.ptr.getProxy(), arguments);
  };

  SensitiveInputVisibilityServiceProxy.prototype.allPasswordFieldsInInsecureContextInvisible = function() {
    var params = new SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params();
    var builder = new codec.MessageBuilder(
        kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name,
        codec.align(SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params.encodedSize));
    builder.encodeStruct(SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function SensitiveInputVisibilityServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  SensitiveInputVisibilityServiceStub.prototype.passwordFieldVisibleInInsecureContext = function() {
    return this.delegate_ && this.delegate_.passwordFieldVisibleInInsecureContext && this.delegate_.passwordFieldVisibleInInsecureContext();
  }
  SensitiveInputVisibilityServiceStub.prototype.allPasswordFieldsInInsecureContextInvisible = function() {
    return this.delegate_ && this.delegate_.allPasswordFieldsInInsecureContextInvisible && this.delegate_.allPasswordFieldsInInsecureContextInvisible();
  }

  SensitiveInputVisibilityServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name:
      var params = reader.decodeStruct(SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params);
      this.passwordFieldVisibleInInsecureContext();
      return true;
    case kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name:
      var params = reader.decodeStruct(SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params);
      this.allPasswordFieldsInInsecureContextInvisible();
      return true;
    default:
      return false;
    }
  };

  SensitiveInputVisibilityServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateSensitiveInputVisibilityServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params;
      break;
      case kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateSensitiveInputVisibilityServiceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var SensitiveInputVisibilityService = {
    name: 'blink::mojom::SensitiveInputVisibilityService',
    ptrClass: SensitiveInputVisibilityServicePtr,
    proxyClass: SensitiveInputVisibilityServiceProxy,
    stubClass: SensitiveInputVisibilityServiceStub,
    validateRequest: validateSensitiveInputVisibilityServiceRequest,
    validateResponse: null,
  };
  SensitiveInputVisibilityServiceStub.prototype.validator = validateSensitiveInputVisibilityServiceRequest;
  SensitiveInputVisibilityServiceProxy.prototype.validator = null;

  var exports = {};
  exports.SensitiveInputVisibilityService = SensitiveInputVisibilityService;
  exports.SensitiveInputVisibilityServicePtr = SensitiveInputVisibilityServicePtr;

  return exports;
});
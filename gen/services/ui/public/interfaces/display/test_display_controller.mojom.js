// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/display/test_display_controller.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function TestDisplayController_ToggleAddRemoveDisplay_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TestDisplayController_ToggleAddRemoveDisplay_Params.prototype.initDefaults_ = function() {
  };
  TestDisplayController_ToggleAddRemoveDisplay_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TestDisplayController_ToggleAddRemoveDisplay_Params.validate = function(messageValidator, offset) {
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

  TestDisplayController_ToggleAddRemoveDisplay_Params.encodedSize = codec.kStructHeaderSize + 0;

  TestDisplayController_ToggleAddRemoveDisplay_Params.decode = function(decoder) {
    var packed;
    var val = new TestDisplayController_ToggleAddRemoveDisplay_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  TestDisplayController_ToggleAddRemoveDisplay_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TestDisplayController_ToggleAddRemoveDisplay_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function TestDisplayController_ToggleDisplayResolution_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TestDisplayController_ToggleDisplayResolution_Params.prototype.initDefaults_ = function() {
  };
  TestDisplayController_ToggleDisplayResolution_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TestDisplayController_ToggleDisplayResolution_Params.validate = function(messageValidator, offset) {
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

  TestDisplayController_ToggleDisplayResolution_Params.encodedSize = codec.kStructHeaderSize + 0;

  TestDisplayController_ToggleDisplayResolution_Params.decode = function(decoder) {
    var packed;
    var val = new TestDisplayController_ToggleDisplayResolution_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  TestDisplayController_ToggleDisplayResolution_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TestDisplayController_ToggleDisplayResolution_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kTestDisplayController_ToggleAddRemoveDisplay_Name = 0;
  var kTestDisplayController_ToggleDisplayResolution_Name = 1;

  function TestDisplayControllerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(TestDisplayController,
                                                   handleOrPtrInfo);
  }

  function TestDisplayControllerProxy(receiver) {
    this.receiver_ = receiver;
  }
  TestDisplayControllerPtr.prototype.toggleAddRemoveDisplay = function() {
    return TestDisplayControllerProxy.prototype.toggleAddRemoveDisplay
        .apply(this.ptr.getProxy(), arguments);
  };

  TestDisplayControllerProxy.prototype.toggleAddRemoveDisplay = function() {
    var params = new TestDisplayController_ToggleAddRemoveDisplay_Params();
    var builder = new codec.MessageBuilder(
        kTestDisplayController_ToggleAddRemoveDisplay_Name,
        codec.align(TestDisplayController_ToggleAddRemoveDisplay_Params.encodedSize));
    builder.encodeStruct(TestDisplayController_ToggleAddRemoveDisplay_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  TestDisplayControllerPtr.prototype.toggleDisplayResolution = function() {
    return TestDisplayControllerProxy.prototype.toggleDisplayResolution
        .apply(this.ptr.getProxy(), arguments);
  };

  TestDisplayControllerProxy.prototype.toggleDisplayResolution = function() {
    var params = new TestDisplayController_ToggleDisplayResolution_Params();
    var builder = new codec.MessageBuilder(
        kTestDisplayController_ToggleDisplayResolution_Name,
        codec.align(TestDisplayController_ToggleDisplayResolution_Params.encodedSize));
    builder.encodeStruct(TestDisplayController_ToggleDisplayResolution_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function TestDisplayControllerStub(delegate) {
    this.delegate_ = delegate;
  }
  TestDisplayControllerStub.prototype.toggleAddRemoveDisplay = function() {
    return this.delegate_ && this.delegate_.toggleAddRemoveDisplay && this.delegate_.toggleAddRemoveDisplay();
  }
  TestDisplayControllerStub.prototype.toggleDisplayResolution = function() {
    return this.delegate_ && this.delegate_.toggleDisplayResolution && this.delegate_.toggleDisplayResolution();
  }

  TestDisplayControllerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kTestDisplayController_ToggleAddRemoveDisplay_Name:
      var params = reader.decodeStruct(TestDisplayController_ToggleAddRemoveDisplay_Params);
      this.toggleAddRemoveDisplay();
      return true;
    case kTestDisplayController_ToggleDisplayResolution_Name:
      var params = reader.decodeStruct(TestDisplayController_ToggleDisplayResolution_Params);
      this.toggleDisplayResolution();
      return true;
    default:
      return false;
    }
  };

  TestDisplayControllerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateTestDisplayControllerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kTestDisplayController_ToggleAddRemoveDisplay_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TestDisplayController_ToggleAddRemoveDisplay_Params;
      break;
      case kTestDisplayController_ToggleDisplayResolution_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TestDisplayController_ToggleDisplayResolution_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateTestDisplayControllerResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var TestDisplayController = {
    name: 'display::mojom::TestDisplayController',
    ptrClass: TestDisplayControllerPtr,
    proxyClass: TestDisplayControllerProxy,
    stubClass: TestDisplayControllerStub,
    validateRequest: validateTestDisplayControllerRequest,
    validateResponse: null,
  };
  TestDisplayControllerStub.prototype.validator = validateTestDisplayControllerRequest;
  TestDisplayControllerProxy.prototype.validator = null;

  var exports = {};
  exports.TestDisplayController = TestDisplayController;
  exports.TestDisplayControllerPtr = TestDisplayControllerPtr;

  return exports;
});
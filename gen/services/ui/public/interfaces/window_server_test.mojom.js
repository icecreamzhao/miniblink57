// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/window_server_test.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function WindowServerTest_EnsureClientHasDrawnWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowServerTest_EnsureClientHasDrawnWindow_Params.prototype.initDefaults_ = function() {
    this.client_name = null;
  };
  WindowServerTest_EnsureClientHasDrawnWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowServerTest_EnsureClientHasDrawnWindow_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowServerTest_EnsureClientHasDrawnWindow_Params.client_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowServerTest_EnsureClientHasDrawnWindow_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowServerTest_EnsureClientHasDrawnWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowServerTest_EnsureClientHasDrawnWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client_name = decoder.decodeStruct(codec.String);
    return val;
  };

  WindowServerTest_EnsureClientHasDrawnWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowServerTest_EnsureClientHasDrawnWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.client_name);
  };
  function WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.validate = function(messageValidator, offset) {
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

  WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kWindowServerTest_EnsureClientHasDrawnWindow_Name = 0;

  function WindowServerTestPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WindowServerTest,
                                                   handleOrPtrInfo);
  }

  function WindowServerTestProxy(receiver) {
    this.receiver_ = receiver;
  }
  WindowServerTestPtr.prototype.ensureClientHasDrawnWindow = function() {
    return WindowServerTestProxy.prototype.ensureClientHasDrawnWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowServerTestProxy.prototype.ensureClientHasDrawnWindow = function(client_name) {
    var params = new WindowServerTest_EnsureClientHasDrawnWindow_Params();
    params.client_name = client_name;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWindowServerTest_EnsureClientHasDrawnWindow_Name,
          codec.align(WindowServerTest_EnsureClientHasDrawnWindow_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WindowServerTest_EnsureClientHasDrawnWindow_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function WindowServerTestStub(delegate) {
    this.delegate_ = delegate;
  }
  WindowServerTestStub.prototype.ensureClientHasDrawnWindow = function(client_name) {
    return this.delegate_ && this.delegate_.ensureClientHasDrawnWindow && this.delegate_.ensureClientHasDrawnWindow(client_name);
  }

  WindowServerTestStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  WindowServerTestStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowServerTest_EnsureClientHasDrawnWindow_Name:
      var params = reader.decodeStruct(WindowServerTest_EnsureClientHasDrawnWindow_Params);
      return this.ensureClientHasDrawnWindow(params.client_name).then(function(response) {
        var responseParams =
            new WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWindowServerTest_EnsureClientHasDrawnWindow_Name,
            codec.align(WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWindowServerTestRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWindowServerTest_EnsureClientHasDrawnWindow_Name:
        if (message.expectsResponse())
          paramsClass = WindowServerTest_EnsureClientHasDrawnWindow_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWindowServerTestResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kWindowServerTest_EnsureClientHasDrawnWindow_Name:
        if (message.isResponse())
          paramsClass = WindowServerTest_EnsureClientHasDrawnWindow_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var WindowServerTest = {
    name: 'ui::mojom::WindowServerTest',
    ptrClass: WindowServerTestPtr,
    proxyClass: WindowServerTestProxy,
    stubClass: WindowServerTestStub,
    validateRequest: validateWindowServerTestRequest,
    validateResponse: validateWindowServerTestResponse,
  };
  WindowServerTestStub.prototype.validator = validateWindowServerTestRequest;
  WindowServerTestProxy.prototype.validator = validateWindowServerTestResponse;

  var exports = {};
  exports.WindowServerTest = WindowServerTest;
  exports.WindowServerTestPtr = WindowServerTestPtr;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/service_manager/public/interfaces/interface_provider.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function InterfaceProvider_GetInterface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceProvider_GetInterface_Params.prototype.initDefaults_ = function() {
    this.interface_name = null;
    this.pipe = null;
  };
  InterfaceProvider_GetInterface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceProvider_GetInterface_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate InterfaceProvider_GetInterface_Params.interface_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate InterfaceProvider_GetInterface_Params.pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceProvider_GetInterface_Params.encodedSize = codec.kStructHeaderSize + 16;

  InterfaceProvider_GetInterface_Params.decode = function(decoder) {
    var packed;
    var val = new InterfaceProvider_GetInterface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.interface_name = decoder.decodeStruct(codec.String);
    val.pipe = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  InterfaceProvider_GetInterface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceProvider_GetInterface_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.interface_name);
    encoder.encodeStruct(codec.Handle, val.pipe);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kInterfaceProvider_GetInterface_Name = 0;

  function InterfaceProviderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(InterfaceProvider,
                                                   handleOrPtrInfo);
  }

  function InterfaceProviderProxy(receiver) {
    this.receiver_ = receiver;
  }
  InterfaceProviderPtr.prototype.getInterface = function() {
    return InterfaceProviderProxy.prototype.getInterface
        .apply(this.ptr.getProxy(), arguments);
  };

  InterfaceProviderProxy.prototype.getInterface = function(interface_name, pipe) {
    var params = new InterfaceProvider_GetInterface_Params();
    params.interface_name = interface_name;
    params.pipe = pipe;
    var builder = new codec.MessageBuilder(
        kInterfaceProvider_GetInterface_Name,
        codec.align(InterfaceProvider_GetInterface_Params.encodedSize));
    builder.encodeStruct(InterfaceProvider_GetInterface_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function InterfaceProviderStub(delegate) {
    this.delegate_ = delegate;
  }
  InterfaceProviderStub.prototype.getInterface = function(interface_name, pipe) {
    return this.delegate_ && this.delegate_.getInterface && this.delegate_.getInterface(interface_name, pipe);
  }

  InterfaceProviderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kInterfaceProvider_GetInterface_Name:
      var params = reader.decodeStruct(InterfaceProvider_GetInterface_Params);
      this.getInterface(params.interface_name, params.pipe);
      return true;
    default:
      return false;
    }
  };

  InterfaceProviderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateInterfaceProviderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kInterfaceProvider_GetInterface_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InterfaceProvider_GetInterface_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateInterfaceProviderResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var InterfaceProvider = {
    name: 'service_manager::mojom::InterfaceProvider',
    ptrClass: InterfaceProviderPtr,
    proxyClass: InterfaceProviderProxy,
    stubClass: InterfaceProviderStub,
    validateRequest: validateInterfaceProviderRequest,
    validateResponse: null,
  };
  InterfaceProviderStub.prototype.validator = validateInterfaceProviderRequest;
  InterfaceProviderProxy.prototype.validator = null;

  var exports = {};
  exports.InterfaceProvider = InterfaceProvider;
  exports.InterfaceProviderPtr = InterfaceProviderPtr;

  return exports;
});
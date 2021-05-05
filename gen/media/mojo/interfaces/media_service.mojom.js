// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/media_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/interface_factory.mojom",
    "services/service_manager/public/interfaces/interface_provider.mojom",
], function(bindings, codec, core, validator, interface_factory$, interface_provider$) {

  function MediaService_CreateInterfaceFactory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MediaService_CreateInterfaceFactory_Params.prototype.initDefaults_ = function() {
    this.factory = new bindings.InterfaceRequest();
    this.host_interfaces = new interface_provider$.InterfaceProviderPtr();
  };
  MediaService_CreateInterfaceFactory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MediaService_CreateInterfaceFactory_Params.validate = function(messageValidator, offset) {
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


    
    // validate MediaService_CreateInterfaceFactory_Params.factory
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate MediaService_CreateInterfaceFactory_Params.host_interfaces
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MediaService_CreateInterfaceFactory_Params.encodedSize = codec.kStructHeaderSize + 16;

  MediaService_CreateInterfaceFactory_Params.decode = function(decoder) {
    var packed;
    var val = new MediaService_CreateInterfaceFactory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.factory = decoder.decodeStruct(codec.InterfaceRequest);
    val.host_interfaces = decoder.decodeStruct(new codec.NullableInterface(interface_provider$.InterfaceProviderPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  MediaService_CreateInterfaceFactory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MediaService_CreateInterfaceFactory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.factory);
    encoder.encodeStruct(new codec.NullableInterface(interface_provider$.InterfaceProviderPtr), val.host_interfaces);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kMediaService_CreateInterfaceFactory_Name = 0;

  function MediaServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(MediaService,
                                                   handleOrPtrInfo);
  }

  function MediaServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  MediaServicePtr.prototype.createInterfaceFactory = function() {
    return MediaServiceProxy.prototype.createInterfaceFactory
        .apply(this.ptr.getProxy(), arguments);
  };

  MediaServiceProxy.prototype.createInterfaceFactory = function(factory, host_interfaces) {
    var params = new MediaService_CreateInterfaceFactory_Params();
    params.factory = factory;
    params.host_interfaces = host_interfaces;
    var builder = new codec.MessageBuilder(
        kMediaService_CreateInterfaceFactory_Name,
        codec.align(MediaService_CreateInterfaceFactory_Params.encodedSize));
    builder.encodeStruct(MediaService_CreateInterfaceFactory_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function MediaServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  MediaServiceStub.prototype.createInterfaceFactory = function(factory, host_interfaces) {
    return this.delegate_ && this.delegate_.createInterfaceFactory && this.delegate_.createInterfaceFactory(factory, host_interfaces);
  }

  MediaServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kMediaService_CreateInterfaceFactory_Name:
      var params = reader.decodeStruct(MediaService_CreateInterfaceFactory_Params);
      this.createInterfaceFactory(params.factory, params.host_interfaces);
      return true;
    default:
      return false;
    }
  };

  MediaServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateMediaServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kMediaService_CreateInterfaceFactory_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MediaService_CreateInterfaceFactory_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateMediaServiceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var MediaService = {
    name: 'media::mojom::MediaService',
    ptrClass: MediaServicePtr,
    proxyClass: MediaServiceProxy,
    stubClass: MediaServiceStub,
    validateRequest: validateMediaServiceRequest,
    validateResponse: null,
  };
  MediaServiceStub.prototype.validator = validateMediaServiceRequest;
  MediaServiceProxy.prototype.validator = null;

  var exports = {};
  exports.MediaService = MediaService;
  exports.MediaServicePtr = MediaServicePtr;

  return exports;
});
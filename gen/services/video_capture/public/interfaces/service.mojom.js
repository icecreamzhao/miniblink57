// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/video_capture/public/interfaces/service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/video_capture/public/interfaces/device_factory.mojom",
], function(bindings, codec, core, validator, device_factory$) {

  function Service_ConnectToDeviceFactory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_ConnectToDeviceFactory_Params.prototype.initDefaults_ = function() {
    this.request = new bindings.InterfaceRequest();
  };
  Service_ConnectToDeviceFactory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_ConnectToDeviceFactory_Params.validate = function(messageValidator, offset) {
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


    
    // validate Service_ConnectToDeviceFactory_Params.request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Service_ConnectToDeviceFactory_Params.encodedSize = codec.kStructHeaderSize + 8;

  Service_ConnectToDeviceFactory_Params.decode = function(decoder) {
    var packed;
    var val = new Service_ConnectToDeviceFactory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Service_ConnectToDeviceFactory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_ConnectToDeviceFactory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Service_ConnectToFakeDeviceFactory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_ConnectToFakeDeviceFactory_Params.prototype.initDefaults_ = function() {
    this.request = new bindings.InterfaceRequest();
  };
  Service_ConnectToFakeDeviceFactory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_ConnectToFakeDeviceFactory_Params.validate = function(messageValidator, offset) {
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


    
    // validate Service_ConnectToFakeDeviceFactory_Params.request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Service_ConnectToFakeDeviceFactory_Params.encodedSize = codec.kStructHeaderSize + 8;

  Service_ConnectToFakeDeviceFactory_Params.decode = function(decoder) {
    var packed;
    var val = new Service_ConnectToFakeDeviceFactory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Service_ConnectToFakeDeviceFactory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_ConnectToFakeDeviceFactory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kService_ConnectToDeviceFactory_Name = 0;
  var kService_ConnectToFakeDeviceFactory_Name = 1;

  function ServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Service,
                                                   handleOrPtrInfo);
  }

  function ServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  ServicePtr.prototype.connectToDeviceFactory = function() {
    return ServiceProxy.prototype.connectToDeviceFactory
        .apply(this.ptr.getProxy(), arguments);
  };

  ServiceProxy.prototype.connectToDeviceFactory = function(request) {
    var params = new Service_ConnectToDeviceFactory_Params();
    params.request = request;
    var builder = new codec.MessageBuilder(
        kService_ConnectToDeviceFactory_Name,
        codec.align(Service_ConnectToDeviceFactory_Params.encodedSize));
    builder.encodeStruct(Service_ConnectToDeviceFactory_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ServicePtr.prototype.connectToFakeDeviceFactory = function() {
    return ServiceProxy.prototype.connectToFakeDeviceFactory
        .apply(this.ptr.getProxy(), arguments);
  };

  ServiceProxy.prototype.connectToFakeDeviceFactory = function(request) {
    var params = new Service_ConnectToFakeDeviceFactory_Params();
    params.request = request;
    var builder = new codec.MessageBuilder(
        kService_ConnectToFakeDeviceFactory_Name,
        codec.align(Service_ConnectToFakeDeviceFactory_Params.encodedSize));
    builder.encodeStruct(Service_ConnectToFakeDeviceFactory_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  ServiceStub.prototype.connectToDeviceFactory = function(request) {
    return this.delegate_ && this.delegate_.connectToDeviceFactory && this.delegate_.connectToDeviceFactory(request);
  }
  ServiceStub.prototype.connectToFakeDeviceFactory = function(request) {
    return this.delegate_ && this.delegate_.connectToFakeDeviceFactory && this.delegate_.connectToFakeDeviceFactory(request);
  }

  ServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kService_ConnectToDeviceFactory_Name:
      var params = reader.decodeStruct(Service_ConnectToDeviceFactory_Params);
      this.connectToDeviceFactory(params.request);
      return true;
    case kService_ConnectToFakeDeviceFactory_Name:
      var params = reader.decodeStruct(Service_ConnectToFakeDeviceFactory_Params);
      this.connectToFakeDeviceFactory(params.request);
      return true;
    default:
      return false;
    }
  };

  ServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kService_ConnectToDeviceFactory_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Service_ConnectToDeviceFactory_Params;
      break;
      case kService_ConnectToFakeDeviceFactory_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Service_ConnectToFakeDeviceFactory_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateServiceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var Service = {
    name: 'video_capture::mojom::Service',
    ptrClass: ServicePtr,
    proxyClass: ServiceProxy,
    stubClass: ServiceStub,
    validateRequest: validateServiceRequest,
    validateResponse: null,
  };
  ServiceStub.prototype.validator = validateServiceRequest;
  ServiceProxy.prototype.validator = null;

  var exports = {};
  exports.Service = Service;
  exports.ServicePtr = ServicePtr;

  return exports;
});
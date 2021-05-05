// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/gpu/interfaces/gpu_main.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/display_compositor.mojom",
    "gpu/ipc/common/gpu_preferences.mojom",
    "services/ui/gpu/interfaces/gpu_host.mojom",
    "services/ui/gpu/interfaces/gpu_service.mojom",
], function(bindings, codec, core, validator, display_compositor$, gpu_preferences$, gpu_host$, gpu_service$) {

  function GpuMain_CreateDisplayCompositor_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuMain_CreateDisplayCompositor_Params.prototype.initDefaults_ = function() {
    this.display_compositor = new bindings.InterfaceRequest();
    this.display_compositor_client = new display_compositor$.DisplayCompositorClientPtr();
  };
  GpuMain_CreateDisplayCompositor_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuMain_CreateDisplayCompositor_Params.validate = function(messageValidator, offset) {
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


    
    // validate GpuMain_CreateDisplayCompositor_Params.display_compositor
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuMain_CreateDisplayCompositor_Params.display_compositor_client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuMain_CreateDisplayCompositor_Params.encodedSize = codec.kStructHeaderSize + 16;

  GpuMain_CreateDisplayCompositor_Params.decode = function(decoder) {
    var packed;
    var val = new GpuMain_CreateDisplayCompositor_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.display_compositor = decoder.decodeStruct(codec.InterfaceRequest);
    val.display_compositor_client = decoder.decodeStruct(new codec.Interface(display_compositor$.DisplayCompositorClientPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GpuMain_CreateDisplayCompositor_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuMain_CreateDisplayCompositor_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.display_compositor);
    encoder.encodeStruct(new codec.Interface(display_compositor$.DisplayCompositorClientPtr), val.display_compositor_client);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GpuMain_CreateGpuService_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuMain_CreateGpuService_Params.prototype.initDefaults_ = function() {
    this.gpu_service = new bindings.InterfaceRequest();
    this.gpu_host = new gpu_host$.GpuHostPtr();
    this.preferences = null;
  };
  GpuMain_CreateGpuService_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuMain_CreateGpuService_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 32}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuMain_CreateGpuService_Params.gpu_service
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuMain_CreateGpuService_Params.gpu_host
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuMain_CreateGpuService_Params.preferences
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, gpu_preferences$.GpuPreferences, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuMain_CreateGpuService_Params.encodedSize = codec.kStructHeaderSize + 24;

  GpuMain_CreateGpuService_Params.decode = function(decoder) {
    var packed;
    var val = new GpuMain_CreateGpuService_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.gpu_service = decoder.decodeStruct(codec.InterfaceRequest);
    val.gpu_host = decoder.decodeStruct(new codec.Interface(gpu_host$.GpuHostPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.preferences = decoder.decodeStructPointer(gpu_preferences$.GpuPreferences);
    return val;
  };

  GpuMain_CreateGpuService_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuMain_CreateGpuService_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.gpu_service);
    encoder.encodeStruct(new codec.Interface(gpu_host$.GpuHostPtr), val.gpu_host);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(gpu_preferences$.GpuPreferences, val.preferences);
  };
  var kGpuMain_CreateDisplayCompositor_Name = 0;
  var kGpuMain_CreateGpuService_Name = 1;

  function GpuMainPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(GpuMain,
                                                   handleOrPtrInfo);
  }

  function GpuMainProxy(receiver) {
    this.receiver_ = receiver;
  }
  GpuMainPtr.prototype.createDisplayCompositor = function() {
    return GpuMainProxy.prototype.createDisplayCompositor
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuMainProxy.prototype.createDisplayCompositor = function(display_compositor, display_compositor_client) {
    var params = new GpuMain_CreateDisplayCompositor_Params();
    params.display_compositor = display_compositor;
    params.display_compositor_client = display_compositor_client;
    var builder = new codec.MessageBuilder(
        kGpuMain_CreateDisplayCompositor_Name,
        codec.align(GpuMain_CreateDisplayCompositor_Params.encodedSize));
    builder.encodeStruct(GpuMain_CreateDisplayCompositor_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GpuMainPtr.prototype.createGpuService = function() {
    return GpuMainProxy.prototype.createGpuService
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuMainProxy.prototype.createGpuService = function(gpu_service, gpu_host, preferences) {
    var params = new GpuMain_CreateGpuService_Params();
    params.gpu_service = gpu_service;
    params.gpu_host = gpu_host;
    params.preferences = preferences;
    var builder = new codec.MessageBuilder(
        kGpuMain_CreateGpuService_Name,
        codec.align(GpuMain_CreateGpuService_Params.encodedSize));
    builder.encodeStruct(GpuMain_CreateGpuService_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function GpuMainStub(delegate) {
    this.delegate_ = delegate;
  }
  GpuMainStub.prototype.createDisplayCompositor = function(display_compositor, display_compositor_client) {
    return this.delegate_ && this.delegate_.createDisplayCompositor && this.delegate_.createDisplayCompositor(display_compositor, display_compositor_client);
  }
  GpuMainStub.prototype.createGpuService = function(gpu_service, gpu_host, preferences) {
    return this.delegate_ && this.delegate_.createGpuService && this.delegate_.createGpuService(gpu_service, gpu_host, preferences);
  }

  GpuMainStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGpuMain_CreateDisplayCompositor_Name:
      var params = reader.decodeStruct(GpuMain_CreateDisplayCompositor_Params);
      this.createDisplayCompositor(params.display_compositor, params.display_compositor_client);
      return true;
    case kGpuMain_CreateGpuService_Name:
      var params = reader.decodeStruct(GpuMain_CreateGpuService_Params);
      this.createGpuService(params.gpu_service, params.gpu_host, params.preferences);
      return true;
    default:
      return false;
    }
  };

  GpuMainStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateGpuMainRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kGpuMain_CreateDisplayCompositor_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuMain_CreateDisplayCompositor_Params;
      break;
      case kGpuMain_CreateGpuService_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuMain_CreateGpuService_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateGpuMainResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var GpuMain = {
    name: 'ui::mojom::GpuMain',
    ptrClass: GpuMainPtr,
    proxyClass: GpuMainProxy,
    stubClass: GpuMainStub,
    validateRequest: validateGpuMainRequest,
    validateResponse: null,
  };
  GpuMainStub.prototype.validator = validateGpuMainRequest;
  GpuMainProxy.prototype.validator = null;

  var exports = {};
  exports.GpuMain = GpuMain;
  exports.GpuMainPtr = GpuMainPtr;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/offscreencanvas/offscreen_canvas_surface.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/compositor_frame.mojom",
    "cc/ipc/frame_sink_id.mojom",
    "cc/ipc/mojo_compositor_frame_sink.mojom",
    "cc/ipc/surface_id.mojom",
    "cc/ipc/surface_info.mojom",
    "cc/ipc/surface_sequence.mojom",
], function(bindings, codec, core, validator, compositor_frame$, frame_sink_id$, mojo_compositor_frame_sink$, surface_id$, surface_info$, surface_sequence$) {

  function OffscreenCanvasSurface_Require_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OffscreenCanvasSurface_Require_Params.prototype.initDefaults_ = function() {
    this.surface_id = null;
    this.sequence = null;
  };
  OffscreenCanvasSurface_Require_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OffscreenCanvasSurface_Require_Params.validate = function(messageValidator, offset) {
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


    
    // validate OffscreenCanvasSurface_Require_Params.surface_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_id$.SurfaceId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate OffscreenCanvasSurface_Require_Params.sequence
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, surface_sequence$.SurfaceSequence, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  OffscreenCanvasSurface_Require_Params.encodedSize = codec.kStructHeaderSize + 16;

  OffscreenCanvasSurface_Require_Params.decode = function(decoder) {
    var packed;
    var val = new OffscreenCanvasSurface_Require_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.surface_id = decoder.decodeStructPointer(surface_id$.SurfaceId);
    val.sequence = decoder.decodeStructPointer(surface_sequence$.SurfaceSequence);
    return val;
  };

  OffscreenCanvasSurface_Require_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OffscreenCanvasSurface_Require_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_id$.SurfaceId, val.surface_id);
    encoder.encodeStructPointer(surface_sequence$.SurfaceSequence, val.sequence);
  };
  function OffscreenCanvasSurface_Satisfy_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OffscreenCanvasSurface_Satisfy_Params.prototype.initDefaults_ = function() {
    this.sequence = null;
  };
  OffscreenCanvasSurface_Satisfy_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OffscreenCanvasSurface_Satisfy_Params.validate = function(messageValidator, offset) {
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


    
    // validate OffscreenCanvasSurface_Satisfy_Params.sequence
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_sequence$.SurfaceSequence, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  OffscreenCanvasSurface_Satisfy_Params.encodedSize = codec.kStructHeaderSize + 8;

  OffscreenCanvasSurface_Satisfy_Params.decode = function(decoder) {
    var packed;
    var val = new OffscreenCanvasSurface_Satisfy_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sequence = decoder.decodeStructPointer(surface_sequence$.SurfaceSequence);
    return val;
  };

  OffscreenCanvasSurface_Satisfy_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OffscreenCanvasSurface_Satisfy_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_sequence$.SurfaceSequence, val.sequence);
  };
  function OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.prototype.initDefaults_ = function() {
    this.surface_info = null;
  };
  OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.validate = function(messageValidator, offset) {
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


    
    // validate OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.surface_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_info$.SurfaceInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.encodedSize = codec.kStructHeaderSize + 8;

  OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.decode = function(decoder) {
    var packed;
    var val = new OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.surface_info = decoder.decodeStructPointer(surface_info$.SurfaceInfo);
    return val;
  };

  OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_info$.SurfaceInfo, val.surface_info);
  };
  function OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.prototype.initDefaults_ = function() {
    this.frame_sink_id = null;
    this.client = new OffscreenCanvasSurfaceClientPtr();
    this.service = new bindings.InterfaceRequest();
  };
  OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.validate = function(messageValidator, offset) {
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


    
    // validate OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.service
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.encodedSize = codec.kStructHeaderSize + 24;

  OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.decode = function(decoder) {
    var packed;
    var val = new OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    val.client = decoder.decodeStruct(new codec.Interface(OffscreenCanvasSurfaceClientPtr));
    val.service = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.frame_sink_id);
    encoder.encodeStruct(new codec.Interface(OffscreenCanvasSurfaceClientPtr), val.client);
    encoder.encodeStruct(codec.InterfaceRequest, val.service);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.prototype.initDefaults_ = function() {
    this.frame_sink_id = null;
    this.client = new mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr();
    this.sink = new bindings.InterfaceRequest();
  };
  OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.validate = function(messageValidator, offset) {
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


    
    // validate OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.sink
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.encodedSize = codec.kStructHeaderSize + 24;

  OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.decode = function(decoder) {
    var packed;
    var val = new OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    val.client = decoder.decodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr));
    val.sink = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.frame_sink_id);
    encoder.encodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr), val.client);
    encoder.encodeStruct(codec.InterfaceRequest, val.sink);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kOffscreenCanvasSurface_Require_Name = 0;
  var kOffscreenCanvasSurface_Satisfy_Name = 1;

  function OffscreenCanvasSurfacePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(OffscreenCanvasSurface,
                                                   handleOrPtrInfo);
  }

  function OffscreenCanvasSurfaceProxy(receiver) {
    this.receiver_ = receiver;
  }
  OffscreenCanvasSurfacePtr.prototype.require = function() {
    return OffscreenCanvasSurfaceProxy.prototype.require
        .apply(this.ptr.getProxy(), arguments);
  };

  OffscreenCanvasSurfaceProxy.prototype.require = function(surface_id, sequence) {
    var params = new OffscreenCanvasSurface_Require_Params();
    params.surface_id = surface_id;
    params.sequence = sequence;
    var builder = new codec.MessageBuilder(
        kOffscreenCanvasSurface_Require_Name,
        codec.align(OffscreenCanvasSurface_Require_Params.encodedSize));
    builder.encodeStruct(OffscreenCanvasSurface_Require_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  OffscreenCanvasSurfacePtr.prototype.satisfy = function() {
    return OffscreenCanvasSurfaceProxy.prototype.satisfy
        .apply(this.ptr.getProxy(), arguments);
  };

  OffscreenCanvasSurfaceProxy.prototype.satisfy = function(sequence) {
    var params = new OffscreenCanvasSurface_Satisfy_Params();
    params.sequence = sequence;
    var builder = new codec.MessageBuilder(
        kOffscreenCanvasSurface_Satisfy_Name,
        codec.align(OffscreenCanvasSurface_Satisfy_Params.encodedSize));
    builder.encodeStruct(OffscreenCanvasSurface_Satisfy_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function OffscreenCanvasSurfaceStub(delegate) {
    this.delegate_ = delegate;
  }
  OffscreenCanvasSurfaceStub.prototype.require = function(surface_id, sequence) {
    return this.delegate_ && this.delegate_.require && this.delegate_.require(surface_id, sequence);
  }
  OffscreenCanvasSurfaceStub.prototype.satisfy = function(sequence) {
    return this.delegate_ && this.delegate_.satisfy && this.delegate_.satisfy(sequence);
  }

  OffscreenCanvasSurfaceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOffscreenCanvasSurface_Require_Name:
      var params = reader.decodeStruct(OffscreenCanvasSurface_Require_Params);
      this.require(params.surface_id, params.sequence);
      return true;
    case kOffscreenCanvasSurface_Satisfy_Name:
      var params = reader.decodeStruct(OffscreenCanvasSurface_Satisfy_Params);
      this.satisfy(params.sequence);
      return true;
    default:
      return false;
    }
  };

  OffscreenCanvasSurfaceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateOffscreenCanvasSurfaceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kOffscreenCanvasSurface_Require_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = OffscreenCanvasSurface_Require_Params;
      break;
      case kOffscreenCanvasSurface_Satisfy_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = OffscreenCanvasSurface_Satisfy_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateOffscreenCanvasSurfaceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var OffscreenCanvasSurface = {
    name: 'blink::mojom::OffscreenCanvasSurface',
    ptrClass: OffscreenCanvasSurfacePtr,
    proxyClass: OffscreenCanvasSurfaceProxy,
    stubClass: OffscreenCanvasSurfaceStub,
    validateRequest: validateOffscreenCanvasSurfaceRequest,
    validateResponse: null,
  };
  OffscreenCanvasSurfaceStub.prototype.validator = validateOffscreenCanvasSurfaceRequest;
  OffscreenCanvasSurfaceProxy.prototype.validator = null;
  var kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name = 0;

  function OffscreenCanvasSurfaceClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(OffscreenCanvasSurfaceClient,
                                                   handleOrPtrInfo);
  }

  function OffscreenCanvasSurfaceClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  OffscreenCanvasSurfaceClientPtr.prototype.onSurfaceCreated = function() {
    return OffscreenCanvasSurfaceClientProxy.prototype.onSurfaceCreated
        .apply(this.ptr.getProxy(), arguments);
  };

  OffscreenCanvasSurfaceClientProxy.prototype.onSurfaceCreated = function(surface_info) {
    var params = new OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params();
    params.surface_info = surface_info;
    var builder = new codec.MessageBuilder(
        kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name,
        codec.align(OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params.encodedSize));
    builder.encodeStruct(OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function OffscreenCanvasSurfaceClientStub(delegate) {
    this.delegate_ = delegate;
  }
  OffscreenCanvasSurfaceClientStub.prototype.onSurfaceCreated = function(surface_info) {
    return this.delegate_ && this.delegate_.onSurfaceCreated && this.delegate_.onSurfaceCreated(surface_info);
  }

  OffscreenCanvasSurfaceClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name:
      var params = reader.decodeStruct(OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params);
      this.onSurfaceCreated(params.surface_info);
      return true;
    default:
      return false;
    }
  };

  OffscreenCanvasSurfaceClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateOffscreenCanvasSurfaceClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateOffscreenCanvasSurfaceClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var OffscreenCanvasSurfaceClient = {
    name: 'blink::mojom::OffscreenCanvasSurfaceClient',
    ptrClass: OffscreenCanvasSurfaceClientPtr,
    proxyClass: OffscreenCanvasSurfaceClientProxy,
    stubClass: OffscreenCanvasSurfaceClientStub,
    validateRequest: validateOffscreenCanvasSurfaceClientRequest,
    validateResponse: null,
  };
  OffscreenCanvasSurfaceClientStub.prototype.validator = validateOffscreenCanvasSurfaceClientRequest;
  OffscreenCanvasSurfaceClientProxy.prototype.validator = null;
  var kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name = 0;

  function OffscreenCanvasSurfaceFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(OffscreenCanvasSurfaceFactory,
                                                   handleOrPtrInfo);
  }

  function OffscreenCanvasSurfaceFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  OffscreenCanvasSurfaceFactoryPtr.prototype.createOffscreenCanvasSurface = function() {
    return OffscreenCanvasSurfaceFactoryProxy.prototype.createOffscreenCanvasSurface
        .apply(this.ptr.getProxy(), arguments);
  };

  OffscreenCanvasSurfaceFactoryProxy.prototype.createOffscreenCanvasSurface = function(frame_sink_id, client, service) {
    var params = new OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params();
    params.frame_sink_id = frame_sink_id;
    params.client = client;
    params.service = service;
    var builder = new codec.MessageBuilder(
        kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name,
        codec.align(OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params.encodedSize));
    builder.encodeStruct(OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function OffscreenCanvasSurfaceFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  OffscreenCanvasSurfaceFactoryStub.prototype.createOffscreenCanvasSurface = function(frame_sink_id, client, service) {
    return this.delegate_ && this.delegate_.createOffscreenCanvasSurface && this.delegate_.createOffscreenCanvasSurface(frame_sink_id, client, service);
  }

  OffscreenCanvasSurfaceFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name:
      var params = reader.decodeStruct(OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params);
      this.createOffscreenCanvasSurface(params.frame_sink_id, params.client, params.service);
      return true;
    default:
      return false;
    }
  };

  OffscreenCanvasSurfaceFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateOffscreenCanvasSurfaceFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateOffscreenCanvasSurfaceFactoryResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var OffscreenCanvasSurfaceFactory = {
    name: 'blink::mojom::OffscreenCanvasSurfaceFactory',
    ptrClass: OffscreenCanvasSurfaceFactoryPtr,
    proxyClass: OffscreenCanvasSurfaceFactoryProxy,
    stubClass: OffscreenCanvasSurfaceFactoryStub,
    validateRequest: validateOffscreenCanvasSurfaceFactoryRequest,
    validateResponse: null,
  };
  OffscreenCanvasSurfaceFactoryStub.prototype.validator = validateOffscreenCanvasSurfaceFactoryRequest;
  OffscreenCanvasSurfaceFactoryProxy.prototype.validator = null;
  var kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name = 0;

  function OffscreenCanvasCompositorFrameSinkProviderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(OffscreenCanvasCompositorFrameSinkProvider,
                                                   handleOrPtrInfo);
  }

  function OffscreenCanvasCompositorFrameSinkProviderProxy(receiver) {
    this.receiver_ = receiver;
  }
  OffscreenCanvasCompositorFrameSinkProviderPtr.prototype.createCompositorFrameSink = function() {
    return OffscreenCanvasCompositorFrameSinkProviderProxy.prototype.createCompositorFrameSink
        .apply(this.ptr.getProxy(), arguments);
  };

  OffscreenCanvasCompositorFrameSinkProviderProxy.prototype.createCompositorFrameSink = function(frame_sink_id, client, sink) {
    var params = new OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params();
    params.frame_sink_id = frame_sink_id;
    params.client = client;
    params.sink = sink;
    var builder = new codec.MessageBuilder(
        kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name,
        codec.align(OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params.encodedSize));
    builder.encodeStruct(OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function OffscreenCanvasCompositorFrameSinkProviderStub(delegate) {
    this.delegate_ = delegate;
  }
  OffscreenCanvasCompositorFrameSinkProviderStub.prototype.createCompositorFrameSink = function(frame_sink_id, client, sink) {
    return this.delegate_ && this.delegate_.createCompositorFrameSink && this.delegate_.createCompositorFrameSink(frame_sink_id, client, sink);
  }

  OffscreenCanvasCompositorFrameSinkProviderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name:
      var params = reader.decodeStruct(OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params);
      this.createCompositorFrameSink(params.frame_sink_id, params.client, params.sink);
      return true;
    default:
      return false;
    }
  };

  OffscreenCanvasCompositorFrameSinkProviderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateOffscreenCanvasCompositorFrameSinkProviderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateOffscreenCanvasCompositorFrameSinkProviderResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var OffscreenCanvasCompositorFrameSinkProvider = {
    name: 'blink::mojom::OffscreenCanvasCompositorFrameSinkProvider',
    ptrClass: OffscreenCanvasCompositorFrameSinkProviderPtr,
    proxyClass: OffscreenCanvasCompositorFrameSinkProviderProxy,
    stubClass: OffscreenCanvasCompositorFrameSinkProviderStub,
    validateRequest: validateOffscreenCanvasCompositorFrameSinkProviderRequest,
    validateResponse: null,
  };
  OffscreenCanvasCompositorFrameSinkProviderStub.prototype.validator = validateOffscreenCanvasCompositorFrameSinkProviderRequest;
  OffscreenCanvasCompositorFrameSinkProviderProxy.prototype.validator = null;

  var exports = {};
  exports.OffscreenCanvasSurface = OffscreenCanvasSurface;
  exports.OffscreenCanvasSurfacePtr = OffscreenCanvasSurfacePtr;
  exports.OffscreenCanvasSurfaceClient = OffscreenCanvasSurfaceClient;
  exports.OffscreenCanvasSurfaceClientPtr = OffscreenCanvasSurfaceClientPtr;
  exports.OffscreenCanvasSurfaceFactory = OffscreenCanvasSurfaceFactory;
  exports.OffscreenCanvasSurfaceFactoryPtr = OffscreenCanvasSurfaceFactoryPtr;
  exports.OffscreenCanvasCompositorFrameSinkProvider = OffscreenCanvasCompositorFrameSinkProvider;
  exports.OffscreenCanvasCompositorFrameSinkProviderPtr = OffscreenCanvasCompositorFrameSinkProviderPtr;

  return exports;
});
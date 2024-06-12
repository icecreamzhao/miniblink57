// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/gpu/interfaces/gpu_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/display_compositor.mojom",
    "gpu/ipc/common/gpu_info.mojom",
    "gpu/ipc/common/surface_handle.mojom",
    "gpu/ipc/common/sync_token.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/gfx/mojo/buffer_types.mojom",
], function(bindings, codec, core, validator, display_compositor$, gpu_info$, surface_handle$, sync_token$, geometry$, buffer_types$) {

  function GpuService_EstablishGpuChannel_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuService_EstablishGpuChannel_Params.prototype.initDefaults_ = function() {
    this.client_id = 0;
    this.is_gpu_host = false;
    this.client_tracing_id = 0;
  };
  GpuService_EstablishGpuChannel_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuService_EstablishGpuChannel_Params.validate = function(messageValidator, offset) {
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




    return validator.validationError.NONE;
  };

  GpuService_EstablishGpuChannel_Params.encodedSize = codec.kStructHeaderSize + 16;

  GpuService_EstablishGpuChannel_Params.decode = function(decoder) {
    var packed;
    var val = new GpuService_EstablishGpuChannel_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client_id = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.is_gpu_host = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.client_tracing_id = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  GpuService_EstablishGpuChannel_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuService_EstablishGpuChannel_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.client_id);
    packed = 0;
    packed |= (val.is_gpu_host & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint64, val.client_tracing_id);
  };
  function GpuService_EstablishGpuChannel_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuService_EstablishGpuChannel_ResponseParams.prototype.initDefaults_ = function() {
    this.channel_handle = null;
  };
  GpuService_EstablishGpuChannel_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuService_EstablishGpuChannel_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate GpuService_EstablishGpuChannel_ResponseParams.channel_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuService_EstablishGpuChannel_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  GpuService_EstablishGpuChannel_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new GpuService_EstablishGpuChannel_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.channel_handle = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GpuService_EstablishGpuChannel_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuService_EstablishGpuChannel_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.channel_handle);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GpuService_CreateGpuMemoryBuffer_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuService_CreateGpuMemoryBuffer_Params.prototype.initDefaults_ = function() {
    this.id = null;
    this.size = null;
    this.format = 0;
    this.usage = 0;
    this.client_id = 0;
    this.surface_handle = null;
  };
  GpuService_CreateGpuMemoryBuffer_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuService_CreateGpuMemoryBuffer_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 48}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuService_CreateGpuMemoryBuffer_Params.id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, buffer_types$.GpuMemoryBufferId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuService_CreateGpuMemoryBuffer_Params.size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuService_CreateGpuMemoryBuffer_Params.format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, buffer_types$.BufferFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuService_CreateGpuMemoryBuffer_Params.usage
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 20, buffer_types$.BufferUsage);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate GpuService_CreateGpuMemoryBuffer_Params.surface_handle
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, surface_handle$.SurfaceHandle, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuService_CreateGpuMemoryBuffer_Params.encodedSize = codec.kStructHeaderSize + 40;

  GpuService_CreateGpuMemoryBuffer_Params.decode = function(decoder) {
    var packed;
    var val = new GpuService_CreateGpuMemoryBuffer_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStructPointer(buffer_types$.GpuMemoryBufferId);
    val.size = decoder.decodeStructPointer(geometry$.Size);
    val.format = decoder.decodeStruct(codec.Int32);
    val.usage = decoder.decodeStruct(codec.Int32);
    val.client_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.surface_handle = decoder.decodeStructPointer(surface_handle$.SurfaceHandle);
    return val;
  };

  GpuService_CreateGpuMemoryBuffer_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuService_CreateGpuMemoryBuffer_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(buffer_types$.GpuMemoryBufferId, val.id);
    encoder.encodeStructPointer(geometry$.Size, val.size);
    encoder.encodeStruct(codec.Int32, val.format);
    encoder.encodeStruct(codec.Int32, val.usage);
    encoder.encodeStruct(codec.Int32, val.client_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(surface_handle$.SurfaceHandle, val.surface_handle);
  };
  function GpuService_CreateGpuMemoryBuffer_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuService_CreateGpuMemoryBuffer_ResponseParams.prototype.initDefaults_ = function() {
    this.buffer_handle = null;
  };
  GpuService_CreateGpuMemoryBuffer_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuService_CreateGpuMemoryBuffer_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate GpuService_CreateGpuMemoryBuffer_ResponseParams.buffer_handle
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, buffer_types$.GpuMemoryBufferHandle, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuService_CreateGpuMemoryBuffer_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  GpuService_CreateGpuMemoryBuffer_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new GpuService_CreateGpuMemoryBuffer_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.buffer_handle = decoder.decodeStructPointer(buffer_types$.GpuMemoryBufferHandle);
    return val;
  };

  GpuService_CreateGpuMemoryBuffer_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuService_CreateGpuMemoryBuffer_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(buffer_types$.GpuMemoryBufferHandle, val.buffer_handle);
  };
  function GpuService_DestroyGpuMemoryBuffer_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuService_DestroyGpuMemoryBuffer_Params.prototype.initDefaults_ = function() {
    this.id = null;
    this.client_id = 0;
    this.sync_token = null;
  };
  GpuService_DestroyGpuMemoryBuffer_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuService_DestroyGpuMemoryBuffer_Params.validate = function(messageValidator, offset) {
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


    
    // validate GpuService_DestroyGpuMemoryBuffer_Params.id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, buffer_types$.GpuMemoryBufferId, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate GpuService_DestroyGpuMemoryBuffer_Params.sync_token
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, sync_token$.SyncToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuService_DestroyGpuMemoryBuffer_Params.encodedSize = codec.kStructHeaderSize + 24;

  GpuService_DestroyGpuMemoryBuffer_Params.decode = function(decoder) {
    var packed;
    var val = new GpuService_DestroyGpuMemoryBuffer_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStructPointer(buffer_types$.GpuMemoryBufferId);
    val.client_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.sync_token = decoder.decodeStructPointer(sync_token$.SyncToken);
    return val;
  };

  GpuService_DestroyGpuMemoryBuffer_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuService_DestroyGpuMemoryBuffer_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(buffer_types$.GpuMemoryBufferId, val.id);
    encoder.encodeStruct(codec.Int32, val.client_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(sync_token$.SyncToken, val.sync_token);
  };
  var kGpuService_EstablishGpuChannel_Name = 0;
  var kGpuService_CreateGpuMemoryBuffer_Name = 1;
  var kGpuService_DestroyGpuMemoryBuffer_Name = 2;

  function GpuServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(GpuService,
                                                   handleOrPtrInfo);
  }

  function GpuServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  GpuServicePtr.prototype.establishGpuChannel = function() {
    return GpuServiceProxy.prototype.establishGpuChannel
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuServiceProxy.prototype.establishGpuChannel = function(client_id, client_tracing_id, is_gpu_host) {
    var params = new GpuService_EstablishGpuChannel_Params();
    params.client_id = client_id;
    params.client_tracing_id = client_tracing_id;
    params.is_gpu_host = is_gpu_host;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kGpuService_EstablishGpuChannel_Name,
          codec.align(GpuService_EstablishGpuChannel_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(GpuService_EstablishGpuChannel_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(GpuService_EstablishGpuChannel_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  GpuServicePtr.prototype.createGpuMemoryBuffer = function() {
    return GpuServiceProxy.prototype.createGpuMemoryBuffer
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuServiceProxy.prototype.createGpuMemoryBuffer = function(id, size, format, usage, client_id, surface_handle) {
    var params = new GpuService_CreateGpuMemoryBuffer_Params();
    params.id = id;
    params.size = size;
    params.format = format;
    params.usage = usage;
    params.client_id = client_id;
    params.surface_handle = surface_handle;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kGpuService_CreateGpuMemoryBuffer_Name,
          codec.align(GpuService_CreateGpuMemoryBuffer_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(GpuService_CreateGpuMemoryBuffer_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(GpuService_CreateGpuMemoryBuffer_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  GpuServicePtr.prototype.destroyGpuMemoryBuffer = function() {
    return GpuServiceProxy.prototype.destroyGpuMemoryBuffer
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuServiceProxy.prototype.destroyGpuMemoryBuffer = function(id, client_id, sync_token) {
    var params = new GpuService_DestroyGpuMemoryBuffer_Params();
    params.id = id;
    params.client_id = client_id;
    params.sync_token = sync_token;
    var builder = new codec.MessageBuilder(
        kGpuService_DestroyGpuMemoryBuffer_Name,
        codec.align(GpuService_DestroyGpuMemoryBuffer_Params.encodedSize));
    builder.encodeStruct(GpuService_DestroyGpuMemoryBuffer_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function GpuServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  GpuServiceStub.prototype.establishGpuChannel = function(client_id, client_tracing_id, is_gpu_host) {
    return this.delegate_ && this.delegate_.establishGpuChannel && this.delegate_.establishGpuChannel(client_id, client_tracing_id, is_gpu_host);
  }
  GpuServiceStub.prototype.createGpuMemoryBuffer = function(id, size, format, usage, client_id, surface_handle) {
    return this.delegate_ && this.delegate_.createGpuMemoryBuffer && this.delegate_.createGpuMemoryBuffer(id, size, format, usage, client_id, surface_handle);
  }
  GpuServiceStub.prototype.destroyGpuMemoryBuffer = function(id, client_id, sync_token) {
    return this.delegate_ && this.delegate_.destroyGpuMemoryBuffer && this.delegate_.destroyGpuMemoryBuffer(id, client_id, sync_token);
  }

  GpuServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGpuService_DestroyGpuMemoryBuffer_Name:
      var params = reader.decodeStruct(GpuService_DestroyGpuMemoryBuffer_Params);
      this.destroyGpuMemoryBuffer(params.id, params.client_id, params.sync_token);
      return true;
    default:
      return false;
    }
  };

  GpuServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGpuService_EstablishGpuChannel_Name:
      var params = reader.decodeStruct(GpuService_EstablishGpuChannel_Params);
      return this.establishGpuChannel(params.client_id, params.client_tracing_id, params.is_gpu_host).then(function(response) {
        var responseParams =
            new GpuService_EstablishGpuChannel_ResponseParams();
        responseParams.channel_handle = response.channel_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kGpuService_EstablishGpuChannel_Name,
            codec.align(GpuService_EstablishGpuChannel_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(GpuService_EstablishGpuChannel_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kGpuService_CreateGpuMemoryBuffer_Name:
      var params = reader.decodeStruct(GpuService_CreateGpuMemoryBuffer_Params);
      return this.createGpuMemoryBuffer(params.id, params.size, params.format, params.usage, params.client_id, params.surface_handle).then(function(response) {
        var responseParams =
            new GpuService_CreateGpuMemoryBuffer_ResponseParams();
        responseParams.buffer_handle = response.buffer_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kGpuService_CreateGpuMemoryBuffer_Name,
            codec.align(GpuService_CreateGpuMemoryBuffer_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(GpuService_CreateGpuMemoryBuffer_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateGpuServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kGpuService_EstablishGpuChannel_Name:
        if (message.expectsResponse())
          paramsClass = GpuService_EstablishGpuChannel_Params;
      break;
      case kGpuService_CreateGpuMemoryBuffer_Name:
        if (message.expectsResponse())
          paramsClass = GpuService_CreateGpuMemoryBuffer_Params;
      break;
      case kGpuService_DestroyGpuMemoryBuffer_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuService_DestroyGpuMemoryBuffer_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateGpuServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kGpuService_EstablishGpuChannel_Name:
        if (message.isResponse())
          paramsClass = GpuService_EstablishGpuChannel_ResponseParams;
        break;
      case kGpuService_CreateGpuMemoryBuffer_Name:
        if (message.isResponse())
          paramsClass = GpuService_CreateGpuMemoryBuffer_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var GpuService = {
    name: 'ui::mojom::GpuService',
    ptrClass: GpuServicePtr,
    proxyClass: GpuServiceProxy,
    stubClass: GpuServiceStub,
    validateRequest: validateGpuServiceRequest,
    validateResponse: validateGpuServiceResponse,
  };
  GpuServiceStub.prototype.validator = validateGpuServiceRequest;
  GpuServiceProxy.prototype.validator = validateGpuServiceResponse;

  var exports = {};
  exports.GpuService = GpuService;
  exports.GpuServicePtr = GpuServicePtr;

  return exports;
});
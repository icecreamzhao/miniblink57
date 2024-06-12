// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/gpu.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "gpu/ipc/common/gpu_info.mojom",
    "gpu/ipc/common/sync_token.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/gfx/mojo/buffer_types.mojom",
], function(bindings, codec, core, validator, gpu_info$, sync_token$, geometry$, buffer_types$) {

  function Gpu_EstablishGpuChannel_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Gpu_EstablishGpuChannel_Params.prototype.initDefaults_ = function() {
  };
  Gpu_EstablishGpuChannel_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Gpu_EstablishGpuChannel_Params.validate = function(messageValidator, offset) {
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

  Gpu_EstablishGpuChannel_Params.encodedSize = codec.kStructHeaderSize + 0;

  Gpu_EstablishGpuChannel_Params.decode = function(decoder) {
    var packed;
    var val = new Gpu_EstablishGpuChannel_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Gpu_EstablishGpuChannel_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Gpu_EstablishGpuChannel_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Gpu_EstablishGpuChannel_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Gpu_EstablishGpuChannel_ResponseParams.prototype.initDefaults_ = function() {
    this.client_id = 0;
    this.channel_handle = null;
    this.gpu_info = null;
  };
  Gpu_EstablishGpuChannel_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Gpu_EstablishGpuChannel_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate Gpu_EstablishGpuChannel_ResponseParams.channel_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 4, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gpu_EstablishGpuChannel_ResponseParams.gpu_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, gpu_info$.GpuInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Gpu_EstablishGpuChannel_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Gpu_EstablishGpuChannel_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Gpu_EstablishGpuChannel_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client_id = decoder.decodeStruct(codec.Int32);
    val.channel_handle = decoder.decodeStruct(codec.NullableHandle);
    val.gpu_info = decoder.decodeStructPointer(gpu_info$.GpuInfo);
    return val;
  };

  Gpu_EstablishGpuChannel_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Gpu_EstablishGpuChannel_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.client_id);
    encoder.encodeStruct(codec.NullableHandle, val.channel_handle);
    encoder.encodeStructPointer(gpu_info$.GpuInfo, val.gpu_info);
  };
  function Gpu_CreateGpuMemoryBuffer_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Gpu_CreateGpuMemoryBuffer_Params.prototype.initDefaults_ = function() {
    this.id = null;
    this.size = null;
    this.format = 0;
    this.usage = 0;
  };
  Gpu_CreateGpuMemoryBuffer_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Gpu_CreateGpuMemoryBuffer_Params.validate = function(messageValidator, offset) {
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


    
    // validate Gpu_CreateGpuMemoryBuffer_Params.id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, buffer_types$.GpuMemoryBufferId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gpu_CreateGpuMemoryBuffer_Params.size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gpu_CreateGpuMemoryBuffer_Params.format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, buffer_types$.BufferFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gpu_CreateGpuMemoryBuffer_Params.usage
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 20, buffer_types$.BufferUsage);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Gpu_CreateGpuMemoryBuffer_Params.encodedSize = codec.kStructHeaderSize + 24;

  Gpu_CreateGpuMemoryBuffer_Params.decode = function(decoder) {
    var packed;
    var val = new Gpu_CreateGpuMemoryBuffer_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStructPointer(buffer_types$.GpuMemoryBufferId);
    val.size = decoder.decodeStructPointer(geometry$.Size);
    val.format = decoder.decodeStruct(codec.Int32);
    val.usage = decoder.decodeStruct(codec.Int32);
    return val;
  };

  Gpu_CreateGpuMemoryBuffer_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Gpu_CreateGpuMemoryBuffer_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(buffer_types$.GpuMemoryBufferId, val.id);
    encoder.encodeStructPointer(geometry$.Size, val.size);
    encoder.encodeStruct(codec.Int32, val.format);
    encoder.encodeStruct(codec.Int32, val.usage);
  };
  function Gpu_CreateGpuMemoryBuffer_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Gpu_CreateGpuMemoryBuffer_ResponseParams.prototype.initDefaults_ = function() {
    this.buffer_handle = null;
  };
  Gpu_CreateGpuMemoryBuffer_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Gpu_CreateGpuMemoryBuffer_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Gpu_CreateGpuMemoryBuffer_ResponseParams.buffer_handle
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, buffer_types$.GpuMemoryBufferHandle, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Gpu_CreateGpuMemoryBuffer_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Gpu_CreateGpuMemoryBuffer_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Gpu_CreateGpuMemoryBuffer_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.buffer_handle = decoder.decodeStructPointer(buffer_types$.GpuMemoryBufferHandle);
    return val;
  };

  Gpu_CreateGpuMemoryBuffer_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Gpu_CreateGpuMemoryBuffer_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(buffer_types$.GpuMemoryBufferHandle, val.buffer_handle);
  };
  function Gpu_DestroyGpuMemoryBuffer_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Gpu_DestroyGpuMemoryBuffer_Params.prototype.initDefaults_ = function() {
    this.id = null;
    this.sync_token = null;
  };
  Gpu_DestroyGpuMemoryBuffer_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Gpu_DestroyGpuMemoryBuffer_Params.validate = function(messageValidator, offset) {
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


    
    // validate Gpu_DestroyGpuMemoryBuffer_Params.id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, buffer_types$.GpuMemoryBufferId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Gpu_DestroyGpuMemoryBuffer_Params.sync_token
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, sync_token$.SyncToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Gpu_DestroyGpuMemoryBuffer_Params.encodedSize = codec.kStructHeaderSize + 16;

  Gpu_DestroyGpuMemoryBuffer_Params.decode = function(decoder) {
    var packed;
    var val = new Gpu_DestroyGpuMemoryBuffer_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStructPointer(buffer_types$.GpuMemoryBufferId);
    val.sync_token = decoder.decodeStructPointer(sync_token$.SyncToken);
    return val;
  };

  Gpu_DestroyGpuMemoryBuffer_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Gpu_DestroyGpuMemoryBuffer_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(buffer_types$.GpuMemoryBufferId, val.id);
    encoder.encodeStructPointer(sync_token$.SyncToken, val.sync_token);
  };
  var kGpu_EstablishGpuChannel_Name = 0;
  var kGpu_CreateGpuMemoryBuffer_Name = 1;
  var kGpu_DestroyGpuMemoryBuffer_Name = 2;

  function GpuPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Gpu,
                                                   handleOrPtrInfo);
  }

  function GpuProxy(receiver) {
    this.receiver_ = receiver;
  }
  GpuPtr.prototype.establishGpuChannel = function() {
    return GpuProxy.prototype.establishGpuChannel
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuProxy.prototype.establishGpuChannel = function() {
    var params = new Gpu_EstablishGpuChannel_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kGpu_EstablishGpuChannel_Name,
          codec.align(Gpu_EstablishGpuChannel_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Gpu_EstablishGpuChannel_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Gpu_EstablishGpuChannel_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  GpuPtr.prototype.createGpuMemoryBuffer = function() {
    return GpuProxy.prototype.createGpuMemoryBuffer
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuProxy.prototype.createGpuMemoryBuffer = function(id, size, format, usage) {
    var params = new Gpu_CreateGpuMemoryBuffer_Params();
    params.id = id;
    params.size = size;
    params.format = format;
    params.usage = usage;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kGpu_CreateGpuMemoryBuffer_Name,
          codec.align(Gpu_CreateGpuMemoryBuffer_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Gpu_CreateGpuMemoryBuffer_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Gpu_CreateGpuMemoryBuffer_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  GpuPtr.prototype.destroyGpuMemoryBuffer = function() {
    return GpuProxy.prototype.destroyGpuMemoryBuffer
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuProxy.prototype.destroyGpuMemoryBuffer = function(id, sync_token) {
    var params = new Gpu_DestroyGpuMemoryBuffer_Params();
    params.id = id;
    params.sync_token = sync_token;
    var builder = new codec.MessageBuilder(
        kGpu_DestroyGpuMemoryBuffer_Name,
        codec.align(Gpu_DestroyGpuMemoryBuffer_Params.encodedSize));
    builder.encodeStruct(Gpu_DestroyGpuMemoryBuffer_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function GpuStub(delegate) {
    this.delegate_ = delegate;
  }
  GpuStub.prototype.establishGpuChannel = function() {
    return this.delegate_ && this.delegate_.establishGpuChannel && this.delegate_.establishGpuChannel();
  }
  GpuStub.prototype.createGpuMemoryBuffer = function(id, size, format, usage) {
    return this.delegate_ && this.delegate_.createGpuMemoryBuffer && this.delegate_.createGpuMemoryBuffer(id, size, format, usage);
  }
  GpuStub.prototype.destroyGpuMemoryBuffer = function(id, sync_token) {
    return this.delegate_ && this.delegate_.destroyGpuMemoryBuffer && this.delegate_.destroyGpuMemoryBuffer(id, sync_token);
  }

  GpuStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGpu_DestroyGpuMemoryBuffer_Name:
      var params = reader.decodeStruct(Gpu_DestroyGpuMemoryBuffer_Params);
      this.destroyGpuMemoryBuffer(params.id, params.sync_token);
      return true;
    default:
      return false;
    }
  };

  GpuStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGpu_EstablishGpuChannel_Name:
      var params = reader.decodeStruct(Gpu_EstablishGpuChannel_Params);
      return this.establishGpuChannel().then(function(response) {
        var responseParams =
            new Gpu_EstablishGpuChannel_ResponseParams();
        responseParams.client_id = response.client_id;
        responseParams.channel_handle = response.channel_handle;
        responseParams.gpu_info = response.gpu_info;
        var builder = new codec.MessageWithRequestIDBuilder(
            kGpu_EstablishGpuChannel_Name,
            codec.align(Gpu_EstablishGpuChannel_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Gpu_EstablishGpuChannel_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kGpu_CreateGpuMemoryBuffer_Name:
      var params = reader.decodeStruct(Gpu_CreateGpuMemoryBuffer_Params);
      return this.createGpuMemoryBuffer(params.id, params.size, params.format, params.usage).then(function(response) {
        var responseParams =
            new Gpu_CreateGpuMemoryBuffer_ResponseParams();
        responseParams.buffer_handle = response.buffer_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kGpu_CreateGpuMemoryBuffer_Name,
            codec.align(Gpu_CreateGpuMemoryBuffer_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Gpu_CreateGpuMemoryBuffer_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateGpuRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kGpu_EstablishGpuChannel_Name:
        if (message.expectsResponse())
          paramsClass = Gpu_EstablishGpuChannel_Params;
      break;
      case kGpu_CreateGpuMemoryBuffer_Name:
        if (message.expectsResponse())
          paramsClass = Gpu_CreateGpuMemoryBuffer_Params;
      break;
      case kGpu_DestroyGpuMemoryBuffer_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Gpu_DestroyGpuMemoryBuffer_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateGpuResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kGpu_EstablishGpuChannel_Name:
        if (message.isResponse())
          paramsClass = Gpu_EstablishGpuChannel_ResponseParams;
        break;
      case kGpu_CreateGpuMemoryBuffer_Name:
        if (message.isResponse())
          paramsClass = Gpu_CreateGpuMemoryBuffer_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Gpu = {
    name: 'ui::mojom::Gpu',
    ptrClass: GpuPtr,
    proxyClass: GpuProxy,
    stubClass: GpuStub,
    validateRequest: validateGpuRequest,
    validateResponse: validateGpuResponse,
  };
  GpuStub.prototype.validator = validateGpuRequest;
  GpuProxy.prototype.validator = validateGpuResponse;

  var exports = {};
  exports.Gpu = Gpu;
  exports.GpuPtr = GpuPtr;

  return exports;
});
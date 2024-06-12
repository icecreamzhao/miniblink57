// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/gpu/interfaces/gpu_host.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "gpu/ipc/common/gpu_info.mojom",
    "gpu/ipc/common/surface_handle.mojom",
    "services/ui/gpu/interfaces/context_lost_reason.mojom",
    "url/mojo/url.mojom",
], function(bindings, codec, core, validator, gpu_info$, surface_handle$, context_lost_reason$, url$) {

  function GpuHost_DidInitialize_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuHost_DidInitialize_Params.prototype.initDefaults_ = function() {
    this.gpu_info = null;
  };
  GpuHost_DidInitialize_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuHost_DidInitialize_Params.validate = function(messageValidator, offset) {
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


    
    // validate GpuHost_DidInitialize_Params.gpu_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, gpu_info$.GpuInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuHost_DidInitialize_Params.encodedSize = codec.kStructHeaderSize + 8;

  GpuHost_DidInitialize_Params.decode = function(decoder) {
    var packed;
    var val = new GpuHost_DidInitialize_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.gpu_info = decoder.decodeStructPointer(gpu_info$.GpuInfo);
    return val;
  };

  GpuHost_DidInitialize_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuHost_DidInitialize_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(gpu_info$.GpuInfo, val.gpu_info);
  };
  function GpuHost_DidCreateOffscreenContext_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuHost_DidCreateOffscreenContext_Params.prototype.initDefaults_ = function() {
    this.url = null;
  };
  GpuHost_DidCreateOffscreenContext_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuHost_DidCreateOffscreenContext_Params.validate = function(messageValidator, offset) {
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


    
    // validate GpuHost_DidCreateOffscreenContext_Params.url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuHost_DidCreateOffscreenContext_Params.encodedSize = codec.kStructHeaderSize + 8;

  GpuHost_DidCreateOffscreenContext_Params.decode = function(decoder) {
    var packed;
    var val = new GpuHost_DidCreateOffscreenContext_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStructPointer(url$.Url);
    return val;
  };

  GpuHost_DidCreateOffscreenContext_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuHost_DidCreateOffscreenContext_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.url);
  };
  function GpuHost_DidDestroyOffscreenContext_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuHost_DidDestroyOffscreenContext_Params.prototype.initDefaults_ = function() {
    this.url = null;
  };
  GpuHost_DidDestroyOffscreenContext_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuHost_DidDestroyOffscreenContext_Params.validate = function(messageValidator, offset) {
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


    
    // validate GpuHost_DidDestroyOffscreenContext_Params.url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuHost_DidDestroyOffscreenContext_Params.encodedSize = codec.kStructHeaderSize + 8;

  GpuHost_DidDestroyOffscreenContext_Params.decode = function(decoder) {
    var packed;
    var val = new GpuHost_DidDestroyOffscreenContext_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStructPointer(url$.Url);
    return val;
  };

  GpuHost_DidDestroyOffscreenContext_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuHost_DidDestroyOffscreenContext_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.url);
  };
  function GpuHost_DidDestroyChannel_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuHost_DidDestroyChannel_Params.prototype.initDefaults_ = function() {
    this.client_id = 0;
  };
  GpuHost_DidDestroyChannel_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuHost_DidDestroyChannel_Params.validate = function(messageValidator, offset) {
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

  GpuHost_DidDestroyChannel_Params.encodedSize = codec.kStructHeaderSize + 8;

  GpuHost_DidDestroyChannel_Params.decode = function(decoder) {
    var packed;
    var val = new GpuHost_DidDestroyChannel_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GpuHost_DidDestroyChannel_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuHost_DidDestroyChannel_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.client_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GpuHost_DidLoseContext_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuHost_DidLoseContext_Params.prototype.initDefaults_ = function() {
    this.offscreen = false;
    this.reason = 0;
    this.active_url = null;
  };
  GpuHost_DidLoseContext_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuHost_DidLoseContext_Params.validate = function(messageValidator, offset) {
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



    
    // validate GpuHost_DidLoseContext_Params.reason
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, context_lost_reason$.ContextLostReason);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuHost_DidLoseContext_Params.active_url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuHost_DidLoseContext_Params.encodedSize = codec.kStructHeaderSize + 16;

  GpuHost_DidLoseContext_Params.decode = function(decoder) {
    var packed;
    var val = new GpuHost_DidLoseContext_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.offscreen = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.reason = decoder.decodeStruct(codec.Int32);
    val.active_url = decoder.decodeStructPointer(url$.Url);
    return val;
  };

  GpuHost_DidLoseContext_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuHost_DidLoseContext_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.offscreen & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.reason);
    encoder.encodeStructPointer(url$.Url, val.active_url);
  };
  function GpuHost_SetChildSurface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuHost_SetChildSurface_Params.prototype.initDefaults_ = function() {
    this.parent = null;
    this.child = null;
  };
  GpuHost_SetChildSurface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuHost_SetChildSurface_Params.validate = function(messageValidator, offset) {
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


    
    // validate GpuHost_SetChildSurface_Params.parent
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_handle$.SurfaceHandle, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuHost_SetChildSurface_Params.child
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, surface_handle$.SurfaceHandle, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuHost_SetChildSurface_Params.encodedSize = codec.kStructHeaderSize + 16;

  GpuHost_SetChildSurface_Params.decode = function(decoder) {
    var packed;
    var val = new GpuHost_SetChildSurface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.parent = decoder.decodeStructPointer(surface_handle$.SurfaceHandle);
    val.child = decoder.decodeStructPointer(surface_handle$.SurfaceHandle);
    return val;
  };

  GpuHost_SetChildSurface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuHost_SetChildSurface_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_handle$.SurfaceHandle, val.parent);
    encoder.encodeStructPointer(surface_handle$.SurfaceHandle, val.child);
  };
  function GpuHost_StoreShaderToDisk_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuHost_StoreShaderToDisk_Params.prototype.initDefaults_ = function() {
    this.client_id = 0;
    this.key = null;
    this.shader = null;
  };
  GpuHost_StoreShaderToDisk_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuHost_StoreShaderToDisk_Params.validate = function(messageValidator, offset) {
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



    
    // validate GpuHost_StoreShaderToDisk_Params.key
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuHost_StoreShaderToDisk_Params.shader
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuHost_StoreShaderToDisk_Params.encodedSize = codec.kStructHeaderSize + 24;

  GpuHost_StoreShaderToDisk_Params.decode = function(decoder) {
    var packed;
    var val = new GpuHost_StoreShaderToDisk_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.key = decoder.decodeStruct(codec.String);
    val.shader = decoder.decodeStruct(codec.String);
    return val;
  };

  GpuHost_StoreShaderToDisk_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuHost_StoreShaderToDisk_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.client_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.key);
    encoder.encodeStruct(codec.String, val.shader);
  };
  var kGpuHost_DidInitialize_Name = 0;
  var kGpuHost_DidCreateOffscreenContext_Name = 1;
  var kGpuHost_DidDestroyOffscreenContext_Name = 2;
  var kGpuHost_DidDestroyChannel_Name = 3;
  var kGpuHost_DidLoseContext_Name = 4;
  var kGpuHost_SetChildSurface_Name = 5;
  var kGpuHost_StoreShaderToDisk_Name = 6;

  function GpuHostPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(GpuHost,
                                                   handleOrPtrInfo);
  }

  function GpuHostProxy(receiver) {
    this.receiver_ = receiver;
  }
  GpuHostPtr.prototype.didInitialize = function() {
    return GpuHostProxy.prototype.didInitialize
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuHostProxy.prototype.didInitialize = function(gpu_info) {
    var params = new GpuHost_DidInitialize_Params();
    params.gpu_info = gpu_info;
    var builder = new codec.MessageBuilder(
        kGpuHost_DidInitialize_Name,
        codec.align(GpuHost_DidInitialize_Params.encodedSize));
    builder.encodeStruct(GpuHost_DidInitialize_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GpuHostPtr.prototype.didCreateOffscreenContext = function() {
    return GpuHostProxy.prototype.didCreateOffscreenContext
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuHostProxy.prototype.didCreateOffscreenContext = function(url) {
    var params = new GpuHost_DidCreateOffscreenContext_Params();
    params.url = url;
    var builder = new codec.MessageBuilder(
        kGpuHost_DidCreateOffscreenContext_Name,
        codec.align(GpuHost_DidCreateOffscreenContext_Params.encodedSize));
    builder.encodeStruct(GpuHost_DidCreateOffscreenContext_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GpuHostPtr.prototype.didDestroyOffscreenContext = function() {
    return GpuHostProxy.prototype.didDestroyOffscreenContext
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuHostProxy.prototype.didDestroyOffscreenContext = function(url) {
    var params = new GpuHost_DidDestroyOffscreenContext_Params();
    params.url = url;
    var builder = new codec.MessageBuilder(
        kGpuHost_DidDestroyOffscreenContext_Name,
        codec.align(GpuHost_DidDestroyOffscreenContext_Params.encodedSize));
    builder.encodeStruct(GpuHost_DidDestroyOffscreenContext_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GpuHostPtr.prototype.didDestroyChannel = function() {
    return GpuHostProxy.prototype.didDestroyChannel
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuHostProxy.prototype.didDestroyChannel = function(client_id) {
    var params = new GpuHost_DidDestroyChannel_Params();
    params.client_id = client_id;
    var builder = new codec.MessageBuilder(
        kGpuHost_DidDestroyChannel_Name,
        codec.align(GpuHost_DidDestroyChannel_Params.encodedSize));
    builder.encodeStruct(GpuHost_DidDestroyChannel_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GpuHostPtr.prototype.didLoseContext = function() {
    return GpuHostProxy.prototype.didLoseContext
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuHostProxy.prototype.didLoseContext = function(offscreen, reason, active_url) {
    var params = new GpuHost_DidLoseContext_Params();
    params.offscreen = offscreen;
    params.reason = reason;
    params.active_url = active_url;
    var builder = new codec.MessageBuilder(
        kGpuHost_DidLoseContext_Name,
        codec.align(GpuHost_DidLoseContext_Params.encodedSize));
    builder.encodeStruct(GpuHost_DidLoseContext_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GpuHostPtr.prototype.setChildSurface = function() {
    return GpuHostProxy.prototype.setChildSurface
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuHostProxy.prototype.setChildSurface = function(parent, child) {
    var params = new GpuHost_SetChildSurface_Params();
    params.parent = parent;
    params.child = child;
    var builder = new codec.MessageBuilder(
        kGpuHost_SetChildSurface_Name,
        codec.align(GpuHost_SetChildSurface_Params.encodedSize));
    builder.encodeStruct(GpuHost_SetChildSurface_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GpuHostPtr.prototype.storeShaderToDisk = function() {
    return GpuHostProxy.prototype.storeShaderToDisk
        .apply(this.ptr.getProxy(), arguments);
  };

  GpuHostProxy.prototype.storeShaderToDisk = function(client_id, key, shader) {
    var params = new GpuHost_StoreShaderToDisk_Params();
    params.client_id = client_id;
    params.key = key;
    params.shader = shader;
    var builder = new codec.MessageBuilder(
        kGpuHost_StoreShaderToDisk_Name,
        codec.align(GpuHost_StoreShaderToDisk_Params.encodedSize));
    builder.encodeStruct(GpuHost_StoreShaderToDisk_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function GpuHostStub(delegate) {
    this.delegate_ = delegate;
  }
  GpuHostStub.prototype.didInitialize = function(gpu_info) {
    return this.delegate_ && this.delegate_.didInitialize && this.delegate_.didInitialize(gpu_info);
  }
  GpuHostStub.prototype.didCreateOffscreenContext = function(url) {
    return this.delegate_ && this.delegate_.didCreateOffscreenContext && this.delegate_.didCreateOffscreenContext(url);
  }
  GpuHostStub.prototype.didDestroyOffscreenContext = function(url) {
    return this.delegate_ && this.delegate_.didDestroyOffscreenContext && this.delegate_.didDestroyOffscreenContext(url);
  }
  GpuHostStub.prototype.didDestroyChannel = function(client_id) {
    return this.delegate_ && this.delegate_.didDestroyChannel && this.delegate_.didDestroyChannel(client_id);
  }
  GpuHostStub.prototype.didLoseContext = function(offscreen, reason, active_url) {
    return this.delegate_ && this.delegate_.didLoseContext && this.delegate_.didLoseContext(offscreen, reason, active_url);
  }
  GpuHostStub.prototype.setChildSurface = function(parent, child) {
    return this.delegate_ && this.delegate_.setChildSurface && this.delegate_.setChildSurface(parent, child);
  }
  GpuHostStub.prototype.storeShaderToDisk = function(client_id, key, shader) {
    return this.delegate_ && this.delegate_.storeShaderToDisk && this.delegate_.storeShaderToDisk(client_id, key, shader);
  }

  GpuHostStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGpuHost_DidInitialize_Name:
      var params = reader.decodeStruct(GpuHost_DidInitialize_Params);
      this.didInitialize(params.gpu_info);
      return true;
    case kGpuHost_DidCreateOffscreenContext_Name:
      var params = reader.decodeStruct(GpuHost_DidCreateOffscreenContext_Params);
      this.didCreateOffscreenContext(params.url);
      return true;
    case kGpuHost_DidDestroyOffscreenContext_Name:
      var params = reader.decodeStruct(GpuHost_DidDestroyOffscreenContext_Params);
      this.didDestroyOffscreenContext(params.url);
      return true;
    case kGpuHost_DidDestroyChannel_Name:
      var params = reader.decodeStruct(GpuHost_DidDestroyChannel_Params);
      this.didDestroyChannel(params.client_id);
      return true;
    case kGpuHost_DidLoseContext_Name:
      var params = reader.decodeStruct(GpuHost_DidLoseContext_Params);
      this.didLoseContext(params.offscreen, params.reason, params.active_url);
      return true;
    case kGpuHost_SetChildSurface_Name:
      var params = reader.decodeStruct(GpuHost_SetChildSurface_Params);
      this.setChildSurface(params.parent, params.child);
      return true;
    case kGpuHost_StoreShaderToDisk_Name:
      var params = reader.decodeStruct(GpuHost_StoreShaderToDisk_Params);
      this.storeShaderToDisk(params.client_id, params.key, params.shader);
      return true;
    default:
      return false;
    }
  };

  GpuHostStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateGpuHostRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kGpuHost_DidInitialize_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuHost_DidInitialize_Params;
      break;
      case kGpuHost_DidCreateOffscreenContext_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuHost_DidCreateOffscreenContext_Params;
      break;
      case kGpuHost_DidDestroyOffscreenContext_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuHost_DidDestroyOffscreenContext_Params;
      break;
      case kGpuHost_DidDestroyChannel_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuHost_DidDestroyChannel_Params;
      break;
      case kGpuHost_DidLoseContext_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuHost_DidLoseContext_Params;
      break;
      case kGpuHost_SetChildSurface_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuHost_SetChildSurface_Params;
      break;
      case kGpuHost_StoreShaderToDisk_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GpuHost_StoreShaderToDisk_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateGpuHostResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var GpuHost = {
    name: 'ui::mojom::GpuHost',
    ptrClass: GpuHostPtr,
    proxyClass: GpuHostProxy,
    stubClass: GpuHostStub,
    validateRequest: validateGpuHostRequest,
    validateResponse: null,
  };
  GpuHostStub.prototype.validator = validateGpuHostRequest;
  GpuHostProxy.prototype.validator = null;

  var exports = {};
  exports.GpuHost = GpuHost;
  exports.GpuHostPtr = GpuHostPtr;

  return exports;
});
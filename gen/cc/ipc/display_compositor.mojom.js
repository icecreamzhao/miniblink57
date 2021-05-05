// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/display_compositor.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/frame_sink_id.mojom",
    "cc/ipc/mojo_compositor_frame_sink.mojom",
    "cc/ipc/surface_id.mojom",
    "cc/ipc/surface_info.mojom",
    "gpu/ipc/common/surface_handle.mojom",
    "mojo/common/time.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/gfx/mojo/color_space.mojom",
], function(bindings, codec, core, validator, frame_sink_id$, mojo_compositor_frame_sink$, surface_id$, surface_info$, surface_handle$, time$, geometry$, color_space$) {

  function DisplayPrivate_SetDisplayVisible_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayPrivate_SetDisplayVisible_Params.prototype.initDefaults_ = function() {
    this.visible = false;
  };
  DisplayPrivate_SetDisplayVisible_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayPrivate_SetDisplayVisible_Params.validate = function(messageValidator, offset) {
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

  DisplayPrivate_SetDisplayVisible_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayPrivate_SetDisplayVisible_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayPrivate_SetDisplayVisible_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.visible = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  DisplayPrivate_SetDisplayVisible_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayPrivate_SetDisplayVisible_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.visible & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function DisplayPrivate_ResizeDisplay_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayPrivate_ResizeDisplay_Params.prototype.initDefaults_ = function() {
    this.size_in_pixel = null;
  };
  DisplayPrivate_ResizeDisplay_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayPrivate_ResizeDisplay_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayPrivate_ResizeDisplay_Params.size_in_pixel
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayPrivate_ResizeDisplay_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayPrivate_ResizeDisplay_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayPrivate_ResizeDisplay_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.size_in_pixel = decoder.decodeStructPointer(geometry$.Size);
    return val;
  };

  DisplayPrivate_ResizeDisplay_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayPrivate_ResizeDisplay_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.Size, val.size_in_pixel);
  };
  function DisplayPrivate_SetDisplayColorSpace_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayPrivate_SetDisplayColorSpace_Params.prototype.initDefaults_ = function() {
    this.color_space = null;
  };
  DisplayPrivate_SetDisplayColorSpace_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayPrivate_SetDisplayColorSpace_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayPrivate_SetDisplayColorSpace_Params.color_space
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, color_space$.ColorSpace, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayPrivate_SetDisplayColorSpace_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayPrivate_SetDisplayColorSpace_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayPrivate_SetDisplayColorSpace_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.color_space = decoder.decodeStructPointer(color_space$.ColorSpace);
    return val;
  };

  DisplayPrivate_SetDisplayColorSpace_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayPrivate_SetDisplayColorSpace_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(color_space$.ColorSpace, val.color_space);
  };
  function DisplayPrivate_SetOutputIsSecure_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayPrivate_SetOutputIsSecure_Params.prototype.initDefaults_ = function() {
    this.secure = false;
  };
  DisplayPrivate_SetOutputIsSecure_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayPrivate_SetOutputIsSecure_Params.validate = function(messageValidator, offset) {
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

  DisplayPrivate_SetOutputIsSecure_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayPrivate_SetOutputIsSecure_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayPrivate_SetOutputIsSecure_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.secure = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  DisplayPrivate_SetOutputIsSecure_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayPrivate_SetOutputIsSecure_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.secure & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function DisplayCompositor_CreateDisplayCompositorFrameSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayCompositor_CreateDisplayCompositorFrameSink_Params.prototype.initDefaults_ = function() {
    this.frame_sink_id = null;
    this.widget = null;
    this.compositor_frame_sink = new bindings.InterfaceRequest();
    this.compositor_frame_sink_private = new bindings.InterfaceRequest();
    this.compositor_frame_sink_client = new mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr();
    this.display_private = new bindings.InterfaceRequest();
  };
  DisplayCompositor_CreateDisplayCompositorFrameSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayCompositor_CreateDisplayCompositorFrameSink_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayCompositor_CreateDisplayCompositorFrameSink_Params.frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateDisplayCompositorFrameSink_Params.widget
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, surface_handle$.SurfaceHandle, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateDisplayCompositorFrameSink_Params.compositor_frame_sink
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateDisplayCompositorFrameSink_Params.compositor_frame_sink_private
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 20, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateDisplayCompositorFrameSink_Params.compositor_frame_sink_client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 24, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateDisplayCompositorFrameSink_Params.display_private
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayCompositor_CreateDisplayCompositorFrameSink_Params.encodedSize = codec.kStructHeaderSize + 40;

  DisplayCompositor_CreateDisplayCompositorFrameSink_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayCompositor_CreateDisplayCompositorFrameSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    val.widget = decoder.decodeStructPointer(surface_handle$.SurfaceHandle);
    val.compositor_frame_sink = decoder.decodeStruct(codec.InterfaceRequest);
    val.compositor_frame_sink_private = decoder.decodeStruct(codec.InterfaceRequest);
    val.compositor_frame_sink_client = decoder.decodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr));
    val.display_private = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  DisplayCompositor_CreateDisplayCompositorFrameSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayCompositor_CreateDisplayCompositorFrameSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.frame_sink_id);
    encoder.encodeStructPointer(surface_handle$.SurfaceHandle, val.widget);
    encoder.encodeStruct(codec.InterfaceRequest, val.compositor_frame_sink);
    encoder.encodeStruct(codec.InterfaceRequest, val.compositor_frame_sink_private);
    encoder.encodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr), val.compositor_frame_sink_client);
    encoder.encodeStruct(codec.InterfaceRequest, val.display_private);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function DisplayCompositor_CreateOffscreenCompositorFrameSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.prototype.initDefaults_ = function() {
    this.frame_sink_id = null;
    this.compositor_frame_sink = new bindings.InterfaceRequest();
    this.compositor_frame_sink_private = new bindings.InterfaceRequest();
    this.compositor_frame_sink_client = new mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr();
  };
  DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.compositor_frame_sink
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.compositor_frame_sink_private
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 12, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.compositor_frame_sink_client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.encodedSize = codec.kStructHeaderSize + 24;

  DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayCompositor_CreateOffscreenCompositorFrameSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    val.compositor_frame_sink = decoder.decodeStruct(codec.InterfaceRequest);
    val.compositor_frame_sink_private = decoder.decodeStruct(codec.InterfaceRequest);
    val.compositor_frame_sink_client = decoder.decodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr));
    return val;
  };

  DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.frame_sink_id);
    encoder.encodeStruct(codec.InterfaceRequest, val.compositor_frame_sink);
    encoder.encodeStruct(codec.InterfaceRequest, val.compositor_frame_sink_private);
    encoder.encodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr), val.compositor_frame_sink_client);
  };
  function DisplayCompositorClient_OnSurfaceCreated_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayCompositorClient_OnSurfaceCreated_Params.prototype.initDefaults_ = function() {
    this.surface_info = null;
  };
  DisplayCompositorClient_OnSurfaceCreated_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayCompositorClient_OnSurfaceCreated_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayCompositorClient_OnSurfaceCreated_Params.surface_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_info$.SurfaceInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayCompositorClient_OnSurfaceCreated_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayCompositorClient_OnSurfaceCreated_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayCompositorClient_OnSurfaceCreated_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.surface_info = decoder.decodeStructPointer(surface_info$.SurfaceInfo);
    return val;
  };

  DisplayCompositorClient_OnSurfaceCreated_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayCompositorClient_OnSurfaceCreated_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_info$.SurfaceInfo, val.surface_info);
  };
  var kDisplayPrivate_SetDisplayVisible_Name = 0;
  var kDisplayPrivate_ResizeDisplay_Name = 1;
  var kDisplayPrivate_SetDisplayColorSpace_Name = 2;
  var kDisplayPrivate_SetOutputIsSecure_Name = 3;

  function DisplayPrivatePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DisplayPrivate,
                                                   handleOrPtrInfo);
  }

  function DisplayPrivateProxy(receiver) {
    this.receiver_ = receiver;
  }
  DisplayPrivatePtr.prototype.setDisplayVisible = function() {
    return DisplayPrivateProxy.prototype.setDisplayVisible
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayPrivateProxy.prototype.setDisplayVisible = function(visible) {
    var params = new DisplayPrivate_SetDisplayVisible_Params();
    params.visible = visible;
    var builder = new codec.MessageBuilder(
        kDisplayPrivate_SetDisplayVisible_Name,
        codec.align(DisplayPrivate_SetDisplayVisible_Params.encodedSize));
    builder.encodeStruct(DisplayPrivate_SetDisplayVisible_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayPrivatePtr.prototype.resizeDisplay = function() {
    return DisplayPrivateProxy.prototype.resizeDisplay
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayPrivateProxy.prototype.resizeDisplay = function(size_in_pixel) {
    var params = new DisplayPrivate_ResizeDisplay_Params();
    params.size_in_pixel = size_in_pixel;
    var builder = new codec.MessageBuilder(
        kDisplayPrivate_ResizeDisplay_Name,
        codec.align(DisplayPrivate_ResizeDisplay_Params.encodedSize));
    builder.encodeStruct(DisplayPrivate_ResizeDisplay_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayPrivatePtr.prototype.setDisplayColorSpace = function() {
    return DisplayPrivateProxy.prototype.setDisplayColorSpace
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayPrivateProxy.prototype.setDisplayColorSpace = function(color_space) {
    var params = new DisplayPrivate_SetDisplayColorSpace_Params();
    params.color_space = color_space;
    var builder = new codec.MessageBuilder(
        kDisplayPrivate_SetDisplayColorSpace_Name,
        codec.align(DisplayPrivate_SetDisplayColorSpace_Params.encodedSize));
    builder.encodeStruct(DisplayPrivate_SetDisplayColorSpace_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayPrivatePtr.prototype.setOutputIsSecure = function() {
    return DisplayPrivateProxy.prototype.setOutputIsSecure
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayPrivateProxy.prototype.setOutputIsSecure = function(secure) {
    var params = new DisplayPrivate_SetOutputIsSecure_Params();
    params.secure = secure;
    var builder = new codec.MessageBuilder(
        kDisplayPrivate_SetOutputIsSecure_Name,
        codec.align(DisplayPrivate_SetOutputIsSecure_Params.encodedSize));
    builder.encodeStruct(DisplayPrivate_SetOutputIsSecure_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DisplayPrivateStub(delegate) {
    this.delegate_ = delegate;
  }
  DisplayPrivateStub.prototype.setDisplayVisible = function(visible) {
    return this.delegate_ && this.delegate_.setDisplayVisible && this.delegate_.setDisplayVisible(visible);
  }
  DisplayPrivateStub.prototype.resizeDisplay = function(size_in_pixel) {
    return this.delegate_ && this.delegate_.resizeDisplay && this.delegate_.resizeDisplay(size_in_pixel);
  }
  DisplayPrivateStub.prototype.setDisplayColorSpace = function(color_space) {
    return this.delegate_ && this.delegate_.setDisplayColorSpace && this.delegate_.setDisplayColorSpace(color_space);
  }
  DisplayPrivateStub.prototype.setOutputIsSecure = function(secure) {
    return this.delegate_ && this.delegate_.setOutputIsSecure && this.delegate_.setOutputIsSecure(secure);
  }

  DisplayPrivateStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDisplayPrivate_SetDisplayVisible_Name:
      var params = reader.decodeStruct(DisplayPrivate_SetDisplayVisible_Params);
      this.setDisplayVisible(params.visible);
      return true;
    case kDisplayPrivate_ResizeDisplay_Name:
      var params = reader.decodeStruct(DisplayPrivate_ResizeDisplay_Params);
      this.resizeDisplay(params.size_in_pixel);
      return true;
    case kDisplayPrivate_SetDisplayColorSpace_Name:
      var params = reader.decodeStruct(DisplayPrivate_SetDisplayColorSpace_Params);
      this.setDisplayColorSpace(params.color_space);
      return true;
    case kDisplayPrivate_SetOutputIsSecure_Name:
      var params = reader.decodeStruct(DisplayPrivate_SetOutputIsSecure_Params);
      this.setOutputIsSecure(params.secure);
      return true;
    default:
      return false;
    }
  };

  DisplayPrivateStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDisplayPrivateRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDisplayPrivate_SetDisplayVisible_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayPrivate_SetDisplayVisible_Params;
      break;
      case kDisplayPrivate_ResizeDisplay_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayPrivate_ResizeDisplay_Params;
      break;
      case kDisplayPrivate_SetDisplayColorSpace_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayPrivate_SetDisplayColorSpace_Params;
      break;
      case kDisplayPrivate_SetOutputIsSecure_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayPrivate_SetOutputIsSecure_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDisplayPrivateResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var DisplayPrivate = {
    name: 'cc::mojom::DisplayPrivate',
    ptrClass: DisplayPrivatePtr,
    proxyClass: DisplayPrivateProxy,
    stubClass: DisplayPrivateStub,
    validateRequest: validateDisplayPrivateRequest,
    validateResponse: null,
  };
  DisplayPrivateStub.prototype.validator = validateDisplayPrivateRequest;
  DisplayPrivateProxy.prototype.validator = null;
  var kDisplayCompositor_CreateDisplayCompositorFrameSink_Name = 0;
  var kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name = 1;

  function DisplayCompositorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DisplayCompositor,
                                                   handleOrPtrInfo);
  }

  function DisplayCompositorProxy(receiver) {
    this.receiver_ = receiver;
  }
  DisplayCompositorPtr.prototype.createDisplayCompositorFrameSink = function() {
    return DisplayCompositorProxy.prototype.createDisplayCompositorFrameSink
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayCompositorProxy.prototype.createDisplayCompositorFrameSink = function(frame_sink_id, widget, compositor_frame_sink, compositor_frame_sink_private, compositor_frame_sink_client, display_private) {
    var params = new DisplayCompositor_CreateDisplayCompositorFrameSink_Params();
    params.frame_sink_id = frame_sink_id;
    params.widget = widget;
    params.compositor_frame_sink = compositor_frame_sink;
    params.compositor_frame_sink_private = compositor_frame_sink_private;
    params.compositor_frame_sink_client = compositor_frame_sink_client;
    params.display_private = display_private;
    var builder = new codec.MessageBuilder(
        kDisplayCompositor_CreateDisplayCompositorFrameSink_Name,
        codec.align(DisplayCompositor_CreateDisplayCompositorFrameSink_Params.encodedSize));
    builder.encodeStruct(DisplayCompositor_CreateDisplayCompositorFrameSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayCompositorPtr.prototype.createOffscreenCompositorFrameSink = function() {
    return DisplayCompositorProxy.prototype.createOffscreenCompositorFrameSink
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayCompositorProxy.prototype.createOffscreenCompositorFrameSink = function(frame_sink_id, compositor_frame_sink, compositor_frame_sink_private, compositor_frame_sink_client) {
    var params = new DisplayCompositor_CreateOffscreenCompositorFrameSink_Params();
    params.frame_sink_id = frame_sink_id;
    params.compositor_frame_sink = compositor_frame_sink;
    params.compositor_frame_sink_private = compositor_frame_sink_private;
    params.compositor_frame_sink_client = compositor_frame_sink_client;
    var builder = new codec.MessageBuilder(
        kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name,
        codec.align(DisplayCompositor_CreateOffscreenCompositorFrameSink_Params.encodedSize));
    builder.encodeStruct(DisplayCompositor_CreateOffscreenCompositorFrameSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DisplayCompositorStub(delegate) {
    this.delegate_ = delegate;
  }
  DisplayCompositorStub.prototype.createDisplayCompositorFrameSink = function(frame_sink_id, widget, compositor_frame_sink, compositor_frame_sink_private, compositor_frame_sink_client, display_private) {
    return this.delegate_ && this.delegate_.createDisplayCompositorFrameSink && this.delegate_.createDisplayCompositorFrameSink(frame_sink_id, widget, compositor_frame_sink, compositor_frame_sink_private, compositor_frame_sink_client, display_private);
  }
  DisplayCompositorStub.prototype.createOffscreenCompositorFrameSink = function(frame_sink_id, compositor_frame_sink, compositor_frame_sink_private, compositor_frame_sink_client) {
    return this.delegate_ && this.delegate_.createOffscreenCompositorFrameSink && this.delegate_.createOffscreenCompositorFrameSink(frame_sink_id, compositor_frame_sink, compositor_frame_sink_private, compositor_frame_sink_client);
  }

  DisplayCompositorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDisplayCompositor_CreateDisplayCompositorFrameSink_Name:
      var params = reader.decodeStruct(DisplayCompositor_CreateDisplayCompositorFrameSink_Params);
      this.createDisplayCompositorFrameSink(params.frame_sink_id, params.widget, params.compositor_frame_sink, params.compositor_frame_sink_private, params.compositor_frame_sink_client, params.display_private);
      return true;
    case kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name:
      var params = reader.decodeStruct(DisplayCompositor_CreateOffscreenCompositorFrameSink_Params);
      this.createOffscreenCompositorFrameSink(params.frame_sink_id, params.compositor_frame_sink, params.compositor_frame_sink_private, params.compositor_frame_sink_client);
      return true;
    default:
      return false;
    }
  };

  DisplayCompositorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDisplayCompositorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDisplayCompositor_CreateDisplayCompositorFrameSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayCompositor_CreateDisplayCompositorFrameSink_Params;
      break;
      case kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayCompositor_CreateOffscreenCompositorFrameSink_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDisplayCompositorResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var DisplayCompositor = {
    name: 'cc::mojom::DisplayCompositor',
    ptrClass: DisplayCompositorPtr,
    proxyClass: DisplayCompositorProxy,
    stubClass: DisplayCompositorStub,
    validateRequest: validateDisplayCompositorRequest,
    validateResponse: null,
  };
  DisplayCompositorStub.prototype.validator = validateDisplayCompositorRequest;
  DisplayCompositorProxy.prototype.validator = null;
  var kDisplayCompositorClient_OnSurfaceCreated_Name = 0;

  function DisplayCompositorClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DisplayCompositorClient,
                                                   handleOrPtrInfo);
  }

  function DisplayCompositorClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  DisplayCompositorClientPtr.prototype.onSurfaceCreated = function() {
    return DisplayCompositorClientProxy.prototype.onSurfaceCreated
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayCompositorClientProxy.prototype.onSurfaceCreated = function(surface_info) {
    var params = new DisplayCompositorClient_OnSurfaceCreated_Params();
    params.surface_info = surface_info;
    var builder = new codec.MessageBuilder(
        kDisplayCompositorClient_OnSurfaceCreated_Name,
        codec.align(DisplayCompositorClient_OnSurfaceCreated_Params.encodedSize));
    builder.encodeStruct(DisplayCompositorClient_OnSurfaceCreated_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DisplayCompositorClientStub(delegate) {
    this.delegate_ = delegate;
  }
  DisplayCompositorClientStub.prototype.onSurfaceCreated = function(surface_info) {
    return this.delegate_ && this.delegate_.onSurfaceCreated && this.delegate_.onSurfaceCreated(surface_info);
  }

  DisplayCompositorClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDisplayCompositorClient_OnSurfaceCreated_Name:
      var params = reader.decodeStruct(DisplayCompositorClient_OnSurfaceCreated_Params);
      this.onSurfaceCreated(params.surface_info);
      return true;
    default:
      return false;
    }
  };

  DisplayCompositorClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDisplayCompositorClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDisplayCompositorClient_OnSurfaceCreated_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayCompositorClient_OnSurfaceCreated_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDisplayCompositorClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var DisplayCompositorClient = {
    name: 'cc::mojom::DisplayCompositorClient',
    ptrClass: DisplayCompositorClientPtr,
    proxyClass: DisplayCompositorClientProxy,
    stubClass: DisplayCompositorClientStub,
    validateRequest: validateDisplayCompositorClientRequest,
    validateResponse: null,
  };
  DisplayCompositorClientStub.prototype.validator = validateDisplayCompositorClientRequest;
  DisplayCompositorClientProxy.prototype.validator = null;

  var exports = {};
  exports.DisplayPrivate = DisplayPrivate;
  exports.DisplayPrivatePtr = DisplayPrivatePtr;
  exports.DisplayCompositor = DisplayCompositor;
  exports.DisplayCompositorPtr = DisplayCompositorPtr;
  exports.DisplayCompositorClient = DisplayCompositorClient;
  exports.DisplayCompositorClientPtr = DisplayCompositorClientPtr;

  return exports;
});
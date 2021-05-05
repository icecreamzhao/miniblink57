// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/mojo_compositor_frame_sink.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/begin_frame_args.mojom",
    "cc/ipc/compositor_frame.mojom",
    "cc/ipc/frame_sink_id.mojom",
    "cc/ipc/local_frame_id.mojom",
    "cc/ipc/surface_reference.mojom",
    "cc/ipc/returned_resource.mojom",
    "cc/ipc/surface_sequence.mojom",
], function(bindings, codec, core, validator, begin_frame_args$, compositor_frame$, frame_sink_id$, local_frame_id$, surface_reference$, returned_resource$, surface_sequence$) {

  function MojoCompositorFrameSink_SetNeedsBeginFrame_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSink_SetNeedsBeginFrame_Params.prototype.initDefaults_ = function() {
    this.needs_begin_frame = false;
  };
  MojoCompositorFrameSink_SetNeedsBeginFrame_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSink_SetNeedsBeginFrame_Params.validate = function(messageValidator, offset) {
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

  MojoCompositorFrameSink_SetNeedsBeginFrame_Params.encodedSize = codec.kStructHeaderSize + 8;

  MojoCompositorFrameSink_SetNeedsBeginFrame_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSink_SetNeedsBeginFrame_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.needs_begin_frame = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  MojoCompositorFrameSink_SetNeedsBeginFrame_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSink_SetNeedsBeginFrame_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.needs_begin_frame & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function MojoCompositorFrameSink_SubmitCompositorFrame_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSink_SubmitCompositorFrame_Params.prototype.initDefaults_ = function() {
    this.local_frame_id = null;
    this.frame = null;
  };
  MojoCompositorFrameSink_SubmitCompositorFrame_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSink_SubmitCompositorFrame_Params.validate = function(messageValidator, offset) {
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


    
    // validate MojoCompositorFrameSink_SubmitCompositorFrame_Params.local_frame_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, local_frame_id$.LocalFrameId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate MojoCompositorFrameSink_SubmitCompositorFrame_Params.frame
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, compositor_frame$.CompositorFrame, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MojoCompositorFrameSink_SubmitCompositorFrame_Params.encodedSize = codec.kStructHeaderSize + 16;

  MojoCompositorFrameSink_SubmitCompositorFrame_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSink_SubmitCompositorFrame_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.local_frame_id = decoder.decodeStructPointer(local_frame_id$.LocalFrameId);
    val.frame = decoder.decodeStructPointer(compositor_frame$.CompositorFrame);
    return val;
  };

  MojoCompositorFrameSink_SubmitCompositorFrame_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSink_SubmitCompositorFrame_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(local_frame_id$.LocalFrameId, val.local_frame_id);
    encoder.encodeStructPointer(compositor_frame$.CompositorFrame, val.frame);
  };
  function MojoCompositorFrameSink_EvictFrame_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSink_EvictFrame_Params.prototype.initDefaults_ = function() {
  };
  MojoCompositorFrameSink_EvictFrame_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSink_EvictFrame_Params.validate = function(messageValidator, offset) {
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

  MojoCompositorFrameSink_EvictFrame_Params.encodedSize = codec.kStructHeaderSize + 0;

  MojoCompositorFrameSink_EvictFrame_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSink_EvictFrame_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  MojoCompositorFrameSink_EvictFrame_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSink_EvictFrame_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function MojoCompositorFrameSink_Require_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSink_Require_Params.prototype.initDefaults_ = function() {
    this.local_frame_id = null;
    this.sequence = null;
  };
  MojoCompositorFrameSink_Require_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSink_Require_Params.validate = function(messageValidator, offset) {
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


    
    // validate MojoCompositorFrameSink_Require_Params.local_frame_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, local_frame_id$.LocalFrameId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate MojoCompositorFrameSink_Require_Params.sequence
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, surface_sequence$.SurfaceSequence, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MojoCompositorFrameSink_Require_Params.encodedSize = codec.kStructHeaderSize + 16;

  MojoCompositorFrameSink_Require_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSink_Require_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.local_frame_id = decoder.decodeStructPointer(local_frame_id$.LocalFrameId);
    val.sequence = decoder.decodeStructPointer(surface_sequence$.SurfaceSequence);
    return val;
  };

  MojoCompositorFrameSink_Require_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSink_Require_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(local_frame_id$.LocalFrameId, val.local_frame_id);
    encoder.encodeStructPointer(surface_sequence$.SurfaceSequence, val.sequence);
  };
  function MojoCompositorFrameSink_Satisfy_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSink_Satisfy_Params.prototype.initDefaults_ = function() {
    this.sequence = null;
  };
  MojoCompositorFrameSink_Satisfy_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSink_Satisfy_Params.validate = function(messageValidator, offset) {
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


    
    // validate MojoCompositorFrameSink_Satisfy_Params.sequence
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_sequence$.SurfaceSequence, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MojoCompositorFrameSink_Satisfy_Params.encodedSize = codec.kStructHeaderSize + 8;

  MojoCompositorFrameSink_Satisfy_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSink_Satisfy_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sequence = decoder.decodeStructPointer(surface_sequence$.SurfaceSequence);
    return val;
  };

  MojoCompositorFrameSink_Satisfy_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSink_Satisfy_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_sequence$.SurfaceSequence, val.sequence);
  };
  function MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.prototype.initDefaults_ = function() {
  };
  MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.validate = function(messageValidator, offset) {
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

  MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.encodedSize = codec.kStructHeaderSize + 0;

  MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function MojoCompositorFrameSinkClient_OnBeginFrame_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSinkClient_OnBeginFrame_Params.prototype.initDefaults_ = function() {
    this.args = null;
  };
  MojoCompositorFrameSinkClient_OnBeginFrame_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSinkClient_OnBeginFrame_Params.validate = function(messageValidator, offset) {
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


    
    // validate MojoCompositorFrameSinkClient_OnBeginFrame_Params.args
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, begin_frame_args$.BeginFrameArgs, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MojoCompositorFrameSinkClient_OnBeginFrame_Params.encodedSize = codec.kStructHeaderSize + 8;

  MojoCompositorFrameSinkClient_OnBeginFrame_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSinkClient_OnBeginFrame_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.args = decoder.decodeStructPointer(begin_frame_args$.BeginFrameArgs);
    return val;
  };

  MojoCompositorFrameSinkClient_OnBeginFrame_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSinkClient_OnBeginFrame_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(begin_frame_args$.BeginFrameArgs, val.args);
  };
  function MojoCompositorFrameSinkClient_ReclaimResources_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSinkClient_ReclaimResources_Params.prototype.initDefaults_ = function() {
    this.resources = null;
  };
  MojoCompositorFrameSinkClient_ReclaimResources_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSinkClient_ReclaimResources_Params.validate = function(messageValidator, offset) {
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


    
    // validate MojoCompositorFrameSinkClient_ReclaimResources_Params.resources
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, returned_resource$.ReturnedResourceArray, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MojoCompositorFrameSinkClient_ReclaimResources_Params.encodedSize = codec.kStructHeaderSize + 8;

  MojoCompositorFrameSinkClient_ReclaimResources_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSinkClient_ReclaimResources_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.resources = decoder.decodeStructPointer(returned_resource$.ReturnedResourceArray);
    return val;
  };

  MojoCompositorFrameSinkClient_ReclaimResources_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSinkClient_ReclaimResources_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(returned_resource$.ReturnedResourceArray, val.resources);
  };
  function MojoCompositorFrameSinkClient_WillDrawSurface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSinkClient_WillDrawSurface_Params.prototype.initDefaults_ = function() {
  };
  MojoCompositorFrameSinkClient_WillDrawSurface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSinkClient_WillDrawSurface_Params.validate = function(messageValidator, offset) {
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

  MojoCompositorFrameSinkClient_WillDrawSurface_Params.encodedSize = codec.kStructHeaderSize + 0;

  MojoCompositorFrameSinkClient_WillDrawSurface_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSinkClient_WillDrawSurface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  MojoCompositorFrameSinkClient_WillDrawSurface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSinkClient_WillDrawSurface_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.prototype.initDefaults_ = function() {
    this.child_frame_sink_id = null;
  };
  MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.validate = function(messageValidator, offset) {
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


    
    // validate MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.child_frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.encodedSize = codec.kStructHeaderSize + 8;

  MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.child_frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    return val;
  };

  MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.child_frame_sink_id);
  };
  function MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.prototype.initDefaults_ = function() {
    this.child_frame_sink_id = null;
  };
  MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.validate = function(messageValidator, offset) {
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


    
    // validate MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.child_frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.encodedSize = codec.kStructHeaderSize + 8;

  MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.decode = function(decoder) {
    var packed;
    var val = new MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.child_frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    return val;
  };

  MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.child_frame_sink_id);
  };
  var kMojoCompositorFrameSink_SetNeedsBeginFrame_Name = 0;
  var kMojoCompositorFrameSink_SubmitCompositorFrame_Name = 1;
  var kMojoCompositorFrameSink_EvictFrame_Name = 2;
  var kMojoCompositorFrameSink_Require_Name = 3;
  var kMojoCompositorFrameSink_Satisfy_Name = 4;

  function MojoCompositorFrameSinkPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(MojoCompositorFrameSink,
                                                   handleOrPtrInfo);
  }

  function MojoCompositorFrameSinkProxy(receiver) {
    this.receiver_ = receiver;
  }
  MojoCompositorFrameSinkPtr.prototype.setNeedsBeginFrame = function() {
    return MojoCompositorFrameSinkProxy.prototype.setNeedsBeginFrame
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkProxy.prototype.setNeedsBeginFrame = function(needs_begin_frame) {
    var params = new MojoCompositorFrameSink_SetNeedsBeginFrame_Params();
    params.needs_begin_frame = needs_begin_frame;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSink_SetNeedsBeginFrame_Name,
        codec.align(MojoCompositorFrameSink_SetNeedsBeginFrame_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSink_SetNeedsBeginFrame_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkPtr.prototype.submitCompositorFrame = function() {
    return MojoCompositorFrameSinkProxy.prototype.submitCompositorFrame
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkProxy.prototype.submitCompositorFrame = function(local_frame_id, frame) {
    var params = new MojoCompositorFrameSink_SubmitCompositorFrame_Params();
    params.local_frame_id = local_frame_id;
    params.frame = frame;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSink_SubmitCompositorFrame_Name,
        codec.align(MojoCompositorFrameSink_SubmitCompositorFrame_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSink_SubmitCompositorFrame_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkPtr.prototype.evictFrame = function() {
    return MojoCompositorFrameSinkProxy.prototype.evictFrame
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkProxy.prototype.evictFrame = function() {
    var params = new MojoCompositorFrameSink_EvictFrame_Params();
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSink_EvictFrame_Name,
        codec.align(MojoCompositorFrameSink_EvictFrame_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSink_EvictFrame_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkPtr.prototype.require = function() {
    return MojoCompositorFrameSinkProxy.prototype.require
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkProxy.prototype.require = function(local_frame_id, sequence) {
    var params = new MojoCompositorFrameSink_Require_Params();
    params.local_frame_id = local_frame_id;
    params.sequence = sequence;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSink_Require_Name,
        codec.align(MojoCompositorFrameSink_Require_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSink_Require_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkPtr.prototype.satisfy = function() {
    return MojoCompositorFrameSinkProxy.prototype.satisfy
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkProxy.prototype.satisfy = function(sequence) {
    var params = new MojoCompositorFrameSink_Satisfy_Params();
    params.sequence = sequence;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSink_Satisfy_Name,
        codec.align(MojoCompositorFrameSink_Satisfy_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSink_Satisfy_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function MojoCompositorFrameSinkStub(delegate) {
    this.delegate_ = delegate;
  }
  MojoCompositorFrameSinkStub.prototype.setNeedsBeginFrame = function(needs_begin_frame) {
    return this.delegate_ && this.delegate_.setNeedsBeginFrame && this.delegate_.setNeedsBeginFrame(needs_begin_frame);
  }
  MojoCompositorFrameSinkStub.prototype.submitCompositorFrame = function(local_frame_id, frame) {
    return this.delegate_ && this.delegate_.submitCompositorFrame && this.delegate_.submitCompositorFrame(local_frame_id, frame);
  }
  MojoCompositorFrameSinkStub.prototype.evictFrame = function() {
    return this.delegate_ && this.delegate_.evictFrame && this.delegate_.evictFrame();
  }
  MojoCompositorFrameSinkStub.prototype.require = function(local_frame_id, sequence) {
    return this.delegate_ && this.delegate_.require && this.delegate_.require(local_frame_id, sequence);
  }
  MojoCompositorFrameSinkStub.prototype.satisfy = function(sequence) {
    return this.delegate_ && this.delegate_.satisfy && this.delegate_.satisfy(sequence);
  }

  MojoCompositorFrameSinkStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kMojoCompositorFrameSink_SetNeedsBeginFrame_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSink_SetNeedsBeginFrame_Params);
      this.setNeedsBeginFrame(params.needs_begin_frame);
      return true;
    case kMojoCompositorFrameSink_SubmitCompositorFrame_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSink_SubmitCompositorFrame_Params);
      this.submitCompositorFrame(params.local_frame_id, params.frame);
      return true;
    case kMojoCompositorFrameSink_EvictFrame_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSink_EvictFrame_Params);
      this.evictFrame();
      return true;
    case kMojoCompositorFrameSink_Require_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSink_Require_Params);
      this.require(params.local_frame_id, params.sequence);
      return true;
    case kMojoCompositorFrameSink_Satisfy_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSink_Satisfy_Params);
      this.satisfy(params.sequence);
      return true;
    default:
      return false;
    }
  };

  MojoCompositorFrameSinkStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateMojoCompositorFrameSinkRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kMojoCompositorFrameSink_SetNeedsBeginFrame_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSink_SetNeedsBeginFrame_Params;
      break;
      case kMojoCompositorFrameSink_SubmitCompositorFrame_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSink_SubmitCompositorFrame_Params;
      break;
      case kMojoCompositorFrameSink_EvictFrame_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSink_EvictFrame_Params;
      break;
      case kMojoCompositorFrameSink_Require_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSink_Require_Params;
      break;
      case kMojoCompositorFrameSink_Satisfy_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSink_Satisfy_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateMojoCompositorFrameSinkResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var MojoCompositorFrameSink = {
    name: 'cc::mojom::MojoCompositorFrameSink',
    ptrClass: MojoCompositorFrameSinkPtr,
    proxyClass: MojoCompositorFrameSinkProxy,
    stubClass: MojoCompositorFrameSinkStub,
    validateRequest: validateMojoCompositorFrameSinkRequest,
    validateResponse: null,
  };
  MojoCompositorFrameSinkStub.prototype.validator = validateMojoCompositorFrameSinkRequest;
  MojoCompositorFrameSinkProxy.prototype.validator = null;
  var kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name = 0;
  var kMojoCompositorFrameSinkClient_OnBeginFrame_Name = 1;
  var kMojoCompositorFrameSinkClient_ReclaimResources_Name = 2;
  var kMojoCompositorFrameSinkClient_WillDrawSurface_Name = 3;

  function MojoCompositorFrameSinkClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(MojoCompositorFrameSinkClient,
                                                   handleOrPtrInfo);
  }

  function MojoCompositorFrameSinkClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  MojoCompositorFrameSinkClientPtr.prototype.didReceiveCompositorFrameAck = function() {
    return MojoCompositorFrameSinkClientProxy.prototype.didReceiveCompositorFrameAck
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkClientProxy.prototype.didReceiveCompositorFrameAck = function() {
    var params = new MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params();
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name,
        codec.align(MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkClientPtr.prototype.onBeginFrame = function() {
    return MojoCompositorFrameSinkClientProxy.prototype.onBeginFrame
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkClientProxy.prototype.onBeginFrame = function(args) {
    var params = new MojoCompositorFrameSinkClient_OnBeginFrame_Params();
    params.args = args;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSinkClient_OnBeginFrame_Name,
        codec.align(MojoCompositorFrameSinkClient_OnBeginFrame_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSinkClient_OnBeginFrame_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkClientPtr.prototype.reclaimResources = function() {
    return MojoCompositorFrameSinkClientProxy.prototype.reclaimResources
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkClientProxy.prototype.reclaimResources = function(resources) {
    var params = new MojoCompositorFrameSinkClient_ReclaimResources_Params();
    params.resources = resources;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSinkClient_ReclaimResources_Name,
        codec.align(MojoCompositorFrameSinkClient_ReclaimResources_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSinkClient_ReclaimResources_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkClientPtr.prototype.willDrawSurface = function() {
    return MojoCompositorFrameSinkClientProxy.prototype.willDrawSurface
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkClientProxy.prototype.willDrawSurface = function() {
    var params = new MojoCompositorFrameSinkClient_WillDrawSurface_Params();
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSinkClient_WillDrawSurface_Name,
        codec.align(MojoCompositorFrameSinkClient_WillDrawSurface_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSinkClient_WillDrawSurface_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function MojoCompositorFrameSinkClientStub(delegate) {
    this.delegate_ = delegate;
  }
  MojoCompositorFrameSinkClientStub.prototype.didReceiveCompositorFrameAck = function() {
    return this.delegate_ && this.delegate_.didReceiveCompositorFrameAck && this.delegate_.didReceiveCompositorFrameAck();
  }
  MojoCompositorFrameSinkClientStub.prototype.onBeginFrame = function(args) {
    return this.delegate_ && this.delegate_.onBeginFrame && this.delegate_.onBeginFrame(args);
  }
  MojoCompositorFrameSinkClientStub.prototype.reclaimResources = function(resources) {
    return this.delegate_ && this.delegate_.reclaimResources && this.delegate_.reclaimResources(resources);
  }
  MojoCompositorFrameSinkClientStub.prototype.willDrawSurface = function() {
    return this.delegate_ && this.delegate_.willDrawSurface && this.delegate_.willDrawSurface();
  }

  MojoCompositorFrameSinkClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params);
      this.didReceiveCompositorFrameAck();
      return true;
    case kMojoCompositorFrameSinkClient_OnBeginFrame_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSinkClient_OnBeginFrame_Params);
      this.onBeginFrame(params.args);
      return true;
    case kMojoCompositorFrameSinkClient_ReclaimResources_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSinkClient_ReclaimResources_Params);
      this.reclaimResources(params.resources);
      return true;
    case kMojoCompositorFrameSinkClient_WillDrawSurface_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSinkClient_WillDrawSurface_Params);
      this.willDrawSurface();
      return true;
    default:
      return false;
    }
  };

  MojoCompositorFrameSinkClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateMojoCompositorFrameSinkClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params;
      break;
      case kMojoCompositorFrameSinkClient_OnBeginFrame_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSinkClient_OnBeginFrame_Params;
      break;
      case kMojoCompositorFrameSinkClient_ReclaimResources_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSinkClient_ReclaimResources_Params;
      break;
      case kMojoCompositorFrameSinkClient_WillDrawSurface_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSinkClient_WillDrawSurface_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateMojoCompositorFrameSinkClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var MojoCompositorFrameSinkClient = {
    name: 'cc::mojom::MojoCompositorFrameSinkClient',
    ptrClass: MojoCompositorFrameSinkClientPtr,
    proxyClass: MojoCompositorFrameSinkClientProxy,
    stubClass: MojoCompositorFrameSinkClientStub,
    validateRequest: validateMojoCompositorFrameSinkClientRequest,
    validateResponse: null,
  };
  MojoCompositorFrameSinkClientStub.prototype.validator = validateMojoCompositorFrameSinkClientRequest;
  MojoCompositorFrameSinkClientProxy.prototype.validator = null;
  var kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name = 0;
  var kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name = 1;

  function MojoCompositorFrameSinkPrivatePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(MojoCompositorFrameSinkPrivate,
                                                   handleOrPtrInfo);
  }

  function MojoCompositorFrameSinkPrivateProxy(receiver) {
    this.receiver_ = receiver;
  }
  MojoCompositorFrameSinkPrivatePtr.prototype.addChildFrameSink = function() {
    return MojoCompositorFrameSinkPrivateProxy.prototype.addChildFrameSink
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkPrivateProxy.prototype.addChildFrameSink = function(child_frame_sink_id) {
    var params = new MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params();
    params.child_frame_sink_id = child_frame_sink_id;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name,
        codec.align(MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  MojoCompositorFrameSinkPrivatePtr.prototype.removeChildFrameSink = function() {
    return MojoCompositorFrameSinkPrivateProxy.prototype.removeChildFrameSink
        .apply(this.ptr.getProxy(), arguments);
  };

  MojoCompositorFrameSinkPrivateProxy.prototype.removeChildFrameSink = function(child_frame_sink_id) {
    var params = new MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params();
    params.child_frame_sink_id = child_frame_sink_id;
    var builder = new codec.MessageBuilder(
        kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name,
        codec.align(MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params.encodedSize));
    builder.encodeStruct(MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function MojoCompositorFrameSinkPrivateStub(delegate) {
    this.delegate_ = delegate;
  }
  MojoCompositorFrameSinkPrivateStub.prototype.addChildFrameSink = function(child_frame_sink_id) {
    return this.delegate_ && this.delegate_.addChildFrameSink && this.delegate_.addChildFrameSink(child_frame_sink_id);
  }
  MojoCompositorFrameSinkPrivateStub.prototype.removeChildFrameSink = function(child_frame_sink_id) {
    return this.delegate_ && this.delegate_.removeChildFrameSink && this.delegate_.removeChildFrameSink(child_frame_sink_id);
  }

  MojoCompositorFrameSinkPrivateStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params);
      this.addChildFrameSink(params.child_frame_sink_id);
      return true;
    case kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name:
      var params = reader.decodeStruct(MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params);
      this.removeChildFrameSink(params.child_frame_sink_id);
      return true;
    default:
      return false;
    }
  };

  MojoCompositorFrameSinkPrivateStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateMojoCompositorFrameSinkPrivateRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params;
      break;
      case kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateMojoCompositorFrameSinkPrivateResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var MojoCompositorFrameSinkPrivate = {
    name: 'cc::mojom::MojoCompositorFrameSinkPrivate',
    ptrClass: MojoCompositorFrameSinkPrivatePtr,
    proxyClass: MojoCompositorFrameSinkPrivateProxy,
    stubClass: MojoCompositorFrameSinkPrivateStub,
    validateRequest: validateMojoCompositorFrameSinkPrivateRequest,
    validateResponse: null,
  };
  MojoCompositorFrameSinkPrivateStub.prototype.validator = validateMojoCompositorFrameSinkPrivateRequest;
  MojoCompositorFrameSinkPrivateProxy.prototype.validator = null;

  var exports = {};
  exports.MojoCompositorFrameSink = MojoCompositorFrameSink;
  exports.MojoCompositorFrameSinkPtr = MojoCompositorFrameSinkPtr;
  exports.MojoCompositorFrameSinkClient = MojoCompositorFrameSinkClient;
  exports.MojoCompositorFrameSinkClientPtr = MojoCompositorFrameSinkClientPtr;
  exports.MojoCompositorFrameSinkPrivate = MojoCompositorFrameSinkPrivate;
  exports.MojoCompositorFrameSinkPrivatePtr = MojoCompositorFrameSinkPrivatePtr;

  return exports;
});
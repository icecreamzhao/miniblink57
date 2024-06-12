// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/window_tree.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/surface_info.mojom",
    "cc/ipc/mojo_compositor_frame_sink.mojom",
    "services/ui/public/interfaces/cursor.mojom",
    "services/ui/public/interfaces/event_matcher.mojom",
    "services/ui/public/interfaces/mus_constants.mojom",
    "services/ui/public/interfaces/window_manager.mojom",
    "services/ui/public/interfaces/window_manager_constants.mojom",
    "services/ui/public/interfaces/window_tree_constants.mojom",
    "ui/events/mojo/event.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/platform_window/mojo/text_input_state.mojom",
], function(bindings, codec, core, validator, surface_info$, mojo_compositor_frame_sink$, cursor$, event_matcher$, mus_constants$, window_manager$, window_manager_constants$, window_tree_constants$, event$, geometry$, text_input_state$) {

  function WindowTree_NewWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_NewWindow_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.properties = null;
  };
  WindowTree_NewWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_NewWindow_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_NewWindow_Params.properties
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, true, codec.String, new codec.ArrayOf(codec.Uint8), false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_NewWindow_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_NewWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_NewWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.properties = decoder.decodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8));
    return val;
  };

  WindowTree_NewWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_NewWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8), val.properties);
  };
  function WindowTree_NewTopLevelWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_NewTopLevelWindow_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.properties = null;
  };
  WindowTree_NewTopLevelWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_NewTopLevelWindow_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_NewTopLevelWindow_Params.properties
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, false, codec.String, new codec.ArrayOf(codec.Uint8), false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_NewTopLevelWindow_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_NewTopLevelWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_NewTopLevelWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.properties = decoder.decodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8));
    return val;
  };

  WindowTree_NewTopLevelWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_NewTopLevelWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8), val.properties);
  };
  function WindowTree_DeleteWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_DeleteWindow_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
  };
  WindowTree_DeleteWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_DeleteWindow_Params.validate = function(messageValidator, offset) {
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

  WindowTree_DeleteWindow_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_DeleteWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_DeleteWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_DeleteWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_DeleteWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
  };
  function WindowTree_SetCapture_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetCapture_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
  };
  WindowTree_SetCapture_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetCapture_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetCapture_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_SetCapture_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetCapture_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_SetCapture_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetCapture_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
  };
  function WindowTree_ReleaseCapture_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_ReleaseCapture_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
  };
  WindowTree_ReleaseCapture_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_ReleaseCapture_Params.validate = function(messageValidator, offset) {
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

  WindowTree_ReleaseCapture_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_ReleaseCapture_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_ReleaseCapture_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_ReleaseCapture_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_ReleaseCapture_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
  };
  function WindowTree_StartPointerWatcher_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_StartPointerWatcher_Params.prototype.initDefaults_ = function() {
    this.want_moves = false;
  };
  WindowTree_StartPointerWatcher_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_StartPointerWatcher_Params.validate = function(messageValidator, offset) {
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

  WindowTree_StartPointerWatcher_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_StartPointerWatcher_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_StartPointerWatcher_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.want_moves = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_StartPointerWatcher_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_StartPointerWatcher_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.want_moves & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_StopPointerWatcher_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_StopPointerWatcher_Params.prototype.initDefaults_ = function() {
  };
  WindowTree_StopPointerWatcher_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_StopPointerWatcher_Params.validate = function(messageValidator, offset) {
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

  WindowTree_StopPointerWatcher_Params.encodedSize = codec.kStructHeaderSize + 0;

  WindowTree_StopPointerWatcher_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_StopPointerWatcher_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  WindowTree_StopPointerWatcher_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_StopPointerWatcher_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function WindowTree_SetWindowBounds_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetWindowBounds_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.bounds = null;
  };
  WindowTree_SetWindowBounds_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetWindowBounds_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_SetWindowBounds_Params.bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_SetWindowBounds_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_SetWindowBounds_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetWindowBounds_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.bounds = decoder.decodeStructPointer(geometry$.Rect);
    return val;
  };

  WindowTree_SetWindowBounds_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetWindowBounds_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStructPointer(geometry$.Rect, val.bounds);
  };
  function WindowTree_SetClientArea_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetClientArea_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.insets = null;
    this.additional_client_areas = null;
  };
  WindowTree_SetClientArea_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetClientArea_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTree_SetClientArea_Params.insets
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Insets, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTree_SetClientArea_Params.additional_client_areas
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(geometry$.Rect), true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_SetClientArea_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTree_SetClientArea_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetClientArea_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.insets = decoder.decodeStructPointer(geometry$.Insets);
    val.additional_client_areas = decoder.decodeArrayPointer(new codec.PointerTo(geometry$.Rect));
    return val;
  };

  WindowTree_SetClientArea_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetClientArea_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Insets, val.insets);
    encoder.encodeArrayPointer(new codec.PointerTo(geometry$.Rect), val.additional_client_areas);
  };
  function WindowTree_SetHitTestMask_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetHitTestMask_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.mask = null;
  };
  WindowTree_SetHitTestMask_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetHitTestMask_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTree_SetHitTestMask_Params.mask
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Rect, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_SetHitTestMask_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_SetHitTestMask_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetHitTestMask_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.mask = decoder.decodeStructPointer(geometry$.Rect);
    return val;
  };

  WindowTree_SetHitTestMask_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetHitTestMask_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Rect, val.mask);
  };
  function WindowTree_SetCanAcceptDrops_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetCanAcceptDrops_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.accepts_drops = false;
  };
  WindowTree_SetCanAcceptDrops_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetCanAcceptDrops_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetCanAcceptDrops_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_SetCanAcceptDrops_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetCanAcceptDrops_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.accepts_drops = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_SetCanAcceptDrops_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetCanAcceptDrops_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    packed = 0;
    packed |= (val.accepts_drops & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_SetWindowVisibility_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetWindowVisibility_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.visible = false;
  };
  WindowTree_SetWindowVisibility_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetWindowVisibility_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetWindowVisibility_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_SetWindowVisibility_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetWindowVisibility_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
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

  WindowTree_SetWindowVisibility_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetWindowVisibility_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
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
  function WindowTree_SetWindowProperty_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetWindowProperty_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.name = null;
    this.value = null;
  };
  WindowTree_SetWindowProperty_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetWindowProperty_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_SetWindowProperty_Params.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTree_SetWindowProperty_Params.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_SetWindowProperty_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTree_SetWindowProperty_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetWindowProperty_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.name = decoder.decodeStruct(codec.String);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  WindowTree_SetWindowProperty_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetWindowProperty_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function WindowTree_SetWindowOpacity_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetWindowOpacity_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.opacity = 0;
  };
  WindowTree_SetWindowOpacity_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetWindowOpacity_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetWindowOpacity_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_SetWindowOpacity_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetWindowOpacity_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.opacity = decoder.decodeStruct(codec.Float);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_SetWindowOpacity_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetWindowOpacity_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Float, val.opacity);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_AttachCompositorFrameSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_AttachCompositorFrameSink_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.compositor_frame_sink = new bindings.InterfaceRequest();
    this.client = new mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr();
  };
  WindowTree_AttachCompositorFrameSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_AttachCompositorFrameSink_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTree_AttachCompositorFrameSink_Params.compositor_frame_sink
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 4, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTree_AttachCompositorFrameSink_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_AttachCompositorFrameSink_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_AttachCompositorFrameSink_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_AttachCompositorFrameSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.compositor_frame_sink = decoder.decodeStruct(codec.InterfaceRequest);
    val.client = decoder.decodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr));
    return val;
  };

  WindowTree_AttachCompositorFrameSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_AttachCompositorFrameSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.InterfaceRequest, val.compositor_frame_sink);
    encoder.encodeStruct(new codec.Interface(mojo_compositor_frame_sink$.MojoCompositorFrameSinkClientPtr), val.client);
  };
  function WindowTree_AddWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_AddWindow_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.parent = 0;
    this.child = 0;
  };
  WindowTree_AddWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_AddWindow_Params.validate = function(messageValidator, offset) {
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

  WindowTree_AddWindow_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_AddWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_AddWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.parent = decoder.decodeStruct(codec.Uint32);
    val.child = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_AddWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_AddWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.parent);
    encoder.encodeStruct(codec.Uint32, val.child);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_RemoveWindowFromParent_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_RemoveWindowFromParent_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
  };
  WindowTree_RemoveWindowFromParent_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_RemoveWindowFromParent_Params.validate = function(messageValidator, offset) {
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

  WindowTree_RemoveWindowFromParent_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_RemoveWindowFromParent_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_RemoveWindowFromParent_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_RemoveWindowFromParent_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_RemoveWindowFromParent_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
  };
  function WindowTree_AddTransientWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_AddTransientWindow_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.transient_window_id = 0;
  };
  WindowTree_AddTransientWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_AddTransientWindow_Params.validate = function(messageValidator, offset) {
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

  WindowTree_AddTransientWindow_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_AddTransientWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_AddTransientWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.transient_window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_AddTransientWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_AddTransientWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Uint32, val.transient_window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_RemoveTransientWindowFromParent_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_RemoveTransientWindowFromParent_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.transient_window_id = 0;
  };
  WindowTree_RemoveTransientWindowFromParent_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_RemoveTransientWindowFromParent_Params.validate = function(messageValidator, offset) {
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

  WindowTree_RemoveTransientWindowFromParent_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_RemoveTransientWindowFromParent_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_RemoveTransientWindowFromParent_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.transient_window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_RemoveTransientWindowFromParent_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_RemoveTransientWindowFromParent_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.transient_window_id);
  };
  function WindowTree_SetModal_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetModal_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
  };
  WindowTree_SetModal_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetModal_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetModal_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_SetModal_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetModal_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_SetModal_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetModal_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
  };
  function WindowTree_ReorderWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_ReorderWindow_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.relative_window_id = 0;
    this.direction = 0;
  };
  WindowTree_ReorderWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_ReorderWindow_Params.validate = function(messageValidator, offset) {
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





    
    // validate WindowTree_ReorderWindow_Params.direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 12, mus_constants$.OrderDirection);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_ReorderWindow_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_ReorderWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_ReorderWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.relative_window_id = decoder.decodeStruct(codec.Uint32);
    val.direction = decoder.decodeStruct(codec.Int32);
    return val;
  };

  WindowTree_ReorderWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_ReorderWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Uint32, val.relative_window_id);
    encoder.encodeStruct(codec.Int32, val.direction);
  };
  function WindowTree_GetWindowTree_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_GetWindowTree_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
  };
  WindowTree_GetWindowTree_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_GetWindowTree_Params.validate = function(messageValidator, offset) {
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

  WindowTree_GetWindowTree_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_GetWindowTree_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_GetWindowTree_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_GetWindowTree_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_GetWindowTree_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_GetWindowTree_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_GetWindowTree_ResponseParams.prototype.initDefaults_ = function() {
    this.windows = null;
  };
  WindowTree_GetWindowTree_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_GetWindowTree_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate WindowTree_GetWindowTree_ResponseParams.windows
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(window_tree_constants$.WindowData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_GetWindowTree_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_GetWindowTree_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WindowTree_GetWindowTree_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.windows = decoder.decodeArrayPointer(new codec.PointerTo(window_tree_constants$.WindowData));
    return val;
  };

  WindowTree_GetWindowTree_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_GetWindowTree_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(window_tree_constants$.WindowData), val.windows);
  };
  function WindowTree_Embed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_Embed_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.client = new WindowTreeClientPtr();
    this.embed_flags = 0;
  };
  WindowTree_Embed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_Embed_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTree_Embed_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowTree_Embed_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_Embed_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_Embed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.client = decoder.decodeStruct(new codec.Interface(WindowTreeClientPtr));
    val.embed_flags = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_Embed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_Embed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(new codec.Interface(WindowTreeClientPtr), val.client);
    encoder.encodeStruct(codec.Uint32, val.embed_flags);
  };
  function WindowTree_Embed_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_Embed_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  WindowTree_Embed_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_Embed_ResponseParams.validate = function(messageValidator, offset) {
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

  WindowTree_Embed_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_Embed_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WindowTree_Embed_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_Embed_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_Embed_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_SetFocus_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetFocus_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
  };
  WindowTree_SetFocus_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetFocus_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetFocus_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_SetFocus_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetFocus_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTree_SetFocus_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetFocus_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
  };
  function WindowTree_SetCanFocus_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetCanFocus_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.can_focus = false;
  };
  WindowTree_SetCanFocus_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetCanFocus_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetCanFocus_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_SetCanFocus_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetCanFocus_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.can_focus = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_SetCanFocus_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetCanFocus_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    packed = 0;
    packed |= (val.can_focus & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_SetPredefinedCursor_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetPredefinedCursor_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.cursor_id = 0;
  };
  WindowTree_SetPredefinedCursor_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetPredefinedCursor_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_SetPredefinedCursor_Params.cursor_id
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, cursor$.Cursor);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_SetPredefinedCursor_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_SetPredefinedCursor_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetPredefinedCursor_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.cursor_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_SetPredefinedCursor_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetPredefinedCursor_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Int32, val.cursor_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_SetWindowTextInputState_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetWindowTextInputState_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.state = null;
  };
  WindowTree_SetWindowTextInputState_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetWindowTextInputState_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTree_SetWindowTextInputState_Params.state
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, text_input_state$.TextInputState, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_SetWindowTextInputState_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_SetWindowTextInputState_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetWindowTextInputState_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.state = decoder.decodeStructPointer(text_input_state$.TextInputState);
    return val;
  };

  WindowTree_SetWindowTextInputState_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetWindowTextInputState_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(text_input_state$.TextInputState, val.state);
  };
  function WindowTree_SetImeVisibility_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetImeVisibility_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.visible = false;
    this.state = null;
  };
  WindowTree_SetImeVisibility_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetImeVisibility_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_SetImeVisibility_Params.state
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, text_input_state$.TextInputState, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_SetImeVisibility_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTree_SetImeVisibility_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetImeVisibility_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.visible = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.state = decoder.decodeStructPointer(text_input_state$.TextInputState);
    return val;
  };

  WindowTree_SetImeVisibility_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetImeVisibility_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    packed = 0;
    packed |= (val.visible & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(text_input_state$.TextInputState, val.state);
  };
  function WindowTree_SetCanAcceptEvents_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_SetCanAcceptEvents_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.accept_events = false;
  };
  WindowTree_SetCanAcceptEvents_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_SetCanAcceptEvents_Params.validate = function(messageValidator, offset) {
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

  WindowTree_SetCanAcceptEvents_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_SetCanAcceptEvents_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_SetCanAcceptEvents_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.accept_events = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_SetCanAcceptEvents_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_SetCanAcceptEvents_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    packed = 0;
    packed |= (val.accept_events & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_OnWindowInputEventAck_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_OnWindowInputEventAck_Params.prototype.initDefaults_ = function() {
    this.event_id = 0;
    this.result = 0;
  };
  WindowTree_OnWindowInputEventAck_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_OnWindowInputEventAck_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTree_OnWindowInputEventAck_Params.result
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, window_tree_constants$.EventResult);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_OnWindowInputEventAck_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_OnWindowInputEventAck_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_OnWindowInputEventAck_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.event_id = decoder.decodeStruct(codec.Uint32);
    val.result = decoder.decodeStruct(codec.Int32);
    return val;
  };

  WindowTree_OnWindowInputEventAck_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_OnWindowInputEventAck_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.event_id);
    encoder.encodeStruct(codec.Int32, val.result);
  };
  function WindowTree_DeactivateWindow_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_DeactivateWindow_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
  };
  WindowTree_DeactivateWindow_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_DeactivateWindow_Params.validate = function(messageValidator, offset) {
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

  WindowTree_DeactivateWindow_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_DeactivateWindow_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_DeactivateWindow_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_DeactivateWindow_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_DeactivateWindow_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_GetWindowManagerClient_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_GetWindowManagerClient_Params.prototype.initDefaults_ = function() {
    this.internal = null;
  };
  WindowTree_GetWindowManagerClient_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_GetWindowManagerClient_Params.validate = function(messageValidator, offset) {
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

  WindowTree_GetWindowManagerClient_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_GetWindowManagerClient_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_GetWindowManagerClient_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.internal = decoder.decodeStruct(codec.AssociatedInterfaceRequestNotSupported);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_GetWindowManagerClient_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_GetWindowManagerClient_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.AssociatedInterfaceRequestNotSupported, val.internal);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_GetCursorLocationMemory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_GetCursorLocationMemory_Params.prototype.initDefaults_ = function() {
  };
  WindowTree_GetCursorLocationMemory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_GetCursorLocationMemory_Params.validate = function(messageValidator, offset) {
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

  WindowTree_GetCursorLocationMemory_Params.encodedSize = codec.kStructHeaderSize + 0;

  WindowTree_GetCursorLocationMemory_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_GetCursorLocationMemory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  WindowTree_GetCursorLocationMemory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_GetCursorLocationMemory_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function WindowTree_GetCursorLocationMemory_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_GetCursorLocationMemory_ResponseParams.prototype.initDefaults_ = function() {
    this.cursor_buffer = null;
  };
  WindowTree_GetCursorLocationMemory_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_GetCursorLocationMemory_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate WindowTree_GetCursorLocationMemory_ResponseParams.cursor_buffer
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_GetCursorLocationMemory_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_GetCursorLocationMemory_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WindowTree_GetCursorLocationMemory_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.cursor_buffer = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_GetCursorLocationMemory_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_GetCursorLocationMemory_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.cursor_buffer);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_PerformWindowMove_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_PerformWindowMove_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.window_id = 0;
    this.source = 0;
    this.cursor = null;
  };
  WindowTree_PerformWindowMove_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_PerformWindowMove_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_PerformWindowMove_Params.source
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, window_manager_constants$.MoveLoopSource);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTree_PerformWindowMove_Params.cursor
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Point, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTree_PerformWindowMove_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTree_PerformWindowMove_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_PerformWindowMove_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.source = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.cursor = decoder.decodeStructPointer(geometry$.Point);
    return val;
  };

  WindowTree_PerformWindowMove_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_PerformWindowMove_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Int32, val.source);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Point, val.cursor);
  };
  function WindowTree_CancelWindowMove_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_CancelWindowMove_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
  };
  WindowTree_CancelWindowMove_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_CancelWindowMove_Params.validate = function(messageValidator, offset) {
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

  WindowTree_CancelWindowMove_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_CancelWindowMove_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_CancelWindowMove_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_CancelWindowMove_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_CancelWindowMove_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_PerformDragDrop_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_PerformDragDrop_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.source_window_id = 0;
    this.drag_data = null;
    this.drag_operation = 0;
  };
  WindowTree_PerformDragDrop_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_PerformDragDrop_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTree_PerformDragDrop_Params.drag_data
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, false, codec.String, new codec.ArrayOf(codec.Uint8), false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowTree_PerformDragDrop_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTree_PerformDragDrop_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_PerformDragDrop_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    val.source_window_id = decoder.decodeStruct(codec.Uint32);
    val.drag_data = decoder.decodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8));
    val.drag_operation = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_PerformDragDrop_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_PerformDragDrop_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    encoder.encodeStruct(codec.Uint32, val.source_window_id);
    encoder.encodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8), val.drag_data);
    encoder.encodeStruct(codec.Uint32, val.drag_operation);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTree_CancelDragDrop_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTree_CancelDragDrop_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
  };
  WindowTree_CancelDragDrop_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTree_CancelDragDrop_Params.validate = function(messageValidator, offset) {
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

  WindowTree_CancelDragDrop_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTree_CancelDragDrop_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTree_CancelDragDrop_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTree_CancelDragDrop_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTree_CancelDragDrop_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnEmbed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnEmbed_Params.prototype.initDefaults_ = function() {
    this.connection_id = 0;
    this.parent_drawn = false;
    this.focused_window = 0;
    this.root = null;
    this.tree = new WindowTreePtr();
    this.display_id = 0;
  };
  WindowTreeClient_OnEmbed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnEmbed_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 40}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate WindowTreeClient_OnEmbed_Params.root
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, window_tree_constants$.WindowData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTreeClient_OnEmbed_Params.tree
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 16, true);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  WindowTreeClient_OnEmbed_Params.encodedSize = codec.kStructHeaderSize + 32;

  WindowTreeClient_OnEmbed_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnEmbed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.connection_id = decoder.decodeStruct(codec.Uint16);
    packed = decoder.readUint8();
    val.parent_drawn = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    val.focused_window = decoder.decodeStruct(codec.Uint32);
    val.root = decoder.decodeStructPointer(window_tree_constants$.WindowData);
    val.tree = decoder.decodeStruct(new codec.NullableInterface(WindowTreePtr));
    val.display_id = decoder.decodeStruct(codec.Int64);
    return val;
  };

  WindowTreeClient_OnEmbed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnEmbed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint16, val.connection_id);
    packed = 0;
    packed |= (val.parent_drawn & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.focused_window);
    encoder.encodeStructPointer(window_tree_constants$.WindowData, val.root);
    encoder.encodeStruct(new codec.NullableInterface(WindowTreePtr), val.tree);
    encoder.encodeStruct(codec.Int64, val.display_id);
  };
  function WindowTreeClient_OnEmbeddedAppDisconnected_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnEmbeddedAppDisconnected_Params.prototype.initDefaults_ = function() {
    this.window = 0;
  };
  WindowTreeClient_OnEmbeddedAppDisconnected_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnEmbeddedAppDisconnected_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnEmbeddedAppDisconnected_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnEmbeddedAppDisconnected_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnEmbeddedAppDisconnected_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnEmbeddedAppDisconnected_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnEmbeddedAppDisconnected_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnUnembed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnUnembed_Params.prototype.initDefaults_ = function() {
    this.window = 0;
  };
  WindowTreeClient_OnUnembed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnUnembed_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnUnembed_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnUnembed_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnUnembed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnUnembed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnUnembed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnCaptureChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnCaptureChanged_Params.prototype.initDefaults_ = function() {
    this.new_capture = 0;
    this.old_capture = 0;
  };
  WindowTreeClient_OnCaptureChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnCaptureChanged_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnCaptureChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnCaptureChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnCaptureChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.new_capture = decoder.decodeStruct(codec.Uint32);
    val.old_capture = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTreeClient_OnCaptureChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnCaptureChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.new_capture);
    encoder.encodeStruct(codec.Uint32, val.old_capture);
  };
  function WindowTreeClient_OnTopLevelCreated_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnTopLevelCreated_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.parent_drawn = false;
    this.data = null;
    this.display_id = 0;
  };
  WindowTreeClient_OnTopLevelCreated_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnTopLevelCreated_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTreeClient_OnTopLevelCreated_Params.data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, window_tree_constants$.WindowData, false);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  WindowTreeClient_OnTopLevelCreated_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnTopLevelCreated_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnTopLevelCreated_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.parent_drawn = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.data = decoder.decodeStructPointer(window_tree_constants$.WindowData);
    val.display_id = decoder.decodeStruct(codec.Int64);
    return val;
  };

  WindowTreeClient_OnTopLevelCreated_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnTopLevelCreated_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    packed = 0;
    packed |= (val.parent_drawn & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(window_tree_constants$.WindowData, val.data);
    encoder.encodeStruct(codec.Int64, val.display_id);
  };
  function WindowTreeClient_OnWindowBoundsChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowBoundsChanged_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.old_bounds = null;
    this.new_bounds = null;
  };
  WindowTreeClient_OnWindowBoundsChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowBoundsChanged_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTreeClient_OnWindowBoundsChanged_Params.old_bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTreeClient_OnWindowBoundsChanged_Params.new_bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnWindowBoundsChanged_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnWindowBoundsChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowBoundsChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.old_bounds = decoder.decodeStructPointer(geometry$.Rect);
    val.new_bounds = decoder.decodeStructPointer(geometry$.Rect);
    return val;
  };

  WindowTreeClient_OnWindowBoundsChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowBoundsChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Rect, val.old_bounds);
    encoder.encodeStructPointer(geometry$.Rect, val.new_bounds);
  };
  function WindowTreeClient_OnClientAreaChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnClientAreaChanged_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.new_client_area = null;
    this.new_additional_client_areas = null;
  };
  WindowTreeClient_OnClientAreaChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnClientAreaChanged_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTreeClient_OnClientAreaChanged_Params.new_client_area
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Insets, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTreeClient_OnClientAreaChanged_Params.new_additional_client_areas
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(geometry$.Rect), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnClientAreaChanged_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnClientAreaChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnClientAreaChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.new_client_area = decoder.decodeStructPointer(geometry$.Insets);
    val.new_additional_client_areas = decoder.decodeArrayPointer(new codec.PointerTo(geometry$.Rect));
    return val;
  };

  WindowTreeClient_OnClientAreaChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnClientAreaChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Insets, val.new_client_area);
    encoder.encodeArrayPointer(new codec.PointerTo(geometry$.Rect), val.new_additional_client_areas);
  };
  function WindowTreeClient_OnTransientWindowAdded_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnTransientWindowAdded_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.transient_window_id = 0;
  };
  WindowTreeClient_OnTransientWindowAdded_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnTransientWindowAdded_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnTransientWindowAdded_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnTransientWindowAdded_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnTransientWindowAdded_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.transient_window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTreeClient_OnTransientWindowAdded_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnTransientWindowAdded_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Uint32, val.transient_window_id);
  };
  function WindowTreeClient_OnTransientWindowRemoved_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnTransientWindowRemoved_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.transient_window_id = 0;
  };
  WindowTreeClient_OnTransientWindowRemoved_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnTransientWindowRemoved_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnTransientWindowRemoved_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnTransientWindowRemoved_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnTransientWindowRemoved_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.transient_window_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  WindowTreeClient_OnTransientWindowRemoved_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnTransientWindowRemoved_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Uint32, val.transient_window_id);
  };
  function WindowTreeClient_OnWindowHierarchyChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowHierarchyChanged_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.old_parent = 0;
    this.new_parent = 0;
    this.windows = null;
  };
  WindowTreeClient_OnWindowHierarchyChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowHierarchyChanged_Params.validate = function(messageValidator, offset) {
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





    
    // validate WindowTreeClient_OnWindowHierarchyChanged_Params.windows
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(window_tree_constants$.WindowData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnWindowHierarchyChanged_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnWindowHierarchyChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowHierarchyChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    val.old_parent = decoder.decodeStruct(codec.Uint32);
    val.new_parent = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.windows = decoder.decodeArrayPointer(new codec.PointerTo(window_tree_constants$.WindowData));
    return val;
  };

  WindowTreeClient_OnWindowHierarchyChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowHierarchyChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.encodeStruct(codec.Uint32, val.old_parent);
    encoder.encodeStruct(codec.Uint32, val.new_parent);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(new codec.PointerTo(window_tree_constants$.WindowData), val.windows);
  };
  function WindowTreeClient_OnWindowReordered_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowReordered_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.relative_window_id = 0;
    this.direction = 0;
  };
  WindowTreeClient_OnWindowReordered_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowReordered_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTreeClient_OnWindowReordered_Params.direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, mus_constants$.OrderDirection);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnWindowReordered_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTreeClient_OnWindowReordered_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowReordered_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.relative_window_id = decoder.decodeStruct(codec.Uint32);
    val.direction = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnWindowReordered_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowReordered_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Uint32, val.relative_window_id);
    encoder.encodeStruct(codec.Int32, val.direction);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnWindowDeleted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowDeleted_Params.prototype.initDefaults_ = function() {
    this.window = 0;
  };
  WindowTreeClient_OnWindowDeleted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowDeleted_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnWindowDeleted_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnWindowDeleted_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowDeleted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnWindowDeleted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowDeleted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnWindowVisibilityChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowVisibilityChanged_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.visible = false;
  };
  WindowTreeClient_OnWindowVisibilityChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowVisibilityChanged_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnWindowVisibilityChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnWindowVisibilityChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowVisibilityChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.visible = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnWindowVisibilityChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowVisibilityChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    packed = 0;
    packed |= (val.visible & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnWindowOpacityChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowOpacityChanged_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.old_opacity = 0;
    this.new_opacity = 0;
  };
  WindowTreeClient_OnWindowOpacityChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowOpacityChanged_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnWindowOpacityChanged_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTreeClient_OnWindowOpacityChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowOpacityChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    val.old_opacity = decoder.decodeStruct(codec.Float);
    val.new_opacity = decoder.decodeStruct(codec.Float);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnWindowOpacityChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowOpacityChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.encodeStruct(codec.Float, val.old_opacity);
    encoder.encodeStruct(codec.Float, val.new_opacity);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnWindowParentDrawnStateChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowParentDrawnStateChanged_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.drawn = false;
  };
  WindowTreeClient_OnWindowParentDrawnStateChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowParentDrawnStateChanged_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnWindowParentDrawnStateChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnWindowParentDrawnStateChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowParentDrawnStateChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.drawn = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnWindowParentDrawnStateChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowParentDrawnStateChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    packed = 0;
    packed |= (val.drawn & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnWindowSharedPropertyChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowSharedPropertyChanged_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.name = null;
    this.new_data = null;
  };
  WindowTreeClient_OnWindowSharedPropertyChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowSharedPropertyChanged_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTreeClient_OnWindowSharedPropertyChanged_Params.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTreeClient_OnWindowSharedPropertyChanged_Params.new_data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnWindowSharedPropertyChanged_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnWindowSharedPropertyChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowSharedPropertyChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.name = decoder.decodeStruct(codec.String);
    val.new_data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  WindowTreeClient_OnWindowSharedPropertyChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowSharedPropertyChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeArrayPointer(codec.Uint8, val.new_data);
  };
  function WindowTreeClient_OnWindowInputEvent_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowInputEvent_Params.prototype.initDefaults_ = function() {
    this.event_id = 0;
    this.window = 0;
    this.event = null;
    this.matches_pointer_watcher = false;
  };
  WindowTreeClient_OnWindowInputEvent_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowInputEvent_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTreeClient_OnWindowInputEvent_Params.event
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, event$.Event, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowTreeClient_OnWindowInputEvent_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnWindowInputEvent_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowInputEvent_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.event_id = decoder.decodeStruct(codec.Uint32);
    val.window = decoder.decodeStruct(codec.Uint32);
    val.event = decoder.decodeStructPointer(event$.Event);
    packed = decoder.readUint8();
    val.matches_pointer_watcher = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnWindowInputEvent_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowInputEvent_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.event_id);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.encodeStructPointer(event$.Event, val.event);
    packed = 0;
    packed |= (val.matches_pointer_watcher & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnPointerEventObserved_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnPointerEventObserved_Params.prototype.initDefaults_ = function() {
    this.event = null;
    this.window_id = 0;
  };
  WindowTreeClient_OnPointerEventObserved_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnPointerEventObserved_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowTreeClient_OnPointerEventObserved_Params.event
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, event$.Event, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowTreeClient_OnPointerEventObserved_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTreeClient_OnPointerEventObserved_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnPointerEventObserved_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.event = decoder.decodeStructPointer(event$.Event);
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnPointerEventObserved_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnPointerEventObserved_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(event$.Event, val.event);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnWindowFocused_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowFocused_Params.prototype.initDefaults_ = function() {
    this.focused_window_id = 0;
  };
  WindowTreeClient_OnWindowFocused_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowFocused_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnWindowFocused_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnWindowFocused_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowFocused_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.focused_window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnWindowFocused_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowFocused_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.focused_window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnWindowPredefinedCursorChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowPredefinedCursorChanged_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.cursor_id = 0;
  };
  WindowTreeClient_OnWindowPredefinedCursorChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowPredefinedCursorChanged_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTreeClient_OnWindowPredefinedCursorChanged_Params.cursor_id
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, cursor$.Cursor);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnWindowPredefinedCursorChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnWindowPredefinedCursorChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowPredefinedCursorChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    val.cursor_id = decoder.decodeStruct(codec.Int32);
    return val;
  };

  WindowTreeClient_OnWindowPredefinedCursorChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowPredefinedCursorChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.encodeStruct(codec.Int32, val.cursor_id);
  };
  function WindowTreeClient_OnWindowSurfaceChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnWindowSurfaceChanged_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
    this.surface_info = null;
  };
  WindowTreeClient_OnWindowSurfaceChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnWindowSurfaceChanged_Params.validate = function(messageValidator, offset) {
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



    
    // validate WindowTreeClient_OnWindowSurfaceChanged_Params.surface_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, surface_info$.SurfaceInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnWindowSurfaceChanged_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTreeClient_OnWindowSurfaceChanged_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnWindowSurfaceChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.surface_info = decoder.decodeStructPointer(surface_info$.SurfaceInfo);
    return val;
  };

  WindowTreeClient_OnWindowSurfaceChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnWindowSurfaceChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(surface_info$.SurfaceInfo, val.surface_info);
  };
  function WindowTreeClient_OnDragDropStart_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnDragDropStart_Params.prototype.initDefaults_ = function() {
    this.drag_data = null;
  };
  WindowTreeClient_OnDragDropStart_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnDragDropStart_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowTreeClient_OnDragDropStart_Params.drag_data
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 0, false, codec.String, new codec.ArrayOf(codec.Uint8), false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeClient_OnDragDropStart_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnDragDropStart_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnDragDropStart_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.drag_data = decoder.decodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8));
    return val;
  };

  WindowTreeClient_OnDragDropStart_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnDragDropStart_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8), val.drag_data);
  };
  function WindowTreeClient_OnDragEnter_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnDragEnter_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.key_state = 0;
    this.screen_position = null;
    this.effect_bitmask = 0;
  };
  WindowTreeClient_OnDragEnter_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnDragEnter_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTreeClient_OnDragEnter_Params.screen_position
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Point, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowTreeClient_OnDragEnter_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnDragEnter_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnDragEnter_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    val.key_state = decoder.decodeStruct(codec.Uint32);
    val.screen_position = decoder.decodeStructPointer(geometry$.Point);
    val.effect_bitmask = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnDragEnter_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnDragEnter_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.encodeStruct(codec.Uint32, val.key_state);
    encoder.encodeStructPointer(geometry$.Point, val.screen_position);
    encoder.encodeStruct(codec.Uint32, val.effect_bitmask);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnDragEnter_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnDragEnter_ResponseParams.prototype.initDefaults_ = function() {
    this.supported_op_bitmask = 0;
  };
  WindowTreeClient_OnDragEnter_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnDragEnter_ResponseParams.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnDragEnter_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnDragEnter_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnDragEnter_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.supported_op_bitmask = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnDragEnter_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnDragEnter_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.supported_op_bitmask);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnDragOver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnDragOver_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.key_state = 0;
    this.screen_position = null;
    this.effect_bitmask = 0;
  };
  WindowTreeClient_OnDragOver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnDragOver_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTreeClient_OnDragOver_Params.screen_position
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Point, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowTreeClient_OnDragOver_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnDragOver_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnDragOver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    val.key_state = decoder.decodeStruct(codec.Uint32);
    val.screen_position = decoder.decodeStructPointer(geometry$.Point);
    val.effect_bitmask = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnDragOver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnDragOver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.encodeStruct(codec.Uint32, val.key_state);
    encoder.encodeStructPointer(geometry$.Point, val.screen_position);
    encoder.encodeStruct(codec.Uint32, val.effect_bitmask);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnDragOver_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnDragOver_ResponseParams.prototype.initDefaults_ = function() {
    this.supported_op_bitmask = 0;
  };
  WindowTreeClient_OnDragOver_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnDragOver_ResponseParams.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnDragOver_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnDragOver_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnDragOver_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.supported_op_bitmask = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnDragOver_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnDragOver_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.supported_op_bitmask);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnDragLeave_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnDragLeave_Params.prototype.initDefaults_ = function() {
    this.window = 0;
  };
  WindowTreeClient_OnDragLeave_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnDragLeave_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnDragLeave_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnDragLeave_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnDragLeave_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnDragLeave_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnDragLeave_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnCompleteDrop_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnCompleteDrop_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.key_state = 0;
    this.screen_position = null;
    this.effect_bitmask = 0;
  };
  WindowTreeClient_OnCompleteDrop_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnCompleteDrop_Params.validate = function(messageValidator, offset) {
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




    
    // validate WindowTreeClient_OnCompleteDrop_Params.screen_position
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Point, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  WindowTreeClient_OnCompleteDrop_Params.encodedSize = codec.kStructHeaderSize + 24;

  WindowTreeClient_OnCompleteDrop_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnCompleteDrop_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    val.key_state = decoder.decodeStruct(codec.Uint32);
    val.screen_position = decoder.decodeStructPointer(geometry$.Point);
    val.effect_bitmask = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnCompleteDrop_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnCompleteDrop_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    encoder.encodeStruct(codec.Uint32, val.key_state);
    encoder.encodeStructPointer(geometry$.Point, val.screen_position);
    encoder.encodeStruct(codec.Uint32, val.effect_bitmask);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnCompleteDrop_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnCompleteDrop_ResponseParams.prototype.initDefaults_ = function() {
    this.action_taken = 0;
  };
  WindowTreeClient_OnCompleteDrop_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnCompleteDrop_ResponseParams.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnCompleteDrop_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnCompleteDrop_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnCompleteDrop_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.action_taken = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnCompleteDrop_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnCompleteDrop_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.action_taken);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnPerformDragDropCompleted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnPerformDragDropCompleted_Params.prototype.initDefaults_ = function() {
    this.window = 0;
    this.success = false;
    this.action_taken = 0;
  };
  WindowTreeClient_OnPerformDragDropCompleted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnPerformDragDropCompleted_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnPerformDragDropCompleted_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTreeClient_OnPerformDragDropCompleted_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnPerformDragDropCompleted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.action_taken = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnPerformDragDropCompleted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnPerformDragDropCompleted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.action_taken);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_OnDragDropDone_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnDragDropDone_Params.prototype.initDefaults_ = function() {
  };
  WindowTreeClient_OnDragDropDone_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnDragDropDone_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnDragDropDone_Params.encodedSize = codec.kStructHeaderSize + 0;

  WindowTreeClient_OnDragDropDone_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnDragDropDone_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  WindowTreeClient_OnDragDropDone_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnDragDropDone_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function WindowTreeClient_OnChangeCompleted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_OnChangeCompleted_Params.prototype.initDefaults_ = function() {
    this.change_id = 0;
    this.success = false;
  };
  WindowTreeClient_OnChangeCompleted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_OnChangeCompleted_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_OnChangeCompleted_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_OnChangeCompleted_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_OnChangeCompleted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.change_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_OnChangeCompleted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_OnChangeCompleted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.change_id);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_RequestClose_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_RequestClose_Params.prototype.initDefaults_ = function() {
    this.window_id = 0;
  };
  WindowTreeClient_RequestClose_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_RequestClose_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_RequestClose_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_RequestClose_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_RequestClose_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_RequestClose_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_RequestClose_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.window_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeClient_GetWindowManager_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeClient_GetWindowManager_Params.prototype.initDefaults_ = function() {
    this.internal = null;
  };
  WindowTreeClient_GetWindowManager_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeClient_GetWindowManager_Params.validate = function(messageValidator, offset) {
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

  WindowTreeClient_GetWindowManager_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeClient_GetWindowManager_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeClient_GetWindowManager_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.internal = decoder.decodeStruct(codec.AssociatedInterfaceRequestNotSupported);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeClient_GetWindowManager_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeClient_GetWindowManager_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.AssociatedInterfaceRequestNotSupported, val.internal);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WindowTreeFactory_CreateWindowTree_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeFactory_CreateWindowTree_Params.prototype.initDefaults_ = function() {
    this.tree_request = new bindings.InterfaceRequest();
    this.client = new WindowTreeClientPtr();
  };
  WindowTreeFactory_CreateWindowTree_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeFactory_CreateWindowTree_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowTreeFactory_CreateWindowTree_Params.tree_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTreeFactory_CreateWindowTree_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeFactory_CreateWindowTree_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTreeFactory_CreateWindowTree_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeFactory_CreateWindowTree_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.tree_request = decoder.decodeStruct(codec.InterfaceRequest);
    val.client = decoder.decodeStruct(new codec.Interface(WindowTreeClientPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeFactory_CreateWindowTree_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeFactory_CreateWindowTree_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.tree_request);
    encoder.encodeStruct(new codec.Interface(WindowTreeClientPtr), val.client);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kWindowTree_NewWindow_Name = 0;
  var kWindowTree_NewTopLevelWindow_Name = 1;
  var kWindowTree_DeleteWindow_Name = 2;
  var kWindowTree_SetCapture_Name = 3;
  var kWindowTree_ReleaseCapture_Name = 4;
  var kWindowTree_StartPointerWatcher_Name = 5;
  var kWindowTree_StopPointerWatcher_Name = 6;
  var kWindowTree_SetWindowBounds_Name = 7;
  var kWindowTree_SetClientArea_Name = 8;
  var kWindowTree_SetHitTestMask_Name = 9;
  var kWindowTree_SetCanAcceptDrops_Name = 10;
  var kWindowTree_SetWindowVisibility_Name = 11;
  var kWindowTree_SetWindowProperty_Name = 12;
  var kWindowTree_SetWindowOpacity_Name = 13;
  var kWindowTree_AttachCompositorFrameSink_Name = 14;
  var kWindowTree_AddWindow_Name = 15;
  var kWindowTree_RemoveWindowFromParent_Name = 16;
  var kWindowTree_AddTransientWindow_Name = 17;
  var kWindowTree_RemoveTransientWindowFromParent_Name = 18;
  var kWindowTree_SetModal_Name = 19;
  var kWindowTree_ReorderWindow_Name = 20;
  var kWindowTree_GetWindowTree_Name = 21;
  var kWindowTree_Embed_Name = 22;
  var kWindowTree_SetFocus_Name = 23;
  var kWindowTree_SetCanFocus_Name = 24;
  var kWindowTree_SetPredefinedCursor_Name = 25;
  var kWindowTree_SetWindowTextInputState_Name = 26;
  var kWindowTree_SetImeVisibility_Name = 27;
  var kWindowTree_SetCanAcceptEvents_Name = 28;
  var kWindowTree_OnWindowInputEventAck_Name = 29;
  var kWindowTree_DeactivateWindow_Name = 30;
  var kWindowTree_GetWindowManagerClient_Name = 31;
  var kWindowTree_GetCursorLocationMemory_Name = 32;
  var kWindowTree_PerformWindowMove_Name = 33;
  var kWindowTree_CancelWindowMove_Name = 34;
  var kWindowTree_PerformDragDrop_Name = 35;
  var kWindowTree_CancelDragDrop_Name = 36;

  function WindowTreePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WindowTree,
                                                   handleOrPtrInfo);
  }

  function WindowTreeProxy(receiver) {
    this.receiver_ = receiver;
  }
  WindowTreePtr.prototype.newWindow = function() {
    return WindowTreeProxy.prototype.newWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.newWindow = function(change_id, window_id, properties) {
    var params = new WindowTree_NewWindow_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.properties = properties;
    var builder = new codec.MessageBuilder(
        kWindowTree_NewWindow_Name,
        codec.align(WindowTree_NewWindow_Params.encodedSize));
    builder.encodeStruct(WindowTree_NewWindow_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.newTopLevelWindow = function() {
    return WindowTreeProxy.prototype.newTopLevelWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.newTopLevelWindow = function(change_id, window_id, properties) {
    var params = new WindowTree_NewTopLevelWindow_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.properties = properties;
    var builder = new codec.MessageBuilder(
        kWindowTree_NewTopLevelWindow_Name,
        codec.align(WindowTree_NewTopLevelWindow_Params.encodedSize));
    builder.encodeStruct(WindowTree_NewTopLevelWindow_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.deleteWindow = function() {
    return WindowTreeProxy.prototype.deleteWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.deleteWindow = function(change_id, window_id) {
    var params = new WindowTree_DeleteWindow_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_DeleteWindow_Name,
        codec.align(WindowTree_DeleteWindow_Params.encodedSize));
    builder.encodeStruct(WindowTree_DeleteWindow_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setCapture = function() {
    return WindowTreeProxy.prototype.setCapture
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setCapture = function(change_id, window_id) {
    var params = new WindowTree_SetCapture_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetCapture_Name,
        codec.align(WindowTree_SetCapture_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetCapture_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.releaseCapture = function() {
    return WindowTreeProxy.prototype.releaseCapture
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.releaseCapture = function(change_id, window_id) {
    var params = new WindowTree_ReleaseCapture_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_ReleaseCapture_Name,
        codec.align(WindowTree_ReleaseCapture_Params.encodedSize));
    builder.encodeStruct(WindowTree_ReleaseCapture_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.startPointerWatcher = function() {
    return WindowTreeProxy.prototype.startPointerWatcher
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.startPointerWatcher = function(want_moves) {
    var params = new WindowTree_StartPointerWatcher_Params();
    params.want_moves = want_moves;
    var builder = new codec.MessageBuilder(
        kWindowTree_StartPointerWatcher_Name,
        codec.align(WindowTree_StartPointerWatcher_Params.encodedSize));
    builder.encodeStruct(WindowTree_StartPointerWatcher_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.stopPointerWatcher = function() {
    return WindowTreeProxy.prototype.stopPointerWatcher
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.stopPointerWatcher = function() {
    var params = new WindowTree_StopPointerWatcher_Params();
    var builder = new codec.MessageBuilder(
        kWindowTree_StopPointerWatcher_Name,
        codec.align(WindowTree_StopPointerWatcher_Params.encodedSize));
    builder.encodeStruct(WindowTree_StopPointerWatcher_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setWindowBounds = function() {
    return WindowTreeProxy.prototype.setWindowBounds
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setWindowBounds = function(change_id, window_id, bounds) {
    var params = new WindowTree_SetWindowBounds_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.bounds = bounds;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetWindowBounds_Name,
        codec.align(WindowTree_SetWindowBounds_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetWindowBounds_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setClientArea = function() {
    return WindowTreeProxy.prototype.setClientArea
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setClientArea = function(window_id, insets, additional_client_areas) {
    var params = new WindowTree_SetClientArea_Params();
    params.window_id = window_id;
    params.insets = insets;
    params.additional_client_areas = additional_client_areas;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetClientArea_Name,
        codec.align(WindowTree_SetClientArea_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetClientArea_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setHitTestMask = function() {
    return WindowTreeProxy.prototype.setHitTestMask
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setHitTestMask = function(window_id, mask) {
    var params = new WindowTree_SetHitTestMask_Params();
    params.window_id = window_id;
    params.mask = mask;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetHitTestMask_Name,
        codec.align(WindowTree_SetHitTestMask_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetHitTestMask_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setCanAcceptDrops = function() {
    return WindowTreeProxy.prototype.setCanAcceptDrops
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setCanAcceptDrops = function(window_id, accepts_drops) {
    var params = new WindowTree_SetCanAcceptDrops_Params();
    params.window_id = window_id;
    params.accepts_drops = accepts_drops;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetCanAcceptDrops_Name,
        codec.align(WindowTree_SetCanAcceptDrops_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetCanAcceptDrops_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setWindowVisibility = function() {
    return WindowTreeProxy.prototype.setWindowVisibility
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setWindowVisibility = function(change_id, window_id, visible) {
    var params = new WindowTree_SetWindowVisibility_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.visible = visible;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetWindowVisibility_Name,
        codec.align(WindowTree_SetWindowVisibility_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetWindowVisibility_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setWindowProperty = function() {
    return WindowTreeProxy.prototype.setWindowProperty
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setWindowProperty = function(change_id, window_id, name, value) {
    var params = new WindowTree_SetWindowProperty_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.name = name;
    params.value = value;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetWindowProperty_Name,
        codec.align(WindowTree_SetWindowProperty_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetWindowProperty_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setWindowOpacity = function() {
    return WindowTreeProxy.prototype.setWindowOpacity
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setWindowOpacity = function(change_id, window_id, opacity) {
    var params = new WindowTree_SetWindowOpacity_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.opacity = opacity;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetWindowOpacity_Name,
        codec.align(WindowTree_SetWindowOpacity_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetWindowOpacity_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.attachCompositorFrameSink = function() {
    return WindowTreeProxy.prototype.attachCompositorFrameSink
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.attachCompositorFrameSink = function(window_id, compositor_frame_sink, client) {
    var params = new WindowTree_AttachCompositorFrameSink_Params();
    params.window_id = window_id;
    params.compositor_frame_sink = compositor_frame_sink;
    params.client = client;
    var builder = new codec.MessageBuilder(
        kWindowTree_AttachCompositorFrameSink_Name,
        codec.align(WindowTree_AttachCompositorFrameSink_Params.encodedSize));
    builder.encodeStruct(WindowTree_AttachCompositorFrameSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.addWindow = function() {
    return WindowTreeProxy.prototype.addWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.addWindow = function(change_id, parent, child) {
    var params = new WindowTree_AddWindow_Params();
    params.change_id = change_id;
    params.parent = parent;
    params.child = child;
    var builder = new codec.MessageBuilder(
        kWindowTree_AddWindow_Name,
        codec.align(WindowTree_AddWindow_Params.encodedSize));
    builder.encodeStruct(WindowTree_AddWindow_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.removeWindowFromParent = function() {
    return WindowTreeProxy.prototype.removeWindowFromParent
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.removeWindowFromParent = function(change_id, window_id) {
    var params = new WindowTree_RemoveWindowFromParent_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_RemoveWindowFromParent_Name,
        codec.align(WindowTree_RemoveWindowFromParent_Params.encodedSize));
    builder.encodeStruct(WindowTree_RemoveWindowFromParent_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.addTransientWindow = function() {
    return WindowTreeProxy.prototype.addTransientWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.addTransientWindow = function(change_id, window_id, transient_window_id) {
    var params = new WindowTree_AddTransientWindow_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.transient_window_id = transient_window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_AddTransientWindow_Name,
        codec.align(WindowTree_AddTransientWindow_Params.encodedSize));
    builder.encodeStruct(WindowTree_AddTransientWindow_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.removeTransientWindowFromParent = function() {
    return WindowTreeProxy.prototype.removeTransientWindowFromParent
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.removeTransientWindowFromParent = function(change_id, transient_window_id) {
    var params = new WindowTree_RemoveTransientWindowFromParent_Params();
    params.change_id = change_id;
    params.transient_window_id = transient_window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_RemoveTransientWindowFromParent_Name,
        codec.align(WindowTree_RemoveTransientWindowFromParent_Params.encodedSize));
    builder.encodeStruct(WindowTree_RemoveTransientWindowFromParent_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setModal = function() {
    return WindowTreeProxy.prototype.setModal
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setModal = function(change_id, window_id) {
    var params = new WindowTree_SetModal_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetModal_Name,
        codec.align(WindowTree_SetModal_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetModal_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.reorderWindow = function() {
    return WindowTreeProxy.prototype.reorderWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.reorderWindow = function(change_id, window_id, relative_window_id, direction) {
    var params = new WindowTree_ReorderWindow_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.relative_window_id = relative_window_id;
    params.direction = direction;
    var builder = new codec.MessageBuilder(
        kWindowTree_ReorderWindow_Name,
        codec.align(WindowTree_ReorderWindow_Params.encodedSize));
    builder.encodeStruct(WindowTree_ReorderWindow_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.getWindowTree = function() {
    return WindowTreeProxy.prototype.getWindowTree
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.getWindowTree = function(window_id) {
    var params = new WindowTree_GetWindowTree_Params();
    params.window_id = window_id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWindowTree_GetWindowTree_Name,
          codec.align(WindowTree_GetWindowTree_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WindowTree_GetWindowTree_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WindowTree_GetWindowTree_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  WindowTreePtr.prototype.embed = function() {
    return WindowTreeProxy.prototype.embed
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.embed = function(window_id, client, embed_flags) {
    var params = new WindowTree_Embed_Params();
    params.window_id = window_id;
    params.client = client;
    params.embed_flags = embed_flags;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWindowTree_Embed_Name,
          codec.align(WindowTree_Embed_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WindowTree_Embed_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WindowTree_Embed_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  WindowTreePtr.prototype.setFocus = function() {
    return WindowTreeProxy.prototype.setFocus
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setFocus = function(change_id, window_id) {
    var params = new WindowTree_SetFocus_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetFocus_Name,
        codec.align(WindowTree_SetFocus_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetFocus_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setCanFocus = function() {
    return WindowTreeProxy.prototype.setCanFocus
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setCanFocus = function(window_id, can_focus) {
    var params = new WindowTree_SetCanFocus_Params();
    params.window_id = window_id;
    params.can_focus = can_focus;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetCanFocus_Name,
        codec.align(WindowTree_SetCanFocus_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetCanFocus_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setPredefinedCursor = function() {
    return WindowTreeProxy.prototype.setPredefinedCursor
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setPredefinedCursor = function(change_id, window_id, cursor_id) {
    var params = new WindowTree_SetPredefinedCursor_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.cursor_id = cursor_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetPredefinedCursor_Name,
        codec.align(WindowTree_SetPredefinedCursor_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetPredefinedCursor_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setWindowTextInputState = function() {
    return WindowTreeProxy.prototype.setWindowTextInputState
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setWindowTextInputState = function(window_id, state) {
    var params = new WindowTree_SetWindowTextInputState_Params();
    params.window_id = window_id;
    params.state = state;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetWindowTextInputState_Name,
        codec.align(WindowTree_SetWindowTextInputState_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetWindowTextInputState_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setImeVisibility = function() {
    return WindowTreeProxy.prototype.setImeVisibility
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setImeVisibility = function(window_id, visible, state) {
    var params = new WindowTree_SetImeVisibility_Params();
    params.window_id = window_id;
    params.visible = visible;
    params.state = state;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetImeVisibility_Name,
        codec.align(WindowTree_SetImeVisibility_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetImeVisibility_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.setCanAcceptEvents = function() {
    return WindowTreeProxy.prototype.setCanAcceptEvents
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.setCanAcceptEvents = function(window_id, accept_events) {
    var params = new WindowTree_SetCanAcceptEvents_Params();
    params.window_id = window_id;
    params.accept_events = accept_events;
    var builder = new codec.MessageBuilder(
        kWindowTree_SetCanAcceptEvents_Name,
        codec.align(WindowTree_SetCanAcceptEvents_Params.encodedSize));
    builder.encodeStruct(WindowTree_SetCanAcceptEvents_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.onWindowInputEventAck = function() {
    return WindowTreeProxy.prototype.onWindowInputEventAck
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.onWindowInputEventAck = function(event_id, result) {
    var params = new WindowTree_OnWindowInputEventAck_Params();
    params.event_id = event_id;
    params.result = result;
    var builder = new codec.MessageBuilder(
        kWindowTree_OnWindowInputEventAck_Name,
        codec.align(WindowTree_OnWindowInputEventAck_Params.encodedSize));
    builder.encodeStruct(WindowTree_OnWindowInputEventAck_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.deactivateWindow = function() {
    return WindowTreeProxy.prototype.deactivateWindow
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.deactivateWindow = function(window_id) {
    var params = new WindowTree_DeactivateWindow_Params();
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_DeactivateWindow_Name,
        codec.align(WindowTree_DeactivateWindow_Params.encodedSize));
    builder.encodeStruct(WindowTree_DeactivateWindow_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.getWindowManagerClient = function() {
    return WindowTreeProxy.prototype.getWindowManagerClient
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.getWindowManagerClient = function(internal) {
    var params = new WindowTree_GetWindowManagerClient_Params();
    params.internal = internal;
    var builder = new codec.MessageBuilder(
        kWindowTree_GetWindowManagerClient_Name,
        codec.align(WindowTree_GetWindowManagerClient_Params.encodedSize));
    builder.encodeStruct(WindowTree_GetWindowManagerClient_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.getCursorLocationMemory = function() {
    return WindowTreeProxy.prototype.getCursorLocationMemory
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.getCursorLocationMemory = function() {
    var params = new WindowTree_GetCursorLocationMemory_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWindowTree_GetCursorLocationMemory_Name,
          codec.align(WindowTree_GetCursorLocationMemory_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WindowTree_GetCursorLocationMemory_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WindowTree_GetCursorLocationMemory_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  WindowTreePtr.prototype.performWindowMove = function() {
    return WindowTreeProxy.prototype.performWindowMove
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.performWindowMove = function(change_id, window_id, source, cursor) {
    var params = new WindowTree_PerformWindowMove_Params();
    params.change_id = change_id;
    params.window_id = window_id;
    params.source = source;
    params.cursor = cursor;
    var builder = new codec.MessageBuilder(
        kWindowTree_PerformWindowMove_Name,
        codec.align(WindowTree_PerformWindowMove_Params.encodedSize));
    builder.encodeStruct(WindowTree_PerformWindowMove_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.cancelWindowMove = function() {
    return WindowTreeProxy.prototype.cancelWindowMove
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.cancelWindowMove = function(window_id) {
    var params = new WindowTree_CancelWindowMove_Params();
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_CancelWindowMove_Name,
        codec.align(WindowTree_CancelWindowMove_Params.encodedSize));
    builder.encodeStruct(WindowTree_CancelWindowMove_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.performDragDrop = function() {
    return WindowTreeProxy.prototype.performDragDrop
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.performDragDrop = function(change_id, source_window_id, drag_data, drag_operation) {
    var params = new WindowTree_PerformDragDrop_Params();
    params.change_id = change_id;
    params.source_window_id = source_window_id;
    params.drag_data = drag_data;
    params.drag_operation = drag_operation;
    var builder = new codec.MessageBuilder(
        kWindowTree_PerformDragDrop_Name,
        codec.align(WindowTree_PerformDragDrop_Params.encodedSize));
    builder.encodeStruct(WindowTree_PerformDragDrop_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreePtr.prototype.cancelDragDrop = function() {
    return WindowTreeProxy.prototype.cancelDragDrop
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeProxy.prototype.cancelDragDrop = function(window_id) {
    var params = new WindowTree_CancelDragDrop_Params();
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTree_CancelDragDrop_Name,
        codec.align(WindowTree_CancelDragDrop_Params.encodedSize));
    builder.encodeStruct(WindowTree_CancelDragDrop_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function WindowTreeStub(delegate) {
    this.delegate_ = delegate;
  }
  WindowTreeStub.prototype.newWindow = function(change_id, window_id, properties) {
    return this.delegate_ && this.delegate_.newWindow && this.delegate_.newWindow(change_id, window_id, properties);
  }
  WindowTreeStub.prototype.newTopLevelWindow = function(change_id, window_id, properties) {
    return this.delegate_ && this.delegate_.newTopLevelWindow && this.delegate_.newTopLevelWindow(change_id, window_id, properties);
  }
  WindowTreeStub.prototype.deleteWindow = function(change_id, window_id) {
    return this.delegate_ && this.delegate_.deleteWindow && this.delegate_.deleteWindow(change_id, window_id);
  }
  WindowTreeStub.prototype.setCapture = function(change_id, window_id) {
    return this.delegate_ && this.delegate_.setCapture && this.delegate_.setCapture(change_id, window_id);
  }
  WindowTreeStub.prototype.releaseCapture = function(change_id, window_id) {
    return this.delegate_ && this.delegate_.releaseCapture && this.delegate_.releaseCapture(change_id, window_id);
  }
  WindowTreeStub.prototype.startPointerWatcher = function(want_moves) {
    return this.delegate_ && this.delegate_.startPointerWatcher && this.delegate_.startPointerWatcher(want_moves);
  }
  WindowTreeStub.prototype.stopPointerWatcher = function() {
    return this.delegate_ && this.delegate_.stopPointerWatcher && this.delegate_.stopPointerWatcher();
  }
  WindowTreeStub.prototype.setWindowBounds = function(change_id, window_id, bounds) {
    return this.delegate_ && this.delegate_.setWindowBounds && this.delegate_.setWindowBounds(change_id, window_id, bounds);
  }
  WindowTreeStub.prototype.setClientArea = function(window_id, insets, additional_client_areas) {
    return this.delegate_ && this.delegate_.setClientArea && this.delegate_.setClientArea(window_id, insets, additional_client_areas);
  }
  WindowTreeStub.prototype.setHitTestMask = function(window_id, mask) {
    return this.delegate_ && this.delegate_.setHitTestMask && this.delegate_.setHitTestMask(window_id, mask);
  }
  WindowTreeStub.prototype.setCanAcceptDrops = function(window_id, accepts_drops) {
    return this.delegate_ && this.delegate_.setCanAcceptDrops && this.delegate_.setCanAcceptDrops(window_id, accepts_drops);
  }
  WindowTreeStub.prototype.setWindowVisibility = function(change_id, window_id, visible) {
    return this.delegate_ && this.delegate_.setWindowVisibility && this.delegate_.setWindowVisibility(change_id, window_id, visible);
  }
  WindowTreeStub.prototype.setWindowProperty = function(change_id, window_id, name, value) {
    return this.delegate_ && this.delegate_.setWindowProperty && this.delegate_.setWindowProperty(change_id, window_id, name, value);
  }
  WindowTreeStub.prototype.setWindowOpacity = function(change_id, window_id, opacity) {
    return this.delegate_ && this.delegate_.setWindowOpacity && this.delegate_.setWindowOpacity(change_id, window_id, opacity);
  }
  WindowTreeStub.prototype.attachCompositorFrameSink = function(window_id, compositor_frame_sink, client) {
    return this.delegate_ && this.delegate_.attachCompositorFrameSink && this.delegate_.attachCompositorFrameSink(window_id, compositor_frame_sink, client);
  }
  WindowTreeStub.prototype.addWindow = function(change_id, parent, child) {
    return this.delegate_ && this.delegate_.addWindow && this.delegate_.addWindow(change_id, parent, child);
  }
  WindowTreeStub.prototype.removeWindowFromParent = function(change_id, window_id) {
    return this.delegate_ && this.delegate_.removeWindowFromParent && this.delegate_.removeWindowFromParent(change_id, window_id);
  }
  WindowTreeStub.prototype.addTransientWindow = function(change_id, window_id, transient_window_id) {
    return this.delegate_ && this.delegate_.addTransientWindow && this.delegate_.addTransientWindow(change_id, window_id, transient_window_id);
  }
  WindowTreeStub.prototype.removeTransientWindowFromParent = function(change_id, transient_window_id) {
    return this.delegate_ && this.delegate_.removeTransientWindowFromParent && this.delegate_.removeTransientWindowFromParent(change_id, transient_window_id);
  }
  WindowTreeStub.prototype.setModal = function(change_id, window_id) {
    return this.delegate_ && this.delegate_.setModal && this.delegate_.setModal(change_id, window_id);
  }
  WindowTreeStub.prototype.reorderWindow = function(change_id, window_id, relative_window_id, direction) {
    return this.delegate_ && this.delegate_.reorderWindow && this.delegate_.reorderWindow(change_id, window_id, relative_window_id, direction);
  }
  WindowTreeStub.prototype.getWindowTree = function(window_id) {
    return this.delegate_ && this.delegate_.getWindowTree && this.delegate_.getWindowTree(window_id);
  }
  WindowTreeStub.prototype.embed = function(window_id, client, embed_flags) {
    return this.delegate_ && this.delegate_.embed && this.delegate_.embed(window_id, client, embed_flags);
  }
  WindowTreeStub.prototype.setFocus = function(change_id, window_id) {
    return this.delegate_ && this.delegate_.setFocus && this.delegate_.setFocus(change_id, window_id);
  }
  WindowTreeStub.prototype.setCanFocus = function(window_id, can_focus) {
    return this.delegate_ && this.delegate_.setCanFocus && this.delegate_.setCanFocus(window_id, can_focus);
  }
  WindowTreeStub.prototype.setPredefinedCursor = function(change_id, window_id, cursor_id) {
    return this.delegate_ && this.delegate_.setPredefinedCursor && this.delegate_.setPredefinedCursor(change_id, window_id, cursor_id);
  }
  WindowTreeStub.prototype.setWindowTextInputState = function(window_id, state) {
    return this.delegate_ && this.delegate_.setWindowTextInputState && this.delegate_.setWindowTextInputState(window_id, state);
  }
  WindowTreeStub.prototype.setImeVisibility = function(window_id, visible, state) {
    return this.delegate_ && this.delegate_.setImeVisibility && this.delegate_.setImeVisibility(window_id, visible, state);
  }
  WindowTreeStub.prototype.setCanAcceptEvents = function(window_id, accept_events) {
    return this.delegate_ && this.delegate_.setCanAcceptEvents && this.delegate_.setCanAcceptEvents(window_id, accept_events);
  }
  WindowTreeStub.prototype.onWindowInputEventAck = function(event_id, result) {
    return this.delegate_ && this.delegate_.onWindowInputEventAck && this.delegate_.onWindowInputEventAck(event_id, result);
  }
  WindowTreeStub.prototype.deactivateWindow = function(window_id) {
    return this.delegate_ && this.delegate_.deactivateWindow && this.delegate_.deactivateWindow(window_id);
  }
  WindowTreeStub.prototype.getWindowManagerClient = function(internal) {
    return this.delegate_ && this.delegate_.getWindowManagerClient && this.delegate_.getWindowManagerClient(internal);
  }
  WindowTreeStub.prototype.getCursorLocationMemory = function() {
    return this.delegate_ && this.delegate_.getCursorLocationMemory && this.delegate_.getCursorLocationMemory();
  }
  WindowTreeStub.prototype.performWindowMove = function(change_id, window_id, source, cursor) {
    return this.delegate_ && this.delegate_.performWindowMove && this.delegate_.performWindowMove(change_id, window_id, source, cursor);
  }
  WindowTreeStub.prototype.cancelWindowMove = function(window_id) {
    return this.delegate_ && this.delegate_.cancelWindowMove && this.delegate_.cancelWindowMove(window_id);
  }
  WindowTreeStub.prototype.performDragDrop = function(change_id, source_window_id, drag_data, drag_operation) {
    return this.delegate_ && this.delegate_.performDragDrop && this.delegate_.performDragDrop(change_id, source_window_id, drag_data, drag_operation);
  }
  WindowTreeStub.prototype.cancelDragDrop = function(window_id) {
    return this.delegate_ && this.delegate_.cancelDragDrop && this.delegate_.cancelDragDrop(window_id);
  }

  WindowTreeStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowTree_NewWindow_Name:
      var params = reader.decodeStruct(WindowTree_NewWindow_Params);
      this.newWindow(params.change_id, params.window_id, params.properties);
      return true;
    case kWindowTree_NewTopLevelWindow_Name:
      var params = reader.decodeStruct(WindowTree_NewTopLevelWindow_Params);
      this.newTopLevelWindow(params.change_id, params.window_id, params.properties);
      return true;
    case kWindowTree_DeleteWindow_Name:
      var params = reader.decodeStruct(WindowTree_DeleteWindow_Params);
      this.deleteWindow(params.change_id, params.window_id);
      return true;
    case kWindowTree_SetCapture_Name:
      var params = reader.decodeStruct(WindowTree_SetCapture_Params);
      this.setCapture(params.change_id, params.window_id);
      return true;
    case kWindowTree_ReleaseCapture_Name:
      var params = reader.decodeStruct(WindowTree_ReleaseCapture_Params);
      this.releaseCapture(params.change_id, params.window_id);
      return true;
    case kWindowTree_StartPointerWatcher_Name:
      var params = reader.decodeStruct(WindowTree_StartPointerWatcher_Params);
      this.startPointerWatcher(params.want_moves);
      return true;
    case kWindowTree_StopPointerWatcher_Name:
      var params = reader.decodeStruct(WindowTree_StopPointerWatcher_Params);
      this.stopPointerWatcher();
      return true;
    case kWindowTree_SetWindowBounds_Name:
      var params = reader.decodeStruct(WindowTree_SetWindowBounds_Params);
      this.setWindowBounds(params.change_id, params.window_id, params.bounds);
      return true;
    case kWindowTree_SetClientArea_Name:
      var params = reader.decodeStruct(WindowTree_SetClientArea_Params);
      this.setClientArea(params.window_id, params.insets, params.additional_client_areas);
      return true;
    case kWindowTree_SetHitTestMask_Name:
      var params = reader.decodeStruct(WindowTree_SetHitTestMask_Params);
      this.setHitTestMask(params.window_id, params.mask);
      return true;
    case kWindowTree_SetCanAcceptDrops_Name:
      var params = reader.decodeStruct(WindowTree_SetCanAcceptDrops_Params);
      this.setCanAcceptDrops(params.window_id, params.accepts_drops);
      return true;
    case kWindowTree_SetWindowVisibility_Name:
      var params = reader.decodeStruct(WindowTree_SetWindowVisibility_Params);
      this.setWindowVisibility(params.change_id, params.window_id, params.visible);
      return true;
    case kWindowTree_SetWindowProperty_Name:
      var params = reader.decodeStruct(WindowTree_SetWindowProperty_Params);
      this.setWindowProperty(params.change_id, params.window_id, params.name, params.value);
      return true;
    case kWindowTree_SetWindowOpacity_Name:
      var params = reader.decodeStruct(WindowTree_SetWindowOpacity_Params);
      this.setWindowOpacity(params.change_id, params.window_id, params.opacity);
      return true;
    case kWindowTree_AttachCompositorFrameSink_Name:
      var params = reader.decodeStruct(WindowTree_AttachCompositorFrameSink_Params);
      this.attachCompositorFrameSink(params.window_id, params.compositor_frame_sink, params.client);
      return true;
    case kWindowTree_AddWindow_Name:
      var params = reader.decodeStruct(WindowTree_AddWindow_Params);
      this.addWindow(params.change_id, params.parent, params.child);
      return true;
    case kWindowTree_RemoveWindowFromParent_Name:
      var params = reader.decodeStruct(WindowTree_RemoveWindowFromParent_Params);
      this.removeWindowFromParent(params.change_id, params.window_id);
      return true;
    case kWindowTree_AddTransientWindow_Name:
      var params = reader.decodeStruct(WindowTree_AddTransientWindow_Params);
      this.addTransientWindow(params.change_id, params.window_id, params.transient_window_id);
      return true;
    case kWindowTree_RemoveTransientWindowFromParent_Name:
      var params = reader.decodeStruct(WindowTree_RemoveTransientWindowFromParent_Params);
      this.removeTransientWindowFromParent(params.change_id, params.transient_window_id);
      return true;
    case kWindowTree_SetModal_Name:
      var params = reader.decodeStruct(WindowTree_SetModal_Params);
      this.setModal(params.change_id, params.window_id);
      return true;
    case kWindowTree_ReorderWindow_Name:
      var params = reader.decodeStruct(WindowTree_ReorderWindow_Params);
      this.reorderWindow(params.change_id, params.window_id, params.relative_window_id, params.direction);
      return true;
    case kWindowTree_SetFocus_Name:
      var params = reader.decodeStruct(WindowTree_SetFocus_Params);
      this.setFocus(params.change_id, params.window_id);
      return true;
    case kWindowTree_SetCanFocus_Name:
      var params = reader.decodeStruct(WindowTree_SetCanFocus_Params);
      this.setCanFocus(params.window_id, params.can_focus);
      return true;
    case kWindowTree_SetPredefinedCursor_Name:
      var params = reader.decodeStruct(WindowTree_SetPredefinedCursor_Params);
      this.setPredefinedCursor(params.change_id, params.window_id, params.cursor_id);
      return true;
    case kWindowTree_SetWindowTextInputState_Name:
      var params = reader.decodeStruct(WindowTree_SetWindowTextInputState_Params);
      this.setWindowTextInputState(params.window_id, params.state);
      return true;
    case kWindowTree_SetImeVisibility_Name:
      var params = reader.decodeStruct(WindowTree_SetImeVisibility_Params);
      this.setImeVisibility(params.window_id, params.visible, params.state);
      return true;
    case kWindowTree_SetCanAcceptEvents_Name:
      var params = reader.decodeStruct(WindowTree_SetCanAcceptEvents_Params);
      this.setCanAcceptEvents(params.window_id, params.accept_events);
      return true;
    case kWindowTree_OnWindowInputEventAck_Name:
      var params = reader.decodeStruct(WindowTree_OnWindowInputEventAck_Params);
      this.onWindowInputEventAck(params.event_id, params.result);
      return true;
    case kWindowTree_DeactivateWindow_Name:
      var params = reader.decodeStruct(WindowTree_DeactivateWindow_Params);
      this.deactivateWindow(params.window_id);
      return true;
    case kWindowTree_GetWindowManagerClient_Name:
      var params = reader.decodeStruct(WindowTree_GetWindowManagerClient_Params);
      this.getWindowManagerClient(params.internal);
      return true;
    case kWindowTree_PerformWindowMove_Name:
      var params = reader.decodeStruct(WindowTree_PerformWindowMove_Params);
      this.performWindowMove(params.change_id, params.window_id, params.source, params.cursor);
      return true;
    case kWindowTree_CancelWindowMove_Name:
      var params = reader.decodeStruct(WindowTree_CancelWindowMove_Params);
      this.cancelWindowMove(params.window_id);
      return true;
    case kWindowTree_PerformDragDrop_Name:
      var params = reader.decodeStruct(WindowTree_PerformDragDrop_Params);
      this.performDragDrop(params.change_id, params.source_window_id, params.drag_data, params.drag_operation);
      return true;
    case kWindowTree_CancelDragDrop_Name:
      var params = reader.decodeStruct(WindowTree_CancelDragDrop_Params);
      this.cancelDragDrop(params.window_id);
      return true;
    default:
      return false;
    }
  };

  WindowTreeStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowTree_GetWindowTree_Name:
      var params = reader.decodeStruct(WindowTree_GetWindowTree_Params);
      return this.getWindowTree(params.window_id).then(function(response) {
        var responseParams =
            new WindowTree_GetWindowTree_ResponseParams();
        responseParams.windows = response.windows;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWindowTree_GetWindowTree_Name,
            codec.align(WindowTree_GetWindowTree_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WindowTree_GetWindowTree_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kWindowTree_Embed_Name:
      var params = reader.decodeStruct(WindowTree_Embed_Params);
      return this.embed(params.window_id, params.client, params.embed_flags).then(function(response) {
        var responseParams =
            new WindowTree_Embed_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWindowTree_Embed_Name,
            codec.align(WindowTree_Embed_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WindowTree_Embed_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kWindowTree_GetCursorLocationMemory_Name:
      var params = reader.decodeStruct(WindowTree_GetCursorLocationMemory_Params);
      return this.getCursorLocationMemory().then(function(response) {
        var responseParams =
            new WindowTree_GetCursorLocationMemory_ResponseParams();
        responseParams.cursor_buffer = response.cursor_buffer;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWindowTree_GetCursorLocationMemory_Name,
            codec.align(WindowTree_GetCursorLocationMemory_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WindowTree_GetCursorLocationMemory_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWindowTreeRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWindowTree_NewWindow_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_NewWindow_Params;
      break;
      case kWindowTree_NewTopLevelWindow_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_NewTopLevelWindow_Params;
      break;
      case kWindowTree_DeleteWindow_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_DeleteWindow_Params;
      break;
      case kWindowTree_SetCapture_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetCapture_Params;
      break;
      case kWindowTree_ReleaseCapture_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_ReleaseCapture_Params;
      break;
      case kWindowTree_StartPointerWatcher_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_StartPointerWatcher_Params;
      break;
      case kWindowTree_StopPointerWatcher_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_StopPointerWatcher_Params;
      break;
      case kWindowTree_SetWindowBounds_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetWindowBounds_Params;
      break;
      case kWindowTree_SetClientArea_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetClientArea_Params;
      break;
      case kWindowTree_SetHitTestMask_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetHitTestMask_Params;
      break;
      case kWindowTree_SetCanAcceptDrops_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetCanAcceptDrops_Params;
      break;
      case kWindowTree_SetWindowVisibility_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetWindowVisibility_Params;
      break;
      case kWindowTree_SetWindowProperty_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetWindowProperty_Params;
      break;
      case kWindowTree_SetWindowOpacity_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetWindowOpacity_Params;
      break;
      case kWindowTree_AttachCompositorFrameSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_AttachCompositorFrameSink_Params;
      break;
      case kWindowTree_AddWindow_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_AddWindow_Params;
      break;
      case kWindowTree_RemoveWindowFromParent_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_RemoveWindowFromParent_Params;
      break;
      case kWindowTree_AddTransientWindow_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_AddTransientWindow_Params;
      break;
      case kWindowTree_RemoveTransientWindowFromParent_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_RemoveTransientWindowFromParent_Params;
      break;
      case kWindowTree_SetModal_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetModal_Params;
      break;
      case kWindowTree_ReorderWindow_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_ReorderWindow_Params;
      break;
      case kWindowTree_GetWindowTree_Name:
        if (message.expectsResponse())
          paramsClass = WindowTree_GetWindowTree_Params;
      break;
      case kWindowTree_Embed_Name:
        if (message.expectsResponse())
          paramsClass = WindowTree_Embed_Params;
      break;
      case kWindowTree_SetFocus_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetFocus_Params;
      break;
      case kWindowTree_SetCanFocus_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetCanFocus_Params;
      break;
      case kWindowTree_SetPredefinedCursor_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetPredefinedCursor_Params;
      break;
      case kWindowTree_SetWindowTextInputState_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetWindowTextInputState_Params;
      break;
      case kWindowTree_SetImeVisibility_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetImeVisibility_Params;
      break;
      case kWindowTree_SetCanAcceptEvents_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_SetCanAcceptEvents_Params;
      break;
      case kWindowTree_OnWindowInputEventAck_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_OnWindowInputEventAck_Params;
      break;
      case kWindowTree_DeactivateWindow_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_DeactivateWindow_Params;
      break;
      case kWindowTree_GetWindowManagerClient_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_GetWindowManagerClient_Params;
      break;
      case kWindowTree_GetCursorLocationMemory_Name:
        if (message.expectsResponse())
          paramsClass = WindowTree_GetCursorLocationMemory_Params;
      break;
      case kWindowTree_PerformWindowMove_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_PerformWindowMove_Params;
      break;
      case kWindowTree_CancelWindowMove_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_CancelWindowMove_Params;
      break;
      case kWindowTree_PerformDragDrop_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_PerformDragDrop_Params;
      break;
      case kWindowTree_CancelDragDrop_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTree_CancelDragDrop_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWindowTreeResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kWindowTree_GetWindowTree_Name:
        if (message.isResponse())
          paramsClass = WindowTree_GetWindowTree_ResponseParams;
        break;
      case kWindowTree_Embed_Name:
        if (message.isResponse())
          paramsClass = WindowTree_Embed_ResponseParams;
        break;
      case kWindowTree_GetCursorLocationMemory_Name:
        if (message.isResponse())
          paramsClass = WindowTree_GetCursorLocationMemory_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var WindowTree = {
    name: 'ui::mojom::WindowTree',
    ptrClass: WindowTreePtr,
    proxyClass: WindowTreeProxy,
    stubClass: WindowTreeStub,
    validateRequest: validateWindowTreeRequest,
    validateResponse: validateWindowTreeResponse,
  };
  WindowTreeStub.prototype.validator = validateWindowTreeRequest;
  WindowTreeProxy.prototype.validator = validateWindowTreeResponse;
  var kWindowTreeClient_OnEmbed_Name = 0;
  var kWindowTreeClient_OnEmbeddedAppDisconnected_Name = 1;
  var kWindowTreeClient_OnUnembed_Name = 2;
  var kWindowTreeClient_OnCaptureChanged_Name = 3;
  var kWindowTreeClient_OnTopLevelCreated_Name = 4;
  var kWindowTreeClient_OnWindowBoundsChanged_Name = 5;
  var kWindowTreeClient_OnClientAreaChanged_Name = 6;
  var kWindowTreeClient_OnTransientWindowAdded_Name = 7;
  var kWindowTreeClient_OnTransientWindowRemoved_Name = 8;
  var kWindowTreeClient_OnWindowHierarchyChanged_Name = 9;
  var kWindowTreeClient_OnWindowReordered_Name = 10;
  var kWindowTreeClient_OnWindowDeleted_Name = 11;
  var kWindowTreeClient_OnWindowVisibilityChanged_Name = 12;
  var kWindowTreeClient_OnWindowOpacityChanged_Name = 13;
  var kWindowTreeClient_OnWindowParentDrawnStateChanged_Name = 14;
  var kWindowTreeClient_OnWindowSharedPropertyChanged_Name = 15;
  var kWindowTreeClient_OnWindowInputEvent_Name = 16;
  var kWindowTreeClient_OnPointerEventObserved_Name = 17;
  var kWindowTreeClient_OnWindowFocused_Name = 18;
  var kWindowTreeClient_OnWindowPredefinedCursorChanged_Name = 19;
  var kWindowTreeClient_OnWindowSurfaceChanged_Name = 20;
  var kWindowTreeClient_OnDragDropStart_Name = 21;
  var kWindowTreeClient_OnDragEnter_Name = 22;
  var kWindowTreeClient_OnDragOver_Name = 23;
  var kWindowTreeClient_OnDragLeave_Name = 24;
  var kWindowTreeClient_OnCompleteDrop_Name = 25;
  var kWindowTreeClient_OnPerformDragDropCompleted_Name = 26;
  var kWindowTreeClient_OnDragDropDone_Name = 27;
  var kWindowTreeClient_OnChangeCompleted_Name = 28;
  var kWindowTreeClient_RequestClose_Name = 29;
  var kWindowTreeClient_GetWindowManager_Name = 30;

  function WindowTreeClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WindowTreeClient,
                                                   handleOrPtrInfo);
  }

  function WindowTreeClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  WindowTreeClientPtr.prototype.onEmbed = function() {
    return WindowTreeClientProxy.prototype.onEmbed
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onEmbed = function(connection_id, root, tree, display_id, focused_window, parent_drawn) {
    var params = new WindowTreeClient_OnEmbed_Params();
    params.connection_id = connection_id;
    params.root = root;
    params.tree = tree;
    params.display_id = display_id;
    params.focused_window = focused_window;
    params.parent_drawn = parent_drawn;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnEmbed_Name,
        codec.align(WindowTreeClient_OnEmbed_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnEmbed_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onEmbeddedAppDisconnected = function() {
    return WindowTreeClientProxy.prototype.onEmbeddedAppDisconnected
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onEmbeddedAppDisconnected = function(window) {
    var params = new WindowTreeClient_OnEmbeddedAppDisconnected_Params();
    params.window = window;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnEmbeddedAppDisconnected_Name,
        codec.align(WindowTreeClient_OnEmbeddedAppDisconnected_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnEmbeddedAppDisconnected_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onUnembed = function() {
    return WindowTreeClientProxy.prototype.onUnembed
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onUnembed = function(window) {
    var params = new WindowTreeClient_OnUnembed_Params();
    params.window = window;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnUnembed_Name,
        codec.align(WindowTreeClient_OnUnembed_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnUnembed_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onCaptureChanged = function() {
    return WindowTreeClientProxy.prototype.onCaptureChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onCaptureChanged = function(new_capture, old_capture) {
    var params = new WindowTreeClient_OnCaptureChanged_Params();
    params.new_capture = new_capture;
    params.old_capture = old_capture;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnCaptureChanged_Name,
        codec.align(WindowTreeClient_OnCaptureChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnCaptureChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onTopLevelCreated = function() {
    return WindowTreeClientProxy.prototype.onTopLevelCreated
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onTopLevelCreated = function(change_id, data, display_id, parent_drawn) {
    var params = new WindowTreeClient_OnTopLevelCreated_Params();
    params.change_id = change_id;
    params.data = data;
    params.display_id = display_id;
    params.parent_drawn = parent_drawn;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnTopLevelCreated_Name,
        codec.align(WindowTreeClient_OnTopLevelCreated_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnTopLevelCreated_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowBoundsChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowBoundsChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowBoundsChanged = function(window, old_bounds, new_bounds) {
    var params = new WindowTreeClient_OnWindowBoundsChanged_Params();
    params.window = window;
    params.old_bounds = old_bounds;
    params.new_bounds = new_bounds;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowBoundsChanged_Name,
        codec.align(WindowTreeClient_OnWindowBoundsChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowBoundsChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onClientAreaChanged = function() {
    return WindowTreeClientProxy.prototype.onClientAreaChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onClientAreaChanged = function(window_id, new_client_area, new_additional_client_areas) {
    var params = new WindowTreeClient_OnClientAreaChanged_Params();
    params.window_id = window_id;
    params.new_client_area = new_client_area;
    params.new_additional_client_areas = new_additional_client_areas;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnClientAreaChanged_Name,
        codec.align(WindowTreeClient_OnClientAreaChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnClientAreaChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onTransientWindowAdded = function() {
    return WindowTreeClientProxy.prototype.onTransientWindowAdded
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onTransientWindowAdded = function(window_id, transient_window_id) {
    var params = new WindowTreeClient_OnTransientWindowAdded_Params();
    params.window_id = window_id;
    params.transient_window_id = transient_window_id;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnTransientWindowAdded_Name,
        codec.align(WindowTreeClient_OnTransientWindowAdded_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnTransientWindowAdded_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onTransientWindowRemoved = function() {
    return WindowTreeClientProxy.prototype.onTransientWindowRemoved
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onTransientWindowRemoved = function(window_id, transient_window_id) {
    var params = new WindowTreeClient_OnTransientWindowRemoved_Params();
    params.window_id = window_id;
    params.transient_window_id = transient_window_id;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnTransientWindowRemoved_Name,
        codec.align(WindowTreeClient_OnTransientWindowRemoved_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnTransientWindowRemoved_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowHierarchyChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowHierarchyChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowHierarchyChanged = function(window, old_parent, new_parent, windows) {
    var params = new WindowTreeClient_OnWindowHierarchyChanged_Params();
    params.window = window;
    params.old_parent = old_parent;
    params.new_parent = new_parent;
    params.windows = windows;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowHierarchyChanged_Name,
        codec.align(WindowTreeClient_OnWindowHierarchyChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowHierarchyChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowReordered = function() {
    return WindowTreeClientProxy.prototype.onWindowReordered
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowReordered = function(window_id, relative_window_id, direction) {
    var params = new WindowTreeClient_OnWindowReordered_Params();
    params.window_id = window_id;
    params.relative_window_id = relative_window_id;
    params.direction = direction;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowReordered_Name,
        codec.align(WindowTreeClient_OnWindowReordered_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowReordered_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowDeleted = function() {
    return WindowTreeClientProxy.prototype.onWindowDeleted
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowDeleted = function(window) {
    var params = new WindowTreeClient_OnWindowDeleted_Params();
    params.window = window;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowDeleted_Name,
        codec.align(WindowTreeClient_OnWindowDeleted_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowDeleted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowVisibilityChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowVisibilityChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowVisibilityChanged = function(window, visible) {
    var params = new WindowTreeClient_OnWindowVisibilityChanged_Params();
    params.window = window;
    params.visible = visible;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowVisibilityChanged_Name,
        codec.align(WindowTreeClient_OnWindowVisibilityChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowVisibilityChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowOpacityChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowOpacityChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowOpacityChanged = function(window, old_opacity, new_opacity) {
    var params = new WindowTreeClient_OnWindowOpacityChanged_Params();
    params.window = window;
    params.old_opacity = old_opacity;
    params.new_opacity = new_opacity;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowOpacityChanged_Name,
        codec.align(WindowTreeClient_OnWindowOpacityChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowOpacityChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowParentDrawnStateChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowParentDrawnStateChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowParentDrawnStateChanged = function(window, drawn) {
    var params = new WindowTreeClient_OnWindowParentDrawnStateChanged_Params();
    params.window = window;
    params.drawn = drawn;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowParentDrawnStateChanged_Name,
        codec.align(WindowTreeClient_OnWindowParentDrawnStateChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowParentDrawnStateChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowSharedPropertyChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowSharedPropertyChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowSharedPropertyChanged = function(window, name, new_data) {
    var params = new WindowTreeClient_OnWindowSharedPropertyChanged_Params();
    params.window = window;
    params.name = name;
    params.new_data = new_data;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowSharedPropertyChanged_Name,
        codec.align(WindowTreeClient_OnWindowSharedPropertyChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowSharedPropertyChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowInputEvent = function() {
    return WindowTreeClientProxy.prototype.onWindowInputEvent
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowInputEvent = function(event_id, window, event, matches_pointer_watcher) {
    var params = new WindowTreeClient_OnWindowInputEvent_Params();
    params.event_id = event_id;
    params.window = window;
    params.event = event;
    params.matches_pointer_watcher = matches_pointer_watcher;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowInputEvent_Name,
        codec.align(WindowTreeClient_OnWindowInputEvent_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowInputEvent_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onPointerEventObserved = function() {
    return WindowTreeClientProxy.prototype.onPointerEventObserved
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onPointerEventObserved = function(event, window_id) {
    var params = new WindowTreeClient_OnPointerEventObserved_Params();
    params.event = event;
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnPointerEventObserved_Name,
        codec.align(WindowTreeClient_OnPointerEventObserved_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnPointerEventObserved_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowFocused = function() {
    return WindowTreeClientProxy.prototype.onWindowFocused
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowFocused = function(focused_window_id) {
    var params = new WindowTreeClient_OnWindowFocused_Params();
    params.focused_window_id = focused_window_id;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowFocused_Name,
        codec.align(WindowTreeClient_OnWindowFocused_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowFocused_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowPredefinedCursorChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowPredefinedCursorChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowPredefinedCursorChanged = function(window_id, cursor_id) {
    var params = new WindowTreeClient_OnWindowPredefinedCursorChanged_Params();
    params.window_id = window_id;
    params.cursor_id = cursor_id;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowPredefinedCursorChanged_Name,
        codec.align(WindowTreeClient_OnWindowPredefinedCursorChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowPredefinedCursorChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onWindowSurfaceChanged = function() {
    return WindowTreeClientProxy.prototype.onWindowSurfaceChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onWindowSurfaceChanged = function(window_id, surface_info) {
    var params = new WindowTreeClient_OnWindowSurfaceChanged_Params();
    params.window_id = window_id;
    params.surface_info = surface_info;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnWindowSurfaceChanged_Name,
        codec.align(WindowTreeClient_OnWindowSurfaceChanged_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnWindowSurfaceChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onDragDropStart = function() {
    return WindowTreeClientProxy.prototype.onDragDropStart
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onDragDropStart = function(drag_data) {
    var params = new WindowTreeClient_OnDragDropStart_Params();
    params.drag_data = drag_data;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnDragDropStart_Name,
        codec.align(WindowTreeClient_OnDragDropStart_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnDragDropStart_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onDragEnter = function() {
    return WindowTreeClientProxy.prototype.onDragEnter
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onDragEnter = function(window, key_state, screen_position, effect_bitmask) {
    var params = new WindowTreeClient_OnDragEnter_Params();
    params.window = window;
    params.key_state = key_state;
    params.screen_position = screen_position;
    params.effect_bitmask = effect_bitmask;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWindowTreeClient_OnDragEnter_Name,
          codec.align(WindowTreeClient_OnDragEnter_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WindowTreeClient_OnDragEnter_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WindowTreeClient_OnDragEnter_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  WindowTreeClientPtr.prototype.onDragOver = function() {
    return WindowTreeClientProxy.prototype.onDragOver
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onDragOver = function(window, key_state, screen_position, effect_bitmask) {
    var params = new WindowTreeClient_OnDragOver_Params();
    params.window = window;
    params.key_state = key_state;
    params.screen_position = screen_position;
    params.effect_bitmask = effect_bitmask;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWindowTreeClient_OnDragOver_Name,
          codec.align(WindowTreeClient_OnDragOver_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WindowTreeClient_OnDragOver_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WindowTreeClient_OnDragOver_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  WindowTreeClientPtr.prototype.onDragLeave = function() {
    return WindowTreeClientProxy.prototype.onDragLeave
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onDragLeave = function(window) {
    var params = new WindowTreeClient_OnDragLeave_Params();
    params.window = window;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnDragLeave_Name,
        codec.align(WindowTreeClient_OnDragLeave_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnDragLeave_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onCompleteDrop = function() {
    return WindowTreeClientProxy.prototype.onCompleteDrop
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onCompleteDrop = function(window, key_state, screen_position, effect_bitmask) {
    var params = new WindowTreeClient_OnCompleteDrop_Params();
    params.window = window;
    params.key_state = key_state;
    params.screen_position = screen_position;
    params.effect_bitmask = effect_bitmask;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWindowTreeClient_OnCompleteDrop_Name,
          codec.align(WindowTreeClient_OnCompleteDrop_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WindowTreeClient_OnCompleteDrop_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WindowTreeClient_OnCompleteDrop_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  WindowTreeClientPtr.prototype.onPerformDragDropCompleted = function() {
    return WindowTreeClientProxy.prototype.onPerformDragDropCompleted
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onPerformDragDropCompleted = function(window, success, action_taken) {
    var params = new WindowTreeClient_OnPerformDragDropCompleted_Params();
    params.window = window;
    params.success = success;
    params.action_taken = action_taken;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnPerformDragDropCompleted_Name,
        codec.align(WindowTreeClient_OnPerformDragDropCompleted_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnPerformDragDropCompleted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onDragDropDone = function() {
    return WindowTreeClientProxy.prototype.onDragDropDone
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onDragDropDone = function() {
    var params = new WindowTreeClient_OnDragDropDone_Params();
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnDragDropDone_Name,
        codec.align(WindowTreeClient_OnDragDropDone_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnDragDropDone_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.onChangeCompleted = function() {
    return WindowTreeClientProxy.prototype.onChangeCompleted
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.onChangeCompleted = function(change_id, success) {
    var params = new WindowTreeClient_OnChangeCompleted_Params();
    params.change_id = change_id;
    params.success = success;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_OnChangeCompleted_Name,
        codec.align(WindowTreeClient_OnChangeCompleted_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_OnChangeCompleted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.requestClose = function() {
    return WindowTreeClientProxy.prototype.requestClose
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.requestClose = function(window_id) {
    var params = new WindowTreeClient_RequestClose_Params();
    params.window_id = window_id;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_RequestClose_Name,
        codec.align(WindowTreeClient_RequestClose_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_RequestClose_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeClientPtr.prototype.getWindowManager = function() {
    return WindowTreeClientProxy.prototype.getWindowManager
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeClientProxy.prototype.getWindowManager = function(internal) {
    var params = new WindowTreeClient_GetWindowManager_Params();
    params.internal = internal;
    var builder = new codec.MessageBuilder(
        kWindowTreeClient_GetWindowManager_Name,
        codec.align(WindowTreeClient_GetWindowManager_Params.encodedSize));
    builder.encodeStruct(WindowTreeClient_GetWindowManager_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function WindowTreeClientStub(delegate) {
    this.delegate_ = delegate;
  }
  WindowTreeClientStub.prototype.onEmbed = function(connection_id, root, tree, display_id, focused_window, parent_drawn) {
    return this.delegate_ && this.delegate_.onEmbed && this.delegate_.onEmbed(connection_id, root, tree, display_id, focused_window, parent_drawn);
  }
  WindowTreeClientStub.prototype.onEmbeddedAppDisconnected = function(window) {
    return this.delegate_ && this.delegate_.onEmbeddedAppDisconnected && this.delegate_.onEmbeddedAppDisconnected(window);
  }
  WindowTreeClientStub.prototype.onUnembed = function(window) {
    return this.delegate_ && this.delegate_.onUnembed && this.delegate_.onUnembed(window);
  }
  WindowTreeClientStub.prototype.onCaptureChanged = function(new_capture, old_capture) {
    return this.delegate_ && this.delegate_.onCaptureChanged && this.delegate_.onCaptureChanged(new_capture, old_capture);
  }
  WindowTreeClientStub.prototype.onTopLevelCreated = function(change_id, data, display_id, parent_drawn) {
    return this.delegate_ && this.delegate_.onTopLevelCreated && this.delegate_.onTopLevelCreated(change_id, data, display_id, parent_drawn);
  }
  WindowTreeClientStub.prototype.onWindowBoundsChanged = function(window, old_bounds, new_bounds) {
    return this.delegate_ && this.delegate_.onWindowBoundsChanged && this.delegate_.onWindowBoundsChanged(window, old_bounds, new_bounds);
  }
  WindowTreeClientStub.prototype.onClientAreaChanged = function(window_id, new_client_area, new_additional_client_areas) {
    return this.delegate_ && this.delegate_.onClientAreaChanged && this.delegate_.onClientAreaChanged(window_id, new_client_area, new_additional_client_areas);
  }
  WindowTreeClientStub.prototype.onTransientWindowAdded = function(window_id, transient_window_id) {
    return this.delegate_ && this.delegate_.onTransientWindowAdded && this.delegate_.onTransientWindowAdded(window_id, transient_window_id);
  }
  WindowTreeClientStub.prototype.onTransientWindowRemoved = function(window_id, transient_window_id) {
    return this.delegate_ && this.delegate_.onTransientWindowRemoved && this.delegate_.onTransientWindowRemoved(window_id, transient_window_id);
  }
  WindowTreeClientStub.prototype.onWindowHierarchyChanged = function(window, old_parent, new_parent, windows) {
    return this.delegate_ && this.delegate_.onWindowHierarchyChanged && this.delegate_.onWindowHierarchyChanged(window, old_parent, new_parent, windows);
  }
  WindowTreeClientStub.prototype.onWindowReordered = function(window_id, relative_window_id, direction) {
    return this.delegate_ && this.delegate_.onWindowReordered && this.delegate_.onWindowReordered(window_id, relative_window_id, direction);
  }
  WindowTreeClientStub.prototype.onWindowDeleted = function(window) {
    return this.delegate_ && this.delegate_.onWindowDeleted && this.delegate_.onWindowDeleted(window);
  }
  WindowTreeClientStub.prototype.onWindowVisibilityChanged = function(window, visible) {
    return this.delegate_ && this.delegate_.onWindowVisibilityChanged && this.delegate_.onWindowVisibilityChanged(window, visible);
  }
  WindowTreeClientStub.prototype.onWindowOpacityChanged = function(window, old_opacity, new_opacity) {
    return this.delegate_ && this.delegate_.onWindowOpacityChanged && this.delegate_.onWindowOpacityChanged(window, old_opacity, new_opacity);
  }
  WindowTreeClientStub.prototype.onWindowParentDrawnStateChanged = function(window, drawn) {
    return this.delegate_ && this.delegate_.onWindowParentDrawnStateChanged && this.delegate_.onWindowParentDrawnStateChanged(window, drawn);
  }
  WindowTreeClientStub.prototype.onWindowSharedPropertyChanged = function(window, name, new_data) {
    return this.delegate_ && this.delegate_.onWindowSharedPropertyChanged && this.delegate_.onWindowSharedPropertyChanged(window, name, new_data);
  }
  WindowTreeClientStub.prototype.onWindowInputEvent = function(event_id, window, event, matches_pointer_watcher) {
    return this.delegate_ && this.delegate_.onWindowInputEvent && this.delegate_.onWindowInputEvent(event_id, window, event, matches_pointer_watcher);
  }
  WindowTreeClientStub.prototype.onPointerEventObserved = function(event, window_id) {
    return this.delegate_ && this.delegate_.onPointerEventObserved && this.delegate_.onPointerEventObserved(event, window_id);
  }
  WindowTreeClientStub.prototype.onWindowFocused = function(focused_window_id) {
    return this.delegate_ && this.delegate_.onWindowFocused && this.delegate_.onWindowFocused(focused_window_id);
  }
  WindowTreeClientStub.prototype.onWindowPredefinedCursorChanged = function(window_id, cursor_id) {
    return this.delegate_ && this.delegate_.onWindowPredefinedCursorChanged && this.delegate_.onWindowPredefinedCursorChanged(window_id, cursor_id);
  }
  WindowTreeClientStub.prototype.onWindowSurfaceChanged = function(window_id, surface_info) {
    return this.delegate_ && this.delegate_.onWindowSurfaceChanged && this.delegate_.onWindowSurfaceChanged(window_id, surface_info);
  }
  WindowTreeClientStub.prototype.onDragDropStart = function(drag_data) {
    return this.delegate_ && this.delegate_.onDragDropStart && this.delegate_.onDragDropStart(drag_data);
  }
  WindowTreeClientStub.prototype.onDragEnter = function(window, key_state, screen_position, effect_bitmask) {
    return this.delegate_ && this.delegate_.onDragEnter && this.delegate_.onDragEnter(window, key_state, screen_position, effect_bitmask);
  }
  WindowTreeClientStub.prototype.onDragOver = function(window, key_state, screen_position, effect_bitmask) {
    return this.delegate_ && this.delegate_.onDragOver && this.delegate_.onDragOver(window, key_state, screen_position, effect_bitmask);
  }
  WindowTreeClientStub.prototype.onDragLeave = function(window) {
    return this.delegate_ && this.delegate_.onDragLeave && this.delegate_.onDragLeave(window);
  }
  WindowTreeClientStub.prototype.onCompleteDrop = function(window, key_state, screen_position, effect_bitmask) {
    return this.delegate_ && this.delegate_.onCompleteDrop && this.delegate_.onCompleteDrop(window, key_state, screen_position, effect_bitmask);
  }
  WindowTreeClientStub.prototype.onPerformDragDropCompleted = function(window, success, action_taken) {
    return this.delegate_ && this.delegate_.onPerformDragDropCompleted && this.delegate_.onPerformDragDropCompleted(window, success, action_taken);
  }
  WindowTreeClientStub.prototype.onDragDropDone = function() {
    return this.delegate_ && this.delegate_.onDragDropDone && this.delegate_.onDragDropDone();
  }
  WindowTreeClientStub.prototype.onChangeCompleted = function(change_id, success) {
    return this.delegate_ && this.delegate_.onChangeCompleted && this.delegate_.onChangeCompleted(change_id, success);
  }
  WindowTreeClientStub.prototype.requestClose = function(window_id) {
    return this.delegate_ && this.delegate_.requestClose && this.delegate_.requestClose(window_id);
  }
  WindowTreeClientStub.prototype.getWindowManager = function(internal) {
    return this.delegate_ && this.delegate_.getWindowManager && this.delegate_.getWindowManager(internal);
  }

  WindowTreeClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowTreeClient_OnEmbed_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnEmbed_Params);
      this.onEmbed(params.connection_id, params.root, params.tree, params.display_id, params.focused_window, params.parent_drawn);
      return true;
    case kWindowTreeClient_OnEmbeddedAppDisconnected_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnEmbeddedAppDisconnected_Params);
      this.onEmbeddedAppDisconnected(params.window);
      return true;
    case kWindowTreeClient_OnUnembed_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnUnembed_Params);
      this.onUnembed(params.window);
      return true;
    case kWindowTreeClient_OnCaptureChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnCaptureChanged_Params);
      this.onCaptureChanged(params.new_capture, params.old_capture);
      return true;
    case kWindowTreeClient_OnTopLevelCreated_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnTopLevelCreated_Params);
      this.onTopLevelCreated(params.change_id, params.data, params.display_id, params.parent_drawn);
      return true;
    case kWindowTreeClient_OnWindowBoundsChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowBoundsChanged_Params);
      this.onWindowBoundsChanged(params.window, params.old_bounds, params.new_bounds);
      return true;
    case kWindowTreeClient_OnClientAreaChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnClientAreaChanged_Params);
      this.onClientAreaChanged(params.window_id, params.new_client_area, params.new_additional_client_areas);
      return true;
    case kWindowTreeClient_OnTransientWindowAdded_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnTransientWindowAdded_Params);
      this.onTransientWindowAdded(params.window_id, params.transient_window_id);
      return true;
    case kWindowTreeClient_OnTransientWindowRemoved_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnTransientWindowRemoved_Params);
      this.onTransientWindowRemoved(params.window_id, params.transient_window_id);
      return true;
    case kWindowTreeClient_OnWindowHierarchyChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowHierarchyChanged_Params);
      this.onWindowHierarchyChanged(params.window, params.old_parent, params.new_parent, params.windows);
      return true;
    case kWindowTreeClient_OnWindowReordered_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowReordered_Params);
      this.onWindowReordered(params.window_id, params.relative_window_id, params.direction);
      return true;
    case kWindowTreeClient_OnWindowDeleted_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowDeleted_Params);
      this.onWindowDeleted(params.window);
      return true;
    case kWindowTreeClient_OnWindowVisibilityChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowVisibilityChanged_Params);
      this.onWindowVisibilityChanged(params.window, params.visible);
      return true;
    case kWindowTreeClient_OnWindowOpacityChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowOpacityChanged_Params);
      this.onWindowOpacityChanged(params.window, params.old_opacity, params.new_opacity);
      return true;
    case kWindowTreeClient_OnWindowParentDrawnStateChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowParentDrawnStateChanged_Params);
      this.onWindowParentDrawnStateChanged(params.window, params.drawn);
      return true;
    case kWindowTreeClient_OnWindowSharedPropertyChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowSharedPropertyChanged_Params);
      this.onWindowSharedPropertyChanged(params.window, params.name, params.new_data);
      return true;
    case kWindowTreeClient_OnWindowInputEvent_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowInputEvent_Params);
      this.onWindowInputEvent(params.event_id, params.window, params.event, params.matches_pointer_watcher);
      return true;
    case kWindowTreeClient_OnPointerEventObserved_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnPointerEventObserved_Params);
      this.onPointerEventObserved(params.event, params.window_id);
      return true;
    case kWindowTreeClient_OnWindowFocused_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowFocused_Params);
      this.onWindowFocused(params.focused_window_id);
      return true;
    case kWindowTreeClient_OnWindowPredefinedCursorChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowPredefinedCursorChanged_Params);
      this.onWindowPredefinedCursorChanged(params.window_id, params.cursor_id);
      return true;
    case kWindowTreeClient_OnWindowSurfaceChanged_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnWindowSurfaceChanged_Params);
      this.onWindowSurfaceChanged(params.window_id, params.surface_info);
      return true;
    case kWindowTreeClient_OnDragDropStart_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnDragDropStart_Params);
      this.onDragDropStart(params.drag_data);
      return true;
    case kWindowTreeClient_OnDragLeave_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnDragLeave_Params);
      this.onDragLeave(params.window);
      return true;
    case kWindowTreeClient_OnPerformDragDropCompleted_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnPerformDragDropCompleted_Params);
      this.onPerformDragDropCompleted(params.window, params.success, params.action_taken);
      return true;
    case kWindowTreeClient_OnDragDropDone_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnDragDropDone_Params);
      this.onDragDropDone();
      return true;
    case kWindowTreeClient_OnChangeCompleted_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnChangeCompleted_Params);
      this.onChangeCompleted(params.change_id, params.success);
      return true;
    case kWindowTreeClient_RequestClose_Name:
      var params = reader.decodeStruct(WindowTreeClient_RequestClose_Params);
      this.requestClose(params.window_id);
      return true;
    case kWindowTreeClient_GetWindowManager_Name:
      var params = reader.decodeStruct(WindowTreeClient_GetWindowManager_Params);
      this.getWindowManager(params.internal);
      return true;
    default:
      return false;
    }
  };

  WindowTreeClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowTreeClient_OnDragEnter_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnDragEnter_Params);
      return this.onDragEnter(params.window, params.key_state, params.screen_position, params.effect_bitmask).then(function(response) {
        var responseParams =
            new WindowTreeClient_OnDragEnter_ResponseParams();
        responseParams.supported_op_bitmask = response.supported_op_bitmask;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWindowTreeClient_OnDragEnter_Name,
            codec.align(WindowTreeClient_OnDragEnter_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WindowTreeClient_OnDragEnter_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kWindowTreeClient_OnDragOver_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnDragOver_Params);
      return this.onDragOver(params.window, params.key_state, params.screen_position, params.effect_bitmask).then(function(response) {
        var responseParams =
            new WindowTreeClient_OnDragOver_ResponseParams();
        responseParams.supported_op_bitmask = response.supported_op_bitmask;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWindowTreeClient_OnDragOver_Name,
            codec.align(WindowTreeClient_OnDragOver_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WindowTreeClient_OnDragOver_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kWindowTreeClient_OnCompleteDrop_Name:
      var params = reader.decodeStruct(WindowTreeClient_OnCompleteDrop_Params);
      return this.onCompleteDrop(params.window, params.key_state, params.screen_position, params.effect_bitmask).then(function(response) {
        var responseParams =
            new WindowTreeClient_OnCompleteDrop_ResponseParams();
        responseParams.action_taken = response.action_taken;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWindowTreeClient_OnCompleteDrop_Name,
            codec.align(WindowTreeClient_OnCompleteDrop_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WindowTreeClient_OnCompleteDrop_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWindowTreeClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWindowTreeClient_OnEmbed_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnEmbed_Params;
      break;
      case kWindowTreeClient_OnEmbeddedAppDisconnected_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnEmbeddedAppDisconnected_Params;
      break;
      case kWindowTreeClient_OnUnembed_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnUnembed_Params;
      break;
      case kWindowTreeClient_OnCaptureChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnCaptureChanged_Params;
      break;
      case kWindowTreeClient_OnTopLevelCreated_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnTopLevelCreated_Params;
      break;
      case kWindowTreeClient_OnWindowBoundsChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowBoundsChanged_Params;
      break;
      case kWindowTreeClient_OnClientAreaChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnClientAreaChanged_Params;
      break;
      case kWindowTreeClient_OnTransientWindowAdded_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnTransientWindowAdded_Params;
      break;
      case kWindowTreeClient_OnTransientWindowRemoved_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnTransientWindowRemoved_Params;
      break;
      case kWindowTreeClient_OnWindowHierarchyChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowHierarchyChanged_Params;
      break;
      case kWindowTreeClient_OnWindowReordered_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowReordered_Params;
      break;
      case kWindowTreeClient_OnWindowDeleted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowDeleted_Params;
      break;
      case kWindowTreeClient_OnWindowVisibilityChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowVisibilityChanged_Params;
      break;
      case kWindowTreeClient_OnWindowOpacityChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowOpacityChanged_Params;
      break;
      case kWindowTreeClient_OnWindowParentDrawnStateChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowParentDrawnStateChanged_Params;
      break;
      case kWindowTreeClient_OnWindowSharedPropertyChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowSharedPropertyChanged_Params;
      break;
      case kWindowTreeClient_OnWindowInputEvent_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowInputEvent_Params;
      break;
      case kWindowTreeClient_OnPointerEventObserved_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnPointerEventObserved_Params;
      break;
      case kWindowTreeClient_OnWindowFocused_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowFocused_Params;
      break;
      case kWindowTreeClient_OnWindowPredefinedCursorChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowPredefinedCursorChanged_Params;
      break;
      case kWindowTreeClient_OnWindowSurfaceChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnWindowSurfaceChanged_Params;
      break;
      case kWindowTreeClient_OnDragDropStart_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnDragDropStart_Params;
      break;
      case kWindowTreeClient_OnDragEnter_Name:
        if (message.expectsResponse())
          paramsClass = WindowTreeClient_OnDragEnter_Params;
      break;
      case kWindowTreeClient_OnDragOver_Name:
        if (message.expectsResponse())
          paramsClass = WindowTreeClient_OnDragOver_Params;
      break;
      case kWindowTreeClient_OnDragLeave_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnDragLeave_Params;
      break;
      case kWindowTreeClient_OnCompleteDrop_Name:
        if (message.expectsResponse())
          paramsClass = WindowTreeClient_OnCompleteDrop_Params;
      break;
      case kWindowTreeClient_OnPerformDragDropCompleted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnPerformDragDropCompleted_Params;
      break;
      case kWindowTreeClient_OnDragDropDone_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnDragDropDone_Params;
      break;
      case kWindowTreeClient_OnChangeCompleted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_OnChangeCompleted_Params;
      break;
      case kWindowTreeClient_RequestClose_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_RequestClose_Params;
      break;
      case kWindowTreeClient_GetWindowManager_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeClient_GetWindowManager_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWindowTreeClientResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kWindowTreeClient_OnDragEnter_Name:
        if (message.isResponse())
          paramsClass = WindowTreeClient_OnDragEnter_ResponseParams;
        break;
      case kWindowTreeClient_OnDragOver_Name:
        if (message.isResponse())
          paramsClass = WindowTreeClient_OnDragOver_ResponseParams;
        break;
      case kWindowTreeClient_OnCompleteDrop_Name:
        if (message.isResponse())
          paramsClass = WindowTreeClient_OnCompleteDrop_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var WindowTreeClient = {
    name: 'ui::mojom::WindowTreeClient',
    ptrClass: WindowTreeClientPtr,
    proxyClass: WindowTreeClientProxy,
    stubClass: WindowTreeClientStub,
    validateRequest: validateWindowTreeClientRequest,
    validateResponse: validateWindowTreeClientResponse,
  };
  WindowTreeClientStub.prototype.validator = validateWindowTreeClientRequest;
  WindowTreeClientProxy.prototype.validator = validateWindowTreeClientResponse;
  var kWindowTreeFactory_CreateWindowTree_Name = 0;

  function WindowTreeFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WindowTreeFactory,
                                                   handleOrPtrInfo);
  }

  function WindowTreeFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  WindowTreeFactoryPtr.prototype.createWindowTree = function() {
    return WindowTreeFactoryProxy.prototype.createWindowTree
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeFactoryProxy.prototype.createWindowTree = function(tree_request, client) {
    var params = new WindowTreeFactory_CreateWindowTree_Params();
    params.tree_request = tree_request;
    params.client = client;
    var builder = new codec.MessageBuilder(
        kWindowTreeFactory_CreateWindowTree_Name,
        codec.align(WindowTreeFactory_CreateWindowTree_Params.encodedSize));
    builder.encodeStruct(WindowTreeFactory_CreateWindowTree_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function WindowTreeFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  WindowTreeFactoryStub.prototype.createWindowTree = function(tree_request, client) {
    return this.delegate_ && this.delegate_.createWindowTree && this.delegate_.createWindowTree(tree_request, client);
  }

  WindowTreeFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowTreeFactory_CreateWindowTree_Name:
      var params = reader.decodeStruct(WindowTreeFactory_CreateWindowTree_Params);
      this.createWindowTree(params.tree_request, params.client);
      return true;
    default:
      return false;
    }
  };

  WindowTreeFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWindowTreeFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWindowTreeFactory_CreateWindowTree_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeFactory_CreateWindowTree_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWindowTreeFactoryResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var WindowTreeFactory = {
    name: 'ui::mojom::WindowTreeFactory',
    ptrClass: WindowTreeFactoryPtr,
    proxyClass: WindowTreeFactoryProxy,
    stubClass: WindowTreeFactoryStub,
    validateRequest: validateWindowTreeFactoryRequest,
    validateResponse: null,
  };
  WindowTreeFactoryStub.prototype.validator = validateWindowTreeFactoryRequest;
  WindowTreeFactoryProxy.prototype.validator = null;

  var exports = {};
  exports.WindowTree = WindowTree;
  exports.WindowTreePtr = WindowTreePtr;
  exports.WindowTreeClient = WindowTreeClient;
  exports.WindowTreeClientPtr = WindowTreeClientPtr;
  exports.WindowTreeFactory = WindowTreeFactory;
  exports.WindowTreeFactoryPtr = WindowTreeFactoryPtr;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/shared_quad_state.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/gfx/mojo/transform.mojom",
], function(bindings, codec, core, validator, geometry$, transform$) {

  function SharedQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SharedQuadState.prototype.initDefaults_ = function() {
    this.quad_to_target_transform = null;
    this.quad_layer_bounds = null;
    this.visible_quad_layer_rect = null;
    this.clip_rect = null;
    this.is_clipped = false;
    this.opacity = 0;
    this.blend_mode = 0;
    this.sorting_context_id = 0;
  };
  SharedQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SharedQuadState.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 56}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SharedQuadState.quad_to_target_transform
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, transform$.Transform, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SharedQuadState.quad_layer_bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SharedQuadState.visible_quad_layer_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SharedQuadState.clip_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;





    return validator.validationError.NONE;
  };

  SharedQuadState.encodedSize = codec.kStructHeaderSize + 48;

  SharedQuadState.decode = function(decoder) {
    var packed;
    var val = new SharedQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.quad_to_target_transform = decoder.decodeStructPointer(transform$.Transform);
    val.quad_layer_bounds = decoder.decodeStructPointer(geometry$.Size);
    val.visible_quad_layer_rect = decoder.decodeStructPointer(geometry$.Rect);
    val.clip_rect = decoder.decodeStructPointer(geometry$.Rect);
    packed = decoder.readUint8();
    val.is_clipped = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.opacity = decoder.decodeStruct(codec.Float);
    val.blend_mode = decoder.decodeStruct(codec.Uint32);
    val.sorting_context_id = decoder.decodeStruct(codec.Int32);
    return val;
  };

  SharedQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SharedQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(transform$.Transform, val.quad_to_target_transform);
    encoder.encodeStructPointer(geometry$.Size, val.quad_layer_bounds);
    encoder.encodeStructPointer(geometry$.Rect, val.visible_quad_layer_rect);
    encoder.encodeStructPointer(geometry$.Rect, val.clip_rect);
    packed = 0;
    packed |= (val.is_clipped & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Float, val.opacity);
    encoder.encodeStruct(codec.Uint32, val.blend_mode);
    encoder.encodeStruct(codec.Int32, val.sorting_context_id);
  };

  var exports = {};
  exports.SharedQuadState = SharedQuadState;

  return exports;
});
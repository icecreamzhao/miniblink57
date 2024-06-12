// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/render_pass.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/filter_operations.mojom",
    "cc/ipc/quads.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/gfx/mojo/transform.mojom",
], function(bindings, codec, core, validator, filter_operations$, quads$, geometry$, transform$) {

  function RenderPass(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RenderPass.prototype.initDefaults_ = function() {
    this.id = 0;
    this.has_transparent_background = false;
    this.output_rect = null;
    this.damage_rect = null;
    this.transform_to_root_target = null;
    this.filters = null;
    this.background_filters = null;
    this.quad_list = null;
  };
  RenderPass.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RenderPass.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 64}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate RenderPass.output_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RenderPass.damage_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RenderPass.transform_to_root_target
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, transform$.Transform, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RenderPass.filters
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, filter_operations$.FilterOperations, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RenderPass.background_filters
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, filter_operations$.FilterOperations, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate RenderPass.quad_list
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 48, 8, new codec.PointerTo(quads$.DrawQuad), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RenderPass.encodedSize = codec.kStructHeaderSize + 56;

  RenderPass.decode = function(decoder) {
    var packed;
    var val = new RenderPass();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.has_transparent_background = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.output_rect = decoder.decodeStructPointer(geometry$.Rect);
    val.damage_rect = decoder.decodeStructPointer(geometry$.Rect);
    val.transform_to_root_target = decoder.decodeStructPointer(transform$.Transform);
    val.filters = decoder.decodeStructPointer(filter_operations$.FilterOperations);
    val.background_filters = decoder.decodeStructPointer(filter_operations$.FilterOperations);
    val.quad_list = decoder.decodeArrayPointer(new codec.PointerTo(quads$.DrawQuad));
    return val;
  };

  RenderPass.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RenderPass.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.id);
    packed = 0;
    packed |= (val.has_transparent_background & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Rect, val.output_rect);
    encoder.encodeStructPointer(geometry$.Rect, val.damage_rect);
    encoder.encodeStructPointer(transform$.Transform, val.transform_to_root_target);
    encoder.encodeStructPointer(filter_operations$.FilterOperations, val.filters);
    encoder.encodeStructPointer(filter_operations$.FilterOperations, val.background_filters);
    encoder.encodeArrayPointer(new codec.PointerTo(quads$.DrawQuad), val.quad_list);
  };

  var exports = {};
  exports.RenderPass = RenderPass;

  return exports;
});
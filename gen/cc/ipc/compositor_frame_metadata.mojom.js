// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/compositor_frame_metadata.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/selection.mojom",
    "cc/ipc/surface_id.mojom",
    "ui/events/mojo/latency_info.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, selection$, surface_id$, latency_info$, geometry$) {

  function CompositorFrameMetadata(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CompositorFrameMetadata.prototype.initDefaults_ = function() {
    this.device_scale_factor = 0;
    this.page_scale_factor = 0;
    this.root_scroll_offset = null;
    this.scrollable_viewport_size = null;
    this.root_layer_size = null;
    this.min_page_scale_factor = 0;
    this.max_page_scale_factor = 0;
    this.root_overflow_x_hidden = false;
    this.root_overflow_y_hidden = false;
    this.may_contain_video = false;
    this.is_resourceless_software_draw_with_scroll_or_animation = false;
    this.top_controls_height = 0;
    this.top_controls_shown_ratio = 0;
    this.bottom_controls_height = 0;
    this.bottom_controls_shown_ratio = 0;
    this.root_background_color = 0;
    this.selection = null;
    this.latency_info = null;
    this.referenced_surfaces = null;
  };
  CompositorFrameMetadata.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CompositorFrameMetadata.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 96}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate CompositorFrameMetadata.root_scroll_offset
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Vector2dF, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate CompositorFrameMetadata.scrollable_viewport_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.SizeF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CompositorFrameMetadata.root_layer_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.SizeF, false);
    if (err !== validator.validationError.NONE)
        return err;













    
    // validate CompositorFrameMetadata.selection
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 64, selection$.Selection, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CompositorFrameMetadata.latency_info
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 72, 8, new codec.PointerTo(latency_info$.LatencyInfo), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CompositorFrameMetadata.referenced_surfaces
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 80, 8, new codec.PointerTo(surface_id$.SurfaceId), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  CompositorFrameMetadata.encodedSize = codec.kStructHeaderSize + 88;

  CompositorFrameMetadata.decode = function(decoder) {
    var packed;
    var val = new CompositorFrameMetadata();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.device_scale_factor = decoder.decodeStruct(codec.Float);
    val.page_scale_factor = decoder.decodeStruct(codec.Float);
    val.root_scroll_offset = decoder.decodeStructPointer(geometry$.Vector2dF);
    val.scrollable_viewport_size = decoder.decodeStructPointer(geometry$.SizeF);
    val.root_layer_size = decoder.decodeStructPointer(geometry$.SizeF);
    val.min_page_scale_factor = decoder.decodeStruct(codec.Float);
    val.max_page_scale_factor = decoder.decodeStruct(codec.Float);
    packed = decoder.readUint8();
    val.root_overflow_x_hidden = (packed >> 0) & 1 ? true : false;
    val.root_overflow_y_hidden = (packed >> 1) & 1 ? true : false;
    val.may_contain_video = (packed >> 2) & 1 ? true : false;
    val.is_resourceless_software_draw_with_scroll_or_animation = (packed >> 3) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.top_controls_height = decoder.decodeStruct(codec.Float);
    val.top_controls_shown_ratio = decoder.decodeStruct(codec.Float);
    val.bottom_controls_height = decoder.decodeStruct(codec.Float);
    val.bottom_controls_shown_ratio = decoder.decodeStruct(codec.Float);
    val.root_background_color = decoder.decodeStruct(codec.Uint32);
    val.selection = decoder.decodeStructPointer(selection$.Selection);
    val.latency_info = decoder.decodeArrayPointer(new codec.PointerTo(latency_info$.LatencyInfo));
    val.referenced_surfaces = decoder.decodeArrayPointer(new codec.PointerTo(surface_id$.SurfaceId));
    return val;
  };

  CompositorFrameMetadata.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CompositorFrameMetadata.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.device_scale_factor);
    encoder.encodeStruct(codec.Float, val.page_scale_factor);
    encoder.encodeStructPointer(geometry$.Vector2dF, val.root_scroll_offset);
    encoder.encodeStructPointer(geometry$.SizeF, val.scrollable_viewport_size);
    encoder.encodeStructPointer(geometry$.SizeF, val.root_layer_size);
    encoder.encodeStruct(codec.Float, val.min_page_scale_factor);
    encoder.encodeStruct(codec.Float, val.max_page_scale_factor);
    packed = 0;
    packed |= (val.root_overflow_x_hidden & 1) << 0
    packed |= (val.root_overflow_y_hidden & 1) << 1
    packed |= (val.may_contain_video & 1) << 2
    packed |= (val.is_resourceless_software_draw_with_scroll_or_animation & 1) << 3
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Float, val.top_controls_height);
    encoder.encodeStruct(codec.Float, val.top_controls_shown_ratio);
    encoder.encodeStruct(codec.Float, val.bottom_controls_height);
    encoder.encodeStruct(codec.Float, val.bottom_controls_shown_ratio);
    encoder.encodeStruct(codec.Uint32, val.root_background_color);
    encoder.encodeStructPointer(selection$.Selection, val.selection);
    encoder.encodeArrayPointer(new codec.PointerTo(latency_info$.LatencyInfo), val.latency_info);
    encoder.encodeArrayPointer(new codec.PointerTo(surface_id$.SurfaceId), val.referenced_surfaces);
  };

  var exports = {};
  exports.CompositorFrameMetadata = CompositorFrameMetadata;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/quads.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/filter_operations.mojom",
    "cc/ipc/shared_quad_state.mojom",
    "cc/ipc/surface_id.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/gfx/mojo/transform.mojom",
], function(bindings, codec, core, validator, filter_operations$, shared_quad_state$, surface_id$, geometry$, transform$) {
  var YUVColorSpace = {};
  YUVColorSpace.REC_601 = 0;
  YUVColorSpace.REC_709 = YUVColorSpace.REC_601 + 1;
  YUVColorSpace.JPEG = YUVColorSpace.REC_709 + 1;

  YUVColorSpace.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  YUVColorSpace.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function DebugBorderQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DebugBorderQuadState.prototype.initDefaults_ = function() {
    this.color = 0;
    this.width = 0;
  };
  DebugBorderQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DebugBorderQuadState.validate = function(messageValidator, offset) {
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

  DebugBorderQuadState.encodedSize = codec.kStructHeaderSize + 8;

  DebugBorderQuadState.decode = function(decoder) {
    var packed;
    var val = new DebugBorderQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.color = decoder.decodeStruct(codec.Uint32);
    val.width = decoder.decodeStruct(codec.Int32);
    return val;
  };

  DebugBorderQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DebugBorderQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.color);
    encoder.encodeStruct(codec.Int32, val.width);
  };
  function RenderPassQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RenderPassQuadState.prototype.initDefaults_ = function() {
    this.render_pass_id = 0;
    this.mask_resource_id = 0;
    this.mask_uv_scale = null;
    this.mask_texture_size = null;
    this.filters_scale = null;
    this.filters_origin = null;
  };
  RenderPassQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RenderPassQuadState.validate = function(messageValidator, offset) {
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




    
    // validate RenderPassQuadState.mask_uv_scale
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Vector2dF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RenderPassQuadState.mask_texture_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RenderPassQuadState.filters_scale
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.Vector2dF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RenderPassQuadState.filters_origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, geometry$.PointF, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RenderPassQuadState.encodedSize = codec.kStructHeaderSize + 40;

  RenderPassQuadState.decode = function(decoder) {
    var packed;
    var val = new RenderPassQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.render_pass_id = decoder.decodeStruct(codec.Int32);
    val.mask_resource_id = decoder.decodeStruct(codec.Uint32);
    val.mask_uv_scale = decoder.decodeStructPointer(geometry$.Vector2dF);
    val.mask_texture_size = decoder.decodeStructPointer(geometry$.Size);
    val.filters_scale = decoder.decodeStructPointer(geometry$.Vector2dF);
    val.filters_origin = decoder.decodeStructPointer(geometry$.PointF);
    return val;
  };

  RenderPassQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RenderPassQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.render_pass_id);
    encoder.encodeStruct(codec.Uint32, val.mask_resource_id);
    encoder.encodeStructPointer(geometry$.Vector2dF, val.mask_uv_scale);
    encoder.encodeStructPointer(geometry$.Size, val.mask_texture_size);
    encoder.encodeStructPointer(geometry$.Vector2dF, val.filters_scale);
    encoder.encodeStructPointer(geometry$.PointF, val.filters_origin);
  };
  function SolidColorQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SolidColorQuadState.prototype.initDefaults_ = function() {
    this.color = 0;
    this.force_anti_aliasing_off = false;
  };
  SolidColorQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SolidColorQuadState.validate = function(messageValidator, offset) {
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

  SolidColorQuadState.encodedSize = codec.kStructHeaderSize + 8;

  SolidColorQuadState.decode = function(decoder) {
    var packed;
    var val = new SolidColorQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.color = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.force_anti_aliasing_off = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  SolidColorQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SolidColorQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.color);
    packed = 0;
    packed |= (val.force_anti_aliasing_off & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function StreamVideoQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  StreamVideoQuadState.prototype.initDefaults_ = function() {
    this.resource_id = 0;
    this.resource_size_in_pixels = null;
    this.matrix = null;
  };
  StreamVideoQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  StreamVideoQuadState.validate = function(messageValidator, offset) {
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



    
    // validate StreamVideoQuadState.resource_size_in_pixels
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate StreamVideoQuadState.matrix
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, transform$.Transform, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  StreamVideoQuadState.encodedSize = codec.kStructHeaderSize + 24;

  StreamVideoQuadState.decode = function(decoder) {
    var packed;
    var val = new StreamVideoQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.resource_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.resource_size_in_pixels = decoder.decodeStructPointer(geometry$.Size);
    val.matrix = decoder.decodeStructPointer(transform$.Transform);
    return val;
  };

  StreamVideoQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(StreamVideoQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.resource_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Size, val.resource_size_in_pixels);
    encoder.encodeStructPointer(transform$.Transform, val.matrix);
  };
  function SurfaceQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SurfaceQuadState.prototype.initDefaults_ = function() {
    this.surface = null;
  };
  SurfaceQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SurfaceQuadState.validate = function(messageValidator, offset) {
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


    
    // validate SurfaceQuadState.surface
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_id$.SurfaceId, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  SurfaceQuadState.encodedSize = codec.kStructHeaderSize + 8;

  SurfaceQuadState.decode = function(decoder) {
    var packed;
    var val = new SurfaceQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.surface = decoder.decodeStructPointer(surface_id$.SurfaceId);
    return val;
  };

  SurfaceQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SurfaceQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_id$.SurfaceId, val.surface);
  };
  function TextureQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextureQuadState.prototype.initDefaults_ = function() {
    this.resource_id = 0;
    this.premultiplied_alpha = false;
    this.y_flipped = false;
    this.nearest_neighbor = false;
    this.secure_output_only = false;
    this.resource_size_in_pixels = null;
    this.uv_top_left = null;
    this.uv_bottom_right = null;
    this.background_color = 0;
    this.vertex_opacity = null;
  };
  TextureQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextureQuadState.validate = function(messageValidator, offset) {
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



    
    // validate TextureQuadState.resource_size_in_pixels
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate TextureQuadState.uv_top_left
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.PointF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate TextureQuadState.uv_bottom_right
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.PointF, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate TextureQuadState.vertex_opacity
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 40, 4, codec.Float, false, [4], 0);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  TextureQuadState.encodedSize = codec.kStructHeaderSize + 48;

  TextureQuadState.decode = function(decoder) {
    var packed;
    var val = new TextureQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.resource_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.premultiplied_alpha = (packed >> 0) & 1 ? true : false;
    val.y_flipped = (packed >> 1) & 1 ? true : false;
    val.nearest_neighbor = (packed >> 2) & 1 ? true : false;
    val.secure_output_only = (packed >> 3) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.resource_size_in_pixels = decoder.decodeStructPointer(geometry$.Size);
    val.uv_top_left = decoder.decodeStructPointer(geometry$.PointF);
    val.uv_bottom_right = decoder.decodeStructPointer(geometry$.PointF);
    val.background_color = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.vertex_opacity = decoder.decodeArrayPointer(codec.Float);
    return val;
  };

  TextureQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextureQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.resource_id);
    packed = 0;
    packed |= (val.premultiplied_alpha & 1) << 0
    packed |= (val.y_flipped & 1) << 1
    packed |= (val.nearest_neighbor & 1) << 2
    packed |= (val.secure_output_only & 1) << 3
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Size, val.resource_size_in_pixels);
    encoder.encodeStructPointer(geometry$.PointF, val.uv_top_left);
    encoder.encodeStructPointer(geometry$.PointF, val.uv_bottom_right);
    encoder.encodeStruct(codec.Uint32, val.background_color);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.Float, val.vertex_opacity);
  };
  function TileQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TileQuadState.prototype.initDefaults_ = function() {
    this.tex_coord_rect = null;
    this.texture_size = null;
    this.swizzle_contents = false;
    this.nearest_neighbor = false;
    this.resource_id = 0;
  };
  TileQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TileQuadState.validate = function(messageValidator, offset) {
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


    
    // validate TileQuadState.tex_coord_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate TileQuadState.texture_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  TileQuadState.encodedSize = codec.kStructHeaderSize + 24;

  TileQuadState.decode = function(decoder) {
    var packed;
    var val = new TileQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.tex_coord_rect = decoder.decodeStructPointer(geometry$.RectF);
    val.texture_size = decoder.decodeStructPointer(geometry$.Size);
    packed = decoder.readUint8();
    val.swizzle_contents = (packed >> 0) & 1 ? true : false;
    val.nearest_neighbor = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.resource_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  TileQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TileQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.RectF, val.tex_coord_rect);
    encoder.encodeStructPointer(geometry$.Size, val.texture_size);
    packed = 0;
    packed |= (val.swizzle_contents & 1) << 0
    packed |= (val.nearest_neighbor & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.resource_id);
  };
  function YUVVideoQuadState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  YUVVideoQuadState.prototype.initDefaults_ = function() {
    this.ya_tex_coord_rect = null;
    this.uv_tex_coord_rect = null;
    this.ya_tex_size = null;
    this.uv_tex_size = null;
    this.y_plane_resource_id = 0;
    this.u_plane_resource_id = 0;
    this.v_plane_resource_id = 0;
    this.a_plane_resource_id = 0;
    this.color_space = 0;
    this.resource_offset = 0;
    this.resource_multiplier = 0;
    this.bits_per_channel = 0;
  };
  YUVVideoQuadState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  YUVVideoQuadState.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 72}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate YUVVideoQuadState.ya_tex_coord_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate YUVVideoQuadState.uv_tex_coord_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate YUVVideoQuadState.ya_tex_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate YUVVideoQuadState.uv_tex_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;






    
    // validate YUVVideoQuadState.color_space
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 48, YUVColorSpace);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  YUVVideoQuadState.encodedSize = codec.kStructHeaderSize + 64;

  YUVVideoQuadState.decode = function(decoder) {
    var packed;
    var val = new YUVVideoQuadState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.ya_tex_coord_rect = decoder.decodeStructPointer(geometry$.RectF);
    val.uv_tex_coord_rect = decoder.decodeStructPointer(geometry$.RectF);
    val.ya_tex_size = decoder.decodeStructPointer(geometry$.Size);
    val.uv_tex_size = decoder.decodeStructPointer(geometry$.Size);
    val.y_plane_resource_id = decoder.decodeStruct(codec.Uint32);
    val.u_plane_resource_id = decoder.decodeStruct(codec.Uint32);
    val.v_plane_resource_id = decoder.decodeStruct(codec.Uint32);
    val.a_plane_resource_id = decoder.decodeStruct(codec.Uint32);
    val.color_space = decoder.decodeStruct(codec.Int32);
    val.resource_offset = decoder.decodeStruct(codec.Float);
    val.resource_multiplier = decoder.decodeStruct(codec.Float);
    val.bits_per_channel = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  YUVVideoQuadState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(YUVVideoQuadState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.RectF, val.ya_tex_coord_rect);
    encoder.encodeStructPointer(geometry$.RectF, val.uv_tex_coord_rect);
    encoder.encodeStructPointer(geometry$.Size, val.ya_tex_size);
    encoder.encodeStructPointer(geometry$.Size, val.uv_tex_size);
    encoder.encodeStruct(codec.Uint32, val.y_plane_resource_id);
    encoder.encodeStruct(codec.Uint32, val.u_plane_resource_id);
    encoder.encodeStruct(codec.Uint32, val.v_plane_resource_id);
    encoder.encodeStruct(codec.Uint32, val.a_plane_resource_id);
    encoder.encodeStruct(codec.Int32, val.color_space);
    encoder.encodeStruct(codec.Float, val.resource_offset);
    encoder.encodeStruct(codec.Float, val.resource_multiplier);
    encoder.encodeStruct(codec.Uint32, val.bits_per_channel);
  };
  function DrawQuad(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DrawQuad.prototype.initDefaults_ = function() {
    this.rect = null;
    this.opaque_rect = null;
    this.visible_rect = null;
    this.needs_blending = false;
    this.sqs = null;
    this.draw_quad_state = null;
  };
  DrawQuad.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DrawQuad.validate = function(messageValidator, offset) {
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


    
    // validate DrawQuad.rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DrawQuad.opaque_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DrawQuad.visible_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate DrawQuad.sqs
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, shared_quad_state$.SharedQuadState, true);
    if (err !== validator.validationError.NONE)
        return err;


    // validate DrawQuad.draw_quad_state
    err = messageValidator.validateUnion(offset + codec.kStructHeaderSize + 40, DrawQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DrawQuad.encodedSize = codec.kStructHeaderSize + 56;

  DrawQuad.decode = function(decoder) {
    var packed;
    var val = new DrawQuad();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.rect = decoder.decodeStructPointer(geometry$.Rect);
    val.opaque_rect = decoder.decodeStructPointer(geometry$.Rect);
    val.visible_rect = decoder.decodeStructPointer(geometry$.Rect);
    packed = decoder.readUint8();
    val.needs_blending = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.sqs = decoder.decodeStructPointer(shared_quad_state$.SharedQuadState);
    val.draw_quad_state = decoder.decodeStruct(DrawQuadState);
    return val;
  };

  DrawQuad.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DrawQuad.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.Rect, val.rect);
    encoder.encodeStructPointer(geometry$.Rect, val.opaque_rect);
    encoder.encodeStructPointer(geometry$.Rect, val.visible_rect);
    packed = 0;
    packed |= (val.needs_blending & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(shared_quad_state$.SharedQuadState, val.sqs);
    encoder.encodeStruct(DrawQuadState, val.draw_quad_state);
  };

  function DrawQuadState(value) {
    this.initDefault_();
    this.initValue_(value);
  }
  
  
  DrawQuadState.Tags = {
    debug_border_quad_state: 0,
    render_pass_quad_state: 1,
    solid_color_quad_state: 2,
    stream_video_quad_state: 3,
    surface_quad_state: 4,
    texture_quad_state: 5,
    tile_quad_state: 6,
    yuv_video_quad_state: 7,
  };
  
  DrawQuadState.prototype.initDefault_ = function() {
    this.$data = null;
    this.$tag = undefined;
  }
  
  DrawQuadState.prototype.initValue_ = function(value) {
    if (value == undefined) {
      return;
    }
  
    var keys = Object.keys(value);
    if (keys.length == 0) {
      return;
    }
  
    if (keys.length > 1) {
      throw new TypeError("You may set only one member on a union.");
    }
  
    var fields = [
        "debug_border_quad_state",
        "render_pass_quad_state",
        "solid_color_quad_state",
        "stream_video_quad_state",
        "surface_quad_state",
        "texture_quad_state",
        "tile_quad_state",
        "yuv_video_quad_state",
    ];
  
    if (fields.indexOf(keys[0]) < 0) {
      throw new ReferenceError(keys[0] + " is not a DrawQuadState member.");
  
    }
  
    this[keys[0]] = value[keys[0]];
  }
  Object.defineProperty(DrawQuadState.prototype, "debug_border_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.debug_border_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.debug_border_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.debug_border_quad_state;
      this.$data = value;
    }
  });
  Object.defineProperty(DrawQuadState.prototype, "render_pass_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.render_pass_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.render_pass_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.render_pass_quad_state;
      this.$data = value;
    }
  });
  Object.defineProperty(DrawQuadState.prototype, "solid_color_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.solid_color_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.solid_color_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.solid_color_quad_state;
      this.$data = value;
    }
  });
  Object.defineProperty(DrawQuadState.prototype, "stream_video_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.stream_video_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.stream_video_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.stream_video_quad_state;
      this.$data = value;
    }
  });
  Object.defineProperty(DrawQuadState.prototype, "surface_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.surface_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.surface_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.surface_quad_state;
      this.$data = value;
    }
  });
  Object.defineProperty(DrawQuadState.prototype, "texture_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.texture_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.texture_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.texture_quad_state;
      this.$data = value;
    }
  });
  Object.defineProperty(DrawQuadState.prototype, "tile_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.tile_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.tile_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.tile_quad_state;
      this.$data = value;
    }
  });
  Object.defineProperty(DrawQuadState.prototype, "yuv_video_quad_state", {
    get: function() {
      if (this.$tag != DrawQuadState.Tags.yuv_video_quad_state) {
        throw new ReferenceError(
            "DrawQuadState.yuv_video_quad_state is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = DrawQuadState.Tags.yuv_video_quad_state;
      this.$data = value;
    }
  });
  
  
    DrawQuadState.encode = function(encoder, val) {
      if (val == null) {
        encoder.writeUint64(0);
        encoder.writeUint64(0);
        return;
      }
      if (val.$tag == undefined) {
        throw new TypeError("Cannot encode unions with an unknown member set.");
      }
    
      encoder.writeUint32(16);
      encoder.writeUint32(val.$tag);
      switch (val.$tag) {
        case DrawQuadState.Tags.debug_border_quad_state:
          encoder.encodeStructPointer(DebugBorderQuadState, val.debug_border_quad_state);
          break;
        case DrawQuadState.Tags.render_pass_quad_state:
          encoder.encodeStructPointer(RenderPassQuadState, val.render_pass_quad_state);
          break;
        case DrawQuadState.Tags.solid_color_quad_state:
          encoder.encodeStructPointer(SolidColorQuadState, val.solid_color_quad_state);
          break;
        case DrawQuadState.Tags.stream_video_quad_state:
          encoder.encodeStructPointer(StreamVideoQuadState, val.stream_video_quad_state);
          break;
        case DrawQuadState.Tags.surface_quad_state:
          encoder.encodeStructPointer(SurfaceQuadState, val.surface_quad_state);
          break;
        case DrawQuadState.Tags.texture_quad_state:
          encoder.encodeStructPointer(TextureQuadState, val.texture_quad_state);
          break;
        case DrawQuadState.Tags.tile_quad_state:
          encoder.encodeStructPointer(TileQuadState, val.tile_quad_state);
          break;
        case DrawQuadState.Tags.yuv_video_quad_state:
          encoder.encodeStructPointer(YUVVideoQuadState, val.yuv_video_quad_state);
          break;
      }
      encoder.align();
    };
  
  
    DrawQuadState.decode = function(decoder) {
      var size = decoder.readUint32();
      if (size == 0) {
        decoder.readUint32();
        decoder.readUint64();
        return null;
      }
    
      var result = new DrawQuadState();
      var tag = decoder.readUint32();
      switch (tag) {
        case DrawQuadState.Tags.debug_border_quad_state:
          result.debug_border_quad_state = decoder.decodeStructPointer(DebugBorderQuadState);
          break;
        case DrawQuadState.Tags.render_pass_quad_state:
          result.render_pass_quad_state = decoder.decodeStructPointer(RenderPassQuadState);
          break;
        case DrawQuadState.Tags.solid_color_quad_state:
          result.solid_color_quad_state = decoder.decodeStructPointer(SolidColorQuadState);
          break;
        case DrawQuadState.Tags.stream_video_quad_state:
          result.stream_video_quad_state = decoder.decodeStructPointer(StreamVideoQuadState);
          break;
        case DrawQuadState.Tags.surface_quad_state:
          result.surface_quad_state = decoder.decodeStructPointer(SurfaceQuadState);
          break;
        case DrawQuadState.Tags.texture_quad_state:
          result.texture_quad_state = decoder.decodeStructPointer(TextureQuadState);
          break;
        case DrawQuadState.Tags.tile_quad_state:
          result.tile_quad_state = decoder.decodeStructPointer(TileQuadState);
          break;
        case DrawQuadState.Tags.yuv_video_quad_state:
          result.yuv_video_quad_state = decoder.decodeStructPointer(YUVVideoQuadState);
          break;
      }
      decoder.align();
    
      return result;
    };
  
  
    DrawQuadState.validate = function(messageValidator, offset) {
      var size = messageValidator.decodeUnionSize(offset);
      if (size != 16) {
        return validator.validationError.INVALID_UNION_SIZE;
      }
    
      var tag = messageValidator.decodeUnionTag(offset);
      var data_offset = offset + 8;
      var err;
      switch (tag) {
        case DrawQuadState.Tags.debug_border_quad_state:
          
    
    // validate DrawQuadState.debug_border_quad_state
    err = messageValidator.validateStructPointer(data_offset, DebugBorderQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case DrawQuadState.Tags.render_pass_quad_state:
          
    
    // validate DrawQuadState.render_pass_quad_state
    err = messageValidator.validateStructPointer(data_offset, RenderPassQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case DrawQuadState.Tags.solid_color_quad_state:
          
    
    // validate DrawQuadState.solid_color_quad_state
    err = messageValidator.validateStructPointer(data_offset, SolidColorQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case DrawQuadState.Tags.stream_video_quad_state:
          
    
    // validate DrawQuadState.stream_video_quad_state
    err = messageValidator.validateStructPointer(data_offset, StreamVideoQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case DrawQuadState.Tags.surface_quad_state:
          
    
    // validate DrawQuadState.surface_quad_state
    err = messageValidator.validateStructPointer(data_offset, SurfaceQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case DrawQuadState.Tags.texture_quad_state:
          
    
    // validate DrawQuadState.texture_quad_state
    err = messageValidator.validateStructPointer(data_offset, TextureQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case DrawQuadState.Tags.tile_quad_state:
          
    
    // validate DrawQuadState.tile_quad_state
    err = messageValidator.validateStructPointer(data_offset, TileQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case DrawQuadState.Tags.yuv_video_quad_state:
          
    
    // validate DrawQuadState.yuv_video_quad_state
    err = messageValidator.validateStructPointer(data_offset, YUVVideoQuadState, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
      }
    
      return validator.validationError.NONE;
    };
  
  DrawQuadState.encodedSize = 16;

  var exports = {};
  exports.YUVColorSpace = YUVColorSpace;
  exports.DebugBorderQuadState = DebugBorderQuadState;
  exports.RenderPassQuadState = RenderPassQuadState;
  exports.SolidColorQuadState = SolidColorQuadState;
  exports.StreamVideoQuadState = StreamVideoQuadState;
  exports.SurfaceQuadState = SurfaceQuadState;
  exports.TextureQuadState = TextureQuadState;
  exports.TileQuadState = TileQuadState;
  exports.YUVVideoQuadState = YUVVideoQuadState;
  exports.DrawQuad = DrawQuad;
  exports.DrawQuadState = DrawQuadState;

  return exports;
});
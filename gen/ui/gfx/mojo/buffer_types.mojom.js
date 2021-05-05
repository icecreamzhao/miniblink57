// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/gfx/mojo/buffer_types.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var BufferFormat = {};
  BufferFormat.ATC = 0;
  BufferFormat.ATCIA = BufferFormat.ATC + 1;
  BufferFormat.DXT1 = BufferFormat.ATCIA + 1;
  BufferFormat.DXT5 = BufferFormat.DXT1 + 1;
  BufferFormat.ETC1 = BufferFormat.DXT5 + 1;
  BufferFormat.R_8 = BufferFormat.ETC1 + 1;
  BufferFormat.RG_88 = BufferFormat.R_8 + 1;
  BufferFormat.BGR_565 = BufferFormat.RG_88 + 1;
  BufferFormat.RGBA_4444 = BufferFormat.BGR_565 + 1;
  BufferFormat.RGBX_8888 = BufferFormat.RGBA_4444 + 1;
  BufferFormat.RGBA_8888 = BufferFormat.RGBX_8888 + 1;
  BufferFormat.BGRX_8888 = BufferFormat.RGBA_8888 + 1;
  BufferFormat.BGRA_8888 = BufferFormat.BGRX_8888 + 1;
  BufferFormat.YVU_420 = BufferFormat.BGRA_8888 + 1;
  BufferFormat.YUV_420_BIPLANAR = BufferFormat.YVU_420 + 1;
  BufferFormat.UYVY_422 = BufferFormat.YUV_420_BIPLANAR + 1;
  BufferFormat.LAST = BufferFormat.UYVY_422;

  BufferFormat.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      return true;
    }
    return false;
  };

  BufferFormat.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var BufferUsage = {};
  BufferUsage.GPU_READ = 0;
  BufferUsage.SCANOUT = BufferUsage.GPU_READ + 1;
  BufferUsage.GPU_READ_CPU_READ_WRITE = BufferUsage.SCANOUT + 1;
  BufferUsage.GPU_READ_CPU_READ_WRITE_PERSISTENT = BufferUsage.GPU_READ_CPU_READ_WRITE + 1;
  BufferUsage.LAST = BufferUsage.GPU_READ_CPU_READ_WRITE_PERSISTENT;

  BufferUsage.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  BufferUsage.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var GpuMemoryBufferType = {};
  GpuMemoryBufferType.EMPTY_BUFFER = 0;
  GpuMemoryBufferType.SHARED_MEMORY_BUFFER = GpuMemoryBufferType.EMPTY_BUFFER + 1;
  GpuMemoryBufferType.IO_SURFACE_BUFFER = GpuMemoryBufferType.SHARED_MEMORY_BUFFER + 1;
  GpuMemoryBufferType.OZONE_NATIVE_PIXMAP = GpuMemoryBufferType.IO_SURFACE_BUFFER + 1;
  GpuMemoryBufferType.LAST = GpuMemoryBufferType.OZONE_NATIVE_PIXMAP;

  GpuMemoryBufferType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  GpuMemoryBufferType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function GpuMemoryBufferId(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuMemoryBufferId.prototype.initDefaults_ = function() {
    this.id = 0;
  };
  GpuMemoryBufferId.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuMemoryBufferId.validate = function(messageValidator, offset) {
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

  GpuMemoryBufferId.encodedSize = codec.kStructHeaderSize + 8;

  GpuMemoryBufferId.decode = function(decoder) {
    var packed;
    var val = new GpuMemoryBufferId();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GpuMemoryBufferId.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuMemoryBufferId.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function NativePixmapPlane(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NativePixmapPlane.prototype.initDefaults_ = function() {
    this.stride = 0;
    this.offset = 0;
    this.size = 0;
    this.modifier = 0;
  };
  NativePixmapPlane.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NativePixmapPlane.validate = function(messageValidator, offset) {
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





    return validator.validationError.NONE;
  };

  NativePixmapPlane.encodedSize = codec.kStructHeaderSize + 24;

  NativePixmapPlane.decode = function(decoder) {
    var packed;
    var val = new NativePixmapPlane();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.stride = decoder.decodeStruct(codec.Uint32);
    val.offset = decoder.decodeStruct(codec.Int32);
    val.size = decoder.decodeStruct(codec.Uint64);
    val.modifier = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  NativePixmapPlane.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NativePixmapPlane.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.stride);
    encoder.encodeStruct(codec.Int32, val.offset);
    encoder.encodeStruct(codec.Uint64, val.size);
    encoder.encodeStruct(codec.Uint64, val.modifier);
  };
  function NativePixmapHandle(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NativePixmapHandle.prototype.initDefaults_ = function() {
    this.fds = null;
    this.planes = null;
  };
  NativePixmapHandle.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NativePixmapHandle.validate = function(messageValidator, offset) {
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


    
    // validate NativePixmapHandle.fds
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 4, codec.Handle, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NativePixmapHandle.planes
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(NativePixmapPlane), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NativePixmapHandle.encodedSize = codec.kStructHeaderSize + 16;

  NativePixmapHandle.decode = function(decoder) {
    var packed;
    var val = new NativePixmapHandle();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.fds = decoder.decodeArrayPointer(codec.Handle);
    val.planes = decoder.decodeArrayPointer(new codec.PointerTo(NativePixmapPlane));
    return val;
  };

  NativePixmapHandle.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NativePixmapHandle.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Handle, val.fds);
    encoder.encodeArrayPointer(new codec.PointerTo(NativePixmapPlane), val.planes);
  };
  function GpuMemoryBufferHandle(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuMemoryBufferHandle.prototype.initDefaults_ = function() {
    this.type = 0;
    this.shared_memory_handle = null;
    this.id = null;
    this.offset = 0;
    this.stride = 0;
    this.native_pixmap_handle = null;
    this.mach_port = null;
  };
  GpuMemoryBufferHandle.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuMemoryBufferHandle.validate = function(messageValidator, offset) {
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


    
    // validate GpuMemoryBufferHandle.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, GpuMemoryBufferType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuMemoryBufferHandle.id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, GpuMemoryBufferId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuMemoryBufferHandle.shared_memory_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 4, true)
    if (err !== validator.validationError.NONE)
        return err;




    
    // validate GpuMemoryBufferHandle.native_pixmap_handle
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, NativePixmapHandle, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuMemoryBufferHandle.mach_port
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 32, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuMemoryBufferHandle.encodedSize = codec.kStructHeaderSize + 40;

  GpuMemoryBufferHandle.decode = function(decoder) {
    var packed;
    var val = new GpuMemoryBufferHandle();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    val.shared_memory_handle = decoder.decodeStruct(codec.NullableHandle);
    val.id = decoder.decodeStructPointer(GpuMemoryBufferId);
    val.offset = decoder.decodeStruct(codec.Uint32);
    val.stride = decoder.decodeStruct(codec.Uint32);
    val.native_pixmap_handle = decoder.decodeStructPointer(NativePixmapHandle);
    val.mach_port = decoder.decodeStruct(codec.NullableHandle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GpuMemoryBufferHandle.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuMemoryBufferHandle.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.encodeStruct(codec.NullableHandle, val.shared_memory_handle);
    encoder.encodeStructPointer(GpuMemoryBufferId, val.id);
    encoder.encodeStruct(codec.Uint32, val.offset);
    encoder.encodeStruct(codec.Uint32, val.stride);
    encoder.encodeStructPointer(NativePixmapHandle, val.native_pixmap_handle);
    encoder.encodeStruct(codec.NullableHandle, val.mach_port);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.BufferFormat = BufferFormat;
  exports.BufferUsage = BufferUsage;
  exports.GpuMemoryBufferType = GpuMemoryBufferType;
  exports.GpuMemoryBufferId = GpuMemoryBufferId;
  exports.NativePixmapPlane = NativePixmapPlane;
  exports.NativePixmapHandle = NativePixmapHandle;
  exports.GpuMemoryBufferHandle = GpuMemoryBufferHandle;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("skia/public/interfaces/bitmap.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var ColorType = {};
  ColorType.UNKNOWN = 0;
  ColorType.ALPHA_8 = ColorType.UNKNOWN + 1;
  ColorType.RGB_565 = ColorType.ALPHA_8 + 1;
  ColorType.ARGB_4444 = ColorType.RGB_565 + 1;
  ColorType.RGBA_8888 = ColorType.ARGB_4444 + 1;
  ColorType.BGRA_8888 = ColorType.RGBA_8888 + 1;
  ColorType.INDEX_8 = ColorType.BGRA_8888 + 1;
  ColorType.GRAY_8 = ColorType.INDEX_8 + 1;

  ColorType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    }
    return false;
  };

  ColorType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var AlphaType = {};
  AlphaType.UNKNOWN = 0;
  AlphaType.ALPHA_TYPE_OPAQUE = AlphaType.UNKNOWN + 1;
  AlphaType.PREMUL = AlphaType.ALPHA_TYPE_OPAQUE + 1;
  AlphaType.UNPREMUL = AlphaType.PREMUL + 1;

  AlphaType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  AlphaType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var ColorProfileType = {};
  ColorProfileType.LINEAR = 0;
  ColorProfileType.SRGB = ColorProfileType.LINEAR + 1;

  ColorProfileType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  ColorProfileType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function Bitmap(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Bitmap.prototype.initDefaults_ = function() {
    this.color_type = 0;
    this.alpha_type = 0;
    this.profile_type = 0;
    this.width = 0;
    this.height = 0;
    this.row_bytes = 0;
    this.pixel_data = null;
  };
  Bitmap.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Bitmap.validate = function(messageValidator, offset) {
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


    
    // validate Bitmap.color_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, ColorType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Bitmap.alpha_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, AlphaType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Bitmap.profile_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, ColorProfileType);
    if (err !== validator.validationError.NONE)
        return err;





    
    // validate Bitmap.pixel_data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 32, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Bitmap.encodedSize = codec.kStructHeaderSize + 40;

  Bitmap.decode = function(decoder) {
    var packed;
    var val = new Bitmap();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.color_type = decoder.decodeStruct(codec.Int32);
    val.alpha_type = decoder.decodeStruct(codec.Int32);
    val.profile_type = decoder.decodeStruct(codec.Int32);
    val.width = decoder.decodeStruct(codec.Uint32);
    val.height = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.row_bytes = decoder.decodeStruct(codec.Uint64);
    val.pixel_data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  Bitmap.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Bitmap.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.color_type);
    encoder.encodeStruct(codec.Int32, val.alpha_type);
    encoder.encodeStruct(codec.Int32, val.profile_type);
    encoder.encodeStruct(codec.Uint32, val.width);
    encoder.encodeStruct(codec.Uint32, val.height);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint64, val.row_bytes);
    encoder.encodeArrayPointer(codec.Uint8, val.pixel_data);
  };

  var exports = {};
  exports.ColorType = ColorType;
  exports.AlphaType = AlphaType;
  exports.ColorProfileType = ColorProfileType;
  exports.Bitmap = Bitmap;

  return exports;
});
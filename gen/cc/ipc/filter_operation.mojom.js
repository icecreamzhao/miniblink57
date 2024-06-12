// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/filter_operation.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "skia/public/interfaces/image_filter.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, image_filter$, geometry$) {
  var FilterType = {};
  FilterType.GRAYSCALE = 0;
  FilterType.SEPIA = FilterType.GRAYSCALE + 1;
  FilterType.SATURATE = FilterType.SEPIA + 1;
  FilterType.HUE_ROTATE = FilterType.SATURATE + 1;
  FilterType.INVERT = FilterType.HUE_ROTATE + 1;
  FilterType.BRIGHTNESS = FilterType.INVERT + 1;
  FilterType.CONTRAST = FilterType.BRIGHTNESS + 1;
  FilterType.OPACITY = FilterType.CONTRAST + 1;
  FilterType.BLUR = FilterType.OPACITY + 1;
  FilterType.DROP_SHADOW = FilterType.BLUR + 1;
  FilterType.COLOR_MATRIX = FilterType.DROP_SHADOW + 1;
  FilterType.ZOOM = FilterType.COLOR_MATRIX + 1;
  FilterType.REFERENCE = FilterType.ZOOM + 1;
  FilterType.SATURATING_BRIGHTNESS = FilterType.REFERENCE + 1;
  FilterType.ALPHA_THRESHOLD = FilterType.SATURATING_BRIGHTNESS + 1;
  FilterType.FILTER_TYPE_LAST = FilterType.ALPHA_THRESHOLD;

  FilterType.isKnownEnumValue = function(value) {
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
      return true;
    }
    return false;
  };

  FilterType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function FilterOperation(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FilterOperation.prototype.initDefaults_ = function() {
    this.type = 0;
    this.amount = 0;
    this.drop_shadow_offset = null;
    this.drop_shadow_color = 0;
    this.zoom_inset = 0;
    this.image_filter = null;
    this.matrix = null;
  };
  FilterOperation.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FilterOperation.validate = function(messageValidator, offset) {
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


    
    // validate FilterOperation.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, FilterType);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate FilterOperation.drop_shadow_offset
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Point, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate FilterOperation.image_filter
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, image_filter$.ImageFilter, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FilterOperation.matrix
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 32, 4, codec.Float, true, [20], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  FilterOperation.encodedSize = codec.kStructHeaderSize + 40;

  FilterOperation.decode = function(decoder) {
    var packed;
    var val = new FilterOperation();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    val.amount = decoder.decodeStruct(codec.Float);
    val.drop_shadow_offset = decoder.decodeStructPointer(geometry$.Point);
    val.drop_shadow_color = decoder.decodeStruct(codec.Uint32);
    val.zoom_inset = decoder.decodeStruct(codec.Int32);
    val.image_filter = decoder.decodeStructPointer(image_filter$.ImageFilter);
    val.matrix = decoder.decodeArrayPointer(codec.Float);
    return val;
  };

  FilterOperation.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FilterOperation.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.encodeStruct(codec.Float, val.amount);
    encoder.encodeStructPointer(geometry$.Point, val.drop_shadow_offset);
    encoder.encodeStruct(codec.Uint32, val.drop_shadow_color);
    encoder.encodeStruct(codec.Int32, val.zoom_inset);
    encoder.encodeStructPointer(image_filter$.ImageFilter, val.image_filter);
    encoder.encodeArrayPointer(codec.Float, val.matrix);
  };

  var exports = {};
  exports.FilterType = FilterType;
  exports.FilterOperation = FilterOperation;

  return exports;
});
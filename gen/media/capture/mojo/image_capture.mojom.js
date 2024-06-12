// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/capture/mojo/image_capture.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var MeteringMode = {};
  MeteringMode.NONE = 0;
  MeteringMode.MANUAL = MeteringMode.NONE + 1;
  MeteringMode.SINGLE_SHOT = MeteringMode.MANUAL + 1;
  MeteringMode.CONTINUOUS = MeteringMode.SINGLE_SHOT + 1;

  MeteringMode.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  MeteringMode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var FillLightMode = {};
  FillLightMode.NONE = 0;
  FillLightMode.OFF = FillLightMode.NONE + 1;
  FillLightMode.AUTO = FillLightMode.OFF + 1;
  FillLightMode.FLASH = FillLightMode.AUTO + 1;
  FillLightMode.TORCH = FillLightMode.FLASH + 1;

  FillLightMode.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    }
    return false;
  };

  FillLightMode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function Range(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Range.prototype.initDefaults_ = function() {
    this.max = 0;
    this.min = 0;
    this.current = 0;
    this.step = 0;
  };
  Range.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Range.validate = function(messageValidator, offset) {
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





    return validator.validationError.NONE;
  };

  Range.encodedSize = codec.kStructHeaderSize + 32;

  Range.decode = function(decoder) {
    var packed;
    var val = new Range();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.max = decoder.decodeStruct(codec.Double);
    val.min = decoder.decodeStruct(codec.Double);
    val.current = decoder.decodeStruct(codec.Double);
    val.step = decoder.decodeStruct(codec.Double);
    return val;
  };

  Range.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Range.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Double, val.max);
    encoder.encodeStruct(codec.Double, val.min);
    encoder.encodeStruct(codec.Double, val.current);
    encoder.encodeStruct(codec.Double, val.step);
  };
  function PhotoCapabilities(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PhotoCapabilities.prototype.initDefaults_ = function() {
    this.white_balance_mode = 0;
    this.exposure_mode = 0;
    this.color_temperature = null;
    this.exposure_compensation = null;
    this.iso = null;
    this.red_eye_reduction = false;
    this.focus_mode = 0;
    this.brightness = null;
    this.contrast = null;
    this.saturation = null;
    this.sharpness = null;
    this.height = null;
    this.width = null;
    this.zoom = null;
    this.fill_light_mode = 0;
  };
  PhotoCapabilities.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PhotoCapabilities.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 112}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.white_balance_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, MeteringMode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.color_temperature
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.exposure_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, MeteringMode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.exposure_compensation
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.iso
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, Range, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PhotoCapabilities.focus_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 36, MeteringMode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.brightness
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.contrast
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 48, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.saturation
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 56, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.sharpness
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 64, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.height
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 72, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.width
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 80, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.zoom
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 88, Range, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoCapabilities.fill_light_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 96, FillLightMode);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PhotoCapabilities.encodedSize = codec.kStructHeaderSize + 104;

  PhotoCapabilities.decode = function(decoder) {
    var packed;
    var val = new PhotoCapabilities();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.white_balance_mode = decoder.decodeStruct(codec.Int32);
    val.exposure_mode = decoder.decodeStruct(codec.Int32);
    val.color_temperature = decoder.decodeStructPointer(Range);
    val.exposure_compensation = decoder.decodeStructPointer(Range);
    val.iso = decoder.decodeStructPointer(Range);
    packed = decoder.readUint8();
    val.red_eye_reduction = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.focus_mode = decoder.decodeStruct(codec.Int32);
    val.brightness = decoder.decodeStructPointer(Range);
    val.contrast = decoder.decodeStructPointer(Range);
    val.saturation = decoder.decodeStructPointer(Range);
    val.sharpness = decoder.decodeStructPointer(Range);
    val.height = decoder.decodeStructPointer(Range);
    val.width = decoder.decodeStructPointer(Range);
    val.zoom = decoder.decodeStructPointer(Range);
    val.fill_light_mode = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PhotoCapabilities.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PhotoCapabilities.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.white_balance_mode);
    encoder.encodeStruct(codec.Int32, val.exposure_mode);
    encoder.encodeStructPointer(Range, val.color_temperature);
    encoder.encodeStructPointer(Range, val.exposure_compensation);
    encoder.encodeStructPointer(Range, val.iso);
    packed = 0;
    packed |= (val.red_eye_reduction & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.focus_mode);
    encoder.encodeStructPointer(Range, val.brightness);
    encoder.encodeStructPointer(Range, val.contrast);
    encoder.encodeStructPointer(Range, val.saturation);
    encoder.encodeStructPointer(Range, val.sharpness);
    encoder.encodeStructPointer(Range, val.height);
    encoder.encodeStructPointer(Range, val.width);
    encoder.encodeStructPointer(Range, val.zoom);
    encoder.encodeStruct(codec.Int32, val.fill_light_mode);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Point2D(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Point2D.prototype.initDefaults_ = function() {
    this.x = 0;
    this.y = 0;
  };
  Point2D.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Point2D.validate = function(messageValidator, offset) {
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

  Point2D.encodedSize = codec.kStructHeaderSize + 8;

  Point2D.decode = function(decoder) {
    var packed;
    var val = new Point2D();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.x = decoder.decodeStruct(codec.Float);
    val.y = decoder.decodeStruct(codec.Float);
    return val;
  };

  Point2D.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Point2D.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.x);
    encoder.encodeStruct(codec.Float, val.y);
  };
  function PhotoSettings(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PhotoSettings.prototype.initDefaults_ = function() {
    this.has_white_balance_mode = false;
    this.has_color_temperature = false;
    this.has_exposure_mode = false;
    this.has_exposure_compensation = false;
    this.has_iso = false;
    this.has_red_eye_reduction = false;
    this.red_eye_reduction = false;
    this.has_focus_mode = false;
    this.has_brightness = false;
    this.has_contrast = false;
    this.has_saturation = false;
    this.has_sharpness = false;
    this.has_zoom = false;
    this.has_width = false;
    this.has_height = false;
    this.has_fill_light_mode = false;
    this.white_balance_mode = 0;
    this.color_temperature = 0;
    this.exposure_mode = 0;
    this.focus_mode = 0;
    this.exposure_compensation = 0;
    this.iso = 0;
    this.points_of_interest = null;
    this.brightness = 0;
    this.contrast = 0;
    this.saturation = 0;
    this.sharpness = 0;
    this.zoom = 0;
    this.width = 0;
    this.height = 0;
    this.fill_light_mode = 0;
  };
  PhotoSettings.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PhotoSettings.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 120}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PhotoSettings.white_balance_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, MeteringMode);
    if (err !== validator.validationError.NONE)
        return err;





    
    // validate PhotoSettings.exposure_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, MeteringMode);
    if (err !== validator.validationError.NONE)
        return err;









    
    // validate PhotoSettings.focus_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 20, MeteringMode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PhotoSettings.points_of_interest
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 40, 8, new codec.PointerTo(Point2D), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

















    
    // validate PhotoSettings.fill_light_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 104, FillLightMode);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PhotoSettings.encodedSize = codec.kStructHeaderSize + 112;

  PhotoSettings.decode = function(decoder) {
    var packed;
    var val = new PhotoSettings();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.has_white_balance_mode = (packed >> 0) & 1 ? true : false;
    val.has_color_temperature = (packed >> 1) & 1 ? true : false;
    val.has_exposure_mode = (packed >> 2) & 1 ? true : false;
    val.has_exposure_compensation = (packed >> 3) & 1 ? true : false;
    val.has_iso = (packed >> 4) & 1 ? true : false;
    val.has_red_eye_reduction = (packed >> 5) & 1 ? true : false;
    val.red_eye_reduction = (packed >> 6) & 1 ? true : false;
    val.has_focus_mode = (packed >> 7) & 1 ? true : false;
    packed = decoder.readUint8();
    val.has_brightness = (packed >> 0) & 1 ? true : false;
    val.has_contrast = (packed >> 1) & 1 ? true : false;
    val.has_saturation = (packed >> 2) & 1 ? true : false;
    val.has_sharpness = (packed >> 3) & 1 ? true : false;
    val.has_zoom = (packed >> 4) & 1 ? true : false;
    val.has_width = (packed >> 5) & 1 ? true : false;
    val.has_height = (packed >> 6) & 1 ? true : false;
    val.has_fill_light_mode = (packed >> 7) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    val.white_balance_mode = decoder.decodeStruct(codec.Int32);
    val.color_temperature = decoder.decodeStruct(codec.Double);
    val.exposure_mode = decoder.decodeStruct(codec.Int32);
    val.focus_mode = decoder.decodeStruct(codec.Int32);
    val.exposure_compensation = decoder.decodeStruct(codec.Double);
    val.iso = decoder.decodeStruct(codec.Double);
    val.points_of_interest = decoder.decodeArrayPointer(new codec.PointerTo(Point2D));
    val.brightness = decoder.decodeStruct(codec.Double);
    val.contrast = decoder.decodeStruct(codec.Double);
    val.saturation = decoder.decodeStruct(codec.Double);
    val.sharpness = decoder.decodeStruct(codec.Double);
    val.zoom = decoder.decodeStruct(codec.Double);
    val.width = decoder.decodeStruct(codec.Double);
    val.height = decoder.decodeStruct(codec.Double);
    val.fill_light_mode = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PhotoSettings.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PhotoSettings.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.has_white_balance_mode & 1) << 0
    packed |= (val.has_color_temperature & 1) << 1
    packed |= (val.has_exposure_mode & 1) << 2
    packed |= (val.has_exposure_compensation & 1) << 3
    packed |= (val.has_iso & 1) << 4
    packed |= (val.has_red_eye_reduction & 1) << 5
    packed |= (val.red_eye_reduction & 1) << 6
    packed |= (val.has_focus_mode & 1) << 7
    encoder.writeUint8(packed);
    packed = 0;
    packed |= (val.has_brightness & 1) << 0
    packed |= (val.has_contrast & 1) << 1
    packed |= (val.has_saturation & 1) << 2
    packed |= (val.has_sharpness & 1) << 3
    packed |= (val.has_zoom & 1) << 4
    packed |= (val.has_width & 1) << 5
    packed |= (val.has_height & 1) << 6
    packed |= (val.has_fill_light_mode & 1) << 7
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.white_balance_mode);
    encoder.encodeStruct(codec.Double, val.color_temperature);
    encoder.encodeStruct(codec.Int32, val.exposure_mode);
    encoder.encodeStruct(codec.Int32, val.focus_mode);
    encoder.encodeStruct(codec.Double, val.exposure_compensation);
    encoder.encodeStruct(codec.Double, val.iso);
    encoder.encodeArrayPointer(new codec.PointerTo(Point2D), val.points_of_interest);
    encoder.encodeStruct(codec.Double, val.brightness);
    encoder.encodeStruct(codec.Double, val.contrast);
    encoder.encodeStruct(codec.Double, val.saturation);
    encoder.encodeStruct(codec.Double, val.sharpness);
    encoder.encodeStruct(codec.Double, val.zoom);
    encoder.encodeStruct(codec.Double, val.width);
    encoder.encodeStruct(codec.Double, val.height);
    encoder.encodeStruct(codec.Int32, val.fill_light_mode);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Blob(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Blob.prototype.initDefaults_ = function() {
    this.mime_type = null;
    this.data = null;
  };
  Blob.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Blob.validate = function(messageValidator, offset) {
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


    
    // validate Blob.mime_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Blob.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Blob.encodedSize = codec.kStructHeaderSize + 16;

  Blob.decode = function(decoder) {
    var packed;
    var val = new Blob();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.mime_type = decoder.decodeStruct(codec.String);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  Blob.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Blob.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.mime_type);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function ImageCapture_GetCapabilities_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ImageCapture_GetCapabilities_Params.prototype.initDefaults_ = function() {
    this.source_id = null;
  };
  ImageCapture_GetCapabilities_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ImageCapture_GetCapabilities_Params.validate = function(messageValidator, offset) {
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


    
    // validate ImageCapture_GetCapabilities_Params.source_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ImageCapture_GetCapabilities_Params.encodedSize = codec.kStructHeaderSize + 8;

  ImageCapture_GetCapabilities_Params.decode = function(decoder) {
    var packed;
    var val = new ImageCapture_GetCapabilities_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.source_id = decoder.decodeStruct(codec.String);
    return val;
  };

  ImageCapture_GetCapabilities_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ImageCapture_GetCapabilities_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.source_id);
  };
  function ImageCapture_GetCapabilities_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ImageCapture_GetCapabilities_ResponseParams.prototype.initDefaults_ = function() {
    this.capabilities = null;
  };
  ImageCapture_GetCapabilities_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ImageCapture_GetCapabilities_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate ImageCapture_GetCapabilities_ResponseParams.capabilities
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PhotoCapabilities, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ImageCapture_GetCapabilities_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  ImageCapture_GetCapabilities_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new ImageCapture_GetCapabilities_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.capabilities = decoder.decodeStructPointer(PhotoCapabilities);
    return val;
  };

  ImageCapture_GetCapabilities_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ImageCapture_GetCapabilities_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PhotoCapabilities, val.capabilities);
  };
  function ImageCapture_SetOptions_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ImageCapture_SetOptions_Params.prototype.initDefaults_ = function() {
    this.source_id = null;
    this.settings = null;
  };
  ImageCapture_SetOptions_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ImageCapture_SetOptions_Params.validate = function(messageValidator, offset) {
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


    
    // validate ImageCapture_SetOptions_Params.source_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ImageCapture_SetOptions_Params.settings
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, PhotoSettings, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ImageCapture_SetOptions_Params.encodedSize = codec.kStructHeaderSize + 16;

  ImageCapture_SetOptions_Params.decode = function(decoder) {
    var packed;
    var val = new ImageCapture_SetOptions_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.source_id = decoder.decodeStruct(codec.String);
    val.settings = decoder.decodeStructPointer(PhotoSettings);
    return val;
  };

  ImageCapture_SetOptions_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ImageCapture_SetOptions_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.source_id);
    encoder.encodeStructPointer(PhotoSettings, val.settings);
  };
  function ImageCapture_SetOptions_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ImageCapture_SetOptions_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  ImageCapture_SetOptions_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ImageCapture_SetOptions_ResponseParams.validate = function(messageValidator, offset) {
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

  ImageCapture_SetOptions_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  ImageCapture_SetOptions_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new ImageCapture_SetOptions_ResponseParams();
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

  ImageCapture_SetOptions_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ImageCapture_SetOptions_ResponseParams.encodedSize);
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
  function ImageCapture_TakePhoto_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ImageCapture_TakePhoto_Params.prototype.initDefaults_ = function() {
    this.source_id = null;
  };
  ImageCapture_TakePhoto_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ImageCapture_TakePhoto_Params.validate = function(messageValidator, offset) {
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


    
    // validate ImageCapture_TakePhoto_Params.source_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ImageCapture_TakePhoto_Params.encodedSize = codec.kStructHeaderSize + 8;

  ImageCapture_TakePhoto_Params.decode = function(decoder) {
    var packed;
    var val = new ImageCapture_TakePhoto_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.source_id = decoder.decodeStruct(codec.String);
    return val;
  };

  ImageCapture_TakePhoto_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ImageCapture_TakePhoto_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.source_id);
  };
  function ImageCapture_TakePhoto_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ImageCapture_TakePhoto_ResponseParams.prototype.initDefaults_ = function() {
    this.blob = null;
  };
  ImageCapture_TakePhoto_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ImageCapture_TakePhoto_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate ImageCapture_TakePhoto_ResponseParams.blob
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, Blob, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ImageCapture_TakePhoto_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  ImageCapture_TakePhoto_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new ImageCapture_TakePhoto_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.blob = decoder.decodeStructPointer(Blob);
    return val;
  };

  ImageCapture_TakePhoto_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ImageCapture_TakePhoto_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(Blob, val.blob);
  };
  var kImageCapture_GetCapabilities_Name = 0;
  var kImageCapture_SetOptions_Name = 1;
  var kImageCapture_TakePhoto_Name = 2;

  function ImageCapturePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ImageCapture,
                                                   handleOrPtrInfo);
  }

  function ImageCaptureProxy(receiver) {
    this.receiver_ = receiver;
  }
  ImageCapturePtr.prototype.getCapabilities = function() {
    return ImageCaptureProxy.prototype.getCapabilities
        .apply(this.ptr.getProxy(), arguments);
  };

  ImageCaptureProxy.prototype.getCapabilities = function(source_id) {
    var params = new ImageCapture_GetCapabilities_Params();
    params.source_id = source_id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kImageCapture_GetCapabilities_Name,
          codec.align(ImageCapture_GetCapabilities_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(ImageCapture_GetCapabilities_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(ImageCapture_GetCapabilities_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ImageCapturePtr.prototype.setOptions = function() {
    return ImageCaptureProxy.prototype.setOptions
        .apply(this.ptr.getProxy(), arguments);
  };

  ImageCaptureProxy.prototype.setOptions = function(source_id, settings) {
    var params = new ImageCapture_SetOptions_Params();
    params.source_id = source_id;
    params.settings = settings;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kImageCapture_SetOptions_Name,
          codec.align(ImageCapture_SetOptions_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(ImageCapture_SetOptions_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(ImageCapture_SetOptions_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ImageCapturePtr.prototype.takePhoto = function() {
    return ImageCaptureProxy.prototype.takePhoto
        .apply(this.ptr.getProxy(), arguments);
  };

  ImageCaptureProxy.prototype.takePhoto = function(source_id) {
    var params = new ImageCapture_TakePhoto_Params();
    params.source_id = source_id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kImageCapture_TakePhoto_Name,
          codec.align(ImageCapture_TakePhoto_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(ImageCapture_TakePhoto_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(ImageCapture_TakePhoto_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function ImageCaptureStub(delegate) {
    this.delegate_ = delegate;
  }
  ImageCaptureStub.prototype.getCapabilities = function(source_id) {
    return this.delegate_ && this.delegate_.getCapabilities && this.delegate_.getCapabilities(source_id);
  }
  ImageCaptureStub.prototype.setOptions = function(source_id, settings) {
    return this.delegate_ && this.delegate_.setOptions && this.delegate_.setOptions(source_id, settings);
  }
  ImageCaptureStub.prototype.takePhoto = function(source_id) {
    return this.delegate_ && this.delegate_.takePhoto && this.delegate_.takePhoto(source_id);
  }

  ImageCaptureStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  ImageCaptureStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kImageCapture_GetCapabilities_Name:
      var params = reader.decodeStruct(ImageCapture_GetCapabilities_Params);
      return this.getCapabilities(params.source_id).then(function(response) {
        var responseParams =
            new ImageCapture_GetCapabilities_ResponseParams();
        responseParams.capabilities = response.capabilities;
        var builder = new codec.MessageWithRequestIDBuilder(
            kImageCapture_GetCapabilities_Name,
            codec.align(ImageCapture_GetCapabilities_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(ImageCapture_GetCapabilities_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kImageCapture_SetOptions_Name:
      var params = reader.decodeStruct(ImageCapture_SetOptions_Params);
      return this.setOptions(params.source_id, params.settings).then(function(response) {
        var responseParams =
            new ImageCapture_SetOptions_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kImageCapture_SetOptions_Name,
            codec.align(ImageCapture_SetOptions_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(ImageCapture_SetOptions_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kImageCapture_TakePhoto_Name:
      var params = reader.decodeStruct(ImageCapture_TakePhoto_Params);
      return this.takePhoto(params.source_id).then(function(response) {
        var responseParams =
            new ImageCapture_TakePhoto_ResponseParams();
        responseParams.blob = response.blob;
        var builder = new codec.MessageWithRequestIDBuilder(
            kImageCapture_TakePhoto_Name,
            codec.align(ImageCapture_TakePhoto_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(ImageCapture_TakePhoto_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateImageCaptureRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kImageCapture_GetCapabilities_Name:
        if (message.expectsResponse())
          paramsClass = ImageCapture_GetCapabilities_Params;
      break;
      case kImageCapture_SetOptions_Name:
        if (message.expectsResponse())
          paramsClass = ImageCapture_SetOptions_Params;
      break;
      case kImageCapture_TakePhoto_Name:
        if (message.expectsResponse())
          paramsClass = ImageCapture_TakePhoto_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateImageCaptureResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kImageCapture_GetCapabilities_Name:
        if (message.isResponse())
          paramsClass = ImageCapture_GetCapabilities_ResponseParams;
        break;
      case kImageCapture_SetOptions_Name:
        if (message.isResponse())
          paramsClass = ImageCapture_SetOptions_ResponseParams;
        break;
      case kImageCapture_TakePhoto_Name:
        if (message.isResponse())
          paramsClass = ImageCapture_TakePhoto_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var ImageCapture = {
    name: 'media::mojom::ImageCapture',
    ptrClass: ImageCapturePtr,
    proxyClass: ImageCaptureProxy,
    stubClass: ImageCaptureStub,
    validateRequest: validateImageCaptureRequest,
    validateResponse: validateImageCaptureResponse,
  };
  ImageCaptureStub.prototype.validator = validateImageCaptureRequest;
  ImageCaptureProxy.prototype.validator = validateImageCaptureResponse;

  var exports = {};
  exports.MeteringMode = MeteringMode;
  exports.FillLightMode = FillLightMode;
  exports.Range = Range;
  exports.PhotoCapabilities = PhotoCapabilities;
  exports.Point2D = Point2D;
  exports.PhotoSettings = PhotoSettings;
  exports.Blob = Blob;
  exports.ImageCapture = ImageCapture;
  exports.ImageCapturePtr = ImageCapturePtr;

  return exports;
});
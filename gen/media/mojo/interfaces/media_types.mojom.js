// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/media_types.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "mojo/common/time.mojom",
], function(bindings, codec, core, validator, geometry$, time$) {
  var BufferingState = {};

  BufferingState.isKnownEnumValue = function(value) {
    return false;
  };

  BufferingState.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var DecodeStatus = {};

  DecodeStatus.isKnownEnumValue = function(value) {
    return false;
  };

  DecodeStatus.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var AudioCodec = {};

  AudioCodec.isKnownEnumValue = function(value) {
    return false;
  };

  AudioCodec.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var ChannelLayout = {};

  ChannelLayout.isKnownEnumValue = function(value) {
    return false;
  };

  ChannelLayout.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var SampleFormat = {};

  SampleFormat.isKnownEnumValue = function(value) {
    return false;
  };

  SampleFormat.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var VideoPixelFormat = {};

  VideoPixelFormat.isKnownEnumValue = function(value) {
    return false;
  };

  VideoPixelFormat.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var ColorSpace = {};

  ColorSpace.isKnownEnumValue = function(value) {
    return false;
  };

  ColorSpace.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var VideoCodec = {};

  VideoCodec.isKnownEnumValue = function(value) {
    return false;
  };

  VideoCodec.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var VideoCodecProfile = {};

  VideoCodecProfile.isKnownEnumValue = function(value) {
    return false;
  };

  VideoCodecProfile.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function Pattern(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Pattern.prototype.initDefaults_ = function() {
    this.encrypt_blocks = 0;
    this.skip_blocks = 0;
  };
  Pattern.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Pattern.validate = function(messageValidator, offset) {
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

  Pattern.encodedSize = codec.kStructHeaderSize + 8;

  Pattern.decode = function(decoder) {
    var packed;
    var val = new Pattern();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.encrypt_blocks = decoder.decodeStruct(codec.Uint32);
    val.skip_blocks = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  Pattern.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Pattern.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.encrypt_blocks);
    encoder.encodeStruct(codec.Uint32, val.skip_blocks);
  };
  function EncryptionScheme(values) {
    this.initDefaults_();
    this.initFields_(values);
  }

  EncryptionScheme.CipherMode = {};

  EncryptionScheme.CipherMode.isKnownEnumValue = function(value) {
    return false;
  };

  EncryptionScheme.CipherMode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  EncryptionScheme.prototype.initDefaults_ = function() {
    this.mode = 0;
    this.pattern = null;
  };
  EncryptionScheme.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  EncryptionScheme.validate = function(messageValidator, offset) {
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


    
    // validate EncryptionScheme.mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, EncryptionScheme.CipherMode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EncryptionScheme.pattern
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, Pattern, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  EncryptionScheme.encodedSize = codec.kStructHeaderSize + 16;

  EncryptionScheme.decode = function(decoder) {
    var packed;
    var val = new EncryptionScheme();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.mode = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.pattern = decoder.decodeStructPointer(Pattern);
    return val;
  };

  EncryptionScheme.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(EncryptionScheme.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.mode);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(Pattern, val.pattern);
  };
  function AudioDecoderConfig(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoderConfig.prototype.initDefaults_ = function() {
    this.codec = 0;
    this.sample_format = 0;
    this.channel_layout = 0;
    this.samples_per_second = 0;
    this.extra_data = null;
    this.seek_preroll = null;
    this.codec_delay = 0;
    this.encryption_scheme = null;
  };
  AudioDecoderConfig.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoderConfig.validate = function(messageValidator, offset) {
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


    
    // validate AudioDecoderConfig.codec
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, AudioCodec);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AudioDecoderConfig.sample_format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, SampleFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AudioDecoderConfig.channel_layout
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, ChannelLayout);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate AudioDecoderConfig.extra_data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AudioDecoderConfig.seek_preroll
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate AudioDecoderConfig.encryption_scheme
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, EncryptionScheme, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioDecoderConfig.encodedSize = codec.kStructHeaderSize + 48;

  AudioDecoderConfig.decode = function(decoder) {
    var packed;
    var val = new AudioDecoderConfig();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.codec = decoder.decodeStruct(codec.Int32);
    val.sample_format = decoder.decodeStruct(codec.Int32);
    val.channel_layout = decoder.decodeStruct(codec.Int32);
    val.samples_per_second = decoder.decodeStruct(codec.Int32);
    val.extra_data = decoder.decodeArrayPointer(codec.Uint8);
    val.seek_preroll = decoder.decodeStructPointer(time$.TimeDelta);
    val.codec_delay = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.encryption_scheme = decoder.decodeStructPointer(EncryptionScheme);
    return val;
  };

  AudioDecoderConfig.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoderConfig.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.codec);
    encoder.encodeStruct(codec.Int32, val.sample_format);
    encoder.encodeStruct(codec.Int32, val.channel_layout);
    encoder.encodeStruct(codec.Int32, val.samples_per_second);
    encoder.encodeArrayPointer(codec.Uint8, val.extra_data);
    encoder.encodeStructPointer(time$.TimeDelta, val.seek_preroll);
    encoder.encodeStruct(codec.Int32, val.codec_delay);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(EncryptionScheme, val.encryption_scheme);
  };
  function VideoDecoderConfig(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoderConfig.prototype.initDefaults_ = function() {
    this.codec = 0;
    this.profile = 0;
    this.format = 0;
    this.color_space = 0;
    this.coded_size = null;
    this.visible_rect = null;
    this.natural_size = null;
    this.extra_data = null;
    this.encryption_scheme = null;
  };
  VideoDecoderConfig.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoderConfig.validate = function(messageValidator, offset) {
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


    
    // validate VideoDecoderConfig.codec
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, VideoCodec);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.profile
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, VideoCodecProfile);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, VideoPixelFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.color_space
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 12, ColorSpace);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.coded_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.visible_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.natural_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.extra_data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 40, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoderConfig.encryption_scheme
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 48, EncryptionScheme, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoDecoderConfig.encodedSize = codec.kStructHeaderSize + 56;

  VideoDecoderConfig.decode = function(decoder) {
    var packed;
    var val = new VideoDecoderConfig();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.codec = decoder.decodeStruct(codec.Int32);
    val.profile = decoder.decodeStruct(codec.Int32);
    val.format = decoder.decodeStruct(codec.Int32);
    val.color_space = decoder.decodeStruct(codec.Int32);
    val.coded_size = decoder.decodeStructPointer(geometry$.Size);
    val.visible_rect = decoder.decodeStructPointer(geometry$.Rect);
    val.natural_size = decoder.decodeStructPointer(geometry$.Size);
    val.extra_data = decoder.decodeArrayPointer(codec.Uint8);
    val.encryption_scheme = decoder.decodeStructPointer(EncryptionScheme);
    return val;
  };

  VideoDecoderConfig.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoderConfig.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.codec);
    encoder.encodeStruct(codec.Int32, val.profile);
    encoder.encodeStruct(codec.Int32, val.format);
    encoder.encodeStruct(codec.Int32, val.color_space);
    encoder.encodeStructPointer(geometry$.Size, val.coded_size);
    encoder.encodeStructPointer(geometry$.Rect, val.visible_rect);
    encoder.encodeStructPointer(geometry$.Size, val.natural_size);
    encoder.encodeArrayPointer(codec.Uint8, val.extra_data);
    encoder.encodeStructPointer(EncryptionScheme, val.encryption_scheme);
  };
  function SubsampleEntry(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SubsampleEntry.prototype.initDefaults_ = function() {
  };
  SubsampleEntry.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SubsampleEntry.validate = function(messageValidator, offset) {
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

  SubsampleEntry.encodedSize = codec.kStructHeaderSize + 0;

  SubsampleEntry.decode = function(decoder) {
    var packed;
    var val = new SubsampleEntry();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  SubsampleEntry.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SubsampleEntry.encodedSize);
    encoder.writeUint32(0);
  };
  function DecryptConfig(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DecryptConfig.prototype.initDefaults_ = function() {
    this.key_id = null;
    this.iv = null;
    this.subsamples = null;
  };
  DecryptConfig.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DecryptConfig.validate = function(messageValidator, offset) {
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


    
    // validate DecryptConfig.key_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DecryptConfig.iv
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DecryptConfig.subsamples
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(SubsampleEntry), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DecryptConfig.encodedSize = codec.kStructHeaderSize + 24;

  DecryptConfig.decode = function(decoder) {
    var packed;
    var val = new DecryptConfig();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key_id = decoder.decodeStruct(codec.String);
    val.iv = decoder.decodeStruct(codec.String);
    val.subsamples = decoder.decodeArrayPointer(new codec.PointerTo(SubsampleEntry));
    return val;
  };

  DecryptConfig.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DecryptConfig.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.key_id);
    encoder.encodeStruct(codec.String, val.iv);
    encoder.encodeArrayPointer(new codec.PointerTo(SubsampleEntry), val.subsamples);
  };
  function DecoderBuffer(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DecoderBuffer.prototype.initDefaults_ = function() {
    this.timestamp = null;
    this.duration = null;
    this.is_end_of_stream = false;
    this.is_key_frame = false;
    this.data_size = 0;
    this.side_data = null;
    this.decrypt_config = null;
    this.front_discard = null;
    this.back_discard = null;
    this.splice_timestamp = null;
  };
  DecoderBuffer.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DecoderBuffer.validate = function(messageValidator, offset) {
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


    
    // validate DecoderBuffer.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DecoderBuffer.duration
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;





    
    // validate DecoderBuffer.side_data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 24, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DecoderBuffer.decrypt_config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, DecryptConfig, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DecoderBuffer.front_discard
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DecoderBuffer.back_discard
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 48, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DecoderBuffer.splice_timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 56, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DecoderBuffer.encodedSize = codec.kStructHeaderSize + 64;

  DecoderBuffer.decode = function(decoder) {
    var packed;
    var val = new DecoderBuffer();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.timestamp = decoder.decodeStructPointer(time$.TimeDelta);
    val.duration = decoder.decodeStructPointer(time$.TimeDelta);
    packed = decoder.readUint8();
    val.is_end_of_stream = (packed >> 0) & 1 ? true : false;
    val.is_key_frame = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.data_size = decoder.decodeStruct(codec.Uint32);
    val.side_data = decoder.decodeArrayPointer(codec.Uint8);
    val.decrypt_config = decoder.decodeStructPointer(DecryptConfig);
    val.front_discard = decoder.decodeStructPointer(time$.TimeDelta);
    val.back_discard = decoder.decodeStructPointer(time$.TimeDelta);
    val.splice_timestamp = decoder.decodeStructPointer(time$.TimeDelta);
    return val;
  };

  DecoderBuffer.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DecoderBuffer.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(time$.TimeDelta, val.timestamp);
    encoder.encodeStructPointer(time$.TimeDelta, val.duration);
    packed = 0;
    packed |= (val.is_end_of_stream & 1) << 0
    packed |= (val.is_key_frame & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.data_size);
    encoder.encodeArrayPointer(codec.Uint8, val.side_data);
    encoder.encodeStructPointer(DecryptConfig, val.decrypt_config);
    encoder.encodeStructPointer(time$.TimeDelta, val.front_discard);
    encoder.encodeStructPointer(time$.TimeDelta, val.back_discard);
    encoder.encodeStructPointer(time$.TimeDelta, val.splice_timestamp);
  };
  function AudioBuffer(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioBuffer.prototype.initDefaults_ = function() {
    this.sample_format = 0;
    this.channel_layout = 0;
    this.channel_count = 0;
    this.sample_rate = 0;
    this.frame_count = 0;
    this.end_of_stream = false;
    this.timestamp = null;
    this.data = null;
  };
  AudioBuffer.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioBuffer.validate = function(messageValidator, offset) {
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


    
    // validate AudioBuffer.sample_format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, SampleFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AudioBuffer.channel_layout
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, ChannelLayout);
    if (err !== validator.validationError.NONE)
        return err;






    
    // validate AudioBuffer.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AudioBuffer.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 32, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioBuffer.encodedSize = codec.kStructHeaderSize + 40;

  AudioBuffer.decode = function(decoder) {
    var packed;
    var val = new AudioBuffer();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sample_format = decoder.decodeStruct(codec.Int32);
    val.channel_layout = decoder.decodeStruct(codec.Int32);
    val.channel_count = decoder.decodeStruct(codec.Int32);
    val.sample_rate = decoder.decodeStruct(codec.Int32);
    val.frame_count = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.end_of_stream = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.timestamp = decoder.decodeStructPointer(time$.TimeDelta);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  AudioBuffer.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioBuffer.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.sample_format);
    encoder.encodeStruct(codec.Int32, val.channel_layout);
    encoder.encodeStruct(codec.Int32, val.channel_count);
    encoder.encodeStruct(codec.Int32, val.sample_rate);
    encoder.encodeStruct(codec.Int32, val.frame_count);
    packed = 0;
    packed |= (val.end_of_stream & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(time$.TimeDelta, val.timestamp);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function VideoFrame(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoFrame.prototype.initDefaults_ = function() {
    this.format = 0;
    this.end_of_stream = false;
    this.coded_size = null;
    this.visible_rect = null;
    this.natural_size = null;
    this.timestamp = null;
    this.frame_data = null;
    this.y_stride = 0;
    this.frame_data_size = 0;
    this.u_stride = 0;
    this.v_stride = 0;
    this.y_offset = 0;
    this.u_offset = 0;
    this.v_offset = 0;
  };
  VideoFrame.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoFrame.validate = function(messageValidator, offset) {
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


    
    // validate VideoFrame.format
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, VideoPixelFormat);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrame.coded_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrame.visible_rect
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrame.natural_size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate VideoFrame.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoFrame.frame_data
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 40, false)
    if (err !== validator.validationError.NONE)
        return err;








    return validator.validationError.NONE;
  };

  VideoFrame.encodedSize = codec.kStructHeaderSize + 88;

  VideoFrame.decode = function(decoder) {
    var packed;
    var val = new VideoFrame();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.format = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.end_of_stream = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.coded_size = decoder.decodeStructPointer(geometry$.Size);
    val.visible_rect = decoder.decodeStructPointer(geometry$.Rect);
    val.natural_size = decoder.decodeStructPointer(geometry$.Size);
    val.timestamp = decoder.decodeStructPointer(time$.TimeDelta);
    val.frame_data = decoder.decodeStruct(codec.Handle);
    val.y_stride = decoder.decodeStruct(codec.Int32);
    val.frame_data_size = decoder.decodeStruct(codec.Uint64);
    val.u_stride = decoder.decodeStruct(codec.Int32);
    val.v_stride = decoder.decodeStruct(codec.Int32);
    val.y_offset = decoder.decodeStruct(codec.Uint64);
    val.u_offset = decoder.decodeStruct(codec.Uint64);
    val.v_offset = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  VideoFrame.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoFrame.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.format);
    packed = 0;
    packed |= (val.end_of_stream & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Size, val.coded_size);
    encoder.encodeStructPointer(geometry$.Rect, val.visible_rect);
    encoder.encodeStructPointer(geometry$.Size, val.natural_size);
    encoder.encodeStructPointer(time$.TimeDelta, val.timestamp);
    encoder.encodeStruct(codec.Handle, val.frame_data);
    encoder.encodeStruct(codec.Int32, val.y_stride);
    encoder.encodeStruct(codec.Uint64, val.frame_data_size);
    encoder.encodeStruct(codec.Int32, val.u_stride);
    encoder.encodeStruct(codec.Int32, val.v_stride);
    encoder.encodeStruct(codec.Uint64, val.y_offset);
    encoder.encodeStruct(codec.Uint64, val.u_offset);
    encoder.encodeStruct(codec.Uint64, val.v_offset);
  };
  function PipelineStatistics(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PipelineStatistics.prototype.initDefaults_ = function() {
    this.audio_bytes_decoded = 0;
    this.video_bytes_decoded = 0;
    this.video_frames_decoded = 0;
    this.video_frames_dropped = 0;
    this.audio_memory_usage = 0;
    this.video_memory_usage = 0;
  };
  PipelineStatistics.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PipelineStatistics.validate = function(messageValidator, offset) {
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







    return validator.validationError.NONE;
  };

  PipelineStatistics.encodedSize = codec.kStructHeaderSize + 40;

  PipelineStatistics.decode = function(decoder) {
    var packed;
    var val = new PipelineStatistics();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.audio_bytes_decoded = decoder.decodeStruct(codec.Uint64);
    val.video_bytes_decoded = decoder.decodeStruct(codec.Uint64);
    val.video_frames_decoded = decoder.decodeStruct(codec.Uint32);
    val.video_frames_dropped = decoder.decodeStruct(codec.Uint32);
    val.audio_memory_usage = decoder.decodeStruct(codec.Int64);
    val.video_memory_usage = decoder.decodeStruct(codec.Int64);
    return val;
  };

  PipelineStatistics.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PipelineStatistics.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.audio_bytes_decoded);
    encoder.encodeStruct(codec.Uint64, val.video_bytes_decoded);
    encoder.encodeStruct(codec.Uint32, val.video_frames_decoded);
    encoder.encodeStruct(codec.Uint32, val.video_frames_dropped);
    encoder.encodeStruct(codec.Int64, val.audio_memory_usage);
    encoder.encodeStruct(codec.Int64, val.video_memory_usage);
  };

  var exports = {};
  exports.BufferingState = BufferingState;
  exports.DecodeStatus = DecodeStatus;
  exports.AudioCodec = AudioCodec;
  exports.ChannelLayout = ChannelLayout;
  exports.SampleFormat = SampleFormat;
  exports.VideoPixelFormat = VideoPixelFormat;
  exports.ColorSpace = ColorSpace;
  exports.VideoCodec = VideoCodec;
  exports.VideoCodecProfile = VideoCodecProfile;
  exports.Pattern = Pattern;
  exports.EncryptionScheme = EncryptionScheme;
  exports.AudioDecoderConfig = AudioDecoderConfig;
  exports.VideoDecoderConfig = VideoDecoderConfig;
  exports.SubsampleEntry = SubsampleEntry;
  exports.DecryptConfig = DecryptConfig;
  exports.DecoderBuffer = DecoderBuffer;
  exports.AudioBuffer = AudioBuffer;
  exports.VideoFrame = VideoFrame;
  exports.PipelineStatistics = PipelineStatistics;

  return exports;
});
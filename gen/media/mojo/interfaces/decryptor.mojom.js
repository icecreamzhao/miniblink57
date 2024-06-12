// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/decryptor.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/media_types.mojom",
], function(bindings, codec, core, validator, media_types$) {

  function Decryptor_Initialize_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_Initialize_Params.prototype.initDefaults_ = function() {
    this.receive_pipe = null;
    this.transmit_pipe = null;
  };
  Decryptor_Initialize_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_Initialize_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_Initialize_Params.receive_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Decryptor_Initialize_Params.transmit_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 4, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_Initialize_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_Initialize_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_Initialize_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.receive_pipe = decoder.decodeStruct(codec.Handle);
    val.transmit_pipe = decoder.decodeStruct(codec.Handle);
    return val;
  };

  Decryptor_Initialize_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_Initialize_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.receive_pipe);
    encoder.encodeStruct(codec.Handle, val.transmit_pipe);
  };
  function Decryptor_Decrypt_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_Decrypt_Params.prototype.initDefaults_ = function() {
    this.stream_type = 0;
    this.encrypted = null;
  };
  Decryptor_Decrypt_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_Decrypt_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_Decrypt_Params.stream_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Decryptor.StreamType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Decryptor_Decrypt_Params.encrypted
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, media_types$.DecoderBuffer, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_Decrypt_Params.encodedSize = codec.kStructHeaderSize + 16;

  Decryptor_Decrypt_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_Decrypt_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.stream_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.encrypted = decoder.decodeStructPointer(media_types$.DecoderBuffer);
    return val;
  };

  Decryptor_Decrypt_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_Decrypt_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.stream_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(media_types$.DecoderBuffer, val.encrypted);
  };
  function Decryptor_Decrypt_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_Decrypt_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.buffer = null;
  };
  Decryptor_Decrypt_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_Decrypt_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_Decrypt_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Decryptor.Status);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Decryptor_Decrypt_ResponseParams.buffer
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, media_types$.DecoderBuffer, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_Decrypt_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Decryptor_Decrypt_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Decryptor_Decrypt_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.buffer = decoder.decodeStructPointer(media_types$.DecoderBuffer);
    return val;
  };

  Decryptor_Decrypt_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_Decrypt_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(media_types$.DecoderBuffer, val.buffer);
  };
  function Decryptor_CancelDecrypt_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_CancelDecrypt_Params.prototype.initDefaults_ = function() {
    this.stream_type = 0;
  };
  Decryptor_CancelDecrypt_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_CancelDecrypt_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_CancelDecrypt_Params.stream_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Decryptor.StreamType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_CancelDecrypt_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_CancelDecrypt_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_CancelDecrypt_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.stream_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Decryptor_CancelDecrypt_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_CancelDecrypt_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.stream_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Decryptor_InitializeAudioDecoder_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_InitializeAudioDecoder_Params.prototype.initDefaults_ = function() {
    this.config = null;
  };
  Decryptor_InitializeAudioDecoder_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_InitializeAudioDecoder_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_InitializeAudioDecoder_Params.config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.AudioDecoderConfig, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_InitializeAudioDecoder_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_InitializeAudioDecoder_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_InitializeAudioDecoder_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.config = decoder.decodeStructPointer(media_types$.AudioDecoderConfig);
    return val;
  };

  Decryptor_InitializeAudioDecoder_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_InitializeAudioDecoder_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.AudioDecoderConfig, val.config);
  };
  function Decryptor_InitializeAudioDecoder_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_InitializeAudioDecoder_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Decryptor_InitializeAudioDecoder_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_InitializeAudioDecoder_ResponseParams.validate = function(messageValidator, offset) {
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

  Decryptor_InitializeAudioDecoder_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_InitializeAudioDecoder_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Decryptor_InitializeAudioDecoder_ResponseParams();
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

  Decryptor_InitializeAudioDecoder_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_InitializeAudioDecoder_ResponseParams.encodedSize);
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
  function Decryptor_InitializeVideoDecoder_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_InitializeVideoDecoder_Params.prototype.initDefaults_ = function() {
    this.config = null;
  };
  Decryptor_InitializeVideoDecoder_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_InitializeVideoDecoder_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_InitializeVideoDecoder_Params.config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.VideoDecoderConfig, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_InitializeVideoDecoder_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_InitializeVideoDecoder_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_InitializeVideoDecoder_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.config = decoder.decodeStructPointer(media_types$.VideoDecoderConfig);
    return val;
  };

  Decryptor_InitializeVideoDecoder_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_InitializeVideoDecoder_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.VideoDecoderConfig, val.config);
  };
  function Decryptor_InitializeVideoDecoder_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_InitializeVideoDecoder_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Decryptor_InitializeVideoDecoder_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_InitializeVideoDecoder_ResponseParams.validate = function(messageValidator, offset) {
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

  Decryptor_InitializeVideoDecoder_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_InitializeVideoDecoder_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Decryptor_InitializeVideoDecoder_ResponseParams();
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

  Decryptor_InitializeVideoDecoder_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_InitializeVideoDecoder_ResponseParams.encodedSize);
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
  function Decryptor_DecryptAndDecodeAudio_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_DecryptAndDecodeAudio_Params.prototype.initDefaults_ = function() {
    this.encrypted = null;
  };
  Decryptor_DecryptAndDecodeAudio_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_DecryptAndDecodeAudio_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_DecryptAndDecodeAudio_Params.encrypted
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.DecoderBuffer, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_DecryptAndDecodeAudio_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_DecryptAndDecodeAudio_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_DecryptAndDecodeAudio_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.encrypted = decoder.decodeStructPointer(media_types$.DecoderBuffer);
    return val;
  };

  Decryptor_DecryptAndDecodeAudio_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_DecryptAndDecodeAudio_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.DecoderBuffer, val.encrypted);
  };
  function Decryptor_DecryptAndDecodeAudio_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_DecryptAndDecodeAudio_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.audio_buffers = null;
  };
  Decryptor_DecryptAndDecodeAudio_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_DecryptAndDecodeAudio_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_DecryptAndDecodeAudio_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Decryptor.Status);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Decryptor_DecryptAndDecodeAudio_ResponseParams.audio_buffers
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(media_types$.AudioBuffer), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_DecryptAndDecodeAudio_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Decryptor_DecryptAndDecodeAudio_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Decryptor_DecryptAndDecodeAudio_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.audio_buffers = decoder.decodeArrayPointer(new codec.PointerTo(media_types$.AudioBuffer));
    return val;
  };

  Decryptor_DecryptAndDecodeAudio_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_DecryptAndDecodeAudio_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(new codec.PointerTo(media_types$.AudioBuffer), val.audio_buffers);
  };
  function Decryptor_DecryptAndDecodeVideo_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_DecryptAndDecodeVideo_Params.prototype.initDefaults_ = function() {
    this.encrypted = null;
  };
  Decryptor_DecryptAndDecodeVideo_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_DecryptAndDecodeVideo_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_DecryptAndDecodeVideo_Params.encrypted
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.DecoderBuffer, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_DecryptAndDecodeVideo_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_DecryptAndDecodeVideo_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_DecryptAndDecodeVideo_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.encrypted = decoder.decodeStructPointer(media_types$.DecoderBuffer);
    return val;
  };

  Decryptor_DecryptAndDecodeVideo_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_DecryptAndDecodeVideo_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.DecoderBuffer, val.encrypted);
  };
  function Decryptor_DecryptAndDecodeVideo_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_DecryptAndDecodeVideo_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.video_frame = null;
  };
  Decryptor_DecryptAndDecodeVideo_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_DecryptAndDecodeVideo_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_DecryptAndDecodeVideo_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Decryptor.Status);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Decryptor_DecryptAndDecodeVideo_ResponseParams.video_frame
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, media_types$.VideoFrame, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_DecryptAndDecodeVideo_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Decryptor_DecryptAndDecodeVideo_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Decryptor_DecryptAndDecodeVideo_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.video_frame = decoder.decodeStructPointer(media_types$.VideoFrame);
    return val;
  };

  Decryptor_DecryptAndDecodeVideo_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_DecryptAndDecodeVideo_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(media_types$.VideoFrame, val.video_frame);
  };
  function Decryptor_ResetDecoder_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_ResetDecoder_Params.prototype.initDefaults_ = function() {
    this.stream_type = 0;
  };
  Decryptor_ResetDecoder_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_ResetDecoder_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_ResetDecoder_Params.stream_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Decryptor.StreamType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_ResetDecoder_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_ResetDecoder_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_ResetDecoder_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.stream_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Decryptor_ResetDecoder_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_ResetDecoder_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.stream_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Decryptor_DeinitializeDecoder_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_DeinitializeDecoder_Params.prototype.initDefaults_ = function() {
    this.stream_type = 0;
  };
  Decryptor_DeinitializeDecoder_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_DeinitializeDecoder_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_DeinitializeDecoder_Params.stream_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Decryptor.StreamType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Decryptor_DeinitializeDecoder_Params.encodedSize = codec.kStructHeaderSize + 8;

  Decryptor_DeinitializeDecoder_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_DeinitializeDecoder_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.stream_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Decryptor_DeinitializeDecoder_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_DeinitializeDecoder_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.stream_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Decryptor_ReleaseSharedBuffer_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Decryptor_ReleaseSharedBuffer_Params.prototype.initDefaults_ = function() {
    this.buffer = null;
    this.buffer_size = 0;
  };
  Decryptor_ReleaseSharedBuffer_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Decryptor_ReleaseSharedBuffer_Params.validate = function(messageValidator, offset) {
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


    
    // validate Decryptor_ReleaseSharedBuffer_Params.buffer
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  Decryptor_ReleaseSharedBuffer_Params.encodedSize = codec.kStructHeaderSize + 16;

  Decryptor_ReleaseSharedBuffer_Params.decode = function(decoder) {
    var packed;
    var val = new Decryptor_ReleaseSharedBuffer_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.buffer = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.buffer_size = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  Decryptor_ReleaseSharedBuffer_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Decryptor_ReleaseSharedBuffer_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.buffer);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint64, val.buffer_size);
  };
  var kDecryptor_Initialize_Name = 0;
  var kDecryptor_Decrypt_Name = 1;
  var kDecryptor_CancelDecrypt_Name = 2;
  var kDecryptor_InitializeAudioDecoder_Name = 3;
  var kDecryptor_InitializeVideoDecoder_Name = 4;
  var kDecryptor_DecryptAndDecodeAudio_Name = 5;
  var kDecryptor_DecryptAndDecodeVideo_Name = 6;
  var kDecryptor_ResetDecoder_Name = 7;
  var kDecryptor_DeinitializeDecoder_Name = 8;
  var kDecryptor_ReleaseSharedBuffer_Name = 9;

  function DecryptorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Decryptor,
                                                   handleOrPtrInfo);
  }

  function DecryptorProxy(receiver) {
    this.receiver_ = receiver;
  }
  DecryptorPtr.prototype.initialize = function() {
    return DecryptorProxy.prototype.initialize
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.initialize = function(receive_pipe, transmit_pipe) {
    var params = new Decryptor_Initialize_Params();
    params.receive_pipe = receive_pipe;
    params.transmit_pipe = transmit_pipe;
    var builder = new codec.MessageBuilder(
        kDecryptor_Initialize_Name,
        codec.align(Decryptor_Initialize_Params.encodedSize));
    builder.encodeStruct(Decryptor_Initialize_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DecryptorPtr.prototype.decrypt = function() {
    return DecryptorProxy.prototype.decrypt
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.decrypt = function(stream_type, encrypted) {
    var params = new Decryptor_Decrypt_Params();
    params.stream_type = stream_type;
    params.encrypted = encrypted;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDecryptor_Decrypt_Name,
          codec.align(Decryptor_Decrypt_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Decryptor_Decrypt_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Decryptor_Decrypt_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DecryptorPtr.prototype.cancelDecrypt = function() {
    return DecryptorProxy.prototype.cancelDecrypt
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.cancelDecrypt = function(stream_type) {
    var params = new Decryptor_CancelDecrypt_Params();
    params.stream_type = stream_type;
    var builder = new codec.MessageBuilder(
        kDecryptor_CancelDecrypt_Name,
        codec.align(Decryptor_CancelDecrypt_Params.encodedSize));
    builder.encodeStruct(Decryptor_CancelDecrypt_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DecryptorPtr.prototype.initializeAudioDecoder = function() {
    return DecryptorProxy.prototype.initializeAudioDecoder
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.initializeAudioDecoder = function(config) {
    var params = new Decryptor_InitializeAudioDecoder_Params();
    params.config = config;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDecryptor_InitializeAudioDecoder_Name,
          codec.align(Decryptor_InitializeAudioDecoder_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Decryptor_InitializeAudioDecoder_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Decryptor_InitializeAudioDecoder_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DecryptorPtr.prototype.initializeVideoDecoder = function() {
    return DecryptorProxy.prototype.initializeVideoDecoder
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.initializeVideoDecoder = function(config) {
    var params = new Decryptor_InitializeVideoDecoder_Params();
    params.config = config;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDecryptor_InitializeVideoDecoder_Name,
          codec.align(Decryptor_InitializeVideoDecoder_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Decryptor_InitializeVideoDecoder_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Decryptor_InitializeVideoDecoder_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DecryptorPtr.prototype.decryptAndDecodeAudio = function() {
    return DecryptorProxy.prototype.decryptAndDecodeAudio
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.decryptAndDecodeAudio = function(encrypted) {
    var params = new Decryptor_DecryptAndDecodeAudio_Params();
    params.encrypted = encrypted;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDecryptor_DecryptAndDecodeAudio_Name,
          codec.align(Decryptor_DecryptAndDecodeAudio_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Decryptor_DecryptAndDecodeAudio_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Decryptor_DecryptAndDecodeAudio_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DecryptorPtr.prototype.decryptAndDecodeVideo = function() {
    return DecryptorProxy.prototype.decryptAndDecodeVideo
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.decryptAndDecodeVideo = function(encrypted) {
    var params = new Decryptor_DecryptAndDecodeVideo_Params();
    params.encrypted = encrypted;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDecryptor_DecryptAndDecodeVideo_Name,
          codec.align(Decryptor_DecryptAndDecodeVideo_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Decryptor_DecryptAndDecodeVideo_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Decryptor_DecryptAndDecodeVideo_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DecryptorPtr.prototype.resetDecoder = function() {
    return DecryptorProxy.prototype.resetDecoder
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.resetDecoder = function(stream_type) {
    var params = new Decryptor_ResetDecoder_Params();
    params.stream_type = stream_type;
    var builder = new codec.MessageBuilder(
        kDecryptor_ResetDecoder_Name,
        codec.align(Decryptor_ResetDecoder_Params.encodedSize));
    builder.encodeStruct(Decryptor_ResetDecoder_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DecryptorPtr.prototype.deinitializeDecoder = function() {
    return DecryptorProxy.prototype.deinitializeDecoder
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.deinitializeDecoder = function(stream_type) {
    var params = new Decryptor_DeinitializeDecoder_Params();
    params.stream_type = stream_type;
    var builder = new codec.MessageBuilder(
        kDecryptor_DeinitializeDecoder_Name,
        codec.align(Decryptor_DeinitializeDecoder_Params.encodedSize));
    builder.encodeStruct(Decryptor_DeinitializeDecoder_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DecryptorPtr.prototype.releaseSharedBuffer = function() {
    return DecryptorProxy.prototype.releaseSharedBuffer
        .apply(this.ptr.getProxy(), arguments);
  };

  DecryptorProxy.prototype.releaseSharedBuffer = function(buffer, buffer_size) {
    var params = new Decryptor_ReleaseSharedBuffer_Params();
    params.buffer = buffer;
    params.buffer_size = buffer_size;
    var builder = new codec.MessageBuilder(
        kDecryptor_ReleaseSharedBuffer_Name,
        codec.align(Decryptor_ReleaseSharedBuffer_Params.encodedSize));
    builder.encodeStruct(Decryptor_ReleaseSharedBuffer_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DecryptorStub(delegate) {
    this.delegate_ = delegate;
  }
  DecryptorStub.prototype.initialize = function(receive_pipe, transmit_pipe) {
    return this.delegate_ && this.delegate_.initialize && this.delegate_.initialize(receive_pipe, transmit_pipe);
  }
  DecryptorStub.prototype.decrypt = function(stream_type, encrypted) {
    return this.delegate_ && this.delegate_.decrypt && this.delegate_.decrypt(stream_type, encrypted);
  }
  DecryptorStub.prototype.cancelDecrypt = function(stream_type) {
    return this.delegate_ && this.delegate_.cancelDecrypt && this.delegate_.cancelDecrypt(stream_type);
  }
  DecryptorStub.prototype.initializeAudioDecoder = function(config) {
    return this.delegate_ && this.delegate_.initializeAudioDecoder && this.delegate_.initializeAudioDecoder(config);
  }
  DecryptorStub.prototype.initializeVideoDecoder = function(config) {
    return this.delegate_ && this.delegate_.initializeVideoDecoder && this.delegate_.initializeVideoDecoder(config);
  }
  DecryptorStub.prototype.decryptAndDecodeAudio = function(encrypted) {
    return this.delegate_ && this.delegate_.decryptAndDecodeAudio && this.delegate_.decryptAndDecodeAudio(encrypted);
  }
  DecryptorStub.prototype.decryptAndDecodeVideo = function(encrypted) {
    return this.delegate_ && this.delegate_.decryptAndDecodeVideo && this.delegate_.decryptAndDecodeVideo(encrypted);
  }
  DecryptorStub.prototype.resetDecoder = function(stream_type) {
    return this.delegate_ && this.delegate_.resetDecoder && this.delegate_.resetDecoder(stream_type);
  }
  DecryptorStub.prototype.deinitializeDecoder = function(stream_type) {
    return this.delegate_ && this.delegate_.deinitializeDecoder && this.delegate_.deinitializeDecoder(stream_type);
  }
  DecryptorStub.prototype.releaseSharedBuffer = function(buffer, buffer_size) {
    return this.delegate_ && this.delegate_.releaseSharedBuffer && this.delegate_.releaseSharedBuffer(buffer, buffer_size);
  }

  DecryptorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDecryptor_Initialize_Name:
      var params = reader.decodeStruct(Decryptor_Initialize_Params);
      this.initialize(params.receive_pipe, params.transmit_pipe);
      return true;
    case kDecryptor_CancelDecrypt_Name:
      var params = reader.decodeStruct(Decryptor_CancelDecrypt_Params);
      this.cancelDecrypt(params.stream_type);
      return true;
    case kDecryptor_ResetDecoder_Name:
      var params = reader.decodeStruct(Decryptor_ResetDecoder_Params);
      this.resetDecoder(params.stream_type);
      return true;
    case kDecryptor_DeinitializeDecoder_Name:
      var params = reader.decodeStruct(Decryptor_DeinitializeDecoder_Params);
      this.deinitializeDecoder(params.stream_type);
      return true;
    case kDecryptor_ReleaseSharedBuffer_Name:
      var params = reader.decodeStruct(Decryptor_ReleaseSharedBuffer_Params);
      this.releaseSharedBuffer(params.buffer, params.buffer_size);
      return true;
    default:
      return false;
    }
  };

  DecryptorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDecryptor_Decrypt_Name:
      var params = reader.decodeStruct(Decryptor_Decrypt_Params);
      return this.decrypt(params.stream_type, params.encrypted).then(function(response) {
        var responseParams =
            new Decryptor_Decrypt_ResponseParams();
        responseParams.status = response.status;
        responseParams.buffer = response.buffer;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDecryptor_Decrypt_Name,
            codec.align(Decryptor_Decrypt_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Decryptor_Decrypt_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDecryptor_InitializeAudioDecoder_Name:
      var params = reader.decodeStruct(Decryptor_InitializeAudioDecoder_Params);
      return this.initializeAudioDecoder(params.config).then(function(response) {
        var responseParams =
            new Decryptor_InitializeAudioDecoder_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDecryptor_InitializeAudioDecoder_Name,
            codec.align(Decryptor_InitializeAudioDecoder_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Decryptor_InitializeAudioDecoder_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDecryptor_InitializeVideoDecoder_Name:
      var params = reader.decodeStruct(Decryptor_InitializeVideoDecoder_Params);
      return this.initializeVideoDecoder(params.config).then(function(response) {
        var responseParams =
            new Decryptor_InitializeVideoDecoder_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDecryptor_InitializeVideoDecoder_Name,
            codec.align(Decryptor_InitializeVideoDecoder_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Decryptor_InitializeVideoDecoder_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDecryptor_DecryptAndDecodeAudio_Name:
      var params = reader.decodeStruct(Decryptor_DecryptAndDecodeAudio_Params);
      return this.decryptAndDecodeAudio(params.encrypted).then(function(response) {
        var responseParams =
            new Decryptor_DecryptAndDecodeAudio_ResponseParams();
        responseParams.status = response.status;
        responseParams.audio_buffers = response.audio_buffers;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDecryptor_DecryptAndDecodeAudio_Name,
            codec.align(Decryptor_DecryptAndDecodeAudio_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Decryptor_DecryptAndDecodeAudio_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDecryptor_DecryptAndDecodeVideo_Name:
      var params = reader.decodeStruct(Decryptor_DecryptAndDecodeVideo_Params);
      return this.decryptAndDecodeVideo(params.encrypted).then(function(response) {
        var responseParams =
            new Decryptor_DecryptAndDecodeVideo_ResponseParams();
        responseParams.status = response.status;
        responseParams.video_frame = response.video_frame;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDecryptor_DecryptAndDecodeVideo_Name,
            codec.align(Decryptor_DecryptAndDecodeVideo_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Decryptor_DecryptAndDecodeVideo_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDecryptorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDecryptor_Initialize_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Decryptor_Initialize_Params;
      break;
      case kDecryptor_Decrypt_Name:
        if (message.expectsResponse())
          paramsClass = Decryptor_Decrypt_Params;
      break;
      case kDecryptor_CancelDecrypt_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Decryptor_CancelDecrypt_Params;
      break;
      case kDecryptor_InitializeAudioDecoder_Name:
        if (message.expectsResponse())
          paramsClass = Decryptor_InitializeAudioDecoder_Params;
      break;
      case kDecryptor_InitializeVideoDecoder_Name:
        if (message.expectsResponse())
          paramsClass = Decryptor_InitializeVideoDecoder_Params;
      break;
      case kDecryptor_DecryptAndDecodeAudio_Name:
        if (message.expectsResponse())
          paramsClass = Decryptor_DecryptAndDecodeAudio_Params;
      break;
      case kDecryptor_DecryptAndDecodeVideo_Name:
        if (message.expectsResponse())
          paramsClass = Decryptor_DecryptAndDecodeVideo_Params;
      break;
      case kDecryptor_ResetDecoder_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Decryptor_ResetDecoder_Params;
      break;
      case kDecryptor_DeinitializeDecoder_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Decryptor_DeinitializeDecoder_Params;
      break;
      case kDecryptor_ReleaseSharedBuffer_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Decryptor_ReleaseSharedBuffer_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDecryptorResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kDecryptor_Decrypt_Name:
        if (message.isResponse())
          paramsClass = Decryptor_Decrypt_ResponseParams;
        break;
      case kDecryptor_InitializeAudioDecoder_Name:
        if (message.isResponse())
          paramsClass = Decryptor_InitializeAudioDecoder_ResponseParams;
        break;
      case kDecryptor_InitializeVideoDecoder_Name:
        if (message.isResponse())
          paramsClass = Decryptor_InitializeVideoDecoder_ResponseParams;
        break;
      case kDecryptor_DecryptAndDecodeAudio_Name:
        if (message.isResponse())
          paramsClass = Decryptor_DecryptAndDecodeAudio_ResponseParams;
        break;
      case kDecryptor_DecryptAndDecodeVideo_Name:
        if (message.isResponse())
          paramsClass = Decryptor_DecryptAndDecodeVideo_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Decryptor = {
    name: 'media::mojom::Decryptor',
    ptrClass: DecryptorPtr,
    proxyClass: DecryptorProxy,
    stubClass: DecryptorStub,
    validateRequest: validateDecryptorRequest,
    validateResponse: validateDecryptorResponse,
  };
  Decryptor.Status = {};

  Decryptor.Status.isKnownEnumValue = function(value) {
    return false;
  };

  Decryptor.Status.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  Decryptor.StreamType = {};

  Decryptor.StreamType.isKnownEnumValue = function(value) {
    return false;
  };

  Decryptor.StreamType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  DecryptorStub.prototype.validator = validateDecryptorRequest;
  DecryptorProxy.prototype.validator = validateDecryptorResponse;

  var exports = {};
  exports.Decryptor = Decryptor;
  exports.DecryptorPtr = DecryptorPtr;

  return exports;
});
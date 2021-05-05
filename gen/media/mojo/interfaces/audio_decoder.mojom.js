// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/audio_decoder.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/media_types.mojom",
], function(bindings, codec, core, validator, media_types$) {

  function AudioDecoder_Construct_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_Construct_Params.prototype.initDefaults_ = function() {
    this.client = null;
  };
  AudioDecoder_Construct_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_Construct_Params.validate = function(messageValidator, offset) {
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

  AudioDecoder_Construct_Params.encodedSize = codec.kStructHeaderSize + 8;

  AudioDecoder_Construct_Params.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_Construct_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(codec.AssociatedInterfaceNotSupported);
    return val;
  };

  AudioDecoder_Construct_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_Construct_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.AssociatedInterfaceNotSupported, val.client);
  };
  function AudioDecoder_Initialize_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_Initialize_Params.prototype.initDefaults_ = function() {
    this.config = null;
    this.cdm_id = 0;
  };
  AudioDecoder_Initialize_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_Initialize_Params.validate = function(messageValidator, offset) {
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


    
    // validate AudioDecoder_Initialize_Params.config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.AudioDecoderConfig, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  AudioDecoder_Initialize_Params.encodedSize = codec.kStructHeaderSize + 16;

  AudioDecoder_Initialize_Params.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_Initialize_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.config = decoder.decodeStructPointer(media_types$.AudioDecoderConfig);
    val.cdm_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  AudioDecoder_Initialize_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_Initialize_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.AudioDecoderConfig, val.config);
    encoder.encodeStruct(codec.Int32, val.cdm_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function AudioDecoder_Initialize_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_Initialize_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
    this.needs_bitstream_conversion = false;
  };
  AudioDecoder_Initialize_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_Initialize_ResponseParams.validate = function(messageValidator, offset) {
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

  AudioDecoder_Initialize_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  AudioDecoder_Initialize_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_Initialize_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    val.needs_bitstream_conversion = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  AudioDecoder_Initialize_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_Initialize_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    packed |= (val.needs_bitstream_conversion & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function AudioDecoder_SetDataSource_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_SetDataSource_Params.prototype.initDefaults_ = function() {
    this.receive_pipe = null;
  };
  AudioDecoder_SetDataSource_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_SetDataSource_Params.validate = function(messageValidator, offset) {
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


    
    // validate AudioDecoder_SetDataSource_Params.receive_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioDecoder_SetDataSource_Params.encodedSize = codec.kStructHeaderSize + 8;

  AudioDecoder_SetDataSource_Params.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_SetDataSource_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.receive_pipe = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  AudioDecoder_SetDataSource_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_SetDataSource_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.receive_pipe);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function AudioDecoder_Decode_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_Decode_Params.prototype.initDefaults_ = function() {
    this.buffer = null;
  };
  AudioDecoder_Decode_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_Decode_Params.validate = function(messageValidator, offset) {
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


    
    // validate AudioDecoder_Decode_Params.buffer
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.DecoderBuffer, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioDecoder_Decode_Params.encodedSize = codec.kStructHeaderSize + 8;

  AudioDecoder_Decode_Params.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_Decode_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.buffer = decoder.decodeStructPointer(media_types$.DecoderBuffer);
    return val;
  };

  AudioDecoder_Decode_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_Decode_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.DecoderBuffer, val.buffer);
  };
  function AudioDecoder_Decode_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_Decode_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  AudioDecoder_Decode_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_Decode_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate AudioDecoder_Decode_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, media_types$.DecodeStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioDecoder_Decode_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  AudioDecoder_Decode_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_Decode_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  AudioDecoder_Decode_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_Decode_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function AudioDecoder_Reset_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_Reset_Params.prototype.initDefaults_ = function() {
  };
  AudioDecoder_Reset_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_Reset_Params.validate = function(messageValidator, offset) {
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

  AudioDecoder_Reset_Params.encodedSize = codec.kStructHeaderSize + 0;

  AudioDecoder_Reset_Params.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_Reset_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AudioDecoder_Reset_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_Reset_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AudioDecoder_Reset_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoder_Reset_ResponseParams.prototype.initDefaults_ = function() {
  };
  AudioDecoder_Reset_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoder_Reset_ResponseParams.validate = function(messageValidator, offset) {
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

  AudioDecoder_Reset_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  AudioDecoder_Reset_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new AudioDecoder_Reset_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AudioDecoder_Reset_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoder_Reset_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  function AudioDecoderClient_OnBufferDecoded_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioDecoderClient_OnBufferDecoded_Params.prototype.initDefaults_ = function() {
    this.buffer = null;
  };
  AudioDecoderClient_OnBufferDecoded_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioDecoderClient_OnBufferDecoded_Params.validate = function(messageValidator, offset) {
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


    
    // validate AudioDecoderClient_OnBufferDecoded_Params.buffer
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.AudioBuffer, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioDecoderClient_OnBufferDecoded_Params.encodedSize = codec.kStructHeaderSize + 8;

  AudioDecoderClient_OnBufferDecoded_Params.decode = function(decoder) {
    var packed;
    var val = new AudioDecoderClient_OnBufferDecoded_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.buffer = decoder.decodeStructPointer(media_types$.AudioBuffer);
    return val;
  };

  AudioDecoderClient_OnBufferDecoded_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioDecoderClient_OnBufferDecoded_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.AudioBuffer, val.buffer);
  };
  var kAudioDecoder_Construct_Name = 0;
  var kAudioDecoder_Initialize_Name = 1;
  var kAudioDecoder_SetDataSource_Name = 2;
  var kAudioDecoder_Decode_Name = 3;
  var kAudioDecoder_Reset_Name = 4;

  function AudioDecoderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(AudioDecoder,
                                                   handleOrPtrInfo);
  }

  function AudioDecoderProxy(receiver) {
    this.receiver_ = receiver;
  }
  AudioDecoderPtr.prototype.construct = function() {
    return AudioDecoderProxy.prototype.construct
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioDecoderProxy.prototype.construct = function(client) {
    var params = new AudioDecoder_Construct_Params();
    params.client = client;
    var builder = new codec.MessageBuilder(
        kAudioDecoder_Construct_Name,
        codec.align(AudioDecoder_Construct_Params.encodedSize));
    builder.encodeStruct(AudioDecoder_Construct_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AudioDecoderPtr.prototype.initialize = function() {
    return AudioDecoderProxy.prototype.initialize
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioDecoderProxy.prototype.initialize = function(config, cdm_id) {
    var params = new AudioDecoder_Initialize_Params();
    params.config = config;
    params.cdm_id = cdm_id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kAudioDecoder_Initialize_Name,
          codec.align(AudioDecoder_Initialize_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(AudioDecoder_Initialize_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(AudioDecoder_Initialize_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  AudioDecoderPtr.prototype.setDataSource = function() {
    return AudioDecoderProxy.prototype.setDataSource
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioDecoderProxy.prototype.setDataSource = function(receive_pipe) {
    var params = new AudioDecoder_SetDataSource_Params();
    params.receive_pipe = receive_pipe;
    var builder = new codec.MessageBuilder(
        kAudioDecoder_SetDataSource_Name,
        codec.align(AudioDecoder_SetDataSource_Params.encodedSize));
    builder.encodeStruct(AudioDecoder_SetDataSource_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AudioDecoderPtr.prototype.decode = function() {
    return AudioDecoderProxy.prototype.decode
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioDecoderProxy.prototype.decode = function(buffer) {
    var params = new AudioDecoder_Decode_Params();
    params.buffer = buffer;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kAudioDecoder_Decode_Name,
          codec.align(AudioDecoder_Decode_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(AudioDecoder_Decode_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(AudioDecoder_Decode_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  AudioDecoderPtr.prototype.reset = function() {
    return AudioDecoderProxy.prototype.reset
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioDecoderProxy.prototype.reset = function() {
    var params = new AudioDecoder_Reset_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kAudioDecoder_Reset_Name,
          codec.align(AudioDecoder_Reset_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(AudioDecoder_Reset_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(AudioDecoder_Reset_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function AudioDecoderStub(delegate) {
    this.delegate_ = delegate;
  }
  AudioDecoderStub.prototype.construct = function(client) {
    return this.delegate_ && this.delegate_.construct && this.delegate_.construct(client);
  }
  AudioDecoderStub.prototype.initialize = function(config, cdm_id) {
    return this.delegate_ && this.delegate_.initialize && this.delegate_.initialize(config, cdm_id);
  }
  AudioDecoderStub.prototype.setDataSource = function(receive_pipe) {
    return this.delegate_ && this.delegate_.setDataSource && this.delegate_.setDataSource(receive_pipe);
  }
  AudioDecoderStub.prototype.decode = function(buffer) {
    return this.delegate_ && this.delegate_.decode && this.delegate_.decode(buffer);
  }
  AudioDecoderStub.prototype.reset = function() {
    return this.delegate_ && this.delegate_.reset && this.delegate_.reset();
  }

  AudioDecoderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAudioDecoder_Construct_Name:
      var params = reader.decodeStruct(AudioDecoder_Construct_Params);
      this.construct(params.client);
      return true;
    case kAudioDecoder_SetDataSource_Name:
      var params = reader.decodeStruct(AudioDecoder_SetDataSource_Params);
      this.setDataSource(params.receive_pipe);
      return true;
    default:
      return false;
    }
  };

  AudioDecoderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAudioDecoder_Initialize_Name:
      var params = reader.decodeStruct(AudioDecoder_Initialize_Params);
      return this.initialize(params.config, params.cdm_id).then(function(response) {
        var responseParams =
            new AudioDecoder_Initialize_ResponseParams();
        responseParams.success = response.success;
        responseParams.needs_bitstream_conversion = response.needs_bitstream_conversion;
        var builder = new codec.MessageWithRequestIDBuilder(
            kAudioDecoder_Initialize_Name,
            codec.align(AudioDecoder_Initialize_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(AudioDecoder_Initialize_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kAudioDecoder_Decode_Name:
      var params = reader.decodeStruct(AudioDecoder_Decode_Params);
      return this.decode(params.buffer).then(function(response) {
        var responseParams =
            new AudioDecoder_Decode_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kAudioDecoder_Decode_Name,
            codec.align(AudioDecoder_Decode_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(AudioDecoder_Decode_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kAudioDecoder_Reset_Name:
      var params = reader.decodeStruct(AudioDecoder_Reset_Params);
      return this.reset().then(function(response) {
        var responseParams =
            new AudioDecoder_Reset_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kAudioDecoder_Reset_Name,
            codec.align(AudioDecoder_Reset_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(AudioDecoder_Reset_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateAudioDecoderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kAudioDecoder_Construct_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AudioDecoder_Construct_Params;
      break;
      case kAudioDecoder_Initialize_Name:
        if (message.expectsResponse())
          paramsClass = AudioDecoder_Initialize_Params;
      break;
      case kAudioDecoder_SetDataSource_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AudioDecoder_SetDataSource_Params;
      break;
      case kAudioDecoder_Decode_Name:
        if (message.expectsResponse())
          paramsClass = AudioDecoder_Decode_Params;
      break;
      case kAudioDecoder_Reset_Name:
        if (message.expectsResponse())
          paramsClass = AudioDecoder_Reset_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateAudioDecoderResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kAudioDecoder_Initialize_Name:
        if (message.isResponse())
          paramsClass = AudioDecoder_Initialize_ResponseParams;
        break;
      case kAudioDecoder_Decode_Name:
        if (message.isResponse())
          paramsClass = AudioDecoder_Decode_ResponseParams;
        break;
      case kAudioDecoder_Reset_Name:
        if (message.isResponse())
          paramsClass = AudioDecoder_Reset_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var AudioDecoder = {
    name: 'media::mojom::AudioDecoder',
    ptrClass: AudioDecoderPtr,
    proxyClass: AudioDecoderProxy,
    stubClass: AudioDecoderStub,
    validateRequest: validateAudioDecoderRequest,
    validateResponse: validateAudioDecoderResponse,
  };
  AudioDecoderStub.prototype.validator = validateAudioDecoderRequest;
  AudioDecoderProxy.prototype.validator = validateAudioDecoderResponse;
  var kAudioDecoderClient_OnBufferDecoded_Name = 0;

  function AudioDecoderClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(AudioDecoderClient,
                                                   handleOrPtrInfo);
  }

  function AudioDecoderClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  AudioDecoderClientPtr.prototype.onBufferDecoded = function() {
    return AudioDecoderClientProxy.prototype.onBufferDecoded
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioDecoderClientProxy.prototype.onBufferDecoded = function(buffer) {
    var params = new AudioDecoderClient_OnBufferDecoded_Params();
    params.buffer = buffer;
    var builder = new codec.MessageBuilder(
        kAudioDecoderClient_OnBufferDecoded_Name,
        codec.align(AudioDecoderClient_OnBufferDecoded_Params.encodedSize));
    builder.encodeStruct(AudioDecoderClient_OnBufferDecoded_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function AudioDecoderClientStub(delegate) {
    this.delegate_ = delegate;
  }
  AudioDecoderClientStub.prototype.onBufferDecoded = function(buffer) {
    return this.delegate_ && this.delegate_.onBufferDecoded && this.delegate_.onBufferDecoded(buffer);
  }

  AudioDecoderClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAudioDecoderClient_OnBufferDecoded_Name:
      var params = reader.decodeStruct(AudioDecoderClient_OnBufferDecoded_Params);
      this.onBufferDecoded(params.buffer);
      return true;
    default:
      return false;
    }
  };

  AudioDecoderClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateAudioDecoderClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kAudioDecoderClient_OnBufferDecoded_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AudioDecoderClient_OnBufferDecoded_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateAudioDecoderClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var AudioDecoderClient = {
    name: 'media::mojom::AudioDecoderClient',
    ptrClass: AudioDecoderClientPtr,
    proxyClass: AudioDecoderClientProxy,
    stubClass: AudioDecoderClientStub,
    validateRequest: validateAudioDecoderClientRequest,
    validateResponse: null,
  };
  AudioDecoderClientStub.prototype.validator = validateAudioDecoderClientRequest;
  AudioDecoderClientProxy.prototype.validator = null;

  var exports = {};
  exports.AudioDecoder = AudioDecoder;
  exports.AudioDecoderPtr = AudioDecoderPtr;
  exports.AudioDecoderClient = AudioDecoderClient;
  exports.AudioDecoderClientPtr = AudioDecoderClientPtr;

  return exports;
});
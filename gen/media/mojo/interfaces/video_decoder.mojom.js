// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/video_decoder.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/media_types.mojom",
    "mojo/common/unguessable_token.mojom",
], function(bindings, codec, core, validator, media_types$, unguessable_token$) {

  function CommandBufferId(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CommandBufferId.prototype.initDefaults_ = function() {
    this.channel_token = null;
    this.route_id = 0;
  };
  CommandBufferId.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CommandBufferId.validate = function(messageValidator, offset) {
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


    
    // validate CommandBufferId.channel_token
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  CommandBufferId.encodedSize = codec.kStructHeaderSize + 16;

  CommandBufferId.decode = function(decoder) {
    var packed;
    var val = new CommandBufferId();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.channel_token = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    val.route_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  CommandBufferId.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CommandBufferId.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.channel_token);
    encoder.encodeStruct(codec.Int32, val.route_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VideoDecoder_Construct_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoder_Construct_Params.prototype.initDefaults_ = function() {
    this.client = null;
    this.decoder_buffer_pipe = null;
    this.command_buffer_id = null;
  };
  VideoDecoder_Construct_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoder_Construct_Params.validate = function(messageValidator, offset) {
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




    
    // validate VideoDecoder_Construct_Params.decoder_buffer_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecoder_Construct_Params.command_buffer_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, CommandBufferId, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoDecoder_Construct_Params.encodedSize = codec.kStructHeaderSize + 24;

  VideoDecoder_Construct_Params.decode = function(decoder) {
    var packed;
    var val = new VideoDecoder_Construct_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(codec.AssociatedInterfaceNotSupported);
    val.decoder_buffer_pipe = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.command_buffer_id = decoder.decodeStructPointer(CommandBufferId);
    return val;
  };

  VideoDecoder_Construct_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoder_Construct_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.AssociatedInterfaceNotSupported, val.client);
    encoder.encodeStruct(codec.Handle, val.decoder_buffer_pipe);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(CommandBufferId, val.command_buffer_id);
  };
  function VideoDecoder_Initialize_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoder_Initialize_Params.prototype.initDefaults_ = function() {
    this.config = null;
    this.low_delay = false;
  };
  VideoDecoder_Initialize_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoder_Initialize_Params.validate = function(messageValidator, offset) {
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


    
    // validate VideoDecoder_Initialize_Params.config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.VideoDecoderConfig, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  VideoDecoder_Initialize_Params.encodedSize = codec.kStructHeaderSize + 16;

  VideoDecoder_Initialize_Params.decode = function(decoder) {
    var packed;
    var val = new VideoDecoder_Initialize_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.config = decoder.decodeStructPointer(media_types$.VideoDecoderConfig);
    packed = decoder.readUint8();
    val.low_delay = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VideoDecoder_Initialize_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoder_Initialize_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.VideoDecoderConfig, val.config);
    packed = 0;
    packed |= (val.low_delay & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VideoDecoder_Initialize_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoder_Initialize_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
    this.needs_bitstream_conversion = false;
    this.max_decode_requests = 0;
  };
  VideoDecoder_Initialize_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoder_Initialize_ResponseParams.validate = function(messageValidator, offset) {
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

  VideoDecoder_Initialize_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  VideoDecoder_Initialize_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VideoDecoder_Initialize_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    val.needs_bitstream_conversion = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.max_decode_requests = decoder.decodeStruct(codec.Int32);
    return val;
  };

  VideoDecoder_Initialize_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoder_Initialize_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    packed |= (val.needs_bitstream_conversion & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.max_decode_requests);
  };
  function VideoDecoder_Decode_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoder_Decode_Params.prototype.initDefaults_ = function() {
    this.buffer = null;
  };
  VideoDecoder_Decode_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoder_Decode_Params.validate = function(messageValidator, offset) {
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


    
    // validate VideoDecoder_Decode_Params.buffer
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.DecoderBuffer, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoDecoder_Decode_Params.encodedSize = codec.kStructHeaderSize + 8;

  VideoDecoder_Decode_Params.decode = function(decoder) {
    var packed;
    var val = new VideoDecoder_Decode_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.buffer = decoder.decodeStructPointer(media_types$.DecoderBuffer);
    return val;
  };

  VideoDecoder_Decode_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoder_Decode_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.DecoderBuffer, val.buffer);
  };
  function VideoDecoder_Decode_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoder_Decode_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  VideoDecoder_Decode_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoder_Decode_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate VideoDecoder_Decode_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, media_types$.DecodeStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoDecoder_Decode_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  VideoDecoder_Decode_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VideoDecoder_Decode_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VideoDecoder_Decode_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoder_Decode_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VideoDecoder_Reset_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoder_Reset_Params.prototype.initDefaults_ = function() {
  };
  VideoDecoder_Reset_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoder_Reset_Params.validate = function(messageValidator, offset) {
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

  VideoDecoder_Reset_Params.encodedSize = codec.kStructHeaderSize + 0;

  VideoDecoder_Reset_Params.decode = function(decoder) {
    var packed;
    var val = new VideoDecoder_Reset_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VideoDecoder_Reset_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoder_Reset_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VideoDecoder_Reset_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoder_Reset_ResponseParams.prototype.initDefaults_ = function() {
  };
  VideoDecoder_Reset_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoder_Reset_ResponseParams.validate = function(messageValidator, offset) {
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

  VideoDecoder_Reset_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  VideoDecoder_Reset_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VideoDecoder_Reset_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VideoDecoder_Reset_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoder_Reset_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  function VideoDecoderClient_OnVideoFrameDecoded_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecoderClient_OnVideoFrameDecoded_Params.prototype.initDefaults_ = function() {
    this.frame = null;
  };
  VideoDecoderClient_OnVideoFrameDecoded_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecoderClient_OnVideoFrameDecoded_Params.validate = function(messageValidator, offset) {
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


    
    // validate VideoDecoderClient_OnVideoFrameDecoded_Params.frame
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.VideoFrame, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VideoDecoderClient_OnVideoFrameDecoded_Params.encodedSize = codec.kStructHeaderSize + 8;

  VideoDecoderClient_OnVideoFrameDecoded_Params.decode = function(decoder) {
    var packed;
    var val = new VideoDecoderClient_OnVideoFrameDecoded_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame = decoder.decodeStructPointer(media_types$.VideoFrame);
    return val;
  };

  VideoDecoderClient_OnVideoFrameDecoded_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecoderClient_OnVideoFrameDecoded_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.VideoFrame, val.frame);
  };
  var kVideoDecoder_Construct_Name = 0;
  var kVideoDecoder_Initialize_Name = 1;
  var kVideoDecoder_Decode_Name = 2;
  var kVideoDecoder_Reset_Name = 3;

  function VideoDecoderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VideoDecoder,
                                                   handleOrPtrInfo);
  }

  function VideoDecoderProxy(receiver) {
    this.receiver_ = receiver;
  }
  VideoDecoderPtr.prototype.construct = function() {
    return VideoDecoderProxy.prototype.construct
        .apply(this.ptr.getProxy(), arguments);
  };

  VideoDecoderProxy.prototype.construct = function(client, decoder_buffer_pipe, command_buffer_id) {
    var params = new VideoDecoder_Construct_Params();
    params.client = client;
    params.decoder_buffer_pipe = decoder_buffer_pipe;
    params.command_buffer_id = command_buffer_id;
    var builder = new codec.MessageBuilder(
        kVideoDecoder_Construct_Name,
        codec.align(VideoDecoder_Construct_Params.encodedSize));
    builder.encodeStruct(VideoDecoder_Construct_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VideoDecoderPtr.prototype.initialize = function() {
    return VideoDecoderProxy.prototype.initialize
        .apply(this.ptr.getProxy(), arguments);
  };

  VideoDecoderProxy.prototype.initialize = function(config, low_delay) {
    var params = new VideoDecoder_Initialize_Params();
    params.config = config;
    params.low_delay = low_delay;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVideoDecoder_Initialize_Name,
          codec.align(VideoDecoder_Initialize_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VideoDecoder_Initialize_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VideoDecoder_Initialize_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  VideoDecoderPtr.prototype.decode = function() {
    return VideoDecoderProxy.prototype.decode
        .apply(this.ptr.getProxy(), arguments);
  };

  VideoDecoderProxy.prototype.decode = function(buffer) {
    var params = new VideoDecoder_Decode_Params();
    params.buffer = buffer;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVideoDecoder_Decode_Name,
          codec.align(VideoDecoder_Decode_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VideoDecoder_Decode_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VideoDecoder_Decode_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  VideoDecoderPtr.prototype.reset = function() {
    return VideoDecoderProxy.prototype.reset
        .apply(this.ptr.getProxy(), arguments);
  };

  VideoDecoderProxy.prototype.reset = function() {
    var params = new VideoDecoder_Reset_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVideoDecoder_Reset_Name,
          codec.align(VideoDecoder_Reset_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VideoDecoder_Reset_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VideoDecoder_Reset_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function VideoDecoderStub(delegate) {
    this.delegate_ = delegate;
  }
  VideoDecoderStub.prototype.construct = function(client, decoder_buffer_pipe, command_buffer_id) {
    return this.delegate_ && this.delegate_.construct && this.delegate_.construct(client, decoder_buffer_pipe, command_buffer_id);
  }
  VideoDecoderStub.prototype.initialize = function(config, low_delay) {
    return this.delegate_ && this.delegate_.initialize && this.delegate_.initialize(config, low_delay);
  }
  VideoDecoderStub.prototype.decode = function(buffer) {
    return this.delegate_ && this.delegate_.decode && this.delegate_.decode(buffer);
  }
  VideoDecoderStub.prototype.reset = function() {
    return this.delegate_ && this.delegate_.reset && this.delegate_.reset();
  }

  VideoDecoderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVideoDecoder_Construct_Name:
      var params = reader.decodeStruct(VideoDecoder_Construct_Params);
      this.construct(params.client, params.decoder_buffer_pipe, params.command_buffer_id);
      return true;
    default:
      return false;
    }
  };

  VideoDecoderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVideoDecoder_Initialize_Name:
      var params = reader.decodeStruct(VideoDecoder_Initialize_Params);
      return this.initialize(params.config, params.low_delay).then(function(response) {
        var responseParams =
            new VideoDecoder_Initialize_ResponseParams();
        responseParams.success = response.success;
        responseParams.needs_bitstream_conversion = response.needs_bitstream_conversion;
        responseParams.max_decode_requests = response.max_decode_requests;
        var builder = new codec.MessageWithRequestIDBuilder(
            kVideoDecoder_Initialize_Name,
            codec.align(VideoDecoder_Initialize_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VideoDecoder_Initialize_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kVideoDecoder_Decode_Name:
      var params = reader.decodeStruct(VideoDecoder_Decode_Params);
      return this.decode(params.buffer).then(function(response) {
        var responseParams =
            new VideoDecoder_Decode_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kVideoDecoder_Decode_Name,
            codec.align(VideoDecoder_Decode_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VideoDecoder_Decode_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kVideoDecoder_Reset_Name:
      var params = reader.decodeStruct(VideoDecoder_Reset_Params);
      return this.reset().then(function(response) {
        var responseParams =
            new VideoDecoder_Reset_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kVideoDecoder_Reset_Name,
            codec.align(VideoDecoder_Reset_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VideoDecoder_Reset_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVideoDecoderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVideoDecoder_Construct_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VideoDecoder_Construct_Params;
      break;
      case kVideoDecoder_Initialize_Name:
        if (message.expectsResponse())
          paramsClass = VideoDecoder_Initialize_Params;
      break;
      case kVideoDecoder_Decode_Name:
        if (message.expectsResponse())
          paramsClass = VideoDecoder_Decode_Params;
      break;
      case kVideoDecoder_Reset_Name:
        if (message.expectsResponse())
          paramsClass = VideoDecoder_Reset_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVideoDecoderResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kVideoDecoder_Initialize_Name:
        if (message.isResponse())
          paramsClass = VideoDecoder_Initialize_ResponseParams;
        break;
      case kVideoDecoder_Decode_Name:
        if (message.isResponse())
          paramsClass = VideoDecoder_Decode_ResponseParams;
        break;
      case kVideoDecoder_Reset_Name:
        if (message.isResponse())
          paramsClass = VideoDecoder_Reset_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var VideoDecoder = {
    name: 'media::mojom::VideoDecoder',
    ptrClass: VideoDecoderPtr,
    proxyClass: VideoDecoderProxy,
    stubClass: VideoDecoderStub,
    validateRequest: validateVideoDecoderRequest,
    validateResponse: validateVideoDecoderResponse,
  };
  VideoDecoderStub.prototype.validator = validateVideoDecoderRequest;
  VideoDecoderProxy.prototype.validator = validateVideoDecoderResponse;
  var kVideoDecoderClient_OnVideoFrameDecoded_Name = 0;

  function VideoDecoderClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VideoDecoderClient,
                                                   handleOrPtrInfo);
  }

  function VideoDecoderClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  VideoDecoderClientPtr.prototype.onVideoFrameDecoded = function() {
    return VideoDecoderClientProxy.prototype.onVideoFrameDecoded
        .apply(this.ptr.getProxy(), arguments);
  };

  VideoDecoderClientProxy.prototype.onVideoFrameDecoded = function(frame) {
    var params = new VideoDecoderClient_OnVideoFrameDecoded_Params();
    params.frame = frame;
    var builder = new codec.MessageBuilder(
        kVideoDecoderClient_OnVideoFrameDecoded_Name,
        codec.align(VideoDecoderClient_OnVideoFrameDecoded_Params.encodedSize));
    builder.encodeStruct(VideoDecoderClient_OnVideoFrameDecoded_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function VideoDecoderClientStub(delegate) {
    this.delegate_ = delegate;
  }
  VideoDecoderClientStub.prototype.onVideoFrameDecoded = function(frame) {
    return this.delegate_ && this.delegate_.onVideoFrameDecoded && this.delegate_.onVideoFrameDecoded(frame);
  }

  VideoDecoderClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVideoDecoderClient_OnVideoFrameDecoded_Name:
      var params = reader.decodeStruct(VideoDecoderClient_OnVideoFrameDecoded_Params);
      this.onVideoFrameDecoded(params.frame);
      return true;
    default:
      return false;
    }
  };

  VideoDecoderClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVideoDecoderClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVideoDecoderClient_OnVideoFrameDecoded_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VideoDecoderClient_OnVideoFrameDecoded_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVideoDecoderClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var VideoDecoderClient = {
    name: 'media::mojom::VideoDecoderClient',
    ptrClass: VideoDecoderClientPtr,
    proxyClass: VideoDecoderClientProxy,
    stubClass: VideoDecoderClientStub,
    validateRequest: validateVideoDecoderClientRequest,
    validateResponse: null,
  };
  VideoDecoderClientStub.prototype.validator = validateVideoDecoderClientRequest;
  VideoDecoderClientProxy.prototype.validator = null;

  var exports = {};
  exports.CommandBufferId = CommandBufferId;
  exports.VideoDecoder = VideoDecoder;
  exports.VideoDecoderPtr = VideoDecoderPtr;
  exports.VideoDecoderClient = VideoDecoderClient;
  exports.VideoDecoderClientPtr = VideoDecoderClientPtr;

  return exports;
});
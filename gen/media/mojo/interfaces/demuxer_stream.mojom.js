// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/demuxer_stream.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/media_types.mojom",
], function(bindings, codec, core, validator, media_types$) {

  function DemuxerStream_Initialize_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DemuxerStream_Initialize_Params.prototype.initDefaults_ = function() {
  };
  DemuxerStream_Initialize_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DemuxerStream_Initialize_Params.validate = function(messageValidator, offset) {
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

  DemuxerStream_Initialize_Params.encodedSize = codec.kStructHeaderSize + 0;

  DemuxerStream_Initialize_Params.decode = function(decoder) {
    var packed;
    var val = new DemuxerStream_Initialize_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DemuxerStream_Initialize_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DemuxerStream_Initialize_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DemuxerStream_Initialize_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DemuxerStream_Initialize_ResponseParams.prototype.initDefaults_ = function() {
    this.type = 0;
    this.pipe = null;
    this.audio_config = null;
    this.video_config = null;
  };
  DemuxerStream_Initialize_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DemuxerStream_Initialize_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate DemuxerStream_Initialize_ResponseParams.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DemuxerStream.Type);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DemuxerStream_Initialize_ResponseParams.pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 4, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DemuxerStream_Initialize_ResponseParams.audio_config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, media_types$.AudioDecoderConfig, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DemuxerStream_Initialize_ResponseParams.video_config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, media_types$.VideoDecoderConfig, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DemuxerStream_Initialize_ResponseParams.encodedSize = codec.kStructHeaderSize + 24;

  DemuxerStream_Initialize_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new DemuxerStream_Initialize_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    val.pipe = decoder.decodeStruct(codec.Handle);
    val.audio_config = decoder.decodeStructPointer(media_types$.AudioDecoderConfig);
    val.video_config = decoder.decodeStructPointer(media_types$.VideoDecoderConfig);
    return val;
  };

  DemuxerStream_Initialize_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DemuxerStream_Initialize_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.encodeStruct(codec.Handle, val.pipe);
    encoder.encodeStructPointer(media_types$.AudioDecoderConfig, val.audio_config);
    encoder.encodeStructPointer(media_types$.VideoDecoderConfig, val.video_config);
  };
  function DemuxerStream_Read_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DemuxerStream_Read_Params.prototype.initDefaults_ = function() {
  };
  DemuxerStream_Read_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DemuxerStream_Read_Params.validate = function(messageValidator, offset) {
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

  DemuxerStream_Read_Params.encodedSize = codec.kStructHeaderSize + 0;

  DemuxerStream_Read_Params.decode = function(decoder) {
    var packed;
    var val = new DemuxerStream_Read_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DemuxerStream_Read_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DemuxerStream_Read_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DemuxerStream_Read_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DemuxerStream_Read_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.buffer = null;
    this.audio_config = null;
    this.video_config = null;
  };
  DemuxerStream_Read_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DemuxerStream_Read_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate DemuxerStream_Read_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DemuxerStream.Status);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DemuxerStream_Read_ResponseParams.buffer
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, media_types$.DecoderBuffer, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DemuxerStream_Read_ResponseParams.audio_config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, media_types$.AudioDecoderConfig, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DemuxerStream_Read_ResponseParams.video_config
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, media_types$.VideoDecoderConfig, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DemuxerStream_Read_ResponseParams.encodedSize = codec.kStructHeaderSize + 32;

  DemuxerStream_Read_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new DemuxerStream_Read_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.buffer = decoder.decodeStructPointer(media_types$.DecoderBuffer);
    val.audio_config = decoder.decodeStructPointer(media_types$.AudioDecoderConfig);
    val.video_config = decoder.decodeStructPointer(media_types$.VideoDecoderConfig);
    return val;
  };

  DemuxerStream_Read_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DemuxerStream_Read_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(media_types$.DecoderBuffer, val.buffer);
    encoder.encodeStructPointer(media_types$.AudioDecoderConfig, val.audio_config);
    encoder.encodeStructPointer(media_types$.VideoDecoderConfig, val.video_config);
  };
  function DemuxerStream_EnableBitstreamConverter_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DemuxerStream_EnableBitstreamConverter_Params.prototype.initDefaults_ = function() {
  };
  DemuxerStream_EnableBitstreamConverter_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DemuxerStream_EnableBitstreamConverter_Params.validate = function(messageValidator, offset) {
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

  DemuxerStream_EnableBitstreamConverter_Params.encodedSize = codec.kStructHeaderSize + 0;

  DemuxerStream_EnableBitstreamConverter_Params.decode = function(decoder) {
    var packed;
    var val = new DemuxerStream_EnableBitstreamConverter_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DemuxerStream_EnableBitstreamConverter_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DemuxerStream_EnableBitstreamConverter_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kDemuxerStream_Initialize_Name = 0;
  var kDemuxerStream_Read_Name = 1;
  var kDemuxerStream_EnableBitstreamConverter_Name = 2;

  function DemuxerStreamPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DemuxerStream,
                                                   handleOrPtrInfo);
  }

  function DemuxerStreamProxy(receiver) {
    this.receiver_ = receiver;
  }
  DemuxerStreamPtr.prototype.initialize = function() {
    return DemuxerStreamProxy.prototype.initialize
        .apply(this.ptr.getProxy(), arguments);
  };

  DemuxerStreamProxy.prototype.initialize = function() {
    var params = new DemuxerStream_Initialize_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDemuxerStream_Initialize_Name,
          codec.align(DemuxerStream_Initialize_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(DemuxerStream_Initialize_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(DemuxerStream_Initialize_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DemuxerStreamPtr.prototype.read = function() {
    return DemuxerStreamProxy.prototype.read
        .apply(this.ptr.getProxy(), arguments);
  };

  DemuxerStreamProxy.prototype.read = function() {
    var params = new DemuxerStream_Read_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDemuxerStream_Read_Name,
          codec.align(DemuxerStream_Read_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(DemuxerStream_Read_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(DemuxerStream_Read_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DemuxerStreamPtr.prototype.enableBitstreamConverter = function() {
    return DemuxerStreamProxy.prototype.enableBitstreamConverter
        .apply(this.ptr.getProxy(), arguments);
  };

  DemuxerStreamProxy.prototype.enableBitstreamConverter = function() {
    var params = new DemuxerStream_EnableBitstreamConverter_Params();
    var builder = new codec.MessageBuilder(
        kDemuxerStream_EnableBitstreamConverter_Name,
        codec.align(DemuxerStream_EnableBitstreamConverter_Params.encodedSize));
    builder.encodeStruct(DemuxerStream_EnableBitstreamConverter_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DemuxerStreamStub(delegate) {
    this.delegate_ = delegate;
  }
  DemuxerStreamStub.prototype.initialize = function() {
    return this.delegate_ && this.delegate_.initialize && this.delegate_.initialize();
  }
  DemuxerStreamStub.prototype.read = function() {
    return this.delegate_ && this.delegate_.read && this.delegate_.read();
  }
  DemuxerStreamStub.prototype.enableBitstreamConverter = function() {
    return this.delegate_ && this.delegate_.enableBitstreamConverter && this.delegate_.enableBitstreamConverter();
  }

  DemuxerStreamStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDemuxerStream_EnableBitstreamConverter_Name:
      var params = reader.decodeStruct(DemuxerStream_EnableBitstreamConverter_Params);
      this.enableBitstreamConverter();
      return true;
    default:
      return false;
    }
  };

  DemuxerStreamStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDemuxerStream_Initialize_Name:
      var params = reader.decodeStruct(DemuxerStream_Initialize_Params);
      return this.initialize().then(function(response) {
        var responseParams =
            new DemuxerStream_Initialize_ResponseParams();
        responseParams.type = response.type;
        responseParams.pipe = response.pipe;
        responseParams.audio_config = response.audio_config;
        responseParams.video_config = response.video_config;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDemuxerStream_Initialize_Name,
            codec.align(DemuxerStream_Initialize_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(DemuxerStream_Initialize_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDemuxerStream_Read_Name:
      var params = reader.decodeStruct(DemuxerStream_Read_Params);
      return this.read().then(function(response) {
        var responseParams =
            new DemuxerStream_Read_ResponseParams();
        responseParams.status = response.status;
        responseParams.buffer = response.buffer;
        responseParams.audio_config = response.audio_config;
        responseParams.video_config = response.video_config;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDemuxerStream_Read_Name,
            codec.align(DemuxerStream_Read_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(DemuxerStream_Read_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDemuxerStreamRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDemuxerStream_Initialize_Name:
        if (message.expectsResponse())
          paramsClass = DemuxerStream_Initialize_Params;
      break;
      case kDemuxerStream_Read_Name:
        if (message.expectsResponse())
          paramsClass = DemuxerStream_Read_Params;
      break;
      case kDemuxerStream_EnableBitstreamConverter_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DemuxerStream_EnableBitstreamConverter_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDemuxerStreamResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kDemuxerStream_Initialize_Name:
        if (message.isResponse())
          paramsClass = DemuxerStream_Initialize_ResponseParams;
        break;
      case kDemuxerStream_Read_Name:
        if (message.isResponse())
          paramsClass = DemuxerStream_Read_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var DemuxerStream = {
    name: 'media::mojom::DemuxerStream',
    ptrClass: DemuxerStreamPtr,
    proxyClass: DemuxerStreamProxy,
    stubClass: DemuxerStreamStub,
    validateRequest: validateDemuxerStreamRequest,
    validateResponse: validateDemuxerStreamResponse,
  };
  DemuxerStream.Type = {};

  DemuxerStream.Type.isKnownEnumValue = function(value) {
    return false;
  };

  DemuxerStream.Type.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  DemuxerStream.Status = {};

  DemuxerStream.Status.isKnownEnumValue = function(value) {
    return false;
  };

  DemuxerStream.Status.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  DemuxerStreamStub.prototype.validator = validateDemuxerStreamRequest;
  DemuxerStreamProxy.prototype.validator = validateDemuxerStreamResponse;

  var exports = {};
  exports.DemuxerStream = DemuxerStream;
  exports.DemuxerStreamPtr = DemuxerStreamPtr;

  return exports;
});
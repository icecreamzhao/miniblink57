// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/audio_output.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/audio_parameters.mojom",
], function(bindings, codec, core, validator, audio_parameters$) {

  function AudioOutputStream_Close_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioOutputStream_Close_Params.prototype.initDefaults_ = function() {
  };
  AudioOutputStream_Close_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioOutputStream_Close_Params.validate = function(messageValidator, offset) {
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

  AudioOutputStream_Close_Params.encodedSize = codec.kStructHeaderSize + 0;

  AudioOutputStream_Close_Params.decode = function(decoder) {
    var packed;
    var val = new AudioOutputStream_Close_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AudioOutputStream_Close_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioOutputStream_Close_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AudioOutput_CreateStream_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioOutput_CreateStream_Params.prototype.initDefaults_ = function() {
    this.stream_id = 0;
    this.params = null;
  };
  AudioOutput_CreateStream_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioOutput_CreateStream_Params.validate = function(messageValidator, offset) {
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



    
    // validate AudioOutput_CreateStream_Params.params
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, audio_parameters$.AudioParameters, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioOutput_CreateStream_Params.encodedSize = codec.kStructHeaderSize + 16;

  AudioOutput_CreateStream_Params.decode = function(decoder) {
    var packed;
    var val = new AudioOutput_CreateStream_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.stream_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.params = decoder.decodeStructPointer(audio_parameters$.AudioParameters);
    return val;
  };

  AudioOutput_CreateStream_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioOutput_CreateStream_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.stream_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(audio_parameters$.AudioParameters, val.params);
  };
  function AudioOutput_CreateStream_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioOutput_CreateStream_ResponseParams.prototype.initDefaults_ = function() {
    this.stream_id = 0;
    this.stream = new AudioOutputStreamPtr();
    this.shared_buffer = null;
    this.socket_descriptor = null;
  };
  AudioOutput_CreateStream_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioOutput_CreateStream_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate AudioOutput_CreateStream_ResponseParams.stream
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AudioOutput_CreateStream_ResponseParams.shared_buffer
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 12, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AudioOutput_CreateStream_ResponseParams.socket_descriptor
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 16, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AudioOutput_CreateStream_ResponseParams.encodedSize = codec.kStructHeaderSize + 24;

  AudioOutput_CreateStream_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new AudioOutput_CreateStream_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.stream_id = decoder.decodeStruct(codec.Int32);
    val.stream = decoder.decodeStruct(new codec.NullableInterface(AudioOutputStreamPtr));
    val.shared_buffer = decoder.decodeStruct(codec.NullableHandle);
    val.socket_descriptor = decoder.decodeStruct(codec.NullableHandle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  AudioOutput_CreateStream_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioOutput_CreateStream_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.stream_id);
    encoder.encodeStruct(new codec.NullableInterface(AudioOutputStreamPtr), val.stream);
    encoder.encodeStruct(codec.NullableHandle, val.shared_buffer);
    encoder.encodeStruct(codec.NullableHandle, val.socket_descriptor);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kAudioOutputStream_Close_Name = 0;

  function AudioOutputStreamPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(AudioOutputStream,
                                                   handleOrPtrInfo);
  }

  function AudioOutputStreamProxy(receiver) {
    this.receiver_ = receiver;
  }
  AudioOutputStreamPtr.prototype.close = function() {
    return AudioOutputStreamProxy.prototype.close
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioOutputStreamProxy.prototype.close = function() {
    var params = new AudioOutputStream_Close_Params();
    var builder = new codec.MessageBuilder(
        kAudioOutputStream_Close_Name,
        codec.align(AudioOutputStream_Close_Params.encodedSize));
    builder.encodeStruct(AudioOutputStream_Close_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function AudioOutputStreamStub(delegate) {
    this.delegate_ = delegate;
  }
  AudioOutputStreamStub.prototype.close = function() {
    return this.delegate_ && this.delegate_.close && this.delegate_.close();
  }

  AudioOutputStreamStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAudioOutputStream_Close_Name:
      var params = reader.decodeStruct(AudioOutputStream_Close_Params);
      this.close();
      return true;
    default:
      return false;
    }
  };

  AudioOutputStreamStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateAudioOutputStreamRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kAudioOutputStream_Close_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AudioOutputStream_Close_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateAudioOutputStreamResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var AudioOutputStream = {
    name: 'media::mojom::AudioOutputStream',
    ptrClass: AudioOutputStreamPtr,
    proxyClass: AudioOutputStreamProxy,
    stubClass: AudioOutputStreamStub,
    validateRequest: validateAudioOutputStreamRequest,
    validateResponse: null,
  };
  AudioOutputStreamStub.prototype.validator = validateAudioOutputStreamRequest;
  AudioOutputStreamProxy.prototype.validator = null;
  var kAudioOutput_CreateStream_Name = 0;

  function AudioOutputPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(AudioOutput,
                                                   handleOrPtrInfo);
  }

  function AudioOutputProxy(receiver) {
    this.receiver_ = receiver;
  }
  AudioOutputPtr.prototype.createStream = function() {
    return AudioOutputProxy.prototype.createStream
        .apply(this.ptr.getProxy(), arguments);
  };

  AudioOutputProxy.prototype.createStream = function(stream_id, params) {
    var params = new AudioOutput_CreateStream_Params();
    params.stream_id = stream_id;
    params.params = params;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kAudioOutput_CreateStream_Name,
          codec.align(AudioOutput_CreateStream_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(AudioOutput_CreateStream_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(AudioOutput_CreateStream_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function AudioOutputStub(delegate) {
    this.delegate_ = delegate;
  }
  AudioOutputStub.prototype.createStream = function(stream_id, params) {
    return this.delegate_ && this.delegate_.createStream && this.delegate_.createStream(stream_id, params);
  }

  AudioOutputStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  AudioOutputStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAudioOutput_CreateStream_Name:
      var params = reader.decodeStruct(AudioOutput_CreateStream_Params);
      return this.createStream(params.stream_id, params.params).then(function(response) {
        var responseParams =
            new AudioOutput_CreateStream_ResponseParams();
        responseParams.stream_id = response.stream_id;
        responseParams.stream = response.stream;
        responseParams.shared_buffer = response.shared_buffer;
        responseParams.socket_descriptor = response.socket_descriptor;
        var builder = new codec.MessageWithRequestIDBuilder(
            kAudioOutput_CreateStream_Name,
            codec.align(AudioOutput_CreateStream_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(AudioOutput_CreateStream_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateAudioOutputRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kAudioOutput_CreateStream_Name:
        if (message.expectsResponse())
          paramsClass = AudioOutput_CreateStream_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateAudioOutputResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kAudioOutput_CreateStream_Name:
        if (message.isResponse())
          paramsClass = AudioOutput_CreateStream_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var AudioOutput = {
    name: 'media::mojom::AudioOutput',
    ptrClass: AudioOutputPtr,
    proxyClass: AudioOutputProxy,
    stubClass: AudioOutputStub,
    validateRequest: validateAudioOutputRequest,
    validateResponse: validateAudioOutputResponse,
  };
  AudioOutputStub.prototype.validator = validateAudioOutputRequest;
  AudioOutputProxy.prototype.validator = validateAudioOutputResponse;

  var exports = {};
  exports.AudioOutputStream = AudioOutputStream;
  exports.AudioOutputStreamPtr = AudioOutputStreamPtr;
  exports.AudioOutput = AudioOutput;
  exports.AudioOutputPtr = AudioOutputPtr;

  return exports;
});
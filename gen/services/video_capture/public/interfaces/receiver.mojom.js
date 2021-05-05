// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/video_capture/public/interfaces/receiver.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/media_types.mojom",
], function(bindings, codec, core, validator, media_types$) {

  function Receiver_OnIncomingCapturedVideoFrame_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Receiver_OnIncomingCapturedVideoFrame_Params.prototype.initDefaults_ = function() {
    this.frame = null;
  };
  Receiver_OnIncomingCapturedVideoFrame_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Receiver_OnIncomingCapturedVideoFrame_Params.validate = function(messageValidator, offset) {
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


    
    // validate Receiver_OnIncomingCapturedVideoFrame_Params.frame
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, media_types$.VideoFrame, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Receiver_OnIncomingCapturedVideoFrame_Params.encodedSize = codec.kStructHeaderSize + 8;

  Receiver_OnIncomingCapturedVideoFrame_Params.decode = function(decoder) {
    var packed;
    var val = new Receiver_OnIncomingCapturedVideoFrame_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame = decoder.decodeStructPointer(media_types$.VideoFrame);
    return val;
  };

  Receiver_OnIncomingCapturedVideoFrame_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Receiver_OnIncomingCapturedVideoFrame_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(media_types$.VideoFrame, val.frame);
  };
  function Receiver_OnError_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Receiver_OnError_Params.prototype.initDefaults_ = function() {
  };
  Receiver_OnError_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Receiver_OnError_Params.validate = function(messageValidator, offset) {
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

  Receiver_OnError_Params.encodedSize = codec.kStructHeaderSize + 0;

  Receiver_OnError_Params.decode = function(decoder) {
    var packed;
    var val = new Receiver_OnError_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Receiver_OnError_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Receiver_OnError_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Receiver_OnLog_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Receiver_OnLog_Params.prototype.initDefaults_ = function() {
    this.message = null;
  };
  Receiver_OnLog_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Receiver_OnLog_Params.validate = function(messageValidator, offset) {
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


    
    // validate Receiver_OnLog_Params.message
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Receiver_OnLog_Params.encodedSize = codec.kStructHeaderSize + 8;

  Receiver_OnLog_Params.decode = function(decoder) {
    var packed;
    var val = new Receiver_OnLog_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.message = decoder.decodeStruct(codec.String);
    return val;
  };

  Receiver_OnLog_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Receiver_OnLog_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.message);
  };
  function Receiver_OnBufferDestroyed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Receiver_OnBufferDestroyed_Params.prototype.initDefaults_ = function() {
    this.buffer_id_to_drop = 0;
  };
  Receiver_OnBufferDestroyed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Receiver_OnBufferDestroyed_Params.validate = function(messageValidator, offset) {
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

  Receiver_OnBufferDestroyed_Params.encodedSize = codec.kStructHeaderSize + 8;

  Receiver_OnBufferDestroyed_Params.decode = function(decoder) {
    var packed;
    var val = new Receiver_OnBufferDestroyed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.buffer_id_to_drop = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Receiver_OnBufferDestroyed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Receiver_OnBufferDestroyed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.buffer_id_to_drop);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kReceiver_OnIncomingCapturedVideoFrame_Name = 0;
  var kReceiver_OnError_Name = 1;
  var kReceiver_OnLog_Name = 2;
  var kReceiver_OnBufferDestroyed_Name = 3;

  function ReceiverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Receiver,
                                                   handleOrPtrInfo);
  }

  function ReceiverProxy(receiver) {
    this.receiver_ = receiver;
  }
  ReceiverPtr.prototype.onIncomingCapturedVideoFrame = function() {
    return ReceiverProxy.prototype.onIncomingCapturedVideoFrame
        .apply(this.ptr.getProxy(), arguments);
  };

  ReceiverProxy.prototype.onIncomingCapturedVideoFrame = function(frame) {
    var params = new Receiver_OnIncomingCapturedVideoFrame_Params();
    params.frame = frame;
    var builder = new codec.MessageBuilder(
        kReceiver_OnIncomingCapturedVideoFrame_Name,
        codec.align(Receiver_OnIncomingCapturedVideoFrame_Params.encodedSize));
    builder.encodeStruct(Receiver_OnIncomingCapturedVideoFrame_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ReceiverPtr.prototype.onError = function() {
    return ReceiverProxy.prototype.onError
        .apply(this.ptr.getProxy(), arguments);
  };

  ReceiverProxy.prototype.onError = function() {
    var params = new Receiver_OnError_Params();
    var builder = new codec.MessageBuilder(
        kReceiver_OnError_Name,
        codec.align(Receiver_OnError_Params.encodedSize));
    builder.encodeStruct(Receiver_OnError_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ReceiverPtr.prototype.onLog = function() {
    return ReceiverProxy.prototype.onLog
        .apply(this.ptr.getProxy(), arguments);
  };

  ReceiverProxy.prototype.onLog = function(message) {
    var params = new Receiver_OnLog_Params();
    params.message = message;
    var builder = new codec.MessageBuilder(
        kReceiver_OnLog_Name,
        codec.align(Receiver_OnLog_Params.encodedSize));
    builder.encodeStruct(Receiver_OnLog_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ReceiverPtr.prototype.onBufferDestroyed = function() {
    return ReceiverProxy.prototype.onBufferDestroyed
        .apply(this.ptr.getProxy(), arguments);
  };

  ReceiverProxy.prototype.onBufferDestroyed = function(buffer_id_to_drop) {
    var params = new Receiver_OnBufferDestroyed_Params();
    params.buffer_id_to_drop = buffer_id_to_drop;
    var builder = new codec.MessageBuilder(
        kReceiver_OnBufferDestroyed_Name,
        codec.align(Receiver_OnBufferDestroyed_Params.encodedSize));
    builder.encodeStruct(Receiver_OnBufferDestroyed_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ReceiverStub(delegate) {
    this.delegate_ = delegate;
  }
  ReceiverStub.prototype.onIncomingCapturedVideoFrame = function(frame) {
    return this.delegate_ && this.delegate_.onIncomingCapturedVideoFrame && this.delegate_.onIncomingCapturedVideoFrame(frame);
  }
  ReceiverStub.prototype.onError = function() {
    return this.delegate_ && this.delegate_.onError && this.delegate_.onError();
  }
  ReceiverStub.prototype.onLog = function(message) {
    return this.delegate_ && this.delegate_.onLog && this.delegate_.onLog(message);
  }
  ReceiverStub.prototype.onBufferDestroyed = function(buffer_id_to_drop) {
    return this.delegate_ && this.delegate_.onBufferDestroyed && this.delegate_.onBufferDestroyed(buffer_id_to_drop);
  }

  ReceiverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kReceiver_OnIncomingCapturedVideoFrame_Name:
      var params = reader.decodeStruct(Receiver_OnIncomingCapturedVideoFrame_Params);
      this.onIncomingCapturedVideoFrame(params.frame);
      return true;
    case kReceiver_OnError_Name:
      var params = reader.decodeStruct(Receiver_OnError_Params);
      this.onError();
      return true;
    case kReceiver_OnLog_Name:
      var params = reader.decodeStruct(Receiver_OnLog_Params);
      this.onLog(params.message);
      return true;
    case kReceiver_OnBufferDestroyed_Name:
      var params = reader.decodeStruct(Receiver_OnBufferDestroyed_Params);
      this.onBufferDestroyed(params.buffer_id_to_drop);
      return true;
    default:
      return false;
    }
  };

  ReceiverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateReceiverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kReceiver_OnIncomingCapturedVideoFrame_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Receiver_OnIncomingCapturedVideoFrame_Params;
      break;
      case kReceiver_OnError_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Receiver_OnError_Params;
      break;
      case kReceiver_OnLog_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Receiver_OnLog_Params;
      break;
      case kReceiver_OnBufferDestroyed_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Receiver_OnBufferDestroyed_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateReceiverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var Receiver = {
    name: 'video_capture::mojom::Receiver',
    ptrClass: ReceiverPtr,
    proxyClass: ReceiverProxy,
    stubClass: ReceiverStub,
    validateRequest: validateReceiverRequest,
    validateResponse: null,
  };
  ReceiverStub.prototype.validator = validateReceiverRequest;
  ReceiverProxy.prototype.validator = null;

  var exports = {};
  exports.Receiver = Receiver;
  exports.ReceiverPtr = ReceiverPtr;

  return exports;
});
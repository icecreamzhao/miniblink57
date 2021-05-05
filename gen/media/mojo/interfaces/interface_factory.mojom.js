// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/interface_factory.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "media/mojo/interfaces/audio_decoder.mojom",
    "media/mojo/interfaces/content_decryption_module.mojom",
    "media/mojo/interfaces/renderer.mojom",
    "media/mojo/interfaces/video_decoder.mojom",
], function(bindings, codec, core, validator, audio_decoder$, content_decryption_module$, renderer$, video_decoder$) {

  function InterfaceFactory_CreateAudioDecoder_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceFactory_CreateAudioDecoder_Params.prototype.initDefaults_ = function() {
    this.audio_decoder = new bindings.InterfaceRequest();
  };
  InterfaceFactory_CreateAudioDecoder_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceFactory_CreateAudioDecoder_Params.validate = function(messageValidator, offset) {
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


    
    // validate InterfaceFactory_CreateAudioDecoder_Params.audio_decoder
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceFactory_CreateAudioDecoder_Params.encodedSize = codec.kStructHeaderSize + 8;

  InterfaceFactory_CreateAudioDecoder_Params.decode = function(decoder) {
    var packed;
    var val = new InterfaceFactory_CreateAudioDecoder_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.audio_decoder = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  InterfaceFactory_CreateAudioDecoder_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceFactory_CreateAudioDecoder_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.audio_decoder);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function InterfaceFactory_CreateVideoDecoder_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceFactory_CreateVideoDecoder_Params.prototype.initDefaults_ = function() {
    this.video_decoder = new bindings.InterfaceRequest();
  };
  InterfaceFactory_CreateVideoDecoder_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceFactory_CreateVideoDecoder_Params.validate = function(messageValidator, offset) {
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


    
    // validate InterfaceFactory_CreateVideoDecoder_Params.video_decoder
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceFactory_CreateVideoDecoder_Params.encodedSize = codec.kStructHeaderSize + 8;

  InterfaceFactory_CreateVideoDecoder_Params.decode = function(decoder) {
    var packed;
    var val = new InterfaceFactory_CreateVideoDecoder_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.video_decoder = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  InterfaceFactory_CreateVideoDecoder_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceFactory_CreateVideoDecoder_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.video_decoder);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function InterfaceFactory_CreateRenderer_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceFactory_CreateRenderer_Params.prototype.initDefaults_ = function() {
    this.audio_device_id = null;
    this.renderer = new bindings.InterfaceRequest();
  };
  InterfaceFactory_CreateRenderer_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceFactory_CreateRenderer_Params.validate = function(messageValidator, offset) {
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


    
    // validate InterfaceFactory_CreateRenderer_Params.audio_device_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate InterfaceFactory_CreateRenderer_Params.renderer
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceFactory_CreateRenderer_Params.encodedSize = codec.kStructHeaderSize + 16;

  InterfaceFactory_CreateRenderer_Params.decode = function(decoder) {
    var packed;
    var val = new InterfaceFactory_CreateRenderer_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.audio_device_id = decoder.decodeStruct(codec.String);
    val.renderer = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  InterfaceFactory_CreateRenderer_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceFactory_CreateRenderer_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.audio_device_id);
    encoder.encodeStruct(codec.InterfaceRequest, val.renderer);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function InterfaceFactory_CreateCdm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceFactory_CreateCdm_Params.prototype.initDefaults_ = function() {
    this.cdm = new bindings.InterfaceRequest();
  };
  InterfaceFactory_CreateCdm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceFactory_CreateCdm_Params.validate = function(messageValidator, offset) {
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


    
    // validate InterfaceFactory_CreateCdm_Params.cdm
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceFactory_CreateCdm_Params.encodedSize = codec.kStructHeaderSize + 8;

  InterfaceFactory_CreateCdm_Params.decode = function(decoder) {
    var packed;
    var val = new InterfaceFactory_CreateCdm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.cdm = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  InterfaceFactory_CreateCdm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceFactory_CreateCdm_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.cdm);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kInterfaceFactory_CreateAudioDecoder_Name = 0;
  var kInterfaceFactory_CreateVideoDecoder_Name = 1;
  var kInterfaceFactory_CreateRenderer_Name = 2;
  var kInterfaceFactory_CreateCdm_Name = 3;

  function InterfaceFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(InterfaceFactory,
                                                   handleOrPtrInfo);
  }

  function InterfaceFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  InterfaceFactoryPtr.prototype.createAudioDecoder = function() {
    return InterfaceFactoryProxy.prototype.createAudioDecoder
        .apply(this.ptr.getProxy(), arguments);
  };

  InterfaceFactoryProxy.prototype.createAudioDecoder = function(audio_decoder) {
    var params = new InterfaceFactory_CreateAudioDecoder_Params();
    params.audio_decoder = audio_decoder;
    var builder = new codec.MessageBuilder(
        kInterfaceFactory_CreateAudioDecoder_Name,
        codec.align(InterfaceFactory_CreateAudioDecoder_Params.encodedSize));
    builder.encodeStruct(InterfaceFactory_CreateAudioDecoder_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  InterfaceFactoryPtr.prototype.createVideoDecoder = function() {
    return InterfaceFactoryProxy.prototype.createVideoDecoder
        .apply(this.ptr.getProxy(), arguments);
  };

  InterfaceFactoryProxy.prototype.createVideoDecoder = function(video_decoder) {
    var params = new InterfaceFactory_CreateVideoDecoder_Params();
    params.video_decoder = video_decoder;
    var builder = new codec.MessageBuilder(
        kInterfaceFactory_CreateVideoDecoder_Name,
        codec.align(InterfaceFactory_CreateVideoDecoder_Params.encodedSize));
    builder.encodeStruct(InterfaceFactory_CreateVideoDecoder_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  InterfaceFactoryPtr.prototype.createRenderer = function() {
    return InterfaceFactoryProxy.prototype.createRenderer
        .apply(this.ptr.getProxy(), arguments);
  };

  InterfaceFactoryProxy.prototype.createRenderer = function(audio_device_id, renderer) {
    var params = new InterfaceFactory_CreateRenderer_Params();
    params.audio_device_id = audio_device_id;
    params.renderer = renderer;
    var builder = new codec.MessageBuilder(
        kInterfaceFactory_CreateRenderer_Name,
        codec.align(InterfaceFactory_CreateRenderer_Params.encodedSize));
    builder.encodeStruct(InterfaceFactory_CreateRenderer_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  InterfaceFactoryPtr.prototype.createCdm = function() {
    return InterfaceFactoryProxy.prototype.createCdm
        .apply(this.ptr.getProxy(), arguments);
  };

  InterfaceFactoryProxy.prototype.createCdm = function(cdm) {
    var params = new InterfaceFactory_CreateCdm_Params();
    params.cdm = cdm;
    var builder = new codec.MessageBuilder(
        kInterfaceFactory_CreateCdm_Name,
        codec.align(InterfaceFactory_CreateCdm_Params.encodedSize));
    builder.encodeStruct(InterfaceFactory_CreateCdm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function InterfaceFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  InterfaceFactoryStub.prototype.createAudioDecoder = function(audio_decoder) {
    return this.delegate_ && this.delegate_.createAudioDecoder && this.delegate_.createAudioDecoder(audio_decoder);
  }
  InterfaceFactoryStub.prototype.createVideoDecoder = function(video_decoder) {
    return this.delegate_ && this.delegate_.createVideoDecoder && this.delegate_.createVideoDecoder(video_decoder);
  }
  InterfaceFactoryStub.prototype.createRenderer = function(audio_device_id, renderer) {
    return this.delegate_ && this.delegate_.createRenderer && this.delegate_.createRenderer(audio_device_id, renderer);
  }
  InterfaceFactoryStub.prototype.createCdm = function(cdm) {
    return this.delegate_ && this.delegate_.createCdm && this.delegate_.createCdm(cdm);
  }

  InterfaceFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kInterfaceFactory_CreateAudioDecoder_Name:
      var params = reader.decodeStruct(InterfaceFactory_CreateAudioDecoder_Params);
      this.createAudioDecoder(params.audio_decoder);
      return true;
    case kInterfaceFactory_CreateVideoDecoder_Name:
      var params = reader.decodeStruct(InterfaceFactory_CreateVideoDecoder_Params);
      this.createVideoDecoder(params.video_decoder);
      return true;
    case kInterfaceFactory_CreateRenderer_Name:
      var params = reader.decodeStruct(InterfaceFactory_CreateRenderer_Params);
      this.createRenderer(params.audio_device_id, params.renderer);
      return true;
    case kInterfaceFactory_CreateCdm_Name:
      var params = reader.decodeStruct(InterfaceFactory_CreateCdm_Params);
      this.createCdm(params.cdm);
      return true;
    default:
      return false;
    }
  };

  InterfaceFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateInterfaceFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kInterfaceFactory_CreateAudioDecoder_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InterfaceFactory_CreateAudioDecoder_Params;
      break;
      case kInterfaceFactory_CreateVideoDecoder_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InterfaceFactory_CreateVideoDecoder_Params;
      break;
      case kInterfaceFactory_CreateRenderer_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InterfaceFactory_CreateRenderer_Params;
      break;
      case kInterfaceFactory_CreateCdm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InterfaceFactory_CreateCdm_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateInterfaceFactoryResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var InterfaceFactory = {
    name: 'media::mojom::InterfaceFactory',
    ptrClass: InterfaceFactoryPtr,
    proxyClass: InterfaceFactoryProxy,
    stubClass: InterfaceFactoryStub,
    validateRequest: validateInterfaceFactoryRequest,
    validateResponse: null,
  };
  InterfaceFactoryStub.prototype.validator = validateInterfaceFactoryRequest;
  InterfaceFactoryProxy.prototype.validator = null;

  var exports = {};
  exports.InterfaceFactory = InterfaceFactory;
  exports.InterfaceFactoryPtr = InterfaceFactoryPtr;

  return exports;
});
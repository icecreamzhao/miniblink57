// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/presentation/presentation.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "url/mojo/url.mojom",
], function(bindings, codec, core, validator, url$) {
  var PresentationConnectionState = {};
  PresentationConnectionState.CONNECTING = 0;
  PresentationConnectionState.CONNECTED = PresentationConnectionState.CONNECTING + 1;
  PresentationConnectionState.CLOSED = PresentationConnectionState.CONNECTED + 1;
  PresentationConnectionState.TERMINATED = PresentationConnectionState.CLOSED + 1;

  PresentationConnectionState.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  PresentationConnectionState.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PresentationConnectionCloseReason = {};
  PresentationConnectionCloseReason.CONNECTION_ERROR = 0;
  PresentationConnectionCloseReason.CLOSED = PresentationConnectionCloseReason.CONNECTION_ERROR + 1;
  PresentationConnectionCloseReason.WENT_AWAY = PresentationConnectionCloseReason.CLOSED + 1;

  PresentationConnectionCloseReason.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  PresentationConnectionCloseReason.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PresentationErrorType = {};
  PresentationErrorType.NO_AVAILABLE_SCREENS = 0;
  PresentationErrorType.SESSION_REQUEST_CANCELLED = PresentationErrorType.NO_AVAILABLE_SCREENS + 1;
  PresentationErrorType.NO_PRESENTATION_FOUND = PresentationErrorType.SESSION_REQUEST_CANCELLED + 1;
  PresentationErrorType.UNKNOWN = PresentationErrorType.NO_PRESENTATION_FOUND + 1;

  PresentationErrorType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  PresentationErrorType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PresentationMessageType = {};
  PresentationMessageType.TEXT = 0;
  PresentationMessageType.BINARY = PresentationMessageType.TEXT + 1;

  PresentationMessageType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  PresentationMessageType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function PresentationSessionInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationSessionInfo.prototype.initDefaults_ = function() {
    this.url = null;
    this.id = null;
  };
  PresentationSessionInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationSessionInfo.validate = function(messageValidator, offset) {
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


    
    // validate PresentationSessionInfo.url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationSessionInfo.id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationSessionInfo.encodedSize = codec.kStructHeaderSize + 16;

  PresentationSessionInfo.decode = function(decoder) {
    var packed;
    var val = new PresentationSessionInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStructPointer(url$.Url);
    val.id = decoder.decodeStruct(codec.String);
    return val;
  };

  PresentationSessionInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationSessionInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.url);
    encoder.encodeStruct(codec.String, val.id);
  };
  function PresentationError(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationError.prototype.initDefaults_ = function() {
    this.error_type = 0;
    this.message = null;
  };
  PresentationError.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationError.validate = function(messageValidator, offset) {
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


    
    // validate PresentationError.error_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PresentationErrorType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationError.message
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationError.encodedSize = codec.kStructHeaderSize + 16;

  PresentationError.decode = function(decoder) {
    var packed;
    var val = new PresentationError();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.message = decoder.decodeStruct(codec.String);
    return val;
  };

  PresentationError.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationError.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.message);
  };
  function ConnectionMessage(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ConnectionMessage.prototype.initDefaults_ = function() {
    this.type = 0;
    this.message = null;
    this.data = null;
  };
  ConnectionMessage.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ConnectionMessage.validate = function(messageValidator, offset) {
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


    
    // validate ConnectionMessage.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PresentationMessageType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ConnectionMessage.message
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ConnectionMessage.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ConnectionMessage.encodedSize = codec.kStructHeaderSize + 24;

  ConnectionMessage.decode = function(decoder) {
    var packed;
    var val = new ConnectionMessage();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.message = decoder.decodeStruct(codec.NullableString);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  ConnectionMessage.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ConnectionMessage.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.NullableString, val.message);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function PresentationConnection_OnMessage_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationConnection_OnMessage_Params.prototype.initDefaults_ = function() {
    this.message = null;
  };
  PresentationConnection_OnMessage_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationConnection_OnMessage_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationConnection_OnMessage_Params.message
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ConnectionMessage, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationConnection_OnMessage_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationConnection_OnMessage_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationConnection_OnMessage_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.message = decoder.decodeStructPointer(ConnectionMessage);
    return val;
  };

  PresentationConnection_OnMessage_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationConnection_OnMessage_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ConnectionMessage, val.message);
  };
  function PresentationConnection_OnMessage_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationConnection_OnMessage_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  PresentationConnection_OnMessage_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationConnection_OnMessage_ResponseParams.validate = function(messageValidator, offset) {
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

  PresentationConnection_OnMessage_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PresentationConnection_OnMessage_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PresentationConnection_OnMessage_ResponseParams();
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

  PresentationConnection_OnMessage_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationConnection_OnMessage_ResponseParams.encodedSize);
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
  function PresentationConnection_DidChangeState_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationConnection_DidChangeState_Params.prototype.initDefaults_ = function() {
    this.state = 0;
  };
  PresentationConnection_DidChangeState_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationConnection_DidChangeState_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationConnection_DidChangeState_Params.state
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PresentationConnectionState);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationConnection_DidChangeState_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationConnection_DidChangeState_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationConnection_DidChangeState_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.state = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PresentationConnection_DidChangeState_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationConnection_DidChangeState_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.state);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PresentationService_SetClient_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_SetClient_Params.prototype.initDefaults_ = function() {
    this.client = new PresentationServiceClientPtr();
  };
  PresentationService_SetClient_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_SetClient_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_SetClient_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_SetClient_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationService_SetClient_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_SetClient_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(new codec.Interface(PresentationServiceClientPtr));
    return val;
  };

  PresentationService_SetClient_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_SetClient_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(PresentationServiceClientPtr), val.client);
  };
  function PresentationService_SetDefaultPresentationUrls_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_SetDefaultPresentationUrls_Params.prototype.initDefaults_ = function() {
    this.presentation_urls = null;
  };
  PresentationService_SetDefaultPresentationUrls_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_SetDefaultPresentationUrls_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_SetDefaultPresentationUrls_Params.presentation_urls
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(url$.Url), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_SetDefaultPresentationUrls_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationService_SetDefaultPresentationUrls_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_SetDefaultPresentationUrls_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.presentation_urls = decoder.decodeArrayPointer(new codec.PointerTo(url$.Url));
    return val;
  };

  PresentationService_SetDefaultPresentationUrls_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_SetDefaultPresentationUrls_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(url$.Url), val.presentation_urls);
  };
  function PresentationService_ListenForScreenAvailability_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_ListenForScreenAvailability_Params.prototype.initDefaults_ = function() {
    this.availability_url = null;
  };
  PresentationService_ListenForScreenAvailability_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_ListenForScreenAvailability_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_ListenForScreenAvailability_Params.availability_url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_ListenForScreenAvailability_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationService_ListenForScreenAvailability_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_ListenForScreenAvailability_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.availability_url = decoder.decodeStructPointer(url$.Url);
    return val;
  };

  PresentationService_ListenForScreenAvailability_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_ListenForScreenAvailability_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.availability_url);
  };
  function PresentationService_StopListeningForScreenAvailability_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_StopListeningForScreenAvailability_Params.prototype.initDefaults_ = function() {
    this.availability_url = null;
  };
  PresentationService_StopListeningForScreenAvailability_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_StopListeningForScreenAvailability_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_StopListeningForScreenAvailability_Params.availability_url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_StopListeningForScreenAvailability_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationService_StopListeningForScreenAvailability_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_StopListeningForScreenAvailability_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.availability_url = decoder.decodeStructPointer(url$.Url);
    return val;
  };

  PresentationService_StopListeningForScreenAvailability_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_StopListeningForScreenAvailability_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.availability_url);
  };
  function PresentationService_StartSession_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_StartSession_Params.prototype.initDefaults_ = function() {
    this.presentation_urls = null;
  };
  PresentationService_StartSession_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_StartSession_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_StartSession_Params.presentation_urls
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(url$.Url), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_StartSession_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationService_StartSession_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_StartSession_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.presentation_urls = decoder.decodeArrayPointer(new codec.PointerTo(url$.Url));
    return val;
  };

  PresentationService_StartSession_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_StartSession_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(url$.Url), val.presentation_urls);
  };
  function PresentationService_StartSession_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_StartSession_ResponseParams.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
    this.error = null;
  };
  PresentationService_StartSession_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_StartSession_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_StartSession_ResponseParams.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_StartSession_ResponseParams.error
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, PresentationError, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_StartSession_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  PresentationService_StartSession_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PresentationService_StartSession_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    val.error = decoder.decodeStructPointer(PresentationError);
    return val;
  };

  PresentationService_StartSession_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_StartSession_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
    encoder.encodeStructPointer(PresentationError, val.error);
  };
  function PresentationService_JoinSession_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_JoinSession_Params.prototype.initDefaults_ = function() {
    this.presentation_urls = null;
    this.presentation_id = null;
  };
  PresentationService_JoinSession_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_JoinSession_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_JoinSession_Params.presentation_urls
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(url$.Url), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_JoinSession_Params.presentation_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_JoinSession_Params.encodedSize = codec.kStructHeaderSize + 16;

  PresentationService_JoinSession_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_JoinSession_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.presentation_urls = decoder.decodeArrayPointer(new codec.PointerTo(url$.Url));
    val.presentation_id = decoder.decodeStruct(codec.NullableString);
    return val;
  };

  PresentationService_JoinSession_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_JoinSession_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(url$.Url), val.presentation_urls);
    encoder.encodeStruct(codec.NullableString, val.presentation_id);
  };
  function PresentationService_JoinSession_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_JoinSession_ResponseParams.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
    this.error = null;
  };
  PresentationService_JoinSession_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_JoinSession_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_JoinSession_ResponseParams.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_JoinSession_ResponseParams.error
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, PresentationError, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_JoinSession_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  PresentationService_JoinSession_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PresentationService_JoinSession_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    val.error = decoder.decodeStructPointer(PresentationError);
    return val;
  };

  PresentationService_JoinSession_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_JoinSession_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
    encoder.encodeStructPointer(PresentationError, val.error);
  };
  function PresentationService_SetPresentationConnection_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_SetPresentationConnection_Params.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
    this.controller_connection_ptr = new PresentationConnectionPtr();
    this.receiver_connection_request = new bindings.InterfaceRequest();
  };
  PresentationService_SetPresentationConnection_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_SetPresentationConnection_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_SetPresentationConnection_Params.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_SetPresentationConnection_Params.controller_connection_ptr
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_SetPresentationConnection_Params.receiver_connection_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_SetPresentationConnection_Params.encodedSize = codec.kStructHeaderSize + 24;

  PresentationService_SetPresentationConnection_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_SetPresentationConnection_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    val.controller_connection_ptr = decoder.decodeStruct(new codec.Interface(PresentationConnectionPtr));
    val.receiver_connection_request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PresentationService_SetPresentationConnection_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_SetPresentationConnection_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
    encoder.encodeStruct(new codec.Interface(PresentationConnectionPtr), val.controller_connection_ptr);
    encoder.encodeStruct(codec.InterfaceRequest, val.receiver_connection_request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PresentationService_SendConnectionMessage_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_SendConnectionMessage_Params.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
    this.message_request = null;
  };
  PresentationService_SendConnectionMessage_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_SendConnectionMessage_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_SendConnectionMessage_Params.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_SendConnectionMessage_Params.message_request
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, ConnectionMessage, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_SendConnectionMessage_Params.encodedSize = codec.kStructHeaderSize + 16;

  PresentationService_SendConnectionMessage_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_SendConnectionMessage_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    val.message_request = decoder.decodeStructPointer(ConnectionMessage);
    return val;
  };

  PresentationService_SendConnectionMessage_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_SendConnectionMessage_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
    encoder.encodeStructPointer(ConnectionMessage, val.message_request);
  };
  function PresentationService_SendConnectionMessage_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_SendConnectionMessage_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  PresentationService_SendConnectionMessage_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_SendConnectionMessage_ResponseParams.validate = function(messageValidator, offset) {
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

  PresentationService_SendConnectionMessage_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PresentationService_SendConnectionMessage_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PresentationService_SendConnectionMessage_ResponseParams();
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

  PresentationService_SendConnectionMessage_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_SendConnectionMessage_ResponseParams.encodedSize);
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
  function PresentationService_CloseConnection_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_CloseConnection_Params.prototype.initDefaults_ = function() {
    this.presentation_url = null;
    this.presentation_id = null;
  };
  PresentationService_CloseConnection_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_CloseConnection_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_CloseConnection_Params.presentation_url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_CloseConnection_Params.presentation_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_CloseConnection_Params.encodedSize = codec.kStructHeaderSize + 16;

  PresentationService_CloseConnection_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_CloseConnection_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.presentation_url = decoder.decodeStructPointer(url$.Url);
    val.presentation_id = decoder.decodeStruct(codec.String);
    return val;
  };

  PresentationService_CloseConnection_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_CloseConnection_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.presentation_url);
    encoder.encodeStruct(codec.String, val.presentation_id);
  };
  function PresentationService_Terminate_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_Terminate_Params.prototype.initDefaults_ = function() {
    this.presentation_url = null;
    this.presentation_id = null;
  };
  PresentationService_Terminate_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_Terminate_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_Terminate_Params.presentation_url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationService_Terminate_Params.presentation_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_Terminate_Params.encodedSize = codec.kStructHeaderSize + 16;

  PresentationService_Terminate_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_Terminate_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.presentation_url = decoder.decodeStructPointer(url$.Url);
    val.presentation_id = decoder.decodeStruct(codec.String);
    return val;
  };

  PresentationService_Terminate_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_Terminate_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.presentation_url);
    encoder.encodeStruct(codec.String, val.presentation_id);
  };
  function PresentationService_ListenForConnectionMessages_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationService_ListenForConnectionMessages_Params.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
  };
  PresentationService_ListenForConnectionMessages_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationService_ListenForConnectionMessages_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationService_ListenForConnectionMessages_Params.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationService_ListenForConnectionMessages_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationService_ListenForConnectionMessages_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationService_ListenForConnectionMessages_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    return val;
  };

  PresentationService_ListenForConnectionMessages_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationService_ListenForConnectionMessages_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
  };
  function PresentationServiceClient_OnScreenAvailabilityNotSupported_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.prototype.initDefaults_ = function() {
    this.url = null;
  };
  PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationServiceClient_OnScreenAvailabilityNotSupported_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStructPointer(url$.Url);
    return val;
  };

  PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.url);
  };
  function PresentationServiceClient_OnScreenAvailabilityUpdated_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationServiceClient_OnScreenAvailabilityUpdated_Params.prototype.initDefaults_ = function() {
    this.url = null;
    this.available = false;
  };
  PresentationServiceClient_OnScreenAvailabilityUpdated_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationServiceClient_OnScreenAvailabilityUpdated_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationServiceClient_OnScreenAvailabilityUpdated_Params.url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  PresentationServiceClient_OnScreenAvailabilityUpdated_Params.encodedSize = codec.kStructHeaderSize + 16;

  PresentationServiceClient_OnScreenAvailabilityUpdated_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationServiceClient_OnScreenAvailabilityUpdated_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStructPointer(url$.Url);
    packed = decoder.readUint8();
    val.available = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PresentationServiceClient_OnScreenAvailabilityUpdated_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationServiceClient_OnScreenAvailabilityUpdated_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.url);
    packed = 0;
    packed |= (val.available & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PresentationServiceClient_OnDefaultSessionStarted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationServiceClient_OnDefaultSessionStarted_Params.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
  };
  PresentationServiceClient_OnDefaultSessionStarted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationServiceClient_OnDefaultSessionStarted_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationServiceClient_OnDefaultSessionStarted_Params.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationServiceClient_OnDefaultSessionStarted_Params.encodedSize = codec.kStructHeaderSize + 8;

  PresentationServiceClient_OnDefaultSessionStarted_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationServiceClient_OnDefaultSessionStarted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    return val;
  };

  PresentationServiceClient_OnDefaultSessionStarted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationServiceClient_OnDefaultSessionStarted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
  };
  function PresentationServiceClient_OnConnectionStateChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationServiceClient_OnConnectionStateChanged_Params.prototype.initDefaults_ = function() {
    this.connection = null;
    this.newState = 0;
  };
  PresentationServiceClient_OnConnectionStateChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationServiceClient_OnConnectionStateChanged_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationServiceClient_OnConnectionStateChanged_Params.connection
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationServiceClient_OnConnectionStateChanged_Params.newState
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, PresentationConnectionState);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationServiceClient_OnConnectionStateChanged_Params.encodedSize = codec.kStructHeaderSize + 16;

  PresentationServiceClient_OnConnectionStateChanged_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationServiceClient_OnConnectionStateChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.connection = decoder.decodeStructPointer(PresentationSessionInfo);
    val.newState = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PresentationServiceClient_OnConnectionStateChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationServiceClient_OnConnectionStateChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.connection);
    encoder.encodeStruct(codec.Int32, val.newState);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PresentationServiceClient_OnConnectionClosed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationServiceClient_OnConnectionClosed_Params.prototype.initDefaults_ = function() {
    this.connection = null;
    this.reason = 0;
    this.message = null;
  };
  PresentationServiceClient_OnConnectionClosed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationServiceClient_OnConnectionClosed_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationServiceClient_OnConnectionClosed_Params.connection
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationServiceClient_OnConnectionClosed_Params.reason
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, PresentationConnectionCloseReason);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationServiceClient_OnConnectionClosed_Params.message
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationServiceClient_OnConnectionClosed_Params.encodedSize = codec.kStructHeaderSize + 24;

  PresentationServiceClient_OnConnectionClosed_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationServiceClient_OnConnectionClosed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.connection = decoder.decodeStructPointer(PresentationSessionInfo);
    val.reason = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.message = decoder.decodeStruct(codec.String);
    return val;
  };

  PresentationServiceClient_OnConnectionClosed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationServiceClient_OnConnectionClosed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.connection);
    encoder.encodeStruct(codec.Int32, val.reason);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.message);
  };
  function PresentationServiceClient_OnConnectionMessagesReceived_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationServiceClient_OnConnectionMessagesReceived_Params.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
    this.messages = null;
  };
  PresentationServiceClient_OnConnectionMessagesReceived_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationServiceClient_OnConnectionMessagesReceived_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationServiceClient_OnConnectionMessagesReceived_Params.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationServiceClient_OnConnectionMessagesReceived_Params.messages
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(ConnectionMessage), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationServiceClient_OnConnectionMessagesReceived_Params.encodedSize = codec.kStructHeaderSize + 16;

  PresentationServiceClient_OnConnectionMessagesReceived_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationServiceClient_OnConnectionMessagesReceived_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    val.messages = decoder.decodeArrayPointer(new codec.PointerTo(ConnectionMessage));
    return val;
  };

  PresentationServiceClient_OnConnectionMessagesReceived_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationServiceClient_OnConnectionMessagesReceived_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
    encoder.encodeArrayPointer(new codec.PointerTo(ConnectionMessage), val.messages);
  };
  function PresentationServiceClient_OnReceiverConnectionAvailable_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PresentationServiceClient_OnReceiverConnectionAvailable_Params.prototype.initDefaults_ = function() {
    this.sessionInfo = null;
    this.controller_connection_ptr = new PresentationConnectionPtr();
    this.receiver_connection_request = new bindings.InterfaceRequest();
  };
  PresentationServiceClient_OnReceiverConnectionAvailable_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PresentationServiceClient_OnReceiverConnectionAvailable_Params.validate = function(messageValidator, offset) {
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


    
    // validate PresentationServiceClient_OnReceiverConnectionAvailable_Params.sessionInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PresentationSessionInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationServiceClient_OnReceiverConnectionAvailable_Params.controller_connection_ptr
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PresentationServiceClient_OnReceiverConnectionAvailable_Params.receiver_connection_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PresentationServiceClient_OnReceiverConnectionAvailable_Params.encodedSize = codec.kStructHeaderSize + 24;

  PresentationServiceClient_OnReceiverConnectionAvailable_Params.decode = function(decoder) {
    var packed;
    var val = new PresentationServiceClient_OnReceiverConnectionAvailable_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sessionInfo = decoder.decodeStructPointer(PresentationSessionInfo);
    val.controller_connection_ptr = decoder.decodeStruct(new codec.Interface(PresentationConnectionPtr));
    val.receiver_connection_request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PresentationServiceClient_OnReceiverConnectionAvailable_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PresentationServiceClient_OnReceiverConnectionAvailable_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PresentationSessionInfo, val.sessionInfo);
    encoder.encodeStruct(new codec.Interface(PresentationConnectionPtr), val.controller_connection_ptr);
    encoder.encodeStruct(codec.InterfaceRequest, val.receiver_connection_request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kPresentationConnection_OnMessage_Name = 0;
  var kPresentationConnection_DidChangeState_Name = 1;

  function PresentationConnectionPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PresentationConnection,
                                                   handleOrPtrInfo);
  }

  function PresentationConnectionProxy(receiver) {
    this.receiver_ = receiver;
  }
  PresentationConnectionPtr.prototype.onMessage = function() {
    return PresentationConnectionProxy.prototype.onMessage
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationConnectionProxy.prototype.onMessage = function(message) {
    var params = new PresentationConnection_OnMessage_Params();
    params.message = message;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPresentationConnection_OnMessage_Name,
          codec.align(PresentationConnection_OnMessage_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PresentationConnection_OnMessage_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PresentationConnection_OnMessage_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PresentationConnectionPtr.prototype.didChangeState = function() {
    return PresentationConnectionProxy.prototype.didChangeState
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationConnectionProxy.prototype.didChangeState = function(state) {
    var params = new PresentationConnection_DidChangeState_Params();
    params.state = state;
    var builder = new codec.MessageBuilder(
        kPresentationConnection_DidChangeState_Name,
        codec.align(PresentationConnection_DidChangeState_Params.encodedSize));
    builder.encodeStruct(PresentationConnection_DidChangeState_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PresentationConnectionStub(delegate) {
    this.delegate_ = delegate;
  }
  PresentationConnectionStub.prototype.onMessage = function(message) {
    return this.delegate_ && this.delegate_.onMessage && this.delegate_.onMessage(message);
  }
  PresentationConnectionStub.prototype.didChangeState = function(state) {
    return this.delegate_ && this.delegate_.didChangeState && this.delegate_.didChangeState(state);
  }

  PresentationConnectionStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPresentationConnection_DidChangeState_Name:
      var params = reader.decodeStruct(PresentationConnection_DidChangeState_Params);
      this.didChangeState(params.state);
      return true;
    default:
      return false;
    }
  };

  PresentationConnectionStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPresentationConnection_OnMessage_Name:
      var params = reader.decodeStruct(PresentationConnection_OnMessage_Params);
      return this.onMessage(params.message).then(function(response) {
        var responseParams =
            new PresentationConnection_OnMessage_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPresentationConnection_OnMessage_Name,
            codec.align(PresentationConnection_OnMessage_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PresentationConnection_OnMessage_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePresentationConnectionRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPresentationConnection_OnMessage_Name:
        if (message.expectsResponse())
          paramsClass = PresentationConnection_OnMessage_Params;
      break;
      case kPresentationConnection_DidChangeState_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationConnection_DidChangeState_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePresentationConnectionResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kPresentationConnection_OnMessage_Name:
        if (message.isResponse())
          paramsClass = PresentationConnection_OnMessage_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var PresentationConnection = {
    name: 'blink::mojom::PresentationConnection',
    ptrClass: PresentationConnectionPtr,
    proxyClass: PresentationConnectionProxy,
    stubClass: PresentationConnectionStub,
    validateRequest: validatePresentationConnectionRequest,
    validateResponse: validatePresentationConnectionResponse,
  };
  PresentationConnectionStub.prototype.validator = validatePresentationConnectionRequest;
  PresentationConnectionProxy.prototype.validator = validatePresentationConnectionResponse;
  var kPresentationService_SetClient_Name = 0;
  var kPresentationService_SetDefaultPresentationUrls_Name = 1;
  var kPresentationService_ListenForScreenAvailability_Name = 2;
  var kPresentationService_StopListeningForScreenAvailability_Name = 3;
  var kPresentationService_StartSession_Name = 4;
  var kPresentationService_JoinSession_Name = 5;
  var kPresentationService_SetPresentationConnection_Name = 6;
  var kPresentationService_SendConnectionMessage_Name = 7;
  var kPresentationService_CloseConnection_Name = 8;
  var kPresentationService_Terminate_Name = 9;
  var kPresentationService_ListenForConnectionMessages_Name = 10;

  function PresentationServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PresentationService,
                                                   handleOrPtrInfo);
  }

  function PresentationServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  PresentationServicePtr.prototype.setClient = function() {
    return PresentationServiceProxy.prototype.setClient
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.setClient = function(client) {
    var params = new PresentationService_SetClient_Params();
    params.client = client;
    var builder = new codec.MessageBuilder(
        kPresentationService_SetClient_Name,
        codec.align(PresentationService_SetClient_Params.encodedSize));
    builder.encodeStruct(PresentationService_SetClient_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServicePtr.prototype.setDefaultPresentationUrls = function() {
    return PresentationServiceProxy.prototype.setDefaultPresentationUrls
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.setDefaultPresentationUrls = function(presentation_urls) {
    var params = new PresentationService_SetDefaultPresentationUrls_Params();
    params.presentation_urls = presentation_urls;
    var builder = new codec.MessageBuilder(
        kPresentationService_SetDefaultPresentationUrls_Name,
        codec.align(PresentationService_SetDefaultPresentationUrls_Params.encodedSize));
    builder.encodeStruct(PresentationService_SetDefaultPresentationUrls_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServicePtr.prototype.listenForScreenAvailability = function() {
    return PresentationServiceProxy.prototype.listenForScreenAvailability
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.listenForScreenAvailability = function(availability_url) {
    var params = new PresentationService_ListenForScreenAvailability_Params();
    params.availability_url = availability_url;
    var builder = new codec.MessageBuilder(
        kPresentationService_ListenForScreenAvailability_Name,
        codec.align(PresentationService_ListenForScreenAvailability_Params.encodedSize));
    builder.encodeStruct(PresentationService_ListenForScreenAvailability_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServicePtr.prototype.stopListeningForScreenAvailability = function() {
    return PresentationServiceProxy.prototype.stopListeningForScreenAvailability
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.stopListeningForScreenAvailability = function(availability_url) {
    var params = new PresentationService_StopListeningForScreenAvailability_Params();
    params.availability_url = availability_url;
    var builder = new codec.MessageBuilder(
        kPresentationService_StopListeningForScreenAvailability_Name,
        codec.align(PresentationService_StopListeningForScreenAvailability_Params.encodedSize));
    builder.encodeStruct(PresentationService_StopListeningForScreenAvailability_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServicePtr.prototype.startSession = function() {
    return PresentationServiceProxy.prototype.startSession
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.startSession = function(presentation_urls) {
    var params = new PresentationService_StartSession_Params();
    params.presentation_urls = presentation_urls;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPresentationService_StartSession_Name,
          codec.align(PresentationService_StartSession_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PresentationService_StartSession_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PresentationService_StartSession_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PresentationServicePtr.prototype.joinSession = function() {
    return PresentationServiceProxy.prototype.joinSession
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.joinSession = function(presentation_urls, presentation_id) {
    var params = new PresentationService_JoinSession_Params();
    params.presentation_urls = presentation_urls;
    params.presentation_id = presentation_id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPresentationService_JoinSession_Name,
          codec.align(PresentationService_JoinSession_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PresentationService_JoinSession_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PresentationService_JoinSession_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PresentationServicePtr.prototype.setPresentationConnection = function() {
    return PresentationServiceProxy.prototype.setPresentationConnection
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.setPresentationConnection = function(sessionInfo, controller_connection_ptr, receiver_connection_request) {
    var params = new PresentationService_SetPresentationConnection_Params();
    params.sessionInfo = sessionInfo;
    params.controller_connection_ptr = controller_connection_ptr;
    params.receiver_connection_request = receiver_connection_request;
    var builder = new codec.MessageBuilder(
        kPresentationService_SetPresentationConnection_Name,
        codec.align(PresentationService_SetPresentationConnection_Params.encodedSize));
    builder.encodeStruct(PresentationService_SetPresentationConnection_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServicePtr.prototype.sendConnectionMessage = function() {
    return PresentationServiceProxy.prototype.sendConnectionMessage
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.sendConnectionMessage = function(sessionInfo, message_request) {
    var params = new PresentationService_SendConnectionMessage_Params();
    params.sessionInfo = sessionInfo;
    params.message_request = message_request;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPresentationService_SendConnectionMessage_Name,
          codec.align(PresentationService_SendConnectionMessage_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PresentationService_SendConnectionMessage_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PresentationService_SendConnectionMessage_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PresentationServicePtr.prototype.closeConnection = function() {
    return PresentationServiceProxy.prototype.closeConnection
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.closeConnection = function(presentation_url, presentation_id) {
    var params = new PresentationService_CloseConnection_Params();
    params.presentation_url = presentation_url;
    params.presentation_id = presentation_id;
    var builder = new codec.MessageBuilder(
        kPresentationService_CloseConnection_Name,
        codec.align(PresentationService_CloseConnection_Params.encodedSize));
    builder.encodeStruct(PresentationService_CloseConnection_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServicePtr.prototype.terminate = function() {
    return PresentationServiceProxy.prototype.terminate
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.terminate = function(presentation_url, presentation_id) {
    var params = new PresentationService_Terminate_Params();
    params.presentation_url = presentation_url;
    params.presentation_id = presentation_id;
    var builder = new codec.MessageBuilder(
        kPresentationService_Terminate_Name,
        codec.align(PresentationService_Terminate_Params.encodedSize));
    builder.encodeStruct(PresentationService_Terminate_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServicePtr.prototype.listenForConnectionMessages = function() {
    return PresentationServiceProxy.prototype.listenForConnectionMessages
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceProxy.prototype.listenForConnectionMessages = function(sessionInfo) {
    var params = new PresentationService_ListenForConnectionMessages_Params();
    params.sessionInfo = sessionInfo;
    var builder = new codec.MessageBuilder(
        kPresentationService_ListenForConnectionMessages_Name,
        codec.align(PresentationService_ListenForConnectionMessages_Params.encodedSize));
    builder.encodeStruct(PresentationService_ListenForConnectionMessages_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PresentationServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  PresentationServiceStub.prototype.setClient = function(client) {
    return this.delegate_ && this.delegate_.setClient && this.delegate_.setClient(client);
  }
  PresentationServiceStub.prototype.setDefaultPresentationUrls = function(presentation_urls) {
    return this.delegate_ && this.delegate_.setDefaultPresentationUrls && this.delegate_.setDefaultPresentationUrls(presentation_urls);
  }
  PresentationServiceStub.prototype.listenForScreenAvailability = function(availability_url) {
    return this.delegate_ && this.delegate_.listenForScreenAvailability && this.delegate_.listenForScreenAvailability(availability_url);
  }
  PresentationServiceStub.prototype.stopListeningForScreenAvailability = function(availability_url) {
    return this.delegate_ && this.delegate_.stopListeningForScreenAvailability && this.delegate_.stopListeningForScreenAvailability(availability_url);
  }
  PresentationServiceStub.prototype.startSession = function(presentation_urls) {
    return this.delegate_ && this.delegate_.startSession && this.delegate_.startSession(presentation_urls);
  }
  PresentationServiceStub.prototype.joinSession = function(presentation_urls, presentation_id) {
    return this.delegate_ && this.delegate_.joinSession && this.delegate_.joinSession(presentation_urls, presentation_id);
  }
  PresentationServiceStub.prototype.setPresentationConnection = function(sessionInfo, controller_connection_ptr, receiver_connection_request) {
    return this.delegate_ && this.delegate_.setPresentationConnection && this.delegate_.setPresentationConnection(sessionInfo, controller_connection_ptr, receiver_connection_request);
  }
  PresentationServiceStub.prototype.sendConnectionMessage = function(sessionInfo, message_request) {
    return this.delegate_ && this.delegate_.sendConnectionMessage && this.delegate_.sendConnectionMessage(sessionInfo, message_request);
  }
  PresentationServiceStub.prototype.closeConnection = function(presentation_url, presentation_id) {
    return this.delegate_ && this.delegate_.closeConnection && this.delegate_.closeConnection(presentation_url, presentation_id);
  }
  PresentationServiceStub.prototype.terminate = function(presentation_url, presentation_id) {
    return this.delegate_ && this.delegate_.terminate && this.delegate_.terminate(presentation_url, presentation_id);
  }
  PresentationServiceStub.prototype.listenForConnectionMessages = function(sessionInfo) {
    return this.delegate_ && this.delegate_.listenForConnectionMessages && this.delegate_.listenForConnectionMessages(sessionInfo);
  }

  PresentationServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPresentationService_SetClient_Name:
      var params = reader.decodeStruct(PresentationService_SetClient_Params);
      this.setClient(params.client);
      return true;
    case kPresentationService_SetDefaultPresentationUrls_Name:
      var params = reader.decodeStruct(PresentationService_SetDefaultPresentationUrls_Params);
      this.setDefaultPresentationUrls(params.presentation_urls);
      return true;
    case kPresentationService_ListenForScreenAvailability_Name:
      var params = reader.decodeStruct(PresentationService_ListenForScreenAvailability_Params);
      this.listenForScreenAvailability(params.availability_url);
      return true;
    case kPresentationService_StopListeningForScreenAvailability_Name:
      var params = reader.decodeStruct(PresentationService_StopListeningForScreenAvailability_Params);
      this.stopListeningForScreenAvailability(params.availability_url);
      return true;
    case kPresentationService_SetPresentationConnection_Name:
      var params = reader.decodeStruct(PresentationService_SetPresentationConnection_Params);
      this.setPresentationConnection(params.sessionInfo, params.controller_connection_ptr, params.receiver_connection_request);
      return true;
    case kPresentationService_CloseConnection_Name:
      var params = reader.decodeStruct(PresentationService_CloseConnection_Params);
      this.closeConnection(params.presentation_url, params.presentation_id);
      return true;
    case kPresentationService_Terminate_Name:
      var params = reader.decodeStruct(PresentationService_Terminate_Params);
      this.terminate(params.presentation_url, params.presentation_id);
      return true;
    case kPresentationService_ListenForConnectionMessages_Name:
      var params = reader.decodeStruct(PresentationService_ListenForConnectionMessages_Params);
      this.listenForConnectionMessages(params.sessionInfo);
      return true;
    default:
      return false;
    }
  };

  PresentationServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPresentationService_StartSession_Name:
      var params = reader.decodeStruct(PresentationService_StartSession_Params);
      return this.startSession(params.presentation_urls).then(function(response) {
        var responseParams =
            new PresentationService_StartSession_ResponseParams();
        responseParams.sessionInfo = response.sessionInfo;
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPresentationService_StartSession_Name,
            codec.align(PresentationService_StartSession_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PresentationService_StartSession_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kPresentationService_JoinSession_Name:
      var params = reader.decodeStruct(PresentationService_JoinSession_Params);
      return this.joinSession(params.presentation_urls, params.presentation_id).then(function(response) {
        var responseParams =
            new PresentationService_JoinSession_ResponseParams();
        responseParams.sessionInfo = response.sessionInfo;
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPresentationService_JoinSession_Name,
            codec.align(PresentationService_JoinSession_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PresentationService_JoinSession_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kPresentationService_SendConnectionMessage_Name:
      var params = reader.decodeStruct(PresentationService_SendConnectionMessage_Params);
      return this.sendConnectionMessage(params.sessionInfo, params.message_request).then(function(response) {
        var responseParams =
            new PresentationService_SendConnectionMessage_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPresentationService_SendConnectionMessage_Name,
            codec.align(PresentationService_SendConnectionMessage_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PresentationService_SendConnectionMessage_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePresentationServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPresentationService_SetClient_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_SetClient_Params;
      break;
      case kPresentationService_SetDefaultPresentationUrls_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_SetDefaultPresentationUrls_Params;
      break;
      case kPresentationService_ListenForScreenAvailability_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_ListenForScreenAvailability_Params;
      break;
      case kPresentationService_StopListeningForScreenAvailability_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_StopListeningForScreenAvailability_Params;
      break;
      case kPresentationService_StartSession_Name:
        if (message.expectsResponse())
          paramsClass = PresentationService_StartSession_Params;
      break;
      case kPresentationService_JoinSession_Name:
        if (message.expectsResponse())
          paramsClass = PresentationService_JoinSession_Params;
      break;
      case kPresentationService_SetPresentationConnection_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_SetPresentationConnection_Params;
      break;
      case kPresentationService_SendConnectionMessage_Name:
        if (message.expectsResponse())
          paramsClass = PresentationService_SendConnectionMessage_Params;
      break;
      case kPresentationService_CloseConnection_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_CloseConnection_Params;
      break;
      case kPresentationService_Terminate_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_Terminate_Params;
      break;
      case kPresentationService_ListenForConnectionMessages_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationService_ListenForConnectionMessages_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePresentationServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kPresentationService_StartSession_Name:
        if (message.isResponse())
          paramsClass = PresentationService_StartSession_ResponseParams;
        break;
      case kPresentationService_JoinSession_Name:
        if (message.isResponse())
          paramsClass = PresentationService_JoinSession_ResponseParams;
        break;
      case kPresentationService_SendConnectionMessage_Name:
        if (message.isResponse())
          paramsClass = PresentationService_SendConnectionMessage_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var PresentationService = {
    name: 'blink::mojom::PresentationService',
    ptrClass: PresentationServicePtr,
    proxyClass: PresentationServiceProxy,
    stubClass: PresentationServiceStub,
    validateRequest: validatePresentationServiceRequest,
    validateResponse: validatePresentationServiceResponse,
  };
  PresentationServiceStub.prototype.validator = validatePresentationServiceRequest;
  PresentationServiceProxy.prototype.validator = validatePresentationServiceResponse;
  var kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name = 0;
  var kPresentationServiceClient_OnScreenAvailabilityUpdated_Name = 1;
  var kPresentationServiceClient_OnDefaultSessionStarted_Name = 2;
  var kPresentationServiceClient_OnConnectionStateChanged_Name = 3;
  var kPresentationServiceClient_OnConnectionClosed_Name = 4;
  var kPresentationServiceClient_OnConnectionMessagesReceived_Name = 5;
  var kPresentationServiceClient_OnReceiverConnectionAvailable_Name = 6;

  function PresentationServiceClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PresentationServiceClient,
                                                   handleOrPtrInfo);
  }

  function PresentationServiceClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  PresentationServiceClientPtr.prototype.onScreenAvailabilityNotSupported = function() {
    return PresentationServiceClientProxy.prototype.onScreenAvailabilityNotSupported
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceClientProxy.prototype.onScreenAvailabilityNotSupported = function(url) {
    var params = new PresentationServiceClient_OnScreenAvailabilityNotSupported_Params();
    params.url = url;
    var builder = new codec.MessageBuilder(
        kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name,
        codec.align(PresentationServiceClient_OnScreenAvailabilityNotSupported_Params.encodedSize));
    builder.encodeStruct(PresentationServiceClient_OnScreenAvailabilityNotSupported_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServiceClientPtr.prototype.onScreenAvailabilityUpdated = function() {
    return PresentationServiceClientProxy.prototype.onScreenAvailabilityUpdated
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceClientProxy.prototype.onScreenAvailabilityUpdated = function(url, available) {
    var params = new PresentationServiceClient_OnScreenAvailabilityUpdated_Params();
    params.url = url;
    params.available = available;
    var builder = new codec.MessageBuilder(
        kPresentationServiceClient_OnScreenAvailabilityUpdated_Name,
        codec.align(PresentationServiceClient_OnScreenAvailabilityUpdated_Params.encodedSize));
    builder.encodeStruct(PresentationServiceClient_OnScreenAvailabilityUpdated_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServiceClientPtr.prototype.onDefaultSessionStarted = function() {
    return PresentationServiceClientProxy.prototype.onDefaultSessionStarted
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceClientProxy.prototype.onDefaultSessionStarted = function(sessionInfo) {
    var params = new PresentationServiceClient_OnDefaultSessionStarted_Params();
    params.sessionInfo = sessionInfo;
    var builder = new codec.MessageBuilder(
        kPresentationServiceClient_OnDefaultSessionStarted_Name,
        codec.align(PresentationServiceClient_OnDefaultSessionStarted_Params.encodedSize));
    builder.encodeStruct(PresentationServiceClient_OnDefaultSessionStarted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServiceClientPtr.prototype.onConnectionStateChanged = function() {
    return PresentationServiceClientProxy.prototype.onConnectionStateChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceClientProxy.prototype.onConnectionStateChanged = function(connection, newState) {
    var params = new PresentationServiceClient_OnConnectionStateChanged_Params();
    params.connection = connection;
    params.newState = newState;
    var builder = new codec.MessageBuilder(
        kPresentationServiceClient_OnConnectionStateChanged_Name,
        codec.align(PresentationServiceClient_OnConnectionStateChanged_Params.encodedSize));
    builder.encodeStruct(PresentationServiceClient_OnConnectionStateChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServiceClientPtr.prototype.onConnectionClosed = function() {
    return PresentationServiceClientProxy.prototype.onConnectionClosed
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceClientProxy.prototype.onConnectionClosed = function(connection, reason, message) {
    var params = new PresentationServiceClient_OnConnectionClosed_Params();
    params.connection = connection;
    params.reason = reason;
    params.message = message;
    var builder = new codec.MessageBuilder(
        kPresentationServiceClient_OnConnectionClosed_Name,
        codec.align(PresentationServiceClient_OnConnectionClosed_Params.encodedSize));
    builder.encodeStruct(PresentationServiceClient_OnConnectionClosed_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServiceClientPtr.prototype.onConnectionMessagesReceived = function() {
    return PresentationServiceClientProxy.prototype.onConnectionMessagesReceived
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceClientProxy.prototype.onConnectionMessagesReceived = function(sessionInfo, messages) {
    var params = new PresentationServiceClient_OnConnectionMessagesReceived_Params();
    params.sessionInfo = sessionInfo;
    params.messages = messages;
    var builder = new codec.MessageBuilder(
        kPresentationServiceClient_OnConnectionMessagesReceived_Name,
        codec.align(PresentationServiceClient_OnConnectionMessagesReceived_Params.encodedSize));
    builder.encodeStruct(PresentationServiceClient_OnConnectionMessagesReceived_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PresentationServiceClientPtr.prototype.onReceiverConnectionAvailable = function() {
    return PresentationServiceClientProxy.prototype.onReceiverConnectionAvailable
        .apply(this.ptr.getProxy(), arguments);
  };

  PresentationServiceClientProxy.prototype.onReceiverConnectionAvailable = function(sessionInfo, controller_connection_ptr, receiver_connection_request) {
    var params = new PresentationServiceClient_OnReceiverConnectionAvailable_Params();
    params.sessionInfo = sessionInfo;
    params.controller_connection_ptr = controller_connection_ptr;
    params.receiver_connection_request = receiver_connection_request;
    var builder = new codec.MessageBuilder(
        kPresentationServiceClient_OnReceiverConnectionAvailable_Name,
        codec.align(PresentationServiceClient_OnReceiverConnectionAvailable_Params.encodedSize));
    builder.encodeStruct(PresentationServiceClient_OnReceiverConnectionAvailable_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PresentationServiceClientStub(delegate) {
    this.delegate_ = delegate;
  }
  PresentationServiceClientStub.prototype.onScreenAvailabilityNotSupported = function(url) {
    return this.delegate_ && this.delegate_.onScreenAvailabilityNotSupported && this.delegate_.onScreenAvailabilityNotSupported(url);
  }
  PresentationServiceClientStub.prototype.onScreenAvailabilityUpdated = function(url, available) {
    return this.delegate_ && this.delegate_.onScreenAvailabilityUpdated && this.delegate_.onScreenAvailabilityUpdated(url, available);
  }
  PresentationServiceClientStub.prototype.onDefaultSessionStarted = function(sessionInfo) {
    return this.delegate_ && this.delegate_.onDefaultSessionStarted && this.delegate_.onDefaultSessionStarted(sessionInfo);
  }
  PresentationServiceClientStub.prototype.onConnectionStateChanged = function(connection, newState) {
    return this.delegate_ && this.delegate_.onConnectionStateChanged && this.delegate_.onConnectionStateChanged(connection, newState);
  }
  PresentationServiceClientStub.prototype.onConnectionClosed = function(connection, reason, message) {
    return this.delegate_ && this.delegate_.onConnectionClosed && this.delegate_.onConnectionClosed(connection, reason, message);
  }
  PresentationServiceClientStub.prototype.onConnectionMessagesReceived = function(sessionInfo, messages) {
    return this.delegate_ && this.delegate_.onConnectionMessagesReceived && this.delegate_.onConnectionMessagesReceived(sessionInfo, messages);
  }
  PresentationServiceClientStub.prototype.onReceiverConnectionAvailable = function(sessionInfo, controller_connection_ptr, receiver_connection_request) {
    return this.delegate_ && this.delegate_.onReceiverConnectionAvailable && this.delegate_.onReceiverConnectionAvailable(sessionInfo, controller_connection_ptr, receiver_connection_request);
  }

  PresentationServiceClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name:
      var params = reader.decodeStruct(PresentationServiceClient_OnScreenAvailabilityNotSupported_Params);
      this.onScreenAvailabilityNotSupported(params.url);
      return true;
    case kPresentationServiceClient_OnScreenAvailabilityUpdated_Name:
      var params = reader.decodeStruct(PresentationServiceClient_OnScreenAvailabilityUpdated_Params);
      this.onScreenAvailabilityUpdated(params.url, params.available);
      return true;
    case kPresentationServiceClient_OnDefaultSessionStarted_Name:
      var params = reader.decodeStruct(PresentationServiceClient_OnDefaultSessionStarted_Params);
      this.onDefaultSessionStarted(params.sessionInfo);
      return true;
    case kPresentationServiceClient_OnConnectionStateChanged_Name:
      var params = reader.decodeStruct(PresentationServiceClient_OnConnectionStateChanged_Params);
      this.onConnectionStateChanged(params.connection, params.newState);
      return true;
    case kPresentationServiceClient_OnConnectionClosed_Name:
      var params = reader.decodeStruct(PresentationServiceClient_OnConnectionClosed_Params);
      this.onConnectionClosed(params.connection, params.reason, params.message);
      return true;
    case kPresentationServiceClient_OnConnectionMessagesReceived_Name:
      var params = reader.decodeStruct(PresentationServiceClient_OnConnectionMessagesReceived_Params);
      this.onConnectionMessagesReceived(params.sessionInfo, params.messages);
      return true;
    case kPresentationServiceClient_OnReceiverConnectionAvailable_Name:
      var params = reader.decodeStruct(PresentationServiceClient_OnReceiverConnectionAvailable_Params);
      this.onReceiverConnectionAvailable(params.sessionInfo, params.controller_connection_ptr, params.receiver_connection_request);
      return true;
    default:
      return false;
    }
  };

  PresentationServiceClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePresentationServiceClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationServiceClient_OnScreenAvailabilityNotSupported_Params;
      break;
      case kPresentationServiceClient_OnScreenAvailabilityUpdated_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationServiceClient_OnScreenAvailabilityUpdated_Params;
      break;
      case kPresentationServiceClient_OnDefaultSessionStarted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationServiceClient_OnDefaultSessionStarted_Params;
      break;
      case kPresentationServiceClient_OnConnectionStateChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationServiceClient_OnConnectionStateChanged_Params;
      break;
      case kPresentationServiceClient_OnConnectionClosed_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationServiceClient_OnConnectionClosed_Params;
      break;
      case kPresentationServiceClient_OnConnectionMessagesReceived_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationServiceClient_OnConnectionMessagesReceived_Params;
      break;
      case kPresentationServiceClient_OnReceiverConnectionAvailable_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PresentationServiceClient_OnReceiverConnectionAvailable_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePresentationServiceClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PresentationServiceClient = {
    name: 'blink::mojom::PresentationServiceClient',
    ptrClass: PresentationServiceClientPtr,
    proxyClass: PresentationServiceClientProxy,
    stubClass: PresentationServiceClientStub,
    validateRequest: validatePresentationServiceClientRequest,
    validateResponse: null,
  };
  PresentationServiceClientStub.prototype.validator = validatePresentationServiceClientRequest;
  PresentationServiceClientProxy.prototype.validator = null;

  var exports = {};
  exports.PresentationConnectionState = PresentationConnectionState;
  exports.PresentationConnectionCloseReason = PresentationConnectionCloseReason;
  exports.PresentationErrorType = PresentationErrorType;
  exports.PresentationMessageType = PresentationMessageType;
  exports.PresentationSessionInfo = PresentationSessionInfo;
  exports.PresentationError = PresentationError;
  exports.ConnectionMessage = ConnectionMessage;
  exports.PresentationConnection = PresentationConnection;
  exports.PresentationConnectionPtr = PresentationConnectionPtr;
  exports.PresentationService = PresentationService;
  exports.PresentationServicePtr = PresentationServicePtr;
  exports.PresentationServiceClient = PresentationServiceClient;
  exports.PresentationServiceClientPtr = PresentationServiceClientPtr;

  return exports;
});
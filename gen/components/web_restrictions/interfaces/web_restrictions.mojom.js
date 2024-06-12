// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/web_restrictions/interfaces/web_restrictions.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function ClientResult(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ClientResult.prototype.initDefaults_ = function() {
    this.intParams = null;
    this.stringParams = null;
  };
  ClientResult.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ClientResult.validate = function(messageValidator, offset) {
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


    
    // validate ClientResult.intParams
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 0, false, codec.String, codec.Int32, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ClientResult.stringParams
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, false, codec.String, codec.String, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ClientResult.encodedSize = codec.kStructHeaderSize + 16;

  ClientResult.decode = function(decoder) {
    var packed;
    var val = new ClientResult();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.intParams = decoder.decodeMapPointer(codec.String, codec.Int32);
    val.stringParams = decoder.decodeMapPointer(codec.String, codec.String);
    return val;
  };

  ClientResult.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ClientResult.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeMapPointer(codec.String, codec.Int32, val.intParams);
    encoder.encodeMapPointer(codec.String, codec.String, val.stringParams);
  };
  function WebRestrictions_GetResult_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WebRestrictions_GetResult_Params.prototype.initDefaults_ = function() {
    this.url = null;
  };
  WebRestrictions_GetResult_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WebRestrictions_GetResult_Params.validate = function(messageValidator, offset) {
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


    
    // validate WebRestrictions_GetResult_Params.url
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WebRestrictions_GetResult_Params.encodedSize = codec.kStructHeaderSize + 8;

  WebRestrictions_GetResult_Params.decode = function(decoder) {
    var packed;
    var val = new WebRestrictions_GetResult_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStruct(codec.String);
    return val;
  };

  WebRestrictions_GetResult_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WebRestrictions_GetResult_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.url);
  };
  function WebRestrictions_GetResult_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WebRestrictions_GetResult_ResponseParams.prototype.initDefaults_ = function() {
    this.reply = null;
  };
  WebRestrictions_GetResult_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WebRestrictions_GetResult_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate WebRestrictions_GetResult_ResponseParams.reply
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ClientResult, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WebRestrictions_GetResult_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WebRestrictions_GetResult_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WebRestrictions_GetResult_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.reply = decoder.decodeStructPointer(ClientResult);
    return val;
  };

  WebRestrictions_GetResult_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WebRestrictions_GetResult_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ClientResult, val.reply);
  };
  function WebRestrictions_RequestPermission_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WebRestrictions_RequestPermission_Params.prototype.initDefaults_ = function() {
    this.url = null;
  };
  WebRestrictions_RequestPermission_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WebRestrictions_RequestPermission_Params.validate = function(messageValidator, offset) {
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


    
    // validate WebRestrictions_RequestPermission_Params.url
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WebRestrictions_RequestPermission_Params.encodedSize = codec.kStructHeaderSize + 8;

  WebRestrictions_RequestPermission_Params.decode = function(decoder) {
    var packed;
    var val = new WebRestrictions_RequestPermission_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStruct(codec.String);
    return val;
  };

  WebRestrictions_RequestPermission_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WebRestrictions_RequestPermission_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.url);
  };
  function WebRestrictions_RequestPermission_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WebRestrictions_RequestPermission_ResponseParams.prototype.initDefaults_ = function() {
    this.result = false;
  };
  WebRestrictions_RequestPermission_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WebRestrictions_RequestPermission_ResponseParams.validate = function(messageValidator, offset) {
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

  WebRestrictions_RequestPermission_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  WebRestrictions_RequestPermission_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new WebRestrictions_RequestPermission_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.result = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WebRestrictions_RequestPermission_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WebRestrictions_RequestPermission_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.result & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kWebRestrictions_GetResult_Name = 0;
  var kWebRestrictions_RequestPermission_Name = 1;

  function WebRestrictionsPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WebRestrictions,
                                                   handleOrPtrInfo);
  }

  function WebRestrictionsProxy(receiver) {
    this.receiver_ = receiver;
  }
  WebRestrictionsPtr.prototype.getResult = function() {
    return WebRestrictionsProxy.prototype.getResult
        .apply(this.ptr.getProxy(), arguments);
  };

  WebRestrictionsProxy.prototype.getResult = function(url) {
    var params = new WebRestrictions_GetResult_Params();
    params.url = url;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWebRestrictions_GetResult_Name,
          codec.align(WebRestrictions_GetResult_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WebRestrictions_GetResult_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WebRestrictions_GetResult_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  WebRestrictionsPtr.prototype.requestPermission = function() {
    return WebRestrictionsProxy.prototype.requestPermission
        .apply(this.ptr.getProxy(), arguments);
  };

  WebRestrictionsProxy.prototype.requestPermission = function(url) {
    var params = new WebRestrictions_RequestPermission_Params();
    params.url = url;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kWebRestrictions_RequestPermission_Name,
          codec.align(WebRestrictions_RequestPermission_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(WebRestrictions_RequestPermission_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(WebRestrictions_RequestPermission_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function WebRestrictionsStub(delegate) {
    this.delegate_ = delegate;
  }
  WebRestrictionsStub.prototype.getResult = function(url) {
    return this.delegate_ && this.delegate_.getResult && this.delegate_.getResult(url);
  }
  WebRestrictionsStub.prototype.requestPermission = function(url) {
    return this.delegate_ && this.delegate_.requestPermission && this.delegate_.requestPermission(url);
  }

  WebRestrictionsStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  WebRestrictionsStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWebRestrictions_GetResult_Name:
      var params = reader.decodeStruct(WebRestrictions_GetResult_Params);
      return this.getResult(params.url).then(function(response) {
        var responseParams =
            new WebRestrictions_GetResult_ResponseParams();
        responseParams.reply = response.reply;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWebRestrictions_GetResult_Name,
            codec.align(WebRestrictions_GetResult_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WebRestrictions_GetResult_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kWebRestrictions_RequestPermission_Name:
      var params = reader.decodeStruct(WebRestrictions_RequestPermission_Params);
      return this.requestPermission(params.url).then(function(response) {
        var responseParams =
            new WebRestrictions_RequestPermission_ResponseParams();
        responseParams.result = response.result;
        var builder = new codec.MessageWithRequestIDBuilder(
            kWebRestrictions_RequestPermission_Name,
            codec.align(WebRestrictions_RequestPermission_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(WebRestrictions_RequestPermission_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWebRestrictionsRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWebRestrictions_GetResult_Name:
        if (message.expectsResponse())
          paramsClass = WebRestrictions_GetResult_Params;
      break;
      case kWebRestrictions_RequestPermission_Name:
        if (message.expectsResponse())
          paramsClass = WebRestrictions_RequestPermission_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWebRestrictionsResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kWebRestrictions_GetResult_Name:
        if (message.isResponse())
          paramsClass = WebRestrictions_GetResult_ResponseParams;
        break;
      case kWebRestrictions_RequestPermission_Name:
        if (message.isResponse())
          paramsClass = WebRestrictions_RequestPermission_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var WebRestrictions = {
    name: 'web_restrictions::mojom::WebRestrictions',
    ptrClass: WebRestrictionsPtr,
    proxyClass: WebRestrictionsProxy,
    stubClass: WebRestrictionsStub,
    validateRequest: validateWebRestrictionsRequest,
    validateResponse: validateWebRestrictionsResponse,
  };
  WebRestrictionsStub.prototype.validator = validateWebRestrictionsRequest;
  WebRestrictionsProxy.prototype.validator = validateWebRestrictionsResponse;

  var exports = {};
  exports.ClientResult = ClientResult;
  exports.WebRestrictions = WebRestrictions;
  exports.WebRestrictionsPtr = WebRestrictionsPtr;

  return exports;
});
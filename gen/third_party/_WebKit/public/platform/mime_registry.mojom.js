// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/mime_registry.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function MimeRegistry_GetMimeTypeFromExtension_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MimeRegistry_GetMimeTypeFromExtension_Params.prototype.initDefaults_ = function() {
    this.extension = null;
  };
  MimeRegistry_GetMimeTypeFromExtension_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MimeRegistry_GetMimeTypeFromExtension_Params.validate = function(messageValidator, offset) {
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


    
    // validate MimeRegistry_GetMimeTypeFromExtension_Params.extension
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MimeRegistry_GetMimeTypeFromExtension_Params.encodedSize = codec.kStructHeaderSize + 8;

  MimeRegistry_GetMimeTypeFromExtension_Params.decode = function(decoder) {
    var packed;
    var val = new MimeRegistry_GetMimeTypeFromExtension_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.extension = decoder.decodeStruct(codec.String);
    return val;
  };

  MimeRegistry_GetMimeTypeFromExtension_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MimeRegistry_GetMimeTypeFromExtension_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.extension);
  };
  function MimeRegistry_GetMimeTypeFromExtension_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MimeRegistry_GetMimeTypeFromExtension_ResponseParams.prototype.initDefaults_ = function() {
    this.mime_type = null;
  };
  MimeRegistry_GetMimeTypeFromExtension_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MimeRegistry_GetMimeTypeFromExtension_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate MimeRegistry_GetMimeTypeFromExtension_ResponseParams.mime_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  MimeRegistry_GetMimeTypeFromExtension_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  MimeRegistry_GetMimeTypeFromExtension_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new MimeRegistry_GetMimeTypeFromExtension_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.mime_type = decoder.decodeStruct(codec.String);
    return val;
  };

  MimeRegistry_GetMimeTypeFromExtension_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MimeRegistry_GetMimeTypeFromExtension_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.mime_type);
  };
  var kMimeRegistry_GetMimeTypeFromExtension_Name = 0;

  function MimeRegistryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(MimeRegistry,
                                                   handleOrPtrInfo);
  }

  function MimeRegistryProxy(receiver) {
    this.receiver_ = receiver;
  }
  MimeRegistryPtr.prototype.getMimeTypeFromExtension = function() {
    return MimeRegistryProxy.prototype.getMimeTypeFromExtension
        .apply(this.ptr.getProxy(), arguments);
  };

  MimeRegistryProxy.prototype.getMimeTypeFromExtension = function(extension) {
    var params = new MimeRegistry_GetMimeTypeFromExtension_Params();
    params.extension = extension;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kMimeRegistry_GetMimeTypeFromExtension_Name,
          codec.align(MimeRegistry_GetMimeTypeFromExtension_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(MimeRegistry_GetMimeTypeFromExtension_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(MimeRegistry_GetMimeTypeFromExtension_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function MimeRegistryStub(delegate) {
    this.delegate_ = delegate;
  }
  MimeRegistryStub.prototype.getMimeTypeFromExtension = function(extension) {
    return this.delegate_ && this.delegate_.getMimeTypeFromExtension && this.delegate_.getMimeTypeFromExtension(extension);
  }

  MimeRegistryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  MimeRegistryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kMimeRegistry_GetMimeTypeFromExtension_Name:
      var params = reader.decodeStruct(MimeRegistry_GetMimeTypeFromExtension_Params);
      return this.getMimeTypeFromExtension(params.extension).then(function(response) {
        var responseParams =
            new MimeRegistry_GetMimeTypeFromExtension_ResponseParams();
        responseParams.mime_type = response.mime_type;
        var builder = new codec.MessageWithRequestIDBuilder(
            kMimeRegistry_GetMimeTypeFromExtension_Name,
            codec.align(MimeRegistry_GetMimeTypeFromExtension_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(MimeRegistry_GetMimeTypeFromExtension_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateMimeRegistryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kMimeRegistry_GetMimeTypeFromExtension_Name:
        if (message.expectsResponse())
          paramsClass = MimeRegistry_GetMimeTypeFromExtension_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateMimeRegistryResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kMimeRegistry_GetMimeTypeFromExtension_Name:
        if (message.isResponse())
          paramsClass = MimeRegistry_GetMimeTypeFromExtension_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var MimeRegistry = {
    name: 'blink::mojom::MimeRegistry',
    ptrClass: MimeRegistryPtr,
    proxyClass: MimeRegistryProxy,
    stubClass: MimeRegistryStub,
    validateRequest: validateMimeRegistryRequest,
    validateResponse: validateMimeRegistryResponse,
  };
  MimeRegistryStub.prototype.validator = validateMimeRegistryRequest;
  MimeRegistryProxy.prototype.validator = validateMimeRegistryResponse;

  var exports = {};
  exports.MimeRegistry = MimeRegistry;
  exports.MimeRegistryPtr = MimeRegistryPtr;

  return exports;
});
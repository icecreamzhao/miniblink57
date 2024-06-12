// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/webshare/webshare.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "url/mojo/url.mojom",
], function(bindings, codec, core, validator, url$) {

  function ShareService_Share_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ShareService_Share_Params.prototype.initDefaults_ = function() {
    this.title = null;
    this.text = null;
    this.url = null;
  };
  ShareService_Share_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ShareService_Share_Params.validate = function(messageValidator, offset) {
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


    
    // validate ShareService_Share_Params.title
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ShareService_Share_Params.text
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ShareService_Share_Params.url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ShareService_Share_Params.encodedSize = codec.kStructHeaderSize + 24;

  ShareService_Share_Params.decode = function(decoder) {
    var packed;
    var val = new ShareService_Share_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.title = decoder.decodeStruct(codec.String);
    val.text = decoder.decodeStruct(codec.String);
    val.url = decoder.decodeStructPointer(url$.Url);
    return val;
  };

  ShareService_Share_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ShareService_Share_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.title);
    encoder.encodeStruct(codec.String, val.text);
    encoder.encodeStructPointer(url$.Url, val.url);
  };
  function ShareService_Share_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ShareService_Share_ResponseParams.prototype.initDefaults_ = function() {
    this.error = null;
  };
  ShareService_Share_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ShareService_Share_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate ShareService_Share_ResponseParams.error
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ShareService_Share_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  ShareService_Share_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new ShareService_Share_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.NullableString);
    return val;
  };

  ShareService_Share_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ShareService_Share_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.NullableString, val.error);
  };
  var kShareService_Share_Name = 0;

  function ShareServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ShareService,
                                                   handleOrPtrInfo);
  }

  function ShareServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  ShareServicePtr.prototype.share = function() {
    return ShareServiceProxy.prototype.share
        .apply(this.ptr.getProxy(), arguments);
  };

  ShareServiceProxy.prototype.share = function(title, text, url) {
    var params = new ShareService_Share_Params();
    params.title = title;
    params.text = text;
    params.url = url;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kShareService_Share_Name,
          codec.align(ShareService_Share_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(ShareService_Share_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(ShareService_Share_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function ShareServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  ShareServiceStub.prototype.share = function(title, text, url) {
    return this.delegate_ && this.delegate_.share && this.delegate_.share(title, text, url);
  }

  ShareServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  ShareServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kShareService_Share_Name:
      var params = reader.decodeStruct(ShareService_Share_Params);
      return this.share(params.title, params.text, params.url).then(function(response) {
        var responseParams =
            new ShareService_Share_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kShareService_Share_Name,
            codec.align(ShareService_Share_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(ShareService_Share_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateShareServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kShareService_Share_Name:
        if (message.expectsResponse())
          paramsClass = ShareService_Share_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateShareServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kShareService_Share_Name:
        if (message.isResponse())
          paramsClass = ShareService_Share_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var ShareService = {
    name: 'blink::mojom::ShareService',
    ptrClass: ShareServicePtr,
    proxyClass: ShareServiceProxy,
    stubClass: ShareServiceStub,
    validateRequest: validateShareServiceRequest,
    validateResponse: validateShareServiceResponse,
  };
  ShareServiceStub.prototype.validator = validateShareServiceRequest;
  ShareServiceProxy.prototype.validator = validateShareServiceResponse;

  var exports = {};
  exports.ShareService = ShareService;
  exports.ShareServicePtr = ShareServicePtr;

  return exports;
});
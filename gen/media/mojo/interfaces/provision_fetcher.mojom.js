// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/provision_fetcher.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function ProvisionFetcher_Retrieve_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProvisionFetcher_Retrieve_Params.prototype.initDefaults_ = function() {
    this.default_url = null;
    this.request_data = null;
  };
  ProvisionFetcher_Retrieve_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProvisionFetcher_Retrieve_Params.validate = function(messageValidator, offset) {
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


    
    // validate ProvisionFetcher_Retrieve_Params.default_url
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProvisionFetcher_Retrieve_Params.request_data
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProvisionFetcher_Retrieve_Params.encodedSize = codec.kStructHeaderSize + 16;

  ProvisionFetcher_Retrieve_Params.decode = function(decoder) {
    var packed;
    var val = new ProvisionFetcher_Retrieve_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.default_url = decoder.decodeStruct(codec.String);
    val.request_data = decoder.decodeStruct(codec.String);
    return val;
  };

  ProvisionFetcher_Retrieve_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProvisionFetcher_Retrieve_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.default_url);
    encoder.encodeStruct(codec.String, val.request_data);
  };
  function ProvisionFetcher_Retrieve_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProvisionFetcher_Retrieve_ResponseParams.prototype.initDefaults_ = function() {
    this.result = false;
    this.response = null;
  };
  ProvisionFetcher_Retrieve_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProvisionFetcher_Retrieve_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate ProvisionFetcher_Retrieve_ResponseParams.response
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProvisionFetcher_Retrieve_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  ProvisionFetcher_Retrieve_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new ProvisionFetcher_Retrieve_ResponseParams();
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
    val.response = decoder.decodeStruct(codec.String);
    return val;
  };

  ProvisionFetcher_Retrieve_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProvisionFetcher_Retrieve_ResponseParams.encodedSize);
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
    encoder.encodeStruct(codec.String, val.response);
  };
  var kProvisionFetcher_Retrieve_Name = 0;

  function ProvisionFetcherPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ProvisionFetcher,
                                                   handleOrPtrInfo);
  }

  function ProvisionFetcherProxy(receiver) {
    this.receiver_ = receiver;
  }
  ProvisionFetcherPtr.prototype.retrieve = function() {
    return ProvisionFetcherProxy.prototype.retrieve
        .apply(this.ptr.getProxy(), arguments);
  };

  ProvisionFetcherProxy.prototype.retrieve = function(default_url, request_data) {
    var params = new ProvisionFetcher_Retrieve_Params();
    params.default_url = default_url;
    params.request_data = request_data;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kProvisionFetcher_Retrieve_Name,
          codec.align(ProvisionFetcher_Retrieve_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(ProvisionFetcher_Retrieve_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(ProvisionFetcher_Retrieve_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function ProvisionFetcherStub(delegate) {
    this.delegate_ = delegate;
  }
  ProvisionFetcherStub.prototype.retrieve = function(default_url, request_data) {
    return this.delegate_ && this.delegate_.retrieve && this.delegate_.retrieve(default_url, request_data);
  }

  ProvisionFetcherStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  ProvisionFetcherStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kProvisionFetcher_Retrieve_Name:
      var params = reader.decodeStruct(ProvisionFetcher_Retrieve_Params);
      return this.retrieve(params.default_url, params.request_data).then(function(response) {
        var responseParams =
            new ProvisionFetcher_Retrieve_ResponseParams();
        responseParams.result = response.result;
        responseParams.response = response.response;
        var builder = new codec.MessageWithRequestIDBuilder(
            kProvisionFetcher_Retrieve_Name,
            codec.align(ProvisionFetcher_Retrieve_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(ProvisionFetcher_Retrieve_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateProvisionFetcherRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kProvisionFetcher_Retrieve_Name:
        if (message.expectsResponse())
          paramsClass = ProvisionFetcher_Retrieve_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateProvisionFetcherResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kProvisionFetcher_Retrieve_Name:
        if (message.isResponse())
          paramsClass = ProvisionFetcher_Retrieve_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var ProvisionFetcher = {
    name: 'media::mojom::ProvisionFetcher',
    ptrClass: ProvisionFetcherPtr,
    proxyClass: ProvisionFetcherProxy,
    stubClass: ProvisionFetcherStub,
    validateRequest: validateProvisionFetcherRequest,
    validateResponse: validateProvisionFetcherResponse,
  };
  ProvisionFetcherStub.prototype.validator = validateProvisionFetcherRequest;
  ProvisionFetcherProxy.prototype.validator = validateProvisionFetcherResponse;

  var exports = {};
  exports.ProvisionFetcher = ProvisionFetcher;
  exports.ProvisionFetcherPtr = ProvisionFetcherPtr;

  return exports;
});
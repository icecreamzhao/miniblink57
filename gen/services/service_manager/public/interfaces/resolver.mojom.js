// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/service_manager/public/interfaces/resolver.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "mojo/common/file_path.mojom",
    "services/service_manager/public/interfaces/interface_provider_spec.mojom",
], function(bindings, codec, core, validator, file_path$, interface_provider_spec$) {

  function ResolveResult(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ResolveResult.prototype.initDefaults_ = function() {
    this.name = null;
    this.interface_provider_specs = null;
    this.package_path = null;
  };
  ResolveResult.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ResolveResult.validate = function(messageValidator, offset) {
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


    
    // validate ResolveResult.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ResolveResult.interface_provider_specs
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, false, codec.String, new codec.PointerTo(interface_provider_spec$.InterfaceProviderSpec), false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ResolveResult.package_path
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, file_path$.FilePath, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ResolveResult.encodedSize = codec.kStructHeaderSize + 24;

  ResolveResult.decode = function(decoder) {
    var packed;
    var val = new ResolveResult();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.interface_provider_specs = decoder.decodeMapPointer(codec.String, new codec.PointerTo(interface_provider_spec$.InterfaceProviderSpec));
    val.package_path = decoder.decodeStructPointer(file_path$.FilePath);
    return val;
  };

  ResolveResult.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ResolveResult.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeMapPointer(codec.String, new codec.PointerTo(interface_provider_spec$.InterfaceProviderSpec), val.interface_provider_specs);
    encoder.encodeStructPointer(file_path$.FilePath, val.package_path);
  };
  function Resolver_ResolveServiceName_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Resolver_ResolveServiceName_Params.prototype.initDefaults_ = function() {
    this.service_name = null;
  };
  Resolver_ResolveServiceName_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Resolver_ResolveServiceName_Params.validate = function(messageValidator, offset) {
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


    
    // validate Resolver_ResolveServiceName_Params.service_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Resolver_ResolveServiceName_Params.encodedSize = codec.kStructHeaderSize + 8;

  Resolver_ResolveServiceName_Params.decode = function(decoder) {
    var packed;
    var val = new Resolver_ResolveServiceName_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.service_name = decoder.decodeStruct(codec.String);
    return val;
  };

  Resolver_ResolveServiceName_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Resolver_ResolveServiceName_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.service_name);
  };
  function Resolver_ResolveServiceName_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Resolver_ResolveServiceName_ResponseParams.prototype.initDefaults_ = function() {
    this.result = null;
    this.parent = null;
  };
  Resolver_ResolveServiceName_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Resolver_ResolveServiceName_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Resolver_ResolveServiceName_ResponseParams.result
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ResolveResult, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Resolver_ResolveServiceName_ResponseParams.parent
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, ResolveResult, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Resolver_ResolveServiceName_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Resolver_ResolveServiceName_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Resolver_ResolveServiceName_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStructPointer(ResolveResult);
    val.parent = decoder.decodeStructPointer(ResolveResult);
    return val;
  };

  Resolver_ResolveServiceName_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Resolver_ResolveServiceName_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ResolveResult, val.result);
    encoder.encodeStructPointer(ResolveResult, val.parent);
  };
  var kResolver_ResolveServiceName_Name = 0;

  function ResolverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Resolver,
                                                   handleOrPtrInfo);
  }

  function ResolverProxy(receiver) {
    this.receiver_ = receiver;
  }
  ResolverPtr.prototype.resolveServiceName = function() {
    return ResolverProxy.prototype.resolveServiceName
        .apply(this.ptr.getProxy(), arguments);
  };

  ResolverProxy.prototype.resolveServiceName = function(service_name) {
    var params = new Resolver_ResolveServiceName_Params();
    params.service_name = service_name;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kResolver_ResolveServiceName_Name,
          codec.align(Resolver_ResolveServiceName_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Resolver_ResolveServiceName_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Resolver_ResolveServiceName_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function ResolverStub(delegate) {
    this.delegate_ = delegate;
  }
  ResolverStub.prototype.resolveServiceName = function(service_name) {
    return this.delegate_ && this.delegate_.resolveServiceName && this.delegate_.resolveServiceName(service_name);
  }

  ResolverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  ResolverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kResolver_ResolveServiceName_Name:
      var params = reader.decodeStruct(Resolver_ResolveServiceName_Params);
      return this.resolveServiceName(params.service_name).then(function(response) {
        var responseParams =
            new Resolver_ResolveServiceName_ResponseParams();
        responseParams.result = response.result;
        responseParams.parent = response.parent;
        var builder = new codec.MessageWithRequestIDBuilder(
            kResolver_ResolveServiceName_Name,
            codec.align(Resolver_ResolveServiceName_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Resolver_ResolveServiceName_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateResolverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kResolver_ResolveServiceName_Name:
        if (message.expectsResponse())
          paramsClass = Resolver_ResolveServiceName_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateResolverResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kResolver_ResolveServiceName_Name:
        if (message.isResponse())
          paramsClass = Resolver_ResolveServiceName_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Resolver = {
    name: 'service_manager::mojom::Resolver',
    ptrClass: ResolverPtr,
    proxyClass: ResolverProxy,
    stubClass: ResolverStub,
    validateRequest: validateResolverRequest,
    validateResponse: validateResolverResponse,
  };
  ResolverStub.prototype.validator = validateResolverRequest;
  ResolverProxy.prototype.validator = validateResolverResponse;

  var exports = {};
  exports.ResolveResult = ResolveResult;
  exports.Resolver = Resolver;
  exports.ResolverPtr = ResolverPtr;

  return exports;
});
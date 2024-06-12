// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/budget_service/budget_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "url/mojo/origin.mojom",
], function(bindings, codec, core, validator, origin$) {
  var BudgetOperationType = {};
  BudgetOperationType.SILENT_PUSH = 0;
  BudgetOperationType.INVALID_OPERATION = BudgetOperationType.SILENT_PUSH + 1;

  BudgetOperationType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  BudgetOperationType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var BudgetServiceErrorType = {};
  BudgetServiceErrorType.NONE = 0;
  BudgetServiceErrorType.DATABASE_ERROR = BudgetServiceErrorType.NONE + 1;
  BudgetServiceErrorType.NOT_SUPPORTED = BudgetServiceErrorType.DATABASE_ERROR + 1;

  BudgetServiceErrorType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  BudgetServiceErrorType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function BudgetState(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BudgetState.prototype.initDefaults_ = function() {
    this.budget_at = 0;
    this.time = 0;
  };
  BudgetState.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BudgetState.validate = function(messageValidator, offset) {
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



    return validator.validationError.NONE;
  };

  BudgetState.encodedSize = codec.kStructHeaderSize + 16;

  BudgetState.decode = function(decoder) {
    var packed;
    var val = new BudgetState();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.budget_at = decoder.decodeStruct(codec.Double);
    val.time = decoder.decodeStruct(codec.Double);
    return val;
  };

  BudgetState.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BudgetState.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Double, val.budget_at);
    encoder.encodeStruct(codec.Double, val.time);
  };
  function BudgetService_GetCost_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BudgetService_GetCost_Params.prototype.initDefaults_ = function() {
    this.operation = 0;
  };
  BudgetService_GetCost_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BudgetService_GetCost_Params.validate = function(messageValidator, offset) {
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


    
    // validate BudgetService_GetCost_Params.operation
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, BudgetOperationType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BudgetService_GetCost_Params.encodedSize = codec.kStructHeaderSize + 8;

  BudgetService_GetCost_Params.decode = function(decoder) {
    var packed;
    var val = new BudgetService_GetCost_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.operation = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  BudgetService_GetCost_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BudgetService_GetCost_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.operation);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function BudgetService_GetCost_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BudgetService_GetCost_ResponseParams.prototype.initDefaults_ = function() {
    this.cost = 0;
  };
  BudgetService_GetCost_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BudgetService_GetCost_ResponseParams.validate = function(messageValidator, offset) {
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

  BudgetService_GetCost_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  BudgetService_GetCost_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new BudgetService_GetCost_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.cost = decoder.decodeStruct(codec.Double);
    return val;
  };

  BudgetService_GetCost_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BudgetService_GetCost_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Double, val.cost);
  };
  function BudgetService_GetBudget_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BudgetService_GetBudget_Params.prototype.initDefaults_ = function() {
    this.origin = null;
  };
  BudgetService_GetBudget_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BudgetService_GetBudget_Params.validate = function(messageValidator, offset) {
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


    
    // validate BudgetService_GetBudget_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BudgetService_GetBudget_Params.encodedSize = codec.kStructHeaderSize + 8;

  BudgetService_GetBudget_Params.decode = function(decoder) {
    var packed;
    var val = new BudgetService_GetBudget_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    return val;
  };

  BudgetService_GetBudget_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BudgetService_GetBudget_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
  };
  function BudgetService_GetBudget_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BudgetService_GetBudget_ResponseParams.prototype.initDefaults_ = function() {
    this.error_type = 0;
    this.budget = null;
  };
  BudgetService_GetBudget_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BudgetService_GetBudget_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate BudgetService_GetBudget_ResponseParams.error_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, BudgetServiceErrorType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BudgetService_GetBudget_ResponseParams.budget
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(BudgetState), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BudgetService_GetBudget_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  BudgetService_GetBudget_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new BudgetService_GetBudget_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.budget = decoder.decodeArrayPointer(new codec.PointerTo(BudgetState));
    return val;
  };

  BudgetService_GetBudget_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BudgetService_GetBudget_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(new codec.PointerTo(BudgetState), val.budget);
  };
  function BudgetService_Reserve_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BudgetService_Reserve_Params.prototype.initDefaults_ = function() {
    this.origin = null;
    this.operation = 0;
  };
  BudgetService_Reserve_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BudgetService_Reserve_Params.validate = function(messageValidator, offset) {
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


    
    // validate BudgetService_Reserve_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BudgetService_Reserve_Params.operation
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, BudgetOperationType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BudgetService_Reserve_Params.encodedSize = codec.kStructHeaderSize + 16;

  BudgetService_Reserve_Params.decode = function(decoder) {
    var packed;
    var val = new BudgetService_Reserve_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    val.operation = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  BudgetService_Reserve_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BudgetService_Reserve_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
    encoder.encodeStruct(codec.Int32, val.operation);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function BudgetService_Reserve_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BudgetService_Reserve_ResponseParams.prototype.initDefaults_ = function() {
    this.error_type = 0;
    this.success = false;
  };
  BudgetService_Reserve_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BudgetService_Reserve_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate BudgetService_Reserve_ResponseParams.error_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, BudgetServiceErrorType);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  BudgetService_Reserve_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  BudgetService_Reserve_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new BudgetService_Reserve_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error_type = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  BudgetService_Reserve_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BudgetService_Reserve_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error_type);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kBudgetService_GetCost_Name = 0;
  var kBudgetService_GetBudget_Name = 1;
  var kBudgetService_Reserve_Name = 2;

  function BudgetServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(BudgetService,
                                                   handleOrPtrInfo);
  }

  function BudgetServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  BudgetServicePtr.prototype.getCost = function() {
    return BudgetServiceProxy.prototype.getCost
        .apply(this.ptr.getProxy(), arguments);
  };

  BudgetServiceProxy.prototype.getCost = function(operation) {
    var params = new BudgetService_GetCost_Params();
    params.operation = operation;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kBudgetService_GetCost_Name,
          codec.align(BudgetService_GetCost_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(BudgetService_GetCost_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(BudgetService_GetCost_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  BudgetServicePtr.prototype.getBudget = function() {
    return BudgetServiceProxy.prototype.getBudget
        .apply(this.ptr.getProxy(), arguments);
  };

  BudgetServiceProxy.prototype.getBudget = function(origin) {
    var params = new BudgetService_GetBudget_Params();
    params.origin = origin;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kBudgetService_GetBudget_Name,
          codec.align(BudgetService_GetBudget_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(BudgetService_GetBudget_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(BudgetService_GetBudget_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  BudgetServicePtr.prototype.reserve = function() {
    return BudgetServiceProxy.prototype.reserve
        .apply(this.ptr.getProxy(), arguments);
  };

  BudgetServiceProxy.prototype.reserve = function(origin, operation) {
    var params = new BudgetService_Reserve_Params();
    params.origin = origin;
    params.operation = operation;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kBudgetService_Reserve_Name,
          codec.align(BudgetService_Reserve_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(BudgetService_Reserve_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(BudgetService_Reserve_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function BudgetServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  BudgetServiceStub.prototype.getCost = function(operation) {
    return this.delegate_ && this.delegate_.getCost && this.delegate_.getCost(operation);
  }
  BudgetServiceStub.prototype.getBudget = function(origin) {
    return this.delegate_ && this.delegate_.getBudget && this.delegate_.getBudget(origin);
  }
  BudgetServiceStub.prototype.reserve = function(origin, operation) {
    return this.delegate_ && this.delegate_.reserve && this.delegate_.reserve(origin, operation);
  }

  BudgetServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  BudgetServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kBudgetService_GetCost_Name:
      var params = reader.decodeStruct(BudgetService_GetCost_Params);
      return this.getCost(params.operation).then(function(response) {
        var responseParams =
            new BudgetService_GetCost_ResponseParams();
        responseParams.cost = response.cost;
        var builder = new codec.MessageWithRequestIDBuilder(
            kBudgetService_GetCost_Name,
            codec.align(BudgetService_GetCost_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(BudgetService_GetCost_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kBudgetService_GetBudget_Name:
      var params = reader.decodeStruct(BudgetService_GetBudget_Params);
      return this.getBudget(params.origin).then(function(response) {
        var responseParams =
            new BudgetService_GetBudget_ResponseParams();
        responseParams.error_type = response.error_type;
        responseParams.budget = response.budget;
        var builder = new codec.MessageWithRequestIDBuilder(
            kBudgetService_GetBudget_Name,
            codec.align(BudgetService_GetBudget_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(BudgetService_GetBudget_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kBudgetService_Reserve_Name:
      var params = reader.decodeStruct(BudgetService_Reserve_Params);
      return this.reserve(params.origin, params.operation).then(function(response) {
        var responseParams =
            new BudgetService_Reserve_ResponseParams();
        responseParams.error_type = response.error_type;
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kBudgetService_Reserve_Name,
            codec.align(BudgetService_Reserve_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(BudgetService_Reserve_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateBudgetServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kBudgetService_GetCost_Name:
        if (message.expectsResponse())
          paramsClass = BudgetService_GetCost_Params;
      break;
      case kBudgetService_GetBudget_Name:
        if (message.expectsResponse())
          paramsClass = BudgetService_GetBudget_Params;
      break;
      case kBudgetService_Reserve_Name:
        if (message.expectsResponse())
          paramsClass = BudgetService_Reserve_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateBudgetServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kBudgetService_GetCost_Name:
        if (message.isResponse())
          paramsClass = BudgetService_GetCost_ResponseParams;
        break;
      case kBudgetService_GetBudget_Name:
        if (message.isResponse())
          paramsClass = BudgetService_GetBudget_ResponseParams;
        break;
      case kBudgetService_Reserve_Name:
        if (message.isResponse())
          paramsClass = BudgetService_Reserve_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var BudgetService = {
    name: 'blink::mojom::BudgetService',
    ptrClass: BudgetServicePtr,
    proxyClass: BudgetServiceProxy,
    stubClass: BudgetServiceStub,
    validateRequest: validateBudgetServiceRequest,
    validateResponse: validateBudgetServiceResponse,
  };
  BudgetServiceStub.prototype.validator = validateBudgetServiceRequest;
  BudgetServiceProxy.prototype.validator = validateBudgetServiceResponse;

  var exports = {};
  exports.BudgetOperationType = BudgetOperationType;
  exports.BudgetServiceErrorType = BudgetServiceErrorType;
  exports.BudgetState = BudgetState;
  exports.BudgetService = BudgetService;
  exports.BudgetServicePtr = BudgetServicePtr;

  return exports;
});
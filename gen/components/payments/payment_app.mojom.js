// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/payments/payment_app.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "components/payments/payment_request.mojom",
    "url/mojo/url.mojom",
], function(bindings, codec, core, validator, payment_request$, url$) {
  var PaymentAppManifestError = {};
  PaymentAppManifestError.NONE = 0;
  PaymentAppManifestError.NOT_IMPLEMENTED = PaymentAppManifestError.NONE + 1;
  PaymentAppManifestError.NO_ACTIVE_WORKER = PaymentAppManifestError.NOT_IMPLEMENTED + 1;
  PaymentAppManifestError.MANIFEST_STORAGE_OPERATION_FAILED = PaymentAppManifestError.NO_ACTIVE_WORKER + 1;

  PaymentAppManifestError.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  PaymentAppManifestError.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function PaymentAppOption(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppOption.prototype.initDefaults_ = function() {
    this.name = null;
    this.icon = null;
    this.id = null;
    this.enabled_methods = null;
  };
  PaymentAppOption.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppOption.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 40}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppOption.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppOption.icon
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppOption.id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppOption.enabled_methods
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 24, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAppOption.encodedSize = codec.kStructHeaderSize + 32;

  PaymentAppOption.decode = function(decoder) {
    var packed;
    var val = new PaymentAppOption();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.icon = decoder.decodeStruct(codec.NullableString);
    val.id = decoder.decodeStruct(codec.String);
    val.enabled_methods = decoder.decodeArrayPointer(codec.String);
    return val;
  };

  PaymentAppOption.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppOption.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStruct(codec.NullableString, val.icon);
    encoder.encodeStruct(codec.String, val.id);
    encoder.encodeArrayPointer(codec.String, val.enabled_methods);
  };
  function PaymentAppManifest(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppManifest.prototype.initDefaults_ = function() {
    this.name = null;
    this.icon = null;
    this.options = null;
  };
  PaymentAppManifest.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppManifest.validate = function(messageValidator, offset) {
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


    
    // validate PaymentAppManifest.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppManifest.icon
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppManifest.options
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(PaymentAppOption), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAppManifest.encodedSize = codec.kStructHeaderSize + 24;

  PaymentAppManifest.decode = function(decoder) {
    var packed;
    var val = new PaymentAppManifest();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.icon = decoder.decodeStruct(codec.NullableString);
    val.options = decoder.decodeArrayPointer(new codec.PointerTo(PaymentAppOption));
    return val;
  };

  PaymentAppManifest.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppManifest.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStruct(codec.NullableString, val.icon);
    encoder.encodeArrayPointer(new codec.PointerTo(PaymentAppOption), val.options);
  };
  function PaymentAppRequestData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppRequestData.prototype.initDefaults_ = function() {
    this.origin = null;
    this.methodData = null;
    this.total = null;
    this.modifiers = null;
    this.optionId = null;
  };
  PaymentAppRequestData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppRequestData.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 48}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppRequestData.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppRequestData.methodData
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(payment_request$.PaymentMethodData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppRequestData.total
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, payment_request$.PaymentItem, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppRequestData.modifiers
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 24, 8, new codec.PointerTo(payment_request$.PaymentDetailsModifier), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppRequestData.optionId
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAppRequestData.encodedSize = codec.kStructHeaderSize + 40;

  PaymentAppRequestData.decode = function(decoder) {
    var packed;
    var val = new PaymentAppRequestData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.origin = decoder.decodeStructPointer(url$.Url);
    val.methodData = decoder.decodeArrayPointer(new codec.PointerTo(payment_request$.PaymentMethodData));
    val.total = decoder.decodeStructPointer(payment_request$.PaymentItem);
    val.modifiers = decoder.decodeArrayPointer(new codec.PointerTo(payment_request$.PaymentDetailsModifier));
    val.optionId = decoder.decodeStruct(codec.String);
    return val;
  };

  PaymentAppRequestData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppRequestData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.origin);
    encoder.encodeArrayPointer(new codec.PointerTo(payment_request$.PaymentMethodData), val.methodData);
    encoder.encodeStructPointer(payment_request$.PaymentItem, val.total);
    encoder.encodeArrayPointer(new codec.PointerTo(payment_request$.PaymentDetailsModifier), val.modifiers);
    encoder.encodeStruct(codec.String, val.optionId);
  };
  function PaymentAppManager_Init_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppManager_Init_Params.prototype.initDefaults_ = function() {
    this.service_worker_scope = null;
  };
  PaymentAppManager_Init_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppManager_Init_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentAppManager_Init_Params.service_worker_scope
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAppManager_Init_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentAppManager_Init_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentAppManager_Init_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.service_worker_scope = decoder.decodeStruct(codec.String);
    return val;
  };

  PaymentAppManager_Init_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppManager_Init_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.service_worker_scope);
  };
  function PaymentAppManager_SetManifest_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppManager_SetManifest_Params.prototype.initDefaults_ = function() {
    this.payment_app_manifest = null;
  };
  PaymentAppManager_SetManifest_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppManager_SetManifest_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentAppManager_SetManifest_Params.payment_app_manifest
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PaymentAppManifest, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAppManager_SetManifest_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentAppManager_SetManifest_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentAppManager_SetManifest_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.payment_app_manifest = decoder.decodeStructPointer(PaymentAppManifest);
    return val;
  };

  PaymentAppManager_SetManifest_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppManager_SetManifest_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PaymentAppManifest, val.payment_app_manifest);
  };
  function PaymentAppManager_SetManifest_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppManager_SetManifest_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  PaymentAppManager_SetManifest_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppManager_SetManifest_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PaymentAppManager_SetManifest_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PaymentAppManifestError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAppManager_SetManifest_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PaymentAppManager_SetManifest_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PaymentAppManager_SetManifest_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentAppManager_SetManifest_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppManager_SetManifest_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PaymentAppManager_GetManifest_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppManager_GetManifest_Params.prototype.initDefaults_ = function() {
  };
  PaymentAppManager_GetManifest_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppManager_GetManifest_Params.validate = function(messageValidator, offset) {
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

  PaymentAppManager_GetManifest_Params.encodedSize = codec.kStructHeaderSize + 0;

  PaymentAppManager_GetManifest_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentAppManager_GetManifest_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PaymentAppManager_GetManifest_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppManager_GetManifest_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function PaymentAppManager_GetManifest_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAppManager_GetManifest_ResponseParams.prototype.initDefaults_ = function() {
    this.payment_app_manifest = null;
    this.error = 0;
  };
  PaymentAppManager_GetManifest_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAppManager_GetManifest_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PaymentAppManager_GetManifest_ResponseParams.payment_app_manifest
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PaymentAppManifest, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAppManager_GetManifest_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, PaymentAppManifestError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAppManager_GetManifest_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  PaymentAppManager_GetManifest_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PaymentAppManager_GetManifest_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.payment_app_manifest = decoder.decodeStructPointer(PaymentAppManifest);
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentAppManager_GetManifest_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAppManager_GetManifest_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PaymentAppManifest, val.payment_app_manifest);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kPaymentAppManager_Init_Name = 0;
  var kPaymentAppManager_SetManifest_Name = 1;
  var kPaymentAppManager_GetManifest_Name = 2;

  function PaymentAppManagerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PaymentAppManager,
                                                   handleOrPtrInfo);
  }

  function PaymentAppManagerProxy(receiver) {
    this.receiver_ = receiver;
  }
  PaymentAppManagerPtr.prototype.init = function() {
    return PaymentAppManagerProxy.prototype.init
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentAppManagerProxy.prototype.init = function(service_worker_scope) {
    var params = new PaymentAppManager_Init_Params();
    params.service_worker_scope = service_worker_scope;
    var builder = new codec.MessageBuilder(
        kPaymentAppManager_Init_Name,
        codec.align(PaymentAppManager_Init_Params.encodedSize));
    builder.encodeStruct(PaymentAppManager_Init_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentAppManagerPtr.prototype.setManifest = function() {
    return PaymentAppManagerProxy.prototype.setManifest
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentAppManagerProxy.prototype.setManifest = function(payment_app_manifest) {
    var params = new PaymentAppManager_SetManifest_Params();
    params.payment_app_manifest = payment_app_manifest;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPaymentAppManager_SetManifest_Name,
          codec.align(PaymentAppManager_SetManifest_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PaymentAppManager_SetManifest_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PaymentAppManager_SetManifest_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PaymentAppManagerPtr.prototype.getManifest = function() {
    return PaymentAppManagerProxy.prototype.getManifest
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentAppManagerProxy.prototype.getManifest = function() {
    var params = new PaymentAppManager_GetManifest_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPaymentAppManager_GetManifest_Name,
          codec.align(PaymentAppManager_GetManifest_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PaymentAppManager_GetManifest_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PaymentAppManager_GetManifest_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function PaymentAppManagerStub(delegate) {
    this.delegate_ = delegate;
  }
  PaymentAppManagerStub.prototype.init = function(service_worker_scope) {
    return this.delegate_ && this.delegate_.init && this.delegate_.init(service_worker_scope);
  }
  PaymentAppManagerStub.prototype.setManifest = function(payment_app_manifest) {
    return this.delegate_ && this.delegate_.setManifest && this.delegate_.setManifest(payment_app_manifest);
  }
  PaymentAppManagerStub.prototype.getManifest = function() {
    return this.delegate_ && this.delegate_.getManifest && this.delegate_.getManifest();
  }

  PaymentAppManagerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPaymentAppManager_Init_Name:
      var params = reader.decodeStruct(PaymentAppManager_Init_Params);
      this.init(params.service_worker_scope);
      return true;
    default:
      return false;
    }
  };

  PaymentAppManagerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPaymentAppManager_SetManifest_Name:
      var params = reader.decodeStruct(PaymentAppManager_SetManifest_Params);
      return this.setManifest(params.payment_app_manifest).then(function(response) {
        var responseParams =
            new PaymentAppManager_SetManifest_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPaymentAppManager_SetManifest_Name,
            codec.align(PaymentAppManager_SetManifest_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PaymentAppManager_SetManifest_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kPaymentAppManager_GetManifest_Name:
      var params = reader.decodeStruct(PaymentAppManager_GetManifest_Params);
      return this.getManifest().then(function(response) {
        var responseParams =
            new PaymentAppManager_GetManifest_ResponseParams();
        responseParams.payment_app_manifest = response.payment_app_manifest;
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPaymentAppManager_GetManifest_Name,
            codec.align(PaymentAppManager_GetManifest_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PaymentAppManager_GetManifest_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePaymentAppManagerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPaymentAppManager_Init_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentAppManager_Init_Params;
      break;
      case kPaymentAppManager_SetManifest_Name:
        if (message.expectsResponse())
          paramsClass = PaymentAppManager_SetManifest_Params;
      break;
      case kPaymentAppManager_GetManifest_Name:
        if (message.expectsResponse())
          paramsClass = PaymentAppManager_GetManifest_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePaymentAppManagerResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kPaymentAppManager_SetManifest_Name:
        if (message.isResponse())
          paramsClass = PaymentAppManager_SetManifest_ResponseParams;
        break;
      case kPaymentAppManager_GetManifest_Name:
        if (message.isResponse())
          paramsClass = PaymentAppManager_GetManifest_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var PaymentAppManager = {
    name: 'payments::mojom::PaymentAppManager',
    ptrClass: PaymentAppManagerPtr,
    proxyClass: PaymentAppManagerProxy,
    stubClass: PaymentAppManagerStub,
    validateRequest: validatePaymentAppManagerRequest,
    validateResponse: validatePaymentAppManagerResponse,
  };
  PaymentAppManagerStub.prototype.validator = validatePaymentAppManagerRequest;
  PaymentAppManagerProxy.prototype.validator = validatePaymentAppManagerResponse;

  var exports = {};
  exports.PaymentAppManifestError = PaymentAppManifestError;
  exports.PaymentAppOption = PaymentAppOption;
  exports.PaymentAppManifest = PaymentAppManifest;
  exports.PaymentAppRequestData = PaymentAppRequestData;
  exports.PaymentAppManager = PaymentAppManager;
  exports.PaymentAppManagerPtr = PaymentAppManagerPtr;

  return exports;
});
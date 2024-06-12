// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/output_protection.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function OutputProtection_QueryStatus_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OutputProtection_QueryStatus_Params.prototype.initDefaults_ = function() {
  };
  OutputProtection_QueryStatus_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OutputProtection_QueryStatus_Params.validate = function(messageValidator, offset) {
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

  OutputProtection_QueryStatus_Params.encodedSize = codec.kStructHeaderSize + 0;

  OutputProtection_QueryStatus_Params.decode = function(decoder) {
    var packed;
    var val = new OutputProtection_QueryStatus_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  OutputProtection_QueryStatus_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OutputProtection_QueryStatus_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function OutputProtection_QueryStatus_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OutputProtection_QueryStatus_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
    this.link_mask = 0;
    this.protection_mask = 0;
  };
  OutputProtection_QueryStatus_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OutputProtection_QueryStatus_ResponseParams.validate = function(messageValidator, offset) {
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

  OutputProtection_QueryStatus_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  OutputProtection_QueryStatus_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new OutputProtection_QueryStatus_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.link_mask = decoder.decodeStruct(codec.Uint32);
    val.protection_mask = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  OutputProtection_QueryStatus_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OutputProtection_QueryStatus_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.link_mask);
    encoder.encodeStruct(codec.Uint32, val.protection_mask);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function OutputProtection_EnableProtection_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OutputProtection_EnableProtection_Params.prototype.initDefaults_ = function() {
    this.desired_protection_mask = 0;
  };
  OutputProtection_EnableProtection_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OutputProtection_EnableProtection_Params.validate = function(messageValidator, offset) {
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

  OutputProtection_EnableProtection_Params.encodedSize = codec.kStructHeaderSize + 8;

  OutputProtection_EnableProtection_Params.decode = function(decoder) {
    var packed;
    var val = new OutputProtection_EnableProtection_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.desired_protection_mask = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  OutputProtection_EnableProtection_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OutputProtection_EnableProtection_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.desired_protection_mask);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function OutputProtection_EnableProtection_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OutputProtection_EnableProtection_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  OutputProtection_EnableProtection_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OutputProtection_EnableProtection_ResponseParams.validate = function(messageValidator, offset) {
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

  OutputProtection_EnableProtection_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  OutputProtection_EnableProtection_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new OutputProtection_EnableProtection_ResponseParams();
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

  OutputProtection_EnableProtection_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OutputProtection_EnableProtection_ResponseParams.encodedSize);
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
  var kOutputProtection_QueryStatus_Name = 0;
  var kOutputProtection_EnableProtection_Name = 1;

  function OutputProtectionPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(OutputProtection,
                                                   handleOrPtrInfo);
  }

  function OutputProtectionProxy(receiver) {
    this.receiver_ = receiver;
  }
  OutputProtectionPtr.prototype.queryStatus = function() {
    return OutputProtectionProxy.prototype.queryStatus
        .apply(this.ptr.getProxy(), arguments);
  };

  OutputProtectionProxy.prototype.queryStatus = function() {
    var params = new OutputProtection_QueryStatus_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kOutputProtection_QueryStatus_Name,
          codec.align(OutputProtection_QueryStatus_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(OutputProtection_QueryStatus_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(OutputProtection_QueryStatus_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  OutputProtectionPtr.prototype.enableProtection = function() {
    return OutputProtectionProxy.prototype.enableProtection
        .apply(this.ptr.getProxy(), arguments);
  };

  OutputProtectionProxy.prototype.enableProtection = function(desired_protection_mask) {
    var params = new OutputProtection_EnableProtection_Params();
    params.desired_protection_mask = desired_protection_mask;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kOutputProtection_EnableProtection_Name,
          codec.align(OutputProtection_EnableProtection_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(OutputProtection_EnableProtection_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(OutputProtection_EnableProtection_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function OutputProtectionStub(delegate) {
    this.delegate_ = delegate;
  }
  OutputProtectionStub.prototype.queryStatus = function() {
    return this.delegate_ && this.delegate_.queryStatus && this.delegate_.queryStatus();
  }
  OutputProtectionStub.prototype.enableProtection = function(desired_protection_mask) {
    return this.delegate_ && this.delegate_.enableProtection && this.delegate_.enableProtection(desired_protection_mask);
  }

  OutputProtectionStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  OutputProtectionStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kOutputProtection_QueryStatus_Name:
      var params = reader.decodeStruct(OutputProtection_QueryStatus_Params);
      return this.queryStatus().then(function(response) {
        var responseParams =
            new OutputProtection_QueryStatus_ResponseParams();
        responseParams.success = response.success;
        responseParams.link_mask = response.link_mask;
        responseParams.protection_mask = response.protection_mask;
        var builder = new codec.MessageWithRequestIDBuilder(
            kOutputProtection_QueryStatus_Name,
            codec.align(OutputProtection_QueryStatus_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(OutputProtection_QueryStatus_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kOutputProtection_EnableProtection_Name:
      var params = reader.decodeStruct(OutputProtection_EnableProtection_Params);
      return this.enableProtection(params.desired_protection_mask).then(function(response) {
        var responseParams =
            new OutputProtection_EnableProtection_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kOutputProtection_EnableProtection_Name,
            codec.align(OutputProtection_EnableProtection_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(OutputProtection_EnableProtection_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateOutputProtectionRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kOutputProtection_QueryStatus_Name:
        if (message.expectsResponse())
          paramsClass = OutputProtection_QueryStatus_Params;
      break;
      case kOutputProtection_EnableProtection_Name:
        if (message.expectsResponse())
          paramsClass = OutputProtection_EnableProtection_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateOutputProtectionResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kOutputProtection_QueryStatus_Name:
        if (message.isResponse())
          paramsClass = OutputProtection_QueryStatus_ResponseParams;
        break;
      case kOutputProtection_EnableProtection_Name:
        if (message.isResponse())
          paramsClass = OutputProtection_EnableProtection_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var OutputProtection = {
    name: 'media::mojom::OutputProtection',
    ptrClass: OutputProtectionPtr,
    proxyClass: OutputProtectionProxy,
    stubClass: OutputProtectionStub,
    validateRequest: validateOutputProtectionRequest,
    validateResponse: validateOutputProtectionResponse,
  };
  OutputProtection.ProtectionType = {};
  OutputProtection.ProtectionType.NONE = 0;
  OutputProtection.ProtectionType.HDCP = 1;

  OutputProtection.ProtectionType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  OutputProtection.ProtectionType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  OutputProtection.LinkType = {};
  OutputProtection.LinkType.NONE = 0;
  OutputProtection.LinkType.UNKNOWN = 1;
  OutputProtection.LinkType.INTERNAL = 2;
  OutputProtection.LinkType.VGA = 4;
  OutputProtection.LinkType.HDMI = 8;
  OutputProtection.LinkType.DVI = 16;
  OutputProtection.LinkType.DISPLAYPORT = 32;
  OutputProtection.LinkType.NETWORK = 64;

  OutputProtection.LinkType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 8:
    case 16:
    case 32:
    case 64:
      return true;
    }
    return false;
  };

  OutputProtection.LinkType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  OutputProtectionStub.prototype.validator = validateOutputProtectionRequest;
  OutputProtectionProxy.prototype.validator = validateOutputProtectionResponse;

  var exports = {};
  exports.OutputProtection = OutputProtection;
  exports.OutputProtectionPtr = OutputProtectionPtr;

  return exports;
});
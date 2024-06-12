// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/site_engagement.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "url/mojo/origin.mojom",
], function(bindings, codec, core, validator, origin$) {
  var EngagementLevel = {};
  EngagementLevel.NONE = 0;
  EngagementLevel.MINIMAL = EngagementLevel.NONE + 1;
  EngagementLevel.LOW = EngagementLevel.MINIMAL + 1;
  EngagementLevel.MEDIUM = EngagementLevel.LOW + 1;
  EngagementLevel.HIGH = EngagementLevel.MEDIUM + 1;
  EngagementLevel.MAX = EngagementLevel.HIGH + 1;

  EngagementLevel.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    }
    return false;
  };

  EngagementLevel.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function EngagementClient_SetEngagementLevel_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  EngagementClient_SetEngagementLevel_Params.prototype.initDefaults_ = function() {
    this.origin = null;
    this.level = 0;
  };
  EngagementClient_SetEngagementLevel_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  EngagementClient_SetEngagementLevel_Params.validate = function(messageValidator, offset) {
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


    
    // validate EngagementClient_SetEngagementLevel_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EngagementClient_SetEngagementLevel_Params.level
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, EngagementLevel);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  EngagementClient_SetEngagementLevel_Params.encodedSize = codec.kStructHeaderSize + 16;

  EngagementClient_SetEngagementLevel_Params.decode = function(decoder) {
    var packed;
    var val = new EngagementClient_SetEngagementLevel_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    val.level = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  EngagementClient_SetEngagementLevel_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(EngagementClient_SetEngagementLevel_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
    encoder.encodeStruct(codec.Int32, val.level);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kEngagementClient_SetEngagementLevel_Name = 0;

  function EngagementClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(EngagementClient,
                                                   handleOrPtrInfo);
  }

  function EngagementClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  EngagementClientPtr.prototype.setEngagementLevel = function() {
    return EngagementClientProxy.prototype.setEngagementLevel
        .apply(this.ptr.getProxy(), arguments);
  };

  EngagementClientProxy.prototype.setEngagementLevel = function(origin, level) {
    var params = new EngagementClient_SetEngagementLevel_Params();
    params.origin = origin;
    params.level = level;
    var builder = new codec.MessageBuilder(
        kEngagementClient_SetEngagementLevel_Name,
        codec.align(EngagementClient_SetEngagementLevel_Params.encodedSize));
    builder.encodeStruct(EngagementClient_SetEngagementLevel_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function EngagementClientStub(delegate) {
    this.delegate_ = delegate;
  }
  EngagementClientStub.prototype.setEngagementLevel = function(origin, level) {
    return this.delegate_ && this.delegate_.setEngagementLevel && this.delegate_.setEngagementLevel(origin, level);
  }

  EngagementClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kEngagementClient_SetEngagementLevel_Name:
      var params = reader.decodeStruct(EngagementClient_SetEngagementLevel_Params);
      this.setEngagementLevel(params.origin, params.level);
      return true;
    default:
      return false;
    }
  };

  EngagementClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateEngagementClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kEngagementClient_SetEngagementLevel_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = EngagementClient_SetEngagementLevel_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateEngagementClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var EngagementClient = {
    name: 'blink::mojom::EngagementClient',
    ptrClass: EngagementClientPtr,
    proxyClass: EngagementClientProxy,
    stubClass: EngagementClientStub,
    validateRequest: validateEngagementClientRequest,
    validateResponse: null,
  };
  EngagementClientStub.prototype.validator = validateEngagementClientRequest;
  EngagementClientProxy.prototype.validator = null;

  var exports = {};
  exports.EngagementLevel = EngagementLevel;
  exports.EngagementClient = EngagementClient;
  exports.EngagementClientPtr = EngagementClientPtr;

  return exports;
});
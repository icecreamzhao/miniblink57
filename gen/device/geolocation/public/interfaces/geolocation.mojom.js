// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/geolocation/public/interfaces/geolocation.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Geoposition(values) {
    this.initDefaults_();
    this.initFields_(values);
  }

  Geoposition.ErrorCode = {};
  Geoposition.ErrorCode.NONE = 0;
  Geoposition.ErrorCode.PERMISSION_DENIED = 1;
  Geoposition.ErrorCode.POSITION_UNAVAILABLE = 2;
  Geoposition.ErrorCode.TIMEOUT = 3;
  Geoposition.ErrorCode.LAST = Geoposition.ErrorCode.TIMEOUT;

  Geoposition.ErrorCode.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  Geoposition.ErrorCode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  Geoposition.prototype.initDefaults_ = function() {
    this.valid = false;
    this.error_code = 0;
    this.latitude = 0;
    this.longitude = 0;
    this.altitude = 0;
    this.accuracy = 0;
    this.altitude_accuracy = 0;
    this.heading = 0;
    this.speed = 0;
    this.timestamp = 0;
    this.error_message = null;
  };
  Geoposition.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Geoposition.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 88}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;











    
    // validate Geoposition.error_code
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, Geoposition.ErrorCode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Geoposition.error_message
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 72, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Geoposition.encodedSize = codec.kStructHeaderSize + 80;

  Geoposition.decode = function(decoder) {
    var packed;
    var val = new Geoposition();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.valid = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.error_code = decoder.decodeStruct(codec.Int32);
    val.latitude = decoder.decodeStruct(codec.Double);
    val.longitude = decoder.decodeStruct(codec.Double);
    val.altitude = decoder.decodeStruct(codec.Double);
    val.accuracy = decoder.decodeStruct(codec.Double);
    val.altitude_accuracy = decoder.decodeStruct(codec.Double);
    val.heading = decoder.decodeStruct(codec.Double);
    val.speed = decoder.decodeStruct(codec.Double);
    val.timestamp = decoder.decodeStruct(codec.Double);
    val.error_message = decoder.decodeStruct(codec.String);
    return val;
  };

  Geoposition.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Geoposition.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.valid & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.error_code);
    encoder.encodeStruct(codec.Double, val.latitude);
    encoder.encodeStruct(codec.Double, val.longitude);
    encoder.encodeStruct(codec.Double, val.altitude);
    encoder.encodeStruct(codec.Double, val.accuracy);
    encoder.encodeStruct(codec.Double, val.altitude_accuracy);
    encoder.encodeStruct(codec.Double, val.heading);
    encoder.encodeStruct(codec.Double, val.speed);
    encoder.encodeStruct(codec.Double, val.timestamp);
    encoder.encodeStruct(codec.String, val.error_message);
  };
  function GeolocationService_SetHighAccuracy_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GeolocationService_SetHighAccuracy_Params.prototype.initDefaults_ = function() {
    this.high_accuracy = false;
  };
  GeolocationService_SetHighAccuracy_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GeolocationService_SetHighAccuracy_Params.validate = function(messageValidator, offset) {
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

  GeolocationService_SetHighAccuracy_Params.encodedSize = codec.kStructHeaderSize + 8;

  GeolocationService_SetHighAccuracy_Params.decode = function(decoder) {
    var packed;
    var val = new GeolocationService_SetHighAccuracy_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.high_accuracy = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  GeolocationService_SetHighAccuracy_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GeolocationService_SetHighAccuracy_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.high_accuracy & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GeolocationService_QueryNextPosition_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GeolocationService_QueryNextPosition_Params.prototype.initDefaults_ = function() {
  };
  GeolocationService_QueryNextPosition_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GeolocationService_QueryNextPosition_Params.validate = function(messageValidator, offset) {
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

  GeolocationService_QueryNextPosition_Params.encodedSize = codec.kStructHeaderSize + 0;

  GeolocationService_QueryNextPosition_Params.decode = function(decoder) {
    var packed;
    var val = new GeolocationService_QueryNextPosition_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  GeolocationService_QueryNextPosition_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GeolocationService_QueryNextPosition_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function GeolocationService_QueryNextPosition_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GeolocationService_QueryNextPosition_ResponseParams.prototype.initDefaults_ = function() {
    this.geoposition = null;
  };
  GeolocationService_QueryNextPosition_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GeolocationService_QueryNextPosition_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate GeolocationService_QueryNextPosition_ResponseParams.geoposition
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, Geoposition, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GeolocationService_QueryNextPosition_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  GeolocationService_QueryNextPosition_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new GeolocationService_QueryNextPosition_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.geoposition = decoder.decodeStructPointer(Geoposition);
    return val;
  };

  GeolocationService_QueryNextPosition_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GeolocationService_QueryNextPosition_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(Geoposition, val.geoposition);
  };
  var kGeolocationService_SetHighAccuracy_Name = 0;
  var kGeolocationService_QueryNextPosition_Name = 1;

  function GeolocationServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(GeolocationService,
                                                   handleOrPtrInfo);
  }

  function GeolocationServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  GeolocationServicePtr.prototype.setHighAccuracy = function() {
    return GeolocationServiceProxy.prototype.setHighAccuracy
        .apply(this.ptr.getProxy(), arguments);
  };

  GeolocationServiceProxy.prototype.setHighAccuracy = function(high_accuracy) {
    var params = new GeolocationService_SetHighAccuracy_Params();
    params.high_accuracy = high_accuracy;
    var builder = new codec.MessageBuilder(
        kGeolocationService_SetHighAccuracy_Name,
        codec.align(GeolocationService_SetHighAccuracy_Params.encodedSize));
    builder.encodeStruct(GeolocationService_SetHighAccuracy_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  GeolocationServicePtr.prototype.queryNextPosition = function() {
    return GeolocationServiceProxy.prototype.queryNextPosition
        .apply(this.ptr.getProxy(), arguments);
  };

  GeolocationServiceProxy.prototype.queryNextPosition = function() {
    var params = new GeolocationService_QueryNextPosition_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kGeolocationService_QueryNextPosition_Name,
          codec.align(GeolocationService_QueryNextPosition_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(GeolocationService_QueryNextPosition_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(GeolocationService_QueryNextPosition_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function GeolocationServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  GeolocationServiceStub.prototype.setHighAccuracy = function(high_accuracy) {
    return this.delegate_ && this.delegate_.setHighAccuracy && this.delegate_.setHighAccuracy(high_accuracy);
  }
  GeolocationServiceStub.prototype.queryNextPosition = function() {
    return this.delegate_ && this.delegate_.queryNextPosition && this.delegate_.queryNextPosition();
  }

  GeolocationServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGeolocationService_SetHighAccuracy_Name:
      var params = reader.decodeStruct(GeolocationService_SetHighAccuracy_Params);
      this.setHighAccuracy(params.high_accuracy);
      return true;
    default:
      return false;
    }
  };

  GeolocationServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kGeolocationService_QueryNextPosition_Name:
      var params = reader.decodeStruct(GeolocationService_QueryNextPosition_Params);
      return this.queryNextPosition().then(function(response) {
        var responseParams =
            new GeolocationService_QueryNextPosition_ResponseParams();
        responseParams.geoposition = response.geoposition;
        var builder = new codec.MessageWithRequestIDBuilder(
            kGeolocationService_QueryNextPosition_Name,
            codec.align(GeolocationService_QueryNextPosition_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(GeolocationService_QueryNextPosition_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateGeolocationServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kGeolocationService_SetHighAccuracy_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = GeolocationService_SetHighAccuracy_Params;
      break;
      case kGeolocationService_QueryNextPosition_Name:
        if (message.expectsResponse())
          paramsClass = GeolocationService_QueryNextPosition_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateGeolocationServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kGeolocationService_QueryNextPosition_Name:
        if (message.isResponse())
          paramsClass = GeolocationService_QueryNextPosition_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var GeolocationService = {
    name: 'device::mojom::GeolocationService',
    ptrClass: GeolocationServicePtr,
    proxyClass: GeolocationServiceProxy,
    stubClass: GeolocationServiceStub,
    validateRequest: validateGeolocationServiceRequest,
    validateResponse: validateGeolocationServiceResponse,
  };
  GeolocationServiceStub.prototype.validator = validateGeolocationServiceRequest;
  GeolocationServiceProxy.prototype.validator = validateGeolocationServiceResponse;

  var exports = {};
  exports.Geoposition = Geoposition;
  exports.GeolocationService = GeolocationService;
  exports.GeolocationServicePtr = GeolocationServicePtr;

  return exports;
});
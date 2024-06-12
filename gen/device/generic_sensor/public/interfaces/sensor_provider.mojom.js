// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/generic_sensor/public/interfaces/sensor_provider.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "device/generic_sensor/public/interfaces/sensor.mojom",
], function(bindings, codec, core, validator, sensor$) {

  function SensorInitParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SensorInitParams.kReadBufferSizeForTests = 40;
  SensorInitParams.prototype.initDefaults_ = function() {
    this.memory = null;
    this.mode = 0;
    this.buffer_offset = 0;
    this.default_configuration = null;
    this.maximum_frequency = 0;
  };
  SensorInitParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SensorInitParams.validate = function(messageValidator, offset) {
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


    
    // validate SensorInitParams.memory
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate SensorInitParams.mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, sensor$.ReportingMode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SensorInitParams.default_configuration
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, sensor$.SensorConfiguration, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  SensorInitParams.encodedSize = codec.kStructHeaderSize + 32;

  SensorInitParams.decode = function(decoder) {
    var packed;
    var val = new SensorInitParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.memory = decoder.decodeStruct(codec.Handle);
    val.mode = decoder.decodeStruct(codec.Int32);
    val.buffer_offset = decoder.decodeStruct(codec.Uint64);
    val.default_configuration = decoder.decodeStructPointer(sensor$.SensorConfiguration);
    val.maximum_frequency = decoder.decodeStruct(codec.Double);
    return val;
  };

  SensorInitParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SensorInitParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.memory);
    encoder.encodeStruct(codec.Int32, val.mode);
    encoder.encodeStruct(codec.Uint64, val.buffer_offset);
    encoder.encodeStructPointer(sensor$.SensorConfiguration, val.default_configuration);
    encoder.encodeStruct(codec.Double, val.maximum_frequency);
  };
  function SensorProvider_GetSensor_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SensorProvider_GetSensor_Params.prototype.initDefaults_ = function() {
    this.type = 0;
    this.sensor_request = new bindings.InterfaceRequest();
  };
  SensorProvider_GetSensor_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SensorProvider_GetSensor_Params.validate = function(messageValidator, offset) {
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


    
    // validate SensorProvider_GetSensor_Params.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, sensor$.SensorType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SensorProvider_GetSensor_Params.sensor_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 4, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  SensorProvider_GetSensor_Params.encodedSize = codec.kStructHeaderSize + 8;

  SensorProvider_GetSensor_Params.decode = function(decoder) {
    var packed;
    var val = new SensorProvider_GetSensor_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    val.sensor_request = decoder.decodeStruct(codec.InterfaceRequest);
    return val;
  };

  SensorProvider_GetSensor_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SensorProvider_GetSensor_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.encodeStruct(codec.InterfaceRequest, val.sensor_request);
  };
  function SensorProvider_GetSensor_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SensorProvider_GetSensor_ResponseParams.prototype.initDefaults_ = function() {
    this.init_params = null;
    this.client_request = new bindings.InterfaceRequest();
  };
  SensorProvider_GetSensor_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SensorProvider_GetSensor_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate SensorProvider_GetSensor_ResponseParams.init_params
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, SensorInitParams, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SensorProvider_GetSensor_ResponseParams.client_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  SensorProvider_GetSensor_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  SensorProvider_GetSensor_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new SensorProvider_GetSensor_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.init_params = decoder.decodeStructPointer(SensorInitParams);
    val.client_request = decoder.decodeStruct(codec.NullableInterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  SensorProvider_GetSensor_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SensorProvider_GetSensor_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(SensorInitParams, val.init_params);
    encoder.encodeStruct(codec.NullableInterfaceRequest, val.client_request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kSensorProvider_GetSensor_Name = 0;

  function SensorProviderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(SensorProvider,
                                                   handleOrPtrInfo);
  }

  function SensorProviderProxy(receiver) {
    this.receiver_ = receiver;
  }
  SensorProviderPtr.prototype.getSensor = function() {
    return SensorProviderProxy.prototype.getSensor
        .apply(this.ptr.getProxy(), arguments);
  };

  SensorProviderProxy.prototype.getSensor = function(type, sensor_request) {
    var params = new SensorProvider_GetSensor_Params();
    params.type = type;
    params.sensor_request = sensor_request;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kSensorProvider_GetSensor_Name,
          codec.align(SensorProvider_GetSensor_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(SensorProvider_GetSensor_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(SensorProvider_GetSensor_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function SensorProviderStub(delegate) {
    this.delegate_ = delegate;
  }
  SensorProviderStub.prototype.getSensor = function(type, sensor_request) {
    return this.delegate_ && this.delegate_.getSensor && this.delegate_.getSensor(type, sensor_request);
  }

  SensorProviderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  SensorProviderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kSensorProvider_GetSensor_Name:
      var params = reader.decodeStruct(SensorProvider_GetSensor_Params);
      return this.getSensor(params.type, params.sensor_request).then(function(response) {
        var responseParams =
            new SensorProvider_GetSensor_ResponseParams();
        responseParams.init_params = response.init_params;
        responseParams.client_request = response.client_request;
        var builder = new codec.MessageWithRequestIDBuilder(
            kSensorProvider_GetSensor_Name,
            codec.align(SensorProvider_GetSensor_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(SensorProvider_GetSensor_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateSensorProviderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kSensorProvider_GetSensor_Name:
        if (message.expectsResponse())
          paramsClass = SensorProvider_GetSensor_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateSensorProviderResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kSensorProvider_GetSensor_Name:
        if (message.isResponse())
          paramsClass = SensorProvider_GetSensor_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var SensorProvider = {
    name: 'device::mojom::SensorProvider',
    ptrClass: SensorProviderPtr,
    proxyClass: SensorProviderProxy,
    stubClass: SensorProviderStub,
    validateRequest: validateSensorProviderRequest,
    validateResponse: validateSensorProviderResponse,
  };
  SensorProviderStub.prototype.validator = validateSensorProviderRequest;
  SensorProviderProxy.prototype.validator = validateSensorProviderResponse;

  var exports = {};
  exports.SensorInitParams = SensorInitParams;
  exports.SensorProvider = SensorProvider;
  exports.SensorProviderPtr = SensorProviderPtr;

  return exports;
});
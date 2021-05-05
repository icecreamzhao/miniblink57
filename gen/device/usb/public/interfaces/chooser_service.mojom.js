// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/usb/public/interfaces/chooser_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "device/usb/public/interfaces/device.mojom",
    "device/usb/public/interfaces/device_manager.mojom",
], function(bindings, codec, core, validator, device$, device_manager$) {

  function ChooserService_GetPermission_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ChooserService_GetPermission_Params.prototype.initDefaults_ = function() {
    this.device_filters = null;
  };
  ChooserService_GetPermission_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ChooserService_GetPermission_Params.validate = function(messageValidator, offset) {
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


    
    // validate ChooserService_GetPermission_Params.device_filters
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(device_manager$.DeviceFilter), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ChooserService_GetPermission_Params.encodedSize = codec.kStructHeaderSize + 8;

  ChooserService_GetPermission_Params.decode = function(decoder) {
    var packed;
    var val = new ChooserService_GetPermission_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.device_filters = decoder.decodeArrayPointer(new codec.PointerTo(device_manager$.DeviceFilter));
    return val;
  };

  ChooserService_GetPermission_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ChooserService_GetPermission_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(device_manager$.DeviceFilter), val.device_filters);
  };
  function ChooserService_GetPermission_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ChooserService_GetPermission_ResponseParams.prototype.initDefaults_ = function() {
    this.result = null;
  };
  ChooserService_GetPermission_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ChooserService_GetPermission_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate ChooserService_GetPermission_ResponseParams.result
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, device$.DeviceInfo, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ChooserService_GetPermission_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  ChooserService_GetPermission_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new ChooserService_GetPermission_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStructPointer(device$.DeviceInfo);
    return val;
  };

  ChooserService_GetPermission_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ChooserService_GetPermission_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(device$.DeviceInfo, val.result);
  };
  var kChooserService_GetPermission_Name = 0;

  function ChooserServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ChooserService,
                                                   handleOrPtrInfo);
  }

  function ChooserServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  ChooserServicePtr.prototype.getPermission = function() {
    return ChooserServiceProxy.prototype.getPermission
        .apply(this.ptr.getProxy(), arguments);
  };

  ChooserServiceProxy.prototype.getPermission = function(device_filters) {
    var params = new ChooserService_GetPermission_Params();
    params.device_filters = device_filters;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kChooserService_GetPermission_Name,
          codec.align(ChooserService_GetPermission_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(ChooserService_GetPermission_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(ChooserService_GetPermission_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function ChooserServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  ChooserServiceStub.prototype.getPermission = function(device_filters) {
    return this.delegate_ && this.delegate_.getPermission && this.delegate_.getPermission(device_filters);
  }

  ChooserServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  ChooserServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kChooserService_GetPermission_Name:
      var params = reader.decodeStruct(ChooserService_GetPermission_Params);
      return this.getPermission(params.device_filters).then(function(response) {
        var responseParams =
            new ChooserService_GetPermission_ResponseParams();
        responseParams.result = response.result;
        var builder = new codec.MessageWithRequestIDBuilder(
            kChooserService_GetPermission_Name,
            codec.align(ChooserService_GetPermission_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(ChooserService_GetPermission_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateChooserServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kChooserService_GetPermission_Name:
        if (message.expectsResponse())
          paramsClass = ChooserService_GetPermission_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateChooserServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kChooserService_GetPermission_Name:
        if (message.isResponse())
          paramsClass = ChooserService_GetPermission_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var ChooserService = {
    name: 'device::usb::ChooserService',
    ptrClass: ChooserServicePtr,
    proxyClass: ChooserServiceProxy,
    stubClass: ChooserServiceStub,
    validateRequest: validateChooserServiceRequest,
    validateResponse: validateChooserServiceResponse,
  };
  ChooserServiceStub.prototype.validator = validateChooserServiceRequest;
  ChooserServiceProxy.prototype.validator = validateChooserServiceResponse;

  var exports = {};
  exports.ChooserService = ChooserService;
  exports.ChooserServicePtr = ChooserServicePtr;

  return exports;
});
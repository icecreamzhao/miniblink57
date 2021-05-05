// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/notifications/notification_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom",
], function(bindings, codec, core, validator, permission_status$) {

  function NotificationService_GetPermissionStatus_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NotificationService_GetPermissionStatus_Params.prototype.initDefaults_ = function() {
    this.origin = null;
  };
  NotificationService_GetPermissionStatus_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NotificationService_GetPermissionStatus_Params.validate = function(messageValidator, offset) {
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


    
    // validate NotificationService_GetPermissionStatus_Params.origin
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NotificationService_GetPermissionStatus_Params.encodedSize = codec.kStructHeaderSize + 8;

  NotificationService_GetPermissionStatus_Params.decode = function(decoder) {
    var packed;
    var val = new NotificationService_GetPermissionStatus_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.origin = decoder.decodeStruct(codec.String);
    return val;
  };

  NotificationService_GetPermissionStatus_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NotificationService_GetPermissionStatus_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.origin);
  };
  function NotificationService_GetPermissionStatus_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NotificationService_GetPermissionStatus_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  NotificationService_GetPermissionStatus_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NotificationService_GetPermissionStatus_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate NotificationService_GetPermissionStatus_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, permission_status$.PermissionStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NotificationService_GetPermissionStatus_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  NotificationService_GetPermissionStatus_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new NotificationService_GetPermissionStatus_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  NotificationService_GetPermissionStatus_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NotificationService_GetPermissionStatus_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kNotificationService_GetPermissionStatus_Name = 0;

  function NotificationServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(NotificationService,
                                                   handleOrPtrInfo);
  }

  function NotificationServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  NotificationServicePtr.prototype.getPermissionStatus = function() {
    return NotificationServiceProxy.prototype.getPermissionStatus
        .apply(this.ptr.getProxy(), arguments);
  };

  NotificationServiceProxy.prototype.getPermissionStatus = function(origin) {
    var params = new NotificationService_GetPermissionStatus_Params();
    params.origin = origin;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kNotificationService_GetPermissionStatus_Name,
          codec.align(NotificationService_GetPermissionStatus_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(NotificationService_GetPermissionStatus_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(NotificationService_GetPermissionStatus_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function NotificationServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  NotificationServiceStub.prototype.getPermissionStatus = function(origin) {
    return this.delegate_ && this.delegate_.getPermissionStatus && this.delegate_.getPermissionStatus(origin);
  }

  NotificationServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  NotificationServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kNotificationService_GetPermissionStatus_Name:
      var params = reader.decodeStruct(NotificationService_GetPermissionStatus_Params);
      return this.getPermissionStatus(params.origin).then(function(response) {
        var responseParams =
            new NotificationService_GetPermissionStatus_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kNotificationService_GetPermissionStatus_Name,
            codec.align(NotificationService_GetPermissionStatus_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(NotificationService_GetPermissionStatus_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateNotificationServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kNotificationService_GetPermissionStatus_Name:
        if (message.expectsResponse())
          paramsClass = NotificationService_GetPermissionStatus_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateNotificationServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kNotificationService_GetPermissionStatus_Name:
        if (message.isResponse())
          paramsClass = NotificationService_GetPermissionStatus_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var NotificationService = {
    name: 'blink::mojom::NotificationService',
    ptrClass: NotificationServicePtr,
    proxyClass: NotificationServiceProxy,
    stubClass: NotificationServiceStub,
    validateRequest: validateNotificationServiceRequest,
    validateResponse: validateNotificationServiceResponse,
  };
  NotificationServiceStub.prototype.validator = validateNotificationServiceRequest;
  NotificationServiceProxy.prototype.validator = validateNotificationServiceResponse;

  var exports = {};
  exports.NotificationService = NotificationService;
  exports.NotificationServicePtr = NotificationServicePtr;

  return exports;
});
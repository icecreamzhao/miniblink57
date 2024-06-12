// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/time_zone_monitor/public/interfaces/time_zone_monitor.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function TimeZoneMonitor_AddClient_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TimeZoneMonitor_AddClient_Params.prototype.initDefaults_ = function() {
    this.client = new TimeZoneMonitorClientPtr();
  };
  TimeZoneMonitor_AddClient_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TimeZoneMonitor_AddClient_Params.validate = function(messageValidator, offset) {
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


    
    // validate TimeZoneMonitor_AddClient_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TimeZoneMonitor_AddClient_Params.encodedSize = codec.kStructHeaderSize + 8;

  TimeZoneMonitor_AddClient_Params.decode = function(decoder) {
    var packed;
    var val = new TimeZoneMonitor_AddClient_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(new codec.Interface(TimeZoneMonitorClientPtr));
    return val;
  };

  TimeZoneMonitor_AddClient_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TimeZoneMonitor_AddClient_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(TimeZoneMonitorClientPtr), val.client);
  };
  function TimeZoneMonitorClient_OnTimeZoneChange_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TimeZoneMonitorClient_OnTimeZoneChange_Params.prototype.initDefaults_ = function() {
    this.tz_info = null;
  };
  TimeZoneMonitorClient_OnTimeZoneChange_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TimeZoneMonitorClient_OnTimeZoneChange_Params.validate = function(messageValidator, offset) {
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


    
    // validate TimeZoneMonitorClient_OnTimeZoneChange_Params.tz_info
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TimeZoneMonitorClient_OnTimeZoneChange_Params.encodedSize = codec.kStructHeaderSize + 8;

  TimeZoneMonitorClient_OnTimeZoneChange_Params.decode = function(decoder) {
    var packed;
    var val = new TimeZoneMonitorClient_OnTimeZoneChange_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.tz_info = decoder.decodeStruct(codec.String);
    return val;
  };

  TimeZoneMonitorClient_OnTimeZoneChange_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TimeZoneMonitorClient_OnTimeZoneChange_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.tz_info);
  };
  var kTimeZoneMonitor_AddClient_Name = 0;

  function TimeZoneMonitorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(TimeZoneMonitor,
                                                   handleOrPtrInfo);
  }

  function TimeZoneMonitorProxy(receiver) {
    this.receiver_ = receiver;
  }
  TimeZoneMonitorPtr.prototype.addClient = function() {
    return TimeZoneMonitorProxy.prototype.addClient
        .apply(this.ptr.getProxy(), arguments);
  };

  TimeZoneMonitorProxy.prototype.addClient = function(client) {
    var params = new TimeZoneMonitor_AddClient_Params();
    params.client = client;
    var builder = new codec.MessageBuilder(
        kTimeZoneMonitor_AddClient_Name,
        codec.align(TimeZoneMonitor_AddClient_Params.encodedSize));
    builder.encodeStruct(TimeZoneMonitor_AddClient_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function TimeZoneMonitorStub(delegate) {
    this.delegate_ = delegate;
  }
  TimeZoneMonitorStub.prototype.addClient = function(client) {
    return this.delegate_ && this.delegate_.addClient && this.delegate_.addClient(client);
  }

  TimeZoneMonitorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kTimeZoneMonitor_AddClient_Name:
      var params = reader.decodeStruct(TimeZoneMonitor_AddClient_Params);
      this.addClient(params.client);
      return true;
    default:
      return false;
    }
  };

  TimeZoneMonitorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateTimeZoneMonitorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kTimeZoneMonitor_AddClient_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TimeZoneMonitor_AddClient_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateTimeZoneMonitorResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var TimeZoneMonitor = {
    name: 'device::mojom::TimeZoneMonitor',
    ptrClass: TimeZoneMonitorPtr,
    proxyClass: TimeZoneMonitorProxy,
    stubClass: TimeZoneMonitorStub,
    validateRequest: validateTimeZoneMonitorRequest,
    validateResponse: null,
  };
  TimeZoneMonitorStub.prototype.validator = validateTimeZoneMonitorRequest;
  TimeZoneMonitorProxy.prototype.validator = null;
  var kTimeZoneMonitorClient_OnTimeZoneChange_Name = 0;

  function TimeZoneMonitorClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(TimeZoneMonitorClient,
                                                   handleOrPtrInfo);
  }

  function TimeZoneMonitorClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  TimeZoneMonitorClientPtr.prototype.onTimeZoneChange = function() {
    return TimeZoneMonitorClientProxy.prototype.onTimeZoneChange
        .apply(this.ptr.getProxy(), arguments);
  };

  TimeZoneMonitorClientProxy.prototype.onTimeZoneChange = function(tz_info) {
    var params = new TimeZoneMonitorClient_OnTimeZoneChange_Params();
    params.tz_info = tz_info;
    var builder = new codec.MessageBuilder(
        kTimeZoneMonitorClient_OnTimeZoneChange_Name,
        codec.align(TimeZoneMonitorClient_OnTimeZoneChange_Params.encodedSize));
    builder.encodeStruct(TimeZoneMonitorClient_OnTimeZoneChange_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function TimeZoneMonitorClientStub(delegate) {
    this.delegate_ = delegate;
  }
  TimeZoneMonitorClientStub.prototype.onTimeZoneChange = function(tz_info) {
    return this.delegate_ && this.delegate_.onTimeZoneChange && this.delegate_.onTimeZoneChange(tz_info);
  }

  TimeZoneMonitorClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kTimeZoneMonitorClient_OnTimeZoneChange_Name:
      var params = reader.decodeStruct(TimeZoneMonitorClient_OnTimeZoneChange_Params);
      this.onTimeZoneChange(params.tz_info);
      return true;
    default:
      return false;
    }
  };

  TimeZoneMonitorClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateTimeZoneMonitorClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kTimeZoneMonitorClient_OnTimeZoneChange_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TimeZoneMonitorClient_OnTimeZoneChange_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateTimeZoneMonitorClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var TimeZoneMonitorClient = {
    name: 'device::mojom::TimeZoneMonitorClient',
    ptrClass: TimeZoneMonitorClientPtr,
    proxyClass: TimeZoneMonitorClientProxy,
    stubClass: TimeZoneMonitorClientStub,
    validateRequest: validateTimeZoneMonitorClientRequest,
    validateResponse: null,
  };
  TimeZoneMonitorClientStub.prototype.validator = validateTimeZoneMonitorClientRequest;
  TimeZoneMonitorClientProxy.prototype.validator = null;

  var exports = {};
  exports.TimeZoneMonitor = TimeZoneMonitor;
  exports.TimeZoneMonitorPtr = TimeZoneMonitorPtr;
  exports.TimeZoneMonitorClient = TimeZoneMonitorClient;
  exports.TimeZoneMonitorClientPtr = TimeZoneMonitorClientPtr;

  return exports;
});
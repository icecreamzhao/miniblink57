// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/power_monitor/public/interfaces/power_monitor.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function PowerMonitor_SetClient_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PowerMonitor_SetClient_Params.prototype.initDefaults_ = function() {
    this.client = new PowerMonitorClientPtr();
  };
  PowerMonitor_SetClient_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PowerMonitor_SetClient_Params.validate = function(messageValidator, offset) {
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


    
    // validate PowerMonitor_SetClient_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PowerMonitor_SetClient_Params.encodedSize = codec.kStructHeaderSize + 8;

  PowerMonitor_SetClient_Params.decode = function(decoder) {
    var packed;
    var val = new PowerMonitor_SetClient_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(new codec.Interface(PowerMonitorClientPtr));
    return val;
  };

  PowerMonitor_SetClient_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PowerMonitor_SetClient_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(PowerMonitorClientPtr), val.client);
  };
  function PowerMonitorClient_PowerStateChange_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PowerMonitorClient_PowerStateChange_Params.prototype.initDefaults_ = function() {
    this.on_battery_power = false;
  };
  PowerMonitorClient_PowerStateChange_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PowerMonitorClient_PowerStateChange_Params.validate = function(messageValidator, offset) {
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

  PowerMonitorClient_PowerStateChange_Params.encodedSize = codec.kStructHeaderSize + 8;

  PowerMonitorClient_PowerStateChange_Params.decode = function(decoder) {
    var packed;
    var val = new PowerMonitorClient_PowerStateChange_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.on_battery_power = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PowerMonitorClient_PowerStateChange_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PowerMonitorClient_PowerStateChange_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.on_battery_power & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PowerMonitorClient_Suspend_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PowerMonitorClient_Suspend_Params.prototype.initDefaults_ = function() {
  };
  PowerMonitorClient_Suspend_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PowerMonitorClient_Suspend_Params.validate = function(messageValidator, offset) {
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

  PowerMonitorClient_Suspend_Params.encodedSize = codec.kStructHeaderSize + 0;

  PowerMonitorClient_Suspend_Params.decode = function(decoder) {
    var packed;
    var val = new PowerMonitorClient_Suspend_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PowerMonitorClient_Suspend_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PowerMonitorClient_Suspend_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function PowerMonitorClient_Resume_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PowerMonitorClient_Resume_Params.prototype.initDefaults_ = function() {
  };
  PowerMonitorClient_Resume_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PowerMonitorClient_Resume_Params.validate = function(messageValidator, offset) {
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

  PowerMonitorClient_Resume_Params.encodedSize = codec.kStructHeaderSize + 0;

  PowerMonitorClient_Resume_Params.decode = function(decoder) {
    var packed;
    var val = new PowerMonitorClient_Resume_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PowerMonitorClient_Resume_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PowerMonitorClient_Resume_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kPowerMonitor_SetClient_Name = 0;

  function PowerMonitorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PowerMonitor,
                                                   handleOrPtrInfo);
  }

  function PowerMonitorProxy(receiver) {
    this.receiver_ = receiver;
  }
  PowerMonitorPtr.prototype.setClient = function() {
    return PowerMonitorProxy.prototype.setClient
        .apply(this.ptr.getProxy(), arguments);
  };

  PowerMonitorProxy.prototype.setClient = function(client) {
    var params = new PowerMonitor_SetClient_Params();
    params.client = client;
    var builder = new codec.MessageBuilder(
        kPowerMonitor_SetClient_Name,
        codec.align(PowerMonitor_SetClient_Params.encodedSize));
    builder.encodeStruct(PowerMonitor_SetClient_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PowerMonitorStub(delegate) {
    this.delegate_ = delegate;
  }
  PowerMonitorStub.prototype.setClient = function(client) {
    return this.delegate_ && this.delegate_.setClient && this.delegate_.setClient(client);
  }

  PowerMonitorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPowerMonitor_SetClient_Name:
      var params = reader.decodeStruct(PowerMonitor_SetClient_Params);
      this.setClient(params.client);
      return true;
    default:
      return false;
    }
  };

  PowerMonitorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePowerMonitorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPowerMonitor_SetClient_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PowerMonitor_SetClient_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePowerMonitorResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PowerMonitor = {
    name: 'device::mojom::PowerMonitor',
    ptrClass: PowerMonitorPtr,
    proxyClass: PowerMonitorProxy,
    stubClass: PowerMonitorStub,
    validateRequest: validatePowerMonitorRequest,
    validateResponse: null,
  };
  PowerMonitorStub.prototype.validator = validatePowerMonitorRequest;
  PowerMonitorProxy.prototype.validator = null;
  var kPowerMonitorClient_PowerStateChange_Name = 0;
  var kPowerMonitorClient_Suspend_Name = 1;
  var kPowerMonitorClient_Resume_Name = 2;

  function PowerMonitorClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PowerMonitorClient,
                                                   handleOrPtrInfo);
  }

  function PowerMonitorClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  PowerMonitorClientPtr.prototype.powerStateChange = function() {
    return PowerMonitorClientProxy.prototype.powerStateChange
        .apply(this.ptr.getProxy(), arguments);
  };

  PowerMonitorClientProxy.prototype.powerStateChange = function(on_battery_power) {
    var params = new PowerMonitorClient_PowerStateChange_Params();
    params.on_battery_power = on_battery_power;
    var builder = new codec.MessageBuilder(
        kPowerMonitorClient_PowerStateChange_Name,
        codec.align(PowerMonitorClient_PowerStateChange_Params.encodedSize));
    builder.encodeStruct(PowerMonitorClient_PowerStateChange_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PowerMonitorClientPtr.prototype.suspend = function() {
    return PowerMonitorClientProxy.prototype.suspend
        .apply(this.ptr.getProxy(), arguments);
  };

  PowerMonitorClientProxy.prototype.suspend = function() {
    var params = new PowerMonitorClient_Suspend_Params();
    var builder = new codec.MessageBuilder(
        kPowerMonitorClient_Suspend_Name,
        codec.align(PowerMonitorClient_Suspend_Params.encodedSize));
    builder.encodeStruct(PowerMonitorClient_Suspend_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PowerMonitorClientPtr.prototype.resume = function() {
    return PowerMonitorClientProxy.prototype.resume
        .apply(this.ptr.getProxy(), arguments);
  };

  PowerMonitorClientProxy.prototype.resume = function() {
    var params = new PowerMonitorClient_Resume_Params();
    var builder = new codec.MessageBuilder(
        kPowerMonitorClient_Resume_Name,
        codec.align(PowerMonitorClient_Resume_Params.encodedSize));
    builder.encodeStruct(PowerMonitorClient_Resume_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PowerMonitorClientStub(delegate) {
    this.delegate_ = delegate;
  }
  PowerMonitorClientStub.prototype.powerStateChange = function(on_battery_power) {
    return this.delegate_ && this.delegate_.powerStateChange && this.delegate_.powerStateChange(on_battery_power);
  }
  PowerMonitorClientStub.prototype.suspend = function() {
    return this.delegate_ && this.delegate_.suspend && this.delegate_.suspend();
  }
  PowerMonitorClientStub.prototype.resume = function() {
    return this.delegate_ && this.delegate_.resume && this.delegate_.resume();
  }

  PowerMonitorClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPowerMonitorClient_PowerStateChange_Name:
      var params = reader.decodeStruct(PowerMonitorClient_PowerStateChange_Params);
      this.powerStateChange(params.on_battery_power);
      return true;
    case kPowerMonitorClient_Suspend_Name:
      var params = reader.decodeStruct(PowerMonitorClient_Suspend_Params);
      this.suspend();
      return true;
    case kPowerMonitorClient_Resume_Name:
      var params = reader.decodeStruct(PowerMonitorClient_Resume_Params);
      this.resume();
      return true;
    default:
      return false;
    }
  };

  PowerMonitorClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePowerMonitorClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPowerMonitorClient_PowerStateChange_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PowerMonitorClient_PowerStateChange_Params;
      break;
      case kPowerMonitorClient_Suspend_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PowerMonitorClient_Suspend_Params;
      break;
      case kPowerMonitorClient_Resume_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PowerMonitorClient_Resume_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePowerMonitorClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PowerMonitorClient = {
    name: 'device::mojom::PowerMonitorClient',
    ptrClass: PowerMonitorClientPtr,
    proxyClass: PowerMonitorClientProxy,
    stubClass: PowerMonitorClientStub,
    validateRequest: validatePowerMonitorClientRequest,
    validateResponse: null,
  };
  PowerMonitorClientStub.prototype.validator = validatePowerMonitorClientRequest;
  PowerMonitorClientProxy.prototype.validator = null;

  var exports = {};
  exports.PowerMonitor = PowerMonitor;
  exports.PowerMonitorPtr = PowerMonitorPtr;
  exports.PowerMonitorClient = PowerMonitorClient;
  exports.PowerMonitorClientPtr = PowerMonitorClientPtr;

  return exports;
});
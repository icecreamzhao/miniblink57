// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/user_activity_monitor.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function UserActivityObserver_OnUserActivity_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  UserActivityObserver_OnUserActivity_Params.prototype.initDefaults_ = function() {
  };
  UserActivityObserver_OnUserActivity_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  UserActivityObserver_OnUserActivity_Params.validate = function(messageValidator, offset) {
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

  UserActivityObserver_OnUserActivity_Params.encodedSize = codec.kStructHeaderSize + 0;

  UserActivityObserver_OnUserActivity_Params.decode = function(decoder) {
    var packed;
    var val = new UserActivityObserver_OnUserActivity_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  UserActivityObserver_OnUserActivity_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(UserActivityObserver_OnUserActivity_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function UserIdleObserver_OnUserIdleStateChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  UserIdleObserver_OnUserIdleStateChanged_Params.prototype.initDefaults_ = function() {
    this.new_state = 0;
  };
  UserIdleObserver_OnUserIdleStateChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  UserIdleObserver_OnUserIdleStateChanged_Params.validate = function(messageValidator, offset) {
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


    
    // validate UserIdleObserver_OnUserIdleStateChanged_Params.new_state
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, UserIdleObserver.IdleState);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  UserIdleObserver_OnUserIdleStateChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  UserIdleObserver_OnUserIdleStateChanged_Params.decode = function(decoder) {
    var packed;
    var val = new UserIdleObserver_OnUserIdleStateChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.new_state = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  UserIdleObserver_OnUserIdleStateChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(UserIdleObserver_OnUserIdleStateChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.new_state);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function UserActivityMonitor_AddUserActivityObserver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  UserActivityMonitor_AddUserActivityObserver_Params.prototype.initDefaults_ = function() {
    this.delay_between_notify_secs = 0;
    this.observer = new UserActivityObserverPtr();
  };
  UserActivityMonitor_AddUserActivityObserver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  UserActivityMonitor_AddUserActivityObserver_Params.validate = function(messageValidator, offset) {
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



    
    // validate UserActivityMonitor_AddUserActivityObserver_Params.observer
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  UserActivityMonitor_AddUserActivityObserver_Params.encodedSize = codec.kStructHeaderSize + 16;

  UserActivityMonitor_AddUserActivityObserver_Params.decode = function(decoder) {
    var packed;
    var val = new UserActivityMonitor_AddUserActivityObserver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.delay_between_notify_secs = decoder.decodeStruct(codec.Uint32);
    val.observer = decoder.decodeStruct(new codec.Interface(UserActivityObserverPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  UserActivityMonitor_AddUserActivityObserver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(UserActivityMonitor_AddUserActivityObserver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.delay_between_notify_secs);
    encoder.encodeStruct(new codec.Interface(UserActivityObserverPtr), val.observer);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function UserActivityMonitor_AddUserIdleObserver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  UserActivityMonitor_AddUserIdleObserver_Params.prototype.initDefaults_ = function() {
    this.idle_time_in_minutes = 0;
    this.observer = new UserIdleObserverPtr();
  };
  UserActivityMonitor_AddUserIdleObserver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  UserActivityMonitor_AddUserIdleObserver_Params.validate = function(messageValidator, offset) {
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



    
    // validate UserActivityMonitor_AddUserIdleObserver_Params.observer
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  UserActivityMonitor_AddUserIdleObserver_Params.encodedSize = codec.kStructHeaderSize + 16;

  UserActivityMonitor_AddUserIdleObserver_Params.decode = function(decoder) {
    var packed;
    var val = new UserActivityMonitor_AddUserIdleObserver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.idle_time_in_minutes = decoder.decodeStruct(codec.Uint32);
    val.observer = decoder.decodeStruct(new codec.Interface(UserIdleObserverPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  UserActivityMonitor_AddUserIdleObserver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(UserActivityMonitor_AddUserIdleObserver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.idle_time_in_minutes);
    encoder.encodeStruct(new codec.Interface(UserIdleObserverPtr), val.observer);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kUserActivityObserver_OnUserActivity_Name = 0;

  function UserActivityObserverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(UserActivityObserver,
                                                   handleOrPtrInfo);
  }

  function UserActivityObserverProxy(receiver) {
    this.receiver_ = receiver;
  }
  UserActivityObserverPtr.prototype.onUserActivity = function() {
    return UserActivityObserverProxy.prototype.onUserActivity
        .apply(this.ptr.getProxy(), arguments);
  };

  UserActivityObserverProxy.prototype.onUserActivity = function() {
    var params = new UserActivityObserver_OnUserActivity_Params();
    var builder = new codec.MessageBuilder(
        kUserActivityObserver_OnUserActivity_Name,
        codec.align(UserActivityObserver_OnUserActivity_Params.encodedSize));
    builder.encodeStruct(UserActivityObserver_OnUserActivity_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function UserActivityObserverStub(delegate) {
    this.delegate_ = delegate;
  }
  UserActivityObserverStub.prototype.onUserActivity = function() {
    return this.delegate_ && this.delegate_.onUserActivity && this.delegate_.onUserActivity();
  }

  UserActivityObserverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kUserActivityObserver_OnUserActivity_Name:
      var params = reader.decodeStruct(UserActivityObserver_OnUserActivity_Params);
      this.onUserActivity();
      return true;
    default:
      return false;
    }
  };

  UserActivityObserverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateUserActivityObserverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kUserActivityObserver_OnUserActivity_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = UserActivityObserver_OnUserActivity_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateUserActivityObserverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var UserActivityObserver = {
    name: 'ui::mojom::UserActivityObserver',
    ptrClass: UserActivityObserverPtr,
    proxyClass: UserActivityObserverProxy,
    stubClass: UserActivityObserverStub,
    validateRequest: validateUserActivityObserverRequest,
    validateResponse: null,
  };
  UserActivityObserverStub.prototype.validator = validateUserActivityObserverRequest;
  UserActivityObserverProxy.prototype.validator = null;
  var kUserIdleObserver_OnUserIdleStateChanged_Name = 0;

  function UserIdleObserverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(UserIdleObserver,
                                                   handleOrPtrInfo);
  }

  function UserIdleObserverProxy(receiver) {
    this.receiver_ = receiver;
  }
  UserIdleObserverPtr.prototype.onUserIdleStateChanged = function() {
    return UserIdleObserverProxy.prototype.onUserIdleStateChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  UserIdleObserverProxy.prototype.onUserIdleStateChanged = function(new_state) {
    var params = new UserIdleObserver_OnUserIdleStateChanged_Params();
    params.new_state = new_state;
    var builder = new codec.MessageBuilder(
        kUserIdleObserver_OnUserIdleStateChanged_Name,
        codec.align(UserIdleObserver_OnUserIdleStateChanged_Params.encodedSize));
    builder.encodeStruct(UserIdleObserver_OnUserIdleStateChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function UserIdleObserverStub(delegate) {
    this.delegate_ = delegate;
  }
  UserIdleObserverStub.prototype.onUserIdleStateChanged = function(new_state) {
    return this.delegate_ && this.delegate_.onUserIdleStateChanged && this.delegate_.onUserIdleStateChanged(new_state);
  }

  UserIdleObserverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kUserIdleObserver_OnUserIdleStateChanged_Name:
      var params = reader.decodeStruct(UserIdleObserver_OnUserIdleStateChanged_Params);
      this.onUserIdleStateChanged(params.new_state);
      return true;
    default:
      return false;
    }
  };

  UserIdleObserverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateUserIdleObserverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kUserIdleObserver_OnUserIdleStateChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = UserIdleObserver_OnUserIdleStateChanged_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateUserIdleObserverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var UserIdleObserver = {
    name: 'ui::mojom::UserIdleObserver',
    ptrClass: UserIdleObserverPtr,
    proxyClass: UserIdleObserverProxy,
    stubClass: UserIdleObserverStub,
    validateRequest: validateUserIdleObserverRequest,
    validateResponse: null,
  };
  UserIdleObserver.IdleState = {};
  UserIdleObserver.IdleState.ACTIVE = 0;
  UserIdleObserver.IdleState.IDLE = UserIdleObserver.IdleState.ACTIVE + 1;

  UserIdleObserver.IdleState.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  UserIdleObserver.IdleState.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  UserIdleObserverStub.prototype.validator = validateUserIdleObserverRequest;
  UserIdleObserverProxy.prototype.validator = null;
  var kUserActivityMonitor_AddUserActivityObserver_Name = 0;
  var kUserActivityMonitor_AddUserIdleObserver_Name = 1;

  function UserActivityMonitorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(UserActivityMonitor,
                                                   handleOrPtrInfo);
  }

  function UserActivityMonitorProxy(receiver) {
    this.receiver_ = receiver;
  }
  UserActivityMonitorPtr.prototype.addUserActivityObserver = function() {
    return UserActivityMonitorProxy.prototype.addUserActivityObserver
        .apply(this.ptr.getProxy(), arguments);
  };

  UserActivityMonitorProxy.prototype.addUserActivityObserver = function(delay_between_notify_secs, observer) {
    var params = new UserActivityMonitor_AddUserActivityObserver_Params();
    params.delay_between_notify_secs = delay_between_notify_secs;
    params.observer = observer;
    var builder = new codec.MessageBuilder(
        kUserActivityMonitor_AddUserActivityObserver_Name,
        codec.align(UserActivityMonitor_AddUserActivityObserver_Params.encodedSize));
    builder.encodeStruct(UserActivityMonitor_AddUserActivityObserver_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  UserActivityMonitorPtr.prototype.addUserIdleObserver = function() {
    return UserActivityMonitorProxy.prototype.addUserIdleObserver
        .apply(this.ptr.getProxy(), arguments);
  };

  UserActivityMonitorProxy.prototype.addUserIdleObserver = function(idle_time_in_minutes, observer) {
    var params = new UserActivityMonitor_AddUserIdleObserver_Params();
    params.idle_time_in_minutes = idle_time_in_minutes;
    params.observer = observer;
    var builder = new codec.MessageBuilder(
        kUserActivityMonitor_AddUserIdleObserver_Name,
        codec.align(UserActivityMonitor_AddUserIdleObserver_Params.encodedSize));
    builder.encodeStruct(UserActivityMonitor_AddUserIdleObserver_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function UserActivityMonitorStub(delegate) {
    this.delegate_ = delegate;
  }
  UserActivityMonitorStub.prototype.addUserActivityObserver = function(delay_between_notify_secs, observer) {
    return this.delegate_ && this.delegate_.addUserActivityObserver && this.delegate_.addUserActivityObserver(delay_between_notify_secs, observer);
  }
  UserActivityMonitorStub.prototype.addUserIdleObserver = function(idle_time_in_minutes, observer) {
    return this.delegate_ && this.delegate_.addUserIdleObserver && this.delegate_.addUserIdleObserver(idle_time_in_minutes, observer);
  }

  UserActivityMonitorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kUserActivityMonitor_AddUserActivityObserver_Name:
      var params = reader.decodeStruct(UserActivityMonitor_AddUserActivityObserver_Params);
      this.addUserActivityObserver(params.delay_between_notify_secs, params.observer);
      return true;
    case kUserActivityMonitor_AddUserIdleObserver_Name:
      var params = reader.decodeStruct(UserActivityMonitor_AddUserIdleObserver_Params);
      this.addUserIdleObserver(params.idle_time_in_minutes, params.observer);
      return true;
    default:
      return false;
    }
  };

  UserActivityMonitorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateUserActivityMonitorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kUserActivityMonitor_AddUserActivityObserver_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = UserActivityMonitor_AddUserActivityObserver_Params;
      break;
      case kUserActivityMonitor_AddUserIdleObserver_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = UserActivityMonitor_AddUserIdleObserver_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateUserActivityMonitorResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var UserActivityMonitor = {
    name: 'ui::mojom::UserActivityMonitor',
    ptrClass: UserActivityMonitorPtr,
    proxyClass: UserActivityMonitorProxy,
    stubClass: UserActivityMonitorStub,
    validateRequest: validateUserActivityMonitorRequest,
    validateResponse: null,
  };
  UserActivityMonitorStub.prototype.validator = validateUserActivityMonitorRequest;
  UserActivityMonitorProxy.prototype.validator = null;

  var exports = {};
  exports.UserActivityObserver = UserActivityObserver;
  exports.UserActivityObserverPtr = UserActivityObserverPtr;
  exports.UserIdleObserver = UserIdleObserver;
  exports.UserIdleObserverPtr = UserIdleObserverPtr;
  exports.UserActivityMonitor = UserActivityMonitor;
  exports.UserActivityMonitorPtr = UserActivityMonitorPtr;

  return exports;
});
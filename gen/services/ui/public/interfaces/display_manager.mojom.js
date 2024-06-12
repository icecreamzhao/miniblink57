// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/display_manager.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/ui/public/interfaces/window_manager_constants.mojom",
], function(bindings, codec, core, validator, window_manager_constants$) {

  function DisplayManagerObserver_OnDisplays_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayManagerObserver_OnDisplays_Params.prototype.initDefaults_ = function() {
    this.displays = null;
    this.primary_display_id = 0;
    this.internal_display_id = 0;
  };
  DisplayManagerObserver_OnDisplays_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayManagerObserver_OnDisplays_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayManagerObserver_OnDisplays_Params.displays
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(window_manager_constants$.WsDisplay), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  DisplayManagerObserver_OnDisplays_Params.encodedSize = codec.kStructHeaderSize + 24;

  DisplayManagerObserver_OnDisplays_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayManagerObserver_OnDisplays_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.displays = decoder.decodeArrayPointer(new codec.PointerTo(window_manager_constants$.WsDisplay));
    val.primary_display_id = decoder.decodeStruct(codec.Int64);
    val.internal_display_id = decoder.decodeStruct(codec.Int64);
    return val;
  };

  DisplayManagerObserver_OnDisplays_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayManagerObserver_OnDisplays_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(window_manager_constants$.WsDisplay), val.displays);
    encoder.encodeStruct(codec.Int64, val.primary_display_id);
    encoder.encodeStruct(codec.Int64, val.internal_display_id);
  };
  function DisplayManagerObserver_OnDisplaysChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayManagerObserver_OnDisplaysChanged_Params.prototype.initDefaults_ = function() {
    this.displays = null;
  };
  DisplayManagerObserver_OnDisplaysChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayManagerObserver_OnDisplaysChanged_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayManagerObserver_OnDisplaysChanged_Params.displays
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(window_manager_constants$.WsDisplay), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayManagerObserver_OnDisplaysChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayManagerObserver_OnDisplaysChanged_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayManagerObserver_OnDisplaysChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.displays = decoder.decodeArrayPointer(new codec.PointerTo(window_manager_constants$.WsDisplay));
    return val;
  };

  DisplayManagerObserver_OnDisplaysChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayManagerObserver_OnDisplaysChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(window_manager_constants$.WsDisplay), val.displays);
  };
  function DisplayManagerObserver_OnDisplayRemoved_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayManagerObserver_OnDisplayRemoved_Params.prototype.initDefaults_ = function() {
    this.display_id = 0;
  };
  DisplayManagerObserver_OnDisplayRemoved_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayManagerObserver_OnDisplayRemoved_Params.validate = function(messageValidator, offset) {
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

  DisplayManagerObserver_OnDisplayRemoved_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayManagerObserver_OnDisplayRemoved_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayManagerObserver_OnDisplayRemoved_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.display_id = decoder.decodeStruct(codec.Int64);
    return val;
  };

  DisplayManagerObserver_OnDisplayRemoved_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayManagerObserver_OnDisplayRemoved_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.display_id);
  };
  function DisplayManagerObserver_OnPrimaryDisplayChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayManagerObserver_OnPrimaryDisplayChanged_Params.prototype.initDefaults_ = function() {
    this.primary_display_id = 0;
  };
  DisplayManagerObserver_OnPrimaryDisplayChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayManagerObserver_OnPrimaryDisplayChanged_Params.validate = function(messageValidator, offset) {
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

  DisplayManagerObserver_OnPrimaryDisplayChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayManagerObserver_OnPrimaryDisplayChanged_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayManagerObserver_OnPrimaryDisplayChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.primary_display_id = decoder.decodeStruct(codec.Int64);
    return val;
  };

  DisplayManagerObserver_OnPrimaryDisplayChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayManagerObserver_OnPrimaryDisplayChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.primary_display_id);
  };
  function DisplayManager_AddObserver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayManager_AddObserver_Params.prototype.initDefaults_ = function() {
    this.observer = new DisplayManagerObserverPtr();
  };
  DisplayManager_AddObserver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayManager_AddObserver_Params.validate = function(messageValidator, offset) {
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


    
    // validate DisplayManager_AddObserver_Params.observer
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayManager_AddObserver_Params.encodedSize = codec.kStructHeaderSize + 8;

  DisplayManager_AddObserver_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayManager_AddObserver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.observer = decoder.decodeStruct(new codec.Interface(DisplayManagerObserverPtr));
    return val;
  };

  DisplayManager_AddObserver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayManager_AddObserver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(DisplayManagerObserverPtr), val.observer);
  };
  var kDisplayManagerObserver_OnDisplays_Name = 0;
  var kDisplayManagerObserver_OnDisplaysChanged_Name = 1;
  var kDisplayManagerObserver_OnDisplayRemoved_Name = 2;
  var kDisplayManagerObserver_OnPrimaryDisplayChanged_Name = 3;

  function DisplayManagerObserverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DisplayManagerObserver,
                                                   handleOrPtrInfo);
  }

  function DisplayManagerObserverProxy(receiver) {
    this.receiver_ = receiver;
  }
  DisplayManagerObserverPtr.prototype.onDisplays = function() {
    return DisplayManagerObserverProxy.prototype.onDisplays
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayManagerObserverProxy.prototype.onDisplays = function(displays, primary_display_id, internal_display_id) {
    var params = new DisplayManagerObserver_OnDisplays_Params();
    params.displays = displays;
    params.primary_display_id = primary_display_id;
    params.internal_display_id = internal_display_id;
    var builder = new codec.MessageBuilder(
        kDisplayManagerObserver_OnDisplays_Name,
        codec.align(DisplayManagerObserver_OnDisplays_Params.encodedSize));
    builder.encodeStruct(DisplayManagerObserver_OnDisplays_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayManagerObserverPtr.prototype.onDisplaysChanged = function() {
    return DisplayManagerObserverProxy.prototype.onDisplaysChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayManagerObserverProxy.prototype.onDisplaysChanged = function(displays) {
    var params = new DisplayManagerObserver_OnDisplaysChanged_Params();
    params.displays = displays;
    var builder = new codec.MessageBuilder(
        kDisplayManagerObserver_OnDisplaysChanged_Name,
        codec.align(DisplayManagerObserver_OnDisplaysChanged_Params.encodedSize));
    builder.encodeStruct(DisplayManagerObserver_OnDisplaysChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayManagerObserverPtr.prototype.onDisplayRemoved = function() {
    return DisplayManagerObserverProxy.prototype.onDisplayRemoved
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayManagerObserverProxy.prototype.onDisplayRemoved = function(display_id) {
    var params = new DisplayManagerObserver_OnDisplayRemoved_Params();
    params.display_id = display_id;
    var builder = new codec.MessageBuilder(
        kDisplayManagerObserver_OnDisplayRemoved_Name,
        codec.align(DisplayManagerObserver_OnDisplayRemoved_Params.encodedSize));
    builder.encodeStruct(DisplayManagerObserver_OnDisplayRemoved_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayManagerObserverPtr.prototype.onPrimaryDisplayChanged = function() {
    return DisplayManagerObserverProxy.prototype.onPrimaryDisplayChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayManagerObserverProxy.prototype.onPrimaryDisplayChanged = function(primary_display_id) {
    var params = new DisplayManagerObserver_OnPrimaryDisplayChanged_Params();
    params.primary_display_id = primary_display_id;
    var builder = new codec.MessageBuilder(
        kDisplayManagerObserver_OnPrimaryDisplayChanged_Name,
        codec.align(DisplayManagerObserver_OnPrimaryDisplayChanged_Params.encodedSize));
    builder.encodeStruct(DisplayManagerObserver_OnPrimaryDisplayChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DisplayManagerObserverStub(delegate) {
    this.delegate_ = delegate;
  }
  DisplayManagerObserverStub.prototype.onDisplays = function(displays, primary_display_id, internal_display_id) {
    return this.delegate_ && this.delegate_.onDisplays && this.delegate_.onDisplays(displays, primary_display_id, internal_display_id);
  }
  DisplayManagerObserverStub.prototype.onDisplaysChanged = function(displays) {
    return this.delegate_ && this.delegate_.onDisplaysChanged && this.delegate_.onDisplaysChanged(displays);
  }
  DisplayManagerObserverStub.prototype.onDisplayRemoved = function(display_id) {
    return this.delegate_ && this.delegate_.onDisplayRemoved && this.delegate_.onDisplayRemoved(display_id);
  }
  DisplayManagerObserverStub.prototype.onPrimaryDisplayChanged = function(primary_display_id) {
    return this.delegate_ && this.delegate_.onPrimaryDisplayChanged && this.delegate_.onPrimaryDisplayChanged(primary_display_id);
  }

  DisplayManagerObserverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDisplayManagerObserver_OnDisplays_Name:
      var params = reader.decodeStruct(DisplayManagerObserver_OnDisplays_Params);
      this.onDisplays(params.displays, params.primary_display_id, params.internal_display_id);
      return true;
    case kDisplayManagerObserver_OnDisplaysChanged_Name:
      var params = reader.decodeStruct(DisplayManagerObserver_OnDisplaysChanged_Params);
      this.onDisplaysChanged(params.displays);
      return true;
    case kDisplayManagerObserver_OnDisplayRemoved_Name:
      var params = reader.decodeStruct(DisplayManagerObserver_OnDisplayRemoved_Params);
      this.onDisplayRemoved(params.display_id);
      return true;
    case kDisplayManagerObserver_OnPrimaryDisplayChanged_Name:
      var params = reader.decodeStruct(DisplayManagerObserver_OnPrimaryDisplayChanged_Params);
      this.onPrimaryDisplayChanged(params.primary_display_id);
      return true;
    default:
      return false;
    }
  };

  DisplayManagerObserverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDisplayManagerObserverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDisplayManagerObserver_OnDisplays_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayManagerObserver_OnDisplays_Params;
      break;
      case kDisplayManagerObserver_OnDisplaysChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayManagerObserver_OnDisplaysChanged_Params;
      break;
      case kDisplayManagerObserver_OnDisplayRemoved_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayManagerObserver_OnDisplayRemoved_Params;
      break;
      case kDisplayManagerObserver_OnPrimaryDisplayChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayManagerObserver_OnPrimaryDisplayChanged_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDisplayManagerObserverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var DisplayManagerObserver = {
    name: 'ui::mojom::DisplayManagerObserver',
    ptrClass: DisplayManagerObserverPtr,
    proxyClass: DisplayManagerObserverProxy,
    stubClass: DisplayManagerObserverStub,
    validateRequest: validateDisplayManagerObserverRequest,
    validateResponse: null,
  };
  DisplayManagerObserverStub.prototype.validator = validateDisplayManagerObserverRequest;
  DisplayManagerObserverProxy.prototype.validator = null;
  var kDisplayManager_AddObserver_Name = 0;

  function DisplayManagerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DisplayManager,
                                                   handleOrPtrInfo);
  }

  function DisplayManagerProxy(receiver) {
    this.receiver_ = receiver;
  }
  DisplayManagerPtr.prototype.addObserver = function() {
    return DisplayManagerProxy.prototype.addObserver
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayManagerProxy.prototype.addObserver = function(observer) {
    var params = new DisplayManager_AddObserver_Params();
    params.observer = observer;
    var builder = new codec.MessageBuilder(
        kDisplayManager_AddObserver_Name,
        codec.align(DisplayManager_AddObserver_Params.encodedSize));
    builder.encodeStruct(DisplayManager_AddObserver_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DisplayManagerStub(delegate) {
    this.delegate_ = delegate;
  }
  DisplayManagerStub.prototype.addObserver = function(observer) {
    return this.delegate_ && this.delegate_.addObserver && this.delegate_.addObserver(observer);
  }

  DisplayManagerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDisplayManager_AddObserver_Name:
      var params = reader.decodeStruct(DisplayManager_AddObserver_Params);
      this.addObserver(params.observer);
      return true;
    default:
      return false;
    }
  };

  DisplayManagerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDisplayManagerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDisplayManager_AddObserver_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayManager_AddObserver_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDisplayManagerResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var DisplayManager = {
    name: 'ui::mojom::DisplayManager',
    ptrClass: DisplayManagerPtr,
    proxyClass: DisplayManagerProxy,
    stubClass: DisplayManagerStub,
    validateRequest: validateDisplayManagerRequest,
    validateResponse: null,
  };
  DisplayManagerStub.prototype.validator = validateDisplayManagerRequest;
  DisplayManagerProxy.prototype.validator = null;

  var exports = {};
  exports.DisplayManagerObserver = DisplayManagerObserver;
  exports.DisplayManagerObserverPtr = DisplayManagerObserverPtr;
  exports.DisplayManager = DisplayManager;
  exports.DisplayManagerPtr = DisplayManagerPtr;

  return exports;
});
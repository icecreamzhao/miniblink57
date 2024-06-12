// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/display/display_controller.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, geometry$) {

  function DisplayController_IncreaseInternalDisplayZoom_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayController_IncreaseInternalDisplayZoom_Params.prototype.initDefaults_ = function() {
  };
  DisplayController_IncreaseInternalDisplayZoom_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayController_IncreaseInternalDisplayZoom_Params.validate = function(messageValidator, offset) {
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

  DisplayController_IncreaseInternalDisplayZoom_Params.encodedSize = codec.kStructHeaderSize + 0;

  DisplayController_IncreaseInternalDisplayZoom_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayController_IncreaseInternalDisplayZoom_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DisplayController_IncreaseInternalDisplayZoom_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayController_IncreaseInternalDisplayZoom_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DisplayController_DecreaseInternalDisplayZoom_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayController_DecreaseInternalDisplayZoom_Params.prototype.initDefaults_ = function() {
  };
  DisplayController_DecreaseInternalDisplayZoom_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayController_DecreaseInternalDisplayZoom_Params.validate = function(messageValidator, offset) {
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

  DisplayController_DecreaseInternalDisplayZoom_Params.encodedSize = codec.kStructHeaderSize + 0;

  DisplayController_DecreaseInternalDisplayZoom_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayController_DecreaseInternalDisplayZoom_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DisplayController_DecreaseInternalDisplayZoom_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayController_DecreaseInternalDisplayZoom_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DisplayController_ResetInternalDisplayZoom_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayController_ResetInternalDisplayZoom_Params.prototype.initDefaults_ = function() {
  };
  DisplayController_ResetInternalDisplayZoom_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayController_ResetInternalDisplayZoom_Params.validate = function(messageValidator, offset) {
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

  DisplayController_ResetInternalDisplayZoom_Params.encodedSize = codec.kStructHeaderSize + 0;

  DisplayController_ResetInternalDisplayZoom_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayController_ResetInternalDisplayZoom_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DisplayController_ResetInternalDisplayZoom_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayController_ResetInternalDisplayZoom_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DisplayController_RotateCurrentDisplayCW_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayController_RotateCurrentDisplayCW_Params.prototype.initDefaults_ = function() {
  };
  DisplayController_RotateCurrentDisplayCW_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayController_RotateCurrentDisplayCW_Params.validate = function(messageValidator, offset) {
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

  DisplayController_RotateCurrentDisplayCW_Params.encodedSize = codec.kStructHeaderSize + 0;

  DisplayController_RotateCurrentDisplayCW_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayController_RotateCurrentDisplayCW_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DisplayController_RotateCurrentDisplayCW_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayController_RotateCurrentDisplayCW_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DisplayController_SwapPrimaryDisplay_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayController_SwapPrimaryDisplay_Params.prototype.initDefaults_ = function() {
  };
  DisplayController_SwapPrimaryDisplay_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayController_SwapPrimaryDisplay_Params.validate = function(messageValidator, offset) {
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

  DisplayController_SwapPrimaryDisplay_Params.encodedSize = codec.kStructHeaderSize + 0;

  DisplayController_SwapPrimaryDisplay_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayController_SwapPrimaryDisplay_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DisplayController_SwapPrimaryDisplay_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayController_SwapPrimaryDisplay_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DisplayController_ToggleMirrorMode_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayController_ToggleMirrorMode_Params.prototype.initDefaults_ = function() {
  };
  DisplayController_ToggleMirrorMode_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayController_ToggleMirrorMode_Params.validate = function(messageValidator, offset) {
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

  DisplayController_ToggleMirrorMode_Params.encodedSize = codec.kStructHeaderSize + 0;

  DisplayController_ToggleMirrorMode_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayController_ToggleMirrorMode_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  DisplayController_ToggleMirrorMode_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayController_ToggleMirrorMode_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function DisplayController_SetDisplayWorkArea_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DisplayController_SetDisplayWorkArea_Params.prototype.initDefaults_ = function() {
    this.display_id = 0;
    this.size = null;
    this.insets = null;
  };
  DisplayController_SetDisplayWorkArea_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DisplayController_SetDisplayWorkArea_Params.validate = function(messageValidator, offset) {
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



    
    // validate DisplayController_SetDisplayWorkArea_Params.size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DisplayController_SetDisplayWorkArea_Params.insets
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Insets, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DisplayController_SetDisplayWorkArea_Params.encodedSize = codec.kStructHeaderSize + 24;

  DisplayController_SetDisplayWorkArea_Params.decode = function(decoder) {
    var packed;
    var val = new DisplayController_SetDisplayWorkArea_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.display_id = decoder.decodeStruct(codec.Int64);
    val.size = decoder.decodeStructPointer(geometry$.Size);
    val.insets = decoder.decodeStructPointer(geometry$.Insets);
    return val;
  };

  DisplayController_SetDisplayWorkArea_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DisplayController_SetDisplayWorkArea_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.display_id);
    encoder.encodeStructPointer(geometry$.Size, val.size);
    encoder.encodeStructPointer(geometry$.Insets, val.insets);
  };
  var kDisplayController_IncreaseInternalDisplayZoom_Name = 0;
  var kDisplayController_DecreaseInternalDisplayZoom_Name = 1;
  var kDisplayController_ResetInternalDisplayZoom_Name = 2;
  var kDisplayController_RotateCurrentDisplayCW_Name = 3;
  var kDisplayController_SwapPrimaryDisplay_Name = 4;
  var kDisplayController_ToggleMirrorMode_Name = 5;
  var kDisplayController_SetDisplayWorkArea_Name = 6;

  function DisplayControllerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DisplayController,
                                                   handleOrPtrInfo);
  }

  function DisplayControllerProxy(receiver) {
    this.receiver_ = receiver;
  }
  DisplayControllerPtr.prototype.increaseInternalDisplayZoom = function() {
    return DisplayControllerProxy.prototype.increaseInternalDisplayZoom
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayControllerProxy.prototype.increaseInternalDisplayZoom = function() {
    var params = new DisplayController_IncreaseInternalDisplayZoom_Params();
    var builder = new codec.MessageBuilder(
        kDisplayController_IncreaseInternalDisplayZoom_Name,
        codec.align(DisplayController_IncreaseInternalDisplayZoom_Params.encodedSize));
    builder.encodeStruct(DisplayController_IncreaseInternalDisplayZoom_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayControllerPtr.prototype.decreaseInternalDisplayZoom = function() {
    return DisplayControllerProxy.prototype.decreaseInternalDisplayZoom
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayControllerProxy.prototype.decreaseInternalDisplayZoom = function() {
    var params = new DisplayController_DecreaseInternalDisplayZoom_Params();
    var builder = new codec.MessageBuilder(
        kDisplayController_DecreaseInternalDisplayZoom_Name,
        codec.align(DisplayController_DecreaseInternalDisplayZoom_Params.encodedSize));
    builder.encodeStruct(DisplayController_DecreaseInternalDisplayZoom_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayControllerPtr.prototype.resetInternalDisplayZoom = function() {
    return DisplayControllerProxy.prototype.resetInternalDisplayZoom
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayControllerProxy.prototype.resetInternalDisplayZoom = function() {
    var params = new DisplayController_ResetInternalDisplayZoom_Params();
    var builder = new codec.MessageBuilder(
        kDisplayController_ResetInternalDisplayZoom_Name,
        codec.align(DisplayController_ResetInternalDisplayZoom_Params.encodedSize));
    builder.encodeStruct(DisplayController_ResetInternalDisplayZoom_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayControllerPtr.prototype.rotateCurrentDisplayCW = function() {
    return DisplayControllerProxy.prototype.rotateCurrentDisplayCW
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayControllerProxy.prototype.rotateCurrentDisplayCW = function() {
    var params = new DisplayController_RotateCurrentDisplayCW_Params();
    var builder = new codec.MessageBuilder(
        kDisplayController_RotateCurrentDisplayCW_Name,
        codec.align(DisplayController_RotateCurrentDisplayCW_Params.encodedSize));
    builder.encodeStruct(DisplayController_RotateCurrentDisplayCW_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayControllerPtr.prototype.swapPrimaryDisplay = function() {
    return DisplayControllerProxy.prototype.swapPrimaryDisplay
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayControllerProxy.prototype.swapPrimaryDisplay = function() {
    var params = new DisplayController_SwapPrimaryDisplay_Params();
    var builder = new codec.MessageBuilder(
        kDisplayController_SwapPrimaryDisplay_Name,
        codec.align(DisplayController_SwapPrimaryDisplay_Params.encodedSize));
    builder.encodeStruct(DisplayController_SwapPrimaryDisplay_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayControllerPtr.prototype.toggleMirrorMode = function() {
    return DisplayControllerProxy.prototype.toggleMirrorMode
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayControllerProxy.prototype.toggleMirrorMode = function() {
    var params = new DisplayController_ToggleMirrorMode_Params();
    var builder = new codec.MessageBuilder(
        kDisplayController_ToggleMirrorMode_Name,
        codec.align(DisplayController_ToggleMirrorMode_Params.encodedSize));
    builder.encodeStruct(DisplayController_ToggleMirrorMode_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  DisplayControllerPtr.prototype.setDisplayWorkArea = function() {
    return DisplayControllerProxy.prototype.setDisplayWorkArea
        .apply(this.ptr.getProxy(), arguments);
  };

  DisplayControllerProxy.prototype.setDisplayWorkArea = function(display_id, size, insets) {
    var params = new DisplayController_SetDisplayWorkArea_Params();
    params.display_id = display_id;
    params.size = size;
    params.insets = insets;
    var builder = new codec.MessageBuilder(
        kDisplayController_SetDisplayWorkArea_Name,
        codec.align(DisplayController_SetDisplayWorkArea_Params.encodedSize));
    builder.encodeStruct(DisplayController_SetDisplayWorkArea_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DisplayControllerStub(delegate) {
    this.delegate_ = delegate;
  }
  DisplayControllerStub.prototype.increaseInternalDisplayZoom = function() {
    return this.delegate_ && this.delegate_.increaseInternalDisplayZoom && this.delegate_.increaseInternalDisplayZoom();
  }
  DisplayControllerStub.prototype.decreaseInternalDisplayZoom = function() {
    return this.delegate_ && this.delegate_.decreaseInternalDisplayZoom && this.delegate_.decreaseInternalDisplayZoom();
  }
  DisplayControllerStub.prototype.resetInternalDisplayZoom = function() {
    return this.delegate_ && this.delegate_.resetInternalDisplayZoom && this.delegate_.resetInternalDisplayZoom();
  }
  DisplayControllerStub.prototype.rotateCurrentDisplayCW = function() {
    return this.delegate_ && this.delegate_.rotateCurrentDisplayCW && this.delegate_.rotateCurrentDisplayCW();
  }
  DisplayControllerStub.prototype.swapPrimaryDisplay = function() {
    return this.delegate_ && this.delegate_.swapPrimaryDisplay && this.delegate_.swapPrimaryDisplay();
  }
  DisplayControllerStub.prototype.toggleMirrorMode = function() {
    return this.delegate_ && this.delegate_.toggleMirrorMode && this.delegate_.toggleMirrorMode();
  }
  DisplayControllerStub.prototype.setDisplayWorkArea = function(display_id, size, insets) {
    return this.delegate_ && this.delegate_.setDisplayWorkArea && this.delegate_.setDisplayWorkArea(display_id, size, insets);
  }

  DisplayControllerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDisplayController_IncreaseInternalDisplayZoom_Name:
      var params = reader.decodeStruct(DisplayController_IncreaseInternalDisplayZoom_Params);
      this.increaseInternalDisplayZoom();
      return true;
    case kDisplayController_DecreaseInternalDisplayZoom_Name:
      var params = reader.decodeStruct(DisplayController_DecreaseInternalDisplayZoom_Params);
      this.decreaseInternalDisplayZoom();
      return true;
    case kDisplayController_ResetInternalDisplayZoom_Name:
      var params = reader.decodeStruct(DisplayController_ResetInternalDisplayZoom_Params);
      this.resetInternalDisplayZoom();
      return true;
    case kDisplayController_RotateCurrentDisplayCW_Name:
      var params = reader.decodeStruct(DisplayController_RotateCurrentDisplayCW_Params);
      this.rotateCurrentDisplayCW();
      return true;
    case kDisplayController_SwapPrimaryDisplay_Name:
      var params = reader.decodeStruct(DisplayController_SwapPrimaryDisplay_Params);
      this.swapPrimaryDisplay();
      return true;
    case kDisplayController_ToggleMirrorMode_Name:
      var params = reader.decodeStruct(DisplayController_ToggleMirrorMode_Params);
      this.toggleMirrorMode();
      return true;
    case kDisplayController_SetDisplayWorkArea_Name:
      var params = reader.decodeStruct(DisplayController_SetDisplayWorkArea_Params);
      this.setDisplayWorkArea(params.display_id, params.size, params.insets);
      return true;
    default:
      return false;
    }
  };

  DisplayControllerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDisplayControllerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDisplayController_IncreaseInternalDisplayZoom_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayController_IncreaseInternalDisplayZoom_Params;
      break;
      case kDisplayController_DecreaseInternalDisplayZoom_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayController_DecreaseInternalDisplayZoom_Params;
      break;
      case kDisplayController_ResetInternalDisplayZoom_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayController_ResetInternalDisplayZoom_Params;
      break;
      case kDisplayController_RotateCurrentDisplayCW_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayController_RotateCurrentDisplayCW_Params;
      break;
      case kDisplayController_SwapPrimaryDisplay_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayController_SwapPrimaryDisplay_Params;
      break;
      case kDisplayController_ToggleMirrorMode_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayController_ToggleMirrorMode_Params;
      break;
      case kDisplayController_SetDisplayWorkArea_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DisplayController_SetDisplayWorkArea_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDisplayControllerResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var DisplayController = {
    name: 'display::mojom::DisplayController',
    ptrClass: DisplayControllerPtr,
    proxyClass: DisplayControllerProxy,
    stubClass: DisplayControllerStub,
    validateRequest: validateDisplayControllerRequest,
    validateResponse: null,
  };
  DisplayControllerStub.prototype.validator = validateDisplayControllerRequest;
  DisplayControllerProxy.prototype.validator = null;

  var exports = {};
  exports.DisplayController = DisplayController;
  exports.DisplayControllerPtr = DisplayControllerPtr;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/accessibility_manager.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function AccessibilityManager_SetHighContrastMode_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AccessibilityManager_SetHighContrastMode_Params.prototype.initDefaults_ = function() {
    this.enabled = false;
  };
  AccessibilityManager_SetHighContrastMode_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AccessibilityManager_SetHighContrastMode_Params.validate = function(messageValidator, offset) {
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

  AccessibilityManager_SetHighContrastMode_Params.encodedSize = codec.kStructHeaderSize + 8;

  AccessibilityManager_SetHighContrastMode_Params.decode = function(decoder) {
    var packed;
    var val = new AccessibilityManager_SetHighContrastMode_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.enabled = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  AccessibilityManager_SetHighContrastMode_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AccessibilityManager_SetHighContrastMode_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.enabled & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kAccessibilityManager_SetHighContrastMode_Name = 0;

  function AccessibilityManagerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(AccessibilityManager,
                                                   handleOrPtrInfo);
  }

  function AccessibilityManagerProxy(receiver) {
    this.receiver_ = receiver;
  }
  AccessibilityManagerPtr.prototype.setHighContrastMode = function() {
    return AccessibilityManagerProxy.prototype.setHighContrastMode
        .apply(this.ptr.getProxy(), arguments);
  };

  AccessibilityManagerProxy.prototype.setHighContrastMode = function(enabled) {
    var params = new AccessibilityManager_SetHighContrastMode_Params();
    params.enabled = enabled;
    var builder = new codec.MessageBuilder(
        kAccessibilityManager_SetHighContrastMode_Name,
        codec.align(AccessibilityManager_SetHighContrastMode_Params.encodedSize));
    builder.encodeStruct(AccessibilityManager_SetHighContrastMode_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function AccessibilityManagerStub(delegate) {
    this.delegate_ = delegate;
  }
  AccessibilityManagerStub.prototype.setHighContrastMode = function(enabled) {
    return this.delegate_ && this.delegate_.setHighContrastMode && this.delegate_.setHighContrastMode(enabled);
  }

  AccessibilityManagerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAccessibilityManager_SetHighContrastMode_Name:
      var params = reader.decodeStruct(AccessibilityManager_SetHighContrastMode_Params);
      this.setHighContrastMode(params.enabled);
      return true;
    default:
      return false;
    }
  };

  AccessibilityManagerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateAccessibilityManagerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kAccessibilityManager_SetHighContrastMode_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AccessibilityManager_SetHighContrastMode_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateAccessibilityManagerResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var AccessibilityManager = {
    name: 'ui::mojom::AccessibilityManager',
    ptrClass: AccessibilityManagerPtr,
    proxyClass: AccessibilityManagerProxy,
    stubClass: AccessibilityManagerStub,
    validateRequest: validateAccessibilityManagerRequest,
    validateResponse: null,
  };
  AccessibilityManagerStub.prototype.validator = validateAccessibilityManagerRequest;
  AccessibilityManagerProxy.prototype.validator = null;

  var exports = {};
  exports.AccessibilityManager = AccessibilityManager;
  exports.AccessibilityManagerPtr = AccessibilityManagerPtr;

  return exports;
});
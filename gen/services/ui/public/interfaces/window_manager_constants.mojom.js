// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/window_manager_constants.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/ui/public/interfaces/display/display.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, display$, geometry$) {
  var kResizeBehaviorNone = 0;
  var kResizeBehaviorCanResize = 1;
  var kResizeBehaviorCanMaximize = 2;
  var kResizeBehaviorCanMinimize = 4;
  var WindowManagerErrorCode = {};
  WindowManagerErrorCode.SUCCESS = 0;
  WindowManagerErrorCode.ACCESS_DENIED = WindowManagerErrorCode.SUCCESS + 1;

  WindowManagerErrorCode.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  WindowManagerErrorCode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var ShowState = {};
  ShowState.DEFAULT = 0;
  ShowState.NORMAL = ShowState.DEFAULT + 1;
  ShowState.MINIMIZED = ShowState.NORMAL + 1;
  ShowState.MAXIMIZED = ShowState.MINIMIZED + 1;
  ShowState.INACTIVE = ShowState.MAXIMIZED + 1;
  ShowState.FULLSCREEN = ShowState.INACTIVE + 1;
  ShowState.DOCKED = ShowState.FULLSCREEN + 1;

  ShowState.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    }
    return false;
  };

  ShowState.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var MoveLoopSource = {};
  MoveLoopSource.MOUSE = 0;
  MoveLoopSource.TOUCH = MoveLoopSource.MOUSE + 1;

  MoveLoopSource.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  MoveLoopSource.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var WindowType = {};
  WindowType.WINDOW = 0;
  WindowType.PANEL = WindowType.WINDOW + 1;
  WindowType.WINDOW_FRAMELESS = WindowType.PANEL + 1;
  WindowType.CONTROL = WindowType.WINDOW_FRAMELESS + 1;
  WindowType.POPUP = WindowType.CONTROL + 1;
  WindowType.MENU = WindowType.POPUP + 1;
  WindowType.TOOLTIP = WindowType.MENU + 1;
  WindowType.BUBBLE = WindowType.TOOLTIP + 1;
  WindowType.DRAG = WindowType.BUBBLE + 1;
  WindowType.UNKNOWN = WindowType.DRAG + 1;

  WindowType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      return true;
    }
    return false;
  };

  WindowType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function FrameDecorationValues(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FrameDecorationValues.prototype.initDefaults_ = function() {
    this.normal_client_area_insets = null;
    this.maximized_client_area_insets = null;
    this.max_title_bar_button_width = 0;
  };
  FrameDecorationValues.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FrameDecorationValues.validate = function(messageValidator, offset) {
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


    
    // validate FrameDecorationValues.normal_client_area_insets
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.Insets, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FrameDecorationValues.maximized_client_area_insets
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Insets, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  FrameDecorationValues.encodedSize = codec.kStructHeaderSize + 24;

  FrameDecorationValues.decode = function(decoder) {
    var packed;
    var val = new FrameDecorationValues();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.normal_client_area_insets = decoder.decodeStructPointer(geometry$.Insets);
    val.maximized_client_area_insets = decoder.decodeStructPointer(geometry$.Insets);
    val.max_title_bar_button_width = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FrameDecorationValues.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FrameDecorationValues.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.Insets, val.normal_client_area_insets);
    encoder.encodeStructPointer(geometry$.Insets, val.maximized_client_area_insets);
    encoder.encodeStruct(codec.Uint32, val.max_title_bar_button_width);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function WsDisplay(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WsDisplay.prototype.initDefaults_ = function() {
    this.display = null;
    this.frame_decoration_values = null;
  };
  WsDisplay.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WsDisplay.validate = function(messageValidator, offset) {
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


    
    // validate WsDisplay.display
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, display$.Display, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WsDisplay.frame_decoration_values
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, FrameDecorationValues, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WsDisplay.encodedSize = codec.kStructHeaderSize + 16;

  WsDisplay.decode = function(decoder) {
    var packed;
    var val = new WsDisplay();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.display = decoder.decodeStructPointer(display$.Display);
    val.frame_decoration_values = decoder.decodeStructPointer(FrameDecorationValues);
    return val;
  };

  WsDisplay.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WsDisplay.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(display$.Display, val.display);
    encoder.encodeStructPointer(FrameDecorationValues, val.frame_decoration_values);
  };

  var exports = {};
  exports.kResizeBehaviorNone = kResizeBehaviorNone;
  exports.kResizeBehaviorCanResize = kResizeBehaviorCanResize;
  exports.kResizeBehaviorCanMaximize = kResizeBehaviorCanMaximize;
  exports.kResizeBehaviorCanMinimize = kResizeBehaviorCanMinimize;
  exports.WindowManagerErrorCode = WindowManagerErrorCode;
  exports.ShowState = ShowState;
  exports.MoveLoopSource = MoveLoopSource;
  exports.WindowType = WindowType;
  exports.FrameDecorationValues = FrameDecorationValues;
  exports.WsDisplay = WsDisplay;

  return exports;
});
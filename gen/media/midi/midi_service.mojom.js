// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/midi/midi_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var Result = {};
  Result.NOT_INITIALIZED = 0;
  Result.OK = Result.NOT_INITIALIZED + 1;
  Result.NOT_SUPPORTED = Result.OK + 1;
  Result.INITIALIZATION_ERROR = Result.NOT_SUPPORTED + 1;
  Result.MAX = Result.INITIALIZATION_ERROR;

  Result.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  Result.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PortState = {};
  PortState.DISCONNECTED = 0;
  PortState.CONNECTED = PortState.DISCONNECTED + 1;
  PortState.OPENED = PortState.CONNECTED + 1;
  PortState.LAST = PortState.OPENED;

  PortState.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  PortState.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.Result = Result;
  exports.PortState = PortState;

  return exports;
});
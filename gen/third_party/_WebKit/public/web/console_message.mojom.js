// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/web/console_message.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var ConsoleMessageLevel = {};
  ConsoleMessageLevel.Debug = 4;
  ConsoleMessageLevel.Log = 1;
  ConsoleMessageLevel.Info = 5;
  ConsoleMessageLevel.Warning = 2;
  ConsoleMessageLevel.Error = 3;

  ConsoleMessageLevel.isKnownEnumValue = function(value) {
    switch (value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    }
    return false;
  };

  ConsoleMessageLevel.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.ConsoleMessageLevel = ConsoleMessageLevel;

  return exports;
});
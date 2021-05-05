// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("content/public/common/window_container_type.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var WindowContainerType = {};
  WindowContainerType.NORMAL = 0;
  WindowContainerType.BACKGROUND = WindowContainerType.NORMAL + 1;
  WindowContainerType.PERSISTENT = WindowContainerType.BACKGROUND + 1;

  WindowContainerType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  WindowContainerType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.WindowContainerType = WindowContainerType;

  return exports;
});
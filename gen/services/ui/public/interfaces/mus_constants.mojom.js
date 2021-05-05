// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/mus_constants.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var OrderDirection = {};
  OrderDirection.ABOVE = 1;
  OrderDirection.BELOW = OrderDirection.ABOVE + 1;

  OrderDirection.isKnownEnumValue = function(value) {
    switch (value) {
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  OrderDirection.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.OrderDirection = OrderDirection;

  return exports;
});
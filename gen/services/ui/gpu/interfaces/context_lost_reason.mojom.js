// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/gpu/interfaces/context_lost_reason.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var ContextLostReason = {};
  ContextLostReason.GUILTY = 0;
  ContextLostReason.INNOCENT = ContextLostReason.GUILTY + 1;
  ContextLostReason.UNKNOWN = ContextLostReason.INNOCENT + 1;
  ContextLostReason.OUT_OF_MEMORY = ContextLostReason.UNKNOWN + 1;
  ContextLostReason.MAKE_CURRENT_FAILED = ContextLostReason.OUT_OF_MEMORY + 1;
  ContextLostReason.GPU_CHANNEL_LOST = ContextLostReason.MAKE_CURRENT_FAILED + 1;
  ContextLostReason.INVALID_GPU_MESSAGE = ContextLostReason.GPU_CHANNEL_LOST + 1;

  ContextLostReason.isKnownEnumValue = function(value) {
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

  ContextLostReason.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.ContextLostReason = ContextLostReason;

  return exports;
});
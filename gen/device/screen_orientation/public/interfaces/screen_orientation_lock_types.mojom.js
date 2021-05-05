// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/screen_orientation/public/interfaces/screen_orientation_lock_types.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var ScreenOrientationLockResult = {};
  ScreenOrientationLockResult.SCREEN_ORIENTATION_LOCK_RESULT_SUCCESS = 0;
  ScreenOrientationLockResult.SCREEN_ORIENTATION_LOCK_RESULT_ERROR_NOT_AVAILABLE = ScreenOrientationLockResult.SCREEN_ORIENTATION_LOCK_RESULT_SUCCESS + 1;
  ScreenOrientationLockResult.SCREEN_ORIENTATION_LOCK_RESULT_ERROR_FULLSCREEN_REQUIRED = ScreenOrientationLockResult.SCREEN_ORIENTATION_LOCK_RESULT_ERROR_NOT_AVAILABLE + 1;
  ScreenOrientationLockResult.SCREEN_ORIENTATION_LOCK_RESULT_ERROR_CANCELED = ScreenOrientationLockResult.SCREEN_ORIENTATION_LOCK_RESULT_ERROR_FULLSCREEN_REQUIRED + 1;

  ScreenOrientationLockResult.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  ScreenOrientationLockResult.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var ScreenOrientationLockType = {};
  ScreenOrientationLockType.DEFAULT = 0;
  ScreenOrientationLockType.PORTRAIT_PRIMARY = ScreenOrientationLockType.DEFAULT + 1;
  ScreenOrientationLockType.PORTRAIT_SECONDARY = ScreenOrientationLockType.PORTRAIT_PRIMARY + 1;
  ScreenOrientationLockType.LANDSCAPE_PRIMARY = ScreenOrientationLockType.PORTRAIT_SECONDARY + 1;
  ScreenOrientationLockType.LANDSCAPE_SECONDARY = ScreenOrientationLockType.LANDSCAPE_PRIMARY + 1;
  ScreenOrientationLockType.ANY = ScreenOrientationLockType.LANDSCAPE_SECONDARY + 1;
  ScreenOrientationLockType.LANDSCAPE = ScreenOrientationLockType.ANY + 1;
  ScreenOrientationLockType.PORTRAIT = ScreenOrientationLockType.LANDSCAPE + 1;
  ScreenOrientationLockType.NATURAL = ScreenOrientationLockType.PORTRAIT + 1;

  ScreenOrientationLockType.isKnownEnumValue = function(value) {
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
      return true;
    }
    return false;
  };

  ScreenOrientationLockType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.ScreenOrientationLockResult = ScreenOrientationLockResult;
  exports.ScreenOrientationLockType = ScreenOrientationLockType;

  return exports;
});
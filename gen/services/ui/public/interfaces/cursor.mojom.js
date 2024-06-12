// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/cursor.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var Cursor = {};
  Cursor.CURSOR_NULL = 0;
  Cursor.POINTER = Cursor.CURSOR_NULL + 1;
  Cursor.CROSS = Cursor.POINTER + 1;
  Cursor.HAND = Cursor.CROSS + 1;
  Cursor.IBEAM = Cursor.HAND + 1;
  Cursor.WAIT = Cursor.IBEAM + 1;
  Cursor.HELP = Cursor.WAIT + 1;
  Cursor.EAST_RESIZE = Cursor.HELP + 1;
  Cursor.NORTH_RESIZE = Cursor.EAST_RESIZE + 1;
  Cursor.NORTH_EAST_RESIZE = Cursor.NORTH_RESIZE + 1;
  Cursor.NORTH_WEST_RESIZE = Cursor.NORTH_EAST_RESIZE + 1;
  Cursor.SOUTH_RESIZE = Cursor.NORTH_WEST_RESIZE + 1;
  Cursor.SOUTH_EAST_RESIZE = Cursor.SOUTH_RESIZE + 1;
  Cursor.SOUTH_WEST_RESIZE = Cursor.SOUTH_EAST_RESIZE + 1;
  Cursor.WEST_RESIZE = Cursor.SOUTH_WEST_RESIZE + 1;
  Cursor.NORTH_SOUTH_RESIZE = Cursor.WEST_RESIZE + 1;
  Cursor.EAST_WEST_RESIZE = Cursor.NORTH_SOUTH_RESIZE + 1;
  Cursor.NORTH_EAST_SOUTH_WEST_RESIZE = Cursor.EAST_WEST_RESIZE + 1;
  Cursor.NORTH_WEST_SOUTH_EAST_RESIZE = Cursor.NORTH_EAST_SOUTH_WEST_RESIZE + 1;
  Cursor.COLUMN_RESIZE = Cursor.NORTH_WEST_SOUTH_EAST_RESIZE + 1;
  Cursor.ROW_RESIZE = Cursor.COLUMN_RESIZE + 1;
  Cursor.MIDDLE_PANNING = Cursor.ROW_RESIZE + 1;
  Cursor.EAST_PANNING = Cursor.MIDDLE_PANNING + 1;
  Cursor.NORTH_PANNING = Cursor.EAST_PANNING + 1;
  Cursor.NORTH_EAST_PANNING = Cursor.NORTH_PANNING + 1;
  Cursor.NORTH_WEST_PANNING = Cursor.NORTH_EAST_PANNING + 1;
  Cursor.SOUTH_PANNING = Cursor.NORTH_WEST_PANNING + 1;
  Cursor.SOUTH_EAST_PANNING = Cursor.SOUTH_PANNING + 1;
  Cursor.SOUTH_WEST_PANNING = Cursor.SOUTH_EAST_PANNING + 1;
  Cursor.WEST_PANNING = Cursor.SOUTH_WEST_PANNING + 1;
  Cursor.MOVE = Cursor.WEST_PANNING + 1;
  Cursor.VERTICAL_TEXT = Cursor.MOVE + 1;
  Cursor.CELL = Cursor.VERTICAL_TEXT + 1;
  Cursor.CONTEXT_MENU = Cursor.CELL + 1;
  Cursor.ALIAS = Cursor.CONTEXT_MENU + 1;
  Cursor.PROGRESS = Cursor.ALIAS + 1;
  Cursor.NO_DROP = Cursor.PROGRESS + 1;
  Cursor.COPY = Cursor.NO_DROP + 1;
  Cursor.NONE = Cursor.COPY + 1;
  Cursor.NOT_ALLOWED = Cursor.NONE + 1;
  Cursor.ZOOM_IN = Cursor.NOT_ALLOWED + 1;
  Cursor.ZOOM_OUT = Cursor.ZOOM_IN + 1;
  Cursor.GRAB = Cursor.ZOOM_OUT + 1;
  Cursor.GRABBING = Cursor.GRAB + 1;
  Cursor.CUSTOM = Cursor.GRABBING + 1;

  Cursor.isKnownEnumValue = function(value) {
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
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
      return true;
    }
    return false;
  };

  Cursor.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };


  var exports = {};
  exports.Cursor = Cursor;

  return exports;
});
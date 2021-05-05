// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/web/window_features.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function WindowFeatures(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowFeatures.prototype.initDefaults_ = function() {
    this.x = 0;
    this.has_x = false;
    this.has_y = false;
    this.has_width = false;
    this.has_height = false;
    this.menu_bar_visible = true;
    this.status_bar_visible = true;
    this.tool_bar_visible = true;
    this.location_bar_visible = true;
    this.scrollbars_visible = true;
    this.resizable = true;
    this.fullscreen = false;
    this.dialog = false;
    this.y = 0;
    this.width = 0;
    this.height = 0;
  };
  WindowFeatures.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowFeatures.validate = function(messageValidator, offset) {
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

















    return validator.validationError.NONE;
  };

  WindowFeatures.encodedSize = codec.kStructHeaderSize + 24;

  WindowFeatures.decode = function(decoder) {
    var packed;
    var val = new WindowFeatures();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.x = decoder.decodeStruct(codec.Float);
    packed = decoder.readUint8();
    val.has_x = (packed >> 0) & 1 ? true : false;
    val.has_y = (packed >> 1) & 1 ? true : false;
    val.has_width = (packed >> 2) & 1 ? true : false;
    val.has_height = (packed >> 3) & 1 ? true : false;
    val.menu_bar_visible = (packed >> 4) & 1 ? true : false;
    val.status_bar_visible = (packed >> 5) & 1 ? true : false;
    val.tool_bar_visible = (packed >> 6) & 1 ? true : false;
    val.location_bar_visible = (packed >> 7) & 1 ? true : false;
    packed = decoder.readUint8();
    val.scrollbars_visible = (packed >> 0) & 1 ? true : false;
    val.resizable = (packed >> 1) & 1 ? true : false;
    val.fullscreen = (packed >> 2) & 1 ? true : false;
    val.dialog = (packed >> 3) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    val.y = decoder.decodeStruct(codec.Float);
    val.width = decoder.decodeStruct(codec.Float);
    val.height = decoder.decodeStruct(codec.Float);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowFeatures.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowFeatures.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.x);
    packed = 0;
    packed |= (val.has_x & 1) << 0
    packed |= (val.has_y & 1) << 1
    packed |= (val.has_width & 1) << 2
    packed |= (val.has_height & 1) << 3
    packed |= (val.menu_bar_visible & 1) << 4
    packed |= (val.status_bar_visible & 1) << 5
    packed |= (val.tool_bar_visible & 1) << 6
    packed |= (val.location_bar_visible & 1) << 7
    encoder.writeUint8(packed);
    packed = 0;
    packed |= (val.scrollbars_visible & 1) << 0
    packed |= (val.resizable & 1) << 1
    packed |= (val.fullscreen & 1) << 2
    packed |= (val.dialog & 1) << 3
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Float, val.y);
    encoder.encodeStruct(codec.Float, val.width);
    encoder.encodeStruct(codec.Float, val.height);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.WindowFeatures = WindowFeatures;

  return exports;
});
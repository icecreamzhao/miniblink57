// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/gfx/mojo/accelerated_widget.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function AcceleratedWidget(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AcceleratedWidget.prototype.initDefaults_ = function() {
    this.widget = 0;
  };
  AcceleratedWidget.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AcceleratedWidget.validate = function(messageValidator, offset) {
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

  AcceleratedWidget.encodedSize = codec.kStructHeaderSize + 8;

  AcceleratedWidget.decode = function(decoder) {
    var packed;
    var val = new AcceleratedWidget();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.widget = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  AcceleratedWidget.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AcceleratedWidget.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.widget);
  };

  var exports = {};
  exports.AcceleratedWidget = AcceleratedWidget;

  return exports;
});
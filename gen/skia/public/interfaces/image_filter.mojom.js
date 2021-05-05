// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("skia/public/interfaces/image_filter.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function ImageFilter(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ImageFilter.prototype.initDefaults_ = function() {
    this.data = null;
  };
  ImageFilter.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ImageFilter.validate = function(messageValidator, offset) {
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


    
    // validate ImageFilter.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ImageFilter.encodedSize = codec.kStructHeaderSize + 8;

  ImageFilter.decode = function(decoder) {
    var packed;
    var val = new ImageFilter();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  ImageFilter.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ImageFilter.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };

  var exports = {};
  exports.ImageFilter = ImageFilter;

  return exports;
});
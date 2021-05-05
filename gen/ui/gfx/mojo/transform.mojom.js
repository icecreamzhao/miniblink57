// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/gfx/mojo/transform.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Transform(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Transform.prototype.initDefaults_ = function() {
    this.matrix = null;
  };
  Transform.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Transform.validate = function(messageValidator, offset) {
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


    
    // validate Transform.matrix
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 4, codec.Float, true, [16], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Transform.encodedSize = codec.kStructHeaderSize + 8;

  Transform.decode = function(decoder) {
    var packed;
    var val = new Transform();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.matrix = decoder.decodeArrayPointer(codec.Float);
    return val;
  };

  Transform.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Transform.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Float, val.matrix);
  };

  var exports = {};
  exports.Transform = Transform;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("mojo/common/version.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Version(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Version.prototype.initDefaults_ = function() {
    this.components = null;
  };
  Version.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Version.validate = function(messageValidator, offset) {
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


    
    // validate Version.components
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 4, codec.Uint32, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Version.encodedSize = codec.kStructHeaderSize + 8;

  Version.decode = function(decoder) {
    var packed;
    var val = new Version();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.components = decoder.decodeArrayPointer(codec.Uint32);
    return val;
  };

  Version.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Version.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint32, val.components);
  };

  var exports = {};
  exports.Version = Version;

  return exports;
});
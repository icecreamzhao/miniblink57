// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("mojo/common/file.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function File(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File.prototype.initDefaults_ = function() {
    this.fd = null;
  };
  File.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File.validate = function(messageValidator, offset) {
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


    
    // validate File.fd
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File.encodedSize = codec.kStructHeaderSize + 8;

  File.decode = function(decoder) {
    var packed;
    var val = new File();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.fd = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.fd);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.File = File;

  return exports;
});
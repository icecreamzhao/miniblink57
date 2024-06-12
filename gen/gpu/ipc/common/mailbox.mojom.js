// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("gpu/ipc/common/mailbox.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Mailbox(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Mailbox.prototype.initDefaults_ = function() {
    this.name = null;
  };
  Mailbox.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Mailbox.validate = function(messageValidator, offset) {
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


    
    // validate Mailbox.name
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Int8, false, [16], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Mailbox.encodedSize = codec.kStructHeaderSize + 8;

  Mailbox.decode = function(decoder) {
    var packed;
    var val = new Mailbox();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeArrayPointer(codec.Int8);
    return val;
  };

  Mailbox.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Mailbox.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Int8, val.name);
  };

  var exports = {};
  exports.Mailbox = Mailbox;

  return exports;
});
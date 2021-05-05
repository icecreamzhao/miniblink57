// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/bluetooth/public/interfaces/uuid.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function UUID(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  UUID.prototype.initDefaults_ = function() {
    this.uuid = null;
  };
  UUID.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  UUID.validate = function(messageValidator, offset) {
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


    
    // validate UUID.uuid
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  UUID.encodedSize = codec.kStructHeaderSize + 8;

  UUID.decode = function(decoder) {
    var packed;
    var val = new UUID();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.uuid = decoder.decodeStruct(codec.String);
    return val;
  };

  UUID.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(UUID.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.uuid);
  };

  var exports = {};
  exports.UUID = UUID;

  return exports;
});
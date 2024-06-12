// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/local_frame_id.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "mojo/common/unguessable_token.mojom",
], function(bindings, codec, core, validator, unguessable_token$) {

  function LocalFrameId(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LocalFrameId.prototype.initDefaults_ = function() {
    this.local_id = 0;
    this.nonce = null;
  };
  LocalFrameId.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LocalFrameId.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate LocalFrameId.nonce
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LocalFrameId.encodedSize = codec.kStructHeaderSize + 16;

  LocalFrameId.decode = function(decoder) {
    var packed;
    var val = new LocalFrameId();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.local_id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.nonce = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LocalFrameId.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LocalFrameId.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.local_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.nonce);
  };

  var exports = {};
  exports.LocalFrameId = LocalFrameId;

  return exports;
});
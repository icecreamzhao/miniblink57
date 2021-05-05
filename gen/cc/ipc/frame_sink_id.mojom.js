// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/frame_sink_id.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function FrameSinkId(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FrameSinkId.prototype.initDefaults_ = function() {
    this.client_id = 0;
    this.sink_id = 0;
  };
  FrameSinkId.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FrameSinkId.validate = function(messageValidator, offset) {
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

  FrameSinkId.encodedSize = codec.kStructHeaderSize + 8;

  FrameSinkId.decode = function(decoder) {
    var packed;
    var val = new FrameSinkId();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client_id = decoder.decodeStruct(codec.Uint32);
    val.sink_id = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  FrameSinkId.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FrameSinkId.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.client_id);
    encoder.encodeStruct(codec.Uint32, val.sink_id);
  };

  var exports = {};
  exports.FrameSinkId = FrameSinkId;

  return exports;
});
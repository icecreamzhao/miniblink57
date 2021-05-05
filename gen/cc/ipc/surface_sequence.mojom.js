// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/surface_sequence.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/frame_sink_id.mojom",
], function(bindings, codec, core, validator, frame_sink_id$) {

  function SurfaceSequence(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SurfaceSequence.prototype.initDefaults_ = function() {
    this.frame_sink_id = null;
    this.sequence = 0;
  };
  SurfaceSequence.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SurfaceSequence.validate = function(messageValidator, offset) {
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


    
    // validate SurfaceSequence.frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  SurfaceSequence.encodedSize = codec.kStructHeaderSize + 16;

  SurfaceSequence.decode = function(decoder) {
    var packed;
    var val = new SurfaceSequence();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    val.sequence = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  SurfaceSequence.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SurfaceSequence.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.frame_sink_id);
    encoder.encodeStruct(codec.Uint32, val.sequence);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.SurfaceSequence = SurfaceSequence;

  return exports;
});
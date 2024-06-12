// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/surface_id.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/frame_sink_id.mojom",
    "cc/ipc/local_frame_id.mojom",
], function(bindings, codec, core, validator, frame_sink_id$, local_frame_id$) {

  function SurfaceId(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SurfaceId.prototype.initDefaults_ = function() {
    this.frame_sink_id = null;
    this.local_frame_id = null;
  };
  SurfaceId.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SurfaceId.validate = function(messageValidator, offset) {
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


    
    // validate SurfaceId.frame_sink_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, frame_sink_id$.FrameSinkId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SurfaceId.local_frame_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, local_frame_id$.LocalFrameId, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  SurfaceId.encodedSize = codec.kStructHeaderSize + 16;

  SurfaceId.decode = function(decoder) {
    var packed;
    var val = new SurfaceId();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_sink_id = decoder.decodeStructPointer(frame_sink_id$.FrameSinkId);
    val.local_frame_id = decoder.decodeStructPointer(local_frame_id$.LocalFrameId);
    return val;
  };

  SurfaceId.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SurfaceId.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(frame_sink_id$.FrameSinkId, val.frame_sink_id);
    encoder.encodeStructPointer(local_frame_id$.LocalFrameId, val.local_frame_id);
  };

  var exports = {};
  exports.SurfaceId = SurfaceId;

  return exports;
});
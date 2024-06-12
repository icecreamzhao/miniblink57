// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/surface_info.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/surface_id.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, surface_id$, geometry$) {

  function SurfaceInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SurfaceInfo.prototype.initDefaults_ = function() {
    this.surface_id = null;
    this.device_scale_factor = 0;
    this.size_in_pixels = null;
  };
  SurfaceInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SurfaceInfo.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 32}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SurfaceInfo.surface_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_id$.SurfaceId, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate SurfaceInfo.size_in_pixels
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  SurfaceInfo.encodedSize = codec.kStructHeaderSize + 24;

  SurfaceInfo.decode = function(decoder) {
    var packed;
    var val = new SurfaceInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.surface_id = decoder.decodeStructPointer(surface_id$.SurfaceId);
    val.device_scale_factor = decoder.decodeStruct(codec.Float);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.size_in_pixels = decoder.decodeStructPointer(geometry$.Size);
    return val;
  };

  SurfaceInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SurfaceInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_id$.SurfaceId, val.surface_id);
    encoder.encodeStruct(codec.Float, val.device_scale_factor);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Size, val.size_in_pixels);
  };

  var exports = {};
  exports.SurfaceInfo = SurfaceInfo;

  return exports;
});
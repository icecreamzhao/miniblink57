// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("gpu/ipc/common/surface_handle.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function SurfaceHandle(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SurfaceHandle.prototype.initDefaults_ = function() {
    this.surface_handle = 0;
  };
  SurfaceHandle.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SurfaceHandle.validate = function(messageValidator, offset) {
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

  SurfaceHandle.encodedSize = codec.kStructHeaderSize + 8;

  SurfaceHandle.decode = function(decoder) {
    var packed;
    var val = new SurfaceHandle();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.surface_handle = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  SurfaceHandle.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SurfaceHandle.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.surface_handle);
  };

  var exports = {};
  exports.SurfaceHandle = SurfaceHandle;

  return exports;
});
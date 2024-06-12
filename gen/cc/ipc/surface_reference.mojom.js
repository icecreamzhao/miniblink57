// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/surface_reference.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/surface_id.mojom",
], function(bindings, codec, core, validator, surface_id$) {

  function SurfaceReference(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SurfaceReference.prototype.initDefaults_ = function() {
    this.parent_id = null;
    this.child_id = null;
  };
  SurfaceReference.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SurfaceReference.validate = function(messageValidator, offset) {
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


    
    // validate SurfaceReference.parent_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, surface_id$.SurfaceId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate SurfaceReference.child_id
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, surface_id$.SurfaceId, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  SurfaceReference.encodedSize = codec.kStructHeaderSize + 16;

  SurfaceReference.decode = function(decoder) {
    var packed;
    var val = new SurfaceReference();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.parent_id = decoder.decodeStructPointer(surface_id$.SurfaceId);
    val.child_id = decoder.decodeStructPointer(surface_id$.SurfaceId);
    return val;
  };

  SurfaceReference.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SurfaceReference.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(surface_id$.SurfaceId, val.parent_id);
    encoder.encodeStructPointer(surface_id$.SurfaceId, val.child_id);
  };

  var exports = {};
  exports.SurfaceReference = SurfaceReference;

  return exports;
});
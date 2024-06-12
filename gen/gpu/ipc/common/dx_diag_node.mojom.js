// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("gpu/ipc/common/dx_diag_node.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function DxDiagNode(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DxDiagNode.prototype.initDefaults_ = function() {
    this.values = null;
    this.children = null;
  };
  DxDiagNode.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DxDiagNode.validate = function(messageValidator, offset) {
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


    
    // validate DxDiagNode.values
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 0, false, codec.String, codec.String, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DxDiagNode.children
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, false, codec.String, new codec.PointerTo(DxDiagNode), false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DxDiagNode.encodedSize = codec.kStructHeaderSize + 16;

  DxDiagNode.decode = function(decoder) {
    var packed;
    var val = new DxDiagNode();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.values = decoder.decodeMapPointer(codec.String, codec.String);
    val.children = decoder.decodeMapPointer(codec.String, new codec.PointerTo(DxDiagNode));
    return val;
  };

  DxDiagNode.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DxDiagNode.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeMapPointer(codec.String, codec.String, val.values);
    encoder.encodeMapPointer(codec.String, new codec.PointerTo(DxDiagNode), val.children);
  };

  var exports = {};
  exports.DxDiagNode = DxDiagNode;

  return exports;
});
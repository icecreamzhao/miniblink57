// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/filter_operations.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/filter_operation.mojom",
], function(bindings, codec, core, validator, filter_operation$) {

  function FilterOperations(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FilterOperations.prototype.initDefaults_ = function() {
    this.operations = null;
  };
  FilterOperations.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FilterOperations.validate = function(messageValidator, offset) {
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


    
    // validate FilterOperations.operations
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(filter_operation$.FilterOperation), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FilterOperations.encodedSize = codec.kStructHeaderSize + 8;

  FilterOperations.decode = function(decoder) {
    var packed;
    var val = new FilterOperations();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.operations = decoder.decodeArrayPointer(new codec.PointerTo(filter_operation$.FilterOperation));
    return val;
  };

  FilterOperations.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FilterOperations.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(filter_operation$.FilterOperation), val.operations);
  };

  var exports = {};
  exports.FilterOperations = FilterOperations;

  return exports;
});
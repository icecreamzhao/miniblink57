// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/gfx/range/mojo/range.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Range(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Range.prototype.initDefaults_ = function() {
    this.start = 0;
    this.end = 0;
  };
  Range.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Range.validate = function(messageValidator, offset) {
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

  Range.encodedSize = codec.kStructHeaderSize + 8;

  Range.decode = function(decoder) {
    var packed;
    var val = new Range();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.start = decoder.decodeStruct(codec.Uint32);
    val.end = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  Range.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Range.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.start);
    encoder.encodeStruct(codec.Uint32, val.end);
  };
  function RangeF(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RangeF.prototype.initDefaults_ = function() {
    this.start = 0;
    this.end = 0;
  };
  RangeF.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RangeF.validate = function(messageValidator, offset) {
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

  RangeF.encodedSize = codec.kStructHeaderSize + 8;

  RangeF.decode = function(decoder) {
    var packed;
    var val = new RangeF();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.start = decoder.decodeStruct(codec.Float);
    val.end = decoder.decodeStruct(codec.Float);
    return val;
  };

  RangeF.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RangeF.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.start);
    encoder.encodeStruct(codec.Float, val.end);
  };

  var exports = {};
  exports.Range = Range;
  exports.RangeF = RangeF;

  return exports;
});
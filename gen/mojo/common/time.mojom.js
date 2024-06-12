// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("mojo/common/time.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Time(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Time.prototype.initDefaults_ = function() {
  };
  Time.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Time.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Time.encodedSize = codec.kStructHeaderSize + 0;

  Time.decode = function(decoder) {
    var packed;
    var val = new Time();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Time.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Time.encodedSize);
    encoder.writeUint32(0);
  };
  function TimeDelta(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TimeDelta.prototype.initDefaults_ = function() {
    this.microseconds = 0;
  };
  TimeDelta.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TimeDelta.validate = function(messageValidator, offset) {
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

  TimeDelta.encodedSize = codec.kStructHeaderSize + 8;

  TimeDelta.decode = function(decoder) {
    var packed;
    var val = new TimeDelta();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.microseconds = decoder.decodeStruct(codec.Int64);
    return val;
  };

  TimeDelta.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TimeDelta.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.microseconds);
  };
  function TimeTicks(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TimeTicks.prototype.initDefaults_ = function() {
  };
  TimeTicks.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TimeTicks.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TimeTicks.encodedSize = codec.kStructHeaderSize + 0;

  TimeTicks.decode = function(decoder) {
    var packed;
    var val = new TimeTicks();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  TimeTicks.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TimeTicks.encodedSize);
    encoder.writeUint32(0);
  };

  var exports = {};
  exports.Time = Time;
  exports.TimeDelta = TimeDelta;
  exports.TimeTicks = TimeTicks;

  return exports;
});
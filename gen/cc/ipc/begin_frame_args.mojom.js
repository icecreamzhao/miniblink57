// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/begin_frame_args.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "mojo/common/time.mojom",
], function(bindings, codec, core, validator, time$) {
  var BeginFrameArgsType = {};
  BeginFrameArgsType.INVALID = 0;
  BeginFrameArgsType.NORMAL = BeginFrameArgsType.INVALID + 1;
  BeginFrameArgsType.MISSED = BeginFrameArgsType.NORMAL + 1;
  BeginFrameArgsType.BEGIN_FRAME_ARGS_TYPE_MAX = BeginFrameArgsType.MISSED + 1;

  BeginFrameArgsType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  BeginFrameArgsType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function BeginFrameArgs(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BeginFrameArgs.prototype.initDefaults_ = function() {
    this.frame_time = null;
    this.deadline = null;
    this.interval = null;
    this.sequence_number = 0;
    this.source_id = 0;
    this.type = 0;
    this.on_critical_path = false;
  };
  BeginFrameArgs.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BeginFrameArgs.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 56}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BeginFrameArgs.frame_time
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, time$.TimeTicks, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BeginFrameArgs.deadline
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, time$.TimeTicks, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BeginFrameArgs.interval
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;




    
    // validate BeginFrameArgs.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 36, BeginFrameArgsType);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  BeginFrameArgs.encodedSize = codec.kStructHeaderSize + 48;

  BeginFrameArgs.decode = function(decoder) {
    var packed;
    var val = new BeginFrameArgs();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_time = decoder.decodeStructPointer(time$.TimeTicks);
    val.deadline = decoder.decodeStructPointer(time$.TimeTicks);
    val.interval = decoder.decodeStructPointer(time$.TimeDelta);
    val.sequence_number = decoder.decodeStruct(codec.Uint64);
    val.source_id = decoder.decodeStruct(codec.Uint32);
    val.type = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.on_critical_path = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  BeginFrameArgs.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BeginFrameArgs.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(time$.TimeTicks, val.frame_time);
    encoder.encodeStructPointer(time$.TimeTicks, val.deadline);
    encoder.encodeStructPointer(time$.TimeDelta, val.interval);
    encoder.encodeStruct(codec.Uint64, val.sequence_number);
    encoder.encodeStruct(codec.Uint32, val.source_id);
    encoder.encodeStruct(codec.Int32, val.type);
    packed = 0;
    packed |= (val.on_critical_path & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.BeginFrameArgsType = BeginFrameArgsType;
  exports.BeginFrameArgs = BeginFrameArgs;

  return exports;
});
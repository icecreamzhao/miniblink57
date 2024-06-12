// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/gfx/mojo/icc_profile.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/mojo/color_space.mojom",
], function(bindings, codec, core, validator, color_space$) {

  function ICCProfile(values) {
    this.initDefaults_();
    this.initFields_(values);
  }

  ICCProfile.Type = {};

  ICCProfile.Type.isKnownEnumValue = function(value) {
    return false;
  };

  ICCProfile.Type.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  ICCProfile.prototype.initDefaults_ = function() {
    this.color_space = null;
    this.type = 0;
    this.data = null;
    this.id = 0;
  };
  ICCProfile.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ICCProfile.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 40}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ICCProfile.color_space
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, color_space$.ColorSpace, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ICCProfile.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, ICCProfile.Type);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ICCProfile.data
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  ICCProfile.encodedSize = codec.kStructHeaderSize + 32;

  ICCProfile.decode = function(decoder) {
    var packed;
    var val = new ICCProfile();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.color_space = decoder.decodeStructPointer(color_space$.ColorSpace);
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.data = decoder.decodeStruct(codec.String);
    val.id = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  ICCProfile.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ICCProfile.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(color_space$.ColorSpace, val.color_space);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.data);
    encoder.encodeStruct(codec.Uint64, val.id);
  };

  var exports = {};
  exports.ICCProfile = ICCProfile;

  return exports;
});
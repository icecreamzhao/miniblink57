// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("url/mojo/origin.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Origin(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Origin.prototype.initDefaults_ = function() {
    this.scheme = null;
    this.host = null;
    this.port = 0;
    this.unique = false;
  };
  Origin.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Origin.validate = function(messageValidator, offset) {
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


    
    // validate Origin.scheme
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Origin.host
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  Origin.encodedSize = codec.kStructHeaderSize + 24;

  Origin.decode = function(decoder) {
    var packed;
    var val = new Origin();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.scheme = decoder.decodeStruct(codec.String);
    val.host = decoder.decodeStruct(codec.String);
    val.port = decoder.decodeStruct(codec.Uint16);
    packed = decoder.readUint8();
    val.unique = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Origin.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Origin.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.scheme);
    encoder.encodeStruct(codec.String, val.host);
    encoder.encodeStruct(codec.Uint16, val.port);
    packed = 0;
    packed |= (val.unique & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.Origin = Origin;

  return exports;
});
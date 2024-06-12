// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/returned_resource.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "gpu/ipc/common/sync_token.mojom",
], function(bindings, codec, core, validator, sync_token$) {

  function ReturnedResource(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ReturnedResource.prototype.initDefaults_ = function() {
    this.id = 0;
    this.count = 0;
    this.sync_token = null;
    this.lost = false;
  };
  ReturnedResource.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ReturnedResource.validate = function(messageValidator, offset) {
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



    
    // validate ReturnedResource.sync_token
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, sync_token$.SyncToken, false);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  ReturnedResource.encodedSize = codec.kStructHeaderSize + 24;

  ReturnedResource.decode = function(decoder) {
    var packed;
    var val = new ReturnedResource();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Uint32);
    val.count = decoder.decodeStruct(codec.Int32);
    val.sync_token = decoder.decodeStructPointer(sync_token$.SyncToken);
    packed = decoder.readUint8();
    val.lost = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  ReturnedResource.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ReturnedResource.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.id);
    encoder.encodeStruct(codec.Int32, val.count);
    encoder.encodeStructPointer(sync_token$.SyncToken, val.sync_token);
    packed = 0;
    packed |= (val.lost & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function ReturnedResourceArray(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ReturnedResourceArray.prototype.initDefaults_ = function() {
    this.returned_resources = null;
  };
  ReturnedResourceArray.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ReturnedResourceArray.validate = function(messageValidator, offset) {
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


    
    // validate ReturnedResourceArray.returned_resources
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(ReturnedResource), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ReturnedResourceArray.encodedSize = codec.kStructHeaderSize + 8;

  ReturnedResourceArray.decode = function(decoder) {
    var packed;
    var val = new ReturnedResourceArray();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.returned_resources = decoder.decodeArrayPointer(new codec.PointerTo(ReturnedResource));
    return val;
  };

  ReturnedResourceArray.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ReturnedResourceArray.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(ReturnedResource), val.returned_resources);
  };

  var exports = {};
  exports.ReturnedResource = ReturnedResource;
  exports.ReturnedResourceArray = ReturnedResourceArray;

  return exports;
});
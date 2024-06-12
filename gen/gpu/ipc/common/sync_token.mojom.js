// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("gpu/ipc/common/sync_token.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var CommandBufferNamespace = {};
  CommandBufferNamespace.INVALID = -1;
  CommandBufferNamespace.GPU_IO = CommandBufferNamespace.INVALID + 1;
  CommandBufferNamespace.IN_PROCESS = CommandBufferNamespace.GPU_IO + 1;
  CommandBufferNamespace.MOJO = CommandBufferNamespace.IN_PROCESS + 1;
  CommandBufferNamespace.MOJO_LOCAL = CommandBufferNamespace.MOJO + 1;
  CommandBufferNamespace.NUM_COMMAND_BUFFER_NAMESPACES = CommandBufferNamespace.MOJO_LOCAL + 1;

  CommandBufferNamespace.isKnownEnumValue = function(value) {
    switch (value) {
    case -1:
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    }
    return false;
  };

  CommandBufferNamespace.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function SyncToken(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SyncToken.prototype.initDefaults_ = function() {
    this.verified_flush = false;
    this.namespace_id = 0;
    this.extra_data_field = 0;
    this.command_buffer_id = 0;
    this.release_count = 0;
  };
  SyncToken.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SyncToken.validate = function(messageValidator, offset) {
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



    
    // validate SyncToken.namespace_id
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, CommandBufferNamespace);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  SyncToken.encodedSize = codec.kStructHeaderSize + 32;

  SyncToken.decode = function(decoder) {
    var packed;
    var val = new SyncToken();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.verified_flush = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.namespace_id = decoder.decodeStruct(codec.Int32);
    val.extra_data_field = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.command_buffer_id = decoder.decodeStruct(codec.Uint64);
    val.release_count = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  SyncToken.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SyncToken.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.verified_flush & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.namespace_id);
    encoder.encodeStruct(codec.Int32, val.extra_data_field);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint64, val.command_buffer_id);
    encoder.encodeStruct(codec.Uint64, val.release_count);
  };

  var exports = {};
  exports.CommandBufferNamespace = CommandBufferNamespace;
  exports.SyncToken = SyncToken;

  return exports;
});
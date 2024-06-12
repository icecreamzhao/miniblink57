// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/service_manager/public/interfaces/interface_provider_spec.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var kServiceManager_ConnectorSpec = "service_manager:connector";

  function InterfaceSet(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceSet.prototype.initDefaults_ = function() {
    this.interfaces = null;
  };
  InterfaceSet.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceSet.validate = function(messageValidator, offset) {
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


    
    // validate InterfaceSet.interfaces
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceSet.encodedSize = codec.kStructHeaderSize + 8;

  InterfaceSet.decode = function(decoder) {
    var packed;
    var val = new InterfaceSet();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.interfaces = decoder.decodeArrayPointer(codec.String);
    return val;
  };

  InterfaceSet.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceSet.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.String, val.interfaces);
  };
  function CapabilitySet(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CapabilitySet.prototype.initDefaults_ = function() {
    this.capabilities = null;
  };
  CapabilitySet.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CapabilitySet.validate = function(messageValidator, offset) {
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


    
    // validate CapabilitySet.capabilities
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  CapabilitySet.encodedSize = codec.kStructHeaderSize + 8;

  CapabilitySet.decode = function(decoder) {
    var packed;
    var val = new CapabilitySet();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.capabilities = decoder.decodeArrayPointer(codec.String);
    return val;
  };

  CapabilitySet.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CapabilitySet.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.String, val.capabilities);
  };
  function InterfaceProviderSpec(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceProviderSpec.prototype.initDefaults_ = function() {
    this.provides = null;
    this.requires = null;
  };
  InterfaceProviderSpec.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceProviderSpec.validate = function(messageValidator, offset) {
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


    
    // validate InterfaceProviderSpec.provides
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 0, false, codec.String, new codec.PointerTo(InterfaceSet), false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate InterfaceProviderSpec.requires
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, false, codec.String, new codec.PointerTo(CapabilitySet), false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceProviderSpec.encodedSize = codec.kStructHeaderSize + 16;

  InterfaceProviderSpec.decode = function(decoder) {
    var packed;
    var val = new InterfaceProviderSpec();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.provides = decoder.decodeMapPointer(codec.String, new codec.PointerTo(InterfaceSet));
    val.requires = decoder.decodeMapPointer(codec.String, new codec.PointerTo(CapabilitySet));
    return val;
  };

  InterfaceProviderSpec.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceProviderSpec.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeMapPointer(codec.String, new codec.PointerTo(InterfaceSet), val.provides);
    encoder.encodeMapPointer(codec.String, new codec.PointerTo(CapabilitySet), val.requires);
  };

  var exports = {};
  exports.kServiceManager_ConnectorSpec = kServiceManager_ConnectorSpec;
  exports.InterfaceSet = InterfaceSet;
  exports.CapabilitySet = CapabilitySet;
  exports.InterfaceProviderSpec = InterfaceProviderSpec;

  return exports;
});
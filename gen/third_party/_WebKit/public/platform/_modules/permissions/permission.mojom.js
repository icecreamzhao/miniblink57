// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/permissions/permission.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom",
    "url/mojo/origin.mojom",
], function(bindings, codec, core, validator, permission_status$, origin$) {
  var PermissionName = {};
  PermissionName.GEOLOCATION = 0;
  PermissionName.NOTIFICATIONS = PermissionName.GEOLOCATION + 1;
  PermissionName.PUSH_NOTIFICATIONS = PermissionName.NOTIFICATIONS + 1;
  PermissionName.MIDI = PermissionName.PUSH_NOTIFICATIONS + 1;
  PermissionName.PROTECTED_MEDIA_IDENTIFIER = PermissionName.MIDI + 1;
  PermissionName.DURABLE_STORAGE = PermissionName.PROTECTED_MEDIA_IDENTIFIER + 1;
  PermissionName.AUDIO_CAPTURE = PermissionName.DURABLE_STORAGE + 1;
  PermissionName.VIDEO_CAPTURE = PermissionName.AUDIO_CAPTURE + 1;
  PermissionName.BACKGROUND_SYNC = PermissionName.VIDEO_CAPTURE + 1;

  PermissionName.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    }
    return false;
  };

  PermissionName.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function MidiPermissionDescriptor(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MidiPermissionDescriptor.prototype.initDefaults_ = function() {
    this.sysex = false;
  };
  MidiPermissionDescriptor.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MidiPermissionDescriptor.validate = function(messageValidator, offset) {
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

  MidiPermissionDescriptor.encodedSize = codec.kStructHeaderSize + 8;

  MidiPermissionDescriptor.decode = function(decoder) {
    var packed;
    var val = new MidiPermissionDescriptor();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.sysex = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  MidiPermissionDescriptor.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MidiPermissionDescriptor.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.sysex & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PermissionDescriptor(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionDescriptor.prototype.initDefaults_ = function() {
    this.name = 0;
    this.extension = null;
  };
  PermissionDescriptor.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionDescriptor.validate = function(messageValidator, offset) {
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


    
    // validate PermissionDescriptor.name
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PermissionName);
    if (err !== validator.validationError.NONE)
        return err;


    // validate PermissionDescriptor.extension
    err = messageValidator.validateUnion(offset + codec.kStructHeaderSize + 8, PermissionDescriptorExtension, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionDescriptor.encodedSize = codec.kStructHeaderSize + 24;

  PermissionDescriptor.decode = function(decoder) {
    var packed;
    var val = new PermissionDescriptor();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.extension = decoder.decodeStruct(PermissionDescriptorExtension);
    return val;
  };

  PermissionDescriptor.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionDescriptor.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.name);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(PermissionDescriptorExtension, val.extension);
  };
  function PermissionObserver_OnPermissionStatusChange_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionObserver_OnPermissionStatusChange_Params.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  PermissionObserver_OnPermissionStatusChange_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionObserver_OnPermissionStatusChange_Params.validate = function(messageValidator, offset) {
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


    
    // validate PermissionObserver_OnPermissionStatusChange_Params.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, permission_status$.PermissionStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionObserver_OnPermissionStatusChange_Params.encodedSize = codec.kStructHeaderSize + 8;

  PermissionObserver_OnPermissionStatusChange_Params.decode = function(decoder) {
    var packed;
    var val = new PermissionObserver_OnPermissionStatusChange_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PermissionObserver_OnPermissionStatusChange_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionObserver_OnPermissionStatusChange_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PermissionService_HasPermission_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_HasPermission_Params.prototype.initDefaults_ = function() {
    this.permission = null;
    this.origin = null;
  };
  PermissionService_HasPermission_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_HasPermission_Params.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_HasPermission_Params.permission
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PermissionDescriptor, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PermissionService_HasPermission_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionService_HasPermission_Params.encodedSize = codec.kStructHeaderSize + 16;

  PermissionService_HasPermission_Params.decode = function(decoder) {
    var packed;
    var val = new PermissionService_HasPermission_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.permission = decoder.decodeStructPointer(PermissionDescriptor);
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    return val;
  };

  PermissionService_HasPermission_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_HasPermission_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PermissionDescriptor, val.permission);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
  };
  function PermissionService_HasPermission_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_HasPermission_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  PermissionService_HasPermission_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_HasPermission_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_HasPermission_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, permission_status$.PermissionStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionService_HasPermission_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PermissionService_HasPermission_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PermissionService_HasPermission_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PermissionService_HasPermission_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_HasPermission_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PermissionService_RequestPermission_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_RequestPermission_Params.prototype.initDefaults_ = function() {
    this.permission = null;
    this.origin = null;
    this.user_gesture = false;
  };
  PermissionService_RequestPermission_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_RequestPermission_Params.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_RequestPermission_Params.permission
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PermissionDescriptor, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PermissionService_RequestPermission_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  PermissionService_RequestPermission_Params.encodedSize = codec.kStructHeaderSize + 24;

  PermissionService_RequestPermission_Params.decode = function(decoder) {
    var packed;
    var val = new PermissionService_RequestPermission_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.permission = decoder.decodeStructPointer(PermissionDescriptor);
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    packed = decoder.readUint8();
    val.user_gesture = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PermissionService_RequestPermission_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_RequestPermission_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PermissionDescriptor, val.permission);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
    packed = 0;
    packed |= (val.user_gesture & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PermissionService_RequestPermission_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_RequestPermission_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  PermissionService_RequestPermission_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_RequestPermission_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_RequestPermission_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, permission_status$.PermissionStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionService_RequestPermission_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PermissionService_RequestPermission_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PermissionService_RequestPermission_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PermissionService_RequestPermission_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_RequestPermission_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PermissionService_RequestPermissions_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_RequestPermissions_Params.prototype.initDefaults_ = function() {
    this.permission = null;
    this.origin = null;
    this.user_gesture = false;
  };
  PermissionService_RequestPermissions_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_RequestPermissions_Params.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_RequestPermissions_Params.permission
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(PermissionDescriptor), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PermissionService_RequestPermissions_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  PermissionService_RequestPermissions_Params.encodedSize = codec.kStructHeaderSize + 24;

  PermissionService_RequestPermissions_Params.decode = function(decoder) {
    var packed;
    var val = new PermissionService_RequestPermissions_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.permission = decoder.decodeArrayPointer(new codec.PointerTo(PermissionDescriptor));
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    packed = decoder.readUint8();
    val.user_gesture = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PermissionService_RequestPermissions_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_RequestPermissions_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(PermissionDescriptor), val.permission);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
    packed = 0;
    packed |= (val.user_gesture & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PermissionService_RequestPermissions_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_RequestPermissions_ResponseParams.prototype.initDefaults_ = function() {
    this.statuses = null;
  };
  PermissionService_RequestPermissions_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_RequestPermissions_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_RequestPermissions_ResponseParams.statuses
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 4, new codec.Enum(permission_status$.PermissionStatus), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionService_RequestPermissions_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PermissionService_RequestPermissions_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PermissionService_RequestPermissions_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.statuses = decoder.decodeArrayPointer(new codec.Enum(permission_status$.PermissionStatus));
    return val;
  };

  PermissionService_RequestPermissions_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_RequestPermissions_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.Enum(permission_status$.PermissionStatus), val.statuses);
  };
  function PermissionService_RevokePermission_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_RevokePermission_Params.prototype.initDefaults_ = function() {
    this.permission = null;
    this.origin = null;
  };
  PermissionService_RevokePermission_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_RevokePermission_Params.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_RevokePermission_Params.permission
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PermissionDescriptor, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PermissionService_RevokePermission_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionService_RevokePermission_Params.encodedSize = codec.kStructHeaderSize + 16;

  PermissionService_RevokePermission_Params.decode = function(decoder) {
    var packed;
    var val = new PermissionService_RevokePermission_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.permission = decoder.decodeStructPointer(PermissionDescriptor);
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    return val;
  };

  PermissionService_RevokePermission_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_RevokePermission_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PermissionDescriptor, val.permission);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
  };
  function PermissionService_RevokePermission_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_RevokePermission_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  PermissionService_RevokePermission_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_RevokePermission_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_RevokePermission_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, permission_status$.PermissionStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionService_RevokePermission_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PermissionService_RevokePermission_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PermissionService_RevokePermission_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PermissionService_RevokePermission_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_RevokePermission_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PermissionService_AddPermissionObserver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PermissionService_AddPermissionObserver_Params.prototype.initDefaults_ = function() {
    this.permission = null;
    this.origin = null;
    this.last_known_status = 0;
    this.observer = new PermissionObserverPtr();
  };
  PermissionService_AddPermissionObserver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PermissionService_AddPermissionObserver_Params.validate = function(messageValidator, offset) {
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


    
    // validate PermissionService_AddPermissionObserver_Params.permission
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PermissionDescriptor, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PermissionService_AddPermissionObserver_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PermissionService_AddPermissionObserver_Params.last_known_status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, permission_status$.PermissionStatus);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PermissionService_AddPermissionObserver_Params.observer
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 20, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PermissionService_AddPermissionObserver_Params.encodedSize = codec.kStructHeaderSize + 32;

  PermissionService_AddPermissionObserver_Params.decode = function(decoder) {
    var packed;
    var val = new PermissionService_AddPermissionObserver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.permission = decoder.decodeStructPointer(PermissionDescriptor);
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    val.last_known_status = decoder.decodeStruct(codec.Int32);
    val.observer = decoder.decodeStruct(new codec.Interface(PermissionObserverPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PermissionService_AddPermissionObserver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PermissionService_AddPermissionObserver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PermissionDescriptor, val.permission);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
    encoder.encodeStruct(codec.Int32, val.last_known_status);
    encoder.encodeStruct(new codec.Interface(PermissionObserverPtr), val.observer);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  function PermissionDescriptorExtension(value) {
    this.initDefault_();
    this.initValue_(value);
  }
  
  
  PermissionDescriptorExtension.Tags = {
    midi: 0,
  };
  
  PermissionDescriptorExtension.prototype.initDefault_ = function() {
    this.$data = null;
    this.$tag = undefined;
  }
  
  PermissionDescriptorExtension.prototype.initValue_ = function(value) {
    if (value == undefined) {
      return;
    }
  
    var keys = Object.keys(value);
    if (keys.length == 0) {
      return;
    }
  
    if (keys.length > 1) {
      throw new TypeError("You may set only one member on a union.");
    }
  
    var fields = [
        "midi",
    ];
  
    if (fields.indexOf(keys[0]) < 0) {
      throw new ReferenceError(keys[0] + " is not a PermissionDescriptorExtension member.");
  
    }
  
    this[keys[0]] = value[keys[0]];
  }
  Object.defineProperty(PermissionDescriptorExtension.prototype, "midi", {
    get: function() {
      if (this.$tag != PermissionDescriptorExtension.Tags.midi) {
        throw new ReferenceError(
            "PermissionDescriptorExtension.midi is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = PermissionDescriptorExtension.Tags.midi;
      this.$data = value;
    }
  });
  
  
    PermissionDescriptorExtension.encode = function(encoder, val) {
      if (val == null) {
        encoder.writeUint64(0);
        encoder.writeUint64(0);
        return;
      }
      if (val.$tag == undefined) {
        throw new TypeError("Cannot encode unions with an unknown member set.");
      }
    
      encoder.writeUint32(16);
      encoder.writeUint32(val.$tag);
      switch (val.$tag) {
        case PermissionDescriptorExtension.Tags.midi:
          encoder.encodeStructPointer(MidiPermissionDescriptor, val.midi);
          break;
      }
      encoder.align();
    };
  
  
    PermissionDescriptorExtension.decode = function(decoder) {
      var size = decoder.readUint32();
      if (size == 0) {
        decoder.readUint32();
        decoder.readUint64();
        return null;
      }
    
      var result = new PermissionDescriptorExtension();
      var tag = decoder.readUint32();
      switch (tag) {
        case PermissionDescriptorExtension.Tags.midi:
          result.midi = decoder.decodeStructPointer(MidiPermissionDescriptor);
          break;
      }
      decoder.align();
    
      return result;
    };
  
  
    PermissionDescriptorExtension.validate = function(messageValidator, offset) {
      var size = messageValidator.decodeUnionSize(offset);
      if (size != 16) {
        return validator.validationError.INVALID_UNION_SIZE;
      }
    
      var tag = messageValidator.decodeUnionTag(offset);
      var data_offset = offset + 8;
      var err;
      switch (tag) {
        case PermissionDescriptorExtension.Tags.midi:
          
    
    // validate PermissionDescriptorExtension.midi
    err = messageValidator.validateStructPointer(data_offset, MidiPermissionDescriptor, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
      }
    
      return validator.validationError.NONE;
    };
  
  PermissionDescriptorExtension.encodedSize = 16;
  var kPermissionObserver_OnPermissionStatusChange_Name = 0;

  function PermissionObserverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PermissionObserver,
                                                   handleOrPtrInfo);
  }

  function PermissionObserverProxy(receiver) {
    this.receiver_ = receiver;
  }
  PermissionObserverPtr.prototype.onPermissionStatusChange = function() {
    return PermissionObserverProxy.prototype.onPermissionStatusChange
        .apply(this.ptr.getProxy(), arguments);
  };

  PermissionObserverProxy.prototype.onPermissionStatusChange = function(status) {
    var params = new PermissionObserver_OnPermissionStatusChange_Params();
    params.status = status;
    var builder = new codec.MessageBuilder(
        kPermissionObserver_OnPermissionStatusChange_Name,
        codec.align(PermissionObserver_OnPermissionStatusChange_Params.encodedSize));
    builder.encodeStruct(PermissionObserver_OnPermissionStatusChange_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PermissionObserverStub(delegate) {
    this.delegate_ = delegate;
  }
  PermissionObserverStub.prototype.onPermissionStatusChange = function(status) {
    return this.delegate_ && this.delegate_.onPermissionStatusChange && this.delegate_.onPermissionStatusChange(status);
  }

  PermissionObserverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPermissionObserver_OnPermissionStatusChange_Name:
      var params = reader.decodeStruct(PermissionObserver_OnPermissionStatusChange_Params);
      this.onPermissionStatusChange(params.status);
      return true;
    default:
      return false;
    }
  };

  PermissionObserverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePermissionObserverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPermissionObserver_OnPermissionStatusChange_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PermissionObserver_OnPermissionStatusChange_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePermissionObserverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PermissionObserver = {
    name: 'blink::mojom::PermissionObserver',
    ptrClass: PermissionObserverPtr,
    proxyClass: PermissionObserverProxy,
    stubClass: PermissionObserverStub,
    validateRequest: validatePermissionObserverRequest,
    validateResponse: null,
  };
  PermissionObserverStub.prototype.validator = validatePermissionObserverRequest;
  PermissionObserverProxy.prototype.validator = null;
  var kPermissionService_HasPermission_Name = 0;
  var kPermissionService_RequestPermission_Name = 1;
  var kPermissionService_RequestPermissions_Name = 2;
  var kPermissionService_RevokePermission_Name = 3;
  var kPermissionService_AddPermissionObserver_Name = 4;

  function PermissionServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PermissionService,
                                                   handleOrPtrInfo);
  }

  function PermissionServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  PermissionServicePtr.prototype.hasPermission = function() {
    return PermissionServiceProxy.prototype.hasPermission
        .apply(this.ptr.getProxy(), arguments);
  };

  PermissionServiceProxy.prototype.hasPermission = function(permission, origin) {
    var params = new PermissionService_HasPermission_Params();
    params.permission = permission;
    params.origin = origin;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPermissionService_HasPermission_Name,
          codec.align(PermissionService_HasPermission_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PermissionService_HasPermission_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PermissionService_HasPermission_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PermissionServicePtr.prototype.requestPermission = function() {
    return PermissionServiceProxy.prototype.requestPermission
        .apply(this.ptr.getProxy(), arguments);
  };

  PermissionServiceProxy.prototype.requestPermission = function(permission, origin, user_gesture) {
    var params = new PermissionService_RequestPermission_Params();
    params.permission = permission;
    params.origin = origin;
    params.user_gesture = user_gesture;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPermissionService_RequestPermission_Name,
          codec.align(PermissionService_RequestPermission_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PermissionService_RequestPermission_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PermissionService_RequestPermission_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PermissionServicePtr.prototype.requestPermissions = function() {
    return PermissionServiceProxy.prototype.requestPermissions
        .apply(this.ptr.getProxy(), arguments);
  };

  PermissionServiceProxy.prototype.requestPermissions = function(permission, origin, user_gesture) {
    var params = new PermissionService_RequestPermissions_Params();
    params.permission = permission;
    params.origin = origin;
    params.user_gesture = user_gesture;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPermissionService_RequestPermissions_Name,
          codec.align(PermissionService_RequestPermissions_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PermissionService_RequestPermissions_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PermissionService_RequestPermissions_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PermissionServicePtr.prototype.revokePermission = function() {
    return PermissionServiceProxy.prototype.revokePermission
        .apply(this.ptr.getProxy(), arguments);
  };

  PermissionServiceProxy.prototype.revokePermission = function(permission, origin) {
    var params = new PermissionService_RevokePermission_Params();
    params.permission = permission;
    params.origin = origin;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPermissionService_RevokePermission_Name,
          codec.align(PermissionService_RevokePermission_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PermissionService_RevokePermission_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PermissionService_RevokePermission_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  PermissionServicePtr.prototype.addPermissionObserver = function() {
    return PermissionServiceProxy.prototype.addPermissionObserver
        .apply(this.ptr.getProxy(), arguments);
  };

  PermissionServiceProxy.prototype.addPermissionObserver = function(permission, origin, last_known_status, observer) {
    var params = new PermissionService_AddPermissionObserver_Params();
    params.permission = permission;
    params.origin = origin;
    params.last_known_status = last_known_status;
    params.observer = observer;
    var builder = new codec.MessageBuilder(
        kPermissionService_AddPermissionObserver_Name,
        codec.align(PermissionService_AddPermissionObserver_Params.encodedSize));
    builder.encodeStruct(PermissionService_AddPermissionObserver_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PermissionServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  PermissionServiceStub.prototype.hasPermission = function(permission, origin) {
    return this.delegate_ && this.delegate_.hasPermission && this.delegate_.hasPermission(permission, origin);
  }
  PermissionServiceStub.prototype.requestPermission = function(permission, origin, user_gesture) {
    return this.delegate_ && this.delegate_.requestPermission && this.delegate_.requestPermission(permission, origin, user_gesture);
  }
  PermissionServiceStub.prototype.requestPermissions = function(permission, origin, user_gesture) {
    return this.delegate_ && this.delegate_.requestPermissions && this.delegate_.requestPermissions(permission, origin, user_gesture);
  }
  PermissionServiceStub.prototype.revokePermission = function(permission, origin) {
    return this.delegate_ && this.delegate_.revokePermission && this.delegate_.revokePermission(permission, origin);
  }
  PermissionServiceStub.prototype.addPermissionObserver = function(permission, origin, last_known_status, observer) {
    return this.delegate_ && this.delegate_.addPermissionObserver && this.delegate_.addPermissionObserver(permission, origin, last_known_status, observer);
  }

  PermissionServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPermissionService_AddPermissionObserver_Name:
      var params = reader.decodeStruct(PermissionService_AddPermissionObserver_Params);
      this.addPermissionObserver(params.permission, params.origin, params.last_known_status, params.observer);
      return true;
    default:
      return false;
    }
  };

  PermissionServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPermissionService_HasPermission_Name:
      var params = reader.decodeStruct(PermissionService_HasPermission_Params);
      return this.hasPermission(params.permission, params.origin).then(function(response) {
        var responseParams =
            new PermissionService_HasPermission_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPermissionService_HasPermission_Name,
            codec.align(PermissionService_HasPermission_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PermissionService_HasPermission_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kPermissionService_RequestPermission_Name:
      var params = reader.decodeStruct(PermissionService_RequestPermission_Params);
      return this.requestPermission(params.permission, params.origin, params.user_gesture).then(function(response) {
        var responseParams =
            new PermissionService_RequestPermission_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPermissionService_RequestPermission_Name,
            codec.align(PermissionService_RequestPermission_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PermissionService_RequestPermission_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kPermissionService_RequestPermissions_Name:
      var params = reader.decodeStruct(PermissionService_RequestPermissions_Params);
      return this.requestPermissions(params.permission, params.origin, params.user_gesture).then(function(response) {
        var responseParams =
            new PermissionService_RequestPermissions_ResponseParams();
        responseParams.statuses = response.statuses;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPermissionService_RequestPermissions_Name,
            codec.align(PermissionService_RequestPermissions_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PermissionService_RequestPermissions_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kPermissionService_RevokePermission_Name:
      var params = reader.decodeStruct(PermissionService_RevokePermission_Params);
      return this.revokePermission(params.permission, params.origin).then(function(response) {
        var responseParams =
            new PermissionService_RevokePermission_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPermissionService_RevokePermission_Name,
            codec.align(PermissionService_RevokePermission_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PermissionService_RevokePermission_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePermissionServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPermissionService_HasPermission_Name:
        if (message.expectsResponse())
          paramsClass = PermissionService_HasPermission_Params;
      break;
      case kPermissionService_RequestPermission_Name:
        if (message.expectsResponse())
          paramsClass = PermissionService_RequestPermission_Params;
      break;
      case kPermissionService_RequestPermissions_Name:
        if (message.expectsResponse())
          paramsClass = PermissionService_RequestPermissions_Params;
      break;
      case kPermissionService_RevokePermission_Name:
        if (message.expectsResponse())
          paramsClass = PermissionService_RevokePermission_Params;
      break;
      case kPermissionService_AddPermissionObserver_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PermissionService_AddPermissionObserver_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePermissionServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kPermissionService_HasPermission_Name:
        if (message.isResponse())
          paramsClass = PermissionService_HasPermission_ResponseParams;
        break;
      case kPermissionService_RequestPermission_Name:
        if (message.isResponse())
          paramsClass = PermissionService_RequestPermission_ResponseParams;
        break;
      case kPermissionService_RequestPermissions_Name:
        if (message.isResponse())
          paramsClass = PermissionService_RequestPermissions_ResponseParams;
        break;
      case kPermissionService_RevokePermission_Name:
        if (message.isResponse())
          paramsClass = PermissionService_RevokePermission_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var PermissionService = {
    name: 'blink::mojom::PermissionService',
    ptrClass: PermissionServicePtr,
    proxyClass: PermissionServiceProxy,
    stubClass: PermissionServiceStub,
    validateRequest: validatePermissionServiceRequest,
    validateResponse: validatePermissionServiceResponse,
  };
  PermissionServiceStub.prototype.validator = validatePermissionServiceRequest;
  PermissionServiceProxy.prototype.validator = validatePermissionServiceResponse;

  var exports = {};
  exports.PermissionName = PermissionName;
  exports.MidiPermissionDescriptor = MidiPermissionDescriptor;
  exports.PermissionDescriptor = PermissionDescriptor;
  exports.PermissionDescriptorExtension = PermissionDescriptorExtension;
  exports.PermissionObserver = PermissionObserver;
  exports.PermissionObserverPtr = PermissionObserverPtr;
  exports.PermissionService = PermissionService;
  exports.PermissionServicePtr = PermissionServicePtr;

  return exports;
});
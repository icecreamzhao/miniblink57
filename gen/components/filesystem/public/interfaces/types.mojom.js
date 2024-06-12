// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/filesystem/public/interfaces/types.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var kFlagOpen = 0x1;
  var kFlagCreate = 0x2;
  var kFlagOpenAlways = 0x4;
  var kCreateAlways = 0x8;
  var kFlagOpenTruncated = 0x10;
  var kFlagRead = 0x20;
  var kFlagWrite = 0x40;
  var kFlagAppend = 0x80;
  var kDeleteOnClose = 0x2000;
  var kDeleteFlagRecursive = 0x1;
  var FileError = {};
  FileError.OK = 0;
  FileError.FAILED = -1;
  FileError.IN_USE = -2;
  FileError.EXISTS = -3;
  FileError.NOT_FOUND = -4;
  FileError.ACCESS_DENIED = -5;
  FileError.TOO_MANY_OPENED = -6;
  FileError.NO_MEMORY = -7;
  FileError.NO_SPACE = -8;
  FileError.NOT_A_DIRECTORY = -9;
  FileError.INVALID_OPERATION = -10;
  FileError.SECURITY = -11;
  FileError.ABORT = -12;
  FileError.NOT_A_FILE = -13;
  FileError.NOT_EMPTY = -14;
  FileError.INVALID_URL = -15;
  FileError.IO = -16;

  FileError.isKnownEnumValue = function(value) {
    switch (value) {
    case -16:
    case -15:
    case -14:
    case -13:
    case -12:
    case -11:
    case -10:
    case -9:
    case -8:
    case -7:
    case -6:
    case -5:
    case -4:
    case -3:
    case -2:
    case -1:
    case 0:
      return true;
    }
    return false;
  };

  FileError.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var Whence = {};
  Whence.FROM_BEGIN = 0;
  Whence.FROM_CURRENT = 1;
  Whence.FROM_END = 2;

  Whence.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  Whence.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var FsFileType = {};
  FsFileType.UNKNOWN = 0;
  FsFileType.REGULAR_FILE = FsFileType.UNKNOWN + 1;
  FsFileType.DIRECTORY = FsFileType.REGULAR_FILE + 1;

  FsFileType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  FsFileType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function TimespecOrNow(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TimespecOrNow.prototype.initDefaults_ = function() {
    this.now = false;
    this.seconds = 0;
  };
  TimespecOrNow.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TimespecOrNow.validate = function(messageValidator, offset) {
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



    return validator.validationError.NONE;
  };

  TimespecOrNow.encodedSize = codec.kStructHeaderSize + 16;

  TimespecOrNow.decode = function(decoder) {
    var packed;
    var val = new TimespecOrNow();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.now = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.seconds = decoder.decodeStruct(codec.Double);
    return val;
  };

  TimespecOrNow.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TimespecOrNow.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.now & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Double, val.seconds);
  };
  function FileInformation(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileInformation.prototype.initDefaults_ = function() {
    this.type = 0;
    this.size = 0;
    this.atime = 0;
    this.mtime = 0;
    this.ctime = 0;
  };
  FileInformation.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileInformation.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 48}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FileInformation.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, FsFileType);
    if (err !== validator.validationError.NONE)
        return err;





    return validator.validationError.NONE;
  };

  FileInformation.encodedSize = codec.kStructHeaderSize + 40;

  FileInformation.decode = function(decoder) {
    var packed;
    var val = new FileInformation();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.size = decoder.decodeStruct(codec.Int64);
    val.atime = decoder.decodeStruct(codec.Double);
    val.mtime = decoder.decodeStruct(codec.Double);
    val.ctime = decoder.decodeStruct(codec.Double);
    return val;
  };

  FileInformation.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileInformation.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int64, val.size);
    encoder.encodeStruct(codec.Double, val.atime);
    encoder.encodeStruct(codec.Double, val.mtime);
    encoder.encodeStruct(codec.Double, val.ctime);
  };
  function DirectoryEntry(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DirectoryEntry.prototype.initDefaults_ = function() {
    this.type = 0;
    this.name = null;
  };
  DirectoryEntry.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DirectoryEntry.validate = function(messageValidator, offset) {
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


    
    // validate DirectoryEntry.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, FsFileType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DirectoryEntry.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DirectoryEntry.encodedSize = codec.kStructHeaderSize + 16;

  DirectoryEntry.decode = function(decoder) {
    var packed;
    var val = new DirectoryEntry();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.name = decoder.decodeStruct(codec.String);
    return val;
  };

  DirectoryEntry.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DirectoryEntry.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.name);
  };

  var exports = {};
  exports.kFlagOpen = kFlagOpen;
  exports.kFlagCreate = kFlagCreate;
  exports.kFlagOpenAlways = kFlagOpenAlways;
  exports.kCreateAlways = kCreateAlways;
  exports.kFlagOpenTruncated = kFlagOpenTruncated;
  exports.kFlagRead = kFlagRead;
  exports.kFlagWrite = kFlagWrite;
  exports.kFlagAppend = kFlagAppend;
  exports.kDeleteOnClose = kDeleteOnClose;
  exports.kDeleteFlagRecursive = kDeleteFlagRecursive;
  exports.FileError = FileError;
  exports.Whence = Whence;
  exports.FsFileType = FsFileType;
  exports.TimespecOrNow = TimespecOrNow;
  exports.FileInformation = FileInformation;
  exports.DirectoryEntry = DirectoryEntry;

  return exports;
});
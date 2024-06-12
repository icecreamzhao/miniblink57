// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/leveldb/public/interfaces/leveldb.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "components/filesystem/public/interfaces/directory.mojom",
    "mojo/common/unguessable_token.mojom",
], function(bindings, codec, core, validator, directory$, unguessable_token$) {
  var DatabaseError = {};
  DatabaseError.OK = 0;
  DatabaseError.NOT_FOUND = DatabaseError.OK + 1;
  DatabaseError.CORRUPTION = DatabaseError.NOT_FOUND + 1;
  DatabaseError.NOT_SUPPORTED = DatabaseError.CORRUPTION + 1;
  DatabaseError.INVALID_ARGUMENT = DatabaseError.NOT_SUPPORTED + 1;
  DatabaseError.IO_ERROR = DatabaseError.INVALID_ARGUMENT + 1;

  DatabaseError.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    }
    return false;
  };

  DatabaseError.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var BatchOperationType = {};
  BatchOperationType.PUT_KEY = 0;
  BatchOperationType.DELETE_KEY = BatchOperationType.PUT_KEY + 1;
  BatchOperationType.DELETE_PREFIXED_KEY = BatchOperationType.DELETE_KEY + 1;

  BatchOperationType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  BatchOperationType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function BatchedOperation(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BatchedOperation.prototype.initDefaults_ = function() {
    this.type = 0;
    this.key = null;
    this.value = null;
  };
  BatchedOperation.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BatchedOperation.validate = function(messageValidator, offset) {
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


    
    // validate BatchedOperation.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, BatchOperationType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BatchedOperation.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BatchedOperation.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BatchedOperation.encodedSize = codec.kStructHeaderSize + 24;

  BatchedOperation.decode = function(decoder) {
    var packed;
    var val = new BatchedOperation();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  BatchedOperation.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BatchedOperation.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function KeyValue(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  KeyValue.prototype.initDefaults_ = function() {
    this.key = null;
    this.value = null;
  };
  KeyValue.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  KeyValue.validate = function(messageValidator, offset) {
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


    
    // validate KeyValue.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate KeyValue.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  KeyValue.encodedSize = codec.kStructHeaderSize + 16;

  KeyValue.decode = function(decoder) {
    var packed;
    var val = new KeyValue();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  KeyValue.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(KeyValue.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function OpenOptions(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  OpenOptions.prototype.initDefaults_ = function() {
    this.create_if_missing = false;
    this.error_if_exists = false;
    this.paranoid_checks = false;
    this.max_open_files = 80;
    this.write_buffer_size = 4194304;
  };
  OpenOptions.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  OpenOptions.validate = function(messageValidator, offset) {
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

  OpenOptions.encodedSize = codec.kStructHeaderSize + 16;

  OpenOptions.decode = function(decoder) {
    var packed;
    var val = new OpenOptions();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.create_if_missing = (packed >> 0) & 1 ? true : false;
    val.error_if_exists = (packed >> 1) & 1 ? true : false;
    val.paranoid_checks = (packed >> 2) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.max_open_files = decoder.decodeStruct(codec.Int32);
    val.write_buffer_size = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  OpenOptions.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(OpenOptions.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.create_if_missing & 1) << 0
    packed |= (val.error_if_exists & 1) << 1
    packed |= (val.paranoid_checks & 1) << 2
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.max_open_files);
    encoder.encodeStruct(codec.Uint64, val.write_buffer_size);
  };
  function LevelDBService_Open_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_Open_Params.prototype.initDefaults_ = function() {
    this.directory = new directory$.DirectoryPtr();
    this.dbname = null;
    this.database = null;
  };
  LevelDBService_Open_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_Open_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBService_Open_Params.directory
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBService_Open_Params.dbname
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  LevelDBService_Open_Params.encodedSize = codec.kStructHeaderSize + 24;

  LevelDBService_Open_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_Open_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.directory = decoder.decodeStruct(new codec.Interface(directory$.DirectoryPtr));
    val.dbname = decoder.decodeStruct(codec.String);
    val.database = decoder.decodeStruct(codec.AssociatedInterfaceRequestNotSupported);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBService_Open_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_Open_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(directory$.DirectoryPtr), val.directory);
    encoder.encodeStruct(codec.String, val.dbname);
    encoder.encodeStruct(codec.AssociatedInterfaceRequestNotSupported, val.database);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBService_Open_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_Open_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBService_Open_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_Open_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBService_Open_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBService_Open_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBService_Open_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_Open_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBService_Open_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_Open_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBService_OpenWithOptions_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_OpenWithOptions_Params.prototype.initDefaults_ = function() {
    this.options = null;
    this.directory = new directory$.DirectoryPtr();
    this.dbname = null;
    this.database = null;
  };
  LevelDBService_OpenWithOptions_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_OpenWithOptions_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBService_OpenWithOptions_Params.options
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, OpenOptions, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBService_OpenWithOptions_Params.directory
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBService_OpenWithOptions_Params.dbname
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  LevelDBService_OpenWithOptions_Params.encodedSize = codec.kStructHeaderSize + 32;

  LevelDBService_OpenWithOptions_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_OpenWithOptions_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.options = decoder.decodeStructPointer(OpenOptions);
    val.directory = decoder.decodeStruct(new codec.Interface(directory$.DirectoryPtr));
    val.dbname = decoder.decodeStruct(codec.String);
    val.database = decoder.decodeStruct(codec.AssociatedInterfaceRequestNotSupported);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBService_OpenWithOptions_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_OpenWithOptions_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(OpenOptions, val.options);
    encoder.encodeStruct(new codec.Interface(directory$.DirectoryPtr), val.directory);
    encoder.encodeStruct(codec.String, val.dbname);
    encoder.encodeStruct(codec.AssociatedInterfaceRequestNotSupported, val.database);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBService_OpenWithOptions_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_OpenWithOptions_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBService_OpenWithOptions_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_OpenWithOptions_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBService_OpenWithOptions_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBService_OpenWithOptions_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBService_OpenWithOptions_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_OpenWithOptions_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBService_OpenWithOptions_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_OpenWithOptions_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBService_OpenInMemory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_OpenInMemory_Params.prototype.initDefaults_ = function() {
    this.database = null;
  };
  LevelDBService_OpenInMemory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_OpenInMemory_Params.validate = function(messageValidator, offset) {
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

  LevelDBService_OpenInMemory_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBService_OpenInMemory_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_OpenInMemory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.database = decoder.decodeStruct(codec.AssociatedInterfaceRequestNotSupported);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBService_OpenInMemory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_OpenInMemory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.AssociatedInterfaceRequestNotSupported, val.database);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBService_OpenInMemory_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_OpenInMemory_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBService_OpenInMemory_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_OpenInMemory_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBService_OpenInMemory_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBService_OpenInMemory_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBService_OpenInMemory_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_OpenInMemory_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBService_OpenInMemory_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_OpenInMemory_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBService_Destroy_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_Destroy_Params.prototype.initDefaults_ = function() {
    this.directory = new directory$.DirectoryPtr();
    this.dbname = null;
  };
  LevelDBService_Destroy_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_Destroy_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBService_Destroy_Params.directory
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBService_Destroy_Params.dbname
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBService_Destroy_Params.encodedSize = codec.kStructHeaderSize + 16;

  LevelDBService_Destroy_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_Destroy_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.directory = decoder.decodeStruct(new codec.Interface(directory$.DirectoryPtr));
    val.dbname = decoder.decodeStruct(codec.String);
    return val;
  };

  LevelDBService_Destroy_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_Destroy_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(directory$.DirectoryPtr), val.directory);
    encoder.encodeStruct(codec.String, val.dbname);
  };
  function LevelDBService_Destroy_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBService_Destroy_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBService_Destroy_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBService_Destroy_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBService_Destroy_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBService_Destroy_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBService_Destroy_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBService_Destroy_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBService_Destroy_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBService_Destroy_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBDatabase_Put_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Put_Params.prototype.initDefaults_ = function() {
    this.key = null;
    this.value = null;
  };
  LevelDBDatabase_Put_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Put_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Put_Params.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_Put_Params.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Put_Params.encodedSize = codec.kStructHeaderSize + 16;

  LevelDBDatabase_Put_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Put_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_Put_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Put_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function LevelDBDatabase_Put_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Put_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBDatabase_Put_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Put_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Put_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Put_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_Put_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Put_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBDatabase_Put_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Put_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBDatabase_Delete_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Delete_Params.prototype.initDefaults_ = function() {
    this.key = null;
  };
  LevelDBDatabase_Delete_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Delete_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Delete_Params.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Delete_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_Delete_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Delete_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_Delete_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Delete_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
  };
  function LevelDBDatabase_Delete_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Delete_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBDatabase_Delete_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Delete_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Delete_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Delete_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_Delete_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Delete_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBDatabase_Delete_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Delete_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBDatabase_DeletePrefixed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_DeletePrefixed_Params.prototype.initDefaults_ = function() {
    this.key_prefix = null;
  };
  LevelDBDatabase_DeletePrefixed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_DeletePrefixed_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_DeletePrefixed_Params.key_prefix
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_DeletePrefixed_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_DeletePrefixed_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_DeletePrefixed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key_prefix = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_DeletePrefixed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_DeletePrefixed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.key_prefix);
  };
  function LevelDBDatabase_DeletePrefixed_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_DeletePrefixed_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBDatabase_DeletePrefixed_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_DeletePrefixed_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_DeletePrefixed_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_DeletePrefixed_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_DeletePrefixed_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_DeletePrefixed_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBDatabase_DeletePrefixed_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_DeletePrefixed_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBDatabase_Write_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Write_Params.prototype.initDefaults_ = function() {
    this.operations = null;
  };
  LevelDBDatabase_Write_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Write_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Write_Params.operations
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(BatchedOperation), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Write_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_Write_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Write_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.operations = decoder.decodeArrayPointer(new codec.PointerTo(BatchedOperation));
    return val;
  };

  LevelDBDatabase_Write_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Write_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(BatchedOperation), val.operations);
  };
  function LevelDBDatabase_Write_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Write_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  LevelDBDatabase_Write_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Write_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Write_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Write_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_Write_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Write_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LevelDBDatabase_Write_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Write_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LevelDBDatabase_Get_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Get_Params.prototype.initDefaults_ = function() {
    this.key = null;
  };
  LevelDBDatabase_Get_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Get_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Get_Params.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Get_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_Get_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Get_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_Get_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Get_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
  };
  function LevelDBDatabase_Get_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_Get_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.value = null;
  };
  LevelDBDatabase_Get_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_Get_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_Get_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_Get_ResponseParams.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_Get_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  LevelDBDatabase_Get_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_Get_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_Get_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_Get_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function LevelDBDatabase_GetPrefixed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_GetPrefixed_Params.prototype.initDefaults_ = function() {
    this.key_prefix = null;
  };
  LevelDBDatabase_GetPrefixed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_GetPrefixed_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_GetPrefixed_Params.key_prefix
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_GetPrefixed_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_GetPrefixed_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_GetPrefixed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key_prefix = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_GetPrefixed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_GetPrefixed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.key_prefix);
  };
  function LevelDBDatabase_GetPrefixed_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_GetPrefixed_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.data = null;
  };
  LevelDBDatabase_GetPrefixed_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_GetPrefixed_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_GetPrefixed_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_GetPrefixed_ResponseParams.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(KeyValue), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_GetPrefixed_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  LevelDBDatabase_GetPrefixed_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_GetPrefixed_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.data = decoder.decodeArrayPointer(new codec.PointerTo(KeyValue));
    return val;
  };

  LevelDBDatabase_GetPrefixed_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_GetPrefixed_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(new codec.PointerTo(KeyValue), val.data);
  };
  function LevelDBDatabase_GetSnapshot_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_GetSnapshot_Params.prototype.initDefaults_ = function() {
  };
  LevelDBDatabase_GetSnapshot_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_GetSnapshot_Params.validate = function(messageValidator, offset) {
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

  LevelDBDatabase_GetSnapshot_Params.encodedSize = codec.kStructHeaderSize + 0;

  LevelDBDatabase_GetSnapshot_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_GetSnapshot_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  LevelDBDatabase_GetSnapshot_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_GetSnapshot_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function LevelDBDatabase_GetSnapshot_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_GetSnapshot_ResponseParams.prototype.initDefaults_ = function() {
    this.snapshot = null;
  };
  LevelDBDatabase_GetSnapshot_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_GetSnapshot_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_GetSnapshot_ResponseParams.snapshot
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_GetSnapshot_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_GetSnapshot_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_GetSnapshot_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.snapshot = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_GetSnapshot_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_GetSnapshot_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.snapshot);
  };
  function LevelDBDatabase_ReleaseSnapshot_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_ReleaseSnapshot_Params.prototype.initDefaults_ = function() {
    this.snapshot = null;
  };
  LevelDBDatabase_ReleaseSnapshot_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_ReleaseSnapshot_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_ReleaseSnapshot_Params.snapshot
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_ReleaseSnapshot_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_ReleaseSnapshot_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_ReleaseSnapshot_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.snapshot = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_ReleaseSnapshot_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_ReleaseSnapshot_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.snapshot);
  };
  function LevelDBDatabase_GetFromSnapshot_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_GetFromSnapshot_Params.prototype.initDefaults_ = function() {
    this.snapshot = null;
    this.key = null;
  };
  LevelDBDatabase_GetFromSnapshot_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_GetFromSnapshot_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_GetFromSnapshot_Params.snapshot
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_GetFromSnapshot_Params.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_GetFromSnapshot_Params.encodedSize = codec.kStructHeaderSize + 16;

  LevelDBDatabase_GetFromSnapshot_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_GetFromSnapshot_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.snapshot = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_GetFromSnapshot_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_GetFromSnapshot_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.snapshot);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
  };
  function LevelDBDatabase_GetFromSnapshot_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_GetFromSnapshot_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.value = null;
  };
  LevelDBDatabase_GetFromSnapshot_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_GetFromSnapshot_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_GetFromSnapshot_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_GetFromSnapshot_ResponseParams.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_GetFromSnapshot_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  LevelDBDatabase_GetFromSnapshot_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_GetFromSnapshot_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_GetFromSnapshot_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_GetFromSnapshot_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function LevelDBDatabase_NewIterator_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_NewIterator_Params.prototype.initDefaults_ = function() {
  };
  LevelDBDatabase_NewIterator_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_NewIterator_Params.validate = function(messageValidator, offset) {
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

  LevelDBDatabase_NewIterator_Params.encodedSize = codec.kStructHeaderSize + 0;

  LevelDBDatabase_NewIterator_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_NewIterator_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  LevelDBDatabase_NewIterator_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_NewIterator_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function LevelDBDatabase_NewIterator_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_NewIterator_ResponseParams.prototype.initDefaults_ = function() {
    this.iterator = null;
  };
  LevelDBDatabase_NewIterator_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_NewIterator_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_NewIterator_ResponseParams.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_NewIterator_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_NewIterator_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_NewIterator_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_NewIterator_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_NewIterator_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
  };
  function LevelDBDatabase_NewIteratorFromSnapshot_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_NewIteratorFromSnapshot_Params.prototype.initDefaults_ = function() {
    this.snapshot = null;
  };
  LevelDBDatabase_NewIteratorFromSnapshot_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_NewIteratorFromSnapshot_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_NewIteratorFromSnapshot_Params.snapshot
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_NewIteratorFromSnapshot_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_NewIteratorFromSnapshot_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_NewIteratorFromSnapshot_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.snapshot = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_NewIteratorFromSnapshot_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_NewIteratorFromSnapshot_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.snapshot);
  };
  function LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.prototype.initDefaults_ = function() {
    this.iterator = null;
  };
  LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
  };
  function LevelDBDatabase_ReleaseIterator_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_ReleaseIterator_Params.prototype.initDefaults_ = function() {
    this.iterator = null;
  };
  LevelDBDatabase_ReleaseIterator_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_ReleaseIterator_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_ReleaseIterator_Params.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_ReleaseIterator_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_ReleaseIterator_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_ReleaseIterator_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_ReleaseIterator_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_ReleaseIterator_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
  };
  function LevelDBDatabase_IteratorSeekToFirst_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorSeekToFirst_Params.prototype.initDefaults_ = function() {
    this.iterator = null;
  };
  LevelDBDatabase_IteratorSeekToFirst_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorSeekToFirst_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_IteratorSeekToFirst_Params.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorSeekToFirst_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_IteratorSeekToFirst_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorSeekToFirst_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_IteratorSeekToFirst_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorSeekToFirst_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
  };
  function LevelDBDatabase_IteratorSeekToFirst_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorSeekToFirst_ResponseParams.prototype.initDefaults_ = function() {
    this.valid = false;
    this.status = 0;
    this.key = null;
    this.value = null;
  };
  LevelDBDatabase_IteratorSeekToFirst_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorSeekToFirst_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate LevelDBDatabase_IteratorSeekToFirst_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorSeekToFirst_ResponseParams.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorSeekToFirst_ResponseParams.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorSeekToFirst_ResponseParams.encodedSize = codec.kStructHeaderSize + 24;

  LevelDBDatabase_IteratorSeekToFirst_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorSeekToFirst_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.valid = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.status = decoder.decodeStruct(codec.Int32);
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_IteratorSeekToFirst_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorSeekToFirst_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.valid & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function LevelDBDatabase_IteratorSeekToLast_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorSeekToLast_Params.prototype.initDefaults_ = function() {
    this.iterator = null;
  };
  LevelDBDatabase_IteratorSeekToLast_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorSeekToLast_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_IteratorSeekToLast_Params.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorSeekToLast_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_IteratorSeekToLast_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorSeekToLast_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_IteratorSeekToLast_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorSeekToLast_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
  };
  function LevelDBDatabase_IteratorSeekToLast_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorSeekToLast_ResponseParams.prototype.initDefaults_ = function() {
    this.valid = false;
    this.status = 0;
    this.key = null;
    this.value = null;
  };
  LevelDBDatabase_IteratorSeekToLast_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorSeekToLast_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate LevelDBDatabase_IteratorSeekToLast_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorSeekToLast_ResponseParams.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorSeekToLast_ResponseParams.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorSeekToLast_ResponseParams.encodedSize = codec.kStructHeaderSize + 24;

  LevelDBDatabase_IteratorSeekToLast_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorSeekToLast_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.valid = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.status = decoder.decodeStruct(codec.Int32);
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_IteratorSeekToLast_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorSeekToLast_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.valid & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function LevelDBDatabase_IteratorSeek_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorSeek_Params.prototype.initDefaults_ = function() {
    this.iterator = null;
    this.target = null;
  };
  LevelDBDatabase_IteratorSeek_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorSeek_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_IteratorSeek_Params.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorSeek_Params.target
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorSeek_Params.encodedSize = codec.kStructHeaderSize + 16;

  LevelDBDatabase_IteratorSeek_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorSeek_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    val.target = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_IteratorSeek_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorSeek_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
    encoder.encodeArrayPointer(codec.Uint8, val.target);
  };
  function LevelDBDatabase_IteratorSeek_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorSeek_ResponseParams.prototype.initDefaults_ = function() {
    this.valid = false;
    this.status = 0;
    this.key = null;
    this.value = null;
  };
  LevelDBDatabase_IteratorSeek_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorSeek_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate LevelDBDatabase_IteratorSeek_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorSeek_ResponseParams.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorSeek_ResponseParams.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorSeek_ResponseParams.encodedSize = codec.kStructHeaderSize + 24;

  LevelDBDatabase_IteratorSeek_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorSeek_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.valid = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.status = decoder.decodeStruct(codec.Int32);
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_IteratorSeek_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorSeek_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.valid & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function LevelDBDatabase_IteratorNext_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorNext_Params.prototype.initDefaults_ = function() {
    this.iterator = null;
  };
  LevelDBDatabase_IteratorNext_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorNext_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_IteratorNext_Params.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorNext_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_IteratorNext_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorNext_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_IteratorNext_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorNext_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
  };
  function LevelDBDatabase_IteratorNext_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorNext_ResponseParams.prototype.initDefaults_ = function() {
    this.valid = false;
    this.status = 0;
    this.key = null;
    this.value = null;
  };
  LevelDBDatabase_IteratorNext_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorNext_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate LevelDBDatabase_IteratorNext_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorNext_ResponseParams.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorNext_ResponseParams.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorNext_ResponseParams.encodedSize = codec.kStructHeaderSize + 24;

  LevelDBDatabase_IteratorNext_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorNext_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.valid = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.status = decoder.decodeStruct(codec.Int32);
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_IteratorNext_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorNext_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.valid & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  function LevelDBDatabase_IteratorPrev_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorPrev_Params.prototype.initDefaults_ = function() {
    this.iterator = null;
  };
  LevelDBDatabase_IteratorPrev_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorPrev_Params.validate = function(messageValidator, offset) {
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


    
    // validate LevelDBDatabase_IteratorPrev_Params.iterator
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, unguessable_token$.UnguessableToken, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorPrev_Params.encodedSize = codec.kStructHeaderSize + 8;

  LevelDBDatabase_IteratorPrev_Params.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorPrev_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.iterator = decoder.decodeStructPointer(unguessable_token$.UnguessableToken);
    return val;
  };

  LevelDBDatabase_IteratorPrev_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorPrev_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(unguessable_token$.UnguessableToken, val.iterator);
  };
  function LevelDBDatabase_IteratorPrev_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LevelDBDatabase_IteratorPrev_ResponseParams.prototype.initDefaults_ = function() {
    this.valid = false;
    this.status = 0;
    this.key = null;
    this.value = null;
  };
  LevelDBDatabase_IteratorPrev_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LevelDBDatabase_IteratorPrev_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate LevelDBDatabase_IteratorPrev_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, DatabaseError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorPrev_ResponseParams.key
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LevelDBDatabase_IteratorPrev_ResponseParams.value
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LevelDBDatabase_IteratorPrev_ResponseParams.encodedSize = codec.kStructHeaderSize + 24;

  LevelDBDatabase_IteratorPrev_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new LevelDBDatabase_IteratorPrev_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.valid = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.status = decoder.decodeStruct(codec.Int32);
    val.key = decoder.decodeArrayPointer(codec.Uint8);
    val.value = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  LevelDBDatabase_IteratorPrev_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LevelDBDatabase_IteratorPrev_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.valid & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.encodeArrayPointer(codec.Uint8, val.key);
    encoder.encodeArrayPointer(codec.Uint8, val.value);
  };
  var kLevelDBService_Open_Name = 0;
  var kLevelDBService_OpenWithOptions_Name = 1;
  var kLevelDBService_OpenInMemory_Name = 2;
  var kLevelDBService_Destroy_Name = 3;

  function LevelDBServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(LevelDBService,
                                                   handleOrPtrInfo);
  }

  function LevelDBServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  LevelDBServicePtr.prototype.open = function() {
    return LevelDBServiceProxy.prototype.open
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBServiceProxy.prototype.open = function(directory, dbname, database) {
    var params = new LevelDBService_Open_Params();
    params.directory = directory;
    params.dbname = dbname;
    params.database = database;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBService_Open_Name,
          codec.align(LevelDBService_Open_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBService_Open_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBService_Open_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBServicePtr.prototype.openWithOptions = function() {
    return LevelDBServiceProxy.prototype.openWithOptions
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBServiceProxy.prototype.openWithOptions = function(options, directory, dbname, database) {
    var params = new LevelDBService_OpenWithOptions_Params();
    params.options = options;
    params.directory = directory;
    params.dbname = dbname;
    params.database = database;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBService_OpenWithOptions_Name,
          codec.align(LevelDBService_OpenWithOptions_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBService_OpenWithOptions_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBService_OpenWithOptions_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBServicePtr.prototype.openInMemory = function() {
    return LevelDBServiceProxy.prototype.openInMemory
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBServiceProxy.prototype.openInMemory = function(database) {
    var params = new LevelDBService_OpenInMemory_Params();
    params.database = database;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBService_OpenInMemory_Name,
          codec.align(LevelDBService_OpenInMemory_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBService_OpenInMemory_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBService_OpenInMemory_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBServicePtr.prototype.destroy = function() {
    return LevelDBServiceProxy.prototype.destroy
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBServiceProxy.prototype.destroy = function(directory, dbname) {
    var params = new LevelDBService_Destroy_Params();
    params.directory = directory;
    params.dbname = dbname;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBService_Destroy_Name,
          codec.align(LevelDBService_Destroy_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBService_Destroy_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBService_Destroy_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function LevelDBServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  LevelDBServiceStub.prototype.open = function(directory, dbname, database) {
    return this.delegate_ && this.delegate_.open && this.delegate_.open(directory, dbname, database);
  }
  LevelDBServiceStub.prototype.openWithOptions = function(options, directory, dbname, database) {
    return this.delegate_ && this.delegate_.openWithOptions && this.delegate_.openWithOptions(options, directory, dbname, database);
  }
  LevelDBServiceStub.prototype.openInMemory = function(database) {
    return this.delegate_ && this.delegate_.openInMemory && this.delegate_.openInMemory(database);
  }
  LevelDBServiceStub.prototype.destroy = function(directory, dbname) {
    return this.delegate_ && this.delegate_.destroy && this.delegate_.destroy(directory, dbname);
  }

  LevelDBServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  LevelDBServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kLevelDBService_Open_Name:
      var params = reader.decodeStruct(LevelDBService_Open_Params);
      return this.open(params.directory, params.dbname, params.database).then(function(response) {
        var responseParams =
            new LevelDBService_Open_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBService_Open_Name,
            codec.align(LevelDBService_Open_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBService_Open_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBService_OpenWithOptions_Name:
      var params = reader.decodeStruct(LevelDBService_OpenWithOptions_Params);
      return this.openWithOptions(params.options, params.directory, params.dbname, params.database).then(function(response) {
        var responseParams =
            new LevelDBService_OpenWithOptions_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBService_OpenWithOptions_Name,
            codec.align(LevelDBService_OpenWithOptions_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBService_OpenWithOptions_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBService_OpenInMemory_Name:
      var params = reader.decodeStruct(LevelDBService_OpenInMemory_Params);
      return this.openInMemory(params.database).then(function(response) {
        var responseParams =
            new LevelDBService_OpenInMemory_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBService_OpenInMemory_Name,
            codec.align(LevelDBService_OpenInMemory_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBService_OpenInMemory_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBService_Destroy_Name:
      var params = reader.decodeStruct(LevelDBService_Destroy_Params);
      return this.destroy(params.directory, params.dbname).then(function(response) {
        var responseParams =
            new LevelDBService_Destroy_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBService_Destroy_Name,
            codec.align(LevelDBService_Destroy_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBService_Destroy_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateLevelDBServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kLevelDBService_Open_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBService_Open_Params;
      break;
      case kLevelDBService_OpenWithOptions_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBService_OpenWithOptions_Params;
      break;
      case kLevelDBService_OpenInMemory_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBService_OpenInMemory_Params;
      break;
      case kLevelDBService_Destroy_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBService_Destroy_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateLevelDBServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kLevelDBService_Open_Name:
        if (message.isResponse())
          paramsClass = LevelDBService_Open_ResponseParams;
        break;
      case kLevelDBService_OpenWithOptions_Name:
        if (message.isResponse())
          paramsClass = LevelDBService_OpenWithOptions_ResponseParams;
        break;
      case kLevelDBService_OpenInMemory_Name:
        if (message.isResponse())
          paramsClass = LevelDBService_OpenInMemory_ResponseParams;
        break;
      case kLevelDBService_Destroy_Name:
        if (message.isResponse())
          paramsClass = LevelDBService_Destroy_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var LevelDBService = {
    name: 'leveldb::mojom::LevelDBService',
    ptrClass: LevelDBServicePtr,
    proxyClass: LevelDBServiceProxy,
    stubClass: LevelDBServiceStub,
    validateRequest: validateLevelDBServiceRequest,
    validateResponse: validateLevelDBServiceResponse,
  };
  LevelDBServiceStub.prototype.validator = validateLevelDBServiceRequest;
  LevelDBServiceProxy.prototype.validator = validateLevelDBServiceResponse;
  var kLevelDBDatabase_Put_Name = 0;
  var kLevelDBDatabase_Delete_Name = 1;
  var kLevelDBDatabase_DeletePrefixed_Name = 2;
  var kLevelDBDatabase_Write_Name = 3;
  var kLevelDBDatabase_Get_Name = 4;
  var kLevelDBDatabase_GetPrefixed_Name = 5;
  var kLevelDBDatabase_GetSnapshot_Name = 6;
  var kLevelDBDatabase_ReleaseSnapshot_Name = 7;
  var kLevelDBDatabase_GetFromSnapshot_Name = 8;
  var kLevelDBDatabase_NewIterator_Name = 9;
  var kLevelDBDatabase_NewIteratorFromSnapshot_Name = 10;
  var kLevelDBDatabase_ReleaseIterator_Name = 11;
  var kLevelDBDatabase_IteratorSeekToFirst_Name = 12;
  var kLevelDBDatabase_IteratorSeekToLast_Name = 13;
  var kLevelDBDatabase_IteratorSeek_Name = 14;
  var kLevelDBDatabase_IteratorNext_Name = 15;
  var kLevelDBDatabase_IteratorPrev_Name = 16;

  function LevelDBDatabasePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(LevelDBDatabase,
                                                   handleOrPtrInfo);
  }

  function LevelDBDatabaseProxy(receiver) {
    this.receiver_ = receiver;
  }
  LevelDBDatabasePtr.prototype.put = function() {
    return LevelDBDatabaseProxy.prototype.put
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.put = function(key, value) {
    var params = new LevelDBDatabase_Put_Params();
    params.key = key;
    params.value = value;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_Put_Name,
          codec.align(LevelDBDatabase_Put_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_Put_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_Put_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.delete = function() {
    return LevelDBDatabaseProxy.prototype.delete
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.delete = function(key) {
    var params = new LevelDBDatabase_Delete_Params();
    params.key = key;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_Delete_Name,
          codec.align(LevelDBDatabase_Delete_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_Delete_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_Delete_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.deletePrefixed = function() {
    return LevelDBDatabaseProxy.prototype.deletePrefixed
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.deletePrefixed = function(key_prefix) {
    var params = new LevelDBDatabase_DeletePrefixed_Params();
    params.key_prefix = key_prefix;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_DeletePrefixed_Name,
          codec.align(LevelDBDatabase_DeletePrefixed_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_DeletePrefixed_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_DeletePrefixed_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.write = function() {
    return LevelDBDatabaseProxy.prototype.write
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.write = function(operations) {
    var params = new LevelDBDatabase_Write_Params();
    params.operations = operations;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_Write_Name,
          codec.align(LevelDBDatabase_Write_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_Write_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_Write_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.get = function() {
    return LevelDBDatabaseProxy.prototype.get
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.get = function(key) {
    var params = new LevelDBDatabase_Get_Params();
    params.key = key;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_Get_Name,
          codec.align(LevelDBDatabase_Get_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_Get_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_Get_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.getPrefixed = function() {
    return LevelDBDatabaseProxy.prototype.getPrefixed
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.getPrefixed = function(key_prefix) {
    var params = new LevelDBDatabase_GetPrefixed_Params();
    params.key_prefix = key_prefix;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_GetPrefixed_Name,
          codec.align(LevelDBDatabase_GetPrefixed_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_GetPrefixed_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_GetPrefixed_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.getSnapshot = function() {
    return LevelDBDatabaseProxy.prototype.getSnapshot
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.getSnapshot = function() {
    var params = new LevelDBDatabase_GetSnapshot_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_GetSnapshot_Name,
          codec.align(LevelDBDatabase_GetSnapshot_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_GetSnapshot_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_GetSnapshot_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.releaseSnapshot = function() {
    return LevelDBDatabaseProxy.prototype.releaseSnapshot
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.releaseSnapshot = function(snapshot) {
    var params = new LevelDBDatabase_ReleaseSnapshot_Params();
    params.snapshot = snapshot;
    var builder = new codec.MessageBuilder(
        kLevelDBDatabase_ReleaseSnapshot_Name,
        codec.align(LevelDBDatabase_ReleaseSnapshot_Params.encodedSize));
    builder.encodeStruct(LevelDBDatabase_ReleaseSnapshot_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  LevelDBDatabasePtr.prototype.getFromSnapshot = function() {
    return LevelDBDatabaseProxy.prototype.getFromSnapshot
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.getFromSnapshot = function(snapshot, key) {
    var params = new LevelDBDatabase_GetFromSnapshot_Params();
    params.snapshot = snapshot;
    params.key = key;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_GetFromSnapshot_Name,
          codec.align(LevelDBDatabase_GetFromSnapshot_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_GetFromSnapshot_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_GetFromSnapshot_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.newIterator = function() {
    return LevelDBDatabaseProxy.prototype.newIterator
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.newIterator = function() {
    var params = new LevelDBDatabase_NewIterator_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_NewIterator_Name,
          codec.align(LevelDBDatabase_NewIterator_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_NewIterator_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_NewIterator_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.newIteratorFromSnapshot = function() {
    return LevelDBDatabaseProxy.prototype.newIteratorFromSnapshot
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.newIteratorFromSnapshot = function(snapshot) {
    var params = new LevelDBDatabase_NewIteratorFromSnapshot_Params();
    params.snapshot = snapshot;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_NewIteratorFromSnapshot_Name,
          codec.align(LevelDBDatabase_NewIteratorFromSnapshot_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_NewIteratorFromSnapshot_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.releaseIterator = function() {
    return LevelDBDatabaseProxy.prototype.releaseIterator
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.releaseIterator = function(iterator) {
    var params = new LevelDBDatabase_ReleaseIterator_Params();
    params.iterator = iterator;
    var builder = new codec.MessageBuilder(
        kLevelDBDatabase_ReleaseIterator_Name,
        codec.align(LevelDBDatabase_ReleaseIterator_Params.encodedSize));
    builder.encodeStruct(LevelDBDatabase_ReleaseIterator_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  LevelDBDatabasePtr.prototype.iteratorSeekToFirst = function() {
    return LevelDBDatabaseProxy.prototype.iteratorSeekToFirst
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.iteratorSeekToFirst = function(iterator) {
    var params = new LevelDBDatabase_IteratorSeekToFirst_Params();
    params.iterator = iterator;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_IteratorSeekToFirst_Name,
          codec.align(LevelDBDatabase_IteratorSeekToFirst_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_IteratorSeekToFirst_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_IteratorSeekToFirst_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.iteratorSeekToLast = function() {
    return LevelDBDatabaseProxy.prototype.iteratorSeekToLast
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.iteratorSeekToLast = function(iterator) {
    var params = new LevelDBDatabase_IteratorSeekToLast_Params();
    params.iterator = iterator;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_IteratorSeekToLast_Name,
          codec.align(LevelDBDatabase_IteratorSeekToLast_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_IteratorSeekToLast_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_IteratorSeekToLast_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.iteratorSeek = function() {
    return LevelDBDatabaseProxy.prototype.iteratorSeek
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.iteratorSeek = function(iterator, target) {
    var params = new LevelDBDatabase_IteratorSeek_Params();
    params.iterator = iterator;
    params.target = target;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_IteratorSeek_Name,
          codec.align(LevelDBDatabase_IteratorSeek_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_IteratorSeek_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_IteratorSeek_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.iteratorNext = function() {
    return LevelDBDatabaseProxy.prototype.iteratorNext
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.iteratorNext = function(iterator) {
    var params = new LevelDBDatabase_IteratorNext_Params();
    params.iterator = iterator;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_IteratorNext_Name,
          codec.align(LevelDBDatabase_IteratorNext_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_IteratorNext_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_IteratorNext_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  LevelDBDatabasePtr.prototype.iteratorPrev = function() {
    return LevelDBDatabaseProxy.prototype.iteratorPrev
        .apply(this.ptr.getProxy(), arguments);
  };

  LevelDBDatabaseProxy.prototype.iteratorPrev = function(iterator) {
    var params = new LevelDBDatabase_IteratorPrev_Params();
    params.iterator = iterator;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kLevelDBDatabase_IteratorPrev_Name,
          codec.align(LevelDBDatabase_IteratorPrev_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(LevelDBDatabase_IteratorPrev_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(LevelDBDatabase_IteratorPrev_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function LevelDBDatabaseStub(delegate) {
    this.delegate_ = delegate;
  }
  LevelDBDatabaseStub.prototype.put = function(key, value) {
    return this.delegate_ && this.delegate_.put && this.delegate_.put(key, value);
  }
  LevelDBDatabaseStub.prototype.delete = function(key) {
    return this.delegate_ && this.delegate_.delete && this.delegate_.delete(key);
  }
  LevelDBDatabaseStub.prototype.deletePrefixed = function(key_prefix) {
    return this.delegate_ && this.delegate_.deletePrefixed && this.delegate_.deletePrefixed(key_prefix);
  }
  LevelDBDatabaseStub.prototype.write = function(operations) {
    return this.delegate_ && this.delegate_.write && this.delegate_.write(operations);
  }
  LevelDBDatabaseStub.prototype.get = function(key) {
    return this.delegate_ && this.delegate_.get && this.delegate_.get(key);
  }
  LevelDBDatabaseStub.prototype.getPrefixed = function(key_prefix) {
    return this.delegate_ && this.delegate_.getPrefixed && this.delegate_.getPrefixed(key_prefix);
  }
  LevelDBDatabaseStub.prototype.getSnapshot = function() {
    return this.delegate_ && this.delegate_.getSnapshot && this.delegate_.getSnapshot();
  }
  LevelDBDatabaseStub.prototype.releaseSnapshot = function(snapshot) {
    return this.delegate_ && this.delegate_.releaseSnapshot && this.delegate_.releaseSnapshot(snapshot);
  }
  LevelDBDatabaseStub.prototype.getFromSnapshot = function(snapshot, key) {
    return this.delegate_ && this.delegate_.getFromSnapshot && this.delegate_.getFromSnapshot(snapshot, key);
  }
  LevelDBDatabaseStub.prototype.newIterator = function() {
    return this.delegate_ && this.delegate_.newIterator && this.delegate_.newIterator();
  }
  LevelDBDatabaseStub.prototype.newIteratorFromSnapshot = function(snapshot) {
    return this.delegate_ && this.delegate_.newIteratorFromSnapshot && this.delegate_.newIteratorFromSnapshot(snapshot);
  }
  LevelDBDatabaseStub.prototype.releaseIterator = function(iterator) {
    return this.delegate_ && this.delegate_.releaseIterator && this.delegate_.releaseIterator(iterator);
  }
  LevelDBDatabaseStub.prototype.iteratorSeekToFirst = function(iterator) {
    return this.delegate_ && this.delegate_.iteratorSeekToFirst && this.delegate_.iteratorSeekToFirst(iterator);
  }
  LevelDBDatabaseStub.prototype.iteratorSeekToLast = function(iterator) {
    return this.delegate_ && this.delegate_.iteratorSeekToLast && this.delegate_.iteratorSeekToLast(iterator);
  }
  LevelDBDatabaseStub.prototype.iteratorSeek = function(iterator, target) {
    return this.delegate_ && this.delegate_.iteratorSeek && this.delegate_.iteratorSeek(iterator, target);
  }
  LevelDBDatabaseStub.prototype.iteratorNext = function(iterator) {
    return this.delegate_ && this.delegate_.iteratorNext && this.delegate_.iteratorNext(iterator);
  }
  LevelDBDatabaseStub.prototype.iteratorPrev = function(iterator) {
    return this.delegate_ && this.delegate_.iteratorPrev && this.delegate_.iteratorPrev(iterator);
  }

  LevelDBDatabaseStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kLevelDBDatabase_ReleaseSnapshot_Name:
      var params = reader.decodeStruct(LevelDBDatabase_ReleaseSnapshot_Params);
      this.releaseSnapshot(params.snapshot);
      return true;
    case kLevelDBDatabase_ReleaseIterator_Name:
      var params = reader.decodeStruct(LevelDBDatabase_ReleaseIterator_Params);
      this.releaseIterator(params.iterator);
      return true;
    default:
      return false;
    }
  };

  LevelDBDatabaseStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kLevelDBDatabase_Put_Name:
      var params = reader.decodeStruct(LevelDBDatabase_Put_Params);
      return this.put(params.key, params.value).then(function(response) {
        var responseParams =
            new LevelDBDatabase_Put_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_Put_Name,
            codec.align(LevelDBDatabase_Put_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_Put_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_Delete_Name:
      var params = reader.decodeStruct(LevelDBDatabase_Delete_Params);
      return this.delete(params.key).then(function(response) {
        var responseParams =
            new LevelDBDatabase_Delete_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_Delete_Name,
            codec.align(LevelDBDatabase_Delete_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_Delete_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_DeletePrefixed_Name:
      var params = reader.decodeStruct(LevelDBDatabase_DeletePrefixed_Params);
      return this.deletePrefixed(params.key_prefix).then(function(response) {
        var responseParams =
            new LevelDBDatabase_DeletePrefixed_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_DeletePrefixed_Name,
            codec.align(LevelDBDatabase_DeletePrefixed_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_DeletePrefixed_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_Write_Name:
      var params = reader.decodeStruct(LevelDBDatabase_Write_Params);
      return this.write(params.operations).then(function(response) {
        var responseParams =
            new LevelDBDatabase_Write_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_Write_Name,
            codec.align(LevelDBDatabase_Write_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_Write_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_Get_Name:
      var params = reader.decodeStruct(LevelDBDatabase_Get_Params);
      return this.get(params.key).then(function(response) {
        var responseParams =
            new LevelDBDatabase_Get_ResponseParams();
        responseParams.status = response.status;
        responseParams.value = response.value;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_Get_Name,
            codec.align(LevelDBDatabase_Get_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_Get_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_GetPrefixed_Name:
      var params = reader.decodeStruct(LevelDBDatabase_GetPrefixed_Params);
      return this.getPrefixed(params.key_prefix).then(function(response) {
        var responseParams =
            new LevelDBDatabase_GetPrefixed_ResponseParams();
        responseParams.status = response.status;
        responseParams.data = response.data;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_GetPrefixed_Name,
            codec.align(LevelDBDatabase_GetPrefixed_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_GetPrefixed_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_GetSnapshot_Name:
      var params = reader.decodeStruct(LevelDBDatabase_GetSnapshot_Params);
      return this.getSnapshot().then(function(response) {
        var responseParams =
            new LevelDBDatabase_GetSnapshot_ResponseParams();
        responseParams.snapshot = response.snapshot;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_GetSnapshot_Name,
            codec.align(LevelDBDatabase_GetSnapshot_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_GetSnapshot_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_GetFromSnapshot_Name:
      var params = reader.decodeStruct(LevelDBDatabase_GetFromSnapshot_Params);
      return this.getFromSnapshot(params.snapshot, params.key).then(function(response) {
        var responseParams =
            new LevelDBDatabase_GetFromSnapshot_ResponseParams();
        responseParams.status = response.status;
        responseParams.value = response.value;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_GetFromSnapshot_Name,
            codec.align(LevelDBDatabase_GetFromSnapshot_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_GetFromSnapshot_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_NewIterator_Name:
      var params = reader.decodeStruct(LevelDBDatabase_NewIterator_Params);
      return this.newIterator().then(function(response) {
        var responseParams =
            new LevelDBDatabase_NewIterator_ResponseParams();
        responseParams.iterator = response.iterator;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_NewIterator_Name,
            codec.align(LevelDBDatabase_NewIterator_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_NewIterator_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_NewIteratorFromSnapshot_Name:
      var params = reader.decodeStruct(LevelDBDatabase_NewIteratorFromSnapshot_Params);
      return this.newIteratorFromSnapshot(params.snapshot).then(function(response) {
        var responseParams =
            new LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams();
        responseParams.iterator = response.iterator;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_NewIteratorFromSnapshot_Name,
            codec.align(LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_IteratorSeekToFirst_Name:
      var params = reader.decodeStruct(LevelDBDatabase_IteratorSeekToFirst_Params);
      return this.iteratorSeekToFirst(params.iterator).then(function(response) {
        var responseParams =
            new LevelDBDatabase_IteratorSeekToFirst_ResponseParams();
        responseParams.valid = response.valid;
        responseParams.status = response.status;
        responseParams.key = response.key;
        responseParams.value = response.value;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_IteratorSeekToFirst_Name,
            codec.align(LevelDBDatabase_IteratorSeekToFirst_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_IteratorSeekToFirst_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_IteratorSeekToLast_Name:
      var params = reader.decodeStruct(LevelDBDatabase_IteratorSeekToLast_Params);
      return this.iteratorSeekToLast(params.iterator).then(function(response) {
        var responseParams =
            new LevelDBDatabase_IteratorSeekToLast_ResponseParams();
        responseParams.valid = response.valid;
        responseParams.status = response.status;
        responseParams.key = response.key;
        responseParams.value = response.value;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_IteratorSeekToLast_Name,
            codec.align(LevelDBDatabase_IteratorSeekToLast_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_IteratorSeekToLast_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_IteratorSeek_Name:
      var params = reader.decodeStruct(LevelDBDatabase_IteratorSeek_Params);
      return this.iteratorSeek(params.iterator, params.target).then(function(response) {
        var responseParams =
            new LevelDBDatabase_IteratorSeek_ResponseParams();
        responseParams.valid = response.valid;
        responseParams.status = response.status;
        responseParams.key = response.key;
        responseParams.value = response.value;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_IteratorSeek_Name,
            codec.align(LevelDBDatabase_IteratorSeek_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_IteratorSeek_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_IteratorNext_Name:
      var params = reader.decodeStruct(LevelDBDatabase_IteratorNext_Params);
      return this.iteratorNext(params.iterator).then(function(response) {
        var responseParams =
            new LevelDBDatabase_IteratorNext_ResponseParams();
        responseParams.valid = response.valid;
        responseParams.status = response.status;
        responseParams.key = response.key;
        responseParams.value = response.value;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_IteratorNext_Name,
            codec.align(LevelDBDatabase_IteratorNext_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_IteratorNext_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kLevelDBDatabase_IteratorPrev_Name:
      var params = reader.decodeStruct(LevelDBDatabase_IteratorPrev_Params);
      return this.iteratorPrev(params.iterator).then(function(response) {
        var responseParams =
            new LevelDBDatabase_IteratorPrev_ResponseParams();
        responseParams.valid = response.valid;
        responseParams.status = response.status;
        responseParams.key = response.key;
        responseParams.value = response.value;
        var builder = new codec.MessageWithRequestIDBuilder(
            kLevelDBDatabase_IteratorPrev_Name,
            codec.align(LevelDBDatabase_IteratorPrev_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(LevelDBDatabase_IteratorPrev_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateLevelDBDatabaseRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kLevelDBDatabase_Put_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_Put_Params;
      break;
      case kLevelDBDatabase_Delete_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_Delete_Params;
      break;
      case kLevelDBDatabase_DeletePrefixed_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_DeletePrefixed_Params;
      break;
      case kLevelDBDatabase_Write_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_Write_Params;
      break;
      case kLevelDBDatabase_Get_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_Get_Params;
      break;
      case kLevelDBDatabase_GetPrefixed_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_GetPrefixed_Params;
      break;
      case kLevelDBDatabase_GetSnapshot_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_GetSnapshot_Params;
      break;
      case kLevelDBDatabase_ReleaseSnapshot_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = LevelDBDatabase_ReleaseSnapshot_Params;
      break;
      case kLevelDBDatabase_GetFromSnapshot_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_GetFromSnapshot_Params;
      break;
      case kLevelDBDatabase_NewIterator_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_NewIterator_Params;
      break;
      case kLevelDBDatabase_NewIteratorFromSnapshot_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_NewIteratorFromSnapshot_Params;
      break;
      case kLevelDBDatabase_ReleaseIterator_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = LevelDBDatabase_ReleaseIterator_Params;
      break;
      case kLevelDBDatabase_IteratorSeekToFirst_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_IteratorSeekToFirst_Params;
      break;
      case kLevelDBDatabase_IteratorSeekToLast_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_IteratorSeekToLast_Params;
      break;
      case kLevelDBDatabase_IteratorSeek_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_IteratorSeek_Params;
      break;
      case kLevelDBDatabase_IteratorNext_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_IteratorNext_Params;
      break;
      case kLevelDBDatabase_IteratorPrev_Name:
        if (message.expectsResponse())
          paramsClass = LevelDBDatabase_IteratorPrev_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateLevelDBDatabaseResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kLevelDBDatabase_Put_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_Put_ResponseParams;
        break;
      case kLevelDBDatabase_Delete_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_Delete_ResponseParams;
        break;
      case kLevelDBDatabase_DeletePrefixed_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_DeletePrefixed_ResponseParams;
        break;
      case kLevelDBDatabase_Write_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_Write_ResponseParams;
        break;
      case kLevelDBDatabase_Get_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_Get_ResponseParams;
        break;
      case kLevelDBDatabase_GetPrefixed_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_GetPrefixed_ResponseParams;
        break;
      case kLevelDBDatabase_GetSnapshot_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_GetSnapshot_ResponseParams;
        break;
      case kLevelDBDatabase_GetFromSnapshot_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_GetFromSnapshot_ResponseParams;
        break;
      case kLevelDBDatabase_NewIterator_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_NewIterator_ResponseParams;
        break;
      case kLevelDBDatabase_NewIteratorFromSnapshot_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams;
        break;
      case kLevelDBDatabase_IteratorSeekToFirst_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_IteratorSeekToFirst_ResponseParams;
        break;
      case kLevelDBDatabase_IteratorSeekToLast_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_IteratorSeekToLast_ResponseParams;
        break;
      case kLevelDBDatabase_IteratorSeek_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_IteratorSeek_ResponseParams;
        break;
      case kLevelDBDatabase_IteratorNext_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_IteratorNext_ResponseParams;
        break;
      case kLevelDBDatabase_IteratorPrev_Name:
        if (message.isResponse())
          paramsClass = LevelDBDatabase_IteratorPrev_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var LevelDBDatabase = {
    name: 'leveldb::mojom::LevelDBDatabase',
    ptrClass: LevelDBDatabasePtr,
    proxyClass: LevelDBDatabaseProxy,
    stubClass: LevelDBDatabaseStub,
    validateRequest: validateLevelDBDatabaseRequest,
    validateResponse: validateLevelDBDatabaseResponse,
  };
  LevelDBDatabaseStub.prototype.validator = validateLevelDBDatabaseRequest;
  LevelDBDatabaseProxy.prototype.validator = validateLevelDBDatabaseResponse;

  var exports = {};
  exports.DatabaseError = DatabaseError;
  exports.BatchOperationType = BatchOperationType;
  exports.BatchedOperation = BatchedOperation;
  exports.KeyValue = KeyValue;
  exports.OpenOptions = OpenOptions;
  exports.LevelDBService = LevelDBService;
  exports.LevelDBServicePtr = LevelDBServicePtr;
  exports.LevelDBDatabase = LevelDBDatabase;
  exports.LevelDBDatabasePtr = LevelDBDatabasePtr;

  return exports;
});
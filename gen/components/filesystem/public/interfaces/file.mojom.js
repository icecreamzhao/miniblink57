// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/filesystem/public/interfaces/file.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "components/filesystem/public/interfaces/types.mojom",
    "mojo/common/file.mojom",
], function(bindings, codec, core, validator, types$, file$) {

  function File_Close_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Close_Params.prototype.initDefaults_ = function() {
  };
  File_Close_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Close_Params.validate = function(messageValidator, offset) {
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

  File_Close_Params.encodedSize = codec.kStructHeaderSize + 0;

  File_Close_Params.decode = function(decoder) {
    var packed;
    var val = new File_Close_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  File_Close_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Close_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function File_Close_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Close_ResponseParams.prototype.initDefaults_ = function() {
    this.err = 0;
  };
  File_Close_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Close_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Close_ResponseParams.err
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Close_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Close_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Close_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.err = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Close_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Close_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.err);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Read_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Read_Params.prototype.initDefaults_ = function() {
    this.num_bytes_to_read = 0;
    this.whence = 0;
    this.offset = 0;
  };
  File_Read_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Read_Params.validate = function(messageValidator, offset) {
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




    
    // validate File_Read_Params.whence
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, types$.Whence);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Read_Params.encodedSize = codec.kStructHeaderSize + 16;

  File_Read_Params.decode = function(decoder) {
    var packed;
    var val = new File_Read_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.num_bytes_to_read = decoder.decodeStruct(codec.Uint32);
    val.whence = decoder.decodeStruct(codec.Int32);
    val.offset = decoder.decodeStruct(codec.Int64);
    return val;
  };

  File_Read_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Read_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.num_bytes_to_read);
    encoder.encodeStruct(codec.Int32, val.whence);
    encoder.encodeStruct(codec.Int64, val.offset);
  };
  function File_Read_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Read_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
    this.bytes_read = null;
  };
  File_Read_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Read_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Read_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate File_Read_ResponseParams.bytes_read
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Read_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  File_Read_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Read_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.bytes_read = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  File_Read_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Read_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.Uint8, val.bytes_read);
  };
  function File_Write_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Write_Params.prototype.initDefaults_ = function() {
    this.bytes_to_write = null;
    this.offset = 0;
    this.whence = 0;
  };
  File_Write_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Write_Params.validate = function(messageValidator, offset) {
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


    
    // validate File_Write_Params.bytes_to_write
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate File_Write_Params.whence
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, types$.Whence);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Write_Params.encodedSize = codec.kStructHeaderSize + 24;

  File_Write_Params.decode = function(decoder) {
    var packed;
    var val = new File_Write_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.bytes_to_write = decoder.decodeArrayPointer(codec.Uint8);
    val.offset = decoder.decodeStruct(codec.Int64);
    val.whence = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Write_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Write_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.bytes_to_write);
    encoder.encodeStruct(codec.Int64, val.offset);
    encoder.encodeStruct(codec.Int32, val.whence);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Write_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Write_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
    this.num_bytes_written = 0;
  };
  File_Write_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Write_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Write_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  File_Write_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Write_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Write_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    val.num_bytes_written = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  File_Write_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Write_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.encodeStruct(codec.Uint32, val.num_bytes_written);
  };
  function File_Tell_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Tell_Params.prototype.initDefaults_ = function() {
  };
  File_Tell_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Tell_Params.validate = function(messageValidator, offset) {
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

  File_Tell_Params.encodedSize = codec.kStructHeaderSize + 0;

  File_Tell_Params.decode = function(decoder) {
    var packed;
    var val = new File_Tell_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  File_Tell_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Tell_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function File_Tell_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Tell_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
    this.position = 0;
  };
  File_Tell_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Tell_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Tell_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  File_Tell_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  File_Tell_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Tell_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.position = decoder.decodeStruct(codec.Int64);
    return val;
  };

  File_Tell_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Tell_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int64, val.position);
  };
  function File_Seek_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Seek_Params.prototype.initDefaults_ = function() {
    this.offset = 0;
    this.whence = 0;
  };
  File_Seek_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Seek_Params.validate = function(messageValidator, offset) {
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



    
    // validate File_Seek_Params.whence
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, types$.Whence);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Seek_Params.encodedSize = codec.kStructHeaderSize + 16;

  File_Seek_Params.decode = function(decoder) {
    var packed;
    var val = new File_Seek_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.offset = decoder.decodeStruct(codec.Int64);
    val.whence = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Seek_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Seek_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.offset);
    encoder.encodeStruct(codec.Int32, val.whence);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Seek_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Seek_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
    this.position = 0;
  };
  File_Seek_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Seek_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Seek_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  File_Seek_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  File_Seek_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Seek_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.position = decoder.decodeStruct(codec.Int64);
    return val;
  };

  File_Seek_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Seek_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int64, val.position);
  };
  function File_Stat_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Stat_Params.prototype.initDefaults_ = function() {
  };
  File_Stat_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Stat_Params.validate = function(messageValidator, offset) {
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

  File_Stat_Params.encodedSize = codec.kStructHeaderSize + 0;

  File_Stat_Params.decode = function(decoder) {
    var packed;
    var val = new File_Stat_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  File_Stat_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Stat_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function File_Stat_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Stat_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
    this.file_information = null;
  };
  File_Stat_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Stat_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Stat_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate File_Stat_ResponseParams.file_information
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, types$.FileInformation, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Stat_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  File_Stat_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Stat_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.file_information = decoder.decodeStructPointer(types$.FileInformation);
    return val;
  };

  File_Stat_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Stat_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(types$.FileInformation, val.file_information);
  };
  function File_Truncate_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Truncate_Params.prototype.initDefaults_ = function() {
    this.size = 0;
  };
  File_Truncate_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Truncate_Params.validate = function(messageValidator, offset) {
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

  File_Truncate_Params.encodedSize = codec.kStructHeaderSize + 8;

  File_Truncate_Params.decode = function(decoder) {
    var packed;
    var val = new File_Truncate_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.size = decoder.decodeStruct(codec.Int64);
    return val;
  };

  File_Truncate_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Truncate_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.size);
  };
  function File_Truncate_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Truncate_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  File_Truncate_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Truncate_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Truncate_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Truncate_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Truncate_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Truncate_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Truncate_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Truncate_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Touch_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Touch_Params.prototype.initDefaults_ = function() {
    this.atime = null;
    this.mtime = null;
  };
  File_Touch_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Touch_Params.validate = function(messageValidator, offset) {
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


    
    // validate File_Touch_Params.atime
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, types$.TimespecOrNow, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate File_Touch_Params.mtime
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, types$.TimespecOrNow, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Touch_Params.encodedSize = codec.kStructHeaderSize + 16;

  File_Touch_Params.decode = function(decoder) {
    var packed;
    var val = new File_Touch_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.atime = decoder.decodeStructPointer(types$.TimespecOrNow);
    val.mtime = decoder.decodeStructPointer(types$.TimespecOrNow);
    return val;
  };

  File_Touch_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Touch_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(types$.TimespecOrNow, val.atime);
    encoder.encodeStructPointer(types$.TimespecOrNow, val.mtime);
  };
  function File_Touch_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Touch_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  File_Touch_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Touch_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Touch_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Touch_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Touch_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Touch_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Touch_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Touch_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Dup_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Dup_Params.prototype.initDefaults_ = function() {
    this.file = new bindings.InterfaceRequest();
  };
  File_Dup_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Dup_Params.validate = function(messageValidator, offset) {
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


    
    // validate File_Dup_Params.file
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Dup_Params.encodedSize = codec.kStructHeaderSize + 8;

  File_Dup_Params.decode = function(decoder) {
    var packed;
    var val = new File_Dup_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.file = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Dup_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Dup_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.file);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Dup_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Dup_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  File_Dup_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Dup_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Dup_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Dup_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Dup_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Dup_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Dup_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Dup_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Flush_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Flush_Params.prototype.initDefaults_ = function() {
  };
  File_Flush_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Flush_Params.validate = function(messageValidator, offset) {
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

  File_Flush_Params.encodedSize = codec.kStructHeaderSize + 0;

  File_Flush_Params.decode = function(decoder) {
    var packed;
    var val = new File_Flush_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  File_Flush_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Flush_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function File_Flush_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Flush_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  File_Flush_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Flush_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Flush_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Flush_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Flush_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Flush_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Flush_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Flush_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Lock_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Lock_Params.prototype.initDefaults_ = function() {
  };
  File_Lock_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Lock_Params.validate = function(messageValidator, offset) {
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

  File_Lock_Params.encodedSize = codec.kStructHeaderSize + 0;

  File_Lock_Params.decode = function(decoder) {
    var packed;
    var val = new File_Lock_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  File_Lock_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Lock_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function File_Lock_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Lock_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  File_Lock_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Lock_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Lock_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Lock_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Lock_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Lock_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Lock_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Lock_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_Unlock_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Unlock_Params.prototype.initDefaults_ = function() {
  };
  File_Unlock_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Unlock_Params.validate = function(messageValidator, offset) {
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

  File_Unlock_Params.encodedSize = codec.kStructHeaderSize + 0;

  File_Unlock_Params.decode = function(decoder) {
    var packed;
    var val = new File_Unlock_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  File_Unlock_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Unlock_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function File_Unlock_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_Unlock_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  File_Unlock_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_Unlock_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_Unlock_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_Unlock_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  File_Unlock_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_Unlock_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  File_Unlock_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_Unlock_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function File_AsHandle_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_AsHandle_Params.prototype.initDefaults_ = function() {
  };
  File_AsHandle_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_AsHandle_Params.validate = function(messageValidator, offset) {
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

  File_AsHandle_Params.encodedSize = codec.kStructHeaderSize + 0;

  File_AsHandle_Params.decode = function(decoder) {
    var packed;
    var val = new File_AsHandle_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  File_AsHandle_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_AsHandle_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function File_AsHandle_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  File_AsHandle_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
    this.file_handle = null;
  };
  File_AsHandle_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  File_AsHandle_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate File_AsHandle_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate File_AsHandle_ResponseParams.file_handle
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, file$.File, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  File_AsHandle_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  File_AsHandle_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new File_AsHandle_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.file_handle = decoder.decodeStructPointer(file$.File);
    return val;
  };

  File_AsHandle_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(File_AsHandle_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(file$.File, val.file_handle);
  };
  var kFile_Close_Name = 0;
  var kFile_Read_Name = 1;
  var kFile_Write_Name = 2;
  var kFile_Tell_Name = 3;
  var kFile_Seek_Name = 4;
  var kFile_Stat_Name = 5;
  var kFile_Truncate_Name = 6;
  var kFile_Touch_Name = 7;
  var kFile_Dup_Name = 8;
  var kFile_Flush_Name = 9;
  var kFile_Lock_Name = 10;
  var kFile_Unlock_Name = 11;
  var kFile_AsHandle_Name = 12;

  function FilePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(File,
                                                   handleOrPtrInfo);
  }

  function FileProxy(receiver) {
    this.receiver_ = receiver;
  }
  FilePtr.prototype.close = function() {
    return FileProxy.prototype.close
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.close = function() {
    var params = new File_Close_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Close_Name,
          codec.align(File_Close_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Close_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Close_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.read = function() {
    return FileProxy.prototype.read
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.read = function(num_bytes_to_read, offset, whence) {
    var params = new File_Read_Params();
    params.num_bytes_to_read = num_bytes_to_read;
    params.offset = offset;
    params.whence = whence;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Read_Name,
          codec.align(File_Read_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Read_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Read_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.write = function() {
    return FileProxy.prototype.write
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.write = function(bytes_to_write, offset, whence) {
    var params = new File_Write_Params();
    params.bytes_to_write = bytes_to_write;
    params.offset = offset;
    params.whence = whence;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Write_Name,
          codec.align(File_Write_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Write_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Write_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.tell = function() {
    return FileProxy.prototype.tell
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.tell = function() {
    var params = new File_Tell_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Tell_Name,
          codec.align(File_Tell_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Tell_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Tell_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.seek = function() {
    return FileProxy.prototype.seek
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.seek = function(offset, whence) {
    var params = new File_Seek_Params();
    params.offset = offset;
    params.whence = whence;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Seek_Name,
          codec.align(File_Seek_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Seek_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Seek_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.stat = function() {
    return FileProxy.prototype.stat
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.stat = function() {
    var params = new File_Stat_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Stat_Name,
          codec.align(File_Stat_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Stat_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Stat_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.truncate = function() {
    return FileProxy.prototype.truncate
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.truncate = function(size) {
    var params = new File_Truncate_Params();
    params.size = size;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Truncate_Name,
          codec.align(File_Truncate_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Truncate_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Truncate_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.touch = function() {
    return FileProxy.prototype.touch
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.touch = function(atime, mtime) {
    var params = new File_Touch_Params();
    params.atime = atime;
    params.mtime = mtime;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Touch_Name,
          codec.align(File_Touch_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Touch_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Touch_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.dup = function() {
    return FileProxy.prototype.dup
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.dup = function(file) {
    var params = new File_Dup_Params();
    params.file = file;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Dup_Name,
          codec.align(File_Dup_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Dup_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Dup_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.flush = function() {
    return FileProxy.prototype.flush
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.flush = function() {
    var params = new File_Flush_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Flush_Name,
          codec.align(File_Flush_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Flush_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Flush_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.lock = function() {
    return FileProxy.prototype.lock
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.lock = function() {
    var params = new File_Lock_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Lock_Name,
          codec.align(File_Lock_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Lock_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Lock_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.unlock = function() {
    return FileProxy.prototype.unlock
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.unlock = function() {
    var params = new File_Unlock_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_Unlock_Name,
          codec.align(File_Unlock_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_Unlock_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_Unlock_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FilePtr.prototype.asHandle = function() {
    return FileProxy.prototype.asHandle
        .apply(this.ptr.getProxy(), arguments);
  };

  FileProxy.prototype.asHandle = function() {
    var params = new File_AsHandle_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFile_AsHandle_Name,
          codec.align(File_AsHandle_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(File_AsHandle_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(File_AsHandle_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function FileStub(delegate) {
    this.delegate_ = delegate;
  }
  FileStub.prototype.close = function() {
    return this.delegate_ && this.delegate_.close && this.delegate_.close();
  }
  FileStub.prototype.read = function(num_bytes_to_read, offset, whence) {
    return this.delegate_ && this.delegate_.read && this.delegate_.read(num_bytes_to_read, offset, whence);
  }
  FileStub.prototype.write = function(bytes_to_write, offset, whence) {
    return this.delegate_ && this.delegate_.write && this.delegate_.write(bytes_to_write, offset, whence);
  }
  FileStub.prototype.tell = function() {
    return this.delegate_ && this.delegate_.tell && this.delegate_.tell();
  }
  FileStub.prototype.seek = function(offset, whence) {
    return this.delegate_ && this.delegate_.seek && this.delegate_.seek(offset, whence);
  }
  FileStub.prototype.stat = function() {
    return this.delegate_ && this.delegate_.stat && this.delegate_.stat();
  }
  FileStub.prototype.truncate = function(size) {
    return this.delegate_ && this.delegate_.truncate && this.delegate_.truncate(size);
  }
  FileStub.prototype.touch = function(atime, mtime) {
    return this.delegate_ && this.delegate_.touch && this.delegate_.touch(atime, mtime);
  }
  FileStub.prototype.dup = function(file) {
    return this.delegate_ && this.delegate_.dup && this.delegate_.dup(file);
  }
  FileStub.prototype.flush = function() {
    return this.delegate_ && this.delegate_.flush && this.delegate_.flush();
  }
  FileStub.prototype.lock = function() {
    return this.delegate_ && this.delegate_.lock && this.delegate_.lock();
  }
  FileStub.prototype.unlock = function() {
    return this.delegate_ && this.delegate_.unlock && this.delegate_.unlock();
  }
  FileStub.prototype.asHandle = function() {
    return this.delegate_ && this.delegate_.asHandle && this.delegate_.asHandle();
  }

  FileStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  FileStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kFile_Close_Name:
      var params = reader.decodeStruct(File_Close_Params);
      return this.close().then(function(response) {
        var responseParams =
            new File_Close_ResponseParams();
        responseParams.err = response.err;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Close_Name,
            codec.align(File_Close_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Close_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Read_Name:
      var params = reader.decodeStruct(File_Read_Params);
      return this.read(params.num_bytes_to_read, params.offset, params.whence).then(function(response) {
        var responseParams =
            new File_Read_ResponseParams();
        responseParams.error = response.error;
        responseParams.bytes_read = response.bytes_read;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Read_Name,
            codec.align(File_Read_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Read_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Write_Name:
      var params = reader.decodeStruct(File_Write_Params);
      return this.write(params.bytes_to_write, params.offset, params.whence).then(function(response) {
        var responseParams =
            new File_Write_ResponseParams();
        responseParams.error = response.error;
        responseParams.num_bytes_written = response.num_bytes_written;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Write_Name,
            codec.align(File_Write_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Write_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Tell_Name:
      var params = reader.decodeStruct(File_Tell_Params);
      return this.tell().then(function(response) {
        var responseParams =
            new File_Tell_ResponseParams();
        responseParams.error = response.error;
        responseParams.position = response.position;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Tell_Name,
            codec.align(File_Tell_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Tell_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Seek_Name:
      var params = reader.decodeStruct(File_Seek_Params);
      return this.seek(params.offset, params.whence).then(function(response) {
        var responseParams =
            new File_Seek_ResponseParams();
        responseParams.error = response.error;
        responseParams.position = response.position;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Seek_Name,
            codec.align(File_Seek_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Seek_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Stat_Name:
      var params = reader.decodeStruct(File_Stat_Params);
      return this.stat().then(function(response) {
        var responseParams =
            new File_Stat_ResponseParams();
        responseParams.error = response.error;
        responseParams.file_information = response.file_information;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Stat_Name,
            codec.align(File_Stat_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Stat_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Truncate_Name:
      var params = reader.decodeStruct(File_Truncate_Params);
      return this.truncate(params.size).then(function(response) {
        var responseParams =
            new File_Truncate_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Truncate_Name,
            codec.align(File_Truncate_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Truncate_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Touch_Name:
      var params = reader.decodeStruct(File_Touch_Params);
      return this.touch(params.atime, params.mtime).then(function(response) {
        var responseParams =
            new File_Touch_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Touch_Name,
            codec.align(File_Touch_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Touch_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Dup_Name:
      var params = reader.decodeStruct(File_Dup_Params);
      return this.dup(params.file).then(function(response) {
        var responseParams =
            new File_Dup_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Dup_Name,
            codec.align(File_Dup_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Dup_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Flush_Name:
      var params = reader.decodeStruct(File_Flush_Params);
      return this.flush().then(function(response) {
        var responseParams =
            new File_Flush_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Flush_Name,
            codec.align(File_Flush_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Flush_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Lock_Name:
      var params = reader.decodeStruct(File_Lock_Params);
      return this.lock().then(function(response) {
        var responseParams =
            new File_Lock_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Lock_Name,
            codec.align(File_Lock_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Lock_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_Unlock_Name:
      var params = reader.decodeStruct(File_Unlock_Params);
      return this.unlock().then(function(response) {
        var responseParams =
            new File_Unlock_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_Unlock_Name,
            codec.align(File_Unlock_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_Unlock_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFile_AsHandle_Name:
      var params = reader.decodeStruct(File_AsHandle_Params);
      return this.asHandle().then(function(response) {
        var responseParams =
            new File_AsHandle_ResponseParams();
        responseParams.error = response.error;
        responseParams.file_handle = response.file_handle;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFile_AsHandle_Name,
            codec.align(File_AsHandle_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(File_AsHandle_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateFileRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kFile_Close_Name:
        if (message.expectsResponse())
          paramsClass = File_Close_Params;
      break;
      case kFile_Read_Name:
        if (message.expectsResponse())
          paramsClass = File_Read_Params;
      break;
      case kFile_Write_Name:
        if (message.expectsResponse())
          paramsClass = File_Write_Params;
      break;
      case kFile_Tell_Name:
        if (message.expectsResponse())
          paramsClass = File_Tell_Params;
      break;
      case kFile_Seek_Name:
        if (message.expectsResponse())
          paramsClass = File_Seek_Params;
      break;
      case kFile_Stat_Name:
        if (message.expectsResponse())
          paramsClass = File_Stat_Params;
      break;
      case kFile_Truncate_Name:
        if (message.expectsResponse())
          paramsClass = File_Truncate_Params;
      break;
      case kFile_Touch_Name:
        if (message.expectsResponse())
          paramsClass = File_Touch_Params;
      break;
      case kFile_Dup_Name:
        if (message.expectsResponse())
          paramsClass = File_Dup_Params;
      break;
      case kFile_Flush_Name:
        if (message.expectsResponse())
          paramsClass = File_Flush_Params;
      break;
      case kFile_Lock_Name:
        if (message.expectsResponse())
          paramsClass = File_Lock_Params;
      break;
      case kFile_Unlock_Name:
        if (message.expectsResponse())
          paramsClass = File_Unlock_Params;
      break;
      case kFile_AsHandle_Name:
        if (message.expectsResponse())
          paramsClass = File_AsHandle_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateFileResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kFile_Close_Name:
        if (message.isResponse())
          paramsClass = File_Close_ResponseParams;
        break;
      case kFile_Read_Name:
        if (message.isResponse())
          paramsClass = File_Read_ResponseParams;
        break;
      case kFile_Write_Name:
        if (message.isResponse())
          paramsClass = File_Write_ResponseParams;
        break;
      case kFile_Tell_Name:
        if (message.isResponse())
          paramsClass = File_Tell_ResponseParams;
        break;
      case kFile_Seek_Name:
        if (message.isResponse())
          paramsClass = File_Seek_ResponseParams;
        break;
      case kFile_Stat_Name:
        if (message.isResponse())
          paramsClass = File_Stat_ResponseParams;
        break;
      case kFile_Truncate_Name:
        if (message.isResponse())
          paramsClass = File_Truncate_ResponseParams;
        break;
      case kFile_Touch_Name:
        if (message.isResponse())
          paramsClass = File_Touch_ResponseParams;
        break;
      case kFile_Dup_Name:
        if (message.isResponse())
          paramsClass = File_Dup_ResponseParams;
        break;
      case kFile_Flush_Name:
        if (message.isResponse())
          paramsClass = File_Flush_ResponseParams;
        break;
      case kFile_Lock_Name:
        if (message.isResponse())
          paramsClass = File_Lock_ResponseParams;
        break;
      case kFile_Unlock_Name:
        if (message.isResponse())
          paramsClass = File_Unlock_ResponseParams;
        break;
      case kFile_AsHandle_Name:
        if (message.isResponse())
          paramsClass = File_AsHandle_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var File = {
    name: 'filesystem::mojom::File',
    ptrClass: FilePtr,
    proxyClass: FileProxy,
    stubClass: FileStub,
    validateRequest: validateFileRequest,
    validateResponse: validateFileResponse,
  };
  FileStub.prototype.validator = validateFileRequest;
  FileProxy.prototype.validator = validateFileResponse;

  var exports = {};
  exports.File = File;
  exports.FilePtr = FilePtr;

  return exports;
});
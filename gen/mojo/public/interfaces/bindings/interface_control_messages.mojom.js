// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("mojo/public/interfaces/bindings/interface_control_messages.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var kRunMessageId = 0xFFFFFFFF;
  var kRunOrClosePipeMessageId = 0xFFFFFFFE;

  function RunMessageParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RunMessageParams.prototype.initDefaults_ = function() {
    this.input = null;
  };
  RunMessageParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RunMessageParams.validate = function(messageValidator, offset) {
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


    // validate RunMessageParams.input
    err = messageValidator.validateUnion(offset + codec.kStructHeaderSize + 0, RunInput, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RunMessageParams.encodedSize = codec.kStructHeaderSize + 16;

  RunMessageParams.decode = function(decoder) {
    var packed;
    var val = new RunMessageParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.input = decoder.decodeStruct(RunInput);
    return val;
  };

  RunMessageParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RunMessageParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(RunInput, val.input);
  };
  function RunResponseMessageParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RunResponseMessageParams.prototype.initDefaults_ = function() {
    this.output = null;
  };
  RunResponseMessageParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RunResponseMessageParams.validate = function(messageValidator, offset) {
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


    // validate RunResponseMessageParams.output
    err = messageValidator.validateUnion(offset + codec.kStructHeaderSize + 0, RunOutput, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RunResponseMessageParams.encodedSize = codec.kStructHeaderSize + 16;

  RunResponseMessageParams.decode = function(decoder) {
    var packed;
    var val = new RunResponseMessageParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.output = decoder.decodeStruct(RunOutput);
    return val;
  };

  RunResponseMessageParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RunResponseMessageParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(RunOutput, val.output);
  };
  function QueryVersion(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  QueryVersion.prototype.initDefaults_ = function() {
  };
  QueryVersion.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  QueryVersion.validate = function(messageValidator, offset) {
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

  QueryVersion.encodedSize = codec.kStructHeaderSize + 0;

  QueryVersion.decode = function(decoder) {
    var packed;
    var val = new QueryVersion();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  QueryVersion.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(QueryVersion.encodedSize);
    encoder.writeUint32(0);
  };
  function QueryVersionResult(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  QueryVersionResult.prototype.initDefaults_ = function() {
    this.version = 0;
  };
  QueryVersionResult.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  QueryVersionResult.validate = function(messageValidator, offset) {
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

  QueryVersionResult.encodedSize = codec.kStructHeaderSize + 8;

  QueryVersionResult.decode = function(decoder) {
    var packed;
    var val = new QueryVersionResult();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.version = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  QueryVersionResult.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(QueryVersionResult.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.version);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FlushForTesting(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FlushForTesting.prototype.initDefaults_ = function() {
  };
  FlushForTesting.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FlushForTesting.validate = function(messageValidator, offset) {
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

  FlushForTesting.encodedSize = codec.kStructHeaderSize + 0;

  FlushForTesting.decode = function(decoder) {
    var packed;
    var val = new FlushForTesting();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  FlushForTesting.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FlushForTesting.encodedSize);
    encoder.writeUint32(0);
  };
  function RunOrClosePipeMessageParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RunOrClosePipeMessageParams.prototype.initDefaults_ = function() {
    this.input = null;
  };
  RunOrClosePipeMessageParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RunOrClosePipeMessageParams.validate = function(messageValidator, offset) {
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


    // validate RunOrClosePipeMessageParams.input
    err = messageValidator.validateUnion(offset + codec.kStructHeaderSize + 0, RunOrClosePipeInput, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RunOrClosePipeMessageParams.encodedSize = codec.kStructHeaderSize + 16;

  RunOrClosePipeMessageParams.decode = function(decoder) {
    var packed;
    var val = new RunOrClosePipeMessageParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.input = decoder.decodeStruct(RunOrClosePipeInput);
    return val;
  };

  RunOrClosePipeMessageParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RunOrClosePipeMessageParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(RunOrClosePipeInput, val.input);
  };
  function RequireVersion(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RequireVersion.prototype.initDefaults_ = function() {
    this.version = 0;
  };
  RequireVersion.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RequireVersion.validate = function(messageValidator, offset) {
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

  RequireVersion.encodedSize = codec.kStructHeaderSize + 8;

  RequireVersion.decode = function(decoder) {
    var packed;
    var val = new RequireVersion();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.version = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  RequireVersion.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RequireVersion.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.version);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function SendDisconnectReason(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  SendDisconnectReason.prototype.initDefaults_ = function() {
    this.custom_reason = 0;
    this.description = null;
  };
  SendDisconnectReason.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  SendDisconnectReason.validate = function(messageValidator, offset) {
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



    
    // validate SendDisconnectReason.description
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  SendDisconnectReason.encodedSize = codec.kStructHeaderSize + 16;

  SendDisconnectReason.decode = function(decoder) {
    var packed;
    var val = new SendDisconnectReason();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.custom_reason = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.description = decoder.decodeStruct(codec.String);
    return val;
  };

  SendDisconnectReason.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(SendDisconnectReason.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.custom_reason);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.description);
  };

  function RunInput(value) {
    this.initDefault_();
    this.initValue_(value);
  }
  
  
  RunInput.Tags = {
    query_version: 0,
    flush_for_testing: 1,
  };
  
  RunInput.prototype.initDefault_ = function() {
    this.$data = null;
    this.$tag = undefined;
  }
  
  RunInput.prototype.initValue_ = function(value) {
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
        "query_version",
        "flush_for_testing",
    ];
  
    if (fields.indexOf(keys[0]) < 0) {
      throw new ReferenceError(keys[0] + " is not a RunInput member.");
  
    }
  
    this[keys[0]] = value[keys[0]];
  }
  Object.defineProperty(RunInput.prototype, "query_version", {
    get: function() {
      if (this.$tag != RunInput.Tags.query_version) {
        throw new ReferenceError(
            "RunInput.query_version is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = RunInput.Tags.query_version;
      this.$data = value;
    }
  });
  Object.defineProperty(RunInput.prototype, "flush_for_testing", {
    get: function() {
      if (this.$tag != RunInput.Tags.flush_for_testing) {
        throw new ReferenceError(
            "RunInput.flush_for_testing is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = RunInput.Tags.flush_for_testing;
      this.$data = value;
    }
  });
  
  
    RunInput.encode = function(encoder, val) {
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
        case RunInput.Tags.query_version:
          encoder.encodeStructPointer(QueryVersion, val.query_version);
          break;
        case RunInput.Tags.flush_for_testing:
          encoder.encodeStructPointer(FlushForTesting, val.flush_for_testing);
          break;
      }
      encoder.align();
    };
  
  
    RunInput.decode = function(decoder) {
      var size = decoder.readUint32();
      if (size == 0) {
        decoder.readUint32();
        decoder.readUint64();
        return null;
      }
    
      var result = new RunInput();
      var tag = decoder.readUint32();
      switch (tag) {
        case RunInput.Tags.query_version:
          result.query_version = decoder.decodeStructPointer(QueryVersion);
          break;
        case RunInput.Tags.flush_for_testing:
          result.flush_for_testing = decoder.decodeStructPointer(FlushForTesting);
          break;
      }
      decoder.align();
    
      return result;
    };
  
  
    RunInput.validate = function(messageValidator, offset) {
      var size = messageValidator.decodeUnionSize(offset);
      if (size != 16) {
        return validator.validationError.INVALID_UNION_SIZE;
      }
    
      var tag = messageValidator.decodeUnionTag(offset);
      var data_offset = offset + 8;
      var err;
      switch (tag) {
        case RunInput.Tags.query_version:
          
    
    // validate RunInput.query_version
    err = messageValidator.validateStructPointer(data_offset, QueryVersion, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case RunInput.Tags.flush_for_testing:
          
    
    // validate RunInput.flush_for_testing
    err = messageValidator.validateStructPointer(data_offset, FlushForTesting, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
      }
    
      return validator.validationError.NONE;
    };
  
  RunInput.encodedSize = 16;

  function RunOutput(value) {
    this.initDefault_();
    this.initValue_(value);
  }
  
  
  RunOutput.Tags = {
    query_version_result: 0,
  };
  
  RunOutput.prototype.initDefault_ = function() {
    this.$data = null;
    this.$tag = undefined;
  }
  
  RunOutput.prototype.initValue_ = function(value) {
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
        "query_version_result",
    ];
  
    if (fields.indexOf(keys[0]) < 0) {
      throw new ReferenceError(keys[0] + " is not a RunOutput member.");
  
    }
  
    this[keys[0]] = value[keys[0]];
  }
  Object.defineProperty(RunOutput.prototype, "query_version_result", {
    get: function() {
      if (this.$tag != RunOutput.Tags.query_version_result) {
        throw new ReferenceError(
            "RunOutput.query_version_result is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = RunOutput.Tags.query_version_result;
      this.$data = value;
    }
  });
  
  
    RunOutput.encode = function(encoder, val) {
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
        case RunOutput.Tags.query_version_result:
          encoder.encodeStructPointer(QueryVersionResult, val.query_version_result);
          break;
      }
      encoder.align();
    };
  
  
    RunOutput.decode = function(decoder) {
      var size = decoder.readUint32();
      if (size == 0) {
        decoder.readUint32();
        decoder.readUint64();
        return null;
      }
    
      var result = new RunOutput();
      var tag = decoder.readUint32();
      switch (tag) {
        case RunOutput.Tags.query_version_result:
          result.query_version_result = decoder.decodeStructPointer(QueryVersionResult);
          break;
      }
      decoder.align();
    
      return result;
    };
  
  
    RunOutput.validate = function(messageValidator, offset) {
      var size = messageValidator.decodeUnionSize(offset);
      if (size != 16) {
        return validator.validationError.INVALID_UNION_SIZE;
      }
    
      var tag = messageValidator.decodeUnionTag(offset);
      var data_offset = offset + 8;
      var err;
      switch (tag) {
        case RunOutput.Tags.query_version_result:
          
    
    // validate RunOutput.query_version_result
    err = messageValidator.validateStructPointer(data_offset, QueryVersionResult, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
      }
    
      return validator.validationError.NONE;
    };
  
  RunOutput.encodedSize = 16;

  function RunOrClosePipeInput(value) {
    this.initDefault_();
    this.initValue_(value);
  }
  
  
  RunOrClosePipeInput.Tags = {
    require_version: 0,
    send_disconnect_reason: 1,
  };
  
  RunOrClosePipeInput.prototype.initDefault_ = function() {
    this.$data = null;
    this.$tag = undefined;
  }
  
  RunOrClosePipeInput.prototype.initValue_ = function(value) {
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
        "require_version",
        "send_disconnect_reason",
    ];
  
    if (fields.indexOf(keys[0]) < 0) {
      throw new ReferenceError(keys[0] + " is not a RunOrClosePipeInput member.");
  
    }
  
    this[keys[0]] = value[keys[0]];
  }
  Object.defineProperty(RunOrClosePipeInput.prototype, "require_version", {
    get: function() {
      if (this.$tag != RunOrClosePipeInput.Tags.require_version) {
        throw new ReferenceError(
            "RunOrClosePipeInput.require_version is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = RunOrClosePipeInput.Tags.require_version;
      this.$data = value;
    }
  });
  Object.defineProperty(RunOrClosePipeInput.prototype, "send_disconnect_reason", {
    get: function() {
      if (this.$tag != RunOrClosePipeInput.Tags.send_disconnect_reason) {
        throw new ReferenceError(
            "RunOrClosePipeInput.send_disconnect_reason is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = RunOrClosePipeInput.Tags.send_disconnect_reason;
      this.$data = value;
    }
  });
  
  
    RunOrClosePipeInput.encode = function(encoder, val) {
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
        case RunOrClosePipeInput.Tags.require_version:
          encoder.encodeStructPointer(RequireVersion, val.require_version);
          break;
        case RunOrClosePipeInput.Tags.send_disconnect_reason:
          encoder.encodeStructPointer(SendDisconnectReason, val.send_disconnect_reason);
          break;
      }
      encoder.align();
    };
  
  
    RunOrClosePipeInput.decode = function(decoder) {
      var size = decoder.readUint32();
      if (size == 0) {
        decoder.readUint32();
        decoder.readUint64();
        return null;
      }
    
      var result = new RunOrClosePipeInput();
      var tag = decoder.readUint32();
      switch (tag) {
        case RunOrClosePipeInput.Tags.require_version:
          result.require_version = decoder.decodeStructPointer(RequireVersion);
          break;
        case RunOrClosePipeInput.Tags.send_disconnect_reason:
          result.send_disconnect_reason = decoder.decodeStructPointer(SendDisconnectReason);
          break;
      }
      decoder.align();
    
      return result;
    };
  
  
    RunOrClosePipeInput.validate = function(messageValidator, offset) {
      var size = messageValidator.decodeUnionSize(offset);
      if (size != 16) {
        return validator.validationError.INVALID_UNION_SIZE;
      }
    
      var tag = messageValidator.decodeUnionTag(offset);
      var data_offset = offset + 8;
      var err;
      switch (tag) {
        case RunOrClosePipeInput.Tags.require_version:
          
    
    // validate RunOrClosePipeInput.require_version
    err = messageValidator.validateStructPointer(data_offset, RequireVersion, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case RunOrClosePipeInput.Tags.send_disconnect_reason:
          
    
    // validate RunOrClosePipeInput.send_disconnect_reason
    err = messageValidator.validateStructPointer(data_offset, SendDisconnectReason, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
      }
    
      return validator.validationError.NONE;
    };
  
  RunOrClosePipeInput.encodedSize = 16;

  var exports = {};
  exports.kRunMessageId = kRunMessageId;
  exports.kRunOrClosePipeMessageId = kRunOrClosePipeMessageId;
  exports.RunMessageParams = RunMessageParams;
  exports.RunResponseMessageParams = RunResponseMessageParams;
  exports.QueryVersion = QueryVersion;
  exports.QueryVersionResult = QueryVersionResult;
  exports.FlushForTesting = FlushForTesting;
  exports.RunOrClosePipeMessageParams = RunOrClosePipeMessageParams;
  exports.RequireVersion = RequireVersion;
  exports.SendDisconnectReason = SendDisconnectReason;
  exports.RunInput = RunInput;
  exports.RunOutput = RunOutput;
  exports.RunOrClosePipeInput = RunOrClosePipeInput;

  return exports;
});
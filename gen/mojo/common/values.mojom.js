// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("mojo/common/values.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function ListValue(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ListValue.prototype.initDefaults_ = function() {
    this.values = null;
  };
  ListValue.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ListValue.validate = function(messageValidator, offset) {
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


    
    // validate ListValue.values
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 16, Value, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ListValue.encodedSize = codec.kStructHeaderSize + 8;

  ListValue.decode = function(decoder) {
    var packed;
    var val = new ListValue();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.values = decoder.decodeArrayPointer(Value);
    return val;
  };

  ListValue.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ListValue.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(Value, val.values);
  };
  function DictionaryValue(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DictionaryValue.prototype.initDefaults_ = function() {
    this.values = null;
  };
  DictionaryValue.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DictionaryValue.validate = function(messageValidator, offset) {
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


    
    // validate DictionaryValue.values
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 0, false, codec.String, Value, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DictionaryValue.encodedSize = codec.kStructHeaderSize + 8;

  DictionaryValue.decode = function(decoder) {
    var packed;
    var val = new DictionaryValue();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.values = decoder.decodeMapPointer(codec.String, Value);
    return val;
  };

  DictionaryValue.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DictionaryValue.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeMapPointer(codec.String, Value, val.values);
  };
  function NullValue(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NullValue.prototype.initDefaults_ = function() {
  };
  NullValue.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NullValue.validate = function(messageValidator, offset) {
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

  NullValue.encodedSize = codec.kStructHeaderSize + 0;

  NullValue.decode = function(decoder) {
    var packed;
    var val = new NullValue();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  NullValue.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NullValue.encodedSize);
    encoder.writeUint32(0);
  };
  function LegacyListValue(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LegacyListValue.prototype.initDefaults_ = function() {
  };
  LegacyListValue.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LegacyListValue.validate = function(messageValidator, offset) {
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

  LegacyListValue.encodedSize = codec.kStructHeaderSize + 0;

  LegacyListValue.decode = function(decoder) {
    var packed;
    var val = new LegacyListValue();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  LegacyListValue.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LegacyListValue.encodedSize);
    encoder.writeUint32(0);
  };

  function Value(value) {
    this.initDefault_();
    this.initValue_(value);
  }
  
  
  Value.Tags = {
    null_value: 0,
    bool_value: 1,
    int_value: 2,
    double_value: 3,
    string_value: 4,
    binary_value: 5,
    dictionary_value: 6,
    list_value: 7,
  };
  
  Value.prototype.initDefault_ = function() {
    this.$data = null;
    this.$tag = undefined;
  }
  
  Value.prototype.initValue_ = function(value) {
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
        "null_value",
        "bool_value",
        "int_value",
        "double_value",
        "string_value",
        "binary_value",
        "dictionary_value",
        "list_value",
    ];
  
    if (fields.indexOf(keys[0]) < 0) {
      throw new ReferenceError(keys[0] + " is not a Value member.");
  
    }
  
    this[keys[0]] = value[keys[0]];
  }
  Object.defineProperty(Value.prototype, "null_value", {
    get: function() {
      if (this.$tag != Value.Tags.null_value) {
        throw new ReferenceError(
            "Value.null_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.null_value;
      this.$data = value;
    }
  });
  Object.defineProperty(Value.prototype, "bool_value", {
    get: function() {
      if (this.$tag != Value.Tags.bool_value) {
        throw new ReferenceError(
            "Value.bool_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.bool_value;
      this.$data = value;
    }
  });
  Object.defineProperty(Value.prototype, "int_value", {
    get: function() {
      if (this.$tag != Value.Tags.int_value) {
        throw new ReferenceError(
            "Value.int_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.int_value;
      this.$data = value;
    }
  });
  Object.defineProperty(Value.prototype, "double_value", {
    get: function() {
      if (this.$tag != Value.Tags.double_value) {
        throw new ReferenceError(
            "Value.double_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.double_value;
      this.$data = value;
    }
  });
  Object.defineProperty(Value.prototype, "string_value", {
    get: function() {
      if (this.$tag != Value.Tags.string_value) {
        throw new ReferenceError(
            "Value.string_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.string_value;
      this.$data = value;
    }
  });
  Object.defineProperty(Value.prototype, "binary_value", {
    get: function() {
      if (this.$tag != Value.Tags.binary_value) {
        throw new ReferenceError(
            "Value.binary_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.binary_value;
      this.$data = value;
    }
  });
  Object.defineProperty(Value.prototype, "dictionary_value", {
    get: function() {
      if (this.$tag != Value.Tags.dictionary_value) {
        throw new ReferenceError(
            "Value.dictionary_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.dictionary_value;
      this.$data = value;
    }
  });
  Object.defineProperty(Value.prototype, "list_value", {
    get: function() {
      if (this.$tag != Value.Tags.list_value) {
        throw new ReferenceError(
            "Value.list_value is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = Value.Tags.list_value;
      this.$data = value;
    }
  });
  
  
    Value.encode = function(encoder, val) {
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
        case Value.Tags.null_value:
          encoder.encodeStructPointer(NullValue, val.null_value);
          break;
        case Value.Tags.bool_value:
          encoder.writeUint8(val.bool_value ? 1 : 0);
          break;
        case Value.Tags.int_value:
          encoder.encodeStruct(codec.Int32, val.int_value);
          break;
        case Value.Tags.double_value:
          encoder.encodeStruct(codec.Double, val.double_value);
          break;
        case Value.Tags.string_value:
          encoder.encodeStruct(codec.String, val.string_value);
          break;
        case Value.Tags.binary_value:
          encoder.encodeArrayPointer(codec.Uint8, val.binary_value);
          break;
        case Value.Tags.dictionary_value:
          encoder.encodeStructPointer(DictionaryValue, val.dictionary_value);
          break;
        case Value.Tags.list_value:
          encoder.encodeStructPointer(ListValue, val.list_value);
          break;
      }
      encoder.align();
    };
  
  
    Value.decode = function(decoder) {
      var size = decoder.readUint32();
      if (size == 0) {
        decoder.readUint32();
        decoder.readUint64();
        return null;
      }
    
      var result = new Value();
      var tag = decoder.readUint32();
      switch (tag) {
        case Value.Tags.null_value:
          result.null_value = decoder.decodeStructPointer(NullValue);
          break;
        case Value.Tags.bool_value:
          result.bool_value = decoder.readUint8() ? true : false;
          break;
        case Value.Tags.int_value:
          result.int_value = decoder.decodeStruct(codec.Int32);
          break;
        case Value.Tags.double_value:
          result.double_value = decoder.decodeStruct(codec.Double);
          break;
        case Value.Tags.string_value:
          result.string_value = decoder.decodeStruct(codec.String);
          break;
        case Value.Tags.binary_value:
          result.binary_value = decoder.decodeArrayPointer(codec.Uint8);
          break;
        case Value.Tags.dictionary_value:
          result.dictionary_value = decoder.decodeStructPointer(DictionaryValue);
          break;
        case Value.Tags.list_value:
          result.list_value = decoder.decodeStructPointer(ListValue);
          break;
      }
      decoder.align();
    
      return result;
    };
  
  
    Value.validate = function(messageValidator, offset) {
      var size = messageValidator.decodeUnionSize(offset);
      if (size != 16) {
        return validator.validationError.INVALID_UNION_SIZE;
      }
    
      var tag = messageValidator.decodeUnionTag(offset);
      var data_offset = offset + 8;
      var err;
      switch (tag) {
        case Value.Tags.null_value:
          
    
    // validate Value.null_value
    err = messageValidator.validateStructPointer(data_offset, NullValue, true);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case Value.Tags.bool_value:
          
    
          break;
        case Value.Tags.int_value:
          
    
          break;
        case Value.Tags.double_value:
          
    
          break;
        case Value.Tags.string_value:
          
    
    // validate Value.string_value
    err = messageValidator.validateStringPointer(data_offset, false)
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case Value.Tags.binary_value:
          
    
    // validate Value.binary_value
    err = messageValidator.validateArrayPointer(data_offset, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case Value.Tags.dictionary_value:
          
    
    // validate Value.dictionary_value
    err = messageValidator.validateStructPointer(data_offset, DictionaryValue, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case Value.Tags.list_value:
          
    
    // validate Value.list_value
    err = messageValidator.validateStructPointer(data_offset, ListValue, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
      }
    
      return validator.validationError.NONE;
    };
  
  Value.encodedSize = 16;

  var exports = {};
  exports.ListValue = ListValue;
  exports.DictionaryValue = DictionaryValue;
  exports.NullValue = NullValue;
  exports.LegacyListValue = LegacyListValue;
  exports.Value = Value;

  return exports;
});
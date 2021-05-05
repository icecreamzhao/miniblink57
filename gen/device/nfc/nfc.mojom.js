// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/nfc/nfc.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var NFCErrorType = {};
  NFCErrorType.SECURITY = 0;
  NFCErrorType.NOT_SUPPORTED = NFCErrorType.SECURITY + 1;
  NFCErrorType.DEVICE_DISABLED = NFCErrorType.NOT_SUPPORTED + 1;
  NFCErrorType.NOT_FOUND = NFCErrorType.DEVICE_DISABLED + 1;
  NFCErrorType.INVALID_MESSAGE = NFCErrorType.NOT_FOUND + 1;
  NFCErrorType.OPERATION_CANCELLED = NFCErrorType.INVALID_MESSAGE + 1;
  NFCErrorType.TIMER_EXPIRED = NFCErrorType.OPERATION_CANCELLED + 1;
  NFCErrorType.CANNOT_CANCEL = NFCErrorType.TIMER_EXPIRED + 1;
  NFCErrorType.IO_ERROR = NFCErrorType.CANNOT_CANCEL + 1;

  NFCErrorType.isKnownEnumValue = function(value) {
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

  NFCErrorType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var NFCRecordType = {};
  NFCRecordType.EMPTY = 0;
  NFCRecordType.TEXT = NFCRecordType.EMPTY + 1;
  NFCRecordType.URL = NFCRecordType.TEXT + 1;
  NFCRecordType.JSON = NFCRecordType.URL + 1;
  NFCRecordType.OPAQUE_RECORD = NFCRecordType.JSON + 1;

  NFCRecordType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    }
    return false;
  };

  NFCRecordType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var NFCPushTarget = {};
  NFCPushTarget.TAG = 0;
  NFCPushTarget.PEER = NFCPushTarget.TAG + 1;
  NFCPushTarget.ANY = NFCPushTarget.PEER + 1;

  NFCPushTarget.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  NFCPushTarget.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var NFCWatchMode = {};
  NFCWatchMode.WEBNFC_ONLY = 0;
  NFCWatchMode.ANY = NFCWatchMode.WEBNFC_ONLY + 1;

  NFCWatchMode.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  NFCWatchMode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function NFCError(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFCError.prototype.initDefaults_ = function() {
    this.error_type = 0;
  };
  NFCError.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFCError.validate = function(messageValidator, offset) {
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


    
    // validate NFCError.error_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, NFCErrorType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFCError.encodedSize = codec.kStructHeaderSize + 8;

  NFCError.decode = function(decoder) {
    var packed;
    var val = new NFCError();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  NFCError.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFCError.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function NFCRecord(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFCRecord.prototype.initDefaults_ = function() {
    this.record_type = 0;
    this.media_type = null;
    this.data = null;
  };
  NFCRecord.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFCRecord.validate = function(messageValidator, offset) {
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


    
    // validate NFCRecord.record_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, NFCRecordType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFCRecord.media_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFCRecord.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFCRecord.encodedSize = codec.kStructHeaderSize + 24;

  NFCRecord.decode = function(decoder) {
    var packed;
    var val = new NFCRecord();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.record_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.media_type = decoder.decodeStruct(codec.NullableString);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  NFCRecord.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFCRecord.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.record_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.NullableString, val.media_type);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function NFCMessage(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFCMessage.kMaxSize = 32768;
  NFCMessage.prototype.initDefaults_ = function() {
    this.data = null;
    this.url = null;
  };
  NFCMessage.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFCMessage.validate = function(messageValidator, offset) {
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


    
    // validate NFCMessage.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(NFCRecord), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFCMessage.url
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFCMessage.encodedSize = codec.kStructHeaderSize + 16;

  NFCMessage.decode = function(decoder) {
    var packed;
    var val = new NFCMessage();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.data = decoder.decodeArrayPointer(new codec.PointerTo(NFCRecord));
    val.url = decoder.decodeStruct(codec.NullableString);
    return val;
  };

  NFCMessage.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFCMessage.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(NFCRecord), val.data);
    encoder.encodeStruct(codec.NullableString, val.url);
  };
  function NFCPushOptions(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFCPushOptions.prototype.initDefaults_ = function() {
    this.target = 0;
    this.ignore_read = false;
    this.timeout = 0;
  };
  NFCPushOptions.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFCPushOptions.validate = function(messageValidator, offset) {
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


    
    // validate NFCPushOptions.target
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, NFCPushTarget);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  NFCPushOptions.encodedSize = codec.kStructHeaderSize + 16;

  NFCPushOptions.decode = function(decoder) {
    var packed;
    var val = new NFCPushOptions();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.target = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.ignore_read = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.timeout = decoder.decodeStruct(codec.Double);
    return val;
  };

  NFCPushOptions.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFCPushOptions.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.target);
    packed = 0;
    packed |= (val.ignore_read & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Double, val.timeout);
  };
  function NFCRecordTypeFilter(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFCRecordTypeFilter.prototype.initDefaults_ = function() {
    this.record_type = 0;
  };
  NFCRecordTypeFilter.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFCRecordTypeFilter.validate = function(messageValidator, offset) {
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


    
    // validate NFCRecordTypeFilter.record_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, NFCRecordType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFCRecordTypeFilter.encodedSize = codec.kStructHeaderSize + 8;

  NFCRecordTypeFilter.decode = function(decoder) {
    var packed;
    var val = new NFCRecordTypeFilter();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.record_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  NFCRecordTypeFilter.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFCRecordTypeFilter.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.record_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function NFCWatchOptions(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFCWatchOptions.prototype.initDefaults_ = function() {
    this.url = null;
    this.record_filter = null;
    this.media_type = null;
    this.mode = 0;
  };
  NFCWatchOptions.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFCWatchOptions.validate = function(messageValidator, offset) {
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


    
    // validate NFCWatchOptions.url
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFCWatchOptions.record_filter
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, NFCRecordTypeFilter, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFCWatchOptions.media_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFCWatchOptions.mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 24, NFCWatchMode);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFCWatchOptions.encodedSize = codec.kStructHeaderSize + 32;

  NFCWatchOptions.decode = function(decoder) {
    var packed;
    var val = new NFCWatchOptions();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStruct(codec.NullableString);
    val.record_filter = decoder.decodeStructPointer(NFCRecordTypeFilter);
    val.media_type = decoder.decodeStruct(codec.NullableString);
    val.mode = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  NFCWatchOptions.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFCWatchOptions.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.NullableString, val.url);
    encoder.encodeStructPointer(NFCRecordTypeFilter, val.record_filter);
    encoder.encodeStruct(codec.NullableString, val.media_type);
    encoder.encodeStruct(codec.Int32, val.mode);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function NFC_SetClient_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_SetClient_Params.prototype.initDefaults_ = function() {
    this.client = new NFCClientPtr();
  };
  NFC_SetClient_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_SetClient_Params.validate = function(messageValidator, offset) {
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


    
    // validate NFC_SetClient_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_SetClient_Params.encodedSize = codec.kStructHeaderSize + 8;

  NFC_SetClient_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_SetClient_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(new codec.Interface(NFCClientPtr));
    return val;
  };

  NFC_SetClient_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_SetClient_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(NFCClientPtr), val.client);
  };
  function NFC_Push_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_Push_Params.prototype.initDefaults_ = function() {
    this.message = null;
    this.options = null;
  };
  NFC_Push_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_Push_Params.validate = function(messageValidator, offset) {
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


    
    // validate NFC_Push_Params.message
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, NFCMessage, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFC_Push_Params.options
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, NFCPushOptions, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_Push_Params.encodedSize = codec.kStructHeaderSize + 16;

  NFC_Push_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_Push_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.message = decoder.decodeStructPointer(NFCMessage);
    val.options = decoder.decodeStructPointer(NFCPushOptions);
    return val;
  };

  NFC_Push_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_Push_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(NFCMessage, val.message);
    encoder.encodeStructPointer(NFCPushOptions, val.options);
  };
  function NFC_Push_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_Push_ResponseParams.prototype.initDefaults_ = function() {
    this.error = null;
  };
  NFC_Push_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_Push_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate NFC_Push_ResponseParams.error
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, NFCError, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_Push_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  NFC_Push_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new NFC_Push_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStructPointer(NFCError);
    return val;
  };

  NFC_Push_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_Push_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(NFCError, val.error);
  };
  function NFC_CancelPush_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_CancelPush_Params.prototype.initDefaults_ = function() {
    this.target = 0;
  };
  NFC_CancelPush_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_CancelPush_Params.validate = function(messageValidator, offset) {
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


    
    // validate NFC_CancelPush_Params.target
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, NFCPushTarget);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_CancelPush_Params.encodedSize = codec.kStructHeaderSize + 8;

  NFC_CancelPush_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_CancelPush_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.target = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  NFC_CancelPush_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_CancelPush_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.target);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function NFC_CancelPush_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_CancelPush_ResponseParams.prototype.initDefaults_ = function() {
    this.error = null;
  };
  NFC_CancelPush_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_CancelPush_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate NFC_CancelPush_ResponseParams.error
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, NFCError, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_CancelPush_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  NFC_CancelPush_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new NFC_CancelPush_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStructPointer(NFCError);
    return val;
  };

  NFC_CancelPush_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_CancelPush_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(NFCError, val.error);
  };
  function NFC_Watch_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_Watch_Params.prototype.initDefaults_ = function() {
    this.options = null;
  };
  NFC_Watch_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_Watch_Params.validate = function(messageValidator, offset) {
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


    
    // validate NFC_Watch_Params.options
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, NFCWatchOptions, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_Watch_Params.encodedSize = codec.kStructHeaderSize + 8;

  NFC_Watch_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_Watch_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.options = decoder.decodeStructPointer(NFCWatchOptions);
    return val;
  };

  NFC_Watch_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_Watch_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(NFCWatchOptions, val.options);
  };
  function NFC_Watch_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_Watch_ResponseParams.prototype.initDefaults_ = function() {
    this.id = 0;
    this.error = null;
  };
  NFC_Watch_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_Watch_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate NFC_Watch_ResponseParams.error
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, NFCError, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_Watch_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  NFC_Watch_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new NFC_Watch_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.error = decoder.decodeStructPointer(NFCError);
    return val;
  };

  NFC_Watch_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_Watch_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(NFCError, val.error);
  };
  function NFC_CancelWatch_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_CancelWatch_Params.prototype.initDefaults_ = function() {
    this.id = 0;
  };
  NFC_CancelWatch_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_CancelWatch_Params.validate = function(messageValidator, offset) {
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

  NFC_CancelWatch_Params.encodedSize = codec.kStructHeaderSize + 8;

  NFC_CancelWatch_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_CancelWatch_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  NFC_CancelWatch_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_CancelWatch_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function NFC_CancelWatch_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_CancelWatch_ResponseParams.prototype.initDefaults_ = function() {
    this.error = null;
  };
  NFC_CancelWatch_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_CancelWatch_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate NFC_CancelWatch_ResponseParams.error
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, NFCError, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_CancelWatch_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  NFC_CancelWatch_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new NFC_CancelWatch_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStructPointer(NFCError);
    return val;
  };

  NFC_CancelWatch_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_CancelWatch_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(NFCError, val.error);
  };
  function NFC_CancelAllWatches_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_CancelAllWatches_Params.prototype.initDefaults_ = function() {
  };
  NFC_CancelAllWatches_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_CancelAllWatches_Params.validate = function(messageValidator, offset) {
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

  NFC_CancelAllWatches_Params.encodedSize = codec.kStructHeaderSize + 0;

  NFC_CancelAllWatches_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_CancelAllWatches_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  NFC_CancelAllWatches_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_CancelAllWatches_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function NFC_CancelAllWatches_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_CancelAllWatches_ResponseParams.prototype.initDefaults_ = function() {
    this.error = null;
  };
  NFC_CancelAllWatches_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_CancelAllWatches_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate NFC_CancelAllWatches_ResponseParams.error
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, NFCError, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFC_CancelAllWatches_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  NFC_CancelAllWatches_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new NFC_CancelAllWatches_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStructPointer(NFCError);
    return val;
  };

  NFC_CancelAllWatches_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_CancelAllWatches_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(NFCError, val.error);
  };
  function NFC_SuspendNFCOperations_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_SuspendNFCOperations_Params.prototype.initDefaults_ = function() {
  };
  NFC_SuspendNFCOperations_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_SuspendNFCOperations_Params.validate = function(messageValidator, offset) {
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

  NFC_SuspendNFCOperations_Params.encodedSize = codec.kStructHeaderSize + 0;

  NFC_SuspendNFCOperations_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_SuspendNFCOperations_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  NFC_SuspendNFCOperations_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_SuspendNFCOperations_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function NFC_ResumeNFCOperations_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFC_ResumeNFCOperations_Params.prototype.initDefaults_ = function() {
  };
  NFC_ResumeNFCOperations_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFC_ResumeNFCOperations_Params.validate = function(messageValidator, offset) {
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

  NFC_ResumeNFCOperations_Params.encodedSize = codec.kStructHeaderSize + 0;

  NFC_ResumeNFCOperations_Params.decode = function(decoder) {
    var packed;
    var val = new NFC_ResumeNFCOperations_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  NFC_ResumeNFCOperations_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFC_ResumeNFCOperations_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function NFCClient_OnWatch_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NFCClient_OnWatch_Params.prototype.initDefaults_ = function() {
    this.watch_ids = null;
    this.message = null;
  };
  NFCClient_OnWatch_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NFCClient_OnWatch_Params.validate = function(messageValidator, offset) {
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


    
    // validate NFCClient_OnWatch_Params.watch_ids
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 4, codec.Uint32, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NFCClient_OnWatch_Params.message
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, NFCMessage, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NFCClient_OnWatch_Params.encodedSize = codec.kStructHeaderSize + 16;

  NFCClient_OnWatch_Params.decode = function(decoder) {
    var packed;
    var val = new NFCClient_OnWatch_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.watch_ids = decoder.decodeArrayPointer(codec.Uint32);
    val.message = decoder.decodeStructPointer(NFCMessage);
    return val;
  };

  NFCClient_OnWatch_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NFCClient_OnWatch_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint32, val.watch_ids);
    encoder.encodeStructPointer(NFCMessage, val.message);
  };
  var kNFC_SetClient_Name = 0;
  var kNFC_Push_Name = 1;
  var kNFC_CancelPush_Name = 2;
  var kNFC_Watch_Name = 3;
  var kNFC_CancelWatch_Name = 4;
  var kNFC_CancelAllWatches_Name = 5;
  var kNFC_SuspendNFCOperations_Name = 6;
  var kNFC_ResumeNFCOperations_Name = 7;

  function NFCPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(NFC,
                                                   handleOrPtrInfo);
  }

  function NFCProxy(receiver) {
    this.receiver_ = receiver;
  }
  NFCPtr.prototype.setClient = function() {
    return NFCProxy.prototype.setClient
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.setClient = function(client) {
    var params = new NFC_SetClient_Params();
    params.client = client;
    var builder = new codec.MessageBuilder(
        kNFC_SetClient_Name,
        codec.align(NFC_SetClient_Params.encodedSize));
    builder.encodeStruct(NFC_SetClient_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  NFCPtr.prototype.push = function() {
    return NFCProxy.prototype.push
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.push = function(message, options) {
    var params = new NFC_Push_Params();
    params.message = message;
    params.options = options;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kNFC_Push_Name,
          codec.align(NFC_Push_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(NFC_Push_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(NFC_Push_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  NFCPtr.prototype.cancelPush = function() {
    return NFCProxy.prototype.cancelPush
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.cancelPush = function(target) {
    var params = new NFC_CancelPush_Params();
    params.target = target;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kNFC_CancelPush_Name,
          codec.align(NFC_CancelPush_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(NFC_CancelPush_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(NFC_CancelPush_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  NFCPtr.prototype.watch = function() {
    return NFCProxy.prototype.watch
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.watch = function(options) {
    var params = new NFC_Watch_Params();
    params.options = options;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kNFC_Watch_Name,
          codec.align(NFC_Watch_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(NFC_Watch_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(NFC_Watch_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  NFCPtr.prototype.cancelWatch = function() {
    return NFCProxy.prototype.cancelWatch
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.cancelWatch = function(id) {
    var params = new NFC_CancelWatch_Params();
    params.id = id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kNFC_CancelWatch_Name,
          codec.align(NFC_CancelWatch_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(NFC_CancelWatch_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(NFC_CancelWatch_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  NFCPtr.prototype.cancelAllWatches = function() {
    return NFCProxy.prototype.cancelAllWatches
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.cancelAllWatches = function() {
    var params = new NFC_CancelAllWatches_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kNFC_CancelAllWatches_Name,
          codec.align(NFC_CancelAllWatches_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(NFC_CancelAllWatches_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(NFC_CancelAllWatches_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  NFCPtr.prototype.suspendNFCOperations = function() {
    return NFCProxy.prototype.suspendNFCOperations
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.suspendNFCOperations = function() {
    var params = new NFC_SuspendNFCOperations_Params();
    var builder = new codec.MessageBuilder(
        kNFC_SuspendNFCOperations_Name,
        codec.align(NFC_SuspendNFCOperations_Params.encodedSize));
    builder.encodeStruct(NFC_SuspendNFCOperations_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  NFCPtr.prototype.resumeNFCOperations = function() {
    return NFCProxy.prototype.resumeNFCOperations
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCProxy.prototype.resumeNFCOperations = function() {
    var params = new NFC_ResumeNFCOperations_Params();
    var builder = new codec.MessageBuilder(
        kNFC_ResumeNFCOperations_Name,
        codec.align(NFC_ResumeNFCOperations_Params.encodedSize));
    builder.encodeStruct(NFC_ResumeNFCOperations_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function NFCStub(delegate) {
    this.delegate_ = delegate;
  }
  NFCStub.prototype.setClient = function(client) {
    return this.delegate_ && this.delegate_.setClient && this.delegate_.setClient(client);
  }
  NFCStub.prototype.push = function(message, options) {
    return this.delegate_ && this.delegate_.push && this.delegate_.push(message, options);
  }
  NFCStub.prototype.cancelPush = function(target) {
    return this.delegate_ && this.delegate_.cancelPush && this.delegate_.cancelPush(target);
  }
  NFCStub.prototype.watch = function(options) {
    return this.delegate_ && this.delegate_.watch && this.delegate_.watch(options);
  }
  NFCStub.prototype.cancelWatch = function(id) {
    return this.delegate_ && this.delegate_.cancelWatch && this.delegate_.cancelWatch(id);
  }
  NFCStub.prototype.cancelAllWatches = function() {
    return this.delegate_ && this.delegate_.cancelAllWatches && this.delegate_.cancelAllWatches();
  }
  NFCStub.prototype.suspendNFCOperations = function() {
    return this.delegate_ && this.delegate_.suspendNFCOperations && this.delegate_.suspendNFCOperations();
  }
  NFCStub.prototype.resumeNFCOperations = function() {
    return this.delegate_ && this.delegate_.resumeNFCOperations && this.delegate_.resumeNFCOperations();
  }

  NFCStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kNFC_SetClient_Name:
      var params = reader.decodeStruct(NFC_SetClient_Params);
      this.setClient(params.client);
      return true;
    case kNFC_SuspendNFCOperations_Name:
      var params = reader.decodeStruct(NFC_SuspendNFCOperations_Params);
      this.suspendNFCOperations();
      return true;
    case kNFC_ResumeNFCOperations_Name:
      var params = reader.decodeStruct(NFC_ResumeNFCOperations_Params);
      this.resumeNFCOperations();
      return true;
    default:
      return false;
    }
  };

  NFCStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kNFC_Push_Name:
      var params = reader.decodeStruct(NFC_Push_Params);
      return this.push(params.message, params.options).then(function(response) {
        var responseParams =
            new NFC_Push_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kNFC_Push_Name,
            codec.align(NFC_Push_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(NFC_Push_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kNFC_CancelPush_Name:
      var params = reader.decodeStruct(NFC_CancelPush_Params);
      return this.cancelPush(params.target).then(function(response) {
        var responseParams =
            new NFC_CancelPush_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kNFC_CancelPush_Name,
            codec.align(NFC_CancelPush_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(NFC_CancelPush_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kNFC_Watch_Name:
      var params = reader.decodeStruct(NFC_Watch_Params);
      return this.watch(params.options).then(function(response) {
        var responseParams =
            new NFC_Watch_ResponseParams();
        responseParams.id = response.id;
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kNFC_Watch_Name,
            codec.align(NFC_Watch_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(NFC_Watch_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kNFC_CancelWatch_Name:
      var params = reader.decodeStruct(NFC_CancelWatch_Params);
      return this.cancelWatch(params.id).then(function(response) {
        var responseParams =
            new NFC_CancelWatch_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kNFC_CancelWatch_Name,
            codec.align(NFC_CancelWatch_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(NFC_CancelWatch_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kNFC_CancelAllWatches_Name:
      var params = reader.decodeStruct(NFC_CancelAllWatches_Params);
      return this.cancelAllWatches().then(function(response) {
        var responseParams =
            new NFC_CancelAllWatches_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kNFC_CancelAllWatches_Name,
            codec.align(NFC_CancelAllWatches_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(NFC_CancelAllWatches_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateNFCRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kNFC_SetClient_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = NFC_SetClient_Params;
      break;
      case kNFC_Push_Name:
        if (message.expectsResponse())
          paramsClass = NFC_Push_Params;
      break;
      case kNFC_CancelPush_Name:
        if (message.expectsResponse())
          paramsClass = NFC_CancelPush_Params;
      break;
      case kNFC_Watch_Name:
        if (message.expectsResponse())
          paramsClass = NFC_Watch_Params;
      break;
      case kNFC_CancelWatch_Name:
        if (message.expectsResponse())
          paramsClass = NFC_CancelWatch_Params;
      break;
      case kNFC_CancelAllWatches_Name:
        if (message.expectsResponse())
          paramsClass = NFC_CancelAllWatches_Params;
      break;
      case kNFC_SuspendNFCOperations_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = NFC_SuspendNFCOperations_Params;
      break;
      case kNFC_ResumeNFCOperations_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = NFC_ResumeNFCOperations_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateNFCResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kNFC_Push_Name:
        if (message.isResponse())
          paramsClass = NFC_Push_ResponseParams;
        break;
      case kNFC_CancelPush_Name:
        if (message.isResponse())
          paramsClass = NFC_CancelPush_ResponseParams;
        break;
      case kNFC_Watch_Name:
        if (message.isResponse())
          paramsClass = NFC_Watch_ResponseParams;
        break;
      case kNFC_CancelWatch_Name:
        if (message.isResponse())
          paramsClass = NFC_CancelWatch_ResponseParams;
        break;
      case kNFC_CancelAllWatches_Name:
        if (message.isResponse())
          paramsClass = NFC_CancelAllWatches_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var NFC = {
    name: 'device::nfc::mojom::NFC',
    ptrClass: NFCPtr,
    proxyClass: NFCProxy,
    stubClass: NFCStub,
    validateRequest: validateNFCRequest,
    validateResponse: validateNFCResponse,
  };
  NFCStub.prototype.validator = validateNFCRequest;
  NFCProxy.prototype.validator = validateNFCResponse;
  var kNFCClient_OnWatch_Name = 0;

  function NFCClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(NFCClient,
                                                   handleOrPtrInfo);
  }

  function NFCClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  NFCClientPtr.prototype.onWatch = function() {
    return NFCClientProxy.prototype.onWatch
        .apply(this.ptr.getProxy(), arguments);
  };

  NFCClientProxy.prototype.onWatch = function(watch_ids, message) {
    var params = new NFCClient_OnWatch_Params();
    params.watch_ids = watch_ids;
    params.message = message;
    var builder = new codec.MessageBuilder(
        kNFCClient_OnWatch_Name,
        codec.align(NFCClient_OnWatch_Params.encodedSize));
    builder.encodeStruct(NFCClient_OnWatch_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function NFCClientStub(delegate) {
    this.delegate_ = delegate;
  }
  NFCClientStub.prototype.onWatch = function(watch_ids, message) {
    return this.delegate_ && this.delegate_.onWatch && this.delegate_.onWatch(watch_ids, message);
  }

  NFCClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kNFCClient_OnWatch_Name:
      var params = reader.decodeStruct(NFCClient_OnWatch_Params);
      this.onWatch(params.watch_ids, params.message);
      return true;
    default:
      return false;
    }
  };

  NFCClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateNFCClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kNFCClient_OnWatch_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = NFCClient_OnWatch_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateNFCClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var NFCClient = {
    name: 'device::nfc::mojom::NFCClient',
    ptrClass: NFCClientPtr,
    proxyClass: NFCClientProxy,
    stubClass: NFCClientStub,
    validateRequest: validateNFCClientRequest,
    validateResponse: null,
  };
  NFCClientStub.prototype.validator = validateNFCClientRequest;
  NFCClientProxy.prototype.validator = null;

  var exports = {};
  exports.NFCErrorType = NFCErrorType;
  exports.NFCRecordType = NFCRecordType;
  exports.NFCPushTarget = NFCPushTarget;
  exports.NFCWatchMode = NFCWatchMode;
  exports.NFCError = NFCError;
  exports.NFCRecord = NFCRecord;
  exports.NFCMessage = NFCMessage;
  exports.NFCPushOptions = NFCPushOptions;
  exports.NFCRecordTypeFilter = NFCRecordTypeFilter;
  exports.NFCWatchOptions = NFCWatchOptions;
  exports.NFC = NFC;
  exports.NFCPtr = NFCPtr;
  exports.NFCClient = NFCClient;
  exports.NFCClientPtr = NFCClientPtr;

  return exports;
});
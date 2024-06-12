// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/clipboard.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var kMimeTypeHTML = "text/html";
  var kMimeTypeMozillaURL = "text/x-moz-url";
  var kMimeTypePNG = "image/png";
  var kMimeTypeRTF = "text/rtf";
  var kMimeTypeText = "text/plain";
  var kMimeTypeURIList = "text/uri-list";
  var kMimeTypeURL = "text/url";

  function Clipboard_GetSequenceNumber_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_GetSequenceNumber_Params.prototype.initDefaults_ = function() {
    this.clipboard_type = 0;
  };
  Clipboard_GetSequenceNumber_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_GetSequenceNumber_Params.validate = function(messageValidator, offset) {
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


    
    // validate Clipboard_GetSequenceNumber_Params.clipboard_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Clipboard.Type);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Clipboard_GetSequenceNumber_Params.encodedSize = codec.kStructHeaderSize + 8;

  Clipboard_GetSequenceNumber_Params.decode = function(decoder) {
    var packed;
    var val = new Clipboard_GetSequenceNumber_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.clipboard_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Clipboard_GetSequenceNumber_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_GetSequenceNumber_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.clipboard_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Clipboard_GetSequenceNumber_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_GetSequenceNumber_ResponseParams.prototype.initDefaults_ = function() {
    this.sequence = 0;
  };
  Clipboard_GetSequenceNumber_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_GetSequenceNumber_ResponseParams.validate = function(messageValidator, offset) {
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

  Clipboard_GetSequenceNumber_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Clipboard_GetSequenceNumber_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Clipboard_GetSequenceNumber_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sequence = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  Clipboard_GetSequenceNumber_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_GetSequenceNumber_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.sequence);
  };
  function Clipboard_GetAvailableMimeTypes_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_GetAvailableMimeTypes_Params.prototype.initDefaults_ = function() {
    this.clipboard_types = 0;
  };
  Clipboard_GetAvailableMimeTypes_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_GetAvailableMimeTypes_Params.validate = function(messageValidator, offset) {
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


    
    // validate Clipboard_GetAvailableMimeTypes_Params.clipboard_types
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Clipboard.Type);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Clipboard_GetAvailableMimeTypes_Params.encodedSize = codec.kStructHeaderSize + 8;

  Clipboard_GetAvailableMimeTypes_Params.decode = function(decoder) {
    var packed;
    var val = new Clipboard_GetAvailableMimeTypes_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.clipboard_types = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Clipboard_GetAvailableMimeTypes_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_GetAvailableMimeTypes_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.clipboard_types);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Clipboard_GetAvailableMimeTypes_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_GetAvailableMimeTypes_ResponseParams.prototype.initDefaults_ = function() {
    this.sequence = 0;
    this.types = null;
  };
  Clipboard_GetAvailableMimeTypes_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_GetAvailableMimeTypes_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate Clipboard_GetAvailableMimeTypes_ResponseParams.types
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Clipboard_GetAvailableMimeTypes_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Clipboard_GetAvailableMimeTypes_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Clipboard_GetAvailableMimeTypes_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sequence = decoder.decodeStruct(codec.Uint64);
    val.types = decoder.decodeArrayPointer(codec.String);
    return val;
  };

  Clipboard_GetAvailableMimeTypes_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_GetAvailableMimeTypes_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.sequence);
    encoder.encodeArrayPointer(codec.String, val.types);
  };
  function Clipboard_ReadClipboardData_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_ReadClipboardData_Params.prototype.initDefaults_ = function() {
    this.clipboard_type = 0;
    this.mime_type = null;
  };
  Clipboard_ReadClipboardData_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_ReadClipboardData_Params.validate = function(messageValidator, offset) {
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


    
    // validate Clipboard_ReadClipboardData_Params.clipboard_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Clipboard.Type);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Clipboard_ReadClipboardData_Params.mime_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Clipboard_ReadClipboardData_Params.encodedSize = codec.kStructHeaderSize + 16;

  Clipboard_ReadClipboardData_Params.decode = function(decoder) {
    var packed;
    var val = new Clipboard_ReadClipboardData_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.clipboard_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.mime_type = decoder.decodeStruct(codec.String);
    return val;
  };

  Clipboard_ReadClipboardData_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_ReadClipboardData_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.clipboard_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.mime_type);
  };
  function Clipboard_ReadClipboardData_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_ReadClipboardData_ResponseParams.prototype.initDefaults_ = function() {
    this.sequence = 0;
    this.data = null;
  };
  Clipboard_ReadClipboardData_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_ReadClipboardData_ResponseParams.validate = function(messageValidator, offset) {
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



    
    // validate Clipboard_ReadClipboardData_ResponseParams.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Clipboard_ReadClipboardData_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Clipboard_ReadClipboardData_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Clipboard_ReadClipboardData_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sequence = decoder.decodeStruct(codec.Uint64);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  Clipboard_ReadClipboardData_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_ReadClipboardData_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.sequence);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function Clipboard_WriteClipboardData_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_WriteClipboardData_Params.prototype.initDefaults_ = function() {
    this.clipboard_type = 0;
    this.data = null;
  };
  Clipboard_WriteClipboardData_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_WriteClipboardData_Params.validate = function(messageValidator, offset) {
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


    
    // validate Clipboard_WriteClipboardData_Params.clipboard_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, Clipboard.Type);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Clipboard_WriteClipboardData_Params.data
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, true, codec.String, new codec.ArrayOf(codec.Uint8), false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Clipboard_WriteClipboardData_Params.encodedSize = codec.kStructHeaderSize + 16;

  Clipboard_WriteClipboardData_Params.decode = function(decoder) {
    var packed;
    var val = new Clipboard_WriteClipboardData_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.clipboard_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.data = decoder.decodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8));
    return val;
  };

  Clipboard_WriteClipboardData_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_WriteClipboardData_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.clipboard_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeMapPointer(codec.String, new codec.ArrayOf(codec.Uint8), val.data);
  };
  function Clipboard_WriteClipboardData_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Clipboard_WriteClipboardData_ResponseParams.prototype.initDefaults_ = function() {
    this.sequence = 0;
  };
  Clipboard_WriteClipboardData_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Clipboard_WriteClipboardData_ResponseParams.validate = function(messageValidator, offset) {
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

  Clipboard_WriteClipboardData_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Clipboard_WriteClipboardData_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Clipboard_WriteClipboardData_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sequence = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  Clipboard_WriteClipboardData_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Clipboard_WriteClipboardData_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.sequence);
  };
  var kClipboard_GetSequenceNumber_Name = 0;
  var kClipboard_GetAvailableMimeTypes_Name = 1;
  var kClipboard_ReadClipboardData_Name = 2;
  var kClipboard_WriteClipboardData_Name = 3;

  function ClipboardPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Clipboard,
                                                   handleOrPtrInfo);
  }

  function ClipboardProxy(receiver) {
    this.receiver_ = receiver;
  }
  ClipboardPtr.prototype.getSequenceNumber = function() {
    return ClipboardProxy.prototype.getSequenceNumber
        .apply(this.ptr.getProxy(), arguments);
  };

  ClipboardProxy.prototype.getSequenceNumber = function(clipboard_type) {
    var params = new Clipboard_GetSequenceNumber_Params();
    params.clipboard_type = clipboard_type;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kClipboard_GetSequenceNumber_Name,
          codec.align(Clipboard_GetSequenceNumber_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Clipboard_GetSequenceNumber_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Clipboard_GetSequenceNumber_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ClipboardPtr.prototype.getAvailableMimeTypes = function() {
    return ClipboardProxy.prototype.getAvailableMimeTypes
        .apply(this.ptr.getProxy(), arguments);
  };

  ClipboardProxy.prototype.getAvailableMimeTypes = function(clipboard_types) {
    var params = new Clipboard_GetAvailableMimeTypes_Params();
    params.clipboard_types = clipboard_types;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kClipboard_GetAvailableMimeTypes_Name,
          codec.align(Clipboard_GetAvailableMimeTypes_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Clipboard_GetAvailableMimeTypes_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Clipboard_GetAvailableMimeTypes_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ClipboardPtr.prototype.readClipboardData = function() {
    return ClipboardProxy.prototype.readClipboardData
        .apply(this.ptr.getProxy(), arguments);
  };

  ClipboardProxy.prototype.readClipboardData = function(clipboard_type, mime_type) {
    var params = new Clipboard_ReadClipboardData_Params();
    params.clipboard_type = clipboard_type;
    params.mime_type = mime_type;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kClipboard_ReadClipboardData_Name,
          codec.align(Clipboard_ReadClipboardData_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Clipboard_ReadClipboardData_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Clipboard_ReadClipboardData_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ClipboardPtr.prototype.writeClipboardData = function() {
    return ClipboardProxy.prototype.writeClipboardData
        .apply(this.ptr.getProxy(), arguments);
  };

  ClipboardProxy.prototype.writeClipboardData = function(clipboard_type, data) {
    var params = new Clipboard_WriteClipboardData_Params();
    params.clipboard_type = clipboard_type;
    params.data = data;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kClipboard_WriteClipboardData_Name,
          codec.align(Clipboard_WriteClipboardData_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Clipboard_WriteClipboardData_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Clipboard_WriteClipboardData_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function ClipboardStub(delegate) {
    this.delegate_ = delegate;
  }
  ClipboardStub.prototype.getSequenceNumber = function(clipboard_type) {
    return this.delegate_ && this.delegate_.getSequenceNumber && this.delegate_.getSequenceNumber(clipboard_type);
  }
  ClipboardStub.prototype.getAvailableMimeTypes = function(clipboard_types) {
    return this.delegate_ && this.delegate_.getAvailableMimeTypes && this.delegate_.getAvailableMimeTypes(clipboard_types);
  }
  ClipboardStub.prototype.readClipboardData = function(clipboard_type, mime_type) {
    return this.delegate_ && this.delegate_.readClipboardData && this.delegate_.readClipboardData(clipboard_type, mime_type);
  }
  ClipboardStub.prototype.writeClipboardData = function(clipboard_type, data) {
    return this.delegate_ && this.delegate_.writeClipboardData && this.delegate_.writeClipboardData(clipboard_type, data);
  }

  ClipboardStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  ClipboardStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kClipboard_GetSequenceNumber_Name:
      var params = reader.decodeStruct(Clipboard_GetSequenceNumber_Params);
      return this.getSequenceNumber(params.clipboard_type).then(function(response) {
        var responseParams =
            new Clipboard_GetSequenceNumber_ResponseParams();
        responseParams.sequence = response.sequence;
        var builder = new codec.MessageWithRequestIDBuilder(
            kClipboard_GetSequenceNumber_Name,
            codec.align(Clipboard_GetSequenceNumber_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Clipboard_GetSequenceNumber_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kClipboard_GetAvailableMimeTypes_Name:
      var params = reader.decodeStruct(Clipboard_GetAvailableMimeTypes_Params);
      return this.getAvailableMimeTypes(params.clipboard_types).then(function(response) {
        var responseParams =
            new Clipboard_GetAvailableMimeTypes_ResponseParams();
        responseParams.sequence = response.sequence;
        responseParams.types = response.types;
        var builder = new codec.MessageWithRequestIDBuilder(
            kClipboard_GetAvailableMimeTypes_Name,
            codec.align(Clipboard_GetAvailableMimeTypes_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Clipboard_GetAvailableMimeTypes_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kClipboard_ReadClipboardData_Name:
      var params = reader.decodeStruct(Clipboard_ReadClipboardData_Params);
      return this.readClipboardData(params.clipboard_type, params.mime_type).then(function(response) {
        var responseParams =
            new Clipboard_ReadClipboardData_ResponseParams();
        responseParams.sequence = response.sequence;
        responseParams.data = response.data;
        var builder = new codec.MessageWithRequestIDBuilder(
            kClipboard_ReadClipboardData_Name,
            codec.align(Clipboard_ReadClipboardData_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Clipboard_ReadClipboardData_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kClipboard_WriteClipboardData_Name:
      var params = reader.decodeStruct(Clipboard_WriteClipboardData_Params);
      return this.writeClipboardData(params.clipboard_type, params.data).then(function(response) {
        var responseParams =
            new Clipboard_WriteClipboardData_ResponseParams();
        responseParams.sequence = response.sequence;
        var builder = new codec.MessageWithRequestIDBuilder(
            kClipboard_WriteClipboardData_Name,
            codec.align(Clipboard_WriteClipboardData_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Clipboard_WriteClipboardData_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateClipboardRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kClipboard_GetSequenceNumber_Name:
        if (message.expectsResponse())
          paramsClass = Clipboard_GetSequenceNumber_Params;
      break;
      case kClipboard_GetAvailableMimeTypes_Name:
        if (message.expectsResponse())
          paramsClass = Clipboard_GetAvailableMimeTypes_Params;
      break;
      case kClipboard_ReadClipboardData_Name:
        if (message.expectsResponse())
          paramsClass = Clipboard_ReadClipboardData_Params;
      break;
      case kClipboard_WriteClipboardData_Name:
        if (message.expectsResponse())
          paramsClass = Clipboard_WriteClipboardData_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateClipboardResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kClipboard_GetSequenceNumber_Name:
        if (message.isResponse())
          paramsClass = Clipboard_GetSequenceNumber_ResponseParams;
        break;
      case kClipboard_GetAvailableMimeTypes_Name:
        if (message.isResponse())
          paramsClass = Clipboard_GetAvailableMimeTypes_ResponseParams;
        break;
      case kClipboard_ReadClipboardData_Name:
        if (message.isResponse())
          paramsClass = Clipboard_ReadClipboardData_ResponseParams;
        break;
      case kClipboard_WriteClipboardData_Name:
        if (message.isResponse())
          paramsClass = Clipboard_WriteClipboardData_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Clipboard = {
    name: 'ui::mojom::Clipboard',
    ptrClass: ClipboardPtr,
    proxyClass: ClipboardProxy,
    stubClass: ClipboardStub,
    validateRequest: validateClipboardRequest,
    validateResponse: validateClipboardResponse,
  };
  Clipboard.Type = {};
  Clipboard.Type.COPY_PASTE = 0;
  Clipboard.Type.SELECTION = 1;

  Clipboard.Type.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  Clipboard.Type.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  ClipboardStub.prototype.validator = validateClipboardRequest;
  ClipboardProxy.prototype.validator = validateClipboardResponse;

  var exports = {};
  exports.kMimeTypeHTML = kMimeTypeHTML;
  exports.kMimeTypeMozillaURL = kMimeTypeMozillaURL;
  exports.kMimeTypePNG = kMimeTypePNG;
  exports.kMimeTypeRTF = kMimeTypeRTF;
  exports.kMimeTypeText = kMimeTypeText;
  exports.kMimeTypeURIList = kMimeTypeURIList;
  exports.kMimeTypeURL = kMimeTypeURL;
  exports.Clipboard = Clipboard;
  exports.ClipboardPtr = ClipboardPtr;

  return exports;
});
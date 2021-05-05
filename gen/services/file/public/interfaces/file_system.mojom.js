// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/file/public/interfaces/file_system.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "components/filesystem/public/interfaces/directory.mojom",
    "components/filesystem/public/interfaces/types.mojom",
], function(bindings, codec, core, validator, directory$, types$) {

  function FileSystem_GetDirectory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_GetDirectory_Params.prototype.initDefaults_ = function() {
    this.dir = new bindings.InterfaceRequest();
  };
  FileSystem_GetDirectory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_GetDirectory_Params.validate = function(messageValidator, offset) {
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


    
    // validate FileSystem_GetDirectory_Params.dir
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FileSystem_GetDirectory_Params.encodedSize = codec.kStructHeaderSize + 8;

  FileSystem_GetDirectory_Params.decode = function(decoder) {
    var packed;
    var val = new FileSystem_GetDirectory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.dir = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FileSystem_GetDirectory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_GetDirectory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.dir);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FileSystem_GetDirectory_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_GetDirectory_ResponseParams.prototype.initDefaults_ = function() {
  };
  FileSystem_GetDirectory_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_GetDirectory_ResponseParams.validate = function(messageValidator, offset) {
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

  FileSystem_GetDirectory_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  FileSystem_GetDirectory_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new FileSystem_GetDirectory_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  FileSystem_GetDirectory_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_GetDirectory_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  function FileSystem_GetSubDirectory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_GetSubDirectory_Params.prototype.initDefaults_ = function() {
    this.dir_path = null;
    this.dir = new bindings.InterfaceRequest();
  };
  FileSystem_GetSubDirectory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_GetSubDirectory_Params.validate = function(messageValidator, offset) {
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


    
    // validate FileSystem_GetSubDirectory_Params.dir_path
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FileSystem_GetSubDirectory_Params.dir
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FileSystem_GetSubDirectory_Params.encodedSize = codec.kStructHeaderSize + 16;

  FileSystem_GetSubDirectory_Params.decode = function(decoder) {
    var packed;
    var val = new FileSystem_GetSubDirectory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.dir_path = decoder.decodeStruct(codec.String);
    val.dir = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FileSystem_GetSubDirectory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_GetSubDirectory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.dir_path);
    encoder.encodeStruct(codec.InterfaceRequest, val.dir);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FileSystem_GetSubDirectory_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_GetSubDirectory_ResponseParams.prototype.initDefaults_ = function() {
    this.err = 0;
  };
  FileSystem_GetSubDirectory_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_GetSubDirectory_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate FileSystem_GetSubDirectory_ResponseParams.err
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FileSystem_GetSubDirectory_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  FileSystem_GetSubDirectory_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new FileSystem_GetSubDirectory_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.err = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FileSystem_GetSubDirectory_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_GetSubDirectory_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.err);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kFileSystem_GetDirectory_Name = 0;
  var kFileSystem_GetSubDirectory_Name = 1;

  function FileSystemPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(FileSystem,
                                                   handleOrPtrInfo);
  }

  function FileSystemProxy(receiver) {
    this.receiver_ = receiver;
  }
  FileSystemPtr.prototype.getDirectory = function() {
    return FileSystemProxy.prototype.getDirectory
        .apply(this.ptr.getProxy(), arguments);
  };

  FileSystemProxy.prototype.getDirectory = function(dir) {
    var params = new FileSystem_GetDirectory_Params();
    params.dir = dir;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFileSystem_GetDirectory_Name,
          codec.align(FileSystem_GetDirectory_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(FileSystem_GetDirectory_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(FileSystem_GetDirectory_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FileSystemPtr.prototype.getSubDirectory = function() {
    return FileSystemProxy.prototype.getSubDirectory
        .apply(this.ptr.getProxy(), arguments);
  };

  FileSystemProxy.prototype.getSubDirectory = function(dir_path, dir) {
    var params = new FileSystem_GetSubDirectory_Params();
    params.dir_path = dir_path;
    params.dir = dir;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFileSystem_GetSubDirectory_Name,
          codec.align(FileSystem_GetSubDirectory_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(FileSystem_GetSubDirectory_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(FileSystem_GetSubDirectory_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function FileSystemStub(delegate) {
    this.delegate_ = delegate;
  }
  FileSystemStub.prototype.getDirectory = function(dir) {
    return this.delegate_ && this.delegate_.getDirectory && this.delegate_.getDirectory(dir);
  }
  FileSystemStub.prototype.getSubDirectory = function(dir_path, dir) {
    return this.delegate_ && this.delegate_.getSubDirectory && this.delegate_.getSubDirectory(dir_path, dir);
  }

  FileSystemStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  FileSystemStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kFileSystem_GetDirectory_Name:
      var params = reader.decodeStruct(FileSystem_GetDirectory_Params);
      return this.getDirectory(params.dir).then(function(response) {
        var responseParams =
            new FileSystem_GetDirectory_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kFileSystem_GetDirectory_Name,
            codec.align(FileSystem_GetDirectory_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(FileSystem_GetDirectory_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFileSystem_GetSubDirectory_Name:
      var params = reader.decodeStruct(FileSystem_GetSubDirectory_Params);
      return this.getSubDirectory(params.dir_path, params.dir).then(function(response) {
        var responseParams =
            new FileSystem_GetSubDirectory_ResponseParams();
        responseParams.err = response.err;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFileSystem_GetSubDirectory_Name,
            codec.align(FileSystem_GetSubDirectory_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(FileSystem_GetSubDirectory_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateFileSystemRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kFileSystem_GetDirectory_Name:
        if (message.expectsResponse())
          paramsClass = FileSystem_GetDirectory_Params;
      break;
      case kFileSystem_GetSubDirectory_Name:
        if (message.expectsResponse())
          paramsClass = FileSystem_GetSubDirectory_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateFileSystemResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kFileSystem_GetDirectory_Name:
        if (message.isResponse())
          paramsClass = FileSystem_GetDirectory_ResponseParams;
        break;
      case kFileSystem_GetSubDirectory_Name:
        if (message.isResponse())
          paramsClass = FileSystem_GetSubDirectory_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var FileSystem = {
    name: 'file::mojom::FileSystem',
    ptrClass: FileSystemPtr,
    proxyClass: FileSystemProxy,
    stubClass: FileSystemStub,
    validateRequest: validateFileSystemRequest,
    validateResponse: validateFileSystemResponse,
  };
  FileSystemStub.prototype.validator = validateFileSystemRequest;
  FileSystemProxy.prototype.validator = validateFileSystemResponse;

  var exports = {};
  exports.FileSystem = FileSystem;
  exports.FileSystemPtr = FileSystemPtr;

  return exports;
});
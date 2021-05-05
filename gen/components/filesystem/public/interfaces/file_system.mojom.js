// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/filesystem/public/interfaces/file_system.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "components/filesystem/public/interfaces/directory.mojom",
    "components/filesystem/public/interfaces/types.mojom",
], function(bindings, codec, core, validator, directory$, types$) {

  function FileSystem_OpenTempDirectory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_OpenTempDirectory_Params.prototype.initDefaults_ = function() {
    this.directory = new bindings.InterfaceRequest();
  };
  FileSystem_OpenTempDirectory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_OpenTempDirectory_Params.validate = function(messageValidator, offset) {
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


    
    // validate FileSystem_OpenTempDirectory_Params.directory
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FileSystem_OpenTempDirectory_Params.encodedSize = codec.kStructHeaderSize + 8;

  FileSystem_OpenTempDirectory_Params.decode = function(decoder) {
    var packed;
    var val = new FileSystem_OpenTempDirectory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.directory = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FileSystem_OpenTempDirectory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_OpenTempDirectory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.directory);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FileSystem_OpenTempDirectory_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_OpenTempDirectory_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  FileSystem_OpenTempDirectory_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_OpenTempDirectory_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate FileSystem_OpenTempDirectory_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FileSystem_OpenTempDirectory_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  FileSystem_OpenTempDirectory_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new FileSystem_OpenTempDirectory_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FileSystem_OpenTempDirectory_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_OpenTempDirectory_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FileSystem_OpenPersistentFileSystem_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_OpenPersistentFileSystem_Params.prototype.initDefaults_ = function() {
    this.directory = new bindings.InterfaceRequest();
  };
  FileSystem_OpenPersistentFileSystem_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_OpenPersistentFileSystem_Params.validate = function(messageValidator, offset) {
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


    
    // validate FileSystem_OpenPersistentFileSystem_Params.directory
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FileSystem_OpenPersistentFileSystem_Params.encodedSize = codec.kStructHeaderSize + 8;

  FileSystem_OpenPersistentFileSystem_Params.decode = function(decoder) {
    var packed;
    var val = new FileSystem_OpenPersistentFileSystem_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.directory = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FileSystem_OpenPersistentFileSystem_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_OpenPersistentFileSystem_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.directory);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FileSystem_OpenPersistentFileSystem_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FileSystem_OpenPersistentFileSystem_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  FileSystem_OpenPersistentFileSystem_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FileSystem_OpenPersistentFileSystem_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate FileSystem_OpenPersistentFileSystem_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, types$.FileError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FileSystem_OpenPersistentFileSystem_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  FileSystem_OpenPersistentFileSystem_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new FileSystem_OpenPersistentFileSystem_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FileSystem_OpenPersistentFileSystem_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FileSystem_OpenPersistentFileSystem_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kFileSystem_OpenTempDirectory_Name = 0;
  var kFileSystem_OpenPersistentFileSystem_Name = 1;

  function FileSystemPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(FileSystem,
                                                   handleOrPtrInfo);
  }

  function FileSystemProxy(receiver) {
    this.receiver_ = receiver;
  }
  FileSystemPtr.prototype.openTempDirectory = function() {
    return FileSystemProxy.prototype.openTempDirectory
        .apply(this.ptr.getProxy(), arguments);
  };

  FileSystemProxy.prototype.openTempDirectory = function(directory) {
    var params = new FileSystem_OpenTempDirectory_Params();
    params.directory = directory;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFileSystem_OpenTempDirectory_Name,
          codec.align(FileSystem_OpenTempDirectory_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(FileSystem_OpenTempDirectory_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(FileSystem_OpenTempDirectory_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  FileSystemPtr.prototype.openPersistentFileSystem = function() {
    return FileSystemProxy.prototype.openPersistentFileSystem
        .apply(this.ptr.getProxy(), arguments);
  };

  FileSystemProxy.prototype.openPersistentFileSystem = function(directory) {
    var params = new FileSystem_OpenPersistentFileSystem_Params();
    params.directory = directory;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFileSystem_OpenPersistentFileSystem_Name,
          codec.align(FileSystem_OpenPersistentFileSystem_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(FileSystem_OpenPersistentFileSystem_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(FileSystem_OpenPersistentFileSystem_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function FileSystemStub(delegate) {
    this.delegate_ = delegate;
  }
  FileSystemStub.prototype.openTempDirectory = function(directory) {
    return this.delegate_ && this.delegate_.openTempDirectory && this.delegate_.openTempDirectory(directory);
  }
  FileSystemStub.prototype.openPersistentFileSystem = function(directory) {
    return this.delegate_ && this.delegate_.openPersistentFileSystem && this.delegate_.openPersistentFileSystem(directory);
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
    case kFileSystem_OpenTempDirectory_Name:
      var params = reader.decodeStruct(FileSystem_OpenTempDirectory_Params);
      return this.openTempDirectory(params.directory).then(function(response) {
        var responseParams =
            new FileSystem_OpenTempDirectory_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFileSystem_OpenTempDirectory_Name,
            codec.align(FileSystem_OpenTempDirectory_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(FileSystem_OpenTempDirectory_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kFileSystem_OpenPersistentFileSystem_Name:
      var params = reader.decodeStruct(FileSystem_OpenPersistentFileSystem_Params);
      return this.openPersistentFileSystem(params.directory).then(function(response) {
        var responseParams =
            new FileSystem_OpenPersistentFileSystem_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFileSystem_OpenPersistentFileSystem_Name,
            codec.align(FileSystem_OpenPersistentFileSystem_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(FileSystem_OpenPersistentFileSystem_ResponseParams,
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
      case kFileSystem_OpenTempDirectory_Name:
        if (message.expectsResponse())
          paramsClass = FileSystem_OpenTempDirectory_Params;
      break;
      case kFileSystem_OpenPersistentFileSystem_Name:
        if (message.expectsResponse())
          paramsClass = FileSystem_OpenPersistentFileSystem_Params;
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
      case kFileSystem_OpenTempDirectory_Name:
        if (message.isResponse())
          paramsClass = FileSystem_OpenTempDirectory_ResponseParams;
        break;
      case kFileSystem_OpenPersistentFileSystem_Name:
        if (message.isResponse())
          paramsClass = FileSystem_OpenPersistentFileSystem_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var FileSystem = {
    name: 'filesystem::mojom::FileSystem',
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
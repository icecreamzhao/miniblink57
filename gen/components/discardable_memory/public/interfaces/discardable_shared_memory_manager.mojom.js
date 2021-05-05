// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/discardable_memory/public/interfaces/discardable_shared_memory_manager.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.prototype.initDefaults_ = function() {
    this.size = 0;
    this.id = 0;
  };
  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.validate = function(messageValidator, offset) {
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

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.encodedSize = codec.kStructHeaderSize + 8;

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.decode = function(decoder) {
    var packed;
    var val = new DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.size = decoder.decodeStruct(codec.Uint32);
    val.id = decoder.decodeStruct(codec.Int32);
    return val;
  };

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.size);
    encoder.encodeStruct(codec.Int32, val.id);
  };
  function DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.prototype.initDefaults_ = function() {
    this.memory = null;
  };
  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.memory
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.memory = decoder.decodeStruct(codec.NullableHandle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.NullableHandle, val.memory);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.prototype.initDefaults_ = function() {
    this.id = 0;
  };
  DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.validate = function(messageValidator, offset) {
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

  DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.encodedSize = codec.kStructHeaderSize + 8;

  DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.decode = function(decoder) {
    var packed;
    var val = new DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name = 0;
  var kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name = 1;

  function DiscardableSharedMemoryManagerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(DiscardableSharedMemoryManager,
                                                   handleOrPtrInfo);
  }

  function DiscardableSharedMemoryManagerProxy(receiver) {
    this.receiver_ = receiver;
  }
  DiscardableSharedMemoryManagerPtr.prototype.allocateLockedDiscardableSharedMemory = function() {
    return DiscardableSharedMemoryManagerProxy.prototype.allocateLockedDiscardableSharedMemory
        .apply(this.ptr.getProxy(), arguments);
  };

  DiscardableSharedMemoryManagerProxy.prototype.allocateLockedDiscardableSharedMemory = function(size, id) {
    var params = new DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params();
    params.size = size;
    params.id = id;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name,
          codec.align(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DiscardableSharedMemoryManagerPtr.prototype.deletedDiscardableSharedMemory = function() {
    return DiscardableSharedMemoryManagerProxy.prototype.deletedDiscardableSharedMemory
        .apply(this.ptr.getProxy(), arguments);
  };

  DiscardableSharedMemoryManagerProxy.prototype.deletedDiscardableSharedMemory = function(id) {
    var params = new DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params();
    params.id = id;
    var builder = new codec.MessageBuilder(
        kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name,
        codec.align(DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params.encodedSize));
    builder.encodeStruct(DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function DiscardableSharedMemoryManagerStub(delegate) {
    this.delegate_ = delegate;
  }
  DiscardableSharedMemoryManagerStub.prototype.allocateLockedDiscardableSharedMemory = function(size, id) {
    return this.delegate_ && this.delegate_.allocateLockedDiscardableSharedMemory && this.delegate_.allocateLockedDiscardableSharedMemory(size, id);
  }
  DiscardableSharedMemoryManagerStub.prototype.deletedDiscardableSharedMemory = function(id) {
    return this.delegate_ && this.delegate_.deletedDiscardableSharedMemory && this.delegate_.deletedDiscardableSharedMemory(id);
  }

  DiscardableSharedMemoryManagerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name:
      var params = reader.decodeStruct(DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params);
      this.deletedDiscardableSharedMemory(params.id);
      return true;
    default:
      return false;
    }
  };

  DiscardableSharedMemoryManagerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name:
      var params = reader.decodeStruct(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params);
      return this.allocateLockedDiscardableSharedMemory(params.size, params.id).then(function(response) {
        var responseParams =
            new DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams();
        responseParams.memory = response.memory;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name,
            codec.align(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDiscardableSharedMemoryManagerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name:
        if (message.expectsResponse())
          paramsClass = DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params;
      break;
      case kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDiscardableSharedMemoryManagerResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name:
        if (message.isResponse())
          paramsClass = DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var DiscardableSharedMemoryManager = {
    name: 'discardable_memory::mojom::DiscardableSharedMemoryManager',
    ptrClass: DiscardableSharedMemoryManagerPtr,
    proxyClass: DiscardableSharedMemoryManagerProxy,
    stubClass: DiscardableSharedMemoryManagerStub,
    validateRequest: validateDiscardableSharedMemoryManagerRequest,
    validateResponse: validateDiscardableSharedMemoryManagerResponse,
  };
  DiscardableSharedMemoryManagerStub.prototype.validator = validateDiscardableSharedMemoryManagerRequest;
  DiscardableSharedMemoryManagerProxy.prototype.validator = validateDiscardableSharedMemoryManagerResponse;

  var exports = {};
  exports.DiscardableSharedMemoryManager = DiscardableSharedMemoryManager;
  exports.DiscardableSharedMemoryManagerPtr = DiscardableSharedMemoryManagerPtr;

  return exports;
});
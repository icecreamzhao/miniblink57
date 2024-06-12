// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/window_tree_host.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/ui/public/interfaces/window_tree.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, window_tree$, geometry$) {

  function WindowTreeHost_SetSize_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeHost_SetSize_Params.prototype.initDefaults_ = function() {
    this.size = null;
  };
  WindowTreeHost_SetSize_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeHost_SetSize_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowTreeHost_SetSize_Params.size
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeHost_SetSize_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeHost_SetSize_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeHost_SetSize_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.size = decoder.decodeStructPointer(geometry$.Size);
    return val;
  };

  WindowTreeHost_SetSize_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeHost_SetSize_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.Size, val.size);
  };
  function WindowTreeHost_SetTitle_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeHost_SetTitle_Params.prototype.initDefaults_ = function() {
    this.title = null;
  };
  WindowTreeHost_SetTitle_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeHost_SetTitle_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowTreeHost_SetTitle_Params.title
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeHost_SetTitle_Params.encodedSize = codec.kStructHeaderSize + 8;

  WindowTreeHost_SetTitle_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeHost_SetTitle_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.title = decoder.decodeStruct(codec.String);
    return val;
  };

  WindowTreeHost_SetTitle_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeHost_SetTitle_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.title);
  };
  function WindowTreeHostFactory_CreateWindowTreeHost_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowTreeHostFactory_CreateWindowTreeHost_Params.prototype.initDefaults_ = function() {
    this.window_tree_host = new bindings.InterfaceRequest();
    this.tree_client = new window_tree$.WindowTreeClientPtr();
  };
  WindowTreeHostFactory_CreateWindowTreeHost_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowTreeHostFactory_CreateWindowTreeHost_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowTreeHostFactory_CreateWindowTreeHost_Params.window_tree_host
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowTreeHostFactory_CreateWindowTreeHost_Params.tree_client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowTreeHostFactory_CreateWindowTreeHost_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowTreeHostFactory_CreateWindowTreeHost_Params.decode = function(decoder) {
    var packed;
    var val = new WindowTreeHostFactory_CreateWindowTreeHost_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.window_tree_host = decoder.decodeStruct(codec.InterfaceRequest);
    val.tree_client = decoder.decodeStruct(new codec.Interface(window_tree$.WindowTreeClientPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowTreeHostFactory_CreateWindowTreeHost_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowTreeHostFactory_CreateWindowTreeHost_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.window_tree_host);
    encoder.encodeStruct(new codec.Interface(window_tree$.WindowTreeClientPtr), val.tree_client);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kWindowTreeHost_SetSize_Name = 0;
  var kWindowTreeHost_SetTitle_Name = 1;

  function WindowTreeHostPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WindowTreeHost,
                                                   handleOrPtrInfo);
  }

  function WindowTreeHostProxy(receiver) {
    this.receiver_ = receiver;
  }
  WindowTreeHostPtr.prototype.setSize = function() {
    return WindowTreeHostProxy.prototype.setSize
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeHostProxy.prototype.setSize = function(size) {
    var params = new WindowTreeHost_SetSize_Params();
    params.size = size;
    var builder = new codec.MessageBuilder(
        kWindowTreeHost_SetSize_Name,
        codec.align(WindowTreeHost_SetSize_Params.encodedSize));
    builder.encodeStruct(WindowTreeHost_SetSize_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  WindowTreeHostPtr.prototype.setTitle = function() {
    return WindowTreeHostProxy.prototype.setTitle
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeHostProxy.prototype.setTitle = function(title) {
    var params = new WindowTreeHost_SetTitle_Params();
    params.title = title;
    var builder = new codec.MessageBuilder(
        kWindowTreeHost_SetTitle_Name,
        codec.align(WindowTreeHost_SetTitle_Params.encodedSize));
    builder.encodeStruct(WindowTreeHost_SetTitle_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function WindowTreeHostStub(delegate) {
    this.delegate_ = delegate;
  }
  WindowTreeHostStub.prototype.setSize = function(size) {
    return this.delegate_ && this.delegate_.setSize && this.delegate_.setSize(size);
  }
  WindowTreeHostStub.prototype.setTitle = function(title) {
    return this.delegate_ && this.delegate_.setTitle && this.delegate_.setTitle(title);
  }

  WindowTreeHostStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowTreeHost_SetSize_Name:
      var params = reader.decodeStruct(WindowTreeHost_SetSize_Params);
      this.setSize(params.size);
      return true;
    case kWindowTreeHost_SetTitle_Name:
      var params = reader.decodeStruct(WindowTreeHost_SetTitle_Params);
      this.setTitle(params.title);
      return true;
    default:
      return false;
    }
  };

  WindowTreeHostStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWindowTreeHostRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWindowTreeHost_SetSize_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeHost_SetSize_Params;
      break;
      case kWindowTreeHost_SetTitle_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeHost_SetTitle_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWindowTreeHostResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var WindowTreeHost = {
    name: 'ui::mojom::WindowTreeHost',
    ptrClass: WindowTreeHostPtr,
    proxyClass: WindowTreeHostProxy,
    stubClass: WindowTreeHostStub,
    validateRequest: validateWindowTreeHostRequest,
    validateResponse: null,
  };
  WindowTreeHostStub.prototype.validator = validateWindowTreeHostRequest;
  WindowTreeHostProxy.prototype.validator = null;
  var kWindowTreeHostFactory_CreateWindowTreeHost_Name = 0;

  function WindowTreeHostFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WindowTreeHostFactory,
                                                   handleOrPtrInfo);
  }

  function WindowTreeHostFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  WindowTreeHostFactoryPtr.prototype.createWindowTreeHost = function() {
    return WindowTreeHostFactoryProxy.prototype.createWindowTreeHost
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowTreeHostFactoryProxy.prototype.createWindowTreeHost = function(window_tree_host, tree_client) {
    var params = new WindowTreeHostFactory_CreateWindowTreeHost_Params();
    params.window_tree_host = window_tree_host;
    params.tree_client = tree_client;
    var builder = new codec.MessageBuilder(
        kWindowTreeHostFactory_CreateWindowTreeHost_Name,
        codec.align(WindowTreeHostFactory_CreateWindowTreeHost_Params.encodedSize));
    builder.encodeStruct(WindowTreeHostFactory_CreateWindowTreeHost_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function WindowTreeHostFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  WindowTreeHostFactoryStub.prototype.createWindowTreeHost = function(window_tree_host, tree_client) {
    return this.delegate_ && this.delegate_.createWindowTreeHost && this.delegate_.createWindowTreeHost(window_tree_host, tree_client);
  }

  WindowTreeHostFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowTreeHostFactory_CreateWindowTreeHost_Name:
      var params = reader.decodeStruct(WindowTreeHostFactory_CreateWindowTreeHost_Params);
      this.createWindowTreeHost(params.window_tree_host, params.tree_client);
      return true;
    default:
      return false;
    }
  };

  WindowTreeHostFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWindowTreeHostFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWindowTreeHostFactory_CreateWindowTreeHost_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowTreeHostFactory_CreateWindowTreeHost_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWindowTreeHostFactoryResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var WindowTreeHostFactory = {
    name: 'ui::mojom::WindowTreeHostFactory',
    ptrClass: WindowTreeHostFactoryPtr,
    proxyClass: WindowTreeHostFactoryProxy,
    stubClass: WindowTreeHostFactoryStub,
    validateRequest: validateWindowTreeHostFactoryRequest,
    validateResponse: null,
  };
  WindowTreeHostFactoryStub.prototype.validator = validateWindowTreeHostFactoryRequest;
  WindowTreeHostFactoryProxy.prototype.validator = null;

  var exports = {};
  exports.WindowTreeHost = WindowTreeHost;
  exports.WindowTreeHostPtr = WindowTreeHostPtr;
  exports.WindowTreeHostFactory = WindowTreeHostFactory;
  exports.WindowTreeHostFactoryPtr = WindowTreeHostFactoryPtr;

  return exports;
});
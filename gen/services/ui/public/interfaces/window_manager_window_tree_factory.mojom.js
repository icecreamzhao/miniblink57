// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/window_manager_window_tree_factory.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/ui/public/interfaces/window_manager_constants.mojom",
    "services/ui/public/interfaces/window_tree.mojom",
], function(bindings, codec, core, validator, window_manager_constants$, window_tree$) {

  function WindowManagerWindowTreeFactory_CreateWindowTree_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  WindowManagerWindowTreeFactory_CreateWindowTree_Params.prototype.initDefaults_ = function() {
    this.tree_request = new bindings.InterfaceRequest();
    this.client = new window_tree$.WindowTreeClientPtr();
  };
  WindowManagerWindowTreeFactory_CreateWindowTree_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  WindowManagerWindowTreeFactory_CreateWindowTree_Params.validate = function(messageValidator, offset) {
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


    
    // validate WindowManagerWindowTreeFactory_CreateWindowTree_Params.tree_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate WindowManagerWindowTreeFactory_CreateWindowTree_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 4, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  WindowManagerWindowTreeFactory_CreateWindowTree_Params.encodedSize = codec.kStructHeaderSize + 16;

  WindowManagerWindowTreeFactory_CreateWindowTree_Params.decode = function(decoder) {
    var packed;
    var val = new WindowManagerWindowTreeFactory_CreateWindowTree_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.tree_request = decoder.decodeStruct(codec.InterfaceRequest);
    val.client = decoder.decodeStruct(new codec.Interface(window_tree$.WindowTreeClientPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  WindowManagerWindowTreeFactory_CreateWindowTree_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(WindowManagerWindowTreeFactory_CreateWindowTree_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.tree_request);
    encoder.encodeStruct(new codec.Interface(window_tree$.WindowTreeClientPtr), val.client);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kWindowManagerWindowTreeFactory_CreateWindowTree_Name = 0;

  function WindowManagerWindowTreeFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(WindowManagerWindowTreeFactory,
                                                   handleOrPtrInfo);
  }

  function WindowManagerWindowTreeFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  WindowManagerWindowTreeFactoryPtr.prototype.createWindowTree = function() {
    return WindowManagerWindowTreeFactoryProxy.prototype.createWindowTree
        .apply(this.ptr.getProxy(), arguments);
  };

  WindowManagerWindowTreeFactoryProxy.prototype.createWindowTree = function(tree_request, client) {
    var params = new WindowManagerWindowTreeFactory_CreateWindowTree_Params();
    params.tree_request = tree_request;
    params.client = client;
    var builder = new codec.MessageBuilder(
        kWindowManagerWindowTreeFactory_CreateWindowTree_Name,
        codec.align(WindowManagerWindowTreeFactory_CreateWindowTree_Params.encodedSize));
    builder.encodeStruct(WindowManagerWindowTreeFactory_CreateWindowTree_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function WindowManagerWindowTreeFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  WindowManagerWindowTreeFactoryStub.prototype.createWindowTree = function(tree_request, client) {
    return this.delegate_ && this.delegate_.createWindowTree && this.delegate_.createWindowTree(tree_request, client);
  }

  WindowManagerWindowTreeFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kWindowManagerWindowTreeFactory_CreateWindowTree_Name:
      var params = reader.decodeStruct(WindowManagerWindowTreeFactory_CreateWindowTree_Params);
      this.createWindowTree(params.tree_request, params.client);
      return true;
    default:
      return false;
    }
  };

  WindowManagerWindowTreeFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateWindowManagerWindowTreeFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kWindowManagerWindowTreeFactory_CreateWindowTree_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = WindowManagerWindowTreeFactory_CreateWindowTree_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateWindowManagerWindowTreeFactoryResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var WindowManagerWindowTreeFactory = {
    name: 'ui::mojom::WindowManagerWindowTreeFactory',
    ptrClass: WindowManagerWindowTreeFactoryPtr,
    proxyClass: WindowManagerWindowTreeFactoryProxy,
    stubClass: WindowManagerWindowTreeFactoryStub,
    validateRequest: validateWindowManagerWindowTreeFactoryRequest,
    validateResponse: null,
  };
  WindowManagerWindowTreeFactoryStub.prototype.validator = validateWindowManagerWindowTreeFactoryRequest;
  WindowManagerWindowTreeFactoryProxy.prototype.validator = null;

  var exports = {};
  exports.WindowManagerWindowTreeFactory = WindowManagerWindowTreeFactory;
  exports.WindowManagerWindowTreeFactoryPtr = WindowManagerWindowTreeFactoryPtr;

  return exports;
});
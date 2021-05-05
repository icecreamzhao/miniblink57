// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/broadcastchannel/broadcast_channel.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "url/mojo/origin.mojom",
], function(bindings, codec, core, validator, origin$) {

  function BroadcastChannelClient_OnMessage_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BroadcastChannelClient_OnMessage_Params.prototype.initDefaults_ = function() {
    this.message = null;
  };
  BroadcastChannelClient_OnMessage_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BroadcastChannelClient_OnMessage_Params.validate = function(messageValidator, offset) {
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


    
    // validate BroadcastChannelClient_OnMessage_Params.message
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BroadcastChannelClient_OnMessage_Params.encodedSize = codec.kStructHeaderSize + 8;

  BroadcastChannelClient_OnMessage_Params.decode = function(decoder) {
    var packed;
    var val = new BroadcastChannelClient_OnMessage_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.message = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  BroadcastChannelClient_OnMessage_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BroadcastChannelClient_OnMessage_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.message);
  };
  function BroadcastChannelProvider_ConnectToChannel_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BroadcastChannelProvider_ConnectToChannel_Params.prototype.initDefaults_ = function() {
    this.origin = null;
    this.name = null;
    this.receiver = null;
    this.sender = null;
  };
  BroadcastChannelProvider_ConnectToChannel_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BroadcastChannelProvider_ConnectToChannel_Params.validate = function(messageValidator, offset) {
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


    
    // validate BroadcastChannelProvider_ConnectToChannel_Params.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BroadcastChannelProvider_ConnectToChannel_Params.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;





    return validator.validationError.NONE;
  };

  BroadcastChannelProvider_ConnectToChannel_Params.encodedSize = codec.kStructHeaderSize + 32;

  BroadcastChannelProvider_ConnectToChannel_Params.decode = function(decoder) {
    var packed;
    var val = new BroadcastChannelProvider_ConnectToChannel_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.origin = decoder.decodeStructPointer(origin$.Origin);
    val.name = decoder.decodeStruct(codec.String);
    val.receiver = decoder.decodeStruct(codec.AssociatedInterfaceNotSupported);
    val.sender = decoder.decodeStruct(codec.AssociatedInterfaceRequestNotSupported);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  BroadcastChannelProvider_ConnectToChannel_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BroadcastChannelProvider_ConnectToChannel_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(origin$.Origin, val.origin);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStruct(codec.AssociatedInterfaceNotSupported, val.receiver);
    encoder.encodeStruct(codec.AssociatedInterfaceRequestNotSupported, val.sender);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kBroadcastChannelClient_OnMessage_Name = 0;

  function BroadcastChannelClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(BroadcastChannelClient,
                                                   handleOrPtrInfo);
  }

  function BroadcastChannelClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  BroadcastChannelClientPtr.prototype.onMessage = function() {
    return BroadcastChannelClientProxy.prototype.onMessage
        .apply(this.ptr.getProxy(), arguments);
  };

  BroadcastChannelClientProxy.prototype.onMessage = function(message) {
    var params = new BroadcastChannelClient_OnMessage_Params();
    params.message = message;
    var builder = new codec.MessageBuilder(
        kBroadcastChannelClient_OnMessage_Name,
        codec.align(BroadcastChannelClient_OnMessage_Params.encodedSize));
    builder.encodeStruct(BroadcastChannelClient_OnMessage_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function BroadcastChannelClientStub(delegate) {
    this.delegate_ = delegate;
  }
  BroadcastChannelClientStub.prototype.onMessage = function(message) {
    return this.delegate_ && this.delegate_.onMessage && this.delegate_.onMessage(message);
  }

  BroadcastChannelClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kBroadcastChannelClient_OnMessage_Name:
      var params = reader.decodeStruct(BroadcastChannelClient_OnMessage_Params);
      this.onMessage(params.message);
      return true;
    default:
      return false;
    }
  };

  BroadcastChannelClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateBroadcastChannelClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kBroadcastChannelClient_OnMessage_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = BroadcastChannelClient_OnMessage_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateBroadcastChannelClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var BroadcastChannelClient = {
    name: 'blink::mojom::BroadcastChannelClient',
    ptrClass: BroadcastChannelClientPtr,
    proxyClass: BroadcastChannelClientProxy,
    stubClass: BroadcastChannelClientStub,
    validateRequest: validateBroadcastChannelClientRequest,
    validateResponse: null,
  };
  BroadcastChannelClientStub.prototype.validator = validateBroadcastChannelClientRequest;
  BroadcastChannelClientProxy.prototype.validator = null;
  var kBroadcastChannelProvider_ConnectToChannel_Name = 0;

  function BroadcastChannelProviderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(BroadcastChannelProvider,
                                                   handleOrPtrInfo);
  }

  function BroadcastChannelProviderProxy(receiver) {
    this.receiver_ = receiver;
  }
  BroadcastChannelProviderPtr.prototype.connectToChannel = function() {
    return BroadcastChannelProviderProxy.prototype.connectToChannel
        .apply(this.ptr.getProxy(), arguments);
  };

  BroadcastChannelProviderProxy.prototype.connectToChannel = function(origin, name, receiver, sender) {
    var params = new BroadcastChannelProvider_ConnectToChannel_Params();
    params.origin = origin;
    params.name = name;
    params.receiver = receiver;
    params.sender = sender;
    var builder = new codec.MessageBuilder(
        kBroadcastChannelProvider_ConnectToChannel_Name,
        codec.align(BroadcastChannelProvider_ConnectToChannel_Params.encodedSize));
    builder.encodeStruct(BroadcastChannelProvider_ConnectToChannel_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function BroadcastChannelProviderStub(delegate) {
    this.delegate_ = delegate;
  }
  BroadcastChannelProviderStub.prototype.connectToChannel = function(origin, name, receiver, sender) {
    return this.delegate_ && this.delegate_.connectToChannel && this.delegate_.connectToChannel(origin, name, receiver, sender);
  }

  BroadcastChannelProviderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kBroadcastChannelProvider_ConnectToChannel_Name:
      var params = reader.decodeStruct(BroadcastChannelProvider_ConnectToChannel_Params);
      this.connectToChannel(params.origin, params.name, params.receiver, params.sender);
      return true;
    default:
      return false;
    }
  };

  BroadcastChannelProviderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateBroadcastChannelProviderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kBroadcastChannelProvider_ConnectToChannel_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = BroadcastChannelProvider_ConnectToChannel_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateBroadcastChannelProviderResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var BroadcastChannelProvider = {
    name: 'blink::mojom::BroadcastChannelProvider',
    ptrClass: BroadcastChannelProviderPtr,
    proxyClass: BroadcastChannelProviderProxy,
    stubClass: BroadcastChannelProviderStub,
    validateRequest: validateBroadcastChannelProviderRequest,
    validateResponse: null,
  };
  BroadcastChannelProviderStub.prototype.validator = validateBroadcastChannelProviderRequest;
  BroadcastChannelProviderProxy.prototype.validator = null;

  var exports = {};
  exports.BroadcastChannelClient = BroadcastChannelClient;
  exports.BroadcastChannelClientPtr = BroadcastChannelClientPtr;
  exports.BroadcastChannelProvider = BroadcastChannelProvider;
  exports.BroadcastChannelProviderPtr = BroadcastChannelProviderPtr;

  return exports;
});
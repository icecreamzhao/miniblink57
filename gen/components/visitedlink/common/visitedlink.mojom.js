// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/visitedlink/common/visitedlink.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function VisitedLinkNotificationSink_UpdateVisitedLinks_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VisitedLinkNotificationSink_UpdateVisitedLinks_Params.prototype.initDefaults_ = function() {
    this.table_handle = null;
  };
  VisitedLinkNotificationSink_UpdateVisitedLinks_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VisitedLinkNotificationSink_UpdateVisitedLinks_Params.validate = function(messageValidator, offset) {
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


    
    // validate VisitedLinkNotificationSink_UpdateVisitedLinks_Params.table_handle
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VisitedLinkNotificationSink_UpdateVisitedLinks_Params.encodedSize = codec.kStructHeaderSize + 8;

  VisitedLinkNotificationSink_UpdateVisitedLinks_Params.decode = function(decoder) {
    var packed;
    var val = new VisitedLinkNotificationSink_UpdateVisitedLinks_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.table_handle = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VisitedLinkNotificationSink_UpdateVisitedLinks_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VisitedLinkNotificationSink_UpdateVisitedLinks_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.table_handle);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VisitedLinkNotificationSink_AddVisitedLinks_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VisitedLinkNotificationSink_AddVisitedLinks_Params.prototype.initDefaults_ = function() {
    this.link_hashes = null;
  };
  VisitedLinkNotificationSink_AddVisitedLinks_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VisitedLinkNotificationSink_AddVisitedLinks_Params.validate = function(messageValidator, offset) {
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


    
    // validate VisitedLinkNotificationSink_AddVisitedLinks_Params.link_hashes
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, codec.Uint64, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VisitedLinkNotificationSink_AddVisitedLinks_Params.encodedSize = codec.kStructHeaderSize + 8;

  VisitedLinkNotificationSink_AddVisitedLinks_Params.decode = function(decoder) {
    var packed;
    var val = new VisitedLinkNotificationSink_AddVisitedLinks_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.link_hashes = decoder.decodeArrayPointer(codec.Uint64);
    return val;
  };

  VisitedLinkNotificationSink_AddVisitedLinks_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VisitedLinkNotificationSink_AddVisitedLinks_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint64, val.link_hashes);
  };
  function VisitedLinkNotificationSink_ResetVisitedLinks_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VisitedLinkNotificationSink_ResetVisitedLinks_Params.prototype.initDefaults_ = function() {
    this.invalidate_cached_hashes = false;
  };
  VisitedLinkNotificationSink_ResetVisitedLinks_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VisitedLinkNotificationSink_ResetVisitedLinks_Params.validate = function(messageValidator, offset) {
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

  VisitedLinkNotificationSink_ResetVisitedLinks_Params.encodedSize = codec.kStructHeaderSize + 8;

  VisitedLinkNotificationSink_ResetVisitedLinks_Params.decode = function(decoder) {
    var packed;
    var val = new VisitedLinkNotificationSink_ResetVisitedLinks_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.invalidate_cached_hashes = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VisitedLinkNotificationSink_ResetVisitedLinks_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VisitedLinkNotificationSink_ResetVisitedLinks_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.invalidate_cached_hashes & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kVisitedLinkNotificationSink_UpdateVisitedLinks_Name = 0;
  var kVisitedLinkNotificationSink_AddVisitedLinks_Name = 1;
  var kVisitedLinkNotificationSink_ResetVisitedLinks_Name = 2;

  function VisitedLinkNotificationSinkPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VisitedLinkNotificationSink,
                                                   handleOrPtrInfo);
  }

  function VisitedLinkNotificationSinkProxy(receiver) {
    this.receiver_ = receiver;
  }
  VisitedLinkNotificationSinkPtr.prototype.updateVisitedLinks = function() {
    return VisitedLinkNotificationSinkProxy.prototype.updateVisitedLinks
        .apply(this.ptr.getProxy(), arguments);
  };

  VisitedLinkNotificationSinkProxy.prototype.updateVisitedLinks = function(table_handle) {
    var params = new VisitedLinkNotificationSink_UpdateVisitedLinks_Params();
    params.table_handle = table_handle;
    var builder = new codec.MessageBuilder(
        kVisitedLinkNotificationSink_UpdateVisitedLinks_Name,
        codec.align(VisitedLinkNotificationSink_UpdateVisitedLinks_Params.encodedSize));
    builder.encodeStruct(VisitedLinkNotificationSink_UpdateVisitedLinks_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VisitedLinkNotificationSinkPtr.prototype.addVisitedLinks = function() {
    return VisitedLinkNotificationSinkProxy.prototype.addVisitedLinks
        .apply(this.ptr.getProxy(), arguments);
  };

  VisitedLinkNotificationSinkProxy.prototype.addVisitedLinks = function(link_hashes) {
    var params = new VisitedLinkNotificationSink_AddVisitedLinks_Params();
    params.link_hashes = link_hashes;
    var builder = new codec.MessageBuilder(
        kVisitedLinkNotificationSink_AddVisitedLinks_Name,
        codec.align(VisitedLinkNotificationSink_AddVisitedLinks_Params.encodedSize));
    builder.encodeStruct(VisitedLinkNotificationSink_AddVisitedLinks_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VisitedLinkNotificationSinkPtr.prototype.resetVisitedLinks = function() {
    return VisitedLinkNotificationSinkProxy.prototype.resetVisitedLinks
        .apply(this.ptr.getProxy(), arguments);
  };

  VisitedLinkNotificationSinkProxy.prototype.resetVisitedLinks = function(invalidate_cached_hashes) {
    var params = new VisitedLinkNotificationSink_ResetVisitedLinks_Params();
    params.invalidate_cached_hashes = invalidate_cached_hashes;
    var builder = new codec.MessageBuilder(
        kVisitedLinkNotificationSink_ResetVisitedLinks_Name,
        codec.align(VisitedLinkNotificationSink_ResetVisitedLinks_Params.encodedSize));
    builder.encodeStruct(VisitedLinkNotificationSink_ResetVisitedLinks_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function VisitedLinkNotificationSinkStub(delegate) {
    this.delegate_ = delegate;
  }
  VisitedLinkNotificationSinkStub.prototype.updateVisitedLinks = function(table_handle) {
    return this.delegate_ && this.delegate_.updateVisitedLinks && this.delegate_.updateVisitedLinks(table_handle);
  }
  VisitedLinkNotificationSinkStub.prototype.addVisitedLinks = function(link_hashes) {
    return this.delegate_ && this.delegate_.addVisitedLinks && this.delegate_.addVisitedLinks(link_hashes);
  }
  VisitedLinkNotificationSinkStub.prototype.resetVisitedLinks = function(invalidate_cached_hashes) {
    return this.delegate_ && this.delegate_.resetVisitedLinks && this.delegate_.resetVisitedLinks(invalidate_cached_hashes);
  }

  VisitedLinkNotificationSinkStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVisitedLinkNotificationSink_UpdateVisitedLinks_Name:
      var params = reader.decodeStruct(VisitedLinkNotificationSink_UpdateVisitedLinks_Params);
      this.updateVisitedLinks(params.table_handle);
      return true;
    case kVisitedLinkNotificationSink_AddVisitedLinks_Name:
      var params = reader.decodeStruct(VisitedLinkNotificationSink_AddVisitedLinks_Params);
      this.addVisitedLinks(params.link_hashes);
      return true;
    case kVisitedLinkNotificationSink_ResetVisitedLinks_Name:
      var params = reader.decodeStruct(VisitedLinkNotificationSink_ResetVisitedLinks_Params);
      this.resetVisitedLinks(params.invalidate_cached_hashes);
      return true;
    default:
      return false;
    }
  };

  VisitedLinkNotificationSinkStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVisitedLinkNotificationSinkRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVisitedLinkNotificationSink_UpdateVisitedLinks_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VisitedLinkNotificationSink_UpdateVisitedLinks_Params;
      break;
      case kVisitedLinkNotificationSink_AddVisitedLinks_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VisitedLinkNotificationSink_AddVisitedLinks_Params;
      break;
      case kVisitedLinkNotificationSink_ResetVisitedLinks_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VisitedLinkNotificationSink_ResetVisitedLinks_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVisitedLinkNotificationSinkResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var VisitedLinkNotificationSink = {
    name: 'visitedlink::mojom::VisitedLinkNotificationSink',
    ptrClass: VisitedLinkNotificationSinkPtr,
    proxyClass: VisitedLinkNotificationSinkProxy,
    stubClass: VisitedLinkNotificationSinkStub,
    validateRequest: validateVisitedLinkNotificationSinkRequest,
    validateResponse: null,
  };
  VisitedLinkNotificationSinkStub.prototype.validator = validateVisitedLinkNotificationSinkRequest;
  VisitedLinkNotificationSinkProxy.prototype.validator = null;

  var exports = {};
  exports.VisitedLinkNotificationSink = VisitedLinkNotificationSink;
  exports.VisitedLinkNotificationSinkPtr = VisitedLinkNotificationSinkPtr;

  return exports;
});
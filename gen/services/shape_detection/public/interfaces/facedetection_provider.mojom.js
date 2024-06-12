// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/shape_detection/public/interfaces/facedetection_provider.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/shape_detection/public/interfaces/facedetection.mojom",
], function(bindings, codec, core, validator, facedetection$) {

  function FaceDetectionProvider_CreateFaceDetection_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FaceDetectionProvider_CreateFaceDetection_Params.prototype.initDefaults_ = function() {
    this.request = new bindings.InterfaceRequest();
    this.options = null;
  };
  FaceDetectionProvider_CreateFaceDetection_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FaceDetectionProvider_CreateFaceDetection_Params.validate = function(messageValidator, offset) {
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


    
    // validate FaceDetectionProvider_CreateFaceDetection_Params.request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FaceDetectionProvider_CreateFaceDetection_Params.options
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, facedetection$.FaceDetectorOptions, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FaceDetectionProvider_CreateFaceDetection_Params.encodedSize = codec.kStructHeaderSize + 16;

  FaceDetectionProvider_CreateFaceDetection_Params.decode = function(decoder) {
    var packed;
    var val = new FaceDetectionProvider_CreateFaceDetection_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.options = decoder.decodeStructPointer(facedetection$.FaceDetectorOptions);
    return val;
  };

  FaceDetectionProvider_CreateFaceDetection_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FaceDetectionProvider_CreateFaceDetection_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(facedetection$.FaceDetectorOptions, val.options);
  };
  var kFaceDetectionProvider_CreateFaceDetection_Name = 0;

  function FaceDetectionProviderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(FaceDetectionProvider,
                                                   handleOrPtrInfo);
  }

  function FaceDetectionProviderProxy(receiver) {
    this.receiver_ = receiver;
  }
  FaceDetectionProviderPtr.prototype.createFaceDetection = function() {
    return FaceDetectionProviderProxy.prototype.createFaceDetection
        .apply(this.ptr.getProxy(), arguments);
  };

  FaceDetectionProviderProxy.prototype.createFaceDetection = function(request, options) {
    var params = new FaceDetectionProvider_CreateFaceDetection_Params();
    params.request = request;
    params.options = options;
    var builder = new codec.MessageBuilder(
        kFaceDetectionProvider_CreateFaceDetection_Name,
        codec.align(FaceDetectionProvider_CreateFaceDetection_Params.encodedSize));
    builder.encodeStruct(FaceDetectionProvider_CreateFaceDetection_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function FaceDetectionProviderStub(delegate) {
    this.delegate_ = delegate;
  }
  FaceDetectionProviderStub.prototype.createFaceDetection = function(request, options) {
    return this.delegate_ && this.delegate_.createFaceDetection && this.delegate_.createFaceDetection(request, options);
  }

  FaceDetectionProviderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kFaceDetectionProvider_CreateFaceDetection_Name:
      var params = reader.decodeStruct(FaceDetectionProvider_CreateFaceDetection_Params);
      this.createFaceDetection(params.request, params.options);
      return true;
    default:
      return false;
    }
  };

  FaceDetectionProviderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateFaceDetectionProviderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kFaceDetectionProvider_CreateFaceDetection_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = FaceDetectionProvider_CreateFaceDetection_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateFaceDetectionProviderResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var FaceDetectionProvider = {
    name: 'shape_detection::mojom::FaceDetectionProvider',
    ptrClass: FaceDetectionProviderPtr,
    proxyClass: FaceDetectionProviderProxy,
    stubClass: FaceDetectionProviderStub,
    validateRequest: validateFaceDetectionProviderRequest,
    validateResponse: null,
  };
  FaceDetectionProviderStub.prototype.validator = validateFaceDetectionProviderRequest;
  FaceDetectionProviderProxy.prototype.validator = null;

  var exports = {};
  exports.FaceDetectionProvider = FaceDetectionProvider;
  exports.FaceDetectionProviderPtr = FaceDetectionProviderPtr;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/shape_detection/public/interfaces/facedetection.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, geometry$) {

  function FaceDetectionResult(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FaceDetectionResult.prototype.initDefaults_ = function() {
    this.bounding_boxes = null;
  };
  FaceDetectionResult.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FaceDetectionResult.validate = function(messageValidator, offset) {
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


    
    // validate FaceDetectionResult.bounding_boxes
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(geometry$.RectF), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FaceDetectionResult.encodedSize = codec.kStructHeaderSize + 8;

  FaceDetectionResult.decode = function(decoder) {
    var packed;
    var val = new FaceDetectionResult();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.bounding_boxes = decoder.decodeArrayPointer(new codec.PointerTo(geometry$.RectF));
    return val;
  };

  FaceDetectionResult.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FaceDetectionResult.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(geometry$.RectF), val.bounding_boxes);
  };
  function FaceDetectorOptions(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FaceDetectorOptions.prototype.initDefaults_ = function() {
    this.max_detected_faces = 0;
    this.fast_mode = false;
  };
  FaceDetectorOptions.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FaceDetectorOptions.validate = function(messageValidator, offset) {
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

  FaceDetectorOptions.encodedSize = codec.kStructHeaderSize + 8;

  FaceDetectorOptions.decode = function(decoder) {
    var packed;
    var val = new FaceDetectorOptions();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.max_detected_faces = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.fast_mode = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FaceDetectorOptions.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FaceDetectorOptions.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.max_detected_faces);
    packed = 0;
    packed |= (val.fast_mode & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FaceDetection_Detect_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FaceDetection_Detect_Params.prototype.initDefaults_ = function() {
    this.frame_data = null;
    this.width = 0;
    this.height = 0;
  };
  FaceDetection_Detect_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FaceDetection_Detect_Params.validate = function(messageValidator, offset) {
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


    
    // validate FaceDetection_Detect_Params.frame_data
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  FaceDetection_Detect_Params.encodedSize = codec.kStructHeaderSize + 16;

  FaceDetection_Detect_Params.decode = function(decoder) {
    var packed;
    var val = new FaceDetection_Detect_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.frame_data = decoder.decodeStruct(codec.Handle);
    val.width = decoder.decodeStruct(codec.Uint32);
    val.height = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  FaceDetection_Detect_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FaceDetection_Detect_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.frame_data);
    encoder.encodeStruct(codec.Uint32, val.width);
    encoder.encodeStruct(codec.Uint32, val.height);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function FaceDetection_Detect_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FaceDetection_Detect_ResponseParams.prototype.initDefaults_ = function() {
    this.result = null;
  };
  FaceDetection_Detect_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FaceDetection_Detect_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate FaceDetection_Detect_ResponseParams.result
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, FaceDetectionResult, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FaceDetection_Detect_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  FaceDetection_Detect_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new FaceDetection_Detect_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStructPointer(FaceDetectionResult);
    return val;
  };

  FaceDetection_Detect_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FaceDetection_Detect_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(FaceDetectionResult, val.result);
  };
  var kFaceDetection_Detect_Name = 0;

  function FaceDetectionPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(FaceDetection,
                                                   handleOrPtrInfo);
  }

  function FaceDetectionProxy(receiver) {
    this.receiver_ = receiver;
  }
  FaceDetectionPtr.prototype.detect = function() {
    return FaceDetectionProxy.prototype.detect
        .apply(this.ptr.getProxy(), arguments);
  };

  FaceDetectionProxy.prototype.detect = function(frame_data, width, height) {
    var params = new FaceDetection_Detect_Params();
    params.frame_data = frame_data;
    params.width = width;
    params.height = height;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kFaceDetection_Detect_Name,
          codec.align(FaceDetection_Detect_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(FaceDetection_Detect_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(FaceDetection_Detect_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function FaceDetectionStub(delegate) {
    this.delegate_ = delegate;
  }
  FaceDetectionStub.prototype.detect = function(frame_data, width, height) {
    return this.delegate_ && this.delegate_.detect && this.delegate_.detect(frame_data, width, height);
  }

  FaceDetectionStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  FaceDetectionStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kFaceDetection_Detect_Name:
      var params = reader.decodeStruct(FaceDetection_Detect_Params);
      return this.detect(params.frame_data, params.width, params.height).then(function(response) {
        var responseParams =
            new FaceDetection_Detect_ResponseParams();
        responseParams.result = response.result;
        var builder = new codec.MessageWithRequestIDBuilder(
            kFaceDetection_Detect_Name,
            codec.align(FaceDetection_Detect_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(FaceDetection_Detect_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateFaceDetectionRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kFaceDetection_Detect_Name:
        if (message.expectsResponse())
          paramsClass = FaceDetection_Detect_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateFaceDetectionResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kFaceDetection_Detect_Name:
        if (message.isResponse())
          paramsClass = FaceDetection_Detect_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var FaceDetection = {
    name: 'shape_detection::mojom::FaceDetection',
    ptrClass: FaceDetectionPtr,
    proxyClass: FaceDetectionProxy,
    stubClass: FaceDetectionStub,
    validateRequest: validateFaceDetectionRequest,
    validateResponse: validateFaceDetectionResponse,
  };
  FaceDetectionStub.prototype.validator = validateFaceDetectionRequest;
  FaceDetectionProxy.prototype.validator = validateFaceDetectionResponse;

  var exports = {};
  exports.FaceDetectionResult = FaceDetectionResult;
  exports.FaceDetectorOptions = FaceDetectorOptions;
  exports.FaceDetection = FaceDetection;
  exports.FaceDetectionPtr = FaceDetectionPtr;

  return exports;
});
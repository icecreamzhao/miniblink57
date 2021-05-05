// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/shape_detection/public/interfaces/barcodedetection.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, geometry$) {

  function BarcodeDetectionResult(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BarcodeDetectionResult.prototype.initDefaults_ = function() {
    this.raw_value = null;
    this.bounding_box = null;
    this.corner_points = null;
  };
  BarcodeDetectionResult.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BarcodeDetectionResult.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 32}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BarcodeDetectionResult.raw_value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BarcodeDetectionResult.bounding_box
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate BarcodeDetectionResult.corner_points
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(geometry$.PointF), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BarcodeDetectionResult.encodedSize = codec.kStructHeaderSize + 24;

  BarcodeDetectionResult.decode = function(decoder) {
    var packed;
    var val = new BarcodeDetectionResult();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.raw_value = decoder.decodeStruct(codec.String);
    val.bounding_box = decoder.decodeStructPointer(geometry$.RectF);
    val.corner_points = decoder.decodeArrayPointer(new codec.PointerTo(geometry$.PointF));
    return val;
  };

  BarcodeDetectionResult.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BarcodeDetectionResult.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.raw_value);
    encoder.encodeStructPointer(geometry$.RectF, val.bounding_box);
    encoder.encodeArrayPointer(new codec.PointerTo(geometry$.PointF), val.corner_points);
  };
  function BarcodeDetection_Detect_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BarcodeDetection_Detect_Params.prototype.initDefaults_ = function() {
    this.frame_data = null;
    this.width = 0;
    this.height = 0;
  };
  BarcodeDetection_Detect_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BarcodeDetection_Detect_Params.validate = function(messageValidator, offset) {
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


    
    // validate BarcodeDetection_Detect_Params.frame_data
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  BarcodeDetection_Detect_Params.encodedSize = codec.kStructHeaderSize + 16;

  BarcodeDetection_Detect_Params.decode = function(decoder) {
    var packed;
    var val = new BarcodeDetection_Detect_Params();
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

  BarcodeDetection_Detect_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BarcodeDetection_Detect_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.frame_data);
    encoder.encodeStruct(codec.Uint32, val.width);
    encoder.encodeStruct(codec.Uint32, val.height);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function BarcodeDetection_Detect_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  BarcodeDetection_Detect_ResponseParams.prototype.initDefaults_ = function() {
    this.results = null;
  };
  BarcodeDetection_Detect_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  BarcodeDetection_Detect_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate BarcodeDetection_Detect_ResponseParams.results
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(BarcodeDetectionResult), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  BarcodeDetection_Detect_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  BarcodeDetection_Detect_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new BarcodeDetection_Detect_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.results = decoder.decodeArrayPointer(new codec.PointerTo(BarcodeDetectionResult));
    return val;
  };

  BarcodeDetection_Detect_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(BarcodeDetection_Detect_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(BarcodeDetectionResult), val.results);
  };
  var kBarcodeDetection_Detect_Name = 0;

  function BarcodeDetectionPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(BarcodeDetection,
                                                   handleOrPtrInfo);
  }

  function BarcodeDetectionProxy(receiver) {
    this.receiver_ = receiver;
  }
  BarcodeDetectionPtr.prototype.detect = function() {
    return BarcodeDetectionProxy.prototype.detect
        .apply(this.ptr.getProxy(), arguments);
  };

  BarcodeDetectionProxy.prototype.detect = function(frame_data, width, height) {
    var params = new BarcodeDetection_Detect_Params();
    params.frame_data = frame_data;
    params.width = width;
    params.height = height;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kBarcodeDetection_Detect_Name,
          codec.align(BarcodeDetection_Detect_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(BarcodeDetection_Detect_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(BarcodeDetection_Detect_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function BarcodeDetectionStub(delegate) {
    this.delegate_ = delegate;
  }
  BarcodeDetectionStub.prototype.detect = function(frame_data, width, height) {
    return this.delegate_ && this.delegate_.detect && this.delegate_.detect(frame_data, width, height);
  }

  BarcodeDetectionStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  BarcodeDetectionStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kBarcodeDetection_Detect_Name:
      var params = reader.decodeStruct(BarcodeDetection_Detect_Params);
      return this.detect(params.frame_data, params.width, params.height).then(function(response) {
        var responseParams =
            new BarcodeDetection_Detect_ResponseParams();
        responseParams.results = response.results;
        var builder = new codec.MessageWithRequestIDBuilder(
            kBarcodeDetection_Detect_Name,
            codec.align(BarcodeDetection_Detect_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(BarcodeDetection_Detect_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateBarcodeDetectionRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kBarcodeDetection_Detect_Name:
        if (message.expectsResponse())
          paramsClass = BarcodeDetection_Detect_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateBarcodeDetectionResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kBarcodeDetection_Detect_Name:
        if (message.isResponse())
          paramsClass = BarcodeDetection_Detect_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var BarcodeDetection = {
    name: 'shape_detection::mojom::BarcodeDetection',
    ptrClass: BarcodeDetectionPtr,
    proxyClass: BarcodeDetectionProxy,
    stubClass: BarcodeDetectionStub,
    validateRequest: validateBarcodeDetectionRequest,
    validateResponse: validateBarcodeDetectionResponse,
  };
  BarcodeDetectionStub.prototype.validator = validateBarcodeDetectionRequest;
  BarcodeDetectionProxy.prototype.validator = validateBarcodeDetectionResponse;

  var exports = {};
  exports.BarcodeDetectionResult = BarcodeDetectionResult;
  exports.BarcodeDetection = BarcodeDetection;
  exports.BarcodeDetectionPtr = BarcodeDetectionPtr;

  return exports;
});
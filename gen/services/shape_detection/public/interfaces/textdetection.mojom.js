// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/shape_detection/public/interfaces/textdetection.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, geometry$) {

  function TextDetectionResult(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextDetectionResult.prototype.initDefaults_ = function() {
    this.raw_value = null;
    this.bounding_box = null;
  };
  TextDetectionResult.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextDetectionResult.validate = function(messageValidator, offset) {
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


    
    // validate TextDetectionResult.raw_value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate TextDetectionResult.bounding_box
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TextDetectionResult.encodedSize = codec.kStructHeaderSize + 16;

  TextDetectionResult.decode = function(decoder) {
    var packed;
    var val = new TextDetectionResult();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.raw_value = decoder.decodeStruct(codec.String);
    val.bounding_box = decoder.decodeStructPointer(geometry$.RectF);
    return val;
  };

  TextDetectionResult.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextDetectionResult.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.raw_value);
    encoder.encodeStructPointer(geometry$.RectF, val.bounding_box);
  };
  function TextDetection_Detect_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextDetection_Detect_Params.prototype.initDefaults_ = function() {
    this.frame_data = null;
    this.width = 0;
    this.height = 0;
  };
  TextDetection_Detect_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextDetection_Detect_Params.validate = function(messageValidator, offset) {
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


    
    // validate TextDetection_Detect_Params.frame_data
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  TextDetection_Detect_Params.encodedSize = codec.kStructHeaderSize + 16;

  TextDetection_Detect_Params.decode = function(decoder) {
    var packed;
    var val = new TextDetection_Detect_Params();
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

  TextDetection_Detect_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextDetection_Detect_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Handle, val.frame_data);
    encoder.encodeStruct(codec.Uint32, val.width);
    encoder.encodeStruct(codec.Uint32, val.height);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function TextDetection_Detect_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextDetection_Detect_ResponseParams.prototype.initDefaults_ = function() {
    this.results = null;
  };
  TextDetection_Detect_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextDetection_Detect_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate TextDetection_Detect_ResponseParams.results
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(TextDetectionResult), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TextDetection_Detect_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  TextDetection_Detect_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new TextDetection_Detect_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.results = decoder.decodeArrayPointer(new codec.PointerTo(TextDetectionResult));
    return val;
  };

  TextDetection_Detect_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextDetection_Detect_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(TextDetectionResult), val.results);
  };
  var kTextDetection_Detect_Name = 0;

  function TextDetectionPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(TextDetection,
                                                   handleOrPtrInfo);
  }

  function TextDetectionProxy(receiver) {
    this.receiver_ = receiver;
  }
  TextDetectionPtr.prototype.detect = function() {
    return TextDetectionProxy.prototype.detect
        .apply(this.ptr.getProxy(), arguments);
  };

  TextDetectionProxy.prototype.detect = function(frame_data, width, height) {
    var params = new TextDetection_Detect_Params();
    params.frame_data = frame_data;
    params.width = width;
    params.height = height;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kTextDetection_Detect_Name,
          codec.align(TextDetection_Detect_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(TextDetection_Detect_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(TextDetection_Detect_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function TextDetectionStub(delegate) {
    this.delegate_ = delegate;
  }
  TextDetectionStub.prototype.detect = function(frame_data, width, height) {
    return this.delegate_ && this.delegate_.detect && this.delegate_.detect(frame_data, width, height);
  }

  TextDetectionStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  TextDetectionStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kTextDetection_Detect_Name:
      var params = reader.decodeStruct(TextDetection_Detect_Params);
      return this.detect(params.frame_data, params.width, params.height).then(function(response) {
        var responseParams =
            new TextDetection_Detect_ResponseParams();
        responseParams.results = response.results;
        var builder = new codec.MessageWithRequestIDBuilder(
            kTextDetection_Detect_Name,
            codec.align(TextDetection_Detect_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(TextDetection_Detect_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateTextDetectionRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kTextDetection_Detect_Name:
        if (message.expectsResponse())
          paramsClass = TextDetection_Detect_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateTextDetectionResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kTextDetection_Detect_Name:
        if (message.isResponse())
          paramsClass = TextDetection_Detect_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var TextDetection = {
    name: 'shape_detection::mojom::TextDetection',
    ptrClass: TextDetectionPtr,
    proxyClass: TextDetectionProxy,
    stubClass: TextDetectionStub,
    validateRequest: validateTextDetectionRequest,
    validateResponse: validateTextDetectionResponse,
  };
  TextDetectionStub.prototype.validator = validateTextDetectionRequest;
  TextDetectionProxy.prototype.validator = validateTextDetectionResponse;

  var exports = {};
  exports.TextDetectionResult = TextDetectionResult;
  exports.TextDetection = TextDetection;
  exports.TextDetectionPtr = TextDetectionPtr;

  return exports;
});
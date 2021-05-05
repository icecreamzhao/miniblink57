// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/vr/vr_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var VRDisplayEventReason = {};
  VRDisplayEventReason.NONE = 0;
  VRDisplayEventReason.NAVIGATION = 1;
  VRDisplayEventReason.MOUNTED = 2;
  VRDisplayEventReason.UNMOUNTED = 3;

  VRDisplayEventReason.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  VRDisplayEventReason.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function VRFieldOfView(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRFieldOfView.prototype.initDefaults_ = function() {
    this.upDegrees = 0;
    this.downDegrees = 0;
    this.leftDegrees = 0;
    this.rightDegrees = 0;
  };
  VRFieldOfView.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRFieldOfView.validate = function(messageValidator, offset) {
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





    return validator.validationError.NONE;
  };

  VRFieldOfView.encodedSize = codec.kStructHeaderSize + 16;

  VRFieldOfView.decode = function(decoder) {
    var packed;
    var val = new VRFieldOfView();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.upDegrees = decoder.decodeStruct(codec.Float);
    val.downDegrees = decoder.decodeStruct(codec.Float);
    val.leftDegrees = decoder.decodeStruct(codec.Float);
    val.rightDegrees = decoder.decodeStruct(codec.Float);
    return val;
  };

  VRFieldOfView.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRFieldOfView.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.upDegrees);
    encoder.encodeStruct(codec.Float, val.downDegrees);
    encoder.encodeStruct(codec.Float, val.leftDegrees);
    encoder.encodeStruct(codec.Float, val.rightDegrees);
  };
  function VRPose(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRPose.prototype.initDefaults_ = function() {
    this.timestamp = 0;
    this.orientation = null;
    this.position = null;
    this.angularVelocity = null;
    this.linearVelocity = null;
    this.angularAcceleration = null;
    this.linearAcceleration = null;
    this.poseIndex = 0;
  };
  VRPose.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRPose.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 72}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate VRPose.orientation
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 4, codec.Float, true, [4], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRPose.position
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 4, codec.Float, true, [3], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRPose.angularVelocity
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 24, 4, codec.Float, true, [3], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRPose.linearVelocity
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 32, 4, codec.Float, true, [3], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRPose.angularAcceleration
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 40, 4, codec.Float, true, [3], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRPose.linearAcceleration
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 48, 4, codec.Float, true, [3], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  VRPose.encodedSize = codec.kStructHeaderSize + 64;

  VRPose.decode = function(decoder) {
    var packed;
    var val = new VRPose();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.timestamp = decoder.decodeStruct(codec.Double);
    val.orientation = decoder.decodeArrayPointer(codec.Float);
    val.position = decoder.decodeArrayPointer(codec.Float);
    val.angularVelocity = decoder.decodeArrayPointer(codec.Float);
    val.linearVelocity = decoder.decodeArrayPointer(codec.Float);
    val.angularAcceleration = decoder.decodeArrayPointer(codec.Float);
    val.linearAcceleration = decoder.decodeArrayPointer(codec.Float);
    val.poseIndex = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRPose.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRPose.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Double, val.timestamp);
    encoder.encodeArrayPointer(codec.Float, val.orientation);
    encoder.encodeArrayPointer(codec.Float, val.position);
    encoder.encodeArrayPointer(codec.Float, val.angularVelocity);
    encoder.encodeArrayPointer(codec.Float, val.linearVelocity);
    encoder.encodeArrayPointer(codec.Float, val.angularAcceleration);
    encoder.encodeArrayPointer(codec.Float, val.linearAcceleration);
    encoder.encodeStruct(codec.Uint32, val.poseIndex);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VRDisplayCapabilities(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayCapabilities.prototype.initDefaults_ = function() {
    this.hasOrientation = false;
    this.hasPosition = false;
    this.hasExternalDisplay = false;
    this.canPresent = false;
  };
  VRDisplayCapabilities.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayCapabilities.validate = function(messageValidator, offset) {
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

  VRDisplayCapabilities.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplayCapabilities.decode = function(decoder) {
    var packed;
    var val = new VRDisplayCapabilities();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.hasOrientation = (packed >> 0) & 1 ? true : false;
    val.hasPosition = (packed >> 1) & 1 ? true : false;
    val.hasExternalDisplay = (packed >> 2) & 1 ? true : false;
    val.canPresent = (packed >> 3) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRDisplayCapabilities.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayCapabilities.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.hasOrientation & 1) << 0
    packed |= (val.hasPosition & 1) << 1
    packed |= (val.hasExternalDisplay & 1) << 2
    packed |= (val.canPresent & 1) << 3
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VREyeParameters(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VREyeParameters.prototype.initDefaults_ = function() {
    this.fieldOfView = null;
    this.offset = null;
    this.renderWidth = 0;
    this.renderHeight = 0;
  };
  VREyeParameters.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VREyeParameters.validate = function(messageValidator, offset) {
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


    
    // validate VREyeParameters.fieldOfView
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, VRFieldOfView, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VREyeParameters.offset
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 4, codec.Float, false, [3], 0);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  VREyeParameters.encodedSize = codec.kStructHeaderSize + 24;

  VREyeParameters.decode = function(decoder) {
    var packed;
    var val = new VREyeParameters();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.fieldOfView = decoder.decodeStructPointer(VRFieldOfView);
    val.offset = decoder.decodeArrayPointer(codec.Float);
    val.renderWidth = decoder.decodeStruct(codec.Uint32);
    val.renderHeight = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  VREyeParameters.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VREyeParameters.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(VRFieldOfView, val.fieldOfView);
    encoder.encodeArrayPointer(codec.Float, val.offset);
    encoder.encodeStruct(codec.Uint32, val.renderWidth);
    encoder.encodeStruct(codec.Uint32, val.renderHeight);
  };
  function VRStageParameters(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRStageParameters.prototype.initDefaults_ = function() {
    this.standingTransform = null;
    this.sizeX = 0;
    this.sizeZ = 0;
  };
  VRStageParameters.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRStageParameters.validate = function(messageValidator, offset) {
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


    
    // validate VRStageParameters.standingTransform
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 4, codec.Float, false, [16], 0);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  VRStageParameters.encodedSize = codec.kStructHeaderSize + 16;

  VRStageParameters.decode = function(decoder) {
    var packed;
    var val = new VRStageParameters();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.standingTransform = decoder.decodeArrayPointer(codec.Float);
    val.sizeX = decoder.decodeStruct(codec.Float);
    val.sizeZ = decoder.decodeStruct(codec.Float);
    return val;
  };

  VRStageParameters.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRStageParameters.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Float, val.standingTransform);
    encoder.encodeStruct(codec.Float, val.sizeX);
    encoder.encodeStruct(codec.Float, val.sizeZ);
  };
  function VRDisplayInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayInfo.prototype.initDefaults_ = function() {
    this.index = 0;
    this.displayName = null;
    this.capabilities = null;
    this.stageParameters = null;
    this.leftEye = null;
    this.rightEye = null;
  };
  VRDisplayInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayInfo.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 56}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate VRDisplayInfo.displayName
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRDisplayInfo.capabilities
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, VRDisplayCapabilities, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRDisplayInfo.stageParameters
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, VRStageParameters, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRDisplayInfo.leftEye
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, VREyeParameters, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRDisplayInfo.rightEye
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, VREyeParameters, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplayInfo.encodedSize = codec.kStructHeaderSize + 48;

  VRDisplayInfo.decode = function(decoder) {
    var packed;
    var val = new VRDisplayInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.index = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.displayName = decoder.decodeStruct(codec.String);
    val.capabilities = decoder.decodeStructPointer(VRDisplayCapabilities);
    val.stageParameters = decoder.decodeStructPointer(VRStageParameters);
    val.leftEye = decoder.decodeStructPointer(VREyeParameters);
    val.rightEye = decoder.decodeStructPointer(VREyeParameters);
    return val;
  };

  VRDisplayInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.index);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.displayName);
    encoder.encodeStructPointer(VRDisplayCapabilities, val.capabilities);
    encoder.encodeStructPointer(VRStageParameters, val.stageParameters);
    encoder.encodeStructPointer(VREyeParameters, val.leftEye);
    encoder.encodeStructPointer(VREyeParameters, val.rightEye);
  };
  function VRLayerBounds(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRLayerBounds.prototype.initDefaults_ = function() {
    this.left = 0;
    this.top = 0;
    this.width = 0;
    this.height = 0;
  };
  VRLayerBounds.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRLayerBounds.validate = function(messageValidator, offset) {
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





    return validator.validationError.NONE;
  };

  VRLayerBounds.encodedSize = codec.kStructHeaderSize + 16;

  VRLayerBounds.decode = function(decoder) {
    var packed;
    var val = new VRLayerBounds();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.left = decoder.decodeStruct(codec.Float);
    val.top = decoder.decodeStruct(codec.Float);
    val.width = decoder.decodeStruct(codec.Float);
    val.height = decoder.decodeStruct(codec.Float);
    return val;
  };

  VRLayerBounds.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRLayerBounds.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Float, val.left);
    encoder.encodeStruct(codec.Float, val.top);
    encoder.encodeStruct(codec.Float, val.width);
    encoder.encodeStruct(codec.Float, val.height);
  };
  function VRService_SetClient_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRService_SetClient_Params.prototype.initDefaults_ = function() {
    this.client = new VRServiceClientPtr();
  };
  VRService_SetClient_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRService_SetClient_Params.validate = function(messageValidator, offset) {
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


    
    // validate VRService_SetClient_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRService_SetClient_Params.encodedSize = codec.kStructHeaderSize + 8;

  VRService_SetClient_Params.decode = function(decoder) {
    var packed;
    var val = new VRService_SetClient_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(new codec.Interface(VRServiceClientPtr));
    return val;
  };

  VRService_SetClient_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRService_SetClient_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(VRServiceClientPtr), val.client);
  };
  function VRService_SetClient_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRService_SetClient_ResponseParams.prototype.initDefaults_ = function() {
    this.numberOfConnectedDevices = 0;
  };
  VRService_SetClient_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRService_SetClient_ResponseParams.validate = function(messageValidator, offset) {
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

  VRService_SetClient_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  VRService_SetClient_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VRService_SetClient_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.numberOfConnectedDevices = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRService_SetClient_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRService_SetClient_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.numberOfConnectedDevices);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VRService_SetListeningForActivate_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRService_SetListeningForActivate_Params.prototype.initDefaults_ = function() {
    this.listening = false;
  };
  VRService_SetListeningForActivate_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRService_SetListeningForActivate_Params.validate = function(messageValidator, offset) {
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

  VRService_SetListeningForActivate_Params.encodedSize = codec.kStructHeaderSize + 8;

  VRService_SetListeningForActivate_Params.decode = function(decoder) {
    var packed;
    var val = new VRService_SetListeningForActivate_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.listening = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRService_SetListeningForActivate_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRService_SetListeningForActivate_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.listening & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VRServiceClient_OnDisplayConnected_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRServiceClient_OnDisplayConnected_Params.prototype.initDefaults_ = function() {
    this.display = new VRDisplayPtr();
    this.request = new bindings.InterfaceRequest();
    this.displayInfo = null;
  };
  VRServiceClient_OnDisplayConnected_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRServiceClient_OnDisplayConnected_Params.validate = function(messageValidator, offset) {
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


    
    // validate VRServiceClient_OnDisplayConnected_Params.display
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRServiceClient_OnDisplayConnected_Params.request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRServiceClient_OnDisplayConnected_Params.displayInfo
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, VRDisplayInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRServiceClient_OnDisplayConnected_Params.encodedSize = codec.kStructHeaderSize + 24;

  VRServiceClient_OnDisplayConnected_Params.decode = function(decoder) {
    var packed;
    var val = new VRServiceClient_OnDisplayConnected_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.display = decoder.decodeStruct(new codec.Interface(VRDisplayPtr));
    val.request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.displayInfo = decoder.decodeStructPointer(VRDisplayInfo);
    return val;
  };

  VRServiceClient_OnDisplayConnected_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRServiceClient_OnDisplayConnected_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(VRDisplayPtr), val.display);
    encoder.encodeStruct(codec.InterfaceRequest, val.request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(VRDisplayInfo, val.displayInfo);
  };
  function VRDisplay_GetPose_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_GetPose_Params.prototype.initDefaults_ = function() {
  };
  VRDisplay_GetPose_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_GetPose_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplay_GetPose_Params.encodedSize = codec.kStructHeaderSize + 0;

  VRDisplay_GetPose_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_GetPose_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VRDisplay_GetPose_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_GetPose_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VRDisplay_GetPose_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_GetPose_ResponseParams.prototype.initDefaults_ = function() {
    this.pose = null;
  };
  VRDisplay_GetPose_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_GetPose_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate VRDisplay_GetPose_ResponseParams.pose
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, VRPose, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplay_GetPose_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplay_GetPose_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_GetPose_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.pose = decoder.decodeStructPointer(VRPose);
    return val;
  };

  VRDisplay_GetPose_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_GetPose_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(VRPose, val.pose);
  };
  function VRDisplay_ResetPose_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_ResetPose_Params.prototype.initDefaults_ = function() {
  };
  VRDisplay_ResetPose_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_ResetPose_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplay_ResetPose_Params.encodedSize = codec.kStructHeaderSize + 0;

  VRDisplay_ResetPose_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_ResetPose_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VRDisplay_ResetPose_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_ResetPose_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VRDisplay_RequestPresent_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_RequestPresent_Params.prototype.initDefaults_ = function() {
    this.secureOrigin = false;
  };
  VRDisplay_RequestPresent_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_RequestPresent_Params.validate = function(messageValidator, offset) {
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

  VRDisplay_RequestPresent_Params.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplay_RequestPresent_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_RequestPresent_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.secureOrigin = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRDisplay_RequestPresent_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_RequestPresent_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.secureOrigin & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VRDisplay_RequestPresent_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_RequestPresent_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  VRDisplay_RequestPresent_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_RequestPresent_ResponseParams.validate = function(messageValidator, offset) {
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

  VRDisplay_RequestPresent_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplay_RequestPresent_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_RequestPresent_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRDisplay_RequestPresent_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_RequestPresent_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VRDisplay_ExitPresent_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_ExitPresent_Params.prototype.initDefaults_ = function() {
  };
  VRDisplay_ExitPresent_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_ExitPresent_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplay_ExitPresent_Params.encodedSize = codec.kStructHeaderSize + 0;

  VRDisplay_ExitPresent_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_ExitPresent_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VRDisplay_ExitPresent_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_ExitPresent_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VRDisplay_SubmitFrame_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_SubmitFrame_Params.prototype.initDefaults_ = function() {
    this.pose = null;
  };
  VRDisplay_SubmitFrame_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_SubmitFrame_Params.validate = function(messageValidator, offset) {
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


    
    // validate VRDisplay_SubmitFrame_Params.pose
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, VRPose, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplay_SubmitFrame_Params.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplay_SubmitFrame_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_SubmitFrame_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.pose = decoder.decodeStructPointer(VRPose);
    return val;
  };

  VRDisplay_SubmitFrame_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_SubmitFrame_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(VRPose, val.pose);
  };
  function VRDisplay_UpdateLayerBounds_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplay_UpdateLayerBounds_Params.prototype.initDefaults_ = function() {
    this.leftBounds = null;
    this.rightBounds = null;
  };
  VRDisplay_UpdateLayerBounds_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplay_UpdateLayerBounds_Params.validate = function(messageValidator, offset) {
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


    
    // validate VRDisplay_UpdateLayerBounds_Params.leftBounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, VRLayerBounds, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VRDisplay_UpdateLayerBounds_Params.rightBounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, VRLayerBounds, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplay_UpdateLayerBounds_Params.encodedSize = codec.kStructHeaderSize + 16;

  VRDisplay_UpdateLayerBounds_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplay_UpdateLayerBounds_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.leftBounds = decoder.decodeStructPointer(VRLayerBounds);
    val.rightBounds = decoder.decodeStructPointer(VRLayerBounds);
    return val;
  };

  VRDisplay_UpdateLayerBounds_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplay_UpdateLayerBounds_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(VRLayerBounds, val.leftBounds);
    encoder.encodeStructPointer(VRLayerBounds, val.rightBounds);
  };
  function VRDisplayClient_OnChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayClient_OnChanged_Params.prototype.initDefaults_ = function() {
    this.display = null;
  };
  VRDisplayClient_OnChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayClient_OnChanged_Params.validate = function(messageValidator, offset) {
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


    
    // validate VRDisplayClient_OnChanged_Params.display
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, VRDisplayInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplayClient_OnChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplayClient_OnChanged_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplayClient_OnChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.display = decoder.decodeStructPointer(VRDisplayInfo);
    return val;
  };

  VRDisplayClient_OnChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayClient_OnChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(VRDisplayInfo, val.display);
  };
  function VRDisplayClient_OnExitPresent_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayClient_OnExitPresent_Params.prototype.initDefaults_ = function() {
  };
  VRDisplayClient_OnExitPresent_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayClient_OnExitPresent_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplayClient_OnExitPresent_Params.encodedSize = codec.kStructHeaderSize + 0;

  VRDisplayClient_OnExitPresent_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplayClient_OnExitPresent_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VRDisplayClient_OnExitPresent_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayClient_OnExitPresent_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VRDisplayClient_OnBlur_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayClient_OnBlur_Params.prototype.initDefaults_ = function() {
  };
  VRDisplayClient_OnBlur_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayClient_OnBlur_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplayClient_OnBlur_Params.encodedSize = codec.kStructHeaderSize + 0;

  VRDisplayClient_OnBlur_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplayClient_OnBlur_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VRDisplayClient_OnBlur_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayClient_OnBlur_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VRDisplayClient_OnFocus_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayClient_OnFocus_Params.prototype.initDefaults_ = function() {
  };
  VRDisplayClient_OnFocus_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayClient_OnFocus_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 8}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplayClient_OnFocus_Params.encodedSize = codec.kStructHeaderSize + 0;

  VRDisplayClient_OnFocus_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplayClient_OnFocus_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  VRDisplayClient_OnFocus_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayClient_OnFocus_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function VRDisplayClient_OnActivate_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayClient_OnActivate_Params.prototype.initDefaults_ = function() {
    this.reason = 0;
  };
  VRDisplayClient_OnActivate_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayClient_OnActivate_Params.validate = function(messageValidator, offset) {
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


    
    // validate VRDisplayClient_OnActivate_Params.reason
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, VRDisplayEventReason);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplayClient_OnActivate_Params.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplayClient_OnActivate_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplayClient_OnActivate_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.reason = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRDisplayClient_OnActivate_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayClient_OnActivate_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.reason);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VRDisplayClient_OnDeactivate_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VRDisplayClient_OnDeactivate_Params.prototype.initDefaults_ = function() {
    this.reason = 0;
  };
  VRDisplayClient_OnDeactivate_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VRDisplayClient_OnDeactivate_Params.validate = function(messageValidator, offset) {
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


    
    // validate VRDisplayClient_OnDeactivate_Params.reason
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, VRDisplayEventReason);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  VRDisplayClient_OnDeactivate_Params.encodedSize = codec.kStructHeaderSize + 8;

  VRDisplayClient_OnDeactivate_Params.decode = function(decoder) {
    var packed;
    var val = new VRDisplayClient_OnDeactivate_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.reason = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VRDisplayClient_OnDeactivate_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VRDisplayClient_OnDeactivate_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.reason);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kVRService_SetClient_Name = 0;
  var kVRService_SetListeningForActivate_Name = 1;

  function VRServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VRService,
                                                   handleOrPtrInfo);
  }

  function VRServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  VRServicePtr.prototype.setClient = function() {
    return VRServiceProxy.prototype.setClient
        .apply(this.ptr.getProxy(), arguments);
  };

  VRServiceProxy.prototype.setClient = function(client) {
    var params = new VRService_SetClient_Params();
    params.client = client;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVRService_SetClient_Name,
          codec.align(VRService_SetClient_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VRService_SetClient_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VRService_SetClient_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  VRServicePtr.prototype.setListeningForActivate = function() {
    return VRServiceProxy.prototype.setListeningForActivate
        .apply(this.ptr.getProxy(), arguments);
  };

  VRServiceProxy.prototype.setListeningForActivate = function(listening) {
    var params = new VRService_SetListeningForActivate_Params();
    params.listening = listening;
    var builder = new codec.MessageBuilder(
        kVRService_SetListeningForActivate_Name,
        codec.align(VRService_SetListeningForActivate_Params.encodedSize));
    builder.encodeStruct(VRService_SetListeningForActivate_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function VRServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  VRServiceStub.prototype.setClient = function(client) {
    return this.delegate_ && this.delegate_.setClient && this.delegate_.setClient(client);
  }
  VRServiceStub.prototype.setListeningForActivate = function(listening) {
    return this.delegate_ && this.delegate_.setListeningForActivate && this.delegate_.setListeningForActivate(listening);
  }

  VRServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVRService_SetListeningForActivate_Name:
      var params = reader.decodeStruct(VRService_SetListeningForActivate_Params);
      this.setListeningForActivate(params.listening);
      return true;
    default:
      return false;
    }
  };

  VRServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVRService_SetClient_Name:
      var params = reader.decodeStruct(VRService_SetClient_Params);
      return this.setClient(params.client).then(function(response) {
        var responseParams =
            new VRService_SetClient_ResponseParams();
        responseParams.numberOfConnectedDevices = response.numberOfConnectedDevices;
        var builder = new codec.MessageWithRequestIDBuilder(
            kVRService_SetClient_Name,
            codec.align(VRService_SetClient_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VRService_SetClient_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVRServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVRService_SetClient_Name:
        if (message.expectsResponse())
          paramsClass = VRService_SetClient_Params;
      break;
      case kVRService_SetListeningForActivate_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRService_SetListeningForActivate_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVRServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kVRService_SetClient_Name:
        if (message.isResponse())
          paramsClass = VRService_SetClient_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var VRService = {
    name: 'device::mojom::VRService',
    ptrClass: VRServicePtr,
    proxyClass: VRServiceProxy,
    stubClass: VRServiceStub,
    validateRequest: validateVRServiceRequest,
    validateResponse: validateVRServiceResponse,
  };
  VRServiceStub.prototype.validator = validateVRServiceRequest;
  VRServiceProxy.prototype.validator = validateVRServiceResponse;
  var kVRServiceClient_OnDisplayConnected_Name = 0;

  function VRServiceClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VRServiceClient,
                                                   handleOrPtrInfo);
  }

  function VRServiceClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  VRServiceClientPtr.prototype.onDisplayConnected = function() {
    return VRServiceClientProxy.prototype.onDisplayConnected
        .apply(this.ptr.getProxy(), arguments);
  };

  VRServiceClientProxy.prototype.onDisplayConnected = function(display, request, displayInfo) {
    var params = new VRServiceClient_OnDisplayConnected_Params();
    params.display = display;
    params.request = request;
    params.displayInfo = displayInfo;
    var builder = new codec.MessageBuilder(
        kVRServiceClient_OnDisplayConnected_Name,
        codec.align(VRServiceClient_OnDisplayConnected_Params.encodedSize));
    builder.encodeStruct(VRServiceClient_OnDisplayConnected_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function VRServiceClientStub(delegate) {
    this.delegate_ = delegate;
  }
  VRServiceClientStub.prototype.onDisplayConnected = function(display, request, displayInfo) {
    return this.delegate_ && this.delegate_.onDisplayConnected && this.delegate_.onDisplayConnected(display, request, displayInfo);
  }

  VRServiceClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVRServiceClient_OnDisplayConnected_Name:
      var params = reader.decodeStruct(VRServiceClient_OnDisplayConnected_Params);
      this.onDisplayConnected(params.display, params.request, params.displayInfo);
      return true;
    default:
      return false;
    }
  };

  VRServiceClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVRServiceClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVRServiceClient_OnDisplayConnected_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRServiceClient_OnDisplayConnected_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVRServiceClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var VRServiceClient = {
    name: 'device::mojom::VRServiceClient',
    ptrClass: VRServiceClientPtr,
    proxyClass: VRServiceClientProxy,
    stubClass: VRServiceClientStub,
    validateRequest: validateVRServiceClientRequest,
    validateResponse: null,
  };
  VRServiceClientStub.prototype.validator = validateVRServiceClientRequest;
  VRServiceClientProxy.prototype.validator = null;
  var kVRDisplay_GetPose_Name = 0;
  var kVRDisplay_ResetPose_Name = 1;
  var kVRDisplay_RequestPresent_Name = 2;
  var kVRDisplay_ExitPresent_Name = 3;
  var kVRDisplay_SubmitFrame_Name = 4;
  var kVRDisplay_UpdateLayerBounds_Name = 5;

  function VRDisplayPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VRDisplay,
                                                   handleOrPtrInfo);
  }

  function VRDisplayProxy(receiver) {
    this.receiver_ = receiver;
  }
  VRDisplayPtr.prototype.getPose = function() {
    return VRDisplayProxy.prototype.getPose
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayProxy.prototype.getPose = function() {
    var params = new VRDisplay_GetPose_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVRDisplay_GetPose_Name,
          codec.align(VRDisplay_GetPose_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VRDisplay_GetPose_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VRDisplay_GetPose_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  VRDisplayPtr.prototype.resetPose = function() {
    return VRDisplayProxy.prototype.resetPose
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayProxy.prototype.resetPose = function() {
    var params = new VRDisplay_ResetPose_Params();
    var builder = new codec.MessageBuilder(
        kVRDisplay_ResetPose_Name,
        codec.align(VRDisplay_ResetPose_Params.encodedSize));
    builder.encodeStruct(VRDisplay_ResetPose_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayPtr.prototype.requestPresent = function() {
    return VRDisplayProxy.prototype.requestPresent
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayProxy.prototype.requestPresent = function(secureOrigin) {
    var params = new VRDisplay_RequestPresent_Params();
    params.secureOrigin = secureOrigin;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kVRDisplay_RequestPresent_Name,
          codec.align(VRDisplay_RequestPresent_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(VRDisplay_RequestPresent_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(VRDisplay_RequestPresent_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  VRDisplayPtr.prototype.exitPresent = function() {
    return VRDisplayProxy.prototype.exitPresent
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayProxy.prototype.exitPresent = function() {
    var params = new VRDisplay_ExitPresent_Params();
    var builder = new codec.MessageBuilder(
        kVRDisplay_ExitPresent_Name,
        codec.align(VRDisplay_ExitPresent_Params.encodedSize));
    builder.encodeStruct(VRDisplay_ExitPresent_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayPtr.prototype.submitFrame = function() {
    return VRDisplayProxy.prototype.submitFrame
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayProxy.prototype.submitFrame = function(pose) {
    var params = new VRDisplay_SubmitFrame_Params();
    params.pose = pose;
    var builder = new codec.MessageBuilder(
        kVRDisplay_SubmitFrame_Name,
        codec.align(VRDisplay_SubmitFrame_Params.encodedSize));
    builder.encodeStruct(VRDisplay_SubmitFrame_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayPtr.prototype.updateLayerBounds = function() {
    return VRDisplayProxy.prototype.updateLayerBounds
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayProxy.prototype.updateLayerBounds = function(leftBounds, rightBounds) {
    var params = new VRDisplay_UpdateLayerBounds_Params();
    params.leftBounds = leftBounds;
    params.rightBounds = rightBounds;
    var builder = new codec.MessageBuilder(
        kVRDisplay_UpdateLayerBounds_Name,
        codec.align(VRDisplay_UpdateLayerBounds_Params.encodedSize));
    builder.encodeStruct(VRDisplay_UpdateLayerBounds_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function VRDisplayStub(delegate) {
    this.delegate_ = delegate;
  }
  VRDisplayStub.prototype.getPose = function() {
    return this.delegate_ && this.delegate_.getPose && this.delegate_.getPose();
  }
  VRDisplayStub.prototype.resetPose = function() {
    return this.delegate_ && this.delegate_.resetPose && this.delegate_.resetPose();
  }
  VRDisplayStub.prototype.requestPresent = function(secureOrigin) {
    return this.delegate_ && this.delegate_.requestPresent && this.delegate_.requestPresent(secureOrigin);
  }
  VRDisplayStub.prototype.exitPresent = function() {
    return this.delegate_ && this.delegate_.exitPresent && this.delegate_.exitPresent();
  }
  VRDisplayStub.prototype.submitFrame = function(pose) {
    return this.delegate_ && this.delegate_.submitFrame && this.delegate_.submitFrame(pose);
  }
  VRDisplayStub.prototype.updateLayerBounds = function(leftBounds, rightBounds) {
    return this.delegate_ && this.delegate_.updateLayerBounds && this.delegate_.updateLayerBounds(leftBounds, rightBounds);
  }

  VRDisplayStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVRDisplay_ResetPose_Name:
      var params = reader.decodeStruct(VRDisplay_ResetPose_Params);
      this.resetPose();
      return true;
    case kVRDisplay_ExitPresent_Name:
      var params = reader.decodeStruct(VRDisplay_ExitPresent_Params);
      this.exitPresent();
      return true;
    case kVRDisplay_SubmitFrame_Name:
      var params = reader.decodeStruct(VRDisplay_SubmitFrame_Params);
      this.submitFrame(params.pose);
      return true;
    case kVRDisplay_UpdateLayerBounds_Name:
      var params = reader.decodeStruct(VRDisplay_UpdateLayerBounds_Params);
      this.updateLayerBounds(params.leftBounds, params.rightBounds);
      return true;
    default:
      return false;
    }
  };

  VRDisplayStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVRDisplay_GetPose_Name:
      var params = reader.decodeStruct(VRDisplay_GetPose_Params);
      return this.getPose().then(function(response) {
        var responseParams =
            new VRDisplay_GetPose_ResponseParams();
        responseParams.pose = response.pose;
        var builder = new codec.MessageWithRequestIDBuilder(
            kVRDisplay_GetPose_Name,
            codec.align(VRDisplay_GetPose_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VRDisplay_GetPose_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kVRDisplay_RequestPresent_Name:
      var params = reader.decodeStruct(VRDisplay_RequestPresent_Params);
      return this.requestPresent(params.secureOrigin).then(function(response) {
        var responseParams =
            new VRDisplay_RequestPresent_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kVRDisplay_RequestPresent_Name,
            codec.align(VRDisplay_RequestPresent_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(VRDisplay_RequestPresent_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVRDisplayRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVRDisplay_GetPose_Name:
        if (message.expectsResponse())
          paramsClass = VRDisplay_GetPose_Params;
      break;
      case kVRDisplay_ResetPose_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplay_ResetPose_Params;
      break;
      case kVRDisplay_RequestPresent_Name:
        if (message.expectsResponse())
          paramsClass = VRDisplay_RequestPresent_Params;
      break;
      case kVRDisplay_ExitPresent_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplay_ExitPresent_Params;
      break;
      case kVRDisplay_SubmitFrame_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplay_SubmitFrame_Params;
      break;
      case kVRDisplay_UpdateLayerBounds_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplay_UpdateLayerBounds_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVRDisplayResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kVRDisplay_GetPose_Name:
        if (message.isResponse())
          paramsClass = VRDisplay_GetPose_ResponseParams;
        break;
      case kVRDisplay_RequestPresent_Name:
        if (message.isResponse())
          paramsClass = VRDisplay_RequestPresent_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var VRDisplay = {
    name: 'device::mojom::VRDisplay',
    ptrClass: VRDisplayPtr,
    proxyClass: VRDisplayProxy,
    stubClass: VRDisplayStub,
    validateRequest: validateVRDisplayRequest,
    validateResponse: validateVRDisplayResponse,
  };
  VRDisplayStub.prototype.validator = validateVRDisplayRequest;
  VRDisplayProxy.prototype.validator = validateVRDisplayResponse;
  var kVRDisplayClient_OnChanged_Name = 0;
  var kVRDisplayClient_OnExitPresent_Name = 1;
  var kVRDisplayClient_OnBlur_Name = 2;
  var kVRDisplayClient_OnFocus_Name = 3;
  var kVRDisplayClient_OnActivate_Name = 4;
  var kVRDisplayClient_OnDeactivate_Name = 5;

  function VRDisplayClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(VRDisplayClient,
                                                   handleOrPtrInfo);
  }

  function VRDisplayClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  VRDisplayClientPtr.prototype.onChanged = function() {
    return VRDisplayClientProxy.prototype.onChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayClientProxy.prototype.onChanged = function(display) {
    var params = new VRDisplayClient_OnChanged_Params();
    params.display = display;
    var builder = new codec.MessageBuilder(
        kVRDisplayClient_OnChanged_Name,
        codec.align(VRDisplayClient_OnChanged_Params.encodedSize));
    builder.encodeStruct(VRDisplayClient_OnChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayClientPtr.prototype.onExitPresent = function() {
    return VRDisplayClientProxy.prototype.onExitPresent
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayClientProxy.prototype.onExitPresent = function() {
    var params = new VRDisplayClient_OnExitPresent_Params();
    var builder = new codec.MessageBuilder(
        kVRDisplayClient_OnExitPresent_Name,
        codec.align(VRDisplayClient_OnExitPresent_Params.encodedSize));
    builder.encodeStruct(VRDisplayClient_OnExitPresent_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayClientPtr.prototype.onBlur = function() {
    return VRDisplayClientProxy.prototype.onBlur
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayClientProxy.prototype.onBlur = function() {
    var params = new VRDisplayClient_OnBlur_Params();
    var builder = new codec.MessageBuilder(
        kVRDisplayClient_OnBlur_Name,
        codec.align(VRDisplayClient_OnBlur_Params.encodedSize));
    builder.encodeStruct(VRDisplayClient_OnBlur_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayClientPtr.prototype.onFocus = function() {
    return VRDisplayClientProxy.prototype.onFocus
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayClientProxy.prototype.onFocus = function() {
    var params = new VRDisplayClient_OnFocus_Params();
    var builder = new codec.MessageBuilder(
        kVRDisplayClient_OnFocus_Name,
        codec.align(VRDisplayClient_OnFocus_Params.encodedSize));
    builder.encodeStruct(VRDisplayClient_OnFocus_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayClientPtr.prototype.onActivate = function() {
    return VRDisplayClientProxy.prototype.onActivate
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayClientProxy.prototype.onActivate = function(reason) {
    var params = new VRDisplayClient_OnActivate_Params();
    params.reason = reason;
    var builder = new codec.MessageBuilder(
        kVRDisplayClient_OnActivate_Name,
        codec.align(VRDisplayClient_OnActivate_Params.encodedSize));
    builder.encodeStruct(VRDisplayClient_OnActivate_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  VRDisplayClientPtr.prototype.onDeactivate = function() {
    return VRDisplayClientProxy.prototype.onDeactivate
        .apply(this.ptr.getProxy(), arguments);
  };

  VRDisplayClientProxy.prototype.onDeactivate = function(reason) {
    var params = new VRDisplayClient_OnDeactivate_Params();
    params.reason = reason;
    var builder = new codec.MessageBuilder(
        kVRDisplayClient_OnDeactivate_Name,
        codec.align(VRDisplayClient_OnDeactivate_Params.encodedSize));
    builder.encodeStruct(VRDisplayClient_OnDeactivate_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function VRDisplayClientStub(delegate) {
    this.delegate_ = delegate;
  }
  VRDisplayClientStub.prototype.onChanged = function(display) {
    return this.delegate_ && this.delegate_.onChanged && this.delegate_.onChanged(display);
  }
  VRDisplayClientStub.prototype.onExitPresent = function() {
    return this.delegate_ && this.delegate_.onExitPresent && this.delegate_.onExitPresent();
  }
  VRDisplayClientStub.prototype.onBlur = function() {
    return this.delegate_ && this.delegate_.onBlur && this.delegate_.onBlur();
  }
  VRDisplayClientStub.prototype.onFocus = function() {
    return this.delegate_ && this.delegate_.onFocus && this.delegate_.onFocus();
  }
  VRDisplayClientStub.prototype.onActivate = function(reason) {
    return this.delegate_ && this.delegate_.onActivate && this.delegate_.onActivate(reason);
  }
  VRDisplayClientStub.prototype.onDeactivate = function(reason) {
    return this.delegate_ && this.delegate_.onDeactivate && this.delegate_.onDeactivate(reason);
  }

  VRDisplayClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kVRDisplayClient_OnChanged_Name:
      var params = reader.decodeStruct(VRDisplayClient_OnChanged_Params);
      this.onChanged(params.display);
      return true;
    case kVRDisplayClient_OnExitPresent_Name:
      var params = reader.decodeStruct(VRDisplayClient_OnExitPresent_Params);
      this.onExitPresent();
      return true;
    case kVRDisplayClient_OnBlur_Name:
      var params = reader.decodeStruct(VRDisplayClient_OnBlur_Params);
      this.onBlur();
      return true;
    case kVRDisplayClient_OnFocus_Name:
      var params = reader.decodeStruct(VRDisplayClient_OnFocus_Params);
      this.onFocus();
      return true;
    case kVRDisplayClient_OnActivate_Name:
      var params = reader.decodeStruct(VRDisplayClient_OnActivate_Params);
      this.onActivate(params.reason);
      return true;
    case kVRDisplayClient_OnDeactivate_Name:
      var params = reader.decodeStruct(VRDisplayClient_OnDeactivate_Params);
      this.onDeactivate(params.reason);
      return true;
    default:
      return false;
    }
  };

  VRDisplayClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateVRDisplayClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kVRDisplayClient_OnChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplayClient_OnChanged_Params;
      break;
      case kVRDisplayClient_OnExitPresent_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplayClient_OnExitPresent_Params;
      break;
      case kVRDisplayClient_OnBlur_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplayClient_OnBlur_Params;
      break;
      case kVRDisplayClient_OnFocus_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplayClient_OnFocus_Params;
      break;
      case kVRDisplayClient_OnActivate_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplayClient_OnActivate_Params;
      break;
      case kVRDisplayClient_OnDeactivate_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = VRDisplayClient_OnDeactivate_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateVRDisplayClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var VRDisplayClient = {
    name: 'device::mojom::VRDisplayClient',
    ptrClass: VRDisplayClientPtr,
    proxyClass: VRDisplayClientProxy,
    stubClass: VRDisplayClientStub,
    validateRequest: validateVRDisplayClientRequest,
    validateResponse: null,
  };
  VRDisplayClientStub.prototype.validator = validateVRDisplayClientRequest;
  VRDisplayClientProxy.prototype.validator = null;

  var exports = {};
  exports.VRDisplayEventReason = VRDisplayEventReason;
  exports.VRFieldOfView = VRFieldOfView;
  exports.VRPose = VRPose;
  exports.VRDisplayCapabilities = VRDisplayCapabilities;
  exports.VREyeParameters = VREyeParameters;
  exports.VRStageParameters = VRStageParameters;
  exports.VRDisplayInfo = VRDisplayInfo;
  exports.VRLayerBounds = VRLayerBounds;
  exports.VRService = VRService;
  exports.VRServicePtr = VRServicePtr;
  exports.VRServiceClient = VRServiceClient;
  exports.VRServiceClientPtr = VRServiceClientPtr;
  exports.VRDisplay = VRDisplay;
  exports.VRDisplayPtr = VRDisplayPtr;
  exports.VRDisplayClient = VRDisplayClient;
  exports.VRDisplayClientPtr = VRDisplayClientPtr;

  return exports;
});
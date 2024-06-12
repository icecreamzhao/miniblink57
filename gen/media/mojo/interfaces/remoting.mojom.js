// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/remoting.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var RemotingStopReason = {};
  RemotingStopReason.ROUTE_TERMINATED = 0;
  RemotingStopReason.LOCAL_PLAYBACK = RemotingStopReason.ROUTE_TERMINATED + 1;
  RemotingStopReason.SOURCE_GONE = RemotingStopReason.LOCAL_PLAYBACK + 1;
  RemotingStopReason.MESSAGE_SEND_FAILED = RemotingStopReason.SOURCE_GONE + 1;
  RemotingStopReason.DATA_SEND_FAILED = RemotingStopReason.MESSAGE_SEND_FAILED + 1;
  RemotingStopReason.UNEXPECTED_FAILURE = RemotingStopReason.DATA_SEND_FAILED + 1;

  RemotingStopReason.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    }
    return false;
  };

  RemotingStopReason.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var RemotingSinkCapabilities = {};
  RemotingSinkCapabilities.NONE = 0;
  RemotingSinkCapabilities.RENDERING_ONLY = RemotingSinkCapabilities.NONE + 1;
  RemotingSinkCapabilities.CONTENT_DECRYPTION_AND_RENDERING = RemotingSinkCapabilities.RENDERING_ONLY + 1;

  RemotingSinkCapabilities.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  RemotingSinkCapabilities.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var RemotingStartFailReason = {};
  RemotingStartFailReason.CANNOT_START_MULTIPLE = 0;
  RemotingStartFailReason.ROUTE_TERMINATED = RemotingStartFailReason.CANNOT_START_MULTIPLE + 1;

  RemotingStartFailReason.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  RemotingStartFailReason.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function RemoterFactory_Create_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemoterFactory_Create_Params.prototype.initDefaults_ = function() {
    this.source = new RemotingSourcePtr();
    this.remoter = new bindings.InterfaceRequest();
  };
  RemoterFactory_Create_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemoterFactory_Create_Params.validate = function(messageValidator, offset) {
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


    
    // validate RemoterFactory_Create_Params.source
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate RemoterFactory_Create_Params.remoter
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RemoterFactory_Create_Params.encodedSize = codec.kStructHeaderSize + 16;

  RemoterFactory_Create_Params.decode = function(decoder) {
    var packed;
    var val = new RemoterFactory_Create_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.source = decoder.decodeStruct(new codec.Interface(RemotingSourcePtr));
    val.remoter = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  RemoterFactory_Create_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemoterFactory_Create_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(RemotingSourcePtr), val.source);
    encoder.encodeStruct(codec.InterfaceRequest, val.remoter);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function RemotingDataStreamSender_ConsumeDataChunk_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingDataStreamSender_ConsumeDataChunk_Params.prototype.initDefaults_ = function() {
    this.offset = 0;
    this.size = 0;
    this.total_payload_size = 0;
  };
  RemotingDataStreamSender_ConsumeDataChunk_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingDataStreamSender_ConsumeDataChunk_Params.validate = function(messageValidator, offset) {
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

  RemotingDataStreamSender_ConsumeDataChunk_Params.encodedSize = codec.kStructHeaderSize + 16;

  RemotingDataStreamSender_ConsumeDataChunk_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingDataStreamSender_ConsumeDataChunk_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.offset = decoder.decodeStruct(codec.Uint32);
    val.size = decoder.decodeStruct(codec.Uint32);
    val.total_payload_size = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  RemotingDataStreamSender_ConsumeDataChunk_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingDataStreamSender_ConsumeDataChunk_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.offset);
    encoder.encodeStruct(codec.Uint32, val.size);
    encoder.encodeStruct(codec.Uint32, val.total_payload_size);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function RemotingDataStreamSender_SendFrame_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingDataStreamSender_SendFrame_Params.prototype.initDefaults_ = function() {
  };
  RemotingDataStreamSender_SendFrame_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingDataStreamSender_SendFrame_Params.validate = function(messageValidator, offset) {
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

  RemotingDataStreamSender_SendFrame_Params.encodedSize = codec.kStructHeaderSize + 0;

  RemotingDataStreamSender_SendFrame_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingDataStreamSender_SendFrame_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  RemotingDataStreamSender_SendFrame_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingDataStreamSender_SendFrame_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function RemotingDataStreamSender_CancelInFlightData_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingDataStreamSender_CancelInFlightData_Params.prototype.initDefaults_ = function() {
  };
  RemotingDataStreamSender_CancelInFlightData_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingDataStreamSender_CancelInFlightData_Params.validate = function(messageValidator, offset) {
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

  RemotingDataStreamSender_CancelInFlightData_Params.encodedSize = codec.kStructHeaderSize + 0;

  RemotingDataStreamSender_CancelInFlightData_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingDataStreamSender_CancelInFlightData_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  RemotingDataStreamSender_CancelInFlightData_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingDataStreamSender_CancelInFlightData_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Remoter_Start_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Remoter_Start_Params.prototype.initDefaults_ = function() {
  };
  Remoter_Start_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Remoter_Start_Params.validate = function(messageValidator, offset) {
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

  Remoter_Start_Params.encodedSize = codec.kStructHeaderSize + 0;

  Remoter_Start_Params.decode = function(decoder) {
    var packed;
    var val = new Remoter_Start_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Remoter_Start_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Remoter_Start_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Remoter_StartDataStreams_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Remoter_StartDataStreams_Params.prototype.initDefaults_ = function() {
    this.audio_pipe = null;
    this.video_pipe = null;
    this.audio_sender = new bindings.InterfaceRequest();
    this.video_sender = new bindings.InterfaceRequest();
  };
  Remoter_StartDataStreams_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Remoter_StartDataStreams_Params.validate = function(messageValidator, offset) {
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


    
    // validate Remoter_StartDataStreams_Params.audio_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 0, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Remoter_StartDataStreams_Params.video_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 4, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Remoter_StartDataStreams_Params.audio_sender
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Remoter_StartDataStreams_Params.video_sender
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 12, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Remoter_StartDataStreams_Params.encodedSize = codec.kStructHeaderSize + 16;

  Remoter_StartDataStreams_Params.decode = function(decoder) {
    var packed;
    var val = new Remoter_StartDataStreams_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.audio_pipe = decoder.decodeStruct(codec.NullableHandle);
    val.video_pipe = decoder.decodeStruct(codec.NullableHandle);
    val.audio_sender = decoder.decodeStruct(codec.NullableInterfaceRequest);
    val.video_sender = decoder.decodeStruct(codec.NullableInterfaceRequest);
    return val;
  };

  Remoter_StartDataStreams_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Remoter_StartDataStreams_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.NullableHandle, val.audio_pipe);
    encoder.encodeStruct(codec.NullableHandle, val.video_pipe);
    encoder.encodeStruct(codec.NullableInterfaceRequest, val.audio_sender);
    encoder.encodeStruct(codec.NullableInterfaceRequest, val.video_sender);
  };
  function Remoter_Stop_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Remoter_Stop_Params.prototype.initDefaults_ = function() {
    this.reason = 0;
  };
  Remoter_Stop_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Remoter_Stop_Params.validate = function(messageValidator, offset) {
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


    
    // validate Remoter_Stop_Params.reason
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, RemotingStopReason);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Remoter_Stop_Params.encodedSize = codec.kStructHeaderSize + 8;

  Remoter_Stop_Params.decode = function(decoder) {
    var packed;
    var val = new Remoter_Stop_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.reason = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Remoter_Stop_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Remoter_Stop_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.reason);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Remoter_SendMessageToSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Remoter_SendMessageToSink_Params.prototype.initDefaults_ = function() {
    this.message = null;
  };
  Remoter_SendMessageToSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Remoter_SendMessageToSink_Params.validate = function(messageValidator, offset) {
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


    
    // validate Remoter_SendMessageToSink_Params.message
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Remoter_SendMessageToSink_Params.encodedSize = codec.kStructHeaderSize + 8;

  Remoter_SendMessageToSink_Params.decode = function(decoder) {
    var packed;
    var val = new Remoter_SendMessageToSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.message = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  Remoter_SendMessageToSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Remoter_SendMessageToSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.message);
  };
  function RemotingSource_OnSinkAvailable_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingSource_OnSinkAvailable_Params.prototype.initDefaults_ = function() {
    this.capabilities = 0;
  };
  RemotingSource_OnSinkAvailable_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingSource_OnSinkAvailable_Params.validate = function(messageValidator, offset) {
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


    
    // validate RemotingSource_OnSinkAvailable_Params.capabilities
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, RemotingSinkCapabilities);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RemotingSource_OnSinkAvailable_Params.encodedSize = codec.kStructHeaderSize + 8;

  RemotingSource_OnSinkAvailable_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingSource_OnSinkAvailable_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.capabilities = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  RemotingSource_OnSinkAvailable_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingSource_OnSinkAvailable_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.capabilities);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function RemotingSource_OnSinkGone_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingSource_OnSinkGone_Params.prototype.initDefaults_ = function() {
  };
  RemotingSource_OnSinkGone_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingSource_OnSinkGone_Params.validate = function(messageValidator, offset) {
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

  RemotingSource_OnSinkGone_Params.encodedSize = codec.kStructHeaderSize + 0;

  RemotingSource_OnSinkGone_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingSource_OnSinkGone_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  RemotingSource_OnSinkGone_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingSource_OnSinkGone_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function RemotingSource_OnStarted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingSource_OnStarted_Params.prototype.initDefaults_ = function() {
  };
  RemotingSource_OnStarted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingSource_OnStarted_Params.validate = function(messageValidator, offset) {
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

  RemotingSource_OnStarted_Params.encodedSize = codec.kStructHeaderSize + 0;

  RemotingSource_OnStarted_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingSource_OnStarted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  RemotingSource_OnStarted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingSource_OnStarted_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function RemotingSource_OnStartFailed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingSource_OnStartFailed_Params.prototype.initDefaults_ = function() {
    this.reason = 0;
  };
  RemotingSource_OnStartFailed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingSource_OnStartFailed_Params.validate = function(messageValidator, offset) {
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


    
    // validate RemotingSource_OnStartFailed_Params.reason
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, RemotingStartFailReason);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RemotingSource_OnStartFailed_Params.encodedSize = codec.kStructHeaderSize + 8;

  RemotingSource_OnStartFailed_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingSource_OnStartFailed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.reason = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  RemotingSource_OnStartFailed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingSource_OnStartFailed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.reason);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function RemotingSource_OnMessageFromSink_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingSource_OnMessageFromSink_Params.prototype.initDefaults_ = function() {
    this.message = null;
  };
  RemotingSource_OnMessageFromSink_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingSource_OnMessageFromSink_Params.validate = function(messageValidator, offset) {
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


    
    // validate RemotingSource_OnMessageFromSink_Params.message
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RemotingSource_OnMessageFromSink_Params.encodedSize = codec.kStructHeaderSize + 8;

  RemotingSource_OnMessageFromSink_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingSource_OnMessageFromSink_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.message = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  RemotingSource_OnMessageFromSink_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingSource_OnMessageFromSink_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.message);
  };
  function RemotingSource_OnStopped_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RemotingSource_OnStopped_Params.prototype.initDefaults_ = function() {
    this.reason = 0;
  };
  RemotingSource_OnStopped_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RemotingSource_OnStopped_Params.validate = function(messageValidator, offset) {
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


    
    // validate RemotingSource_OnStopped_Params.reason
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, RemotingStopReason);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RemotingSource_OnStopped_Params.encodedSize = codec.kStructHeaderSize + 8;

  RemotingSource_OnStopped_Params.decode = function(decoder) {
    var packed;
    var val = new RemotingSource_OnStopped_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.reason = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  RemotingSource_OnStopped_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RemotingSource_OnStopped_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.reason);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kRemoterFactory_Create_Name = 0;

  function RemoterFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(RemoterFactory,
                                                   handleOrPtrInfo);
  }

  function RemoterFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  RemoterFactoryPtr.prototype.create = function() {
    return RemoterFactoryProxy.prototype.create
        .apply(this.ptr.getProxy(), arguments);
  };

  RemoterFactoryProxy.prototype.create = function(source, remoter) {
    var params = new RemoterFactory_Create_Params();
    params.source = source;
    params.remoter = remoter;
    var builder = new codec.MessageBuilder(
        kRemoterFactory_Create_Name,
        codec.align(RemoterFactory_Create_Params.encodedSize));
    builder.encodeStruct(RemoterFactory_Create_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function RemoterFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  RemoterFactoryStub.prototype.create = function(source, remoter) {
    return this.delegate_ && this.delegate_.create && this.delegate_.create(source, remoter);
  }

  RemoterFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kRemoterFactory_Create_Name:
      var params = reader.decodeStruct(RemoterFactory_Create_Params);
      this.create(params.source, params.remoter);
      return true;
    default:
      return false;
    }
  };

  RemoterFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateRemoterFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kRemoterFactory_Create_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemoterFactory_Create_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateRemoterFactoryResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var RemoterFactory = {
    name: 'media::mojom::RemoterFactory',
    ptrClass: RemoterFactoryPtr,
    proxyClass: RemoterFactoryProxy,
    stubClass: RemoterFactoryStub,
    validateRequest: validateRemoterFactoryRequest,
    validateResponse: null,
  };
  RemoterFactoryStub.prototype.validator = validateRemoterFactoryRequest;
  RemoterFactoryProxy.prototype.validator = null;
  var kRemotingDataStreamSender_ConsumeDataChunk_Name = 0;
  var kRemotingDataStreamSender_SendFrame_Name = 1;
  var kRemotingDataStreamSender_CancelInFlightData_Name = 2;

  function RemotingDataStreamSenderPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(RemotingDataStreamSender,
                                                   handleOrPtrInfo);
  }

  function RemotingDataStreamSenderProxy(receiver) {
    this.receiver_ = receiver;
  }
  RemotingDataStreamSenderPtr.prototype.consumeDataChunk = function() {
    return RemotingDataStreamSenderProxy.prototype.consumeDataChunk
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingDataStreamSenderProxy.prototype.consumeDataChunk = function(offset, size, total_payload_size) {
    var params = new RemotingDataStreamSender_ConsumeDataChunk_Params();
    params.offset = offset;
    params.size = size;
    params.total_payload_size = total_payload_size;
    var builder = new codec.MessageBuilder(
        kRemotingDataStreamSender_ConsumeDataChunk_Name,
        codec.align(RemotingDataStreamSender_ConsumeDataChunk_Params.encodedSize));
    builder.encodeStruct(RemotingDataStreamSender_ConsumeDataChunk_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemotingDataStreamSenderPtr.prototype.sendFrame = function() {
    return RemotingDataStreamSenderProxy.prototype.sendFrame
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingDataStreamSenderProxy.prototype.sendFrame = function() {
    var params = new RemotingDataStreamSender_SendFrame_Params();
    var builder = new codec.MessageBuilder(
        kRemotingDataStreamSender_SendFrame_Name,
        codec.align(RemotingDataStreamSender_SendFrame_Params.encodedSize));
    builder.encodeStruct(RemotingDataStreamSender_SendFrame_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemotingDataStreamSenderPtr.prototype.cancelInFlightData = function() {
    return RemotingDataStreamSenderProxy.prototype.cancelInFlightData
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingDataStreamSenderProxy.prototype.cancelInFlightData = function() {
    var params = new RemotingDataStreamSender_CancelInFlightData_Params();
    var builder = new codec.MessageBuilder(
        kRemotingDataStreamSender_CancelInFlightData_Name,
        codec.align(RemotingDataStreamSender_CancelInFlightData_Params.encodedSize));
    builder.encodeStruct(RemotingDataStreamSender_CancelInFlightData_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function RemotingDataStreamSenderStub(delegate) {
    this.delegate_ = delegate;
  }
  RemotingDataStreamSenderStub.prototype.consumeDataChunk = function(offset, size, total_payload_size) {
    return this.delegate_ && this.delegate_.consumeDataChunk && this.delegate_.consumeDataChunk(offset, size, total_payload_size);
  }
  RemotingDataStreamSenderStub.prototype.sendFrame = function() {
    return this.delegate_ && this.delegate_.sendFrame && this.delegate_.sendFrame();
  }
  RemotingDataStreamSenderStub.prototype.cancelInFlightData = function() {
    return this.delegate_ && this.delegate_.cancelInFlightData && this.delegate_.cancelInFlightData();
  }

  RemotingDataStreamSenderStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kRemotingDataStreamSender_ConsumeDataChunk_Name:
      var params = reader.decodeStruct(RemotingDataStreamSender_ConsumeDataChunk_Params);
      this.consumeDataChunk(params.offset, params.size, params.total_payload_size);
      return true;
    case kRemotingDataStreamSender_SendFrame_Name:
      var params = reader.decodeStruct(RemotingDataStreamSender_SendFrame_Params);
      this.sendFrame();
      return true;
    case kRemotingDataStreamSender_CancelInFlightData_Name:
      var params = reader.decodeStruct(RemotingDataStreamSender_CancelInFlightData_Params);
      this.cancelInFlightData();
      return true;
    default:
      return false;
    }
  };

  RemotingDataStreamSenderStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateRemotingDataStreamSenderRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kRemotingDataStreamSender_ConsumeDataChunk_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingDataStreamSender_ConsumeDataChunk_Params;
      break;
      case kRemotingDataStreamSender_SendFrame_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingDataStreamSender_SendFrame_Params;
      break;
      case kRemotingDataStreamSender_CancelInFlightData_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingDataStreamSender_CancelInFlightData_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateRemotingDataStreamSenderResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var RemotingDataStreamSender = {
    name: 'media::mojom::RemotingDataStreamSender',
    ptrClass: RemotingDataStreamSenderPtr,
    proxyClass: RemotingDataStreamSenderProxy,
    stubClass: RemotingDataStreamSenderStub,
    validateRequest: validateRemotingDataStreamSenderRequest,
    validateResponse: null,
  };
  RemotingDataStreamSenderStub.prototype.validator = validateRemotingDataStreamSenderRequest;
  RemotingDataStreamSenderProxy.prototype.validator = null;
  var kRemoter_Start_Name = 0;
  var kRemoter_StartDataStreams_Name = 1;
  var kRemoter_Stop_Name = 2;
  var kRemoter_SendMessageToSink_Name = 3;

  function RemoterPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Remoter,
                                                   handleOrPtrInfo);
  }

  function RemoterProxy(receiver) {
    this.receiver_ = receiver;
  }
  RemoterPtr.prototype.start = function() {
    return RemoterProxy.prototype.start
        .apply(this.ptr.getProxy(), arguments);
  };

  RemoterProxy.prototype.start = function() {
    var params = new Remoter_Start_Params();
    var builder = new codec.MessageBuilder(
        kRemoter_Start_Name,
        codec.align(Remoter_Start_Params.encodedSize));
    builder.encodeStruct(Remoter_Start_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemoterPtr.prototype.startDataStreams = function() {
    return RemoterProxy.prototype.startDataStreams
        .apply(this.ptr.getProxy(), arguments);
  };

  RemoterProxy.prototype.startDataStreams = function(audio_pipe, video_pipe, audio_sender, video_sender) {
    var params = new Remoter_StartDataStreams_Params();
    params.audio_pipe = audio_pipe;
    params.video_pipe = video_pipe;
    params.audio_sender = audio_sender;
    params.video_sender = video_sender;
    var builder = new codec.MessageBuilder(
        kRemoter_StartDataStreams_Name,
        codec.align(Remoter_StartDataStreams_Params.encodedSize));
    builder.encodeStruct(Remoter_StartDataStreams_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemoterPtr.prototype.stop = function() {
    return RemoterProxy.prototype.stop
        .apply(this.ptr.getProxy(), arguments);
  };

  RemoterProxy.prototype.stop = function(reason) {
    var params = new Remoter_Stop_Params();
    params.reason = reason;
    var builder = new codec.MessageBuilder(
        kRemoter_Stop_Name,
        codec.align(Remoter_Stop_Params.encodedSize));
    builder.encodeStruct(Remoter_Stop_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemoterPtr.prototype.sendMessageToSink = function() {
    return RemoterProxy.prototype.sendMessageToSink
        .apply(this.ptr.getProxy(), arguments);
  };

  RemoterProxy.prototype.sendMessageToSink = function(message) {
    var params = new Remoter_SendMessageToSink_Params();
    params.message = message;
    var builder = new codec.MessageBuilder(
        kRemoter_SendMessageToSink_Name,
        codec.align(Remoter_SendMessageToSink_Params.encodedSize));
    builder.encodeStruct(Remoter_SendMessageToSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function RemoterStub(delegate) {
    this.delegate_ = delegate;
  }
  RemoterStub.prototype.start = function() {
    return this.delegate_ && this.delegate_.start && this.delegate_.start();
  }
  RemoterStub.prototype.startDataStreams = function(audio_pipe, video_pipe, audio_sender, video_sender) {
    return this.delegate_ && this.delegate_.startDataStreams && this.delegate_.startDataStreams(audio_pipe, video_pipe, audio_sender, video_sender);
  }
  RemoterStub.prototype.stop = function(reason) {
    return this.delegate_ && this.delegate_.stop && this.delegate_.stop(reason);
  }
  RemoterStub.prototype.sendMessageToSink = function(message) {
    return this.delegate_ && this.delegate_.sendMessageToSink && this.delegate_.sendMessageToSink(message);
  }

  RemoterStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kRemoter_Start_Name:
      var params = reader.decodeStruct(Remoter_Start_Params);
      this.start();
      return true;
    case kRemoter_StartDataStreams_Name:
      var params = reader.decodeStruct(Remoter_StartDataStreams_Params);
      this.startDataStreams(params.audio_pipe, params.video_pipe, params.audio_sender, params.video_sender);
      return true;
    case kRemoter_Stop_Name:
      var params = reader.decodeStruct(Remoter_Stop_Params);
      this.stop(params.reason);
      return true;
    case kRemoter_SendMessageToSink_Name:
      var params = reader.decodeStruct(Remoter_SendMessageToSink_Params);
      this.sendMessageToSink(params.message);
      return true;
    default:
      return false;
    }
  };

  RemoterStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateRemoterRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kRemoter_Start_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Remoter_Start_Params;
      break;
      case kRemoter_StartDataStreams_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Remoter_StartDataStreams_Params;
      break;
      case kRemoter_Stop_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Remoter_Stop_Params;
      break;
      case kRemoter_SendMessageToSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Remoter_SendMessageToSink_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateRemoterResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var Remoter = {
    name: 'media::mojom::Remoter',
    ptrClass: RemoterPtr,
    proxyClass: RemoterProxy,
    stubClass: RemoterStub,
    validateRequest: validateRemoterRequest,
    validateResponse: null,
  };
  RemoterStub.prototype.validator = validateRemoterRequest;
  RemoterProxy.prototype.validator = null;
  var kRemotingSource_OnSinkAvailable_Name = 0;
  var kRemotingSource_OnSinkGone_Name = 1;
  var kRemotingSource_OnStarted_Name = 2;
  var kRemotingSource_OnStartFailed_Name = 3;
  var kRemotingSource_OnMessageFromSink_Name = 4;
  var kRemotingSource_OnStopped_Name = 5;

  function RemotingSourcePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(RemotingSource,
                                                   handleOrPtrInfo);
  }

  function RemotingSourceProxy(receiver) {
    this.receiver_ = receiver;
  }
  RemotingSourcePtr.prototype.onSinkAvailable = function() {
    return RemotingSourceProxy.prototype.onSinkAvailable
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingSourceProxy.prototype.onSinkAvailable = function(capabilities) {
    var params = new RemotingSource_OnSinkAvailable_Params();
    params.capabilities = capabilities;
    var builder = new codec.MessageBuilder(
        kRemotingSource_OnSinkAvailable_Name,
        codec.align(RemotingSource_OnSinkAvailable_Params.encodedSize));
    builder.encodeStruct(RemotingSource_OnSinkAvailable_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemotingSourcePtr.prototype.onSinkGone = function() {
    return RemotingSourceProxy.prototype.onSinkGone
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingSourceProxy.prototype.onSinkGone = function() {
    var params = new RemotingSource_OnSinkGone_Params();
    var builder = new codec.MessageBuilder(
        kRemotingSource_OnSinkGone_Name,
        codec.align(RemotingSource_OnSinkGone_Params.encodedSize));
    builder.encodeStruct(RemotingSource_OnSinkGone_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemotingSourcePtr.prototype.onStarted = function() {
    return RemotingSourceProxy.prototype.onStarted
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingSourceProxy.prototype.onStarted = function() {
    var params = new RemotingSource_OnStarted_Params();
    var builder = new codec.MessageBuilder(
        kRemotingSource_OnStarted_Name,
        codec.align(RemotingSource_OnStarted_Params.encodedSize));
    builder.encodeStruct(RemotingSource_OnStarted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemotingSourcePtr.prototype.onStartFailed = function() {
    return RemotingSourceProxy.prototype.onStartFailed
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingSourceProxy.prototype.onStartFailed = function(reason) {
    var params = new RemotingSource_OnStartFailed_Params();
    params.reason = reason;
    var builder = new codec.MessageBuilder(
        kRemotingSource_OnStartFailed_Name,
        codec.align(RemotingSource_OnStartFailed_Params.encodedSize));
    builder.encodeStruct(RemotingSource_OnStartFailed_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemotingSourcePtr.prototype.onMessageFromSink = function() {
    return RemotingSourceProxy.prototype.onMessageFromSink
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingSourceProxy.prototype.onMessageFromSink = function(message) {
    var params = new RemotingSource_OnMessageFromSink_Params();
    params.message = message;
    var builder = new codec.MessageBuilder(
        kRemotingSource_OnMessageFromSink_Name,
        codec.align(RemotingSource_OnMessageFromSink_Params.encodedSize));
    builder.encodeStruct(RemotingSource_OnMessageFromSink_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  RemotingSourcePtr.prototype.onStopped = function() {
    return RemotingSourceProxy.prototype.onStopped
        .apply(this.ptr.getProxy(), arguments);
  };

  RemotingSourceProxy.prototype.onStopped = function(reason) {
    var params = new RemotingSource_OnStopped_Params();
    params.reason = reason;
    var builder = new codec.MessageBuilder(
        kRemotingSource_OnStopped_Name,
        codec.align(RemotingSource_OnStopped_Params.encodedSize));
    builder.encodeStruct(RemotingSource_OnStopped_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function RemotingSourceStub(delegate) {
    this.delegate_ = delegate;
  }
  RemotingSourceStub.prototype.onSinkAvailable = function(capabilities) {
    return this.delegate_ && this.delegate_.onSinkAvailable && this.delegate_.onSinkAvailable(capabilities);
  }
  RemotingSourceStub.prototype.onSinkGone = function() {
    return this.delegate_ && this.delegate_.onSinkGone && this.delegate_.onSinkGone();
  }
  RemotingSourceStub.prototype.onStarted = function() {
    return this.delegate_ && this.delegate_.onStarted && this.delegate_.onStarted();
  }
  RemotingSourceStub.prototype.onStartFailed = function(reason) {
    return this.delegate_ && this.delegate_.onStartFailed && this.delegate_.onStartFailed(reason);
  }
  RemotingSourceStub.prototype.onMessageFromSink = function(message) {
    return this.delegate_ && this.delegate_.onMessageFromSink && this.delegate_.onMessageFromSink(message);
  }
  RemotingSourceStub.prototype.onStopped = function(reason) {
    return this.delegate_ && this.delegate_.onStopped && this.delegate_.onStopped(reason);
  }

  RemotingSourceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kRemotingSource_OnSinkAvailable_Name:
      var params = reader.decodeStruct(RemotingSource_OnSinkAvailable_Params);
      this.onSinkAvailable(params.capabilities);
      return true;
    case kRemotingSource_OnSinkGone_Name:
      var params = reader.decodeStruct(RemotingSource_OnSinkGone_Params);
      this.onSinkGone();
      return true;
    case kRemotingSource_OnStarted_Name:
      var params = reader.decodeStruct(RemotingSource_OnStarted_Params);
      this.onStarted();
      return true;
    case kRemotingSource_OnStartFailed_Name:
      var params = reader.decodeStruct(RemotingSource_OnStartFailed_Params);
      this.onStartFailed(params.reason);
      return true;
    case kRemotingSource_OnMessageFromSink_Name:
      var params = reader.decodeStruct(RemotingSource_OnMessageFromSink_Params);
      this.onMessageFromSink(params.message);
      return true;
    case kRemotingSource_OnStopped_Name:
      var params = reader.decodeStruct(RemotingSource_OnStopped_Params);
      this.onStopped(params.reason);
      return true;
    default:
      return false;
    }
  };

  RemotingSourceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateRemotingSourceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kRemotingSource_OnSinkAvailable_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingSource_OnSinkAvailable_Params;
      break;
      case kRemotingSource_OnSinkGone_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingSource_OnSinkGone_Params;
      break;
      case kRemotingSource_OnStarted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingSource_OnStarted_Params;
      break;
      case kRemotingSource_OnStartFailed_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingSource_OnStartFailed_Params;
      break;
      case kRemotingSource_OnMessageFromSink_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingSource_OnMessageFromSink_Params;
      break;
      case kRemotingSource_OnStopped_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = RemotingSource_OnStopped_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateRemotingSourceResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var RemotingSource = {
    name: 'media::mojom::RemotingSource',
    ptrClass: RemotingSourcePtr,
    proxyClass: RemotingSourceProxy,
    stubClass: RemotingSourceStub,
    validateRequest: validateRemotingSourceRequest,
    validateResponse: null,
  };
  RemotingSourceStub.prototype.validator = validateRemotingSourceRequest;
  RemotingSourceProxy.prototype.validator = null;

  var exports = {};
  exports.RemotingStopReason = RemotingStopReason;
  exports.RemotingSinkCapabilities = RemotingSinkCapabilities;
  exports.RemotingStartFailReason = RemotingStartFailReason;
  exports.RemoterFactory = RemoterFactory;
  exports.RemoterFactoryPtr = RemoterFactoryPtr;
  exports.RemotingDataStreamSender = RemotingDataStreamSender;
  exports.RemotingDataStreamSenderPtr = RemotingDataStreamSenderPtr;
  exports.Remoter = Remoter;
  exports.RemoterPtr = RemoterPtr;
  exports.RemotingSource = RemotingSource;
  exports.RemotingSourcePtr = RemotingSourcePtr;

  return exports;
});
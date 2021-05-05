// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("ui/events/mojo/latency_info.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "mojo/common/time.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, time$, geometry$) {
  var LatencyComponentType = {};
  LatencyComponentType.INPUT_EVENT_LATENCY_BEGIN_RWH_COMPONENT = 0;
  LatencyComponentType.LATENCY_BEGIN_SCROLL_LISTENER_UPDATE_MAIN_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_BEGIN_RWH_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_SCROLL_UPDATE_ORIGINAL_COMPONENT = LatencyComponentType.LATENCY_BEGIN_SCROLL_LISTENER_UPDATE_MAIN_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_FIRST_SCROLL_UPDATE_ORIGINAL_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_SCROLL_UPDATE_ORIGINAL_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_ORIGINAL_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_FIRST_SCROLL_UPDATE_ORIGINAL_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_UI_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_ORIGINAL_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_RENDERER_MAIN_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_UI_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_MAIN_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_RENDERER_MAIN_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_IMPL_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_MAIN_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_FORWARD_SCROLL_UPDATE_TO_MAIN_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_RENDERING_SCHEDULED_IMPL_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_ACK_RWH_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_FORWARD_SCROLL_UPDATE_TO_MAIN_COMPONENT + 1;
  LatencyComponentType.WINDOW_SNAPSHOT_FRAME_NUMBER_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_ACK_RWH_COMPONENT + 1;
  LatencyComponentType.TAB_SHOW_COMPONENT = LatencyComponentType.WINDOW_SNAPSHOT_FRAME_NUMBER_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_RENDERER_SWAP_COMPONENT = LatencyComponentType.TAB_SHOW_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_BROWSER_RECEIVED_RENDERER_SWAP_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_RENDERER_SWAP_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_GPU_SWAP_BUFFER_COMPONENT = LatencyComponentType.INPUT_EVENT_BROWSER_RECEIVED_RENDERER_SWAP_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_GENERATE_SCROLL_UPDATE_FROM_MOUSE_WHEEL = LatencyComponentType.INPUT_EVENT_GPU_SWAP_BUFFER_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_MOUSE_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_GENERATE_SCROLL_UPDATE_FROM_MOUSE_WHEEL + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_MOUSE_WHEEL_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_MOUSE_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_KEYBOARD_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_MOUSE_WHEEL_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_TOUCH_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_KEYBOARD_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_GESTURE_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_TOUCH_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_FRAME_SWAP_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_GESTURE_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_COMMIT_FAILED_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_FRAME_SWAP_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_COMMIT_NO_UPDATE_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_COMMIT_FAILED_COMPONENT + 1;
  LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_SWAP_FAILED_COMPONENT = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_COMMIT_NO_UPDATE_COMPONENT + 1;
  LatencyComponentType.LATENCY_COMPONENT_TYPE_LAST = LatencyComponentType.INPUT_EVENT_LATENCY_TERMINATED_SWAP_FAILED_COMPONENT;

  LatencyComponentType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
      return true;
    }
    return false;
  };

  LatencyComponentType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function LatencyComponentId(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LatencyComponentId.prototype.initDefaults_ = function() {
    this.type = 0;
    this.id = 0;
  };
  LatencyComponentId.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LatencyComponentId.validate = function(messageValidator, offset) {
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


    
    // validate LatencyComponentId.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, LatencyComponentType);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  LatencyComponentId.encodedSize = codec.kStructHeaderSize + 16;

  LatencyComponentId.decode = function(decoder) {
    var packed;
    var val = new LatencyComponentId();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.id = decoder.decodeStruct(codec.Int64);
    return val;
  };

  LatencyComponentId.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LatencyComponentId.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int64, val.id);
  };
  function LatencyComponent(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LatencyComponent.prototype.initDefaults_ = function() {
    this.sequence_number = 0;
    this.event_time = null;
    this.event_count = 0;
  };
  LatencyComponent.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LatencyComponent.validate = function(messageValidator, offset) {
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



    
    // validate LatencyComponent.event_time
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, time$.TimeTicks, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  LatencyComponent.encodedSize = codec.kStructHeaderSize + 24;

  LatencyComponent.decode = function(decoder) {
    var packed;
    var val = new LatencyComponent();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.sequence_number = decoder.decodeStruct(codec.Int64);
    val.event_time = decoder.decodeStructPointer(time$.TimeTicks);
    val.event_count = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LatencyComponent.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LatencyComponent.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int64, val.sequence_number);
    encoder.encodeStructPointer(time$.TimeTicks, val.event_time);
    encoder.encodeStruct(codec.Uint32, val.event_count);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function LatencyComponentPair(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LatencyComponentPair.prototype.initDefaults_ = function() {
    this.key = null;
    this.value = null;
  };
  LatencyComponentPair.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LatencyComponentPair.validate = function(messageValidator, offset) {
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


    
    // validate LatencyComponentPair.key
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, LatencyComponentId, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LatencyComponentPair.value
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, LatencyComponent, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  LatencyComponentPair.encodedSize = codec.kStructHeaderSize + 16;

  LatencyComponentPair.decode = function(decoder) {
    var packed;
    var val = new LatencyComponentPair();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeStructPointer(LatencyComponentId);
    val.value = decoder.decodeStructPointer(LatencyComponent);
    return val;
  };

  LatencyComponentPair.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LatencyComponentPair.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(LatencyComponentId, val.key);
    encoder.encodeStructPointer(LatencyComponent, val.value);
  };
  function LatencyInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  LatencyInfo.prototype.initDefaults_ = function() {
    this.trace_name = null;
    this.latency_components = null;
    this.input_coordinates = null;
    this.trace_id = 0;
    this.coalesced = false;
    this.terminated = false;
  };
  LatencyInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  LatencyInfo.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 48}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LatencyInfo.trace_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LatencyInfo.latency_components
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(LatencyComponentPair), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate LatencyInfo.input_coordinates
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(geometry$.PointF), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  LatencyInfo.encodedSize = codec.kStructHeaderSize + 40;

  LatencyInfo.decode = function(decoder) {
    var packed;
    var val = new LatencyInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.trace_name = decoder.decodeStruct(codec.String);
    val.latency_components = decoder.decodeArrayPointer(new codec.PointerTo(LatencyComponentPair));
    val.input_coordinates = decoder.decodeArrayPointer(new codec.PointerTo(geometry$.PointF));
    val.trace_id = decoder.decodeStruct(codec.Int64);
    packed = decoder.readUint8();
    val.coalesced = (packed >> 0) & 1 ? true : false;
    val.terminated = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  LatencyInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(LatencyInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.trace_name);
    encoder.encodeArrayPointer(new codec.PointerTo(LatencyComponentPair), val.latency_components);
    encoder.encodeArrayPointer(new codec.PointerTo(geometry$.PointF), val.input_coordinates);
    encoder.encodeStruct(codec.Int64, val.trace_id);
    packed = 0;
    packed |= (val.coalesced & 1) << 0
    packed |= (val.terminated & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.LatencyComponentType = LatencyComponentType;
  exports.LatencyComponentId = LatencyComponentId;
  exports.LatencyComponent = LatencyComponent;
  exports.LatencyComponentPair = LatencyComponentPair;
  exports.LatencyInfo = LatencyInfo;

  return exports;
});
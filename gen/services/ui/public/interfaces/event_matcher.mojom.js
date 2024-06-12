// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/event_matcher.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/events/mojo/event_constants.mojom",
    "ui/events/mojo/keyboard_codes.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, event_constants$, keyboard_codes$, geometry$) {

  function KeyEventMatcher(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  KeyEventMatcher.prototype.initDefaults_ = function() {
    this.keyboard_code = 0;
  };
  KeyEventMatcher.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  KeyEventMatcher.validate = function(messageValidator, offset) {
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


    
    // validate KeyEventMatcher.keyboard_code
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, keyboard_codes$.KeyboardCode);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  KeyEventMatcher.encodedSize = codec.kStructHeaderSize + 8;

  KeyEventMatcher.decode = function(decoder) {
    var packed;
    var val = new KeyEventMatcher();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.keyboard_code = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  KeyEventMatcher.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(KeyEventMatcher.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.keyboard_code);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PointerKindMatcher(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PointerKindMatcher.prototype.initDefaults_ = function() {
    this.pointer_kind = 0;
  };
  PointerKindMatcher.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PointerKindMatcher.validate = function(messageValidator, offset) {
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


    
    // validate PointerKindMatcher.pointer_kind
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, event_constants$.PointerKind);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PointerKindMatcher.encodedSize = codec.kStructHeaderSize + 8;

  PointerKindMatcher.decode = function(decoder) {
    var packed;
    var val = new PointerKindMatcher();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.pointer_kind = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PointerKindMatcher.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PointerKindMatcher.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.pointer_kind);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PointerLocationMatcher(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PointerLocationMatcher.prototype.initDefaults_ = function() {
    this.region = null;
  };
  PointerLocationMatcher.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PointerLocationMatcher.validate = function(messageValidator, offset) {
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


    
    // validate PointerLocationMatcher.region
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PointerLocationMatcher.encodedSize = codec.kStructHeaderSize + 8;

  PointerLocationMatcher.decode = function(decoder) {
    var packed;
    var val = new PointerLocationMatcher();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.region = decoder.decodeStructPointer(geometry$.RectF);
    return val;
  };

  PointerLocationMatcher.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PointerLocationMatcher.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.RectF, val.region);
  };
  function EventTypeMatcher(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  EventTypeMatcher.prototype.initDefaults_ = function() {
    this.type = 0;
  };
  EventTypeMatcher.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  EventTypeMatcher.validate = function(messageValidator, offset) {
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


    
    // validate EventTypeMatcher.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, event_constants$.EventType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  EventTypeMatcher.encodedSize = codec.kStructHeaderSize + 8;

  EventTypeMatcher.decode = function(decoder) {
    var packed;
    var val = new EventTypeMatcher();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  EventTypeMatcher.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(EventTypeMatcher.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function EventFlagsMatcher(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  EventFlagsMatcher.prototype.initDefaults_ = function() {
    this.flags = 0;
  };
  EventFlagsMatcher.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  EventFlagsMatcher.validate = function(messageValidator, offset) {
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

  EventFlagsMatcher.encodedSize = codec.kStructHeaderSize + 8;

  EventFlagsMatcher.decode = function(decoder) {
    var packed;
    var val = new EventFlagsMatcher();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.flags = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  EventFlagsMatcher.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(EventFlagsMatcher.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.flags);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function EventMatcher(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  EventMatcher.prototype.initDefaults_ = function() {
    this.accelerator_phase = 0;
    this.type_matcher = null;
    this.flags_matcher = null;
    this.ignore_flags_matcher = null;
    this.key_matcher = null;
    this.pointer_kind_matcher = null;
    this.pointer_location_matcher = null;
  };
  EventMatcher.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  EventMatcher.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 64}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EventMatcher.accelerator_phase
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, event_constants$.AcceleratorPhase);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EventMatcher.type_matcher
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, EventTypeMatcher, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EventMatcher.flags_matcher
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, EventFlagsMatcher, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EventMatcher.ignore_flags_matcher
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, EventFlagsMatcher, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EventMatcher.key_matcher
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, KeyEventMatcher, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EventMatcher.pointer_kind_matcher
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 40, PointerKindMatcher, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EventMatcher.pointer_location_matcher
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 48, PointerLocationMatcher, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  EventMatcher.encodedSize = codec.kStructHeaderSize + 56;

  EventMatcher.decode = function(decoder) {
    var packed;
    var val = new EventMatcher();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.accelerator_phase = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.type_matcher = decoder.decodeStructPointer(EventTypeMatcher);
    val.flags_matcher = decoder.decodeStructPointer(EventFlagsMatcher);
    val.ignore_flags_matcher = decoder.decodeStructPointer(EventFlagsMatcher);
    val.key_matcher = decoder.decodeStructPointer(KeyEventMatcher);
    val.pointer_kind_matcher = decoder.decodeStructPointer(PointerKindMatcher);
    val.pointer_location_matcher = decoder.decodeStructPointer(PointerLocationMatcher);
    return val;
  };

  EventMatcher.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(EventMatcher.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.accelerator_phase);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(EventTypeMatcher, val.type_matcher);
    encoder.encodeStructPointer(EventFlagsMatcher, val.flags_matcher);
    encoder.encodeStructPointer(EventFlagsMatcher, val.ignore_flags_matcher);
    encoder.encodeStructPointer(KeyEventMatcher, val.key_matcher);
    encoder.encodeStructPointer(PointerKindMatcher, val.pointer_kind_matcher);
    encoder.encodeStructPointer(PointerLocationMatcher, val.pointer_location_matcher);
  };

  var exports = {};
  exports.KeyEventMatcher = KeyEventMatcher;
  exports.PointerKindMatcher = PointerKindMatcher;
  exports.PointerLocationMatcher = PointerLocationMatcher;
  exports.EventTypeMatcher = EventTypeMatcher;
  exports.EventFlagsMatcher = EventFlagsMatcher;
  exports.EventMatcher = EventMatcher;

  return exports;
});
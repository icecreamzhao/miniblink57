// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("third_party/WebKit/public/platform/modules/notifications/notification.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var NotificationActionType = {};
  NotificationActionType.BUTTON = 0;
  NotificationActionType.TEXT = NotificationActionType.BUTTON + 1;

  NotificationActionType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  NotificationActionType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var NotificationDirection = {};
  NotificationDirection.LEFT_TO_RIGHT = 0;
  NotificationDirection.RIGHT_TO_LEFT = NotificationDirection.LEFT_TO_RIGHT + 1;
  NotificationDirection.AUTO = NotificationDirection.RIGHT_TO_LEFT + 1;

  NotificationDirection.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  NotificationDirection.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function NotificationAction(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  NotificationAction.prototype.initDefaults_ = function() {
    this.type = 0;
    this.action = null;
    this.title = null;
    this.icon = null;
    this.placeholder = null;
  };
  NotificationAction.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  NotificationAction.validate = function(messageValidator, offset) {
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


    
    // validate NotificationAction.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, NotificationActionType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NotificationAction.action
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NotificationAction.title
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NotificationAction.icon
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate NotificationAction.placeholder
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  NotificationAction.encodedSize = codec.kStructHeaderSize + 40;

  NotificationAction.decode = function(decoder) {
    var packed;
    var val = new NotificationAction();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.action = decoder.decodeStruct(codec.String);
    val.title = decoder.decodeStruct(codec.String);
    val.icon = decoder.decodeStruct(codec.String);
    val.placeholder = decoder.decodeStruct(codec.NullableString);
    return val;
  };

  NotificationAction.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(NotificationAction.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.action);
    encoder.encodeStruct(codec.String, val.title);
    encoder.encodeStruct(codec.String, val.icon);
    encoder.encodeStruct(codec.NullableString, val.placeholder);
  };
  function Notification(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Notification.kMaximumDeveloperDataBytes = 1048576;
  Notification.prototype.initDefaults_ = function() {
    this.title = null;
    this.direction = 0;
    this.renotify = false;
    this.silent = false;
    this.require_interaction = false;
    this.lang = null;
    this.body = null;
    this.tag = null;
    this.icon = null;
    this.badge = null;
    this.vibration_pattern = null;
    this.timestamp = 0;
    this.data = null;
    this.actions = null;
  };
  Notification.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Notification.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 96}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.title
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, NotificationDirection);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.lang
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.body
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.tag
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.icon
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.badge
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 48, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.vibration_pattern
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 56, 4, codec.Uint32, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;






    
    // validate Notification.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 72, 1, codec.Int8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Notification.actions
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 80, 8, new codec.PointerTo(NotificationAction), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Notification.encodedSize = codec.kStructHeaderSize + 88;

  Notification.decode = function(decoder) {
    var packed;
    var val = new Notification();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.title = decoder.decodeStruct(codec.String);
    val.direction = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.renotify = (packed >> 0) & 1 ? true : false;
    val.silent = (packed >> 1) & 1 ? true : false;
    val.require_interaction = (packed >> 2) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.lang = decoder.decodeStruct(codec.NullableString);
    val.body = decoder.decodeStruct(codec.String);
    val.tag = decoder.decodeStruct(codec.String);
    val.icon = decoder.decodeStruct(codec.String);
    val.badge = decoder.decodeStruct(codec.String);
    val.vibration_pattern = decoder.decodeArrayPointer(codec.Uint32);
    val.timestamp = decoder.decodeStruct(codec.Double);
    val.data = decoder.decodeArrayPointer(codec.Int8);
    val.actions = decoder.decodeArrayPointer(new codec.PointerTo(NotificationAction));
    return val;
  };

  Notification.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Notification.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.title);
    encoder.encodeStruct(codec.Int32, val.direction);
    packed = 0;
    packed |= (val.renotify & 1) << 0
    packed |= (val.silent & 1) << 1
    packed |= (val.require_interaction & 1) << 2
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.NullableString, val.lang);
    encoder.encodeStruct(codec.String, val.body);
    encoder.encodeStruct(codec.String, val.tag);
    encoder.encodeStruct(codec.String, val.icon);
    encoder.encodeStruct(codec.String, val.badge);
    encoder.encodeArrayPointer(codec.Uint32, val.vibration_pattern);
    encoder.encodeStruct(codec.Double, val.timestamp);
    encoder.encodeArrayPointer(codec.Int8, val.data);
    encoder.encodeArrayPointer(new codec.PointerTo(NotificationAction), val.actions);
  };

  var exports = {};
  exports.NotificationActionType = NotificationActionType;
  exports.NotificationDirection = NotificationDirection;
  exports.NotificationAction = NotificationAction;
  exports.Notification = Notification;

  return exports;
});
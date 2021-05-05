// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/autofill/content/common/autofill_types.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "mojo/common/text_direction.mojom",
    "mojo/common/time.mojom",
    "url/mojo/origin.mojom",
    "url/mojo/url.mojom",
], function(bindings, codec, core, validator, text_direction$, time$, origin$, url$) {
  var CheckStatus = {};
  CheckStatus.NOT_CHECKABLE = 0;
  CheckStatus.CHECKABLE_BUT_UNCHECKED = CheckStatus.NOT_CHECKABLE + 1;
  CheckStatus.CHECKED = CheckStatus.CHECKABLE_BUT_UNCHECKED + 1;

  CheckStatus.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  CheckStatus.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var RoleAttribute = {};
  RoleAttribute.ROLE_ATTRIBUTE_PRESENTATION = 0;
  RoleAttribute.ROLE_ATTRIBUTE_OTHER = RoleAttribute.ROLE_ATTRIBUTE_PRESENTATION + 1;

  RoleAttribute.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  RoleAttribute.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var GenerationUploadStatus = {};
  GenerationUploadStatus.NO_SIGNAL_SENT = 0;
  GenerationUploadStatus.POSITIVE_SIGNAL_SENT = GenerationUploadStatus.NO_SIGNAL_SENT + 1;
  GenerationUploadStatus.NEGATIVE_SIGNAL_SENT = GenerationUploadStatus.POSITIVE_SIGNAL_SENT + 1;
  GenerationUploadStatus.UNKNOWN_STATUS = 10;

  GenerationUploadStatus.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 10:
      return true;
    }
    return false;
  };

  GenerationUploadStatus.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PasswordFormLayout = {};
  PasswordFormLayout.LAYOUT_OTHER = 0;
  PasswordFormLayout.LAYOUT_LOGIN_AND_SIGNUP = PasswordFormLayout.LAYOUT_OTHER + 1;

  PasswordFormLayout.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  PasswordFormLayout.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PasswordFormType = {};
  PasswordFormType.TYPE_MANUAL = 0;
  PasswordFormType.TYPE_GENERATED = PasswordFormType.TYPE_MANUAL + 1;
  PasswordFormType.TYPE_API = PasswordFormType.TYPE_GENERATED + 1;

  PasswordFormType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  PasswordFormType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PasswordFormScheme = {};
  PasswordFormScheme.SCHEME_HTML = 0;
  PasswordFormScheme.SCHEME_BASIC = PasswordFormScheme.SCHEME_HTML + 1;
  PasswordFormScheme.SCHEME_DIGEST = PasswordFormScheme.SCHEME_BASIC + 1;
  PasswordFormScheme.SCHEME_OTHER = PasswordFormScheme.SCHEME_DIGEST + 1;
  PasswordFormScheme.SCHEME_USERNAME_ONLY = PasswordFormScheme.SCHEME_OTHER + 1;

  PasswordFormScheme.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    }
    return false;
  };

  PasswordFormScheme.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PasswordFormFieldPredictionType = {};
  PasswordFormFieldPredictionType.PREDICTION_USERNAME = 0;
  PasswordFormFieldPredictionType.PREDICTION_CURRENT_PASSWORD = PasswordFormFieldPredictionType.PREDICTION_USERNAME + 1;
  PasswordFormFieldPredictionType.PREDICTION_NEW_PASSWORD = PasswordFormFieldPredictionType.PREDICTION_CURRENT_PASSWORD + 1;
  PasswordFormFieldPredictionType.PREDICTION_NOT_PASSWORD = PasswordFormFieldPredictionType.PREDICTION_NEW_PASSWORD + 1;

  PasswordFormFieldPredictionType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  PasswordFormFieldPredictionType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function FormFieldData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FormFieldData.prototype.initDefaults_ = function() {
    this.label = null;
    this.name = null;
    this.value = null;
    this.form_control_type = null;
    this.autocomplete_attribute = null;
    this.placeholder = null;
    this.css_classes = null;
    this.properties_mask = 0;
    this.is_autofilled = false;
    this.is_focusable = false;
    this.should_autocomplete = false;
    this.max_length = 0;
    this.check_status = 0;
    this.role = 0;
    this.text_direction = 0;
    this.option_values = null;
    this.option_contents = null;
  };
  FormFieldData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FormFieldData.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 112}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.label
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.form_control_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.autocomplete_attribute
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.placeholder
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.css_classes
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 48, false)
    if (err !== validator.validationError.NONE)
        return err;





    
    // validate FormFieldData.check_status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 72, CheckStatus);
    if (err !== validator.validationError.NONE)
        return err;




    
    // validate FormFieldData.role
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 76, RoleAttribute);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.text_direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 80, text_direction$.TextDirection);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.option_values
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 88, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldData.option_contents
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 96, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FormFieldData.encodedSize = codec.kStructHeaderSize + 104;

  FormFieldData.decode = function(decoder) {
    var packed;
    var val = new FormFieldData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.label = decoder.decodeStruct(codec.String);
    val.name = decoder.decodeStruct(codec.String);
    val.value = decoder.decodeStruct(codec.String);
    val.form_control_type = decoder.decodeStruct(codec.String);
    val.autocomplete_attribute = decoder.decodeStruct(codec.String);
    val.placeholder = decoder.decodeStruct(codec.String);
    val.css_classes = decoder.decodeStruct(codec.String);
    val.properties_mask = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.is_autofilled = (packed >> 0) & 1 ? true : false;
    val.is_focusable = (packed >> 1) & 1 ? true : false;
    val.should_autocomplete = (packed >> 2) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.max_length = decoder.decodeStruct(codec.Uint64);
    val.check_status = decoder.decodeStruct(codec.Int32);
    val.role = decoder.decodeStruct(codec.Int32);
    val.text_direction = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.option_values = decoder.decodeArrayPointer(codec.String);
    val.option_contents = decoder.decodeArrayPointer(codec.String);
    return val;
  };

  FormFieldData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FormFieldData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.label);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStruct(codec.String, val.value);
    encoder.encodeStruct(codec.String, val.form_control_type);
    encoder.encodeStruct(codec.String, val.autocomplete_attribute);
    encoder.encodeStruct(codec.String, val.placeholder);
    encoder.encodeStruct(codec.String, val.css_classes);
    encoder.encodeStruct(codec.Uint32, val.properties_mask);
    packed = 0;
    packed |= (val.is_autofilled & 1) << 0
    packed |= (val.is_focusable & 1) << 1
    packed |= (val.should_autocomplete & 1) << 2
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint64, val.max_length);
    encoder.encodeStruct(codec.Int32, val.check_status);
    encoder.encodeStruct(codec.Int32, val.role);
    encoder.encodeStruct(codec.Int32, val.text_direction);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.String, val.option_values);
    encoder.encodeArrayPointer(codec.String, val.option_contents);
  };
  function FormData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FormData.prototype.initDefaults_ = function() {
    this.name = null;
    this.origin = null;
    this.action = null;
    this.is_form_tag = false;
    this.is_formless_checkout = false;
    this.fields = null;
  };
  FormData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FormData.validate = function(messageValidator, offset) {
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


    
    // validate FormData.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormData.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormData.action
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;




    
    // validate FormData.fields
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 32, 8, new codec.PointerTo(FormFieldData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FormData.encodedSize = codec.kStructHeaderSize + 40;

  FormData.decode = function(decoder) {
    var packed;
    var val = new FormData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.origin = decoder.decodeStructPointer(url$.Url);
    val.action = decoder.decodeStructPointer(url$.Url);
    packed = decoder.readUint8();
    val.is_form_tag = (packed >> 0) & 1 ? true : false;
    val.is_formless_checkout = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.fields = decoder.decodeArrayPointer(new codec.PointerTo(FormFieldData));
    return val;
  };

  FormData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FormData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStructPointer(url$.Url, val.origin);
    encoder.encodeStructPointer(url$.Url, val.action);
    packed = 0;
    packed |= (val.is_form_tag & 1) << 0
    packed |= (val.is_formless_checkout & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(new codec.PointerTo(FormFieldData), val.fields);
  };
  function FormFieldDataPredictions(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FormFieldDataPredictions.prototype.initDefaults_ = function() {
    this.field = null;
    this.signature = null;
    this.heuristic_type = null;
    this.server_type = null;
    this.overall_type = null;
    this.parseable_name = null;
  };
  FormFieldDataPredictions.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FormFieldDataPredictions.validate = function(messageValidator, offset) {
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


    
    // validate FormFieldDataPredictions.field
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, FormFieldData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldDataPredictions.signature
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldDataPredictions.heuristic_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldDataPredictions.server_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldDataPredictions.overall_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormFieldDataPredictions.parseable_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FormFieldDataPredictions.encodedSize = codec.kStructHeaderSize + 48;

  FormFieldDataPredictions.decode = function(decoder) {
    var packed;
    var val = new FormFieldDataPredictions();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.field = decoder.decodeStructPointer(FormFieldData);
    val.signature = decoder.decodeStruct(codec.String);
    val.heuristic_type = decoder.decodeStruct(codec.String);
    val.server_type = decoder.decodeStruct(codec.String);
    val.overall_type = decoder.decodeStruct(codec.String);
    val.parseable_name = decoder.decodeStruct(codec.String);
    return val;
  };

  FormFieldDataPredictions.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FormFieldDataPredictions.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(FormFieldData, val.field);
    encoder.encodeStruct(codec.String, val.signature);
    encoder.encodeStruct(codec.String, val.heuristic_type);
    encoder.encodeStruct(codec.String, val.server_type);
    encoder.encodeStruct(codec.String, val.overall_type);
    encoder.encodeStruct(codec.String, val.parseable_name);
  };
  function FormDataPredictions(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FormDataPredictions.prototype.initDefaults_ = function() {
    this.data = null;
    this.signature = null;
    this.fields = null;
  };
  FormDataPredictions.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FormDataPredictions.validate = function(messageValidator, offset) {
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


    
    // validate FormDataPredictions.data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, FormData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormDataPredictions.signature
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormDataPredictions.fields
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(FormFieldDataPredictions), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FormDataPredictions.encodedSize = codec.kStructHeaderSize + 24;

  FormDataPredictions.decode = function(decoder) {
    var packed;
    var val = new FormDataPredictions();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.data = decoder.decodeStructPointer(FormData);
    val.signature = decoder.decodeStruct(codec.String);
    val.fields = decoder.decodeArrayPointer(new codec.PointerTo(FormFieldDataPredictions));
    return val;
  };

  FormDataPredictions.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FormDataPredictions.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(FormData, val.data);
    encoder.encodeStruct(codec.String, val.signature);
    encoder.encodeArrayPointer(new codec.PointerTo(FormFieldDataPredictions), val.fields);
  };
  function PasswordAndRealm(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordAndRealm.prototype.initDefaults_ = function() {
    this.password = null;
    this.realm = null;
  };
  PasswordAndRealm.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordAndRealm.validate = function(messageValidator, offset) {
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


    
    // validate PasswordAndRealm.password
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordAndRealm.realm
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordAndRealm.encodedSize = codec.kStructHeaderSize + 16;

  PasswordAndRealm.decode = function(decoder) {
    var packed;
    var val = new PasswordAndRealm();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.password = decoder.decodeStruct(codec.String);
    val.realm = decoder.decodeStruct(codec.String);
    return val;
  };

  PasswordAndRealm.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordAndRealm.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.password);
    encoder.encodeStruct(codec.String, val.realm);
  };
  function UsernamesCollectionKey(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  UsernamesCollectionKey.prototype.initDefaults_ = function() {
    this.username = null;
    this.password = null;
    this.realm = null;
  };
  UsernamesCollectionKey.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  UsernamesCollectionKey.validate = function(messageValidator, offset) {
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


    
    // validate UsernamesCollectionKey.username
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate UsernamesCollectionKey.password
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate UsernamesCollectionKey.realm
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  UsernamesCollectionKey.encodedSize = codec.kStructHeaderSize + 24;

  UsernamesCollectionKey.decode = function(decoder) {
    var packed;
    var val = new UsernamesCollectionKey();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.username = decoder.decodeStruct(codec.String);
    val.password = decoder.decodeStruct(codec.String);
    val.realm = decoder.decodeStruct(codec.String);
    return val;
  };

  UsernamesCollectionKey.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(UsernamesCollectionKey.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.username);
    encoder.encodeStruct(codec.String, val.password);
    encoder.encodeStruct(codec.String, val.realm);
  };
  function PasswordFormFillData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordFormFillData.prototype.initDefaults_ = function() {
    this.name = null;
    this.origin = null;
    this.action = null;
    this.username_field = null;
    this.password_field = null;
    this.preferred_realm = null;
    this.additional_logins = null;
    this.other_possible_usernames_keys = null;
    this.other_possible_usernames_values = null;
    this.wait_for_username = false;
    this.is_possible_change_password_form = false;
  };
  PasswordFormFillData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordFormFillData.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 88}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.action
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.username_field
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, FormFieldData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.password_field
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, FormFieldData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.preferred_realm
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.additional_logins
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 48, false, codec.String, new codec.PointerTo(PasswordAndRealm), false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.other_possible_usernames_keys
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 56, 8, new codec.PointerTo(UsernamesCollectionKey), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFillData.other_possible_usernames_values
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 64, 8, new codec.ArrayOf(codec.String), false, [0, 0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  PasswordFormFillData.encodedSize = codec.kStructHeaderSize + 80;

  PasswordFormFillData.decode = function(decoder) {
    var packed;
    var val = new PasswordFormFillData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.origin = decoder.decodeStructPointer(url$.Url);
    val.action = decoder.decodeStructPointer(url$.Url);
    val.username_field = decoder.decodeStructPointer(FormFieldData);
    val.password_field = decoder.decodeStructPointer(FormFieldData);
    val.preferred_realm = decoder.decodeStruct(codec.String);
    val.additional_logins = decoder.decodeMapPointer(codec.String, new codec.PointerTo(PasswordAndRealm));
    val.other_possible_usernames_keys = decoder.decodeArrayPointer(new codec.PointerTo(UsernamesCollectionKey));
    val.other_possible_usernames_values = decoder.decodeArrayPointer(new codec.ArrayOf(codec.String));
    packed = decoder.readUint8();
    val.wait_for_username = (packed >> 0) & 1 ? true : false;
    val.is_possible_change_password_form = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PasswordFormFillData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordFormFillData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStructPointer(url$.Url, val.origin);
    encoder.encodeStructPointer(url$.Url, val.action);
    encoder.encodeStructPointer(FormFieldData, val.username_field);
    encoder.encodeStructPointer(FormFieldData, val.password_field);
    encoder.encodeStruct(codec.String, val.preferred_realm);
    encoder.encodeMapPointer(codec.String, new codec.PointerTo(PasswordAndRealm), val.additional_logins);
    encoder.encodeArrayPointer(new codec.PointerTo(UsernamesCollectionKey), val.other_possible_usernames_keys);
    encoder.encodeArrayPointer(new codec.ArrayOf(codec.String), val.other_possible_usernames_values);
    packed = 0;
    packed |= (val.wait_for_username & 1) << 0
    packed |= (val.is_possible_change_password_form & 1) << 1
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PasswordFormGenerationData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordFormGenerationData.prototype.initDefaults_ = function() {
    this.form_signature = 0;
    this.field_signature = 0;
  };
  PasswordFormGenerationData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordFormGenerationData.validate = function(messageValidator, offset) {
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

  PasswordFormGenerationData.encodedSize = codec.kStructHeaderSize + 16;

  PasswordFormGenerationData.decode = function(decoder) {
    var packed;
    var val = new PasswordFormGenerationData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.form_signature = decoder.decodeStruct(codec.Uint64);
    val.field_signature = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PasswordFormGenerationData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordFormGenerationData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint64, val.form_signature);
    encoder.encodeStruct(codec.Uint32, val.field_signature);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PasswordForm(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordForm.prototype.initDefaults_ = function() {
    this.scheme = 0;
    this.username_marked_by_site = false;
    this.password_value_is_default = false;
    this.new_password_value_is_default = false;
    this.new_password_marked_by_site = false;
    this.preferred = false;
    this.blacklisted_by_user = false;
    this.skip_zero_click = false;
    this.was_parsed_using_autofill_predictions = false;
    this.is_public_suffix_match = false;
    this.is_affiliation_based_match = false;
    this.does_look_like_signup_form = false;
    this.signon_realm = null;
    this.origin_with_path = null;
    this.action = null;
    this.affiliated_web_realm = null;
    this.submit_element = null;
    this.username_element = null;
    this.username_value = null;
    this.other_possible_usernames = null;
    this.password_element = null;
    this.password_value = null;
    this.new_password_element = null;
    this.new_password_value = null;
    this.date_created = null;
    this.date_synced = null;
    this.type = 0;
    this.times_used = 0;
    this.form_data = null;
    this.generation_upload_status = 0;
    this.layout = 0;
    this.display_name = null;
    this.icon_url = null;
    this.federation_origin = null;
  };
  PasswordForm.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordForm.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 176}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.scheme
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PasswordFormScheme);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.signon_realm
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.origin_with_path
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.action
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.affiliated_web_realm
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.submit_element
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.username_element
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 48, false)
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordForm.username_value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 56, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.other_possible_usernames
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 64, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.password_element
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 72, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.password_value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 80, false)
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordForm.new_password_element
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 88, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.new_password_value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 96, false)
    if (err !== validator.validationError.NONE)
        return err;





    
    // validate PasswordForm.date_created
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 104, time$.Time, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.date_synced
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 112, time$.Time, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordForm.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 120, PasswordFormType);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordForm.form_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 128, FormData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.generation_upload_status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 136, GenerationUploadStatus);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.display_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 144, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.icon_url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 152, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordForm.federation_origin
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 160, origin$.Origin, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordForm.layout
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 140, PasswordFormLayout);
    if (err !== validator.validationError.NONE)
        return err;





    return validator.validationError.NONE;
  };

  PasswordForm.encodedSize = codec.kStructHeaderSize + 168;

  PasswordForm.decode = function(decoder) {
    var packed;
    var val = new PasswordForm();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.scheme = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.username_marked_by_site = (packed >> 0) & 1 ? true : false;
    val.password_value_is_default = (packed >> 1) & 1 ? true : false;
    val.new_password_value_is_default = (packed >> 2) & 1 ? true : false;
    val.new_password_marked_by_site = (packed >> 3) & 1 ? true : false;
    val.preferred = (packed >> 4) & 1 ? true : false;
    val.blacklisted_by_user = (packed >> 5) & 1 ? true : false;
    val.skip_zero_click = (packed >> 6) & 1 ? true : false;
    val.was_parsed_using_autofill_predictions = (packed >> 7) & 1 ? true : false;
    packed = decoder.readUint8();
    val.is_public_suffix_match = (packed >> 0) & 1 ? true : false;
    val.is_affiliation_based_match = (packed >> 1) & 1 ? true : false;
    val.does_look_like_signup_form = (packed >> 2) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    val.signon_realm = decoder.decodeStruct(codec.String);
    val.origin_with_path = decoder.decodeStructPointer(url$.Url);
    val.action = decoder.decodeStructPointer(url$.Url);
    val.affiliated_web_realm = decoder.decodeStruct(codec.String);
    val.submit_element = decoder.decodeStruct(codec.String);
    val.username_element = decoder.decodeStruct(codec.String);
    val.username_value = decoder.decodeStruct(codec.String);
    val.other_possible_usernames = decoder.decodeArrayPointer(codec.String);
    val.password_element = decoder.decodeStruct(codec.String);
    val.password_value = decoder.decodeStruct(codec.String);
    val.new_password_element = decoder.decodeStruct(codec.String);
    val.new_password_value = decoder.decodeStruct(codec.String);
    val.date_created = decoder.decodeStructPointer(time$.Time);
    val.date_synced = decoder.decodeStructPointer(time$.Time);
    val.type = decoder.decodeStruct(codec.Int32);
    val.times_used = decoder.decodeStruct(codec.Int32);
    val.form_data = decoder.decodeStructPointer(FormData);
    val.generation_upload_status = decoder.decodeStruct(codec.Int32);
    val.layout = decoder.decodeStruct(codec.Int32);
    val.display_name = decoder.decodeStruct(codec.String);
    val.icon_url = decoder.decodeStructPointer(url$.Url);
    val.federation_origin = decoder.decodeStructPointer(origin$.Origin);
    return val;
  };

  PasswordForm.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordForm.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.scheme);
    packed = 0;
    packed |= (val.username_marked_by_site & 1) << 0
    packed |= (val.password_value_is_default & 1) << 1
    packed |= (val.new_password_value_is_default & 1) << 2
    packed |= (val.new_password_marked_by_site & 1) << 3
    packed |= (val.preferred & 1) << 4
    packed |= (val.blacklisted_by_user & 1) << 5
    packed |= (val.skip_zero_click & 1) << 6
    packed |= (val.was_parsed_using_autofill_predictions & 1) << 7
    encoder.writeUint8(packed);
    packed = 0;
    packed |= (val.is_public_suffix_match & 1) << 0
    packed |= (val.is_affiliation_based_match & 1) << 1
    packed |= (val.does_look_like_signup_form & 1) << 2
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.signon_realm);
    encoder.encodeStructPointer(url$.Url, val.origin_with_path);
    encoder.encodeStructPointer(url$.Url, val.action);
    encoder.encodeStruct(codec.String, val.affiliated_web_realm);
    encoder.encodeStruct(codec.String, val.submit_element);
    encoder.encodeStruct(codec.String, val.username_element);
    encoder.encodeStruct(codec.String, val.username_value);
    encoder.encodeArrayPointer(codec.String, val.other_possible_usernames);
    encoder.encodeStruct(codec.String, val.password_element);
    encoder.encodeStruct(codec.String, val.password_value);
    encoder.encodeStruct(codec.String, val.new_password_element);
    encoder.encodeStruct(codec.String, val.new_password_value);
    encoder.encodeStructPointer(time$.Time, val.date_created);
    encoder.encodeStructPointer(time$.Time, val.date_synced);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.encodeStruct(codec.Int32, val.times_used);
    encoder.encodeStructPointer(FormData, val.form_data);
    encoder.encodeStruct(codec.Int32, val.generation_upload_status);
    encoder.encodeStruct(codec.Int32, val.layout);
    encoder.encodeStruct(codec.String, val.display_name);
    encoder.encodeStructPointer(url$.Url, val.icon_url);
    encoder.encodeStructPointer(origin$.Origin, val.federation_origin);
  };
  function PasswordFormFieldPredictionMap(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordFormFieldPredictionMap.prototype.initDefaults_ = function() {
    this.keys = null;
    this.values = null;
  };
  PasswordFormFieldPredictionMap.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordFormFieldPredictionMap.validate = function(messageValidator, offset) {
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


    
    // validate PasswordFormFieldPredictionMap.keys
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(FormFieldData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordFormFieldPredictionMap.values
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 4, new codec.Enum(PasswordFormFieldPredictionType), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordFormFieldPredictionMap.encodedSize = codec.kStructHeaderSize + 16;

  PasswordFormFieldPredictionMap.decode = function(decoder) {
    var packed;
    var val = new PasswordFormFieldPredictionMap();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.keys = decoder.decodeArrayPointer(new codec.PointerTo(FormFieldData));
    val.values = decoder.decodeArrayPointer(new codec.Enum(PasswordFormFieldPredictionType));
    return val;
  };

  PasswordFormFieldPredictionMap.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordFormFieldPredictionMap.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(FormFieldData), val.keys);
    encoder.encodeArrayPointer(new codec.Enum(PasswordFormFieldPredictionType), val.values);
  };
  function FormsPredictionsMap(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  FormsPredictionsMap.prototype.initDefaults_ = function() {
    this.keys = null;
    this.values = null;
  };
  FormsPredictionsMap.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  FormsPredictionsMap.validate = function(messageValidator, offset) {
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


    
    // validate FormsPredictionsMap.keys
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(FormData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate FormsPredictionsMap.values
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(PasswordFormFieldPredictionMap), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  FormsPredictionsMap.encodedSize = codec.kStructHeaderSize + 16;

  FormsPredictionsMap.decode = function(decoder) {
    var packed;
    var val = new FormsPredictionsMap();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.keys = decoder.decodeArrayPointer(new codec.PointerTo(FormData));
    val.values = decoder.decodeArrayPointer(new codec.PointerTo(PasswordFormFieldPredictionMap));
    return val;
  };

  FormsPredictionsMap.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(FormsPredictionsMap.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(FormData), val.keys);
    encoder.encodeArrayPointer(new codec.PointerTo(PasswordFormFieldPredictionMap), val.values);
  };

  var exports = {};
  exports.CheckStatus = CheckStatus;
  exports.RoleAttribute = RoleAttribute;
  exports.GenerationUploadStatus = GenerationUploadStatus;
  exports.PasswordFormLayout = PasswordFormLayout;
  exports.PasswordFormType = PasswordFormType;
  exports.PasswordFormScheme = PasswordFormScheme;
  exports.PasswordFormFieldPredictionType = PasswordFormFieldPredictionType;
  exports.FormFieldData = FormFieldData;
  exports.FormData = FormData;
  exports.FormFieldDataPredictions = FormFieldDataPredictions;
  exports.FormDataPredictions = FormDataPredictions;
  exports.PasswordAndRealm = PasswordAndRealm;
  exports.UsernamesCollectionKey = UsernamesCollectionKey;
  exports.PasswordFormFillData = PasswordFormFillData;
  exports.PasswordFormGenerationData = PasswordFormGenerationData;
  exports.PasswordForm = PasswordForm;
  exports.PasswordFormFieldPredictionMap = PasswordFormFieldPredictionMap;
  exports.FormsPredictionsMap = FormsPredictionsMap;

  return exports;
});
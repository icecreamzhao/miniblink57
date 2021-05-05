// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/ime/ime.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "mojo/common/text_direction.mojom",
    "ui/events/mojo/event.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
    "ui/gfx/range/mojo/range.mojom",
], function(bindings, codec, core, validator, text_direction$, event$, geometry$, range$) {
  var TextInputType = {};
  TextInputType.NONE = 0;
  TextInputType.TEXT = TextInputType.NONE + 1;
  TextInputType.PASSWORD = TextInputType.TEXT + 1;
  TextInputType.SEARCH = TextInputType.PASSWORD + 1;
  TextInputType.EMAIL = TextInputType.SEARCH + 1;
  TextInputType.NUMBER = TextInputType.EMAIL + 1;
  TextInputType.TELEPHONE = TextInputType.NUMBER + 1;
  TextInputType.URL = TextInputType.TELEPHONE + 1;
  TextInputType.DATE = TextInputType.URL + 1;
  TextInputType.TIME = TextInputType.DATE + 1;
  TextInputType.DATETIME = TextInputType.TIME + 1;
  TextInputType.DATETIME_LOCAL = TextInputType.DATETIME + 1;
  TextInputType.MONTH = TextInputType.DATETIME_LOCAL + 1;
  TextInputType.WEEK = TextInputType.MONTH + 1;
  TextInputType.TEXT_AREA = TextInputType.WEEK + 1;
  TextInputType.CONTENT_EDITABLE = TextInputType.TEXT_AREA + 1;
  TextInputType.DATETIME_FIELD = TextInputType.CONTENT_EDITABLE + 1;

  TextInputType.isKnownEnumValue = function(value) {
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
      return true;
    }
    return false;
  };

  TextInputType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var TextInputMode = {};
  TextInputMode.DEFAULT = 0;
  TextInputMode.VERBATIM = TextInputMode.DEFAULT + 1;
  TextInputMode.LATIN = TextInputMode.VERBATIM + 1;
  TextInputMode.LATIN_NAME = TextInputMode.LATIN + 1;
  TextInputMode.LATIN_PROSE = TextInputMode.LATIN_NAME + 1;
  TextInputMode.FULL_WIDTH_LATIN = TextInputMode.LATIN_PROSE + 1;
  TextInputMode.KANA = TextInputMode.FULL_WIDTH_LATIN + 1;
  TextInputMode.KANA_NAME = TextInputMode.KANA + 1;
  TextInputMode.KATAKANA = TextInputMode.KANA_NAME + 1;
  TextInputMode.NUMERIC = TextInputMode.KATAKANA + 1;
  TextInputMode.TEL = TextInputMode.NUMERIC + 1;
  TextInputMode.EMAIL = TextInputMode.TEL + 1;
  TextInputMode.URL = TextInputMode.EMAIL + 1;

  TextInputMode.isKnownEnumValue = function(value) {
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
      return true;
    }
    return false;
  };

  TextInputMode.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function CompositionUnderline(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CompositionUnderline.prototype.initDefaults_ = function() {
    this.start_offset = 0;
    this.end_offset = 0;
    this.thick = false;
    this.color = 0;
    this.background_color = 0;
  };
  CompositionUnderline.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CompositionUnderline.validate = function(messageValidator, offset) {
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






    return validator.validationError.NONE;
  };

  CompositionUnderline.encodedSize = codec.kStructHeaderSize + 24;

  CompositionUnderline.decode = function(decoder) {
    var packed;
    var val = new CompositionUnderline();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.start_offset = decoder.decodeStruct(codec.Uint32);
    val.end_offset = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.thick = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.color = decoder.decodeStruct(codec.Uint32);
    val.background_color = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  CompositionUnderline.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CompositionUnderline.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.start_offset);
    encoder.encodeStruct(codec.Uint32, val.end_offset);
    packed = 0;
    packed |= (val.thick & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.color);
    encoder.encodeStruct(codec.Uint32, val.background_color);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function CompositionText(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CompositionText.prototype.initDefaults_ = function() {
    this.text = null;
    this.underlines = null;
    this.selection = null;
  };
  CompositionText.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CompositionText.validate = function(messageValidator, offset) {
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


    
    // validate CompositionText.text
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CompositionText.underlines
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(CompositionUnderline), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CompositionText.selection
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, range$.Range, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  CompositionText.encodedSize = codec.kStructHeaderSize + 24;

  CompositionText.decode = function(decoder) {
    var packed;
    var val = new CompositionText();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.text = decoder.decodeStruct(codec.String);
    val.underlines = decoder.decodeArrayPointer(new codec.PointerTo(CompositionUnderline));
    val.selection = decoder.decodeStructPointer(range$.Range);
    return val;
  };

  CompositionText.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CompositionText.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.text);
    encoder.encodeArrayPointer(new codec.PointerTo(CompositionUnderline), val.underlines);
    encoder.encodeStructPointer(range$.Range, val.selection);
  };
  function StartSessionDetails(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  StartSessionDetails.prototype.initDefaults_ = function() {
    this.client = new TextInputClientPtr();
    this.input_method_request = new bindings.InterfaceRequest();
    this.text_input_type = 0;
    this.text_input_mode = 0;
    this.text_direction = 0;
    this.text_input_flags = 0;
    this.caret_bounds = null;
  };
  StartSessionDetails.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  StartSessionDetails.validate = function(messageValidator, offset) {
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


    
    // validate StartSessionDetails.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate StartSessionDetails.input_method_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate StartSessionDetails.text_input_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 12, TextInputType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate StartSessionDetails.text_input_mode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, TextInputMode);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate StartSessionDetails.text_direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 20, text_direction$.TextDirection);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate StartSessionDetails.caret_bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 32, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  StartSessionDetails.encodedSize = codec.kStructHeaderSize + 40;

  StartSessionDetails.decode = function(decoder) {
    var packed;
    var val = new StartSessionDetails();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(new codec.Interface(TextInputClientPtr));
    val.input_method_request = decoder.decodeStruct(codec.InterfaceRequest);
    val.text_input_type = decoder.decodeStruct(codec.Int32);
    val.text_input_mode = decoder.decodeStruct(codec.Int32);
    val.text_direction = decoder.decodeStruct(codec.Int32);
    val.text_input_flags = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.caret_bounds = decoder.decodeStructPointer(geometry$.Rect);
    return val;
  };

  StartSessionDetails.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(StartSessionDetails.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(TextInputClientPtr), val.client);
    encoder.encodeStruct(codec.InterfaceRequest, val.input_method_request);
    encoder.encodeStruct(codec.Int32, val.text_input_type);
    encoder.encodeStruct(codec.Int32, val.text_input_mode);
    encoder.encodeStruct(codec.Int32, val.text_direction);
    encoder.encodeStruct(codec.Int32, val.text_input_flags);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Rect, val.caret_bounds);
  };
  function IMEDriver_StartSession_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  IMEDriver_StartSession_Params.prototype.initDefaults_ = function() {
    this.session_id = 0;
    this.details = null;
  };
  IMEDriver_StartSession_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  IMEDriver_StartSession_Params.validate = function(messageValidator, offset) {
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



    
    // validate IMEDriver_StartSession_Params.details
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, StartSessionDetails, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  IMEDriver_StartSession_Params.encodedSize = codec.kStructHeaderSize + 16;

  IMEDriver_StartSession_Params.decode = function(decoder) {
    var packed;
    var val = new IMEDriver_StartSession_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.session_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.details = decoder.decodeStructPointer(StartSessionDetails);
    return val;
  };

  IMEDriver_StartSession_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(IMEDriver_StartSession_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.session_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(StartSessionDetails, val.details);
  };
  function IMEDriver_CancelSession_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  IMEDriver_CancelSession_Params.prototype.initDefaults_ = function() {
    this.session_id = 0;
  };
  IMEDriver_CancelSession_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  IMEDriver_CancelSession_Params.validate = function(messageValidator, offset) {
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

  IMEDriver_CancelSession_Params.encodedSize = codec.kStructHeaderSize + 8;

  IMEDriver_CancelSession_Params.decode = function(decoder) {
    var packed;
    var val = new IMEDriver_CancelSession_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.session_id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  IMEDriver_CancelSession_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(IMEDriver_CancelSession_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.session_id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function IMEServer_StartSession_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  IMEServer_StartSession_Params.prototype.initDefaults_ = function() {
    this.details = null;
  };
  IMEServer_StartSession_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  IMEServer_StartSession_Params.validate = function(messageValidator, offset) {
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


    
    // validate IMEServer_StartSession_Params.details
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, StartSessionDetails, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  IMEServer_StartSession_Params.encodedSize = codec.kStructHeaderSize + 8;

  IMEServer_StartSession_Params.decode = function(decoder) {
    var packed;
    var val = new IMEServer_StartSession_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.details = decoder.decodeStructPointer(StartSessionDetails);
    return val;
  };

  IMEServer_StartSession_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(IMEServer_StartSession_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(StartSessionDetails, val.details);
  };
  function IMERegistrar_RegisterDriver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  IMERegistrar_RegisterDriver_Params.prototype.initDefaults_ = function() {
    this.driver = new IMEDriverPtr();
  };
  IMERegistrar_RegisterDriver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  IMERegistrar_RegisterDriver_Params.validate = function(messageValidator, offset) {
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


    
    // validate IMERegistrar_RegisterDriver_Params.driver
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  IMERegistrar_RegisterDriver_Params.encodedSize = codec.kStructHeaderSize + 8;

  IMERegistrar_RegisterDriver_Params.decode = function(decoder) {
    var packed;
    var val = new IMERegistrar_RegisterDriver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.driver = decoder.decodeStruct(new codec.Interface(IMEDriverPtr));
    return val;
  };

  IMERegistrar_RegisterDriver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(IMERegistrar_RegisterDriver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(IMEDriverPtr), val.driver);
  };
  function InputMethod_OnTextInputTypeChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InputMethod_OnTextInputTypeChanged_Params.prototype.initDefaults_ = function() {
    this.text_input_type = 0;
  };
  InputMethod_OnTextInputTypeChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InputMethod_OnTextInputTypeChanged_Params.validate = function(messageValidator, offset) {
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


    
    // validate InputMethod_OnTextInputTypeChanged_Params.text_input_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, TextInputType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InputMethod_OnTextInputTypeChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  InputMethod_OnTextInputTypeChanged_Params.decode = function(decoder) {
    var packed;
    var val = new InputMethod_OnTextInputTypeChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.text_input_type = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  InputMethod_OnTextInputTypeChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InputMethod_OnTextInputTypeChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.text_input_type);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function InputMethod_OnCaretBoundsChanged_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InputMethod_OnCaretBoundsChanged_Params.prototype.initDefaults_ = function() {
    this.caret_bounds = null;
  };
  InputMethod_OnCaretBoundsChanged_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InputMethod_OnCaretBoundsChanged_Params.validate = function(messageValidator, offset) {
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


    
    // validate InputMethod_OnCaretBoundsChanged_Params.caret_bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.Rect, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InputMethod_OnCaretBoundsChanged_Params.encodedSize = codec.kStructHeaderSize + 8;

  InputMethod_OnCaretBoundsChanged_Params.decode = function(decoder) {
    var packed;
    var val = new InputMethod_OnCaretBoundsChanged_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.caret_bounds = decoder.decodeStructPointer(geometry$.Rect);
    return val;
  };

  InputMethod_OnCaretBoundsChanged_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InputMethod_OnCaretBoundsChanged_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.Rect, val.caret_bounds);
  };
  function InputMethod_ProcessKeyEvent_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InputMethod_ProcessKeyEvent_Params.prototype.initDefaults_ = function() {
    this.key_event = null;
  };
  InputMethod_ProcessKeyEvent_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InputMethod_ProcessKeyEvent_Params.validate = function(messageValidator, offset) {
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


    
    // validate InputMethod_ProcessKeyEvent_Params.key_event
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, event$.Event, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InputMethod_ProcessKeyEvent_Params.encodedSize = codec.kStructHeaderSize + 8;

  InputMethod_ProcessKeyEvent_Params.decode = function(decoder) {
    var packed;
    var val = new InputMethod_ProcessKeyEvent_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key_event = decoder.decodeStructPointer(event$.Event);
    return val;
  };

  InputMethod_ProcessKeyEvent_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InputMethod_ProcessKeyEvent_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(event$.Event, val.key_event);
  };
  function InputMethod_ProcessKeyEvent_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InputMethod_ProcessKeyEvent_ResponseParams.prototype.initDefaults_ = function() {
    this.handled = false;
  };
  InputMethod_ProcessKeyEvent_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InputMethod_ProcessKeyEvent_ResponseParams.validate = function(messageValidator, offset) {
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

  InputMethod_ProcessKeyEvent_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  InputMethod_ProcessKeyEvent_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new InputMethod_ProcessKeyEvent_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.handled = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  InputMethod_ProcessKeyEvent_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InputMethod_ProcessKeyEvent_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.handled & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function InputMethod_CancelComposition_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InputMethod_CancelComposition_Params.prototype.initDefaults_ = function() {
  };
  InputMethod_CancelComposition_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InputMethod_CancelComposition_Params.validate = function(messageValidator, offset) {
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

  InputMethod_CancelComposition_Params.encodedSize = codec.kStructHeaderSize + 0;

  InputMethod_CancelComposition_Params.decode = function(decoder) {
    var packed;
    var val = new InputMethod_CancelComposition_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  InputMethod_CancelComposition_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InputMethod_CancelComposition_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function TextInputClient_SetCompositionText_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextInputClient_SetCompositionText_Params.prototype.initDefaults_ = function() {
    this.composition = null;
  };
  TextInputClient_SetCompositionText_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextInputClient_SetCompositionText_Params.validate = function(messageValidator, offset) {
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


    
    // validate TextInputClient_SetCompositionText_Params.composition
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, CompositionText, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TextInputClient_SetCompositionText_Params.encodedSize = codec.kStructHeaderSize + 8;

  TextInputClient_SetCompositionText_Params.decode = function(decoder) {
    var packed;
    var val = new TextInputClient_SetCompositionText_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.composition = decoder.decodeStructPointer(CompositionText);
    return val;
  };

  TextInputClient_SetCompositionText_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextInputClient_SetCompositionText_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(CompositionText, val.composition);
  };
  function TextInputClient_ConfirmCompositionText_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextInputClient_ConfirmCompositionText_Params.prototype.initDefaults_ = function() {
  };
  TextInputClient_ConfirmCompositionText_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextInputClient_ConfirmCompositionText_Params.validate = function(messageValidator, offset) {
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

  TextInputClient_ConfirmCompositionText_Params.encodedSize = codec.kStructHeaderSize + 0;

  TextInputClient_ConfirmCompositionText_Params.decode = function(decoder) {
    var packed;
    var val = new TextInputClient_ConfirmCompositionText_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  TextInputClient_ConfirmCompositionText_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextInputClient_ConfirmCompositionText_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function TextInputClient_ClearCompositionText_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextInputClient_ClearCompositionText_Params.prototype.initDefaults_ = function() {
  };
  TextInputClient_ClearCompositionText_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextInputClient_ClearCompositionText_Params.validate = function(messageValidator, offset) {
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

  TextInputClient_ClearCompositionText_Params.encodedSize = codec.kStructHeaderSize + 0;

  TextInputClient_ClearCompositionText_Params.decode = function(decoder) {
    var packed;
    var val = new TextInputClient_ClearCompositionText_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  TextInputClient_ClearCompositionText_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextInputClient_ClearCompositionText_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function TextInputClient_InsertText_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextInputClient_InsertText_Params.prototype.initDefaults_ = function() {
    this.text = null;
  };
  TextInputClient_InsertText_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextInputClient_InsertText_Params.validate = function(messageValidator, offset) {
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


    
    // validate TextInputClient_InsertText_Params.text
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TextInputClient_InsertText_Params.encodedSize = codec.kStructHeaderSize + 8;

  TextInputClient_InsertText_Params.decode = function(decoder) {
    var packed;
    var val = new TextInputClient_InsertText_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.text = decoder.decodeStruct(codec.String);
    return val;
  };

  TextInputClient_InsertText_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextInputClient_InsertText_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.text);
  };
  function TextInputClient_InsertChar_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  TextInputClient_InsertChar_Params.prototype.initDefaults_ = function() {
    this.event = null;
  };
  TextInputClient_InsertChar_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  TextInputClient_InsertChar_Params.validate = function(messageValidator, offset) {
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


    
    // validate TextInputClient_InsertChar_Params.event
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, event$.Event, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  TextInputClient_InsertChar_Params.encodedSize = codec.kStructHeaderSize + 8;

  TextInputClient_InsertChar_Params.decode = function(decoder) {
    var packed;
    var val = new TextInputClient_InsertChar_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.event = decoder.decodeStructPointer(event$.Event);
    return val;
  };

  TextInputClient_InsertChar_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(TextInputClient_InsertChar_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(event$.Event, val.event);
  };
  var kIMEDriver_StartSession_Name = 0;
  var kIMEDriver_CancelSession_Name = 1;

  function IMEDriverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(IMEDriver,
                                                   handleOrPtrInfo);
  }

  function IMEDriverProxy(receiver) {
    this.receiver_ = receiver;
  }
  IMEDriverPtr.prototype.startSession = function() {
    return IMEDriverProxy.prototype.startSession
        .apply(this.ptr.getProxy(), arguments);
  };

  IMEDriverProxy.prototype.startSession = function(session_id, details) {
    var params = new IMEDriver_StartSession_Params();
    params.session_id = session_id;
    params.details = details;
    var builder = new codec.MessageBuilder(
        kIMEDriver_StartSession_Name,
        codec.align(IMEDriver_StartSession_Params.encodedSize));
    builder.encodeStruct(IMEDriver_StartSession_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  IMEDriverPtr.prototype.cancelSession = function() {
    return IMEDriverProxy.prototype.cancelSession
        .apply(this.ptr.getProxy(), arguments);
  };

  IMEDriverProxy.prototype.cancelSession = function(session_id) {
    var params = new IMEDriver_CancelSession_Params();
    params.session_id = session_id;
    var builder = new codec.MessageBuilder(
        kIMEDriver_CancelSession_Name,
        codec.align(IMEDriver_CancelSession_Params.encodedSize));
    builder.encodeStruct(IMEDriver_CancelSession_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function IMEDriverStub(delegate) {
    this.delegate_ = delegate;
  }
  IMEDriverStub.prototype.startSession = function(session_id, details) {
    return this.delegate_ && this.delegate_.startSession && this.delegate_.startSession(session_id, details);
  }
  IMEDriverStub.prototype.cancelSession = function(session_id) {
    return this.delegate_ && this.delegate_.cancelSession && this.delegate_.cancelSession(session_id);
  }

  IMEDriverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kIMEDriver_StartSession_Name:
      var params = reader.decodeStruct(IMEDriver_StartSession_Params);
      this.startSession(params.session_id, params.details);
      return true;
    case kIMEDriver_CancelSession_Name:
      var params = reader.decodeStruct(IMEDriver_CancelSession_Params);
      this.cancelSession(params.session_id);
      return true;
    default:
      return false;
    }
  };

  IMEDriverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateIMEDriverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kIMEDriver_StartSession_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = IMEDriver_StartSession_Params;
      break;
      case kIMEDriver_CancelSession_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = IMEDriver_CancelSession_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateIMEDriverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var IMEDriver = {
    name: 'ui::mojom::IMEDriver',
    ptrClass: IMEDriverPtr,
    proxyClass: IMEDriverProxy,
    stubClass: IMEDriverStub,
    validateRequest: validateIMEDriverRequest,
    validateResponse: null,
  };
  IMEDriverStub.prototype.validator = validateIMEDriverRequest;
  IMEDriverProxy.prototype.validator = null;
  var kIMEServer_StartSession_Name = 0;

  function IMEServerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(IMEServer,
                                                   handleOrPtrInfo);
  }

  function IMEServerProxy(receiver) {
    this.receiver_ = receiver;
  }
  IMEServerPtr.prototype.startSession = function() {
    return IMEServerProxy.prototype.startSession
        .apply(this.ptr.getProxy(), arguments);
  };

  IMEServerProxy.prototype.startSession = function(details) {
    var params = new IMEServer_StartSession_Params();
    params.details = details;
    var builder = new codec.MessageBuilder(
        kIMEServer_StartSession_Name,
        codec.align(IMEServer_StartSession_Params.encodedSize));
    builder.encodeStruct(IMEServer_StartSession_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function IMEServerStub(delegate) {
    this.delegate_ = delegate;
  }
  IMEServerStub.prototype.startSession = function(details) {
    return this.delegate_ && this.delegate_.startSession && this.delegate_.startSession(details);
  }

  IMEServerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kIMEServer_StartSession_Name:
      var params = reader.decodeStruct(IMEServer_StartSession_Params);
      this.startSession(params.details);
      return true;
    default:
      return false;
    }
  };

  IMEServerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateIMEServerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kIMEServer_StartSession_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = IMEServer_StartSession_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateIMEServerResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var IMEServer = {
    name: 'ui::mojom::IMEServer',
    ptrClass: IMEServerPtr,
    proxyClass: IMEServerProxy,
    stubClass: IMEServerStub,
    validateRequest: validateIMEServerRequest,
    validateResponse: null,
  };
  IMEServerStub.prototype.validator = validateIMEServerRequest;
  IMEServerProxy.prototype.validator = null;
  var kIMERegistrar_RegisterDriver_Name = 0;

  function IMERegistrarPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(IMERegistrar,
                                                   handleOrPtrInfo);
  }

  function IMERegistrarProxy(receiver) {
    this.receiver_ = receiver;
  }
  IMERegistrarPtr.prototype.registerDriver = function() {
    return IMERegistrarProxy.prototype.registerDriver
        .apply(this.ptr.getProxy(), arguments);
  };

  IMERegistrarProxy.prototype.registerDriver = function(driver) {
    var params = new IMERegistrar_RegisterDriver_Params();
    params.driver = driver;
    var builder = new codec.MessageBuilder(
        kIMERegistrar_RegisterDriver_Name,
        codec.align(IMERegistrar_RegisterDriver_Params.encodedSize));
    builder.encodeStruct(IMERegistrar_RegisterDriver_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function IMERegistrarStub(delegate) {
    this.delegate_ = delegate;
  }
  IMERegistrarStub.prototype.registerDriver = function(driver) {
    return this.delegate_ && this.delegate_.registerDriver && this.delegate_.registerDriver(driver);
  }

  IMERegistrarStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kIMERegistrar_RegisterDriver_Name:
      var params = reader.decodeStruct(IMERegistrar_RegisterDriver_Params);
      this.registerDriver(params.driver);
      return true;
    default:
      return false;
    }
  };

  IMERegistrarStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateIMERegistrarRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kIMERegistrar_RegisterDriver_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = IMERegistrar_RegisterDriver_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateIMERegistrarResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var IMERegistrar = {
    name: 'ui::mojom::IMERegistrar',
    ptrClass: IMERegistrarPtr,
    proxyClass: IMERegistrarProxy,
    stubClass: IMERegistrarStub,
    validateRequest: validateIMERegistrarRequest,
    validateResponse: null,
  };
  IMERegistrarStub.prototype.validator = validateIMERegistrarRequest;
  IMERegistrarProxy.prototype.validator = null;
  var kInputMethod_OnTextInputTypeChanged_Name = 0;
  var kInputMethod_OnCaretBoundsChanged_Name = 1;
  var kInputMethod_ProcessKeyEvent_Name = 2;
  var kInputMethod_CancelComposition_Name = 3;

  function InputMethodPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(InputMethod,
                                                   handleOrPtrInfo);
  }

  function InputMethodProxy(receiver) {
    this.receiver_ = receiver;
  }
  InputMethodPtr.prototype.onTextInputTypeChanged = function() {
    return InputMethodProxy.prototype.onTextInputTypeChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  InputMethodProxy.prototype.onTextInputTypeChanged = function(text_input_type) {
    var params = new InputMethod_OnTextInputTypeChanged_Params();
    params.text_input_type = text_input_type;
    var builder = new codec.MessageBuilder(
        kInputMethod_OnTextInputTypeChanged_Name,
        codec.align(InputMethod_OnTextInputTypeChanged_Params.encodedSize));
    builder.encodeStruct(InputMethod_OnTextInputTypeChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  InputMethodPtr.prototype.onCaretBoundsChanged = function() {
    return InputMethodProxy.prototype.onCaretBoundsChanged
        .apply(this.ptr.getProxy(), arguments);
  };

  InputMethodProxy.prototype.onCaretBoundsChanged = function(caret_bounds) {
    var params = new InputMethod_OnCaretBoundsChanged_Params();
    params.caret_bounds = caret_bounds;
    var builder = new codec.MessageBuilder(
        kInputMethod_OnCaretBoundsChanged_Name,
        codec.align(InputMethod_OnCaretBoundsChanged_Params.encodedSize));
    builder.encodeStruct(InputMethod_OnCaretBoundsChanged_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  InputMethodPtr.prototype.processKeyEvent = function() {
    return InputMethodProxy.prototype.processKeyEvent
        .apply(this.ptr.getProxy(), arguments);
  };

  InputMethodProxy.prototype.processKeyEvent = function(key_event) {
    var params = new InputMethod_ProcessKeyEvent_Params();
    params.key_event = key_event;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kInputMethod_ProcessKeyEvent_Name,
          codec.align(InputMethod_ProcessKeyEvent_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(InputMethod_ProcessKeyEvent_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(InputMethod_ProcessKeyEvent_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  InputMethodPtr.prototype.cancelComposition = function() {
    return InputMethodProxy.prototype.cancelComposition
        .apply(this.ptr.getProxy(), arguments);
  };

  InputMethodProxy.prototype.cancelComposition = function() {
    var params = new InputMethod_CancelComposition_Params();
    var builder = new codec.MessageBuilder(
        kInputMethod_CancelComposition_Name,
        codec.align(InputMethod_CancelComposition_Params.encodedSize));
    builder.encodeStruct(InputMethod_CancelComposition_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function InputMethodStub(delegate) {
    this.delegate_ = delegate;
  }
  InputMethodStub.prototype.onTextInputTypeChanged = function(text_input_type) {
    return this.delegate_ && this.delegate_.onTextInputTypeChanged && this.delegate_.onTextInputTypeChanged(text_input_type);
  }
  InputMethodStub.prototype.onCaretBoundsChanged = function(caret_bounds) {
    return this.delegate_ && this.delegate_.onCaretBoundsChanged && this.delegate_.onCaretBoundsChanged(caret_bounds);
  }
  InputMethodStub.prototype.processKeyEvent = function(key_event) {
    return this.delegate_ && this.delegate_.processKeyEvent && this.delegate_.processKeyEvent(key_event);
  }
  InputMethodStub.prototype.cancelComposition = function() {
    return this.delegate_ && this.delegate_.cancelComposition && this.delegate_.cancelComposition();
  }

  InputMethodStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kInputMethod_OnTextInputTypeChanged_Name:
      var params = reader.decodeStruct(InputMethod_OnTextInputTypeChanged_Params);
      this.onTextInputTypeChanged(params.text_input_type);
      return true;
    case kInputMethod_OnCaretBoundsChanged_Name:
      var params = reader.decodeStruct(InputMethod_OnCaretBoundsChanged_Params);
      this.onCaretBoundsChanged(params.caret_bounds);
      return true;
    case kInputMethod_CancelComposition_Name:
      var params = reader.decodeStruct(InputMethod_CancelComposition_Params);
      this.cancelComposition();
      return true;
    default:
      return false;
    }
  };

  InputMethodStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kInputMethod_ProcessKeyEvent_Name:
      var params = reader.decodeStruct(InputMethod_ProcessKeyEvent_Params);
      return this.processKeyEvent(params.key_event).then(function(response) {
        var responseParams =
            new InputMethod_ProcessKeyEvent_ResponseParams();
        responseParams.handled = response.handled;
        var builder = new codec.MessageWithRequestIDBuilder(
            kInputMethod_ProcessKeyEvent_Name,
            codec.align(InputMethod_ProcessKeyEvent_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(InputMethod_ProcessKeyEvent_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateInputMethodRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kInputMethod_OnTextInputTypeChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InputMethod_OnTextInputTypeChanged_Params;
      break;
      case kInputMethod_OnCaretBoundsChanged_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InputMethod_OnCaretBoundsChanged_Params;
      break;
      case kInputMethod_ProcessKeyEvent_Name:
        if (message.expectsResponse())
          paramsClass = InputMethod_ProcessKeyEvent_Params;
      break;
      case kInputMethod_CancelComposition_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = InputMethod_CancelComposition_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateInputMethodResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kInputMethod_ProcessKeyEvent_Name:
        if (message.isResponse())
          paramsClass = InputMethod_ProcessKeyEvent_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var InputMethod = {
    name: 'ui::mojom::InputMethod',
    ptrClass: InputMethodPtr,
    proxyClass: InputMethodProxy,
    stubClass: InputMethodStub,
    validateRequest: validateInputMethodRequest,
    validateResponse: validateInputMethodResponse,
  };
  InputMethodStub.prototype.validator = validateInputMethodRequest;
  InputMethodProxy.prototype.validator = validateInputMethodResponse;
  var kTextInputClient_SetCompositionText_Name = 0;
  var kTextInputClient_ConfirmCompositionText_Name = 1;
  var kTextInputClient_ClearCompositionText_Name = 2;
  var kTextInputClient_InsertText_Name = 3;
  var kTextInputClient_InsertChar_Name = 4;

  function TextInputClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(TextInputClient,
                                                   handleOrPtrInfo);
  }

  function TextInputClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  TextInputClientPtr.prototype.setCompositionText = function() {
    return TextInputClientProxy.prototype.setCompositionText
        .apply(this.ptr.getProxy(), arguments);
  };

  TextInputClientProxy.prototype.setCompositionText = function(composition) {
    var params = new TextInputClient_SetCompositionText_Params();
    params.composition = composition;
    var builder = new codec.MessageBuilder(
        kTextInputClient_SetCompositionText_Name,
        codec.align(TextInputClient_SetCompositionText_Params.encodedSize));
    builder.encodeStruct(TextInputClient_SetCompositionText_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  TextInputClientPtr.prototype.confirmCompositionText = function() {
    return TextInputClientProxy.prototype.confirmCompositionText
        .apply(this.ptr.getProxy(), arguments);
  };

  TextInputClientProxy.prototype.confirmCompositionText = function() {
    var params = new TextInputClient_ConfirmCompositionText_Params();
    var builder = new codec.MessageBuilder(
        kTextInputClient_ConfirmCompositionText_Name,
        codec.align(TextInputClient_ConfirmCompositionText_Params.encodedSize));
    builder.encodeStruct(TextInputClient_ConfirmCompositionText_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  TextInputClientPtr.prototype.clearCompositionText = function() {
    return TextInputClientProxy.prototype.clearCompositionText
        .apply(this.ptr.getProxy(), arguments);
  };

  TextInputClientProxy.prototype.clearCompositionText = function() {
    var params = new TextInputClient_ClearCompositionText_Params();
    var builder = new codec.MessageBuilder(
        kTextInputClient_ClearCompositionText_Name,
        codec.align(TextInputClient_ClearCompositionText_Params.encodedSize));
    builder.encodeStruct(TextInputClient_ClearCompositionText_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  TextInputClientPtr.prototype.insertText = function() {
    return TextInputClientProxy.prototype.insertText
        .apply(this.ptr.getProxy(), arguments);
  };

  TextInputClientProxy.prototype.insertText = function(text) {
    var params = new TextInputClient_InsertText_Params();
    params.text = text;
    var builder = new codec.MessageBuilder(
        kTextInputClient_InsertText_Name,
        codec.align(TextInputClient_InsertText_Params.encodedSize));
    builder.encodeStruct(TextInputClient_InsertText_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  TextInputClientPtr.prototype.insertChar = function() {
    return TextInputClientProxy.prototype.insertChar
        .apply(this.ptr.getProxy(), arguments);
  };

  TextInputClientProxy.prototype.insertChar = function(event) {
    var params = new TextInputClient_InsertChar_Params();
    params.event = event;
    var builder = new codec.MessageBuilder(
        kTextInputClient_InsertChar_Name,
        codec.align(TextInputClient_InsertChar_Params.encodedSize));
    builder.encodeStruct(TextInputClient_InsertChar_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function TextInputClientStub(delegate) {
    this.delegate_ = delegate;
  }
  TextInputClientStub.prototype.setCompositionText = function(composition) {
    return this.delegate_ && this.delegate_.setCompositionText && this.delegate_.setCompositionText(composition);
  }
  TextInputClientStub.prototype.confirmCompositionText = function() {
    return this.delegate_ && this.delegate_.confirmCompositionText && this.delegate_.confirmCompositionText();
  }
  TextInputClientStub.prototype.clearCompositionText = function() {
    return this.delegate_ && this.delegate_.clearCompositionText && this.delegate_.clearCompositionText();
  }
  TextInputClientStub.prototype.insertText = function(text) {
    return this.delegate_ && this.delegate_.insertText && this.delegate_.insertText(text);
  }
  TextInputClientStub.prototype.insertChar = function(event) {
    return this.delegate_ && this.delegate_.insertChar && this.delegate_.insertChar(event);
  }

  TextInputClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kTextInputClient_SetCompositionText_Name:
      var params = reader.decodeStruct(TextInputClient_SetCompositionText_Params);
      this.setCompositionText(params.composition);
      return true;
    case kTextInputClient_ConfirmCompositionText_Name:
      var params = reader.decodeStruct(TextInputClient_ConfirmCompositionText_Params);
      this.confirmCompositionText();
      return true;
    case kTextInputClient_ClearCompositionText_Name:
      var params = reader.decodeStruct(TextInputClient_ClearCompositionText_Params);
      this.clearCompositionText();
      return true;
    case kTextInputClient_InsertText_Name:
      var params = reader.decodeStruct(TextInputClient_InsertText_Params);
      this.insertText(params.text);
      return true;
    case kTextInputClient_InsertChar_Name:
      var params = reader.decodeStruct(TextInputClient_InsertChar_Params);
      this.insertChar(params.event);
      return true;
    default:
      return false;
    }
  };

  TextInputClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateTextInputClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kTextInputClient_SetCompositionText_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TextInputClient_SetCompositionText_Params;
      break;
      case kTextInputClient_ConfirmCompositionText_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TextInputClient_ConfirmCompositionText_Params;
      break;
      case kTextInputClient_ClearCompositionText_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TextInputClient_ClearCompositionText_Params;
      break;
      case kTextInputClient_InsertText_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TextInputClient_InsertText_Params;
      break;
      case kTextInputClient_InsertChar_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = TextInputClient_InsertChar_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateTextInputClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var TextInputClient = {
    name: 'ui::mojom::TextInputClient',
    ptrClass: TextInputClientPtr,
    proxyClass: TextInputClientProxy,
    stubClass: TextInputClientStub,
    validateRequest: validateTextInputClientRequest,
    validateResponse: null,
  };
  TextInputClientStub.prototype.validator = validateTextInputClientRequest;
  TextInputClientProxy.prototype.validator = null;

  var exports = {};
  exports.TextInputType = TextInputType;
  exports.TextInputMode = TextInputMode;
  exports.CompositionUnderline = CompositionUnderline;
  exports.CompositionText = CompositionText;
  exports.StartSessionDetails = StartSessionDetails;
  exports.IMEDriver = IMEDriver;
  exports.IMEDriverPtr = IMEDriverPtr;
  exports.IMEServer = IMEServer;
  exports.IMEServerPtr = IMEServerPtr;
  exports.IMERegistrar = IMERegistrar;
  exports.IMERegistrarPtr = IMERegistrarPtr;
  exports.InputMethod = InputMethod;
  exports.InputMethodPtr = InputMethodPtr;
  exports.TextInputClient = TextInputClient;
  exports.TextInputClientPtr = TextInputClientPtr;

  return exports;
});
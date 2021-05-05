// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/autofill/content/common/autofill_agent.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "components/autofill/content/common/autofill_types.mojom",
    "mojo/common/string16.mojom",
], function(bindings, codec, core, validator, autofill_types$, string16$) {

  function AutofillAgent_FirstUserGestureObservedInTab_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_FirstUserGestureObservedInTab_Params.prototype.initDefaults_ = function() {
  };
  AutofillAgent_FirstUserGestureObservedInTab_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_FirstUserGestureObservedInTab_Params.validate = function(messageValidator, offset) {
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

  AutofillAgent_FirstUserGestureObservedInTab_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillAgent_FirstUserGestureObservedInTab_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_FirstUserGestureObservedInTab_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillAgent_FirstUserGestureObservedInTab_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_FirstUserGestureObservedInTab_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillAgent_FillForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_FillForm_Params.prototype.initDefaults_ = function() {
    this.id = 0;
    this.form = null;
  };
  AutofillAgent_FillForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_FillForm_Params.validate = function(messageValidator, offset) {
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



    
    // validate AutofillAgent_FillForm_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, autofill_types$.FormData, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_FillForm_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillAgent_FillForm_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_FillForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.form = decoder.decodeStructPointer(autofill_types$.FormData);
    return val;
  };

  AutofillAgent_FillForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_FillForm_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(autofill_types$.FormData, val.form);
  };
  function AutofillAgent_PreviewForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_PreviewForm_Params.prototype.initDefaults_ = function() {
    this.id = 0;
    this.form = null;
  };
  AutofillAgent_PreviewForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_PreviewForm_Params.validate = function(messageValidator, offset) {
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



    
    // validate AutofillAgent_PreviewForm_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, autofill_types$.FormData, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_PreviewForm_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillAgent_PreviewForm_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_PreviewForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.form = decoder.decodeStructPointer(autofill_types$.FormData);
    return val;
  };

  AutofillAgent_PreviewForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_PreviewForm_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(autofill_types$.FormData, val.form);
  };
  function AutofillAgent_FieldTypePredictionsAvailable_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_FieldTypePredictionsAvailable_Params.prototype.initDefaults_ = function() {
    this.forms = null;
  };
  AutofillAgent_FieldTypePredictionsAvailable_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_FieldTypePredictionsAvailable_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillAgent_FieldTypePredictionsAvailable_Params.forms
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(autofill_types$.FormDataPredictions), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_FieldTypePredictionsAvailable_Params.encodedSize = codec.kStructHeaderSize + 8;

  AutofillAgent_FieldTypePredictionsAvailable_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_FieldTypePredictionsAvailable_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.forms = decoder.decodeArrayPointer(new codec.PointerTo(autofill_types$.FormDataPredictions));
    return val;
  };

  AutofillAgent_FieldTypePredictionsAvailable_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_FieldTypePredictionsAvailable_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(autofill_types$.FormDataPredictions), val.forms);
  };
  function AutofillAgent_ClearForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_ClearForm_Params.prototype.initDefaults_ = function() {
  };
  AutofillAgent_ClearForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_ClearForm_Params.validate = function(messageValidator, offset) {
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

  AutofillAgent_ClearForm_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillAgent_ClearForm_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_ClearForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillAgent_ClearForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_ClearForm_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillAgent_ClearPreviewedForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_ClearPreviewedForm_Params.prototype.initDefaults_ = function() {
  };
  AutofillAgent_ClearPreviewedForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_ClearPreviewedForm_Params.validate = function(messageValidator, offset) {
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

  AutofillAgent_ClearPreviewedForm_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillAgent_ClearPreviewedForm_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_ClearPreviewedForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillAgent_ClearPreviewedForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_ClearPreviewedForm_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillAgent_FillFieldWithValue_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_FillFieldWithValue_Params.prototype.initDefaults_ = function() {
    this.value = null;
  };
  AutofillAgent_FillFieldWithValue_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_FillFieldWithValue_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillAgent_FillFieldWithValue_Params.value
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_FillFieldWithValue_Params.encodedSize = codec.kStructHeaderSize + 8;

  AutofillAgent_FillFieldWithValue_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_FillFieldWithValue_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.value = decoder.decodeStructPointer(string16$.String16);
    return val;
  };

  AutofillAgent_FillFieldWithValue_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_FillFieldWithValue_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(string16$.String16, val.value);
  };
  function AutofillAgent_PreviewFieldWithValue_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_PreviewFieldWithValue_Params.prototype.initDefaults_ = function() {
    this.value = null;
  };
  AutofillAgent_PreviewFieldWithValue_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_PreviewFieldWithValue_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillAgent_PreviewFieldWithValue_Params.value
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_PreviewFieldWithValue_Params.encodedSize = codec.kStructHeaderSize + 8;

  AutofillAgent_PreviewFieldWithValue_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_PreviewFieldWithValue_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.value = decoder.decodeStructPointer(string16$.String16);
    return val;
  };

  AutofillAgent_PreviewFieldWithValue_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_PreviewFieldWithValue_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(string16$.String16, val.value);
  };
  function AutofillAgent_AcceptDataListSuggestion_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_AcceptDataListSuggestion_Params.prototype.initDefaults_ = function() {
    this.value = null;
  };
  AutofillAgent_AcceptDataListSuggestion_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_AcceptDataListSuggestion_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillAgent_AcceptDataListSuggestion_Params.value
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_AcceptDataListSuggestion_Params.encodedSize = codec.kStructHeaderSize + 8;

  AutofillAgent_AcceptDataListSuggestion_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_AcceptDataListSuggestion_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.value = decoder.decodeStructPointer(string16$.String16);
    return val;
  };

  AutofillAgent_AcceptDataListSuggestion_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_AcceptDataListSuggestion_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(string16$.String16, val.value);
  };
  function AutofillAgent_FillPasswordSuggestion_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_FillPasswordSuggestion_Params.prototype.initDefaults_ = function() {
    this.username = null;
    this.password = null;
  };
  AutofillAgent_FillPasswordSuggestion_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_FillPasswordSuggestion_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillAgent_FillPasswordSuggestion_Params.username
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillAgent_FillPasswordSuggestion_Params.password
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_FillPasswordSuggestion_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillAgent_FillPasswordSuggestion_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_FillPasswordSuggestion_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.username = decoder.decodeStructPointer(string16$.String16);
    val.password = decoder.decodeStructPointer(string16$.String16);
    return val;
  };

  AutofillAgent_FillPasswordSuggestion_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_FillPasswordSuggestion_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(string16$.String16, val.username);
    encoder.encodeStructPointer(string16$.String16, val.password);
  };
  function AutofillAgent_PreviewPasswordSuggestion_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_PreviewPasswordSuggestion_Params.prototype.initDefaults_ = function() {
    this.username = null;
    this.password = null;
  };
  AutofillAgent_PreviewPasswordSuggestion_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_PreviewPasswordSuggestion_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillAgent_PreviewPasswordSuggestion_Params.username
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillAgent_PreviewPasswordSuggestion_Params.password
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_PreviewPasswordSuggestion_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillAgent_PreviewPasswordSuggestion_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_PreviewPasswordSuggestion_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.username = decoder.decodeStructPointer(string16$.String16);
    val.password = decoder.decodeStructPointer(string16$.String16);
    return val;
  };

  AutofillAgent_PreviewPasswordSuggestion_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_PreviewPasswordSuggestion_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(string16$.String16, val.username);
    encoder.encodeStructPointer(string16$.String16, val.password);
  };
  function AutofillAgent_ShowInitialPasswordAccountSuggestions_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.prototype.initDefaults_ = function() {
    this.key = 0;
    this.form_data = null;
  };
  AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.validate = function(messageValidator, offset) {
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



    
    // validate AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.form_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, autofill_types$.PasswordFormFillData, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillAgent_ShowInitialPasswordAccountSuggestions_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.form_data = decoder.decodeStructPointer(autofill_types$.PasswordFormFillData);
    return val;
  };

  AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.key);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(autofill_types$.PasswordFormFillData, val.form_data);
  };
  function PasswordAutofillAgent_FillPasswordForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordAutofillAgent_FillPasswordForm_Params.prototype.initDefaults_ = function() {
    this.key = 0;
    this.form_data = null;
  };
  PasswordAutofillAgent_FillPasswordForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordAutofillAgent_FillPasswordForm_Params.validate = function(messageValidator, offset) {
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



    
    // validate PasswordAutofillAgent_FillPasswordForm_Params.form_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, autofill_types$.PasswordFormFillData, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordAutofillAgent_FillPasswordForm_Params.encodedSize = codec.kStructHeaderSize + 16;

  PasswordAutofillAgent_FillPasswordForm_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordAutofillAgent_FillPasswordForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.form_data = decoder.decodeStructPointer(autofill_types$.PasswordFormFillData);
    return val;
  };

  PasswordAutofillAgent_FillPasswordForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordAutofillAgent_FillPasswordForm_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.key);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(autofill_types$.PasswordFormFillData, val.form_data);
  };
  function PasswordAutofillAgent_SetLoggingState_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordAutofillAgent_SetLoggingState_Params.prototype.initDefaults_ = function() {
    this.active = false;
  };
  PasswordAutofillAgent_SetLoggingState_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordAutofillAgent_SetLoggingState_Params.validate = function(messageValidator, offset) {
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

  PasswordAutofillAgent_SetLoggingState_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordAutofillAgent_SetLoggingState_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordAutofillAgent_SetLoggingState_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.active = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PasswordAutofillAgent_SetLoggingState_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordAutofillAgent_SetLoggingState_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.active & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.prototype.initDefaults_ = function() {
    this.predictions = null;
  };
  PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.predictions
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.FormsPredictionsMap, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.predictions = decoder.decodeStructPointer(autofill_types$.FormsPredictionsMap);
    return val;
  };

  PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.FormsPredictionsMap, val.predictions);
  };
  function PasswordAutofillAgent_FindFocusedPasswordForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordAutofillAgent_FindFocusedPasswordForm_Params.prototype.initDefaults_ = function() {
  };
  PasswordAutofillAgent_FindFocusedPasswordForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordAutofillAgent_FindFocusedPasswordForm_Params.validate = function(messageValidator, offset) {
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

  PasswordAutofillAgent_FindFocusedPasswordForm_Params.encodedSize = codec.kStructHeaderSize + 0;

  PasswordAutofillAgent_FindFocusedPasswordForm_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordAutofillAgent_FindFocusedPasswordForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PasswordAutofillAgent_FindFocusedPasswordForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordAutofillAgent_FindFocusedPasswordForm_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.prototype.initDefaults_ = function() {
    this.form = null;
  };
  PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.form);
  };
  function PasswordGenerationAgent_GeneratedPasswordAccepted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordGenerationAgent_GeneratedPasswordAccepted_Params.prototype.initDefaults_ = function() {
    this.generated_password = null;
  };
  PasswordGenerationAgent_GeneratedPasswordAccepted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordGenerationAgent_GeneratedPasswordAccepted_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordGenerationAgent_GeneratedPasswordAccepted_Params.generated_password
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordGenerationAgent_GeneratedPasswordAccepted_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordGenerationAgent_GeneratedPasswordAccepted_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordGenerationAgent_GeneratedPasswordAccepted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.generated_password = decoder.decodeStructPointer(string16$.String16);
    return val;
  };

  PasswordGenerationAgent_GeneratedPasswordAccepted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordGenerationAgent_GeneratedPasswordAccepted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(string16$.String16, val.generated_password);
  };
  function PasswordGenerationAgent_UserTriggeredGeneratePassword_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.prototype.initDefaults_ = function() {
  };
  PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.validate = function(messageValidator, offset) {
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

  PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.encodedSize = codec.kStructHeaderSize + 0;

  PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordGenerationAgent_UserTriggeredGeneratePassword_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function PasswordGenerationAgent_FormNotBlacklisted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordGenerationAgent_FormNotBlacklisted_Params.prototype.initDefaults_ = function() {
    this.form = null;
  };
  PasswordGenerationAgent_FormNotBlacklisted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordGenerationAgent_FormNotBlacklisted_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordGenerationAgent_FormNotBlacklisted_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordGenerationAgent_FormNotBlacklisted_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordGenerationAgent_FormNotBlacklisted_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordGenerationAgent_FormNotBlacklisted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordGenerationAgent_FormNotBlacklisted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordGenerationAgent_FormNotBlacklisted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.form);
  };
  function PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.prototype.initDefaults_ = function() {
    this.forms = null;
  };
  PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.forms
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(autofill_types$.PasswordFormGenerationData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.forms = decoder.decodeArrayPointer(new codec.PointerTo(autofill_types$.PasswordFormGenerationData));
    return val;
  };

  PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(autofill_types$.PasswordFormGenerationData), val.forms);
  };
  function PasswordGenerationAgent_AllowToRunFormClassifier_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordGenerationAgent_AllowToRunFormClassifier_Params.prototype.initDefaults_ = function() {
  };
  PasswordGenerationAgent_AllowToRunFormClassifier_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordGenerationAgent_AllowToRunFormClassifier_Params.validate = function(messageValidator, offset) {
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

  PasswordGenerationAgent_AllowToRunFormClassifier_Params.encodedSize = codec.kStructHeaderSize + 0;

  PasswordGenerationAgent_AllowToRunFormClassifier_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordGenerationAgent_AllowToRunFormClassifier_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PasswordGenerationAgent_AllowToRunFormClassifier_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordGenerationAgent_AllowToRunFormClassifier_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kAutofillAgent_FirstUserGestureObservedInTab_Name = 0;
  var kAutofillAgent_FillForm_Name = 1;
  var kAutofillAgent_PreviewForm_Name = 2;
  var kAutofillAgent_FieldTypePredictionsAvailable_Name = 3;
  var kAutofillAgent_ClearForm_Name = 4;
  var kAutofillAgent_ClearPreviewedForm_Name = 5;
  var kAutofillAgent_FillFieldWithValue_Name = 6;
  var kAutofillAgent_PreviewFieldWithValue_Name = 7;
  var kAutofillAgent_AcceptDataListSuggestion_Name = 8;
  var kAutofillAgent_FillPasswordSuggestion_Name = 9;
  var kAutofillAgent_PreviewPasswordSuggestion_Name = 10;
  var kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name = 11;

  function AutofillAgentPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(AutofillAgent,
                                                   handleOrPtrInfo);
  }

  function AutofillAgentProxy(receiver) {
    this.receiver_ = receiver;
  }
  AutofillAgentPtr.prototype.firstUserGestureObservedInTab = function() {
    return AutofillAgentProxy.prototype.firstUserGestureObservedInTab
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.firstUserGestureObservedInTab = function() {
    var params = new AutofillAgent_FirstUserGestureObservedInTab_Params();
    var builder = new codec.MessageBuilder(
        kAutofillAgent_FirstUserGestureObservedInTab_Name,
        codec.align(AutofillAgent_FirstUserGestureObservedInTab_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_FirstUserGestureObservedInTab_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.fillForm = function() {
    return AutofillAgentProxy.prototype.fillForm
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.fillForm = function(id, form) {
    var params = new AutofillAgent_FillForm_Params();
    params.id = id;
    params.form = form;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_FillForm_Name,
        codec.align(AutofillAgent_FillForm_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_FillForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.previewForm = function() {
    return AutofillAgentProxy.prototype.previewForm
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.previewForm = function(id, form) {
    var params = new AutofillAgent_PreviewForm_Params();
    params.id = id;
    params.form = form;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_PreviewForm_Name,
        codec.align(AutofillAgent_PreviewForm_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_PreviewForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.fieldTypePredictionsAvailable = function() {
    return AutofillAgentProxy.prototype.fieldTypePredictionsAvailable
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.fieldTypePredictionsAvailable = function(forms) {
    var params = new AutofillAgent_FieldTypePredictionsAvailable_Params();
    params.forms = forms;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_FieldTypePredictionsAvailable_Name,
        codec.align(AutofillAgent_FieldTypePredictionsAvailable_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_FieldTypePredictionsAvailable_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.clearForm = function() {
    return AutofillAgentProxy.prototype.clearForm
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.clearForm = function() {
    var params = new AutofillAgent_ClearForm_Params();
    var builder = new codec.MessageBuilder(
        kAutofillAgent_ClearForm_Name,
        codec.align(AutofillAgent_ClearForm_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_ClearForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.clearPreviewedForm = function() {
    return AutofillAgentProxy.prototype.clearPreviewedForm
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.clearPreviewedForm = function() {
    var params = new AutofillAgent_ClearPreviewedForm_Params();
    var builder = new codec.MessageBuilder(
        kAutofillAgent_ClearPreviewedForm_Name,
        codec.align(AutofillAgent_ClearPreviewedForm_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_ClearPreviewedForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.fillFieldWithValue = function() {
    return AutofillAgentProxy.prototype.fillFieldWithValue
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.fillFieldWithValue = function(value) {
    var params = new AutofillAgent_FillFieldWithValue_Params();
    params.value = value;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_FillFieldWithValue_Name,
        codec.align(AutofillAgent_FillFieldWithValue_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_FillFieldWithValue_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.previewFieldWithValue = function() {
    return AutofillAgentProxy.prototype.previewFieldWithValue
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.previewFieldWithValue = function(value) {
    var params = new AutofillAgent_PreviewFieldWithValue_Params();
    params.value = value;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_PreviewFieldWithValue_Name,
        codec.align(AutofillAgent_PreviewFieldWithValue_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_PreviewFieldWithValue_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.acceptDataListSuggestion = function() {
    return AutofillAgentProxy.prototype.acceptDataListSuggestion
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.acceptDataListSuggestion = function(value) {
    var params = new AutofillAgent_AcceptDataListSuggestion_Params();
    params.value = value;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_AcceptDataListSuggestion_Name,
        codec.align(AutofillAgent_AcceptDataListSuggestion_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_AcceptDataListSuggestion_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.fillPasswordSuggestion = function() {
    return AutofillAgentProxy.prototype.fillPasswordSuggestion
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.fillPasswordSuggestion = function(username, password) {
    var params = new AutofillAgent_FillPasswordSuggestion_Params();
    params.username = username;
    params.password = password;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_FillPasswordSuggestion_Name,
        codec.align(AutofillAgent_FillPasswordSuggestion_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_FillPasswordSuggestion_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.previewPasswordSuggestion = function() {
    return AutofillAgentProxy.prototype.previewPasswordSuggestion
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.previewPasswordSuggestion = function(username, password) {
    var params = new AutofillAgent_PreviewPasswordSuggestion_Params();
    params.username = username;
    params.password = password;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_PreviewPasswordSuggestion_Name,
        codec.align(AutofillAgent_PreviewPasswordSuggestion_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_PreviewPasswordSuggestion_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillAgentPtr.prototype.showInitialPasswordAccountSuggestions = function() {
    return AutofillAgentProxy.prototype.showInitialPasswordAccountSuggestions
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillAgentProxy.prototype.showInitialPasswordAccountSuggestions = function(key, form_data) {
    var params = new AutofillAgent_ShowInitialPasswordAccountSuggestions_Params();
    params.key = key;
    params.form_data = form_data;
    var builder = new codec.MessageBuilder(
        kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name,
        codec.align(AutofillAgent_ShowInitialPasswordAccountSuggestions_Params.encodedSize));
    builder.encodeStruct(AutofillAgent_ShowInitialPasswordAccountSuggestions_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function AutofillAgentStub(delegate) {
    this.delegate_ = delegate;
  }
  AutofillAgentStub.prototype.firstUserGestureObservedInTab = function() {
    return this.delegate_ && this.delegate_.firstUserGestureObservedInTab && this.delegate_.firstUserGestureObservedInTab();
  }
  AutofillAgentStub.prototype.fillForm = function(id, form) {
    return this.delegate_ && this.delegate_.fillForm && this.delegate_.fillForm(id, form);
  }
  AutofillAgentStub.prototype.previewForm = function(id, form) {
    return this.delegate_ && this.delegate_.previewForm && this.delegate_.previewForm(id, form);
  }
  AutofillAgentStub.prototype.fieldTypePredictionsAvailable = function(forms) {
    return this.delegate_ && this.delegate_.fieldTypePredictionsAvailable && this.delegate_.fieldTypePredictionsAvailable(forms);
  }
  AutofillAgentStub.prototype.clearForm = function() {
    return this.delegate_ && this.delegate_.clearForm && this.delegate_.clearForm();
  }
  AutofillAgentStub.prototype.clearPreviewedForm = function() {
    return this.delegate_ && this.delegate_.clearPreviewedForm && this.delegate_.clearPreviewedForm();
  }
  AutofillAgentStub.prototype.fillFieldWithValue = function(value) {
    return this.delegate_ && this.delegate_.fillFieldWithValue && this.delegate_.fillFieldWithValue(value);
  }
  AutofillAgentStub.prototype.previewFieldWithValue = function(value) {
    return this.delegate_ && this.delegate_.previewFieldWithValue && this.delegate_.previewFieldWithValue(value);
  }
  AutofillAgentStub.prototype.acceptDataListSuggestion = function(value) {
    return this.delegate_ && this.delegate_.acceptDataListSuggestion && this.delegate_.acceptDataListSuggestion(value);
  }
  AutofillAgentStub.prototype.fillPasswordSuggestion = function(username, password) {
    return this.delegate_ && this.delegate_.fillPasswordSuggestion && this.delegate_.fillPasswordSuggestion(username, password);
  }
  AutofillAgentStub.prototype.previewPasswordSuggestion = function(username, password) {
    return this.delegate_ && this.delegate_.previewPasswordSuggestion && this.delegate_.previewPasswordSuggestion(username, password);
  }
  AutofillAgentStub.prototype.showInitialPasswordAccountSuggestions = function(key, form_data) {
    return this.delegate_ && this.delegate_.showInitialPasswordAccountSuggestions && this.delegate_.showInitialPasswordAccountSuggestions(key, form_data);
  }

  AutofillAgentStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAutofillAgent_FirstUserGestureObservedInTab_Name:
      var params = reader.decodeStruct(AutofillAgent_FirstUserGestureObservedInTab_Params);
      this.firstUserGestureObservedInTab();
      return true;
    case kAutofillAgent_FillForm_Name:
      var params = reader.decodeStruct(AutofillAgent_FillForm_Params);
      this.fillForm(params.id, params.form);
      return true;
    case kAutofillAgent_PreviewForm_Name:
      var params = reader.decodeStruct(AutofillAgent_PreviewForm_Params);
      this.previewForm(params.id, params.form);
      return true;
    case kAutofillAgent_FieldTypePredictionsAvailable_Name:
      var params = reader.decodeStruct(AutofillAgent_FieldTypePredictionsAvailable_Params);
      this.fieldTypePredictionsAvailable(params.forms);
      return true;
    case kAutofillAgent_ClearForm_Name:
      var params = reader.decodeStruct(AutofillAgent_ClearForm_Params);
      this.clearForm();
      return true;
    case kAutofillAgent_ClearPreviewedForm_Name:
      var params = reader.decodeStruct(AutofillAgent_ClearPreviewedForm_Params);
      this.clearPreviewedForm();
      return true;
    case kAutofillAgent_FillFieldWithValue_Name:
      var params = reader.decodeStruct(AutofillAgent_FillFieldWithValue_Params);
      this.fillFieldWithValue(params.value);
      return true;
    case kAutofillAgent_PreviewFieldWithValue_Name:
      var params = reader.decodeStruct(AutofillAgent_PreviewFieldWithValue_Params);
      this.previewFieldWithValue(params.value);
      return true;
    case kAutofillAgent_AcceptDataListSuggestion_Name:
      var params = reader.decodeStruct(AutofillAgent_AcceptDataListSuggestion_Params);
      this.acceptDataListSuggestion(params.value);
      return true;
    case kAutofillAgent_FillPasswordSuggestion_Name:
      var params = reader.decodeStruct(AutofillAgent_FillPasswordSuggestion_Params);
      this.fillPasswordSuggestion(params.username, params.password);
      return true;
    case kAutofillAgent_PreviewPasswordSuggestion_Name:
      var params = reader.decodeStruct(AutofillAgent_PreviewPasswordSuggestion_Params);
      this.previewPasswordSuggestion(params.username, params.password);
      return true;
    case kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name:
      var params = reader.decodeStruct(AutofillAgent_ShowInitialPasswordAccountSuggestions_Params);
      this.showInitialPasswordAccountSuggestions(params.key, params.form_data);
      return true;
    default:
      return false;
    }
  };

  AutofillAgentStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateAutofillAgentRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kAutofillAgent_FirstUserGestureObservedInTab_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_FirstUserGestureObservedInTab_Params;
      break;
      case kAutofillAgent_FillForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_FillForm_Params;
      break;
      case kAutofillAgent_PreviewForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_PreviewForm_Params;
      break;
      case kAutofillAgent_FieldTypePredictionsAvailable_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_FieldTypePredictionsAvailable_Params;
      break;
      case kAutofillAgent_ClearForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_ClearForm_Params;
      break;
      case kAutofillAgent_ClearPreviewedForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_ClearPreviewedForm_Params;
      break;
      case kAutofillAgent_FillFieldWithValue_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_FillFieldWithValue_Params;
      break;
      case kAutofillAgent_PreviewFieldWithValue_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_PreviewFieldWithValue_Params;
      break;
      case kAutofillAgent_AcceptDataListSuggestion_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_AcceptDataListSuggestion_Params;
      break;
      case kAutofillAgent_FillPasswordSuggestion_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_FillPasswordSuggestion_Params;
      break;
      case kAutofillAgent_PreviewPasswordSuggestion_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_PreviewPasswordSuggestion_Params;
      break;
      case kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillAgent_ShowInitialPasswordAccountSuggestions_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateAutofillAgentResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var AutofillAgent = {
    name: 'autofill::mojom::AutofillAgent',
    ptrClass: AutofillAgentPtr,
    proxyClass: AutofillAgentProxy,
    stubClass: AutofillAgentStub,
    validateRequest: validateAutofillAgentRequest,
    validateResponse: null,
  };
  AutofillAgentStub.prototype.validator = validateAutofillAgentRequest;
  AutofillAgentProxy.prototype.validator = null;
  var kPasswordAutofillAgent_FillPasswordForm_Name = 0;
  var kPasswordAutofillAgent_SetLoggingState_Name = 1;
  var kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name = 2;
  var kPasswordAutofillAgent_FindFocusedPasswordForm_Name = 3;

  function PasswordAutofillAgentPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PasswordAutofillAgent,
                                                   handleOrPtrInfo);
  }

  function PasswordAutofillAgentProxy(receiver) {
    this.receiver_ = receiver;
  }
  PasswordAutofillAgentPtr.prototype.fillPasswordForm = function() {
    return PasswordAutofillAgentProxy.prototype.fillPasswordForm
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordAutofillAgentProxy.prototype.fillPasswordForm = function(key, form_data) {
    var params = new PasswordAutofillAgent_FillPasswordForm_Params();
    params.key = key;
    params.form_data = form_data;
    var builder = new codec.MessageBuilder(
        kPasswordAutofillAgent_FillPasswordForm_Name,
        codec.align(PasswordAutofillAgent_FillPasswordForm_Params.encodedSize));
    builder.encodeStruct(PasswordAutofillAgent_FillPasswordForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordAutofillAgentPtr.prototype.setLoggingState = function() {
    return PasswordAutofillAgentProxy.prototype.setLoggingState
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordAutofillAgentProxy.prototype.setLoggingState = function(active) {
    var params = new PasswordAutofillAgent_SetLoggingState_Params();
    params.active = active;
    var builder = new codec.MessageBuilder(
        kPasswordAutofillAgent_SetLoggingState_Name,
        codec.align(PasswordAutofillAgent_SetLoggingState_Params.encodedSize));
    builder.encodeStruct(PasswordAutofillAgent_SetLoggingState_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordAutofillAgentPtr.prototype.autofillUsernameAndPasswordDataReceived = function() {
    return PasswordAutofillAgentProxy.prototype.autofillUsernameAndPasswordDataReceived
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordAutofillAgentProxy.prototype.autofillUsernameAndPasswordDataReceived = function(predictions) {
    var params = new PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params();
    params.predictions = predictions;
    var builder = new codec.MessageBuilder(
        kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name,
        codec.align(PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params.encodedSize));
    builder.encodeStruct(PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordAutofillAgentPtr.prototype.findFocusedPasswordForm = function() {
    return PasswordAutofillAgentProxy.prototype.findFocusedPasswordForm
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordAutofillAgentProxy.prototype.findFocusedPasswordForm = function() {
    var params = new PasswordAutofillAgent_FindFocusedPasswordForm_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kPasswordAutofillAgent_FindFocusedPasswordForm_Name,
          codec.align(PasswordAutofillAgent_FindFocusedPasswordForm_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(PasswordAutofillAgent_FindFocusedPasswordForm_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function PasswordAutofillAgentStub(delegate) {
    this.delegate_ = delegate;
  }
  PasswordAutofillAgentStub.prototype.fillPasswordForm = function(key, form_data) {
    return this.delegate_ && this.delegate_.fillPasswordForm && this.delegate_.fillPasswordForm(key, form_data);
  }
  PasswordAutofillAgentStub.prototype.setLoggingState = function(active) {
    return this.delegate_ && this.delegate_.setLoggingState && this.delegate_.setLoggingState(active);
  }
  PasswordAutofillAgentStub.prototype.autofillUsernameAndPasswordDataReceived = function(predictions) {
    return this.delegate_ && this.delegate_.autofillUsernameAndPasswordDataReceived && this.delegate_.autofillUsernameAndPasswordDataReceived(predictions);
  }
  PasswordAutofillAgentStub.prototype.findFocusedPasswordForm = function() {
    return this.delegate_ && this.delegate_.findFocusedPasswordForm && this.delegate_.findFocusedPasswordForm();
  }

  PasswordAutofillAgentStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPasswordAutofillAgent_FillPasswordForm_Name:
      var params = reader.decodeStruct(PasswordAutofillAgent_FillPasswordForm_Params);
      this.fillPasswordForm(params.key, params.form_data);
      return true;
    case kPasswordAutofillAgent_SetLoggingState_Name:
      var params = reader.decodeStruct(PasswordAutofillAgent_SetLoggingState_Params);
      this.setLoggingState(params.active);
      return true;
    case kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name:
      var params = reader.decodeStruct(PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params);
      this.autofillUsernameAndPasswordDataReceived(params.predictions);
      return true;
    default:
      return false;
    }
  };

  PasswordAutofillAgentStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPasswordAutofillAgent_FindFocusedPasswordForm_Name:
      var params = reader.decodeStruct(PasswordAutofillAgent_FindFocusedPasswordForm_Params);
      return this.findFocusedPasswordForm().then(function(response) {
        var responseParams =
            new PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams();
        responseParams.form = response.form;
        var builder = new codec.MessageWithRequestIDBuilder(
            kPasswordAutofillAgent_FindFocusedPasswordForm_Name,
            codec.align(PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePasswordAutofillAgentRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPasswordAutofillAgent_FillPasswordForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordAutofillAgent_FillPasswordForm_Params;
      break;
      case kPasswordAutofillAgent_SetLoggingState_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordAutofillAgent_SetLoggingState_Params;
      break;
      case kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params;
      break;
      case kPasswordAutofillAgent_FindFocusedPasswordForm_Name:
        if (message.expectsResponse())
          paramsClass = PasswordAutofillAgent_FindFocusedPasswordForm_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePasswordAutofillAgentResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kPasswordAutofillAgent_FindFocusedPasswordForm_Name:
        if (message.isResponse())
          paramsClass = PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var PasswordAutofillAgent = {
    name: 'autofill::mojom::PasswordAutofillAgent',
    ptrClass: PasswordAutofillAgentPtr,
    proxyClass: PasswordAutofillAgentProxy,
    stubClass: PasswordAutofillAgentStub,
    validateRequest: validatePasswordAutofillAgentRequest,
    validateResponse: validatePasswordAutofillAgentResponse,
  };
  PasswordAutofillAgentStub.prototype.validator = validatePasswordAutofillAgentRequest;
  PasswordAutofillAgentProxy.prototype.validator = validatePasswordAutofillAgentResponse;
  var kPasswordGenerationAgent_GeneratedPasswordAccepted_Name = 0;
  var kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name = 1;
  var kPasswordGenerationAgent_FormNotBlacklisted_Name = 2;
  var kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name = 3;
  var kPasswordGenerationAgent_AllowToRunFormClassifier_Name = 4;

  function PasswordGenerationAgentPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PasswordGenerationAgent,
                                                   handleOrPtrInfo);
  }

  function PasswordGenerationAgentProxy(receiver) {
    this.receiver_ = receiver;
  }
  PasswordGenerationAgentPtr.prototype.generatedPasswordAccepted = function() {
    return PasswordGenerationAgentProxy.prototype.generatedPasswordAccepted
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordGenerationAgentProxy.prototype.generatedPasswordAccepted = function(generated_password) {
    var params = new PasswordGenerationAgent_GeneratedPasswordAccepted_Params();
    params.generated_password = generated_password;
    var builder = new codec.MessageBuilder(
        kPasswordGenerationAgent_GeneratedPasswordAccepted_Name,
        codec.align(PasswordGenerationAgent_GeneratedPasswordAccepted_Params.encodedSize));
    builder.encodeStruct(PasswordGenerationAgent_GeneratedPasswordAccepted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordGenerationAgentPtr.prototype.userTriggeredGeneratePassword = function() {
    return PasswordGenerationAgentProxy.prototype.userTriggeredGeneratePassword
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordGenerationAgentProxy.prototype.userTriggeredGeneratePassword = function() {
    var params = new PasswordGenerationAgent_UserTriggeredGeneratePassword_Params();
    var builder = new codec.MessageBuilder(
        kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name,
        codec.align(PasswordGenerationAgent_UserTriggeredGeneratePassword_Params.encodedSize));
    builder.encodeStruct(PasswordGenerationAgent_UserTriggeredGeneratePassword_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordGenerationAgentPtr.prototype.formNotBlacklisted = function() {
    return PasswordGenerationAgentProxy.prototype.formNotBlacklisted
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordGenerationAgentProxy.prototype.formNotBlacklisted = function(form) {
    var params = new PasswordGenerationAgent_FormNotBlacklisted_Params();
    params.form = form;
    var builder = new codec.MessageBuilder(
        kPasswordGenerationAgent_FormNotBlacklisted_Name,
        codec.align(PasswordGenerationAgent_FormNotBlacklisted_Params.encodedSize));
    builder.encodeStruct(PasswordGenerationAgent_FormNotBlacklisted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordGenerationAgentPtr.prototype.foundFormsEligibleForGeneration = function() {
    return PasswordGenerationAgentProxy.prototype.foundFormsEligibleForGeneration
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordGenerationAgentProxy.prototype.foundFormsEligibleForGeneration = function(forms) {
    var params = new PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params();
    params.forms = forms;
    var builder = new codec.MessageBuilder(
        kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name,
        codec.align(PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params.encodedSize));
    builder.encodeStruct(PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordGenerationAgentPtr.prototype.allowToRunFormClassifier = function() {
    return PasswordGenerationAgentProxy.prototype.allowToRunFormClassifier
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordGenerationAgentProxy.prototype.allowToRunFormClassifier = function() {
    var params = new PasswordGenerationAgent_AllowToRunFormClassifier_Params();
    var builder = new codec.MessageBuilder(
        kPasswordGenerationAgent_AllowToRunFormClassifier_Name,
        codec.align(PasswordGenerationAgent_AllowToRunFormClassifier_Params.encodedSize));
    builder.encodeStruct(PasswordGenerationAgent_AllowToRunFormClassifier_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PasswordGenerationAgentStub(delegate) {
    this.delegate_ = delegate;
  }
  PasswordGenerationAgentStub.prototype.generatedPasswordAccepted = function(generated_password) {
    return this.delegate_ && this.delegate_.generatedPasswordAccepted && this.delegate_.generatedPasswordAccepted(generated_password);
  }
  PasswordGenerationAgentStub.prototype.userTriggeredGeneratePassword = function() {
    return this.delegate_ && this.delegate_.userTriggeredGeneratePassword && this.delegate_.userTriggeredGeneratePassword();
  }
  PasswordGenerationAgentStub.prototype.formNotBlacklisted = function(form) {
    return this.delegate_ && this.delegate_.formNotBlacklisted && this.delegate_.formNotBlacklisted(form);
  }
  PasswordGenerationAgentStub.prototype.foundFormsEligibleForGeneration = function(forms) {
    return this.delegate_ && this.delegate_.foundFormsEligibleForGeneration && this.delegate_.foundFormsEligibleForGeneration(forms);
  }
  PasswordGenerationAgentStub.prototype.allowToRunFormClassifier = function() {
    return this.delegate_ && this.delegate_.allowToRunFormClassifier && this.delegate_.allowToRunFormClassifier();
  }

  PasswordGenerationAgentStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPasswordGenerationAgent_GeneratedPasswordAccepted_Name:
      var params = reader.decodeStruct(PasswordGenerationAgent_GeneratedPasswordAccepted_Params);
      this.generatedPasswordAccepted(params.generated_password);
      return true;
    case kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name:
      var params = reader.decodeStruct(PasswordGenerationAgent_UserTriggeredGeneratePassword_Params);
      this.userTriggeredGeneratePassword();
      return true;
    case kPasswordGenerationAgent_FormNotBlacklisted_Name:
      var params = reader.decodeStruct(PasswordGenerationAgent_FormNotBlacklisted_Params);
      this.formNotBlacklisted(params.form);
      return true;
    case kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name:
      var params = reader.decodeStruct(PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params);
      this.foundFormsEligibleForGeneration(params.forms);
      return true;
    case kPasswordGenerationAgent_AllowToRunFormClassifier_Name:
      var params = reader.decodeStruct(PasswordGenerationAgent_AllowToRunFormClassifier_Params);
      this.allowToRunFormClassifier();
      return true;
    default:
      return false;
    }
  };

  PasswordGenerationAgentStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePasswordGenerationAgentRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPasswordGenerationAgent_GeneratedPasswordAccepted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordGenerationAgent_GeneratedPasswordAccepted_Params;
      break;
      case kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordGenerationAgent_UserTriggeredGeneratePassword_Params;
      break;
      case kPasswordGenerationAgent_FormNotBlacklisted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordGenerationAgent_FormNotBlacklisted_Params;
      break;
      case kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params;
      break;
      case kPasswordGenerationAgent_AllowToRunFormClassifier_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordGenerationAgent_AllowToRunFormClassifier_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePasswordGenerationAgentResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PasswordGenerationAgent = {
    name: 'autofill::mojom::PasswordGenerationAgent',
    ptrClass: PasswordGenerationAgentPtr,
    proxyClass: PasswordGenerationAgentProxy,
    stubClass: PasswordGenerationAgentStub,
    validateRequest: validatePasswordGenerationAgentRequest,
    validateResponse: null,
  };
  PasswordGenerationAgentStub.prototype.validator = validatePasswordGenerationAgentRequest;
  PasswordGenerationAgentProxy.prototype.validator = null;

  var exports = {};
  exports.AutofillAgent = AutofillAgent;
  exports.AutofillAgentPtr = AutofillAgentPtr;
  exports.PasswordAutofillAgent = PasswordAutofillAgent;
  exports.PasswordAutofillAgentPtr = PasswordAutofillAgentPtr;
  exports.PasswordGenerationAgent = PasswordGenerationAgent;
  exports.PasswordGenerationAgentPtr = PasswordGenerationAgentPtr;

  return exports;
});
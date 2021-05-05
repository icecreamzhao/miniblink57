// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/autofill/content/common/autofill_driver.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "components/autofill/content/common/autofill_types.mojom",
    "mojo/common/string16.mojom",
    "mojo/common/text_direction.mojom",
    "mojo/common/time.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, autofill_types$, string16$, text_direction$, time$, geometry$) {

  function AutofillDriver_FirstUserGestureObserved_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_FirstUserGestureObserved_Params.prototype.initDefaults_ = function() {
  };
  AutofillDriver_FirstUserGestureObserved_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_FirstUserGestureObserved_Params.validate = function(messageValidator, offset) {
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

  AutofillDriver_FirstUserGestureObserved_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillDriver_FirstUserGestureObserved_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_FirstUserGestureObserved_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillDriver_FirstUserGestureObserved_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_FirstUserGestureObserved_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillDriver_FormsSeen_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_FormsSeen_Params.prototype.initDefaults_ = function() {
    this.forms = null;
    this.timestamp = null;
  };
  AutofillDriver_FormsSeen_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_FormsSeen_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillDriver_FormsSeen_Params.forms
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(autofill_types$.FormData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_FormsSeen_Params.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, time$.TimeTicks, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillDriver_FormsSeen_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillDriver_FormsSeen_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_FormsSeen_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.forms = decoder.decodeArrayPointer(new codec.PointerTo(autofill_types$.FormData));
    val.timestamp = decoder.decodeStructPointer(time$.TimeTicks);
    return val;
  };

  AutofillDriver_FormsSeen_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_FormsSeen_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(autofill_types$.FormData), val.forms);
    encoder.encodeStructPointer(time$.TimeTicks, val.timestamp);
  };
  function AutofillDriver_WillSubmitForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_WillSubmitForm_Params.prototype.initDefaults_ = function() {
    this.form = null;
    this.timestamp = null;
  };
  AutofillDriver_WillSubmitForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_WillSubmitForm_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillDriver_WillSubmitForm_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.FormData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_WillSubmitForm_Params.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, time$.TimeTicks, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillDriver_WillSubmitForm_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillDriver_WillSubmitForm_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_WillSubmitForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.form = decoder.decodeStructPointer(autofill_types$.FormData);
    val.timestamp = decoder.decodeStructPointer(time$.TimeTicks);
    return val;
  };

  AutofillDriver_WillSubmitForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_WillSubmitForm_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.FormData, val.form);
    encoder.encodeStructPointer(time$.TimeTicks, val.timestamp);
  };
  function AutofillDriver_FormSubmitted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_FormSubmitted_Params.prototype.initDefaults_ = function() {
    this.form = null;
  };
  AutofillDriver_FormSubmitted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_FormSubmitted_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillDriver_FormSubmitted_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.FormData, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillDriver_FormSubmitted_Params.encodedSize = codec.kStructHeaderSize + 8;

  AutofillDriver_FormSubmitted_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_FormSubmitted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.form = decoder.decodeStructPointer(autofill_types$.FormData);
    return val;
  };

  AutofillDriver_FormSubmitted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_FormSubmitted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.FormData, val.form);
  };
  function AutofillDriver_TextFieldDidChange_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_TextFieldDidChange_Params.prototype.initDefaults_ = function() {
    this.form = null;
    this.field = null;
    this.timestamp = null;
  };
  AutofillDriver_TextFieldDidChange_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_TextFieldDidChange_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillDriver_TextFieldDidChange_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.FormData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_TextFieldDidChange_Params.field
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, autofill_types$.FormFieldData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_TextFieldDidChange_Params.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, time$.TimeTicks, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillDriver_TextFieldDidChange_Params.encodedSize = codec.kStructHeaderSize + 24;

  AutofillDriver_TextFieldDidChange_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_TextFieldDidChange_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.form = decoder.decodeStructPointer(autofill_types$.FormData);
    val.field = decoder.decodeStructPointer(autofill_types$.FormFieldData);
    val.timestamp = decoder.decodeStructPointer(time$.TimeTicks);
    return val;
  };

  AutofillDriver_TextFieldDidChange_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_TextFieldDidChange_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.FormData, val.form);
    encoder.encodeStructPointer(autofill_types$.FormFieldData, val.field);
    encoder.encodeStructPointer(time$.TimeTicks, val.timestamp);
  };
  function AutofillDriver_QueryFormFieldAutofill_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_QueryFormFieldAutofill_Params.prototype.initDefaults_ = function() {
    this.id = 0;
    this.form = null;
    this.field = null;
    this.bounding_box = null;
  };
  AutofillDriver_QueryFormFieldAutofill_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_QueryFormFieldAutofill_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 40}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate AutofillDriver_QueryFormFieldAutofill_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, autofill_types$.FormData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_QueryFormFieldAutofill_Params.field
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, autofill_types$.FormFieldData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_QueryFormFieldAutofill_Params.bounding_box
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillDriver_QueryFormFieldAutofill_Params.encodedSize = codec.kStructHeaderSize + 32;

  AutofillDriver_QueryFormFieldAutofill_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_QueryFormFieldAutofill_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.form = decoder.decodeStructPointer(autofill_types$.FormData);
    val.field = decoder.decodeStructPointer(autofill_types$.FormFieldData);
    val.bounding_box = decoder.decodeStructPointer(geometry$.RectF);
    return val;
  };

  AutofillDriver_QueryFormFieldAutofill_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_QueryFormFieldAutofill_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(autofill_types$.FormData, val.form);
    encoder.encodeStructPointer(autofill_types$.FormFieldData, val.field);
    encoder.encodeStructPointer(geometry$.RectF, val.bounding_box);
  };
  function AutofillDriver_HidePopup_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_HidePopup_Params.prototype.initDefaults_ = function() {
  };
  AutofillDriver_HidePopup_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_HidePopup_Params.validate = function(messageValidator, offset) {
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

  AutofillDriver_HidePopup_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillDriver_HidePopup_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_HidePopup_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillDriver_HidePopup_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_HidePopup_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillDriver_FocusNoLongerOnForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_FocusNoLongerOnForm_Params.prototype.initDefaults_ = function() {
  };
  AutofillDriver_FocusNoLongerOnForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_FocusNoLongerOnForm_Params.validate = function(messageValidator, offset) {
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

  AutofillDriver_FocusNoLongerOnForm_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillDriver_FocusNoLongerOnForm_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_FocusNoLongerOnForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillDriver_FocusNoLongerOnForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_FocusNoLongerOnForm_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillDriver_DidFillAutofillFormData_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_DidFillAutofillFormData_Params.prototype.initDefaults_ = function() {
    this.form = null;
    this.timestamp = null;
  };
  AutofillDriver_DidFillAutofillFormData_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_DidFillAutofillFormData_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillDriver_DidFillAutofillFormData_Params.form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.FormData, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_DidFillAutofillFormData_Params.timestamp
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, time$.TimeTicks, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillDriver_DidFillAutofillFormData_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillDriver_DidFillAutofillFormData_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_DidFillAutofillFormData_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.form = decoder.decodeStructPointer(autofill_types$.FormData);
    val.timestamp = decoder.decodeStructPointer(time$.TimeTicks);
    return val;
  };

  AutofillDriver_DidFillAutofillFormData_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_DidFillAutofillFormData_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.FormData, val.form);
    encoder.encodeStructPointer(time$.TimeTicks, val.timestamp);
  };
  function AutofillDriver_DidPreviewAutofillFormData_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_DidPreviewAutofillFormData_Params.prototype.initDefaults_ = function() {
  };
  AutofillDriver_DidPreviewAutofillFormData_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_DidPreviewAutofillFormData_Params.validate = function(messageValidator, offset) {
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

  AutofillDriver_DidPreviewAutofillFormData_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillDriver_DidPreviewAutofillFormData_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_DidPreviewAutofillFormData_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillDriver_DidPreviewAutofillFormData_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_DidPreviewAutofillFormData_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillDriver_DidEndTextFieldEditing_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_DidEndTextFieldEditing_Params.prototype.initDefaults_ = function() {
  };
  AutofillDriver_DidEndTextFieldEditing_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_DidEndTextFieldEditing_Params.validate = function(messageValidator, offset) {
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

  AutofillDriver_DidEndTextFieldEditing_Params.encodedSize = codec.kStructHeaderSize + 0;

  AutofillDriver_DidEndTextFieldEditing_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_DidEndTextFieldEditing_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AutofillDriver_DidEndTextFieldEditing_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_DidEndTextFieldEditing_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function AutofillDriver_SetDataList_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AutofillDriver_SetDataList_Params.prototype.initDefaults_ = function() {
    this.values = null;
    this.labels = null;
  };
  AutofillDriver_SetDataList_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AutofillDriver_SetDataList_Params.validate = function(messageValidator, offset) {
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


    
    // validate AutofillDriver_SetDataList_Params.values
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(string16$.String16), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AutofillDriver_SetDataList_Params.labels
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(string16$.String16), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AutofillDriver_SetDataList_Params.encodedSize = codec.kStructHeaderSize + 16;

  AutofillDriver_SetDataList_Params.decode = function(decoder) {
    var packed;
    var val = new AutofillDriver_SetDataList_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.values = decoder.decodeArrayPointer(new codec.PointerTo(string16$.String16));
    val.labels = decoder.decodeArrayPointer(new codec.PointerTo(string16$.String16));
    return val;
  };

  AutofillDriver_SetDataList_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AutofillDriver_SetDataList_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(string16$.String16), val.values);
    encoder.encodeArrayPointer(new codec.PointerTo(string16$.String16), val.labels);
  };
  function PasswordManagerDriver_PasswordFormsParsed_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_PasswordFormsParsed_Params.prototype.initDefaults_ = function() {
    this.forms = null;
  };
  PasswordManagerDriver_PasswordFormsParsed_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_PasswordFormsParsed_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_PasswordFormsParsed_Params.forms
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(autofill_types$.PasswordForm), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_PasswordFormsParsed_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordManagerDriver_PasswordFormsParsed_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_PasswordFormsParsed_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.forms = decoder.decodeArrayPointer(new codec.PointerTo(autofill_types$.PasswordForm));
    return val;
  };

  PasswordManagerDriver_PasswordFormsParsed_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_PasswordFormsParsed_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(autofill_types$.PasswordForm), val.forms);
  };
  function PasswordManagerDriver_PasswordFormsRendered_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_PasswordFormsRendered_Params.prototype.initDefaults_ = function() {
    this.visible_forms = null;
    this.did_stop_loading = false;
  };
  PasswordManagerDriver_PasswordFormsRendered_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_PasswordFormsRendered_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_PasswordFormsRendered_Params.visible_forms
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(autofill_types$.PasswordForm), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  PasswordManagerDriver_PasswordFormsRendered_Params.encodedSize = codec.kStructHeaderSize + 16;

  PasswordManagerDriver_PasswordFormsRendered_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_PasswordFormsRendered_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.visible_forms = decoder.decodeArrayPointer(new codec.PointerTo(autofill_types$.PasswordForm));
    packed = decoder.readUint8();
    val.did_stop_loading = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PasswordManagerDriver_PasswordFormsRendered_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_PasswordFormsRendered_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(autofill_types$.PasswordForm), val.visible_forms);
    packed = 0;
    packed |= (val.did_stop_loading & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PasswordManagerDriver_PasswordFormSubmitted_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_PasswordFormSubmitted_Params.prototype.initDefaults_ = function() {
    this.password_form = null;
  };
  PasswordManagerDriver_PasswordFormSubmitted_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_PasswordFormSubmitted_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_PasswordFormSubmitted_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_PasswordFormSubmitted_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordManagerDriver_PasswordFormSubmitted_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_PasswordFormSubmitted_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordManagerDriver_PasswordFormSubmitted_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_PasswordFormSubmitted_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
  };
  function PasswordManagerDriver_InPageNavigation_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_InPageNavigation_Params.prototype.initDefaults_ = function() {
    this.password_form = null;
  };
  PasswordManagerDriver_InPageNavigation_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_InPageNavigation_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_InPageNavigation_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_InPageNavigation_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordManagerDriver_InPageNavigation_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_InPageNavigation_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordManagerDriver_InPageNavigation_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_InPageNavigation_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
  };
  function PasswordManagerDriver_RecordSavePasswordProgress_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_RecordSavePasswordProgress_Params.prototype.initDefaults_ = function() {
    this.log = null;
  };
  PasswordManagerDriver_RecordSavePasswordProgress_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_RecordSavePasswordProgress_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_RecordSavePasswordProgress_Params.log
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_RecordSavePasswordProgress_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordManagerDriver_RecordSavePasswordProgress_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_RecordSavePasswordProgress_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.log = decoder.decodeStruct(codec.String);
    return val;
  };

  PasswordManagerDriver_RecordSavePasswordProgress_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_RecordSavePasswordProgress_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.log);
  };
  function PasswordManagerDriver_ShowPasswordSuggestions_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_ShowPasswordSuggestions_Params.prototype.initDefaults_ = function() {
    this.key = 0;
    this.text_direction = 0;
    this.typed_username = null;
    this.options = 0;
    this.bounds = null;
  };
  PasswordManagerDriver_ShowPasswordSuggestions_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_ShowPasswordSuggestions_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 40}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordManagerDriver_ShowPasswordSuggestions_Params.text_direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, text_direction$.TextDirection);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordManagerDriver_ShowPasswordSuggestions_Params.typed_username
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordManagerDriver_ShowPasswordSuggestions_Params.bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_ShowPasswordSuggestions_Params.encodedSize = codec.kStructHeaderSize + 32;

  PasswordManagerDriver_ShowPasswordSuggestions_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_ShowPasswordSuggestions_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeStruct(codec.Int32);
    val.text_direction = decoder.decodeStruct(codec.Int32);
    val.typed_username = decoder.decodeStructPointer(string16$.String16);
    val.options = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.bounds = decoder.decodeStructPointer(geometry$.RectF);
    return val;
  };

  PasswordManagerDriver_ShowPasswordSuggestions_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_ShowPasswordSuggestions_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.key);
    encoder.encodeStruct(codec.Int32, val.text_direction);
    encoder.encodeStructPointer(string16$.String16, val.typed_username);
    encoder.encodeStruct(codec.Int32, val.options);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.RectF, val.bounds);
  };
  function PasswordManagerDriver_ShowNotSecureWarning_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_ShowNotSecureWarning_Params.prototype.initDefaults_ = function() {
    this.text_direction = 0;
    this.bounds = null;
  };
  PasswordManagerDriver_ShowNotSecureWarning_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_ShowNotSecureWarning_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_ShowNotSecureWarning_Params.text_direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, text_direction$.TextDirection);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordManagerDriver_ShowNotSecureWarning_Params.bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_ShowNotSecureWarning_Params.encodedSize = codec.kStructHeaderSize + 16;

  PasswordManagerDriver_ShowNotSecureWarning_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_ShowNotSecureWarning_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.text_direction = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.bounds = decoder.decodeStructPointer(geometry$.RectF);
    return val;
  };

  PasswordManagerDriver_ShowNotSecureWarning_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_ShowNotSecureWarning_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.text_direction);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.RectF, val.bounds);
  };
  function PasswordManagerDriver_PresaveGeneratedPassword_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_PresaveGeneratedPassword_Params.prototype.initDefaults_ = function() {
    this.password_form = null;
  };
  PasswordManagerDriver_PresaveGeneratedPassword_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_PresaveGeneratedPassword_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_PresaveGeneratedPassword_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_PresaveGeneratedPassword_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordManagerDriver_PresaveGeneratedPassword_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_PresaveGeneratedPassword_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordManagerDriver_PresaveGeneratedPassword_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_PresaveGeneratedPassword_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
  };
  function PasswordManagerDriver_PasswordNoLongerGenerated_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_PasswordNoLongerGenerated_Params.prototype.initDefaults_ = function() {
    this.password_form = null;
  };
  PasswordManagerDriver_PasswordNoLongerGenerated_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_PasswordNoLongerGenerated_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_PasswordNoLongerGenerated_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_PasswordNoLongerGenerated_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordManagerDriver_PasswordNoLongerGenerated_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_PasswordNoLongerGenerated_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordManagerDriver_PasswordNoLongerGenerated_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_PasswordNoLongerGenerated_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
  };
  function PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.prototype.initDefaults_ = function() {
    this.password_form = null;
    this.generation_field = null;
  };
  PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.generation_field
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.encodedSize = codec.kStructHeaderSize + 16;

  PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    val.generation_field = decoder.decodeStructPointer(string16$.String16);
    return val;
  };

  PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
    encoder.encodeStructPointer(string16$.String16, val.generation_field);
  };
  function PasswordManagerClient_GenerationAvailableForForm_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerClient_GenerationAvailableForForm_Params.prototype.initDefaults_ = function() {
    this.password_form = null;
  };
  PasswordManagerClient_GenerationAvailableForForm_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerClient_GenerationAvailableForForm_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerClient_GenerationAvailableForForm_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerClient_GenerationAvailableForForm_Params.encodedSize = codec.kStructHeaderSize + 8;

  PasswordManagerClient_GenerationAvailableForForm_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerClient_GenerationAvailableForForm_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordManagerClient_GenerationAvailableForForm_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerClient_GenerationAvailableForForm_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
  };
  function PasswordManagerClient_ShowPasswordGenerationPopup_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerClient_ShowPasswordGenerationPopup_Params.prototype.initDefaults_ = function() {
    this.bounds = null;
    this.max_length = 0;
    this.is_manually_triggered = false;
    this.generation_element = null;
    this.password_form = null;
  };
  PasswordManagerClient_ShowPasswordGenerationPopup_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerClient_ShowPasswordGenerationPopup_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 40}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordManagerClient_ShowPasswordGenerationPopup_Params.bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordManagerClient_ShowPasswordGenerationPopup_Params.generation_element
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, string16$.String16, false);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PasswordManagerClient_ShowPasswordGenerationPopup_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerClient_ShowPasswordGenerationPopup_Params.encodedSize = codec.kStructHeaderSize + 32;

  PasswordManagerClient_ShowPasswordGenerationPopup_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerClient_ShowPasswordGenerationPopup_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.bounds = decoder.decodeStructPointer(geometry$.RectF);
    val.max_length = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.is_manually_triggered = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.generation_element = decoder.decodeStructPointer(string16$.String16);
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordManagerClient_ShowPasswordGenerationPopup_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerClient_ShowPasswordGenerationPopup_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.RectF, val.bounds);
    encoder.encodeStruct(codec.Int32, val.max_length);
    packed = 0;
    packed |= (val.is_manually_triggered & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(string16$.String16, val.generation_element);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
  };
  function PasswordManagerClient_ShowPasswordEditingPopup_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerClient_ShowPasswordEditingPopup_Params.prototype.initDefaults_ = function() {
    this.bounds = null;
    this.password_form = null;
  };
  PasswordManagerClient_ShowPasswordEditingPopup_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerClient_ShowPasswordEditingPopup_Params.validate = function(messageValidator, offset) {
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


    
    // validate PasswordManagerClient_ShowPasswordEditingPopup_Params.bounds
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, geometry$.RectF, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PasswordManagerClient_ShowPasswordEditingPopup_Params.password_form
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, autofill_types$.PasswordForm, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PasswordManagerClient_ShowPasswordEditingPopup_Params.encodedSize = codec.kStructHeaderSize + 16;

  PasswordManagerClient_ShowPasswordEditingPopup_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerClient_ShowPasswordEditingPopup_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.bounds = decoder.decodeStructPointer(geometry$.RectF);
    val.password_form = decoder.decodeStructPointer(autofill_types$.PasswordForm);
    return val;
  };

  PasswordManagerClient_ShowPasswordEditingPopup_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerClient_ShowPasswordEditingPopup_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(geometry$.RectF, val.bounds);
    encoder.encodeStructPointer(autofill_types$.PasswordForm, val.password_form);
  };
  function PasswordManagerClient_HidePasswordGenerationPopup_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PasswordManagerClient_HidePasswordGenerationPopup_Params.prototype.initDefaults_ = function() {
  };
  PasswordManagerClient_HidePasswordGenerationPopup_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PasswordManagerClient_HidePasswordGenerationPopup_Params.validate = function(messageValidator, offset) {
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

  PasswordManagerClient_HidePasswordGenerationPopup_Params.encodedSize = codec.kStructHeaderSize + 0;

  PasswordManagerClient_HidePasswordGenerationPopup_Params.decode = function(decoder) {
    var packed;
    var val = new PasswordManagerClient_HidePasswordGenerationPopup_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PasswordManagerClient_HidePasswordGenerationPopup_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PasswordManagerClient_HidePasswordGenerationPopup_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kAutofillDriver_FirstUserGestureObserved_Name = 0;
  var kAutofillDriver_FormsSeen_Name = 1;
  var kAutofillDriver_WillSubmitForm_Name = 2;
  var kAutofillDriver_FormSubmitted_Name = 3;
  var kAutofillDriver_TextFieldDidChange_Name = 4;
  var kAutofillDriver_QueryFormFieldAutofill_Name = 5;
  var kAutofillDriver_HidePopup_Name = 6;
  var kAutofillDriver_FocusNoLongerOnForm_Name = 7;
  var kAutofillDriver_DidFillAutofillFormData_Name = 8;
  var kAutofillDriver_DidPreviewAutofillFormData_Name = 9;
  var kAutofillDriver_DidEndTextFieldEditing_Name = 10;
  var kAutofillDriver_SetDataList_Name = 11;

  function AutofillDriverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(AutofillDriver,
                                                   handleOrPtrInfo);
  }

  function AutofillDriverProxy(receiver) {
    this.receiver_ = receiver;
  }
  AutofillDriverPtr.prototype.firstUserGestureObserved = function() {
    return AutofillDriverProxy.prototype.firstUserGestureObserved
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.firstUserGestureObserved = function() {
    var params = new AutofillDriver_FirstUserGestureObserved_Params();
    var builder = new codec.MessageBuilder(
        kAutofillDriver_FirstUserGestureObserved_Name,
        codec.align(AutofillDriver_FirstUserGestureObserved_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_FirstUserGestureObserved_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.formsSeen = function() {
    return AutofillDriverProxy.prototype.formsSeen
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.formsSeen = function(forms, timestamp) {
    var params = new AutofillDriver_FormsSeen_Params();
    params.forms = forms;
    params.timestamp = timestamp;
    var builder = new codec.MessageBuilder(
        kAutofillDriver_FormsSeen_Name,
        codec.align(AutofillDriver_FormsSeen_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_FormsSeen_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.willSubmitForm = function() {
    return AutofillDriverProxy.prototype.willSubmitForm
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.willSubmitForm = function(form, timestamp) {
    var params = new AutofillDriver_WillSubmitForm_Params();
    params.form = form;
    params.timestamp = timestamp;
    var builder = new codec.MessageBuilder(
        kAutofillDriver_WillSubmitForm_Name,
        codec.align(AutofillDriver_WillSubmitForm_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_WillSubmitForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.formSubmitted = function() {
    return AutofillDriverProxy.prototype.formSubmitted
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.formSubmitted = function(form) {
    var params = new AutofillDriver_FormSubmitted_Params();
    params.form = form;
    var builder = new codec.MessageBuilder(
        kAutofillDriver_FormSubmitted_Name,
        codec.align(AutofillDriver_FormSubmitted_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_FormSubmitted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.textFieldDidChange = function() {
    return AutofillDriverProxy.prototype.textFieldDidChange
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.textFieldDidChange = function(form, field, timestamp) {
    var params = new AutofillDriver_TextFieldDidChange_Params();
    params.form = form;
    params.field = field;
    params.timestamp = timestamp;
    var builder = new codec.MessageBuilder(
        kAutofillDriver_TextFieldDidChange_Name,
        codec.align(AutofillDriver_TextFieldDidChange_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_TextFieldDidChange_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.queryFormFieldAutofill = function() {
    return AutofillDriverProxy.prototype.queryFormFieldAutofill
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.queryFormFieldAutofill = function(id, form, field, bounding_box) {
    var params = new AutofillDriver_QueryFormFieldAutofill_Params();
    params.id = id;
    params.form = form;
    params.field = field;
    params.bounding_box = bounding_box;
    var builder = new codec.MessageBuilder(
        kAutofillDriver_QueryFormFieldAutofill_Name,
        codec.align(AutofillDriver_QueryFormFieldAutofill_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_QueryFormFieldAutofill_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.hidePopup = function() {
    return AutofillDriverProxy.prototype.hidePopup
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.hidePopup = function() {
    var params = new AutofillDriver_HidePopup_Params();
    var builder = new codec.MessageBuilder(
        kAutofillDriver_HidePopup_Name,
        codec.align(AutofillDriver_HidePopup_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_HidePopup_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.focusNoLongerOnForm = function() {
    return AutofillDriverProxy.prototype.focusNoLongerOnForm
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.focusNoLongerOnForm = function() {
    var params = new AutofillDriver_FocusNoLongerOnForm_Params();
    var builder = new codec.MessageBuilder(
        kAutofillDriver_FocusNoLongerOnForm_Name,
        codec.align(AutofillDriver_FocusNoLongerOnForm_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_FocusNoLongerOnForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.didFillAutofillFormData = function() {
    return AutofillDriverProxy.prototype.didFillAutofillFormData
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.didFillAutofillFormData = function(form, timestamp) {
    var params = new AutofillDriver_DidFillAutofillFormData_Params();
    params.form = form;
    params.timestamp = timestamp;
    var builder = new codec.MessageBuilder(
        kAutofillDriver_DidFillAutofillFormData_Name,
        codec.align(AutofillDriver_DidFillAutofillFormData_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_DidFillAutofillFormData_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.didPreviewAutofillFormData = function() {
    return AutofillDriverProxy.prototype.didPreviewAutofillFormData
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.didPreviewAutofillFormData = function() {
    var params = new AutofillDriver_DidPreviewAutofillFormData_Params();
    var builder = new codec.MessageBuilder(
        kAutofillDriver_DidPreviewAutofillFormData_Name,
        codec.align(AutofillDriver_DidPreviewAutofillFormData_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_DidPreviewAutofillFormData_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.didEndTextFieldEditing = function() {
    return AutofillDriverProxy.prototype.didEndTextFieldEditing
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.didEndTextFieldEditing = function() {
    var params = new AutofillDriver_DidEndTextFieldEditing_Params();
    var builder = new codec.MessageBuilder(
        kAutofillDriver_DidEndTextFieldEditing_Name,
        codec.align(AutofillDriver_DidEndTextFieldEditing_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_DidEndTextFieldEditing_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  AutofillDriverPtr.prototype.setDataList = function() {
    return AutofillDriverProxy.prototype.setDataList
        .apply(this.ptr.getProxy(), arguments);
  };

  AutofillDriverProxy.prototype.setDataList = function(values, labels) {
    var params = new AutofillDriver_SetDataList_Params();
    params.values = values;
    params.labels = labels;
    var builder = new codec.MessageBuilder(
        kAutofillDriver_SetDataList_Name,
        codec.align(AutofillDriver_SetDataList_Params.encodedSize));
    builder.encodeStruct(AutofillDriver_SetDataList_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function AutofillDriverStub(delegate) {
    this.delegate_ = delegate;
  }
  AutofillDriverStub.prototype.firstUserGestureObserved = function() {
    return this.delegate_ && this.delegate_.firstUserGestureObserved && this.delegate_.firstUserGestureObserved();
  }
  AutofillDriverStub.prototype.formsSeen = function(forms, timestamp) {
    return this.delegate_ && this.delegate_.formsSeen && this.delegate_.formsSeen(forms, timestamp);
  }
  AutofillDriverStub.prototype.willSubmitForm = function(form, timestamp) {
    return this.delegate_ && this.delegate_.willSubmitForm && this.delegate_.willSubmitForm(form, timestamp);
  }
  AutofillDriverStub.prototype.formSubmitted = function(form) {
    return this.delegate_ && this.delegate_.formSubmitted && this.delegate_.formSubmitted(form);
  }
  AutofillDriverStub.prototype.textFieldDidChange = function(form, field, timestamp) {
    return this.delegate_ && this.delegate_.textFieldDidChange && this.delegate_.textFieldDidChange(form, field, timestamp);
  }
  AutofillDriverStub.prototype.queryFormFieldAutofill = function(id, form, field, bounding_box) {
    return this.delegate_ && this.delegate_.queryFormFieldAutofill && this.delegate_.queryFormFieldAutofill(id, form, field, bounding_box);
  }
  AutofillDriverStub.prototype.hidePopup = function() {
    return this.delegate_ && this.delegate_.hidePopup && this.delegate_.hidePopup();
  }
  AutofillDriverStub.prototype.focusNoLongerOnForm = function() {
    return this.delegate_ && this.delegate_.focusNoLongerOnForm && this.delegate_.focusNoLongerOnForm();
  }
  AutofillDriverStub.prototype.didFillAutofillFormData = function(form, timestamp) {
    return this.delegate_ && this.delegate_.didFillAutofillFormData && this.delegate_.didFillAutofillFormData(form, timestamp);
  }
  AutofillDriverStub.prototype.didPreviewAutofillFormData = function() {
    return this.delegate_ && this.delegate_.didPreviewAutofillFormData && this.delegate_.didPreviewAutofillFormData();
  }
  AutofillDriverStub.prototype.didEndTextFieldEditing = function() {
    return this.delegate_ && this.delegate_.didEndTextFieldEditing && this.delegate_.didEndTextFieldEditing();
  }
  AutofillDriverStub.prototype.setDataList = function(values, labels) {
    return this.delegate_ && this.delegate_.setDataList && this.delegate_.setDataList(values, labels);
  }

  AutofillDriverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kAutofillDriver_FirstUserGestureObserved_Name:
      var params = reader.decodeStruct(AutofillDriver_FirstUserGestureObserved_Params);
      this.firstUserGestureObserved();
      return true;
    case kAutofillDriver_FormsSeen_Name:
      var params = reader.decodeStruct(AutofillDriver_FormsSeen_Params);
      this.formsSeen(params.forms, params.timestamp);
      return true;
    case kAutofillDriver_WillSubmitForm_Name:
      var params = reader.decodeStruct(AutofillDriver_WillSubmitForm_Params);
      this.willSubmitForm(params.form, params.timestamp);
      return true;
    case kAutofillDriver_FormSubmitted_Name:
      var params = reader.decodeStruct(AutofillDriver_FormSubmitted_Params);
      this.formSubmitted(params.form);
      return true;
    case kAutofillDriver_TextFieldDidChange_Name:
      var params = reader.decodeStruct(AutofillDriver_TextFieldDidChange_Params);
      this.textFieldDidChange(params.form, params.field, params.timestamp);
      return true;
    case kAutofillDriver_QueryFormFieldAutofill_Name:
      var params = reader.decodeStruct(AutofillDriver_QueryFormFieldAutofill_Params);
      this.queryFormFieldAutofill(params.id, params.form, params.field, params.bounding_box);
      return true;
    case kAutofillDriver_HidePopup_Name:
      var params = reader.decodeStruct(AutofillDriver_HidePopup_Params);
      this.hidePopup();
      return true;
    case kAutofillDriver_FocusNoLongerOnForm_Name:
      var params = reader.decodeStruct(AutofillDriver_FocusNoLongerOnForm_Params);
      this.focusNoLongerOnForm();
      return true;
    case kAutofillDriver_DidFillAutofillFormData_Name:
      var params = reader.decodeStruct(AutofillDriver_DidFillAutofillFormData_Params);
      this.didFillAutofillFormData(params.form, params.timestamp);
      return true;
    case kAutofillDriver_DidPreviewAutofillFormData_Name:
      var params = reader.decodeStruct(AutofillDriver_DidPreviewAutofillFormData_Params);
      this.didPreviewAutofillFormData();
      return true;
    case kAutofillDriver_DidEndTextFieldEditing_Name:
      var params = reader.decodeStruct(AutofillDriver_DidEndTextFieldEditing_Params);
      this.didEndTextFieldEditing();
      return true;
    case kAutofillDriver_SetDataList_Name:
      var params = reader.decodeStruct(AutofillDriver_SetDataList_Params);
      this.setDataList(params.values, params.labels);
      return true;
    default:
      return false;
    }
  };

  AutofillDriverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateAutofillDriverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kAutofillDriver_FirstUserGestureObserved_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_FirstUserGestureObserved_Params;
      break;
      case kAutofillDriver_FormsSeen_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_FormsSeen_Params;
      break;
      case kAutofillDriver_WillSubmitForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_WillSubmitForm_Params;
      break;
      case kAutofillDriver_FormSubmitted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_FormSubmitted_Params;
      break;
      case kAutofillDriver_TextFieldDidChange_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_TextFieldDidChange_Params;
      break;
      case kAutofillDriver_QueryFormFieldAutofill_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_QueryFormFieldAutofill_Params;
      break;
      case kAutofillDriver_HidePopup_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_HidePopup_Params;
      break;
      case kAutofillDriver_FocusNoLongerOnForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_FocusNoLongerOnForm_Params;
      break;
      case kAutofillDriver_DidFillAutofillFormData_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_DidFillAutofillFormData_Params;
      break;
      case kAutofillDriver_DidPreviewAutofillFormData_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_DidPreviewAutofillFormData_Params;
      break;
      case kAutofillDriver_DidEndTextFieldEditing_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_DidEndTextFieldEditing_Params;
      break;
      case kAutofillDriver_SetDataList_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = AutofillDriver_SetDataList_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateAutofillDriverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var AutofillDriver = {
    name: 'autofill::mojom::AutofillDriver',
    ptrClass: AutofillDriverPtr,
    proxyClass: AutofillDriverProxy,
    stubClass: AutofillDriverStub,
    validateRequest: validateAutofillDriverRequest,
    validateResponse: null,
  };
  AutofillDriverStub.prototype.validator = validateAutofillDriverRequest;
  AutofillDriverProxy.prototype.validator = null;
  var kPasswordManagerDriver_PasswordFormsParsed_Name = 0;
  var kPasswordManagerDriver_PasswordFormsRendered_Name = 1;
  var kPasswordManagerDriver_PasswordFormSubmitted_Name = 2;
  var kPasswordManagerDriver_InPageNavigation_Name = 3;
  var kPasswordManagerDriver_RecordSavePasswordProgress_Name = 4;
  var kPasswordManagerDriver_ShowPasswordSuggestions_Name = 5;
  var kPasswordManagerDriver_ShowNotSecureWarning_Name = 6;
  var kPasswordManagerDriver_PresaveGeneratedPassword_Name = 7;
  var kPasswordManagerDriver_PasswordNoLongerGenerated_Name = 8;
  var kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name = 9;

  function PasswordManagerDriverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PasswordManagerDriver,
                                                   handleOrPtrInfo);
  }

  function PasswordManagerDriverProxy(receiver) {
    this.receiver_ = receiver;
  }
  PasswordManagerDriverPtr.prototype.passwordFormsParsed = function() {
    return PasswordManagerDriverProxy.prototype.passwordFormsParsed
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.passwordFormsParsed = function(forms) {
    var params = new PasswordManagerDriver_PasswordFormsParsed_Params();
    params.forms = forms;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_PasswordFormsParsed_Name,
        codec.align(PasswordManagerDriver_PasswordFormsParsed_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_PasswordFormsParsed_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.passwordFormsRendered = function() {
    return PasswordManagerDriverProxy.prototype.passwordFormsRendered
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.passwordFormsRendered = function(visible_forms, did_stop_loading) {
    var params = new PasswordManagerDriver_PasswordFormsRendered_Params();
    params.visible_forms = visible_forms;
    params.did_stop_loading = did_stop_loading;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_PasswordFormsRendered_Name,
        codec.align(PasswordManagerDriver_PasswordFormsRendered_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_PasswordFormsRendered_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.passwordFormSubmitted = function() {
    return PasswordManagerDriverProxy.prototype.passwordFormSubmitted
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.passwordFormSubmitted = function(password_form) {
    var params = new PasswordManagerDriver_PasswordFormSubmitted_Params();
    params.password_form = password_form;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_PasswordFormSubmitted_Name,
        codec.align(PasswordManagerDriver_PasswordFormSubmitted_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_PasswordFormSubmitted_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.inPageNavigation = function() {
    return PasswordManagerDriverProxy.prototype.inPageNavigation
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.inPageNavigation = function(password_form) {
    var params = new PasswordManagerDriver_InPageNavigation_Params();
    params.password_form = password_form;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_InPageNavigation_Name,
        codec.align(PasswordManagerDriver_InPageNavigation_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_InPageNavigation_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.recordSavePasswordProgress = function() {
    return PasswordManagerDriverProxy.prototype.recordSavePasswordProgress
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.recordSavePasswordProgress = function(log) {
    var params = new PasswordManagerDriver_RecordSavePasswordProgress_Params();
    params.log = log;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_RecordSavePasswordProgress_Name,
        codec.align(PasswordManagerDriver_RecordSavePasswordProgress_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_RecordSavePasswordProgress_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.showPasswordSuggestions = function() {
    return PasswordManagerDriverProxy.prototype.showPasswordSuggestions
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.showPasswordSuggestions = function(key, text_direction, typed_username, options, bounds) {
    var params = new PasswordManagerDriver_ShowPasswordSuggestions_Params();
    params.key = key;
    params.text_direction = text_direction;
    params.typed_username = typed_username;
    params.options = options;
    params.bounds = bounds;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_ShowPasswordSuggestions_Name,
        codec.align(PasswordManagerDriver_ShowPasswordSuggestions_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_ShowPasswordSuggestions_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.showNotSecureWarning = function() {
    return PasswordManagerDriverProxy.prototype.showNotSecureWarning
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.showNotSecureWarning = function(text_direction, bounds) {
    var params = new PasswordManagerDriver_ShowNotSecureWarning_Params();
    params.text_direction = text_direction;
    params.bounds = bounds;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_ShowNotSecureWarning_Name,
        codec.align(PasswordManagerDriver_ShowNotSecureWarning_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_ShowNotSecureWarning_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.presaveGeneratedPassword = function() {
    return PasswordManagerDriverProxy.prototype.presaveGeneratedPassword
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.presaveGeneratedPassword = function(password_form) {
    var params = new PasswordManagerDriver_PresaveGeneratedPassword_Params();
    params.password_form = password_form;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_PresaveGeneratedPassword_Name,
        codec.align(PasswordManagerDriver_PresaveGeneratedPassword_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_PresaveGeneratedPassword_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.passwordNoLongerGenerated = function() {
    return PasswordManagerDriverProxy.prototype.passwordNoLongerGenerated
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.passwordNoLongerGenerated = function(password_form) {
    var params = new PasswordManagerDriver_PasswordNoLongerGenerated_Params();
    params.password_form = password_form;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_PasswordNoLongerGenerated_Name,
        codec.align(PasswordManagerDriver_PasswordNoLongerGenerated_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_PasswordNoLongerGenerated_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerDriverPtr.prototype.saveGenerationFieldDetectedByClassifier = function() {
    return PasswordManagerDriverProxy.prototype.saveGenerationFieldDetectedByClassifier
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerDriverProxy.prototype.saveGenerationFieldDetectedByClassifier = function(password_form, generation_field) {
    var params = new PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params();
    params.password_form = password_form;
    params.generation_field = generation_field;
    var builder = new codec.MessageBuilder(
        kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name,
        codec.align(PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params.encodedSize));
    builder.encodeStruct(PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PasswordManagerDriverStub(delegate) {
    this.delegate_ = delegate;
  }
  PasswordManagerDriverStub.prototype.passwordFormsParsed = function(forms) {
    return this.delegate_ && this.delegate_.passwordFormsParsed && this.delegate_.passwordFormsParsed(forms);
  }
  PasswordManagerDriverStub.prototype.passwordFormsRendered = function(visible_forms, did_stop_loading) {
    return this.delegate_ && this.delegate_.passwordFormsRendered && this.delegate_.passwordFormsRendered(visible_forms, did_stop_loading);
  }
  PasswordManagerDriverStub.prototype.passwordFormSubmitted = function(password_form) {
    return this.delegate_ && this.delegate_.passwordFormSubmitted && this.delegate_.passwordFormSubmitted(password_form);
  }
  PasswordManagerDriverStub.prototype.inPageNavigation = function(password_form) {
    return this.delegate_ && this.delegate_.inPageNavigation && this.delegate_.inPageNavigation(password_form);
  }
  PasswordManagerDriverStub.prototype.recordSavePasswordProgress = function(log) {
    return this.delegate_ && this.delegate_.recordSavePasswordProgress && this.delegate_.recordSavePasswordProgress(log);
  }
  PasswordManagerDriverStub.prototype.showPasswordSuggestions = function(key, text_direction, typed_username, options, bounds) {
    return this.delegate_ && this.delegate_.showPasswordSuggestions && this.delegate_.showPasswordSuggestions(key, text_direction, typed_username, options, bounds);
  }
  PasswordManagerDriverStub.prototype.showNotSecureWarning = function(text_direction, bounds) {
    return this.delegate_ && this.delegate_.showNotSecureWarning && this.delegate_.showNotSecureWarning(text_direction, bounds);
  }
  PasswordManagerDriverStub.prototype.presaveGeneratedPassword = function(password_form) {
    return this.delegate_ && this.delegate_.presaveGeneratedPassword && this.delegate_.presaveGeneratedPassword(password_form);
  }
  PasswordManagerDriverStub.prototype.passwordNoLongerGenerated = function(password_form) {
    return this.delegate_ && this.delegate_.passwordNoLongerGenerated && this.delegate_.passwordNoLongerGenerated(password_form);
  }
  PasswordManagerDriverStub.prototype.saveGenerationFieldDetectedByClassifier = function(password_form, generation_field) {
    return this.delegate_ && this.delegate_.saveGenerationFieldDetectedByClassifier && this.delegate_.saveGenerationFieldDetectedByClassifier(password_form, generation_field);
  }

  PasswordManagerDriverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPasswordManagerDriver_PasswordFormsParsed_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_PasswordFormsParsed_Params);
      this.passwordFormsParsed(params.forms);
      return true;
    case kPasswordManagerDriver_PasswordFormsRendered_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_PasswordFormsRendered_Params);
      this.passwordFormsRendered(params.visible_forms, params.did_stop_loading);
      return true;
    case kPasswordManagerDriver_PasswordFormSubmitted_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_PasswordFormSubmitted_Params);
      this.passwordFormSubmitted(params.password_form);
      return true;
    case kPasswordManagerDriver_InPageNavigation_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_InPageNavigation_Params);
      this.inPageNavigation(params.password_form);
      return true;
    case kPasswordManagerDriver_RecordSavePasswordProgress_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_RecordSavePasswordProgress_Params);
      this.recordSavePasswordProgress(params.log);
      return true;
    case kPasswordManagerDriver_ShowPasswordSuggestions_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_ShowPasswordSuggestions_Params);
      this.showPasswordSuggestions(params.key, params.text_direction, params.typed_username, params.options, params.bounds);
      return true;
    case kPasswordManagerDriver_ShowNotSecureWarning_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_ShowNotSecureWarning_Params);
      this.showNotSecureWarning(params.text_direction, params.bounds);
      return true;
    case kPasswordManagerDriver_PresaveGeneratedPassword_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_PresaveGeneratedPassword_Params);
      this.presaveGeneratedPassword(params.password_form);
      return true;
    case kPasswordManagerDriver_PasswordNoLongerGenerated_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_PasswordNoLongerGenerated_Params);
      this.passwordNoLongerGenerated(params.password_form);
      return true;
    case kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name:
      var params = reader.decodeStruct(PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params);
      this.saveGenerationFieldDetectedByClassifier(params.password_form, params.generation_field);
      return true;
    default:
      return false;
    }
  };

  PasswordManagerDriverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePasswordManagerDriverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPasswordManagerDriver_PasswordFormsParsed_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_PasswordFormsParsed_Params;
      break;
      case kPasswordManagerDriver_PasswordFormsRendered_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_PasswordFormsRendered_Params;
      break;
      case kPasswordManagerDriver_PasswordFormSubmitted_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_PasswordFormSubmitted_Params;
      break;
      case kPasswordManagerDriver_InPageNavigation_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_InPageNavigation_Params;
      break;
      case kPasswordManagerDriver_RecordSavePasswordProgress_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_RecordSavePasswordProgress_Params;
      break;
      case kPasswordManagerDriver_ShowPasswordSuggestions_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_ShowPasswordSuggestions_Params;
      break;
      case kPasswordManagerDriver_ShowNotSecureWarning_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_ShowNotSecureWarning_Params;
      break;
      case kPasswordManagerDriver_PresaveGeneratedPassword_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_PresaveGeneratedPassword_Params;
      break;
      case kPasswordManagerDriver_PasswordNoLongerGenerated_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_PasswordNoLongerGenerated_Params;
      break;
      case kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePasswordManagerDriverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PasswordManagerDriver = {
    name: 'autofill::mojom::PasswordManagerDriver',
    ptrClass: PasswordManagerDriverPtr,
    proxyClass: PasswordManagerDriverProxy,
    stubClass: PasswordManagerDriverStub,
    validateRequest: validatePasswordManagerDriverRequest,
    validateResponse: null,
  };
  PasswordManagerDriverStub.prototype.validator = validatePasswordManagerDriverRequest;
  PasswordManagerDriverProxy.prototype.validator = null;
  var kPasswordManagerClient_GenerationAvailableForForm_Name = 0;
  var kPasswordManagerClient_ShowPasswordGenerationPopup_Name = 1;
  var kPasswordManagerClient_ShowPasswordEditingPopup_Name = 2;
  var kPasswordManagerClient_HidePasswordGenerationPopup_Name = 3;

  function PasswordManagerClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PasswordManagerClient,
                                                   handleOrPtrInfo);
  }

  function PasswordManagerClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  PasswordManagerClientPtr.prototype.generationAvailableForForm = function() {
    return PasswordManagerClientProxy.prototype.generationAvailableForForm
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerClientProxy.prototype.generationAvailableForForm = function(password_form) {
    var params = new PasswordManagerClient_GenerationAvailableForForm_Params();
    params.password_form = password_form;
    var builder = new codec.MessageBuilder(
        kPasswordManagerClient_GenerationAvailableForForm_Name,
        codec.align(PasswordManagerClient_GenerationAvailableForForm_Params.encodedSize));
    builder.encodeStruct(PasswordManagerClient_GenerationAvailableForForm_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerClientPtr.prototype.showPasswordGenerationPopup = function() {
    return PasswordManagerClientProxy.prototype.showPasswordGenerationPopup
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerClientProxy.prototype.showPasswordGenerationPopup = function(bounds, max_length, generation_element, is_manually_triggered, password_form) {
    var params = new PasswordManagerClient_ShowPasswordGenerationPopup_Params();
    params.bounds = bounds;
    params.max_length = max_length;
    params.generation_element = generation_element;
    params.is_manually_triggered = is_manually_triggered;
    params.password_form = password_form;
    var builder = new codec.MessageBuilder(
        kPasswordManagerClient_ShowPasswordGenerationPopup_Name,
        codec.align(PasswordManagerClient_ShowPasswordGenerationPopup_Params.encodedSize));
    builder.encodeStruct(PasswordManagerClient_ShowPasswordGenerationPopup_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerClientPtr.prototype.showPasswordEditingPopup = function() {
    return PasswordManagerClientProxy.prototype.showPasswordEditingPopup
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerClientProxy.prototype.showPasswordEditingPopup = function(bounds, password_form) {
    var params = new PasswordManagerClient_ShowPasswordEditingPopup_Params();
    params.bounds = bounds;
    params.password_form = password_form;
    var builder = new codec.MessageBuilder(
        kPasswordManagerClient_ShowPasswordEditingPopup_Name,
        codec.align(PasswordManagerClient_ShowPasswordEditingPopup_Params.encodedSize));
    builder.encodeStruct(PasswordManagerClient_ShowPasswordEditingPopup_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PasswordManagerClientPtr.prototype.hidePasswordGenerationPopup = function() {
    return PasswordManagerClientProxy.prototype.hidePasswordGenerationPopup
        .apply(this.ptr.getProxy(), arguments);
  };

  PasswordManagerClientProxy.prototype.hidePasswordGenerationPopup = function() {
    var params = new PasswordManagerClient_HidePasswordGenerationPopup_Params();
    var builder = new codec.MessageBuilder(
        kPasswordManagerClient_HidePasswordGenerationPopup_Name,
        codec.align(PasswordManagerClient_HidePasswordGenerationPopup_Params.encodedSize));
    builder.encodeStruct(PasswordManagerClient_HidePasswordGenerationPopup_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PasswordManagerClientStub(delegate) {
    this.delegate_ = delegate;
  }
  PasswordManagerClientStub.prototype.generationAvailableForForm = function(password_form) {
    return this.delegate_ && this.delegate_.generationAvailableForForm && this.delegate_.generationAvailableForForm(password_form);
  }
  PasswordManagerClientStub.prototype.showPasswordGenerationPopup = function(bounds, max_length, generation_element, is_manually_triggered, password_form) {
    return this.delegate_ && this.delegate_.showPasswordGenerationPopup && this.delegate_.showPasswordGenerationPopup(bounds, max_length, generation_element, is_manually_triggered, password_form);
  }
  PasswordManagerClientStub.prototype.showPasswordEditingPopup = function(bounds, password_form) {
    return this.delegate_ && this.delegate_.showPasswordEditingPopup && this.delegate_.showPasswordEditingPopup(bounds, password_form);
  }
  PasswordManagerClientStub.prototype.hidePasswordGenerationPopup = function() {
    return this.delegate_ && this.delegate_.hidePasswordGenerationPopup && this.delegate_.hidePasswordGenerationPopup();
  }

  PasswordManagerClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPasswordManagerClient_GenerationAvailableForForm_Name:
      var params = reader.decodeStruct(PasswordManagerClient_GenerationAvailableForForm_Params);
      this.generationAvailableForForm(params.password_form);
      return true;
    case kPasswordManagerClient_ShowPasswordGenerationPopup_Name:
      var params = reader.decodeStruct(PasswordManagerClient_ShowPasswordGenerationPopup_Params);
      this.showPasswordGenerationPopup(params.bounds, params.max_length, params.generation_element, params.is_manually_triggered, params.password_form);
      return true;
    case kPasswordManagerClient_ShowPasswordEditingPopup_Name:
      var params = reader.decodeStruct(PasswordManagerClient_ShowPasswordEditingPopup_Params);
      this.showPasswordEditingPopup(params.bounds, params.password_form);
      return true;
    case kPasswordManagerClient_HidePasswordGenerationPopup_Name:
      var params = reader.decodeStruct(PasswordManagerClient_HidePasswordGenerationPopup_Params);
      this.hidePasswordGenerationPopup();
      return true;
    default:
      return false;
    }
  };

  PasswordManagerClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePasswordManagerClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPasswordManagerClient_GenerationAvailableForForm_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerClient_GenerationAvailableForForm_Params;
      break;
      case kPasswordManagerClient_ShowPasswordGenerationPopup_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerClient_ShowPasswordGenerationPopup_Params;
      break;
      case kPasswordManagerClient_ShowPasswordEditingPopup_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerClient_ShowPasswordEditingPopup_Params;
      break;
      case kPasswordManagerClient_HidePasswordGenerationPopup_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PasswordManagerClient_HidePasswordGenerationPopup_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePasswordManagerClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PasswordManagerClient = {
    name: 'autofill::mojom::PasswordManagerClient',
    ptrClass: PasswordManagerClientPtr,
    proxyClass: PasswordManagerClientProxy,
    stubClass: PasswordManagerClientStub,
    validateRequest: validatePasswordManagerClientRequest,
    validateResponse: null,
  };
  PasswordManagerClientStub.prototype.validator = validatePasswordManagerClientRequest;
  PasswordManagerClientProxy.prototype.validator = null;

  var exports = {};
  exports.AutofillDriver = AutofillDriver;
  exports.AutofillDriverPtr = AutofillDriverPtr;
  exports.PasswordManagerDriver = PasswordManagerDriver;
  exports.PasswordManagerDriverPtr = PasswordManagerDriverPtr;
  exports.PasswordManagerClient = PasswordManagerClient;
  exports.PasswordManagerClientPtr = PasswordManagerClientPtr;

  return exports;
});
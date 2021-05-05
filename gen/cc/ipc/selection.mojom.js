// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/selection.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "ui/gfx/mojo/selection_bound.mojom",
], function(bindings, codec, core, validator, selection_bound$) {

  function Selection(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Selection.prototype.initDefaults_ = function() {
    this.start = null;
    this.end = null;
    this.is_editable = false;
    this.is_empty_text_form_control = false;
  };
  Selection.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Selection.validate = function(messageValidator, offset) {
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


    
    // validate Selection.start
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, selection_bound$.SelectionBound, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Selection.end
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, selection_bound$.SelectionBound, false);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  Selection.encodedSize = codec.kStructHeaderSize + 24;

  Selection.decode = function(decoder) {
    var packed;
    var val = new Selection();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.start = decoder.decodeStructPointer(selection_bound$.SelectionBound);
    val.end = decoder.decodeStructPointer(selection_bound$.SelectionBound);
    packed = decoder.readUint8();
    val.is_editable = (packed >> 0) & 1 ? true : false;
    val.is_empty_text_form_control = (packed >> 1) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Selection.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Selection.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(selection_bound$.SelectionBound, val.start);
    encoder.encodeStructPointer(selection_bound$.SelectionBound, val.end);
    packed = 0;
    packed |= (val.is_editable & 1) << 0
    packed |= (val.is_empty_text_form_control & 1) << 1
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
  exports.Selection = Selection;

  return exports;
});
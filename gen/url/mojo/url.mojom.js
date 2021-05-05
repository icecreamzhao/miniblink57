// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("url/mojo/url.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function Url(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Url.prototype.initDefaults_ = function() {
    this.url = null;
  };
  Url.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Url.validate = function(messageValidator, offset) {
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


    
    // validate Url.url
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Url.encodedSize = codec.kStructHeaderSize + 8;

  Url.decode = function(decoder) {
    var packed;
    var val = new Url();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStruct(codec.String);
    return val;
  };

  Url.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Url.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.url);
  };

  var exports = {};
  exports.Url = Url;

  return exports;
});
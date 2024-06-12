// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("media/mojo/interfaces/audio_parameters.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function AudioParameters(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AudioParameters.prototype.initDefaults_ = function() {
  };
  AudioParameters.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AudioParameters.validate = function(messageValidator, offset) {
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

  AudioParameters.encodedSize = codec.kStructHeaderSize + 0;

  AudioParameters.decode = function(decoder) {
    var packed;
    var val = new AudioParameters();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  AudioParameters.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AudioParameters.encodedSize);
    encoder.writeUint32(0);
  };

  var exports = {};
  exports.AudioParameters = AudioParameters;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("gpu/ipc/common/mailbox_holder.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "gpu/ipc/common/mailbox.mojom",
    "gpu/ipc/common/sync_token.mojom",
], function(bindings, codec, core, validator, mailbox$, sync_token$) {

  function MailboxHolder(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  MailboxHolder.prototype.initDefaults_ = function() {
    this.mailbox = null;
    this.sync_token = null;
    this.texture_target = 0;
  };
  MailboxHolder.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  MailboxHolder.validate = function(messageValidator, offset) {
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


    
    // validate MailboxHolder.mailbox
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, mailbox$.Mailbox, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate MailboxHolder.sync_token
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, sync_token$.SyncToken, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  MailboxHolder.encodedSize = codec.kStructHeaderSize + 24;

  MailboxHolder.decode = function(decoder) {
    var packed;
    var val = new MailboxHolder();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.mailbox = decoder.decodeStructPointer(mailbox$.Mailbox);
    val.sync_token = decoder.decodeStructPointer(sync_token$.SyncToken);
    val.texture_target = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  MailboxHolder.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(MailboxHolder.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(mailbox$.Mailbox, val.mailbox);
    encoder.encodeStructPointer(sync_token$.SyncToken, val.sync_token);
    encoder.encodeStruct(codec.Uint32, val.texture_target);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  var exports = {};
  exports.MailboxHolder = MailboxHolder;

  return exports;
});
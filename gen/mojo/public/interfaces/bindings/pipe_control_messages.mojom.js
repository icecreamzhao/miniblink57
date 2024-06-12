// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("mojo/public/interfaces/bindings/pipe_control_messages.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var kRunOrClosePipeMessageId = 0xFFFFFFFE;

  function RunOrClosePipeMessageParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  RunOrClosePipeMessageParams.prototype.initDefaults_ = function() {
    this.input = null;
  };
  RunOrClosePipeMessageParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  RunOrClosePipeMessageParams.validate = function(messageValidator, offset) {
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


    // validate RunOrClosePipeMessageParams.input
    err = messageValidator.validateUnion(offset + codec.kStructHeaderSize + 0, RunOrClosePipeInput, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  RunOrClosePipeMessageParams.encodedSize = codec.kStructHeaderSize + 16;

  RunOrClosePipeMessageParams.decode = function(decoder) {
    var packed;
    var val = new RunOrClosePipeMessageParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.input = decoder.decodeStruct(RunOrClosePipeInput);
    return val;
  };

  RunOrClosePipeMessageParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(RunOrClosePipeMessageParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(RunOrClosePipeInput, val.input);
  };
  function PeerAssociatedEndpointClosedEvent(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PeerAssociatedEndpointClosedEvent.prototype.initDefaults_ = function() {
    this.id = 0;
  };
  PeerAssociatedEndpointClosedEvent.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PeerAssociatedEndpointClosedEvent.validate = function(messageValidator, offset) {
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

  PeerAssociatedEndpointClosedEvent.encodedSize = codec.kStructHeaderSize + 8;

  PeerAssociatedEndpointClosedEvent.decode = function(decoder) {
    var packed;
    var val = new PeerAssociatedEndpointClosedEvent();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PeerAssociatedEndpointClosedEvent.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PeerAssociatedEndpointClosedEvent.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function AssociatedEndpointClosedBeforeSentEvent(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AssociatedEndpointClosedBeforeSentEvent.prototype.initDefaults_ = function() {
    this.id = 0;
  };
  AssociatedEndpointClosedBeforeSentEvent.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AssociatedEndpointClosedBeforeSentEvent.validate = function(messageValidator, offset) {
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

  AssociatedEndpointClosedBeforeSentEvent.encodedSize = codec.kStructHeaderSize + 8;

  AssociatedEndpointClosedBeforeSentEvent.decode = function(decoder) {
    var packed;
    var val = new AssociatedEndpointClosedBeforeSentEvent();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  AssociatedEndpointClosedBeforeSentEvent.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AssociatedEndpointClosedBeforeSentEvent.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.id);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };

  function RunOrClosePipeInput(value) {
    this.initDefault_();
    this.initValue_(value);
  }
  
  
  RunOrClosePipeInput.Tags = {
    peer_associated_endpoint_closed_event: 0,
    associated_endpoint_closed_before_sent_event: 1,
  };
  
  RunOrClosePipeInput.prototype.initDefault_ = function() {
    this.$data = null;
    this.$tag = undefined;
  }
  
  RunOrClosePipeInput.prototype.initValue_ = function(value) {
    if (value == undefined) {
      return;
    }
  
    var keys = Object.keys(value);
    if (keys.length == 0) {
      return;
    }
  
    if (keys.length > 1) {
      throw new TypeError("You may set only one member on a union.");
    }
  
    var fields = [
        "peer_associated_endpoint_closed_event",
        "associated_endpoint_closed_before_sent_event",
    ];
  
    if (fields.indexOf(keys[0]) < 0) {
      throw new ReferenceError(keys[0] + " is not a RunOrClosePipeInput member.");
  
    }
  
    this[keys[0]] = value[keys[0]];
  }
  Object.defineProperty(RunOrClosePipeInput.prototype, "peer_associated_endpoint_closed_event", {
    get: function() {
      if (this.$tag != RunOrClosePipeInput.Tags.peer_associated_endpoint_closed_event) {
        throw new ReferenceError(
            "RunOrClosePipeInput.peer_associated_endpoint_closed_event is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = RunOrClosePipeInput.Tags.peer_associated_endpoint_closed_event;
      this.$data = value;
    }
  });
  Object.defineProperty(RunOrClosePipeInput.prototype, "associated_endpoint_closed_before_sent_event", {
    get: function() {
      if (this.$tag != RunOrClosePipeInput.Tags.associated_endpoint_closed_before_sent_event) {
        throw new ReferenceError(
            "RunOrClosePipeInput.associated_endpoint_closed_before_sent_event is not currently set.");
      }
      return this.$data;
    },
  
    set: function(value) {
      this.$tag = RunOrClosePipeInput.Tags.associated_endpoint_closed_before_sent_event;
      this.$data = value;
    }
  });
  
  
    RunOrClosePipeInput.encode = function(encoder, val) {
      if (val == null) {
        encoder.writeUint64(0);
        encoder.writeUint64(0);
        return;
      }
      if (val.$tag == undefined) {
        throw new TypeError("Cannot encode unions with an unknown member set.");
      }
    
      encoder.writeUint32(16);
      encoder.writeUint32(val.$tag);
      switch (val.$tag) {
        case RunOrClosePipeInput.Tags.peer_associated_endpoint_closed_event:
          encoder.encodeStructPointer(PeerAssociatedEndpointClosedEvent, val.peer_associated_endpoint_closed_event);
          break;
        case RunOrClosePipeInput.Tags.associated_endpoint_closed_before_sent_event:
          encoder.encodeStructPointer(AssociatedEndpointClosedBeforeSentEvent, val.associated_endpoint_closed_before_sent_event);
          break;
      }
      encoder.align();
    };
  
  
    RunOrClosePipeInput.decode = function(decoder) {
      var size = decoder.readUint32();
      if (size == 0) {
        decoder.readUint32();
        decoder.readUint64();
        return null;
      }
    
      var result = new RunOrClosePipeInput();
      var tag = decoder.readUint32();
      switch (tag) {
        case RunOrClosePipeInput.Tags.peer_associated_endpoint_closed_event:
          result.peer_associated_endpoint_closed_event = decoder.decodeStructPointer(PeerAssociatedEndpointClosedEvent);
          break;
        case RunOrClosePipeInput.Tags.associated_endpoint_closed_before_sent_event:
          result.associated_endpoint_closed_before_sent_event = decoder.decodeStructPointer(AssociatedEndpointClosedBeforeSentEvent);
          break;
      }
      decoder.align();
    
      return result;
    };
  
  
    RunOrClosePipeInput.validate = function(messageValidator, offset) {
      var size = messageValidator.decodeUnionSize(offset);
      if (size != 16) {
        return validator.validationError.INVALID_UNION_SIZE;
      }
    
      var tag = messageValidator.decodeUnionTag(offset);
      var data_offset = offset + 8;
      var err;
      switch (tag) {
        case RunOrClosePipeInput.Tags.peer_associated_endpoint_closed_event:
          
    
    // validate RunOrClosePipeInput.peer_associated_endpoint_closed_event
    err = messageValidator.validateStructPointer(data_offset, PeerAssociatedEndpointClosedEvent, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
        case RunOrClosePipeInput.Tags.associated_endpoint_closed_before_sent_event:
          
    
    // validate RunOrClosePipeInput.associated_endpoint_closed_before_sent_event
    err = messageValidator.validateStructPointer(data_offset, AssociatedEndpointClosedBeforeSentEvent, false);
    if (err !== validator.validationError.NONE)
        return err;
          break;
      }
    
      return validator.validationError.NONE;
    };
  
  RunOrClosePipeInput.encodedSize = 16;

  var exports = {};
  exports.kRunOrClosePipeMessageId = kRunOrClosePipeMessageId;
  exports.RunOrClosePipeMessageParams = RunOrClosePipeMessageParams;
  exports.PeerAssociatedEndpointClosedEvent = PeerAssociatedEndpointClosedEvent;
  exports.AssociatedEndpointClosedBeforeSentEvent = AssociatedEndpointClosedBeforeSentEvent;
  exports.RunOrClosePipeInput = RunOrClosePipeInput;

  return exports;
});
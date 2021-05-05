// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("cc/ipc/compositor_frame.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "cc/ipc/compositor_frame_metadata.mojom",
    "cc/ipc/render_pass.mojom",
    "cc/ipc/transferable_resource.mojom",
], function(bindings, codec, core, validator, compositor_frame_metadata$, render_pass$, transferable_resource$) {

  function CompositorFrame(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CompositorFrame.prototype.initDefaults_ = function() {
    this.metadata = null;
    this.resources = null;
    this.passes = null;
  };
  CompositorFrame.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CompositorFrame.validate = function(messageValidator, offset) {
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


    
    // validate CompositorFrame.metadata
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, compositor_frame_metadata$.CompositorFrameMetadata, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CompositorFrame.resources
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(transferable_resource$.TransferableResource), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CompositorFrame.passes
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(render_pass$.RenderPass), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  CompositorFrame.encodedSize = codec.kStructHeaderSize + 24;

  CompositorFrame.decode = function(decoder) {
    var packed;
    var val = new CompositorFrame();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.metadata = decoder.decodeStructPointer(compositor_frame_metadata$.CompositorFrameMetadata);
    val.resources = decoder.decodeArrayPointer(new codec.PointerTo(transferable_resource$.TransferableResource));
    val.passes = decoder.decodeArrayPointer(new codec.PointerTo(render_pass$.RenderPass));
    return val;
  };

  CompositorFrame.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CompositorFrame.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(compositor_frame_metadata$.CompositorFrameMetadata, val.metadata);
    encoder.encodeArrayPointer(new codec.PointerTo(transferable_resource$.TransferableResource), val.resources);
    encoder.encodeArrayPointer(new codec.PointerTo(render_pass$.RenderPass), val.passes);
  };

  var exports = {};
  exports.CompositorFrame = CompositorFrame;

  return exports;
});
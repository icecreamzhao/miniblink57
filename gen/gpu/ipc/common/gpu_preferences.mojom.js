// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("gpu/ipc/common/gpu_preferences.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var VpxDecodeVendors = {};
  VpxDecodeVendors.VPX_VENDOR_NONE = 0;
  VpxDecodeVendors.VPX_VENDOR_MICROSOFT = 1;
  VpxDecodeVendors.VPX_VENDOR_AMD = 2;
  VpxDecodeVendors.VPX_VENDOR_ALL = 3;

  VpxDecodeVendors.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  VpxDecodeVendors.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function GpuPreferences(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuPreferences.prototype.initDefaults_ = function() {
    this.single_process = false;
    this.in_process_gpu = false;
    this.ui_prioritize_in_gpu_process = false;
    this.disable_accelerated_video_decode = false;
    this.disable_vaapi_accelerated_video_encode = false;
    this.disable_web_rtc_hw_encoding = false;
    this.enable_low_latency_dxva = false;
    this.enable_zero_copy_dxgi_video = false;
    this.enable_nv12_dxgi_video = false;
    this.compile_shader_always_succeeds = false;
    this.disable_gl_error_limit = false;
    this.disable_glsl_translator = false;
    this.disable_gpu_driver_bug_workarounds = false;
    this.disable_shader_name_hashing = false;
    this.enable_gpu_command_logging = false;
    this.enable_gpu_debugging = false;
    this.enable_gpu_service_logging_gpu = false;
    this.enable_gpu_driver_debug_logging = false;
    this.disable_gpu_program_cache = false;
    this.enforce_gl_minimums = false;
    this.disable_gpu_shader_disk_cache = false;
    this.enable_threaded_texture_mailboxes = false;
    this.gl_shader_interm_output = false;
    this.emulate_shader_precision = false;
    this.enable_gpu_service_logging = false;
    this.enable_gpu_service_tracing = false;
    this.enable_es3_apis = false;
    this.use_passthrough_cmd_decoder = false;
    this.enable_accelerated_vpx_decode = 0;
    this.force_gpu_mem_available = 0;
    this.gpu_program_cache_size = 0;
  };
  GpuPreferences.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuPreferences.validate = function(messageValidator, offset) {
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








    
    // validate GpuPreferences.enable_accelerated_vpx_decode
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, VpxDecodeVendors);
    if (err !== validator.validationError.NONE)
        return err;

























    return validator.validationError.NONE;
  };

  GpuPreferences.encodedSize = codec.kStructHeaderSize + 16;

  GpuPreferences.decode = function(decoder) {
    var packed;
    var val = new GpuPreferences();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.single_process = (packed >> 0) & 1 ? true : false;
    val.in_process_gpu = (packed >> 1) & 1 ? true : false;
    val.ui_prioritize_in_gpu_process = (packed >> 2) & 1 ? true : false;
    val.disable_accelerated_video_decode = (packed >> 3) & 1 ? true : false;
    val.disable_vaapi_accelerated_video_encode = (packed >> 4) & 1 ? true : false;
    val.disable_web_rtc_hw_encoding = (packed >> 5) & 1 ? true : false;
    val.enable_low_latency_dxva = (packed >> 6) & 1 ? true : false;
    val.enable_zero_copy_dxgi_video = (packed >> 7) & 1 ? true : false;
    packed = decoder.readUint8();
    val.enable_nv12_dxgi_video = (packed >> 0) & 1 ? true : false;
    val.compile_shader_always_succeeds = (packed >> 1) & 1 ? true : false;
    val.disable_gl_error_limit = (packed >> 2) & 1 ? true : false;
    val.disable_glsl_translator = (packed >> 3) & 1 ? true : false;
    val.disable_gpu_driver_bug_workarounds = (packed >> 4) & 1 ? true : false;
    val.disable_shader_name_hashing = (packed >> 5) & 1 ? true : false;
    val.enable_gpu_command_logging = (packed >> 6) & 1 ? true : false;
    val.enable_gpu_debugging = (packed >> 7) & 1 ? true : false;
    packed = decoder.readUint8();
    val.enable_gpu_service_logging_gpu = (packed >> 0) & 1 ? true : false;
    val.enable_gpu_driver_debug_logging = (packed >> 1) & 1 ? true : false;
    val.disable_gpu_program_cache = (packed >> 2) & 1 ? true : false;
    val.enforce_gl_minimums = (packed >> 3) & 1 ? true : false;
    val.disable_gpu_shader_disk_cache = (packed >> 4) & 1 ? true : false;
    val.enable_threaded_texture_mailboxes = (packed >> 5) & 1 ? true : false;
    val.gl_shader_interm_output = (packed >> 6) & 1 ? true : false;
    val.emulate_shader_precision = (packed >> 7) & 1 ? true : false;
    packed = decoder.readUint8();
    val.enable_gpu_service_logging = (packed >> 0) & 1 ? true : false;
    val.enable_gpu_service_tracing = (packed >> 1) & 1 ? true : false;
    val.enable_es3_apis = (packed >> 2) & 1 ? true : false;
    val.use_passthrough_cmd_decoder = (packed >> 3) & 1 ? true : false;
    val.enable_accelerated_vpx_decode = decoder.decodeStruct(codec.Int32);
    val.force_gpu_mem_available = decoder.decodeStruct(codec.Uint32);
    val.gpu_program_cache_size = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  GpuPreferences.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuPreferences.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.single_process & 1) << 0
    packed |= (val.in_process_gpu & 1) << 1
    packed |= (val.ui_prioritize_in_gpu_process & 1) << 2
    packed |= (val.disable_accelerated_video_decode & 1) << 3
    packed |= (val.disable_vaapi_accelerated_video_encode & 1) << 4
    packed |= (val.disable_web_rtc_hw_encoding & 1) << 5
    packed |= (val.enable_low_latency_dxva & 1) << 6
    packed |= (val.enable_zero_copy_dxgi_video & 1) << 7
    encoder.writeUint8(packed);
    packed = 0;
    packed |= (val.enable_nv12_dxgi_video & 1) << 0
    packed |= (val.compile_shader_always_succeeds & 1) << 1
    packed |= (val.disable_gl_error_limit & 1) << 2
    packed |= (val.disable_glsl_translator & 1) << 3
    packed |= (val.disable_gpu_driver_bug_workarounds & 1) << 4
    packed |= (val.disable_shader_name_hashing & 1) << 5
    packed |= (val.enable_gpu_command_logging & 1) << 6
    packed |= (val.enable_gpu_debugging & 1) << 7
    encoder.writeUint8(packed);
    packed = 0;
    packed |= (val.enable_gpu_service_logging_gpu & 1) << 0
    packed |= (val.enable_gpu_driver_debug_logging & 1) << 1
    packed |= (val.disable_gpu_program_cache & 1) << 2
    packed |= (val.enforce_gl_minimums & 1) << 3
    packed |= (val.disable_gpu_shader_disk_cache & 1) << 4
    packed |= (val.enable_threaded_texture_mailboxes & 1) << 5
    packed |= (val.gl_shader_interm_output & 1) << 6
    packed |= (val.emulate_shader_precision & 1) << 7
    encoder.writeUint8(packed);
    packed = 0;
    packed |= (val.enable_gpu_service_logging & 1) << 0
    packed |= (val.enable_gpu_service_tracing & 1) << 1
    packed |= (val.enable_es3_apis & 1) << 2
    packed |= (val.use_passthrough_cmd_decoder & 1) << 3
    encoder.writeUint8(packed);
    encoder.encodeStruct(codec.Int32, val.enable_accelerated_vpx_decode);
    encoder.encodeStruct(codec.Uint32, val.force_gpu_mem_available);
    encoder.encodeStruct(codec.Uint32, val.gpu_program_cache_size);
  };

  var exports = {};
  exports.VpxDecodeVendors = VpxDecodeVendors;
  exports.GpuPreferences = GpuPreferences;

  return exports;
});
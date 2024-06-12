// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("gpu/ipc/common/gpu_info.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "gpu/ipc/common/dx_diag_node.mojom",
    "mojo/common/time.mojom",
    "mojo/common/version.mojom",
    "ui/gfx/geometry/mojo/geometry.mojom",
], function(bindings, codec, core, validator, dx_diag_node$, time$, version$, geometry$) {
  var CollectInfoResult = {};
  CollectInfoResult.kCollectInfoNone = 0;
  CollectInfoResult.kCollectInfoSuccess = 1;
  CollectInfoResult.kCollectInfoNonFatalFailure = 2;
  CollectInfoResult.kCollectInfoFatalFailure = 3;

  CollectInfoResult.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  CollectInfoResult.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var VideoCodecProfile = {};
  VideoCodecProfile.VIDEO_CODEC_PROFILE_UNKNOWN = -1;
  VideoCodecProfile.H264PROFILE_BASELINE = 0;
  VideoCodecProfile.H264PROFILE_MAIN = VideoCodecProfile.H264PROFILE_BASELINE + 1;
  VideoCodecProfile.H264PROFILE_EXTENDED = VideoCodecProfile.H264PROFILE_MAIN + 1;
  VideoCodecProfile.H264PROFILE_HIGH = VideoCodecProfile.H264PROFILE_EXTENDED + 1;
  VideoCodecProfile.H264PROFILE_HIGH10PROFILE = VideoCodecProfile.H264PROFILE_HIGH + 1;
  VideoCodecProfile.H264PROFILE_HIGH422PROFILE = VideoCodecProfile.H264PROFILE_HIGH10PROFILE + 1;
  VideoCodecProfile.H264PROFILE_HIGH444PREDICTIVEPROFILE = VideoCodecProfile.H264PROFILE_HIGH422PROFILE + 1;
  VideoCodecProfile.H264PROFILE_SCALABLEBASELINE = VideoCodecProfile.H264PROFILE_HIGH444PREDICTIVEPROFILE + 1;
  VideoCodecProfile.H264PROFILE_SCALABLEHIGH = VideoCodecProfile.H264PROFILE_SCALABLEBASELINE + 1;
  VideoCodecProfile.H264PROFILE_STEREOHIGH = VideoCodecProfile.H264PROFILE_SCALABLEHIGH + 1;
  VideoCodecProfile.H264PROFILE_MULTIVIEWHIGH = VideoCodecProfile.H264PROFILE_STEREOHIGH + 1;
  VideoCodecProfile.VP8PROFILE_ANY = VideoCodecProfile.H264PROFILE_MULTIVIEWHIGH + 1;
  VideoCodecProfile.VP9PROFILE_PROFILE0 = VideoCodecProfile.VP8PROFILE_ANY + 1;
  VideoCodecProfile.VP9PROFILE_PROFILE1 = VideoCodecProfile.VP9PROFILE_PROFILE0 + 1;
  VideoCodecProfile.VP9PROFILE_PROFILE2 = VideoCodecProfile.VP9PROFILE_PROFILE1 + 1;
  VideoCodecProfile.VP9PROFILE_PROFILE3 = VideoCodecProfile.VP9PROFILE_PROFILE2 + 1;
  VideoCodecProfile.HEVCPROFILE_MAIN = VideoCodecProfile.VP9PROFILE_PROFILE3 + 1;
  VideoCodecProfile.HEVCPROFILE_MAIN10 = VideoCodecProfile.HEVCPROFILE_MAIN + 1;
  VideoCodecProfile.HEVCPROFILE_MAIN_STILL_PICTURE = VideoCodecProfile.HEVCPROFILE_MAIN10 + 1;

  VideoCodecProfile.isKnownEnumValue = function(value) {
    switch (value) {
    case -1:
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
    case 17:
    case 18:
      return true;
    }
    return false;
  };

  VideoCodecProfile.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function GpuDevice(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuDevice.prototype.initDefaults_ = function() {
    this.vendor_id = 0;
    this.device_id = 0;
    this.active = false;
    this.vendor_string = null;
    this.device_string = null;
  };
  GpuDevice.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuDevice.validate = function(messageValidator, offset) {
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





    
    // validate GpuDevice.vendor_string
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuDevice.device_string
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  GpuDevice.encodedSize = codec.kStructHeaderSize + 32;

  GpuDevice.decode = function(decoder) {
    var packed;
    var val = new GpuDevice();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.vendor_id = decoder.decodeStruct(codec.Uint32);
    val.device_id = decoder.decodeStruct(codec.Uint32);
    packed = decoder.readUint8();
    val.active = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.vendor_string = decoder.decodeStruct(codec.String);
    val.device_string = decoder.decodeStruct(codec.String);
    return val;
  };

  GpuDevice.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuDevice.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.vendor_id);
    encoder.encodeStruct(codec.Uint32, val.device_id);
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
    encoder.encodeStruct(codec.String, val.vendor_string);
    encoder.encodeStruct(codec.String, val.device_string);
  };
  function VideoDecodeAcceleratorSupportedProfile(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecodeAcceleratorSupportedProfile.prototype.initDefaults_ = function() {
    this.profile = 0;
    this.encrypted_only = false;
    this.max_resolution = null;
    this.min_resolution = null;
  };
  VideoDecodeAcceleratorSupportedProfile.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecodeAcceleratorSupportedProfile.validate = function(messageValidator, offset) {
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


    
    // validate VideoDecodeAcceleratorSupportedProfile.profile
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, VideoCodecProfile);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecodeAcceleratorSupportedProfile.max_resolution
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoDecodeAcceleratorSupportedProfile.min_resolution
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  VideoDecodeAcceleratorSupportedProfile.encodedSize = codec.kStructHeaderSize + 24;

  VideoDecodeAcceleratorSupportedProfile.decode = function(decoder) {
    var packed;
    var val = new VideoDecodeAcceleratorSupportedProfile();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.profile = decoder.decodeStruct(codec.Int32);
    packed = decoder.readUint8();
    val.encrypted_only = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.max_resolution = decoder.decodeStructPointer(geometry$.Size);
    val.min_resolution = decoder.decodeStructPointer(geometry$.Size);
    return val;
  };

  VideoDecodeAcceleratorSupportedProfile.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecodeAcceleratorSupportedProfile.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.profile);
    packed = 0;
    packed |= (val.encrypted_only & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(geometry$.Size, val.max_resolution);
    encoder.encodeStructPointer(geometry$.Size, val.min_resolution);
  };
  function VideoDecodeAcceleratorCapabilities(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoDecodeAcceleratorCapabilities.prototype.initDefaults_ = function() {
    this.supported_profiles = null;
    this.flags = 0;
  };
  VideoDecodeAcceleratorCapabilities.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoDecodeAcceleratorCapabilities.validate = function(messageValidator, offset) {
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


    
    // validate VideoDecodeAcceleratorCapabilities.supported_profiles
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(VideoDecodeAcceleratorSupportedProfile), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  VideoDecodeAcceleratorCapabilities.encodedSize = codec.kStructHeaderSize + 16;

  VideoDecodeAcceleratorCapabilities.decode = function(decoder) {
    var packed;
    var val = new VideoDecodeAcceleratorCapabilities();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.supported_profiles = decoder.decodeArrayPointer(new codec.PointerTo(VideoDecodeAcceleratorSupportedProfile));
    val.flags = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VideoDecodeAcceleratorCapabilities.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoDecodeAcceleratorCapabilities.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(VideoDecodeAcceleratorSupportedProfile), val.supported_profiles);
    encoder.encodeStruct(codec.Uint32, val.flags);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function VideoEncodeAcceleratorSupportedProfile(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  VideoEncodeAcceleratorSupportedProfile.prototype.initDefaults_ = function() {
    this.profile = 0;
    this.max_framerate_numerator = 0;
    this.max_resolution = null;
    this.max_framerate_denominator = 0;
  };
  VideoEncodeAcceleratorSupportedProfile.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  VideoEncodeAcceleratorSupportedProfile.validate = function(messageValidator, offset) {
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


    
    // validate VideoEncodeAcceleratorSupportedProfile.profile
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, VideoCodecProfile);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate VideoEncodeAcceleratorSupportedProfile.max_resolution
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, geometry$.Size, false);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  VideoEncodeAcceleratorSupportedProfile.encodedSize = codec.kStructHeaderSize + 24;

  VideoEncodeAcceleratorSupportedProfile.decode = function(decoder) {
    var packed;
    var val = new VideoEncodeAcceleratorSupportedProfile();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.profile = decoder.decodeStruct(codec.Int32);
    val.max_framerate_numerator = decoder.decodeStruct(codec.Uint32);
    val.max_resolution = decoder.decodeStructPointer(geometry$.Size);
    val.max_framerate_denominator = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  VideoEncodeAcceleratorSupportedProfile.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(VideoEncodeAcceleratorSupportedProfile.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.profile);
    encoder.encodeStruct(codec.Uint32, val.max_framerate_numerator);
    encoder.encodeStructPointer(geometry$.Size, val.max_resolution);
    encoder.encodeStruct(codec.Uint32, val.max_framerate_denominator);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function GpuInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  GpuInfo.prototype.initDefaults_ = function() {
    this.initialization_time = null;
    this.optimus = false;
    this.amd_switchable = false;
    this.lenovo_dcute = false;
    this.software_rendering = false;
    this.direct_rendering = false;
    this.sandboxed = false;
    this.in_process_gpu = false;
    this.passthrough_cmd_decoder = false;
    this.jpeg_decode_accelerator_supported = false;
    this.gl_reset_notification_strategy = 0;
    this.display_link_version = null;
    this.gpu = null;
    this.secondary_gpus = null;
    this.adapter_luid = 0;
    this.driver_vendor = null;
    this.driver_version = null;
    this.driver_date = null;
    this.pixel_shader_version = null;
    this.vertex_shader_version = null;
    this.max_msaa_samples = null;
    this.machine_model_name = null;
    this.machine_model_version = null;
    this.gl_version = null;
    this.gl_vendor = null;
    this.gl_renderer = null;
    this.gl_extensions = null;
    this.gl_ws_vendor = null;
    this.gl_ws_version = null;
    this.gl_ws_extensions = null;
    this.process_crash_count = 0;
    this.basic_info_state = 0;
    this.context_info_state = 0;
    this.dx_diagnostics_info_state = 0;
    this.dx_diagnostics = null;
    this.video_decode_accelerator_capabilities = null;
    this.video_encode_accelerator_supported_profiles = null;
    this.system_visual = 0;
    this.rgba_visual = 0;
  };
  GpuInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  GpuInfo.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 232}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.initialization_time
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, time$.TimeDelta, false);
    if (err !== validator.validationError.NONE)
        return err;





    
    // validate GpuInfo.display_link_version
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, version$.Version, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gpu
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, GpuDevice, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.secondary_gpus
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 32, 8, new codec.PointerTo(GpuDevice), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate GpuInfo.driver_vendor
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 48, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.driver_version
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 56, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.driver_date
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 64, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.pixel_shader_version
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 72, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.vertex_shader_version
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 80, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.max_msaa_samples
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 88, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.machine_model_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 96, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.machine_model_version
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 104, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gl_version
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 112, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gl_vendor
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 120, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gl_renderer
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 128, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gl_extensions
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 136, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gl_ws_vendor
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 144, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gl_ws_version
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 152, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.gl_ws_extensions
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 160, false)
    if (err !== validator.validationError.NONE)
        return err;









    
    // validate GpuInfo.basic_info_state
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 172, CollectInfoResult);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.context_info_state
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 176, CollectInfoResult);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.dx_diagnostics_info_state
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 180, CollectInfoResult);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.dx_diagnostics
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 184, dx_diag_node$.DxDiagNode, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.video_decode_accelerator_capabilities
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 192, VideoDecodeAcceleratorCapabilities, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate GpuInfo.video_encode_accelerator_supported_profiles
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 200, 8, new codec.PointerTo(VideoEncodeAcceleratorSupportedProfile), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  GpuInfo.encodedSize = codec.kStructHeaderSize + 224;

  GpuInfo.decode = function(decoder) {
    var packed;
    var val = new GpuInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.initialization_time = decoder.decodeStructPointer(time$.TimeDelta);
    packed = decoder.readUint8();
    val.optimus = (packed >> 0) & 1 ? true : false;
    val.amd_switchable = (packed >> 1) & 1 ? true : false;
    val.lenovo_dcute = (packed >> 2) & 1 ? true : false;
    val.software_rendering = (packed >> 3) & 1 ? true : false;
    val.direct_rendering = (packed >> 4) & 1 ? true : false;
    val.sandboxed = (packed >> 5) & 1 ? true : false;
    val.in_process_gpu = (packed >> 6) & 1 ? true : false;
    val.passthrough_cmd_decoder = (packed >> 7) & 1 ? true : false;
    packed = decoder.readUint8();
    val.jpeg_decode_accelerator_supported = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    val.gl_reset_notification_strategy = decoder.decodeStruct(codec.Uint32);
    val.display_link_version = decoder.decodeStructPointer(version$.Version);
    val.gpu = decoder.decodeStructPointer(GpuDevice);
    val.secondary_gpus = decoder.decodeArrayPointer(new codec.PointerTo(GpuDevice));
    val.adapter_luid = decoder.decodeStruct(codec.Uint64);
    val.driver_vendor = decoder.decodeStruct(codec.String);
    val.driver_version = decoder.decodeStruct(codec.String);
    val.driver_date = decoder.decodeStruct(codec.String);
    val.pixel_shader_version = decoder.decodeStruct(codec.String);
    val.vertex_shader_version = decoder.decodeStruct(codec.String);
    val.max_msaa_samples = decoder.decodeStruct(codec.String);
    val.machine_model_name = decoder.decodeStruct(codec.String);
    val.machine_model_version = decoder.decodeStruct(codec.String);
    val.gl_version = decoder.decodeStruct(codec.String);
    val.gl_vendor = decoder.decodeStruct(codec.String);
    val.gl_renderer = decoder.decodeStruct(codec.String);
    val.gl_extensions = decoder.decodeStruct(codec.String);
    val.gl_ws_vendor = decoder.decodeStruct(codec.String);
    val.gl_ws_version = decoder.decodeStruct(codec.String);
    val.gl_ws_extensions = decoder.decodeStruct(codec.String);
    val.process_crash_count = decoder.decodeStruct(codec.Int32);
    val.basic_info_state = decoder.decodeStruct(codec.Int32);
    val.context_info_state = decoder.decodeStruct(codec.Int32);
    val.dx_diagnostics_info_state = decoder.decodeStruct(codec.Int32);
    val.dx_diagnostics = decoder.decodeStructPointer(dx_diag_node$.DxDiagNode);
    val.video_decode_accelerator_capabilities = decoder.decodeStructPointer(VideoDecodeAcceleratorCapabilities);
    val.video_encode_accelerator_supported_profiles = decoder.decodeArrayPointer(new codec.PointerTo(VideoEncodeAcceleratorSupportedProfile));
    val.system_visual = decoder.decodeStruct(codec.Uint64);
    val.rgba_visual = decoder.decodeStruct(codec.Uint64);
    return val;
  };

  GpuInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(GpuInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(time$.TimeDelta, val.initialization_time);
    packed = 0;
    packed |= (val.optimus & 1) << 0
    packed |= (val.amd_switchable & 1) << 1
    packed |= (val.lenovo_dcute & 1) << 2
    packed |= (val.software_rendering & 1) << 3
    packed |= (val.direct_rendering & 1) << 4
    packed |= (val.sandboxed & 1) << 5
    packed |= (val.in_process_gpu & 1) << 6
    packed |= (val.passthrough_cmd_decoder & 1) << 7
    encoder.writeUint8(packed);
    packed = 0;
    packed |= (val.jpeg_decode_accelerator_supported & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.gl_reset_notification_strategy);
    encoder.encodeStructPointer(version$.Version, val.display_link_version);
    encoder.encodeStructPointer(GpuDevice, val.gpu);
    encoder.encodeArrayPointer(new codec.PointerTo(GpuDevice), val.secondary_gpus);
    encoder.encodeStruct(codec.Uint64, val.adapter_luid);
    encoder.encodeStruct(codec.String, val.driver_vendor);
    encoder.encodeStruct(codec.String, val.driver_version);
    encoder.encodeStruct(codec.String, val.driver_date);
    encoder.encodeStruct(codec.String, val.pixel_shader_version);
    encoder.encodeStruct(codec.String, val.vertex_shader_version);
    encoder.encodeStruct(codec.String, val.max_msaa_samples);
    encoder.encodeStruct(codec.String, val.machine_model_name);
    encoder.encodeStruct(codec.String, val.machine_model_version);
    encoder.encodeStruct(codec.String, val.gl_version);
    encoder.encodeStruct(codec.String, val.gl_vendor);
    encoder.encodeStruct(codec.String, val.gl_renderer);
    encoder.encodeStruct(codec.String, val.gl_extensions);
    encoder.encodeStruct(codec.String, val.gl_ws_vendor);
    encoder.encodeStruct(codec.String, val.gl_ws_version);
    encoder.encodeStruct(codec.String, val.gl_ws_extensions);
    encoder.encodeStruct(codec.Int32, val.process_crash_count);
    encoder.encodeStruct(codec.Int32, val.basic_info_state);
    encoder.encodeStruct(codec.Int32, val.context_info_state);
    encoder.encodeStruct(codec.Int32, val.dx_diagnostics_info_state);
    encoder.encodeStructPointer(dx_diag_node$.DxDiagNode, val.dx_diagnostics);
    encoder.encodeStructPointer(VideoDecodeAcceleratorCapabilities, val.video_decode_accelerator_capabilities);
    encoder.encodeArrayPointer(new codec.PointerTo(VideoEncodeAcceleratorSupportedProfile), val.video_encode_accelerator_supported_profiles);
    encoder.encodeStruct(codec.Uint64, val.system_visual);
    encoder.encodeStruct(codec.Uint64, val.rgba_visual);
  };

  var exports = {};
  exports.CollectInfoResult = CollectInfoResult;
  exports.VideoCodecProfile = VideoCodecProfile;
  exports.GpuDevice = GpuDevice;
  exports.VideoDecodeAcceleratorSupportedProfile = VideoDecodeAcceleratorSupportedProfile;
  exports.VideoDecodeAcceleratorCapabilities = VideoDecodeAcceleratorCapabilities;
  exports.VideoEncodeAcceleratorSupportedProfile = VideoEncodeAcceleratorSupportedProfile;
  exports.GpuInfo = GpuInfo;

  return exports;
});
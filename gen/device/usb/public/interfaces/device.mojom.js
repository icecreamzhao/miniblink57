// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("device/usb/public/interfaces/device.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var OpenDeviceError = {};
  OpenDeviceError.OK = 0;
  OpenDeviceError.ACCESS_DENIED = OpenDeviceError.OK + 1;
  OpenDeviceError.ALREADY_OPEN = OpenDeviceError.ACCESS_DENIED + 1;

  OpenDeviceError.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  OpenDeviceError.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var TransferDirection = {};
  TransferDirection.INBOUND = 0;
  TransferDirection.OUTBOUND = TransferDirection.INBOUND + 1;

  TransferDirection.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  TransferDirection.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var ControlTransferType = {};
  ControlTransferType.STANDARD = 0;
  ControlTransferType.CLASS = ControlTransferType.STANDARD + 1;
  ControlTransferType.VENDOR = ControlTransferType.CLASS + 1;
  ControlTransferType.RESERVED = ControlTransferType.VENDOR + 1;

  ControlTransferType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  ControlTransferType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var ControlTransferRecipient = {};
  ControlTransferRecipient.DEVICE = 0;
  ControlTransferRecipient.INTERFACE = ControlTransferRecipient.DEVICE + 1;
  ControlTransferRecipient.ENDPOINT = ControlTransferRecipient.INTERFACE + 1;
  ControlTransferRecipient.OTHER = ControlTransferRecipient.ENDPOINT + 1;

  ControlTransferRecipient.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  ControlTransferRecipient.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var EndpointType = {};
  EndpointType.BULK = 0;
  EndpointType.INTERRUPT = EndpointType.BULK + 1;
  EndpointType.ISOCHRONOUS = EndpointType.INTERRUPT + 1;

  EndpointType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  EndpointType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var TransferStatus = {};
  TransferStatus.COMPLETED = 0;
  TransferStatus.TRANSFER_ERROR = TransferStatus.COMPLETED + 1;
  TransferStatus.PERMISSION_DENIED = TransferStatus.TRANSFER_ERROR + 1;
  TransferStatus.TIMEOUT = TransferStatus.PERMISSION_DENIED + 1;
  TransferStatus.CANCELLED = TransferStatus.TIMEOUT + 1;
  TransferStatus.STALLED = TransferStatus.CANCELLED + 1;
  TransferStatus.DISCONNECT = TransferStatus.STALLED + 1;
  TransferStatus.BABBLE = TransferStatus.DISCONNECT + 1;
  TransferStatus.SHORT_PACKET = TransferStatus.BABBLE + 1;

  TransferStatus.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    }
    return false;
  };

  TransferStatus.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function EndpointInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  EndpointInfo.prototype.initDefaults_ = function() {
    this.endpoint_number = 0;
    this.direction = 0;
    this.type = 0;
    this.packet_size = 0;
  };
  EndpointInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  EndpointInfo.validate = function(messageValidator, offset) {
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



    
    // validate EndpointInfo.direction
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, TransferDirection);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate EndpointInfo.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, EndpointType);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  EndpointInfo.encodedSize = codec.kStructHeaderSize + 16;

  EndpointInfo.decode = function(decoder) {
    var packed;
    var val = new EndpointInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.endpoint_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.direction = decoder.decodeStruct(codec.Int32);
    val.type = decoder.decodeStruct(codec.Int32);
    val.packet_size = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  EndpointInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(EndpointInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.endpoint_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.direction);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.encodeStruct(codec.Uint32, val.packet_size);
  };
  function AlternateInterfaceInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AlternateInterfaceInfo.prototype.initDefaults_ = function() {
    this.alternate_setting = 0;
    this.class_code = 0;
    this.subclass_code = 0;
    this.protocol_code = 0;
    this.interface_name = null;
    this.endpoints = null;
  };
  AlternateInterfaceInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AlternateInterfaceInfo.validate = function(messageValidator, offset) {
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






    
    // validate AlternateInterfaceInfo.interface_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AlternateInterfaceInfo.endpoints
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(EndpointInfo), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AlternateInterfaceInfo.encodedSize = codec.kStructHeaderSize + 24;

  AlternateInterfaceInfo.decode = function(decoder) {
    var packed;
    var val = new AlternateInterfaceInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.alternate_setting = decoder.decodeStruct(codec.Uint8);
    val.class_code = decoder.decodeStruct(codec.Uint8);
    val.subclass_code = decoder.decodeStruct(codec.Uint8);
    val.protocol_code = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.interface_name = decoder.decodeStruct(codec.NullableString);
    val.endpoints = decoder.decodeArrayPointer(new codec.PointerTo(EndpointInfo));
    return val;
  };

  AlternateInterfaceInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AlternateInterfaceInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.alternate_setting);
    encoder.encodeStruct(codec.Uint8, val.class_code);
    encoder.encodeStruct(codec.Uint8, val.subclass_code);
    encoder.encodeStruct(codec.Uint8, val.protocol_code);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.NullableString, val.interface_name);
    encoder.encodeArrayPointer(new codec.PointerTo(EndpointInfo), val.endpoints);
  };
  function InterfaceInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  InterfaceInfo.prototype.initDefaults_ = function() {
    this.interface_number = 0;
    this.alternates = null;
  };
  InterfaceInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  InterfaceInfo.validate = function(messageValidator, offset) {
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



    
    // validate InterfaceInfo.alternates
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(AlternateInterfaceInfo), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  InterfaceInfo.encodedSize = codec.kStructHeaderSize + 16;

  InterfaceInfo.decode = function(decoder) {
    var packed;
    var val = new InterfaceInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.interface_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.alternates = decoder.decodeArrayPointer(new codec.PointerTo(AlternateInterfaceInfo));
    return val;
  };

  InterfaceInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(InterfaceInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.interface_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(new codec.PointerTo(AlternateInterfaceInfo), val.alternates);
  };
  function ConfigurationInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ConfigurationInfo.prototype.initDefaults_ = function() {
    this.configuration_value = 0;
    this.configuration_name = null;
    this.interfaces = null;
  };
  ConfigurationInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ConfigurationInfo.validate = function(messageValidator, offset) {
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



    
    // validate ConfigurationInfo.configuration_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ConfigurationInfo.interfaces
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(InterfaceInfo), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ConfigurationInfo.encodedSize = codec.kStructHeaderSize + 24;

  ConfigurationInfo.decode = function(decoder) {
    var packed;
    var val = new ConfigurationInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.configuration_value = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.configuration_name = decoder.decodeStruct(codec.NullableString);
    val.interfaces = decoder.decodeArrayPointer(new codec.PointerTo(InterfaceInfo));
    return val;
  };

  ConfigurationInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ConfigurationInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.configuration_value);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.NullableString, val.configuration_name);
    encoder.encodeArrayPointer(new codec.PointerTo(InterfaceInfo), val.interfaces);
  };
  function DeviceInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  DeviceInfo.prototype.initDefaults_ = function() {
    this.guid = null;
    this.usb_version_major = 0;
    this.usb_version_minor = 0;
    this.usb_version_subminor = 0;
    this.class_code = 0;
    this.subclass_code = 0;
    this.protocol_code = 0;
    this.vendor_id = 0;
    this.product_id = 0;
    this.device_version_major = 0;
    this.device_version_minor = 0;
    this.device_version_subminor = 0;
    this.active_configuration = 0;
    this.manufacturer_name = null;
    this.product_name = null;
    this.serial_number = null;
    this.configurations = null;
  };
  DeviceInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  DeviceInfo.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 64}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceInfo.guid
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;













    
    // validate DeviceInfo.manufacturer_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceInfo.product_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate DeviceInfo.serial_number
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, true)
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate DeviceInfo.configurations
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 48, 8, new codec.PointerTo(ConfigurationInfo), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  DeviceInfo.encodedSize = codec.kStructHeaderSize + 56;

  DeviceInfo.decode = function(decoder) {
    var packed;
    var val = new DeviceInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.guid = decoder.decodeStruct(codec.String);
    val.usb_version_major = decoder.decodeStruct(codec.Uint8);
    val.usb_version_minor = decoder.decodeStruct(codec.Uint8);
    val.usb_version_subminor = decoder.decodeStruct(codec.Uint8);
    val.class_code = decoder.decodeStruct(codec.Uint8);
    val.subclass_code = decoder.decodeStruct(codec.Uint8);
    val.protocol_code = decoder.decodeStruct(codec.Uint8);
    val.vendor_id = decoder.decodeStruct(codec.Uint16);
    val.product_id = decoder.decodeStruct(codec.Uint16);
    val.device_version_major = decoder.decodeStruct(codec.Uint8);
    val.device_version_minor = decoder.decodeStruct(codec.Uint8);
    val.device_version_subminor = decoder.decodeStruct(codec.Uint8);
    val.active_configuration = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    val.manufacturer_name = decoder.decodeStruct(codec.NullableString);
    val.product_name = decoder.decodeStruct(codec.NullableString);
    val.serial_number = decoder.decodeStruct(codec.NullableString);
    val.configurations = decoder.decodeArrayPointer(new codec.PointerTo(ConfigurationInfo));
    return val;
  };

  DeviceInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(DeviceInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.guid);
    encoder.encodeStruct(codec.Uint8, val.usb_version_major);
    encoder.encodeStruct(codec.Uint8, val.usb_version_minor);
    encoder.encodeStruct(codec.Uint8, val.usb_version_subminor);
    encoder.encodeStruct(codec.Uint8, val.class_code);
    encoder.encodeStruct(codec.Uint8, val.subclass_code);
    encoder.encodeStruct(codec.Uint8, val.protocol_code);
    encoder.encodeStruct(codec.Uint16, val.vendor_id);
    encoder.encodeStruct(codec.Uint16, val.product_id);
    encoder.encodeStruct(codec.Uint8, val.device_version_major);
    encoder.encodeStruct(codec.Uint8, val.device_version_minor);
    encoder.encodeStruct(codec.Uint8, val.device_version_subminor);
    encoder.encodeStruct(codec.Uint8, val.active_configuration);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.NullableString, val.manufacturer_name);
    encoder.encodeStruct(codec.NullableString, val.product_name);
    encoder.encodeStruct(codec.NullableString, val.serial_number);
    encoder.encodeArrayPointer(new codec.PointerTo(ConfigurationInfo), val.configurations);
  };
  function ControlTransferParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ControlTransferParams.prototype.initDefaults_ = function() {
    this.type = 0;
    this.recipient = 0;
    this.request = 0;
    this.value = 0;
    this.index = 0;
  };
  ControlTransferParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ControlTransferParams.validate = function(messageValidator, offset) {
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


    
    // validate ControlTransferParams.type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, ControlTransferType);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ControlTransferParams.recipient
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, ControlTransferRecipient);
    if (err !== validator.validationError.NONE)
        return err;




    return validator.validationError.NONE;
  };

  ControlTransferParams.encodedSize = codec.kStructHeaderSize + 16;

  ControlTransferParams.decode = function(decoder) {
    var packed;
    var val = new ControlTransferParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.type = decoder.decodeStruct(codec.Int32);
    val.recipient = decoder.decodeStruct(codec.Int32);
    val.request = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    val.value = decoder.decodeStruct(codec.Uint16);
    val.index = decoder.decodeStruct(codec.Uint16);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  ControlTransferParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ControlTransferParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.type);
    encoder.encodeStruct(codec.Int32, val.recipient);
    encoder.encodeStruct(codec.Uint8, val.request);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint16, val.value);
    encoder.encodeStruct(codec.Uint16, val.index);
    encoder.skip(1);
    encoder.skip(1);
  };
  function IsochronousPacket(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  IsochronousPacket.prototype.initDefaults_ = function() {
    this.length = 0;
    this.transferred_length = 0;
    this.status = 0;
  };
  IsochronousPacket.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  IsochronousPacket.validate = function(messageValidator, offset) {
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




    
    // validate IsochronousPacket.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 8, TransferStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  IsochronousPacket.encodedSize = codec.kStructHeaderSize + 16;

  IsochronousPacket.decode = function(decoder) {
    var packed;
    var val = new IsochronousPacket();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.length = decoder.decodeStruct(codec.Uint32);
    val.transferred_length = decoder.decodeStruct(codec.Uint32);
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  IsochronousPacket.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(IsochronousPacket.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.length);
    encoder.encodeStruct(codec.Uint32, val.transferred_length);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_GetDeviceInfo_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_GetDeviceInfo_Params.prototype.initDefaults_ = function() {
  };
  Device_GetDeviceInfo_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_GetDeviceInfo_Params.validate = function(messageValidator, offset) {
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

  Device_GetDeviceInfo_Params.encodedSize = codec.kStructHeaderSize + 0;

  Device_GetDeviceInfo_Params.decode = function(decoder) {
    var packed;
    var val = new Device_GetDeviceInfo_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Device_GetDeviceInfo_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_GetDeviceInfo_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Device_GetDeviceInfo_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_GetDeviceInfo_ResponseParams.prototype.initDefaults_ = function() {
    this.info = null;
  };
  Device_GetDeviceInfo_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_GetDeviceInfo_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_GetDeviceInfo_ResponseParams.info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, DeviceInfo, true);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_GetDeviceInfo_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_GetDeviceInfo_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_GetDeviceInfo_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.info = decoder.decodeStructPointer(DeviceInfo);
    return val;
  };

  Device_GetDeviceInfo_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_GetDeviceInfo_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(DeviceInfo, val.info);
  };
  function Device_Open_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_Open_Params.prototype.initDefaults_ = function() {
  };
  Device_Open_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_Open_Params.validate = function(messageValidator, offset) {
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

  Device_Open_Params.encodedSize = codec.kStructHeaderSize + 0;

  Device_Open_Params.decode = function(decoder) {
    var packed;
    var val = new Device_Open_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Device_Open_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_Open_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Device_Open_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_Open_ResponseParams.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  Device_Open_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_Open_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_Open_ResponseParams.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, OpenDeviceError);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_Open_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_Open_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_Open_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_Open_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_Open_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_Close_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_Close_Params.prototype.initDefaults_ = function() {
  };
  Device_Close_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_Close_Params.validate = function(messageValidator, offset) {
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

  Device_Close_Params.encodedSize = codec.kStructHeaderSize + 0;

  Device_Close_Params.decode = function(decoder) {
    var packed;
    var val = new Device_Close_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Device_Close_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_Close_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Device_Close_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_Close_ResponseParams.prototype.initDefaults_ = function() {
  };
  Device_Close_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_Close_ResponseParams.validate = function(messageValidator, offset) {
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

  Device_Close_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  Device_Close_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_Close_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Device_Close_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_Close_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  function Device_SetConfiguration_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_SetConfiguration_Params.prototype.initDefaults_ = function() {
    this.value = 0;
  };
  Device_SetConfiguration_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_SetConfiguration_Params.validate = function(messageValidator, offset) {
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

  Device_SetConfiguration_Params.encodedSize = codec.kStructHeaderSize + 8;

  Device_SetConfiguration_Params.decode = function(decoder) {
    var packed;
    var val = new Device_SetConfiguration_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.value = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_SetConfiguration_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_SetConfiguration_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.value);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_SetConfiguration_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_SetConfiguration_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Device_SetConfiguration_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_SetConfiguration_ResponseParams.validate = function(messageValidator, offset) {
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

  Device_SetConfiguration_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_SetConfiguration_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_SetConfiguration_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_SetConfiguration_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_SetConfiguration_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ClaimInterface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ClaimInterface_Params.prototype.initDefaults_ = function() {
    this.interface_number = 0;
  };
  Device_ClaimInterface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ClaimInterface_Params.validate = function(messageValidator, offset) {
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

  Device_ClaimInterface_Params.encodedSize = codec.kStructHeaderSize + 8;

  Device_ClaimInterface_Params.decode = function(decoder) {
    var packed;
    var val = new Device_ClaimInterface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.interface_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ClaimInterface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ClaimInterface_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.interface_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ClaimInterface_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ClaimInterface_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Device_ClaimInterface_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ClaimInterface_ResponseParams.validate = function(messageValidator, offset) {
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

  Device_ClaimInterface_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_ClaimInterface_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_ClaimInterface_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ClaimInterface_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ClaimInterface_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ReleaseInterface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ReleaseInterface_Params.prototype.initDefaults_ = function() {
    this.interface_number = 0;
  };
  Device_ReleaseInterface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ReleaseInterface_Params.validate = function(messageValidator, offset) {
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

  Device_ReleaseInterface_Params.encodedSize = codec.kStructHeaderSize + 8;

  Device_ReleaseInterface_Params.decode = function(decoder) {
    var packed;
    var val = new Device_ReleaseInterface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.interface_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ReleaseInterface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ReleaseInterface_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.interface_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ReleaseInterface_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ReleaseInterface_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Device_ReleaseInterface_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ReleaseInterface_ResponseParams.validate = function(messageValidator, offset) {
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

  Device_ReleaseInterface_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_ReleaseInterface_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_ReleaseInterface_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ReleaseInterface_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ReleaseInterface_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_SetInterfaceAlternateSetting_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_SetInterfaceAlternateSetting_Params.prototype.initDefaults_ = function() {
    this.interface_number = 0;
    this.alternate_setting = 0;
  };
  Device_SetInterfaceAlternateSetting_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_SetInterfaceAlternateSetting_Params.validate = function(messageValidator, offset) {
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

  Device_SetInterfaceAlternateSetting_Params.encodedSize = codec.kStructHeaderSize + 8;

  Device_SetInterfaceAlternateSetting_Params.decode = function(decoder) {
    var packed;
    var val = new Device_SetInterfaceAlternateSetting_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.interface_number = decoder.decodeStruct(codec.Uint8);
    val.alternate_setting = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_SetInterfaceAlternateSetting_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_SetInterfaceAlternateSetting_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.interface_number);
    encoder.encodeStruct(codec.Uint8, val.alternate_setting);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_SetInterfaceAlternateSetting_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_SetInterfaceAlternateSetting_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Device_SetInterfaceAlternateSetting_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_SetInterfaceAlternateSetting_ResponseParams.validate = function(messageValidator, offset) {
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

  Device_SetInterfaceAlternateSetting_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_SetInterfaceAlternateSetting_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_SetInterfaceAlternateSetting_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_SetInterfaceAlternateSetting_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_SetInterfaceAlternateSetting_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_Reset_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_Reset_Params.prototype.initDefaults_ = function() {
  };
  Device_Reset_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_Reset_Params.validate = function(messageValidator, offset) {
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

  Device_Reset_Params.encodedSize = codec.kStructHeaderSize + 0;

  Device_Reset_Params.decode = function(decoder) {
    var packed;
    var val = new Device_Reset_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Device_Reset_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_Reset_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function Device_Reset_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_Reset_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Device_Reset_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_Reset_ResponseParams.validate = function(messageValidator, offset) {
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

  Device_Reset_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_Reset_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_Reset_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_Reset_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_Reset_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ClearHalt_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ClearHalt_Params.prototype.initDefaults_ = function() {
    this.endpoint = 0;
  };
  Device_ClearHalt_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ClearHalt_Params.validate = function(messageValidator, offset) {
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

  Device_ClearHalt_Params.encodedSize = codec.kStructHeaderSize + 8;

  Device_ClearHalt_Params.decode = function(decoder) {
    var packed;
    var val = new Device_ClearHalt_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.endpoint = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ClearHalt_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ClearHalt_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.endpoint);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ClearHalt_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ClearHalt_ResponseParams.prototype.initDefaults_ = function() {
    this.success = false;
  };
  Device_ClearHalt_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ClearHalt_ResponseParams.validate = function(messageValidator, offset) {
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

  Device_ClearHalt_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_ClearHalt_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_ClearHalt_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.success = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ClearHalt_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ClearHalt_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.success & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ControlTransferIn_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ControlTransferIn_Params.prototype.initDefaults_ = function() {
    this.params = null;
    this.length = 0;
    this.timeout = 0;
  };
  Device_ControlTransferIn_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ControlTransferIn_Params.validate = function(messageValidator, offset) {
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


    
    // validate Device_ControlTransferIn_Params.params
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ControlTransferParams, false);
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  Device_ControlTransferIn_Params.encodedSize = codec.kStructHeaderSize + 16;

  Device_ControlTransferIn_Params.decode = function(decoder) {
    var packed;
    var val = new Device_ControlTransferIn_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.params = decoder.decodeStructPointer(ControlTransferParams);
    val.length = decoder.decodeStruct(codec.Uint32);
    val.timeout = decoder.decodeStruct(codec.Uint32);
    return val;
  };

  Device_ControlTransferIn_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ControlTransferIn_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ControlTransferParams, val.params);
    encoder.encodeStruct(codec.Uint32, val.length);
    encoder.encodeStruct(codec.Uint32, val.timeout);
  };
  function Device_ControlTransferIn_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ControlTransferIn_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.data = null;
  };
  Device_ControlTransferIn_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ControlTransferIn_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_ControlTransferIn_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, TransferStatus);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Device_ControlTransferIn_ResponseParams.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_ControlTransferIn_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Device_ControlTransferIn_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_ControlTransferIn_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  Device_ControlTransferIn_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ControlTransferIn_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function Device_ControlTransferOut_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ControlTransferOut_Params.prototype.initDefaults_ = function() {
    this.params = null;
    this.data = null;
    this.timeout = 0;
  };
  Device_ControlTransferOut_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ControlTransferOut_Params.validate = function(messageValidator, offset) {
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


    
    // validate Device_ControlTransferOut_Params.params
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ControlTransferParams, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Device_ControlTransferOut_Params.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  Device_ControlTransferOut_Params.encodedSize = codec.kStructHeaderSize + 24;

  Device_ControlTransferOut_Params.decode = function(decoder) {
    var packed;
    var val = new Device_ControlTransferOut_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.params = decoder.decodeStructPointer(ControlTransferParams);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    val.timeout = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ControlTransferOut_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ControlTransferOut_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ControlTransferParams, val.params);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
    encoder.encodeStruct(codec.Uint32, val.timeout);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_ControlTransferOut_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_ControlTransferOut_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  Device_ControlTransferOut_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_ControlTransferOut_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_ControlTransferOut_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, TransferStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_ControlTransferOut_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_ControlTransferOut_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_ControlTransferOut_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_ControlTransferOut_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_ControlTransferOut_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_GenericTransferIn_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_GenericTransferIn_Params.prototype.initDefaults_ = function() {
    this.endpoint_number = 0;
    this.length = 0;
    this.timeout = 0;
  };
  Device_GenericTransferIn_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_GenericTransferIn_Params.validate = function(messageValidator, offset) {
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




    return validator.validationError.NONE;
  };

  Device_GenericTransferIn_Params.encodedSize = codec.kStructHeaderSize + 16;

  Device_GenericTransferIn_Params.decode = function(decoder) {
    var packed;
    var val = new Device_GenericTransferIn_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.endpoint_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.length = decoder.decodeStruct(codec.Uint32);
    val.timeout = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_GenericTransferIn_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_GenericTransferIn_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.endpoint_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.length);
    encoder.encodeStruct(codec.Uint32, val.timeout);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_GenericTransferIn_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_GenericTransferIn_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
    this.data = null;
  };
  Device_GenericTransferIn_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_GenericTransferIn_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_GenericTransferIn_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, TransferStatus);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Device_GenericTransferIn_ResponseParams.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_GenericTransferIn_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Device_GenericTransferIn_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_GenericTransferIn_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  Device_GenericTransferIn_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_GenericTransferIn_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function Device_GenericTransferOut_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_GenericTransferOut_Params.prototype.initDefaults_ = function() {
    this.endpoint_number = 0;
    this.timeout = 0;
    this.data = null;
  };
  Device_GenericTransferOut_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_GenericTransferOut_Params.validate = function(messageValidator, offset) {
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



    
    // validate Device_GenericTransferOut_Params.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  Device_GenericTransferOut_Params.encodedSize = codec.kStructHeaderSize + 16;

  Device_GenericTransferOut_Params.decode = function(decoder) {
    var packed;
    var val = new Device_GenericTransferOut_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.endpoint_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.timeout = decoder.decodeStruct(codec.Uint32);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    return val;
  };

  Device_GenericTransferOut_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_GenericTransferOut_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.endpoint_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.timeout);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
  };
  function Device_GenericTransferOut_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_GenericTransferOut_ResponseParams.prototype.initDefaults_ = function() {
    this.status = 0;
  };
  Device_GenericTransferOut_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_GenericTransferOut_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_GenericTransferOut_ResponseParams.status
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, TransferStatus);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_GenericTransferOut_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_GenericTransferOut_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_GenericTransferOut_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.status = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Device_GenericTransferOut_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_GenericTransferOut_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.status);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Device_IsochronousTransferIn_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_IsochronousTransferIn_Params.prototype.initDefaults_ = function() {
    this.endpoint_number = 0;
    this.timeout = 0;
    this.packet_lengths = null;
  };
  Device_IsochronousTransferIn_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_IsochronousTransferIn_Params.validate = function(messageValidator, offset) {
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



    
    // validate Device_IsochronousTransferIn_Params.packet_lengths
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 4, codec.Uint32, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  Device_IsochronousTransferIn_Params.encodedSize = codec.kStructHeaderSize + 16;

  Device_IsochronousTransferIn_Params.decode = function(decoder) {
    var packed;
    var val = new Device_IsochronousTransferIn_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.endpoint_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.timeout = decoder.decodeStruct(codec.Uint32);
    val.packet_lengths = decoder.decodeArrayPointer(codec.Uint32);
    return val;
  };

  Device_IsochronousTransferIn_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_IsochronousTransferIn_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.endpoint_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.timeout);
    encoder.encodeArrayPointer(codec.Uint32, val.packet_lengths);
  };
  function Device_IsochronousTransferIn_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_IsochronousTransferIn_ResponseParams.prototype.initDefaults_ = function() {
    this.data = null;
    this.packets = null;
  };
  Device_IsochronousTransferIn_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_IsochronousTransferIn_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_IsochronousTransferIn_ResponseParams.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 1, codec.Uint8, true, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Device_IsochronousTransferIn_ResponseParams.packets
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(IsochronousPacket), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_IsochronousTransferIn_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Device_IsochronousTransferIn_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_IsochronousTransferIn_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    val.packets = decoder.decodeArrayPointer(new codec.PointerTo(IsochronousPacket));
    return val;
  };

  Device_IsochronousTransferIn_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_IsochronousTransferIn_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
    encoder.encodeArrayPointer(new codec.PointerTo(IsochronousPacket), val.packets);
  };
  function Device_IsochronousTransferOut_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_IsochronousTransferOut_Params.prototype.initDefaults_ = function() {
    this.endpoint_number = 0;
    this.timeout = 0;
    this.data = null;
    this.packet_lengths = null;
  };
  Device_IsochronousTransferOut_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_IsochronousTransferOut_Params.validate = function(messageValidator, offset) {
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



    
    // validate Device_IsochronousTransferOut_Params.data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 1, codec.Uint8, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Device_IsochronousTransferOut_Params.packet_lengths
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 4, codec.Uint32, false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  Device_IsochronousTransferOut_Params.encodedSize = codec.kStructHeaderSize + 24;

  Device_IsochronousTransferOut_Params.decode = function(decoder) {
    var packed;
    var val = new Device_IsochronousTransferOut_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.endpoint_number = decoder.decodeStruct(codec.Uint8);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.timeout = decoder.decodeStruct(codec.Uint32);
    val.data = decoder.decodeArrayPointer(codec.Uint8);
    val.packet_lengths = decoder.decodeArrayPointer(codec.Uint32);
    return val;
  };

  Device_IsochronousTransferOut_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_IsochronousTransferOut_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint8, val.endpoint_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Uint32, val.timeout);
    encoder.encodeArrayPointer(codec.Uint8, val.data);
    encoder.encodeArrayPointer(codec.Uint32, val.packet_lengths);
  };
  function Device_IsochronousTransferOut_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Device_IsochronousTransferOut_ResponseParams.prototype.initDefaults_ = function() {
    this.packets = null;
  };
  Device_IsochronousTransferOut_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Device_IsochronousTransferOut_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Device_IsochronousTransferOut_ResponseParams.packets
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(IsochronousPacket), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Device_IsochronousTransferOut_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Device_IsochronousTransferOut_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Device_IsochronousTransferOut_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.packets = decoder.decodeArrayPointer(new codec.PointerTo(IsochronousPacket));
    return val;
  };

  Device_IsochronousTransferOut_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Device_IsochronousTransferOut_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(IsochronousPacket), val.packets);
  };
  var kDevice_GetDeviceInfo_Name = 0;
  var kDevice_Open_Name = 1;
  var kDevice_Close_Name = 2;
  var kDevice_SetConfiguration_Name = 3;
  var kDevice_ClaimInterface_Name = 4;
  var kDevice_ReleaseInterface_Name = 5;
  var kDevice_SetInterfaceAlternateSetting_Name = 6;
  var kDevice_Reset_Name = 7;
  var kDevice_ClearHalt_Name = 8;
  var kDevice_ControlTransferIn_Name = 9;
  var kDevice_ControlTransferOut_Name = 10;
  var kDevice_GenericTransferIn_Name = 11;
  var kDevice_GenericTransferOut_Name = 12;
  var kDevice_IsochronousTransferIn_Name = 13;
  var kDevice_IsochronousTransferOut_Name = 14;

  function DevicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Device,
                                                   handleOrPtrInfo);
  }

  function DeviceProxy(receiver) {
    this.receiver_ = receiver;
  }
  DevicePtr.prototype.getDeviceInfo = function() {
    return DeviceProxy.prototype.getDeviceInfo
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.getDeviceInfo = function() {
    var params = new Device_GetDeviceInfo_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_GetDeviceInfo_Name,
          codec.align(Device_GetDeviceInfo_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_GetDeviceInfo_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_GetDeviceInfo_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.open = function() {
    return DeviceProxy.prototype.open
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.open = function() {
    var params = new Device_Open_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_Open_Name,
          codec.align(Device_Open_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_Open_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_Open_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.close = function() {
    return DeviceProxy.prototype.close
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.close = function() {
    var params = new Device_Close_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_Close_Name,
          codec.align(Device_Close_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_Close_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_Close_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.setConfiguration = function() {
    return DeviceProxy.prototype.setConfiguration
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.setConfiguration = function(value) {
    var params = new Device_SetConfiguration_Params();
    params.value = value;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_SetConfiguration_Name,
          codec.align(Device_SetConfiguration_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_SetConfiguration_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_SetConfiguration_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.claimInterface = function() {
    return DeviceProxy.prototype.claimInterface
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.claimInterface = function(interface_number) {
    var params = new Device_ClaimInterface_Params();
    params.interface_number = interface_number;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_ClaimInterface_Name,
          codec.align(Device_ClaimInterface_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_ClaimInterface_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_ClaimInterface_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.releaseInterface = function() {
    return DeviceProxy.prototype.releaseInterface
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.releaseInterface = function(interface_number) {
    var params = new Device_ReleaseInterface_Params();
    params.interface_number = interface_number;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_ReleaseInterface_Name,
          codec.align(Device_ReleaseInterface_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_ReleaseInterface_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_ReleaseInterface_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.setInterfaceAlternateSetting = function() {
    return DeviceProxy.prototype.setInterfaceAlternateSetting
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.setInterfaceAlternateSetting = function(interface_number, alternate_setting) {
    var params = new Device_SetInterfaceAlternateSetting_Params();
    params.interface_number = interface_number;
    params.alternate_setting = alternate_setting;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_SetInterfaceAlternateSetting_Name,
          codec.align(Device_SetInterfaceAlternateSetting_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_SetInterfaceAlternateSetting_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_SetInterfaceAlternateSetting_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.reset = function() {
    return DeviceProxy.prototype.reset
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.reset = function() {
    var params = new Device_Reset_Params();
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_Reset_Name,
          codec.align(Device_Reset_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_Reset_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_Reset_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.clearHalt = function() {
    return DeviceProxy.prototype.clearHalt
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.clearHalt = function(endpoint) {
    var params = new Device_ClearHalt_Params();
    params.endpoint = endpoint;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_ClearHalt_Name,
          codec.align(Device_ClearHalt_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_ClearHalt_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_ClearHalt_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.controlTransferIn = function() {
    return DeviceProxy.prototype.controlTransferIn
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.controlTransferIn = function(params, length, timeout) {
    var params = new Device_ControlTransferIn_Params();
    params.params = params;
    params.length = length;
    params.timeout = timeout;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_ControlTransferIn_Name,
          codec.align(Device_ControlTransferIn_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_ControlTransferIn_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_ControlTransferIn_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.controlTransferOut = function() {
    return DeviceProxy.prototype.controlTransferOut
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.controlTransferOut = function(params, data, timeout) {
    var params = new Device_ControlTransferOut_Params();
    params.params = params;
    params.data = data;
    params.timeout = timeout;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_ControlTransferOut_Name,
          codec.align(Device_ControlTransferOut_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_ControlTransferOut_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_ControlTransferOut_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.genericTransferIn = function() {
    return DeviceProxy.prototype.genericTransferIn
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.genericTransferIn = function(endpoint_number, length, timeout) {
    var params = new Device_GenericTransferIn_Params();
    params.endpoint_number = endpoint_number;
    params.length = length;
    params.timeout = timeout;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_GenericTransferIn_Name,
          codec.align(Device_GenericTransferIn_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_GenericTransferIn_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_GenericTransferIn_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.genericTransferOut = function() {
    return DeviceProxy.prototype.genericTransferOut
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.genericTransferOut = function(endpoint_number, data, timeout) {
    var params = new Device_GenericTransferOut_Params();
    params.endpoint_number = endpoint_number;
    params.data = data;
    params.timeout = timeout;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_GenericTransferOut_Name,
          codec.align(Device_GenericTransferOut_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_GenericTransferOut_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_GenericTransferOut_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.isochronousTransferIn = function() {
    return DeviceProxy.prototype.isochronousTransferIn
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.isochronousTransferIn = function(endpoint_number, packet_lengths, timeout) {
    var params = new Device_IsochronousTransferIn_Params();
    params.endpoint_number = endpoint_number;
    params.packet_lengths = packet_lengths;
    params.timeout = timeout;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_IsochronousTransferIn_Name,
          codec.align(Device_IsochronousTransferIn_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_IsochronousTransferIn_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_IsochronousTransferIn_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  DevicePtr.prototype.isochronousTransferOut = function() {
    return DeviceProxy.prototype.isochronousTransferOut
        .apply(this.ptr.getProxy(), arguments);
  };

  DeviceProxy.prototype.isochronousTransferOut = function(endpoint_number, data, packet_lengths, timeout) {
    var params = new Device_IsochronousTransferOut_Params();
    params.endpoint_number = endpoint_number;
    params.data = data;
    params.packet_lengths = packet_lengths;
    params.timeout = timeout;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kDevice_IsochronousTransferOut_Name,
          codec.align(Device_IsochronousTransferOut_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Device_IsochronousTransferOut_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Device_IsochronousTransferOut_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function DeviceStub(delegate) {
    this.delegate_ = delegate;
  }
  DeviceStub.prototype.getDeviceInfo = function() {
    return this.delegate_ && this.delegate_.getDeviceInfo && this.delegate_.getDeviceInfo();
  }
  DeviceStub.prototype.open = function() {
    return this.delegate_ && this.delegate_.open && this.delegate_.open();
  }
  DeviceStub.prototype.close = function() {
    return this.delegate_ && this.delegate_.close && this.delegate_.close();
  }
  DeviceStub.prototype.setConfiguration = function(value) {
    return this.delegate_ && this.delegate_.setConfiguration && this.delegate_.setConfiguration(value);
  }
  DeviceStub.prototype.claimInterface = function(interface_number) {
    return this.delegate_ && this.delegate_.claimInterface && this.delegate_.claimInterface(interface_number);
  }
  DeviceStub.prototype.releaseInterface = function(interface_number) {
    return this.delegate_ && this.delegate_.releaseInterface && this.delegate_.releaseInterface(interface_number);
  }
  DeviceStub.prototype.setInterfaceAlternateSetting = function(interface_number, alternate_setting) {
    return this.delegate_ && this.delegate_.setInterfaceAlternateSetting && this.delegate_.setInterfaceAlternateSetting(interface_number, alternate_setting);
  }
  DeviceStub.prototype.reset = function() {
    return this.delegate_ && this.delegate_.reset && this.delegate_.reset();
  }
  DeviceStub.prototype.clearHalt = function(endpoint) {
    return this.delegate_ && this.delegate_.clearHalt && this.delegate_.clearHalt(endpoint);
  }
  DeviceStub.prototype.controlTransferIn = function(params, length, timeout) {
    return this.delegate_ && this.delegate_.controlTransferIn && this.delegate_.controlTransferIn(params, length, timeout);
  }
  DeviceStub.prototype.controlTransferOut = function(params, data, timeout) {
    return this.delegate_ && this.delegate_.controlTransferOut && this.delegate_.controlTransferOut(params, data, timeout);
  }
  DeviceStub.prototype.genericTransferIn = function(endpoint_number, length, timeout) {
    return this.delegate_ && this.delegate_.genericTransferIn && this.delegate_.genericTransferIn(endpoint_number, length, timeout);
  }
  DeviceStub.prototype.genericTransferOut = function(endpoint_number, data, timeout) {
    return this.delegate_ && this.delegate_.genericTransferOut && this.delegate_.genericTransferOut(endpoint_number, data, timeout);
  }
  DeviceStub.prototype.isochronousTransferIn = function(endpoint_number, packet_lengths, timeout) {
    return this.delegate_ && this.delegate_.isochronousTransferIn && this.delegate_.isochronousTransferIn(endpoint_number, packet_lengths, timeout);
  }
  DeviceStub.prototype.isochronousTransferOut = function(endpoint_number, data, packet_lengths, timeout) {
    return this.delegate_ && this.delegate_.isochronousTransferOut && this.delegate_.isochronousTransferOut(endpoint_number, data, packet_lengths, timeout);
  }

  DeviceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  DeviceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kDevice_GetDeviceInfo_Name:
      var params = reader.decodeStruct(Device_GetDeviceInfo_Params);
      return this.getDeviceInfo().then(function(response) {
        var responseParams =
            new Device_GetDeviceInfo_ResponseParams();
        responseParams.info = response.info;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_GetDeviceInfo_Name,
            codec.align(Device_GetDeviceInfo_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_GetDeviceInfo_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_Open_Name:
      var params = reader.decodeStruct(Device_Open_Params);
      return this.open().then(function(response) {
        var responseParams =
            new Device_Open_ResponseParams();
        responseParams.error = response.error;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_Open_Name,
            codec.align(Device_Open_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_Open_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_Close_Name:
      var params = reader.decodeStruct(Device_Close_Params);
      return this.close().then(function(response) {
        var responseParams =
            new Device_Close_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_Close_Name,
            codec.align(Device_Close_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_Close_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_SetConfiguration_Name:
      var params = reader.decodeStruct(Device_SetConfiguration_Params);
      return this.setConfiguration(params.value).then(function(response) {
        var responseParams =
            new Device_SetConfiguration_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_SetConfiguration_Name,
            codec.align(Device_SetConfiguration_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_SetConfiguration_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_ClaimInterface_Name:
      var params = reader.decodeStruct(Device_ClaimInterface_Params);
      return this.claimInterface(params.interface_number).then(function(response) {
        var responseParams =
            new Device_ClaimInterface_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_ClaimInterface_Name,
            codec.align(Device_ClaimInterface_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_ClaimInterface_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_ReleaseInterface_Name:
      var params = reader.decodeStruct(Device_ReleaseInterface_Params);
      return this.releaseInterface(params.interface_number).then(function(response) {
        var responseParams =
            new Device_ReleaseInterface_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_ReleaseInterface_Name,
            codec.align(Device_ReleaseInterface_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_ReleaseInterface_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_SetInterfaceAlternateSetting_Name:
      var params = reader.decodeStruct(Device_SetInterfaceAlternateSetting_Params);
      return this.setInterfaceAlternateSetting(params.interface_number, params.alternate_setting).then(function(response) {
        var responseParams =
            new Device_SetInterfaceAlternateSetting_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_SetInterfaceAlternateSetting_Name,
            codec.align(Device_SetInterfaceAlternateSetting_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_SetInterfaceAlternateSetting_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_Reset_Name:
      var params = reader.decodeStruct(Device_Reset_Params);
      return this.reset().then(function(response) {
        var responseParams =
            new Device_Reset_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_Reset_Name,
            codec.align(Device_Reset_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_Reset_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_ClearHalt_Name:
      var params = reader.decodeStruct(Device_ClearHalt_Params);
      return this.clearHalt(params.endpoint).then(function(response) {
        var responseParams =
            new Device_ClearHalt_ResponseParams();
        responseParams.success = response.success;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_ClearHalt_Name,
            codec.align(Device_ClearHalt_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_ClearHalt_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_ControlTransferIn_Name:
      var params = reader.decodeStruct(Device_ControlTransferIn_Params);
      return this.controlTransferIn(params.params, params.length, params.timeout).then(function(response) {
        var responseParams =
            new Device_ControlTransferIn_ResponseParams();
        responseParams.status = response.status;
        responseParams.data = response.data;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_ControlTransferIn_Name,
            codec.align(Device_ControlTransferIn_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_ControlTransferIn_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_ControlTransferOut_Name:
      var params = reader.decodeStruct(Device_ControlTransferOut_Params);
      return this.controlTransferOut(params.params, params.data, params.timeout).then(function(response) {
        var responseParams =
            new Device_ControlTransferOut_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_ControlTransferOut_Name,
            codec.align(Device_ControlTransferOut_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_ControlTransferOut_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_GenericTransferIn_Name:
      var params = reader.decodeStruct(Device_GenericTransferIn_Params);
      return this.genericTransferIn(params.endpoint_number, params.length, params.timeout).then(function(response) {
        var responseParams =
            new Device_GenericTransferIn_ResponseParams();
        responseParams.status = response.status;
        responseParams.data = response.data;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_GenericTransferIn_Name,
            codec.align(Device_GenericTransferIn_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_GenericTransferIn_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_GenericTransferOut_Name:
      var params = reader.decodeStruct(Device_GenericTransferOut_Params);
      return this.genericTransferOut(params.endpoint_number, params.data, params.timeout).then(function(response) {
        var responseParams =
            new Device_GenericTransferOut_ResponseParams();
        responseParams.status = response.status;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_GenericTransferOut_Name,
            codec.align(Device_GenericTransferOut_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_GenericTransferOut_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_IsochronousTransferIn_Name:
      var params = reader.decodeStruct(Device_IsochronousTransferIn_Params);
      return this.isochronousTransferIn(params.endpoint_number, params.packet_lengths, params.timeout).then(function(response) {
        var responseParams =
            new Device_IsochronousTransferIn_ResponseParams();
        responseParams.data = response.data;
        responseParams.packets = response.packets;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_IsochronousTransferIn_Name,
            codec.align(Device_IsochronousTransferIn_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_IsochronousTransferIn_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kDevice_IsochronousTransferOut_Name:
      var params = reader.decodeStruct(Device_IsochronousTransferOut_Params);
      return this.isochronousTransferOut(params.endpoint_number, params.data, params.packet_lengths, params.timeout).then(function(response) {
        var responseParams =
            new Device_IsochronousTransferOut_ResponseParams();
        responseParams.packets = response.packets;
        var builder = new codec.MessageWithRequestIDBuilder(
            kDevice_IsochronousTransferOut_Name,
            codec.align(Device_IsochronousTransferOut_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Device_IsochronousTransferOut_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateDeviceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kDevice_GetDeviceInfo_Name:
        if (message.expectsResponse())
          paramsClass = Device_GetDeviceInfo_Params;
      break;
      case kDevice_Open_Name:
        if (message.expectsResponse())
          paramsClass = Device_Open_Params;
      break;
      case kDevice_Close_Name:
        if (message.expectsResponse())
          paramsClass = Device_Close_Params;
      break;
      case kDevice_SetConfiguration_Name:
        if (message.expectsResponse())
          paramsClass = Device_SetConfiguration_Params;
      break;
      case kDevice_ClaimInterface_Name:
        if (message.expectsResponse())
          paramsClass = Device_ClaimInterface_Params;
      break;
      case kDevice_ReleaseInterface_Name:
        if (message.expectsResponse())
          paramsClass = Device_ReleaseInterface_Params;
      break;
      case kDevice_SetInterfaceAlternateSetting_Name:
        if (message.expectsResponse())
          paramsClass = Device_SetInterfaceAlternateSetting_Params;
      break;
      case kDevice_Reset_Name:
        if (message.expectsResponse())
          paramsClass = Device_Reset_Params;
      break;
      case kDevice_ClearHalt_Name:
        if (message.expectsResponse())
          paramsClass = Device_ClearHalt_Params;
      break;
      case kDevice_ControlTransferIn_Name:
        if (message.expectsResponse())
          paramsClass = Device_ControlTransferIn_Params;
      break;
      case kDevice_ControlTransferOut_Name:
        if (message.expectsResponse())
          paramsClass = Device_ControlTransferOut_Params;
      break;
      case kDevice_GenericTransferIn_Name:
        if (message.expectsResponse())
          paramsClass = Device_GenericTransferIn_Params;
      break;
      case kDevice_GenericTransferOut_Name:
        if (message.expectsResponse())
          paramsClass = Device_GenericTransferOut_Params;
      break;
      case kDevice_IsochronousTransferIn_Name:
        if (message.expectsResponse())
          paramsClass = Device_IsochronousTransferIn_Params;
      break;
      case kDevice_IsochronousTransferOut_Name:
        if (message.expectsResponse())
          paramsClass = Device_IsochronousTransferOut_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateDeviceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kDevice_GetDeviceInfo_Name:
        if (message.isResponse())
          paramsClass = Device_GetDeviceInfo_ResponseParams;
        break;
      case kDevice_Open_Name:
        if (message.isResponse())
          paramsClass = Device_Open_ResponseParams;
        break;
      case kDevice_Close_Name:
        if (message.isResponse())
          paramsClass = Device_Close_ResponseParams;
        break;
      case kDevice_SetConfiguration_Name:
        if (message.isResponse())
          paramsClass = Device_SetConfiguration_ResponseParams;
        break;
      case kDevice_ClaimInterface_Name:
        if (message.isResponse())
          paramsClass = Device_ClaimInterface_ResponseParams;
        break;
      case kDevice_ReleaseInterface_Name:
        if (message.isResponse())
          paramsClass = Device_ReleaseInterface_ResponseParams;
        break;
      case kDevice_SetInterfaceAlternateSetting_Name:
        if (message.isResponse())
          paramsClass = Device_SetInterfaceAlternateSetting_ResponseParams;
        break;
      case kDevice_Reset_Name:
        if (message.isResponse())
          paramsClass = Device_Reset_ResponseParams;
        break;
      case kDevice_ClearHalt_Name:
        if (message.isResponse())
          paramsClass = Device_ClearHalt_ResponseParams;
        break;
      case kDevice_ControlTransferIn_Name:
        if (message.isResponse())
          paramsClass = Device_ControlTransferIn_ResponseParams;
        break;
      case kDevice_ControlTransferOut_Name:
        if (message.isResponse())
          paramsClass = Device_ControlTransferOut_ResponseParams;
        break;
      case kDevice_GenericTransferIn_Name:
        if (message.isResponse())
          paramsClass = Device_GenericTransferIn_ResponseParams;
        break;
      case kDevice_GenericTransferOut_Name:
        if (message.isResponse())
          paramsClass = Device_GenericTransferOut_ResponseParams;
        break;
      case kDevice_IsochronousTransferIn_Name:
        if (message.isResponse())
          paramsClass = Device_IsochronousTransferIn_ResponseParams;
        break;
      case kDevice_IsochronousTransferOut_Name:
        if (message.isResponse())
          paramsClass = Device_IsochronousTransferOut_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Device = {
    name: 'device::usb::Device',
    ptrClass: DevicePtr,
    proxyClass: DeviceProxy,
    stubClass: DeviceStub,
    validateRequest: validateDeviceRequest,
    validateResponse: validateDeviceResponse,
  };
  DeviceStub.prototype.validator = validateDeviceRequest;
  DeviceProxy.prototype.validator = validateDeviceResponse;

  var exports = {};
  exports.OpenDeviceError = OpenDeviceError;
  exports.TransferDirection = TransferDirection;
  exports.ControlTransferType = ControlTransferType;
  exports.ControlTransferRecipient = ControlTransferRecipient;
  exports.EndpointType = EndpointType;
  exports.TransferStatus = TransferStatus;
  exports.EndpointInfo = EndpointInfo;
  exports.AlternateInterfaceInfo = AlternateInterfaceInfo;
  exports.InterfaceInfo = InterfaceInfo;
  exports.ConfigurationInfo = ConfigurationInfo;
  exports.DeviceInfo = DeviceInfo;
  exports.ControlTransferParams = ControlTransferParams;
  exports.IsochronousPacket = IsochronousPacket;
  exports.Device = Device;
  exports.DevicePtr = DevicePtr;

  return exports;
});
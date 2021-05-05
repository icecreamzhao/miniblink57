// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/service_manager/public/interfaces/connector.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/service_manager/public/interfaces/interface_provider.mojom",
], function(bindings, codec, core, validator, interface_provider$) {
  var kRootUserID = "505C0EE9-3013-43C0-82B0-A84F50CF8D84";
  var kInheritUserID = "D26290E4-4485-4EAE-81A2-66D1EEB40A9D";
  var kInvalidInstanceID = 0;
  var ConnectResult = {};
  ConnectResult.SUCCEEDED = 0;
  ConnectResult.INVALID_ARGUMENT = ConnectResult.SUCCEEDED + 1;
  ConnectResult.ACCESS_DENIED = ConnectResult.INVALID_ARGUMENT + 1;

  ConnectResult.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  ConnectResult.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function Identity(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Identity.prototype.initDefaults_ = function() {
    this.name = null;
    this.user_id = null;
    this.instance = null;
  };
  Identity.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Identity.validate = function(messageValidator, offset) {
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


    
    // validate Identity.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Identity.user_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Identity.instance
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Identity.encodedSize = codec.kStructHeaderSize + 24;

  Identity.decode = function(decoder) {
    var packed;
    var val = new Identity();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.user_id = decoder.decodeStruct(codec.String);
    val.instance = decoder.decodeStruct(codec.String);
    return val;
  };

  Identity.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Identity.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStruct(codec.String, val.user_id);
    encoder.encodeStruct(codec.String, val.instance);
  };
  function PIDReceiver_SetPID_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PIDReceiver_SetPID_Params.prototype.initDefaults_ = function() {
    this.pid = 0;
  };
  PIDReceiver_SetPID_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PIDReceiver_SetPID_Params.validate = function(messageValidator, offset) {
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

  PIDReceiver_SetPID_Params.encodedSize = codec.kStructHeaderSize + 8;

  PIDReceiver_SetPID_Params.decode = function(decoder) {
    var packed;
    var val = new PIDReceiver_SetPID_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.pid = decoder.decodeStruct(codec.Uint32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PIDReceiver_SetPID_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PIDReceiver_SetPID_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Uint32, val.pid);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Connector_StartService_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Connector_StartService_Params.prototype.initDefaults_ = function() {
    this.name = null;
    this.service = null;
    this.pid_receiver_request = new bindings.InterfaceRequest();
  };
  Connector_StartService_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Connector_StartService_Params.validate = function(messageValidator, offset) {
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


    
    // validate Connector_StartService_Params.name
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, Identity, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Connector_StartService_Params.service
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Connector_StartService_Params.pid_receiver_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 12, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Connector_StartService_Params.encodedSize = codec.kStructHeaderSize + 16;

  Connector_StartService_Params.decode = function(decoder) {
    var packed;
    var val = new Connector_StartService_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStructPointer(Identity);
    val.service = decoder.decodeStruct(codec.Handle);
    val.pid_receiver_request = decoder.decodeStruct(codec.InterfaceRequest);
    return val;
  };

  Connector_StartService_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Connector_StartService_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(Identity, val.name);
    encoder.encodeStruct(codec.Handle, val.service);
    encoder.encodeStruct(codec.InterfaceRequest, val.pid_receiver_request);
  };
  function Connector_Connect_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Connector_Connect_Params.prototype.initDefaults_ = function() {
    this.target = null;
    this.remote_interfaces = new bindings.InterfaceRequest();
  };
  Connector_Connect_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Connector_Connect_Params.validate = function(messageValidator, offset) {
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


    
    // validate Connector_Connect_Params.target
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, Identity, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Connector_Connect_Params.remote_interfaces
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Connector_Connect_Params.encodedSize = codec.kStructHeaderSize + 16;

  Connector_Connect_Params.decode = function(decoder) {
    var packed;
    var val = new Connector_Connect_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.target = decoder.decodeStructPointer(Identity);
    val.remote_interfaces = decoder.decodeStruct(codec.NullableInterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Connector_Connect_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Connector_Connect_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(Identity, val.target);
    encoder.encodeStruct(codec.NullableInterfaceRequest, val.remote_interfaces);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Connector_Connect_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Connector_Connect_ResponseParams.prototype.initDefaults_ = function() {
    this.result = 0;
    this.user_id = null;
  };
  Connector_Connect_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Connector_Connect_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Connector_Connect_ResponseParams.result
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, ConnectResult);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Connector_Connect_ResponseParams.user_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Connector_Connect_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Connector_Connect_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Connector_Connect_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.user_id = decoder.decodeStruct(codec.String);
    return val;
  };

  Connector_Connect_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Connector_Connect_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.result);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.user_id);
  };
  function Connector_BindInterface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Connector_BindInterface_Params.prototype.initDefaults_ = function() {
    this.target = null;
    this.interface_name = null;
    this.interface_pipe = null;
  };
  Connector_BindInterface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Connector_BindInterface_Params.validate = function(messageValidator, offset) {
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


    
    // validate Connector_BindInterface_Params.target
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, Identity, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Connector_BindInterface_Params.interface_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Connector_BindInterface_Params.interface_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Connector_BindInterface_Params.encodedSize = codec.kStructHeaderSize + 24;

  Connector_BindInterface_Params.decode = function(decoder) {
    var packed;
    var val = new Connector_BindInterface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.target = decoder.decodeStructPointer(Identity);
    val.interface_name = decoder.decodeStruct(codec.String);
    val.interface_pipe = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Connector_BindInterface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Connector_BindInterface_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(Identity, val.target);
    encoder.encodeStruct(codec.String, val.interface_name);
    encoder.encodeStruct(codec.Handle, val.interface_pipe);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Connector_BindInterface_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Connector_BindInterface_ResponseParams.prototype.initDefaults_ = function() {
    this.result = 0;
    this.user_id = null;
  };
  Connector_BindInterface_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Connector_BindInterface_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Connector_BindInterface_ResponseParams.result
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, ConnectResult);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Connector_BindInterface_ResponseParams.user_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Connector_BindInterface_ResponseParams.encodedSize = codec.kStructHeaderSize + 16;

  Connector_BindInterface_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Connector_BindInterface_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.user_id = decoder.decodeStruct(codec.String);
    return val;
  };

  Connector_BindInterface_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Connector_BindInterface_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.result);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.user_id);
  };
  function Connector_Clone_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Connector_Clone_Params.prototype.initDefaults_ = function() {
    this.request = new bindings.InterfaceRequest();
  };
  Connector_Clone_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Connector_Clone_Params.validate = function(messageValidator, offset) {
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


    
    // validate Connector_Clone_Params.request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Connector_Clone_Params.encodedSize = codec.kStructHeaderSize + 8;

  Connector_Clone_Params.decode = function(decoder) {
    var packed;
    var val = new Connector_Clone_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.request = decoder.decodeStruct(codec.InterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Connector_Clone_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Connector_Clone_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.InterfaceRequest, val.request);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  var kPIDReceiver_SetPID_Name = 0;

  function PIDReceiverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PIDReceiver,
                                                   handleOrPtrInfo);
  }

  function PIDReceiverProxy(receiver) {
    this.receiver_ = receiver;
  }
  PIDReceiverPtr.prototype.setPID = function() {
    return PIDReceiverProxy.prototype.setPID
        .apply(this.ptr.getProxy(), arguments);
  };

  PIDReceiverProxy.prototype.setPID = function(pid) {
    var params = new PIDReceiver_SetPID_Params();
    params.pid = pid;
    var builder = new codec.MessageBuilder(
        kPIDReceiver_SetPID_Name,
        codec.align(PIDReceiver_SetPID_Params.encodedSize));
    builder.encodeStruct(PIDReceiver_SetPID_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PIDReceiverStub(delegate) {
    this.delegate_ = delegate;
  }
  PIDReceiverStub.prototype.setPID = function(pid) {
    return this.delegate_ && this.delegate_.setPID && this.delegate_.setPID(pid);
  }

  PIDReceiverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPIDReceiver_SetPID_Name:
      var params = reader.decodeStruct(PIDReceiver_SetPID_Params);
      this.setPID(params.pid);
      return true;
    default:
      return false;
    }
  };

  PIDReceiverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePIDReceiverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPIDReceiver_SetPID_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PIDReceiver_SetPID_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePIDReceiverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PIDReceiver = {
    name: 'service_manager::mojom::PIDReceiver',
    ptrClass: PIDReceiverPtr,
    proxyClass: PIDReceiverProxy,
    stubClass: PIDReceiverStub,
    validateRequest: validatePIDReceiverRequest,
    validateResponse: null,
  };
  PIDReceiverStub.prototype.validator = validatePIDReceiverRequest;
  PIDReceiverProxy.prototype.validator = null;
  var kConnector_StartService_Name = 0;
  var kConnector_Connect_Name = 1;
  var kConnector_BindInterface_Name = 2;
  var kConnector_Clone_Name = 3;

  function ConnectorPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Connector,
                                                   handleOrPtrInfo);
  }

  function ConnectorProxy(receiver) {
    this.receiver_ = receiver;
  }
  ConnectorPtr.prototype.startService = function() {
    return ConnectorProxy.prototype.startService
        .apply(this.ptr.getProxy(), arguments);
  };

  ConnectorProxy.prototype.startService = function(name, service, pid_receiver_request) {
    var params = new Connector_StartService_Params();
    params.name = name;
    params.service = service;
    params.pid_receiver_request = pid_receiver_request;
    var builder = new codec.MessageBuilder(
        kConnector_StartService_Name,
        codec.align(Connector_StartService_Params.encodedSize));
    builder.encodeStruct(Connector_StartService_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ConnectorPtr.prototype.connect = function() {
    return ConnectorProxy.prototype.connect
        .apply(this.ptr.getProxy(), arguments);
  };

  ConnectorProxy.prototype.connect = function(target, remote_interfaces) {
    var params = new Connector_Connect_Params();
    params.target = target;
    params.remote_interfaces = remote_interfaces;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kConnector_Connect_Name,
          codec.align(Connector_Connect_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Connector_Connect_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Connector_Connect_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ConnectorPtr.prototype.bindInterface = function() {
    return ConnectorProxy.prototype.bindInterface
        .apply(this.ptr.getProxy(), arguments);
  };

  ConnectorProxy.prototype.bindInterface = function(target, interface_name, interface_pipe) {
    var params = new Connector_BindInterface_Params();
    params.target = target;
    params.interface_name = interface_name;
    params.interface_pipe = interface_pipe;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kConnector_BindInterface_Name,
          codec.align(Connector_BindInterface_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Connector_BindInterface_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Connector_BindInterface_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ConnectorPtr.prototype.clone = function() {
    return ConnectorProxy.prototype.clone
        .apply(this.ptr.getProxy(), arguments);
  };

  ConnectorProxy.prototype.clone = function(request) {
    var params = new Connector_Clone_Params();
    params.request = request;
    var builder = new codec.MessageBuilder(
        kConnector_Clone_Name,
        codec.align(Connector_Clone_Params.encodedSize));
    builder.encodeStruct(Connector_Clone_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ConnectorStub(delegate) {
    this.delegate_ = delegate;
  }
  ConnectorStub.prototype.startService = function(name, service, pid_receiver_request) {
    return this.delegate_ && this.delegate_.startService && this.delegate_.startService(name, service, pid_receiver_request);
  }
  ConnectorStub.prototype.connect = function(target, remote_interfaces) {
    return this.delegate_ && this.delegate_.connect && this.delegate_.connect(target, remote_interfaces);
  }
  ConnectorStub.prototype.bindInterface = function(target, interface_name, interface_pipe) {
    return this.delegate_ && this.delegate_.bindInterface && this.delegate_.bindInterface(target, interface_name, interface_pipe);
  }
  ConnectorStub.prototype.clone = function(request) {
    return this.delegate_ && this.delegate_.clone && this.delegate_.clone(request);
  }

  ConnectorStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kConnector_StartService_Name:
      var params = reader.decodeStruct(Connector_StartService_Params);
      this.startService(params.name, params.service, params.pid_receiver_request);
      return true;
    case kConnector_Clone_Name:
      var params = reader.decodeStruct(Connector_Clone_Params);
      this.clone(params.request);
      return true;
    default:
      return false;
    }
  };

  ConnectorStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kConnector_Connect_Name:
      var params = reader.decodeStruct(Connector_Connect_Params);
      return this.connect(params.target, params.remote_interfaces).then(function(response) {
        var responseParams =
            new Connector_Connect_ResponseParams();
        responseParams.result = response.result;
        responseParams.user_id = response.user_id;
        var builder = new codec.MessageWithRequestIDBuilder(
            kConnector_Connect_Name,
            codec.align(Connector_Connect_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Connector_Connect_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kConnector_BindInterface_Name:
      var params = reader.decodeStruct(Connector_BindInterface_Params);
      return this.bindInterface(params.target, params.interface_name, params.interface_pipe).then(function(response) {
        var responseParams =
            new Connector_BindInterface_ResponseParams();
        responseParams.result = response.result;
        responseParams.user_id = response.user_id;
        var builder = new codec.MessageWithRequestIDBuilder(
            kConnector_BindInterface_Name,
            codec.align(Connector_BindInterface_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Connector_BindInterface_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateConnectorRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kConnector_StartService_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Connector_StartService_Params;
      break;
      case kConnector_Connect_Name:
        if (message.expectsResponse())
          paramsClass = Connector_Connect_Params;
      break;
      case kConnector_BindInterface_Name:
        if (message.expectsResponse())
          paramsClass = Connector_BindInterface_Params;
      break;
      case kConnector_Clone_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = Connector_Clone_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateConnectorResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kConnector_Connect_Name:
        if (message.isResponse())
          paramsClass = Connector_Connect_ResponseParams;
        break;
      case kConnector_BindInterface_Name:
        if (message.isResponse())
          paramsClass = Connector_BindInterface_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Connector = {
    name: 'service_manager::mojom::Connector',
    ptrClass: ConnectorPtr,
    proxyClass: ConnectorProxy,
    stubClass: ConnectorStub,
    validateRequest: validateConnectorRequest,
    validateResponse: validateConnectorResponse,
  };
  ConnectorStub.prototype.validator = validateConnectorRequest;
  ConnectorProxy.prototype.validator = validateConnectorResponse;

  var exports = {};
  exports.kRootUserID = kRootUserID;
  exports.kInheritUserID = kInheritUserID;
  exports.kInvalidInstanceID = kInvalidInstanceID;
  exports.ConnectResult = ConnectResult;
  exports.Identity = Identity;
  exports.PIDReceiver = PIDReceiver;
  exports.PIDReceiverPtr = PIDReceiverPtr;
  exports.Connector = Connector;
  exports.ConnectorPtr = ConnectorPtr;

  return exports;
});
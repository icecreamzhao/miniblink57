// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/service_manager/public/interfaces/service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "services/service_manager/public/interfaces/connector.mojom",
    "services/service_manager/public/interfaces/interface_provider.mojom",
    "services/service_manager/public/interfaces/interface_provider_spec.mojom",
    "services/service_manager/public/interfaces/service_control.mojom",
], function(bindings, codec, core, validator, connector$, interface_provider$, interface_provider_spec$, service_control$) {

  function ServiceInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ServiceInfo.prototype.initDefaults_ = function() {
    this.identity = null;
    this.interface_provider_specs = null;
  };
  ServiceInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ServiceInfo.validate = function(messageValidator, offset) {
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


    
    // validate ServiceInfo.identity
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, connector$.Identity, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ServiceInfo.interface_provider_specs
    err = messageValidator.validateMapPointer(offset + codec.kStructHeaderSize + 8, false, codec.String, new codec.PointerTo(interface_provider_spec$.InterfaceProviderSpec), false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ServiceInfo.encodedSize = codec.kStructHeaderSize + 16;

  ServiceInfo.decode = function(decoder) {
    var packed;
    var val = new ServiceInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.identity = decoder.decodeStructPointer(connector$.Identity);
    val.interface_provider_specs = decoder.decodeMapPointer(codec.String, new codec.PointerTo(interface_provider_spec$.InterfaceProviderSpec));
    return val;
  };

  ServiceInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ServiceInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(connector$.Identity, val.identity);
    encoder.encodeMapPointer(codec.String, new codec.PointerTo(interface_provider_spec$.InterfaceProviderSpec), val.interface_provider_specs);
  };
  function Service_OnStart_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_OnStart_Params.prototype.initDefaults_ = function() {
    this.info = null;
  };
  Service_OnStart_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_OnStart_Params.validate = function(messageValidator, offset) {
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


    
    // validate Service_OnStart_Params.info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ServiceInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Service_OnStart_Params.encodedSize = codec.kStructHeaderSize + 8;

  Service_OnStart_Params.decode = function(decoder) {
    var packed;
    var val = new Service_OnStart_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.info = decoder.decodeStructPointer(ServiceInfo);
    return val;
  };

  Service_OnStart_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_OnStart_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ServiceInfo, val.info);
  };
  function Service_OnStart_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_OnStart_ResponseParams.prototype.initDefaults_ = function() {
    this.connector_request = new bindings.InterfaceRequest();
    this.control_request = null;
  };
  Service_OnStart_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_OnStart_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Service_OnStart_ResponseParams.connector_request
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 0, true)
    if (err !== validator.validationError.NONE)
        return err;



    return validator.validationError.NONE;
  };

  Service_OnStart_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Service_OnStart_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Service_OnStart_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.connector_request = decoder.decodeStruct(codec.NullableInterfaceRequest);
    val.control_request = decoder.decodeStruct(codec.AssociatedInterfaceRequestNotSupported);
    return val;
  };

  Service_OnStart_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_OnStart_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.NullableInterfaceRequest, val.connector_request);
    encoder.encodeStruct(codec.AssociatedInterfaceRequestNotSupported, val.control_request);
  };
  function Service_OnConnect_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_OnConnect_Params.prototype.initDefaults_ = function() {
    this.source_info = null;
    this.interfaces = new bindings.InterfaceRequest();
  };
  Service_OnConnect_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_OnConnect_Params.validate = function(messageValidator, offset) {
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


    
    // validate Service_OnConnect_Params.source_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ServiceInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Service_OnConnect_Params.interfaces
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Service_OnConnect_Params.encodedSize = codec.kStructHeaderSize + 16;

  Service_OnConnect_Params.decode = function(decoder) {
    var packed;
    var val = new Service_OnConnect_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.source_info = decoder.decodeStructPointer(ServiceInfo);
    val.interfaces = decoder.decodeStruct(codec.NullableInterfaceRequest);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Service_OnConnect_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_OnConnect_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ServiceInfo, val.source_info);
    encoder.encodeStruct(codec.NullableInterfaceRequest, val.interfaces);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Service_OnConnect_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_OnConnect_ResponseParams.prototype.initDefaults_ = function() {
  };
  Service_OnConnect_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_OnConnect_ResponseParams.validate = function(messageValidator, offset) {
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

  Service_OnConnect_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  Service_OnConnect_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Service_OnConnect_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Service_OnConnect_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_OnConnect_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  function Service_OnBindInterface_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_OnBindInterface_Params.prototype.initDefaults_ = function() {
    this.source_info = null;
    this.interface_name = null;
    this.interface_pipe = null;
  };
  Service_OnBindInterface_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_OnBindInterface_Params.validate = function(messageValidator, offset) {
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


    
    // validate Service_OnBindInterface_Params.source_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, ServiceInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Service_OnBindInterface_Params.interface_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Service_OnBindInterface_Params.interface_pipe
    err = messageValidator.validateHandle(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Service_OnBindInterface_Params.encodedSize = codec.kStructHeaderSize + 24;

  Service_OnBindInterface_Params.decode = function(decoder) {
    var packed;
    var val = new Service_OnBindInterface_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.source_info = decoder.decodeStructPointer(ServiceInfo);
    val.interface_name = decoder.decodeStruct(codec.String);
    val.interface_pipe = decoder.decodeStruct(codec.Handle);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  Service_OnBindInterface_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_OnBindInterface_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(ServiceInfo, val.source_info);
    encoder.encodeStruct(codec.String, val.interface_name);
    encoder.encodeStruct(codec.Handle, val.interface_pipe);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function Service_OnBindInterface_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Service_OnBindInterface_ResponseParams.prototype.initDefaults_ = function() {
  };
  Service_OnBindInterface_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Service_OnBindInterface_ResponseParams.validate = function(messageValidator, offset) {
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

  Service_OnBindInterface_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  Service_OnBindInterface_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Service_OnBindInterface_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  Service_OnBindInterface_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Service_OnBindInterface_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  var kService_OnStart_Name = 0;
  var kService_OnConnect_Name = 1;
  var kService_OnBindInterface_Name = 2;

  function ServicePtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Service,
                                                   handleOrPtrInfo);
  }

  function ServiceProxy(receiver) {
    this.receiver_ = receiver;
  }
  ServicePtr.prototype.onStart = function() {
    return ServiceProxy.prototype.onStart
        .apply(this.ptr.getProxy(), arguments);
  };

  ServiceProxy.prototype.onStart = function(info) {
    var params = new Service_OnStart_Params();
    params.info = info;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kService_OnStart_Name,
          codec.align(Service_OnStart_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Service_OnStart_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Service_OnStart_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ServicePtr.prototype.onConnect = function() {
    return ServiceProxy.prototype.onConnect
        .apply(this.ptr.getProxy(), arguments);
  };

  ServiceProxy.prototype.onConnect = function(source_info, interfaces) {
    var params = new Service_OnConnect_Params();
    params.source_info = source_info;
    params.interfaces = interfaces;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kService_OnConnect_Name,
          codec.align(Service_OnConnect_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Service_OnConnect_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Service_OnConnect_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  ServicePtr.prototype.onBindInterface = function() {
    return ServiceProxy.prototype.onBindInterface
        .apply(this.ptr.getProxy(), arguments);
  };

  ServiceProxy.prototype.onBindInterface = function(source_info, interface_name, interface_pipe) {
    var params = new Service_OnBindInterface_Params();
    params.source_info = source_info;
    params.interface_name = interface_name;
    params.interface_pipe = interface_pipe;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kService_OnBindInterface_Name,
          codec.align(Service_OnBindInterface_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Service_OnBindInterface_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Service_OnBindInterface_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function ServiceStub(delegate) {
    this.delegate_ = delegate;
  }
  ServiceStub.prototype.onStart = function(info) {
    return this.delegate_ && this.delegate_.onStart && this.delegate_.onStart(info);
  }
  ServiceStub.prototype.onConnect = function(source_info, interfaces) {
    return this.delegate_ && this.delegate_.onConnect && this.delegate_.onConnect(source_info, interfaces);
  }
  ServiceStub.prototype.onBindInterface = function(source_info, interface_name, interface_pipe) {
    return this.delegate_ && this.delegate_.onBindInterface && this.delegate_.onBindInterface(source_info, interface_name, interface_pipe);
  }

  ServiceStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  ServiceStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kService_OnStart_Name:
      var params = reader.decodeStruct(Service_OnStart_Params);
      return this.onStart(params.info).then(function(response) {
        var responseParams =
            new Service_OnStart_ResponseParams();
        responseParams.connector_request = response.connector_request;
        responseParams.control_request = response.control_request;
        var builder = new codec.MessageWithRequestIDBuilder(
            kService_OnStart_Name,
            codec.align(Service_OnStart_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Service_OnStart_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kService_OnConnect_Name:
      var params = reader.decodeStruct(Service_OnConnect_Params);
      return this.onConnect(params.source_info, params.interfaces).then(function(response) {
        var responseParams =
            new Service_OnConnect_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kService_OnConnect_Name,
            codec.align(Service_OnConnect_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Service_OnConnect_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kService_OnBindInterface_Name:
      var params = reader.decodeStruct(Service_OnBindInterface_Params);
      return this.onBindInterface(params.source_info, params.interface_name, params.interface_pipe).then(function(response) {
        var responseParams =
            new Service_OnBindInterface_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kService_OnBindInterface_Name,
            codec.align(Service_OnBindInterface_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Service_OnBindInterface_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateServiceRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kService_OnStart_Name:
        if (message.expectsResponse())
          paramsClass = Service_OnStart_Params;
      break;
      case kService_OnConnect_Name:
        if (message.expectsResponse())
          paramsClass = Service_OnConnect_Params;
      break;
      case kService_OnBindInterface_Name:
        if (message.expectsResponse())
          paramsClass = Service_OnBindInterface_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateServiceResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kService_OnStart_Name:
        if (message.isResponse())
          paramsClass = Service_OnStart_ResponseParams;
        break;
      case kService_OnConnect_Name:
        if (message.isResponse())
          paramsClass = Service_OnConnect_ResponseParams;
        break;
      case kService_OnBindInterface_Name:
        if (message.isResponse())
          paramsClass = Service_OnBindInterface_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Service = {
    name: 'service_manager::mojom::Service',
    ptrClass: ServicePtr,
    proxyClass: ServiceProxy,
    stubClass: ServiceStub,
    validateRequest: validateServiceRequest,
    validateResponse: validateServiceResponse,
  };
  ServiceStub.prototype.validator = validateServiceRequest;
  ServiceProxy.prototype.validator = validateServiceResponse;

  var exports = {};
  exports.ServiceInfo = ServiceInfo;
  exports.Service = Service;
  exports.ServicePtr = ServicePtr;

  return exports;
});
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/catalog/public/interfaces/catalog.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "mojo/common/file_path.mojom",
], function(bindings, codec, core, validator, file_path$) {

  function Entry(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Entry.prototype.initDefaults_ = function() {
    this.name = null;
    this.display_name = null;
  };
  Entry.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Entry.validate = function(messageValidator, offset) {
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


    
    // validate Entry.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate Entry.display_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Entry.encodedSize = codec.kStructHeaderSize + 16;

  Entry.decode = function(decoder) {
    var packed;
    var val = new Entry();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.display_name = decoder.decodeStruct(codec.String);
    return val;
  };

  Entry.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Entry.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStruct(codec.String, val.display_name);
  };
  function Catalog_GetEntries_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntries_Params.prototype.initDefaults_ = function() {
    this.names = null;
  };
  Catalog_GetEntries_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntries_Params.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntries_Params.names
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, codec.String, true, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntries_Params.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntries_Params.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntries_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.names = decoder.decodeArrayPointer(codec.String);
    return val;
  };

  Catalog_GetEntries_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntries_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.String, val.names);
  };
  function Catalog_GetEntries_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntries_ResponseParams.prototype.initDefaults_ = function() {
    this.entries = null;
  };
  Catalog_GetEntries_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntries_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntries_ResponseParams.entries
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(Entry), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntries_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntries_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntries_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.entries = decoder.decodeArrayPointer(new codec.PointerTo(Entry));
    return val;
  };

  Catalog_GetEntries_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntries_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(Entry), val.entries);
  };
  function Catalog_GetEntriesProvidingCapability_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntriesProvidingCapability_Params.prototype.initDefaults_ = function() {
    this.capability = null;
  };
  Catalog_GetEntriesProvidingCapability_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntriesProvidingCapability_Params.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntriesProvidingCapability_Params.capability
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntriesProvidingCapability_Params.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntriesProvidingCapability_Params.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntriesProvidingCapability_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.capability = decoder.decodeStruct(codec.String);
    return val;
  };

  Catalog_GetEntriesProvidingCapability_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntriesProvidingCapability_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.capability);
  };
  function Catalog_GetEntriesProvidingCapability_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntriesProvidingCapability_ResponseParams.prototype.initDefaults_ = function() {
    this.entries = null;
  };
  Catalog_GetEntriesProvidingCapability_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntriesProvidingCapability_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntriesProvidingCapability_ResponseParams.entries
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(Entry), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntriesProvidingCapability_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntriesProvidingCapability_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntriesProvidingCapability_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.entries = decoder.decodeArrayPointer(new codec.PointerTo(Entry));
    return val;
  };

  Catalog_GetEntriesProvidingCapability_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntriesProvidingCapability_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(Entry), val.entries);
  };
  function Catalog_GetEntriesConsumingMIMEType_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntriesConsumingMIMEType_Params.prototype.initDefaults_ = function() {
    this.mime_type = null;
  };
  Catalog_GetEntriesConsumingMIMEType_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntriesConsumingMIMEType_Params.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntriesConsumingMIMEType_Params.mime_type
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntriesConsumingMIMEType_Params.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntriesConsumingMIMEType_Params.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntriesConsumingMIMEType_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.mime_type = decoder.decodeStruct(codec.String);
    return val;
  };

  Catalog_GetEntriesConsumingMIMEType_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntriesConsumingMIMEType_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.mime_type);
  };
  function Catalog_GetEntriesConsumingMIMEType_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntriesConsumingMIMEType_ResponseParams.prototype.initDefaults_ = function() {
    this.entries = null;
  };
  Catalog_GetEntriesConsumingMIMEType_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntriesConsumingMIMEType_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntriesConsumingMIMEType_ResponseParams.entries
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(Entry), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntriesConsumingMIMEType_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntriesConsumingMIMEType_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntriesConsumingMIMEType_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.entries = decoder.decodeArrayPointer(new codec.PointerTo(Entry));
    return val;
  };

  Catalog_GetEntriesConsumingMIMEType_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntriesConsumingMIMEType_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(Entry), val.entries);
  };
  function Catalog_GetEntriesSupportingScheme_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntriesSupportingScheme_Params.prototype.initDefaults_ = function() {
    this.protocol_scheme = null;
  };
  Catalog_GetEntriesSupportingScheme_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntriesSupportingScheme_Params.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntriesSupportingScheme_Params.protocol_scheme
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntriesSupportingScheme_Params.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntriesSupportingScheme_Params.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntriesSupportingScheme_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.protocol_scheme = decoder.decodeStruct(codec.String);
    return val;
  };

  Catalog_GetEntriesSupportingScheme_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntriesSupportingScheme_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.protocol_scheme);
  };
  function Catalog_GetEntriesSupportingScheme_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  Catalog_GetEntriesSupportingScheme_ResponseParams.prototype.initDefaults_ = function() {
    this.entries = null;
  };
  Catalog_GetEntriesSupportingScheme_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  Catalog_GetEntriesSupportingScheme_ResponseParams.validate = function(messageValidator, offset) {
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


    
    // validate Catalog_GetEntriesSupportingScheme_ResponseParams.entries
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(Entry), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  Catalog_GetEntriesSupportingScheme_ResponseParams.encodedSize = codec.kStructHeaderSize + 8;

  Catalog_GetEntriesSupportingScheme_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new Catalog_GetEntriesSupportingScheme_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.entries = decoder.decodeArrayPointer(new codec.PointerTo(Entry));
    return val;
  };

  Catalog_GetEntriesSupportingScheme_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(Catalog_GetEntriesSupportingScheme_ResponseParams.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(Entry), val.entries);
  };
  function CatalogControl_OverrideManifestPath_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CatalogControl_OverrideManifestPath_Params.prototype.initDefaults_ = function() {
    this.name = null;
    this.path = null;
  };
  CatalogControl_OverrideManifestPath_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CatalogControl_OverrideManifestPath_Params.validate = function(messageValidator, offset) {
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


    
    // validate CatalogControl_OverrideManifestPath_Params.name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate CatalogControl_OverrideManifestPath_Params.path
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, file_path$.FilePath, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  CatalogControl_OverrideManifestPath_Params.encodedSize = codec.kStructHeaderSize + 16;

  CatalogControl_OverrideManifestPath_Params.decode = function(decoder) {
    var packed;
    var val = new CatalogControl_OverrideManifestPath_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.name = decoder.decodeStruct(codec.String);
    val.path = decoder.decodeStructPointer(file_path$.FilePath);
    return val;
  };

  CatalogControl_OverrideManifestPath_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CatalogControl_OverrideManifestPath_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.name);
    encoder.encodeStructPointer(file_path$.FilePath, val.path);
  };
  function CatalogControl_OverrideManifestPath_ResponseParams(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  CatalogControl_OverrideManifestPath_ResponseParams.prototype.initDefaults_ = function() {
  };
  CatalogControl_OverrideManifestPath_ResponseParams.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  CatalogControl_OverrideManifestPath_ResponseParams.validate = function(messageValidator, offset) {
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

  CatalogControl_OverrideManifestPath_ResponseParams.encodedSize = codec.kStructHeaderSize + 0;

  CatalogControl_OverrideManifestPath_ResponseParams.decode = function(decoder) {
    var packed;
    var val = new CatalogControl_OverrideManifestPath_ResponseParams();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  CatalogControl_OverrideManifestPath_ResponseParams.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(CatalogControl_OverrideManifestPath_ResponseParams.encodedSize);
    encoder.writeUint32(0);
  };
  var kCatalog_GetEntries_Name = 0;
  var kCatalog_GetEntriesProvidingCapability_Name = 1;
  var kCatalog_GetEntriesConsumingMIMEType_Name = 2;
  var kCatalog_GetEntriesSupportingScheme_Name = 3;

  function CatalogPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(Catalog,
                                                   handleOrPtrInfo);
  }

  function CatalogProxy(receiver) {
    this.receiver_ = receiver;
  }
  CatalogPtr.prototype.getEntries = function() {
    return CatalogProxy.prototype.getEntries
        .apply(this.ptr.getProxy(), arguments);
  };

  CatalogProxy.prototype.getEntries = function(names) {
    var params = new Catalog_GetEntries_Params();
    params.names = names;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kCatalog_GetEntries_Name,
          codec.align(Catalog_GetEntries_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Catalog_GetEntries_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Catalog_GetEntries_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  CatalogPtr.prototype.getEntriesProvidingCapability = function() {
    return CatalogProxy.prototype.getEntriesProvidingCapability
        .apply(this.ptr.getProxy(), arguments);
  };

  CatalogProxy.prototype.getEntriesProvidingCapability = function(capability) {
    var params = new Catalog_GetEntriesProvidingCapability_Params();
    params.capability = capability;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kCatalog_GetEntriesProvidingCapability_Name,
          codec.align(Catalog_GetEntriesProvidingCapability_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Catalog_GetEntriesProvidingCapability_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Catalog_GetEntriesProvidingCapability_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  CatalogPtr.prototype.getEntriesConsumingMIMEType = function() {
    return CatalogProxy.prototype.getEntriesConsumingMIMEType
        .apply(this.ptr.getProxy(), arguments);
  };

  CatalogProxy.prototype.getEntriesConsumingMIMEType = function(mime_type) {
    var params = new Catalog_GetEntriesConsumingMIMEType_Params();
    params.mime_type = mime_type;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kCatalog_GetEntriesConsumingMIMEType_Name,
          codec.align(Catalog_GetEntriesConsumingMIMEType_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Catalog_GetEntriesConsumingMIMEType_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Catalog_GetEntriesConsumingMIMEType_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };
  CatalogPtr.prototype.getEntriesSupportingScheme = function() {
    return CatalogProxy.prototype.getEntriesSupportingScheme
        .apply(this.ptr.getProxy(), arguments);
  };

  CatalogProxy.prototype.getEntriesSupportingScheme = function(protocol_scheme) {
    var params = new Catalog_GetEntriesSupportingScheme_Params();
    params.protocol_scheme = protocol_scheme;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kCatalog_GetEntriesSupportingScheme_Name,
          codec.align(Catalog_GetEntriesSupportingScheme_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(Catalog_GetEntriesSupportingScheme_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(Catalog_GetEntriesSupportingScheme_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function CatalogStub(delegate) {
    this.delegate_ = delegate;
  }
  CatalogStub.prototype.getEntries = function(names) {
    return this.delegate_ && this.delegate_.getEntries && this.delegate_.getEntries(names);
  }
  CatalogStub.prototype.getEntriesProvidingCapability = function(capability) {
    return this.delegate_ && this.delegate_.getEntriesProvidingCapability && this.delegate_.getEntriesProvidingCapability(capability);
  }
  CatalogStub.prototype.getEntriesConsumingMIMEType = function(mime_type) {
    return this.delegate_ && this.delegate_.getEntriesConsumingMIMEType && this.delegate_.getEntriesConsumingMIMEType(mime_type);
  }
  CatalogStub.prototype.getEntriesSupportingScheme = function(protocol_scheme) {
    return this.delegate_ && this.delegate_.getEntriesSupportingScheme && this.delegate_.getEntriesSupportingScheme(protocol_scheme);
  }

  CatalogStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  CatalogStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kCatalog_GetEntries_Name:
      var params = reader.decodeStruct(Catalog_GetEntries_Params);
      return this.getEntries(params.names).then(function(response) {
        var responseParams =
            new Catalog_GetEntries_ResponseParams();
        responseParams.entries = response.entries;
        var builder = new codec.MessageWithRequestIDBuilder(
            kCatalog_GetEntries_Name,
            codec.align(Catalog_GetEntries_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Catalog_GetEntries_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kCatalog_GetEntriesProvidingCapability_Name:
      var params = reader.decodeStruct(Catalog_GetEntriesProvidingCapability_Params);
      return this.getEntriesProvidingCapability(params.capability).then(function(response) {
        var responseParams =
            new Catalog_GetEntriesProvidingCapability_ResponseParams();
        responseParams.entries = response.entries;
        var builder = new codec.MessageWithRequestIDBuilder(
            kCatalog_GetEntriesProvidingCapability_Name,
            codec.align(Catalog_GetEntriesProvidingCapability_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Catalog_GetEntriesProvidingCapability_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kCatalog_GetEntriesConsumingMIMEType_Name:
      var params = reader.decodeStruct(Catalog_GetEntriesConsumingMIMEType_Params);
      return this.getEntriesConsumingMIMEType(params.mime_type).then(function(response) {
        var responseParams =
            new Catalog_GetEntriesConsumingMIMEType_ResponseParams();
        responseParams.entries = response.entries;
        var builder = new codec.MessageWithRequestIDBuilder(
            kCatalog_GetEntriesConsumingMIMEType_Name,
            codec.align(Catalog_GetEntriesConsumingMIMEType_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Catalog_GetEntriesConsumingMIMEType_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    case kCatalog_GetEntriesSupportingScheme_Name:
      var params = reader.decodeStruct(Catalog_GetEntriesSupportingScheme_Params);
      return this.getEntriesSupportingScheme(params.protocol_scheme).then(function(response) {
        var responseParams =
            new Catalog_GetEntriesSupportingScheme_ResponseParams();
        responseParams.entries = response.entries;
        var builder = new codec.MessageWithRequestIDBuilder(
            kCatalog_GetEntriesSupportingScheme_Name,
            codec.align(Catalog_GetEntriesSupportingScheme_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(Catalog_GetEntriesSupportingScheme_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateCatalogRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kCatalog_GetEntries_Name:
        if (message.expectsResponse())
          paramsClass = Catalog_GetEntries_Params;
      break;
      case kCatalog_GetEntriesProvidingCapability_Name:
        if (message.expectsResponse())
          paramsClass = Catalog_GetEntriesProvidingCapability_Params;
      break;
      case kCatalog_GetEntriesConsumingMIMEType_Name:
        if (message.expectsResponse())
          paramsClass = Catalog_GetEntriesConsumingMIMEType_Params;
      break;
      case kCatalog_GetEntriesSupportingScheme_Name:
        if (message.expectsResponse())
          paramsClass = Catalog_GetEntriesSupportingScheme_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateCatalogResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kCatalog_GetEntries_Name:
        if (message.isResponse())
          paramsClass = Catalog_GetEntries_ResponseParams;
        break;
      case kCatalog_GetEntriesProvidingCapability_Name:
        if (message.isResponse())
          paramsClass = Catalog_GetEntriesProvidingCapability_ResponseParams;
        break;
      case kCatalog_GetEntriesConsumingMIMEType_Name:
        if (message.isResponse())
          paramsClass = Catalog_GetEntriesConsumingMIMEType_ResponseParams;
        break;
      case kCatalog_GetEntriesSupportingScheme_Name:
        if (message.isResponse())
          paramsClass = Catalog_GetEntriesSupportingScheme_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var Catalog = {
    name: 'catalog::mojom::Catalog',
    ptrClass: CatalogPtr,
    proxyClass: CatalogProxy,
    stubClass: CatalogStub,
    validateRequest: validateCatalogRequest,
    validateResponse: validateCatalogResponse,
  };
  CatalogStub.prototype.validator = validateCatalogRequest;
  CatalogProxy.prototype.validator = validateCatalogResponse;
  var kCatalogControl_OverrideManifestPath_Name = 0;

  function CatalogControlPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(CatalogControl,
                                                   handleOrPtrInfo);
  }

  function CatalogControlProxy(receiver) {
    this.receiver_ = receiver;
  }
  CatalogControlPtr.prototype.overrideManifestPath = function() {
    return CatalogControlProxy.prototype.overrideManifestPath
        .apply(this.ptr.getProxy(), arguments);
  };

  CatalogControlProxy.prototype.overrideManifestPath = function(name, path) {
    var params = new CatalogControl_OverrideManifestPath_Params();
    params.name = name;
    params.path = path;
    return new Promise(function(resolve, reject) {
      var builder = new codec.MessageWithRequestIDBuilder(
          kCatalogControl_OverrideManifestPath_Name,
          codec.align(CatalogControl_OverrideManifestPath_Params.encodedSize),
          codec.kMessageExpectsResponse, 0);
      builder.encodeStruct(CatalogControl_OverrideManifestPath_Params, params);
      var message = builder.finish();
      this.receiver_.acceptAndExpectResponse(message).then(function(message) {
        var reader = new codec.MessageReader(message);
        var responseParams =
            reader.decodeStruct(CatalogControl_OverrideManifestPath_ResponseParams);
        resolve(responseParams);
      }).catch(function(result) {
        reject(Error("Connection error: " + result));
      });
    }.bind(this));
  };

  function CatalogControlStub(delegate) {
    this.delegate_ = delegate;
  }
  CatalogControlStub.prototype.overrideManifestPath = function(name, path) {
    return this.delegate_ && this.delegate_.overrideManifestPath && this.delegate_.overrideManifestPath(name, path);
  }

  CatalogControlStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return false;
    }
  };

  CatalogControlStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kCatalogControl_OverrideManifestPath_Name:
      var params = reader.decodeStruct(CatalogControl_OverrideManifestPath_Params);
      return this.overrideManifestPath(params.name, params.path).then(function(response) {
        var responseParams =
            new CatalogControl_OverrideManifestPath_ResponseParams();
        var builder = new codec.MessageWithRequestIDBuilder(
            kCatalogControl_OverrideManifestPath_Name,
            codec.align(CatalogControl_OverrideManifestPath_ResponseParams.encodedSize),
            codec.kMessageIsResponse, reader.requestID);
        builder.encodeStruct(CatalogControl_OverrideManifestPath_ResponseParams,
                             responseParams);
        var message = builder.finish();
        responder.accept(message);
      });
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateCatalogControlRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kCatalogControl_OverrideManifestPath_Name:
        if (message.expectsResponse())
          paramsClass = CatalogControl_OverrideManifestPath_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateCatalogControlResponse(messageValidator) {
   var message = messageValidator.message;
   var paramsClass = null;
   switch (message.getName()) {
      case kCatalogControl_OverrideManifestPath_Name:
        if (message.isResponse())
          paramsClass = CatalogControl_OverrideManifestPath_ResponseParams;
        break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  var CatalogControl = {
    name: 'catalog::mojom::CatalogControl',
    ptrClass: CatalogControlPtr,
    proxyClass: CatalogControlProxy,
    stubClass: CatalogControlStub,
    validateRequest: validateCatalogControlRequest,
    validateResponse: validateCatalogControlResponse,
  };
  CatalogControlStub.prototype.validator = validateCatalogControlRequest;
  CatalogControlProxy.prototype.validator = validateCatalogControlResponse;

  var exports = {};
  exports.Entry = Entry;
  exports.Catalog = Catalog;
  exports.CatalogPtr = CatalogPtr;
  exports.CatalogControl = CatalogControl;
  exports.CatalogControlPtr = CatalogControlPtr;

  return exports;
});
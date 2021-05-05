// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("services/ui/public/interfaces/user_access_manager.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {

  function UserAccessManager_SetActiveUser_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  UserAccessManager_SetActiveUser_Params.prototype.initDefaults_ = function() {
    this.user_id = null;
  };
  UserAccessManager_SetActiveUser_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  UserAccessManager_SetActiveUser_Params.validate = function(messageValidator, offset) {
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


    
    // validate UserAccessManager_SetActiveUser_Params.user_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  UserAccessManager_SetActiveUser_Params.encodedSize = codec.kStructHeaderSize + 8;

  UserAccessManager_SetActiveUser_Params.decode = function(decoder) {
    var packed;
    var val = new UserAccessManager_SetActiveUser_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.user_id = decoder.decodeStruct(codec.String);
    return val;
  };

  UserAccessManager_SetActiveUser_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(UserAccessManager_SetActiveUser_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.user_id);
  };
  var kUserAccessManager_SetActiveUser_Name = 0;

  function UserAccessManagerPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(UserAccessManager,
                                                   handleOrPtrInfo);
  }

  function UserAccessManagerProxy(receiver) {
    this.receiver_ = receiver;
  }
  UserAccessManagerPtr.prototype.setActiveUser = function() {
    return UserAccessManagerProxy.prototype.setActiveUser
        .apply(this.ptr.getProxy(), arguments);
  };

  UserAccessManagerProxy.prototype.setActiveUser = function(user_id) {
    var params = new UserAccessManager_SetActiveUser_Params();
    params.user_id = user_id;
    var builder = new codec.MessageBuilder(
        kUserAccessManager_SetActiveUser_Name,
        codec.align(UserAccessManager_SetActiveUser_Params.encodedSize));
    builder.encodeStruct(UserAccessManager_SetActiveUser_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function UserAccessManagerStub(delegate) {
    this.delegate_ = delegate;
  }
  UserAccessManagerStub.prototype.setActiveUser = function(user_id) {
    return this.delegate_ && this.delegate_.setActiveUser && this.delegate_.setActiveUser(user_id);
  }

  UserAccessManagerStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kUserAccessManager_SetActiveUser_Name:
      var params = reader.decodeStruct(UserAccessManager_SetActiveUser_Params);
      this.setActiveUser(params.user_id);
      return true;
    default:
      return false;
    }
  };

  UserAccessManagerStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateUserAccessManagerRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kUserAccessManager_SetActiveUser_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = UserAccessManager_SetActiveUser_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateUserAccessManagerResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var UserAccessManager = {
    name: 'ui::mojom::UserAccessManager',
    ptrClass: UserAccessManagerPtr,
    proxyClass: UserAccessManagerProxy,
    stubClass: UserAccessManagerStub,
    validateRequest: validateUserAccessManagerRequest,
    validateResponse: null,
  };
  UserAccessManagerStub.prototype.validator = validateUserAccessManagerRequest;
  UserAccessManagerProxy.prototype.validator = null;

  var exports = {};
  exports.UserAccessManager = UserAccessManager;
  exports.UserAccessManagerPtr = UserAccessManagerPtr;

  return exports;
});
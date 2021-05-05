// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("components/payments/payment_request.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
], function(bindings, codec, core, validator) {
  var PaymentErrorReason = {};
  PaymentErrorReason.UNKNOWN = 0;
  PaymentErrorReason.USER_CANCEL = PaymentErrorReason.UNKNOWN + 1;
  PaymentErrorReason.NOT_SUPPORTED = PaymentErrorReason.USER_CANCEL + 1;

  PaymentErrorReason.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  PaymentErrorReason.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var CanMakePaymentQueryResult = {};
  CanMakePaymentQueryResult.CAN_MAKE_PAYMENT = 0;
  CanMakePaymentQueryResult.CANNOT_MAKE_PAYMENT = CanMakePaymentQueryResult.CAN_MAKE_PAYMENT + 1;
  CanMakePaymentQueryResult.QUERY_QUOTA_EXCEEDED = CanMakePaymentQueryResult.CANNOT_MAKE_PAYMENT + 1;

  CanMakePaymentQueryResult.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  CanMakePaymentQueryResult.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var AndroidPayEnvironment = {};
  AndroidPayEnvironment.PRODUCTION = 0;
  AndroidPayEnvironment.TEST = AndroidPayEnvironment.PRODUCTION + 1;

  AndroidPayEnvironment.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
      return true;
    }
    return false;
  };

  AndroidPayEnvironment.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var AndroidPayCardNetwork = {};
  AndroidPayCardNetwork.AMEX = 0;
  AndroidPayCardNetwork.DISCOVER = AndroidPayCardNetwork.AMEX + 1;
  AndroidPayCardNetwork.MASTERCARD = AndroidPayCardNetwork.DISCOVER + 1;
  AndroidPayCardNetwork.VISA = AndroidPayCardNetwork.MASTERCARD + 1;

  AndroidPayCardNetwork.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    }
    return false;
  };

  AndroidPayCardNetwork.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var AndroidPayTokenization = {};
  AndroidPayTokenization.UNSPECIFIED = 0;
  AndroidPayTokenization.GATEWAY_TOKEN = AndroidPayTokenization.UNSPECIFIED + 1;
  AndroidPayTokenization.NETWORK_TOKEN = AndroidPayTokenization.GATEWAY_TOKEN + 1;

  AndroidPayTokenization.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  AndroidPayTokenization.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var BasicCardNetwork = {};
  BasicCardNetwork.AMEX = 0;
  BasicCardNetwork.DINERS = BasicCardNetwork.AMEX + 1;
  BasicCardNetwork.DISCOVER = BasicCardNetwork.DINERS + 1;
  BasicCardNetwork.JCB = BasicCardNetwork.DISCOVER + 1;
  BasicCardNetwork.MASTERCARD = BasicCardNetwork.JCB + 1;
  BasicCardNetwork.MIR = BasicCardNetwork.MASTERCARD + 1;
  BasicCardNetwork.UNIONPAY = BasicCardNetwork.MIR + 1;
  BasicCardNetwork.VISA = BasicCardNetwork.UNIONPAY + 1;

  BasicCardNetwork.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    }
    return false;
  };

  BasicCardNetwork.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var BasicCardType = {};
  BasicCardType.CREDIT = 0;
  BasicCardType.DEBIT = BasicCardType.CREDIT + 1;
  BasicCardType.PREPAID = BasicCardType.DEBIT + 1;

  BasicCardType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  BasicCardType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PaymentShippingType = {};
  PaymentShippingType.SHIPPING = 0;
  PaymentShippingType.DELIVERY = PaymentShippingType.SHIPPING + 1;
  PaymentShippingType.PICKUP = PaymentShippingType.DELIVERY + 1;

  PaymentShippingType.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  PaymentShippingType.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };
  var PaymentComplete = {};
  PaymentComplete.SUCCESS = 0;
  PaymentComplete.FAIL = PaymentComplete.SUCCESS + 1;
  PaymentComplete.UNKNOWN = PaymentComplete.FAIL + 1;

  PaymentComplete.isKnownEnumValue = function(value) {
    switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    }
    return false;
  };

  PaymentComplete.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function PaymentAddress(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentAddress.prototype.initDefaults_ = function() {
    this.country = null;
    this.address_line = null;
    this.region = null;
    this.city = null;
    this.dependent_locality = null;
    this.postal_code = null;
    this.sorting_code = null;
    this.language_code = null;
    this.script_code = null;
    this.organization = null;
    this.recipient = null;
    this.phone = null;
  };
  PaymentAddress.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentAddress.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 104}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.country
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.address_line
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.region
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.city
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.dependent_locality
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.postal_code
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.sorting_code
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 48, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.language_code
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 56, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.script_code
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 64, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.organization
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 72, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.recipient
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 80, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentAddress.phone
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 88, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentAddress.encodedSize = codec.kStructHeaderSize + 96;

  PaymentAddress.decode = function(decoder) {
    var packed;
    var val = new PaymentAddress();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.country = decoder.decodeStruct(codec.String);
    val.address_line = decoder.decodeArrayPointer(codec.String);
    val.region = decoder.decodeStruct(codec.String);
    val.city = decoder.decodeStruct(codec.String);
    val.dependent_locality = decoder.decodeStruct(codec.String);
    val.postal_code = decoder.decodeStruct(codec.String);
    val.sorting_code = decoder.decodeStruct(codec.String);
    val.language_code = decoder.decodeStruct(codec.String);
    val.script_code = decoder.decodeStruct(codec.String);
    val.organization = decoder.decodeStruct(codec.String);
    val.recipient = decoder.decodeStruct(codec.String);
    val.phone = decoder.decodeStruct(codec.String);
    return val;
  };

  PaymentAddress.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentAddress.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.country);
    encoder.encodeArrayPointer(codec.String, val.address_line);
    encoder.encodeStruct(codec.String, val.region);
    encoder.encodeStruct(codec.String, val.city);
    encoder.encodeStruct(codec.String, val.dependent_locality);
    encoder.encodeStruct(codec.String, val.postal_code);
    encoder.encodeStruct(codec.String, val.sorting_code);
    encoder.encodeStruct(codec.String, val.language_code);
    encoder.encodeStruct(codec.String, val.script_code);
    encoder.encodeStruct(codec.String, val.organization);
    encoder.encodeStruct(codec.String, val.recipient);
    encoder.encodeStruct(codec.String, val.phone);
  };
  function PaymentCurrencyAmount(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentCurrencyAmount.prototype.initDefaults_ = function() {
    this.currency = null;
    this.value = null;
    this.currency_system = null;
  };
  PaymentCurrencyAmount.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentCurrencyAmount.validate = function(messageValidator, offset) {
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


    
    // validate PaymentCurrencyAmount.currency
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentCurrencyAmount.value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentCurrencyAmount.currency_system
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 16, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentCurrencyAmount.encodedSize = codec.kStructHeaderSize + 24;

  PaymentCurrencyAmount.decode = function(decoder) {
    var packed;
    var val = new PaymentCurrencyAmount();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.currency = decoder.decodeStruct(codec.String);
    val.value = decoder.decodeStruct(codec.String);
    val.currency_system = decoder.decodeStruct(codec.NullableString);
    return val;
  };

  PaymentCurrencyAmount.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentCurrencyAmount.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.currency);
    encoder.encodeStruct(codec.String, val.value);
    encoder.encodeStruct(codec.NullableString, val.currency_system);
  };
  function PaymentResponse(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentResponse.prototype.initDefaults_ = function() {
    this.method_name = null;
    this.stringified_details = null;
    this.shipping_address = null;
    this.shipping_option = null;
    this.payer_name = null;
    this.payer_email = null;
    this.payer_phone = null;
  };
  PaymentResponse.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentResponse.validate = function(messageValidator, offset) {
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


    
    // validate PaymentResponse.method_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentResponse.stringified_details
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentResponse.shipping_address
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, PaymentAddress, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentResponse.shipping_option
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentResponse.payer_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentResponse.payer_email
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 40, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentResponse.payer_phone
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 48, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentResponse.encodedSize = codec.kStructHeaderSize + 56;

  PaymentResponse.decode = function(decoder) {
    var packed;
    var val = new PaymentResponse();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.method_name = decoder.decodeStruct(codec.String);
    val.stringified_details = decoder.decodeStruct(codec.String);
    val.shipping_address = decoder.decodeStructPointer(PaymentAddress);
    val.shipping_option = decoder.decodeStruct(codec.NullableString);
    val.payer_name = decoder.decodeStruct(codec.NullableString);
    val.payer_email = decoder.decodeStruct(codec.NullableString);
    val.payer_phone = decoder.decodeStruct(codec.NullableString);
    return val;
  };

  PaymentResponse.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentResponse.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.method_name);
    encoder.encodeStruct(codec.String, val.stringified_details);
    encoder.encodeStructPointer(PaymentAddress, val.shipping_address);
    encoder.encodeStruct(codec.NullableString, val.shipping_option);
    encoder.encodeStruct(codec.NullableString, val.payer_name);
    encoder.encodeStruct(codec.NullableString, val.payer_email);
    encoder.encodeStruct(codec.NullableString, val.payer_phone);
  };
  function PaymentItem(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentItem.prototype.initDefaults_ = function() {
    this.label = null;
    this.amount = null;
    this.pending = false;
  };
  PaymentItem.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentItem.validate = function(messageValidator, offset) {
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


    
    // validate PaymentItem.label
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentItem.amount
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, PaymentCurrencyAmount, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  PaymentItem.encodedSize = codec.kStructHeaderSize + 24;

  PaymentItem.decode = function(decoder) {
    var packed;
    var val = new PaymentItem();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.label = decoder.decodeStruct(codec.String);
    val.amount = decoder.decodeStructPointer(PaymentCurrencyAmount);
    packed = decoder.readUint8();
    val.pending = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentItem.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentItem.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.label);
    encoder.encodeStructPointer(PaymentCurrencyAmount, val.amount);
    packed = 0;
    packed |= (val.pending & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PaymentShippingOption(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentShippingOption.prototype.initDefaults_ = function() {
    this.id = null;
    this.label = null;
    this.amount = null;
    this.selected = false;
  };
  PaymentShippingOption.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentShippingOption.validate = function(messageValidator, offset) {
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


    
    // validate PaymentShippingOption.id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentShippingOption.label
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentShippingOption.amount
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, PaymentCurrencyAmount, false);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  PaymentShippingOption.encodedSize = codec.kStructHeaderSize + 32;

  PaymentShippingOption.decode = function(decoder) {
    var packed;
    var val = new PaymentShippingOption();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.id = decoder.decodeStruct(codec.String);
    val.label = decoder.decodeStruct(codec.String);
    val.amount = decoder.decodeStructPointer(PaymentCurrencyAmount);
    packed = decoder.readUint8();
    val.selected = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentShippingOption.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentShippingOption.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.id);
    encoder.encodeStruct(codec.String, val.label);
    encoder.encodeStructPointer(PaymentCurrencyAmount, val.amount);
    packed = 0;
    packed |= (val.selected & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function AndroidPayTokenizationParameter(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  AndroidPayTokenizationParameter.prototype.initDefaults_ = function() {
    this.key = null;
    this.value = null;
  };
  AndroidPayTokenizationParameter.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  AndroidPayTokenizationParameter.validate = function(messageValidator, offset) {
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


    
    // validate AndroidPayTokenizationParameter.key
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate AndroidPayTokenizationParameter.value
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, true)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  AndroidPayTokenizationParameter.encodedSize = codec.kStructHeaderSize + 16;

  AndroidPayTokenizationParameter.decode = function(decoder) {
    var packed;
    var val = new AndroidPayTokenizationParameter();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.key = decoder.decodeStruct(codec.NullableString);
    val.value = decoder.decodeStruct(codec.NullableString);
    return val;
  };

  AndroidPayTokenizationParameter.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(AndroidPayTokenizationParameter.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.NullableString, val.key);
    encoder.encodeStruct(codec.NullableString, val.value);
  };
  function PaymentMethodData(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentMethodData.prototype.initDefaults_ = function() {
    this.supported_methods = null;
    this.stringified_data = null;
    this.environment = 0;
    this.tokenization_type = 0;
    this.merchant_name = null;
    this.merchant_id = null;
    this.allowed_card_networks = null;
    this.parameters = null;
    this.min_google_play_services_version = 0;
    this.supported_networks = null;
    this.supported_types = null;
  };
  PaymentMethodData.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentMethodData.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 88}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.supported_methods
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, codec.String, false, [0, 0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.stringified_data
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.environment
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 16, AndroidPayEnvironment);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.merchant_name
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 24, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.merchant_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, true)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.allowed_card_networks
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 40, 4, new codec.Enum(AndroidPayCardNetwork), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.tokenization_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 20, AndroidPayTokenization);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.parameters
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 48, 8, new codec.PointerTo(AndroidPayTokenizationParameter), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate PaymentMethodData.supported_networks
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 64, 4, new codec.Enum(BasicCardNetwork), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentMethodData.supported_types
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 72, 4, new codec.Enum(BasicCardType), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentMethodData.encodedSize = codec.kStructHeaderSize + 80;

  PaymentMethodData.decode = function(decoder) {
    var packed;
    var val = new PaymentMethodData();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.supported_methods = decoder.decodeArrayPointer(codec.String);
    val.stringified_data = decoder.decodeStruct(codec.String);
    val.environment = decoder.decodeStruct(codec.Int32);
    val.tokenization_type = decoder.decodeStruct(codec.Int32);
    val.merchant_name = decoder.decodeStruct(codec.NullableString);
    val.merchant_id = decoder.decodeStruct(codec.NullableString);
    val.allowed_card_networks = decoder.decodeArrayPointer(new codec.Enum(AndroidPayCardNetwork));
    val.parameters = decoder.decodeArrayPointer(new codec.PointerTo(AndroidPayTokenizationParameter));
    val.min_google_play_services_version = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.supported_networks = decoder.decodeArrayPointer(new codec.Enum(BasicCardNetwork));
    val.supported_types = decoder.decodeArrayPointer(new codec.Enum(BasicCardType));
    return val;
  };

  PaymentMethodData.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentMethodData.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(codec.String, val.supported_methods);
    encoder.encodeStruct(codec.String, val.stringified_data);
    encoder.encodeStruct(codec.Int32, val.environment);
    encoder.encodeStruct(codec.Int32, val.tokenization_type);
    encoder.encodeStruct(codec.NullableString, val.merchant_name);
    encoder.encodeStruct(codec.NullableString, val.merchant_id);
    encoder.encodeArrayPointer(new codec.Enum(AndroidPayCardNetwork), val.allowed_card_networks);
    encoder.encodeArrayPointer(new codec.PointerTo(AndroidPayTokenizationParameter), val.parameters);
    encoder.encodeStruct(codec.Int32, val.min_google_play_services_version);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeArrayPointer(new codec.Enum(BasicCardNetwork), val.supported_networks);
    encoder.encodeArrayPointer(new codec.Enum(BasicCardType), val.supported_types);
  };
  function PaymentDetailsModifier(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentDetailsModifier.prototype.initDefaults_ = function() {
    this.total = null;
    this.additional_display_items = null;
    this.method_data = null;
  };
  PaymentDetailsModifier.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentDetailsModifier.validate = function(messageValidator, offset) {
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


    
    // validate PaymentDetailsModifier.total
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PaymentItem, true);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentDetailsModifier.additional_display_items
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(PaymentItem), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentDetailsModifier.method_data
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, PaymentMethodData, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentDetailsModifier.encodedSize = codec.kStructHeaderSize + 24;

  PaymentDetailsModifier.decode = function(decoder) {
    var packed;
    var val = new PaymentDetailsModifier();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.total = decoder.decodeStructPointer(PaymentItem);
    val.additional_display_items = decoder.decodeArrayPointer(new codec.PointerTo(PaymentItem));
    val.method_data = decoder.decodeStructPointer(PaymentMethodData);
    return val;
  };

  PaymentDetailsModifier.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentDetailsModifier.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PaymentItem, val.total);
    encoder.encodeArrayPointer(new codec.PointerTo(PaymentItem), val.additional_display_items);
    encoder.encodeStructPointer(PaymentMethodData, val.method_data);
  };
  function PaymentDetails(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentDetails.prototype.initDefaults_ = function() {
    this.total = null;
    this.display_items = null;
    this.shipping_options = null;
    this.modifiers = null;
    this.error = null;
  };
  PaymentDetails.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentDetails.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 48}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentDetails.total
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PaymentItem, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentDetails.display_items
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(PaymentItem), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentDetails.shipping_options
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 16, 8, new codec.PointerTo(PaymentShippingOption), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentDetails.modifiers
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 24, 8, new codec.PointerTo(PaymentDetailsModifier), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentDetails.error
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 32, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentDetails.encodedSize = codec.kStructHeaderSize + 40;

  PaymentDetails.decode = function(decoder) {
    var packed;
    var val = new PaymentDetails();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.total = decoder.decodeStructPointer(PaymentItem);
    val.display_items = decoder.decodeArrayPointer(new codec.PointerTo(PaymentItem));
    val.shipping_options = decoder.decodeArrayPointer(new codec.PointerTo(PaymentShippingOption));
    val.modifiers = decoder.decodeArrayPointer(new codec.PointerTo(PaymentDetailsModifier));
    val.error = decoder.decodeStruct(codec.String);
    return val;
  };

  PaymentDetails.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentDetails.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PaymentItem, val.total);
    encoder.encodeArrayPointer(new codec.PointerTo(PaymentItem), val.display_items);
    encoder.encodeArrayPointer(new codec.PointerTo(PaymentShippingOption), val.shipping_options);
    encoder.encodeArrayPointer(new codec.PointerTo(PaymentDetailsModifier), val.modifiers);
    encoder.encodeStruct(codec.String, val.error);
  };
  function PaymentOptions(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentOptions.prototype.initDefaults_ = function() {
    this.request_payer_name = false;
    this.request_payer_email = false;
    this.request_payer_phone = false;
    this.request_shipping = false;
    this.shipping_type = 0;
  };
  PaymentOptions.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentOptions.validate = function(messageValidator, offset) {
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






    
    // validate PaymentOptions.shipping_type
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 4, PaymentShippingType);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentOptions.encodedSize = codec.kStructHeaderSize + 8;

  PaymentOptions.decode = function(decoder) {
    var packed;
    var val = new PaymentOptions();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.request_payer_name = (packed >> 0) & 1 ? true : false;
    val.request_payer_email = (packed >> 1) & 1 ? true : false;
    val.request_payer_phone = (packed >> 2) & 1 ? true : false;
    val.request_shipping = (packed >> 3) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.shipping_type = decoder.decodeStruct(codec.Int32);
    return val;
  };

  PaymentOptions.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentOptions.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.request_payer_name & 1) << 0
    packed |= (val.request_payer_email & 1) << 1
    packed |= (val.request_payer_phone & 1) << 2
    packed |= (val.request_shipping & 1) << 3
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.Int32, val.shipping_type);
  };
  function PaymentRequestClient_OnShippingAddressChange_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequestClient_OnShippingAddressChange_Params.prototype.initDefaults_ = function() {
    this.address = null;
  };
  PaymentRequestClient_OnShippingAddressChange_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequestClient_OnShippingAddressChange_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequestClient_OnShippingAddressChange_Params.address
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PaymentAddress, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequestClient_OnShippingAddressChange_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequestClient_OnShippingAddressChange_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequestClient_OnShippingAddressChange_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.address = decoder.decodeStructPointer(PaymentAddress);
    return val;
  };

  PaymentRequestClient_OnShippingAddressChange_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequestClient_OnShippingAddressChange_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PaymentAddress, val.address);
  };
  function PaymentRequestClient_OnShippingOptionChange_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequestClient_OnShippingOptionChange_Params.prototype.initDefaults_ = function() {
    this.shipping_option_id = null;
  };
  PaymentRequestClient_OnShippingOptionChange_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequestClient_OnShippingOptionChange_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequestClient_OnShippingOptionChange_Params.shipping_option_id
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequestClient_OnShippingOptionChange_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequestClient_OnShippingOptionChange_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequestClient_OnShippingOptionChange_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.shipping_option_id = decoder.decodeStruct(codec.String);
    return val;
  };

  PaymentRequestClient_OnShippingOptionChange_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequestClient_OnShippingOptionChange_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.shipping_option_id);
  };
  function PaymentRequestClient_OnPaymentResponse_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequestClient_OnPaymentResponse_Params.prototype.initDefaults_ = function() {
    this.response = null;
  };
  PaymentRequestClient_OnPaymentResponse_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequestClient_OnPaymentResponse_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequestClient_OnPaymentResponse_Params.response
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PaymentResponse, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequestClient_OnPaymentResponse_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequestClient_OnPaymentResponse_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequestClient_OnPaymentResponse_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.response = decoder.decodeStructPointer(PaymentResponse);
    return val;
  };

  PaymentRequestClient_OnPaymentResponse_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequestClient_OnPaymentResponse_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PaymentResponse, val.response);
  };
  function PaymentRequestClient_OnError_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequestClient_OnError_Params.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  PaymentRequestClient_OnError_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequestClient_OnError_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequestClient_OnError_Params.error
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PaymentErrorReason);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequestClient_OnError_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequestClient_OnError_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequestClient_OnError_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentRequestClient_OnError_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequestClient_OnError_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PaymentRequestClient_OnComplete_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequestClient_OnComplete_Params.prototype.initDefaults_ = function() {
  };
  PaymentRequestClient_OnComplete_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequestClient_OnComplete_Params.validate = function(messageValidator, offset) {
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

  PaymentRequestClient_OnComplete_Params.encodedSize = codec.kStructHeaderSize + 0;

  PaymentRequestClient_OnComplete_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequestClient_OnComplete_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PaymentRequestClient_OnComplete_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequestClient_OnComplete_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function PaymentRequestClient_OnAbort_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequestClient_OnAbort_Params.prototype.initDefaults_ = function() {
    this.aborted_successfully = false;
  };
  PaymentRequestClient_OnAbort_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequestClient_OnAbort_Params.validate = function(messageValidator, offset) {
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

  PaymentRequestClient_OnAbort_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequestClient_OnAbort_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequestClient_OnAbort_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    packed = decoder.readUint8();
    val.aborted_successfully = (packed >> 0) & 1 ? true : false;
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentRequestClient_OnAbort_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequestClient_OnAbort_Params.encodedSize);
    encoder.writeUint32(0);
    packed = 0;
    packed |= (val.aborted_successfully & 1) << 0
    encoder.writeUint8(packed);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PaymentRequestClient_OnCanMakePayment_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequestClient_OnCanMakePayment_Params.prototype.initDefaults_ = function() {
    this.result = 0;
  };
  PaymentRequestClient_OnCanMakePayment_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequestClient_OnCanMakePayment_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequestClient_OnCanMakePayment_Params.result
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, CanMakePaymentQueryResult);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequestClient_OnCanMakePayment_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequestClient_OnCanMakePayment_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequestClient_OnCanMakePayment_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentRequestClient_OnCanMakePayment_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequestClient_OnCanMakePayment_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.result);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PaymentRequest_Init_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequest_Init_Params.prototype.initDefaults_ = function() {
    this.client = new PaymentRequestClientPtr();
    this.method_data = null;
    this.details = null;
    this.options = null;
  };
  PaymentRequest_Init_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequest_Init_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequest_Init_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 0, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentRequest_Init_Params.method_data
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 8, 8, new codec.PointerTo(PaymentMethodData), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentRequest_Init_Params.details
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 16, PaymentDetails, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate PaymentRequest_Init_Params.options
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 24, PaymentOptions, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequest_Init_Params.encodedSize = codec.kStructHeaderSize + 32;

  PaymentRequest_Init_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequest_Init_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.client = decoder.decodeStruct(new codec.Interface(PaymentRequestClientPtr));
    val.method_data = decoder.decodeArrayPointer(new codec.PointerTo(PaymentMethodData));
    val.details = decoder.decodeStructPointer(PaymentDetails);
    val.options = decoder.decodeStructPointer(PaymentOptions);
    return val;
  };

  PaymentRequest_Init_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequest_Init_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(new codec.Interface(PaymentRequestClientPtr), val.client);
    encoder.encodeArrayPointer(new codec.PointerTo(PaymentMethodData), val.method_data);
    encoder.encodeStructPointer(PaymentDetails, val.details);
    encoder.encodeStructPointer(PaymentOptions, val.options);
  };
  function PaymentRequest_Show_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequest_Show_Params.prototype.initDefaults_ = function() {
  };
  PaymentRequest_Show_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequest_Show_Params.validate = function(messageValidator, offset) {
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

  PaymentRequest_Show_Params.encodedSize = codec.kStructHeaderSize + 0;

  PaymentRequest_Show_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequest_Show_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PaymentRequest_Show_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequest_Show_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function PaymentRequest_UpdateWith_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequest_UpdateWith_Params.prototype.initDefaults_ = function() {
    this.details = null;
  };
  PaymentRequest_UpdateWith_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequest_UpdateWith_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequest_UpdateWith_Params.details
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, PaymentDetails, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequest_UpdateWith_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequest_UpdateWith_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequest_UpdateWith_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.details = decoder.decodeStructPointer(PaymentDetails);
    return val;
  };

  PaymentRequest_UpdateWith_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequest_UpdateWith_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(PaymentDetails, val.details);
  };
  function PaymentRequest_Abort_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequest_Abort_Params.prototype.initDefaults_ = function() {
  };
  PaymentRequest_Abort_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequest_Abort_Params.validate = function(messageValidator, offset) {
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

  PaymentRequest_Abort_Params.encodedSize = codec.kStructHeaderSize + 0;

  PaymentRequest_Abort_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequest_Abort_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PaymentRequest_Abort_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequest_Abort_Params.encodedSize);
    encoder.writeUint32(0);
  };
  function PaymentRequest_Complete_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequest_Complete_Params.prototype.initDefaults_ = function() {
    this.result = 0;
  };
  PaymentRequest_Complete_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequest_Complete_Params.validate = function(messageValidator, offset) {
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


    
    // validate PaymentRequest_Complete_Params.result
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, PaymentComplete);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  PaymentRequest_Complete_Params.encodedSize = codec.kStructHeaderSize + 8;

  PaymentRequest_Complete_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequest_Complete_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.result = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  PaymentRequest_Complete_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequest_Complete_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.result);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function PaymentRequest_CanMakePayment_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  PaymentRequest_CanMakePayment_Params.prototype.initDefaults_ = function() {
  };
  PaymentRequest_CanMakePayment_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  PaymentRequest_CanMakePayment_Params.validate = function(messageValidator, offset) {
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

  PaymentRequest_CanMakePayment_Params.encodedSize = codec.kStructHeaderSize + 0;

  PaymentRequest_CanMakePayment_Params.decode = function(decoder) {
    var packed;
    var val = new PaymentRequest_CanMakePayment_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    return val;
  };

  PaymentRequest_CanMakePayment_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(PaymentRequest_CanMakePayment_Params.encodedSize);
    encoder.writeUint32(0);
  };
  var kPaymentRequestClient_OnShippingAddressChange_Name = 0;
  var kPaymentRequestClient_OnShippingOptionChange_Name = 1;
  var kPaymentRequestClient_OnPaymentResponse_Name = 2;
  var kPaymentRequestClient_OnError_Name = 3;
  var kPaymentRequestClient_OnComplete_Name = 4;
  var kPaymentRequestClient_OnAbort_Name = 5;
  var kPaymentRequestClient_OnCanMakePayment_Name = 6;

  function PaymentRequestClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PaymentRequestClient,
                                                   handleOrPtrInfo);
  }

  function PaymentRequestClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  PaymentRequestClientPtr.prototype.onShippingAddressChange = function() {
    return PaymentRequestClientProxy.prototype.onShippingAddressChange
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestClientProxy.prototype.onShippingAddressChange = function(address) {
    var params = new PaymentRequestClient_OnShippingAddressChange_Params();
    params.address = address;
    var builder = new codec.MessageBuilder(
        kPaymentRequestClient_OnShippingAddressChange_Name,
        codec.align(PaymentRequestClient_OnShippingAddressChange_Params.encodedSize));
    builder.encodeStruct(PaymentRequestClient_OnShippingAddressChange_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestClientPtr.prototype.onShippingOptionChange = function() {
    return PaymentRequestClientProxy.prototype.onShippingOptionChange
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestClientProxy.prototype.onShippingOptionChange = function(shipping_option_id) {
    var params = new PaymentRequestClient_OnShippingOptionChange_Params();
    params.shipping_option_id = shipping_option_id;
    var builder = new codec.MessageBuilder(
        kPaymentRequestClient_OnShippingOptionChange_Name,
        codec.align(PaymentRequestClient_OnShippingOptionChange_Params.encodedSize));
    builder.encodeStruct(PaymentRequestClient_OnShippingOptionChange_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestClientPtr.prototype.onPaymentResponse = function() {
    return PaymentRequestClientProxy.prototype.onPaymentResponse
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestClientProxy.prototype.onPaymentResponse = function(response) {
    var params = new PaymentRequestClient_OnPaymentResponse_Params();
    params.response = response;
    var builder = new codec.MessageBuilder(
        kPaymentRequestClient_OnPaymentResponse_Name,
        codec.align(PaymentRequestClient_OnPaymentResponse_Params.encodedSize));
    builder.encodeStruct(PaymentRequestClient_OnPaymentResponse_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestClientPtr.prototype.onError = function() {
    return PaymentRequestClientProxy.prototype.onError
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestClientProxy.prototype.onError = function(error) {
    var params = new PaymentRequestClient_OnError_Params();
    params.error = error;
    var builder = new codec.MessageBuilder(
        kPaymentRequestClient_OnError_Name,
        codec.align(PaymentRequestClient_OnError_Params.encodedSize));
    builder.encodeStruct(PaymentRequestClient_OnError_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestClientPtr.prototype.onComplete = function() {
    return PaymentRequestClientProxy.prototype.onComplete
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestClientProxy.prototype.onComplete = function() {
    var params = new PaymentRequestClient_OnComplete_Params();
    var builder = new codec.MessageBuilder(
        kPaymentRequestClient_OnComplete_Name,
        codec.align(PaymentRequestClient_OnComplete_Params.encodedSize));
    builder.encodeStruct(PaymentRequestClient_OnComplete_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestClientPtr.prototype.onAbort = function() {
    return PaymentRequestClientProxy.prototype.onAbort
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestClientProxy.prototype.onAbort = function(aborted_successfully) {
    var params = new PaymentRequestClient_OnAbort_Params();
    params.aborted_successfully = aborted_successfully;
    var builder = new codec.MessageBuilder(
        kPaymentRequestClient_OnAbort_Name,
        codec.align(PaymentRequestClient_OnAbort_Params.encodedSize));
    builder.encodeStruct(PaymentRequestClient_OnAbort_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestClientPtr.prototype.onCanMakePayment = function() {
    return PaymentRequestClientProxy.prototype.onCanMakePayment
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestClientProxy.prototype.onCanMakePayment = function(result) {
    var params = new PaymentRequestClient_OnCanMakePayment_Params();
    params.result = result;
    var builder = new codec.MessageBuilder(
        kPaymentRequestClient_OnCanMakePayment_Name,
        codec.align(PaymentRequestClient_OnCanMakePayment_Params.encodedSize));
    builder.encodeStruct(PaymentRequestClient_OnCanMakePayment_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PaymentRequestClientStub(delegate) {
    this.delegate_ = delegate;
  }
  PaymentRequestClientStub.prototype.onShippingAddressChange = function(address) {
    return this.delegate_ && this.delegate_.onShippingAddressChange && this.delegate_.onShippingAddressChange(address);
  }
  PaymentRequestClientStub.prototype.onShippingOptionChange = function(shipping_option_id) {
    return this.delegate_ && this.delegate_.onShippingOptionChange && this.delegate_.onShippingOptionChange(shipping_option_id);
  }
  PaymentRequestClientStub.prototype.onPaymentResponse = function(response) {
    return this.delegate_ && this.delegate_.onPaymentResponse && this.delegate_.onPaymentResponse(response);
  }
  PaymentRequestClientStub.prototype.onError = function(error) {
    return this.delegate_ && this.delegate_.onError && this.delegate_.onError(error);
  }
  PaymentRequestClientStub.prototype.onComplete = function() {
    return this.delegate_ && this.delegate_.onComplete && this.delegate_.onComplete();
  }
  PaymentRequestClientStub.prototype.onAbort = function(aborted_successfully) {
    return this.delegate_ && this.delegate_.onAbort && this.delegate_.onAbort(aborted_successfully);
  }
  PaymentRequestClientStub.prototype.onCanMakePayment = function(result) {
    return this.delegate_ && this.delegate_.onCanMakePayment && this.delegate_.onCanMakePayment(result);
  }

  PaymentRequestClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPaymentRequestClient_OnShippingAddressChange_Name:
      var params = reader.decodeStruct(PaymentRequestClient_OnShippingAddressChange_Params);
      this.onShippingAddressChange(params.address);
      return true;
    case kPaymentRequestClient_OnShippingOptionChange_Name:
      var params = reader.decodeStruct(PaymentRequestClient_OnShippingOptionChange_Params);
      this.onShippingOptionChange(params.shipping_option_id);
      return true;
    case kPaymentRequestClient_OnPaymentResponse_Name:
      var params = reader.decodeStruct(PaymentRequestClient_OnPaymentResponse_Params);
      this.onPaymentResponse(params.response);
      return true;
    case kPaymentRequestClient_OnError_Name:
      var params = reader.decodeStruct(PaymentRequestClient_OnError_Params);
      this.onError(params.error);
      return true;
    case kPaymentRequestClient_OnComplete_Name:
      var params = reader.decodeStruct(PaymentRequestClient_OnComplete_Params);
      this.onComplete();
      return true;
    case kPaymentRequestClient_OnAbort_Name:
      var params = reader.decodeStruct(PaymentRequestClient_OnAbort_Params);
      this.onAbort(params.aborted_successfully);
      return true;
    case kPaymentRequestClient_OnCanMakePayment_Name:
      var params = reader.decodeStruct(PaymentRequestClient_OnCanMakePayment_Params);
      this.onCanMakePayment(params.result);
      return true;
    default:
      return false;
    }
  };

  PaymentRequestClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePaymentRequestClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPaymentRequestClient_OnShippingAddressChange_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequestClient_OnShippingAddressChange_Params;
      break;
      case kPaymentRequestClient_OnShippingOptionChange_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequestClient_OnShippingOptionChange_Params;
      break;
      case kPaymentRequestClient_OnPaymentResponse_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequestClient_OnPaymentResponse_Params;
      break;
      case kPaymentRequestClient_OnError_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequestClient_OnError_Params;
      break;
      case kPaymentRequestClient_OnComplete_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequestClient_OnComplete_Params;
      break;
      case kPaymentRequestClient_OnAbort_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequestClient_OnAbort_Params;
      break;
      case kPaymentRequestClient_OnCanMakePayment_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequestClient_OnCanMakePayment_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePaymentRequestClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PaymentRequestClient = {
    name: 'payments::mojom::PaymentRequestClient',
    ptrClass: PaymentRequestClientPtr,
    proxyClass: PaymentRequestClientProxy,
    stubClass: PaymentRequestClientStub,
    validateRequest: validatePaymentRequestClientRequest,
    validateResponse: null,
  };
  PaymentRequestClientStub.prototype.validator = validatePaymentRequestClientRequest;
  PaymentRequestClientProxy.prototype.validator = null;
  var kPaymentRequest_Init_Name = 0;
  var kPaymentRequest_Show_Name = 1;
  var kPaymentRequest_UpdateWith_Name = 2;
  var kPaymentRequest_Abort_Name = 3;
  var kPaymentRequest_Complete_Name = 4;
  var kPaymentRequest_CanMakePayment_Name = 5;

  function PaymentRequestPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(PaymentRequest,
                                                   handleOrPtrInfo);
  }

  function PaymentRequestProxy(receiver) {
    this.receiver_ = receiver;
  }
  PaymentRequestPtr.prototype.init = function() {
    return PaymentRequestProxy.prototype.init
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestProxy.prototype.init = function(client, method_data, details, options) {
    var params = new PaymentRequest_Init_Params();
    params.client = client;
    params.method_data = method_data;
    params.details = details;
    params.options = options;
    var builder = new codec.MessageBuilder(
        kPaymentRequest_Init_Name,
        codec.align(PaymentRequest_Init_Params.encodedSize));
    builder.encodeStruct(PaymentRequest_Init_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestPtr.prototype.show = function() {
    return PaymentRequestProxy.prototype.show
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestProxy.prototype.show = function() {
    var params = new PaymentRequest_Show_Params();
    var builder = new codec.MessageBuilder(
        kPaymentRequest_Show_Name,
        codec.align(PaymentRequest_Show_Params.encodedSize));
    builder.encodeStruct(PaymentRequest_Show_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestPtr.prototype.updateWith = function() {
    return PaymentRequestProxy.prototype.updateWith
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestProxy.prototype.updateWith = function(details) {
    var params = new PaymentRequest_UpdateWith_Params();
    params.details = details;
    var builder = new codec.MessageBuilder(
        kPaymentRequest_UpdateWith_Name,
        codec.align(PaymentRequest_UpdateWith_Params.encodedSize));
    builder.encodeStruct(PaymentRequest_UpdateWith_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestPtr.prototype.abort = function() {
    return PaymentRequestProxy.prototype.abort
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestProxy.prototype.abort = function() {
    var params = new PaymentRequest_Abort_Params();
    var builder = new codec.MessageBuilder(
        kPaymentRequest_Abort_Name,
        codec.align(PaymentRequest_Abort_Params.encodedSize));
    builder.encodeStruct(PaymentRequest_Abort_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestPtr.prototype.complete = function() {
    return PaymentRequestProxy.prototype.complete
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestProxy.prototype.complete = function(result) {
    var params = new PaymentRequest_Complete_Params();
    params.result = result;
    var builder = new codec.MessageBuilder(
        kPaymentRequest_Complete_Name,
        codec.align(PaymentRequest_Complete_Params.encodedSize));
    builder.encodeStruct(PaymentRequest_Complete_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  PaymentRequestPtr.prototype.canMakePayment = function() {
    return PaymentRequestProxy.prototype.canMakePayment
        .apply(this.ptr.getProxy(), arguments);
  };

  PaymentRequestProxy.prototype.canMakePayment = function() {
    var params = new PaymentRequest_CanMakePayment_Params();
    var builder = new codec.MessageBuilder(
        kPaymentRequest_CanMakePayment_Name,
        codec.align(PaymentRequest_CanMakePayment_Params.encodedSize));
    builder.encodeStruct(PaymentRequest_CanMakePayment_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function PaymentRequestStub(delegate) {
    this.delegate_ = delegate;
  }
  PaymentRequestStub.prototype.init = function(client, method_data, details, options) {
    return this.delegate_ && this.delegate_.init && this.delegate_.init(client, method_data, details, options);
  }
  PaymentRequestStub.prototype.show = function() {
    return this.delegate_ && this.delegate_.show && this.delegate_.show();
  }
  PaymentRequestStub.prototype.updateWith = function(details) {
    return this.delegate_ && this.delegate_.updateWith && this.delegate_.updateWith(details);
  }
  PaymentRequestStub.prototype.abort = function() {
    return this.delegate_ && this.delegate_.abort && this.delegate_.abort();
  }
  PaymentRequestStub.prototype.complete = function(result) {
    return this.delegate_ && this.delegate_.complete && this.delegate_.complete(result);
  }
  PaymentRequestStub.prototype.canMakePayment = function() {
    return this.delegate_ && this.delegate_.canMakePayment && this.delegate_.canMakePayment();
  }

  PaymentRequestStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kPaymentRequest_Init_Name:
      var params = reader.decodeStruct(PaymentRequest_Init_Params);
      this.init(params.client, params.method_data, params.details, params.options);
      return true;
    case kPaymentRequest_Show_Name:
      var params = reader.decodeStruct(PaymentRequest_Show_Params);
      this.show();
      return true;
    case kPaymentRequest_UpdateWith_Name:
      var params = reader.decodeStruct(PaymentRequest_UpdateWith_Params);
      this.updateWith(params.details);
      return true;
    case kPaymentRequest_Abort_Name:
      var params = reader.decodeStruct(PaymentRequest_Abort_Params);
      this.abort();
      return true;
    case kPaymentRequest_Complete_Name:
      var params = reader.decodeStruct(PaymentRequest_Complete_Params);
      this.complete(params.result);
      return true;
    case kPaymentRequest_CanMakePayment_Name:
      var params = reader.decodeStruct(PaymentRequest_CanMakePayment_Params);
      this.canMakePayment();
      return true;
    default:
      return false;
    }
  };

  PaymentRequestStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validatePaymentRequestRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kPaymentRequest_Init_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequest_Init_Params;
      break;
      case kPaymentRequest_Show_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequest_Show_Params;
      break;
      case kPaymentRequest_UpdateWith_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequest_UpdateWith_Params;
      break;
      case kPaymentRequest_Abort_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequest_Abort_Params;
      break;
      case kPaymentRequest_Complete_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequest_Complete_Params;
      break;
      case kPaymentRequest_CanMakePayment_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = PaymentRequest_CanMakePayment_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validatePaymentRequestResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var PaymentRequest = {
    name: 'payments::mojom::PaymentRequest',
    ptrClass: PaymentRequestPtr,
    proxyClass: PaymentRequestProxy,
    stubClass: PaymentRequestStub,
    validateRequest: validatePaymentRequestRequest,
    validateResponse: null,
  };
  PaymentRequestStub.prototype.validator = validatePaymentRequestRequest;
  PaymentRequestProxy.prototype.validator = null;

  var exports = {};
  exports.PaymentErrorReason = PaymentErrorReason;
  exports.CanMakePaymentQueryResult = CanMakePaymentQueryResult;
  exports.AndroidPayEnvironment = AndroidPayEnvironment;
  exports.AndroidPayCardNetwork = AndroidPayCardNetwork;
  exports.AndroidPayTokenization = AndroidPayTokenization;
  exports.BasicCardNetwork = BasicCardNetwork;
  exports.BasicCardType = BasicCardType;
  exports.PaymentShippingType = PaymentShippingType;
  exports.PaymentComplete = PaymentComplete;
  exports.PaymentAddress = PaymentAddress;
  exports.PaymentCurrencyAmount = PaymentCurrencyAmount;
  exports.PaymentResponse = PaymentResponse;
  exports.PaymentItem = PaymentItem;
  exports.PaymentShippingOption = PaymentShippingOption;
  exports.AndroidPayTokenizationParameter = AndroidPayTokenizationParameter;
  exports.PaymentMethodData = PaymentMethodData;
  exports.PaymentDetailsModifier = PaymentDetailsModifier;
  exports.PaymentDetails = PaymentDetails;
  exports.PaymentOptions = PaymentOptions;
  exports.PaymentRequestClient = PaymentRequestClient;
  exports.PaymentRequestClientPtr = PaymentRequestClientPtr;
  exports.PaymentRequest = PaymentRequest;
  exports.PaymentRequestPtr = PaymentRequestPtr;

  return exports;
});
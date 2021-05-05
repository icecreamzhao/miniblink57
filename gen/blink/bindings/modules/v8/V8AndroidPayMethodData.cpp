// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8AndroidPayMethodData.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8AndroidPayTokenization.h"

namespace blink {

void V8AndroidPayMethodData::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, AndroidPayMethodData& impl, ExceptionState& exceptionState) {
  if (isUndefinedOrNull(v8Value)) {
    return;
  }
  if (!v8Value->IsObject()) {
    exceptionState.throwTypeError("cannot convert to dictionary.");
    return;
  }

  v8::TryCatch block(isolate);
  v8::Local<v8::Object> v8Object;
  if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  v8::Local<v8::Value> allowedCardNetworksValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "allowedCardNetworks")).ToLocal(&allowedCardNetworksValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (allowedCardNetworksValue.IsEmpty() || allowedCardNetworksValue->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<String> allowedCardNetworks = toImplArray<Vector<String>>(allowedCardNetworksValue, 0, isolate, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setAllowedCardNetworks(allowedCardNetworks);
  }

  v8::Local<v8::Value> environmentValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "environment")).ToLocal(&environmentValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (environmentValue.IsEmpty() || environmentValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> environment = environmentValue;
    if (!environment.prepare(exceptionState))
      return;
    impl.setEnvironment(environment);
  }

  v8::Local<v8::Value> merchantIdValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "merchantId")).ToLocal(&merchantIdValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (merchantIdValue.IsEmpty() || merchantIdValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> merchantId = merchantIdValue;
    if (!merchantId.prepare(exceptionState))
      return;
    impl.setMerchantId(merchantId);
  }

  v8::Local<v8::Value> merchantNameValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "merchantName")).ToLocal(&merchantNameValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (merchantNameValue.IsEmpty() || merchantNameValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> merchantName = merchantNameValue;
    if (!merchantName.prepare(exceptionState))
      return;
    impl.setMerchantName(merchantName);
  }

  v8::Local<v8::Value> minGooglePlayServicesVersionValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "minGooglePlayServicesVersion")).ToLocal(&minGooglePlayServicesVersionValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (minGooglePlayServicesVersionValue.IsEmpty() || minGooglePlayServicesVersionValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> minGooglePlayServicesVersion = minGooglePlayServicesVersionValue;
    if (!minGooglePlayServicesVersion.prepare(exceptionState))
      return;
    impl.setMinGooglePlayServicesVersion(minGooglePlayServicesVersion);
  }

  v8::Local<v8::Value> paymentMethodTokenizationParametersValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "paymentMethodTokenizationParameters")).ToLocal(&paymentMethodTokenizationParametersValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (paymentMethodTokenizationParametersValue.IsEmpty() || paymentMethodTokenizationParametersValue->IsUndefined()) {
    // Do nothing.
  } else {
    AndroidPayTokenization paymentMethodTokenizationParameters;
    V8AndroidPayTokenization::toImpl(isolate, paymentMethodTokenizationParametersValue, paymentMethodTokenizationParameters, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setPaymentMethodTokenizationParameters(paymentMethodTokenizationParameters);
  }
}

v8::Local<v8::Value> AndroidPayMethodData::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8AndroidPayMethodData(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8AndroidPayMethodData(const AndroidPayMethodData& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasAllowedCardNetworks()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "allowedCardNetworks"), ToV8(impl.allowedCardNetworks(), creationContext, isolate))))
      return false;
  }

  if (impl.hasEnvironment()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "environment"), v8String(isolate, impl.environment()))))
      return false;
  }

  if (impl.hasMerchantId()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "merchantId"), v8String(isolate, impl.merchantId()))))
      return false;
  }

  if (impl.hasMerchantName()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "merchantName"), v8String(isolate, impl.merchantName()))))
      return false;
  }

  if (impl.hasMinGooglePlayServicesVersion()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "minGooglePlayServicesVersion"), v8String(isolate, impl.minGooglePlayServicesVersion()))))
      return false;
  }

  if (impl.hasPaymentMethodTokenizationParameters()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "paymentMethodTokenizationParameters"), ToV8(impl.paymentMethodTokenizationParameters(), creationContext, isolate))))
      return false;
  }

  return true;
}

AndroidPayMethodData NativeValueTraits<AndroidPayMethodData>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  AndroidPayMethodData impl;
  V8AndroidPayMethodData::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

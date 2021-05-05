// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8StorageEstimate.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8StorageEstimate::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, StorageEstimate& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> quotaValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "quota")).ToLocal(&quotaValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (quotaValue.IsEmpty() || quotaValue->IsUndefined()) {
    // Do nothing.
  } else {
    unsigned long long quota = toUInt64(isolate, quotaValue, NormalConversion, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setQuota(quota);
  }

  v8::Local<v8::Value> usageValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "usage")).ToLocal(&usageValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (usageValue.IsEmpty() || usageValue->IsUndefined()) {
    // Do nothing.
  } else {
    unsigned long long usage = toUInt64(isolate, usageValue, NormalConversion, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setUsage(usage);
  }
}

v8::Local<v8::Value> StorageEstimate::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8StorageEstimate(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8StorageEstimate(const StorageEstimate& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasQuota()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "quota"), v8::Number::New(isolate, static_cast<double>(impl.quota())))))
      return false;
  }

  if (impl.hasUsage()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "usage"), v8::Number::New(isolate, static_cast<double>(impl.usage())))))
      return false;
  }

  return true;
}

StorageEstimate NativeValueTraits<StorageEstimate>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  StorageEstimate impl;
  V8StorageEstimate::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

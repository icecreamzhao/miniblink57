// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8AnalyserOptions.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8AudioNodeOptions.h"

namespace blink {

void V8AnalyserOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, AnalyserOptions& impl, ExceptionState& exceptionState) {
  if (isUndefinedOrNull(v8Value)) {
    return;
  }
  if (!v8Value->IsObject()) {
    exceptionState.throwTypeError("cannot convert to dictionary.");
    return;
  }

  V8AudioNodeOptions::toImpl(isolate, v8Value, impl, exceptionState);
  if (exceptionState.hadException())
    return;

  v8::TryCatch block(isolate);
  v8::Local<v8::Object> v8Object;
  if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  v8::Local<v8::Value> fftSizeValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "fftSize")).ToLocal(&fftSizeValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (fftSizeValue.IsEmpty() || fftSizeValue->IsUndefined()) {
    // Do nothing.
  } else {
    unsigned fftSize = toUInt32(isolate, fftSizeValue, NormalConversion, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setFftSize(fftSize);
  }

  v8::Local<v8::Value> maxDecibelsValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "maxDecibels")).ToLocal(&maxDecibelsValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (maxDecibelsValue.IsEmpty() || maxDecibelsValue->IsUndefined()) {
    // Do nothing.
  } else {
    float maxDecibels = toRestrictedFloat(isolate, maxDecibelsValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setMaxDecibels(maxDecibels);
  }

  v8::Local<v8::Value> minDecibelsValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "minDecibels")).ToLocal(&minDecibelsValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (minDecibelsValue.IsEmpty() || minDecibelsValue->IsUndefined()) {
    // Do nothing.
  } else {
    float minDecibels = toRestrictedFloat(isolate, minDecibelsValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setMinDecibels(minDecibels);
  }

  v8::Local<v8::Value> smoothingTimeConstantValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "smoothingTimeConstant")).ToLocal(&smoothingTimeConstantValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (smoothingTimeConstantValue.IsEmpty() || smoothingTimeConstantValue->IsUndefined()) {
    // Do nothing.
  } else {
    float smoothingTimeConstant = toRestrictedFloat(isolate, smoothingTimeConstantValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setSmoothingTimeConstant(smoothingTimeConstant);
  }
}

v8::Local<v8::Value> AnalyserOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8AnalyserOptions(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8AnalyserOptions(const AnalyserOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8AudioNodeOptions(impl, dictionary, creationContext, isolate))
    return false;

  if (impl.hasFftSize()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "fftSize"), v8::Integer::NewFromUnsigned(isolate, impl.fftSize()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "fftSize"), v8::Integer::NewFromUnsigned(isolate, 2048u))))
      return false;
  }

  if (impl.hasMaxDecibels()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "maxDecibels"), v8::Number::New(isolate, impl.maxDecibels()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "maxDecibels"), v8::Number::New(isolate, -30))))
      return false;
  }

  if (impl.hasMinDecibels()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "minDecibels"), v8::Number::New(isolate, impl.minDecibels()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "minDecibels"), v8::Number::New(isolate, -100))))
      return false;
  }

  if (impl.hasSmoothingTimeConstant()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "smoothingTimeConstant"), v8::Number::New(isolate, impl.smoothingTimeConstant()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "smoothingTimeConstant"), v8::Number::New(isolate, 0.8))))
      return false;
  }

  return true;
}

AnalyserOptions NativeValueTraits<AnalyserOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  AnalyserOptions impl;
  V8AnalyserOptions::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

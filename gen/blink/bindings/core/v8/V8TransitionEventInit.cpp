// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8TransitionEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8EventInit.h"

namespace blink {

void V8TransitionEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, TransitionEventInit& impl, ExceptionState& exceptionState) {
  if (isUndefinedOrNull(v8Value)) {
    return;
  }
  if (!v8Value->IsObject()) {
    exceptionState.throwTypeError("cannot convert to dictionary.");
    return;
  }

  V8EventInit::toImpl(isolate, v8Value, impl, exceptionState);
  if (exceptionState.hadException())
    return;

  v8::TryCatch block(isolate);
  v8::Local<v8::Object> v8Object;
  if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  v8::Local<v8::Value> elapsedTimeValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "elapsedTime")).ToLocal(&elapsedTimeValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (elapsedTimeValue.IsEmpty() || elapsedTimeValue->IsUndefined()) {
    // Do nothing.
  } else {
    double elapsedTime = toRestrictedDouble(isolate, elapsedTimeValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setElapsedTime(elapsedTime);
  }

  v8::Local<v8::Value> propertyNameValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "propertyName")).ToLocal(&propertyNameValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (propertyNameValue.IsEmpty() || propertyNameValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> propertyName = propertyNameValue;
    if (!propertyName.prepare(exceptionState))
      return;
    impl.setPropertyName(propertyName);
  }

  v8::Local<v8::Value> pseudoElementValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "pseudoElement")).ToLocal(&pseudoElementValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (pseudoElementValue.IsEmpty() || pseudoElementValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> pseudoElement = pseudoElementValue;
    if (!pseudoElement.prepare(exceptionState))
      return;
    impl.setPseudoElement(pseudoElement);
  }
}

v8::Local<v8::Value> TransitionEventInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8TransitionEventInit(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8TransitionEventInit(const TransitionEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8EventInit(impl, dictionary, creationContext, isolate))
    return false;

  if (impl.hasElapsedTime()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "elapsedTime"), v8::Number::New(isolate, impl.elapsedTime()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "elapsedTime"), v8::Number::New(isolate, 0))))
      return false;
  }

  if (impl.hasPropertyName()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "propertyName"), v8String(isolate, impl.propertyName()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "propertyName"), v8String(isolate, String("")))))
      return false;
  }

  if (impl.hasPseudoElement()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "pseudoElement"), v8String(isolate, impl.pseudoElement()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "pseudoElement"), v8String(isolate, String("")))))
      return false;
  }

  return true;
}

TransitionEventInit NativeValueTraits<TransitionEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  TransitionEventInit impl;
  V8TransitionEventInit::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

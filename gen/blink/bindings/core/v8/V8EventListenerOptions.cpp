// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8EventListenerOptions.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8EventListenerOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, EventListenerOptions& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> captureValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "capture")).ToLocal(&captureValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (captureValue.IsEmpty() || captureValue->IsUndefined()) {
    // Do nothing.
  } else {
    bool capture = toBoolean(isolate, captureValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setCapture(capture);
  }
}

v8::Local<v8::Value> EventListenerOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8EventListenerOptions(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8EventListenerOptions(const EventListenerOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasCapture()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "capture"), v8Boolean(impl.capture(), isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "capture"), v8Boolean(false, isolate))))
      return false;
  }

  return true;
}

EventListenerOptions NativeValueTraits<EventListenerOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  EventListenerOptions impl;
  V8EventListenerOptions::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

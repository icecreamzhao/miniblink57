// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8HashChangeEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8EventInit.h"

namespace blink {

void V8HashChangeEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, HashChangeEventInit& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> newURLValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "newURL")).ToLocal(&newURLValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (newURLValue.IsEmpty() || newURLValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> newURL = newURLValue;
    if (!newURL.prepare(exceptionState))
      return;
    impl.setNewURL(newURL);
  }

  v8::Local<v8::Value> oldURLValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "oldURL")).ToLocal(&oldURLValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (oldURLValue.IsEmpty() || oldURLValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> oldURL = oldURLValue;
    if (!oldURL.prepare(exceptionState))
      return;
    impl.setOldURL(oldURL);
  }
}

v8::Local<v8::Value> HashChangeEventInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8HashChangeEventInit(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8HashChangeEventInit(const HashChangeEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8EventInit(impl, dictionary, creationContext, isolate))
    return false;

  if (impl.hasNewURL()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "newURL"), v8String(isolate, impl.newURL()))))
      return false;
  }

  if (impl.hasOldURL()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "oldURL"), v8String(isolate, impl.oldURL()))))
      return false;
  }

  return true;
}

HashChangeEventInit NativeValueTraits<HashChangeEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  HashChangeEventInit impl;
  V8HashChangeEventInit::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

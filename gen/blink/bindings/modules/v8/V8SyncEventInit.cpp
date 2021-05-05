// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8SyncEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8ExtendableEventInit.h"

namespace blink {

void V8SyncEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, SyncEventInit& impl, ExceptionState& exceptionState) {
  if (isUndefinedOrNull(v8Value)) {
    exceptionState.throwTypeError("Missing required member(s): tag.");
    return;
  }
  if (!v8Value->IsObject()) {
    exceptionState.throwTypeError("cannot convert to dictionary.");
    return;
  }

  V8ExtendableEventInit::toImpl(isolate, v8Value, impl, exceptionState);
  if (exceptionState.hadException())
    return;

  v8::TryCatch block(isolate);
  v8::Local<v8::Object> v8Object;
  if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  v8::Local<v8::Value> lastChanceValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "lastChance")).ToLocal(&lastChanceValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (lastChanceValue.IsEmpty() || lastChanceValue->IsUndefined()) {
    // Do nothing.
  } else {
    bool lastChance = toBoolean(isolate, lastChanceValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setLastChance(lastChance);
  }

  v8::Local<v8::Value> tagValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "tag")).ToLocal(&tagValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (tagValue.IsEmpty() || tagValue->IsUndefined()) {
    exceptionState.throwTypeError("required member tag is undefined.");
    return;
  } else {
    V8StringResource<> tag = tagValue;
    if (!tag.prepare(exceptionState))
      return;
    impl.setTag(tag);
  }
}

v8::Local<v8::Value> SyncEventInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8SyncEventInit(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8SyncEventInit(const SyncEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8ExtendableEventInit(impl, dictionary, creationContext, isolate))
    return false;

  if (impl.hasLastChance()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "lastChance"), v8Boolean(impl.lastChance(), isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "lastChance"), v8Boolean(false, isolate))))
      return false;
  }

  if (impl.hasTag()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "tag"), v8String(isolate, impl.tag()))))
      return false;
  } else {
    NOTREACHED();
  }

  return true;
}

SyncEventInit NativeValueTraits<SyncEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  SyncEventInit impl;
  V8SyncEventInit::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

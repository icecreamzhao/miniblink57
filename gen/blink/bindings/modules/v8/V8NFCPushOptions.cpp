// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8NFCPushOptions.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8NFCPushOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, NFCPushOptions& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> ignoreReadValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "ignoreRead")).ToLocal(&ignoreReadValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (ignoreReadValue.IsEmpty() || ignoreReadValue->IsUndefined()) {
    // Do nothing.
  } else {
    bool ignoreRead = toBoolean(isolate, ignoreReadValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setIgnoreRead(ignoreRead);
  }

  v8::Local<v8::Value> targetValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "target")).ToLocal(&targetValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (targetValue.IsEmpty() || targetValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> target = targetValue;
    if (!target.prepare(exceptionState))
      return;
    const char* validValues[] = {
        "tag",
        "peer",
        "any",
    };
    if (!isValidEnum(target, validValues, WTF_ARRAY_LENGTH(validValues), "NFCPushTarget", exceptionState))
      return;
    impl.setTarget(target);
  }

  v8::Local<v8::Value> timeoutValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "timeout")).ToLocal(&timeoutValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (timeoutValue.IsEmpty() || timeoutValue->IsUndefined()) {
    // Do nothing.
  } else {
    double timeout = toDouble(isolate, timeoutValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setTimeout(timeout);
  }
}

v8::Local<v8::Value> NFCPushOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8NFCPushOptions(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8NFCPushOptions(const NFCPushOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasIgnoreRead()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "ignoreRead"), v8Boolean(impl.ignoreRead(), isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "ignoreRead"), v8Boolean(true, isolate))))
      return false;
  }

  if (impl.hasTarget()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "target"), v8String(isolate, impl.target()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "target"), v8String(isolate, String("any")))))
      return false;
  }

  if (impl.hasTimeout()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "timeout"), v8::Number::New(isolate, impl.timeout()))))
      return false;
  }

  return true;
}

NFCPushOptions NativeValueTraits<NFCPushOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  NFCPushOptions impl;
  V8NFCPushOptions::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

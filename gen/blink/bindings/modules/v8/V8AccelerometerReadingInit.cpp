// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8AccelerometerReadingInit.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8AccelerometerReadingInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, AccelerometerReadingInit& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> xValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "x")).ToLocal(&xValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (xValue.IsEmpty() || xValue->IsUndefined()) {
    // Do nothing.
  } else {
    double x = toDouble(isolate, xValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setX(x);
  }

  v8::Local<v8::Value> yValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "y")).ToLocal(&yValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (yValue.IsEmpty() || yValue->IsUndefined()) {
    // Do nothing.
  } else {
    double y = toDouble(isolate, yValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setY(y);
  }

  v8::Local<v8::Value> zValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "z")).ToLocal(&zValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (zValue.IsEmpty() || zValue->IsUndefined()) {
    // Do nothing.
  } else {
    double z = toDouble(isolate, zValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setZ(z);
  }
}

v8::Local<v8::Value> AccelerometerReadingInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8AccelerometerReadingInit(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8AccelerometerReadingInit(const AccelerometerReadingInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasX()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "x"), v8::Number::New(isolate, impl.x()))))
      return false;
  }

  if (impl.hasY()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "y"), v8::Number::New(isolate, impl.y()))))
      return false;
  }

  if (impl.hasZ()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "z"), v8::Number::New(isolate, impl.z()))))
      return false;
  }

  return true;
}

AccelerometerReadingInit NativeValueTraits<AccelerometerReadingInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  AccelerometerReadingInit impl;
  V8AccelerometerReadingInit::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

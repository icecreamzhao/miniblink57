// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8VRLayer.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8HTMLCanvasElement.h"

namespace blink {

void V8VRLayer::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, VRLayer& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> leftBoundsValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "leftBounds")).ToLocal(&leftBoundsValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (leftBoundsValue.IsEmpty() || leftBoundsValue->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<float> leftBounds = toImplArray<Vector<float>>(leftBoundsValue, 0, isolate, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setLeftBounds(leftBounds);
  }

  v8::Local<v8::Value> rightBoundsValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "rightBounds")).ToLocal(&rightBoundsValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (rightBoundsValue.IsEmpty() || rightBoundsValue->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<float> rightBounds = toImplArray<Vector<float>>(rightBoundsValue, 0, isolate, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setRightBounds(rightBounds);
  }

  v8::Local<v8::Value> sourceValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "source")).ToLocal(&sourceValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (sourceValue.IsEmpty() || sourceValue->IsUndefined()) {
    // Do nothing.
  } else if (sourceValue->IsNull()) {
    impl.setSourceToNull();
  } else {
    HTMLCanvasElement* source = V8HTMLCanvasElement::toImplWithTypeCheck(isolate, sourceValue);
    if (!source) {
      exceptionState.throwTypeError("member source is not of type HTMLCanvasElement.");
      return;
    }
    impl.setSource(source);
  }
}

v8::Local<v8::Value> VRLayer::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8VRLayer(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8VRLayer(const VRLayer& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasLeftBounds()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "leftBounds"), ToV8(impl.leftBounds(), creationContext, isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "leftBounds"), ToV8(Vector<float>(), creationContext, isolate))))
      return false;
  }

  if (impl.hasRightBounds()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "rightBounds"), ToV8(impl.rightBounds(), creationContext, isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "rightBounds"), ToV8(Vector<float>(), creationContext, isolate))))
      return false;
  }

  if (impl.hasSource()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "source"), ToV8(impl.source(), creationContext, isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "source"), v8::Null(isolate))))
      return false;
  }

  return true;
}

VRLayer NativeValueTraits<VRLayer>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  VRLayer impl;
  V8VRLayer::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

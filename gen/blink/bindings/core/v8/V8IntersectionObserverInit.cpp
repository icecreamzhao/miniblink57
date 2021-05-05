// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8IntersectionObserverInit.h"

#include "bindings/core/v8/DoubleOrDoubleSequence.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Element.h"

namespace blink {

void V8IntersectionObserverInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, IntersectionObserverInit& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> rootValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "root")).ToLocal(&rootValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (rootValue.IsEmpty() || rootValue->IsUndefined()) {
    // Do nothing.
  } else if (rootValue->IsNull()) {
    impl.setRootToNull();
  } else {
    Element* root = V8Element::toImplWithTypeCheck(isolate, rootValue);
    if (!root) {
      exceptionState.throwTypeError("member root is not of type Element.");
      return;
    }
    impl.setRoot(root);
  }

  v8::Local<v8::Value> rootMarginValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "rootMargin")).ToLocal(&rootMarginValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (rootMarginValue.IsEmpty() || rootMarginValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> rootMargin = rootMarginValue;
    if (!rootMargin.prepare(exceptionState))
      return;
    impl.setRootMargin(rootMargin);
  }

  v8::Local<v8::Value> thresholdValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "threshold")).ToLocal(&thresholdValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (thresholdValue.IsEmpty() || thresholdValue->IsUndefined()) {
    // Do nothing.
  } else {
    DoubleOrDoubleSequence threshold;
    V8DoubleOrDoubleSequence::toImpl(isolate, thresholdValue, threshold, UnionTypeConversionMode::NotNullable, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setThreshold(threshold);
  }
}

v8::Local<v8::Value> IntersectionObserverInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8IntersectionObserverInit(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8IntersectionObserverInit(const IntersectionObserverInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasRoot()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "root"), ToV8(impl.root(), creationContext, isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "root"), v8::Null(isolate))))
      return false;
  }

  if (impl.hasRootMargin()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "rootMargin"), v8String(isolate, impl.rootMargin()))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "rootMargin"), v8String(isolate, String("0px")))))
      return false;
  }

  if (impl.hasThreshold()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "threshold"), ToV8(impl.threshold(), creationContext, isolate))))
      return false;
  } else {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "threshold"), ToV8(DoubleOrDoubleSequence::fromDouble(0), creationContext, isolate))))
      return false;
  }

  return true;
}

IntersectionObserverInit NativeValueTraits<IntersectionObserverInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  IntersectionObserverInit impl;
  V8IntersectionObserverInit::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

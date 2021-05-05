// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8InternalDictionaryDerivedDerived.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8InternalDictionaryDerived.h"

namespace blink {

void V8InternalDictionaryDerivedDerived::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, InternalDictionaryDerivedDerived& impl, ExceptionState& exceptionState) {
  if (isUndefinedOrNull(v8Value)) {
    return;
  }
  if (!v8Value->IsObject()) {
    exceptionState.throwTypeError("cannot convert to dictionary.");
    return;
  }

  V8InternalDictionaryDerived::toImpl(isolate, v8Value, impl, exceptionState);
  if (exceptionState.hadException())
    return;

  v8::TryCatch block(isolate);
  v8::Local<v8::Object> v8Object;
  if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  v8::Local<v8::Value> derivedDerivedStringMemberValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "derivedDerivedStringMember")).ToLocal(&derivedDerivedStringMemberValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (derivedDerivedStringMemberValue.IsEmpty() || derivedDerivedStringMemberValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> derivedDerivedStringMember = derivedDerivedStringMemberValue;
    if (!derivedDerivedStringMember.prepare(exceptionState))
      return;
    impl.setDerivedDerivedStringMember(derivedDerivedStringMember);
  }
}

v8::Local<v8::Value> InternalDictionaryDerivedDerived::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8InternalDictionaryDerivedDerived(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8InternalDictionaryDerivedDerived(const InternalDictionaryDerivedDerived& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8InternalDictionaryDerived(impl, dictionary, creationContext, isolate))
    return false;

  if (impl.hasDerivedDerivedStringMember()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "derivedDerivedStringMember"), v8String(isolate, impl.derivedDerivedStringMember()))))
      return false;
  }

  return true;
}

InternalDictionaryDerivedDerived NativeValueTraits<InternalDictionaryDerivedDerived>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  InternalDictionaryDerivedDerived impl;
  V8InternalDictionaryDerivedDerived::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

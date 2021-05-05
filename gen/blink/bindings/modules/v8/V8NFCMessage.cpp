// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8NFCMessage.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8NFCRecord.h"

namespace blink {

void V8NFCMessage::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, NFCMessage& impl, ExceptionState& exceptionState) {
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
  v8::Local<v8::Value> dataValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "data")).ToLocal(&dataValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (dataValue.IsEmpty() || dataValue->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<NFCRecord> data = toImplArray<HeapVector<NFCRecord>>(dataValue, 0, isolate, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setData(data);
  }

  v8::Local<v8::Value> urlValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "url")).ToLocal(&urlValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (urlValue.IsEmpty() || urlValue->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> url = toUSVString(isolate, urlValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setURL(url);
  }
}

v8::Local<v8::Value> NFCMessage::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8NFCMessage(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8NFCMessage(const NFCMessage& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasData()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "data"), ToV8(impl.data(), creationContext, isolate))))
      return false;
  }

  if (impl.hasURL()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "url"), v8String(isolate, impl.url()))))
      return false;
  }

  return true;
}

NFCMessage NativeValueTraits<NFCMessage>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  NFCMessage impl;
  V8NFCMessage::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

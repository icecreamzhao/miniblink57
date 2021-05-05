// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format off
#include "V8MediaElementAudioSourceOptions.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8HTMLMediaElement.h"

namespace blink {

void V8MediaElementAudioSourceOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, MediaElementAudioSourceOptions& impl, ExceptionState& exceptionState) {
  if (isUndefinedOrNull(v8Value)) {
    exceptionState.throwTypeError("Missing required member(s): mediaElement.");
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
  v8::Local<v8::Value> mediaElementValue;
  if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "mediaElement")).ToLocal(&mediaElementValue)) {
    exceptionState.rethrowV8Exception(block.Exception());
    return;
  }
  if (mediaElementValue.IsEmpty() || mediaElementValue->IsUndefined()) {
    exceptionState.throwTypeError("required member mediaElement is undefined.");
    return;
  } else {
    HTMLMediaElement* mediaElement = V8HTMLMediaElement::toImplWithTypeCheck(isolate, mediaElementValue);
    if (!mediaElement) {
      exceptionState.throwTypeError("member mediaElement is not of type HTMLMediaElement.");
      return;
    }
    impl.setMediaElement(mediaElement);
  }
}

v8::Local<v8::Value> MediaElementAudioSourceOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8MediaElementAudioSourceOptions(*this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8MediaElementAudioSourceOptions(const MediaElementAudioSourceOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (impl.hasMediaElement()) {
    if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "mediaElement"), ToV8(impl.mediaElement(), creationContext, isolate))))
      return false;
  } else {
    NOTREACHED();
  }

  return true;
}

MediaElementAudioSourceOptions NativeValueTraits<MediaElementAudioSourceOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  MediaElementAudioSourceOptions impl;
  V8MediaElementAudioSourceOptions::toImpl(isolate, value, impl, exceptionState);
  return impl;
}

}  // namespace blink

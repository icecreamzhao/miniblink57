// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8MediaStreamEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8EventInit.h"
#include "bindings/modules/v8/V8MediaStream.h"

namespace blink {

void V8MediaStreamEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, MediaStreamEventInit& impl, ExceptionState& exceptionState)
{
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
    v8::Local<v8::Value> streamValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "stream")).ToLocal(&streamValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (streamValue.IsEmpty() || streamValue->IsUndefined()) {
        // Do nothing.
    } else if (streamValue->IsNull()) {
        impl.setStreamToNull();
    } else {
        MediaStream* stream = V8MediaStream::toImplWithTypeCheck(isolate, streamValue);
        if (!stream) {
            exceptionState.throwTypeError("member stream is not of type MediaStream.");
            return;
        }
        impl.setStream(stream);
    }
}

v8::Local<v8::Value> MediaStreamEventInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8MediaStreamEventInit(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8MediaStreamEventInit(const MediaStreamEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!toV8EventInit(impl, dictionary, creationContext, isolate))
        return false;

    if (impl.hasStream()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "stream"), ToV8(impl.stream(), creationContext, isolate))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "stream"), v8::Null(isolate))))
            return false;
    }

    return true;
}

MediaStreamEventInit NativeValueTraits<MediaStreamEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    MediaStreamEventInit impl;
    V8MediaStreamEventInit::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

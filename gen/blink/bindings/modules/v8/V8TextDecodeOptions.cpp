// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8TextDecodeOptions.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8TextDecodeOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, TextDecodeOptions& impl, ExceptionState& exceptionState)
{
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
    v8::Local<v8::Value> streamValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "stream")).ToLocal(&streamValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (streamValue.IsEmpty() || streamValue->IsUndefined()) {
        // Do nothing.
    } else {
        bool stream = toBoolean(isolate, streamValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setStream(stream);
    }
}

v8::Local<v8::Value> TextDecodeOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8TextDecodeOptions(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8TextDecodeOptions(const TextDecodeOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasStream()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "stream"), v8Boolean(impl.stream(), isolate))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "stream"), v8Boolean(false, isolate))))
            return false;
    }

    return true;
}

TextDecodeOptions NativeValueTraits<TextDecodeOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    TextDecodeOptions impl;
    V8TextDecodeOptions::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

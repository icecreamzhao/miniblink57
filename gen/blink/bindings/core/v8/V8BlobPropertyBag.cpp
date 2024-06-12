// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8BlobPropertyBag.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8BlobPropertyBag::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, BlobPropertyBag& impl, ExceptionState& exceptionState)
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
    v8::Local<v8::Value> endingsValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "endings")).ToLocal(&endingsValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (endingsValue.IsEmpty() || endingsValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> endings = endingsValue;
        if (!endings.prepare(exceptionState))
            return;
        const char* validValues[] = {
            "transparent",
            "native",
        };
        if (!isValidEnum(endings, validValues, WTF_ARRAY_LENGTH(validValues), "NormalizeLineEndings", exceptionState))
            return;
        impl.setEndings(endings);
    }

    v8::Local<v8::Value> typeValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "type")).ToLocal(&typeValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (typeValue.IsEmpty() || typeValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> type = typeValue;
        if (!type.prepare(exceptionState))
            return;
        impl.setType(type);
    }
}

v8::Local<v8::Value> BlobPropertyBag::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8BlobPropertyBag(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8BlobPropertyBag(const BlobPropertyBag& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasEndings()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "endings"), v8String(isolate, impl.endings()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "endings"), v8String(isolate, String("transparent")))))
            return false;
    }

    if (impl.hasType()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "type"), v8String(isolate, impl.type()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "type"), v8String(isolate, String("")))))
            return false;
    }

    return true;
}

BlobPropertyBag NativeValueTraits<BlobPropertyBag>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    BlobPropertyBag impl;
    V8BlobPropertyBag::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

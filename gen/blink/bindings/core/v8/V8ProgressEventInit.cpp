// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8ProgressEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8EventInit.h"

namespace blink {

void V8ProgressEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, ProgressEventInit& impl, ExceptionState& exceptionState)
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
    v8::Local<v8::Value> lengthComputableValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "lengthComputable")).ToLocal(&lengthComputableValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (lengthComputableValue.IsEmpty() || lengthComputableValue->IsUndefined()) {
        // Do nothing.
    } else {
        bool lengthComputable = toBoolean(isolate, lengthComputableValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setLengthComputable(lengthComputable);
    }

    v8::Local<v8::Value> loadedValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "loaded")).ToLocal(&loadedValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (loadedValue.IsEmpty() || loadedValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned long long loaded = toUInt64(isolate, loadedValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setLoaded(loaded);
    }

    v8::Local<v8::Value> totalValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "total")).ToLocal(&totalValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (totalValue.IsEmpty() || totalValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned long long total = toUInt64(isolate, totalValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setTotal(total);
    }
}

v8::Local<v8::Value> ProgressEventInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8ProgressEventInit(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8ProgressEventInit(const ProgressEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!toV8EventInit(impl, dictionary, creationContext, isolate))
        return false;

    if (impl.hasLengthComputable()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "lengthComputable"), v8Boolean(impl.lengthComputable(), isolate))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "lengthComputable"), v8Boolean(false, isolate))))
            return false;
    }

    if (impl.hasLoaded()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "loaded"), v8::Number::New(isolate, static_cast<double>(impl.loaded())))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "loaded"), v8::Number::New(isolate, static_cast<double>(0)))))
            return false;
    }

    if (impl.hasTotal()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "total"), v8::Number::New(isolate, static_cast<double>(impl.total())))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "total"), v8::Number::New(isolate, static_cast<double>(0)))))
            return false;
    }

    return true;
}

ProgressEventInit NativeValueTraits<ProgressEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    ProgressEventInit impl;
    V8ProgressEventInit::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

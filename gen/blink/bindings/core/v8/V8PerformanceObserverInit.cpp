// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8PerformanceObserverInit.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8PerformanceObserverInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, PerformanceObserverInit& impl, ExceptionState& exceptionState)
{
    if (isUndefinedOrNull(v8Value)) {
        exceptionState.throwTypeError("Missing required member(s): entryTypes.");
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
    v8::Local<v8::Value> entryTypesValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "entryTypes")).ToLocal(&entryTypesValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (entryTypesValue.IsEmpty() || entryTypesValue->IsUndefined()) {
        exceptionState.throwTypeError("required member entryTypes is undefined.");
        return;
    } else {
        Vector<String> entryTypes = toImplArray<Vector<String>>(entryTypesValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setEntryTypes(entryTypes);
    }
}

v8::Local<v8::Value> PerformanceObserverInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8PerformanceObserverInit(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8PerformanceObserverInit(const PerformanceObserverInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasEntryTypes()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "entryTypes"), ToV8(impl.entryTypes(), creationContext, isolate))))
            return false;
    } else {
        NOTREACHED();
    }

    return true;
}

PerformanceObserverInit NativeValueTraits<PerformanceObserverInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    PerformanceObserverInit impl;
    V8PerformanceObserverInit::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

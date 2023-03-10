// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8WaveShaperOptions.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8AudioNodeOptions.h"

namespace blink {

void V8WaveShaperOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, WaveShaperOptions& impl, ExceptionState& exceptionState)
{
    if (isUndefinedOrNull(v8Value)) {
        return;
    }
    if (!v8Value->IsObject()) {
        exceptionState.throwTypeError("cannot convert to dictionary.");
        return;
    }

    V8AudioNodeOptions::toImpl(isolate, v8Value, impl, exceptionState);
    if (exceptionState.hadException())
        return;

    v8::TryCatch block(isolate);
    v8::Local<v8::Object> v8Object;
    if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    v8::Local<v8::Value> curveValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "curve")).ToLocal(&curveValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (curveValue.IsEmpty() || curveValue->IsUndefined()) {
        // Do nothing.
    } else {
        Vector<float> curve = toImplArray<Vector<float>>(curveValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setCurve(curve);
    }

    v8::Local<v8::Value> oversampleValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "oversample")).ToLocal(&oversampleValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (oversampleValue.IsEmpty() || oversampleValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> oversample = oversampleValue;
        if (!oversample.prepare(exceptionState))
            return;
        const char* validValues[] = {
            "none",
            "2x",
            "4x",
        };
        if (!isValidEnum(oversample, validValues, WTF_ARRAY_LENGTH(validValues), "OverSampleType", exceptionState))
            return;
        impl.setOversample(oversample);
    }
}

v8::Local<v8::Value> WaveShaperOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8WaveShaperOptions(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8WaveShaperOptions(const WaveShaperOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!toV8AudioNodeOptions(impl, dictionary, creationContext, isolate))
        return false;

    if (impl.hasCurve()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "curve"), ToV8(impl.curve(), creationContext, isolate))))
            return false;
    }

    if (impl.hasOversample()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "oversample"), v8String(isolate, impl.oversample()))))
            return false;
    }

    return true;
}

WaveShaperOptions NativeValueTraits<WaveShaperOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    WaveShaperOptions impl;
    V8WaveShaperOptions::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

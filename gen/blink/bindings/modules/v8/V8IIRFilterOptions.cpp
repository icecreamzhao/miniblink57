// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8IIRFilterOptions.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8AudioNodeOptions.h"

namespace blink {

void V8IIRFilterOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, IIRFilterOptions& impl, ExceptionState& exceptionState)
{
    if (isUndefinedOrNull(v8Value)) {
        exceptionState.throwTypeError("Missing required member(s): feedback, feedforward.");
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
    v8::Local<v8::Value> feedbackValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "feedback")).ToLocal(&feedbackValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (feedbackValue.IsEmpty() || feedbackValue->IsUndefined()) {
        exceptionState.throwTypeError("required member feedback is undefined.");
        return;
    } else {
        Vector<double> feedback = toImplArray<Vector<double>>(feedbackValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setFeedback(feedback);
    }

    v8::Local<v8::Value> feedforwardValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "feedforward")).ToLocal(&feedforwardValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (feedforwardValue.IsEmpty() || feedforwardValue->IsUndefined()) {
        exceptionState.throwTypeError("required member feedforward is undefined.");
        return;
    } else {
        Vector<double> feedforward = toImplArray<Vector<double>>(feedforwardValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setFeedforward(feedforward);
    }
}

v8::Local<v8::Value> IIRFilterOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8IIRFilterOptions(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8IIRFilterOptions(const IIRFilterOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!toV8AudioNodeOptions(impl, dictionary, creationContext, isolate))
        return false;

    if (impl.hasFeedback()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "feedback"), ToV8(impl.feedback(), creationContext, isolate))))
            return false;
    } else {
        NOTREACHED();
    }

    if (impl.hasFeedforward()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "feedforward"), ToV8(impl.feedforward(), creationContext, isolate))))
            return false;
    } else {
        NOTREACHED();
    }

    return true;
}

IIRFilterOptions NativeValueTraits<IIRFilterOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    IIRFilterOptions impl;
    V8IIRFilterOptions::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

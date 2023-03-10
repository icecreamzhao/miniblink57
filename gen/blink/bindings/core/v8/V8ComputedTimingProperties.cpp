// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8ComputedTimingProperties.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8AnimationEffectTimingProperties.h"

namespace blink {

void V8ComputedTimingProperties::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, ComputedTimingProperties& impl, ExceptionState& exceptionState)
{
    if (isUndefinedOrNull(v8Value)) {
        return;
    }
    if (!v8Value->IsObject()) {
        exceptionState.throwTypeError("cannot convert to dictionary.");
        return;
    }

    V8AnimationEffectTimingProperties::toImpl(isolate, v8Value, impl, exceptionState);
    if (exceptionState.hadException())
        return;

    v8::TryCatch block(isolate);
    v8::Local<v8::Object> v8Object;
    if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    v8::Local<v8::Value> activeDurationValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "activeDuration")).ToLocal(&activeDurationValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (activeDurationValue.IsEmpty() || activeDurationValue->IsUndefined()) {
        // Do nothing.
    } else {
        double activeDuration = toDouble(isolate, activeDurationValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setActiveDuration(activeDuration);
    }

    v8::Local<v8::Value> currentIterationValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "currentIteration")).ToLocal(&currentIterationValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (currentIterationValue.IsEmpty() || currentIterationValue->IsUndefined()) {
        // Do nothing.
    } else if (currentIterationValue->IsNull()) {
        impl.setCurrentIterationToNull();
    } else {
        double currentIteration = toDouble(isolate, currentIterationValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setCurrentIteration(currentIteration);
    }

    v8::Local<v8::Value> endTimeValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "endTime")).ToLocal(&endTimeValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (endTimeValue.IsEmpty() || endTimeValue->IsUndefined()) {
        // Do nothing.
    } else {
        double endTime = toDouble(isolate, endTimeValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setEndTime(endTime);
    }

    v8::Local<v8::Value> localTimeValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "localTime")).ToLocal(&localTimeValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (localTimeValue.IsEmpty() || localTimeValue->IsUndefined()) {
        // Do nothing.
    } else if (localTimeValue->IsNull()) {
        impl.setLocalTimeToNull();
    } else {
        double localTime = toRestrictedDouble(isolate, localTimeValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setLocalTime(localTime);
    }

    v8::Local<v8::Value> progressValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "progress")).ToLocal(&progressValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (progressValue.IsEmpty() || progressValue->IsUndefined()) {
        // Do nothing.
    } else if (progressValue->IsNull()) {
        impl.setProgressToNull();
    } else {
        double progress = toRestrictedDouble(isolate, progressValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setProgress(progress);
    }
}

v8::Local<v8::Value> ComputedTimingProperties::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8ComputedTimingProperties(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8ComputedTimingProperties(const ComputedTimingProperties& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!toV8AnimationEffectTimingProperties(impl, dictionary, creationContext, isolate))
        return false;

    if (impl.hasActiveDuration()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "activeDuration"), v8::Number::New(isolate, impl.activeDuration()))))
            return false;
    }

    if (impl.hasCurrentIteration()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "currentIteration"), v8::Number::New(isolate, impl.currentIteration()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "currentIteration"), v8::Null(isolate))))
            return false;
    }

    if (impl.hasEndTime()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "endTime"), v8::Number::New(isolate, impl.endTime()))))
            return false;
    }

    if (impl.hasLocalTime()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "localTime"), v8::Number::New(isolate, impl.localTime()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "localTime"), v8::Null(isolate))))
            return false;
    }

    if (impl.hasProgress()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "progress"), v8::Number::New(isolate, impl.progress()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "progress"), v8::Null(isolate))))
            return false;
    }

    return true;
}

ComputedTimingProperties NativeValueTraits<ComputedTimingProperties>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    ComputedTimingProperties impl;
    V8ComputedTimingProperties::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

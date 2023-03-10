// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8MouseEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8EventModifierInit.h"
#include "bindings/core/v8/V8EventTarget.h"

namespace blink {

void V8MouseEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, MouseEventInit& impl, ExceptionState& exceptionState)
{
    if (isUndefinedOrNull(v8Value)) {
        return;
    }
    if (!v8Value->IsObject()) {
        exceptionState.throwTypeError("cannot convert to dictionary.");
        return;
    }

    V8EventModifierInit::toImpl(isolate, v8Value, impl, exceptionState);
    if (exceptionState.hadException())
        return;

    v8::TryCatch block(isolate);
    v8::Local<v8::Object> v8Object;
    if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    v8::Local<v8::Value> buttonValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "button")).ToLocal(&buttonValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (buttonValue.IsEmpty() || buttonValue->IsUndefined()) {
        // Do nothing.
    } else {
        int button = toInt16(isolate, buttonValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setButton(button);
    }

    v8::Local<v8::Value> buttonsValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "buttons")).ToLocal(&buttonsValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (buttonsValue.IsEmpty() || buttonsValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned buttons = toUInt16(isolate, buttonsValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setButtons(buttons);
    }

    v8::Local<v8::Value> clientXValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "clientX")).ToLocal(&clientXValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (clientXValue.IsEmpty() || clientXValue->IsUndefined()) {
        // Do nothing.
    } else {
        double clientX = toRestrictedDouble(isolate, clientXValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setClientX(clientX);
    }

    v8::Local<v8::Value> clientYValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "clientY")).ToLocal(&clientYValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (clientYValue.IsEmpty() || clientYValue->IsUndefined()) {
        // Do nothing.
    } else {
        double clientY = toRestrictedDouble(isolate, clientYValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setClientY(clientY);
    }

    v8::Local<v8::Value> movementXValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "movementX")).ToLocal(&movementXValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (movementXValue.IsEmpty() || movementXValue->IsUndefined()) {
        // Do nothing.
    } else {
        int movementX = toInt32(isolate, movementXValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setMovementX(movementX);
    }

    v8::Local<v8::Value> movementYValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "movementY")).ToLocal(&movementYValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (movementYValue.IsEmpty() || movementYValue->IsUndefined()) {
        // Do nothing.
    } else {
        int movementY = toInt32(isolate, movementYValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setMovementY(movementY);
    }

    v8::Local<v8::Value> regionValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "region")).ToLocal(&regionValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (regionValue.IsEmpty() || regionValue->IsUndefined()) {
        // Do nothing.
    } else if (regionValue->IsNull()) {
        impl.setRegionToNull();
    } else {
        V8StringResource<> region = regionValue;
        if (!region.prepare(exceptionState))
            return;
        impl.setRegion(region);
    }

    v8::Local<v8::Value> relatedTargetValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "relatedTarget")).ToLocal(&relatedTargetValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (relatedTargetValue.IsEmpty() || relatedTargetValue->IsUndefined()) {
        // Do nothing.
    } else if (relatedTargetValue->IsNull()) {
        impl.setRelatedTargetToNull();
    } else {
        EventTarget* relatedTarget = toEventTarget(isolate, relatedTargetValue);
        if (!relatedTarget) {
            exceptionState.throwTypeError("member relatedTarget is not of type EventTarget.");
            return;
        }
        impl.setRelatedTarget(relatedTarget);
    }

    v8::Local<v8::Value> screenXValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "screenX")).ToLocal(&screenXValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (screenXValue.IsEmpty() || screenXValue->IsUndefined()) {
        // Do nothing.
    } else {
        double screenX = toRestrictedDouble(isolate, screenXValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setScreenX(screenX);
    }

    v8::Local<v8::Value> screenYValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "screenY")).ToLocal(&screenYValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (screenYValue.IsEmpty() || screenYValue->IsUndefined()) {
        // Do nothing.
    } else {
        double screenY = toRestrictedDouble(isolate, screenYValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setScreenY(screenY);
    }
}

v8::Local<v8::Value> MouseEventInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8MouseEventInit(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8MouseEventInit(const MouseEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!toV8EventModifierInit(impl, dictionary, creationContext, isolate))
        return false;

    if (impl.hasButton()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "button"), v8::Integer::New(isolate, impl.button()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "button"), v8::Integer::New(isolate, 0))))
            return false;
    }

    if (impl.hasButtons()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "buttons"), v8::Integer::NewFromUnsigned(isolate, impl.buttons()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "buttons"), v8::Integer::NewFromUnsigned(isolate, 0u))))
            return false;
    }

    if (impl.hasClientX()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "clientX"), v8::Number::New(isolate, impl.clientX()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "clientX"), v8::Number::New(isolate, 0))))
            return false;
    }

    if (impl.hasClientY()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "clientY"), v8::Number::New(isolate, impl.clientY()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "clientY"), v8::Number::New(isolate, 0))))
            return false;
    }

    if (impl.hasMovementX()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "movementX"), v8::Integer::New(isolate, impl.movementX()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "movementX"), v8::Integer::New(isolate, 0))))
            return false;
    }

    if (impl.hasMovementY()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "movementY"), v8::Integer::New(isolate, impl.movementY()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "movementY"), v8::Integer::New(isolate, 0))))
            return false;
    }

    if (impl.hasRegion()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "region"), v8String(isolate, impl.region()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "region"), v8::Null(isolate))))
            return false;
    }

    if (impl.hasRelatedTarget()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "relatedTarget"), ToV8(impl.relatedTarget(), creationContext, isolate))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "relatedTarget"), v8::Null(isolate))))
            return false;
    }

    if (impl.hasScreenX()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "screenX"), v8::Number::New(isolate, impl.screenX()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "screenX"), v8::Number::New(isolate, 0))))
            return false;
    }

    if (impl.hasScreenY()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "screenY"), v8::Number::New(isolate, impl.screenY()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "screenY"), v8::Number::New(isolate, 0))))
            return false;
    }

    return true;
}

MouseEventInit NativeValueTraits<MouseEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    MouseEventInit impl;
    V8MouseEventInit::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8PaymentDetails.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8PaymentDetailsModifier.h"
#include "bindings/modules/v8/V8PaymentItem.h"
#include "bindings/modules/v8/V8PaymentShippingOption.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {

void V8PaymentDetails::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, PaymentDetails& impl, ExceptionState& exceptionState)
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
    v8::Local<v8::Value> displayItemsValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "displayItems")).ToLocal(&displayItemsValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (displayItemsValue.IsEmpty() || displayItemsValue->IsUndefined()) {
        // Do nothing.
    } else {
        HeapVector<PaymentItem> displayItems = toImplArray<HeapVector<PaymentItem>>(displayItemsValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setDisplayItems(displayItems);
    }

    if (RuntimeEnabledFeatures::paymentDetailsErrorEnabled()) {
        v8::Local<v8::Value> errorValue;
        if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "error")).ToLocal(&errorValue)) {
            exceptionState.rethrowV8Exception(block.Exception());
            return;
        }
        if (errorValue.IsEmpty() || errorValue->IsUndefined()) {
            // Do nothing.
        } else {
            V8StringResource<> error = errorValue;
            if (!error.prepare(exceptionState))
                return;
            impl.setError(error);
        }
    }

    v8::Local<v8::Value> modifiersValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "modifiers")).ToLocal(&modifiersValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (modifiersValue.IsEmpty() || modifiersValue->IsUndefined()) {
        // Do nothing.
    } else {
        HeapVector<PaymentDetailsModifier> modifiers = toImplArray<HeapVector<PaymentDetailsModifier>>(modifiersValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setModifiers(modifiers);
    }

    v8::Local<v8::Value> shippingOptionsValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "shippingOptions")).ToLocal(&shippingOptionsValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (shippingOptionsValue.IsEmpty() || shippingOptionsValue->IsUndefined()) {
        // Do nothing.
    } else {
        HeapVector<PaymentShippingOption> shippingOptions = toImplArray<HeapVector<PaymentShippingOption>>(shippingOptionsValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setShippingOptions(shippingOptions);
    }

    v8::Local<v8::Value> totalValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "total")).ToLocal(&totalValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (totalValue.IsEmpty() || totalValue->IsUndefined()) {
        // Do nothing.
    } else {
        PaymentItem total;
        V8PaymentItem::toImpl(isolate, totalValue, total, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setTotal(total);
    }
}

v8::Local<v8::Value> PaymentDetails::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8PaymentDetails(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8PaymentDetails(const PaymentDetails& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasDisplayItems()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "displayItems"), ToV8(impl.displayItems(), creationContext, isolate))))
            return false;
    }

    if (impl.hasError()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "error"), v8String(isolate, impl.error()))))
            return false;
    }

    if (impl.hasModifiers()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "modifiers"), ToV8(impl.modifiers(), creationContext, isolate))))
            return false;
    }

    if (impl.hasShippingOptions()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "shippingOptions"), ToV8(impl.shippingOptions(), creationContext, isolate))))
            return false;
    }

    if (impl.hasTotal()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "total"), ToV8(impl.total(), creationContext, isolate))))
            return false;
    }

    return true;
}

PaymentDetails NativeValueTraits<PaymentDetails>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    PaymentDetails impl;
    V8PaymentDetails::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8RequestDeviceOptions.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8BluetoothScanFilterInit.h"

namespace blink {

void V8RequestDeviceOptions::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, RequestDeviceOptions& impl, ExceptionState& exceptionState)
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
    v8::Local<v8::Value> acceptAllDevicesValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "acceptAllDevices")).ToLocal(&acceptAllDevicesValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (acceptAllDevicesValue.IsEmpty() || acceptAllDevicesValue->IsUndefined()) {
        // Do nothing.
    } else {
        bool acceptAllDevices = toBoolean(isolate, acceptAllDevicesValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setAcceptAllDevices(acceptAllDevices);
    }

    v8::Local<v8::Value> filtersValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "filters")).ToLocal(&filtersValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (filtersValue.IsEmpty() || filtersValue->IsUndefined()) {
        // Do nothing.
    } else {
        HeapVector<BluetoothScanFilterInit> filters = toImplArray<HeapVector<BluetoothScanFilterInit>>(filtersValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setFilters(filters);
    }

    v8::Local<v8::Value> optionalServicesValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "optionalServices")).ToLocal(&optionalServicesValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (optionalServicesValue.IsEmpty() || optionalServicesValue->IsUndefined()) {
        // Do nothing.
    } else {
        HeapVector<StringOrUnsignedLong> optionalServices = toImplArray<HeapVector<StringOrUnsignedLong>>(optionalServicesValue, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setOptionalServices(optionalServices);
    }
}

v8::Local<v8::Value> RequestDeviceOptions::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8RequestDeviceOptions(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8RequestDeviceOptions(const RequestDeviceOptions& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasAcceptAllDevices()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "acceptAllDevices"), v8Boolean(impl.acceptAllDevices(), isolate))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "acceptAllDevices"), v8Boolean(false, isolate))))
            return false;
    }

    if (impl.hasFilters()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "filters"), ToV8(impl.filters(), creationContext, isolate))))
            return false;
    }

    if (impl.hasOptionalServices()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "optionalServices"), ToV8(impl.optionalServices(), creationContext, isolate))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "optionalServices"), ToV8(HeapVector<StringOrUnsignedLong>(), creationContext, isolate))))
            return false;
    }

    return true;
}

RequestDeviceOptions NativeValueTraits<RequestDeviceOptions>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    RequestDeviceOptions impl;
    V8RequestDeviceOptions::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

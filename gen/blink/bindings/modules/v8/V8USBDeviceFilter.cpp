// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8USBDeviceFilter.h"

#include "bindings/core/v8/ExceptionState.h"

namespace blink {

void V8USBDeviceFilter::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, USBDeviceFilter& impl, ExceptionState& exceptionState)
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
    v8::Local<v8::Value> classCodeValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "classCode")).ToLocal(&classCodeValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (classCodeValue.IsEmpty() || classCodeValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned classCode = toUInt8(isolate, classCodeValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setClassCode(classCode);
    }

    v8::Local<v8::Value> productIdValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "productId")).ToLocal(&productIdValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (productIdValue.IsEmpty() || productIdValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned productId = toUInt16(isolate, productIdValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setProductId(productId);
    }

    v8::Local<v8::Value> protocolCodeValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "protocolCode")).ToLocal(&protocolCodeValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (protocolCodeValue.IsEmpty() || protocolCodeValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned protocolCode = toUInt8(isolate, protocolCodeValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setProtocolCode(protocolCode);
    }

    v8::Local<v8::Value> serialNumberValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "serialNumber")).ToLocal(&serialNumberValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (serialNumberValue.IsEmpty() || serialNumberValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> serialNumber = serialNumberValue;
        if (!serialNumber.prepare(exceptionState))
            return;
        impl.setSerialNumber(serialNumber);
    }

    v8::Local<v8::Value> subclassCodeValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "subclassCode")).ToLocal(&subclassCodeValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (subclassCodeValue.IsEmpty() || subclassCodeValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned subclassCode = toUInt8(isolate, subclassCodeValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setSubclassCode(subclassCode);
    }

    v8::Local<v8::Value> vendorIdValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "vendorId")).ToLocal(&vendorIdValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (vendorIdValue.IsEmpty() || vendorIdValue->IsUndefined()) {
        // Do nothing.
    } else {
        unsigned vendorId = toUInt16(isolate, vendorIdValue, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setVendorId(vendorId);
    }
}

v8::Local<v8::Value> USBDeviceFilter::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8USBDeviceFilter(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8USBDeviceFilter(const USBDeviceFilter& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasClassCode()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "classCode"), v8::Integer::NewFromUnsigned(isolate, impl.classCode()))))
            return false;
    }

    if (impl.hasProductId()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "productId"), v8::Integer::NewFromUnsigned(isolate, impl.productId()))))
            return false;
    }

    if (impl.hasProtocolCode()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "protocolCode"), v8::Integer::NewFromUnsigned(isolate, impl.protocolCode()))))
            return false;
    }

    if (impl.hasSerialNumber()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "serialNumber"), v8String(isolate, impl.serialNumber()))))
            return false;
    }

    if (impl.hasSubclassCode()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "subclassCode"), v8::Integer::NewFromUnsigned(isolate, impl.subclassCode()))))
            return false;
    }

    if (impl.hasVendorId()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "vendorId"), v8::Integer::NewFromUnsigned(isolate, impl.vendorId()))))
            return false;
    }

    return true;
}

USBDeviceFilter NativeValueTraits<USBDeviceFilter>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    USBDeviceFilter impl;
    V8USBDeviceFilter::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

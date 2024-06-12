// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8RTCIceServer.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/StringOrStringSequence.h"

namespace blink {

void V8RTCIceServer::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, RTCIceServer& impl, ExceptionState& exceptionState)
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
    v8::Local<v8::Value> credentialValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "credential")).ToLocal(&credentialValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (credentialValue.IsEmpty() || credentialValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> credential = credentialValue;
        if (!credential.prepare(exceptionState))
            return;
        impl.setCredential(credential);
    }

    v8::Local<v8::Value> urlValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "url")).ToLocal(&urlValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (urlValue.IsEmpty() || urlValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> url = urlValue;
        if (!url.prepare(exceptionState))
            return;
        impl.setURL(url);
    }

    v8::Local<v8::Value> urlsValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "urls")).ToLocal(&urlsValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (urlsValue.IsEmpty() || urlsValue->IsUndefined()) {
        // Do nothing.
    } else {
        StringOrStringSequence urls;
        V8StringOrStringSequence::toImpl(isolate, urlsValue, urls, UnionTypeConversionMode::NotNullable, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setURLs(urls);
    }

    v8::Local<v8::Value> usernameValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "username")).ToLocal(&usernameValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (usernameValue.IsEmpty() || usernameValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> username = usernameValue;
        if (!username.prepare(exceptionState))
            return;
        impl.setUsername(username);
    }
}

v8::Local<v8::Value> RTCIceServer::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8RTCIceServer(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8RTCIceServer(const RTCIceServer& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasCredential()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "credential"), v8String(isolate, impl.credential()))))
            return false;
    }

    if (impl.hasURL()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "url"), v8String(isolate, impl.url()))))
            return false;
    }

    if (impl.hasURLs()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "urls"), ToV8(impl.urls(), creationContext, isolate))))
            return false;
    }

    if (impl.hasUsername()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "username"), v8String(isolate, impl.username()))))
            return false;
    }

    return true;
}

RTCIceServer NativeValueTraits<RTCIceServer>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    RTCIceServer impl;
    V8RTCIceServer::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink

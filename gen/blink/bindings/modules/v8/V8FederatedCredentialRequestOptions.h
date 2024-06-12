// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.h.tmpl

// clang-format on
#ifndef V8FederatedCredentialRequestOptions_h
#define V8FederatedCredentialRequestOptions_h

#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "modules/ModulesExport.h"
#include "modules/credentialmanager/FederatedCredentialRequestOptions.h"
#include "platform/heap/Handle.h"

namespace blink {

class ExceptionState;

class V8FederatedCredentialRequestOptions {
public:
    MODULES_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, FederatedCredentialRequestOptions&, ExceptionState&);
};

MODULES_EXPORT bool toV8FederatedCredentialRequestOptions(const FederatedCredentialRequestOptions&, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, FederatedCredentialRequestOptions& impl)
{
    v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<FederatedCredentialRequestOptions> {
    static FederatedCredentialRequestOptions nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

template <>
struct V8TypeOf<FederatedCredentialRequestOptions> {
    typedef V8FederatedCredentialRequestOptions Type;
};

} // namespace blink

#endif // V8FederatedCredentialRequestOptions_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.h.tmpl

// clang-format on
#ifndef V8EventListenerOptions_h
#define V8EventListenerOptions_h

#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/CoreExport.h"
#include "core/events/EventListenerOptions.h"
#include "platform/heap/Handle.h"

namespace blink {

class ExceptionState;

class V8EventListenerOptions {
public:
    CORE_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, EventListenerOptions&, ExceptionState&);
};

CORE_EXPORT bool toV8EventListenerOptions(const EventListenerOptions&, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, EventListenerOptions& impl)
{
    v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<EventListenerOptions> {
    static EventListenerOptions nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

template <>
struct V8TypeOf<EventListenerOptions> {
    typedef V8EventListenerOptions Type;
};

} // namespace blink

#endif // V8EventListenerOptions_h

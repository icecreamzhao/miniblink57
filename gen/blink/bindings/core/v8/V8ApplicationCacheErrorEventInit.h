// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.h.tmpl

// clang-format off
#ifndef V8ApplicationCacheErrorEventInit_h
#define V8ApplicationCacheErrorEventInit_h

#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/CoreExport.h"
#include "core/events/ApplicationCacheErrorEventInit.h"
#include "platform/heap/Handle.h"

namespace blink {

class ExceptionState;

class V8ApplicationCacheErrorEventInit {
 public:
  CORE_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, ApplicationCacheErrorEventInit&, ExceptionState&);
};

CORE_EXPORT bool toV8ApplicationCacheErrorEventInit(const ApplicationCacheErrorEventInit&, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate*);

template<class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, ApplicationCacheErrorEventInit& impl) {
  v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<ApplicationCacheErrorEventInit> {
  static ApplicationCacheErrorEventInit nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

template <>
struct V8TypeOf<ApplicationCacheErrorEventInit> {
  typedef V8ApplicationCacheErrorEventInit Type;
};

}  // namespace blink

#endif  // V8ApplicationCacheErrorEventInit_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.h.tmpl

// clang-format off
#ifndef V8ResourceProgressEvent_h
#define V8ResourceProgressEvent_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8DOMWrapper.h"
#include "bindings/core/v8/V8ProgressEvent.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "core/CoreExport.h"
#include "core/events/ResourceProgressEvent.h"
#include "platform/heap/Handle.h"

namespace blink {

class V8ResourceProgressEvent {
  STATIC_ONLY(V8ResourceProgressEvent);
 public:
  CORE_EXPORT static bool hasInstance(v8::Local<v8::Value>, v8::Isolate*);
  static v8::Local<v8::Object> findInstanceInPrototypeChain(v8::Local<v8::Value>, v8::Isolate*);
  CORE_EXPORT static v8::Local<v8::FunctionTemplate> domTemplate(v8::Isolate*, const DOMWrapperWorld&);
  static ResourceProgressEvent* toImpl(v8::Local<v8::Object> object) {
    return toScriptWrappable(object)->toImpl<ResourceProgressEvent>();
  }
  CORE_EXPORT static ResourceProgressEvent* toImplWithTypeCheck(v8::Isolate*, v8::Local<v8::Value>);
  CORE_EXPORT static const WrapperTypeInfo wrapperTypeInfo;
  template<typename VisitorDispatcher>
  static void trace(VisitorDispatcher visitor, ScriptWrappable* scriptWrappable) {
    visitor->trace(scriptWrappable->toImpl<ResourceProgressEvent>());
  }
  static void traceWrappers(WrapperVisitor* visitor, ScriptWrappable* scriptWrappable) {
    visitor->traceWrappers(scriptWrappable->toImpl<ResourceProgressEvent>());
  }
  static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
};

template <>
struct V8TypeOf<ResourceProgressEvent> {
  typedef V8ResourceProgressEvent Type;
};

}  // namespace blink

#endif  // V8ResourceProgressEvent_h

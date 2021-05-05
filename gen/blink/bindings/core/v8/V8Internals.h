// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.h.tmpl

// clang-format off
#ifndef V8Internals_h
#define V8Internals_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8DOMWrapper.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "core/testing/Internals.h"
#include "platform/heap/Handle.h"

namespace blink {

class V8Internals {
  STATIC_ONLY(V8Internals);
 public:
  static bool hasInstance(v8::Local<v8::Value>, v8::Isolate*);
  static v8::Local<v8::Object> findInstanceInPrototypeChain(v8::Local<v8::Value>, v8::Isolate*);
  static v8::Local<v8::FunctionTemplate> domTemplate(v8::Isolate*, const DOMWrapperWorld&);
  static Internals* toImpl(v8::Local<v8::Object> object) {
    return toScriptWrappable(object)->toImpl<Internals>();
  }
  static Internals* toImplWithTypeCheck(v8::Isolate*, v8::Local<v8::Value>);
  static WrapperTypeInfo wrapperTypeInfo;
  template<typename VisitorDispatcher>
  static void trace(VisitorDispatcher visitor, ScriptWrappable* scriptWrappable) {
    visitor->trace(scriptWrappable->toImpl<Internals>());
  }
  static void traceWrappers(WrapperVisitor* visitor, ScriptWrappable* scriptWrappable) {
    visitor->traceWrappers(scriptWrappable->toImpl<Internals>());
  }
  static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
  static void preparePrototypeAndInterfaceObject(v8::Local<v8::Context>, const DOMWrapperWorld&, v8::Local<v8::Object> prototypeObject, v8::Local<v8::Function> interfaceObject, v8::Local<v8::FunctionTemplate> interfaceTemplate);
  static void updateWrapperTypeInfo(InstallTemplateFunction, PreparePrototypeAndInterfaceObjectFunction);
  static void installV8InternalsTemplate(v8::Isolate*, const DOMWrapperWorld&, v8::Local<v8::FunctionTemplate> interfaceTemplate);

 private:
  static InstallTemplateFunction installV8InternalsTemplateFunction;
};

template <>
struct V8TypeOf<Internals> {
  typedef V8Internals Type;
};

}  // namespace blink

#endif  // V8Internals_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.h.tmpl

// clang-format off
#ifndef V8BiquadFilterNode_h
#define V8BiquadFilterNode_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8DOMWrapper.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "bindings/modules/v8/V8AudioNode.h"
#include "modules/ModulesExport.h"
#include "modules/webaudio/BiquadFilterNode.h"
#include "platform/heap/Handle.h"

namespace blink {

class V8BiquadFilterNode {
  STATIC_ONLY(V8BiquadFilterNode);
 public:
  MODULES_EXPORT static bool hasInstance(v8::Local<v8::Value>, v8::Isolate*);
  static v8::Local<v8::Object> findInstanceInPrototypeChain(v8::Local<v8::Value>, v8::Isolate*);
  MODULES_EXPORT static v8::Local<v8::FunctionTemplate> domTemplate(v8::Isolate*, const DOMWrapperWorld&);
  static BiquadFilterNode* toImpl(v8::Local<v8::Object> object) {
    return toScriptWrappable(object)->toImpl<BiquadFilterNode>();
  }
  MODULES_EXPORT static BiquadFilterNode* toImplWithTypeCheck(v8::Isolate*, v8::Local<v8::Value>);
  MODULES_EXPORT static const WrapperTypeInfo wrapperTypeInfo;
  template<typename VisitorDispatcher>
  static void trace(VisitorDispatcher visitor, ScriptWrappable* scriptWrappable) {
    visitor->trace(scriptWrappable->toImpl<BiquadFilterNode>());
  }
  static void traceWrappers(WrapperVisitor* visitor, ScriptWrappable* scriptWrappable) {
    visitor->traceWrappers(scriptWrappable->toImpl<BiquadFilterNode>());
  }
  static void constructorCallback(const v8::FunctionCallbackInfo<v8::Value>&);
  static const int eventListenerCacheIndex = v8DefaultWrapperInternalFieldCount + 0;
  static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 1;
};

template <>
struct V8TypeOf<BiquadFilterNode> {
  typedef V8BiquadFilterNode Type;
};

}  // namespace blink

#endif  // V8BiquadFilterNode_h

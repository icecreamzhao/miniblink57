// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.h.tmpl

// clang-format off
#ifndef V8CSSFontFaceRule_h
#define V8CSSFontFaceRule_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8CSSRule.h"
#include "bindings/core/v8/V8DOMWrapper.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "core/CoreExport.h"
#include "core/css/CSSFontFaceRule.h"
#include "platform/heap/Handle.h"

namespace blink {

class V8CSSFontFaceRule {
  STATIC_ONLY(V8CSSFontFaceRule);
 public:
  CORE_EXPORT static bool hasInstance(v8::Local<v8::Value>, v8::Isolate*);
  static v8::Local<v8::Object> findInstanceInPrototypeChain(v8::Local<v8::Value>, v8::Isolate*);
  CORE_EXPORT static v8::Local<v8::FunctionTemplate> domTemplate(v8::Isolate*, const DOMWrapperWorld&);
  static CSSFontFaceRule* toImpl(v8::Local<v8::Object> object) {
    return toScriptWrappable(object)->toImpl<CSSFontFaceRule>();
  }
  CORE_EXPORT static CSSFontFaceRule* toImplWithTypeCheck(v8::Isolate*, v8::Local<v8::Value>);
  CORE_EXPORT static const WrapperTypeInfo wrapperTypeInfo;
  template<typename VisitorDispatcher>
  static void trace(VisitorDispatcher visitor, ScriptWrappable* scriptWrappable) {
    visitor->trace(scriptWrappable->toImpl<CSSFontFaceRule>());
  }
  static void traceWrappers(WrapperVisitor* visitor, ScriptWrappable* scriptWrappable) {
    visitor->traceWrappers(scriptWrappable->toImpl<CSSFontFaceRule>());
  }
  static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
};

template <>
struct V8TypeOf<CSSFontFaceRule> {
  typedef V8CSSFontFaceRule Type;
};

}  // namespace blink

#endif  // V8CSSFontFaceRule_h

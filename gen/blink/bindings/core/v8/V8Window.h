// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.h.tmpl

// clang-format off
#ifndef V8Window_h
#define V8Window_h

#include "bindings/core/v8/HTMLImageElementOrHTMLVideoElementOrHTMLCanvasElementOrBlobOrImageDataOrImageBitmapOrOffscreenCanvas.h"
#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8DOMWrapper.h"
#include "bindings/core/v8/V8EventTarget.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "core/CoreExport.h"
#include "core/frame/DOMWindow.h"
#include "platform/heap/Handle.h"

namespace blink {

class ScriptState;
class V8Window {
  STATIC_ONLY(V8Window);
 public:
  CORE_EXPORT static bool hasInstance(v8::Local<v8::Value>, v8::Isolate*);
  static v8::Local<v8::Object> findInstanceInPrototypeChain(v8::Local<v8::Value>, v8::Isolate*);
  CORE_EXPORT static v8::Local<v8::FunctionTemplate> domTemplate(v8::Isolate*, const DOMWrapperWorld&);
  CORE_EXPORT static v8::Local<v8::FunctionTemplate> domTemplateForNamedPropertiesObject(v8::Isolate*, const DOMWrapperWorld&);
  static DOMWindow* toImpl(v8::Local<v8::Object> object) {
    return toScriptWrappable(object)->toImpl<DOMWindow>();
  }
  CORE_EXPORT static DOMWindow* toImplWithTypeCheck(v8::Isolate*, v8::Local<v8::Value>);
  CORE_EXPORT static WrapperTypeInfo wrapperTypeInfo;
  template<typename VisitorDispatcher>
  static void trace(VisitorDispatcher visitor, ScriptWrappable* scriptWrappable) {
    visitor->trace(scriptWrappable->toImpl<DOMWindow>());
  }
  static void traceWrappers(WrapperVisitor* visitor, ScriptWrappable* scriptWrappable) {
    visitor->traceWrappers(scriptWrappable->toImpl<DOMWindow>());
  }
  static void openMethodCustom(const v8::FunctionCallbackInfo<v8::Value>&);
  static void postMessageMethodCustom(const v8::FunctionCallbackInfo<v8::Value>&);
  static void openerAttributeSetterCustom(v8::Local<v8::Value>, const v8::PropertyCallbackInfo<void>&);
  static void frameElementAttributeGetterCustom(const v8::FunctionCallbackInfo<v8::Value>&);
  static void eventAttributeGetterCustom(const v8::FunctionCallbackInfo<v8::Value>&);
  static void eventAttributeSetterCustom(v8::Local<v8::Value>, const v8::FunctionCallbackInfo<v8::Value>&);
  static void namedPropertyGetterCustom(const AtomicString&, const v8::PropertyCallbackInfo<v8::Value>&);
  static const int eventListenerCacheIndex = v8DefaultWrapperInternalFieldCount + 0;
  static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 1;
  CORE_EXPORT static void preparePrototypeAndInterfaceObject(v8::Local<v8::Context>, const DOMWrapperWorld&, v8::Local<v8::Object> prototypeObject, v8::Local<v8::Function> interfaceObject, v8::Local<v8::FunctionTemplate> interfaceTemplate) {}
  CORE_EXPORT static void updateWrapperTypeInfo(InstallTemplateFunction, PreparePrototypeAndInterfaceObjectFunction);
  CORE_EXPORT static void installV8WindowTemplate(v8::Isolate*, const DOMWrapperWorld&, v8::Local<v8::FunctionTemplate> interfaceTemplate);

  CORE_EXPORT static void installRuntimeEnabledFeatures(
      v8::Isolate* isolate,
      const DOMWrapperWorld& world,
      v8::Local<v8::Object> instance,
      v8::Local<v8::Object> prototype,
      v8::Local<v8::Function> interface);

  static void installLongTaskObserver(v8::Isolate*, const DOMWrapperWorld&, v8::Local<v8::Object> instance, v8::Local<v8::Object> prototype, v8::Local<v8::Function> interface);
  static void installLongTaskObserver(ScriptState*, v8::Local<v8::Object> instance);

 private:
  static InstallTemplateFunction installV8WindowTemplateFunction;
};

template <>
struct V8TypeOf<DOMWindow> {
  typedef V8Window Type;
};

}  // namespace blink

#endif  // V8Window_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8WebGLLoseContext.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8GCController.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/dom/Element.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8WebGLLoseContext::wrapperTypeInfo = { gin::kEmbedderBlink, V8WebGLLoseContext::domTemplate, V8WebGLLoseContext::trace, V8WebGLLoseContext::traceWrappers, V8WebGLLoseContext::visitDOMWrapper, nullptr, "WebGLLoseContext", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in WebGLLoseContext.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& WebGLLoseContext::s_wrapperTypeInfo = V8WebGLLoseContext::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, WebGLLoseContext>::value,
    "WebGLLoseContext inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&WebGLLoseContext::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "WebGLLoseContext is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace WebGLLoseContextV8Internal {

static void loseContextMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  WebGLLoseContext* impl = V8WebGLLoseContext::toImpl(info.Holder());

  impl->loseContext();
}

MODULES_EXPORT  void loseContextMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  WebGLLoseContextV8Internal::loseContextMethod(info);
}

static void restoreContextMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  WebGLLoseContext* impl = V8WebGLLoseContext::toImpl(info.Holder());

  impl->restoreContext();
}

MODULES_EXPORT  void restoreContextMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  WebGLLoseContextV8Internal::restoreContextMethod(info);
}

} // namespace WebGLLoseContextV8Internal

void V8WebGLLoseContext::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper) {
  WebGLLoseContext* impl = scriptWrappable->toImpl<WebGLLoseContext>();
  // The canvas() method may return a reference or a pointer.
  if (Node* owner = WTF::getPtr(impl->canvas())) {
    Node* root = V8GCController::opaqueRootForGC(isolate, owner);
    isolate->SetReferenceFromGroup(v8::UniqueId(reinterpret_cast<intptr_t>(root)), wrapper);
    return;
  }
}

const V8DOMConfiguration::MethodConfiguration V8WebGLLoseContextMethods[] = {
    {"loseContext", WebGLLoseContextV8Internal::loseContextMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"restoreContext", WebGLLoseContextV8Internal::restoreContextMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8WebGLLoseContextTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8WebGLLoseContext::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8WebGLLoseContext::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8WebGLLoseContextMethods, WTF_ARRAY_LENGTH(V8WebGLLoseContextMethods));
}

v8::Local<v8::FunctionTemplate> V8WebGLLoseContext::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8WebGLLoseContextTemplate);
}

bool V8WebGLLoseContext::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8WebGLLoseContext::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

WebGLLoseContext* V8WebGLLoseContext::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

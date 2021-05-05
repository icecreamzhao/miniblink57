// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8GarbageCollectedScriptWrappable.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8GarbageCollectedScriptWrappable::wrapperTypeInfo = { gin::kEmbedderBlink, V8GarbageCollectedScriptWrappable::domTemplate, V8GarbageCollectedScriptWrappable::trace, V8GarbageCollectedScriptWrappable::traceWrappers, 0, nullptr, "GarbageCollectedScriptWrappable", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in GarbageCollectedScriptWrappable.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& GarbageCollectedScriptWrappable::s_wrapperTypeInfo = V8GarbageCollectedScriptWrappable::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, GarbageCollectedScriptWrappable>::value,
    "GarbageCollectedScriptWrappable inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&GarbageCollectedScriptWrappable::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "GarbageCollectedScriptWrappable is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace GarbageCollectedScriptWrappableV8Internal {

static void toStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GarbageCollectedScriptWrappable* impl = V8GarbageCollectedScriptWrappable::toImpl(info.Holder());

  v8SetReturnValueString(info, impl->toString(), info.GetIsolate());
}

 void toStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GarbageCollectedScriptWrappableV8Internal::toStringMethod(info);
}

} // namespace GarbageCollectedScriptWrappableV8Internal

const V8DOMConfiguration::MethodConfiguration V8GarbageCollectedScriptWrappableMethods[] = {
    {"toString", GarbageCollectedScriptWrappableV8Internal::toStringMethodCallback, 0, 0, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8GarbageCollectedScriptWrappableTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8GarbageCollectedScriptWrappable::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8GarbageCollectedScriptWrappable::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8GarbageCollectedScriptWrappableMethods, WTF_ARRAY_LENGTH(V8GarbageCollectedScriptWrappableMethods));
}

v8::Local<v8::FunctionTemplate> V8GarbageCollectedScriptWrappable::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8GarbageCollectedScriptWrappableTemplate);
}

bool V8GarbageCollectedScriptWrappable::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8GarbageCollectedScriptWrappable::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

GarbageCollectedScriptWrappable* V8GarbageCollectedScriptWrappable::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

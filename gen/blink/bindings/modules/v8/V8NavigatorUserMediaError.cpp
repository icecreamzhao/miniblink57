// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8NavigatorUserMediaError.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/frame/UseCounter.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8NavigatorUserMediaError::wrapperTypeInfo = { gin::kEmbedderBlink, V8NavigatorUserMediaError::domTemplate, V8NavigatorUserMediaError::trace, V8NavigatorUserMediaError::traceWrappers, 0, nullptr, "NavigatorUserMediaError", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in NavigatorUserMediaError.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& NavigatorUserMediaError::s_wrapperTypeInfo = V8NavigatorUserMediaError::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, NavigatorUserMediaError>::value,
    "NavigatorUserMediaError inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&NavigatorUserMediaError::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "NavigatorUserMediaError is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace NavigatorUserMediaErrorV8Internal {

static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NavigatorUserMediaError* impl = V8NavigatorUserMediaError::toImpl(holder);

  v8SetReturnValueString(info, impl->name(), info.GetIsolate());
}

MODULES_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NavigatorUserMediaErrorV8Internal::nameAttributeGetter(info);
}

static void messageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NavigatorUserMediaError* impl = V8NavigatorUserMediaError::toImpl(holder);

  v8SetReturnValueString(info, impl->message(), info.GetIsolate());
}

MODULES_EXPORT void messageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NavigatorUserMediaErrorV8Internal::messageAttributeGetter(info);
}

static void constraintNameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NavigatorUserMediaError* impl = V8NavigatorUserMediaError::toImpl(holder);

  v8SetReturnValueString(info, impl->constraintName(), info.GetIsolate());
}

MODULES_EXPORT void constraintNameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8NavigatorUserMediaError_ConstraintName_AttributeGetter);

  NavigatorUserMediaErrorV8Internal::constraintNameAttributeGetter(info);
}

} // namespace NavigatorUserMediaErrorV8Internal

const V8DOMConfiguration::AccessorConfiguration V8NavigatorUserMediaErrorAccessors[] = {
    {"name", NavigatorUserMediaErrorV8Internal::nameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"message", NavigatorUserMediaErrorV8Internal::messageAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"constraintName", NavigatorUserMediaErrorV8Internal::constraintNameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8NavigatorUserMediaErrorTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8NavigatorUserMediaError::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8NavigatorUserMediaError::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8NavigatorUserMediaErrorAccessors, WTF_ARRAY_LENGTH(V8NavigatorUserMediaErrorAccessors));
}

v8::Local<v8::FunctionTemplate> V8NavigatorUserMediaError::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8NavigatorUserMediaErrorTemplate);
}

bool V8NavigatorUserMediaError::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8NavigatorUserMediaError::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

NavigatorUserMediaError* V8NavigatorUserMediaError::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

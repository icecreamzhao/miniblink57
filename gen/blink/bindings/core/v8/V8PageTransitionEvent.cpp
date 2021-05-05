// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8PageTransitionEvent.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8PageTransitionEventInit.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8PageTransitionEvent::wrapperTypeInfo = { gin::kEmbedderBlink, V8PageTransitionEvent::domTemplate, V8PageTransitionEvent::trace, V8PageTransitionEvent::traceWrappers, 0, nullptr, "PageTransitionEvent", &V8Event::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in PageTransitionEvent.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& PageTransitionEvent::s_wrapperTypeInfo = V8PageTransitionEvent::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, PageTransitionEvent>::value,
    "PageTransitionEvent inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&PageTransitionEvent::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "PageTransitionEvent is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace PageTransitionEventV8Internal {

static void persistedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PageTransitionEvent* impl = V8PageTransitionEvent::toImpl(holder);

  v8SetReturnValueBool(info, impl->persisted());
}

CORE_EXPORT void persistedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PageTransitionEventV8Internal::persistedAttributeGetter(info);
}

static void isTrustedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PageTransitionEvent* impl = V8PageTransitionEvent::toImpl(holder);

  v8SetReturnValueBool(info, impl->isTrusted());
}

CORE_EXPORT void isTrustedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PageTransitionEventV8Internal::isTrustedAttributeGetter(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "PageTransitionEvent");

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> type;
  PageTransitionEventInit eventInitDict;
  type = info[0];
  if (!type.prepare())
    return;

  if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
    exceptionState.throwTypeError("parameter 2 ('eventInitDict') is not an object.");

    return;
  }
  V8PageTransitionEventInit::toImpl(info.GetIsolate(), info[1], eventInitDict, exceptionState);
  if (exceptionState.hadException())
    return;

  PageTransitionEvent* impl = PageTransitionEvent::create(type, eventInitDict);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8PageTransitionEvent::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace PageTransitionEventV8Internal

const V8DOMConfiguration::AccessorConfiguration V8PageTransitionEventAccessors[] = {
    {"persisted", PageTransitionEventV8Internal::persistedAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"isTrusted", PageTransitionEventV8Internal::isTrustedAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::DontDelete | v8::ReadOnly), V8DOMConfiguration::OnInstance, V8DOMConfiguration::CheckHolder},
};

void V8PageTransitionEvent::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("PageTransitionEvent"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  PageTransitionEventV8Internal::constructor(info);
}

static void installV8PageTransitionEventTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8PageTransitionEvent::wrapperTypeInfo.interfaceName, V8Event::domTemplate(isolate, world), V8PageTransitionEvent::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8PageTransitionEvent::constructorCallback);
  interfaceTemplate->SetLength(1);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PageTransitionEventAccessors, WTF_ARRAY_LENGTH(V8PageTransitionEventAccessors));
}

v8::Local<v8::FunctionTemplate> V8PageTransitionEvent::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8PageTransitionEventTemplate);
}

bool V8PageTransitionEvent::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8PageTransitionEvent::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

PageTransitionEvent* V8PageTransitionEvent::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

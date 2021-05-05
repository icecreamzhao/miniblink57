// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8PromiseRejectionEvent.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8PromiseRejectionEventInit.h"
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
const WrapperTypeInfo V8PromiseRejectionEvent::wrapperTypeInfo = { gin::kEmbedderBlink, V8PromiseRejectionEvent::domTemplate, V8PromiseRejectionEvent::trace, V8PromiseRejectionEvent::traceWrappers, V8PromiseRejectionEvent::visitDOMWrapper, nullptr, "PromiseRejectionEvent", &V8Event::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in PromiseRejectionEvent.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& PromiseRejectionEvent::s_wrapperTypeInfo = V8PromiseRejectionEvent::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, PromiseRejectionEvent>::value,
    "PromiseRejectionEvent inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&PromiseRejectionEvent::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "PromiseRejectionEvent is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace PromiseRejectionEventV8Internal {

CORE_EXPORT void promiseAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  V8PromiseRejectionEvent::promiseAttributeGetterCustom(info);
}

static void reasonAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PromiseRejectionEvent* impl = V8PromiseRejectionEvent::toImpl(holder);

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  v8SetReturnValue(info, impl->reason(scriptState).v8Value());
}

CORE_EXPORT void reasonAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PromiseRejectionEventV8Internal::reasonAttributeGetter(info);
}

static void isTrustedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PromiseRejectionEvent* impl = V8PromiseRejectionEvent::toImpl(holder);

  v8SetReturnValueBool(info, impl->isTrusted());
}

CORE_EXPORT void isTrustedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PromiseRejectionEventV8Internal::isTrustedAttributeGetter(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "PromiseRejectionEvent");
  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  V8StringResource<> type;
  PromiseRejectionEventInit eventInitDict;
  type = info[0];
  if (!type.prepare())
    return;

  if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
    exceptionState.throwTypeError("parameter 2 ('eventInitDict') is not an object.");

    return;
  }
  V8PromiseRejectionEventInit::toImpl(info.GetIsolate(), info[1], eventInitDict, exceptionState);
  if (exceptionState.hadException())
    return;

  PromiseRejectionEvent* impl = PromiseRejectionEvent::create(scriptState, type, eventInitDict);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8PromiseRejectionEvent::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace PromiseRejectionEventV8Internal

void V8PromiseRejectionEvent::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper) {
  V8PromiseRejectionEvent::visitDOMWrapperCustom(isolate, scriptWrappable, wrapper);
}

const V8DOMConfiguration::AccessorConfiguration V8PromiseRejectionEventAccessors[] = {
    {"promise", PromiseRejectionEventV8Internal::promiseAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"reason", PromiseRejectionEventV8Internal::reasonAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"isTrusted", PromiseRejectionEventV8Internal::isTrustedAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::DontDelete | v8::ReadOnly), V8DOMConfiguration::OnInstance, V8DOMConfiguration::CheckHolder},
};

void V8PromiseRejectionEvent::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("PromiseRejectionEvent"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  PromiseRejectionEventV8Internal::constructor(info);
}

static void installV8PromiseRejectionEventTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8PromiseRejectionEvent::wrapperTypeInfo.interfaceName, V8Event::domTemplate(isolate, world), V8PromiseRejectionEvent::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8PromiseRejectionEvent::constructorCallback);
  interfaceTemplate->SetLength(2);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PromiseRejectionEventAccessors, WTF_ARRAY_LENGTH(V8PromiseRejectionEventAccessors));
}

v8::Local<v8::FunctionTemplate> V8PromiseRejectionEvent::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8PromiseRejectionEventTemplate);
}

bool V8PromiseRejectionEvent::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8PromiseRejectionEvent::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

PromiseRejectionEvent* V8PromiseRejectionEvent::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8MediaQueryListEvent.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8MediaQueryListEventInit.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
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
const WrapperTypeInfo V8MediaQueryListEvent::wrapperTypeInfo = { gin::kEmbedderBlink, V8MediaQueryListEvent::domTemplate, V8MediaQueryListEvent::trace, V8MediaQueryListEvent::traceWrappers, 0, nullptr, "MediaQueryListEvent", &V8Event::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in MediaQueryListEvent.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& MediaQueryListEvent::s_wrapperTypeInfo = V8MediaQueryListEvent::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, MediaQueryListEvent>::value,
    "MediaQueryListEvent inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&MediaQueryListEvent::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "MediaQueryListEvent is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace MediaQueryListEventV8Internal {

static void mediaAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MediaQueryListEvent* impl = V8MediaQueryListEvent::toImpl(holder);

  v8SetReturnValueString(info, impl->media(), info.GetIsolate());
}

CORE_EXPORT void mediaAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  MediaQueryListEventV8Internal::mediaAttributeGetter(info);
}

static void matchesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MediaQueryListEvent* impl = V8MediaQueryListEvent::toImpl(holder);

  v8SetReturnValueBool(info, impl->matches());
}

CORE_EXPORT void matchesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  MediaQueryListEventV8Internal::matchesAttributeGetter(info);
}

static void isTrustedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MediaQueryListEvent* impl = V8MediaQueryListEvent::toImpl(holder);

  v8SetReturnValueBool(info, impl->isTrusted());
}

CORE_EXPORT void isTrustedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  MediaQueryListEventV8Internal::isTrustedAttributeGetter(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "MediaQueryListEvent");

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> type;
  MediaQueryListEventInit eventInitDict;
  type = info[0];
  if (!type.prepare())
    return;

  if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
    exceptionState.throwTypeError("parameter 2 ('eventInitDict') is not an object.");

    return;
  }
  V8MediaQueryListEventInit::toImpl(info.GetIsolate(), info[1], eventInitDict, exceptionState);
  if (exceptionState.hadException())
    return;

  MediaQueryListEvent* impl = MediaQueryListEvent::create(type, eventInitDict);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8MediaQueryListEvent::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace MediaQueryListEventV8Internal

const V8DOMConfiguration::AccessorConfiguration V8MediaQueryListEventAccessors[] = {
    {"media", MediaQueryListEventV8Internal::mediaAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"matches", MediaQueryListEventV8Internal::matchesAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"isTrusted", MediaQueryListEventV8Internal::isTrustedAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::DontDelete | v8::ReadOnly), V8DOMConfiguration::OnInstance, V8DOMConfiguration::CheckHolder},
};

void V8MediaQueryListEvent::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("MediaQueryListEvent"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  MediaQueryListEventV8Internal::constructor(info);
}

static void installV8MediaQueryListEventTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8MediaQueryListEvent::wrapperTypeInfo.interfaceName, V8Event::domTemplate(isolate, world), V8MediaQueryListEvent::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8MediaQueryListEvent::constructorCallback);
  interfaceTemplate->SetLength(1);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8MediaQueryListEventAccessors, WTF_ARRAY_LENGTH(V8MediaQueryListEventAccessors));
}

v8::Local<v8::FunctionTemplate> V8MediaQueryListEvent::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8MediaQueryListEventTemplate);
}

bool V8MediaQueryListEvent::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8MediaQueryListEvent::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

MediaQueryListEvent* V8MediaQueryListEvent::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8PerformanceNavigationTiming.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/inspector/ConsoleMessage.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8PerformanceNavigationTiming::wrapperTypeInfo = { gin::kEmbedderBlink, V8PerformanceNavigationTiming::domTemplate, V8PerformanceNavigationTiming::trace, V8PerformanceNavigationTiming::traceWrappers, 0, nullptr, "PerformanceNavigationTiming", &V8PerformanceResourceTiming::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in PerformanceNavigationTiming.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& PerformanceNavigationTiming::s_wrapperTypeInfo = V8PerformanceNavigationTiming::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, PerformanceNavigationTiming>::value,
    "PerformanceNavigationTiming inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&PerformanceNavigationTiming::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "PerformanceNavigationTiming is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace PerformanceNavigationTimingV8Internal {

static void unloadEventStartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->unloadEventStart());
}

CORE_EXPORT void unloadEventStartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::unloadEventStartAttributeGetter(info);
}

static void unloadEventEndAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->unloadEventEnd());
}

CORE_EXPORT void unloadEventEndAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::unloadEventEndAttributeGetter(info);
}

static void domInteractiveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->domInteractive());
}

CORE_EXPORT void domInteractiveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::domInteractiveAttributeGetter(info);
}

static void domContentLoadedEventStartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->domContentLoadedEventStart());
}

CORE_EXPORT void domContentLoadedEventStartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::domContentLoadedEventStartAttributeGetter(info);
}

static void domContentLoadedEventEndAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->domContentLoadedEventEnd());
}

CORE_EXPORT void domContentLoadedEventEndAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::domContentLoadedEventEndAttributeGetter(info);
}

static void domCompleteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->domComplete());
}

CORE_EXPORT void domCompleteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::domCompleteAttributeGetter(info);
}

static void loadEventStartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->loadEventStart());
}

CORE_EXPORT void loadEventStartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::loadEventStartAttributeGetter(info);
}

static void loadEventEndAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValue(info, impl->loadEventEnd());
}

CORE_EXPORT void loadEventEndAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::loadEventEndAttributeGetter(info);
}

static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValueString(info, impl->type(), info.GetIsolate());
}

CORE_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::typeAttributeGetter(info);
}

static void redirectCountAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->redirectCount());
}

CORE_EXPORT void redirectCountAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::redirectCountAttributeGetter(info);
}

static void toJSONMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTiming* impl = V8PerformanceNavigationTiming::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  ScriptValue result = impl->toJSONForBinding(scriptState);
  v8SetReturnValue(info, result.v8Value());
}

CORE_EXPORT  void toJSONMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceNavigationTimingV8Internal::toJSONMethod(info);
}

} // namespace PerformanceNavigationTimingV8Internal

const V8DOMConfiguration::AccessorConfiguration V8PerformanceNavigationTimingAccessors[] = {
    {"unloadEventStart", PerformanceNavigationTimingV8Internal::unloadEventStartAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"unloadEventEnd", PerformanceNavigationTimingV8Internal::unloadEventEndAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"domInteractive", PerformanceNavigationTimingV8Internal::domInteractiveAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"domContentLoadedEventStart", PerformanceNavigationTimingV8Internal::domContentLoadedEventStartAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"domContentLoadedEventEnd", PerformanceNavigationTimingV8Internal::domContentLoadedEventEndAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"domComplete", PerformanceNavigationTimingV8Internal::domCompleteAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"loadEventStart", PerformanceNavigationTimingV8Internal::loadEventStartAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"loadEventEnd", PerformanceNavigationTimingV8Internal::loadEventEndAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"type", PerformanceNavigationTimingV8Internal::typeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"redirectCount", PerformanceNavigationTimingV8Internal::redirectCountAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8PerformanceNavigationTimingMethods[] = {
    {"toJSON", PerformanceNavigationTimingV8Internal::toJSONMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8PerformanceNavigationTimingTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8PerformanceNavigationTiming::wrapperTypeInfo.interfaceName, V8PerformanceResourceTiming::domTemplate(isolate, world), V8PerformanceNavigationTiming::internalFieldCount);

  if (!RuntimeEnabledFeatures::performanceNavigationTiming2Enabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PerformanceNavigationTimingAccessors, WTF_ARRAY_LENGTH(V8PerformanceNavigationTimingAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PerformanceNavigationTimingMethods, WTF_ARRAY_LENGTH(V8PerformanceNavigationTimingMethods));
}

v8::Local<v8::FunctionTemplate> V8PerformanceNavigationTiming::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8PerformanceNavigationTimingTemplate);
}

bool V8PerformanceNavigationTiming::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8PerformanceNavigationTiming::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

PerformanceNavigationTiming* V8PerformanceNavigationTiming::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

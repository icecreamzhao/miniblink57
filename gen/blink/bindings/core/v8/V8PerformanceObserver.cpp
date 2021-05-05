// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8PerformanceObserver.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8PerformanceObserverInit.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
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
const WrapperTypeInfo V8PerformanceObserver::wrapperTypeInfo = { gin::kEmbedderBlink, V8PerformanceObserver::domTemplate, V8PerformanceObserver::trace, V8PerformanceObserver::traceWrappers, 0, nullptr, "PerformanceObserver", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in PerformanceObserver.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& PerformanceObserver::s_wrapperTypeInfo = V8PerformanceObserver::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, PerformanceObserver>::value,
    "PerformanceObserver inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&PerformanceObserver::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "PerformanceObserver is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace PerformanceObserverV8Internal {

static void observeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "PerformanceObserver", "observe");

  PerformanceObserver* impl = V8PerformanceObserver::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  PerformanceObserverInit options;
  if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
    exceptionState.throwTypeError("parameter 1 ('options') is not an object.");

    return;
  }
  V8PerformanceObserverInit::toImpl(info.GetIsolate(), info[0], options, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->observe(options, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void observeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceObserverV8Internal::observeMethod(info);
}

static void disconnectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceObserver* impl = V8PerformanceObserver::toImpl(info.Holder());

  impl->disconnect();
}

CORE_EXPORT  void disconnectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  PerformanceObserverV8Internal::disconnectMethod(info);
}

} // namespace PerformanceObserverV8Internal

const V8DOMConfiguration::MethodConfiguration V8PerformanceObserverMethods[] = {
    {"observe", PerformanceObserverV8Internal::observeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"disconnect", PerformanceObserverV8Internal::disconnectMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

void V8PerformanceObserver::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("PerformanceObserver"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  V8PerformanceObserver::constructorCustom(info);
}

static void installV8PerformanceObserverTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8PerformanceObserver::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8PerformanceObserver::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8PerformanceObserver::constructorCallback);
  interfaceTemplate->SetLength(1);

  if (!RuntimeEnabledFeatures::performanceObserverEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PerformanceObserverMethods, WTF_ARRAY_LENGTH(V8PerformanceObserverMethods));
}

v8::Local<v8::FunctionTemplate> V8PerformanceObserver::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8PerformanceObserverTemplate);
}

bool V8PerformanceObserver::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8PerformanceObserver::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

PerformanceObserver* V8PerformanceObserver::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

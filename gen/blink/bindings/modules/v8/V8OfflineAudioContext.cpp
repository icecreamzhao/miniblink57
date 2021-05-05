// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8OfflineAudioContext.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8EventListenerHelper.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
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
const WrapperTypeInfo V8OfflineAudioContext::wrapperTypeInfo = { gin::kEmbedderBlink, V8OfflineAudioContext::domTemplate, V8OfflineAudioContext::trace, V8OfflineAudioContext::traceWrappers, 0, nullptr, "OfflineAudioContext", &V8BaseAudioContext::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::InheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in OfflineAudioContext.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& OfflineAudioContext::s_wrapperTypeInfo = V8OfflineAudioContext::wrapperTypeInfo;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, OfflineAudioContext>::value,
    "OfflineAudioContext does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&OfflineAudioContext::hasPendingActivity),
                  decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "OfflineAudioContext is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace OfflineAudioContextV8Internal {

static void oncompleteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  OfflineAudioContext* impl = V8OfflineAudioContext::toImpl(holder);

  EventListener* cppValue(WTF::getPtr(impl->oncomplete()));

  v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
}

MODULES_EXPORT void oncompleteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  OfflineAudioContextV8Internal::oncompleteAttributeGetter(info);
}

static void oncompleteAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  OfflineAudioContext* impl = V8OfflineAudioContext::toImpl(holder);

  // Prepare the value to be set.
  moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->oncomplete(), v8Value, V8OfflineAudioContext::eventListenerCacheIndex);

  impl->setOncomplete(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
}

MODULES_EXPORT void oncompleteAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  OfflineAudioContextV8Internal::oncompleteAttributeSetter(v8Value, info);
}

static void lengthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  OfflineAudioContext* impl = V8OfflineAudioContext::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->length());
}

MODULES_EXPORT void lengthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  OfflineAudioContextV8Internal::lengthAttributeGetter(info);
}

static void startRenderingMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "OfflineAudioContext", "startRendering");
  ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

  // V8DOMConfiguration::DoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8OfflineAudioContext::hasInstance(info.Holder(), info.GetIsolate())) {
    exceptionState.throwTypeError("Illegal invocation");
    return;
  }
  OfflineAudioContext* impl = V8OfflineAudioContext::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  ScriptPromise result = impl->startOfflineRendering(scriptState);
  v8SetReturnValue(info, result.v8Value());
}

MODULES_EXPORT  void startRenderingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::OfflineAudioContextStartRendering);
  OfflineAudioContextV8Internal::startRenderingMethod(info);
}

static void suspendMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "OfflineAudioContext", "suspend");
  ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

  // V8DOMConfiguration::DoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8OfflineAudioContext::hasInstance(info.Holder(), info.GetIsolate())) {
    exceptionState.throwTypeError("Illegal invocation");
    return;
  }
  OfflineAudioContext* impl = V8OfflineAudioContext::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  double suspendTime;
  suspendTime = toRestrictedDouble(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  ScriptPromise result = impl->suspendContext(scriptState, suspendTime);
  v8SetReturnValue(info, result.v8Value());
}

MODULES_EXPORT  void suspendMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::OfflineAudioContextSuspend);
  OfflineAudioContextV8Internal::suspendMethod(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "OfflineAudioContext");

  if (UNLIKELY(info.Length() < 3)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(3, info.Length()));
    return;
  }

  unsigned numberOfChannels;
  unsigned numberOfFrames;
  float sampleRate;
  numberOfChannels = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  numberOfFrames = toUInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  sampleRate = toRestrictedFloat(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  ExecutionContext* executionContext = currentExecutionContext(info.GetIsolate());
  OfflineAudioContext* impl = OfflineAudioContext::create(executionContext, numberOfChannels, numberOfFrames, sampleRate, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8OfflineAudioContext::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace OfflineAudioContextV8Internal

const V8DOMConfiguration::AccessorConfiguration V8OfflineAudioContextAccessors[] = {
    {"oncomplete", OfflineAudioContextV8Internal::oncompleteAttributeGetterCallback, OfflineAudioContextV8Internal::oncompleteAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"length", OfflineAudioContextV8Internal::lengthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8OfflineAudioContextMethods[] = {
    {"startRendering", OfflineAudioContextV8Internal::startRenderingMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder},
    {"suspend", OfflineAudioContextV8Internal::suspendMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder},
};

void V8OfflineAudioContext::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8OfflineAudioContext_Constructor);
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("OfflineAudioContext"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  OfflineAudioContextV8Internal::constructor(info);
}

static void installV8OfflineAudioContextTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8OfflineAudioContext::wrapperTypeInfo.interfaceName, V8BaseAudioContext::domTemplate(isolate, world), V8OfflineAudioContext::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8OfflineAudioContext::constructorCallback);
  interfaceTemplate->SetLength(3);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8OfflineAudioContextAccessors, WTF_ARRAY_LENGTH(V8OfflineAudioContextAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8OfflineAudioContextMethods, WTF_ARRAY_LENGTH(V8OfflineAudioContextMethods));
}

v8::Local<v8::FunctionTemplate> V8OfflineAudioContext::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8OfflineAudioContextTemplate);
}

bool V8OfflineAudioContext::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8OfflineAudioContext::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

OfflineAudioContext* V8OfflineAudioContext::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SpeechSynthesis.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8EventListenerHelper.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8SpeechSynthesisUtterance.h"
#include "bindings/modules/v8/V8SpeechSynthesisVoice.h"
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
const WrapperTypeInfo V8SpeechSynthesis::wrapperTypeInfo = { gin::kEmbedderBlink, V8SpeechSynthesis::domTemplate, V8SpeechSynthesis::trace, V8SpeechSynthesis::traceWrappers, 0, nullptr, "SpeechSynthesis", &V8EventTarget::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SpeechSynthesis.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SpeechSynthesis::s_wrapperTypeInfo = V8SpeechSynthesis::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SpeechSynthesis>::value,
    "SpeechSynthesis inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SpeechSynthesis::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SpeechSynthesis is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SpeechSynthesisV8Internal {

static void pendingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(holder);

  v8SetReturnValueBool(info, impl->pending());
}

MODULES_EXPORT void pendingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::pendingAttributeGetter(info);
}

static void speakingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(holder);

  v8SetReturnValueBool(info, impl->speaking());
}

MODULES_EXPORT void speakingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::speakingAttributeGetter(info);
}

static void pausedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(holder);

  v8SetReturnValueBool(info, impl->paused());
}

MODULES_EXPORT void pausedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::pausedAttributeGetter(info);
}

static void onvoiceschangedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(holder);

  EventListener* cppValue(WTF::getPtr(impl->onvoiceschanged()));

  v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
}

MODULES_EXPORT void onvoiceschangedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::onvoiceschangedAttributeGetter(info);
}

static void onvoiceschangedAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(holder);

  // Prepare the value to be set.
  moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onvoiceschanged(), v8Value, V8SpeechSynthesis::eventListenerCacheIndex);

  impl->setOnvoiceschanged(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
}

MODULES_EXPORT void onvoiceschangedAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  SpeechSynthesisV8Internal::onvoiceschangedAttributeSetter(v8Value, info);
}

static void speakMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("speak", "SpeechSynthesis", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  SpeechSynthesisUtterance* utterance;
  utterance = V8SpeechSynthesisUtterance::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!utterance) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("speak", "SpeechSynthesis", "parameter 1 is not of type 'SpeechSynthesisUtterance'."));

    return;
  }

  impl->speak(utterance);
}

MODULES_EXPORT  void speakMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::speakMethod(info);
}

static void cancelMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(info.Holder());

  impl->cancel();
}

MODULES_EXPORT  void cancelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::cancelMethod(info);
}

static void pauseMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(info.Holder());

  impl->pause();
}

MODULES_EXPORT  void pauseMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::pauseMethod(info);
}

static void resumeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(info.Holder());

  impl->resume();
}

MODULES_EXPORT  void resumeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::resumeMethod(info);
}

static void getVoicesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesis* impl = V8SpeechSynthesis::toImpl(info.Holder());

  v8SetReturnValue(info, ToV8(impl->getVoices(), info.Holder(), info.GetIsolate()));
}

MODULES_EXPORT  void getVoicesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisV8Internal::getVoicesMethod(info);
}

} // namespace SpeechSynthesisV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SpeechSynthesisAccessors[] = {
    {"pending", SpeechSynthesisV8Internal::pendingAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"speaking", SpeechSynthesisV8Internal::speakingAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"paused", SpeechSynthesisV8Internal::pausedAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"onvoiceschanged", SpeechSynthesisV8Internal::onvoiceschangedAttributeGetterCallback, SpeechSynthesisV8Internal::onvoiceschangedAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8SpeechSynthesisMethods[] = {
    {"speak", SpeechSynthesisV8Internal::speakMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"cancel", SpeechSynthesisV8Internal::cancelMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"pause", SpeechSynthesisV8Internal::pauseMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"resume", SpeechSynthesisV8Internal::resumeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"getVoices", SpeechSynthesisV8Internal::getVoicesMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8SpeechSynthesisTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SpeechSynthesis::wrapperTypeInfo.interfaceName, V8EventTarget::domTemplate(isolate, world), V8SpeechSynthesis::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SpeechSynthesisAccessors, WTF_ARRAY_LENGTH(V8SpeechSynthesisAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SpeechSynthesisMethods, WTF_ARRAY_LENGTH(V8SpeechSynthesisMethods));
}

v8::Local<v8::FunctionTemplate> V8SpeechSynthesis::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SpeechSynthesisTemplate);
}

bool V8SpeechSynthesis::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SpeechSynthesis::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SpeechSynthesis* V8SpeechSynthesis::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SpeechSynthesisEvent.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8SpeechSynthesisUtterance.h"
#include "core/dom/Document.h"
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
const WrapperTypeInfo V8SpeechSynthesisEvent::wrapperTypeInfo = { gin::kEmbedderBlink, V8SpeechSynthesisEvent::domTemplate, V8SpeechSynthesisEvent::trace, V8SpeechSynthesisEvent::traceWrappers, 0, nullptr, "SpeechSynthesisEvent", &V8Event::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SpeechSynthesisEvent.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SpeechSynthesisEvent::s_wrapperTypeInfo = V8SpeechSynthesisEvent::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SpeechSynthesisEvent>::value,
    "SpeechSynthesisEvent inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SpeechSynthesisEvent::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SpeechSynthesisEvent is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SpeechSynthesisEventV8Internal {

static void utteranceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesisEvent* impl = V8SpeechSynthesisEvent::toImpl(holder);

  SpeechSynthesisUtterance* cppValue(WTF::getPtr(impl->utterance()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
    return;
  v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
  const char kKeepAliveKey[] = "KeepAlive#SpeechSynthesisEvent#utterance";
  V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

  v8SetReturnValue(info, v8Value);
}

MODULES_EXPORT void utteranceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisEventV8Internal::utteranceAttributeGetter(info);
}

static void charIndexAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesisEvent* impl = V8SpeechSynthesisEvent::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->charIndex());
}

MODULES_EXPORT void charIndexAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisEventV8Internal::charIndexAttributeGetter(info);
}

static void elapsedTimeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesisEvent* impl = V8SpeechSynthesisEvent::toImpl(holder);

  v8SetReturnValue(info, impl->elapsedTime());
}

MODULES_EXPORT void elapsedTimeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisEventV8Internal::elapsedTimeAttributeGetter(info);
}

static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SpeechSynthesisEvent* impl = V8SpeechSynthesisEvent::toImpl(holder);

  v8SetReturnValueString(info, impl->name(), info.GetIsolate());
}

MODULES_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SpeechSynthesisEventV8Internal::nameAttributeGetter(info);
}

} // namespace SpeechSynthesisEventV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SpeechSynthesisEventAccessors[] = {
    {"utterance", SpeechSynthesisEventV8Internal::utteranceAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"charIndex", SpeechSynthesisEventV8Internal::charIndexAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"elapsedTime", SpeechSynthesisEventV8Internal::elapsedTimeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"name", SpeechSynthesisEventV8Internal::nameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8SpeechSynthesisEventTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SpeechSynthesisEvent::wrapperTypeInfo.interfaceName, V8Event::domTemplate(isolate, world), V8SpeechSynthesisEvent::internalFieldCount);

  if (!RuntimeEnabledFeatures::scriptedSpeechEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SpeechSynthesisEventAccessors, WTF_ARRAY_LENGTH(V8SpeechSynthesisEventAccessors));
}

v8::Local<v8::FunctionTemplate> V8SpeechSynthesisEvent::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SpeechSynthesisEventTemplate);
}

bool V8SpeechSynthesisEvent::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SpeechSynthesisEvent::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SpeechSynthesisEvent* V8SpeechSynthesisEvent::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

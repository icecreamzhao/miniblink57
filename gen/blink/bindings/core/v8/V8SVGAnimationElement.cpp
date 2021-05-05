// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SVGAnimationElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8EventListenerHelper.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGElement.h"
#include "bindings/core/v8/V8SVGStringList.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/frame/UseCounter.h"
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
const WrapperTypeInfo V8SVGAnimationElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGAnimationElement::domTemplate, V8SVGAnimationElement::trace, V8SVGAnimationElement::traceWrappers, 0, nullptr, "SVGAnimationElement", &V8SVGElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGAnimationElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGAnimationElement::s_wrapperTypeInfo = V8SVGAnimationElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGAnimationElement>::value,
    "SVGAnimationElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGAnimationElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGAnimationElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGAnimationElementV8Internal {

static void targetElementAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->targetElement()), impl);
}

CORE_EXPORT void targetElementAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimationElementV8Internal::targetElementAttributeGetter(info);
}

static void onbeginAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  EventListener* cppValue(WTF::getPtr(impl->onbegin()));

  v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
}

CORE_EXPORT void onbeginAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimationElementV8Internal::onbeginAttributeGetter(info);
}

static void onbeginAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  // Prepare the value to be set.

  impl->setOnbegin(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
}

CORE_EXPORT void onbeginAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  SVGAnimationElementV8Internal::onbeginAttributeSetter(v8Value, info);
}

static void onendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  EventListener* cppValue(WTF::getPtr(impl->onend()));

  v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
}

CORE_EXPORT void onendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimationElementV8Internal::onendAttributeGetter(info);
}

static void onendAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  // Prepare the value to be set.

  impl->setOnend(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
}

CORE_EXPORT void onendAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  SVGAnimationElementV8Internal::onendAttributeSetter(v8Value, info);
}

static void onrepeatAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  EventListener* cppValue(WTF::getPtr(impl->onrepeat()));

  v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
}

CORE_EXPORT void onrepeatAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimationElementV8Internal::onrepeatAttributeGetter(info);
}

static void onrepeatAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  // Prepare the value to be set.

  impl->setOnrepeat(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
}

CORE_EXPORT void onrepeatAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  SVGAnimationElementV8Internal::onrepeatAttributeSetter(v8Value, info);
}

static void requiredFeaturesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->requiredFeatures()), impl);
}

CORE_EXPORT void requiredFeaturesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMSVGTests);

  SVGAnimationElementV8Internal::requiredFeaturesAttributeGetter(info);
}

static void requiredExtensionsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->requiredExtensions()), impl);
}

CORE_EXPORT void requiredExtensionsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMSVGTests);

  SVGAnimationElementV8Internal::requiredExtensionsAttributeGetter(info);
}

static void systemLanguageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->systemLanguage()), impl);
}

CORE_EXPORT void systemLanguageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMSVGTests);

  SVGAnimationElementV8Internal::systemLanguageAttributeGetter(info);
}

static void getStartTimeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGAnimationElement", "getStartTime");

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(info.Holder());

  float result = impl->getStartTime(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void getStartTimeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILAnimationElementTiming);
  SVGAnimationElementV8Internal::getStartTimeMethod(info);
}

static void getCurrentTimeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(info.Holder());

  v8SetReturnValue(info, impl->getCurrentTime());
}

CORE_EXPORT  void getCurrentTimeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILAnimationElementTiming);
  SVGAnimationElementV8Internal::getCurrentTimeMethod(info);
}

static void getSimpleDurationMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGAnimationElement", "getSimpleDuration");

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(info.Holder());

  float result = impl->getSimpleDuration(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void getSimpleDurationMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILAnimationElementTiming);
  SVGAnimationElementV8Internal::getSimpleDurationMethod(info);
}

static void beginElementMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(info.Holder());

  impl->beginElement();
}

CORE_EXPORT  void beginElementMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILBeginEndAnimationElement);
  SVGAnimationElementV8Internal::beginElementMethod(info);
}

static void beginElementAtMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGAnimationElement", "beginElementAt");

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  float offset;
  offset = toRestrictedFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->beginElementAt(offset);
}

CORE_EXPORT  void beginElementAtMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILBeginEndAnimationElement);
  SVGAnimationElementV8Internal::beginElementAtMethod(info);
}

static void endElementMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(info.Holder());

  impl->endElement();
}

CORE_EXPORT  void endElementMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILBeginEndAnimationElement);
  SVGAnimationElementV8Internal::endElementMethod(info);
}

static void endElementAtMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGAnimationElement", "endElementAt");

  SVGAnimationElement* impl = V8SVGAnimationElement::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  float offset;
  offset = toRestrictedFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->endElementAt(offset);
}

CORE_EXPORT  void endElementAtMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILBeginEndAnimationElement);
  SVGAnimationElementV8Internal::endElementAtMethod(info);
}

} // namespace SVGAnimationElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SVGAnimationElementAccessors[] = {
    {"targetElement", SVGAnimationElementV8Internal::targetElementAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"onbegin", SVGAnimationElementV8Internal::onbeginAttributeGetterCallback, SVGAnimationElementV8Internal::onbeginAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"onend", SVGAnimationElementV8Internal::onendAttributeGetterCallback, SVGAnimationElementV8Internal::onendAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"onrepeat", SVGAnimationElementV8Internal::onrepeatAttributeGetterCallback, SVGAnimationElementV8Internal::onrepeatAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"requiredFeatures", SVGAnimationElementV8Internal::requiredFeaturesAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"requiredExtensions", SVGAnimationElementV8Internal::requiredExtensionsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"systemLanguage", SVGAnimationElementV8Internal::systemLanguageAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8SVGAnimationElementMethods[] = {
    {"getStartTime", SVGAnimationElementV8Internal::getStartTimeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"getCurrentTime", SVGAnimationElementV8Internal::getCurrentTimeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"getSimpleDuration", SVGAnimationElementV8Internal::getSimpleDurationMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"beginElement", SVGAnimationElementV8Internal::beginElementMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"beginElementAt", SVGAnimationElementV8Internal::beginElementAtMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"endElement", SVGAnimationElementV8Internal::endElementMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"endElementAt", SVGAnimationElementV8Internal::endElementAtMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8SVGAnimationElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGAnimationElement::wrapperTypeInfo.interfaceName, V8SVGElement::domTemplate(isolate, world), V8SVGAnimationElement::internalFieldCount);

  if (!RuntimeEnabledFeatures::smilEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGAnimationElementAccessors, WTF_ARRAY_LENGTH(V8SVGAnimationElementAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGAnimationElementMethods, WTF_ARRAY_LENGTH(V8SVGAnimationElementMethods));
}

v8::Local<v8::FunctionTemplate> V8SVGAnimationElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGAnimationElementTemplate);
}

bool V8SVGAnimationElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGAnimationElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGAnimationElement* V8SVGAnimationElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

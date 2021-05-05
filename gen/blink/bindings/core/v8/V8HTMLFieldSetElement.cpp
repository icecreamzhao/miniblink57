// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8HTMLFieldSetElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HTMLCollection.h"
#include "bindings/core/v8/V8HTMLFormElement.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8ValidityState.h"
#include "core/HTMLNames.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/ClassCollection.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/TagCollection.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
#include "core/frame/UseCounter.h"
#include "core/html/HTMLCollection.h"
#include "core/html/HTMLDataListOptionsCollection.h"
#include "core/html/HTMLFormControlsCollection.h"
#include "core/html/HTMLTableRowsCollection.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8HTMLFieldSetElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLFieldSetElement::domTemplate, V8HTMLFieldSetElement::trace, V8HTMLFieldSetElement::traceWrappers, 0, nullptr, "HTMLFieldSetElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLFieldSetElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLFieldSetElement::s_wrapperTypeInfo = V8HTMLFieldSetElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLFieldSetElement>::value,
    "HTMLFieldSetElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLFieldSetElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLFieldSetElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLFieldSetElementV8Internal {

static void disabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueBool(info, impl->fastHasAttribute(HTMLNames::disabledAttr));
}

CORE_EXPORT void disabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::disabledAttributeGetter(info);
}

static void disabledAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  // Skip on compact node DOMString getters.
  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLFieldSetElement", "disabled");

  // Prepare the value to be set.
  bool cppValue = toBoolean(info.GetIsolate(), v8Value, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->setBooleanAttribute(HTMLNames::disabledAttr, cppValue);
}

CORE_EXPORT void disabledAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLFieldSetElementV8Internal::disabledAttributeSetter(v8Value, info);
}

static void formAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->formOwner()), impl);
}

CORE_EXPORT void formAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::formAttributeGetter(info);
}

static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueString(info, impl->getNameAttribute(), info.GetIsolate());
}

CORE_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::nameAttributeGetter(info);
}

static void nameAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::nameAttr, cppValue);
}

CORE_EXPORT void nameAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLFieldSetElementV8Internal::nameAttributeSetter(v8Value, info);
}

static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueString(info, impl->type(), info.GetIsolate());
}

CORE_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::typeAttributeGetter(info);
}

static void elementsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->elements()), impl);
}

CORE_EXPORT void elementsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8HTMLFieldSetElement_Elements_AttributeGetter);

  HTMLFieldSetElementV8Internal::elementsAttributeGetter(info);
}

static void willValidateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueBool(info, impl->willValidate());
}

CORE_EXPORT void willValidateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::willValidateAttributeGetter(info);
}

static void validityAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->validity()), impl);
}

CORE_EXPORT void validityAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::validityAttributeGetter(info);
}

static void validationMessageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(holder);

  v8SetReturnValueString(info, impl->validationMessage(), info.GetIsolate());
}

CORE_EXPORT void validationMessageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::validationMessageAttributeGetter(info);
}

static void checkValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(info.Holder());

  v8SetReturnValueBool(info, impl->checkValidity());
}

CORE_EXPORT  void checkValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::checkValidityMethod(info);
}

static void reportValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(info.Holder());

  v8SetReturnValueBool(info, impl->reportValidity());
}

CORE_EXPORT  void reportValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::reportValidityMethod(info);
}

static void setCustomValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElement* impl = V8HTMLFieldSetElement::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setCustomValidity", "HTMLFieldSetElement", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> error;
  error = info[0];
  if (!error.prepare())
    return;

  impl->setCustomValidity(error);
}

CORE_EXPORT  void setCustomValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLFieldSetElementV8Internal::setCustomValidityMethod(info);
}

} // namespace HTMLFieldSetElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLFieldSetElementAccessors[] = {
    {"disabled", HTMLFieldSetElementV8Internal::disabledAttributeGetterCallback, HTMLFieldSetElementV8Internal::disabledAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"form", HTMLFieldSetElementV8Internal::formAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"name", HTMLFieldSetElementV8Internal::nameAttributeGetterCallback, HTMLFieldSetElementV8Internal::nameAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"type", HTMLFieldSetElementV8Internal::typeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"elements", HTMLFieldSetElementV8Internal::elementsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"willValidate", HTMLFieldSetElementV8Internal::willValidateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"validity", HTMLFieldSetElementV8Internal::validityAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"validationMessage", HTMLFieldSetElementV8Internal::validationMessageAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8HTMLFieldSetElementMethods[] = {
    {"checkValidity", HTMLFieldSetElementV8Internal::checkValidityMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"reportValidity", HTMLFieldSetElementV8Internal::reportValidityMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"setCustomValidity", HTMLFieldSetElementV8Internal::setCustomValidityMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8HTMLFieldSetElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLFieldSetElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLFieldSetElement::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLFieldSetElementAccessors, WTF_ARRAY_LENGTH(V8HTMLFieldSetElementAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLFieldSetElementMethods, WTF_ARRAY_LENGTH(V8HTMLFieldSetElementMethods));
}

v8::Local<v8::FunctionTemplate> V8HTMLFieldSetElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLFieldSetElementTemplate);
}

bool V8HTMLFieldSetElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLFieldSetElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLFieldSetElement* V8HTMLFieldSetElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

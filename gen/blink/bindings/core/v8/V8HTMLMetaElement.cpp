// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8HTMLMetaElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/HTMLNames.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8HTMLMetaElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLMetaElement::domTemplate, V8HTMLMetaElement::trace, V8HTMLMetaElement::traceWrappers, 0, nullptr, "HTMLMetaElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLMetaElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLMetaElement::s_wrapperTypeInfo = V8HTMLMetaElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLMetaElement>::value,
    "HTMLMetaElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLMetaElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLMetaElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLMetaElementV8Internal {

static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

  v8SetReturnValueString(info, impl->getNameAttribute(), info.GetIsolate());
}

CORE_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLMetaElementV8Internal::nameAttributeGetter(info);
}

static void nameAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

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

  HTMLMetaElementV8Internal::nameAttributeSetter(v8Value, info);
}

static void httpEquivAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::http_equivAttr), info.GetIsolate());
}

CORE_EXPORT void httpEquivAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLMetaElementV8Internal::httpEquivAttributeGetter(info);
}

static void httpEquivAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::http_equivAttr, cppValue);
}

CORE_EXPORT void httpEquivAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLMetaElementV8Internal::httpEquivAttributeSetter(v8Value, info);
}

static void contentAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::contentAttr), info.GetIsolate());
}

CORE_EXPORT void contentAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLMetaElementV8Internal::contentAttributeGetter(info);
}

static void contentAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::contentAttr, cppValue);
}

CORE_EXPORT void contentAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLMetaElementV8Internal::contentAttributeSetter(v8Value, info);
}

static void schemeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::schemeAttr), info.GetIsolate());
}

CORE_EXPORT void schemeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLMetaElementV8Internal::schemeAttributeGetter(info);
}

static void schemeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLMetaElement* impl = V8HTMLMetaElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::schemeAttr, cppValue);
}

CORE_EXPORT void schemeAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLMetaElementV8Internal::schemeAttributeSetter(v8Value, info);
}

} // namespace HTMLMetaElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLMetaElementAccessors[] = {
    {"name", HTMLMetaElementV8Internal::nameAttributeGetterCallback, HTMLMetaElementV8Internal::nameAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"httpEquiv", HTMLMetaElementV8Internal::httpEquivAttributeGetterCallback, HTMLMetaElementV8Internal::httpEquivAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"content", HTMLMetaElementV8Internal::contentAttributeGetterCallback, HTMLMetaElementV8Internal::contentAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"scheme", HTMLMetaElementV8Internal::schemeAttributeGetterCallback, HTMLMetaElementV8Internal::schemeAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8HTMLMetaElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLMetaElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLMetaElement::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLMetaElementAccessors, WTF_ARRAY_LENGTH(V8HTMLMetaElementAccessors));
}

v8::Local<v8::FunctionTemplate> V8HTMLMetaElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLMetaElementTemplate);
}

bool V8HTMLMetaElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLMetaElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLMetaElement* V8HTMLMetaElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

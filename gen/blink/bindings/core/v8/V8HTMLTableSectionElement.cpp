// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8HTMLTableSectionElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HTMLCollection.h"
#include "bindings/core/v8/V8HTMLElement.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/HTMLNames.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/ClassCollection.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/TagCollection.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
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
const WrapperTypeInfo V8HTMLTableSectionElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLTableSectionElement::domTemplate, V8HTMLTableSectionElement::trace, V8HTMLTableSectionElement::traceWrappers, 0, nullptr, "HTMLTableSectionElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLTableSectionElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLTableSectionElement::s_wrapperTypeInfo = V8HTMLTableSectionElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLTableSectionElement>::value,
    "HTMLTableSectionElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLTableSectionElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLTableSectionElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLTableSectionElementV8Internal {

static void rowsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->rows()), impl);
}

CORE_EXPORT void rowsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableSectionElementV8Internal::rowsAttributeGetter(info);
}

static void alignAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::alignAttr), info.GetIsolate());
}

CORE_EXPORT void alignAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableSectionElementV8Internal::alignAttributeGetter(info);
}

static void alignAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::alignAttr, cppValue);
}

CORE_EXPORT void alignAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableSectionElementV8Internal::alignAttributeSetter(v8Value, info);
}

static void chAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::charAttr), info.GetIsolate());
}

CORE_EXPORT void chAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableSectionElementV8Internal::chAttributeGetter(info);
}

static void chAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::charAttr, cppValue);
}

CORE_EXPORT void chAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableSectionElementV8Internal::chAttributeSetter(v8Value, info);
}

static void chOffAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::charoffAttr), info.GetIsolate());
}

CORE_EXPORT void chOffAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableSectionElementV8Internal::chOffAttributeGetter(info);
}

static void chOffAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::charoffAttr, cppValue);
}

CORE_EXPORT void chOffAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableSectionElementV8Internal::chOffAttributeSetter(v8Value, info);
}

static void vAlignAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::valignAttr), info.GetIsolate());
}

CORE_EXPORT void vAlignAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableSectionElementV8Internal::vAlignAttributeGetter(info);
}

static void vAlignAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::valignAttr, cppValue);
}

CORE_EXPORT void vAlignAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableSectionElementV8Internal::vAlignAttributeSetter(v8Value, info);
}

static void insertRowMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "HTMLTableSectionElement", "insertRow");

  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(info.Holder());

  int index;
  if (!info[0]->IsUndefined()) {
    index = toInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
    if (exceptionState.hadException())
      return;
  } else {
    index = -1;
  }

  HTMLElement* result = impl->insertRow(index, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValueFast(info, result, impl);
}

CORE_EXPORT  void insertRowMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  HTMLTableSectionElementV8Internal::insertRowMethod(info);
}

static void deleteRowMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "HTMLTableSectionElement", "deleteRow");

  HTMLTableSectionElement* impl = V8HTMLTableSectionElement::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  int index;
  index = toInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->deleteRow(index, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void deleteRowMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CEReactionsScope ceReactionsScope;
  HTMLTableSectionElementV8Internal::deleteRowMethod(info);
}

} // namespace HTMLTableSectionElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLTableSectionElementAccessors[] = {
    {"rows", HTMLTableSectionElementV8Internal::rowsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"align", HTMLTableSectionElementV8Internal::alignAttributeGetterCallback, HTMLTableSectionElementV8Internal::alignAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"ch", HTMLTableSectionElementV8Internal::chAttributeGetterCallback, HTMLTableSectionElementV8Internal::chAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"chOff", HTMLTableSectionElementV8Internal::chOffAttributeGetterCallback, HTMLTableSectionElementV8Internal::chOffAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"vAlign", HTMLTableSectionElementV8Internal::vAlignAttributeGetterCallback, HTMLTableSectionElementV8Internal::vAlignAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8HTMLTableSectionElementMethods[] = {
    {"insertRow", HTMLTableSectionElementV8Internal::insertRowMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"deleteRow", HTMLTableSectionElementV8Internal::deleteRowMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8HTMLTableSectionElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLTableSectionElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLTableSectionElement::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLTableSectionElementAccessors, WTF_ARRAY_LENGTH(V8HTMLTableSectionElementAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLTableSectionElementMethods, WTF_ARRAY_LENGTH(V8HTMLTableSectionElementMethods));
}

v8::Local<v8::FunctionTemplate> V8HTMLTableSectionElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLTableSectionElementTemplate);
}

bool V8HTMLTableSectionElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLTableSectionElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLTableSectionElement* V8HTMLTableSectionElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

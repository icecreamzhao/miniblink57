// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8HTMLTableCellElement.h"

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
const WrapperTypeInfo V8HTMLTableCellElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLTableCellElement::domTemplate, V8HTMLTableCellElement::trace, V8HTMLTableCellElement::traceWrappers, 0, nullptr, "HTMLTableCellElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLTableCellElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLTableCellElement::s_wrapperTypeInfo = V8HTMLTableCellElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLTableCellElement>::value,
    "HTMLTableCellElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLTableCellElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLTableCellElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLTableCellElementV8Internal {

static void colSpanAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->colSpan());
}

CORE_EXPORT void colSpanAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::colSpanAttributeGetter(info);
}

static void colSpanAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLTableCellElement", "colSpan");

  // Prepare the value to be set.
  unsigned cppValue = toUInt32(info.GetIsolate(), v8Value, NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->setColSpan(cppValue);
}

CORE_EXPORT void colSpanAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  HTMLTableCellElementV8Internal::colSpanAttributeSetter(v8Value, info);
}

static void rowSpanAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->rowSpan());
}

CORE_EXPORT void rowSpanAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::rowSpanAttributeGetter(info);
}

static void rowSpanAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLTableCellElement", "rowSpan");

  // Prepare the value to be set.
  unsigned cppValue = toUInt32(info.GetIsolate(), v8Value, NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->setRowSpan(cppValue);
}

CORE_EXPORT void rowSpanAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  HTMLTableCellElementV8Internal::rowSpanAttributeSetter(v8Value, info);
}

static void headersAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::headersAttr), info.GetIsolate());
}

CORE_EXPORT void headersAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::headersAttributeGetter(info);
}

static void headersAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<TreatNullAsNullString> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::headersAttr, cppValue);
}

CORE_EXPORT void headersAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::headersAttributeSetter(v8Value, info);
}

static void cellIndexAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueInt(info, impl->cellIndex());
}

CORE_EXPORT void cellIndexAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::cellIndexAttributeGetter(info);
}

static void alignAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::alignAttr), info.GetIsolate());
}

CORE_EXPORT void alignAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::alignAttributeGetter(info);
}

static void alignAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

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

  HTMLTableCellElementV8Internal::alignAttributeSetter(v8Value, info);
}

static void axisAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::axisAttr), info.GetIsolate());
}

CORE_EXPORT void axisAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::axisAttributeGetter(info);
}

static void axisAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::axisAttr, cppValue);
}

CORE_EXPORT void axisAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::axisAttributeSetter(v8Value, info);
}

static void heightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::heightAttr), info.GetIsolate());
}

CORE_EXPORT void heightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::heightAttributeGetter(info);
}

static void heightAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::heightAttr, cppValue);
}

CORE_EXPORT void heightAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::heightAttributeSetter(v8Value, info);
}

static void widthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::widthAttr), info.GetIsolate());
}

CORE_EXPORT void widthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::widthAttributeGetter(info);
}

static void widthAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::widthAttr, cppValue);
}

CORE_EXPORT void widthAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::widthAttributeSetter(v8Value, info);
}

static void chAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::charAttr), info.GetIsolate());
}

CORE_EXPORT void chAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::chAttributeGetter(info);
}

static void chAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

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

  HTMLTableCellElementV8Internal::chAttributeSetter(v8Value, info);
}

static void chOffAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::charoffAttr), info.GetIsolate());
}

CORE_EXPORT void chOffAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::chOffAttributeGetter(info);
}

static void chOffAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

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

  HTMLTableCellElementV8Internal::chOffAttributeSetter(v8Value, info);
}

static void noWrapAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueBool(info, impl->fastHasAttribute(HTMLNames::nowrapAttr));
}

CORE_EXPORT void noWrapAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::noWrapAttributeGetter(info);
}

static void noWrapAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Skip on compact node DOMString getters.
  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLTableCellElement", "noWrap");

  // Prepare the value to be set.
  bool cppValue = toBoolean(info.GetIsolate(), v8Value, exceptionState);
  if (exceptionState.hadException())
    return;

  impl->setBooleanAttribute(HTMLNames::nowrapAttr, cppValue);
}

CORE_EXPORT void noWrapAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::noWrapAttributeSetter(v8Value, info);
}

static void vAlignAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::valignAttr), info.GetIsolate());
}

CORE_EXPORT void vAlignAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::vAlignAttributeGetter(info);
}

static void vAlignAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

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

  HTMLTableCellElementV8Internal::vAlignAttributeSetter(v8Value, info);
}

static void bgColorAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::bgcolorAttr), info.GetIsolate());
}

CORE_EXPORT void bgColorAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::bgColorAttributeGetter(info);
}

static void bgColorAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<TreatNullAsEmptyString> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::bgcolorAttr, cppValue);
}

CORE_EXPORT void bgColorAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::bgColorAttributeSetter(v8Value, info);
}

static void abbrAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::abbrAttr), info.GetIsolate());
}

CORE_EXPORT void abbrAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::abbrAttributeGetter(info);
}

static void abbrAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::abbrAttr, cppValue);
}

CORE_EXPORT void abbrAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::abbrAttributeSetter(v8Value, info);
}

static void scopeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  String cppValue(impl->fastGetAttribute(HTMLNames::scopeAttr));

  if (cppValue.isEmpty()) {
    ;
  } else if (equalIgnoringASCIICase(cppValue, "row")) {
    cppValue = "row";
  } else if (equalIgnoringASCIICase(cppValue, "col")) {
    cppValue = "col";
  } else if (equalIgnoringASCIICase(cppValue, "rowgroup")) {
    cppValue = "rowgroup";
  } else if (equalIgnoringASCIICase(cppValue, "colgroup")) {
    cppValue = "colgroup";
  } else {
    cppValue = "";
  }

  v8SetReturnValueString(info, cppValue, info.GetIsolate());
}

CORE_EXPORT void scopeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  HTMLTableCellElementV8Internal::scopeAttributeGetter(info);
}

static void scopeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  HTMLTableCellElement* impl = V8HTMLTableCellElement::toImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  impl->setAttribute(HTMLNames::scopeAttr, cppValue);
}

CORE_EXPORT void scopeAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  CEReactionsScope ceReactionsScope;

  V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

  HTMLTableCellElementV8Internal::scopeAttributeSetter(v8Value, info);
}

} // namespace HTMLTableCellElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLTableCellElementAccessors[] = {
    {"colSpan", HTMLTableCellElementV8Internal::colSpanAttributeGetterCallback, HTMLTableCellElementV8Internal::colSpanAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"rowSpan", HTMLTableCellElementV8Internal::rowSpanAttributeGetterCallback, HTMLTableCellElementV8Internal::rowSpanAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"headers", HTMLTableCellElementV8Internal::headersAttributeGetterCallback, HTMLTableCellElementV8Internal::headersAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"cellIndex", HTMLTableCellElementV8Internal::cellIndexAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"align", HTMLTableCellElementV8Internal::alignAttributeGetterCallback, HTMLTableCellElementV8Internal::alignAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"axis", HTMLTableCellElementV8Internal::axisAttributeGetterCallback, HTMLTableCellElementV8Internal::axisAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"height", HTMLTableCellElementV8Internal::heightAttributeGetterCallback, HTMLTableCellElementV8Internal::heightAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"width", HTMLTableCellElementV8Internal::widthAttributeGetterCallback, HTMLTableCellElementV8Internal::widthAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"ch", HTMLTableCellElementV8Internal::chAttributeGetterCallback, HTMLTableCellElementV8Internal::chAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"chOff", HTMLTableCellElementV8Internal::chOffAttributeGetterCallback, HTMLTableCellElementV8Internal::chOffAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"noWrap", HTMLTableCellElementV8Internal::noWrapAttributeGetterCallback, HTMLTableCellElementV8Internal::noWrapAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"vAlign", HTMLTableCellElementV8Internal::vAlignAttributeGetterCallback, HTMLTableCellElementV8Internal::vAlignAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"bgColor", HTMLTableCellElementV8Internal::bgColorAttributeGetterCallback, HTMLTableCellElementV8Internal::bgColorAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"abbr", HTMLTableCellElementV8Internal::abbrAttributeGetterCallback, HTMLTableCellElementV8Internal::abbrAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"scope", HTMLTableCellElementV8Internal::scopeAttributeGetterCallback, HTMLTableCellElementV8Internal::scopeAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8HTMLTableCellElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLTableCellElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLTableCellElement::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLTableCellElementAccessors, WTF_ARRAY_LENGTH(V8HTMLTableCellElementAccessors));
}

v8::Local<v8::FunctionTemplate> V8HTMLTableCellElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLTableCellElementTemplate);
}

bool V8HTMLTableCellElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLTableCellElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLTableCellElement* V8HTMLTableCellElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

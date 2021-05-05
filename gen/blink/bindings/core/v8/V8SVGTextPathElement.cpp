// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SVGTextPathElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGAnimatedEnumeration.h"
#include "bindings/core/v8/V8SVGAnimatedLength.h"
#include "bindings/core/v8/V8SVGAnimatedString.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
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
const WrapperTypeInfo V8SVGTextPathElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGTextPathElement::domTemplate, V8SVGTextPathElement::trace, V8SVGTextPathElement::traceWrappers, 0, nullptr, "SVGTextPathElement", &V8SVGTextContentElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGTextPathElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGTextPathElement::s_wrapperTypeInfo = V8SVGTextPathElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGTextPathElement>::value,
    "SVGTextPathElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGTextPathElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGTextPathElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGTextPathElementV8Internal {

CORE_EXPORT void TEXTPATH_METHODTYPE_UNKNOWNConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);
  v8SetReturnValueInt(info, 0);
}

CORE_EXPORT void TEXTPATH_METHODTYPE_ALIGNConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);
  v8SetReturnValueInt(info, 1);
}

CORE_EXPORT void TEXTPATH_METHODTYPE_STRETCHConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);
  v8SetReturnValueInt(info, 2);
}

CORE_EXPORT void TEXTPATH_SPACINGTYPE_UNKNOWNConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);
  v8SetReturnValueInt(info, 0);
}

CORE_EXPORT void TEXTPATH_SPACINGTYPE_AUTOConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);
  v8SetReturnValueInt(info, 1);
}

CORE_EXPORT void TEXTPATH_SPACINGTYPE_EXACTConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);
  v8SetReturnValueInt(info, 2);
}

static void startOffsetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPathElement* impl = V8SVGTextPathElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->startOffset()), impl);
}

CORE_EXPORT void startOffsetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPathElementV8Internal::startOffsetAttributeGetter(info);
}

static void methodAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPathElement* impl = V8SVGTextPathElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->method()), impl);
}

CORE_EXPORT void methodAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPathElementV8Internal::methodAttributeGetter(info);
}

static void spacingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPathElement* impl = V8SVGTextPathElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->spacing()), impl);
}

CORE_EXPORT void spacingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPathElementV8Internal::spacingAttributeGetter(info);
}

static void hrefAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPathElement* impl = V8SVGTextPathElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->href()), impl);
}

CORE_EXPORT void hrefAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMUriReference);

  SVGTextPathElementV8Internal::hrefAttributeGetter(info);
}

} // namespace SVGTextPathElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SVGTextPathElementAccessors[] = {
    {"startOffset", SVGTextPathElementV8Internal::startOffsetAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"method", SVGTextPathElementV8Internal::methodAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"spacing", SVGTextPathElementV8Internal::spacingAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"href", SVGTextPathElementV8Internal::hrefAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8SVGTextPathElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGTextPathElement::wrapperTypeInfo.interfaceName, V8SVGTextContentElement::domTemplate(isolate, world), V8SVGTextPathElement::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "TEXTPATH_METHODTYPE_UNKNOWN", SVGTextPathElementV8Internal::TEXTPATH_METHODTYPE_UNKNOWNConstantGetterCallback);
  V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "TEXTPATH_METHODTYPE_ALIGN", SVGTextPathElementV8Internal::TEXTPATH_METHODTYPE_ALIGNConstantGetterCallback);
  V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "TEXTPATH_METHODTYPE_STRETCH", SVGTextPathElementV8Internal::TEXTPATH_METHODTYPE_STRETCHConstantGetterCallback);
  V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "TEXTPATH_SPACINGTYPE_UNKNOWN", SVGTextPathElementV8Internal::TEXTPATH_SPACINGTYPE_UNKNOWNConstantGetterCallback);
  V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "TEXTPATH_SPACINGTYPE_AUTO", SVGTextPathElementV8Internal::TEXTPATH_SPACINGTYPE_AUTOConstantGetterCallback);
  V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "TEXTPATH_SPACINGTYPE_EXACT", SVGTextPathElementV8Internal::TEXTPATH_SPACINGTYPE_EXACTConstantGetterCallback);
  static_assert(0 == SVGTextPathElement::kTextpathMethodtypeUnknown, "the value of SVGTextPathElement_kTextpathMethodtypeUnknown does not match with implementation");
  static_assert(1 == SVGTextPathElement::kTextpathMethodtypeAlign, "the value of SVGTextPathElement_kTextpathMethodtypeAlign does not match with implementation");
  static_assert(2 == SVGTextPathElement::kTextpathMethodtypeStretch, "the value of SVGTextPathElement_kTextpathMethodtypeStretch does not match with implementation");
  static_assert(0 == SVGTextPathElement::kTextpathSpacingtypeUnknown, "the value of SVGTextPathElement_kTextpathSpacingtypeUnknown does not match with implementation");
  static_assert(1 == SVGTextPathElement::kTextpathSpacingtypeAuto, "the value of SVGTextPathElement_kTextpathSpacingtypeAuto does not match with implementation");
  static_assert(2 == SVGTextPathElement::kTextpathSpacingtypeExact, "the value of SVGTextPathElement_kTextpathSpacingtypeExact does not match with implementation");
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGTextPathElementAccessors, WTF_ARRAY_LENGTH(V8SVGTextPathElementAccessors));
}

v8::Local<v8::FunctionTemplate> V8SVGTextPathElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGTextPathElementTemplate);
}

bool V8SVGTextPathElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGTextPathElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGTextPathElement* V8SVGTextPathElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

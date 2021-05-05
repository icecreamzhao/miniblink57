// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SVGTextPositioningElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGAnimatedLengthList.h"
#include "bindings/core/v8/V8SVGAnimatedNumberList.h"
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
const WrapperTypeInfo V8SVGTextPositioningElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGTextPositioningElement::domTemplate, V8SVGTextPositioningElement::trace, V8SVGTextPositioningElement::traceWrappers, 0, nullptr, "SVGTextPositioningElement", &V8SVGTextContentElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGTextPositioningElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGTextPositioningElement::s_wrapperTypeInfo = V8SVGTextPositioningElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGTextPositioningElement>::value,
    "SVGTextPositioningElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGTextPositioningElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGTextPositioningElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGTextPositioningElementV8Internal {

static void xAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPositioningElement* impl = V8SVGTextPositioningElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->x()), impl);
}

CORE_EXPORT void xAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPositioningElementV8Internal::xAttributeGetter(info);
}

static void yAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPositioningElement* impl = V8SVGTextPositioningElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->y()), impl);
}

CORE_EXPORT void yAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPositioningElementV8Internal::yAttributeGetter(info);
}

static void dxAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPositioningElement* impl = V8SVGTextPositioningElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->dx()), impl);
}

CORE_EXPORT void dxAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPositioningElementV8Internal::dxAttributeGetter(info);
}

static void dyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPositioningElement* impl = V8SVGTextPositioningElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->dy()), impl);
}

CORE_EXPORT void dyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPositioningElementV8Internal::dyAttributeGetter(info);
}

static void rotateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGTextPositioningElement* impl = V8SVGTextPositioningElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->rotate()), impl);
}

CORE_EXPORT void rotateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMText);

  SVGTextPositioningElementV8Internal::rotateAttributeGetter(info);
}

} // namespace SVGTextPositioningElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SVGTextPositioningElementAccessors[] = {
    {"x", SVGTextPositioningElementV8Internal::xAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"y", SVGTextPositioningElementV8Internal::yAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"dx", SVGTextPositioningElementV8Internal::dxAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"dy", SVGTextPositioningElementV8Internal::dyAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"rotate", SVGTextPositioningElementV8Internal::rotateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8SVGTextPositioningElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGTextPositioningElement::wrapperTypeInfo.interfaceName, V8SVGTextContentElement::domTemplate(isolate, world), V8SVGTextPositioningElement::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGTextPositioningElementAccessors, WTF_ARRAY_LENGTH(V8SVGTextPositioningElementAccessors));
}

v8::Local<v8::FunctionTemplate> V8SVGTextPositioningElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGTextPositioningElementTemplate);
}

bool V8SVGTextPositioningElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGTextPositioningElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGTextPositioningElement* V8SVGTextPositioningElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SVGFEGaussianBlurElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGAnimatedLength.h"
#include "bindings/core/v8/V8SVGAnimatedNumber.h"
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
const WrapperTypeInfo V8SVGFEGaussianBlurElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGFEGaussianBlurElement::domTemplate, V8SVGFEGaussianBlurElement::trace, V8SVGFEGaussianBlurElement::traceWrappers, 0, nullptr, "SVGFEGaussianBlurElement", &V8SVGElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGFEGaussianBlurElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGFEGaussianBlurElement::s_wrapperTypeInfo = V8SVGFEGaussianBlurElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGFEGaussianBlurElement>::value,
    "SVGFEGaussianBlurElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGFEGaussianBlurElement::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGFEGaussianBlurElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGFEGaussianBlurElementV8Internal {

static void in1AttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->in1()), impl);
}

CORE_EXPORT void in1AttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::in1AttributeGetter(info);
}

static void stdDeviationXAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->stdDeviationX()), impl);
}

CORE_EXPORT void stdDeviationXAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::stdDeviationXAttributeGetter(info);
}

static void stdDeviationYAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->stdDeviationY()), impl);
}

CORE_EXPORT void stdDeviationYAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::stdDeviationYAttributeGetter(info);
}

static void xAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->x()), impl);
}

CORE_EXPORT void xAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::xAttributeGetter(info);
}

static void yAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->y()), impl);
}

CORE_EXPORT void yAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::yAttributeGetter(info);
}

static void widthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->width()), impl);
}

CORE_EXPORT void widthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::widthAttributeGetter(info);
}

static void heightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->height()), impl);
}

CORE_EXPORT void heightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::heightAttributeGetter(info);
}

static void resultAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->result()), impl);
}

CORE_EXPORT void resultAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

  SVGFEGaussianBlurElementV8Internal::resultAttributeGetter(info);
}

static void setStdDeviationMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGFEGaussianBlurElement", "setStdDeviation");

  SVGFEGaussianBlurElement* impl = V8SVGFEGaussianBlurElement::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  float stdDeviationX;
  float stdDeviationY;
  stdDeviationX = toRestrictedFloat(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  stdDeviationY = toRestrictedFloat(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  impl->setStdDeviation(stdDeviationX, stdDeviationY);
}

CORE_EXPORT  void setStdDeviationMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);
  SVGFEGaussianBlurElementV8Internal::setStdDeviationMethod(info);
}

} // namespace SVGFEGaussianBlurElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SVGFEGaussianBlurElementAccessors[] = {
    {"in1", SVGFEGaussianBlurElementV8Internal::in1AttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"stdDeviationX", SVGFEGaussianBlurElementV8Internal::stdDeviationXAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"stdDeviationY", SVGFEGaussianBlurElementV8Internal::stdDeviationYAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"x", SVGFEGaussianBlurElementV8Internal::xAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"y", SVGFEGaussianBlurElementV8Internal::yAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"width", SVGFEGaussianBlurElementV8Internal::widthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"height", SVGFEGaussianBlurElementV8Internal::heightAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"result", SVGFEGaussianBlurElementV8Internal::resultAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8SVGFEGaussianBlurElementMethods[] = {
    {"setStdDeviation", SVGFEGaussianBlurElementV8Internal::setStdDeviationMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8SVGFEGaussianBlurElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGFEGaussianBlurElement::wrapperTypeInfo.interfaceName, V8SVGElement::domTemplate(isolate, world), V8SVGFEGaussianBlurElement::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGFEGaussianBlurElementAccessors, WTF_ARRAY_LENGTH(V8SVGFEGaussianBlurElementAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGFEGaussianBlurElementMethods, WTF_ARRAY_LENGTH(V8SVGFEGaussianBlurElementMethods));
}

v8::Local<v8::FunctionTemplate> V8SVGFEGaussianBlurElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGFEGaussianBlurElementTemplate);
}

bool V8SVGFEGaussianBlurElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGFEGaussianBlurElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGFEGaussianBlurElement* V8SVGFEGaussianBlurElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

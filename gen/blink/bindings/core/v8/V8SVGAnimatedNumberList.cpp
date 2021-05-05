// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SVGAnimatedNumberList.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGElement.h"
#include "bindings/core/v8/V8SVGNumberList.h"
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
const WrapperTypeInfo V8SVGAnimatedNumberList::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGAnimatedNumberList::domTemplate, V8SVGAnimatedNumberList::trace, V8SVGAnimatedNumberList::traceWrappers, V8SVGAnimatedNumberList::visitDOMWrapper, nullptr, "SVGAnimatedNumberList", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGAnimatedNumberList.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGAnimatedNumberList::s_wrapperTypeInfo = V8SVGAnimatedNumberList::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGAnimatedNumberList>::value,
    "SVGAnimatedNumberList inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGAnimatedNumberList::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGAnimatedNumberList is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGAnimatedNumberListV8Internal {

static void baseValAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimatedNumberList* impl = V8SVGAnimatedNumberList::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->baseVal()), impl);
}

CORE_EXPORT void baseValAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimatedNumberListV8Internal::baseValAttributeGetter(info);
}

static void animValAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  SVGAnimatedNumberList* impl = V8SVGAnimatedNumberList::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->animVal()), impl);
}

CORE_EXPORT void animValAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SVGAnimatedNumberListV8Internal::animValAttributeGetter(info);
}

} // namespace SVGAnimatedNumberListV8Internal

void V8SVGAnimatedNumberList::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper) {
  SVGAnimatedNumberList* impl = scriptWrappable->toImpl<SVGAnimatedNumberList>();
  SVGElement* contextElement = impl->contextElement();
  if (contextElement) {
    DOMWrapperWorld::setWrapperReferencesInAllWorlds(wrapper, contextElement, isolate);
  }
}

const V8DOMConfiguration::AccessorConfiguration V8SVGAnimatedNumberListAccessors[] = {
    {"baseVal", SVGAnimatedNumberListV8Internal::baseValAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"animVal", SVGAnimatedNumberListV8Internal::animValAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8SVGAnimatedNumberListTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGAnimatedNumberList::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8SVGAnimatedNumberList::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGAnimatedNumberListAccessors, WTF_ARRAY_LENGTH(V8SVGAnimatedNumberListAccessors));
}

v8::Local<v8::FunctionTemplate> V8SVGAnimatedNumberList::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGAnimatedNumberListTemplate);
}

bool V8SVGAnimatedNumberList::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGAnimatedNumberList::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGAnimatedNumberList* V8SVGAnimatedNumberList::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8NodeIterator.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/V8NodeFilter.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
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
const WrapperTypeInfo V8NodeIterator::wrapperTypeInfo = { gin::kEmbedderBlink, V8NodeIterator::domTemplate, V8NodeIterator::trace, V8NodeIterator::traceWrappers, V8NodeIterator::visitDOMWrapper, nullptr, "NodeIterator", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in NodeIterator.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& NodeIterator::s_wrapperTypeInfo = V8NodeIterator::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, NodeIterator>::value,
    "NodeIterator inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&NodeIterator::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "NodeIterator is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace NodeIteratorV8Internal {

static void rootAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NodeIterator* impl = V8NodeIterator::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->root()), impl);
}

CORE_EXPORT void rootAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIteratorV8Internal::rootAttributeGetter(info);
}

static void referenceNodeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NodeIterator* impl = V8NodeIterator::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->referenceNode()), impl);
}

CORE_EXPORT void referenceNodeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIteratorV8Internal::referenceNodeAttributeGetter(info);
}

static void pointerBeforeReferenceNodeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NodeIterator* impl = V8NodeIterator::toImpl(holder);

  v8SetReturnValueBool(info, impl->pointerBeforeReferenceNode());
}

CORE_EXPORT void pointerBeforeReferenceNodeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIteratorV8Internal::pointerBeforeReferenceNodeAttributeGetter(info);
}

static void whatToShowAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NodeIterator* impl = V8NodeIterator::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->whatToShow());
}

CORE_EXPORT void whatToShowAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIteratorV8Internal::whatToShowAttributeGetter(info);
}

static void filterAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  NodeIterator* impl = V8NodeIterator::toImpl(holder);

  v8SetReturnValueFast(info, WTF::getPtr(impl->filter()), impl);
}

CORE_EXPORT void filterAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIteratorV8Internal::filterAttributeGetter(info);
}

static void nextNodeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "NodeIterator", "nextNode");

  NodeIterator* impl = V8NodeIterator::toImpl(info.Holder());

  Node* result = impl->nextNode(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void nextNodeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIteratorV8Internal::nextNodeMethod(info);
}

static void previousNodeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "NodeIterator", "previousNode");

  NodeIterator* impl = V8NodeIterator::toImpl(info.Holder());

  Node* result = impl->previousNode(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void previousNodeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIteratorV8Internal::previousNodeMethod(info);
}

static void detachMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  NodeIterator* impl = V8NodeIterator::toImpl(info.Holder());

  impl->detach();
}

CORE_EXPORT  void detachMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::NodeIteratorDetach);
  NodeIteratorV8Internal::detachMethod(info);
}

} // namespace NodeIteratorV8Internal

void V8NodeIterator::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper) {
  NodeIterator* impl = scriptWrappable->toImpl<NodeIterator>();
  NodeFilter* filter = impl->filter();
  if (filter) {
    DOMWrapperWorld::setWrapperReferencesInAllWorlds(wrapper, filter, isolate);
  }
}

const V8DOMConfiguration::AccessorConfiguration V8NodeIteratorAccessors[] = {
    {"root", NodeIteratorV8Internal::rootAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"referenceNode", NodeIteratorV8Internal::referenceNodeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"pointerBeforeReferenceNode", NodeIteratorV8Internal::pointerBeforeReferenceNodeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"whatToShow", NodeIteratorV8Internal::whatToShowAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"filter", NodeIteratorV8Internal::filterAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8NodeIteratorMethods[] = {
    {"nextNode", NodeIteratorV8Internal::nextNodeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"previousNode", NodeIteratorV8Internal::previousNodeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"detach", NodeIteratorV8Internal::detachMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8NodeIteratorTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8NodeIterator::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8NodeIterator::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8NodeIteratorAccessors, WTF_ARRAY_LENGTH(V8NodeIteratorAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8NodeIteratorMethods, WTF_ARRAY_LENGTH(V8NodeIteratorMethods));
}

v8::Local<v8::FunctionTemplate> V8NodeIterator::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8NodeIteratorTemplate);
}

bool V8NodeIterator::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8NodeIterator::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

NodeIterator* V8NodeIterator::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

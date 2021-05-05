// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8IDBOpenDBRequest.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8EventListenerHelper.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
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
const WrapperTypeInfo V8IDBOpenDBRequest::wrapperTypeInfo = { gin::kEmbedderBlink, V8IDBOpenDBRequest::domTemplate, V8IDBOpenDBRequest::trace, V8IDBOpenDBRequest::traceWrappers, 0, nullptr, "IDBOpenDBRequest", &V8IDBRequest::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::InheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in IDBOpenDBRequest.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& IDBOpenDBRequest::s_wrapperTypeInfo = V8IDBOpenDBRequest::wrapperTypeInfo;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, IDBOpenDBRequest>::value,
    "IDBOpenDBRequest does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&IDBOpenDBRequest::hasPendingActivity),
                  decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "IDBOpenDBRequest is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace IDBOpenDBRequestV8Internal {

static void onblockedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  IDBOpenDBRequest* impl = V8IDBOpenDBRequest::toImpl(holder);

  EventListener* cppValue(WTF::getPtr(impl->onblocked()));

  v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
}

MODULES_EXPORT void onblockedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  IDBOpenDBRequestV8Internal::onblockedAttributeGetter(info);
}

static void onblockedAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  IDBOpenDBRequest* impl = V8IDBOpenDBRequest::toImpl(holder);

  // Prepare the value to be set.
  moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onblocked(), v8Value, V8IDBOpenDBRequest::eventListenerCacheIndex);

  impl->setOnblocked(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
}

MODULES_EXPORT void onblockedAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  IDBOpenDBRequestV8Internal::onblockedAttributeSetter(v8Value, info);
}

static void onupgradeneededAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  IDBOpenDBRequest* impl = V8IDBOpenDBRequest::toImpl(holder);

  EventListener* cppValue(WTF::getPtr(impl->onupgradeneeded()));

  v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
}

MODULES_EXPORT void onupgradeneededAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  IDBOpenDBRequestV8Internal::onupgradeneededAttributeGetter(info);
}

static void onupgradeneededAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  IDBOpenDBRequest* impl = V8IDBOpenDBRequest::toImpl(holder);

  // Prepare the value to be set.
  moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onupgradeneeded(), v8Value, V8IDBOpenDBRequest::eventListenerCacheIndex);

  impl->setOnupgradeneeded(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
}

MODULES_EXPORT void onupgradeneededAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  IDBOpenDBRequestV8Internal::onupgradeneededAttributeSetter(v8Value, info);
}

} // namespace IDBOpenDBRequestV8Internal

const V8DOMConfiguration::AccessorConfiguration V8IDBOpenDBRequestAccessors[] = {
    {"onblocked", IDBOpenDBRequestV8Internal::onblockedAttributeGetterCallback, IDBOpenDBRequestV8Internal::onblockedAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"onupgradeneeded", IDBOpenDBRequestV8Internal::onupgradeneededAttributeGetterCallback, IDBOpenDBRequestV8Internal::onupgradeneededAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8IDBOpenDBRequestTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8IDBOpenDBRequest::wrapperTypeInfo.interfaceName, V8IDBRequest::domTemplate(isolate, world), V8IDBOpenDBRequest::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8IDBOpenDBRequestAccessors, WTF_ARRAY_LENGTH(V8IDBOpenDBRequestAccessors));
}

v8::Local<v8::FunctionTemplate> V8IDBOpenDBRequest::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8IDBOpenDBRequestTemplate);
}

bool V8IDBOpenDBRequest::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8IDBOpenDBRequest::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

IDBOpenDBRequest* V8IDBOpenDBRequest::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

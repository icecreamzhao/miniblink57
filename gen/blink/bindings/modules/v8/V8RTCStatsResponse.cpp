// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8RTCStatsResponse.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8RTCLegacyStatsReport.h"
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
const WrapperTypeInfo V8RTCStatsResponse::wrapperTypeInfo = { gin::kEmbedderBlink, V8RTCStatsResponse::domTemplate, V8RTCStatsResponse::trace, V8RTCStatsResponse::traceWrappers, 0, nullptr, "RTCStatsResponse", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in RTCStatsResponse.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& RTCStatsResponse::s_wrapperTypeInfo = V8RTCStatsResponse::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, RTCStatsResponse>::value,
    "RTCStatsResponse inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&RTCStatsResponse::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "RTCStatsResponse is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace RTCStatsResponseV8Internal {

static void resultMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RTCStatsResponse* impl = V8RTCStatsResponse::toImpl(info.Holder());

  v8SetReturnValue(info, ToV8(impl->result(), info.Holder(), info.GetIsolate()));
}

MODULES_EXPORT  void resultMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RTCStatsResponseV8Internal::resultMethod(info);
}

static void namedItemMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RTCStatsResponse* impl = V8RTCStatsResponse::toImpl(info.Holder());

  V8StringResource<> name;
  name = info[0];
  if (!name.prepare())
    return;

  v8SetReturnValue(info, impl->namedItem(name));
}

MODULES_EXPORT  void namedItemMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RTCStatsResponseV8Internal::namedItemMethod(info);
}

static void namedPropertyGetter(const AtomicString& name, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RTCStatsResponse* impl = V8RTCStatsResponse::toImpl(info.Holder());
  RTCLegacyStatsReport* result = impl->namedItem(name);
  if (!result)
    return;
  v8SetReturnValueFast(info, result, impl);
}

MODULES_EXPORT void namedPropertyGetterCallback(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info) {
  if (!name->IsString())
    return;
  const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

  RTCStatsResponseV8Internal::namedPropertyGetter(propertyName, info);
}

MODULES_EXPORT void indexedPropertyGetterCallback(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info) {
  const AtomicString& propertyName = AtomicString::number(index);

  RTCStatsResponseV8Internal::namedPropertyGetter(propertyName, info);
}

} // namespace RTCStatsResponseV8Internal

const V8DOMConfiguration::MethodConfiguration V8RTCStatsResponseMethods[] = {
    {"result", RTCStatsResponseV8Internal::resultMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"namedItem", RTCStatsResponseV8Internal::namedItemMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8RTCStatsResponseTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8RTCStatsResponse::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8RTCStatsResponse::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8RTCStatsResponseMethods, WTF_ARRAY_LENGTH(V8RTCStatsResponseMethods));

  // Indexed properties
  v8::IndexedPropertyHandlerConfiguration indexedPropertyHandlerConfig(RTCStatsResponseV8Internal::indexedPropertyGetterCallback, 0, 0, 0, 0, v8::Local<v8::Value>(), v8::PropertyHandlerFlags::kNone);
  instanceTemplate->SetHandler(indexedPropertyHandlerConfig);
  // Named properties
  v8::NamedPropertyHandlerConfiguration namedPropertyHandlerConfig(RTCStatsResponseV8Internal::namedPropertyGetterCallback, 0, 0, 0, 0, v8::Local<v8::Value>(), static_cast<v8::PropertyHandlerFlags>(int(v8::PropertyHandlerFlags::kOnlyInterceptStrings) | int(v8::PropertyHandlerFlags::kNonMasking)));
  instanceTemplate->SetHandler(namedPropertyHandlerConfig);
}

v8::Local<v8::FunctionTemplate> V8RTCStatsResponse::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8RTCStatsResponseTemplate);
}

bool V8RTCStatsResponse::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8RTCStatsResponse::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

RTCStatsResponse* V8RTCStatsResponse::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

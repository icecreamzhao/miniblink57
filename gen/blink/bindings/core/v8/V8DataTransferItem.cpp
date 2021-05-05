// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8DataTransferItem.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8Blob.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8StringCallback.h"
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
WrapperTypeInfo V8DataTransferItem::wrapperTypeInfo = { gin::kEmbedderBlink, V8DataTransferItem::domTemplate, V8DataTransferItem::trace, V8DataTransferItem::traceWrappers, 0, nullptr, "DataTransferItem", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DataTransferItem.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& DataTransferItem::s_wrapperTypeInfo = V8DataTransferItem::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DataTransferItem>::value,
    "DataTransferItem inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DataTransferItem::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DataTransferItem is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace DataTransferItemV8Internal {

static void kindAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DataTransferItem* impl = V8DataTransferItem::toImpl(holder);

  v8SetReturnValueString(info, impl->kind(), info.GetIsolate());
}

CORE_EXPORT void kindAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DataTransferItemV8Internal::kindAttributeGetter(info);
}

static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DataTransferItem* impl = V8DataTransferItem::toImpl(holder);

  v8SetReturnValueString(info, impl->type(), info.GetIsolate());
}

CORE_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DataTransferItemV8Internal::typeAttributeGetter(info);
}

static void getAsStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DataTransferItem* impl = V8DataTransferItem::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getAsString", "DataTransferItem", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  StringCallback* callback;
  if (info.Length() <= 0 || !(info[0]->IsFunction() || info[0]->IsNull())) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getAsString", "DataTransferItem", "The callback provided as parameter 1 is not a function."));

    return;
  }
  callback = info[0]->IsNull() ? nullptr : V8StringCallback::create(v8::Local<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));

  impl->getAsString(scriptState, callback);
}

CORE_EXPORT  void getAsStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DataTransferItemV8Internal::getAsStringMethod(info);
}

static void getAsFileMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DataTransferItem* impl = V8DataTransferItem::toImpl(info.Holder());

  v8SetReturnValue(info, impl->getAsFile());
}

CORE_EXPORT  void getAsFileMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DataTransferItemV8Internal::getAsFileMethod(info);
}

} // namespace DataTransferItemV8Internal

const V8DOMConfiguration::AccessorConfiguration V8DataTransferItemAccessors[] = {
    {"kind", DataTransferItemV8Internal::kindAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"type", DataTransferItemV8Internal::typeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8DataTransferItemMethods[] = {
    {"getAsString", DataTransferItemV8Internal::getAsStringMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"getAsFile", DataTransferItemV8Internal::getAsFileMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

void V8DataTransferItem::installV8DataTransferItemTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8DataTransferItem::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8DataTransferItem::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DataTransferItemAccessors, WTF_ARRAY_LENGTH(V8DataTransferItemAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DataTransferItemMethods, WTF_ARRAY_LENGTH(V8DataTransferItemMethods));
}

v8::Local<v8::FunctionTemplate> V8DataTransferItem::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), V8DataTransferItem::installV8DataTransferItemTemplateFunction);
}

bool V8DataTransferItem::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8DataTransferItem::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

DataTransferItem* V8DataTransferItem::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

InstallTemplateFunction V8DataTransferItem::installV8DataTransferItemTemplateFunction = (InstallTemplateFunction)&V8DataTransferItem::installV8DataTransferItemTemplate;

void V8DataTransferItem::updateWrapperTypeInfo(InstallTemplateFunction installTemplateFunction, PreparePrototypeAndInterfaceObjectFunction preparePrototypeAndInterfaceObjectFunction) {
  V8DataTransferItem::installV8DataTransferItemTemplateFunction = installTemplateFunction;
  if (preparePrototypeAndInterfaceObjectFunction)
    V8DataTransferItem::wrapperTypeInfo.preparePrototypeAndInterfaceObjectFunction = preparePrototypeAndInterfaceObjectFunction;
}

}  // namespace blink

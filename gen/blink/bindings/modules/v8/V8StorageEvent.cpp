// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8StorageEvent.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8Storage.h"
#include "bindings/modules/v8/V8StorageEventInit.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
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
const WrapperTypeInfo V8StorageEvent::wrapperTypeInfo = { gin::kEmbedderBlink, V8StorageEvent::domTemplate, V8StorageEvent::trace, V8StorageEvent::traceWrappers, 0, nullptr, "StorageEvent", &V8Event::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in StorageEvent.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& StorageEvent::s_wrapperTypeInfo = V8StorageEvent::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, StorageEvent>::value,
    "StorageEvent inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&StorageEvent::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "StorageEvent is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace StorageEventV8Internal {

static void keyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  StorageEvent* impl = V8StorageEvent::toImpl(holder);

  v8SetReturnValueStringOrNull(info, impl->key(), info.GetIsolate());
}

MODULES_EXPORT void keyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  StorageEventV8Internal::keyAttributeGetter(info);
}

static void oldValueAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  StorageEvent* impl = V8StorageEvent::toImpl(holder);

  v8SetReturnValueStringOrNull(info, impl->oldValue(), info.GetIsolate());
}

MODULES_EXPORT void oldValueAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  StorageEventV8Internal::oldValueAttributeGetter(info);
}

static void newValueAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  StorageEvent* impl = V8StorageEvent::toImpl(holder);

  v8SetReturnValueStringOrNull(info, impl->newValue(), info.GetIsolate());
}

MODULES_EXPORT void newValueAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  StorageEventV8Internal::newValueAttributeGetter(info);
}

static void urlAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  StorageEvent* impl = V8StorageEvent::toImpl(holder);

  v8SetReturnValueString(info, impl->url(), info.GetIsolate());
}

MODULES_EXPORT void urlAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  StorageEventV8Internal::urlAttributeGetter(info);
}

static void storageAreaAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  StorageEvent* impl = V8StorageEvent::toImpl(holder);

  Storage* cppValue(WTF::getPtr(impl->storageArea()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
    return;
  v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
  const char kKeepAliveKey[] = "KeepAlive#StorageEvent#storageArea";
  V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

  v8SetReturnValue(info, v8Value);
}

MODULES_EXPORT void storageAreaAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  StorageEventV8Internal::storageAreaAttributeGetter(info);
}

static void initStorageEventMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "StorageEvent", "initStorageEvent");

  StorageEvent* impl = V8StorageEvent::toImpl(info.Holder());

  V8StringResource<> typeArg;
  bool canBubbleArg;
  bool cancelableArg;
  V8StringResource<> keyArg;
  V8StringResource<TreatNullAndUndefinedAsNullString> oldValueArg;
  V8StringResource<TreatNullAndUndefinedAsNullString> newValueArg;
  V8StringResource<> urlArg;
  Storage* storageAreaArg;
  typeArg = info[0];
  if (!typeArg.prepare())
    return;

  canBubbleArg = toBoolean(info.GetIsolate(), info[1], exceptionState);
  if (exceptionState.hadException())
    return;

  cancelableArg = toBoolean(info.GetIsolate(), info[2], exceptionState);
  if (exceptionState.hadException())
    return;

  keyArg = info[3];
  if (!keyArg.prepare())
    return;

  oldValueArg = info[4];
  if (!oldValueArg.prepare())
    return;

  newValueArg = info[5];
  if (!newValueArg.prepare())
    return;

  urlArg = info[6];
  if (!urlArg.prepare())
    return;

  storageAreaArg = V8Storage::toImplWithTypeCheck(info.GetIsolate(), info[7]);

  impl->initStorageEvent(typeArg, canBubbleArg, cancelableArg, keyArg, oldValueArg, newValueArg, urlArg, storageAreaArg);
}

MODULES_EXPORT  void initStorageEventMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8StorageEvent_InitStorageEvent_Method);
  StorageEventV8Internal::initStorageEventMethod(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "StorageEvent");

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> type;
  StorageEventInit eventInitDict;
  type = info[0];
  if (!type.prepare())
    return;

  if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
    exceptionState.throwTypeError("parameter 2 ('eventInitDict') is not an object.");

    return;
  }
  V8StorageEventInit::toImpl(info.GetIsolate(), info[1], eventInitDict, exceptionState);
  if (exceptionState.hadException())
    return;

  StorageEvent* impl = StorageEvent::create(type, eventInitDict);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8StorageEvent::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace StorageEventV8Internal

const V8DOMConfiguration::AccessorConfiguration V8StorageEventAccessors[] = {
    {"key", StorageEventV8Internal::keyAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"oldValue", StorageEventV8Internal::oldValueAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"newValue", StorageEventV8Internal::newValueAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"url", StorageEventV8Internal::urlAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"storageArea", StorageEventV8Internal::storageAreaAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8StorageEventMethods[] = {
    {"initStorageEvent", StorageEventV8Internal::initStorageEventMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

void V8StorageEvent::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("StorageEvent"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  StorageEventV8Internal::constructor(info);
}

static void installV8StorageEventTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8StorageEvent::wrapperTypeInfo.interfaceName, V8Event::domTemplate(isolate, world), V8StorageEvent::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8StorageEvent::constructorCallback);
  interfaceTemplate->SetLength(1);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8StorageEventAccessors, WTF_ARRAY_LENGTH(V8StorageEventAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8StorageEventMethods, WTF_ARRAY_LENGTH(V8StorageEventMethods));
}

v8::Local<v8::FunctionTemplate> V8StorageEvent::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8StorageEventTemplate);
}

bool V8StorageEvent::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8StorageEvent::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

StorageEvent* V8StorageEvent::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

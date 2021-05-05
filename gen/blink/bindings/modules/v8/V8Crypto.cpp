// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8Crypto.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8ArrayBufferView.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8SubtleCrypto.h"
#include "core/dom/Document.h"
#include "core/dom/FlexibleArrayBufferView.h"
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
const WrapperTypeInfo V8Crypto::wrapperTypeInfo = { gin::kEmbedderBlink, V8Crypto::domTemplate, V8Crypto::trace, V8Crypto::traceWrappers, 0, nullptr, "Crypto", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in Crypto.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& Crypto::s_wrapperTypeInfo = V8Crypto::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, Crypto>::value,
    "Crypto inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&Crypto::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "Crypto is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace CryptoV8Internal {

static void subtleAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Crypto* impl = V8Crypto::toImpl(holder);

  SubtleCrypto* cppValue(WTF::getPtr(impl->subtle()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
    return;
  v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
  const char kKeepAliveKey[] = "KeepAlive#Crypto#subtle";
  V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

  v8SetReturnValue(info, v8Value);
}

MODULES_EXPORT void subtleAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  CryptoV8Internal::subtleAttributeGetter(info);
}

static void getRandomValuesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Crypto", "getRandomValues");

  Crypto* impl = V8Crypto::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  DOMArrayBufferView* array;
  array = info[0]->IsArrayBufferView() ? V8ArrayBufferView::toImpl(v8::Local<v8::ArrayBufferView>::Cast(info[0])) : 0;
  if (!array) {
    exceptionState.throwTypeError("parameter 1 is not of type 'ArrayBufferView'.");

    return;
  }

  DOMArrayBufferView* result = impl->getRandomValues(array, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

MODULES_EXPORT  void getRandomValuesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::CryptoGetRandomValues);
  CryptoV8Internal::getRandomValuesMethod(info);
}

} // namespace CryptoV8Internal

const V8DOMConfiguration::AccessorConfiguration V8CryptoAccessors[] = {
    {"subtle", CryptoV8Internal::subtleAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8CryptoMethods[] = {
    {"getRandomValues", CryptoV8Internal::getRandomValuesMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8CryptoTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8Crypto::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8Crypto::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CryptoAccessors, WTF_ARRAY_LENGTH(V8CryptoAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CryptoMethods, WTF_ARRAY_LENGTH(V8CryptoMethods));
}

v8::Local<v8::FunctionTemplate> V8Crypto::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8CryptoTemplate);
}

bool V8Crypto::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8Crypto::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

Crypto* V8Crypto::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

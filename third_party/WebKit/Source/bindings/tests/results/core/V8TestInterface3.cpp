// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8TestInterface3.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Document.h"
#include "bindings/core/v8/V8Iterator.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8TestInterface3::wrapperTypeInfo = { gin::kEmbedderBlink, V8TestInterface3::domTemplate, V8TestInterface3::trace, V8TestInterface3::traceWrappers, V8TestInterface3::visitDOMWrapper, nullptr, "TestInterface3", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in TestInterface3.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& TestInterface3::s_wrapperTypeInfo = V8TestInterface3::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, TestInterface3>::value,
    "TestInterface3 inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&TestInterface3::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "TestInterface3 is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace TestInterface3V8Internal {

static void readonlyStringifierAttributeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  TestInterface3* impl = V8TestInterface3::toImpl(holder);

  v8SetReturnValueString(info, impl->readonlyStringifierAttribute(), info.GetIsolate());
}

CORE_EXPORT void readonlyStringifierAttributeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::readonlyStringifierAttributeAttributeGetter(info);
}

static void voidMethodDocumentMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3* impl = V8TestInterface3::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("voidMethodDocument", "TestInterface3", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  Document* document;
  document = V8Document::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!document) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("voidMethodDocument", "TestInterface3", "parameter 1 is not of type 'Document'."));

    return;
  }

  impl->voidMethodDocument(document);
}

CORE_EXPORT  void voidMethodDocumentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::voidMethodDocumentMethod(info);
}

static void keysMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "TestInterface3", "keys");

  TestInterface3* impl = V8TestInterface3::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  Iterator* result = impl->iterableKeys(scriptState, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void keysMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::keysMethod(info);
}

static void valuesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "TestInterface3", "values");

  TestInterface3* impl = V8TestInterface3::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  Iterator* result = impl->valuesForBinding(scriptState, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void valuesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::valuesMethod(info);
}

static void entriesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "TestInterface3", "entries");

  TestInterface3* impl = V8TestInterface3::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  Iterator* result = impl->entriesForBinding(scriptState, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void entriesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::entriesMethod(info);
}

static void forEachMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "TestInterface3", "forEach");

  TestInterface3* impl = V8TestInterface3::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  ScriptValue callback;
  ScriptValue thisArg;
  if (!(info[0]->IsObject() && v8::Local<v8::Object>::Cast(info[0])->IsCallable())) {
    exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

    return;
  }
  callback = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

  thisArg = ScriptValue(ScriptState::current(info.GetIsolate()), info[1]);

  impl->forEachForBinding(scriptState, ScriptValue(scriptState, info.Holder()), callback, thisArg, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void forEachMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::forEachMethod(info);
}

static void toStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3* impl = V8TestInterface3::toImpl(info.Holder());

  v8SetReturnValueString(info, impl->readonlyStringifierAttribute(), info.GetIsolate());
}

CORE_EXPORT  void toStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::toStringMethod(info);
}

static void iteratorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "TestInterface3", "iterator");

  TestInterface3* impl = V8TestInterface3::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  Iterator* result = impl->iterator(scriptState, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void iteratorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TestInterface3V8Internal::iteratorMethod(info);
}

CORE_EXPORT void namedPropertyGetterCallback(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info) {
  if (!name->IsString())
    return;
  const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

  V8TestInterface3::namedPropertyGetterCustom(propertyName, info);
}

CORE_EXPORT void namedPropertySetterCallback(v8::Local<v8::Name> name, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info) {
  if (!name->IsString())
    return;
  const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

  V8TestInterface3::namedPropertySetterCustom(propertyName, v8Value, info);
}

CORE_EXPORT void namedPropertyDeleterCallback(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Boolean>& info) {
  if (!name->IsString())
    return;
  const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

  V8TestInterface3::namedPropertyDeleterCustom(propertyName, info);
}

CORE_EXPORT void namedPropertyQueryCallback(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Integer>& info) {
  if (!name->IsString())
    return;
  const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

  V8TestInterface3::namedPropertyQueryCustom(propertyName, info);
}

CORE_EXPORT void namedPropertyEnumeratorCallback(const v8::PropertyCallbackInfo<v8::Array>& info) {
  V8TestInterface3::namedPropertyEnumeratorCustom(info);
}

CORE_EXPORT void indexedPropertyGetterCallback(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info) {
  V8TestInterface3::indexedPropertyGetterCustom(index, info);
}

CORE_EXPORT void indexedPropertySetterCallback(uint32_t index, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info) {
  V8TestInterface3::indexedPropertySetterCustom(index, v8Value, info);
}

CORE_EXPORT void indexedPropertyDeleterCallback(uint32_t index, const v8::PropertyCallbackInfo<v8::Boolean>& info) {
  V8TestInterface3::indexedPropertyDeleterCustom(index, info);
}

} // namespace TestInterface3V8Internal

void V8TestInterface3::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper) {
  V8TestInterface3::visitDOMWrapperCustom(isolate, scriptWrappable, wrapper);
}

const V8DOMConfiguration::AccessorConfiguration V8TestInterface3Accessors[] = {
    {"readonlyStringifierAttribute", TestInterface3V8Internal::readonlyStringifierAttributeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8TestInterface3Methods[] = {
    {"voidMethodDocument", TestInterface3V8Internal::voidMethodDocumentMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"toString", TestInterface3V8Internal::toStringMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8TestInterface3Template(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8TestInterface3::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8TestInterface3::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8TestInterface3Accessors, WTF_ARRAY_LENGTH(V8TestInterface3Accessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8TestInterface3Methods, WTF_ARRAY_LENGTH(V8TestInterface3Methods));

  // Indexed properties
  v8::IndexedPropertyHandlerConfiguration indexedPropertyHandlerConfig(TestInterface3V8Internal::indexedPropertyGetterCallback, TestInterface3V8Internal::indexedPropertySetterCallback, 0, TestInterface3V8Internal::indexedPropertyDeleterCallback, indexedPropertyEnumerator<TestInterface3>, v8::Local<v8::Value>(), v8::PropertyHandlerFlags::kNone);
  instanceTemplate->SetHandler(indexedPropertyHandlerConfig);
  // Named properties
  v8::NamedPropertyHandlerConfiguration namedPropertyHandlerConfig(TestInterface3V8Internal::namedPropertyGetterCallback, TestInterface3V8Internal::namedPropertySetterCallback, TestInterface3V8Internal::namedPropertyQueryCallback, TestInterface3V8Internal::namedPropertyDeleterCallback, TestInterface3V8Internal::namedPropertyEnumeratorCallback, v8::Local<v8::Value>(), static_cast<v8::PropertyHandlerFlags>(int(v8::PropertyHandlerFlags::kOnlyInterceptStrings) | int(v8::PropertyHandlerFlags::kNonMasking)));
  instanceTemplate->SetHandler(namedPropertyHandlerConfig);

  if (RuntimeEnabledFeatures::featureNameEnabled()) {
    // Iterator (@@iterator)
    const V8DOMConfiguration::SymbolKeyedMethodConfiguration symbolKeyedIteratorConfiguration = { v8::Symbol::GetIterator, TestInterface3V8Internal::iteratorMethodCallback, 0, v8::DontEnum, V8DOMConfiguration::OnPrototype };
    V8DOMConfiguration::installMethod(isolate, world, prototypeTemplate, signature, symbolKeyedIteratorConfiguration);
  }

  if (RuntimeEnabledFeatures::featureNameEnabled()) {
    const V8DOMConfiguration::MethodConfiguration keysMethodConfiguration = {"keys", TestInterface3V8Internal::keysMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, keysMethodConfiguration);
  }
  if (RuntimeEnabledFeatures::featureNameEnabled()) {
    const V8DOMConfiguration::MethodConfiguration valuesMethodConfiguration = {"values", TestInterface3V8Internal::valuesMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, valuesMethodConfiguration);
  }
  if (RuntimeEnabledFeatures::featureNameEnabled()) {
    const V8DOMConfiguration::MethodConfiguration entriesMethodConfiguration = {"entries", TestInterface3V8Internal::entriesMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, entriesMethodConfiguration);
  }
  if (RuntimeEnabledFeatures::featureNameEnabled()) {
    const V8DOMConfiguration::MethodConfiguration forEachMethodConfiguration = {"forEach", TestInterface3V8Internal::forEachMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, forEachMethodConfiguration);
  }
}

v8::Local<v8::FunctionTemplate> V8TestInterface3::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8TestInterface3Template);
}

bool V8TestInterface3::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8TestInterface3::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TestInterface3* V8TestInterface3::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

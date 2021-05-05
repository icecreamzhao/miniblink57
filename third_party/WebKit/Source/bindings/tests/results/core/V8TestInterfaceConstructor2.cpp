// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8TestInterfaceConstructor2.h"

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8TestInterfaceEmpty.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8TestInterfaceConstructor2::wrapperTypeInfo = { gin::kEmbedderBlink, V8TestInterfaceConstructor2::domTemplate, V8TestInterfaceConstructor2::trace, V8TestInterfaceConstructor2::traceWrappers, 0, nullptr, "TestInterfaceConstructor2", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in TestInterfaceConstructor2.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& TestInterfaceConstructor2::s_wrapperTypeInfo = V8TestInterfaceConstructor2::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, TestInterfaceConstructor2>::value,
    "TestInterfaceConstructor2 inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&TestInterfaceConstructor2::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "TestInterfaceConstructor2 is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace TestInterfaceConstructor2V8Internal {

static void constructor1(const v8::FunctionCallbackInfo<v8::Value>& info) {
  V8StringResource<> stringArg;
  stringArg = info[0];
  if (!stringArg.prepare())
    return;

  TestInterfaceConstructor2* impl = TestInterfaceConstructor2::create(stringArg);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8TestInterfaceConstructor2::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

static void constructor2(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "TestInterfaceConstructor2");

  Dictionary dictionaryArg;
  if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
    exceptionState.throwTypeError("parameter 1 ('dictionaryArg') is not an object.");

    return;
  }
  dictionaryArg = Dictionary(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  TestInterfaceConstructor2* impl = TestInterfaceConstructor2::create(dictionaryArg);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8TestInterfaceConstructor2::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

static void constructor3(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "TestInterfaceConstructor2");

  Vector<Vector<String>> stringSequenceSequenceArg;
  stringSequenceSequenceArg = toImplArray<Vector<Vector<String>>>(info[0], 1, info.GetIsolate(), exceptionState);
  if (exceptionState.hadException())
    return;

  TestInterfaceConstructor2* impl = TestInterfaceConstructor2::create(stringSequenceSequenceArg);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8TestInterfaceConstructor2::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

static void constructor4(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "TestInterfaceConstructor2");

  TestInterfaceEmpty* testInterfaceEmptyArg;
  int longArg;
  V8StringResource<> defaultUndefinedOptionalStringArg;
  V8StringResource<> defaultNullStringOptionalStringArg;
  Dictionary defaultUndefinedOptionalDictionaryArg;
  V8StringResource<> optionalStringArg;
  int numArgsPassed = info.Length();
  while (numArgsPassed > 0) {
    if (!info[numArgsPassed - 1]->IsUndefined())
      break;
    --numArgsPassed;
  }
  testInterfaceEmptyArg = V8TestInterfaceEmpty::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!testInterfaceEmptyArg) {
    exceptionState.throwTypeError("parameter 1 is not of type 'TestInterfaceEmpty'.");

    return;
  }

  longArg = toInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  defaultUndefinedOptionalStringArg = info[2];
  if (!defaultUndefinedOptionalStringArg.prepare())
    return;

  if (!info[3]->IsUndefined()) {
    defaultNullStringOptionalStringArg = info[3];
    if (!defaultNullStringOptionalStringArg.prepare())
      return;
  } else {
    defaultNullStringOptionalStringArg = nullptr;
  }
  if (!isUndefinedOrNull(info[4]) && !info[4]->IsObject()) {
    exceptionState.throwTypeError("parameter 5 ('defaultUndefinedOptionalDictionaryArg') is not an object.");

    return;
  }
  defaultUndefinedOptionalDictionaryArg = Dictionary(info.GetIsolate(), info[4], exceptionState);
  if (exceptionState.hadException())
    return;

  if (UNLIKELY(numArgsPassed <= 5)) {
    TestInterfaceConstructor2* impl = TestInterfaceConstructor2::create(testInterfaceEmptyArg, longArg, defaultUndefinedOptionalStringArg, defaultNullStringOptionalStringArg, defaultUndefinedOptionalDictionaryArg);
    v8::Local<v8::Object> wrapper = info.Holder();
    wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8TestInterfaceConstructor2::wrapperTypeInfo, wrapper);
    v8SetReturnValue(info, wrapper);
    return;
  }
  optionalStringArg = info[5];
  if (!optionalStringArg.prepare())
    return;

  TestInterfaceConstructor2* impl = TestInterfaceConstructor2::create(testInterfaceEmptyArg, longArg, defaultUndefinedOptionalStringArg, defaultNullStringOptionalStringArg, defaultUndefinedOptionalDictionaryArg, optionalStringArg);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8TestInterfaceConstructor2::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "TestInterfaceConstructor2");
  switch (std::min(6, info.Length())) {
    case 1:
      if (info[0]->IsArray()) {
        TestInterfaceConstructor2V8Internal::constructor3(info);
        return;
      }
      if (info[0]->IsObject()) {
        TestInterfaceConstructor2V8Internal::constructor2(info);
        return;
      }
      if (true) {
        TestInterfaceConstructor2V8Internal::constructor1(info);
        return;
      }
      break;
    case 2:
      if (true) {
        TestInterfaceConstructor2V8Internal::constructor4(info);
        return;
      }
      break;
    case 3:
      if (true) {
        TestInterfaceConstructor2V8Internal::constructor4(info);
        return;
      }
      break;
    case 4:
      if (true) {
        TestInterfaceConstructor2V8Internal::constructor4(info);
        return;
      }
      break;
    case 5:
      if (true) {
        TestInterfaceConstructor2V8Internal::constructor4(info);
        return;
      }
      break;
    case 6:
      if (true) {
        TestInterfaceConstructor2V8Internal::constructor4(info);
        return;
      }
      break;
    default:
      exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
      return;
  }
  exceptionState.throwTypeError("No matching constructor signature.");
}

} // namespace TestInterfaceConstructor2V8Internal

void V8TestInterfaceConstructor2::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("TestInterfaceConstructor2"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  TestInterfaceConstructor2V8Internal::constructor(info);
}

static void installV8TestInterfaceConstructor2Template(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8TestInterfaceConstructor2::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8TestInterfaceConstructor2::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8TestInterfaceConstructor2::constructorCallback);
  interfaceTemplate->SetLength(1);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
}

v8::Local<v8::FunctionTemplate> V8TestInterfaceConstructor2::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8TestInterfaceConstructor2Template);
}

bool V8TestInterfaceConstructor2::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8TestInterfaceConstructor2::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TestInterfaceConstructor2* V8TestInterfaceConstructor2::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8TimeRanges.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
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
const WrapperTypeInfo V8TimeRanges::wrapperTypeInfo = { gin::kEmbedderBlink, V8TimeRanges::domTemplate, V8TimeRanges::trace, V8TimeRanges::traceWrappers, 0, nullptr, "TimeRanges", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in TimeRanges.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& TimeRanges::s_wrapperTypeInfo = V8TimeRanges::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, TimeRanges>::value,
    "TimeRanges inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&TimeRanges::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "TimeRanges is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace TimeRangesV8Internal {

static void lengthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  TimeRanges* impl = V8TimeRanges::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->length());
}

CORE_EXPORT void lengthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TimeRangesV8Internal::lengthAttributeGetter(info);
}

static void startMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "TimeRanges", "start");

  TimeRanges* impl = V8TimeRanges::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  unsigned index;
  index = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  double result = impl->start(index, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void startMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TimeRangesV8Internal::startMethod(info);
}

static void endMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "TimeRanges", "end");

  TimeRanges* impl = V8TimeRanges::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  unsigned index;
  index = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  double result = impl->end(index, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

CORE_EXPORT  void endMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TimeRangesV8Internal::endMethod(info);
}

} // namespace TimeRangesV8Internal

const V8DOMConfiguration::AccessorConfiguration V8TimeRangesAccessors[] = {
    {"length", TimeRangesV8Internal::lengthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8TimeRangesMethods[] = {
    {"start", TimeRangesV8Internal::startMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"end", TimeRangesV8Internal::endMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8TimeRangesTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8TimeRanges::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8TimeRanges::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8TimeRangesAccessors, WTF_ARRAY_LENGTH(V8TimeRangesAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8TimeRangesMethods, WTF_ARRAY_LENGTH(V8TimeRangesMethods));
}

v8::Local<v8::FunctionTemplate> V8TimeRanges::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8TimeRangesTemplate);
}

bool V8TimeRanges::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8TimeRanges::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TimeRanges* V8TimeRanges::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8DelayNode.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8AudioParam.h"
#include "bindings/modules/v8/V8BaseAudioContext.h"
#include "bindings/modules/v8/V8DelayOptions.h"
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
const WrapperTypeInfo V8DelayNode::wrapperTypeInfo = { gin::kEmbedderBlink, V8DelayNode::domTemplate, V8DelayNode::trace, V8DelayNode::traceWrappers, 0, nullptr, "DelayNode", &V8AudioNode::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DelayNode.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& DelayNode::s_wrapperTypeInfo = V8DelayNode::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DelayNode>::value,
    "DelayNode inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DelayNode::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DelayNode is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace DelayNodeV8Internal {

static void delayTimeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DelayNode* impl = V8DelayNode::toImpl(holder);

  AudioParam* cppValue(WTF::getPtr(impl->delayTime()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
    return;
  v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
  const char kKeepAliveKey[] = "KeepAlive#DelayNode#delayTime";
  V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

  v8SetReturnValue(info, v8Value);
}

MODULES_EXPORT void delayTimeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DelayNodeV8Internal::delayTimeAttributeGetter(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "DelayNode");

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  BaseAudioContext* context;
  DelayOptions options;
  context = V8BaseAudioContext::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!context) {
    exceptionState.throwTypeError("parameter 1 is not of type 'BaseAudioContext'.");

    return;
  }

  if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
    exceptionState.throwTypeError("parameter 2 ('options') is not an object.");

    return;
  }
  V8DelayOptions::toImpl(info.GetIsolate(), info[1], options, exceptionState);
  if (exceptionState.hadException())
    return;

  DelayNode* impl = DelayNode::create(context, options, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8DelayNode::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace DelayNodeV8Internal

const V8DOMConfiguration::AccessorConfiguration V8DelayNodeAccessors[] = {
    {"delayTime", DelayNodeV8Internal::delayTimeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

void V8DelayNode::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8DelayNode_Constructor);
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("DelayNode"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  DelayNodeV8Internal::constructor(info);
}

static void installV8DelayNodeTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8DelayNode::wrapperTypeInfo.interfaceName, V8AudioNode::domTemplate(isolate, world), V8DelayNode::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8DelayNode::constructorCallback);
  interfaceTemplate->SetLength(1);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DelayNodeAccessors, WTF_ARRAY_LENGTH(V8DelayNodeAccessors));
}

v8::Local<v8::FunctionTemplate> V8DelayNode::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8DelayNodeTemplate);
}

bool V8DelayNode::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8DelayNode::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

DelayNode* V8DelayNode::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

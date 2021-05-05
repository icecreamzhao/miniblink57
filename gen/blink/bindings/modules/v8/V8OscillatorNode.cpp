// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8OscillatorNode.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8AudioParam.h"
#include "bindings/modules/v8/V8BaseAudioContext.h"
#include "bindings/modules/v8/V8OscillatorOptions.h"
#include "bindings/modules/v8/V8PeriodicWave.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/UseCounter.h"
#include "core/inspector/ConsoleMessage.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8OscillatorNode::wrapperTypeInfo = { gin::kEmbedderBlink, V8OscillatorNode::domTemplate, V8OscillatorNode::trace, V8OscillatorNode::traceWrappers, 0, nullptr, "OscillatorNode", &V8AudioScheduledSourceNode::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::InheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in OscillatorNode.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& OscillatorNode::s_wrapperTypeInfo = V8OscillatorNode::wrapperTypeInfo;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, OscillatorNode>::value,
    "OscillatorNode does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&OscillatorNode::hasPendingActivity),
                  decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "OscillatorNode is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace OscillatorNodeV8Internal {

static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  OscillatorNode* impl = V8OscillatorNode::toImpl(holder);

  v8SetReturnValueString(info, impl->type(), info.GetIsolate());
}

MODULES_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  OscillatorNodeV8Internal::typeAttributeGetter(info);
}

static void typeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();
  OscillatorNode* impl = V8OscillatorNode::toImpl(holder);

  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "OscillatorNode", "type");

  // Prepare the value to be set.
  V8StringResource<> cppValue = v8Value;
  if (!cppValue.prepare())
    return;

  // Type check per: http://heycam.github.io/webidl/#dfn-attribute-setter
  // Returns undefined without setting the value if the value is invalid.
  DummyExceptionStateForTesting dummyExceptionState;
  const char* validValues[] = {
      "sine",
      "square",
      "sawtooth",
      "triangle",
      "custom",
  };
  if (!isValidEnum(cppValue, validValues, WTF_ARRAY_LENGTH(validValues), "OscillatorType", dummyExceptionState)) {
    currentExecutionContext(info.GetIsolate())->addConsoleMessage(ConsoleMessage::create(JSMessageSource, WarningMessageLevel, dummyExceptionState.message()));
    return;
  }

  impl->setType(cppValue, exceptionState);
}

MODULES_EXPORT void typeAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Value> v8Value = info[0];

  OscillatorNodeV8Internal::typeAttributeSetter(v8Value, info);
}

static void frequencyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  OscillatorNode* impl = V8OscillatorNode::toImpl(holder);

  AudioParam* cppValue(WTF::getPtr(impl->frequency()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
    return;
  v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
  const char kKeepAliveKey[] = "KeepAlive#OscillatorNode#frequency";
  V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

  v8SetReturnValue(info, v8Value);
}

MODULES_EXPORT void frequencyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  OscillatorNodeV8Internal::frequencyAttributeGetter(info);
}

static void detuneAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  OscillatorNode* impl = V8OscillatorNode::toImpl(holder);

  AudioParam* cppValue(WTF::getPtr(impl->detune()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
    return;
  v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
  const char kKeepAliveKey[] = "KeepAlive#OscillatorNode#detune";
  V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

  v8SetReturnValue(info, v8Value);
}

MODULES_EXPORT void detuneAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  OscillatorNodeV8Internal::detuneAttributeGetter(info);
}

static void setPeriodicWaveMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  OscillatorNode* impl = V8OscillatorNode::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setPeriodicWave", "OscillatorNode", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  PeriodicWave* periodicWave;
  periodicWave = V8PeriodicWave::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!periodicWave) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setPeriodicWave", "OscillatorNode", "parameter 1 is not of type 'PeriodicWave'."));

    return;
  }

  impl->setPeriodicWave(periodicWave);
}

MODULES_EXPORT  void setPeriodicWaveMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  OscillatorNodeV8Internal::setPeriodicWaveMethod(info);
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "OscillatorNode");

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  BaseAudioContext* context;
  OscillatorOptions options;
  context = V8BaseAudioContext::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!context) {
    exceptionState.throwTypeError("parameter 1 is not of type 'BaseAudioContext'.");

    return;
  }

  if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
    exceptionState.throwTypeError("parameter 2 ('options') is not an object.");

    return;
  }
  V8OscillatorOptions::toImpl(info.GetIsolate(), info[1], options, exceptionState);
  if (exceptionState.hadException())
    return;

  OscillatorNode* impl = OscillatorNode::create(context, options, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8OscillatorNode::wrapperTypeInfo, wrapper);
  v8SetReturnValue(info, wrapper);
}

} // namespace OscillatorNodeV8Internal

const V8DOMConfiguration::AccessorConfiguration V8OscillatorNodeAccessors[] = {
    {"type", OscillatorNodeV8Internal::typeAttributeGetterCallback, OscillatorNodeV8Internal::typeAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"frequency", OscillatorNodeV8Internal::frequencyAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"detune", OscillatorNodeV8Internal::detuneAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8OscillatorNodeMethods[] = {
    {"setPeriodicWave", OscillatorNodeV8Internal::setPeriodicWaveMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

void V8OscillatorNode::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8OscillatorNode_Constructor);
  if (!info.IsConstructCall()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("OscillatorNode"));
    return;
  }

  if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
    v8SetReturnValue(info, info.Holder());
    return;
  }

  OscillatorNodeV8Internal::constructor(info);
}

static void installV8OscillatorNodeTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8OscillatorNode::wrapperTypeInfo.interfaceName, V8AudioScheduledSourceNode::domTemplate(isolate, world), V8OscillatorNode::internalFieldCount);
  interfaceTemplate->SetCallHandler(V8OscillatorNode::constructorCallback);
  interfaceTemplate->SetLength(1);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8OscillatorNodeAccessors, WTF_ARRAY_LENGTH(V8OscillatorNodeAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8OscillatorNodeMethods, WTF_ARRAY_LENGTH(V8OscillatorNodeMethods));
}

v8::Local<v8::FunctionTemplate> V8OscillatorNode::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8OscillatorNodeTemplate);
}

bool V8OscillatorNode::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8OscillatorNode::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

OscillatorNode* V8OscillatorNode::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

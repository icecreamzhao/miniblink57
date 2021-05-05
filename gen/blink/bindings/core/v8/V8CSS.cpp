// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8CSS.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8PropertyDescriptor.h"
#include "core/css/PropertyRegistration.h"
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
const WrapperTypeInfo V8CSS::wrapperTypeInfo = { gin::kEmbedderBlink, V8CSS::domTemplate, V8CSS::trace, V8CSS::traceWrappers, 0, nullptr, "CSS", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DOMWindowCSS.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& DOMWindowCSS::s_wrapperTypeInfo = V8CSS::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DOMWindowCSS>::value,
    "DOMWindowCSS inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DOMWindowCSS::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DOMWindowCSS is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace DOMWindowCSSV8Internal {

static void supports1Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  V8StringResource<> property;
  V8StringResource<> value;
  property = info[0];
  if (!property.prepare())
    return;

  value = info[1];
  if (!value.prepare())
    return;

  v8SetReturnValueBool(info, DOMWindowCSS::supports(property, value));
}

static void supports2Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  V8StringResource<> conditionText;
  conditionText = info[0];
  if (!conditionText.prepare())
    return;

  v8SetReturnValueBool(info, DOMWindowCSS::supports(conditionText));
}

static void supportsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  bool isArityError = false;
  switch (std::min(2, info.Length())) {
    case 1:
      if (true) {
        supports2Method(info);
        return;
      }
      break;
    case 2:
      if (true) {
        supports1Method(info);
        return;
      }
      break;
    default:
      isArityError = true;
  }

  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CSS", "supports");

  if (isArityError) {
    if (info.Length() < 1) {
      exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
      return;
    }
  }
  exceptionState.throwTypeError("No function was found that matched the signature provided.");
}

CORE_EXPORT  void supportsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DOMWindowCSSV8Internal::supportsMethod(info);
}

static void escapeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("escape", "CSS", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> ident;
  ident = info[0];
  if (!ident.prepare())
    return;

  v8SetReturnValueString(info, DOMWindowCSS::escape(ident), info.GetIsolate());
}

CORE_EXPORT  void escapeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DOMWindowCSSV8Internal::escapeMethod(info);
}

static void registerPropertyMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CSS", "registerProperty");

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  PropertyDescriptor descriptor;
  if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
    exceptionState.throwTypeError("parameter 1 ('descriptor') is not an object.");

    return;
  }
  V8PropertyDescriptor::toImpl(info.GetIsolate(), info[0], descriptor, exceptionState);
  if (exceptionState.hadException())
    return;

  ExecutionContext* executionContext = currentExecutionContext(info.GetIsolate());
  PropertyRegistration::registerProperty(executionContext, descriptor, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

CORE_EXPORT  void registerPropertyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DOMWindowCSSV8Internal::registerPropertyMethod(info);
}

} // namespace DOMWindowCSSV8Internal

const V8DOMConfiguration::MethodConfiguration V8CSSMethods[] = {
    {"supports", DOMWindowCSSV8Internal::supportsMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnInterface, V8DOMConfiguration::CheckHolder},
    {"escape", DOMWindowCSSV8Internal::escapeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnInterface, V8DOMConfiguration::CheckHolder},
};

static void installV8CSSTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8CSS::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8CSS::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CSSMethods, WTF_ARRAY_LENGTH(V8CSSMethods));

  if (RuntimeEnabledFeatures::cssVariables2Enabled()) {
    const V8DOMConfiguration::MethodConfiguration registerPropertyMethodConfiguration = {"registerProperty", DOMWindowCSSV8Internal::registerPropertyMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnInterface, V8DOMConfiguration::CheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, registerPropertyMethodConfiguration);
  }
}

v8::Local<v8::FunctionTemplate> V8CSS::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8CSSTemplate);
}

bool V8CSS::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8CSS::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

DOMWindowCSS* V8CSS::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

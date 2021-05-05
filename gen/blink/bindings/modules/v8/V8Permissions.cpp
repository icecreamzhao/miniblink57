// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8Permissions.h"

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/frame/UseCounter.h"
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
const WrapperTypeInfo V8Permissions::wrapperTypeInfo = { gin::kEmbedderBlink, V8Permissions::domTemplate, V8Permissions::trace, V8Permissions::traceWrappers, 0, nullptr, "Permissions", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in Permissions.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& Permissions::s_wrapperTypeInfo = V8Permissions::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, Permissions>::value,
    "Permissions inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&Permissions::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "Permissions is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace PermissionsV8Internal {

static void queryMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Permissions", "query");
  ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

  // V8DOMConfiguration::DoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8Permissions::hasInstance(info.Holder(), info.GetIsolate())) {
    exceptionState.throwTypeError("Illegal invocation");
    return;
  }
  Permissions* impl = V8Permissions::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Dictionary permission;
  if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
    exceptionState.throwTypeError("parameter 1 ('permission') is not an object.");

    return;
  }
  permission = Dictionary(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  ScriptPromise result = impl->query(scriptState, permission);
  v8SetReturnValue(info, result.v8Value());
}

MODULES_EXPORT  void queryMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8Permissions_Query_Method);
  PermissionsV8Internal::queryMethod(info);
}

static void requestMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Permissions", "request");
  ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

  // V8DOMConfiguration::DoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8Permissions::hasInstance(info.Holder(), info.GetIsolate())) {
    exceptionState.throwTypeError("Illegal invocation");
    return;
  }
  Permissions* impl = V8Permissions::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Dictionary permissions;
  if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
    exceptionState.throwTypeError("parameter 1 ('permissions') is not an object.");

    return;
  }
  permissions = Dictionary(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  ScriptPromise result = impl->request(scriptState, permissions);
  v8SetReturnValue(info, result.v8Value());
}

MODULES_EXPORT  void requestMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8Permissions_Request_Method);
  PermissionsV8Internal::requestMethod(info);
}

static void revokeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Permissions", "revoke");
  ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

  // V8DOMConfiguration::DoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8Permissions::hasInstance(info.Holder(), info.GetIsolate())) {
    exceptionState.throwTypeError("Illegal invocation");
    return;
  }
  Permissions* impl = V8Permissions::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Dictionary permission;
  if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
    exceptionState.throwTypeError("parameter 1 ('permission') is not an object.");

    return;
  }
  permission = Dictionary(info.GetIsolate(), info[0], exceptionState);
  if (exceptionState.hadException())
    return;

  ScriptPromise result = impl->revoke(scriptState, permission);
  v8SetReturnValue(info, result.v8Value());
}

MODULES_EXPORT  void revokeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8Permissions_Revoke_Method);
  PermissionsV8Internal::revokeMethod(info);
}

static void requestAllMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Permissions", "requestAll");
  ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

  // V8DOMConfiguration::DoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8Permissions::hasInstance(info.Holder(), info.GetIsolate())) {
    exceptionState.throwTypeError("Illegal invocation");
    return;
  }
  Permissions* impl = V8Permissions::toImpl(info.Holder());

  ScriptState* scriptState = ScriptState::forReceiverObject(info);

  if (UNLIKELY(info.Length() < 1)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
    return;
  }

  Vector<Dictionary> permissions;
  permissions = toImplArray<Vector<Dictionary>>(info[0], 1, info.GetIsolate(), exceptionState);
  if (exceptionState.hadException())
    return;

  ScriptPromise result = impl->requestAll(scriptState, permissions);
  v8SetReturnValue(info, result.v8Value());
}

MODULES_EXPORT  void requestAllMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8Permissions_RequestAll_Method);
  PermissionsV8Internal::requestAllMethod(info);
}

} // namespace PermissionsV8Internal

const V8DOMConfiguration::MethodConfiguration V8PermissionsMethods[] = {
    {"query", PermissionsV8Internal::queryMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder},
};

static void installV8PermissionsTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8Permissions::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8Permissions::internalFieldCount);

  if (!RuntimeEnabledFeatures::permissionsEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PermissionsMethods, WTF_ARRAY_LENGTH(V8PermissionsMethods));

  if (RuntimeEnabledFeatures::permissionsRequestRevokeEnabled()) {
    const V8DOMConfiguration::MethodConfiguration requestMethodConfiguration = {"request", PermissionsV8Internal::requestMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, requestMethodConfiguration);
  }
  if (RuntimeEnabledFeatures::permissionsRequestRevokeEnabled()) {
    const V8DOMConfiguration::MethodConfiguration revokeMethodConfiguration = {"revoke", PermissionsV8Internal::revokeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, revokeMethodConfiguration);
  }
  if (RuntimeEnabledFeatures::permissionsRequestRevokeEnabled()) {
    const V8DOMConfiguration::MethodConfiguration requestAllMethodConfiguration = {"requestAll", PermissionsV8Internal::requestAllMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder};
    V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, requestAllMethodConfiguration);
  }
}

v8::Local<v8::FunctionTemplate> V8Permissions::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8PermissionsTemplate);
}

bool V8Permissions::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8Permissions::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

Permissions* V8Permissions::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink

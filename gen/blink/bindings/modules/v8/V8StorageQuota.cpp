// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8StorageQuota.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/inspector/ConsoleMessage.h"
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
const WrapperTypeInfo V8StorageQuota::wrapperTypeInfo = { gin::kEmbedderBlink, V8StorageQuota::domTemplate, V8StorageQuota::trace, V8StorageQuota::traceWrappers, 0, nullptr, "StorageQuota", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in StorageQuota.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& StorageQuota::s_wrapperTypeInfo = V8StorageQuota::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, StorageQuota>::value,
    "StorageQuota inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&StorageQuota::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "StorageQuota is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace StorageQuotaV8Internal {

    static void supportedTypesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        StorageQuota* impl = V8StorageQuota::toImpl(holder);

        v8SetReturnValue(info, ToV8(impl->supportedTypes(), info.Holder(), info.GetIsolate()));
    }

    MODULES_EXPORT void supportedTypesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        StorageQuotaV8Internal::supportedTypesAttributeGetter(info);
    }

    static void queryInfoMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "StorageQuota", "queryInfo");
        ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

        // V8DOMConfiguration::DoNotCheckHolder
        // Make sure that info.Holder() really points to an instance of the type.
        if (!V8StorageQuota::hasInstance(info.Holder(), info.GetIsolate())) {
            exceptionState.throwTypeError("Illegal invocation");
            return;
        }
        StorageQuota* impl = V8StorageQuota::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> type;
        type = info[0];
        if (!type.prepare(exceptionState))
            return;
        const char* validTypeValues[] = {
            "temporary",
            "persistent",
        };
        if (!isValidEnum(type, validTypeValues, WTF_ARRAY_LENGTH(validTypeValues), "StorageType", exceptionState)) {
            return;
        }

        ScriptPromise result = impl->queryInfo(scriptState, type);
        v8SetReturnValue(info, result.v8Value());
    }

    MODULES_EXPORT void queryInfoMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        StorageQuotaV8Internal::queryInfoMethod(info);
    }

    static void requestPersistentQuotaMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "StorageQuota", "requestPersistentQuota");
        ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

        // V8DOMConfiguration::DoNotCheckHolder
        // Make sure that info.Holder() really points to an instance of the type.
        if (!V8StorageQuota::hasInstance(info.Holder(), info.GetIsolate())) {
            exceptionState.throwTypeError("Illegal invocation");
            return;
        }
        StorageQuota* impl = V8StorageQuota::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        unsigned long long newQuota;
        newQuota = toUInt64(info.GetIsolate(), info[0], Clamp, exceptionState);
        if (exceptionState.hadException())
            return;

        ScriptPromise result = impl->requestPersistentQuota(scriptState, newQuota);
        v8SetReturnValue(info, result.v8Value());
    }

    MODULES_EXPORT void requestPersistentQuotaMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        StorageQuotaV8Internal::requestPersistentQuotaMethod(info);
    }

} // namespace StorageQuotaV8Internal

const V8DOMConfiguration::AccessorConfiguration V8StorageQuotaAccessors[] = {
    { "supportedTypes", StorageQuotaV8Internal::supportedTypesAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8StorageQuotaMethods[] = {
    { "queryInfo", StorageQuotaV8Internal::queryInfoMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder },
    { "requestPersistentQuota", StorageQuotaV8Internal::requestPersistentQuotaMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder },
};

static void installV8StorageQuotaTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8StorageQuota::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8StorageQuota::internalFieldCount);

    if (!RuntimeEnabledFeatures::quotaPromiseEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8StorageQuotaAccessors, WTF_ARRAY_LENGTH(V8StorageQuotaAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8StorageQuotaMethods, WTF_ARRAY_LENGTH(V8StorageQuotaMethods));
}

v8::Local<v8::FunctionTemplate> V8StorageQuota::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8StorageQuotaTemplate);
}

bool V8StorageQuota::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8StorageQuota::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

StorageQuota* V8StorageQuota::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

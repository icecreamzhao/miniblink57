// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8PushSubscription.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8ArrayBuffer.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8PushSubscriptionOptions.h"
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
const WrapperTypeInfo V8PushSubscription::wrapperTypeInfo = { gin::kEmbedderBlink, V8PushSubscription::domTemplate, V8PushSubscription::trace, V8PushSubscription::traceWrappers, 0, nullptr, "PushSubscription", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in PushSubscription.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& PushSubscription::s_wrapperTypeInfo = V8PushSubscription::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, PushSubscription>::value,
    "PushSubscription inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&PushSubscription::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "PushSubscription is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace PushSubscriptionV8Internal {

    static void endpointAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        PushSubscription* impl = V8PushSubscription::toImpl(holder);

        v8SetReturnValueString(info, impl->endpoint(), info.GetIsolate());
    }

    MODULES_EXPORT void endpointAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PushSubscriptionV8Internal::endpointAttributeGetter(info);
    }

    static void optionsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        PushSubscription* impl = V8PushSubscription::toImpl(holder);

        PushSubscriptionOptions* cppValue(WTF::getPtr(impl->options()));

        // Keep the wrapper object for the return value alive as long as |this|
        // object is alive in order to save creation time of the wrapper object.
        if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
            return;
        v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
        const char kKeepAliveKey[] = "KeepAlive#PushSubscription#options";
        V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

        v8SetReturnValue(info, v8Value);
    }

    MODULES_EXPORT void optionsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PushSubscriptionV8Internal::optionsAttributeGetter(info);
    }

    static void getKeyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "PushSubscription", "getKey");

        PushSubscription* impl = V8PushSubscription::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> name;
        name = info[0];
        if (!name.prepare())
            return;
        const char* validNameValues[] = {
            "p256dh",
            "auth",
        };
        if (!isValidEnum(name, validNameValues, WTF_ARRAY_LENGTH(validNameValues), "PushEncryptionKeyName", exceptionState)) {
            return;
        }

        v8SetReturnValue(info, impl->getKey(name));
    }

    MODULES_EXPORT void getKeyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PushSubscriptionV8Internal::getKeyMethod(info);
    }

    static void unsubscribeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "PushSubscription", "unsubscribe");
        ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

        // V8DOMConfiguration::DoNotCheckHolder
        // Make sure that info.Holder() really points to an instance of the type.
        if (!V8PushSubscription::hasInstance(info.Holder(), info.GetIsolate())) {
            exceptionState.throwTypeError("Illegal invocation");
            return;
        }
        PushSubscription* impl = V8PushSubscription::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptPromise result = impl->unsubscribe(scriptState);
        v8SetReturnValue(info, result.v8Value());
    }

    MODULES_EXPORT void unsubscribeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PushSubscriptionV8Internal::unsubscribeMethod(info);
    }

    static void toJSONMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PushSubscription* impl = V8PushSubscription::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptValue result = impl->toJSONForBinding(scriptState);
        v8SetReturnValue(info, result.v8Value());
    }

    MODULES_EXPORT void toJSONMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PushSubscriptionV8Internal::toJSONMethod(info);
    }

} // namespace PushSubscriptionV8Internal

const V8DOMConfiguration::AccessorConfiguration V8PushSubscriptionAccessors[] = {
    { "endpoint", PushSubscriptionV8Internal::endpointAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "options", PushSubscriptionV8Internal::optionsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8PushSubscriptionMethods[] = {
    { "getKey", PushSubscriptionV8Internal::getKeyMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "unsubscribe", PushSubscriptionV8Internal::unsubscribeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder },
    { "toJSON", PushSubscriptionV8Internal::toJSONMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8PushSubscriptionTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8PushSubscription::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8PushSubscription::internalFieldCount);

    if (!RuntimeEnabledFeatures::pushMessagingEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PushSubscriptionAccessors, WTF_ARRAY_LENGTH(V8PushSubscriptionAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PushSubscriptionMethods, WTF_ARRAY_LENGTH(V8PushSubscriptionMethods));
}

v8::Local<v8::FunctionTemplate> V8PushSubscription::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8PushSubscriptionTemplate);
}

bool V8PushSubscription::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8PushSubscription::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

PushSubscription* V8PushSubscription::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8BeforeInstallPromptEvent.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8BeforeInstallPromptEventInit.h"
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
const WrapperTypeInfo V8BeforeInstallPromptEvent::wrapperTypeInfo = { gin::kEmbedderBlink, V8BeforeInstallPromptEvent::domTemplate, V8BeforeInstallPromptEvent::trace, V8BeforeInstallPromptEvent::traceWrappers, 0, nullptr, "BeforeInstallPromptEvent", &V8Event::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in BeforeInstallPromptEvent.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& BeforeInstallPromptEvent::s_wrapperTypeInfo = V8BeforeInstallPromptEvent::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, BeforeInstallPromptEvent>::value,
    "BeforeInstallPromptEvent inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&BeforeInstallPromptEvent::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "BeforeInstallPromptEvent is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace BeforeInstallPromptEventV8Internal {

    static void platformsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BeforeInstallPromptEvent* impl = V8BeforeInstallPromptEvent::toImpl(holder);

        v8SetReturnValue(info, ToV8(impl->platforms(), info.Holder(), info.GetIsolate()));
    }

    MODULES_EXPORT void platformsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BeforeInstallPromptEventV8Internal::platformsAttributeGetter(info);
    }

    static void userChoiceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BeforeInstallPromptEvent* impl = V8BeforeInstallPromptEvent::toImpl(holder);

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        v8SetReturnValue(info, impl->userChoice(scriptState).v8Value());
    }

    MODULES_EXPORT void userChoiceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BeforeInstallPromptEventV8Internal::userChoiceAttributeGetter(info);
    }

    static void promptMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "BeforeInstallPromptEvent", "prompt");
        ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

        // V8DOMConfiguration::DoNotCheckHolder
        // Make sure that info.Holder() really points to an instance of the type.
        if (!V8BeforeInstallPromptEvent::hasInstance(info.Holder(), info.GetIsolate())) {
            exceptionState.throwTypeError("Illegal invocation");
            return;
        }
        BeforeInstallPromptEvent* impl = V8BeforeInstallPromptEvent::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptPromise result = impl->prompt(scriptState);
        v8SetReturnValue(info, result.v8Value());
    }

    MODULES_EXPORT void promptMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BeforeInstallPromptEventV8Internal::promptMethod(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "BeforeInstallPromptEvent");

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> type;
        BeforeInstallPromptEventInit eventInitDict;
        type = info[0];
        if (!type.prepare())
            return;

        if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
            exceptionState.throwTypeError("parameter 2 ('eventInitDict') is not an object.");

            return;
        }
        V8BeforeInstallPromptEventInit::toImpl(info.GetIsolate(), info[1], eventInitDict, exceptionState);
        if (exceptionState.hadException())
            return;

        BeforeInstallPromptEvent* impl = BeforeInstallPromptEvent::create(type, eventInitDict);
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8BeforeInstallPromptEvent::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace BeforeInstallPromptEventV8Internal

const V8DOMConfiguration::AccessorConfiguration V8BeforeInstallPromptEventAccessors[] = {
    { "platforms", BeforeInstallPromptEventV8Internal::platformsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "userChoice", BeforeInstallPromptEventV8Internal::userChoiceAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8BeforeInstallPromptEventMethods[] = {
    { "prompt", BeforeInstallPromptEventV8Internal::promptMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder },
};

void V8BeforeInstallPromptEvent::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("BeforeInstallPromptEvent"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    BeforeInstallPromptEventV8Internal::constructor(info);
}

static void installV8BeforeInstallPromptEventTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8BeforeInstallPromptEvent::wrapperTypeInfo.interfaceName, V8Event::domTemplate(isolate, world), V8BeforeInstallPromptEvent::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8BeforeInstallPromptEvent::constructorCallback);
    interfaceTemplate->SetLength(1);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8BeforeInstallPromptEventAccessors, WTF_ARRAY_LENGTH(V8BeforeInstallPromptEventAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8BeforeInstallPromptEventMethods, WTF_ARRAY_LENGTH(V8BeforeInstallPromptEventMethods));
}

v8::Local<v8::FunctionTemplate> V8BeforeInstallPromptEvent::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8BeforeInstallPromptEventTemplate);
}

bool V8BeforeInstallPromptEvent::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8BeforeInstallPromptEvent::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

BeforeInstallPromptEvent* V8BeforeInstallPromptEvent::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

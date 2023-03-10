// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8TrackDefault.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
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
const WrapperTypeInfo V8TrackDefault::wrapperTypeInfo = { gin::kEmbedderBlink, V8TrackDefault::domTemplate, V8TrackDefault::trace, V8TrackDefault::traceWrappers, 0, nullptr, "TrackDefault", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in TrackDefault.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& TrackDefault::s_wrapperTypeInfo = V8TrackDefault::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, TrackDefault>::value,
    "TrackDefault inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&TrackDefault::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "TrackDefault is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace TrackDefaultV8Internal {

    static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        TrackDefault* impl = V8TrackDefault::toImpl(holder);

        v8SetReturnValueString(info, impl->type(), info.GetIsolate());
    }

    MODULES_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        TrackDefaultV8Internal::typeAttributeGetter(info);
    }

    static void byteStreamTrackIDAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        TrackDefault* impl = V8TrackDefault::toImpl(holder);

        v8SetReturnValueString(info, impl->byteStreamTrackID(), info.GetIsolate());
    }

    MODULES_EXPORT void byteStreamTrackIDAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        TrackDefaultV8Internal::byteStreamTrackIDAttributeGetter(info);
    }

    static void languageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        TrackDefault* impl = V8TrackDefault::toImpl(holder);

        v8SetReturnValueString(info, impl->language(), info.GetIsolate());
    }

    MODULES_EXPORT void languageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        TrackDefaultV8Internal::languageAttributeGetter(info);
    }

    static void labelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        TrackDefault* impl = V8TrackDefault::toImpl(holder);

        v8SetReturnValueString(info, impl->label(), info.GetIsolate());
    }

    MODULES_EXPORT void labelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        TrackDefaultV8Internal::labelAttributeGetter(info);
    }

    static void kindsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        TrackDefault* impl = V8TrackDefault::toImpl(holder);

        v8SetReturnValue(info, ToV8(impl->kinds(), info.Holder(), info.GetIsolate()));
    }

    MODULES_EXPORT void kindsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        TrackDefaultV8Internal::kindsAttributeGetter(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "TrackDefault");

        if (UNLIKELY(info.Length() < 4)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(4, info.Length()));
            return;
        }

        V8StringResource<> type;
        V8StringResource<> language;
        V8StringResource<> label;
        Vector<String> kinds;
        V8StringResource<> byteStreamTrackID;
        type = info[0];
        if (!type.prepare())
            return;
        const char* validTypeValues[] = {
            "audio",
            "video",
            "text",
        };
        if (!isValidEnum(type, validTypeValues, WTF_ARRAY_LENGTH(validTypeValues), "TrackDefaultType", exceptionState)) {
            return;
        }

        language = info[1];
        if (!language.prepare())
            return;

        label = info[2];
        if (!label.prepare())
            return;

        kinds = toImplArray<Vector<String>>(info[3], 4, info.GetIsolate(), exceptionState);
        if (exceptionState.hadException())
            return;

        if (!info[4]->IsUndefined()) {
            byteStreamTrackID = info[4];
            if (!byteStreamTrackID.prepare())
                return;
        } else {
            byteStreamTrackID = String("");
        }

        TrackDefault* impl = TrackDefault::create(type, language, label, kinds, byteStreamTrackID, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8TrackDefault::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace TrackDefaultV8Internal

const V8DOMConfiguration::AccessorConfiguration V8TrackDefaultAccessors[] = {
    { "type", TrackDefaultV8Internal::typeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "byteStreamTrackID", TrackDefaultV8Internal::byteStreamTrackIDAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "language", TrackDefaultV8Internal::languageAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "label", TrackDefaultV8Internal::labelAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "kinds", TrackDefaultV8Internal::kindsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8TrackDefault::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("TrackDefault"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    TrackDefaultV8Internal::constructor(info);
}

static void installV8TrackDefaultTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8TrackDefault::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8TrackDefault::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8TrackDefault::constructorCallback);
    interfaceTemplate->SetLength(4);

    if (!RuntimeEnabledFeatures::mediaSourceExperimentalEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8TrackDefaultAccessors, WTF_ARRAY_LENGTH(V8TrackDefaultAccessors));
}

v8::Local<v8::FunctionTemplate> V8TrackDefault::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8TrackDefaultTemplate);
}

bool V8TrackDefault::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8TrackDefault::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TrackDefault* V8TrackDefault::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

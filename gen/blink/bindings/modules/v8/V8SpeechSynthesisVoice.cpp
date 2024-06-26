// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8SpeechSynthesisVoice.h"

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
const WrapperTypeInfo V8SpeechSynthesisVoice::wrapperTypeInfo = { gin::kEmbedderBlink, V8SpeechSynthesisVoice::domTemplate, V8SpeechSynthesisVoice::trace, V8SpeechSynthesisVoice::traceWrappers, 0, nullptr, "SpeechSynthesisVoice", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SpeechSynthesisVoice.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SpeechSynthesisVoice::s_wrapperTypeInfo = V8SpeechSynthesisVoice::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SpeechSynthesisVoice>::value,
    "SpeechSynthesisVoice inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SpeechSynthesisVoice::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SpeechSynthesisVoice is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SpeechSynthesisVoiceV8Internal {

    static void voiceURIAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SpeechSynthesisVoice* impl = V8SpeechSynthesisVoice::toImpl(holder);

        v8SetReturnValueString(info, impl->voiceURI(), info.GetIsolate());
    }

    MODULES_EXPORT void voiceURIAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SpeechSynthesisVoiceV8Internal::voiceURIAttributeGetter(info);
    }

    static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SpeechSynthesisVoice* impl = V8SpeechSynthesisVoice::toImpl(holder);

        v8SetReturnValueString(info, impl->name(), info.GetIsolate());
    }

    MODULES_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SpeechSynthesisVoiceV8Internal::nameAttributeGetter(info);
    }

    static void langAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SpeechSynthesisVoice* impl = V8SpeechSynthesisVoice::toImpl(holder);

        v8SetReturnValueString(info, impl->lang(), info.GetIsolate());
    }

    MODULES_EXPORT void langAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SpeechSynthesisVoiceV8Internal::langAttributeGetter(info);
    }

    static void localServiceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SpeechSynthesisVoice* impl = V8SpeechSynthesisVoice::toImpl(holder);

        v8SetReturnValueBool(info, impl->localService());
    }

    MODULES_EXPORT void localServiceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SpeechSynthesisVoiceV8Internal::localServiceAttributeGetter(info);
    }

    static void defaultAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SpeechSynthesisVoice* impl = V8SpeechSynthesisVoice::toImpl(holder);

        v8SetReturnValueBool(info, impl->isDefault());
    }

    MODULES_EXPORT void defaultAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SpeechSynthesisVoiceV8Internal::defaultAttributeGetter(info);
    }

} // namespace SpeechSynthesisVoiceV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SpeechSynthesisVoiceAccessors[] = {
    { "voiceURI", SpeechSynthesisVoiceV8Internal::voiceURIAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "name", SpeechSynthesisVoiceV8Internal::nameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "lang", SpeechSynthesisVoiceV8Internal::langAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "localService", SpeechSynthesisVoiceV8Internal::localServiceAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "default", SpeechSynthesisVoiceV8Internal::defaultAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8SpeechSynthesisVoiceTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SpeechSynthesisVoice::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8SpeechSynthesisVoice::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SpeechSynthesisVoiceAccessors, WTF_ARRAY_LENGTH(V8SpeechSynthesisVoiceAccessors));
}

v8::Local<v8::FunctionTemplate> V8SpeechSynthesisVoice::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SpeechSynthesisVoiceTemplate);
}

bool V8SpeechSynthesisVoice::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SpeechSynthesisVoice::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SpeechSynthesisVoice* V8SpeechSynthesisVoice::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

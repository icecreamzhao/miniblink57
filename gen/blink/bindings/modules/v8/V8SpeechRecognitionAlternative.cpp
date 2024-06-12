// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8SpeechRecognitionAlternative.h"

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
const WrapperTypeInfo V8SpeechRecognitionAlternative::wrapperTypeInfo = { gin::kEmbedderBlink, V8SpeechRecognitionAlternative::domTemplate, V8SpeechRecognitionAlternative::trace, V8SpeechRecognitionAlternative::traceWrappers, 0, nullptr, "SpeechRecognitionAlternative", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SpeechRecognitionAlternative.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SpeechRecognitionAlternative::s_wrapperTypeInfo = V8SpeechRecognitionAlternative::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SpeechRecognitionAlternative>::value,
    "SpeechRecognitionAlternative inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SpeechRecognitionAlternative::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SpeechRecognitionAlternative is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SpeechRecognitionAlternativeV8Internal {

    static void transcriptAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SpeechRecognitionAlternative* impl = V8SpeechRecognitionAlternative::toImpl(holder);

        v8SetReturnValueString(info, impl->transcript(), info.GetIsolate());
    }

    MODULES_EXPORT void transcriptAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SpeechRecognitionAlternativeV8Internal::transcriptAttributeGetter(info);
    }

    static void confidenceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SpeechRecognitionAlternative* impl = V8SpeechRecognitionAlternative::toImpl(holder);

        v8SetReturnValue(info, impl->confidence());
    }

    MODULES_EXPORT void confidenceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SpeechRecognitionAlternativeV8Internal::confidenceAttributeGetter(info);
    }

} // namespace SpeechRecognitionAlternativeV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SpeechRecognitionAlternativeAccessors[] = {
    { "transcript", SpeechRecognitionAlternativeV8Internal::transcriptAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "confidence", SpeechRecognitionAlternativeV8Internal::confidenceAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8SpeechRecognitionAlternativeTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SpeechRecognitionAlternative::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8SpeechRecognitionAlternative::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SpeechRecognitionAlternativeAccessors, WTF_ARRAY_LENGTH(V8SpeechRecognitionAlternativeAccessors));
}

v8::Local<v8::FunctionTemplate> V8SpeechRecognitionAlternative::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SpeechRecognitionAlternativeTemplate);
}

bool V8SpeechRecognitionAlternative::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SpeechRecognitionAlternative::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SpeechRecognitionAlternative* V8SpeechRecognitionAlternative::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

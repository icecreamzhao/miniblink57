// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8AnimationEffectTimingReadOnly.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/UnrestrictedDoubleOrString.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
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
const WrapperTypeInfo V8AnimationEffectTimingReadOnly::wrapperTypeInfo = { gin::kEmbedderBlink, V8AnimationEffectTimingReadOnly::domTemplate, V8AnimationEffectTimingReadOnly::trace, V8AnimationEffectTimingReadOnly::traceWrappers, 0, nullptr, "AnimationEffectTimingReadOnly", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in AnimationEffectTimingReadOnly.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& AnimationEffectTimingReadOnly::s_wrapperTypeInfo = V8AnimationEffectTimingReadOnly::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, AnimationEffectTimingReadOnly>::value,
    "AnimationEffectTimingReadOnly inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&AnimationEffectTimingReadOnly::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "AnimationEffectTimingReadOnly is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace AnimationEffectTimingReadOnlyV8Internal {

    static void delayAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        v8SetReturnValue(info, impl->delay());
    }

    CORE_EXPORT void delayAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::delayAttributeGetter(info);
    }

    static void endDelayAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        v8SetReturnValue(info, impl->endDelay());
    }

    CORE_EXPORT void endDelayAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::endDelayAttributeGetter(info);
    }

    static void fillAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        v8SetReturnValueString(info, impl->fill(), info.GetIsolate());
    }

    CORE_EXPORT void fillAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::fillAttributeGetter(info);
    }

    static void iterationStartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        v8SetReturnValue(info, impl->iterationStart());
    }

    CORE_EXPORT void iterationStartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::iterationStartAttributeGetter(info);
    }

    static void iterationsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        v8SetReturnValue(info, impl->iterations());
    }

    CORE_EXPORT void iterationsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::iterationsAttributeGetter(info);
    }

    static void durationAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        UnrestrictedDoubleOrString result;
        impl->duration(result);

        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void durationAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::durationAttributeGetter(info);
    }

    static void directionAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        v8SetReturnValueString(info, impl->direction(), info.GetIsolate());
    }

    CORE_EXPORT void directionAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::directionAttributeGetter(info);
    }

    static void easingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AnimationEffectTimingReadOnly* impl = V8AnimationEffectTimingReadOnly::toImpl(holder);

        v8SetReturnValueString(info, impl->easing(), info.GetIsolate());
    }

    CORE_EXPORT void easingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AnimationEffectTimingReadOnlyV8Internal::easingAttributeGetter(info);
    }

} // namespace AnimationEffectTimingReadOnlyV8Internal

const V8DOMConfiguration::AccessorConfiguration V8AnimationEffectTimingReadOnlyAccessors[] = {
    { "delay", AnimationEffectTimingReadOnlyV8Internal::delayAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "endDelay", AnimationEffectTimingReadOnlyV8Internal::endDelayAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "fill", AnimationEffectTimingReadOnlyV8Internal::fillAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "iterationStart", AnimationEffectTimingReadOnlyV8Internal::iterationStartAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "iterations", AnimationEffectTimingReadOnlyV8Internal::iterationsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "duration", AnimationEffectTimingReadOnlyV8Internal::durationAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "direction", AnimationEffectTimingReadOnlyV8Internal::directionAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "easing", AnimationEffectTimingReadOnlyV8Internal::easingAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8AnimationEffectTimingReadOnlyTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8AnimationEffectTimingReadOnly::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8AnimationEffectTimingReadOnly::internalFieldCount);

    if (!RuntimeEnabledFeatures::webAnimationsAPIEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8AnimationEffectTimingReadOnlyAccessors, WTF_ARRAY_LENGTH(V8AnimationEffectTimingReadOnlyAccessors));
}

v8::Local<v8::FunctionTemplate> V8AnimationEffectTimingReadOnly::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8AnimationEffectTimingReadOnlyTemplate);
}

bool V8AnimationEffectTimingReadOnly::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8AnimationEffectTimingReadOnly::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

AnimationEffectTimingReadOnly* V8AnimationEffectTimingReadOnly::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

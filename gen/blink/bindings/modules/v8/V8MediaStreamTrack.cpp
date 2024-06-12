// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8MediaStreamTrack.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8EventListenerHelper.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8MediaStreamTrack.h"
#include "bindings/modules/v8/V8MediaTrackConstraints.h"
#include "bindings/modules/v8/V8MediaTrackSettings.h"
#include "core/dom/Document.h"
#include "core/frame/UseCounter.h"
#include "core/inspector/ConsoleMessage.h"
#include "modules/mediastream/MediaStreamTrackContentHint.h"
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
const WrapperTypeInfo V8MediaStreamTrack::wrapperTypeInfo = { gin::kEmbedderBlink, V8MediaStreamTrack::domTemplate, V8MediaStreamTrack::trace, V8MediaStreamTrack::traceWrappers, 0, nullptr, "MediaStreamTrack", &V8EventTarget::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::InheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in MediaStreamTrack.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& MediaStreamTrack::s_wrapperTypeInfo = V8MediaStreamTrack::wrapperTypeInfo;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, MediaStreamTrack>::value,
    "MediaStreamTrack does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&MediaStreamTrack::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "MediaStreamTrack is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace MediaStreamTrackV8Internal {

    static void kindAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->kind(), info.GetIsolate());
    }

    MODULES_EXPORT void kindAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::kindAttributeGetter(info);
    }

    static void idAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->id(), info.GetIsolate());
    }

    MODULES_EXPORT void idAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::idAttributeGetter(info);
    }

    static void labelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->label(), info.GetIsolate());
    }

    MODULES_EXPORT void labelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::labelAttributeGetter(info);
    }

    static void enabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueBool(info, impl->enabled());
    }

    MODULES_EXPORT void enabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::enabledAttributeGetter(info);
    }

    static void enabledAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "MediaStreamTrack", "enabled");

        // Prepare the value to be set.
        bool cppValue = toBoolean(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setEnabled(cppValue);
    }

    MODULES_EXPORT void enabledAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        MediaStreamTrackV8Internal::enabledAttributeSetter(v8Value, info);
    }

    static void mutedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueBool(info, impl->muted());
    }

    MODULES_EXPORT void mutedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::mutedAttributeGetter(info);
    }

    static void onmuteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        EventListener* cppValue(WTF::getPtr(impl->onmute()));

        v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
    }

    MODULES_EXPORT void onmuteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::onmuteAttributeGetter(info);
    }

    static void onmuteAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        // Prepare the value to be set.
        moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onmute(), v8Value, V8MediaStreamTrack::eventListenerCacheIndex);

        impl->setOnmute(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
    }

    MODULES_EXPORT void onmuteAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        MediaStreamTrackV8Internal::onmuteAttributeSetter(v8Value, info);
    }

    static void onunmuteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        EventListener* cppValue(WTF::getPtr(impl->onunmute()));

        v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
    }

    MODULES_EXPORT void onunmuteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::onunmuteAttributeGetter(info);
    }

    static void onunmuteAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        // Prepare the value to be set.
        moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onunmute(), v8Value, V8MediaStreamTrack::eventListenerCacheIndex);

        impl->setOnunmute(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
    }

    MODULES_EXPORT void onunmuteAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        MediaStreamTrackV8Internal::onunmuteAttributeSetter(v8Value, info);
    }

    static void readyStateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->readyState(), info.GetIsolate());
    }

    MODULES_EXPORT void readyStateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::readyStateAttributeGetter(info);
    }

    static void onendedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        EventListener* cppValue(WTF::getPtr(impl->onended()));

        v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
    }

    MODULES_EXPORT void onendedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::onendedAttributeGetter(info);
    }

    static void onendedAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        // Prepare the value to be set.
        moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onended(), v8Value, V8MediaStreamTrack::eventListenerCacheIndex);

        impl->setOnended(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
    }

    MODULES_EXPORT void onendedAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        MediaStreamTrackV8Internal::onendedAttributeSetter(v8Value, info);
    }

    static void remoteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueBool(info, impl->remote());
    }

    MODULES_EXPORT void remoteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::MediaStreamTrackRemote);

        MediaStreamTrackV8Internal::remoteAttributeGetter(info);
    }

    static void contentHintAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        v8SetReturnValueString(info, MediaStreamTrackContentHint::contentHint(*impl), info.GetIsolate());
    }

    MODULES_EXPORT void contentHintAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::contentHintAttributeGetter(info);
    }

    static void contentHintAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        MediaStreamTrackContentHint::setContentHint(*impl, cppValue);
    }

    MODULES_EXPORT void contentHintAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        MediaStreamTrackV8Internal::contentHintAttributeSetter(v8Value, info);
    }

    static void cloneMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(info.Holder());

        ExecutionContext* executionContext = currentExecutionContext(info.GetIsolate());
        v8SetReturnValue(info, impl->clone(executionContext));
    }

    MODULES_EXPORT void cloneMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::cloneMethod(info);
    }

    static void stopMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "MediaStreamTrack", "stop");

        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(info.Holder());

        impl->stopTrack(exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    MODULES_EXPORT void stopMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::stopMethod(info);
    }

    static void getConstraintsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(info.Holder());

        MediaTrackConstraints result;
        impl->getConstraints(result);
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void getConstraintsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::getConstraintsMethod(info);
    }

    static void getSettingsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrack* impl = V8MediaStreamTrack::toImpl(info.Holder());

        MediaTrackSettings result;
        impl->getSettings(result);
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void getSettingsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStreamTrackV8Internal::getSettingsMethod(info);
    }

} // namespace MediaStreamTrackV8Internal

const V8DOMConfiguration::AccessorConfiguration V8MediaStreamTrackAccessors[] = {
    { "kind", MediaStreamTrackV8Internal::kindAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "id", MediaStreamTrackV8Internal::idAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "label", MediaStreamTrackV8Internal::labelAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "enabled", MediaStreamTrackV8Internal::enabledAttributeGetterCallback, MediaStreamTrackV8Internal::enabledAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "muted", MediaStreamTrackV8Internal::mutedAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "onmute", MediaStreamTrackV8Internal::onmuteAttributeGetterCallback, MediaStreamTrackV8Internal::onmuteAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "onunmute", MediaStreamTrackV8Internal::onunmuteAttributeGetterCallback, MediaStreamTrackV8Internal::onunmuteAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "readyState", MediaStreamTrackV8Internal::readyStateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "onended", MediaStreamTrackV8Internal::onendedAttributeGetterCallback, MediaStreamTrackV8Internal::onendedAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "remote", MediaStreamTrackV8Internal::remoteAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8MediaStreamTrackMethods[] = {
    { "clone", MediaStreamTrackV8Internal::cloneMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "stop", MediaStreamTrackV8Internal::stopMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8MediaStreamTrackTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8MediaStreamTrack::wrapperTypeInfo.interfaceName, V8EventTarget::domTemplate(isolate, world), V8MediaStreamTrack::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8MediaStreamTrackAccessors, WTF_ARRAY_LENGTH(V8MediaStreamTrackAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8MediaStreamTrackMethods, WTF_ARRAY_LENGTH(V8MediaStreamTrackMethods));

    if (RuntimeEnabledFeatures::mediaStreamTrackContentHintEnabled()) {
        const V8DOMConfiguration::AccessorConfiguration accessorcontentHintConfiguration = { "contentHint", MediaStreamTrackV8Internal::contentHintAttributeGetterCallback, MediaStreamTrackV8Internal::contentHintAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installAccessor(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, accessorcontentHintConfiguration);
    }

    if (RuntimeEnabledFeatures::mediaConstraintsEnabled()) {
        const V8DOMConfiguration::MethodConfiguration getConstraintsMethodConfiguration = { "getConstraints", MediaStreamTrackV8Internal::getConstraintsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, getConstraintsMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::mediaGetSettingsEnabled()) {
        const V8DOMConfiguration::MethodConfiguration getSettingsMethodConfiguration = { "getSettings", MediaStreamTrackV8Internal::getSettingsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, getSettingsMethodConfiguration);
    }
}

v8::Local<v8::FunctionTemplate> V8MediaStreamTrack::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8MediaStreamTrackTemplate);
}

bool V8MediaStreamTrack::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8MediaStreamTrack::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

MediaStreamTrack* V8MediaStreamTrack::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

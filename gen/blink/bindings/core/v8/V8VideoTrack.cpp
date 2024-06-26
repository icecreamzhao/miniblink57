// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8VideoTrack.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8GCController.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/dom/Element.h"
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
WrapperTypeInfo V8VideoTrack::wrapperTypeInfo = { gin::kEmbedderBlink, V8VideoTrack::domTemplate, V8VideoTrack::trace, V8VideoTrack::traceWrappers, V8VideoTrack::visitDOMWrapper, nullptr, "VideoTrack", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in VideoTrack.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& VideoTrack::s_wrapperTypeInfo = V8VideoTrack::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, VideoTrack>::value,
    "VideoTrack inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&VideoTrack::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "VideoTrack is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace VideoTrackV8Internal {

    static void idAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        VideoTrack* impl = V8VideoTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->id(), info.GetIsolate());
    }

    CORE_EXPORT void idAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        VideoTrackV8Internal::idAttributeGetter(info);
    }

    static void kindAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        VideoTrack* impl = V8VideoTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->kind(), info.GetIsolate());
    }

    CORE_EXPORT void kindAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        VideoTrackV8Internal::kindAttributeGetter(info);
    }

    static void labelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        VideoTrack* impl = V8VideoTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->label(), info.GetIsolate());
    }

    CORE_EXPORT void labelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        VideoTrackV8Internal::labelAttributeGetter(info);
    }

    static void languageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        VideoTrack* impl = V8VideoTrack::toImpl(holder);

        v8SetReturnValueString(info, impl->language(), info.GetIsolate());
    }

    CORE_EXPORT void languageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        VideoTrackV8Internal::languageAttributeGetter(info);
    }

    static void selectedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        VideoTrack* impl = V8VideoTrack::toImpl(holder);

        v8SetReturnValueBool(info, impl->selected());
    }

    CORE_EXPORT void selectedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        VideoTrackV8Internal::selectedAttributeGetter(info);
    }

    static void selectedAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        VideoTrack* impl = V8VideoTrack::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "VideoTrack", "selected");

        // Prepare the value to be set.
        bool cppValue = toBoolean(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setSelected(cppValue);
    }

    CORE_EXPORT void selectedAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        VideoTrackV8Internal::selectedAttributeSetter(v8Value, info);
    }

} // namespace VideoTrackV8Internal

void V8VideoTrack::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper)
{
    VideoTrack* impl = scriptWrappable->toImpl<VideoTrack>();
    // The owner() method may return a reference or a pointer.
    if (Node* owner = WTF::getPtr(impl->owner())) {
        Node* root = V8GCController::opaqueRootForGC(isolate, owner);
        isolate->SetReferenceFromGroup(v8::UniqueId(reinterpret_cast<intptr_t>(root)), wrapper);
        return;
    }
}

const V8DOMConfiguration::AccessorConfiguration V8VideoTrackAccessors[] = {
    { "id", VideoTrackV8Internal::idAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "kind", VideoTrackV8Internal::kindAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "label", VideoTrackV8Internal::labelAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "language", VideoTrackV8Internal::languageAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "selected", VideoTrackV8Internal::selectedAttributeGetterCallback, VideoTrackV8Internal::selectedAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8VideoTrack::installV8VideoTrackTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8VideoTrack::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8VideoTrack::internalFieldCount);

    if (!RuntimeEnabledFeatures::audioVideoTracksEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8VideoTrackAccessors, WTF_ARRAY_LENGTH(V8VideoTrackAccessors));
}

v8::Local<v8::FunctionTemplate> V8VideoTrack::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), V8VideoTrack::installV8VideoTrackTemplateFunction);
}

bool V8VideoTrack::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8VideoTrack::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

VideoTrack* V8VideoTrack::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

InstallTemplateFunction V8VideoTrack::installV8VideoTrackTemplateFunction = (InstallTemplateFunction)&V8VideoTrack::installV8VideoTrackTemplate;

void V8VideoTrack::updateWrapperTypeInfo(InstallTemplateFunction installTemplateFunction, PreparePrototypeAndInterfaceObjectFunction preparePrototypeAndInterfaceObjectFunction)
{
    V8VideoTrack::installV8VideoTrackTemplateFunction = installTemplateFunction;
    if (preparePrototypeAndInterfaceObjectFunction)
        V8VideoTrack::wrapperTypeInfo.preparePrototypeAndInterfaceObjectFunction = preparePrototypeAndInterfaceObjectFunction;
}

} // namespace blink

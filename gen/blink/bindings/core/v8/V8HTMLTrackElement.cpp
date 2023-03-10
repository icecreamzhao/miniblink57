// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8HTMLTrackElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8TextTrack.h"
#include "core/HTMLNames.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8HTMLTrackElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLTrackElement::domTemplate, V8HTMLTrackElement::trace, V8HTMLTrackElement::traceWrappers, 0, nullptr, "HTMLTrackElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLTrackElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLTrackElement::s_wrapperTypeInfo = V8HTMLTrackElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLTrackElement>::value,
    "HTMLTrackElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLTrackElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLTrackElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLTrackElementV8Internal {

    static void kindAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        v8SetReturnValueString(info, impl->kind(), info.GetIsolate());
    }

    CORE_EXPORT void kindAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLTrackElementV8Internal::kindAttributeGetter(info);
    }

    static void kindAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setKind(cppValue);
    }

    CORE_EXPORT void kindAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLTrackElementV8Internal::kindAttributeSetter(v8Value, info);
    }

    static void srcAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        v8SetReturnValueString(info, impl->getURLAttribute(HTMLNames::srcAttr), info.GetIsolate());
    }

    CORE_EXPORT void srcAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLTrackElementV8Internal::srcAttributeGetter(info);
    }

    static void srcAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::srcAttr, cppValue);
    }

    CORE_EXPORT void srcAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLTrackElementV8Internal::srcAttributeSetter(v8Value, info);
    }

    static void srclangAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::srclangAttr), info.GetIsolate());
    }

    CORE_EXPORT void srclangAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLTrackElementV8Internal::srclangAttributeGetter(info);
    }

    static void srclangAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::srclangAttr, cppValue);
    }

    CORE_EXPORT void srclangAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLTrackElementV8Internal::srclangAttributeSetter(v8Value, info);
    }

    static void labelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::labelAttr), info.GetIsolate());
    }

    CORE_EXPORT void labelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLTrackElementV8Internal::labelAttributeGetter(info);
    }

    static void labelAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::labelAttr, cppValue);
    }

    CORE_EXPORT void labelAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLTrackElementV8Internal::labelAttributeSetter(v8Value, info);
    }

    static void defaultAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        v8SetReturnValueBool(info, impl->fastHasAttribute(HTMLNames::defaultAttr));
    }

    CORE_EXPORT void defaultAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLTrackElementV8Internal::defaultAttributeGetter(info);
    }

    static void defaultAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        // Skip on compact node DOMString getters.
        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLTrackElement", "default");

        // Prepare the value to be set.
        bool cppValue = toBoolean(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setBooleanAttribute(HTMLNames::defaultAttr, cppValue);
    }

    CORE_EXPORT void defaultAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLTrackElementV8Internal::defaultAttributeSetter(v8Value, info);
    }

    static void readyStateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        v8SetReturnValueUnsigned(info, impl->getReadyState());
    }

    CORE_EXPORT void readyStateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLTrackElementV8Internal::readyStateAttributeGetter(info);
    }

    static void trackAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLTrackElement* impl = V8HTMLTrackElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->track()), impl);
    }

    CORE_EXPORT void trackAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLTrackElementV8Internal::trackAttributeGetter(info);
    }

} // namespace HTMLTrackElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLTrackElementAccessors[] = {
    { "kind", HTMLTrackElementV8Internal::kindAttributeGetterCallback, HTMLTrackElementV8Internal::kindAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "src", HTMLTrackElementV8Internal::srcAttributeGetterCallback, HTMLTrackElementV8Internal::srcAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "srclang", HTMLTrackElementV8Internal::srclangAttributeGetterCallback, HTMLTrackElementV8Internal::srclangAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "label", HTMLTrackElementV8Internal::labelAttributeGetterCallback, HTMLTrackElementV8Internal::labelAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "default", HTMLTrackElementV8Internal::defaultAttributeGetterCallback, HTMLTrackElementV8Internal::defaultAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "readyState", HTMLTrackElementV8Internal::readyStateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "track", HTMLTrackElementV8Internal::trackAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8HTMLTrackElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLTrackElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLTrackElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    const V8DOMConfiguration::ConstantConfiguration V8HTMLTrackElementConstants[] = {
        { "NONE", 0, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "LOADING", 1, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "LOADED", 2, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "ERROR", 3, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
    };
    V8DOMConfiguration::installConstants(isolate, interfaceTemplate, prototypeTemplate, V8HTMLTrackElementConstants, WTF_ARRAY_LENGTH(V8HTMLTrackElementConstants));
    static_assert(0 == HTMLTrackElement::kNone, "the value of HTMLTrackElement_kNone does not match with implementation");
    static_assert(1 == HTMLTrackElement::kLoading, "the value of HTMLTrackElement_kLoading does not match with implementation");
    static_assert(2 == HTMLTrackElement::kLoaded, "the value of HTMLTrackElement_kLoaded does not match with implementation");
    static_assert(3 == HTMLTrackElement::kError, "the value of HTMLTrackElement_kError does not match with implementation");
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLTrackElementAccessors, WTF_ARRAY_LENGTH(V8HTMLTrackElementAccessors));
}

v8::Local<v8::FunctionTemplate> V8HTMLTrackElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLTrackElementTemplate);
}

bool V8HTMLTrackElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLTrackElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLTrackElement* V8HTMLTrackElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

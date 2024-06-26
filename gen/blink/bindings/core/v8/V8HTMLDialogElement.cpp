// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8HTMLDialogElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
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
const WrapperTypeInfo V8HTMLDialogElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLDialogElement::domTemplate, V8HTMLDialogElement::trace, V8HTMLDialogElement::traceWrappers, 0, nullptr, "HTMLDialogElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLDialogElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLDialogElement::s_wrapperTypeInfo = V8HTMLDialogElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLDialogElement>::value,
    "HTMLDialogElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLDialogElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLDialogElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLDialogElementV8Internal {

    static void openAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLDialogElement* impl = V8HTMLDialogElement::toImpl(holder);

        v8SetReturnValueBool(info, impl->fastHasAttribute(HTMLNames::openAttr));
    }

    CORE_EXPORT void openAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLDialogElementV8Internal::openAttributeGetter(info);
    }

    static void openAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLDialogElement* impl = V8HTMLDialogElement::toImpl(holder);

        // Skip on compact node DOMString getters.
        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLDialogElement", "open");

        // Prepare the value to be set.
        bool cppValue = toBoolean(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setBooleanAttribute(HTMLNames::openAttr, cppValue);
    }

    CORE_EXPORT void openAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLDialogElementV8Internal::openAttributeSetter(v8Value, info);
    }

    static void returnValueAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLDialogElement* impl = V8HTMLDialogElement::toImpl(holder);

        v8SetReturnValueString(info, impl->returnValue(), info.GetIsolate());
    }

    CORE_EXPORT void returnValueAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLDialogElementV8Internal::returnValueAttributeGetter(info);
    }

    static void returnValueAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLDialogElement* impl = V8HTMLDialogElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setReturnValue(cppValue);
    }

    CORE_EXPORT void returnValueAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        HTMLDialogElementV8Internal::returnValueAttributeSetter(v8Value, info);
    }

    static void showMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLDialogElement* impl = V8HTMLDialogElement::toImpl(info.Holder());

        impl->show();
    }

    CORE_EXPORT void showMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        HTMLDialogElementV8Internal::showMethod(info);
    }

    static void showModalMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "HTMLDialogElement", "showModal");

        HTMLDialogElement* impl = V8HTMLDialogElement::toImpl(info.Holder());

        impl->showModal(exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void showModalMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        HTMLDialogElementV8Internal::showModalMethod(info);
    }

    static void closeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "HTMLDialogElement", "close");

        HTMLDialogElement* impl = V8HTMLDialogElement::toImpl(info.Holder());

        V8StringResource<> returnValue;
        if (!info[0]->IsUndefined()) {
            returnValue = info[0];
            if (!returnValue.prepare())
                return;
        } else {
            returnValue = nullptr;
        }

        impl->close(returnValue, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void closeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        HTMLDialogElementV8Internal::closeMethod(info);
    }

} // namespace HTMLDialogElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLDialogElementAccessors[] = {
    { "open", HTMLDialogElementV8Internal::openAttributeGetterCallback, HTMLDialogElementV8Internal::openAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "returnValue", HTMLDialogElementV8Internal::returnValueAttributeGetterCallback, HTMLDialogElementV8Internal::returnValueAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8HTMLDialogElementMethods[] = {
    { "show", HTMLDialogElementV8Internal::showMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "showModal", HTMLDialogElementV8Internal::showModalMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "close", HTMLDialogElementV8Internal::closeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8HTMLDialogElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLDialogElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLDialogElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLDialogElementAccessors, WTF_ARRAY_LENGTH(V8HTMLDialogElementAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLDialogElementMethods, WTF_ARRAY_LENGTH(V8HTMLDialogElementMethods));
}

v8::Local<v8::FunctionTemplate> V8HTMLDialogElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLDialogElementTemplate);
}

bool V8HTMLDialogElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLDialogElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLDialogElement* V8HTMLDialogElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

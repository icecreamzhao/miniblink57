// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8HTMLOutputElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8DOMTokenList.h"
#include "bindings/core/v8/V8HTMLFormElement.h"
#include "bindings/core/v8/V8NodeList.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8ValidityState.h"
#include "core/HTMLNames.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/NameNodeList.h"
#include "core/dom/NodeList.h"
#include "core/dom/StaticNodeList.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
#include "core/html/LabelsNodeList.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8HTMLOutputElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLOutputElement::domTemplate, V8HTMLOutputElement::trace, V8HTMLOutputElement::traceWrappers, 0, nullptr, "HTMLOutputElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLOutputElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLOutputElement::s_wrapperTypeInfo = V8HTMLOutputElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLOutputElement>::value,
    "HTMLOutputElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLOutputElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLOutputElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLOutputElementV8Internal {

    static void htmlForAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->htmlFor()), impl);
    }

    CORE_EXPORT void htmlForAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::htmlForAttributeGetter(info);
    }

    static void htmlForAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLOutputElement* proxyImpl = V8HTMLOutputElement::toImpl(holder);
        DOMTokenList* impl = WTF::getPtr(proxyImpl->htmlFor());
        if (!impl)
            return;

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setValue(cppValue);
    }

    CORE_EXPORT void htmlForAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLOutputElementV8Internal::htmlForAttributeSetter(v8Value, info);
    }

    static void formAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->formOwner()), impl);
    }

    CORE_EXPORT void formAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::formAttributeGetter(info);
    }

    static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueString(info, impl->getNameAttribute(), info.GetIsolate());
    }

    CORE_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::nameAttributeGetter(info);
    }

    static void nameAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::nameAttr, cppValue);
    }

    CORE_EXPORT void nameAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLOutputElementV8Internal::nameAttributeSetter(v8Value, info);
    }

    static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueString(info, impl->type(), info.GetIsolate());
    }

    CORE_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::typeAttributeGetter(info);
    }

    static void defaultValueAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueString(info, impl->defaultValue(), info.GetIsolate());
    }

    CORE_EXPORT void defaultValueAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::defaultValueAttributeGetter(info);
    }

    static void defaultValueAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setDefaultValue(cppValue);
    }

    CORE_EXPORT void defaultValueAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLOutputElementV8Internal::defaultValueAttributeSetter(v8Value, info);
    }

    static void valueAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueString(info, impl->value(), info.GetIsolate());
    }

    CORE_EXPORT void valueAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::valueAttributeGetter(info);
    }

    static void valueAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setValue(cppValue);
    }

    CORE_EXPORT void valueAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLOutputElementV8Internal::valueAttributeSetter(v8Value, info);
    }

    static void willValidateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueBool(info, impl->willValidate());
    }

    CORE_EXPORT void willValidateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::willValidateAttributeGetter(info);
    }

    static void validityAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->validity()), impl);
    }

    CORE_EXPORT void validityAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::validityAttributeGetter(info);
    }

    static void validationMessageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueString(info, impl->validationMessage(), info.GetIsolate());
    }

    CORE_EXPORT void validationMessageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::validationMessageAttributeGetter(info);
    }

    static void labelsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->labels()), impl);
    }

    CORE_EXPORT void labelsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::labelsAttributeGetter(info);
    }

    static void checkValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(info.Holder());

        v8SetReturnValueBool(info, impl->checkValidity());
    }

    CORE_EXPORT void checkValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::checkValidityMethod(info);
    }

    static void reportValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(info.Holder());

        v8SetReturnValueBool(info, impl->reportValidity());
    }

    CORE_EXPORT void reportValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::reportValidityMethod(info);
    }

    static void setCustomValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElement* impl = V8HTMLOutputElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setCustomValidity", "HTMLOutputElement", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        V8StringResource<> error;
        error = info[0];
        if (!error.prepare())
            return;

        impl->setCustomValidity(error);
    }

    CORE_EXPORT void setCustomValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLOutputElementV8Internal::setCustomValidityMethod(info);
    }

} // namespace HTMLOutputElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLOutputElementAccessors[] = {
    { "htmlFor", HTMLOutputElementV8Internal::htmlForAttributeGetterCallback, HTMLOutputElementV8Internal::htmlForAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "form", HTMLOutputElementV8Internal::formAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "name", HTMLOutputElementV8Internal::nameAttributeGetterCallback, HTMLOutputElementV8Internal::nameAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "type", HTMLOutputElementV8Internal::typeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "defaultValue", HTMLOutputElementV8Internal::defaultValueAttributeGetterCallback, HTMLOutputElementV8Internal::defaultValueAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "value", HTMLOutputElementV8Internal::valueAttributeGetterCallback, HTMLOutputElementV8Internal::valueAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "willValidate", HTMLOutputElementV8Internal::willValidateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "validity", HTMLOutputElementV8Internal::validityAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "validationMessage", HTMLOutputElementV8Internal::validationMessageAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "labels", HTMLOutputElementV8Internal::labelsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8HTMLOutputElementMethods[] = {
    { "checkValidity", HTMLOutputElementV8Internal::checkValidityMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "reportValidity", HTMLOutputElementV8Internal::reportValidityMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "setCustomValidity", HTMLOutputElementV8Internal::setCustomValidityMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8HTMLOutputElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLOutputElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLOutputElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLOutputElementAccessors, WTF_ARRAY_LENGTH(V8HTMLOutputElementAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLOutputElementMethods, WTF_ARRAY_LENGTH(V8HTMLOutputElementMethods));
}

v8::Local<v8::FunctionTemplate> V8HTMLOutputElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLOutputElementTemplate);
}

bool V8HTMLOutputElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLOutputElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLOutputElement* V8HTMLOutputElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

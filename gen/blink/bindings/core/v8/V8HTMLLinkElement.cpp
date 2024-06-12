// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8HTMLLinkElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8DOMTokenList.h"
#include "bindings/core/v8/V8Document.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8StyleSheet.h"
#include "core/HTMLNames.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
#include "core/frame/UseCounter.h"
#include "core/origin_trials/OriginTrials.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8HTMLLinkElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLLinkElement::domTemplate, V8HTMLLinkElement::trace, V8HTMLLinkElement::traceWrappers, 0, nullptr, "HTMLLinkElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLLinkElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLLinkElement::s_wrapperTypeInfo = V8HTMLLinkElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLLinkElement>::value,
    "HTMLLinkElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLLinkElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLLinkElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLLinkElementV8Internal {

    static void disabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueBool(info, impl->fastHasAttribute(HTMLNames::disabledAttr));
    }

    CORE_EXPORT void disabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8HTMLLinkElement_Disabled_AttributeGetter);

        HTMLLinkElementV8Internal::disabledAttributeGetter(info);
    }

    static void disabledAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Skip on compact node DOMString getters.
        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLLinkElement", "disabled");

        // Prepare the value to be set.
        bool cppValue = toBoolean(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setBooleanAttribute(HTMLNames::disabledAttr, cppValue);
    }

    CORE_EXPORT void disabledAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8HTMLLinkElement_Disabled_AttributeSetter);

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::disabledAttributeSetter(v8Value, info);
    }

    static void hrefAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->getURLAttribute(HTMLNames::hrefAttr), info.GetIsolate());
    }

    CORE_EXPORT void hrefAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::hrefAttributeGetter(info);
    }

    static void hrefAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::hrefAttr, cppValue);
    }

    CORE_EXPORT void hrefAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::hrefAttributeSetter(v8Value, info);
    }

    static void crossOriginAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        String cppValue(impl->fastGetAttribute(HTMLNames::crossoriginAttr));

        if (cppValue.isNull()) {
            ;
        } else if (cppValue.isEmpty()) {
            cppValue = "anonymous";
        } else if (equalIgnoringASCIICase(cppValue, "anonymous")) {
            cppValue = "anonymous";
        } else if (equalIgnoringASCIICase(cppValue, "use-credentials")) {
            cppValue = "use-credentials";
        } else {
            cppValue = "anonymous";
        }

        v8SetReturnValueStringOrNull(info, cppValue, info.GetIsolate());
    }

    CORE_EXPORT void crossOriginAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::crossOriginAttributeGetter(info);
    }

    static void crossOriginAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<TreatNullAndUndefinedAsNullString> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::crossoriginAttr, cppValue);
    }

    CORE_EXPORT void crossOriginAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::crossOriginAttributeSetter(v8Value, info);
    }

    static void relAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::relAttr), info.GetIsolate());
    }

    CORE_EXPORT void relAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::relAttributeGetter(info);
    }

    static void relAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::relAttr, cppValue);
    }

    CORE_EXPORT void relAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::relAttributeSetter(v8Value, info);
    }

    static void relListAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->relList()), impl);
    }

    CORE_EXPORT void relListAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::relListAttributeGetter(info);
    }

    static void relListAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* proxyImpl = V8HTMLLinkElement::toImpl(holder);
        DOMTokenList* impl = WTF::getPtr(proxyImpl->relList());
        if (!impl)
            return;

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setValue(cppValue);
    }

    CORE_EXPORT void relListAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLLinkElementV8Internal::relListAttributeSetter(v8Value, info);
    }

    static void mediaAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::mediaAttr), info.GetIsolate());
    }

    CORE_EXPORT void mediaAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::mediaAttributeGetter(info);
    }

    static void mediaAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::mediaAttr, cppValue);
    }

    CORE_EXPORT void mediaAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::mediaAttributeSetter(v8Value, info);
    }

    static void hreflangAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::hreflangAttr), info.GetIsolate());
    }

    CORE_EXPORT void hreflangAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::hreflangAttributeGetter(info);
    }

    static void hreflangAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::hreflangAttr, cppValue);
    }

    CORE_EXPORT void hreflangAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::hreflangAttributeSetter(v8Value, info);
    }

    static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::typeAttr), info.GetIsolate());
    }

    CORE_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::typeAttributeGetter(info);
    }

    static void typeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::typeAttr, cppValue);
    }

    CORE_EXPORT void typeAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::typeAttributeSetter(v8Value, info);
    }

    static void asAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::asAttr), info.GetIsolate());
    }

    CORE_EXPORT void asAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::asAttributeGetter(info);
    }

    static void asAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::asAttr, cppValue);
    }

    CORE_EXPORT void asAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::asAttributeSetter(v8Value, info);
    }

    static void sizesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->sizes()), impl);
    }

    CORE_EXPORT void sizesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::sizesAttributeGetter(info);
    }

    static void sizesAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* proxyImpl = V8HTMLLinkElement::toImpl(holder);
        DOMTokenList* impl = WTF::getPtr(proxyImpl->sizes());
        if (!impl)
            return;

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setValue(cppValue);
    }

    CORE_EXPORT void sizesAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLLinkElementV8Internal::sizesAttributeSetter(v8Value, info);
    }

    static void charsetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::charsetAttr), info.GetIsolate());
    }

    CORE_EXPORT void charsetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::charsetAttributeGetter(info);
    }

    static void charsetAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::charsetAttr, cppValue);
    }

    CORE_EXPORT void charsetAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::charsetAttributeSetter(v8Value, info);
    }

    static void revAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::revAttr), info.GetIsolate());
    }

    CORE_EXPORT void revAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::revAttributeGetter(info);
    }

    static void revAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::revAttr, cppValue);
    }

    CORE_EXPORT void revAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::revAttributeSetter(v8Value, info);
    }

    static void targetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::targetAttr), info.GetIsolate());
    }

    CORE_EXPORT void targetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::targetAttributeGetter(info);
    }

    static void targetAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::targetAttr, cppValue);
    }

    CORE_EXPORT void targetAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::targetAttributeSetter(v8Value, info);
    }

    static void sheetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->sheet()), impl);
    }

    CORE_EXPORT void sheetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::sheetAttributeGetter(info);
    }

    static void importAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->import()), impl);
    }

    CORE_EXPORT void importAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::importAttributeGetter(info);
    }

    static void integrityAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::integrityAttr), info.GetIsolate());
    }

    CORE_EXPORT void integrityAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::integrityAttributeGetter(info);
    }

    static void integrityAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setAttribute(HTMLNames::integrityAttr, cppValue);
    }

    CORE_EXPORT void integrityAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::integrityAttributeSetter(v8Value, info);
    }

    static void scopeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        v8SetReturnValueString(info, impl->fastGetAttribute(HTMLNames::scopeAttr), info.GetIsolate());
    }

    CORE_EXPORT void scopeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLLinkElementV8Internal::scopeAttributeGetter(info);
    }

    static void scopeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLLinkElement* impl = V8HTMLLinkElement::toImpl(holder);

        // Skip on compact node DOMString getters.
        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLLinkElement", "scope");

        // Prepare the value to be set.
        V8StringResource<> cppValue = toUSVString(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setAttribute(HTMLNames::scopeAttr, cppValue);
    }

    CORE_EXPORT void scopeAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HTMLLinkElementV8Internal::scopeAttributeSetter(v8Value, info);
    }

} // namespace HTMLLinkElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLLinkElementAccessors[] = {
    { "disabled", HTMLLinkElementV8Internal::disabledAttributeGetterCallback, HTMLLinkElementV8Internal::disabledAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "href", HTMLLinkElementV8Internal::hrefAttributeGetterCallback, HTMLLinkElementV8Internal::hrefAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "crossOrigin", HTMLLinkElementV8Internal::crossOriginAttributeGetterCallback, HTMLLinkElementV8Internal::crossOriginAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "rel", HTMLLinkElementV8Internal::relAttributeGetterCallback, HTMLLinkElementV8Internal::relAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "relList", HTMLLinkElementV8Internal::relListAttributeGetterCallback, HTMLLinkElementV8Internal::relListAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "media", HTMLLinkElementV8Internal::mediaAttributeGetterCallback, HTMLLinkElementV8Internal::mediaAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "hreflang", HTMLLinkElementV8Internal::hreflangAttributeGetterCallback, HTMLLinkElementV8Internal::hreflangAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "type", HTMLLinkElementV8Internal::typeAttributeGetterCallback, HTMLLinkElementV8Internal::typeAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "as", HTMLLinkElementV8Internal::asAttributeGetterCallback, HTMLLinkElementV8Internal::asAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "sizes", HTMLLinkElementV8Internal::sizesAttributeGetterCallback, HTMLLinkElementV8Internal::sizesAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "charset", HTMLLinkElementV8Internal::charsetAttributeGetterCallback, HTMLLinkElementV8Internal::charsetAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "rev", HTMLLinkElementV8Internal::revAttributeGetterCallback, HTMLLinkElementV8Internal::revAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "target", HTMLLinkElementV8Internal::targetAttributeGetterCallback, HTMLLinkElementV8Internal::targetAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "sheet", HTMLLinkElementV8Internal::sheetAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "import", HTMLLinkElementV8Internal::importAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "integrity", HTMLLinkElementV8Internal::integrityAttributeGetterCallback, HTMLLinkElementV8Internal::integrityAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8HTMLLinkElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLLinkElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLLinkElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLLinkElementAccessors, WTF_ARRAY_LENGTH(V8HTMLLinkElementAccessors));
}

void V8HTMLLinkElement::installLinkServiceWorker(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::Object> instance, v8::Local<v8::Object> prototype, v8::Local<v8::Function> interface)
{
    v8::Local<v8::FunctionTemplate> interfaceTemplate = V8HTMLLinkElement::wrapperTypeInfo.domTemplate(isolate, world);
    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    const V8DOMConfiguration::AccessorConfiguration accessorscopeConfiguration = { "scope", HTMLLinkElementV8Internal::scopeAttributeGetterCallback, HTMLLinkElementV8Internal::scopeAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installAccessor(isolate, world, instance, prototype, interface, signature, accessorscopeConfiguration);
}

void V8HTMLLinkElement::installLinkServiceWorker(ScriptState* scriptState, v8::Local<v8::Object> instance)
{
    V8PerContextData* perContextData = V8PerContextData::from(scriptState->context());
    v8::Local<v8::Object> prototype = perContextData->prototypeForType(&V8HTMLLinkElement::wrapperTypeInfo);
    v8::Local<v8::Function> interface = perContextData->constructorForType(&V8HTMLLinkElement::wrapperTypeInfo);
    ALLOW_UNUSED_LOCAL(interface);
    installLinkServiceWorker(scriptState->isolate(), scriptState->world(), instance, prototype, interface);
}

void V8HTMLLinkElement::installLinkServiceWorker(ScriptState* scriptState)
{
    installLinkServiceWorker(scriptState, v8::Local<v8::Object>());
}

v8::Local<v8::FunctionTemplate> V8HTMLLinkElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8HTMLLinkElementTemplate);
}

bool V8HTMLLinkElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLLinkElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLLinkElement* V8HTMLLinkElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

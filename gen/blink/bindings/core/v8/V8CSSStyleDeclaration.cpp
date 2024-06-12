// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8CSSStyleDeclaration.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/StringOrFloat.h"
#include "bindings/core/v8/V8CSSRule.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8CSSStyleDeclaration::wrapperTypeInfo = { gin::kEmbedderBlink, V8CSSStyleDeclaration::domTemplate, V8CSSStyleDeclaration::trace, V8CSSStyleDeclaration::traceWrappers, V8CSSStyleDeclaration::visitDOMWrapper, nullptr, "CSSStyleDeclaration", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in CSSStyleDeclaration.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& CSSStyleDeclaration::s_wrapperTypeInfo = V8CSSStyleDeclaration::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, CSSStyleDeclaration>::value,
    "CSSStyleDeclaration inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&CSSStyleDeclaration::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "CSSStyleDeclaration is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace CSSStyleDeclarationV8Internal {

    static void cssTextAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(holder);

        v8SetReturnValueString(info, impl->cssText(), info.GetIsolate());
    }

    CORE_EXPORT void cssTextAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::cssTextAttributeGetter(info);
    }

    static void cssTextAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "CSSStyleDeclaration", "cssText");

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setCSSText(cppValue, exceptionState);
    }

    CORE_EXPORT void cssTextAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        CSSStyleDeclarationV8Internal::cssTextAttributeSetter(v8Value, info);
    }

    static void lengthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(holder);

        v8SetReturnValueUnsigned(info, impl->length());
    }

    CORE_EXPORT void lengthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::lengthAttributeGetter(info);
    }

    static void parentRuleAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(holder);

        CSSRule* cppValue(WTF::getPtr(impl->parentRule()));

        // Keep the wrapper object for the return value alive as long as |this|
        // object is alive in order to save creation time of the wrapper object.
        if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
            return;
        v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
        const char kKeepAliveKey[] = "KeepAlive#CSSStyleDeclaration#parentRule";
        V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

        v8SetReturnValue(info, v8Value);
    }

    CORE_EXPORT void parentRuleAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::parentRuleAttributeGetter(info);
    }

    static void cssFloatAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(holder);

        v8SetReturnValueString(info, impl->cssFloat(), info.GetIsolate());
    }

    CORE_EXPORT void cssFloatAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::cssFloatAttributeGetter(info);
    }

    static void cssFloatAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "CSSStyleDeclaration", "cssFloat");

        // Prepare the value to be set.
        V8StringResource<TreatNullAsEmptyString> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setCSSFloat(cppValue, exceptionState);
    }

    CORE_EXPORT void cssFloatAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        CSSStyleDeclarationV8Internal::cssFloatAttributeSetter(v8Value, info);
    }

    static void itemMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CSSStyleDeclaration", "item");

        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        unsigned index;
        index = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        v8SetReturnValueString(info, impl->item(index), info.GetIsolate());
    }

    CORE_EXPORT void itemMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::itemMethod(info);
    }

    static void getPropertyValueMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getPropertyValue", "CSSStyleDeclaration", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        V8StringResource<> property;
        property = info[0];
        if (!property.prepare())
            return;

        v8SetReturnValueString(info, impl->getPropertyValue(property), info.GetIsolate());
    }

    CORE_EXPORT void getPropertyValueMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::getPropertyValueMethod(info);
    }

    static void getPropertyPriorityMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getPropertyPriority", "CSSStyleDeclaration", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        V8StringResource<> property;
        property = info[0];
        if (!property.prepare())
            return;

        v8SetReturnValueString(info, impl->getPropertyPriority(property), info.GetIsolate());
    }

    CORE_EXPORT void getPropertyPriorityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::getPropertyPriorityMethod(info);
    }

    static void setPropertyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CSSStyleDeclaration", "setProperty");

        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        V8StringResource<> property;
        V8StringResource<TreatNullAndUndefinedAsNullString> value;
        V8StringResource<TreatNullAndUndefinedAsNullString> priority;
        property = info[0];
        if (!property.prepare())
            return;

        value = info[1];
        if (!value.prepare())
            return;

        if (!info[2]->IsUndefined()) {
            priority = info[2];
            if (!priority.prepare())
                return;
        } else {
            priority = nullptr;
        }

        impl->setProperty(property, value, priority, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void setPropertyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        CSSStyleDeclarationV8Internal::setPropertyMethod(info);
    }

    static void removePropertyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CSSStyleDeclaration", "removeProperty");

        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> property;
        property = info[0];
        if (!property.prepare())
            return;

        String result = impl->removeProperty(property, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValueString(info, result, info.GetIsolate());
    }

    CORE_EXPORT void removePropertyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        CSSStyleDeclarationV8Internal::removePropertyMethod(info);
    }

    CORE_EXPORT void namedPropertyGetterCallback(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        if (!name->IsString())
            return;
        const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

        V8CSSStyleDeclaration::namedPropertyGetterCustom(propertyName, info);
    }

    CORE_EXPORT void namedPropertySetterCallback(v8::Local<v8::Name> name, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        if (!name->IsString())
            return;
        const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

        V8CSSStyleDeclaration::namedPropertySetterCustom(propertyName, v8Value, info);
    }

    CORE_EXPORT void namedPropertyQueryCallback(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Integer>& info)
    {
        if (!name->IsString())
            return;
        const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

        V8CSSStyleDeclaration::namedPropertyQueryCustom(propertyName, info);
    }

    CORE_EXPORT void namedPropertyEnumeratorCallback(const v8::PropertyCallbackInfo<v8::Array>& info)
    {
        V8CSSStyleDeclaration::namedPropertyEnumeratorCustom(info);
    }

    static void indexedPropertyGetter(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclaration* impl = V8CSSStyleDeclaration::toImpl(info.Holder());

        // We assume that all the implementations support length() method, although
        // the spec doesn't require that length() must exist.  It's okay that
        // the interface does not have length attribute as long as the
        // implementation supports length() member function.
        if (index >= impl->length())
            return; // Returns undefined due to out-of-range.

        String result = impl->item(index);
        v8SetReturnValueString(info, result, info.GetIsolate());
    }

    CORE_EXPORT void indexedPropertyGetterCallback(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        CSSStyleDeclarationV8Internal::indexedPropertyGetter(index, info);
    }

    CORE_EXPORT void indexedPropertySetterCallback(uint32_t index, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        const AtomicString& propertyName = AtomicString::number(index);

        V8CSSStyleDeclaration::namedPropertySetterCustom(propertyName, v8Value, info);
    }

} // namespace CSSStyleDeclarationV8Internal

void V8CSSStyleDeclaration::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper)
{
    CSSStyleDeclaration* impl = scriptWrappable->toImpl<CSSStyleDeclaration>();
    CSSRule* parentRule = impl->parentRule();
    if (parentRule) {
        DOMWrapperWorld::setWrapperReferencesInAllWorlds(wrapper, parentRule, isolate);
    }
}

const V8DOMConfiguration::AccessorConfiguration V8CSSStyleDeclarationAccessors[] = {
    { "cssText", CSSStyleDeclarationV8Internal::cssTextAttributeGetterCallback, CSSStyleDeclarationV8Internal::cssTextAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "length", CSSStyleDeclarationV8Internal::lengthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "parentRule", CSSStyleDeclarationV8Internal::parentRuleAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "cssFloat", CSSStyleDeclarationV8Internal::cssFloatAttributeGetterCallback, CSSStyleDeclarationV8Internal::cssFloatAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8CSSStyleDeclarationMethods[] = {
    { "item", CSSStyleDeclarationV8Internal::itemMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getPropertyValue", CSSStyleDeclarationV8Internal::getPropertyValueMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getPropertyPriority", CSSStyleDeclarationV8Internal::getPropertyPriorityMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "setProperty", CSSStyleDeclarationV8Internal::setPropertyMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "removeProperty", CSSStyleDeclarationV8Internal::removePropertyMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8CSSStyleDeclarationTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8CSSStyleDeclaration::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8CSSStyleDeclaration::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CSSStyleDeclarationAccessors, WTF_ARRAY_LENGTH(V8CSSStyleDeclarationAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CSSStyleDeclarationMethods, WTF_ARRAY_LENGTH(V8CSSStyleDeclarationMethods));

    // Indexed properties
    v8::IndexedPropertyHandlerConfiguration indexedPropertyHandlerConfig(CSSStyleDeclarationV8Internal::indexedPropertyGetterCallback, CSSStyleDeclarationV8Internal::indexedPropertySetterCallback, 0, 0, indexedPropertyEnumerator<CSSStyleDeclaration>, v8::Local<v8::Value>(), v8::PropertyHandlerFlags::kNone);
    instanceTemplate->SetHandler(indexedPropertyHandlerConfig);
    // Named properties
    v8::NamedPropertyHandlerConfiguration namedPropertyHandlerConfig(CSSStyleDeclarationV8Internal::namedPropertyGetterCallback, CSSStyleDeclarationV8Internal::namedPropertySetterCallback, CSSStyleDeclarationV8Internal::namedPropertyQueryCallback, 0, CSSStyleDeclarationV8Internal::namedPropertyEnumeratorCallback, v8::Local<v8::Value>(), static_cast<v8::PropertyHandlerFlags>(int(v8::PropertyHandlerFlags::kOnlyInterceptStrings) | int(v8::PropertyHandlerFlags::kNonMasking)));
    instanceTemplate->SetHandler(namedPropertyHandlerConfig);

    // Array iterator (@@iterator)
    prototypeTemplate->SetIntrinsicDataProperty(v8::Symbol::GetIterator(isolate), v8::kArrayProto_values, v8::DontEnum);
}

v8::Local<v8::FunctionTemplate> V8CSSStyleDeclaration::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8CSSStyleDeclarationTemplate);
}

bool V8CSSStyleDeclaration::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8CSSStyleDeclaration::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

CSSStyleDeclaration* V8CSSStyleDeclaration::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

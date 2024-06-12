// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8OriginTrialsTest.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/origin_trials/OriginTrials.h"
#include "core/testing/OriginTrialsTestPartial.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8OriginTrialsTest::wrapperTypeInfo = { gin::kEmbedderBlink, V8OriginTrialsTest::domTemplate, V8OriginTrialsTest::trace, V8OriginTrialsTest::traceWrappers, 0, nullptr, "OriginTrialsTest", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in OriginTrialsTest.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& OriginTrialsTest::s_wrapperTypeInfo = V8OriginTrialsTest::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, OriginTrialsTest>::value,
    "OriginTrialsTest inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&OriginTrialsTest::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "OriginTrialsTest is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace OriginTrialsTestV8Internal {

    static void normalAttributeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        OriginTrialsTest* impl = V8OriginTrialsTest::toImpl(holder);

        v8SetReturnValueBool(info, impl->normalAttribute());
    }

    void normalAttributeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::normalAttributeAttributeGetter(info);
    }

    static void staticAttributeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8SetReturnValueBool(info, OriginTrialsTest::staticAttribute());
    }

    void staticAttributeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::staticAttributeAttributeGetter(info);
    }

    static void throwingAttributeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        OriginTrialsTest* impl = V8OriginTrialsTest::toImpl(holder);

        ScriptState* scriptState = ScriptState::forReceiverObject(info);
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::GetterContext, "OriginTrialsTest", "throwingAttribute");

        bool cppValue(impl->throwingAttribute(scriptState, exceptionState));

        if (UNLIKELY(exceptionState.hadException()))
            return;

        v8SetReturnValueBool(info, cppValue);
    }

    void throwingAttributeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::throwingAttributeAttributeGetter(info);
    }

    static void unconditionalAttributeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        OriginTrialsTest* impl = V8OriginTrialsTest::toImpl(holder);

        v8SetReturnValueBool(info, impl->unconditionalAttribute());
    }

    void unconditionalAttributeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::unconditionalAttributeAttributeGetter(info);
    }

    static void bindingsTestAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        OriginTrialsTest* impl = V8OriginTrialsTest::toImpl(holder);

        v8SetReturnValueBool(info, impl->unconditionalAttribute());
    }

    void bindingsTestAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::bindingsTestAttributeGetter(info);
    }

    static void normalAttributePartialAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        OriginTrialsTest* impl = V8OriginTrialsTest::toImpl(holder);

        v8SetReturnValueBool(info, OriginTrialsTestPartial::normalAttributePartial(*impl));
    }

    void normalAttributePartialAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::normalAttributePartialAttributeGetter(info);
    }

    static void staticAttributePartialAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8SetReturnValueBool(info, OriginTrialsTestPartial::staticAttributePartial());
    }

    void staticAttributePartialAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::staticAttributePartialAttributeGetter(info);
    }

    static void methodPartialMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTest* impl = V8OriginTrialsTest::toImpl(info.Holder());

        v8SetReturnValueBool(info, OriginTrialsTestPartial::methodPartial(*impl));
    }

    void methodPartialMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::methodPartialMethod(info);
    }

    static void staticMethodPartialMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8SetReturnValueBool(info, OriginTrialsTestPartial::staticMethodPartial());
    }

    void staticMethodPartialMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OriginTrialsTestV8Internal::staticMethodPartialMethod(info);
    }

} // namespace OriginTrialsTestV8Internal

const V8DOMConfiguration::AccessorConfiguration V8OriginTrialsTestAccessors[] = {
    { "throwingAttribute", OriginTrialsTestV8Internal::throwingAttributeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "unconditionalAttribute", OriginTrialsTestV8Internal::unconditionalAttributeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8OriginTrialsTestTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8OriginTrialsTest::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8OriginTrialsTest::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    static_assert(1 == OriginTrialsTest::kConstant, "the value of OriginTrialsTest_kConstant does not match with implementation");
    static_assert(2 == OriginTrialsTestPartial::kConstantPartial, "the value of OriginTrialsTest_kConstantPartial does not match with implementation");
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8OriginTrialsTestAccessors, WTF_ARRAY_LENGTH(V8OriginTrialsTestAccessors));
}

void V8OriginTrialsTest::installOriginTrialsSampleAPI(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::Object> instance, v8::Local<v8::Object> prototype, v8::Local<v8::Function> interface)
{
    v8::Local<v8::FunctionTemplate> interfaceTemplate = V8OriginTrialsTest::wrapperTypeInfo.domTemplate(isolate, world);
    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    const V8DOMConfiguration::AccessorConfiguration accessorbindingsTestConfiguration = { "bindingsTest", OriginTrialsTestV8Internal::bindingsTestAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installAccessor(isolate, world, instance, prototype, interface, signature, accessorbindingsTestConfiguration);
    const V8DOMConfiguration::AccessorConfiguration accessornormalAttributeConfiguration = { "normalAttribute", OriginTrialsTestV8Internal::normalAttributeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installAccessor(isolate, world, instance, prototype, interface, signature, accessornormalAttributeConfiguration);
    const V8DOMConfiguration::AccessorConfiguration accessornormalAttributePartialConfiguration = { "normalAttributePartial", OriginTrialsTestV8Internal::normalAttributePartialAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installAccessor(isolate, world, instance, prototype, interface, signature, accessornormalAttributePartialConfiguration);
    const V8DOMConfiguration::AccessorConfiguration accessorstaticAttributeConfiguration = { "staticAttribute", OriginTrialsTestV8Internal::staticAttributeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnInterface, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installAccessor(isolate, world, instance, prototype, interface, signature, accessorstaticAttributeConfiguration);
    const V8DOMConfiguration::AccessorConfiguration accessorstaticAttributePartialConfiguration = { "staticAttributePartial", OriginTrialsTestV8Internal::staticAttributePartialAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnInterface, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installAccessor(isolate, world, instance, prototype, interface, signature, accessorstaticAttributePartialConfiguration);
    const V8DOMConfiguration::ConstantConfiguration constantConstantConfiguration = { "CONSTANT", 1, 0, V8DOMConfiguration::ConstantTypeUnsignedShort };
    V8DOMConfiguration::installConstant(isolate, interface, prototype, constantConstantConfiguration);
    const V8DOMConfiguration::ConstantConfiguration constantConstantPartialConfiguration = { "CONSTANT_PARTIAL", 2, 0, V8DOMConfiguration::ConstantTypeUnsignedShort };
    V8DOMConfiguration::installConstant(isolate, interface, prototype, constantConstantPartialConfiguration);
    const V8DOMConfiguration::MethodConfiguration methodMethodpartialConfiguration = { "methodPartial", OriginTrialsTestV8Internal::methodPartialMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installMethod(isolate, world, instance, prototype, interface, signature, methodMethodpartialConfiguration);
    const V8DOMConfiguration::MethodConfiguration methodStaticmethodpartialConfiguration = { "staticMethodPartial", OriginTrialsTestV8Internal::staticMethodPartialMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnInterface, V8DOMConfiguration::CheckHolder };
    V8DOMConfiguration::installMethod(isolate, world, instance, prototype, interface, signature, methodStaticmethodpartialConfiguration);
}

void V8OriginTrialsTest::installOriginTrialsSampleAPI(ScriptState* scriptState, v8::Local<v8::Object> instance)
{
    V8PerContextData* perContextData = V8PerContextData::from(scriptState->context());
    v8::Local<v8::Object> prototype = perContextData->prototypeForType(&V8OriginTrialsTest::wrapperTypeInfo);
    v8::Local<v8::Function> interface = perContextData->constructorForType(&V8OriginTrialsTest::wrapperTypeInfo);
    ALLOW_UNUSED_LOCAL(interface);
    installOriginTrialsSampleAPI(scriptState->isolate(), scriptState->world(), instance, prototype, interface);
}

void V8OriginTrialsTest::installOriginTrialsSampleAPI(ScriptState* scriptState)
{
    installOriginTrialsSampleAPI(scriptState, v8::Local<v8::Object>());
}

v8::Local<v8::FunctionTemplate> V8OriginTrialsTest::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8OriginTrialsTestTemplate);
}

bool V8OriginTrialsTest::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8OriginTrialsTest::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

OriginTrialsTest* V8OriginTrialsTest::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

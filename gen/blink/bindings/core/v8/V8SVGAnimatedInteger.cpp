// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8SVGAnimatedInteger.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGElement.h"
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
const WrapperTypeInfo V8SVGAnimatedInteger::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGAnimatedInteger::domTemplate, V8SVGAnimatedInteger::trace, V8SVGAnimatedInteger::traceWrappers, V8SVGAnimatedInteger::visitDOMWrapper, nullptr, "SVGAnimatedInteger", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGAnimatedInteger.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGAnimatedInteger::s_wrapperTypeInfo = V8SVGAnimatedInteger::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGAnimatedInteger>::value,
    "SVGAnimatedInteger inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGAnimatedInteger::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGAnimatedInteger is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGAnimatedIntegerV8Internal {

    static void baseValAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGAnimatedInteger* impl = V8SVGAnimatedInteger::toImpl(holder);

        v8SetReturnValueInt(info, impl->baseVal());
    }

    CORE_EXPORT void baseValAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGAnimatedIntegerV8Internal::baseValAttributeGetter(info);
    }

    static void baseValAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        SVGAnimatedInteger* impl = V8SVGAnimatedInteger::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "SVGAnimatedInteger", "baseVal");

        // Prepare the value to be set.
        int cppValue = toInt32(info.GetIsolate(), v8Value, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setBaseVal(cppValue, exceptionState);
    }

    CORE_EXPORT void baseValAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        SVGAnimatedIntegerV8Internal::baseValAttributeSetter(v8Value, info);
    }

    static void animValAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGAnimatedInteger* impl = V8SVGAnimatedInteger::toImpl(holder);

        v8SetReturnValueInt(info, impl->animVal());
    }

    CORE_EXPORT void animValAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGAnimatedIntegerV8Internal::animValAttributeGetter(info);
    }

} // namespace SVGAnimatedIntegerV8Internal

void V8SVGAnimatedInteger::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper)
{
    SVGAnimatedInteger* impl = scriptWrappable->toImpl<SVGAnimatedInteger>();
    SVGElement* contextElement = impl->contextElement();
    if (contextElement) {
        DOMWrapperWorld::setWrapperReferencesInAllWorlds(wrapper, contextElement, isolate);
    }
}

const V8DOMConfiguration::AccessorConfiguration V8SVGAnimatedIntegerAccessors[] = {
    { "baseVal", SVGAnimatedIntegerV8Internal::baseValAttributeGetterCallback, SVGAnimatedIntegerV8Internal::baseValAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "animVal", SVGAnimatedIntegerV8Internal::animValAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8SVGAnimatedIntegerTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGAnimatedInteger::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8SVGAnimatedInteger::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGAnimatedIntegerAccessors, WTF_ARRAY_LENGTH(V8SVGAnimatedIntegerAccessors));
}

v8::Local<v8::FunctionTemplate> V8SVGAnimatedInteger::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGAnimatedIntegerTemplate);
}

bool V8SVGAnimatedInteger::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGAnimatedInteger::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGAnimatedInteger* V8SVGAnimatedInteger::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

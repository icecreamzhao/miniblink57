// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8SVGRect.h"

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
const WrapperTypeInfo V8SVGRect::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGRect::domTemplate, V8SVGRect::trace, V8SVGRect::traceWrappers, V8SVGRect::visitDOMWrapper, nullptr, "SVGRect", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGRectTearOff.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGRectTearOff::s_wrapperTypeInfo = V8SVGRect::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGRectTearOff>::value,
    "SVGRectTearOff inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGRectTearOff::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGRectTearOff is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGRectTearOffV8Internal {

    static void xAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        v8SetReturnValue(info, impl->x());
    }

    CORE_EXPORT void xAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGRectTearOffV8Internal::xAttributeGetter(info);
    }

    static void xAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "SVGRect", "x");

        // Prepare the value to be set.
        float cppValue = toFloat(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setX(cppValue, exceptionState);
    }

    CORE_EXPORT void xAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        SVGRectTearOffV8Internal::xAttributeSetter(v8Value, info);
    }

    static void yAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        v8SetReturnValue(info, impl->y());
    }

    CORE_EXPORT void yAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGRectTearOffV8Internal::yAttributeGetter(info);
    }

    static void yAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "SVGRect", "y");

        // Prepare the value to be set.
        float cppValue = toFloat(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setY(cppValue, exceptionState);
    }

    CORE_EXPORT void yAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        SVGRectTearOffV8Internal::yAttributeSetter(v8Value, info);
    }

    static void widthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        v8SetReturnValue(info, impl->width());
    }

    CORE_EXPORT void widthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGRectTearOffV8Internal::widthAttributeGetter(info);
    }

    static void widthAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "SVGRect", "width");

        // Prepare the value to be set.
        float cppValue = toFloat(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setWidth(cppValue, exceptionState);
    }

    CORE_EXPORT void widthAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        SVGRectTearOffV8Internal::widthAttributeSetter(v8Value, info);
    }

    static void heightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        v8SetReturnValue(info, impl->height());
    }

    CORE_EXPORT void heightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGRectTearOffV8Internal::heightAttributeGetter(info);
    }

    static void heightAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        SVGRectTearOff* impl = V8SVGRect::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "SVGRect", "height");

        // Prepare the value to be set.
        float cppValue = toFloat(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setHeight(cppValue, exceptionState);
    }

    CORE_EXPORT void heightAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        SVGRectTearOffV8Internal::heightAttributeSetter(v8Value, info);
    }

} // namespace SVGRectTearOffV8Internal

void V8SVGRect::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper)
{
    SVGRectTearOff* impl = scriptWrappable->toImpl<SVGRectTearOff>();
    SVGElement* contextElement = impl->contextElement();
    if (contextElement) {
        DOMWrapperWorld::setWrapperReferencesInAllWorlds(wrapper, contextElement, isolate);
    }
}

const V8DOMConfiguration::AccessorConfiguration V8SVGRectAccessors[] = {
    { "x", SVGRectTearOffV8Internal::xAttributeGetterCallback, SVGRectTearOffV8Internal::xAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "y", SVGRectTearOffV8Internal::yAttributeGetterCallback, SVGRectTearOffV8Internal::yAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "width", SVGRectTearOffV8Internal::widthAttributeGetterCallback, SVGRectTearOffV8Internal::widthAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "height", SVGRectTearOffV8Internal::heightAttributeGetterCallback, SVGRectTearOffV8Internal::heightAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8SVGRectTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGRect::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8SVGRect::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGRectAccessors, WTF_ARRAY_LENGTH(V8SVGRectAccessors));
}

v8::Local<v8::FunctionTemplate> V8SVGRect::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGRectTemplate);
}

bool V8SVGRect::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGRect::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGRectTearOff* V8SVGRect::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

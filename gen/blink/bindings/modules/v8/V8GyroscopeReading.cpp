// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8GyroscopeReading.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8GyroscopeReadingInit.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
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
const WrapperTypeInfo V8GyroscopeReading::wrapperTypeInfo = { gin::kEmbedderBlink, V8GyroscopeReading::domTemplate, V8GyroscopeReading::trace, V8GyroscopeReading::traceWrappers, 0, nullptr, "GyroscopeReading", &V8SensorReading::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in GyroscopeReading.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& GyroscopeReading::s_wrapperTypeInfo = V8GyroscopeReading::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, GyroscopeReading>::value,
    "GyroscopeReading inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&GyroscopeReading::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "GyroscopeReading is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace GyroscopeReadingV8Internal {

    static void xAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        GyroscopeReading* impl = V8GyroscopeReading::toImpl(holder);

        v8SetReturnValue(info, impl->x());
    }

    MODULES_EXPORT void xAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        GyroscopeReadingV8Internal::xAttributeGetter(info);
    }

    static void yAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        GyroscopeReading* impl = V8GyroscopeReading::toImpl(holder);

        v8SetReturnValue(info, impl->y());
    }

    MODULES_EXPORT void yAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        GyroscopeReadingV8Internal::yAttributeGetter(info);
    }

    static void zAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        GyroscopeReading* impl = V8GyroscopeReading::toImpl(holder);

        v8SetReturnValue(info, impl->z());
    }

    MODULES_EXPORT void zAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        GyroscopeReadingV8Internal::zAttributeGetter(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "GyroscopeReading");

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        GyroscopeReadingInit gyroscopeReadingInit;
        if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
            exceptionState.throwTypeError("parameter 1 ('gyroscopeReadingInit') is not an object.");

            return;
        }
        V8GyroscopeReadingInit::toImpl(info.GetIsolate(), info[0], gyroscopeReadingInit, exceptionState);
        if (exceptionState.hadException())
            return;

        GyroscopeReading* impl = GyroscopeReading::create(gyroscopeReadingInit);
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8GyroscopeReading::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace GyroscopeReadingV8Internal

const V8DOMConfiguration::AccessorConfiguration V8GyroscopeReadingAccessors[] = {
    { "x", GyroscopeReadingV8Internal::xAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "y", GyroscopeReadingV8Internal::yAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "z", GyroscopeReadingV8Internal::zAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8GyroscopeReading::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("GyroscopeReading"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    GyroscopeReadingV8Internal::constructor(info);
}

static void installV8GyroscopeReadingTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8GyroscopeReading::wrapperTypeInfo.interfaceName, V8SensorReading::domTemplate(isolate, world), V8GyroscopeReading::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8GyroscopeReading::constructorCallback);
    interfaceTemplate->SetLength(1);

    if (!RuntimeEnabledFeatures::sensorEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8GyroscopeReadingAccessors, WTF_ARRAY_LENGTH(V8GyroscopeReadingAccessors));
}

v8::Local<v8::FunctionTemplate> V8GyroscopeReading::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8GyroscopeReadingTemplate);
}

bool V8GyroscopeReading::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8GyroscopeReading::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

GyroscopeReading* V8GyroscopeReading::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

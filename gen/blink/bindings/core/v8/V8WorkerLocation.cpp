// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8WorkerLocation.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
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
const WrapperTypeInfo V8WorkerLocation::wrapperTypeInfo = { gin::kEmbedderBlink, V8WorkerLocation::domTemplate, V8WorkerLocation::trace, V8WorkerLocation::traceWrappers, 0, nullptr, "WorkerLocation", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in WorkerLocation.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& WorkerLocation::s_wrapperTypeInfo = V8WorkerLocation::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, WorkerLocation>::value,
    "WorkerLocation inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&WorkerLocation::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "WorkerLocation is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace WorkerLocationV8Internal {

    static void hrefAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->href(), info.GetIsolate());
    }

    CORE_EXPORT void hrefAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::hrefAttributeGetter(info);
    }

    static void originAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->origin(), info.GetIsolate());
    }

    CORE_EXPORT void originAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::originAttributeGetter(info);
    }

    static void protocolAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->protocol(), info.GetIsolate());
    }

    CORE_EXPORT void protocolAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::protocolAttributeGetter(info);
    }

    static void hostAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->host(), info.GetIsolate());
    }

    CORE_EXPORT void hostAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::hostAttributeGetter(info);
    }

    static void hostnameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->hostname(), info.GetIsolate());
    }

    CORE_EXPORT void hostnameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::hostnameAttributeGetter(info);
    }

    static void portAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->port(), info.GetIsolate());
    }

    CORE_EXPORT void portAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::portAttributeGetter(info);
    }

    static void pathnameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->pathname(), info.GetIsolate());
    }

    CORE_EXPORT void pathnameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::pathnameAttributeGetter(info);
    }

    static void searchAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->search(), info.GetIsolate());
    }

    CORE_EXPORT void searchAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::searchAttributeGetter(info);
    }

    static void hashAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        WorkerLocation* impl = V8WorkerLocation::toImpl(holder);

        v8SetReturnValueString(info, impl->hash(), info.GetIsolate());
    }

    CORE_EXPORT void hashAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::hashAttributeGetter(info);
    }

    static void toStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocation* impl = V8WorkerLocation::toImpl(info.Holder());

        v8SetReturnValueString(info, impl->href(), info.GetIsolate());
    }

    CORE_EXPORT void toStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerLocationV8Internal::toStringMethod(info);
    }

} // namespace WorkerLocationV8Internal

const V8DOMConfiguration::AccessorConfiguration V8WorkerLocationAccessors[] = {
    { "href", WorkerLocationV8Internal::hrefAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "origin", WorkerLocationV8Internal::originAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "protocol", WorkerLocationV8Internal::protocolAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "host", WorkerLocationV8Internal::hostAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "hostname", WorkerLocationV8Internal::hostnameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "port", WorkerLocationV8Internal::portAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "pathname", WorkerLocationV8Internal::pathnameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "search", WorkerLocationV8Internal::searchAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "hash", WorkerLocationV8Internal::hashAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8WorkerLocationMethods[] = {
    { "toString", WorkerLocationV8Internal::toStringMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8WorkerLocationTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8WorkerLocation::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8WorkerLocation::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8WorkerLocationAccessors, WTF_ARRAY_LENGTH(V8WorkerLocationAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8WorkerLocationMethods, WTF_ARRAY_LENGTH(V8WorkerLocationMethods));
}

v8::Local<v8::FunctionTemplate> V8WorkerLocation::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8WorkerLocationTemplate);
}

bool V8WorkerLocation::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8WorkerLocation::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

WorkerLocation* V8WorkerLocation::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

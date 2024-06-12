// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8BluetoothCharacteristicProperties.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
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
const WrapperTypeInfo V8BluetoothCharacteristicProperties::wrapperTypeInfo = { gin::kEmbedderBlink, V8BluetoothCharacteristicProperties::domTemplate, V8BluetoothCharacteristicProperties::trace, V8BluetoothCharacteristicProperties::traceWrappers, 0, nullptr, "BluetoothCharacteristicProperties", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in BluetoothCharacteristicProperties.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& BluetoothCharacteristicProperties::s_wrapperTypeInfo = V8BluetoothCharacteristicProperties::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, BluetoothCharacteristicProperties>::value,
    "BluetoothCharacteristicProperties inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&BluetoothCharacteristicProperties::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "BluetoothCharacteristicProperties is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace BluetoothCharacteristicPropertiesV8Internal {

    static void broadcastAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->broadcast());
    }

    MODULES_EXPORT void broadcastAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::broadcastAttributeGetter(info);
    }

    static void readAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->read());
    }

    MODULES_EXPORT void readAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::readAttributeGetter(info);
    }

    static void writeWithoutResponseAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->writeWithoutResponse());
    }

    MODULES_EXPORT void writeWithoutResponseAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::writeWithoutResponseAttributeGetter(info);
    }

    static void writeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->write());
    }

    MODULES_EXPORT void writeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::writeAttributeGetter(info);
    }

    static void notifyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->notify());
    }

    MODULES_EXPORT void notifyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::notifyAttributeGetter(info);
    }

    static void indicateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->indicate());
    }

    MODULES_EXPORT void indicateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::indicateAttributeGetter(info);
    }

    static void authenticatedSignedWritesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->authenticatedSignedWrites());
    }

    MODULES_EXPORT void authenticatedSignedWritesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::authenticatedSignedWritesAttributeGetter(info);
    }

    static void reliableWriteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->reliableWrite());
    }

    MODULES_EXPORT void reliableWriteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::reliableWriteAttributeGetter(info);
    }

    static void writableAuxiliariesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        BluetoothCharacteristicProperties* impl = V8BluetoothCharacteristicProperties::toImpl(holder);

        v8SetReturnValueBool(info, impl->writableAuxiliaries());
    }

    MODULES_EXPORT void writableAuxiliariesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        BluetoothCharacteristicPropertiesV8Internal::writableAuxiliariesAttributeGetter(info);
    }

} // namespace BluetoothCharacteristicPropertiesV8Internal

const V8DOMConfiguration::AccessorConfiguration V8BluetoothCharacteristicPropertiesAccessors[] = {
    { "broadcast", BluetoothCharacteristicPropertiesV8Internal::broadcastAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "read", BluetoothCharacteristicPropertiesV8Internal::readAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "writeWithoutResponse", BluetoothCharacteristicPropertiesV8Internal::writeWithoutResponseAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "write", BluetoothCharacteristicPropertiesV8Internal::writeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "notify", BluetoothCharacteristicPropertiesV8Internal::notifyAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "indicate", BluetoothCharacteristicPropertiesV8Internal::indicateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "authenticatedSignedWrites", BluetoothCharacteristicPropertiesV8Internal::authenticatedSignedWritesAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "reliableWrite", BluetoothCharacteristicPropertiesV8Internal::reliableWriteAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "writableAuxiliaries", BluetoothCharacteristicPropertiesV8Internal::writableAuxiliariesAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8BluetoothCharacteristicPropertiesTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8BluetoothCharacteristicProperties::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8BluetoothCharacteristicProperties::internalFieldCount);

    if (!RuntimeEnabledFeatures::webBluetoothEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8BluetoothCharacteristicPropertiesAccessors, WTF_ARRAY_LENGTH(V8BluetoothCharacteristicPropertiesAccessors));
}

v8::Local<v8::FunctionTemplate> V8BluetoothCharacteristicProperties::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8BluetoothCharacteristicPropertiesTemplate);
}

bool V8BluetoothCharacteristicProperties::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8BluetoothCharacteristicProperties::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

BluetoothCharacteristicProperties* V8BluetoothCharacteristicProperties::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

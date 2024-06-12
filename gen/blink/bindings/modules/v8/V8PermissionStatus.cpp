// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8PermissionStatus.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8EventListenerHelper.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/inspector/ConsoleMessage.h"
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
const WrapperTypeInfo V8PermissionStatus::wrapperTypeInfo = { gin::kEmbedderBlink, V8PermissionStatus::domTemplate, V8PermissionStatus::trace, V8PermissionStatus::traceWrappers, 0, nullptr, "PermissionStatus", &V8EventTarget::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::InheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in PermissionStatus.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& PermissionStatus::s_wrapperTypeInfo = V8PermissionStatus::wrapperTypeInfo;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, PermissionStatus>::value,
    "PermissionStatus does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&PermissionStatus::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "PermissionStatus is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace PermissionStatusV8Internal {

    static void stateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        PermissionStatus* impl = V8PermissionStatus::toImpl(holder);

        v8SetReturnValueString(info, impl->state(), info.GetIsolate());
    }

    MODULES_EXPORT void stateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PermissionStatusV8Internal::stateAttributeGetter(info);
    }

    static void onchangeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        PermissionStatus* impl = V8PermissionStatus::toImpl(holder);

        EventListener* cppValue(WTF::getPtr(impl->onchange()));

        v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
    }

    MODULES_EXPORT void onchangeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        PermissionStatusV8Internal::onchangeAttributeGetter(info);
    }

    static void onchangeAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        PermissionStatus* impl = V8PermissionStatus::toImpl(holder);

        // Prepare the value to be set.
        moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onchange(), v8Value, V8PermissionStatus::eventListenerCacheIndex);

        impl->setOnchange(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
    }

    MODULES_EXPORT void onchangeAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        PermissionStatusV8Internal::onchangeAttributeSetter(v8Value, info);
    }

} // namespace PermissionStatusV8Internal

const V8DOMConfiguration::AccessorConfiguration V8PermissionStatusAccessors[] = {
    { "state", PermissionStatusV8Internal::stateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "onchange", PermissionStatusV8Internal::onchangeAttributeGetterCallback, PermissionStatusV8Internal::onchangeAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8PermissionStatusTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8PermissionStatus::wrapperTypeInfo.interfaceName, V8EventTarget::domTemplate(isolate, world), V8PermissionStatus::internalFieldCount);

    if (!RuntimeEnabledFeatures::permissionsEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8PermissionStatusAccessors, WTF_ARRAY_LENGTH(V8PermissionStatusAccessors));
}

v8::Local<v8::FunctionTemplate> V8PermissionStatus::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8PermissionStatusTemplate);
}

bool V8PermissionStatus::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8PermissionStatus::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

PermissionStatus* V8PermissionStatus::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8CSSImageValue.h"

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
const WrapperTypeInfo V8CSSImageValue::wrapperTypeInfo = { gin::kEmbedderBlink, V8CSSImageValue::domTemplate, V8CSSImageValue::trace, V8CSSImageValue::traceWrappers, 0, nullptr, "CSSImageValue", &V8CSSResourceValue::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in CSSStyleImageValue.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& CSSStyleImageValue::s_wrapperTypeInfo = V8CSSImageValue::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, CSSStyleImageValue>::value,
    "CSSStyleImageValue inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&CSSStyleImageValue::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "CSSStyleImageValue is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace CSSStyleImageValueV8Internal {

    static void intrinsicWidthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSStyleImageValue* impl = V8CSSImageValue::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->intrinsicWidth(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void intrinsicWidthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleImageValueV8Internal::intrinsicWidthAttributeGetter(info);
    }

    static void intrinsicHeightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSStyleImageValue* impl = V8CSSImageValue::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->intrinsicHeight(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void intrinsicHeightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleImageValueV8Internal::intrinsicHeightAttributeGetter(info);
    }

    static void intrinsicRatioAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSStyleImageValue* impl = V8CSSImageValue::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->intrinsicRatio(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void intrinsicRatioAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSStyleImageValueV8Internal::intrinsicRatioAttributeGetter(info);
    }

} // namespace CSSStyleImageValueV8Internal

const V8DOMConfiguration::AccessorConfiguration V8CSSImageValueAccessors[] = {
    { "intrinsicWidth", CSSStyleImageValueV8Internal::intrinsicWidthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "intrinsicHeight", CSSStyleImageValueV8Internal::intrinsicHeightAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "intrinsicRatio", CSSStyleImageValueV8Internal::intrinsicRatioAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8CSSImageValueTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8CSSImageValue::wrapperTypeInfo.interfaceName, V8CSSResourceValue::domTemplate(isolate, world), V8CSSImageValue::internalFieldCount);

    if (!RuntimeEnabledFeatures::cssTypedOMEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CSSImageValueAccessors, WTF_ARRAY_LENGTH(V8CSSImageValueAccessors));
}

v8::Local<v8::FunctionTemplate> V8CSSImageValue::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8CSSImageValueTemplate);
}

bool V8CSSImageValue::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8CSSImageValue::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

CSSStyleImageValue* V8CSSImageValue::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

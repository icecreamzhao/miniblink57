// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8CSSCalcLength.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8CSSCalcDictionary.h"
#include "bindings/core/v8/V8CSSLengthValue.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
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
const WrapperTypeInfo V8CSSCalcLength::wrapperTypeInfo = { gin::kEmbedderBlink, V8CSSCalcLength::domTemplate, V8CSSCalcLength::trace, V8CSSCalcLength::traceWrappers, 0, nullptr, "CSSCalcLength", &V8CSSLengthValue::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in CSSCalcLength.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& CSSCalcLength::s_wrapperTypeInfo = V8CSSCalcLength::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, CSSCalcLength>::value,
    "CSSCalcLength inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&CSSCalcLength::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "CSSCalcLength is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace CSSCalcLengthV8Internal {

    static void pxAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->px(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void pxAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::pxAttributeGetter(info);
    }

    static void percentAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->percent(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void percentAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::percentAttributeGetter(info);
    }

    static void emAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->em(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void emAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::emAttributeGetter(info);
    }

    static void exAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->ex(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void exAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::exAttributeGetter(info);
    }

    static void chAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->ch(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void chAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::chAttributeGetter(info);
    }

    static void remAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->rem(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void remAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::remAttributeGetter(info);
    }

    static void vwAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->vw(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void vwAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::vwAttributeGetter(info);
    }

    static void vhAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->vh(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void vhAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::vhAttributeGetter(info);
    }

    static void vminAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->vmin(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void vminAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::vminAttributeGetter(info);
    }

    static void vmaxAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->vmax(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void vmaxAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::vmaxAttributeGetter(info);
    }

    static void cmAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->cm(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void cmAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::cmAttributeGetter(info);
    }

    static void mmAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->mm(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void mmAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::mmAttributeGetter(info);
    }

    static void inAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->in(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void inAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::inAttributeGetter(info);
    }

    static void pcAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->pc(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void pcAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::pcAttributeGetter(info);
    }

    static void ptAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        CSSCalcLength* impl = V8CSSCalcLength::toImpl(holder);

        bool isNull = false;

        double cppValue(impl->pt(isNull));

        if (isNull) {
            v8SetReturnValueNull(info);
            return;
        }

        v8SetReturnValue(info, cppValue);
    }

    CORE_EXPORT void ptAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CSSCalcLengthV8Internal::ptAttributeGetter(info);
    }

    static void constructor1(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "CSSCalcLength");

        CSSLengthValue* length;
        length = V8CSSLengthValue::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!length) {
            exceptionState.throwTypeError("parameter 1 is not of type 'CSSLengthValue'.");

            return;
        }

        CSSCalcLength* impl = CSSCalcLength::create(length, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8CSSCalcLength::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

    static void constructor2(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "CSSCalcLength");

        CSSCalcDictionary calcDictionary;
        if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
            exceptionState.throwTypeError("parameter 1 ('calcDictionary') is not an object.");

            return;
        }
        V8CSSCalcDictionary::toImpl(info.GetIsolate(), info[0], calcDictionary, exceptionState);
        if (exceptionState.hadException())
            return;

        CSSCalcLength* impl = CSSCalcLength::create(calcDictionary, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8CSSCalcLength::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "CSSCalcLength");
        switch (std::min(1, info.Length())) {
        case 1:
            if (V8CSSLengthValue::hasInstance(info[0], info.GetIsolate())) {
                CSSCalcLengthV8Internal::constructor1(info);
                return;
            }
            if (info[0]->IsObject()) {
                CSSCalcLengthV8Internal::constructor2(info);
                return;
            }
            break;
        default:
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }
        exceptionState.throwTypeError("No matching constructor signature.");
    }

} // namespace CSSCalcLengthV8Internal

const V8DOMConfiguration::AccessorConfiguration V8CSSCalcLengthAccessors[] = {
    { "px", CSSCalcLengthV8Internal::pxAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "percent", CSSCalcLengthV8Internal::percentAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "em", CSSCalcLengthV8Internal::emAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "ex", CSSCalcLengthV8Internal::exAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "ch", CSSCalcLengthV8Internal::chAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "rem", CSSCalcLengthV8Internal::remAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "vw", CSSCalcLengthV8Internal::vwAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "vh", CSSCalcLengthV8Internal::vhAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "vmin", CSSCalcLengthV8Internal::vminAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "vmax", CSSCalcLengthV8Internal::vmaxAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "cm", CSSCalcLengthV8Internal::cmAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "mm", CSSCalcLengthV8Internal::mmAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "in", CSSCalcLengthV8Internal::inAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "pc", CSSCalcLengthV8Internal::pcAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "pt", CSSCalcLengthV8Internal::ptAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8CSSCalcLength::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("CSSCalcLength"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    CSSCalcLengthV8Internal::constructor(info);
}

static void installV8CSSCalcLengthTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8CSSCalcLength::wrapperTypeInfo.interfaceName, V8CSSLengthValue::domTemplate(isolate, world), V8CSSCalcLength::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8CSSCalcLength::constructorCallback);
    interfaceTemplate->SetLength(1);

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
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CSSCalcLengthAccessors, WTF_ARRAY_LENGTH(V8CSSCalcLengthAccessors));
}

v8::Local<v8::FunctionTemplate> V8CSSCalcLength::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8CSSCalcLengthTemplate);
}

bool V8CSSCalcLength::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8CSSCalcLength::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

CSSCalcLength* V8CSSCalcLength::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

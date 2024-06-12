// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8HTMLCanvasElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8BlobCallback.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/frame/UseCounter.h"
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
WrapperTypeInfo V8HTMLCanvasElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8HTMLCanvasElement::domTemplate, V8HTMLCanvasElement::trace, V8HTMLCanvasElement::traceWrappers, 0, nullptr, "HTMLCanvasElement", &V8HTMLElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLCanvasElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& HTMLCanvasElement::s_wrapperTypeInfo = V8HTMLCanvasElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, HTMLCanvasElement>::value,
    "HTMLCanvasElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&HTMLCanvasElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "HTMLCanvasElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace HTMLCanvasElementV8Internal {

    static void widthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLCanvasElement* impl = V8HTMLCanvasElement::toImpl(holder);

        v8SetReturnValueInt(info, impl->width());
    }

    CORE_EXPORT void widthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLCanvasElementV8Internal::widthAttributeGetter(info);
    }

    static void widthAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLCanvasElement* impl = V8HTMLCanvasElement::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLCanvasElement", "width");

        // Prepare the value to be set.
        int cppValue = toInt32(info.GetIsolate(), v8Value, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setWidth(cppValue, exceptionState);
    }

    CORE_EXPORT void widthAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLCanvasElementV8Internal::widthAttributeSetter(v8Value, info);
    }

    static void heightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        HTMLCanvasElement* impl = V8HTMLCanvasElement::toImpl(holder);

        v8SetReturnValueInt(info, impl->height());
    }

    CORE_EXPORT void heightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLCanvasElementV8Internal::heightAttributeGetter(info);
    }

    static void heightAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        HTMLCanvasElement* impl = V8HTMLCanvasElement::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "HTMLCanvasElement", "height");

        // Prepare the value to be set.
        int cppValue = toInt32(info.GetIsolate(), v8Value, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setHeight(cppValue, exceptionState);
    }

    CORE_EXPORT void heightAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        CEReactionsScope ceReactionsScope;

        HTMLCanvasElementV8Internal::heightAttributeSetter(v8Value, info);
    }

    static void toDataURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "HTMLCanvasElement", "toDataURL");

        HTMLCanvasElement* impl = V8HTMLCanvasElement::toImpl(info.Holder());

        V8StringResource<> type;
        ScriptValue arguments;
        int numArgsPassed = info.Length();
        while (numArgsPassed > 0) {
            if (!info[numArgsPassed - 1]->IsUndefined())
                break;
            --numArgsPassed;
        }
        if (!info[0]->IsUndefined()) {
            type = info[0];
            if (!type.prepare())
                return;
        } else {
            type = nullptr;
        }
        if (UNLIKELY(numArgsPassed <= 1)) {
            String result = impl->toDataURL(type, exceptionState);
            if (exceptionState.hadException()) {
                return;
            }
            v8SetReturnValueString(info, result, info.GetIsolate());
            return;
        }
        arguments = ScriptValue(ScriptState::current(info.GetIsolate()), info[1]);

        String result = impl->toDataURL(type, arguments, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValueString(info, result, info.GetIsolate());
    }

    CORE_EXPORT void toDataURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLCanvasElementV8Internal::toDataURLMethod(info);
    }

    static void toBlobMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "HTMLCanvasElement", "toBlob");

        HTMLCanvasElement* impl = V8HTMLCanvasElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        BlobCallback* callback;
        V8StringResource<> type;
        ScriptValue arguments;
        int numArgsPassed = info.Length();
        while (numArgsPassed > 0) {
            if (!info[numArgsPassed - 1]->IsUndefined())
                break;
            --numArgsPassed;
        }
        if (info.Length() <= 0 || !info[0]->IsFunction()) {
            exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

            return;
        }
        callback = V8BlobCallback::create(v8::Local<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));

        if (!info[1]->IsUndefined()) {
            type = info[1];
            if (!type.prepare())
                return;
        } else {
            type = nullptr;
        }
        if (UNLIKELY(numArgsPassed <= 2)) {
            impl->toBlob(callback, type, exceptionState);
            if (exceptionState.hadException()) {
                return;
            }
            return;
        }
        arguments = ScriptValue(ScriptState::current(info.GetIsolate()), info[2]);

        impl->toBlob(callback, type, arguments, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void toBlobMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        HTMLCanvasElementV8Internal::toBlobMethod(info);
    }

} // namespace HTMLCanvasElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8HTMLCanvasElementAccessors[] = {
    { "width", HTMLCanvasElementV8Internal::widthAttributeGetterCallback, HTMLCanvasElementV8Internal::widthAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "height", HTMLCanvasElementV8Internal::heightAttributeGetterCallback, HTMLCanvasElementV8Internal::heightAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8HTMLCanvasElementMethods[] = {
    { "toDataURL", HTMLCanvasElementV8Internal::toDataURLMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "toBlob", HTMLCanvasElementV8Internal::toBlobMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8HTMLCanvasElement::installV8HTMLCanvasElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8HTMLCanvasElement::wrapperTypeInfo.interfaceName, V8HTMLElement::domTemplate(isolate, world), V8HTMLCanvasElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLCanvasElementAccessors, WTF_ARRAY_LENGTH(V8HTMLCanvasElementAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8HTMLCanvasElementMethods, WTF_ARRAY_LENGTH(V8HTMLCanvasElementMethods));
}

v8::Local<v8::FunctionTemplate> V8HTMLCanvasElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), V8HTMLCanvasElement::installV8HTMLCanvasElementTemplateFunction);
}

bool V8HTMLCanvasElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8HTMLCanvasElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

HTMLCanvasElement* V8HTMLCanvasElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

InstallTemplateFunction V8HTMLCanvasElement::installV8HTMLCanvasElementTemplateFunction = (InstallTemplateFunction)&V8HTMLCanvasElement::installV8HTMLCanvasElementTemplate;

void V8HTMLCanvasElement::updateWrapperTypeInfo(InstallTemplateFunction installTemplateFunction, PreparePrototypeAndInterfaceObjectFunction preparePrototypeAndInterfaceObjectFunction)
{
    V8HTMLCanvasElement::installV8HTMLCanvasElementTemplateFunction = installTemplateFunction;
    if (preparePrototypeAndInterfaceObjectFunction)
        V8HTMLCanvasElement::wrapperTypeInfo.preparePrototypeAndInterfaceObjectFunction = preparePrototypeAndInterfaceObjectFunction;
}

} // namespace blink

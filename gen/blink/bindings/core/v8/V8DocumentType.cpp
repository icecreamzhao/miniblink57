// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8DocumentType.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/ChildNode.h"
#include "core/dom/Document.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
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
const WrapperTypeInfo V8DocumentType::wrapperTypeInfo = { gin::kEmbedderBlink, V8DocumentType::domTemplate, V8DocumentType::trace, V8DocumentType::traceWrappers, 0, V8DocumentType::preparePrototypeAndInterfaceObject, "DocumentType", &V8Node::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DocumentType.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& DocumentType::s_wrapperTypeInfo = V8DocumentType::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DocumentType>::value,
    "DocumentType inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DocumentType::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DocumentType is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace DocumentTypeV8Internal {

    static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentType* impl = V8DocumentType::toImpl(holder);

        v8SetReturnValueString(info, impl->name(), info.GetIsolate());
    }

    CORE_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentTypeV8Internal::nameAttributeGetter(info);
    }

    static void publicIdAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentType* impl = V8DocumentType::toImpl(holder);

        v8SetReturnValueString(info, impl->publicId(), info.GetIsolate());
    }

    CORE_EXPORT void publicIdAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentTypeV8Internal::publicIdAttributeGetter(info);
    }

    static void systemIdAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentType* impl = V8DocumentType::toImpl(holder);

        v8SetReturnValueString(info, impl->systemId(), info.GetIsolate());
    }

    CORE_EXPORT void systemIdAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentTypeV8Internal::systemIdAttributeGetter(info);
    }

    static void beforeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentType", "before");

        DocumentType* impl = V8DocumentType::toImpl(info.Holder());

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HeapVector<NodeOrString> nodes;
        nodes = toImplArguments<HeapVector<NodeOrString>>(info, 0, exceptionState);
        if (exceptionState.hadException())
            return;

        ChildNode::before(*impl, nodes, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void beforeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        DocumentTypeV8Internal::beforeMethod(info);
    }

    static void afterMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentType", "after");

        DocumentType* impl = V8DocumentType::toImpl(info.Holder());

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HeapVector<NodeOrString> nodes;
        nodes = toImplArguments<HeapVector<NodeOrString>>(info, 0, exceptionState);
        if (exceptionState.hadException())
            return;

        ChildNode::after(*impl, nodes, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void afterMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        DocumentTypeV8Internal::afterMethod(info);
    }

    static void replaceWithMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentType", "replaceWith");

        DocumentType* impl = V8DocumentType::toImpl(info.Holder());

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HeapVector<NodeOrString> nodes;
        nodes = toImplArguments<HeapVector<NodeOrString>>(info, 0, exceptionState);
        if (exceptionState.hadException())
            return;

        ChildNode::replaceWith(*impl, nodes, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void replaceWithMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        DocumentTypeV8Internal::replaceWithMethod(info);
    }

    static void removeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentType", "remove");

        DocumentType* impl = V8DocumentType::toImpl(info.Holder());

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        ChildNode::remove(*impl, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void removeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        DocumentTypeV8Internal::removeMethod(info);
    }

} // namespace DocumentTypeV8Internal

const V8DOMConfiguration::AccessorConfiguration V8DocumentTypeAccessors[] = {
    { "name", DocumentTypeV8Internal::nameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "publicId", DocumentTypeV8Internal::publicIdAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "systemId", DocumentTypeV8Internal::systemIdAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8DocumentTypeMethods[] = {
    { "remove", DocumentTypeV8Internal::removeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8DocumentTypeTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8DocumentType::wrapperTypeInfo.interfaceName, V8Node::domTemplate(isolate, world), V8DocumentType::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DocumentTypeAccessors, WTF_ARRAY_LENGTH(V8DocumentTypeAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DocumentTypeMethods, WTF_ARRAY_LENGTH(V8DocumentTypeMethods));

    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        const V8DOMConfiguration::MethodConfiguration beforeMethodConfiguration = { "before", DocumentTypeV8Internal::beforeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, beforeMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        const V8DOMConfiguration::MethodConfiguration afterMethodConfiguration = { "after", DocumentTypeV8Internal::afterMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, afterMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        const V8DOMConfiguration::MethodConfiguration replaceWithMethodConfiguration = { "replaceWith", DocumentTypeV8Internal::replaceWithMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, replaceWithMethodConfiguration);
    }
}

v8::Local<v8::FunctionTemplate> V8DocumentType::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8DocumentTypeTemplate);
}

bool V8DocumentType::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8DocumentType::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

DocumentType* V8DocumentType::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

void V8DocumentType::preparePrototypeAndInterfaceObject(v8::Local<v8::Context> context, const DOMWrapperWorld& world, v8::Local<v8::Object> prototypeObject, v8::Local<v8::Function> interfaceObject, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    v8::Isolate* isolate = context->GetIsolate();
    v8::Local<v8::Name> unscopablesSymbol(v8::Symbol::GetUnscopables(isolate));
    v8::Local<v8::Object> unscopables;
    if (v8CallBoolean(prototypeObject->HasOwnProperty(context, unscopablesSymbol)))
        unscopables = prototypeObject->Get(context, unscopablesSymbol).ToLocalChecked().As<v8::Object>();
    else
        unscopables = v8::Object::New(isolate);
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        unscopables->CreateDataProperty(context, v8AtomicString(isolate, "after"), v8::True(isolate)).FromJust();
    }
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        unscopables->CreateDataProperty(context, v8AtomicString(isolate, "before"), v8::True(isolate)).FromJust();
    }
    unscopables->CreateDataProperty(context, v8AtomicString(isolate, "remove"), v8::True(isolate)).FromJust();
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        unscopables->CreateDataProperty(context, v8AtomicString(isolate, "replaceWith"), v8::True(isolate)).FromJust();
    }
    prototypeObject->CreateDataProperty(context, unscopablesSymbol, unscopables).FromJust();
}

} // namespace blink

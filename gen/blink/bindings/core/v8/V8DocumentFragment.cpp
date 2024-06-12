// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8DocumentFragment.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Element.h"
#include "bindings/core/v8/V8HTMLCollection.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/V8NodeList.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/ClassCollection.h"
#include "core/dom/Document.h"
#include "core/dom/NameNodeList.h"
#include "core/dom/NodeList.h"
#include "core/dom/NonElementParentNode.h"
#include "core/dom/ParentNode.h"
#include "core/dom/StaticNodeList.h"
#include "core/dom/TagCollection.h"
#include "core/dom/custom/CEReactionsScope.h"
#include "core/dom/custom/V0CustomElementProcessingStack.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/html/HTMLCollection.h"
#include "core/html/HTMLDataListOptionsCollection.h"
#include "core/html/HTMLFormControlsCollection.h"
#include "core/html/HTMLTableRowsCollection.h"
#include "core/html/LabelsNodeList.h"
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
const WrapperTypeInfo V8DocumentFragment::wrapperTypeInfo = { gin::kEmbedderBlink, V8DocumentFragment::domTemplate, V8DocumentFragment::trace, V8DocumentFragment::traceWrappers, 0, V8DocumentFragment::preparePrototypeAndInterfaceObject, "DocumentFragment", &V8Node::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DocumentFragment.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& DocumentFragment::s_wrapperTypeInfo = V8DocumentFragment::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DocumentFragment>::value,
    "DocumentFragment inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DocumentFragment::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DocumentFragment is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace DocumentFragmentV8Internal {

    static void childrenAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentFragment* impl = V8DocumentFragment::toImpl(holder);

        v8SetReturnValueFast(info, ParentNode::children(*impl), impl);
    }

    CORE_EXPORT void childrenAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::childrenAttributeGetter(info);
    }

    static void childrenAttributeGetterForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentFragment* impl = V8DocumentFragment::toImpl(holder);

        v8SetReturnValueForMainWorld(info, ParentNode::children(*impl));
    }

    CORE_EXPORT void childrenAttributeGetterCallbackForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::childrenAttributeGetterForMainWorld(info);
    }

    static void firstElementChildAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentFragment* impl = V8DocumentFragment::toImpl(holder);

        v8SetReturnValueFast(info, ParentNode::firstElementChild(*impl), impl);
    }

    CORE_EXPORT void firstElementChildAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::firstElementChildAttributeGetter(info);
    }

    static void firstElementChildAttributeGetterForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentFragment* impl = V8DocumentFragment::toImpl(holder);

        v8SetReturnValueForMainWorld(info, ParentNode::firstElementChild(*impl));
    }

    CORE_EXPORT void firstElementChildAttributeGetterCallbackForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::firstElementChildAttributeGetterForMainWorld(info);
    }

    static void lastElementChildAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentFragment* impl = V8DocumentFragment::toImpl(holder);

        v8SetReturnValueFast(info, ParentNode::lastElementChild(*impl), impl);
    }

    CORE_EXPORT void lastElementChildAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::lastElementChildAttributeGetter(info);
    }

    static void lastElementChildAttributeGetterForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentFragment* impl = V8DocumentFragment::toImpl(holder);

        v8SetReturnValueForMainWorld(info, ParentNode::lastElementChild(*impl));
    }

    CORE_EXPORT void lastElementChildAttributeGetterCallbackForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::lastElementChildAttributeGetterForMainWorld(info);
    }

    static void childElementCountAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        DocumentFragment* impl = V8DocumentFragment::toImpl(holder);

        v8SetReturnValueUnsigned(info, ParentNode::childElementCount(*impl));
    }

    CORE_EXPORT void childElementCountAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::childElementCountAttributeGetter(info);
    }

    static void getElementByIdMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragment* impl = V8DocumentFragment::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getElementById", "DocumentFragment", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        V8StringResource<> elementId;
        elementId = info[0];
        if (!elementId.prepare())
            return;

        v8SetReturnValueFast(info, NonElementParentNode::getElementById(*impl, elementId), impl);
    }

    CORE_EXPORT void getElementByIdMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::getElementByIdMethod(info);
    }

    static void getElementByIdMethodForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragment* impl = V8DocumentFragment::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getElementById", "DocumentFragment", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        V8StringResource<> elementId;
        elementId = info[0];
        if (!elementId.prepare())
            return;

        v8SetReturnValueForMainWorld(info, NonElementParentNode::getElementById(*impl, elementId));
    }

    CORE_EXPORT void getElementByIdMethodCallbackForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::getElementByIdMethodForMainWorld(info);
    }

    static void prependMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentFragment", "prepend");

        DocumentFragment* impl = V8DocumentFragment::toImpl(info.Holder());

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HeapVector<NodeOrString> nodes;
        nodes = toImplArguments<HeapVector<NodeOrString>>(info, 0, exceptionState);
        if (exceptionState.hadException())
            return;

        ParentNode::prepend(*impl, nodes, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void prependMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        DocumentFragmentV8Internal::prependMethod(info);
    }

    static void appendMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentFragment", "append");

        DocumentFragment* impl = V8DocumentFragment::toImpl(info.Holder());

        V0CustomElementProcessingStack::CallbackDeliveryScope deliveryScope;

        HeapVector<NodeOrString> nodes;
        nodes = toImplArguments<HeapVector<NodeOrString>>(info, 0, exceptionState);
        if (exceptionState.hadException())
            return;

        ParentNode::append(*impl, nodes, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void appendMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CEReactionsScope ceReactionsScope;
        DocumentFragmentV8Internal::appendMethod(info);
    }

    static void querySelectorMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentFragment", "querySelector");

        DocumentFragment* impl = V8DocumentFragment::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> selectors;
        selectors = info[0];
        if (!selectors.prepare())
            return;

        Element* result = ParentNode::querySelector(*impl, selectors, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValueFast(info, result, impl);
    }

    CORE_EXPORT void querySelectorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::querySelectorMethod(info);
    }

    static void querySelectorAllMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "DocumentFragment", "querySelectorAll");

        DocumentFragment* impl = V8DocumentFragment::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> selectors;
        selectors = info[0];
        if (!selectors.prepare())
            return;

        NodeList* result = ParentNode::querySelectorAll(*impl, selectors, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        // [NewObject] must always create a new wrapper.  Check that a wrapper
        // does not exist yet.
        DCHECK(!result || DOMDataStore::getWrapper(result, info.GetIsolate()).IsEmpty());
        v8SetReturnValueFast(info, result, impl);
    }

    CORE_EXPORT void querySelectorAllMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DocumentFragmentV8Internal::querySelectorAllMethod(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Document& document = *toDocument(currentExecutionContext(info.GetIsolate()));
        DocumentFragment* impl = DocumentFragment::create(document);
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8DocumentFragment::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace DocumentFragmentV8Internal

const V8DOMConfiguration::AccessorConfiguration V8DocumentFragmentAccessors[] = {
    { "children", DocumentFragmentV8Internal::childrenAttributeGetterCallback, 0, DocumentFragmentV8Internal::childrenAttributeGetterCallbackForMainWorld, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "firstElementChild", DocumentFragmentV8Internal::firstElementChildAttributeGetterCallback, 0, DocumentFragmentV8Internal::firstElementChildAttributeGetterCallbackForMainWorld, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "lastElementChild", DocumentFragmentV8Internal::lastElementChildAttributeGetterCallback, 0, DocumentFragmentV8Internal::lastElementChildAttributeGetterCallbackForMainWorld, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "childElementCount", DocumentFragmentV8Internal::childElementCountAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8DocumentFragmentMethods[] = {
    { "getElementById", DocumentFragmentV8Internal::getElementByIdMethodCallback, DocumentFragmentV8Internal::getElementByIdMethodCallbackForMainWorld, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "querySelector", DocumentFragmentV8Internal::querySelectorMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "querySelectorAll", DocumentFragmentV8Internal::querySelectorAllMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8DocumentFragment::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("DocumentFragment"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    DocumentFragmentV8Internal::constructor(info);
}

static void installV8DocumentFragmentTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8DocumentFragment::wrapperTypeInfo.interfaceName, V8Node::domTemplate(isolate, world), V8DocumentFragment::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8DocumentFragment::constructorCallback);
    interfaceTemplate->SetLength(0);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DocumentFragmentAccessors, WTF_ARRAY_LENGTH(V8DocumentFragmentAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DocumentFragmentMethods, WTF_ARRAY_LENGTH(V8DocumentFragmentMethods));

    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        const V8DOMConfiguration::MethodConfiguration prependMethodConfiguration = { "prepend", DocumentFragmentV8Internal::prependMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, prependMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        const V8DOMConfiguration::MethodConfiguration appendMethodConfiguration = { "append", DocumentFragmentV8Internal::appendMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, appendMethodConfiguration);
    }
}

v8::Local<v8::FunctionTemplate> V8DocumentFragment::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8DocumentFragmentTemplate);
}

bool V8DocumentFragment::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8DocumentFragment::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

DocumentFragment* V8DocumentFragment::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

void V8DocumentFragment::preparePrototypeAndInterfaceObject(v8::Local<v8::Context> context, const DOMWrapperWorld& world, v8::Local<v8::Object> prototypeObject, v8::Local<v8::Function> interfaceObject, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    v8::Isolate* isolate = context->GetIsolate();
    v8::Local<v8::Name> unscopablesSymbol(v8::Symbol::GetUnscopables(isolate));
    v8::Local<v8::Object> unscopables;
    if (v8CallBoolean(prototypeObject->HasOwnProperty(context, unscopablesSymbol)))
        unscopables = prototypeObject->Get(context, unscopablesSymbol).ToLocalChecked().As<v8::Object>();
    else
        unscopables = v8::Object::New(isolate);
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        unscopables->CreateDataProperty(context, v8AtomicString(isolate, "append"), v8::True(isolate)).FromJust();
    }
    if (RuntimeEnabledFeatures::dOMConvenienceAPIEnabled()) {
        unscopables->CreateDataProperty(context, v8AtomicString(isolate, "prepend"), v8::True(isolate)).FromJust();
    }
    prototypeObject->CreateDataProperty(context, unscopablesSymbol, unscopables).FromJust();
}

} // namespace blink

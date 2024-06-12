// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8SVGFEColorMatrixElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGAnimatedEnumeration.h"
#include "bindings/core/v8/V8SVGAnimatedLength.h"
#include "bindings/core/v8/V8SVGAnimatedNumberList.h"
#include "bindings/core/v8/V8SVGAnimatedString.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/frame/UseCounter.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8SVGFEColorMatrixElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGFEColorMatrixElement::domTemplate, V8SVGFEColorMatrixElement::trace, V8SVGFEColorMatrixElement::traceWrappers, 0, nullptr, "SVGFEColorMatrixElement", &V8SVGElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGFEColorMatrixElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGFEColorMatrixElement::s_wrapperTypeInfo = V8SVGFEColorMatrixElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGFEColorMatrixElement>::value,
    "SVGFEColorMatrixElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGFEColorMatrixElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGFEColorMatrixElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGFEColorMatrixElementV8Internal {

    CORE_EXPORT void SVG_FECOLORMATRIX_TYPE_UNKNOWNConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);
        v8SetReturnValueInt(info, 0);
    }

    CORE_EXPORT void SVG_FECOLORMATRIX_TYPE_MATRIXConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);
        v8SetReturnValueInt(info, 1);
    }

    CORE_EXPORT void SVG_FECOLORMATRIX_TYPE_SATURATEConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);
        v8SetReturnValueInt(info, 2);
    }

    CORE_EXPORT void SVG_FECOLORMATRIX_TYPE_HUEROTATEConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);
        v8SetReturnValueInt(info, 3);
    }

    CORE_EXPORT void SVG_FECOLORMATRIX_TYPE_LUMINANCETOALPHAConstantGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);
        v8SetReturnValueInt(info, 4);
    }

    static void in1AttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->in1()), impl);
    }

    CORE_EXPORT void in1AttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::in1AttributeGetter(info);
    }

    static void typeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->type()), impl);
    }

    CORE_EXPORT void typeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::typeAttributeGetter(info);
    }

    static void valuesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->values()), impl);
    }

    CORE_EXPORT void valuesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::valuesAttributeGetter(info);
    }

    static void xAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->x()), impl);
    }

    CORE_EXPORT void xAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::xAttributeGetter(info);
    }

    static void yAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->y()), impl);
    }

    CORE_EXPORT void yAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::yAttributeGetter(info);
    }

    static void widthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->width()), impl);
    }

    CORE_EXPORT void widthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::widthAttributeGetter(info);
    }

    static void heightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->height()), impl);
    }

    CORE_EXPORT void heightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::heightAttributeGetter(info);
    }

    static void resultAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGFEColorMatrixElement* impl = V8SVGFEColorMatrixElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->result()), impl);
    }

    CORE_EXPORT void resultAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFilter);

        SVGFEColorMatrixElementV8Internal::resultAttributeGetter(info);
    }

} // namespace SVGFEColorMatrixElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SVGFEColorMatrixElementAccessors[] = {
    { "in1", SVGFEColorMatrixElementV8Internal::in1AttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "type", SVGFEColorMatrixElementV8Internal::typeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "values", SVGFEColorMatrixElementV8Internal::valuesAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "x", SVGFEColorMatrixElementV8Internal::xAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "y", SVGFEColorMatrixElementV8Internal::yAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "width", SVGFEColorMatrixElementV8Internal::widthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "height", SVGFEColorMatrixElementV8Internal::heightAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "result", SVGFEColorMatrixElementV8Internal::resultAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8SVGFEColorMatrixElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGFEColorMatrixElement::wrapperTypeInfo.interfaceName, V8SVGElement::domTemplate(isolate, world), V8SVGFEColorMatrixElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "SVG_FECOLORMATRIX_TYPE_UNKNOWN", SVGFEColorMatrixElementV8Internal::SVG_FECOLORMATRIX_TYPE_UNKNOWNConstantGetterCallback);
    V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "SVG_FECOLORMATRIX_TYPE_MATRIX", SVGFEColorMatrixElementV8Internal::SVG_FECOLORMATRIX_TYPE_MATRIXConstantGetterCallback);
    V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "SVG_FECOLORMATRIX_TYPE_SATURATE", SVGFEColorMatrixElementV8Internal::SVG_FECOLORMATRIX_TYPE_SATURATEConstantGetterCallback);
    V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "SVG_FECOLORMATRIX_TYPE_HUEROTATE", SVGFEColorMatrixElementV8Internal::SVG_FECOLORMATRIX_TYPE_HUEROTATEConstantGetterCallback);
    V8DOMConfiguration::installConstantWithGetter(isolate, interfaceTemplate, prototypeTemplate, "SVG_FECOLORMATRIX_TYPE_LUMINANCETOALPHA", SVGFEColorMatrixElementV8Internal::SVG_FECOLORMATRIX_TYPE_LUMINANCETOALPHAConstantGetterCallback);
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGFEColorMatrixElementAccessors, WTF_ARRAY_LENGTH(V8SVGFEColorMatrixElementAccessors));
}

v8::Local<v8::FunctionTemplate> V8SVGFEColorMatrixElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGFEColorMatrixElementTemplate);
}

bool V8SVGFEColorMatrixElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGFEColorMatrixElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGFEColorMatrixElement* V8SVGFEColorMatrixElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

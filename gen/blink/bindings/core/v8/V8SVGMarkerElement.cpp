// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8SVGMarkerElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGAngle.h"
#include "bindings/core/v8/V8SVGAnimatedAngle.h"
#include "bindings/core/v8/V8SVGAnimatedEnumeration.h"
#include "bindings/core/v8/V8SVGAnimatedLength.h"
#include "bindings/core/v8/V8SVGAnimatedPreserveAspectRatio.h"
#include "bindings/core/v8/V8SVGAnimatedRect.h"
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
const WrapperTypeInfo V8SVGMarkerElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGMarkerElement::domTemplate, V8SVGMarkerElement::trace, V8SVGMarkerElement::traceWrappers, 0, nullptr, "SVGMarkerElement", &V8SVGElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGMarkerElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGMarkerElement::s_wrapperTypeInfo = V8SVGMarkerElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGMarkerElement>::value,
    "SVGMarkerElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGMarkerElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGMarkerElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGMarkerElementV8Internal {

    static void refXAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->refX()), impl);
    }

    CORE_EXPORT void refXAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);

        SVGMarkerElementV8Internal::refXAttributeGetter(info);
    }

    static void refYAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->refY()), impl);
    }

    CORE_EXPORT void refYAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);

        SVGMarkerElementV8Internal::refYAttributeGetter(info);
    }

    static void markerUnitsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->markerUnits()), impl);
    }

    CORE_EXPORT void markerUnitsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);

        SVGMarkerElementV8Internal::markerUnitsAttributeGetter(info);
    }

    static void markerWidthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->markerWidth()), impl);
    }

    CORE_EXPORT void markerWidthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);

        SVGMarkerElementV8Internal::markerWidthAttributeGetter(info);
    }

    static void markerHeightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->markerHeight()), impl);
    }

    CORE_EXPORT void markerHeightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);

        SVGMarkerElementV8Internal::markerHeightAttributeGetter(info);
    }

    static void orientTypeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->orientType()), impl);
    }

    CORE_EXPORT void orientTypeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);

        SVGMarkerElementV8Internal::orientTypeAttributeGetter(info);
    }

    static void orientAngleAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->orientAngle()), impl);
    }

    CORE_EXPORT void orientAngleAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);

        SVGMarkerElementV8Internal::orientAngleAttributeGetter(info);
    }

    static void viewBoxAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->viewBox()), impl);
    }

    CORE_EXPORT void viewBoxAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFitToViewBox);

        SVGMarkerElementV8Internal::viewBoxAttributeGetter(info);
    }

    static void preserveAspectRatioAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->preserveAspectRatio()), impl);
    }

    CORE_EXPORT void preserveAspectRatioAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFitToViewBox);

        SVGMarkerElementV8Internal::preserveAspectRatioAttributeGetter(info);
    }

    static void setOrientToAutoMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(info.Holder());

        impl->setOrientToAuto();
    }

    CORE_EXPORT void setOrientToAutoMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);
        SVGMarkerElementV8Internal::setOrientToAutoMethod(info);
    }

    static void setOrientToAngleMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGMarkerElement* impl = V8SVGMarkerElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setOrientToAngle", "SVGMarkerElement", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        SVGAngleTearOff* angle;
        angle = V8SVGAngle::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!angle) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setOrientToAngle", "SVGMarkerElement", "parameter 1 is not of type 'SVGAngle'."));

            return;
        }

        impl->setOrientToAngle(angle);
    }

    CORE_EXPORT void setOrientToAngleMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMMarkerElement);
        SVGMarkerElementV8Internal::setOrientToAngleMethod(info);
    }

} // namespace SVGMarkerElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SVGMarkerElementAccessors[] = {
    { "refX", SVGMarkerElementV8Internal::refXAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "refY", SVGMarkerElementV8Internal::refYAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "markerUnits", SVGMarkerElementV8Internal::markerUnitsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "markerWidth", SVGMarkerElementV8Internal::markerWidthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "markerHeight", SVGMarkerElementV8Internal::markerHeightAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "orientType", SVGMarkerElementV8Internal::orientTypeAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "orientAngle", SVGMarkerElementV8Internal::orientAngleAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "viewBox", SVGMarkerElementV8Internal::viewBoxAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "preserveAspectRatio", SVGMarkerElementV8Internal::preserveAspectRatioAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8SVGMarkerElementMethods[] = {
    { "setOrientToAuto", SVGMarkerElementV8Internal::setOrientToAutoMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "setOrientToAngle", SVGMarkerElementV8Internal::setOrientToAngleMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8SVGMarkerElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGMarkerElement::wrapperTypeInfo.interfaceName, V8SVGElement::domTemplate(isolate, world), V8SVGMarkerElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    const V8DOMConfiguration::ConstantConfiguration V8SVGMarkerElementConstants[] = {
        { "SVG_MARKERUNITS_UNKNOWN", 0, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "SVG_MARKERUNITS_USERSPACEONUSE", 1, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "SVG_MARKERUNITS_STROKEWIDTH", 2, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "SVG_MARKER_ORIENT_UNKNOWN", 0, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "SVG_MARKER_ORIENT_AUTO", 1, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "SVG_MARKER_ORIENT_ANGLE", 2, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
    };
    V8DOMConfiguration::installConstants(isolate, interfaceTemplate, prototypeTemplate, V8SVGMarkerElementConstants, WTF_ARRAY_LENGTH(V8SVGMarkerElementConstants));
    static_assert(0 == SVGMarkerElement::kSvgMarkerunitsUnknown, "the value of SVGMarkerElement_kSvgMarkerunitsUnknown does not match with implementation");
    static_assert(1 == SVGMarkerElement::kSvgMarkerunitsUserspaceonuse, "the value of SVGMarkerElement_kSvgMarkerunitsUserspaceonuse does not match with implementation");
    static_assert(2 == SVGMarkerElement::kSvgMarkerunitsStrokewidth, "the value of SVGMarkerElement_kSvgMarkerunitsStrokewidth does not match with implementation");
    static_assert(0 == SVGMarkerElement::kSvgMarkerOrientUnknown, "the value of SVGMarkerElement_kSvgMarkerOrientUnknown does not match with implementation");
    static_assert(1 == SVGMarkerElement::kSvgMarkerOrientAuto, "the value of SVGMarkerElement_kSvgMarkerOrientAuto does not match with implementation");
    static_assert(2 == SVGMarkerElement::kSvgMarkerOrientAngle, "the value of SVGMarkerElement_kSvgMarkerOrientAngle does not match with implementation");
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGMarkerElementAccessors, WTF_ARRAY_LENGTH(V8SVGMarkerElementAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGMarkerElementMethods, WTF_ARRAY_LENGTH(V8SVGMarkerElementMethods));
}

v8::Local<v8::FunctionTemplate> V8SVGMarkerElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGMarkerElementTemplate);
}

bool V8SVGMarkerElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGMarkerElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGMarkerElement* V8SVGMarkerElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

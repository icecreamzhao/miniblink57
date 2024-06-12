// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8SVGSVGElement.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Element.h"
#include "bindings/core/v8/V8NodeList.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SVGAngle.h"
#include "bindings/core/v8/V8SVGAnimatedLength.h"
#include "bindings/core/v8/V8SVGAnimatedPreserveAspectRatio.h"
#include "bindings/core/v8/V8SVGAnimatedRect.h"
#include "bindings/core/v8/V8SVGElement.h"
#include "bindings/core/v8/V8SVGLength.h"
#include "bindings/core/v8/V8SVGMatrix.h"
#include "bindings/core/v8/V8SVGNumber.h"
#include "bindings/core/v8/V8SVGPoint.h"
#include "bindings/core/v8/V8SVGRect.h"
#include "bindings/core/v8/V8SVGTransform.h"
#include "core/animation/ElementAnimation.h"
#include "core/dom/Document.h"
#include "core/dom/ElementFullscreen.h"
#include "core/dom/NameNodeList.h"
#include "core/dom/NodeList.h"
#include "core/dom/StaticNodeList.h"
#include "core/frame/UseCounter.h"
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
const WrapperTypeInfo V8SVGSVGElement::wrapperTypeInfo = { gin::kEmbedderBlink, V8SVGSVGElement::domTemplate, V8SVGSVGElement::trace, V8SVGSVGElement::traceWrappers, 0, nullptr, "SVGSVGElement", &V8SVGGraphicsElement::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::NodeClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in SVGSVGElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& SVGSVGElement::s_wrapperTypeInfo = V8SVGSVGElement::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, SVGSVGElement>::value,
    "SVGSVGElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&SVGSVGElement::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "SVGSVGElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace SVGSVGElementV8Internal {

    static void xAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->x()), impl);
    }

    CORE_EXPORT void xAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMSVGElement);

        SVGSVGElementV8Internal::xAttributeGetter(info);
    }

    static void yAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->y()), impl);
    }

    CORE_EXPORT void yAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMSVGElement);

        SVGSVGElementV8Internal::yAttributeGetter(info);
    }

    static void widthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->width()), impl);
    }

    CORE_EXPORT void widthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMSVGElement);

        SVGSVGElementV8Internal::widthAttributeGetter(info);
    }

    static void heightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->height()), impl);
    }

    CORE_EXPORT void heightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMSVGElement);

        SVGSVGElementV8Internal::heightAttributeGetter(info);
    }

    static void currentScaleAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValue(info, impl->currentScale());
    }

    CORE_EXPORT void currentScaleAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElementV8Internal::currentScaleAttributeGetter(info);
    }

    static void currentScaleAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "SVGSVGElement", "currentScale");

        // Prepare the value to be set.
        float cppValue = toRestrictedFloat(info.GetIsolate(), v8Value, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setCurrentScale(cppValue);
    }

    CORE_EXPORT void currentScaleAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        SVGSVGElementV8Internal::currentScaleAttributeSetter(v8Value, info);
    }

    static void currentTranslateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->currentTranslateFromJavascript()), impl);
    }

    CORE_EXPORT void currentTranslateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElementV8Internal::currentTranslateAttributeGetter(info);
    }

    static void viewBoxAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->viewBox()), impl);
    }

    CORE_EXPORT void viewBoxAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFitToViewBox);

        SVGSVGElementV8Internal::viewBoxAttributeGetter(info);
    }

    static void preserveAspectRatioAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueFast(info, WTF::getPtr(impl->preserveAspectRatio()), impl);
    }

    CORE_EXPORT void preserveAspectRatioAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMFitToViewBox);

        SVGSVGElementV8Internal::preserveAspectRatioAttributeGetter(info);
    }

    static void zoomAndPanAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        v8SetReturnValueUnsigned(info, impl->zoomAndPan());
    }

    CORE_EXPORT void zoomAndPanAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMZoomAndPan);

        SVGSVGElementV8Internal::zoomAndPanAttributeGetter(info);
    }

    static void zoomAndPanAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "SVGSVGElement", "zoomAndPan");

        // Prepare the value to be set.
        unsigned cppValue = toUInt16(info.GetIsolate(), v8Value, NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setZoomAndPan(cppValue, exceptionState);
    }

    CORE_EXPORT void zoomAndPanAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVG1DOMZoomAndPan);

        SVGSVGElementV8Internal::zoomAndPanAttributeSetter(v8Value, info);
    }

    static void getIntersectionListMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getIntersectionList", "SVGSVGElement", ExceptionMessages::notEnoughArguments(2, info.Length())));
            return;
        }

        SVGRectTearOff* rect;
        SVGElement* referenceElement;
        rect = V8SVGRect::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!rect) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getIntersectionList", "SVGSVGElement", "parameter 1 is not of type 'SVGRect'."));

            return;
        }

        referenceElement = V8SVGElement::toImplWithTypeCheck(info.GetIsolate(), info[1]);
        if (!referenceElement && !isUndefinedOrNull(info[1])) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getIntersectionList", "SVGSVGElement", "parameter 2 is not of type 'SVGElement'."));

            return;
        }

        v8SetReturnValueFast(info, impl->getIntersectionList(rect, referenceElement), impl);
    }

    CORE_EXPORT void getIntersectionListMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElementV8Internal::getIntersectionListMethod(info);
    }

    static void getEnclosureListMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getEnclosureList", "SVGSVGElement", ExceptionMessages::notEnoughArguments(2, info.Length())));
            return;
        }

        SVGRectTearOff* rect;
        SVGElement* referenceElement;
        rect = V8SVGRect::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!rect) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getEnclosureList", "SVGSVGElement", "parameter 1 is not of type 'SVGRect'."));

            return;
        }

        referenceElement = V8SVGElement::toImplWithTypeCheck(info.GetIsolate(), info[1]);
        if (!referenceElement && !isUndefinedOrNull(info[1])) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getEnclosureList", "SVGSVGElement", "parameter 2 is not of type 'SVGElement'."));

            return;
        }

        v8SetReturnValueFast(info, impl->getEnclosureList(rect, referenceElement), impl);
    }

    CORE_EXPORT void getEnclosureListMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElementV8Internal::getEnclosureListMethod(info);
    }

    static void checkIntersectionMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("checkIntersection", "SVGSVGElement", ExceptionMessages::notEnoughArguments(2, info.Length())));
            return;
        }

        SVGElement* element;
        SVGRectTearOff* rect;
        element = V8SVGElement::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!element) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("checkIntersection", "SVGSVGElement", "parameter 1 is not of type 'SVGElement'."));

            return;
        }

        rect = V8SVGRect::toImplWithTypeCheck(info.GetIsolate(), info[1]);
        if (!rect) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("checkIntersection", "SVGSVGElement", "parameter 2 is not of type 'SVGRect'."));

            return;
        }

        v8SetReturnValueBool(info, impl->checkIntersection(element, rect));
    }

    CORE_EXPORT void checkIntersectionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElementV8Internal::checkIntersectionMethod(info);
    }

    static void checkEnclosureMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("checkEnclosure", "SVGSVGElement", ExceptionMessages::notEnoughArguments(2, info.Length())));
            return;
        }

        SVGElement* element;
        SVGRectTearOff* rect;
        element = V8SVGElement::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!element) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("checkEnclosure", "SVGSVGElement", "parameter 1 is not of type 'SVGElement'."));

            return;
        }

        rect = V8SVGRect::toImplWithTypeCheck(info.GetIsolate(), info[1]);
        if (!rect) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("checkEnclosure", "SVGSVGElement", "parameter 2 is not of type 'SVGRect'."));

            return;
        }

        v8SetReturnValueBool(info, impl->checkEnclosure(element, rect));
    }

    CORE_EXPORT void checkEnclosureMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElementV8Internal::checkEnclosureMethod(info);
    }

    static void deselectAllMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        impl->deselectAll();
    }

    CORE_EXPORT void deselectAllMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElementV8Internal::deselectAllMethod(info);
    }

    static void createSVGNumberMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueFast(info, impl->createSVGNumber(), impl);
    }

    CORE_EXPORT void createSVGNumberMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGNumber_Method);
        SVGSVGElementV8Internal::createSVGNumberMethod(info);
    }

    static void createSVGLengthMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueFast(info, impl->createSVGLength(), impl);
    }

    CORE_EXPORT void createSVGLengthMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGLength_Method);
        SVGSVGElementV8Internal::createSVGLengthMethod(info);
    }

    static void createSVGAngleMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueFast(info, impl->createSVGAngle(), impl);
    }

    CORE_EXPORT void createSVGAngleMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGAngle_Method);
        SVGSVGElementV8Internal::createSVGAngleMethod(info);
    }

    static void createSVGPointMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueFast(info, impl->createSVGPoint(), impl);
    }

    CORE_EXPORT void createSVGPointMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGPoint_Method);
        SVGSVGElementV8Internal::createSVGPointMethod(info);
    }

    static void createSVGMatrixMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueFast(info, impl->createSVGMatrix(), impl);
    }

    CORE_EXPORT void createSVGMatrixMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGMatrix_Method);
        SVGSVGElementV8Internal::createSVGMatrixMethod(info);
    }

    static void createSVGRectMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueFast(info, impl->createSVGRect(), impl);
    }

    CORE_EXPORT void createSVGRectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGRect_Method);
        SVGSVGElementV8Internal::createSVGRectMethod(info);
    }

    static void createSVGTransformMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueFast(info, impl->createSVGTransform(), impl);
    }

    CORE_EXPORT void createSVGTransformMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGTransform_Method);
        SVGSVGElementV8Internal::createSVGTransformMethod(info);
    }

    static void createSVGTransformFromMatrixMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createSVGTransformFromMatrix", "SVGSVGElement", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        SVGMatrixTearOff* matrix;
        matrix = V8SVGMatrix::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!matrix) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createSVGTransformFromMatrix", "SVGSVGElement", "parameter 1 is not of type 'SVGMatrix'."));

            return;
        }

        v8SetReturnValueFast(info, impl->createSVGTransformFromMatrix(matrix), impl);
    }

    CORE_EXPORT void createSVGTransformFromMatrixMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_CreateSVGTransformFromMatrix_Method);
        SVGSVGElementV8Internal::createSVGTransformFromMatrixMethod(info);
    }

    static void getElementByIdMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getElementById", "SVGSVGElement", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        V8StringResource<> elementId;
        elementId = info[0];
        if (!elementId.prepare())
            return;

        v8SetReturnValueFast(info, impl->getElementById(elementId), impl);
    }

    CORE_EXPORT void getElementByIdMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8SVGSVGElement_GetElementById_Method);
        SVGSVGElementV8Internal::getElementByIdMethod(info);
    }

    static void suspendRedrawMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGSVGElement", "suspendRedraw");

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        unsigned maxWaitMilliseconds;
        maxWaitMilliseconds = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        v8SetReturnValueUnsigned(info, impl->suspendRedraw(maxWaitMilliseconds));
    }

    CORE_EXPORT void suspendRedrawMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSVGElementSuspendRedraw);
        SVGSVGElementV8Internal::suspendRedrawMethod(info);
    }

    static void unsuspendRedrawMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGSVGElement", "unsuspendRedraw");

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        unsigned suspendHandleId;
        suspendHandleId = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->unsuspendRedraw(suspendHandleId);
    }

    CORE_EXPORT void unsuspendRedrawMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSVGElementUnsuspendRedraw);
        SVGSVGElementV8Internal::unsuspendRedrawMethod(info);
    }

    static void unsuspendRedrawAllMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        impl->unsuspendRedrawAll();
    }

    CORE_EXPORT void unsuspendRedrawAllMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSVGElementUnsuspendRedrawAll);
        SVGSVGElementV8Internal::unsuspendRedrawAllMethod(info);
    }

    static void forceRedrawMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        impl->forceRedraw();
    }

    CORE_EXPORT void forceRedrawMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSVGElementForceRedraw);
        SVGSVGElementV8Internal::forceRedrawMethod(info);
    }

    static void pauseAnimationsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        impl->pauseAnimations();
    }

    CORE_EXPORT void pauseAnimationsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILPausing);
        SVGSVGElementV8Internal::pauseAnimationsMethod(info);
    }

    static void unpauseAnimationsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        impl->unpauseAnimations();
    }

    CORE_EXPORT void unpauseAnimationsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILPausing);
        SVGSVGElementV8Internal::unpauseAnimationsMethod(info);
    }

    static void animationsPausedMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValueBool(info, impl->animationsPaused());
    }

    CORE_EXPORT void animationsPausedMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILPausing);
        SVGSVGElementV8Internal::animationsPausedMethod(info);
    }

    static void getCurrentTimeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        v8SetReturnValue(info, impl->getCurrentTime());
    }

    CORE_EXPORT void getCurrentTimeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILCurrentTime);
        SVGSVGElementV8Internal::getCurrentTimeMethod(info);
    }

    static void setCurrentTimeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "SVGSVGElement", "setCurrentTime");

        SVGSVGElement* impl = V8SVGSVGElement::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        float seconds;
        seconds = toRestrictedFloat(info.GetIsolate(), info[0], exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setCurrentTime(seconds);
    }

    CORE_EXPORT void setCurrentTimeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::SVGSMILCurrentTime);
        SVGSVGElementV8Internal::setCurrentTimeMethod(info);
    }

} // namespace SVGSVGElementV8Internal

const V8DOMConfiguration::AccessorConfiguration V8SVGSVGElementAccessors[] = {
    { "x", SVGSVGElementV8Internal::xAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "y", SVGSVGElementV8Internal::yAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "width", SVGSVGElementV8Internal::widthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "height", SVGSVGElementV8Internal::heightAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "currentScale", SVGSVGElementV8Internal::currentScaleAttributeGetterCallback, SVGSVGElementV8Internal::currentScaleAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "currentTranslate", SVGSVGElementV8Internal::currentTranslateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "viewBox", SVGSVGElementV8Internal::viewBoxAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "preserveAspectRatio", SVGSVGElementV8Internal::preserveAspectRatioAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "zoomAndPan", SVGSVGElementV8Internal::zoomAndPanAttributeGetterCallback, SVGSVGElementV8Internal::zoomAndPanAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8SVGSVGElementMethods[] = {
    { "getIntersectionList", SVGSVGElementV8Internal::getIntersectionListMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getEnclosureList", SVGSVGElementV8Internal::getEnclosureListMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "checkIntersection", SVGSVGElementV8Internal::checkIntersectionMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "checkEnclosure", SVGSVGElementV8Internal::checkEnclosureMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "deselectAll", SVGSVGElementV8Internal::deselectAllMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGNumber", SVGSVGElementV8Internal::createSVGNumberMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGLength", SVGSVGElementV8Internal::createSVGLengthMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGAngle", SVGSVGElementV8Internal::createSVGAngleMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGPoint", SVGSVGElementV8Internal::createSVGPointMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGMatrix", SVGSVGElementV8Internal::createSVGMatrixMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGRect", SVGSVGElementV8Internal::createSVGRectMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGTransform", SVGSVGElementV8Internal::createSVGTransformMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createSVGTransformFromMatrix", SVGSVGElementV8Internal::createSVGTransformFromMatrixMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getElementById", SVGSVGElementV8Internal::getElementByIdMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "suspendRedraw", SVGSVGElementV8Internal::suspendRedrawMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "unsuspendRedraw", SVGSVGElementV8Internal::unsuspendRedrawMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "unsuspendRedrawAll", SVGSVGElementV8Internal::unsuspendRedrawAllMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "forceRedraw", SVGSVGElementV8Internal::forceRedrawMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8SVGSVGElementTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8SVGSVGElement::wrapperTypeInfo.interfaceName, V8SVGGraphicsElement::domTemplate(isolate, world), V8SVGSVGElement::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    const V8DOMConfiguration::ConstantConfiguration V8SVGSVGElementConstants[] = {
        { "SVG_ZOOMANDPAN_UNKNOWN", 0, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "SVG_ZOOMANDPAN_DISABLE", 1, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
        { "SVG_ZOOMANDPAN_MAGNIFY", 2, 0, V8DOMConfiguration::ConstantTypeUnsignedShort },
    };
    V8DOMConfiguration::installConstants(isolate, interfaceTemplate, prototypeTemplate, V8SVGSVGElementConstants, WTF_ARRAY_LENGTH(V8SVGSVGElementConstants));
    static_assert(0 == SVGSVGElement::kSvgZoomandpanUnknown, "the value of SVGSVGElement_kSvgZoomandpanUnknown does not match with implementation");
    static_assert(1 == SVGSVGElement::kSvgZoomandpanDisable, "the value of SVGSVGElement_kSvgZoomandpanDisable does not match with implementation");
    static_assert(2 == SVGSVGElement::kSvgZoomandpanMagnify, "the value of SVGSVGElement_kSvgZoomandpanMagnify does not match with implementation");
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGSVGElementAccessors, WTF_ARRAY_LENGTH(V8SVGSVGElementAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8SVGSVGElementMethods, WTF_ARRAY_LENGTH(V8SVGSVGElementMethods));

    if (RuntimeEnabledFeatures::smilEnabled()) {
        const V8DOMConfiguration::MethodConfiguration pauseAnimationsMethodConfiguration = { "pauseAnimations", SVGSVGElementV8Internal::pauseAnimationsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, pauseAnimationsMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::smilEnabled()) {
        const V8DOMConfiguration::MethodConfiguration unpauseAnimationsMethodConfiguration = { "unpauseAnimations", SVGSVGElementV8Internal::unpauseAnimationsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, unpauseAnimationsMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::smilEnabled()) {
        const V8DOMConfiguration::MethodConfiguration animationsPausedMethodConfiguration = { "animationsPaused", SVGSVGElementV8Internal::animationsPausedMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, animationsPausedMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::smilEnabled()) {
        const V8DOMConfiguration::MethodConfiguration getCurrentTimeMethodConfiguration = { "getCurrentTime", SVGSVGElementV8Internal::getCurrentTimeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, getCurrentTimeMethodConfiguration);
    }
    if (RuntimeEnabledFeatures::smilEnabled()) {
        const V8DOMConfiguration::MethodConfiguration setCurrentTimeMethodConfiguration = { "setCurrentTime", SVGSVGElementV8Internal::setCurrentTimeMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder };
        V8DOMConfiguration::installMethod(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, setCurrentTimeMethodConfiguration);
    }
}

v8::Local<v8::FunctionTemplate> V8SVGSVGElement::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8SVGSVGElementTemplate);
}

bool V8SVGSVGElement::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8SVGSVGElement::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

SVGSVGElement* V8SVGSVGElement::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink

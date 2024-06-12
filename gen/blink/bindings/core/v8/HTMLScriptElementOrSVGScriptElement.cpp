// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format on
#include "HTMLScriptElementOrSVGScriptElement.h"

#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8HTMLScriptElement.h"
#include "bindings/core/v8/V8SVGScriptElement.h"

namespace blink {

HTMLScriptElementOrSVGScriptElement::HTMLScriptElementOrSVGScriptElement()
    : m_type(SpecificTypeNone)
{
}

HTMLScriptElement* HTMLScriptElementOrSVGScriptElement::getAsHTMLScriptElement() const
{
    DCHECK(isHTMLScriptElement());
    return m_htmlScriptElement;
}

void HTMLScriptElementOrSVGScriptElement::setHTMLScriptElement(HTMLScriptElement* value)
{
    DCHECK(isNull());
    m_htmlScriptElement = value;
    m_type = SpecificTypeHTMLScriptElement;
}

HTMLScriptElementOrSVGScriptElement HTMLScriptElementOrSVGScriptElement::fromHTMLScriptElement(HTMLScriptElement* value)
{
    HTMLScriptElementOrSVGScriptElement container;
    container.setHTMLScriptElement(value);
    return container;
}

SVGScriptElement* HTMLScriptElementOrSVGScriptElement::getAsSVGScriptElement() const
{
    DCHECK(isSVGScriptElement());
    return m_svgScriptElement;
}

void HTMLScriptElementOrSVGScriptElement::setSVGScriptElement(SVGScriptElement* value)
{
    DCHECK(isNull());
    m_svgScriptElement = value;
    m_type = SpecificTypeSVGScriptElement;
}

HTMLScriptElementOrSVGScriptElement HTMLScriptElementOrSVGScriptElement::fromSVGScriptElement(SVGScriptElement* value)
{
    HTMLScriptElementOrSVGScriptElement container;
    container.setSVGScriptElement(value);
    return container;
}

HTMLScriptElementOrSVGScriptElement::HTMLScriptElementOrSVGScriptElement(const HTMLScriptElementOrSVGScriptElement&) = default;
HTMLScriptElementOrSVGScriptElement::~HTMLScriptElementOrSVGScriptElement() = default;
HTMLScriptElementOrSVGScriptElement& HTMLScriptElementOrSVGScriptElement::operator=(const HTMLScriptElementOrSVGScriptElement&) = default;

DEFINE_TRACE(HTMLScriptElementOrSVGScriptElement)
{
    visitor->trace(m_htmlScriptElement);
    visitor->trace(m_svgScriptElement);
}

void V8HTMLScriptElementOrSVGScriptElement::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, HTMLScriptElementOrSVGScriptElement& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState)
{
    if (v8Value.IsEmpty())
        return;

    if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
        return;

    if (V8HTMLScriptElement::hasInstance(v8Value, isolate)) {
        HTMLScriptElement* cppValue = V8HTMLScriptElement::toImpl(v8::Local<v8::Object>::Cast(v8Value));
        impl.setHTMLScriptElement(cppValue);
        return;
    }

    if (V8SVGScriptElement::hasInstance(v8Value, isolate)) {
        SVGScriptElement* cppValue = V8SVGScriptElement::toImpl(v8::Local<v8::Object>::Cast(v8Value));
        impl.setSVGScriptElement(cppValue);
        return;
    }

    exceptionState.throwTypeError("The provided value is not of type '(HTMLScriptElement or SVGScriptElement)'");
}

v8::Local<v8::Value> ToV8(const HTMLScriptElementOrSVGScriptElement& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    switch (impl.m_type) {
    case HTMLScriptElementOrSVGScriptElement::SpecificTypeNone:
        return v8::Null(isolate);
    case HTMLScriptElementOrSVGScriptElement::SpecificTypeHTMLScriptElement:
        return ToV8(impl.getAsHTMLScriptElement(), creationContext, isolate);
    case HTMLScriptElementOrSVGScriptElement::SpecificTypeSVGScriptElement:
        return ToV8(impl.getAsSVGScriptElement(), creationContext, isolate);
    default:
        NOTREACHED();
    }
    return v8::Local<v8::Value>();
}

HTMLScriptElementOrSVGScriptElement NativeValueTraits<HTMLScriptElementOrSVGScriptElement>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    HTMLScriptElementOrSVGScriptElement impl;
    V8HTMLScriptElementOrSVGScriptElement::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
    return impl;
}

} // namespace blink

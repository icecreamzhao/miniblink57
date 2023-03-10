// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format on
#include "StringOrStringSequenceOrConstrainDOMStringParameters.h"

#include "bindings/core/v8/ToV8.h"
#include "bindings/modules/v8/StringOrStringSequence.h"

namespace blink {

StringOrStringSequenceOrConstrainDOMStringParameters::StringOrStringSequenceOrConstrainDOMStringParameters()
    : m_type(SpecificTypeNone)
{
}

String StringOrStringSequenceOrConstrainDOMStringParameters::getAsString() const
{
    DCHECK(isString());
    return m_string;
}

void StringOrStringSequenceOrConstrainDOMStringParameters::setString(String value)
{
    DCHECK(isNull());
    m_string = value;
    m_type = SpecificTypeString;
}

StringOrStringSequenceOrConstrainDOMStringParameters StringOrStringSequenceOrConstrainDOMStringParameters::fromString(String value)
{
    StringOrStringSequenceOrConstrainDOMStringParameters container;
    container.setString(value);
    return container;
}

const Vector<String>& StringOrStringSequenceOrConstrainDOMStringParameters::getAsStringSequence() const
{
    DCHECK(isStringSequence());
    return m_stringSequence;
}

void StringOrStringSequenceOrConstrainDOMStringParameters::setStringSequence(const Vector<String>& value)
{
    DCHECK(isNull());
    m_stringSequence = value;
    m_type = SpecificTypeStringSequence;
}

StringOrStringSequenceOrConstrainDOMStringParameters StringOrStringSequenceOrConstrainDOMStringParameters::fromStringSequence(const Vector<String>& value)
{
    StringOrStringSequenceOrConstrainDOMStringParameters container;
    container.setStringSequence(value);
    return container;
}

const ConstrainDOMStringParameters& StringOrStringSequenceOrConstrainDOMStringParameters::getAsConstrainDOMStringParameters() const
{
    DCHECK(isConstrainDOMStringParameters());
    return m_constrainDOMStringParameters;
}

void StringOrStringSequenceOrConstrainDOMStringParameters::setConstrainDOMStringParameters(const ConstrainDOMStringParameters& value)
{
    DCHECK(isNull());
    m_constrainDOMStringParameters = value;
    m_type = SpecificTypeConstrainDOMStringParameters;
}

StringOrStringSequenceOrConstrainDOMStringParameters StringOrStringSequenceOrConstrainDOMStringParameters::fromConstrainDOMStringParameters(const ConstrainDOMStringParameters& value)
{
    StringOrStringSequenceOrConstrainDOMStringParameters container;
    container.setConstrainDOMStringParameters(value);
    return container;
}

StringOrStringSequenceOrConstrainDOMStringParameters::StringOrStringSequenceOrConstrainDOMStringParameters(const StringOrStringSequenceOrConstrainDOMStringParameters&) = default;
StringOrStringSequenceOrConstrainDOMStringParameters::~StringOrStringSequenceOrConstrainDOMStringParameters() = default;
StringOrStringSequenceOrConstrainDOMStringParameters& StringOrStringSequenceOrConstrainDOMStringParameters::operator=(const StringOrStringSequenceOrConstrainDOMStringParameters&) = default;

DEFINE_TRACE(StringOrStringSequenceOrConstrainDOMStringParameters)
{
    visitor->trace(m_constrainDOMStringParameters);
}

void V8StringOrStringSequenceOrConstrainDOMStringParameters::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, StringOrStringSequenceOrConstrainDOMStringParameters& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState)
{
    if (v8Value.IsEmpty())
        return;

    if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
        return;

    if (isUndefinedOrNull(v8Value)) {
        ConstrainDOMStringParameters cppValue;
        V8ConstrainDOMStringParameters::toImpl(isolate, v8Value, cppValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setConstrainDOMStringParameters(cppValue);
        return;
    }

    if (v8Value->IsArray()) {
        Vector<String> cppValue = toImplArray<Vector<String>>(v8Value, 0, isolate, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setStringSequence(cppValue);
        return;
    }

    if (v8Value->IsObject()) {
        ConstrainDOMStringParameters cppValue;
        V8ConstrainDOMStringParameters::toImpl(isolate, v8Value, cppValue, exceptionState);
        if (exceptionState.hadException())
            return;
        impl.setConstrainDOMStringParameters(cppValue);
        return;
    }

    {
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare(exceptionState))
            return;
        impl.setString(cppValue);
        return;
    }
}

v8::Local<v8::Value> ToV8(const StringOrStringSequenceOrConstrainDOMStringParameters& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    switch (impl.m_type) {
    case StringOrStringSequenceOrConstrainDOMStringParameters::SpecificTypeNone:
        return v8::Null(isolate);
    case StringOrStringSequenceOrConstrainDOMStringParameters::SpecificTypeString:
        return v8String(isolate, impl.getAsString());
    case StringOrStringSequenceOrConstrainDOMStringParameters::SpecificTypeStringSequence:
        return ToV8(impl.getAsStringSequence(), creationContext, isolate);
    case StringOrStringSequenceOrConstrainDOMStringParameters::SpecificTypeConstrainDOMStringParameters:
        return ToV8(impl.getAsConstrainDOMStringParameters(), creationContext, isolate);
    default:
        NOTREACHED();
    }
    return v8::Local<v8::Value>();
}

StringOrStringSequenceOrConstrainDOMStringParameters NativeValueTraits<StringOrStringSequenceOrConstrainDOMStringParameters>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    StringOrStringSequenceOrConstrainDOMStringParameters impl;
    V8StringOrStringSequenceOrConstrainDOMStringParameters::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
    return impl;
}

} // namespace blink

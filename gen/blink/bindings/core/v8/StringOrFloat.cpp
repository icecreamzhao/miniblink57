// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format off
#include "StringOrFloat.h"

#include "bindings/core/v8/ToV8.h"

namespace blink {

StringOrFloat::StringOrFloat() : m_type(SpecificTypeNone) {}

String StringOrFloat::getAsString() const {
  DCHECK(isString());
  return m_string;
}

void StringOrFloat::setString(String value) {
  DCHECK(isNull());
  m_string = value;
  m_type = SpecificTypeString;
}

StringOrFloat StringOrFloat::fromString(String value) {
  StringOrFloat container;
  container.setString(value);
  return container;
}

float StringOrFloat::getAsFloat() const {
  DCHECK(isFloat());
  return m_float;
}

void StringOrFloat::setFloat(float value) {
  DCHECK(isNull());
  m_float = value;
  m_type = SpecificTypeFloat;
}

StringOrFloat StringOrFloat::fromFloat(float value) {
  StringOrFloat container;
  container.setFloat(value);
  return container;
}

StringOrFloat::StringOrFloat(const StringOrFloat&) = default;
StringOrFloat::~StringOrFloat() = default;
StringOrFloat& StringOrFloat::operator=(const StringOrFloat&) = default;

DEFINE_TRACE(StringOrFloat) {
}

void V8StringOrFloat::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, StringOrFloat& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState) {
  if (v8Value.IsEmpty())
    return;

  if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
    return;

  if (v8Value->IsNumber()) {
    float cppValue = toRestrictedFloat(isolate, v8Value, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setFloat(cppValue);
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

v8::Local<v8::Value> ToV8(const StringOrFloat& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.m_type) {
    case StringOrFloat::SpecificTypeNone:
      return v8::Null(isolate);
    case StringOrFloat::SpecificTypeString:
      return v8String(isolate, impl.getAsString());
    case StringOrFloat::SpecificTypeFloat:
      return v8::Number::New(isolate, impl.getAsFloat());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

StringOrFloat NativeValueTraits<StringOrFloat>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  StringOrFloat impl;
  V8StringOrFloat::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
  return impl;
}

}  // namespace blink

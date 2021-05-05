// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format off
#include "TestEnumOrDouble.h"

#include "bindings/core/v8/ToV8.h"

namespace blink {

TestEnumOrDouble::TestEnumOrDouble() : m_type(SpecificTypeNone) {}

String TestEnumOrDouble::getAsTestEnum() const {
  DCHECK(isTestEnum());
  return m_testEnum;
}

void TestEnumOrDouble::setTestEnum(String value) {
  DCHECK(isNull());
  NonThrowableExceptionState exceptionState;
  const char* validValues[] = {
      "",
      "EnumValue1",
      "EnumValue2",
      "EnumValue3",
  };
  if (!isValidEnum(value, validValues, WTF_ARRAY_LENGTH(validValues), "TestEnum", exceptionState)) {
    NOTREACHED();
    return;
  }
  m_testEnum = value;
  m_type = SpecificTypeTestEnum;
}

TestEnumOrDouble TestEnumOrDouble::fromTestEnum(String value) {
  TestEnumOrDouble container;
  container.setTestEnum(value);
  return container;
}

double TestEnumOrDouble::getAsDouble() const {
  DCHECK(isDouble());
  return m_double;
}

void TestEnumOrDouble::setDouble(double value) {
  DCHECK(isNull());
  m_double = value;
  m_type = SpecificTypeDouble;
}

TestEnumOrDouble TestEnumOrDouble::fromDouble(double value) {
  TestEnumOrDouble container;
  container.setDouble(value);
  return container;
}

TestEnumOrDouble::TestEnumOrDouble(const TestEnumOrDouble&) = default;
TestEnumOrDouble::~TestEnumOrDouble() = default;
TestEnumOrDouble& TestEnumOrDouble::operator=(const TestEnumOrDouble&) = default;

DEFINE_TRACE(TestEnumOrDouble) {
}

void V8TestEnumOrDouble::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, TestEnumOrDouble& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState) {
  if (v8Value.IsEmpty())
    return;

  if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
    return;

  if (v8Value->IsNumber()) {
    double cppValue = toRestrictedDouble(isolate, v8Value, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setDouble(cppValue);
    return;
  }

  {
    V8StringResource<> cppValue = v8Value;
    if (!cppValue.prepare(exceptionState))
      return;
    const char* validValues[] = {
        "",
        "EnumValue1",
        "EnumValue2",
        "EnumValue3",
    };
    if (!isValidEnum(cppValue, validValues, WTF_ARRAY_LENGTH(validValues), "TestEnum", exceptionState))
      return;
    impl.setTestEnum(cppValue);
    return;
  }
}

v8::Local<v8::Value> ToV8(const TestEnumOrDouble& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.m_type) {
    case TestEnumOrDouble::SpecificTypeNone:
      return v8::Null(isolate);
    case TestEnumOrDouble::SpecificTypeTestEnum:
      return v8String(isolate, impl.getAsTestEnum());
    case TestEnumOrDouble::SpecificTypeDouble:
      return v8::Number::New(isolate, impl.getAsDouble());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

TestEnumOrDouble NativeValueTraits<TestEnumOrDouble>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  TestEnumOrDouble impl;
  V8TestEnumOrDouble::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
  return impl;
}

}  // namespace blink

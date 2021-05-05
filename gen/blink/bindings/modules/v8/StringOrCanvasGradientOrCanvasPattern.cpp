// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format off
#include "StringOrCanvasGradientOrCanvasPattern.h"

#include "bindings/core/v8/ToV8.h"
#include "bindings/modules/v8/V8CanvasGradient.h"
#include "bindings/modules/v8/V8CanvasPattern.h"

namespace blink {

StringOrCanvasGradientOrCanvasPattern::StringOrCanvasGradientOrCanvasPattern() : m_type(SpecificTypeNone) {}

String StringOrCanvasGradientOrCanvasPattern::getAsString() const {
  DCHECK(isString());
  return m_string;
}

void StringOrCanvasGradientOrCanvasPattern::setString(String value) {
  DCHECK(isNull());
  m_string = value;
  m_type = SpecificTypeString;
}

StringOrCanvasGradientOrCanvasPattern StringOrCanvasGradientOrCanvasPattern::fromString(String value) {
  StringOrCanvasGradientOrCanvasPattern container;
  container.setString(value);
  return container;
}

CanvasGradient* StringOrCanvasGradientOrCanvasPattern::getAsCanvasGradient() const {
  DCHECK(isCanvasGradient());
  return m_canvasGradient;
}

void StringOrCanvasGradientOrCanvasPattern::setCanvasGradient(CanvasGradient* value) {
  DCHECK(isNull());
  m_canvasGradient = value;
  m_type = SpecificTypeCanvasGradient;
}

StringOrCanvasGradientOrCanvasPattern StringOrCanvasGradientOrCanvasPattern::fromCanvasGradient(CanvasGradient* value) {
  StringOrCanvasGradientOrCanvasPattern container;
  container.setCanvasGradient(value);
  return container;
}

CanvasPattern* StringOrCanvasGradientOrCanvasPattern::getAsCanvasPattern() const {
  DCHECK(isCanvasPattern());
  return m_canvasPattern;
}

void StringOrCanvasGradientOrCanvasPattern::setCanvasPattern(CanvasPattern* value) {
  DCHECK(isNull());
  m_canvasPattern = value;
  m_type = SpecificTypeCanvasPattern;
}

StringOrCanvasGradientOrCanvasPattern StringOrCanvasGradientOrCanvasPattern::fromCanvasPattern(CanvasPattern* value) {
  StringOrCanvasGradientOrCanvasPattern container;
  container.setCanvasPattern(value);
  return container;
}

StringOrCanvasGradientOrCanvasPattern::StringOrCanvasGradientOrCanvasPattern(const StringOrCanvasGradientOrCanvasPattern&) = default;
StringOrCanvasGradientOrCanvasPattern::~StringOrCanvasGradientOrCanvasPattern() = default;
StringOrCanvasGradientOrCanvasPattern& StringOrCanvasGradientOrCanvasPattern::operator=(const StringOrCanvasGradientOrCanvasPattern&) = default;

DEFINE_TRACE(StringOrCanvasGradientOrCanvasPattern) {
  visitor->trace(m_canvasGradient);
  visitor->trace(m_canvasPattern);
}

void V8StringOrCanvasGradientOrCanvasPattern::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, StringOrCanvasGradientOrCanvasPattern& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState) {
  if (v8Value.IsEmpty())
    return;

  if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
    return;

  if (V8CanvasGradient::hasInstance(v8Value, isolate)) {
    CanvasGradient* cppValue = V8CanvasGradient::toImpl(v8::Local<v8::Object>::Cast(v8Value));
    impl.setCanvasGradient(cppValue);
    return;
  }

  if (V8CanvasPattern::hasInstance(v8Value, isolate)) {
    CanvasPattern* cppValue = V8CanvasPattern::toImpl(v8::Local<v8::Object>::Cast(v8Value));
    impl.setCanvasPattern(cppValue);
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

v8::Local<v8::Value> ToV8(const StringOrCanvasGradientOrCanvasPattern& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.m_type) {
    case StringOrCanvasGradientOrCanvasPattern::SpecificTypeNone:
      return v8::Null(isolate);
    case StringOrCanvasGradientOrCanvasPattern::SpecificTypeString:
      return v8String(isolate, impl.getAsString());
    case StringOrCanvasGradientOrCanvasPattern::SpecificTypeCanvasGradient:
      return ToV8(impl.getAsCanvasGradient(), creationContext, isolate);
    case StringOrCanvasGradientOrCanvasPattern::SpecificTypeCanvasPattern:
      return ToV8(impl.getAsCanvasPattern(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

StringOrCanvasGradientOrCanvasPattern NativeValueTraits<StringOrCanvasGradientOrCanvasPattern>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  StringOrCanvasGradientOrCanvasPattern impl;
  V8StringOrCanvasGradientOrCanvasPattern::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
  return impl;
}

}  // namespace blink

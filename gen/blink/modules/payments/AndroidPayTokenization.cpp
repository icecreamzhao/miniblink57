// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "AndroidPayTokenization.h"

namespace blink {

AndroidPayTokenization::AndroidPayTokenization() {
}

AndroidPayTokenization::~AndroidPayTokenization() {}

AndroidPayTokenization::AndroidPayTokenization(const AndroidPayTokenization&) = default;

AndroidPayTokenization& AndroidPayTokenization::operator=(const AndroidPayTokenization&) = default;

bool AndroidPayTokenization::hasParameters() const {
  return !m_parameters.isUndefinedOrNull();
}
Dictionary AndroidPayTokenization::parameters() const {
  return m_parameters;
}
void AndroidPayTokenization::setParameters(Dictionary value) {
  m_parameters = value;
}
bool AndroidPayTokenization::hasTokenizationType() const {
  return !m_tokenizationType.isNull();
}
String AndroidPayTokenization::tokenizationType() const {
  return m_tokenizationType;
}
void AndroidPayTokenization::setTokenizationType(String value) {
  m_tokenizationType = value;
}

DEFINE_TRACE(AndroidPayTokenization) {
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

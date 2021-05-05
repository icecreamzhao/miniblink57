// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "ElementCreationOptions.h"

namespace blink {

ElementCreationOptions::ElementCreationOptions() {
}

ElementCreationOptions::~ElementCreationOptions() {}

ElementCreationOptions::ElementCreationOptions(const ElementCreationOptions&) = default;

ElementCreationOptions& ElementCreationOptions::operator=(const ElementCreationOptions&) = default;

bool ElementCreationOptions::hasIs() const {
  return !m_is.isNull();
}
String ElementCreationOptions::is() const {
  return m_is;
}
void ElementCreationOptions::setIs(String value) {
  m_is = value;
}

DEFINE_TRACE(ElementCreationOptions) {
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

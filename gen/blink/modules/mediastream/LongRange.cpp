// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "LongRange.h"

namespace blink {

LongRange::LongRange() {
}

LongRange::~LongRange() {}

LongRange::LongRange(const LongRange&) = default;

LongRange& LongRange::operator=(const LongRange&) = default;

bool LongRange::hasMax() const {
  return m_hasMax;
}
int LongRange::max() const {
  DCHECK(m_hasMax);
  return m_max;
}
void LongRange::setMax(int value) {
  m_max = value;
  m_hasMax = true;
}
bool LongRange::hasMin() const {
  return m_hasMin;
}
int LongRange::min() const {
  DCHECK(m_hasMin);
  return m_min;
}
void LongRange::setMin(int value) {
  m_min = value;
  m_hasMin = true;
}

DEFINE_TRACE(LongRange) {
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

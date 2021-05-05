// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "SensorOptions.h"

namespace blink {

SensorOptions::SensorOptions() {
}

SensorOptions::~SensorOptions() {}

SensorOptions::SensorOptions(const SensorOptions&) = default;

SensorOptions& SensorOptions::operator=(const SensorOptions&) = default;

bool SensorOptions::hasFrequency() const {
  return m_hasFrequency;
}
double SensorOptions::frequency() const {
  DCHECK(m_hasFrequency);
  return m_frequency;
}
void SensorOptions::setFrequency(double value) {
  m_frequency = value;
  m_hasFrequency = true;
}
void SensorOptions::setFrequencyToNull() {
  m_hasFrequency = false;
}

DEFINE_TRACE(SensorOptions) {
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

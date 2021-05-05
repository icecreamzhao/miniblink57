// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "PushEventInit.h"

#include "bindings/modules/v8/ArrayBufferOrArrayBufferViewOrUSVString.h"

namespace blink {

PushEventInit::PushEventInit() {
}

PushEventInit::~PushEventInit() {}

PushEventInit::PushEventInit(const PushEventInit&) = default;

PushEventInit& PushEventInit::operator=(const PushEventInit&) = default;

bool PushEventInit::hasData() const {
  return !m_data.isNull();
}
const ArrayBufferOrArrayBufferViewOrUSVString& PushEventInit::data() const {
  return m_data;
}
void PushEventInit::setData(const ArrayBufferOrArrayBufferViewOrUSVString& value) {
  m_data = value;
}

DEFINE_TRACE(PushEventInit) {
  visitor->trace(m_data);
  ExtendableEventInit::trace(visitor);
}

}  // namespace blink

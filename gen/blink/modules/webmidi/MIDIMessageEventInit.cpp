// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "MIDIMessageEventInit.h"

namespace blink {

MIDIMessageEventInit::MIDIMessageEventInit() {
}

MIDIMessageEventInit::~MIDIMessageEventInit() {}

MIDIMessageEventInit::MIDIMessageEventInit(const MIDIMessageEventInit&) = default;

MIDIMessageEventInit& MIDIMessageEventInit::operator=(const MIDIMessageEventInit&) = default;

bool MIDIMessageEventInit::hasData() const {
  return m_data;
}
DOMUint8Array* MIDIMessageEventInit::data() const {
  return m_data;
}
void MIDIMessageEventInit::setData(DOMUint8Array* value) {
  m_data = value;
}
void MIDIMessageEventInit::setDataToNull() {
  m_data = Member<DOMUint8Array>();
}

DEFINE_TRACE(MIDIMessageEventInit) {
  visitor->trace(m_data);
  EventInit::trace(visitor);
}

}  // namespace blink

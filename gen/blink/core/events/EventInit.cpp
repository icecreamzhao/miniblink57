// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "EventInit.h"

namespace blink {

EventInit::EventInit() {
  setBubbles(false);
  setCancelable(false);
  setComposed(false);
}

EventInit::~EventInit() {}

EventInit::EventInit(const EventInit&) = default;

EventInit& EventInit::operator=(const EventInit&) = default;

bool EventInit::hasBubbles() const {
  return m_hasBubbles;
}
bool EventInit::bubbles() const {
  DCHECK(m_hasBubbles);
  return m_bubbles;
}
void EventInit::setBubbles(bool value) {
  m_bubbles = value;
  m_hasBubbles = true;
}
bool EventInit::hasCancelable() const {
  return m_hasCancelable;
}
bool EventInit::cancelable() const {
  DCHECK(m_hasCancelable);
  return m_cancelable;
}
void EventInit::setCancelable(bool value) {
  m_cancelable = value;
  m_hasCancelable = true;
}
bool EventInit::hasComposed() const {
  return m_hasComposed;
}
bool EventInit::composed() const {
  DCHECK(m_hasComposed);
  return m_composed;
}
void EventInit::setComposed(bool value) {
  m_composed = value;
  m_hasComposed = true;
}

DEFINE_TRACE(EventInit) {
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

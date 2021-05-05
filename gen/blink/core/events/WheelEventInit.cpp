// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "WheelEventInit.h"

namespace blink {

WheelEventInit::WheelEventInit() {
  setDeltaMode(0u);
  setDeltaX(0);
  setDeltaY(0);
  setDeltaZ(0);
  setWheelDeltaX(0);
  setWheelDeltaY(0);
}

WheelEventInit::~WheelEventInit() {}

WheelEventInit::WheelEventInit(const WheelEventInit&) = default;

WheelEventInit& WheelEventInit::operator=(const WheelEventInit&) = default;

bool WheelEventInit::hasDeltaMode() const {
  return m_hasDeltaMode;
}
unsigned WheelEventInit::deltaMode() const {
  DCHECK(m_hasDeltaMode);
  return m_deltaMode;
}
void WheelEventInit::setDeltaMode(unsigned value) {
  m_deltaMode = value;
  m_hasDeltaMode = true;
}
bool WheelEventInit::hasDeltaX() const {
  return m_hasDeltaX;
}
double WheelEventInit::deltaX() const {
  DCHECK(m_hasDeltaX);
  return m_deltaX;
}
void WheelEventInit::setDeltaX(double value) {
  m_deltaX = value;
  m_hasDeltaX = true;
}
bool WheelEventInit::hasDeltaY() const {
  return m_hasDeltaY;
}
double WheelEventInit::deltaY() const {
  DCHECK(m_hasDeltaY);
  return m_deltaY;
}
void WheelEventInit::setDeltaY(double value) {
  m_deltaY = value;
  m_hasDeltaY = true;
}
bool WheelEventInit::hasDeltaZ() const {
  return m_hasDeltaZ;
}
double WheelEventInit::deltaZ() const {
  DCHECK(m_hasDeltaZ);
  return m_deltaZ;
}
void WheelEventInit::setDeltaZ(double value) {
  m_deltaZ = value;
  m_hasDeltaZ = true;
}
bool WheelEventInit::hasWheelDeltaX() const {
  return m_hasWheelDeltaX;
}
int WheelEventInit::wheelDeltaX() const {
  DCHECK(m_hasWheelDeltaX);
  return m_wheelDeltaX;
}
void WheelEventInit::setWheelDeltaX(int value) {
  m_wheelDeltaX = value;
  m_hasWheelDeltaX = true;
}
bool WheelEventInit::hasWheelDeltaY() const {
  return m_hasWheelDeltaY;
}
int WheelEventInit::wheelDeltaY() const {
  DCHECK(m_hasWheelDeltaY);
  return m_wheelDeltaY;
}
void WheelEventInit::setWheelDeltaY(int value) {
  m_wheelDeltaY = value;
  m_hasWheelDeltaY = true;
}

DEFINE_TRACE(WheelEventInit) {
  MouseEventInit::trace(visitor);
}

}  // namespace blink

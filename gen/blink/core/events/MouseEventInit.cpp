// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "MouseEventInit.h"

#include "core/events/EventTarget.h"

namespace blink {

MouseEventInit::MouseEventInit() {
  setButton(0);
  setButtons(0u);
  setClientX(0);
  setClientY(0);
  setMovementX(0);
  setMovementY(0);
  setScreenX(0);
  setScreenY(0);
}

MouseEventInit::~MouseEventInit() {}

MouseEventInit::MouseEventInit(const MouseEventInit&) = default;

MouseEventInit& MouseEventInit::operator=(const MouseEventInit&) = default;

bool MouseEventInit::hasButton() const {
  return m_hasButton;
}
int MouseEventInit::button() const {
  DCHECK(m_hasButton);
  return m_button;
}
void MouseEventInit::setButton(int value) {
  m_button = value;
  m_hasButton = true;
}
bool MouseEventInit::hasButtons() const {
  return m_hasButtons;
}
unsigned MouseEventInit::buttons() const {
  DCHECK(m_hasButtons);
  return m_buttons;
}
void MouseEventInit::setButtons(unsigned value) {
  m_buttons = value;
  m_hasButtons = true;
}
bool MouseEventInit::hasClientX() const {
  return m_hasClientX;
}
double MouseEventInit::clientX() const {
  DCHECK(m_hasClientX);
  return m_clientX;
}
void MouseEventInit::setClientX(double value) {
  m_clientX = value;
  m_hasClientX = true;
}
bool MouseEventInit::hasClientY() const {
  return m_hasClientY;
}
double MouseEventInit::clientY() const {
  DCHECK(m_hasClientY);
  return m_clientY;
}
void MouseEventInit::setClientY(double value) {
  m_clientY = value;
  m_hasClientY = true;
}
bool MouseEventInit::hasMovementX() const {
  return m_hasMovementX;
}
int MouseEventInit::movementX() const {
  DCHECK(m_hasMovementX);
  return m_movementX;
}
void MouseEventInit::setMovementX(int value) {
  m_movementX = value;
  m_hasMovementX = true;
}
bool MouseEventInit::hasMovementY() const {
  return m_hasMovementY;
}
int MouseEventInit::movementY() const {
  DCHECK(m_hasMovementY);
  return m_movementY;
}
void MouseEventInit::setMovementY(int value) {
  m_movementY = value;
  m_hasMovementY = true;
}
bool MouseEventInit::hasRegion() const {
  return !m_region.isNull();
}
String MouseEventInit::region() const {
  return m_region;
}
void MouseEventInit::setRegion(String value) {
  m_region = value;
}
void MouseEventInit::setRegionToNull() {
  m_region = String();
}
bool MouseEventInit::hasRelatedTarget() const {
  return m_relatedTarget;
}
EventTarget* MouseEventInit::relatedTarget() const {
  return m_relatedTarget;
}
void MouseEventInit::setRelatedTarget(EventTarget* value) {
  m_relatedTarget = value;
}
void MouseEventInit::setRelatedTargetToNull() {
  m_relatedTarget = Member<EventTarget>();
}
bool MouseEventInit::hasScreenX() const {
  return m_hasScreenX;
}
double MouseEventInit::screenX() const {
  DCHECK(m_hasScreenX);
  return m_screenX;
}
void MouseEventInit::setScreenX(double value) {
  m_screenX = value;
  m_hasScreenX = true;
}
bool MouseEventInit::hasScreenY() const {
  return m_hasScreenY;
}
double MouseEventInit::screenY() const {
  DCHECK(m_hasScreenY);
  return m_screenY;
}
void MouseEventInit::setScreenY(double value) {
  m_screenY = value;
  m_hasScreenY = true;
}

DEFINE_TRACE(MouseEventInit) {
  visitor->trace(m_relatedTarget);
  EventModifierInit::trace(visitor);
}

}  // namespace blink

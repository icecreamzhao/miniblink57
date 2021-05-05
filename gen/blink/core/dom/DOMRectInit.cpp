// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "DOMRectInit.h"

namespace blink {

DOMRectInit::DOMRectInit() {
  setHeight(0);
  setWidth(0);
  setX(0);
  setY(0);
}

DOMRectInit::~DOMRectInit() {}

DOMRectInit::DOMRectInit(const DOMRectInit&) = default;

DOMRectInit& DOMRectInit::operator=(const DOMRectInit&) = default;

bool DOMRectInit::hasHeight() const {
  return m_hasHeight;
}
double DOMRectInit::height() const {
  DCHECK(m_hasHeight);
  return m_height;
}
void DOMRectInit::setHeight(double value) {
  m_height = value;
  m_hasHeight = true;
}
bool DOMRectInit::hasWidth() const {
  return m_hasWidth;
}
double DOMRectInit::width() const {
  DCHECK(m_hasWidth);
  return m_width;
}
void DOMRectInit::setWidth(double value) {
  m_width = value;
  m_hasWidth = true;
}
bool DOMRectInit::hasX() const {
  return m_hasX;
}
double DOMRectInit::x() const {
  DCHECK(m_hasX);
  return m_x;
}
void DOMRectInit::setX(double value) {
  m_x = value;
  m_hasX = true;
}
bool DOMRectInit::hasY() const {
  return m_hasY;
}
double DOMRectInit::y() const {
  DCHECK(m_hasY);
  return m_y;
}
void DOMRectInit::setY(double value) {
  m_y = value;
  m_hasY = true;
}

DEFINE_TRACE(DOMRectInit) {
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

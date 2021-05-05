// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "VRLayer.h"

#include "core/html/HTMLCanvasElement.h"

namespace blink {

VRLayer::VRLayer() {
  setLeftBounds(Vector<float>());
  setRightBounds(Vector<float>());
}

VRLayer::~VRLayer() {}

VRLayer::VRLayer(const VRLayer&) = default;

VRLayer& VRLayer::operator=(const VRLayer&) = default;

bool VRLayer::hasLeftBounds() const {
  return m_hasLeftBounds;
}
const Vector<float>& VRLayer::leftBounds() const {
  DCHECK(m_hasLeftBounds);
  return m_leftBounds;
}
void VRLayer::setLeftBounds(const Vector<float>& value) {
  m_leftBounds = value;
  m_hasLeftBounds = true;
}
bool VRLayer::hasRightBounds() const {
  return m_hasRightBounds;
}
const Vector<float>& VRLayer::rightBounds() const {
  DCHECK(m_hasRightBounds);
  return m_rightBounds;
}
void VRLayer::setRightBounds(const Vector<float>& value) {
  m_rightBounds = value;
  m_hasRightBounds = true;
}
bool VRLayer::hasSource() const {
  return m_source;
}
HTMLCanvasElement* VRLayer::source() const {
  return m_source;
}
void VRLayer::setSource(HTMLCanvasElement* value) {
  m_source = value;
}
void VRLayer::setSourceToNull() {
  m_source = Member<HTMLCanvasElement>();
}

DEFINE_TRACE(VRLayer) {
  visitor->trace(m_source);
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

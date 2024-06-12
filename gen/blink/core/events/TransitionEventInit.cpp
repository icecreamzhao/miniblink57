// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "TransitionEventInit.h"

namespace blink {

TransitionEventInit::TransitionEventInit()
{
    setElapsedTime(0);
    setPropertyName(String(""));
    setPseudoElement(String(""));
}

TransitionEventInit::~TransitionEventInit() { }

TransitionEventInit::TransitionEventInit(const TransitionEventInit&) = default;

TransitionEventInit& TransitionEventInit::operator=(const TransitionEventInit&) = default;

bool TransitionEventInit::hasElapsedTime() const
{
    return m_hasElapsedTime;
}
double TransitionEventInit::elapsedTime() const
{
    DCHECK(m_hasElapsedTime);
    return m_elapsedTime;
}
void TransitionEventInit::setElapsedTime(double value)
{
    m_elapsedTime = value;
    m_hasElapsedTime = true;
}
bool TransitionEventInit::hasPropertyName() const
{
    return !m_propertyName.isNull();
}
String TransitionEventInit::propertyName() const
{
    return m_propertyName;
}
void TransitionEventInit::setPropertyName(String value)
{
    m_propertyName = value;
}
bool TransitionEventInit::hasPseudoElement() const
{
    return !m_pseudoElement.isNull();
}
String TransitionEventInit::pseudoElement() const
{
    return m_pseudoElement;
}
void TransitionEventInit::setPseudoElement(String value)
{
    m_pseudoElement = value;
}

DEFINE_TRACE(TransitionEventInit)
{
    EventInit::trace(visitor);
}

} // namespace blink

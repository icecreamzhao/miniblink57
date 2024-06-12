// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "TouchEventInit.h"

#include "core/dom/Touch.h"
#include "wtf/Vector.h"

namespace blink {

TouchEventInit::TouchEventInit()
{
    setChangedTouches(HeapVector<Member<Touch>>());
    setTargetTouches(HeapVector<Member<Touch>>());
    setTouches(HeapVector<Member<Touch>>());
}

TouchEventInit::~TouchEventInit() { }

TouchEventInit::TouchEventInit(const TouchEventInit&) = default;

TouchEventInit& TouchEventInit::operator=(const TouchEventInit&) = default;

bool TouchEventInit::hasChangedTouches() const
{
    return m_hasChangedTouches;
}
const HeapVector<Member<Touch>>& TouchEventInit::changedTouches() const
{
    DCHECK(m_hasChangedTouches);
    return m_changedTouches;
}
void TouchEventInit::setChangedTouches(const HeapVector<Member<Touch>>& value)
{
    m_changedTouches = value;
    m_hasChangedTouches = true;
}
bool TouchEventInit::hasTargetTouches() const
{
    return m_hasTargetTouches;
}
const HeapVector<Member<Touch>>& TouchEventInit::targetTouches() const
{
    DCHECK(m_hasTargetTouches);
    return m_targetTouches;
}
void TouchEventInit::setTargetTouches(const HeapVector<Member<Touch>>& value)
{
    m_targetTouches = value;
    m_hasTargetTouches = true;
}
bool TouchEventInit::hasTouches() const
{
    return m_hasTouches;
}
const HeapVector<Member<Touch>>& TouchEventInit::touches() const
{
    DCHECK(m_hasTouches);
    return m_touches;
}
void TouchEventInit::setTouches(const HeapVector<Member<Touch>>& value)
{
    m_touches = value;
    m_hasTouches = true;
}

DEFINE_TRACE(TouchEventInit)
{
    visitor->trace(m_changedTouches);
    visitor->trace(m_targetTouches);
    visitor->trace(m_touches);
    EventModifierInit::trace(visitor);
}

} // namespace blink

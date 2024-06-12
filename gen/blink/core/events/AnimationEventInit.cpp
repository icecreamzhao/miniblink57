// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "AnimationEventInit.h"

namespace blink {

AnimationEventInit::AnimationEventInit()
{
    setAnimationName(String(""));
    setElapsedTime(0);
}

AnimationEventInit::~AnimationEventInit() { }

AnimationEventInit::AnimationEventInit(const AnimationEventInit&) = default;

AnimationEventInit& AnimationEventInit::operator=(const AnimationEventInit&) = default;

bool AnimationEventInit::hasAnimationName() const
{
    return !m_animationName.isNull();
}
String AnimationEventInit::animationName() const
{
    return m_animationName;
}
void AnimationEventInit::setAnimationName(String value)
{
    m_animationName = value;
}
bool AnimationEventInit::hasElapsedTime() const
{
    return m_hasElapsedTime;
}
double AnimationEventInit::elapsedTime() const
{
    DCHECK(m_hasElapsedTime);
    return m_elapsedTime;
}
void AnimationEventInit::setElapsedTime(double value)
{
    m_elapsedTime = value;
    m_hasElapsedTime = true;
}

DEFINE_TRACE(AnimationEventInit)
{
    EventInit::trace(visitor);
}

} // namespace blink

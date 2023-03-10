// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "AnimationEffectTimingProperties.h"

#include "bindings/core/v8/UnrestrictedDoubleOrString.h"

namespace blink {

AnimationEffectTimingProperties::AnimationEffectTimingProperties()
{
    setDelay(0);
    setDirection(String("normal"));
    setDuration(UnrestrictedDoubleOrString::fromString(String("auto")));
    setEasing(String("linear"));
    setEndDelay(0);
    setFill(String("auto"));
    setIterationStart(0);
    setIterations(1);
}

AnimationEffectTimingProperties::~AnimationEffectTimingProperties() { }

AnimationEffectTimingProperties::AnimationEffectTimingProperties(const AnimationEffectTimingProperties&) = default;

AnimationEffectTimingProperties& AnimationEffectTimingProperties::operator=(const AnimationEffectTimingProperties&) = default;

bool AnimationEffectTimingProperties::hasDelay() const
{
    return m_hasDelay;
}
double AnimationEffectTimingProperties::delay() const
{
    DCHECK(m_hasDelay);
    return m_delay;
}
void AnimationEffectTimingProperties::setDelay(double value)
{
    m_delay = value;
    m_hasDelay = true;
}
bool AnimationEffectTimingProperties::hasDirection() const
{
    return !m_direction.isNull();
}
String AnimationEffectTimingProperties::direction() const
{
    return m_direction;
}
void AnimationEffectTimingProperties::setDirection(String value)
{
    m_direction = value;
}
bool AnimationEffectTimingProperties::hasDuration() const
{
    return !m_duration.isNull();
}
const UnrestrictedDoubleOrString& AnimationEffectTimingProperties::duration() const
{
    return m_duration;
}
void AnimationEffectTimingProperties::setDuration(const UnrestrictedDoubleOrString& value)
{
    m_duration = value;
}
bool AnimationEffectTimingProperties::hasEasing() const
{
    return !m_easing.isNull();
}
String AnimationEffectTimingProperties::easing() const
{
    return m_easing;
}
void AnimationEffectTimingProperties::setEasing(String value)
{
    m_easing = value;
}
bool AnimationEffectTimingProperties::hasEndDelay() const
{
    return m_hasEndDelay;
}
double AnimationEffectTimingProperties::endDelay() const
{
    DCHECK(m_hasEndDelay);
    return m_endDelay;
}
void AnimationEffectTimingProperties::setEndDelay(double value)
{
    m_endDelay = value;
    m_hasEndDelay = true;
}
bool AnimationEffectTimingProperties::hasFill() const
{
    return !m_fill.isNull();
}
String AnimationEffectTimingProperties::fill() const
{
    return m_fill;
}
void AnimationEffectTimingProperties::setFill(String value)
{
    m_fill = value;
}
bool AnimationEffectTimingProperties::hasIterationStart() const
{
    return m_hasIterationStart;
}
double AnimationEffectTimingProperties::iterationStart() const
{
    DCHECK(m_hasIterationStart);
    return m_iterationStart;
}
void AnimationEffectTimingProperties::setIterationStart(double value)
{
    m_iterationStart = value;
    m_hasIterationStart = true;
}
bool AnimationEffectTimingProperties::hasIterations() const
{
    return m_hasIterations;
}
double AnimationEffectTimingProperties::iterations() const
{
    DCHECK(m_hasIterations);
    return m_iterations;
}
void AnimationEffectTimingProperties::setIterations(double value)
{
    m_iterations = value;
    m_hasIterations = true;
}

DEFINE_TRACE(AnimationEffectTimingProperties)
{
    visitor->trace(m_duration);
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink

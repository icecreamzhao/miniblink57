// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "AnimationPlaybackEventInit.h"

namespace blink {

AnimationPlaybackEventInit::AnimationPlaybackEventInit() {
}

AnimationPlaybackEventInit::~AnimationPlaybackEventInit() {}

AnimationPlaybackEventInit::AnimationPlaybackEventInit(const AnimationPlaybackEventInit&) = default;

AnimationPlaybackEventInit& AnimationPlaybackEventInit::operator=(const AnimationPlaybackEventInit&) = default;

bool AnimationPlaybackEventInit::hasCurrentTime() const {
  return m_hasCurrentTime;
}
double AnimationPlaybackEventInit::currentTime() const {
  DCHECK(m_hasCurrentTime);
  return m_currentTime;
}
void AnimationPlaybackEventInit::setCurrentTime(double value) {
  m_currentTime = value;
  m_hasCurrentTime = true;
}
void AnimationPlaybackEventInit::setCurrentTimeToNull() {
  m_hasCurrentTime = false;
}
bool AnimationPlaybackEventInit::hasTimelineTime() const {
  return m_hasTimelineTime;
}
double AnimationPlaybackEventInit::timelineTime() const {
  DCHECK(m_hasTimelineTime);
  return m_timelineTime;
}
void AnimationPlaybackEventInit::setTimelineTime(double value) {
  m_timelineTime = value;
  m_hasTimelineTime = true;
}
void AnimationPlaybackEventInit::setTimelineTimeToNull() {
  m_hasTimelineTime = false;
}

DEFINE_TRACE(AnimationPlaybackEventInit) {
  EventInit::trace(visitor);
}

}  // namespace blink

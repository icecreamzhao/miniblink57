// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/animation/css/CSSTimingData.h"

#include "core/animation/Timing.h"

namespace blink {

CSSTimingData::CSSTimingData()
{
    m_delayList.push_back(initialDelay());
    m_durationList.push_back(initialDuration());
    m_timingFunctionList.push_back(initialTimingFunction());
}

CSSTimingData::CSSTimingData(const CSSTimingData& other)
    : m_delayList(other.m_delayList)
    , m_durationList(other.m_durationList)
    , m_timingFunctionList(other.m_timingFunctionList)
{
}

Timing CSSTimingData::convertToTiming(size_t index) const
{
    Timing timing;
    timing.startDelay = getRepeated(m_delayList, index);
    timing.iterationDuration = getRepeated(m_durationList, index);
    timing.timingFunction = getRepeated(m_timingFunctionList, index);
    timing.assertValid();
    return timing;
}

} // namespace blink

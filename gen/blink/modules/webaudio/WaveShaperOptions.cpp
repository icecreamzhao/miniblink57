// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "WaveShaperOptions.h"

namespace blink {

WaveShaperOptions::WaveShaperOptions()
{
}

WaveShaperOptions::~WaveShaperOptions() { }

WaveShaperOptions::WaveShaperOptions(const WaveShaperOptions&) = default;

WaveShaperOptions& WaveShaperOptions::operator=(const WaveShaperOptions&) = default;

bool WaveShaperOptions::hasCurve() const
{
    return m_hasCurve;
}
const Vector<float>& WaveShaperOptions::curve() const
{
    DCHECK(m_hasCurve);
    return m_curve;
}
void WaveShaperOptions::setCurve(const Vector<float>& value)
{
    m_curve = value;
    m_hasCurve = true;
}
bool WaveShaperOptions::hasOversample() const
{
    return !m_oversample.isNull();
}
String WaveShaperOptions::oversample() const
{
    return m_oversample;
}
void WaveShaperOptions::setOversample(String value)
{
    m_oversample = value;
}

DEFINE_TRACE(WaveShaperOptions)
{
    AudioNodeOptions::trace(visitor);
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "RTCOfferAnswerOptions.h"

namespace blink {

RTCOfferAnswerOptions::RTCOfferAnswerOptions()
{
    setVoiceActivityDetection(true);
}

RTCOfferAnswerOptions::~RTCOfferAnswerOptions() { }

RTCOfferAnswerOptions::RTCOfferAnswerOptions(const RTCOfferAnswerOptions&) = default;

RTCOfferAnswerOptions& RTCOfferAnswerOptions::operator=(const RTCOfferAnswerOptions&) = default;

bool RTCOfferAnswerOptions::hasVoiceActivityDetection() const
{
    return m_hasVoiceActivityDetection;
}
bool RTCOfferAnswerOptions::voiceActivityDetection() const
{
    DCHECK(m_hasVoiceActivityDetection);
    return m_voiceActivityDetection;
}
void RTCOfferAnswerOptions::setVoiceActivityDetection(bool value)
{
    m_voiceActivityDetection = value;
    m_hasVoiceActivityDetection = true;
}

DEFINE_TRACE(RTCOfferAnswerOptions)
{
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink

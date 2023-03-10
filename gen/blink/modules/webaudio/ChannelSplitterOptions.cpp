// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "ChannelSplitterOptions.h"

namespace blink {

ChannelSplitterOptions::ChannelSplitterOptions()
{
    setNumberOfOutputs(6u);
}

ChannelSplitterOptions::~ChannelSplitterOptions() { }

ChannelSplitterOptions::ChannelSplitterOptions(const ChannelSplitterOptions&) = default;

ChannelSplitterOptions& ChannelSplitterOptions::operator=(const ChannelSplitterOptions&) = default;

bool ChannelSplitterOptions::hasNumberOfOutputs() const
{
    return m_hasNumberOfOutputs;
}
unsigned ChannelSplitterOptions::numberOfOutputs() const
{
    DCHECK(m_hasNumberOfOutputs);
    return m_numberOfOutputs;
}
void ChannelSplitterOptions::setNumberOfOutputs(unsigned value)
{
    m_numberOfOutputs = value;
    m_hasNumberOfOutputs = true;
}

DEFINE_TRACE(ChannelSplitterOptions)
{
    AudioNodeOptions::trace(visitor);
}

} // namespace blink

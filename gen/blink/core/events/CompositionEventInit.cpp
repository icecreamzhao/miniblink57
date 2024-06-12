// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "CompositionEventInit.h"

namespace blink {

CompositionEventInit::CompositionEventInit()
{
    setData(String(""));
}

CompositionEventInit::~CompositionEventInit() { }

CompositionEventInit::CompositionEventInit(const CompositionEventInit&) = default;

CompositionEventInit& CompositionEventInit::operator=(const CompositionEventInit&) = default;

bool CompositionEventInit::hasData() const
{
    return !m_data.isNull();
}
String CompositionEventInit::data() const
{
    return m_data;
}
void CompositionEventInit::setData(String value)
{
    m_data = value;
}

DEFINE_TRACE(CompositionEventInit)
{
    UIEventInit::trace(visitor);
}

} // namespace blink

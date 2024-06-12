// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "SensorErrorEventInit.h"

#include "core/dom/DOMException.h"

namespace blink {

SensorErrorEventInit::SensorErrorEventInit()
{
}

SensorErrorEventInit::~SensorErrorEventInit() { }

SensorErrorEventInit::SensorErrorEventInit(const SensorErrorEventInit&) = default;

SensorErrorEventInit& SensorErrorEventInit::operator=(const SensorErrorEventInit&) = default;

bool SensorErrorEventInit::hasError() const
{
    return m_error;
}
DOMException* SensorErrorEventInit::error() const
{
    return m_error;
}
void SensorErrorEventInit::setError(DOMException* value)
{
    m_error = value;
}

DEFINE_TRACE(SensorErrorEventInit)
{
    visitor->trace(m_error);
    EventInit::trace(visitor);
}

} // namespace blink

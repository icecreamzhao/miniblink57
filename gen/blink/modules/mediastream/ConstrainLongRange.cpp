// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "ConstrainLongRange.h"

namespace blink {

ConstrainLongRange::ConstrainLongRange()
{
}

ConstrainLongRange::~ConstrainLongRange() { }

ConstrainLongRange::ConstrainLongRange(const ConstrainLongRange&) = default;

ConstrainLongRange& ConstrainLongRange::operator=(const ConstrainLongRange&) = default;

bool ConstrainLongRange::hasExact() const
{
    return m_hasExact;
}
int ConstrainLongRange::exact() const
{
    DCHECK(m_hasExact);
    return m_exact;
}
void ConstrainLongRange::setExact(int value)
{
    m_exact = value;
    m_hasExact = true;
}
bool ConstrainLongRange::hasIdeal() const
{
    return m_hasIdeal;
}
int ConstrainLongRange::ideal() const
{
    DCHECK(m_hasIdeal);
    return m_ideal;
}
void ConstrainLongRange::setIdeal(int value)
{
    m_ideal = value;
    m_hasIdeal = true;
}

DEFINE_TRACE(ConstrainLongRange)
{
    LongRange::trace(visitor);
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "IDBIndexParameters.h"

namespace blink {

IDBIndexParameters::IDBIndexParameters()
{
    setMultiEntry(false);
    setUnique(false);
}

IDBIndexParameters::~IDBIndexParameters() { }

IDBIndexParameters::IDBIndexParameters(const IDBIndexParameters&) = default;

IDBIndexParameters& IDBIndexParameters::operator=(const IDBIndexParameters&) = default;

bool IDBIndexParameters::hasMultiEntry() const
{
    return m_hasMultiEntry;
}
bool IDBIndexParameters::multiEntry() const
{
    DCHECK(m_hasMultiEntry);
    return m_multiEntry;
}
void IDBIndexParameters::setMultiEntry(bool value)
{
    m_multiEntry = value;
    m_hasMultiEntry = true;
}
bool IDBIndexParameters::hasUnique() const
{
    return m_hasUnique;
}
bool IDBIndexParameters::unique() const
{
    DCHECK(m_hasUnique);
    return m_unique;
}
void IDBIndexParameters::setUnique(bool value)
{
    m_unique = value;
    m_hasUnique = true;
}

DEFINE_TRACE(IDBIndexParameters)
{
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink

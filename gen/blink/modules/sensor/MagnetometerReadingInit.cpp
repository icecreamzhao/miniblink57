// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "MagnetometerReadingInit.h"

namespace blink {

MagnetometerReadingInit::MagnetometerReadingInit()
{
    setX(0);
    setY(0);
    setZ(0);
}

MagnetometerReadingInit::~MagnetometerReadingInit() { }

MagnetometerReadingInit::MagnetometerReadingInit(const MagnetometerReadingInit&) = default;

MagnetometerReadingInit& MagnetometerReadingInit::operator=(const MagnetometerReadingInit&) = default;

bool MagnetometerReadingInit::hasX() const
{
    return m_hasX;
}
double MagnetometerReadingInit::x() const
{
    DCHECK(m_hasX);
    return m_x;
}
void MagnetometerReadingInit::setX(double value)
{
    m_x = value;
    m_hasX = true;
}
bool MagnetometerReadingInit::hasY() const
{
    return m_hasY;
}
double MagnetometerReadingInit::y() const
{
    DCHECK(m_hasY);
    return m_y;
}
void MagnetometerReadingInit::setY(double value)
{
    m_y = value;
    m_hasY = true;
}
bool MagnetometerReadingInit::hasZ() const
{
    return m_hasZ;
}
double MagnetometerReadingInit::z() const
{
    DCHECK(m_hasZ);
    return m_z;
}
void MagnetometerReadingInit::setZ(double value)
{
    m_z = value;
    m_hasZ = true;
}

DEFINE_TRACE(MagnetometerReadingInit)
{
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "AmbientLightSensorReadingInit.h"

namespace blink {

AmbientLightSensorReadingInit::AmbientLightSensorReadingInit()
{
}

AmbientLightSensorReadingInit::~AmbientLightSensorReadingInit() { }

AmbientLightSensorReadingInit::AmbientLightSensorReadingInit(const AmbientLightSensorReadingInit&) = default;

AmbientLightSensorReadingInit& AmbientLightSensorReadingInit::operator=(const AmbientLightSensorReadingInit&) = default;

bool AmbientLightSensorReadingInit::hasIlluminance() const
{
    return m_hasIlluminance;
}
double AmbientLightSensorReadingInit::illuminance() const
{
    DCHECK(m_hasIlluminance);
    return m_illuminance;
}
void AmbientLightSensorReadingInit::setIlluminance(double value)
{
    m_illuminance = value;
    m_hasIlluminance = true;
}

DEFINE_TRACE(AmbientLightSensorReadingInit)
{
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink

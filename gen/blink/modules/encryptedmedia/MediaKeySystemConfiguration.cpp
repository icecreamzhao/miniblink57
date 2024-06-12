// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "MediaKeySystemConfiguration.h"

namespace blink {

MediaKeySystemConfiguration::MediaKeySystemConfiguration()
{
    setAudioCapabilities(HeapVector<MediaKeySystemMediaCapability>());
    setDistinctiveIdentifier(String("optional"));
    setInitDataTypes(Vector<String>());
    setLabel(String(""));
    setPersistentState(String("optional"));
    setVideoCapabilities(HeapVector<MediaKeySystemMediaCapability>());
}

MediaKeySystemConfiguration::~MediaKeySystemConfiguration() { }

MediaKeySystemConfiguration::MediaKeySystemConfiguration(const MediaKeySystemConfiguration&) = default;

MediaKeySystemConfiguration& MediaKeySystemConfiguration::operator=(const MediaKeySystemConfiguration&) = default;

bool MediaKeySystemConfiguration::hasAudioCapabilities() const
{
    return m_hasAudioCapabilities;
}
const HeapVector<MediaKeySystemMediaCapability>& MediaKeySystemConfiguration::audioCapabilities() const
{
    DCHECK(m_hasAudioCapabilities);
    return m_audioCapabilities;
}
void MediaKeySystemConfiguration::setAudioCapabilities(const HeapVector<MediaKeySystemMediaCapability>& value)
{
    m_audioCapabilities = value;
    m_hasAudioCapabilities = true;
}
bool MediaKeySystemConfiguration::hasDistinctiveIdentifier() const
{
    return !m_distinctiveIdentifier.isNull();
}
String MediaKeySystemConfiguration::distinctiveIdentifier() const
{
    return m_distinctiveIdentifier;
}
void MediaKeySystemConfiguration::setDistinctiveIdentifier(String value)
{
    m_distinctiveIdentifier = value;
}
bool MediaKeySystemConfiguration::hasInitDataTypes() const
{
    return m_hasInitDataTypes;
}
const Vector<String>& MediaKeySystemConfiguration::initDataTypes() const
{
    DCHECK(m_hasInitDataTypes);
    return m_initDataTypes;
}
void MediaKeySystemConfiguration::setInitDataTypes(const Vector<String>& value)
{
    m_initDataTypes = value;
    m_hasInitDataTypes = true;
}
bool MediaKeySystemConfiguration::hasLabel() const
{
    return !m_label.isNull();
}
String MediaKeySystemConfiguration::label() const
{
    return m_label;
}
void MediaKeySystemConfiguration::setLabel(String value)
{
    m_label = value;
}
bool MediaKeySystemConfiguration::hasPersistentState() const
{
    return !m_persistentState.isNull();
}
String MediaKeySystemConfiguration::persistentState() const
{
    return m_persistentState;
}
void MediaKeySystemConfiguration::setPersistentState(String value)
{
    m_persistentState = value;
}
bool MediaKeySystemConfiguration::hasSessionTypes() const
{
    return m_hasSessionTypes;
}
const Vector<String>& MediaKeySystemConfiguration::sessionTypes() const
{
    DCHECK(m_hasSessionTypes);
    return m_sessionTypes;
}
void MediaKeySystemConfiguration::setSessionTypes(const Vector<String>& value)
{
    m_sessionTypes = value;
    m_hasSessionTypes = true;
}
bool MediaKeySystemConfiguration::hasVideoCapabilities() const
{
    return m_hasVideoCapabilities;
}
const HeapVector<MediaKeySystemMediaCapability>& MediaKeySystemConfiguration::videoCapabilities() const
{
    DCHECK(m_hasVideoCapabilities);
    return m_videoCapabilities;
}
void MediaKeySystemConfiguration::setVideoCapabilities(const HeapVector<MediaKeySystemMediaCapability>& value)
{
    m_videoCapabilities = value;
    m_hasVideoCapabilities = true;
}

DEFINE_TRACE(MediaKeySystemConfiguration)
{
    visitor->trace(m_audioCapabilities);
    visitor->trace(m_videoCapabilities);
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink

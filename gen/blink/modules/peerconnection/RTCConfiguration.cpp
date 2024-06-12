// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "RTCConfiguration.h"

#include "modules/peerconnection/RTCCertificate.h"
#include "wtf/Vector.h"

namespace blink {

RTCConfiguration::RTCConfiguration()
{
    setBundlePolicy(String("balanced"));
    setRtcpMuxPolicy(String("require"));
}

RTCConfiguration::~RTCConfiguration() { }

RTCConfiguration::RTCConfiguration(const RTCConfiguration&) = default;

RTCConfiguration& RTCConfiguration::operator=(const RTCConfiguration&) = default;

bool RTCConfiguration::hasBundlePolicy() const
{
    return !m_bundlePolicy.isNull();
}
String RTCConfiguration::bundlePolicy() const
{
    return m_bundlePolicy;
}
void RTCConfiguration::setBundlePolicy(String value)
{
    m_bundlePolicy = value;
}
bool RTCConfiguration::hasCertificates() const
{
    return m_hasCertificates;
}
const HeapVector<Member<RTCCertificate>>& RTCConfiguration::certificates() const
{
    DCHECK(m_hasCertificates);
    return m_certificates;
}
void RTCConfiguration::setCertificates(const HeapVector<Member<RTCCertificate>>& value)
{
    m_certificates = value;
    m_hasCertificates = true;
}
bool RTCConfiguration::hasIceServers() const
{
    return m_hasIceServers;
}
const HeapVector<RTCIceServer>& RTCConfiguration::iceServers() const
{
    DCHECK(m_hasIceServers);
    return m_iceServers;
}
void RTCConfiguration::setIceServers(const HeapVector<RTCIceServer>& value)
{
    m_iceServers = value;
    m_hasIceServers = true;
}
bool RTCConfiguration::hasIceTransportPolicy() const
{
    return !m_iceTransportPolicy.isNull();
}
String RTCConfiguration::iceTransportPolicy() const
{
    return m_iceTransportPolicy;
}
void RTCConfiguration::setIceTransportPolicy(String value)
{
    m_iceTransportPolicy = value;
}
bool RTCConfiguration::hasIceTransports() const
{
    return !m_iceTransports.isNull();
}
String RTCConfiguration::iceTransports() const
{
    return m_iceTransports;
}
void RTCConfiguration::setIceTransports(String value)
{
    m_iceTransports = value;
}
bool RTCConfiguration::hasRtcpMuxPolicy() const
{
    return !m_rtcpMuxPolicy.isNull();
}
String RTCConfiguration::rtcpMuxPolicy() const
{
    return m_rtcpMuxPolicy;
}
void RTCConfiguration::setRtcpMuxPolicy(String value)
{
    m_rtcpMuxPolicy = value;
}

DEFINE_TRACE(RTCConfiguration)
{
    visitor->trace(m_certificates);
    visitor->trace(m_iceServers);
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink

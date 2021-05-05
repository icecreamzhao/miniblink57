// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format off
#include "USBDeviceFilter.h"

namespace blink {

USBDeviceFilter::USBDeviceFilter() {
}

USBDeviceFilter::~USBDeviceFilter() {}

USBDeviceFilter::USBDeviceFilter(const USBDeviceFilter&) = default;

USBDeviceFilter& USBDeviceFilter::operator=(const USBDeviceFilter&) = default;

bool USBDeviceFilter::hasClassCode() const {
  return m_hasClassCode;
}
unsigned USBDeviceFilter::classCode() const {
  DCHECK(m_hasClassCode);
  return m_classCode;
}
void USBDeviceFilter::setClassCode(unsigned value) {
  m_classCode = value;
  m_hasClassCode = true;
}
bool USBDeviceFilter::hasProductId() const {
  return m_hasProductId;
}
unsigned USBDeviceFilter::productId() const {
  DCHECK(m_hasProductId);
  return m_productId;
}
void USBDeviceFilter::setProductId(unsigned value) {
  m_productId = value;
  m_hasProductId = true;
}
bool USBDeviceFilter::hasProtocolCode() const {
  return m_hasProtocolCode;
}
unsigned USBDeviceFilter::protocolCode() const {
  DCHECK(m_hasProtocolCode);
  return m_protocolCode;
}
void USBDeviceFilter::setProtocolCode(unsigned value) {
  m_protocolCode = value;
  m_hasProtocolCode = true;
}
bool USBDeviceFilter::hasSerialNumber() const {
  return !m_serialNumber.isNull();
}
String USBDeviceFilter::serialNumber() const {
  return m_serialNumber;
}
void USBDeviceFilter::setSerialNumber(String value) {
  m_serialNumber = value;
}
bool USBDeviceFilter::hasSubclassCode() const {
  return m_hasSubclassCode;
}
unsigned USBDeviceFilter::subclassCode() const {
  DCHECK(m_hasSubclassCode);
  return m_subclassCode;
}
void USBDeviceFilter::setSubclassCode(unsigned value) {
  m_subclassCode = value;
  m_hasSubclassCode = true;
}
bool USBDeviceFilter::hasVendorId() const {
  return m_hasVendorId;
}
unsigned USBDeviceFilter::vendorId() const {
  DCHECK(m_hasVendorId);
  return m_vendorId;
}
void USBDeviceFilter::setVendorId(unsigned value) {
  m_vendorId = value;
  m_hasVendorId = true;
}

DEFINE_TRACE(USBDeviceFilter) {
  IDLDictionaryBase::trace(visitor);
}

}  // namespace blink

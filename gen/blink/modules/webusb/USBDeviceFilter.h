// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef USBDeviceFilter_h
#define USBDeviceFilter_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT USBDeviceFilter : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  USBDeviceFilter();
  virtual ~USBDeviceFilter();
  USBDeviceFilter(const USBDeviceFilter&);
  USBDeviceFilter& operator=(const USBDeviceFilter&);

  bool hasClassCode() const;
  unsigned classCode() const;
  void setClassCode(unsigned);

  bool hasProductId() const;
  unsigned productId() const;
  void setProductId(unsigned);

  bool hasProtocolCode() const;
  unsigned protocolCode() const;
  void setProtocolCode(unsigned);

  bool hasSerialNumber() const;
  String serialNumber() const;
  void setSerialNumber(String);

  bool hasSubclassCode() const;
  unsigned subclassCode() const;
  void setSubclassCode(unsigned);

  bool hasVendorId() const;
  unsigned vendorId() const;
  void setVendorId(unsigned);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasClassCode = false;
  unsigned m_classCode;
  bool m_hasProductId = false;
  unsigned m_productId;
  bool m_hasProtocolCode = false;
  unsigned m_protocolCode;
  String m_serialNumber;
  bool m_hasSubclassCode = false;
  unsigned m_subclassCode;
  bool m_hasVendorId = false;
  unsigned m_vendorId;

  friend class V8USBDeviceFilter;
};

}  // namespace blink

#endif  // USBDeviceFilter_h

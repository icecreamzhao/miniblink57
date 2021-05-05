// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef BluetoothScanFilterInit_h
#define BluetoothScanFilterInit_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "bindings/modules/v8/StringOrUnsignedLong.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT BluetoothScanFilterInit : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  BluetoothScanFilterInit();
  virtual ~BluetoothScanFilterInit();
  BluetoothScanFilterInit(const BluetoothScanFilterInit&);
  BluetoothScanFilterInit& operator=(const BluetoothScanFilterInit&);

  bool hasName() const;
  String name() const;
  void setName(String);

  bool hasNamePrefix() const;
  String namePrefix() const;
  void setNamePrefix(String);

  bool hasServices() const;
  const HeapVector<StringOrUnsignedLong>& services() const;
  void setServices(const HeapVector<StringOrUnsignedLong>&);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  String m_name;
  String m_namePrefix;
  bool m_hasServices = false;
  HeapVector<StringOrUnsignedLong> m_services;

  friend class V8BluetoothScanFilterInit;
};

}  // namespace blink

#endif  // BluetoothScanFilterInit_h

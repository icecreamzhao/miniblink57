// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef USBControlTransferParameters_h
#define USBControlTransferParameters_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT USBControlTransferParameters : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  USBControlTransferParameters();
  virtual ~USBControlTransferParameters();
  USBControlTransferParameters(const USBControlTransferParameters&);
  USBControlTransferParameters& operator=(const USBControlTransferParameters&);

  bool hasIndex() const;
  unsigned index() const;
  void setIndex(unsigned);

  bool hasRecipient() const;
  String recipient() const;
  void setRecipient(String);

  bool hasRequest() const;
  unsigned request() const;
  void setRequest(unsigned);

  bool hasRequestType() const;
  String requestType() const;
  void setRequestType(String);

  bool hasValue() const;
  unsigned value() const;
  void setValue(unsigned);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasIndex = false;
  unsigned m_index;
  String m_recipient;
  bool m_hasRequest = false;
  unsigned m_request;
  String m_requestType;
  bool m_hasValue = false;
  unsigned m_value;

  friend class V8USBControlTransferParameters;
};

}  // namespace blink

#endif  // USBControlTransferParameters_h

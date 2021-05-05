// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef NFCMessage_h
#define NFCMessage_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "modules/nfc/NFCRecord.h"
#include "platform/heap/Handle.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT NFCMessage : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  NFCMessage();
  virtual ~NFCMessage();
  NFCMessage(const NFCMessage&);
  NFCMessage& operator=(const NFCMessage&);

  bool hasData() const;
  const HeapVector<NFCRecord>& data() const;
  void setData(const HeapVector<NFCRecord>&);

  bool hasURL() const;
  String url() const;
  void setURL(String);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasData = false;
  HeapVector<NFCRecord> m_data;
  String m_url;

  friend class V8NFCMessage;
};

}  // namespace blink

#endif  // NFCMessage_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef NFCRecord_h
#define NFCRecord_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "bindings/core/v8/ScriptValue.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT NFCRecord : public IDLDictionaryBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    NFCRecord();
    virtual ~NFCRecord();
    NFCRecord(const NFCRecord&);
    NFCRecord& operator=(const NFCRecord&);

    bool hasData() const;
    ScriptValue data() const;
    void setData(ScriptValue);

    bool hasMediaType() const;
    String mediaType() const;
    void setMediaType(String);

    bool hasRecordType() const;
    String recordType() const;
    void setRecordType(String);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    ScriptValue m_data;
    String m_mediaType;
    String m_recordType;

    friend class V8NFCRecord;
};

} // namespace blink

#endif // NFCRecord_h

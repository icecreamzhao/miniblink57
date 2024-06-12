// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef CompositionEventInit_h
#define CompositionEventInit_h

#include "core/CoreExport.h"
#include "core/events/UIEventInit.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class CORE_EXPORT CompositionEventInit : public UIEventInit {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    CompositionEventInit();
    virtual ~CompositionEventInit();
    CompositionEventInit(const CompositionEventInit&);
    CompositionEventInit& operator=(const CompositionEventInit&);

    bool hasData() const;
    String data() const;
    void setData(String);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    String m_data;

    friend class V8CompositionEventInit;
};

} // namespace blink

#endif // CompositionEventInit_h

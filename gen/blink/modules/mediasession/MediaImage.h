// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef MediaImage_h
#define MediaImage_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT MediaImage : public IDLDictionaryBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    MediaImage();
    virtual ~MediaImage();
    MediaImage(const MediaImage&);
    MediaImage& operator=(const MediaImage&);

    bool hasSizes() const;
    String sizes() const;
    void setSizes(String);

    bool hasSrc() const;
    String src() const;
    void setSrc(String);

    bool hasType() const;
    String type() const;
    void setType(String);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    String m_sizes;
    String m_src;
    String m_type;

    friend class V8MediaImage;
};

} // namespace blink

#endif // MediaImage_h

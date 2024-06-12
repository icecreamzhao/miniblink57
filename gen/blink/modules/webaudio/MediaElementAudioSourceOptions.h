// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef MediaElementAudioSourceOptions_h
#define MediaElementAudioSourceOptions_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class HTMLMediaElement;

class MODULES_EXPORT MediaElementAudioSourceOptions : public IDLDictionaryBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    MediaElementAudioSourceOptions();
    virtual ~MediaElementAudioSourceOptions();
    MediaElementAudioSourceOptions(const MediaElementAudioSourceOptions&);
    MediaElementAudioSourceOptions& operator=(const MediaElementAudioSourceOptions&);

    bool hasMediaElement() const;
    HTMLMediaElement* mediaElement() const;
    void setMediaElement(HTMLMediaElement*);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    Member<HTMLMediaElement> m_mediaElement;

    friend class V8MediaElementAudioSourceOptions;
};

} // namespace blink

#endif // MediaElementAudioSourceOptions_h

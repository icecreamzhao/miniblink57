// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef MediaStreamConstraints_h
#define MediaStreamConstraints_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "bindings/modules/v8/BooleanOrMediaTrackConstraints.h"
#include "modules/ModulesExport.h"
#include "modules/mediastream/MediaTrackConstraints.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT MediaStreamConstraints : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  MediaStreamConstraints();
  virtual ~MediaStreamConstraints();
  MediaStreamConstraints(const MediaStreamConstraints&);
  MediaStreamConstraints& operator=(const MediaStreamConstraints&);

  bool hasAudio() const;
  const BooleanOrMediaTrackConstraints& audio() const;
  void setAudio(const BooleanOrMediaTrackConstraints&);

  bool hasVideo() const;
  const BooleanOrMediaTrackConstraints& video() const;
  void setVideo(const BooleanOrMediaTrackConstraints&);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  BooleanOrMediaTrackConstraints m_audio;
  BooleanOrMediaTrackConstraints m_video;

  friend class V8MediaStreamConstraints;
};

}  // namespace blink

#endif  // MediaStreamConstraints_h

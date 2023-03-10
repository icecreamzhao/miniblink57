// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format on
#ifndef VideoTrackOrAudioTrackOrTextTrack_h
#define VideoTrackOrAudioTrackOrTextTrack_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class AudioTrack;
class TextTrack;
class VideoTrack;

class CORE_EXPORT VideoTrackOrAudioTrackOrTextTrack final {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    VideoTrackOrAudioTrackOrTextTrack();
    bool isNull() const { return m_type == SpecificTypeNone; }

    bool isVideoTrack() const { return m_type == SpecificTypeVideoTrack; }
    VideoTrack* getAsVideoTrack() const;
    void setVideoTrack(VideoTrack*);
    static VideoTrackOrAudioTrackOrTextTrack fromVideoTrack(VideoTrack*);

    bool isAudioTrack() const { return m_type == SpecificTypeAudioTrack; }
    AudioTrack* getAsAudioTrack() const;
    void setAudioTrack(AudioTrack*);
    static VideoTrackOrAudioTrackOrTextTrack fromAudioTrack(AudioTrack*);

    bool isTextTrack() const { return m_type == SpecificTypeTextTrack; }
    TextTrack* getAsTextTrack() const;
    void setTextTrack(TextTrack*);
    static VideoTrackOrAudioTrackOrTextTrack fromTextTrack(TextTrack*);

    VideoTrackOrAudioTrackOrTextTrack(const VideoTrackOrAudioTrackOrTextTrack&);
    ~VideoTrackOrAudioTrackOrTextTrack();
    VideoTrackOrAudioTrackOrTextTrack& operator=(const VideoTrackOrAudioTrackOrTextTrack&);
    DECLARE_TRACE();

private:
    enum SpecificTypes {
        SpecificTypeNone,
        SpecificTypeVideoTrack,
        SpecificTypeAudioTrack,
        SpecificTypeTextTrack,
    };
    SpecificTypes m_type;

    Member<VideoTrack> m_videoTrack;
    Member<AudioTrack> m_audioTrack;
    Member<TextTrack> m_textTrack;

    friend CORE_EXPORT v8::Local<v8::Value> ToV8(const VideoTrackOrAudioTrackOrTextTrack&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8VideoTrackOrAudioTrackOrTextTrack final {
public:
    CORE_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, VideoTrackOrAudioTrackOrTextTrack&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const VideoTrackOrAudioTrackOrTextTrack&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, VideoTrackOrAudioTrackOrTextTrack& impl)
{
    v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<VideoTrackOrAudioTrackOrTextTrack> {
    CORE_EXPORT static VideoTrackOrAudioTrackOrTextTrack nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

} // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::VideoTrackOrAudioTrackOrTextTrack);

#endif // VideoTrackOrAudioTrackOrTextTrack_h

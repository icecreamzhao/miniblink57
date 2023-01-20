// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebRTCOfferOptions_h
#define WebRTCOfferOptions_h

#include "WebCommon.h"
<<<<<<< HEAD
=======
#include "WebNonCopyable.h"
>>>>>>> miniblink49
#include "WebPrivatePtr.h"

namespace blink {

<<<<<<< HEAD
class RTCOfferOptionsPlatform;

class BLINK_PLATFORM_EXPORT WebRTCOfferOptions {
public:
    WebRTCOfferOptions(int32_t offerToReceiveAudio,
        int32_t offerToReceiveVideo,
        bool voiceActivityDetection,
        bool iceRestart);
=======
class RTCOfferOptions;

class WebRTCOfferOptions {
public:
    WebRTCOfferOptions() { }
>>>>>>> miniblink49
    WebRTCOfferOptions(const WebRTCOfferOptions& other) { assign(other); }
    ~WebRTCOfferOptions() { reset(); }

    WebRTCOfferOptions& operator=(const WebRTCOfferOptions& other)
    {
        assign(other);
        return *this;
    }

<<<<<<< HEAD
    void assign(const WebRTCOfferOptions&);

    void reset();
    bool isNull() const { return m_private.isNull(); }

    int32_t offerToReceiveVideo() const;
    int32_t offerToReceiveAudio() const;
    bool voiceActivityDetection() const;
    bool iceRestart() const;

#if INSIDE_BLINK
    WebRTCOfferOptions(RTCOfferOptionsPlatform*);
#endif

private:
    WebPrivatePtr<RTCOfferOptionsPlatform> m_private;
=======
    BLINK_PLATFORM_EXPORT void assign(const WebRTCOfferOptions&);

    BLINK_PLATFORM_EXPORT void reset();
    bool isNull() const { return m_private.isNull(); }

    BLINK_PLATFORM_EXPORT int32_t offerToReceiveVideo() const;
    BLINK_PLATFORM_EXPORT int32_t offerToReceiveAudio() const;
    BLINK_PLATFORM_EXPORT bool voiceActivityDetection() const;
    BLINK_PLATFORM_EXPORT bool iceRestart() const;

#if INSIDE_BLINK
    BLINK_PLATFORM_EXPORT WebRTCOfferOptions(RTCOfferOptions*);
#endif

private:
    WebPrivatePtr<RTCOfferOptions> m_private;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebRTCOfferOptions_h

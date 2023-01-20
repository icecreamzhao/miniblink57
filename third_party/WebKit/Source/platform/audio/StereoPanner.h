// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StereoPanner_h
#define StereoPanner_h

<<<<<<< HEAD
#include "platform/PlatformExport.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"

namespace blink {

class AudioBus;

// Implement the equal-power panning algorithm for mono or stereo input. See:
// https://webaudio.github.io/web-audio-api/#Spatialzation-equal-power-panning

class PLATFORM_EXPORT StereoPanner {
    USING_FAST_MALLOC(StereoPanner);
    WTF_MAKE_NONCOPYABLE(StereoPanner);

public:
    static std::unique_ptr<StereoPanner> create(float sampleRate);
    ~StereoPanner() {};

    void panWithSampleAccurateValues(const AudioBus* inputBus,
        AudioBus* outputBus,
        const float* panValues,
        size_t framesToProcess);
    void panToTargetValue(const AudioBus* inputBus,
        AudioBus* outputBus,
        float panValue,
        size_t framesToProcess);

private:
    explicit StereoPanner(float sampleRate);

=======
#include "platform/audio/Spatializer.h"

namespace blink {

// Common type of stereo panner as found in normal audio mixing equipment.
// See: http://webaudio.github.io/web-audio-api/#the-stereopannernode-interface

class PLATFORM_EXPORT StereoPanner final : public Spatializer {
public:
    explicit StereoPanner(float sampleRate);

    void panWithSampleAccurateValues(const AudioBus* inputBus, AudioBus* outputBuf, const float* panValues, size_t framesToProcess) override;
    void panToTargetValue(const AudioBus* inputBus, AudioBus* outputBuf, float panValue, size_t framesToProcess) override;

    void reset() override { }

    double tailTime() const override { return 0; }
    double latencyTime() const override { return 0; }

private:
>>>>>>> miniblink49
    bool m_isFirstRender;
    double m_smoothingConstant;

    double m_pan;
};

} // namespace blink

#endif // StereoPanner_h

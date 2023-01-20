// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StereoPannerNode_h
#define StereoPannerNode_h

<<<<<<< HEAD
#include "base/gtest_prod_util.h"
#include "modules/webaudio/AudioNode.h"
#include "modules/webaudio/AudioParam.h"
#include "platform/audio/AudioBus.h"
#include "platform/audio/StereoPanner.h"
#include <memory>

namespace blink {

class BaseAudioContext;
class StereoPannerOptions;

=======
#include "modules/webaudio/AudioNode.h"
#include "modules/webaudio/AudioParam.h"
#include "platform/audio/AudioBus.h"
#include "platform/audio/Spatializer.h"

namespace blink {

>>>>>>> miniblink49
// StereoPannerNode is an AudioNode with one input and one output. It is
// specifically designed for equal-power stereo panning.
class StereoPannerHandler final : public AudioHandler {
public:
<<<<<<< HEAD
    static PassRefPtr<StereoPannerHandler> create(AudioNode&,
        float sampleRate,
        AudioParamHandler& pan);
    ~StereoPannerHandler() override;

    void process(size_t framesToProcess) override;
    void processOnlyAudioParams(size_t framesToProcess) override;
=======
    static PassRefPtr<StereoPannerHandler> create(AudioNode&, float sampleRate, AudioParamHandler& pan);
    ~StereoPannerHandler() override;

    void process(size_t framesToProcess) override;
>>>>>>> miniblink49
    void initialize() override;

    void setChannelCount(unsigned long, ExceptionState&) final;
    void setChannelCountMode(const String&, ExceptionState&) final;

private:
    StereoPannerHandler(AudioNode&, float sampleRate, AudioParamHandler& pan);

<<<<<<< HEAD
    std::unique_ptr<StereoPanner> m_stereoPanner;
=======
    OwnPtr<Spatializer> m_stereoPanner;
>>>>>>> miniblink49
    RefPtr<AudioParamHandler> m_pan;

    AudioFloatArray m_sampleAccuratePanValues;

<<<<<<< HEAD
    FRIEND_TEST_ALL_PREFIXES(StereoPannerNodeTest, StereoPannerLifetime);
=======
    // TODO(tkent): Use FRIEND_TEST macro provided by gtest_prod.h
    friend class StereoPannerNodeTest_StereoPannerLifetime_Test;
>>>>>>> miniblink49
};

class StereoPannerNode final : public AudioNode {
    DEFINE_WRAPPERTYPEINFO();
<<<<<<< HEAD

public:
    static StereoPannerNode* create(BaseAudioContext&, ExceptionState&);
    static StereoPannerNode* create(BaseAudioContext*,
        const StereoPannerOptions&,
        ExceptionState&);
=======
public:
    static StereoPannerNode* create(AudioContext&, float sampleRate);
>>>>>>> miniblink49
    DECLARE_VIRTUAL_TRACE();

    AudioParam* pan() const;

private:
<<<<<<< HEAD
    StereoPannerNode(BaseAudioContext&);
=======
    StereoPannerNode(AudioContext&, float sampleRate);
>>>>>>> miniblink49

    Member<AudioParam> m_pan;
};

} // namespace blink

#endif // StereoPannerNode_h

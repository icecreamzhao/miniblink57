/*
 * Copyright (C) 2011, Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
<<<<<<< HEAD
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
=======
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
>>>>>>> miniblink49
 */

#ifndef DynamicsCompressorNode_h
#define DynamicsCompressorNode_h

<<<<<<< HEAD
#include "base/gtest_prod_util.h"
#include "modules/ModulesExport.h"
#include "modules/webaudio/AudioNode.h"
#include "modules/webaudio/AudioParam.h"
#include <memory>

namespace blink {

class BaseAudioContext;
class DynamicsCompressor;
class DynamicsCompressorOptions;

class MODULES_EXPORT DynamicsCompressorHandler final : public AudioHandler {
public:
    static PassRefPtr<DynamicsCompressorHandler> create(
        AudioNode&,
        float sampleRate,
        AudioParamHandler& threshold,
        AudioParamHandler& knee,
        AudioParamHandler& ratio,
        AudioParamHandler& attack,
        AudioParamHandler& release);

=======
#include "modules/ModulesExport.h"
#include "modules/webaudio/AudioNode.h"
#include "modules/webaudio/AudioParam.h"
#include "wtf/OwnPtr.h"

namespace blink {

class DynamicsCompressor;

class MODULES_EXPORT DynamicsCompressorHandler final : public AudioHandler {
public:
    static PassRefPtr<DynamicsCompressorHandler> create(AudioNode&, float sampleRate, AudioParamHandler& threshold, AudioParamHandler& knee, AudioParamHandler& ratio, AudioParamHandler& reduction, AudioParamHandler& attack, AudioParamHandler& release);
>>>>>>> miniblink49
    ~DynamicsCompressorHandler();

    // AudioHandler
    void process(size_t framesToProcess) override;
<<<<<<< HEAD
    void processOnlyAudioParams(size_t framesToProcess) override;
    void initialize() override;
    void clearInternalStateWhenDisabled() override;

    float reductionValue() const { return m_reduction; }

private:
    DynamicsCompressorHandler(AudioNode&,
        float sampleRate,
        AudioParamHandler& threshold,
        AudioParamHandler& knee,
        AudioParamHandler& ratio,
        AudioParamHandler& attack,
        AudioParamHandler& release);
    double tailTime() const override;
    double latencyTime() const override;

    std::unique_ptr<DynamicsCompressor> m_dynamicsCompressor;
    RefPtr<AudioParamHandler> m_threshold;
    RefPtr<AudioParamHandler> m_knee;
    RefPtr<AudioParamHandler> m_ratio;
    float m_reduction;
    RefPtr<AudioParamHandler> m_attack;
    RefPtr<AudioParamHandler> m_release;

    FRIEND_TEST_ALL_PREFIXES(DynamicsCompressorNodeTest, ProcessorLifetime);
=======
    void initialize() override;
    void clearInternalStateWhenDisabled() override;

private:
    DynamicsCompressorHandler(AudioNode&, float sampleRate, AudioParamHandler& threshold, AudioParamHandler& knee, AudioParamHandler& ratio, AudioParamHandler& reduction, AudioParamHandler& attack, AudioParamHandler& release);
    double tailTime() const override;
    double latencyTime() const override;

    OwnPtr<DynamicsCompressor> m_dynamicsCompressor;
    RefPtr<AudioParamHandler> m_threshold;
    RefPtr<AudioParamHandler> m_knee;
    RefPtr<AudioParamHandler> m_ratio;
    RefPtr<AudioParamHandler> m_reduction;
    RefPtr<AudioParamHandler> m_attack;
    RefPtr<AudioParamHandler> m_release;

    // TODO(tkent): Use FRIEND_TEST macro provided by gtest_prod.h
    friend class DynamicsCompressorNodeTest_ProcessorLifetime_Test;
>>>>>>> miniblink49
};

class MODULES_EXPORT DynamicsCompressorNode final : public AudioNode {
    DEFINE_WRAPPERTYPEINFO();
<<<<<<< HEAD

public:
    static DynamicsCompressorNode* create(BaseAudioContext&, ExceptionState&);
    static DynamicsCompressorNode* create(BaseAudioContext*,
        const DynamicsCompressorOptions&,
        ExceptionState&);
=======
public:
    static DynamicsCompressorNode* create(AudioContext&, float sampleRate);
>>>>>>> miniblink49
    DECLARE_VIRTUAL_TRACE();

    AudioParam* threshold() const;
    AudioParam* knee() const;
    AudioParam* ratio() const;
<<<<<<< HEAD
    float reduction() const;
=======
    AudioParam* reduction() const;
>>>>>>> miniblink49
    AudioParam* attack() const;
    AudioParam* release() const;

private:
<<<<<<< HEAD
    DynamicsCompressorNode(BaseAudioContext&);
=======
    DynamicsCompressorNode(AudioContext&, float sampleRate);
>>>>>>> miniblink49
    DynamicsCompressorHandler& dynamicsCompressorHandler() const;

    Member<AudioParam> m_threshold;
    Member<AudioParam> m_knee;
    Member<AudioParam> m_ratio;
<<<<<<< HEAD
    Member<AudioParam> m_attack;
    Member<AudioParam> m_release;

    FRIEND_TEST_ALL_PREFIXES(DynamicsCompressorNodeTest, ProcessorLifetime);
=======
    Member<AudioParam> m_reduction;
    Member<AudioParam> m_attack;
    Member<AudioParam> m_release;

    // TODO(tkent): Use FRIEND_TEST macro provided by gtest_prod.h
    friend class DynamicsCompressorNodeTest_ProcessorLifetime_Test;
>>>>>>> miniblink49
};

} // namespace blink

#endif // DynamicsCompressorNode_h

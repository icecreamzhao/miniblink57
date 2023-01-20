// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/webaudio/StereoPannerNode.h"
=======
#include "config.h"
#if ENABLE(WEB_AUDIO)
#include "modules/webaudio/StereoPannerNode.h"

>>>>>>> miniblink49
#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
<<<<<<< HEAD
#include "modules/webaudio/AudioNodeInput.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "modules/webaudio/BaseAudioContext.h"
#include "modules/webaudio/StereoPannerOptions.h"
=======
#include "modules/webaudio/AudioContext.h"
#include "modules/webaudio/AudioNodeInput.h"
#include "modules/webaudio/AudioNodeOutput.h"
>>>>>>> miniblink49
#include "platform/audio/StereoPanner.h"
#include "wtf/MathExtras.h"

namespace blink {

<<<<<<< HEAD
StereoPannerHandler::StereoPannerHandler(AudioNode& node,
    float sampleRate,
    AudioParamHandler& pan)
    : AudioHandler(NodeTypeStereoPanner, node, sampleRate)
    , m_pan(pan)
    , m_sampleAccuratePanValues(AudioUtilities::kRenderQuantumFrames)
=======
StereoPannerHandler::StereoPannerHandler(AudioNode& node, float sampleRate, AudioParamHandler& pan)
    : AudioHandler(NodeTypeStereoPanner, node, sampleRate)
    , m_pan(pan)
    , m_sampleAccuratePanValues(ProcessingSizeInFrames)
>>>>>>> miniblink49
{
    addInput();
    addOutput(2);

    // The node-specific default mixing rules declare that StereoPannerNode
    // can handle mono to stereo and stereo to stereo conversion.
    m_channelCount = 2;
<<<<<<< HEAD
    setInternalChannelCountMode(ClampedMax);
    setInternalChannelInterpretation(AudioBus::Speakers);
=======
    m_channelCountMode = ClampedMax;
    m_channelInterpretation = AudioBus::Speakers;
>>>>>>> miniblink49

    initialize();
}

<<<<<<< HEAD
PassRefPtr<StereoPannerHandler> StereoPannerHandler::create(
    AudioNode& node,
    float sampleRate,
    AudioParamHandler& pan)
=======
PassRefPtr<StereoPannerHandler> StereoPannerHandler::create(AudioNode& node, float sampleRate, AudioParamHandler& pan)
>>>>>>> miniblink49
{
    return adoptRef(new StereoPannerHandler(node, sampleRate, pan));
}

StereoPannerHandler::~StereoPannerHandler()
{
    uninitialize();
}

void StereoPannerHandler::process(size_t framesToProcess)
{
    AudioBus* outputBus = output(0).bus();

    if (!isInitialized() || !input(0).isConnected() || !m_stereoPanner.get()) {
        outputBus->zero();
        return;
    }

    AudioBus* inputBus = input(0).bus();
    if (!inputBus) {
        outputBus->zero();
        return;
    }

    if (m_pan->hasSampleAccurateValues()) {
        // Apply sample-accurate panning specified by AudioParam automation.
<<<<<<< HEAD
        DCHECK_LE(framesToProcess, m_sampleAccuratePanValues.size());
        if (framesToProcess <= m_sampleAccuratePanValues.size()) {
            float* panValues = m_sampleAccuratePanValues.data();
            m_pan->calculateSampleAccurateValues(panValues, framesToProcess);
            m_stereoPanner->panWithSampleAccurateValues(inputBus, outputBus,
                panValues, framesToProcess);
        }
    } else {
        m_stereoPanner->panToTargetValue(inputBus, outputBus, m_pan->value(),
            framesToProcess);
    }
}

void StereoPannerHandler::processOnlyAudioParams(size_t framesToProcess)
{
    float values[AudioUtilities::kRenderQuantumFrames];
    DCHECK_LE(framesToProcess, AudioUtilities::kRenderQuantumFrames);

    m_pan->calculateSampleAccurateValues(values, framesToProcess);
}

=======
        ASSERT(framesToProcess <= m_sampleAccuratePanValues.size());
        if (framesToProcess <= m_sampleAccuratePanValues.size()) {
            float* panValues = m_sampleAccuratePanValues.data();
            m_pan->calculateSampleAccurateValues(panValues, framesToProcess);
            m_stereoPanner->panWithSampleAccurateValues(inputBus, outputBus, panValues, framesToProcess);
        }
    } else {
        m_stereoPanner->panToTargetValue(inputBus, outputBus, m_pan->value(), framesToProcess);
    }
}

>>>>>>> miniblink49
void StereoPannerHandler::initialize()
{
    if (isInitialized())
        return;

<<<<<<< HEAD
    m_stereoPanner = StereoPanner::create(sampleRate());
=======
    m_stereoPanner = Spatializer::create(Spatializer::PanningModelEqualPower, sampleRate());
>>>>>>> miniblink49

    AudioHandler::initialize();
}

<<<<<<< HEAD
void StereoPannerHandler::setChannelCount(unsigned long channelCount,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());
    BaseAudioContext::AutoLocker locker(context());
=======
void StereoPannerHandler::setChannelCount(unsigned long channelCount, ExceptionState& exceptionState)
{
    ASSERT(isMainThread());
    AudioContext::AutoLocker locker(context());
>>>>>>> miniblink49

    // A PannerNode only supports 1 or 2 channels
    if (channelCount > 0 && channelCount <= 2) {
        if (m_channelCount != channelCount) {
            m_channelCount = channelCount;
<<<<<<< HEAD
            if (internalChannelCountMode() != Max)
=======
            if (m_channelCountMode != Max)
>>>>>>> miniblink49
                updateChannelsForInputs();
        }
    } else {
        exceptionState.throwDOMException(
            NotSupportedError,
            ExceptionMessages::indexOutsideRange<unsigned long>(
<<<<<<< HEAD
                "channelCount", channelCount, 1, ExceptionMessages::InclusiveBound,
                2, ExceptionMessages::InclusiveBound));
    }
}

void StereoPannerHandler::setChannelCountMode(const String& mode,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());
    BaseAudioContext::AutoLocker locker(context());

    ChannelCountMode oldMode = internalChannelCountMode();
=======
                "channelCount",
                channelCount,
                1,
                ExceptionMessages::InclusiveBound,
                2,
                ExceptionMessages::InclusiveBound));
    }
}

void StereoPannerHandler::setChannelCountMode(const String& mode, ExceptionState& exceptionState)
{
    ASSERT(isMainThread());
    AudioContext::AutoLocker locker(context());

    ChannelCountMode oldMode = m_channelCountMode;
>>>>>>> miniblink49

    if (mode == "clamped-max") {
        m_newChannelCountMode = ClampedMax;
    } else if (mode == "explicit") {
        m_newChannelCountMode = Explicit;
    } else if (mode == "max") {
        // This is not supported for a StereoPannerNode, which can only handle
        // 1 or 2 channels.
<<<<<<< HEAD
        exceptionState.throwDOMException(NotSupportedError,
            "StereoPanner: 'max' is not allowed");
=======
        exceptionState.throwDOMException(
            NotSupportedError,
                "StereoPanner: 'max' is not allowed");
>>>>>>> miniblink49
        m_newChannelCountMode = oldMode;
    } else {
        // Do nothing for other invalid values.
        m_newChannelCountMode = oldMode;
    }

    if (m_newChannelCountMode != oldMode)
        context()->deferredTaskHandler().addChangedChannelCountMode(this);
}

// ----------------------------------------------------------------

<<<<<<< HEAD
StereoPannerNode::StereoPannerNode(BaseAudioContext& context)
    : AudioNode(context)
    , m_pan(AudioParam::create(context, ParamTypeStereoPannerPan, 0, -1, 1))
{
    setHandler(StereoPannerHandler::create(*this, context.sampleRate(),
        m_pan->handler()));
}

StereoPannerNode* StereoPannerNode::create(BaseAudioContext& context,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    if (context.isContextClosed()) {
        context.throwExceptionForClosedState(exceptionState);
        return nullptr;
    }

    return new StereoPannerNode(context);
}

StereoPannerNode* StereoPannerNode::create(BaseAudioContext* context,
    const StereoPannerOptions& options,
    ExceptionState& exceptionState)
{
    StereoPannerNode* node = create(*context, exceptionState);

    if (!node)
        return nullptr;

    node->handleChannelOptions(options, exceptionState);

    if (options.hasPan())
        node->pan()->setValue(options.pan());

    return node;
=======
StereoPannerNode::StereoPannerNode(AudioContext& context, float sampleRate)
    : AudioNode(context)
    , m_pan(AudioParam::create(context, 0))
{
    setHandler(StereoPannerHandler::create(*this, sampleRate, m_pan->handler()));
}

StereoPannerNode* StereoPannerNode::create(AudioContext& context, float sampleRate)
{
    return new StereoPannerNode(context, sampleRate);
>>>>>>> miniblink49
}

DEFINE_TRACE(StereoPannerNode)
{
    visitor->trace(m_pan);
    AudioNode::trace(visitor);
}

AudioParam* StereoPannerNode::pan() const
{
    return m_pan;
}

} // namespace blink
<<<<<<< HEAD
=======

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49

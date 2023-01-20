/*
 * Copyright (C) 2012, Google Inc. All rights reserved.
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
 */

#include "modules/webaudio/AudioScheduledSourceNode.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContextTask.h"
#include "core/dom/TaskRunnerHelper.h"
#include "modules/EventModules.h"
#include "modules/webaudio/BaseAudioContext.h"
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
 */

#include "config.h"
#if ENABLE(WEB_AUDIO)
#include "modules/webaudio/AudioScheduledSourceNode.h"

#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/CrossThreadTask.h"
#include "core/dom/ExceptionCode.h"
#include "modules/EventModules.h"
#include "modules/webaudio/AudioContext.h"
>>>>>>> miniblink49
#include "platform/audio/AudioUtilities.h"
#include "wtf/MathExtras.h"
#include <algorithm>

namespace blink {

const double AudioScheduledSourceHandler::UnknownTime = -1;

<<<<<<< HEAD
AudioScheduledSourceHandler::AudioScheduledSourceHandler(NodeType nodeType,
    AudioNode& node,
    float sampleRate)
    : AudioHandler(nodeType, node, sampleRate)
    , m_startTime(0)
    , m_endTime(UnknownTime)
    , m_playbackState(UNSCHEDULED_STATE)
=======
AudioScheduledSourceHandler::AudioScheduledSourceHandler(NodeType nodeType, AudioNode& node, float sampleRate)
    : AudioHandler(nodeType, node, sampleRate)
    , m_playbackState(UNSCHEDULED_STATE)
    , m_startTime(0)
    , m_endTime(UnknownTime)
    , m_hasEndedListener(false)
>>>>>>> miniblink49
{
}

void AudioScheduledSourceHandler::updateSchedulingInfo(
<<<<<<< HEAD
    size_t quantumFrameSize,
    AudioBus* outputBus,
    size_t& quantumFrameOffset,
    size_t& nonSilentFramesToProcess,
    double& startFrameOffset)
{
    DCHECK(outputBus);
    if (!outputBus)
        return;

    DCHECK_EQ(quantumFrameSize,
        static_cast<size_t>(AudioUtilities::kRenderQuantumFrames));
    if (quantumFrameSize != AudioUtilities::kRenderQuantumFrames)
=======
    size_t quantumFrameSize, AudioBus* outputBus, size_t& quantumFrameOffset, size_t& nonSilentFramesToProcess)
{
    ASSERT(outputBus);
    if (!outputBus)
        return;

    ASSERT(quantumFrameSize == ProcessingSizeInFrames);
    if (quantumFrameSize != ProcessingSizeInFrames)
>>>>>>> miniblink49
        return;

    double sampleRate = this->sampleRate();

    // quantumStartFrame     : Start frame of the current time quantum.
    // quantumEndFrame       : End frame of the current time quantum.
    // startFrame            : Start frame for this source.
    // endFrame              : End frame for this source.
    size_t quantumStartFrame = context()->currentSampleFrame();
    size_t quantumEndFrame = quantumStartFrame + quantumFrameSize;
    size_t startFrame = AudioUtilities::timeToSampleFrame(m_startTime, sampleRate);
    size_t endFrame = m_endTime == UnknownTime ? 0 : AudioUtilities::timeToSampleFrame(m_endTime, sampleRate);

<<<<<<< HEAD
    // If we know the end time and it's already passed, then don't bother doing
    // any more rendering this cycle.
    if (m_endTime != UnknownTime && endFrame <= quantumStartFrame)
        finish();

    PlaybackState state = playbackState();

    if (state == UNSCHEDULED_STATE || state == FINISHED_STATE || startFrame >= quantumEndFrame) {
=======
    // If we know the end time and it's already passed, then don't bother doing any more rendering this cycle.
    if (m_endTime != UnknownTime && endFrame <= quantumStartFrame)
        finish();

    if (m_playbackState == UNSCHEDULED_STATE || m_playbackState == FINISHED_STATE || startFrame >= quantumEndFrame) {
>>>>>>> miniblink49
        // Output silence.
        outputBus->zero();
        nonSilentFramesToProcess = 0;
        return;
    }

    // Check if it's time to start playing.
<<<<<<< HEAD
    if (state == SCHEDULED_STATE) {
        // Increment the active source count only if we're transitioning from
        // SCHEDULED_STATE to PLAYING_STATE.
        setPlaybackState(PLAYING_STATE);
        // Determine the offset of the true start time from the starting frame.
        startFrameOffset = m_startTime * sampleRate - startFrame;
    } else {
        startFrameOffset = 0;
=======
    if (m_playbackState == SCHEDULED_STATE) {
        // Increment the active source count only if we're transitioning from SCHEDULED_STATE to PLAYING_STATE.
        m_playbackState = PLAYING_STATE;
>>>>>>> miniblink49
    }

    quantumFrameOffset = startFrame > quantumStartFrame ? startFrame - quantumStartFrame : 0;
    quantumFrameOffset = std::min(quantumFrameOffset, quantumFrameSize); // clamp to valid range
    nonSilentFramesToProcess = quantumFrameSize - quantumFrameOffset;

    if (!nonSilentFramesToProcess) {
        // Output silence.
        outputBus->zero();
        return;
    }

    // Handle silence before we start playing.
<<<<<<< HEAD
    // Zero any initial frames representing silence leading up to a rendering
    // start time in the middle of the quantum.
    if (quantumFrameOffset) {
        for (unsigned i = 0; i < outputBus->numberOfChannels(); ++i)
            memset(outputBus->channel(i)->mutableData(), 0,
                sizeof(float) * quantumFrameOffset);
    }

    // Handle silence after we're done playing.
    // If the end time is somewhere in the middle of this time quantum, then zero
    // out the frames from the end time to the very end of the quantum.
=======
    // Zero any initial frames representing silence leading up to a rendering start time in the middle of the quantum.
    if (quantumFrameOffset) {
        for (unsigned i = 0; i < outputBus->numberOfChannels(); ++i)
            memset(outputBus->channel(i)->mutableData(), 0, sizeof(float) * quantumFrameOffset);
    }

    // Handle silence after we're done playing.
    // If the end time is somewhere in the middle of this time quantum, then zero out the
    // frames from the end time to the very end of the quantum.
>>>>>>> miniblink49
    if (m_endTime != UnknownTime && endFrame >= quantumStartFrame && endFrame < quantumEndFrame) {
        size_t zeroStartFrame = endFrame - quantumStartFrame;
        size_t framesToZero = quantumFrameSize - zeroStartFrame;

        bool isSafe = zeroStartFrame < quantumFrameSize && framesToZero <= quantumFrameSize && zeroStartFrame + framesToZero <= quantumFrameSize;
<<<<<<< HEAD
        DCHECK(isSafe);
=======
        ASSERT(isSafe);
>>>>>>> miniblink49

        if (isSafe) {
            if (framesToZero > nonSilentFramesToProcess)
                nonSilentFramesToProcess = 0;
            else
                nonSilentFramesToProcess -= framesToZero;

            for (unsigned i = 0; i < outputBus->numberOfChannels(); ++i)
<<<<<<< HEAD
                memset(outputBus->channel(i)->mutableData() + zeroStartFrame, 0,
                    sizeof(float) * framesToZero);
=======
                memset(outputBus->channel(i)->mutableData() + zeroStartFrame, 0, sizeof(float) * framesToZero);
>>>>>>> miniblink49
        }

        finish();
    }

    return;
}

<<<<<<< HEAD
void AudioScheduledSourceHandler::start(double when,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    context()->maybeRecordStartAttempt();

    if (playbackState() != UNSCHEDULED_STATE) {
        exceptionState.throwDOMException(InvalidStateError,
=======
void AudioScheduledSourceHandler::start(double when, ExceptionState& exceptionState)
{
    ASSERT(isMainThread());

    if (m_playbackState != UNSCHEDULED_STATE) {
        exceptionState.throwDOMException(
            InvalidStateError,
>>>>>>> miniblink49
            "cannot call start more than once.");
        return;
    }

    if (when < 0) {
        exceptionState.throwDOMException(
            InvalidAccessError,
<<<<<<< HEAD
            ExceptionMessages::indexExceedsMinimumBound("start time", when, 0.0));
        return;
    }

    // The node is started. Add a reference to keep us alive so that audio will
    // eventually get played even if Javascript should drop all references to this
    // node. The reference will get dropped when the source has finished playing.
    context()->notifySourceNodeStartedProcessing(node());

    // This synchronizes with process(). updateSchedulingInfo will read some of
    // the variables being set here.
    MutexLocker processLocker(m_processLock);

=======
            ExceptionMessages::indexExceedsMinimumBound(
                "start time",
                when,
                0.0));
        return;
    }

    // The node is started. Add a reference to keep us alive so that audio will eventually get
    // played even if Javascript should drop all references to this node. The reference will get
    // dropped when the source has finished playing.
    context()->notifySourceNodeStartedProcessing(node());

>>>>>>> miniblink49
    // If |when| < currentTime, the source must start now according to the spec.
    // So just set startTime to currentTime in this case to start the source now.
    m_startTime = std::max(when, context()->currentTime());

<<<<<<< HEAD
    setPlaybackState(SCHEDULED_STATE);
}

void AudioScheduledSourceHandler::stop(double when,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    if (playbackState() == UNSCHEDULED_STATE) {
        exceptionState.throwDOMException(
            InvalidStateError, "cannot call stop without calling start first.");
=======
    m_playbackState = SCHEDULED_STATE;
}

void AudioScheduledSourceHandler::stop(double when, ExceptionState& exceptionState)
{
    ASSERT(isMainThread());

    if (m_playbackState == UNSCHEDULED_STATE) {
        exceptionState.throwDOMException(
            InvalidStateError,
            "cannot call stop without calling start first.");
>>>>>>> miniblink49
        return;
    }

    if (when < 0) {
        exceptionState.throwDOMException(
            InvalidAccessError,
<<<<<<< HEAD
            ExceptionMessages::indexExceedsMinimumBound("stop time", when, 0.0));
        return;
    }

    // This synchronizes with process()
    MutexLocker processLocker(m_processLock);

    // stop() can be called more than once, with the last call to stop taking
    // effect, unless the source has already stopped due to earlier calls to stop.
    // No exceptions are thrown in any case.
=======
            ExceptionMessages::indexExceedsMinimumBound(
                "stop time",
                when,
                0.0));
        return;
    }

    // stop() can be called more than once, with the last call to stop taking effect, unless the
    // source has already stopped due to earlier calls to stop. No exceptions are thrown in any
    // case.
>>>>>>> miniblink49
    when = std::max(0.0, when);
    m_endTime = when;
}

void AudioScheduledSourceHandler::finishWithoutOnEnded()
{
<<<<<<< HEAD
    if (playbackState() != FINISHED_STATE) {
        // Let the context dereference this AudioNode.
        context()->notifySourceNodeFinishedProcessing(this);
        setPlaybackState(FINISHED_STATE);
    }
}

=======
    if (m_playbackState != FINISHED_STATE) {
        // Let the context dereference this AudioNode.
        context()->notifySourceNodeFinishedProcessing(this);
        m_playbackState = FINISHED_STATE;
    }
}
>>>>>>> miniblink49
void AudioScheduledSourceHandler::finish()
{
    finishWithoutOnEnded();

<<<<<<< HEAD
    if (context()->getExecutionContext()) {
        context()->getExecutionContext()->postTask(
            TaskType::MediaElementEvent, BLINK_FROM_HERE,
            createCrossThreadTask(&AudioScheduledSourceHandler::notifyEnded,
                PassRefPtr<AudioScheduledSourceHandler>(this)));
=======
    if (m_hasEndedListener && context()->executionContext()) {
        context()->executionContext()->postTask(FROM_HERE, createCrossThreadTask(&AudioScheduledSourceHandler::notifyEnded, PassRefPtr<AudioScheduledSourceHandler>(this)));
>>>>>>> miniblink49
    }
}

void AudioScheduledSourceHandler::notifyEnded()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    if (node())
        node()->dispatchEvent(Event::create(EventTypeNames::ended));
}

// ----------------------------------------------------------------

<<<<<<< HEAD
AudioScheduledSourceNode::AudioScheduledSourceNode(BaseAudioContext& context)
    : AudioNode(context)
{
}

AudioScheduledSourceHandler&
AudioScheduledSourceNode::audioScheduledSourceHandler() const
=======
AudioScheduledSourceNode::AudioScheduledSourceNode(AudioContext& context)
    : AudioSourceNode(context)
{
}

AudioScheduledSourceHandler& AudioScheduledSourceNode::audioScheduledSourceHandler() const
>>>>>>> miniblink49
{
    return static_cast<AudioScheduledSourceHandler&>(handler());
}

void AudioScheduledSourceNode::start(ExceptionState& exceptionState)
{
    start(0, exceptionState);
}

<<<<<<< HEAD
void AudioScheduledSourceNode::start(double when,
    ExceptionState& exceptionState)
=======
void AudioScheduledSourceNode::start(double when, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    audioScheduledSourceHandler().start(when, exceptionState);
}

void AudioScheduledSourceNode::stop(ExceptionState& exceptionState)
{
    stop(0, exceptionState);
}

<<<<<<< HEAD
void AudioScheduledSourceNode::stop(double when,
    ExceptionState& exceptionState)
=======
void AudioScheduledSourceNode::stop(double when, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    audioScheduledSourceHandler().stop(when, exceptionState);
}

EventListener* AudioScheduledSourceNode::onended()
{
    return getAttributeEventListener(EventTypeNames::ended);
}

<<<<<<< HEAD
void AudioScheduledSourceNode::setOnended(EventListener* listener)
{
    setAttributeEventListener(EventTypeNames::ended, listener);
}

bool AudioScheduledSourceNode::hasPendingActivity() const
{
    // To avoid the leak, a node should be collected regardless of its
    // playback state if the context is closed.
    if (context()->isContextClosed())
        return false;

    // If a node is scheduled or playing, do not collect the node prematurely
    // even its reference is out of scope. Then fire onended event if assigned.
    return audioScheduledSourceHandler().isPlayingOrScheduled();
}

} // namespace blink
=======
void AudioScheduledSourceNode::setOnended(PassRefPtr<EventListener> listener)
{
    audioScheduledSourceHandler().setHasEndedListener();
    setAttributeEventListener(EventTypeNames::ended, listener);
}

} // namespace blink

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49

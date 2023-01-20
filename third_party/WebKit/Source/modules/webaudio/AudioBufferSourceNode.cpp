/*
 * Copyright (C) 2010, Google Inc. All rights reserved.
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

#include "modules/webaudio/AudioBufferSourceNode.h"
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
#include "modules/webaudio/AudioBufferSourceNode.h"

>>>>>>> miniblink49
#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "core/frame/UseCounter.h"
<<<<<<< HEAD
#include "modules/webaudio/AudioBufferSourceOptions.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "modules/webaudio/BaseAudioContext.h"
#include "platform/audio/AudioUtilities.h"
#include "wtf/MathExtras.h"
#include "wtf/PtrUtil.h"
=======
#include "modules/webaudio/AudioContext.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "platform/FloatConversion.h"
#include "platform/audio/AudioUtilities.h"
#include "wtf/MainThread.h"
#include "wtf/MathExtras.h"
>>>>>>> miniblink49
#include <algorithm>

namespace blink {

const double DefaultGrainDuration = 0.020; // 20ms

// Arbitrary upper limit on playback rate.
<<<<<<< HEAD
// Higher than expected rates can be useful when playing back oversampled
// buffers to minimize linear interpolation aliasing.
const double MaxRate = 1024;

// Number of extra frames to use when determining if a source node can be
// stopped.  This should be at least one rendering quantum, but we add one more
// quantum for good measure.  This doesn't need to be extra precise, just more
// than one rendering quantum.  See |handleStoppableSourceNode()|.
// FIXME: Expose the rendering quantum somehow instead of hardwiring a value
// here.
const int kExtraStopFrames = 256;

AudioBufferSourceHandler::AudioBufferSourceHandler(
    AudioNode& node,
    float sampleRate,
    AudioParamHandler& playbackRate,
    AudioParamHandler& detune)
=======
// Higher than expected rates can be useful when playing back oversampled buffers
// to minimize linear interpolation aliasing.
const double MaxRate = 1024;

// Number of extra frames to use when determining if a source node can be stopped.  This should be
// at least one rendering quantum, but we add one more quantum for good measure.  This doesn't need
// to be extra precise, just more than one rendering quantum.  See |handleStoppableSourceNode()|.
// FIXME: Expose the rendering quantum somehow instead of hardwiring a value here.
const int kExtraStopFrames = 256;

AudioBufferSourceHandler::AudioBufferSourceHandler(AudioNode& node, float sampleRate, AudioParamHandler& playbackRate, AudioParamHandler& detune)
>>>>>>> miniblink49
    : AudioScheduledSourceHandler(NodeTypeAudioBufferSource, node, sampleRate)
    , m_buffer(nullptr)
    , m_playbackRate(playbackRate)
    , m_detune(detune)
    , m_isLooping(false)
<<<<<<< HEAD
    , m_didSetLooping(false)
=======
>>>>>>> miniblink49
    , m_loopStart(0)
    , m_loopEnd(0)
    , m_virtualReadIndex(0)
    , m_isGrain(false)
    , m_grainOffset(0.0)
    , m_grainDuration(DefaultGrainDuration)
    , m_minPlaybackRate(1.0)
{
    // Default to mono. A call to setBuffer() will set the number of output
    // channels to that of the buffer.
    addOutput(1);

    initialize();
}

<<<<<<< HEAD
PassRefPtr<AudioBufferSourceHandler> AudioBufferSourceHandler::create(
    AudioNode& node,
    float sampleRate,
    AudioParamHandler& playbackRate,
    AudioParamHandler& detune)
{
    return adoptRef(
        new AudioBufferSourceHandler(node, sampleRate, playbackRate, detune));
=======
PassRefPtr<AudioBufferSourceHandler> AudioBufferSourceHandler::create(AudioNode& node, float sampleRate, AudioParamHandler& playbackRate, AudioParamHandler& detune)
{
    return adoptRef(new AudioBufferSourceHandler(node, sampleRate, playbackRate, detune));
>>>>>>> miniblink49
}

AudioBufferSourceHandler::~AudioBufferSourceHandler()
{
<<<<<<< HEAD
=======
    clearPannerNode();
>>>>>>> miniblink49
    uninitialize();
}

void AudioBufferSourceHandler::process(size_t framesToProcess)
{
    AudioBus* outputBus = output(0).bus();

    if (!isInitialized()) {
        outputBus->zero();
        return;
    }

    // The audio thread can't block on this lock, so we call tryLock() instead.
    MutexTryLocker tryLocker(m_processLock);
    if (tryLocker.locked()) {
        if (!buffer()) {
            outputBus->zero();
            return;
        }

<<<<<<< HEAD
        // After calling setBuffer() with a buffer having a different number of
        // channels, there can in rare cases be a slight delay before the output bus
        // is updated to the new number of channels because of use of tryLocks() in
        // the context's updating system.  In this case, if the the buffer has just
        // been changed and we're not quite ready yet, then just output silence.
=======
        // After calling setBuffer() with a buffer having a different number of channels, there can in rare cases be a slight delay
        // before the output bus is updated to the new number of channels because of use of tryLocks() in the context's updating system.
        // In this case, if the the buffer has just been changed and we're not quite ready yet, then just output silence.
>>>>>>> miniblink49
        if (numberOfChannels() != buffer()->numberOfChannels()) {
            outputBus->zero();
            return;
        }

        size_t quantumFrameOffset;
        size_t bufferFramesToProcess;
<<<<<<< HEAD
        double startTimeOffset;

        updateSchedulingInfo(framesToProcess, outputBus, quantumFrameOffset,
            bufferFramesToProcess, startTimeOffset);
=======

        updateSchedulingInfo(framesToProcess, outputBus, quantumFrameOffset, bufferFramesToProcess);
>>>>>>> miniblink49

        if (!bufferFramesToProcess) {
            outputBus->zero();
            return;
        }

        for (unsigned i = 0; i < outputBus->numberOfChannels(); ++i)
            m_destinationChannels[i] = outputBus->channel(i)->mutableData();

        // Render by reading directly from the buffer.
<<<<<<< HEAD
        if (!renderFromBuffer(outputBus, quantumFrameOffset,
                bufferFramesToProcess)) {
=======
        if (!renderFromBuffer(outputBus, quantumFrameOffset, bufferFramesToProcess)) {
>>>>>>> miniblink49
            outputBus->zero();
            return;
        }

        outputBus->clearSilentFlag();
    } else {
<<<<<<< HEAD
        // Too bad - the tryLock() failed.  We must be in the middle of changing
        // buffers and were already outputting silence anyway.
=======
        // Too bad - the tryLock() failed.  We must be in the middle of changing buffers and were already outputting silence anyway.
>>>>>>> miniblink49
        outputBus->zero();
    }
}

// Returns true if we're finished.
<<<<<<< HEAD
bool AudioBufferSourceHandler::renderSilenceAndFinishIfNotLooping(
    AudioBus*,
    unsigned index,
    size_t framesToProcess)
=======
bool AudioBufferSourceHandler::renderSilenceAndFinishIfNotLooping(AudioBus*, unsigned index, size_t framesToProcess)
>>>>>>> miniblink49
{
    if (!loop()) {
        // If we're not looping, then stop playing when we get to the end.

        if (framesToProcess > 0) {
<<<<<<< HEAD
            // We're not looping and we've reached the end of the sample data, but we
            // still need to provide more output, so generate silence for the
            // remaining.
            for (unsigned i = 0; i < numberOfChannels(); ++i)
                memset(m_destinationChannels[i] + index, 0,
                    sizeof(float) * framesToProcess);
=======
            // We're not looping and we've reached the end of the sample data, but we still need to provide more output,
            // so generate silence for the remaining.
            for (unsigned i = 0; i < numberOfChannels(); ++i)
                memset(m_destinationChannels[i] + index, 0, sizeof(float) * framesToProcess);
>>>>>>> miniblink49
        }

        finish();
        return true;
    }
    return false;
}

<<<<<<< HEAD
bool AudioBufferSourceHandler::renderFromBuffer(AudioBus* bus,
    unsigned destinationFrameOffset,
    size_t numberOfFrames)
{
    DCHECK(context()->isAudioThread());

    // Basic sanity checking
    DCHECK(bus);
    DCHECK(buffer());
=======
bool AudioBufferSourceHandler::renderFromBuffer(AudioBus* bus, unsigned destinationFrameOffset, size_t numberOfFrames)
{
    ASSERT(context()->isAudioThread());

    // Basic sanity checking
    ASSERT(bus);
    ASSERT(buffer());
>>>>>>> miniblink49
    if (!bus || !buffer())
        return false;

    unsigned numberOfChannels = this->numberOfChannels();
    unsigned busNumberOfChannels = bus->numberOfChannels();

    bool channelCountGood = numberOfChannels && numberOfChannels == busNumberOfChannels;
<<<<<<< HEAD
    DCHECK(channelCountGood);
=======
    ASSERT(channelCountGood);
>>>>>>> miniblink49
    if (!channelCountGood)
        return false;

    // Sanity check destinationFrameOffset, numberOfFrames.
    size_t destinationLength = bus->length();

<<<<<<< HEAD
    bool isLengthGood = destinationLength <= AudioUtilities::kRenderQuantumFrames && numberOfFrames <= AudioUtilities::kRenderQuantumFrames;
    DCHECK(isLengthGood);
=======
    bool isLengthGood = destinationLength <= 4096 && numberOfFrames <= 4096;
    ASSERT(isLengthGood);
>>>>>>> miniblink49
    if (!isLengthGood)
        return false;

    bool isOffsetGood = destinationFrameOffset <= destinationLength && destinationFrameOffset + numberOfFrames <= destinationLength;
<<<<<<< HEAD
    DCHECK(isOffsetGood);
=======
    ASSERT(isOffsetGood);
>>>>>>> miniblink49
    if (!isOffsetGood)
        return false;

    // Potentially zero out initial frames leading up to the offset.
    if (destinationFrameOffset) {
        for (unsigned i = 0; i < numberOfChannels; ++i)
<<<<<<< HEAD
            memset(m_destinationChannels[i], 0,
                sizeof(float) * destinationFrameOffset);
=======
            memset(m_destinationChannels[i], 0, sizeof(float) * destinationFrameOffset);
>>>>>>> miniblink49
    }

    // Offset the pointers to the correct offset frame.
    unsigned writeIndex = destinationFrameOffset;

    size_t bufferLength = buffer()->length();
    double bufferSampleRate = buffer()->sampleRate();

    // Avoid converting from time to sample-frames twice by computing
    // the grain end time first before computing the sample frame.
<<<<<<< HEAD
    unsigned endFrame = m_isGrain ? AudioUtilities::timeToSampleFrame(
                            m_grainOffset + m_grainDuration, bufferSampleRate)
                                  : bufferLength;

    // This is a HACK to allow for HRTF tail-time - avoids glitch at end.
    // FIXME: implement tailTime for each AudioNode for a more general solution to
    // this problem, https://bugs.webkit.org/show_bug.cgi?id=77224
=======
    unsigned endFrame = m_isGrain ? AudioUtilities::timeToSampleFrame(m_grainOffset + m_grainDuration, bufferSampleRate) : bufferLength;

    // This is a HACK to allow for HRTF tail-time - avoids glitch at end.
    // FIXME: implement tailTime for each AudioNode for a more general solution to this problem.
    // https://bugs.webkit.org/show_bug.cgi?id=77224
>>>>>>> miniblink49
    if (m_isGrain)
        endFrame += 512;

    // Do some sanity checking.
    if (endFrame > bufferLength)
        endFrame = bufferLength;

<<<<<<< HEAD
    // If the .loop attribute is true, then values of
    // m_loopStart == 0 && m_loopEnd == 0 implies that we should use the entire
    // buffer as the loop, otherwise use the loop values in m_loopStart and
    // m_loopEnd.
=======
    // If the .loop attribute is true, then values of m_loopStart == 0 && m_loopEnd == 0 implies
    // that we should use the entire buffer as the loop, otherwise use the loop values in m_loopStart and m_loopEnd.
>>>>>>> miniblink49
    double virtualEndFrame = endFrame;
    double virtualDeltaFrames = endFrame;

    if (loop() && (m_loopStart || m_loopEnd) && m_loopStart >= 0 && m_loopEnd > 0 && m_loopStart < m_loopEnd) {
        // Convert from seconds to sample-frames.
        double loopStartFrame = m_loopStart * buffer()->sampleRate();
        double loopEndFrame = m_loopEnd * buffer()->sampleRate();

        virtualEndFrame = std::min(loopEndFrame, virtualEndFrame);
        virtualDeltaFrames = virtualEndFrame - loopStartFrame;
    }

<<<<<<< HEAD
    // If we're looping and the offset (virtualReadIndex) is past the end of the
    // loop, wrap back to the beginning of the loop. For other cases, nothing
    // needs to be done.
    if (loop() && m_virtualReadIndex >= virtualEndFrame) {
        m_virtualReadIndex = (m_loopStart < 0) ? 0 : (m_loopStart * buffer()->sampleRate());
        m_virtualReadIndex = std::min(m_virtualReadIndex, static_cast<double>(bufferLength - 1));
    }
=======
    // If we're looping and the offset (virtualReadIndex) is past the end of the loop, wrap back to
    // the beginning of the loop. For other cases, nothing needs to be done.
    if (loop() && m_virtualReadIndex >= virtualEndFrame)
        m_virtualReadIndex = (m_loopStart < 0) ? 0 : (m_loopStart * buffer()->sampleRate());
>>>>>>> miniblink49

    double computedPlaybackRate = computePlaybackRate();

    // Sanity check that our playback rate isn't larger than the loop size.
    if (computedPlaybackRate > virtualDeltaFrames)
        return false;

    // Get local copy.
    double virtualReadIndex = m_virtualReadIndex;

<<<<<<< HEAD
    // Render loop - reading from the source buffer to the destination using
    // linear interpolation.
=======
    // Render loop - reading from the source buffer to the destination using linear interpolation.
>>>>>>> miniblink49
    int framesToProcess = numberOfFrames;

    const float** sourceChannels = m_sourceChannels.get();
    float** destinationChannels = m_destinationChannels.get();

<<<<<<< HEAD
    DCHECK_GE(virtualReadIndex, 0);
    DCHECK_GE(virtualDeltaFrames, 0);
    DCHECK_GE(virtualEndFrame, 0);

    // Optimize for the very common case of playing back with
    // computedPlaybackRate == 1.  We can avoid the linear interpolation.
    if (computedPlaybackRate == 1 && virtualReadIndex == floor(virtualReadIndex) && virtualDeltaFrames == floor(virtualDeltaFrames) && virtualEndFrame == floor(virtualEndFrame)) {
=======
    ASSERT(virtualReadIndex >= 0);
    ASSERT(virtualDeltaFrames >= 0);
    ASSERT(virtualEndFrame >= 0);

    // Optimize for the very common case of playing back with computedPlaybackRate == 1.
    // We can avoid the linear interpolation.
    if (computedPlaybackRate == 1 && virtualReadIndex == floor(virtualReadIndex)
        && virtualDeltaFrames == floor(virtualDeltaFrames)
        && virtualEndFrame == floor(virtualEndFrame)) {
>>>>>>> miniblink49
        unsigned readIndex = static_cast<unsigned>(virtualReadIndex);
        unsigned deltaFrames = static_cast<unsigned>(virtualDeltaFrames);
        endFrame = static_cast<unsigned>(virtualEndFrame);
        while (framesToProcess > 0) {
            int framesToEnd = endFrame - readIndex;
            int framesThisTime = std::min(framesToProcess, framesToEnd);
            framesThisTime = std::max(0, framesThisTime);

<<<<<<< HEAD
            DCHECK_LE(writeIndex + framesThisTime, destinationLength);
            DCHECK_LE(readIndex + framesThisTime, bufferLength);

            for (unsigned i = 0; i < numberOfChannels; ++i)
                memcpy(destinationChannels[i] + writeIndex,
                    sourceChannels[i] + readIndex, sizeof(float) * framesThisTime);
=======
            for (unsigned i = 0; i < numberOfChannels; ++i)
                memcpy(destinationChannels[i] + writeIndex, sourceChannels[i] + readIndex, sizeof(float) * framesThisTime);
>>>>>>> miniblink49

            writeIndex += framesThisTime;
            readIndex += framesThisTime;
            framesToProcess -= framesThisTime;

<<<<<<< HEAD
            // It can happen that framesThisTime is 0. DCHECK that we will actually
            // exit the loop in this case.  framesThisTime is 0 only if
            // readIndex >= endFrame;
            DCHECK(framesThisTime ? true : readIndex >= endFrame);
=======
            // It can happen that framesThisTime is 0. Assert that we will actually exit the loop in
            // this case.  framesThisTime is 0 only if readIndex >= endFrame;
            ASSERT(framesThisTime ? true : readIndex >= endFrame);
>>>>>>> miniblink49

            // Wrap-around.
            if (readIndex >= endFrame) {
                readIndex -= deltaFrames;
<<<<<<< HEAD
                if (renderSilenceAndFinishIfNotLooping(bus, writeIndex,
                        framesToProcess))
=======
                if (renderSilenceAndFinishIfNotLooping(bus, writeIndex, framesToProcess))
>>>>>>> miniblink49
                    break;
            }
        }
        virtualReadIndex = readIndex;
    } else {
        while (framesToProcess--) {
            unsigned readIndex = static_cast<unsigned>(virtualReadIndex);
            double interpolationFactor = virtualReadIndex - readIndex;

            // For linear interpolation we need the next sample-frame too.
            unsigned readIndex2 = readIndex + 1;
            if (readIndex2 >= bufferLength) {
                if (loop()) {
                    // Make sure to wrap around at the end of the buffer.
                    readIndex2 = static_cast<unsigned>(virtualReadIndex + 1 - virtualDeltaFrames);
                } else {
                    readIndex2 = readIndex;
                }
            }

            // Final sanity check on buffer access.
<<<<<<< HEAD
            // FIXME: as an optimization, try to get rid of this inner-loop check and
            // put assertions and guards before the loop.
=======
            // FIXME: as an optimization, try to get rid of this inner-loop check and put assertions and guards before the loop.
>>>>>>> miniblink49
            if (readIndex >= bufferLength || readIndex2 >= bufferLength)
                break;

            // Linear interpolation.
            for (unsigned i = 0; i < numberOfChannels; ++i) {
                float* destination = destinationChannels[i];
                const float* source = sourceChannels[i];

                double sample1 = source[readIndex];
                double sample2 = source[readIndex2];
                double sample = (1.0 - interpolationFactor) * sample1 + interpolationFactor * sample2;

<<<<<<< HEAD
                destination[writeIndex] = clampTo<float>(sample);
=======
                destination[writeIndex] = narrowPrecisionToFloat(sample);
>>>>>>> miniblink49
            }
            writeIndex++;

            virtualReadIndex += computedPlaybackRate;

<<<<<<< HEAD
            // Wrap-around, retaining sub-sample position since virtualReadIndex is
            // floating-point.
            if (virtualReadIndex >= virtualEndFrame) {
                virtualReadIndex -= virtualDeltaFrames;
                if (renderSilenceAndFinishIfNotLooping(bus, writeIndex,
                        framesToProcess))
=======
            // Wrap-around, retaining sub-sample position since virtualReadIndex is floating-point.
            if (virtualReadIndex >= virtualEndFrame) {
                virtualReadIndex -= virtualDeltaFrames;
                if (renderSilenceAndFinishIfNotLooping(bus, writeIndex, framesToProcess))
>>>>>>> miniblink49
                    break;
            }
        }
    }

    bus->clearSilentFlag();

    m_virtualReadIndex = virtualReadIndex;

    return true;
}

<<<<<<< HEAD
void AudioBufferSourceHandler::setBuffer(AudioBuffer* buffer,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());
=======

void AudioBufferSourceHandler::setBuffer(AudioBuffer* buffer, ExceptionState& exceptionState)
{
    ASSERT(isMainThread());
>>>>>>> miniblink49

    if (m_buffer) {
        exceptionState.throwDOMException(
            InvalidStateError,
            "Cannot set buffer after it has been already been set");
        return;
    }

<<<<<<< HEAD
    // The context must be locked since changing the buffer can re-configure the
    // number of channels that are output.
    BaseAudioContext::AutoLocker contextLocker(context());
=======
    // The context must be locked since changing the buffer can re-configure the number of channels that are output.
    AudioContext::AutoLocker contextLocker(context());
>>>>>>> miniblink49

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);

    if (buffer) {
        // Do any necesssary re-configuration to the buffer's number of channels.
        unsigned numberOfChannels = buffer->numberOfChannels();

<<<<<<< HEAD
        // This should not be possible since AudioBuffers can't be created with too
        // many channels either.
        if (numberOfChannels > BaseAudioContext::maxNumberOfChannels()) {
            exceptionState.throwDOMException(
                NotSupportedError, ExceptionMessages::indexOutsideRange("number of input channels", numberOfChannels, 1u, ExceptionMessages::InclusiveBound, BaseAudioContext::maxNumberOfChannels(), ExceptionMessages::InclusiveBound));
=======
        // This should not be possible since AudioBuffers can't be created with too many channels
        // either.
        if (numberOfChannels > AudioContext::maxNumberOfChannels()) {
            exceptionState.throwDOMException(
                NotSupportedError,
                ExceptionMessages::indexOutsideRange(
                    "number of input channels",
                    numberOfChannels,
                    1u,
                    ExceptionMessages::InclusiveBound,
                    AudioContext::maxNumberOfChannels(),
                    ExceptionMessages::InclusiveBound));
>>>>>>> miniblink49
            return;
        }

        output(0).setNumberOfChannels(numberOfChannels);

<<<<<<< HEAD
        m_sourceChannels = wrapArrayUnique(new const float*[numberOfChannels]);
        m_destinationChannels = wrapArrayUnique(new float*[numberOfChannels]);
=======
        m_sourceChannels = adoptArrayPtr(new const float* [numberOfChannels]);
        m_destinationChannels = adoptArrayPtr(new float* [numberOfChannels]);
>>>>>>> miniblink49

        for (unsigned i = 0; i < numberOfChannels; ++i)
            m_sourceChannels[i] = buffer->getChannelData(i)->data();

<<<<<<< HEAD
        // If this is a grain (as set by a previous call to start()), validate the
        // grain parameters now since it wasn't validated when start was called
        // (because there was no buffer then).
=======
        // If this is a grain (as set by a previous call to start()), validate the grain parameters
        // now since it wasn't validated when start was called (because there was no buffer then).
>>>>>>> miniblink49
        if (m_isGrain)
            clampGrainParameters(buffer);
    }

    m_virtualReadIndex = 0;
    m_buffer = buffer;
}

unsigned AudioBufferSourceHandler::numberOfChannels()
{
    return output(0).numberOfChannels();
}

void AudioBufferSourceHandler::clampGrainParameters(const AudioBuffer* buffer)
{
<<<<<<< HEAD
    DCHECK(buffer);

    // We have a buffer so we can clip the offset and duration to lie within the
    // buffer.
=======
    ASSERT(buffer);

    // We have a buffer so we can clip the offset and duration to lie within the buffer.
>>>>>>> miniblink49
    double bufferDuration = buffer->duration();

    m_grainOffset = clampTo(m_grainOffset, 0.0, bufferDuration);

<<<<<<< HEAD
    // If the duration was not explicitly given, use the buffer duration to set
    // the grain duration. Otherwise, we want to use the user-specified value, of
    // course.
=======
    // If the duration was not explicitly given, use the buffer duration to set the grain
    // duration. Otherwise, we want to use the user-specified value, of course.
>>>>>>> miniblink49
    if (!m_isDurationGiven)
        m_grainDuration = bufferDuration - m_grainOffset;

    if (m_isDurationGiven && loop()) {
<<<<<<< HEAD
        // We're looping a grain with a grain duration specified. Schedule the loop
        // to stop after grainDuration seconds after starting, possibly running the
        // loop multiple times if grainDuration is larger than the buffer duration.
        // The net effect is as if the user called stop(when + grainDuration).
=======
        // We're looping a grain with a grain duration specified. Schedule the loop to stop after
        // grainDuration seconds after starting, possibly running the loop multiple times if
        // grainDuration is larger than the buffer duration. The net effect is as if the user called
        // stop(when + grainDuration).
>>>>>>> miniblink49
        m_grainDuration = clampTo(m_grainDuration, 0.0, std::numeric_limits<double>::infinity());
        m_endTime = m_startTime + m_grainDuration;
    } else {
        m_grainDuration = clampTo(m_grainDuration, 0.0, bufferDuration - m_grainOffset);
    }

<<<<<<< HEAD
    // We call timeToSampleFrame here since at playbackRate == 1 we don't want to
    // go through linear interpolation at a sub-sample position since it will
    // degrade the quality. When aligned to the sample-frame the playback will be
    // identical to the PCM data stored in the buffer. Since playbackRate == 1 is
    // very common, it's worth considering quality.
    m_virtualReadIndex = AudioUtilities::timeToSampleFrame(m_grainOffset, buffer->sampleRate());
}

void AudioBufferSourceHandler::start(double when,
    ExceptionState& exceptionState)
=======
    // We call timeToSampleFrame here since at playbackRate == 1 we don't want to go through
    // linear interpolation at a sub-sample position since it will degrade the quality. When
    // aligned to the sample-frame the playback will be identical to the PCM data stored in the
    // buffer. Since playbackRate == 1 is very common, it's worth considering quality.
    m_virtualReadIndex = AudioUtilities::timeToSampleFrame(m_grainOffset, buffer->sampleRate());
}

void AudioBufferSourceHandler::start(double when, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    AudioScheduledSourceHandler::start(when, exceptionState);
}

<<<<<<< HEAD
void AudioBufferSourceHandler::start(double when,
    double grainOffset,
    ExceptionState& exceptionState)
{
    startSource(when, grainOffset, buffer() ? buffer()->duration() : 0, false,
        exceptionState);
}

void AudioBufferSourceHandler::start(double when,
    double grainOffset,
    double grainDuration,
    ExceptionState& exceptionState)
=======
void AudioBufferSourceHandler::start(double when, double grainOffset, ExceptionState& exceptionState)
{
    startSource(when, grainOffset, buffer() ? buffer()->duration() : 0, false, exceptionState);
}

void AudioBufferSourceHandler::start(double when, double grainOffset, double grainDuration, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    startSource(when, grainOffset, grainDuration, true, exceptionState);
}

<<<<<<< HEAD
void AudioBufferSourceHandler::startSource(double when,
    double grainOffset,
    double grainDuration,
    bool isDurationGiven,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    context()->maybeRecordStartAttempt();

    if (playbackState() != UNSCHEDULED_STATE) {
        exceptionState.throwDOMException(InvalidStateError,
=======
void AudioBufferSourceHandler::startSource(double when, double grainOffset, double grainDuration, bool isDurationGiven, ExceptionState& exceptionState)
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
            InvalidStateError,
<<<<<<< HEAD
            ExceptionMessages::indexExceedsMinimumBound("start time", when, 0.0));
=======
            ExceptionMessages::indexExceedsMinimumBound(
                "start time",
                when,
                0.0));
>>>>>>> miniblink49
        return;
    }

    if (grainOffset < 0) {
        exceptionState.throwDOMException(
<<<<<<< HEAD
            InvalidStateError, ExceptionMessages::indexExceedsMinimumBound("offset", grainOffset, 0.0));
=======
            InvalidStateError,
            ExceptionMessages::indexExceedsMinimumBound(
                "offset",
                grainOffset,
                0.0));
>>>>>>> miniblink49
        return;
    }

    if (grainDuration < 0) {
        exceptionState.throwDOMException(
<<<<<<< HEAD
            InvalidStateError, ExceptionMessages::indexExceedsMinimumBound("duration", grainDuration, 0.0));
        return;
    }

=======
            InvalidStateError,
            ExceptionMessages::indexExceedsMinimumBound(
                "duration",
                grainDuration,
                0.0));
        return;
    }

    m_isDurationGiven = isDurationGiven;
    m_isGrain = true;
    m_grainOffset = grainOffset;
    m_grainDuration = grainDuration;

>>>>>>> miniblink49
    // The node is started. Add a reference to keep us alive so that audio
    // will eventually get played even if Javascript should drop all references
    // to this node. The reference will get dropped when the source has finished
    // playing.
    context()->notifySourceNodeStartedProcessing(node());

<<<<<<< HEAD
    // This synchronizes with process(). updateSchedulingInfo will read some of
    // the variables being set here.
    MutexLocker processLocker(m_processLock);

    m_isDurationGiven = isDurationGiven;
    m_isGrain = true;
    m_grainOffset = grainOffset;
    m_grainDuration = grainDuration;

=======
>>>>>>> miniblink49
    // If |when| < currentTime, the source must start now according to the spec.
    // So just set startTime to currentTime in this case to start the source now.
    m_startTime = std::max(when, context()->currentTime());

    if (buffer())
        clampGrainParameters(buffer());

<<<<<<< HEAD
    setPlaybackState(SCHEDULED_STATE);
=======
    m_playbackState = SCHEDULED_STATE;
>>>>>>> miniblink49
}

double AudioBufferSourceHandler::computePlaybackRate()
{
<<<<<<< HEAD
    // Incorporate buffer's sample-rate versus BaseAudioContext's sample-rate.
    // Normally it's not an issue because buffers are loaded at the
    // BaseAudioContext's sample-rate, but we can handle it in any case.
=======
    double dopplerRate = 1;
    if (m_pannerNode)
        dopplerRate = m_pannerNode->dopplerRate();

    // Incorporate buffer's sample-rate versus AudioContext's sample-rate.
    // Normally it's not an issue because buffers are loaded at the
    // AudioContext's sample-rate, but we can handle it in any case.
>>>>>>> miniblink49
    double sampleRateFactor = 1.0;
    if (buffer()) {
        // Use doubles to compute this to full accuracy.
        sampleRateFactor = buffer()->sampleRate() / static_cast<double>(sampleRate());
    }

    // Use finalValue() to incorporate changes of AudioParamTimeline and
    // AudioSummingJunction from m_playbackRate AudioParam.
    double basePlaybackRate = m_playbackRate->finalValue();

<<<<<<< HEAD
    double finalPlaybackRate = sampleRateFactor * basePlaybackRate;
=======
    double finalPlaybackRate = dopplerRate * sampleRateFactor * basePlaybackRate;
>>>>>>> miniblink49

    // Take the detune value into account for the final playback rate.
    finalPlaybackRate *= pow(2, m_detune->finalValue() / 1200);

    // Sanity check the total rate.  It's very important that the resampler not
    // get any bad rate values.
    finalPlaybackRate = clampTo(finalPlaybackRate, 0.0, MaxRate);

<<<<<<< HEAD
    bool isPlaybackRateValid = !std_isnan(finalPlaybackRate) && !std_isinf(finalPlaybackRate);
    DCHECK(isPlaybackRateValid);
=======
    bool isPlaybackRateValid = !std::isnan(finalPlaybackRate) && !std::isinf(finalPlaybackRate);
    ASSERT(isPlaybackRateValid);
>>>>>>> miniblink49

    if (!isPlaybackRateValid)
        finalPlaybackRate = 1.0;

    // Record the minimum playback rate for use by handleStoppableSourceNode.
    m_minPlaybackRate = std::min(finalPlaybackRate, m_minPlaybackRate);

    return finalPlaybackRate;
}

bool AudioBufferSourceHandler::propagatesSilence() const
{
    return !isPlayingOrScheduled() || hasFinished() || !m_buffer;
}

<<<<<<< HEAD
void AudioBufferSourceHandler::handleStoppableSourceNode()
{
    // If the source node is not looping, and we have a buffer, we can determine
    // when the source would stop playing.  This is intended to handle the
    // (uncommon) scenario where start() has been called but is never connected to
    // the destination (directly or indirectly).  By stopping the node, the node
    // can be collected.  Otherwise, the node will never get collected, leaking
    // memory.
    //
    // If looping was ever done (m_didSetLooping = true), give up.  We can't
    // easily determine how long we looped so we don't know the actual duration
    // thus far, so don't try to do anything fancy.
    if (!didSetLooping() && buffer() && isPlayingOrScheduled() && m_minPlaybackRate > 0) {
        // Adjust the duration to include the playback rate. Only need to account
        // for rate < 1 which makes the sound last longer.  For rate >= 1, the
        // source stops sooner, but that's ok.
=======
void AudioBufferSourceHandler::setPannerNode(PannerHandler* pannerNode)
{
    if (m_pannerNode != pannerNode && !hasFinished()) {
        RefPtr<PannerHandler> oldPannerNode(m_pannerNode.release());
        m_pannerNode = pannerNode;
        if (pannerNode)
            pannerNode->makeConnection();
        if (oldPannerNode)
            oldPannerNode->breakConnection();
    }
}

void AudioBufferSourceHandler::clearPannerNode()
{
    if (m_pannerNode) {
        m_pannerNode->breakConnection();
        m_pannerNode.clear();
    }
}

void AudioBufferSourceHandler::handleStoppableSourceNode()
{
    // If the source node is not looping, and we have a buffer, we can determine when the source
    // would stop playing.  This is intended to handle the (uncommon) scenario where start() has
    // been called but is never connected to the destination (directly or indirectly).  By stopping
    // the node, the node can be collected.  Otherwise, the node will never get collected, leaking
    // memory.
    if (!loop() && buffer() && isPlayingOrScheduled() && m_minPlaybackRate > 0) {
        // Adjust the duration to include the playback rate. Only need to account for rate < 1
        // which makes the sound last longer.  For rate >= 1, the source stops sooner, but that's
        // ok.
>>>>>>> miniblink49
        double actualDuration = buffer()->duration() / m_minPlaybackRate;

        double stopTime = m_startTime + actualDuration;

<<<<<<< HEAD
        // See crbug.com/478301. If a source node is started via start(), the source
        // may not start at that time but one quantum (128 frames) later.  But we
        // compute the stop time based on the start time and the duration, so we end
        // up stopping one quantum early.  Thus, add a little extra time; we just
        // need to stop the source sometime after it should have stopped if it
        // hadn't already.  We don't need to be super precise on when to stop.
=======
        // See crbug.com/478301. If a source node is started via start(), the source may not start
        // at that time but one quantum (128 frames) later.  But we compute the stop time based on
        // the start time and the duration, so we end up stopping one quantum early.  Thus, add a
        // little extra time; we just need to stop the source sometime after it should have stopped
        // if it hadn't already.  We don't need to be super precise on when to stop.
>>>>>>> miniblink49
        double extraStopTime = kExtraStopFrames / static_cast<double>(context()->sampleRate());

        stopTime += extraStopTime;
        if (context()->currentTime() > stopTime) {
<<<<<<< HEAD
            // The context time has passed the time when the source nodes should have
            // stopped playing. Stop the node now and deref it. (But don't run the
            // onEnded event because the source never actually played.)
=======
            // The context time has passed the time when the source nodes should have stopped
            // playing. Stop the node now and deref it. (But don't run the onEnded event because the
            // source never actually played.)
>>>>>>> miniblink49
            finishWithoutOnEnded();
        }
    }
}

<<<<<<< HEAD
// ----------------------------------------------------------------
AudioBufferSourceNode::AudioBufferSourceNode(BaseAudioContext& context)
    : AudioScheduledSourceNode(context)
    , m_playbackRate(AudioParam::create(context,
          ParamTypeAudioBufferSourcePlaybackRate,
          1.0))
    , m_detune(
          AudioParam::create(context, ParamTypeAudioBufferSourceDetune, 0.0))
{
    setHandler(AudioBufferSourceHandler::create(*this, context.sampleRate(),
        m_playbackRate->handler(),
        m_detune->handler()));
}

AudioBufferSourceNode* AudioBufferSourceNode::create(
    BaseAudioContext& context,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    if (context.isContextClosed()) {
        context.throwExceptionForClosedState(exceptionState);
        return nullptr;
    }

    return new AudioBufferSourceNode(context);
}

AudioBufferSourceNode* AudioBufferSourceNode::create(
    BaseAudioContext* context,
    AudioBufferSourceOptions& options,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    AudioBufferSourceNode* node = create(*context, exceptionState);

    if (!node)
        return nullptr;

    if (options.hasBuffer())
        node->setBuffer(options.buffer(), exceptionState);
    if (options.hasDetune())
        node->detune()->setValue(options.detune());
    if (options.hasLoop())
        node->setLoop(options.loop());
    if (options.hasLoopEnd())
        node->setLoopEnd(options.loopEnd());
    if (options.hasLoopStart())
        node->setLoopStart(options.loopStart());
    if (options.hasPlaybackRate())
        node->playbackRate()->setValue(options.playbackRate());

    return node;
=======
void AudioBufferSourceHandler::finish()
{
    clearPannerNode();
    ASSERT(!m_pannerNode);
    AudioScheduledSourceHandler::finish();
}

// ----------------------------------------------------------------
AudioBufferSourceNode::AudioBufferSourceNode(AudioContext& context, float sampleRate)
    : AudioScheduledSourceNode(context)
    , m_playbackRate(AudioParam::create(context, 1.0))
    , m_detune(AudioParam::create(context, 0.0))
{
    setHandler(AudioBufferSourceHandler::create(*this, sampleRate, m_playbackRate->handler(), m_detune->handler()));
}

AudioBufferSourceNode* AudioBufferSourceNode::create(AudioContext& context, float sampleRate)
{
    return new AudioBufferSourceNode(context, sampleRate);
>>>>>>> miniblink49
}

DEFINE_TRACE(AudioBufferSourceNode)
{
    visitor->trace(m_playbackRate);
    visitor->trace(m_detune);
    AudioScheduledSourceNode::trace(visitor);
}

<<<<<<< HEAD
AudioBufferSourceHandler& AudioBufferSourceNode::audioBufferSourceHandler()
    const
=======
AudioBufferSourceHandler& AudioBufferSourceNode::audioBufferSourceHandler() const
>>>>>>> miniblink49
{
    return static_cast<AudioBufferSourceHandler&>(handler());
}

AudioBuffer* AudioBufferSourceNode::buffer() const
{
    return audioBufferSourceHandler().buffer();
}

<<<<<<< HEAD
void AudioBufferSourceNode::setBuffer(AudioBuffer* newBuffer,
    ExceptionState& exceptionState)
=======
void AudioBufferSourceNode::setBuffer(AudioBuffer* newBuffer, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    audioBufferSourceHandler().setBuffer(newBuffer, exceptionState);
}

AudioParam* AudioBufferSourceNode::playbackRate() const
{
    return m_playbackRate;
}

AudioParam* AudioBufferSourceNode::detune() const
{
    return m_detune;
}

bool AudioBufferSourceNode::loop() const
{
    return audioBufferSourceHandler().loop();
}

void AudioBufferSourceNode::setLoop(bool loop)
{
    audioBufferSourceHandler().setLoop(loop);
}

double AudioBufferSourceNode::loopStart() const
{
    return audioBufferSourceHandler().loopStart();
}

void AudioBufferSourceNode::setLoopStart(double loopStart)
{
    audioBufferSourceHandler().setLoopStart(loopStart);
}

double AudioBufferSourceNode::loopEnd() const
{
    return audioBufferSourceHandler().loopEnd();
}

void AudioBufferSourceNode::setLoopEnd(double loopEnd)
{
    audioBufferSourceHandler().setLoopEnd(loopEnd);
}

void AudioBufferSourceNode::start(ExceptionState& exceptionState)
{
    audioBufferSourceHandler().start(0, exceptionState);
}

void AudioBufferSourceNode::start(double when, ExceptionState& exceptionState)
{
    audioBufferSourceHandler().start(when, exceptionState);
}

<<<<<<< HEAD
void AudioBufferSourceNode::start(double when,
    double grainOffset,
    ExceptionState& exceptionState)
=======
void AudioBufferSourceNode::start(double when, double grainOffset, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    audioBufferSourceHandler().start(when, grainOffset, exceptionState);
}

<<<<<<< HEAD
void AudioBufferSourceNode::start(double when,
    double grainOffset,
    double grainDuration,
    ExceptionState& exceptionState)
{
    audioBufferSourceHandler().start(when, grainOffset, grainDuration,
        exceptionState);
}

} // namespace blink
=======
void AudioBufferSourceNode::start(double when, double grainOffset, double grainDuration, ExceptionState& exceptionState)
{
    audioBufferSourceHandler().start(when, grainOffset, grainDuration, exceptionState);
}

} // namespace blink

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49

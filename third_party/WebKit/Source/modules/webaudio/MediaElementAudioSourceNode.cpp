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
 */

#include "modules/webaudio/MediaElementAudioSourceNode.h"

#include "core/dom/ExecutionContextTask.h"
#include "core/dom/TaskRunnerHelper.h"
#include "core/html/HTMLMediaElement.h"
#include "core/inspector/ConsoleMessage.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "modules/webaudio/BaseAudioContext.h"
#include "modules/webaudio/MediaElementAudioSourceOptions.h"
#include "platform/audio/AudioUtilities.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "wtf/Locker.h"
#include "wtf/PtrUtil.h"

namespace blink {

MediaElementAudioSourceHandler::MediaElementAudioSourceHandler(
    AudioNode& node,
    HTMLMediaElement& mediaElement)
    : AudioHandler(NodeTypeMediaElementAudioSource,
        node,
        node.context()->sampleRate())
    , m_mediaElement(mediaElement)
    , m_sourceNumberOfChannels(0)
    , m_sourceSampleRate(0)
    , m_passesCurrentSrcCORSAccessCheck(
          passesCurrentSrcCORSAccessCheck(mediaElement.currentSrc()))
    , m_maybePrintCORSMessage(!m_passesCurrentSrcCORSAccessCheck)
    , m_currentSrcString(mediaElement.currentSrc().getString())
{
    DCHECK(isMainThread());
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
#include "modules/webaudio/MediaElementAudioSourceNode.h"

#include "core/dom/CrossThreadTask.h"
#include "core/frame/ConsoleTypes.h"
#include "core/html/HTMLMediaElement.h"
#include "core/inspector/ConsoleMessage.h"
#include "modules/webaudio/AudioContext.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "platform/Logging.h"
#include "platform/audio/AudioUtilities.h"
#include "platform/graphics/media/MediaPlayer.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "wtf/Locker.h"
#include "wtf/MainThread.h"

namespace blink {

MediaElementAudioSourceHandler::MediaElementAudioSourceHandler(AudioNode& node, HTMLMediaElement& mediaElement)
    : AudioHandler(NodeTypeMediaElementAudioSource, node, node.context()->sampleRate())
    , m_mediaElement(mediaElement)
    , m_sourceNumberOfChannels(0)
    , m_sourceSampleRate(0)
    , m_passesCurrentSrcCORSAccessCheck(passesCurrentSrcCORSAccessCheck(mediaElement.currentSrc()))
    , m_maybePrintCORSMessage(!m_passesCurrentSrcCORSAccessCheck)
    , m_currentSrcString(mediaElement.currentSrc().string())
{
    ASSERT(isMainThread());
>>>>>>> miniblink49
    // Default to stereo. This could change depending on what the media element
    // .src is set to.
    addOutput(2);

    initialize();
}

<<<<<<< HEAD
PassRefPtr<MediaElementAudioSourceHandler>
MediaElementAudioSourceHandler::create(AudioNode& node,
    HTMLMediaElement& mediaElement)
=======
PassRefPtr<MediaElementAudioSourceHandler> MediaElementAudioSourceHandler::create(AudioNode& node, HTMLMediaElement& mediaElement)
>>>>>>> miniblink49
{
    return adoptRef(new MediaElementAudioSourceHandler(node, mediaElement));
}

MediaElementAudioSourceHandler::~MediaElementAudioSourceHandler()
{
    uninitialize();
}

void MediaElementAudioSourceHandler::dispose()
{
    m_mediaElement->setAudioSourceNode(nullptr);
    AudioHandler::dispose();
}

<<<<<<< HEAD
void MediaElementAudioSourceHandler::setFormat(size_t numberOfChannels,
    float sourceSampleRate)
{
    if (numberOfChannels != m_sourceNumberOfChannels || sourceSampleRate != m_sourceSampleRate) {
        if (!numberOfChannels || numberOfChannels > BaseAudioContext::maxNumberOfChannels() || !AudioUtilities::isValidAudioBufferSampleRate(sourceSampleRate)) {
            // process() will generate silence for these uninitialized values.
            DLOG(ERROR) << "setFormat(" << numberOfChannels << ", "
                        << sourceSampleRate << ") - unhandled format change";
            // Synchronize with process().
            Locker<MediaElementAudioSourceHandler> locker(*this);
=======
void MediaElementAudioSourceHandler::setFormat(size_t numberOfChannels, float sourceSampleRate)
{
    if (numberOfChannels != m_sourceNumberOfChannels || sourceSampleRate != m_sourceSampleRate) {
        if (!numberOfChannels || numberOfChannels > AudioContext::maxNumberOfChannels() || !AudioUtilities::isValidAudioBufferSampleRate(sourceSampleRate)) {
            // process() will generate silence for these uninitialized values.
            WTF_LOG(Media, "MediaElementAudioSourceNode::setFormat(%u, %f) - unhandled format change", static_cast<unsigned>(numberOfChannels), sourceSampleRate);
>>>>>>> miniblink49
            m_sourceNumberOfChannels = 0;
            m_sourceSampleRate = 0;
            return;
        }

<<<<<<< HEAD
        // Synchronize with process() to protect m_sourceNumberOfChannels,
        // m_sourceSampleRate, and m_multiChannelResampler.
        Locker<MediaElementAudioSourceHandler> locker(*this);

        m_sourceNumberOfChannels = numberOfChannels;
        m_sourceSampleRate = sourceSampleRate;

        if (sourceSampleRate != sampleRate()) {
            double scaleFactor = sourceSampleRate / sampleRate();
            m_multiChannelResampler = WTF::makeUnique<MultiChannelResampler>(scaleFactor, numberOfChannels);
        } else {
            // Bypass resampling.
            m_multiChannelResampler.reset();
=======
        m_sourceNumberOfChannels = numberOfChannels;
        m_sourceSampleRate = sourceSampleRate;

        // Synchronize with process().
        Locker<MediaElementAudioSourceHandler> locker(*this);

        if (sourceSampleRate != sampleRate()) {
            double scaleFactor = sourceSampleRate / sampleRate();
            m_multiChannelResampler = adoptPtr(new MultiChannelResampler(scaleFactor, numberOfChannels));
        } else {
            // Bypass resampling.
            m_multiChannelResampler.clear();
>>>>>>> miniblink49
        }

        {
            // The context must be locked when changing the number of output channels.
<<<<<<< HEAD
            BaseAudioContext::AutoLocker contextLocker(context());
=======
            AudioContext::AutoLocker contextLocker(context());
>>>>>>> miniblink49

            // Do any necesssary re-configuration to the output's number of channels.
            output(0).setNumberOfChannels(numberOfChannels);
        }
    }
}

bool MediaElementAudioSourceHandler::passesCORSAccessCheck()
{
<<<<<<< HEAD
    DCHECK(mediaElement());

    return (mediaElement()->webMediaPlayer() && mediaElement()->webMediaPlayer()->didPassCORSAccessCheck()) || m_passesCurrentSrcCORSAccessCheck;
}

void MediaElementAudioSourceHandler::onCurrentSrcChanged(
    const KURL& currentSrc)
{
    DCHECK(isMainThread());
=======
    ASSERT(mediaElement());

    return (mediaElement()->webMediaPlayer() && mediaElement()->webMediaPlayer()->didPassCORSAccessCheck())
        || m_passesCurrentSrcCORSAccessCheck;
}

void MediaElementAudioSourceHandler::onCurrentSrcChanged(const KURL& currentSrc)
{
    ASSERT(isMainThread());
>>>>>>> miniblink49

    // Synchronize with process().
    Locker<MediaElementAudioSourceHandler> locker(*this);

    m_passesCurrentSrcCORSAccessCheck = passesCurrentSrcCORSAccessCheck(currentSrc);

<<<<<<< HEAD
    // Make a note if we need to print a console message and save the |curentSrc|
    // for use in the message.  Need to wait until later to print the message in
    // case HTMLMediaElement allows access.
    m_maybePrintCORSMessage = !m_passesCurrentSrcCORSAccessCheck;
    m_currentSrcString = currentSrc.getString();
}

bool MediaElementAudioSourceHandler::passesCurrentSrcCORSAccessCheck(
    const KURL& currentSrc)
{
    DCHECK(isMainThread());
    return context()->getSecurityOrigin() && context()->getSecurityOrigin()->canRequest(currentSrc);
=======
    // Make a note if we need to print a console message and save the |curentSrc| for use in the
    // message.  Need to wait until later to print the message in case HTMLMediaElement allows
    // access.
    m_maybePrintCORSMessage = !m_passesCurrentSrcCORSAccessCheck;
    m_currentSrcString = currentSrc.string();
}

bool MediaElementAudioSourceHandler::passesCurrentSrcCORSAccessCheck(const KURL& currentSrc)
{
    ASSERT(isMainThread());
    return context()->securityOrigin() && context()->securityOrigin()->canRequest(currentSrc);
>>>>>>> miniblink49
}

void MediaElementAudioSourceHandler::printCORSMessage(const String& message)
{
<<<<<<< HEAD
    if (context()->getExecutionContext()) {
        context()->getExecutionContext()->addConsoleMessage(
            ConsoleMessage::create(SecurityMessageSource, InfoMessageLevel,
                "MediaElementAudioSource outputs zeroes due to "
                "CORS access restrictions for "
                    + message));
=======
    if (context()->executionContext()) {
        context()->executionContext()->addConsoleMessage(
            ConsoleMessage::create(SecurityMessageSource, InfoMessageLevel,
                "MediaElementAudioSource outputs zeroes due to CORS access restrictions for " + message));
>>>>>>> miniblink49
    }
}

void MediaElementAudioSourceHandler::process(size_t numberOfFrames)
{
    AudioBus* outputBus = output(0).bus();

<<<<<<< HEAD
    // Use a tryLock() to avoid contention in the real-time audio thread.
    // If we fail to acquire the lock then the HTMLMediaElement must be in the
    // middle of reconfiguring its playback engine, so we output silence in this
    // case.
    MutexTryLocker tryLocker(m_processLock);
    if (tryLocker.locked()) {
        if (!mediaElement() || !m_sourceNumberOfChannels || !m_sourceSampleRate) {
            outputBus->zero();
            return;
        }
        AudioSourceProvider& provider = mediaElement()->getAudioSourceProvider();
        // Grab data from the provider so that the element continues to make
        // progress, even if we're going to output silence anyway.
        if (m_multiChannelResampler.get()) {
            DCHECK_NE(m_sourceSampleRate, sampleRate());
            m_multiChannelResampler->process(&provider, outputBus, numberOfFrames);
        } else {
            // Bypass the resampler completely if the source is at the context's
            // sample-rate.
            DCHECK_EQ(m_sourceSampleRate, sampleRate());
            provider.provideInput(outputBus, numberOfFrames);
        }
        // Output silence if we don't have access to the element.
        if (!passesCORSAccessCheck()) {
            if (m_maybePrintCORSMessage) {
                // Print a CORS message, but just once for each change in the current
                // media element source, and only if we have a document to print to.
                m_maybePrintCORSMessage = false;
                if (context()->getExecutionContext()) {
                    context()->getExecutionContext()->postTask(
                        TaskType::MediaElementEvent, BLINK_FROM_HERE,
                        createCrossThreadTask(
                            &MediaElementAudioSourceHandler::printCORSMessage,
                            PassRefPtr<MediaElementAudioSourceHandler>(this),
                            m_currentSrcString));
                }
            }
=======
    if (!mediaElement() || !m_sourceNumberOfChannels || !m_sourceSampleRate) {
        outputBus->zero();
        return;
    }

    // Use a tryLock() to avoid contention in the real-time audio thread.
    // If we fail to acquire the lock then the HTMLMediaElement must be in the middle of
    // reconfiguring its playback engine, so we output silence in this case.
    MutexTryLocker tryLocker(m_processLock);
    if (tryLocker.locked()) {
        if (AudioSourceProvider* provider = mediaElement()->audioSourceProvider()) {
            // Grab data from the provider so that the element continues to make progress, even if
            // we're going to output silence anyway.
            if (m_multiChannelResampler.get()) {
                ASSERT(m_sourceSampleRate != sampleRate());
                m_multiChannelResampler->process(provider, outputBus, numberOfFrames);
            } else {
                // Bypass the resampler completely if the source is at the context's sample-rate.
                ASSERT(m_sourceSampleRate == sampleRate());
                provider->provideInput(outputBus, numberOfFrames);
            }
            // Output silence if we don't have access to the element.
            if (!passesCORSAccessCheck()) {
                if (m_maybePrintCORSMessage) {
                    // Print a CORS message, but just once for each change in the current media
                    // element source, and only if we have a document to print to.
                    m_maybePrintCORSMessage = false;
                    if (context()->executionContext()) {
                        context()->executionContext()->postTask(FROM_HERE,
                            createCrossThreadTask(&MediaElementAudioSourceHandler::printCORSMessage,
                                this,
                                m_currentSrcString));
                    }
                }
                outputBus->zero();
            }
        } else {
            // Either this port doesn't yet support HTMLMediaElement audio stream access,
            // or the stream is not yet available.
>>>>>>> miniblink49
            outputBus->zero();
        }
    } else {
        // We failed to acquire the lock.
        outputBus->zero();
    }
}

void MediaElementAudioSourceHandler::lock()
{
    m_processLock.lock();
}

void MediaElementAudioSourceHandler::unlock()
{
    m_processLock.unlock();
}

// ----------------------------------------------------------------

<<<<<<< HEAD
MediaElementAudioSourceNode::MediaElementAudioSourceNode(
    BaseAudioContext& context,
    HTMLMediaElement& mediaElement)
=======
MediaElementAudioSourceNode::MediaElementAudioSourceNode(AudioContext& context, HTMLMediaElement& mediaElement)
>>>>>>> miniblink49
    : AudioSourceNode(context)
{
    setHandler(MediaElementAudioSourceHandler::create(*this, mediaElement));
}

<<<<<<< HEAD
MediaElementAudioSourceNode* MediaElementAudioSourceNode::create(
    BaseAudioContext& context,
    HTMLMediaElement& mediaElement,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    if (context.isContextClosed()) {
        context.throwExceptionForClosedState(exceptionState);
        return nullptr;
    }

    // First check if this media element already has a source node.
    if (mediaElement.audioSourceNode()) {
        exceptionState.throwDOMException(InvalidStateError,
            "HTMLMediaElement already connected "
            "previously to a different "
            "MediaElementSourceNode.");
        return nullptr;
    }

    MediaElementAudioSourceNode* node = new MediaElementAudioSourceNode(context, mediaElement);

    if (node) {
        mediaElement.setAudioSourceNode(node);
        // context keeps reference until node is disconnected
        context.notifySourceNodeStartedProcessing(node);
    }

    return node;
}

MediaElementAudioSourceNode* MediaElementAudioSourceNode::create(
    BaseAudioContext* context,
    const MediaElementAudioSourceOptions& options,
    ExceptionState& exceptionState)
{
    if (!options.hasMediaElement()) {
        exceptionState.throwDOMException(NotFoundError,
            "mediaElement member is required.");
        return nullptr;
    }

    return create(*context, *options.mediaElement(), exceptionState);
=======
MediaElementAudioSourceNode* MediaElementAudioSourceNode::create(AudioContext& context, HTMLMediaElement& mediaElement)
{
    return new MediaElementAudioSourceNode(context, mediaElement);
>>>>>>> miniblink49
}

DEFINE_TRACE(MediaElementAudioSourceNode)
{
    AudioSourceProviderClient::trace(visitor);
    AudioSourceNode::trace(visitor);
}

<<<<<<< HEAD
MediaElementAudioSourceHandler&
MediaElementAudioSourceNode::mediaElementAudioSourceHandler() const
=======
MediaElementAudioSourceHandler& MediaElementAudioSourceNode::mediaElementAudioSourceHandler() const
>>>>>>> miniblink49
{
    return static_cast<MediaElementAudioSourceHandler&>(handler());
}

HTMLMediaElement* MediaElementAudioSourceNode::mediaElement() const
{
    return mediaElementAudioSourceHandler().mediaElement();
}

<<<<<<< HEAD
void MediaElementAudioSourceNode::setFormat(size_t numberOfChannels,
    float sampleRate)
=======
void MediaElementAudioSourceNode::setFormat(size_t numberOfChannels, float sampleRate)
>>>>>>> miniblink49
{
    mediaElementAudioSourceHandler().setFormat(numberOfChannels, sampleRate);
}

void MediaElementAudioSourceNode::onCurrentSrcChanged(const KURL& currentSrc)
{
    mediaElementAudioSourceHandler().onCurrentSrcChanged(currentSrc);
}

void MediaElementAudioSourceNode::lock()
{
    mediaElementAudioSourceHandler().lock();
}

void MediaElementAudioSourceNode::unlock()
{
    mediaElementAudioSourceHandler().unlock();
}

} // namespace blink
<<<<<<< HEAD
=======

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49

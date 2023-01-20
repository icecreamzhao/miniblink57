/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "modules/speech/SpeechSynthesis.h"

=======
#include "config.h"
#include "modules/speech/SpeechSynthesis.h"

#include "bindings/core/v8/ExceptionState.h"
>>>>>>> miniblink49
#include "core/dom/ExecutionContext.h"
#include "modules/speech/SpeechSynthesisEvent.h"
#include "platform/speech/PlatformSpeechSynthesisVoice.h"
#include "wtf/CurrentTime.h"

namespace blink {

SpeechSynthesis* SpeechSynthesis::create(ExecutionContext* context)
{
    return new SpeechSynthesis(context);
}

SpeechSynthesis::SpeechSynthesis(ExecutionContext* context)
<<<<<<< HEAD
    : ContextClient(context)
=======
    : ContextLifecycleObserver(context)
>>>>>>> miniblink49
    , m_platformSpeechSynthesizer(PlatformSpeechSynthesizer::create(this))
    , m_isPaused(false)
{
}

<<<<<<< HEAD
void SpeechSynthesis::setPlatformSynthesizer(
    PlatformSpeechSynthesizer* synthesizer)
=======
void SpeechSynthesis::setPlatformSynthesizer(PlatformSpeechSynthesizer* synthesizer)
>>>>>>> miniblink49
{
    m_platformSpeechSynthesizer = synthesizer;
}

<<<<<<< HEAD
void SpeechSynthesis::voicesDidChange()
{
    m_voiceList.clear();
    if (getExecutionContext())
=======
ExecutionContext* SpeechSynthesis::executionContext() const
{
    return ContextLifecycleObserver::executionContext();
}

void SpeechSynthesis::voicesDidChange()
{
    m_voiceList.clear();
    if (executionContext() && !executionContext()->activeDOMObjectsAreStopped())
>>>>>>> miniblink49
        dispatchEvent(Event::create(EventTypeNames::voiceschanged));
}

const HeapVector<Member<SpeechSynthesisVoice>>& SpeechSynthesis::getVoices()
{
    if (m_voiceList.size())
        return m_voiceList;

<<<<<<< HEAD
    // If the voiceList is empty, that's the cue to get the voices from the
    // platform again.
    const Vector<RefPtr<PlatformSpeechSynthesisVoice>>& platformVoices = m_platformSpeechSynthesizer->voiceList();
    size_t voiceCount = platformVoices.size();
    for (size_t k = 0; k < voiceCount; k++)
        m_voiceList.push_back(SpeechSynthesisVoice::create(platformVoices[k]));
=======
    // If the voiceList is empty, that's the cue to get the voices from the platform again.
    const HeapVector<Member<PlatformSpeechSynthesisVoice>>& platformVoices = m_platformSpeechSynthesizer->voiceList();
    size_t voiceCount = platformVoices.size();
    for (size_t k = 0; k < voiceCount; k++)
        m_voiceList.append(SpeechSynthesisVoice::create(platformVoices[k]));
>>>>>>> miniblink49

    return m_voiceList;
}

bool SpeechSynthesis::speaking() const
{
<<<<<<< HEAD
    // If we have a current speech utterance, then that means we're assumed to be
    // in a speaking state. This state is independent of whether the utterance
    // happens to be paused.
=======
    // If we have a current speech utterance, then that means we're assumed to be in a speaking state.
    // This state is independent of whether the utterance happens to be paused.
>>>>>>> miniblink49
    return currentSpeechUtterance();
}

bool SpeechSynthesis::pending() const
{
    // This is true if there are any utterances that have not started.
    // That means there will be more than one in the queue.
    return m_utteranceQueue.size() > 1;
}

bool SpeechSynthesis::paused() const
{
    return m_isPaused;
}

void SpeechSynthesis::startSpeakingImmediately()
{
    SpeechSynthesisUtterance* utterance = currentSpeechUtterance();
    ASSERT(utterance);

    utterance->setStartTime(monotonicallyIncreasingTime());
    m_isPaused = false;
    m_platformSpeechSynthesizer->speak(utterance->platformUtterance());
}

<<<<<<< HEAD
void SpeechSynthesis::speak(SpeechSynthesisUtterance* utterance)
{
    ASSERT(utterance);
=======
void SpeechSynthesis::speak(SpeechSynthesisUtterance* utterance, ExceptionState& exceptionState)
{
    if (!utterance) {
        exceptionState.throwTypeError("Invalid utterance argument");
        return;
    }
>>>>>>> miniblink49

    m_utteranceQueue.append(utterance);

    // If the queue was empty, speak this immediately.
    if (m_utteranceQueue.size() == 1)
        startSpeakingImmediately();
}

void SpeechSynthesis::cancel()
{
    // Remove all the items from the utterance queue. The platform
    // may still have references to some of these utterances and may
    // fire events on them asynchronously.
    m_utteranceQueue.clear();
    m_platformSpeechSynthesizer->cancel();
}

void SpeechSynthesis::pause()
{
    if (!m_isPaused)
        m_platformSpeechSynthesizer->pause();
}

void SpeechSynthesis::resume()
{
    if (!currentSpeechUtterance())
        return;
    m_platformSpeechSynthesizer->resume();
}

<<<<<<< HEAD
void SpeechSynthesis::fireEvent(const AtomicString& type,
    SpeechSynthesisUtterance* utterance,
    unsigned long charIndex,
    const String& name)
{
    if (!getExecutionContext())
        return;

    double elapsedTimeMillis = (monotonicallyIncreasingTime() - utterance->startTime()) * 1000.0;
    utterance->dispatchEvent(SpeechSynthesisEvent::create(
        type, utterance, charIndex, elapsedTimeMillis, name));
}

void SpeechSynthesis::handleSpeakingCompleted(
    SpeechSynthesisUtterance* utterance,
    bool errorOccurred)
=======
void SpeechSynthesis::fireEvent(const AtomicString& type, SpeechSynthesisUtterance* utterance, unsigned long charIndex, const String& name)
{
    if (executionContext() && !executionContext()->activeDOMObjectsAreStopped())
        utterance->dispatchEvent(SpeechSynthesisEvent::create(type, utterance, charIndex, (currentTime() - utterance->startTime()), name));
}

void SpeechSynthesis::handleSpeakingCompleted(SpeechSynthesisUtterance* utterance, bool errorOccurred)
>>>>>>> miniblink49
{
    ASSERT(utterance);

    bool shouldStartSpeaking = false;
    // If the utterance that completed was the one we're currently speaking,
    // remove it from the queue and start speaking the next one.
    if (utterance == currentSpeechUtterance()) {
        m_utteranceQueue.removeFirst();
        shouldStartSpeaking = !!m_utteranceQueue.size();
    }

    // Always fire the event, because the platform may have asynchronously
    // sent an event on an utterance before it got the message that we
    // canceled it, and we should always report to the user what actually
    // happened.
<<<<<<< HEAD
    fireEvent(errorOccurred ? EventTypeNames::error : EventTypeNames::end,
        utterance, 0, String());
=======
    fireEvent(errorOccurred ? EventTypeNames::error : EventTypeNames::end, utterance, 0, String());
>>>>>>> miniblink49

    // Start the next utterance if we just finished one and one was pending.
    if (shouldStartSpeaking && !m_utteranceQueue.isEmpty())
        startSpeakingImmediately();
}

<<<<<<< HEAD
void SpeechSynthesis::boundaryEventOccurred(
    PlatformSpeechSynthesisUtterance* utterance,
    SpeechBoundary boundary,
    unsigned charIndex)
=======
void SpeechSynthesis::boundaryEventOccurred(PlatformSpeechSynthesisUtterance* utterance, SpeechBoundary boundary, unsigned charIndex)
>>>>>>> miniblink49
{
    DEFINE_STATIC_LOCAL(const String, wordBoundaryString, ("word"));
    DEFINE_STATIC_LOCAL(const String, sentenceBoundaryString, ("sentence"));

    switch (boundary) {
    case SpeechWordBoundary:
<<<<<<< HEAD
        fireEvent(EventTypeNames::boundary,
            static_cast<SpeechSynthesisUtterance*>(utterance->client()),
            charIndex, wordBoundaryString);
        break;
    case SpeechSentenceBoundary:
        fireEvent(EventTypeNames::boundary,
            static_cast<SpeechSynthesisUtterance*>(utterance->client()),
            charIndex, sentenceBoundaryString);
=======
        fireEvent(EventTypeNames::boundary, static_cast<SpeechSynthesisUtterance*>(utterance->client()), charIndex, wordBoundaryString);
        break;
    case SpeechSentenceBoundary:
        fireEvent(EventTypeNames::boundary, static_cast<SpeechSynthesisUtterance*>(utterance->client()), charIndex, sentenceBoundaryString);
>>>>>>> miniblink49
        break;
    default:
        ASSERT_NOT_REACHED();
    }
}

<<<<<<< HEAD
void SpeechSynthesis::didStartSpeaking(
    PlatformSpeechSynthesisUtterance* utterance)
{
    if (utterance->client())
        fireEvent(EventTypeNames::start,
            static_cast<SpeechSynthesisUtterance*>(utterance->client()), 0,
            String());
}

void SpeechSynthesis::didPauseSpeaking(
    PlatformSpeechSynthesisUtterance* utterance)
{
    m_isPaused = true;
    if (utterance->client())
        fireEvent(EventTypeNames::pause,
            static_cast<SpeechSynthesisUtterance*>(utterance->client()), 0,
            String());
}

void SpeechSynthesis::didResumeSpeaking(
    PlatformSpeechSynthesisUtterance* utterance)
{
    m_isPaused = false;
    if (utterance->client())
        fireEvent(EventTypeNames::resume,
            static_cast<SpeechSynthesisUtterance*>(utterance->client()), 0,
            String());
}

void SpeechSynthesis::didFinishSpeaking(
    PlatformSpeechSynthesisUtterance* utterance)
{
    if (utterance->client())
        handleSpeakingCompleted(
            static_cast<SpeechSynthesisUtterance*>(utterance->client()), false);
}

void SpeechSynthesis::speakingErrorOccurred(
    PlatformSpeechSynthesisUtterance* utterance)
{
    if (utterance->client())
        handleSpeakingCompleted(
            static_cast<SpeechSynthesisUtterance*>(utterance->client()), true);
=======
void SpeechSynthesis::didStartSpeaking(PlatformSpeechSynthesisUtterance* utterance)
{
    if (utterance->client())
        fireEvent(EventTypeNames::start, static_cast<SpeechSynthesisUtterance*>(utterance->client()), 0, String());
}

void SpeechSynthesis::didPauseSpeaking(PlatformSpeechSynthesisUtterance* utterance)
{
    m_isPaused = true;
    if (utterance->client())
        fireEvent(EventTypeNames::pause, static_cast<SpeechSynthesisUtterance*>(utterance->client()), 0, String());
}

void SpeechSynthesis::didResumeSpeaking(PlatformSpeechSynthesisUtterance* utterance)
{
    m_isPaused = false;
    if (utterance->client())
        fireEvent(EventTypeNames::resume, static_cast<SpeechSynthesisUtterance*>(utterance->client()), 0, String());
}

void SpeechSynthesis::didFinishSpeaking(PlatformSpeechSynthesisUtterance* utterance)
{
    if (utterance->client())
        handleSpeakingCompleted(static_cast<SpeechSynthesisUtterance*>(utterance->client()), false);
}

void SpeechSynthesis::speakingErrorOccurred(PlatformSpeechSynthesisUtterance* utterance)
{
    if (utterance->client())
        handleSpeakingCompleted(static_cast<SpeechSynthesisUtterance*>(utterance->client()), true);
>>>>>>> miniblink49
}

SpeechSynthesisUtterance* SpeechSynthesis::currentSpeechUtterance() const
{
    if (m_utteranceQueue.isEmpty())
        return nullptr;

    return m_utteranceQueue.first();
}

const AtomicString& SpeechSynthesis::interfaceName() const
{
    return EventTargetNames::SpeechSynthesis;
}

DEFINE_TRACE(SpeechSynthesis)
{
    visitor->trace(m_platformSpeechSynthesizer);
    visitor->trace(m_voiceList);
    visitor->trace(m_utteranceQueue);
    PlatformSpeechSynthesizerClient::trace(visitor);
<<<<<<< HEAD
    ContextClient::trace(visitor);
    EventTargetWithInlineData::trace(visitor);
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<SpeechSynthesis>::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink

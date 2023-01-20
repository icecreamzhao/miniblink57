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
#include "modules/speech/SpeechSynthesisUtterance.h"

#include "core/dom/ExecutionContext.h"

namespace blink {

SpeechSynthesisUtterance* SpeechSynthesisUtterance::create(
    ExecutionContext* context,
    const String& text)
=======
#include "config.h"
#include "modules/speech/SpeechSynthesisUtterance.h"

namespace blink {

SpeechSynthesisUtterance* SpeechSynthesisUtterance::create(ExecutionContext* context, const String& text)
>>>>>>> miniblink49
{
    return new SpeechSynthesisUtterance(context, text);
}

<<<<<<< HEAD
SpeechSynthesisUtterance::SpeechSynthesisUtterance(ExecutionContext* context,
    const String& text)
    : ContextClient(context)
=======
SpeechSynthesisUtterance::SpeechSynthesisUtterance(ExecutionContext* context, const String& text)
    : ContextLifecycleObserver(context)
>>>>>>> miniblink49
    , m_platformUtterance(PlatformSpeechSynthesisUtterance::create(this))
{
    m_platformUtterance->setText(text);
}

<<<<<<< HEAD
SpeechSynthesisUtterance::~SpeechSynthesisUtterance() { }
=======
SpeechSynthesisUtterance::~SpeechSynthesisUtterance()
{
}

ExecutionContext* SpeechSynthesisUtterance::executionContext() const
{
    return ContextLifecycleObserver::executionContext();
}
>>>>>>> miniblink49

const AtomicString& SpeechSynthesisUtterance::interfaceName() const
{
    return EventTargetNames::SpeechSynthesisUtterance;
}

SpeechSynthesisVoice* SpeechSynthesisUtterance::voice() const
{
    return m_voice;
}

void SpeechSynthesisUtterance::setVoice(SpeechSynthesisVoice* voice)
{
<<<<<<< HEAD
    // Cache our own version of the SpeechSynthesisVoice so that we don't have to
    // do some lookup to go from the platform voice back to the speech synthesis
    // voice in the read property.
=======
    // Cache our own version of the SpeechSynthesisVoice so that we don't have to do some lookup
    // to go from the platform voice back to the speech synthesis voice in the read property.
>>>>>>> miniblink49
    m_voice = voice;

    if (voice)
        m_platformUtterance->setVoice(voice->platformVoice());
}

DEFINE_TRACE(SpeechSynthesisUtterance)
{
    visitor->trace(m_platformUtterance);
    visitor->trace(m_voice);
<<<<<<< HEAD
    ContextClient::trace(visitor);
    EventTargetWithInlineData::trace(visitor);
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<SpeechSynthesisUtterance>::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink

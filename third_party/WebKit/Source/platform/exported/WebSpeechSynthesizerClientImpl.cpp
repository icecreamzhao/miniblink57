/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/exported/WebSpeechSynthesizerClientImpl.h"

#include "platform/speech/PlatformSpeechSynthesisUtterance.h"

namespace blink {

<<<<<<< HEAD
WebSpeechSynthesizerClientImpl::WebSpeechSynthesizerClientImpl(
    PlatformSpeechSynthesizer* synthesizer,
    PlatformSpeechSynthesizerClient* client)
=======
WebSpeechSynthesizerClientImpl::WebSpeechSynthesizerClientImpl(PlatformSpeechSynthesizer* synthesizer, PlatformSpeechSynthesizerClient* client)
>>>>>>> miniblink49
    : m_synthesizer(synthesizer)
    , m_client(client)
{
}

<<<<<<< HEAD
WebSpeechSynthesizerClientImpl::~WebSpeechSynthesizerClientImpl() { }

void WebSpeechSynthesizerClientImpl::setVoiceList(
    const WebVector<WebSpeechSynthesisVoice>& voices)
{
    Vector<RefPtr<PlatformSpeechSynthesisVoice>> outVoices;
    for (size_t i = 0; i < voices.size(); i++)
        outVoices.push_back(voices[i]);
=======
WebSpeechSynthesizerClientImpl::~WebSpeechSynthesizerClientImpl()
{
}

void WebSpeechSynthesizerClientImpl::setVoiceList(const WebVector<WebSpeechSynthesisVoice>& voices)
{
    HeapVector<Member<PlatformSpeechSynthesisVoice>> outVoices;
    for (size_t i = 0; i < voices.size(); i++)
        outVoices.append(voices[i]);
>>>>>>> miniblink49
    m_synthesizer->setVoiceList(outVoices);
    m_client->voicesDidChange();
}

<<<<<<< HEAD
void WebSpeechSynthesizerClientImpl::didStartSpeaking(
    const WebSpeechSynthesisUtterance& utterance)
=======
void WebSpeechSynthesizerClientImpl::didStartSpeaking(const WebSpeechSynthesisUtterance& utterance)
>>>>>>> miniblink49
{
    m_client->didStartSpeaking(utterance);
}

<<<<<<< HEAD
void WebSpeechSynthesizerClientImpl::didFinishSpeaking(
    const WebSpeechSynthesisUtterance& utterance)
=======
void WebSpeechSynthesizerClientImpl::didFinishSpeaking(const WebSpeechSynthesisUtterance& utterance)
>>>>>>> miniblink49
{
    m_client->didFinishSpeaking(utterance);
}

<<<<<<< HEAD
void WebSpeechSynthesizerClientImpl::didPauseSpeaking(
    const WebSpeechSynthesisUtterance& utterance)
=======
void WebSpeechSynthesizerClientImpl::didPauseSpeaking(const WebSpeechSynthesisUtterance& utterance)
>>>>>>> miniblink49
{
    m_client->didPauseSpeaking(utterance);
}

<<<<<<< HEAD
void WebSpeechSynthesizerClientImpl::didResumeSpeaking(
    const WebSpeechSynthesisUtterance& utterance)
=======
void WebSpeechSynthesizerClientImpl::didResumeSpeaking(const WebSpeechSynthesisUtterance& utterance)
>>>>>>> miniblink49
{
    m_client->didResumeSpeaking(utterance);
}

<<<<<<< HEAD
void WebSpeechSynthesizerClientImpl::speakingErrorOccurred(
    const WebSpeechSynthesisUtterance& utterance)
=======
void WebSpeechSynthesizerClientImpl::speakingErrorOccurred(const WebSpeechSynthesisUtterance& utterance)
>>>>>>> miniblink49
{
    m_client->speakingErrorOccurred(utterance);
}

<<<<<<< HEAD
void WebSpeechSynthesizerClientImpl::wordBoundaryEventOccurred(
    const WebSpeechSynthesisUtterance& utterance,
    unsigned charIndex)
=======
void WebSpeechSynthesizerClientImpl::wordBoundaryEventOccurred(const WebSpeechSynthesisUtterance& utterance, unsigned charIndex)
>>>>>>> miniblink49
{
    m_client->boundaryEventOccurred(utterance, SpeechWordBoundary, charIndex);
}

<<<<<<< HEAD
void WebSpeechSynthesizerClientImpl::sentenceBoundaryEventOccurred(
    const WebSpeechSynthesisUtterance& utterance,
    unsigned charIndex)
=======
void WebSpeechSynthesizerClientImpl::sentenceBoundaryEventOccurred(const WebSpeechSynthesisUtterance& utterance, unsigned charIndex)
>>>>>>> miniblink49
{
    m_client->boundaryEventOccurred(utterance, SpeechSentenceBoundary, charIndex);
}

DEFINE_TRACE(WebSpeechSynthesizerClientImpl)
{
    visitor->trace(m_synthesizer);
    visitor->trace(m_client);
}

} // namespace blink

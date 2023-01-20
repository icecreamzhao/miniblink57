/*
 * Copyright (C) 2013 Apple Computer, Inc.  All rights reserved.
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
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/speech/PlatformSpeechSynthesizer.h"

#include "platform/exported/WebSpeechSynthesizerClientImpl.h"
#include "platform/speech/PlatformSpeechSynthesisUtterance.h"
#include "public/platform/Platform.h"
#include "public/platform/WebSpeechSynthesisUtterance.h"
#include "public/platform/WebSpeechSynthesizer.h"
#include "public/platform/WebSpeechSynthesizerClient.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"

namespace blink {

PlatformSpeechSynthesizer* PlatformSpeechSynthesizer::create(
    PlatformSpeechSynthesizerClient* client)
=======
#include "wtf/RetainPtr.h"

namespace blink {

PlatformSpeechSynthesizer* PlatformSpeechSynthesizer::create(PlatformSpeechSynthesizerClient* client)
>>>>>>> miniblink49
{
    PlatformSpeechSynthesizer* synthesizer = new PlatformSpeechSynthesizer(client);
    synthesizer->initializeVoiceList();
    return synthesizer;
}

<<<<<<< HEAD
PlatformSpeechSynthesizer::PlatformSpeechSynthesizer(
    PlatformSpeechSynthesizerClient* client)
    : m_speechSynthesizerClient(client)
{
    m_webSpeechSynthesizerClient = new WebSpeechSynthesizerClientImpl(this, client);
    m_webSpeechSynthesizer = WTF::wrapUnique(Platform::current()->createSpeechSynthesizer(
        m_webSpeechSynthesizerClient));
}

PlatformSpeechSynthesizer::~PlatformSpeechSynthesizer() { }

void PlatformSpeechSynthesizer::speak(
    PlatformSpeechSynthesisUtterance* utterance)
=======
PlatformSpeechSynthesizer::PlatformSpeechSynthesizer(PlatformSpeechSynthesizerClient* client)
    : m_speechSynthesizerClient(client)
{
    m_webSpeechSynthesizerClient = new WebSpeechSynthesizerClientImpl(this, client);
    m_webSpeechSynthesizer = adoptPtr(Platform::current()->createSpeechSynthesizer(m_webSpeechSynthesizerClient));
}

PlatformSpeechSynthesizer::~PlatformSpeechSynthesizer()
{
}

void PlatformSpeechSynthesizer::speak(PlatformSpeechSynthesisUtterance* utterance)
>>>>>>> miniblink49
{
    if (m_webSpeechSynthesizer && m_webSpeechSynthesizerClient)
        m_webSpeechSynthesizer->speak(WebSpeechSynthesisUtterance(utterance));
}

void PlatformSpeechSynthesizer::pause()
{
<<<<<<< HEAD
    if (m_webSpeechSynthesizer)
=======
    if (m_webSpeechSynthesizer.get())
>>>>>>> miniblink49
        m_webSpeechSynthesizer->pause();
}

void PlatformSpeechSynthesizer::resume()
{
<<<<<<< HEAD
    if (m_webSpeechSynthesizer)
=======
    if (m_webSpeechSynthesizer.get())
>>>>>>> miniblink49
        m_webSpeechSynthesizer->resume();
}

void PlatformSpeechSynthesizer::cancel()
{
<<<<<<< HEAD
    if (m_webSpeechSynthesizer)
        m_webSpeechSynthesizer->cancel();
}

void PlatformSpeechSynthesizer::setVoiceList(
    Vector<RefPtr<PlatformSpeechSynthesisVoice>>& voices)
=======
    if (m_webSpeechSynthesizer.get())
        m_webSpeechSynthesizer->cancel();
}

void PlatformSpeechSynthesizer::setVoiceList(HeapVector<Member<PlatformSpeechSynthesisVoice>>& voices)
>>>>>>> miniblink49
{
    m_voiceList = voices;
}

void PlatformSpeechSynthesizer::initializeVoiceList()
{
<<<<<<< HEAD
    if (m_webSpeechSynthesizer)
=======
    if (m_webSpeechSynthesizer.get())
>>>>>>> miniblink49
        m_webSpeechSynthesizer->updateVoiceList();
}

DEFINE_TRACE(PlatformSpeechSynthesizer)
{
    visitor->trace(m_speechSynthesizerClient);
<<<<<<< HEAD
=======
    visitor->trace(m_voiceList);
>>>>>>> miniblink49
    visitor->trace(m_webSpeechSynthesizerClient);
}

} // namespace blink

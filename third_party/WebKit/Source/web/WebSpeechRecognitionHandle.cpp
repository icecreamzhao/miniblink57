/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
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
#include "public/web/WebSpeechRecognitionHandle.h"

#include "modules/speech/SpeechRecognition.h"

namespace blink {

void WebSpeechRecognitionHandle::reset()
{
    m_private.reset();
}

<<<<<<< HEAD
void WebSpeechRecognitionHandle::assign(
    const WebSpeechRecognitionHandle& other)
=======
void WebSpeechRecognitionHandle::assign(const WebSpeechRecognitionHandle& other)
>>>>>>> miniblink49
{
    m_private = other.m_private;
}

<<<<<<< HEAD
bool WebSpeechRecognitionHandle::equals(
    const WebSpeechRecognitionHandle& other) const
=======
bool WebSpeechRecognitionHandle::equals(const WebSpeechRecognitionHandle& other) const
>>>>>>> miniblink49
{
    return m_private.get() == other.m_private.get();
}

<<<<<<< HEAD
bool WebSpeechRecognitionHandle::lessThan(
    const WebSpeechRecognitionHandle& other) const
=======
bool WebSpeechRecognitionHandle::lessThan(const WebSpeechRecognitionHandle& other) const
>>>>>>> miniblink49
{
    return m_private.get() < other.m_private.get();
}

<<<<<<< HEAD
WebSpeechRecognitionHandle::WebSpeechRecognitionHandle(
    SpeechRecognition* speechRecognition)
=======
WebSpeechRecognitionHandle::WebSpeechRecognitionHandle(SpeechRecognition* speechRecognition)
>>>>>>> miniblink49
    : m_private(speechRecognition)
{
}

WebSpeechRecognitionHandle::operator SpeechRecognition*() const
{
    return m_private.get();
}

} // namespace blink

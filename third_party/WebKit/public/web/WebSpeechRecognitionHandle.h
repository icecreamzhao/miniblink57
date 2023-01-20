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

#ifndef WebSpeechRecognitionHandle_h
#define WebSpeechRecognitionHandle_h

#include "../platform/WebCommon.h"
#include "../platform/WebPrivatePtr.h"

namespace blink {

class SpeechRecognition;

// WebSpeechRecognitionHandle is used by WebSpeechRecognizer to identify a
// recognition session, and by WebSpeechRecognizerClient to route
// recognition events.
class WebSpeechRecognitionHandle {
public:
    ~WebSpeechRecognitionHandle() { reset(); }
    WebSpeechRecognitionHandle() { }

<<<<<<< HEAD
    WebSpeechRecognitionHandle(const WebSpeechRecognitionHandle& other)
    {
        assign(other);
    }
    WebSpeechRecognitionHandle& operator=(
        const WebSpeechRecognitionHandle& other)
=======
    WebSpeechRecognitionHandle(const WebSpeechRecognitionHandle& other) { assign(other); }
    WebSpeechRecognitionHandle& operator=(const WebSpeechRecognitionHandle& other)
>>>>>>> miniblink49
    {
        assign(other);
        return *this;
    }

    BLINK_EXPORT void reset();
    BLINK_EXPORT void assign(const WebSpeechRecognitionHandle&);

<<<<<<< HEAD
    // Comparison functions are provided so that WebSpeechRecognitionHandle
    // objects can be stored in a hash map.
=======
    // Comparison functions are provided so that WebSpeechRecognitionHandle objects
    // can be stored in a hash map.
>>>>>>> miniblink49
    BLINK_EXPORT bool equals(const WebSpeechRecognitionHandle&) const;
    BLINK_EXPORT bool lessThan(const WebSpeechRecognitionHandle&) const;

#if BLINK_IMPLEMENTATION
    WebSpeechRecognitionHandle(SpeechRecognition*);
    operator SpeechRecognition*() const;
#endif

private:
    WebPrivatePtr<SpeechRecognition> m_private;
};

<<<<<<< HEAD
inline bool operator==(const WebSpeechRecognitionHandle& a,
    const WebSpeechRecognitionHandle& b)
=======
inline bool operator==(const WebSpeechRecognitionHandle& a, const WebSpeechRecognitionHandle& b)
>>>>>>> miniblink49
{
    return a.equals(b);
}

<<<<<<< HEAD
inline bool operator!=(const WebSpeechRecognitionHandle& a,
    const WebSpeechRecognitionHandle& b)
=======
inline bool operator!=(const WebSpeechRecognitionHandle& a, const WebSpeechRecognitionHandle& b)
>>>>>>> miniblink49
{
    return !(a == b);
}

<<<<<<< HEAD
inline bool operator<(const WebSpeechRecognitionHandle& a,
    const WebSpeechRecognitionHandle& b)
=======
inline bool operator<(const WebSpeechRecognitionHandle& a, const WebSpeechRecognitionHandle& b)
>>>>>>> miniblink49
{
    return a.lessThan(b);
}

} // namespace blink

#endif // WebSpeechRecognitionHandle_h

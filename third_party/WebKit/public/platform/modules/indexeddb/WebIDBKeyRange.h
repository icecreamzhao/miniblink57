/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebIDBKeyRange_h
#define WebIDBKeyRange_h

#include "public/platform/WebCommon.h"
#include "public/platform/WebPrivatePtr.h"

namespace blink {

class IDBKeyRange;
class WebIDBKey;

class WebIDBKeyRange {
public:
    ~WebIDBKeyRange() { reset(); }

    WebIDBKeyRange() { }
    WebIDBKeyRange(const WebIDBKeyRange& keyRange) { assign(keyRange); }
    WebIDBKeyRange(const WebIDBKey& lower,
        const WebIDBKey& upper,
        bool lowerOpen,
        bool upperOpen)
    {
        assign(lower, upper, lowerOpen, upperOpen);
    }

    BLINK_EXPORT WebIDBKey lower() const;
    BLINK_EXPORT WebIDBKey upper() const;
    BLINK_EXPORT bool lowerOpen() const;
    BLINK_EXPORT bool upperOpen() const;

    BLINK_EXPORT void assign(const WebIDBKeyRange&);
    BLINK_EXPORT void assign(const WebIDBKey& lower,
        const WebIDBKey& upper,
        bool lowerOpen,
        bool upperOpen);

    WebIDBKeyRange& operator=(const WebIDBKeyRange& e)
    {
        assign(e);
        return *this;
    }

// FIXME: when compiling core or modules, use inline for reset.
// when compiling WebIDBKeyRange.cpp, don't use inline to avoid redefinition.
#if !BLINK_WEB_IMPLEMENTATION && BLINK_IMPLEMENTATION && defined(COMPONENT_BUILD)
    BLINK_EXPORT void reset()
    {
        m_private.reset();
    }
#else
    BLINK_EXPORT void reset();
#endif

#if BLINK_IMPLEMENTATION
    WebIDBKeyRange(IDBKeyRange* value)
        : m_private(value)
    {
    }
    WebIDBKeyRange& operator=(IDBKeyRange* value)
    {
        m_private = value;
        return *this;
    }
    operator IDBKeyRange*() const { return m_private.get(); }
#endif

private:
    WebPrivatePtr<IDBKeyRange> m_private;
};

} // namespace blink

#endif // WebIDBKeyRange_h

/*
 * Copyright (C) 2008 Apple Inc. All Rights Reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KURLHash_h
#define KURLHash_h

#include "platform/weborigin/KURL.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/text/StringHash.h"
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
// KURLHash doesn't support null KURLs.  get(), contains(), and add() on
// HashMap<KURL,..., KURLHash> cause a null-pointer dereference when passed null
// KURLs.

struct KURLHash {
    STATIC_ONLY(KURLHash);
    static unsigned hash(const KURL& key)
    {
        return key.getString().impl()->hash();
=======
struct KURLHash {
    static unsigned hash(const KURL& key)
    {
        return key.string().impl()->hash();
>>>>>>> miniblink49
    }

    static bool equal(const KURL& a, const KURL& b)
    {
<<<<<<< HEAD
        return StringHash::equal(a.getString(), b.getString());
=======
        return StringHash::equal(a.string(), b.string());
>>>>>>> miniblink49
    }

    static const bool safeToCompareToEmptyOrDeleted = false;
};

} // namespace blink

namespace WTF {

<<<<<<< HEAD
template <>
struct HashTraits<blink::KURL> : SimpleClassHashTraits<blink::KURL> {
};
=======
template<> struct HashTraits<blink::KURL> : SimpleClassHashTraits<blink::KURL> { };
>>>>>>> miniblink49

} // namespace WTF

#endif // KURLHash_h

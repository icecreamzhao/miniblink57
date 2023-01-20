/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "platform/CrossThreadCopier.h"

#include "platform/network/ResourceError.h"
#include "platform/network/ResourceRequest.h"
#include "platform/network/ResourceResponse.h"
#include "platform/weborigin/KURL.h"
#include "wtf/text/WTFString.h"
<<<<<<< HEAD
#include <memory>

namespace blink {

CrossThreadCopier<KURL>::Type CrossThreadCopier<KURL>::copy(const KURL& url)
=======

namespace blink {

CrossThreadCopierBase<false, false, false, KURL>::Type CrossThreadCopierBase<false, false, false, KURL>::copy(const KURL& url)
>>>>>>> miniblink49
{
    return url.copy();
}

<<<<<<< HEAD
CrossThreadCopier<String>::Type CrossThreadCopier<String>::copy(
    const String& str)
=======
CrossThreadCopierBase<false, false, false, String>::Type CrossThreadCopierBase<false, false, false, String>::copy(const String& str)
>>>>>>> miniblink49
{
    return str.isolatedCopy();
}

<<<<<<< HEAD
CrossThreadCopier<ResourceError>::Type CrossThreadCopier<ResourceError>::copy(
    const ResourceError& error)
=======
CrossThreadCopierBase<false, false, false, ResourceError>::Type CrossThreadCopierBase<false, false, false, ResourceError>::copy(const ResourceError& error)
>>>>>>> miniblink49
{
    return error.copy();
}

<<<<<<< HEAD
CrossThreadCopier<ResourceRequest>::Type
CrossThreadCopier<ResourceRequest>::copy(const ResourceRequest& request)
{
    return WTF::passed(request.copyData());
}

CrossThreadCopier<ResourceResponse>::Type
CrossThreadCopier<ResourceResponse>::copy(const ResourceResponse& response)
{
    return WTF::passed(response.copyData());
=======
CrossThreadCopierBase<false, false, false, ResourceRequest>::Type CrossThreadCopierBase<false, false, false, ResourceRequest>::copy(const ResourceRequest& request)
{
    return request.copyData();
}

CrossThreadCopierBase<false, false, false, ResourceResponse>::Type CrossThreadCopierBase<false, false, false, ResourceResponse>::copy(const ResourceResponse& response)
{
    return response.copyData();
>>>>>>> miniblink49
}

// Test CrossThreadCopier using static_assert.

// Verify that ThreadSafeRefCounted objects get handled correctly.
<<<<<<< HEAD
class CopierThreadSafeRefCountedTest
    : public ThreadSafeRefCounted<CopierThreadSafeRefCountedTest> {
};

// Add a generic specialization which will let's us verify that no other
// template matches.
template <typename T>
struct CrossThreadCopierBase<T, false> {
    typedef int Type;
};

static_assert(
    (std::is_same<PassRefPtr<CopierThreadSafeRefCountedTest>,
        CrossThreadCopier<PassRefPtr<
            CopierThreadSafeRefCountedTest>>::Type>::value),
    "PassRefPtr + ThreadSafeRefCounted should pass CrossThreadCopier");
static_assert(
    (std::is_same<RefPtr<CopierThreadSafeRefCountedTest>,
        CrossThreadCopier<
            RefPtr<CopierThreadSafeRefCountedTest>>::Type>::value),
    "RefPtr + ThreadSafeRefCounted should pass CrossThreadCopier");
static_assert(
    (std::is_same<
        int,
        CrossThreadCopier<CopierThreadSafeRefCountedTest*>::Type>::value),
    "Raw pointer + ThreadSafeRefCounted should NOT pass CrossThreadCopier");

// Verify that RefCounted objects only match our generic template which exposes
// Type as int.
class CopierRefCountedTest : public RefCounted<CopierRefCountedTest> {
};

static_assert(
    (std::is_same<int, CrossThreadCopier<CopierRefCountedTest*>::Type>::value),
    "Raw pointer + RefCounted should NOT pass CrossThreadCopier");

// Verify that std::unique_ptr gets passed through.
static_assert(
    (std::is_same<std::unique_ptr<float>,
        CrossThreadCopier<std::unique_ptr<float>>::Type>::value),
    "std::unique_ptr test");
=======
class CopierThreadSafeRefCountedTest : public ThreadSafeRefCounted<CopierThreadSafeRefCountedTest> {
};

static_assert((WTF::IsSameType<
    PassRefPtr<CopierThreadSafeRefCountedTest>,
    CrossThreadCopier<PassRefPtr<CopierThreadSafeRefCountedTest>>::Type
    >::value),
    "PassRefPtr test");
static_assert((WTF::IsSameType<
    PassRefPtr<CopierThreadSafeRefCountedTest>,
    CrossThreadCopier<RefPtr<CopierThreadSafeRefCountedTest>>::Type
    >::value),
    "RefPtr test");
static_assert((WTF::IsSameType<
    PassRefPtr<CopierThreadSafeRefCountedTest>,
    CrossThreadCopier<CopierThreadSafeRefCountedTest*>::Type
    >::value),
    "RawPointer test");


// Add a generic specialization which will let's us verify that no other template matches.
template<typename T> struct CrossThreadCopierBase<false, false, false, T> {
    typedef int Type;
};

// Verify that RefCounted objects only match our generic template which exposes Type as int.
class CopierRefCountedTest : public RefCounted<CopierRefCountedTest> {
};

static_assert((WTF::IsSameType<
    int,
    CrossThreadCopier<PassRefPtr<CopierRefCountedTest>>::Type
    >::value),
    "PassRefPtr<RefCountedTest> test");

static_assert((WTF::IsSameType<
    int,
    CrossThreadCopier<RefPtr<CopierRefCountedTest>>::Type
    >::value),
    "RefPtr<RefCounted> test");

static_assert((WTF::IsSameType<
    int,
    CrossThreadCopier<CopierRefCountedTest*>::Type
    >::value),
    "Raw pointer RefCounted test");

// Verify that PassOwnPtr gets passed through.
static_assert((WTF::IsSameType<
    PassOwnPtr<float>,
    CrossThreadCopier<PassOwnPtr<float>>::Type
    >::value),
    "PassOwnPtr test");

// Verify that PassOwnPtr does not get passed through.
static_assert((WTF::IsSameType<
    int,
    CrossThreadCopier<OwnPtr<float>>::Type
    >::value),
    "OwnPtr test");
>>>>>>> miniblink49

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef EventDispatchForbiddenScope_h
#define EventDispatchForbiddenScope_h

#include "platform/PlatformExport.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/Assertions.h"
#include "wtf/AutoReset.h"

namespace blink {

#if DCHECK_IS_ON()

class EventDispatchForbiddenScope {
    STACK_ALLOCATED();
    WTF_MAKE_NONCOPYABLE(EventDispatchForbiddenScope);

=======
#include "wtf/Assertions.h"
#include "wtf/MainThread.h"
#include "wtf/TemporaryChange.h"

namespace blink {

#if ENABLE(ASSERT)

class EventDispatchForbiddenScope {
>>>>>>> miniblink49
public:
    EventDispatchForbiddenScope()
    {
        ASSERT(isMainThread());
        ++s_count;
    }

    ~EventDispatchForbiddenScope()
    {
        ASSERT(isMainThread());
        ASSERT(s_count);
        --s_count;
    }

    static bool isEventDispatchForbidden()
    {
        if (!isMainThread())
            return false;
        return s_count;
    }

    class AllowUserAgentEvents {
<<<<<<< HEAD
        STACK_ALLOCATED();

    public:
        AllowUserAgentEvents()
            : m_change(&s_count, 0)
=======
    public:
        AllowUserAgentEvents()
            : m_change(s_count, 0)
>>>>>>> miniblink49
        {
            ASSERT(isMainThread());
        }

<<<<<<< HEAD
        ~AllowUserAgentEvents() { ASSERT(!s_count); }

        AutoReset<unsigned> m_change;
=======
        ~AllowUserAgentEvents()
        {
            ASSERT(!s_count);
        }

        TemporaryChange<unsigned> m_change;
>>>>>>> miniblink49
    };

private:
    PLATFORM_EXPORT static unsigned s_count;
};

#else

class EventDispatchForbiddenScope {
<<<<<<< HEAD
    STACK_ALLOCATED();
    WTF_MAKE_NONCOPYABLE(EventDispatchForbiddenScope);

=======
>>>>>>> miniblink49
public:
    EventDispatchForbiddenScope() { }

    class AllowUserAgentEvents {
    public:
        AllowUserAgentEvents() { }
    };
};

<<<<<<< HEAD
#endif // DCHECK_IS_ON()
=======
#endif // ENABLE(ASSERT)
>>>>>>> miniblink49

} // namespace blink

#endif // EventDispatchForbiddenScope_h

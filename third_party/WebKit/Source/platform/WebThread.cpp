// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "public/platform/WebThread.h"

#include "platform/WebTaskRunner.h"
#include "third_party/WebKit/Source/platform/Task.h"
#include "wtf/Assertions.h"
=======
#include "config.h"
#include "public/platform/WebThread.h"

#include "platform/Task.h"
#include "public/platform/WebTraceLocation.h"
#include "wtf/Assertions.h"
#include "wtf/OwnPtr.h"
>>>>>>> miniblink49

#if OS(WIN)
#include <windows.h>
#elif OS(POSIX)
#include <unistd.h>
#endif

namespace blink {

#if OS(WIN)
<<<<<<< HEAD
static_assert(sizeof(blink::PlatformThreadId) >= sizeof(DWORD),
    "size of platform thread id is too small");
#elif OS(POSIX)
static_assert(sizeof(blink::PlatformThreadId) >= sizeof(pid_t),
    "size of platform thread id is too small");
=======
static_assert(sizeof(blink::PlatformThreadId) >= sizeof(DWORD), "size of platform thread id is too small");
#elif OS(POSIX)
static_assert(sizeof(blink::PlatformThreadId) >= sizeof(pid_t), "size of platform thread id is too small");
>>>>>>> miniblink49
#else
#error Unexpected platform
#endif

<<<<<<< HEAD
base::SingleThreadTaskRunner* WebThread::getSingleThreadTaskRunner()
{
    return getWebTaskRunner()->toSingleThreadTaskRunner();
}

void WebThread::postTask(const WebTraceLocation& location, std::unique_ptr<Function<void()>> func)
{
    postTask(location, new blink::Task(std::move(func)));
}

class CrossThreadTask : public WebThread::Task {
public:
    explicit CrossThreadTask(std::unique_ptr<Function<void(), WTF::CrossThreadAffinity> > closure)
        : m_closure(std::move(closure))
    {
    }

    void run() override
    {
        (*m_closure)();
    }

private:
    std::unique_ptr<Function<void(), WTF::CrossThreadAffinity> > m_closure;
};

void WebThread::postTask(const WebTraceLocation& location, std::unique_ptr<Function<void(), WTF::CrossThreadAffinity> > func)
{
    postTask(location, new blink::CrossThreadTask(std::move(func)));
}

void WebThread::postDelayedTask(const WebTraceLocation& location, std::unique_ptr<Function<void()>> func, long long delayMs)
{
    postDelayedTask(location, new blink::Task(std::move(func)), delayMs);
}

void WebThread::postDelayedTask(const WebTraceLocation& location, std::unique_ptr<Function<void(), WTF::CrossThreadAffinity>> func, long long delayMs)
{
    postDelayedTask(location, new blink::CrossThreadTask(std::move(func)), delayMs);
=======
void WebThread::postTask(const WebTraceLocation& location, PassOwnPtr<Function<void()>> function)
{
    postTask(location, new blink::Task(function));
}

void WebThread::postDelayedTask(const WebTraceLocation& location, PassOwnPtr<Function<void()>> function, long long delayMs)
{
    postDelayedTask(location, new blink::Task(function), delayMs);
>>>>>>> miniblink49
}

} // namespace blink

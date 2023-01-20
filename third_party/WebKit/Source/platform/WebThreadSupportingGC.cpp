// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/WebThreadSupportingGC.h"

#include "platform/heap/SafePoint.h"
#include "public/platform/WebScheduler.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include "wtf/Threading.h"
#include <memory>

namespace blink {

std::unique_ptr<WebThreadSupportingGC> WebThreadSupportingGC::create(
    const char* name)
{
    return WTF::wrapUnique(new WebThreadSupportingGC(name, nullptr));
}

std::unique_ptr<WebThreadSupportingGC> WebThreadSupportingGC::createForThread(
    WebThread* thread)
{
    return WTF::wrapUnique(new WebThreadSupportingGC(nullptr, thread));
}

WebThreadSupportingGC::WebThreadSupportingGC(const char* name,
    WebThread* thread)
    : m_thread(thread)
{
    DCHECK(!name || !thread);
#if DCHECK_IS_ON()
    // We call this regardless of whether an existing thread is given or not,
    // as it means that blink is going to run with more than one thread.
    WTF::willCreateThread();
#endif
    if (!m_thread) {
        // If |thread| is not given, create a new one and own it.
        m_owningThread = WTF::wrapUnique(Platform::current()->createThread(name));
        m_thread = m_owningThread.get();
    }
=======
#include "wtf/Threading.h"

namespace blink {

PassOwnPtr<WebThreadSupportingGC> WebThreadSupportingGC::create(const char* name)
{
#if ENABLE(ASSERT)
    WTF::willCreateThread();
#endif
    return adoptPtr(new WebThreadSupportingGC(name));
}

WebThreadSupportingGC::WebThreadSupportingGC(const char* name)
    : m_thread(adoptPtr(Platform::current()->createThread(name)))
{
>>>>>>> miniblink49
}

WebThreadSupportingGC::~WebThreadSupportingGC()
{
<<<<<<< HEAD
    if (ThreadState::current() && m_owningThread) {
        // WebThread's destructor blocks until all the tasks are processed.
        SafePointScope scope(BlinkGC::HeapPointersOnStack);
        m_owningThread.reset();
=======
    if (ThreadState::current()) {
        // WebThread's destructor blocks until all the tasks are processed.
        SafePointScope scope(ThreadState::HeapPointersOnStack);
        m_thread.clear();
>>>>>>> miniblink49
    }
}

void WebThreadSupportingGC::initialize()
{
<<<<<<< HEAD
    ThreadState::attachCurrentThread();
    m_gcTaskRunner = WTF::makeUnique<GCTaskRunner>(m_thread);
=======
    m_pendingGCRunner = adoptPtr(new PendingGCRunner);
    m_messageLoopInterruptor = adoptPtr(new MessageLoopInterruptor(&platformThread()));
    platformThread().addTaskObserver(m_pendingGCRunner.get());
    ThreadState::attach();
    ThreadState::current()->addInterruptor(m_messageLoopInterruptor.get());
>>>>>>> miniblink49
}

void WebThreadSupportingGC::shutdown()
{
<<<<<<< HEAD
#if defined(LEAK_SANITIZER)
    ThreadState::current()->releaseStaticPersistentNodes();
#endif
    // Ensure no posted tasks will run from this point on.
    m_gcTaskRunner.reset();

    // Shutdown the thread (via its scheduler) only when the thread is created
    // and is owned by this instance.
    if (m_owningThread)
        m_owningThread->scheduler()->shutdown();

    ThreadState::detachCurrentThread();
=======
    // Ensure no posted tasks will run from this point on.
    platformThread().removeTaskObserver(m_pendingGCRunner.get());
    platformThread().scheduler()->shutdown();

    ThreadState::current()->removeInterruptor(m_messageLoopInterruptor.get());
    ThreadState::detach();
    m_pendingGCRunner = nullptr;
    m_messageLoopInterruptor = nullptr;
>>>>>>> miniblink49
}

} // namespace blink

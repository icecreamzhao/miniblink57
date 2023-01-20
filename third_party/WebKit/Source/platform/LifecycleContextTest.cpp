/*
 * Copyright (C) 2013 Google Inc. All Rights Reserved.
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
 *
 */

<<<<<<< HEAD
#include "platform/LifecycleNotifier.h"
#include "platform/LifecycleObserver.h"
#include "platform/heap/Handle.h"
#include "testing/gtest/include/gtest/gtest.h"
=======
#include "config.h"

#include "platform/LifecycleNotifier.h"
#include "platform/LifecycleObserver.h"
#include "platform/heap/Handle.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {

class TestingObserver;

<<<<<<< HEAD
class DummyContext final
    : public GarbageCollectedFinalized<DummyContext>,
      public LifecycleNotifier<DummyContext, TestingObserver> {
    USING_GARBAGE_COLLECTED_MIXIN(DummyContext);

public:
    static DummyContext* create() { return new DummyContext; }
=======
class DummyContext final : public NoBaseWillBeGarbageCollectedFinalized<DummyContext>, public LifecycleNotifier<DummyContext, TestingObserver> {
public:
    static PassOwnPtrWillBeRawPtr<DummyContext> create()
    {
        return adoptPtrWillBeNoop(new DummyContext());
    }
>>>>>>> miniblink49

    DEFINE_INLINE_TRACE()
    {
        LifecycleNotifier<DummyContext, TestingObserver>::trace(visitor);
    }
};

<<<<<<< HEAD
class TestingObserver final
    : public GarbageCollected<TestingObserver>,
      public LifecycleObserver<DummyContext, TestingObserver> {
    USING_GARBAGE_COLLECTED_MIXIN(TestingObserver);

public:
    static TestingObserver* create(DummyContext* context)
    {
        return new TestingObserver(context);
    }

    void contextDestroyed(DummyContext* destroyedContext)
    {
        if (m_observerToRemoveOnDestruct) {
            destroyedContext->removeObserver(m_observerToRemoveOnDestruct);
=======
class TestingObserver final : public NoBaseWillBeGarbageCollectedFinalized<TestingObserver>, public LifecycleObserver<DummyContext, TestingObserver, DummyContext> {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(TestingObserver);
public:
    static PassOwnPtrWillBeRawPtr<TestingObserver> create(DummyContext* context)
    {
        return adoptPtrWillBeNoop(new TestingObserver(context));
    }

    void contextDestroyed() override
    {
        LifecycleObserver::contextDestroyed();
        if (m_observerToRemoveOnDestruct) {
            lifecycleContext()->removeObserver(m_observerToRemoveOnDestruct.get());
>>>>>>> miniblink49
            m_observerToRemoveOnDestruct.clear();
        }
        m_contextDestroyedCalled = true;
    }

    DEFINE_INLINE_TRACE()
    {
        visitor->trace(m_observerToRemoveOnDestruct);
        LifecycleObserver::trace(visitor);
    }

    void unobserve() { setContext(nullptr); }

<<<<<<< HEAD
    void setObserverToRemoveAndDestroy(
        TestingObserver* observerToRemoveOnDestruct)
=======
    void setObserverToRemoveAndDestroy(PassOwnPtrWillBeRawPtr<TestingObserver> observerToRemoveOnDestruct)
>>>>>>> miniblink49
    {
        ASSERT(!m_observerToRemoveOnDestruct);
        m_observerToRemoveOnDestruct = observerToRemoveOnDestruct;
    }

<<<<<<< HEAD
    TestingObserver* innerObserver() const
    {
        return m_observerToRemoveOnDestruct;
    }
=======
    TestingObserver* innerObserver() const { return m_observerToRemoveOnDestruct.get(); }
>>>>>>> miniblink49
    bool contextDestroyedCalled() const { return m_contextDestroyedCalled; }

private:
    explicit TestingObserver(DummyContext* context)
        : LifecycleObserver(context)
        , m_contextDestroyedCalled(false)
    {
    }

<<<<<<< HEAD
    Member<TestingObserver> m_observerToRemoveOnDestruct;
=======
    OwnPtrWillBeMember<TestingObserver> m_observerToRemoveOnDestruct;
>>>>>>> miniblink49
    bool m_contextDestroyedCalled;
};

TEST(LifecycleContextTest, shouldObserveContextDestroyed)
{
<<<<<<< HEAD
    DummyContext* context = DummyContext::create();
    Persistent<TestingObserver> observer = TestingObserver::create(context);

    EXPECT_EQ(observer->lifecycleContext(), context);
    EXPECT_FALSE(observer->contextDestroyedCalled());
    context->notifyContextDestroyed();
    context = nullptr;
    ThreadState::current()->collectAllGarbage();
=======
    OwnPtrWillBeRawPtr<DummyContext> context = DummyContext::create();
    OwnPtrWillBePersistent<TestingObserver> observer = TestingObserver::create(context.get());

    EXPECT_EQ(observer->lifecycleContext(), context.get());
    EXPECT_FALSE(observer->contextDestroyedCalled());
    context->notifyContextDestroyed();
    context = nullptr;
    Heap::collectAllGarbage();
>>>>>>> miniblink49
    EXPECT_EQ(observer->lifecycleContext(), static_cast<DummyContext*>(0));
    EXPECT_TRUE(observer->contextDestroyedCalled());
}

TEST(LifecycleContextTest, shouldNotObserveContextDestroyedIfUnobserve)
{
<<<<<<< HEAD
    DummyContext* context = DummyContext::create();
    Persistent<TestingObserver> observer = TestingObserver::create(context);
    observer->unobserve();
    context->notifyContextDestroyed();
    context = nullptr;
    ThreadState::current()->collectAllGarbage();
=======
    OwnPtrWillBeRawPtr<DummyContext> context = DummyContext::create();
    OwnPtrWillBePersistent<TestingObserver> observer = TestingObserver::create(context.get());
    observer->unobserve();
    context->notifyContextDestroyed();
    context = nullptr;
    Heap::collectAllGarbage();
>>>>>>> miniblink49
    EXPECT_EQ(observer->lifecycleContext(), static_cast<DummyContext*>(0));
    EXPECT_FALSE(observer->contextDestroyedCalled());
}

TEST(LifecycleContextTest, observerRemovedDuringNotifyDestroyed)
{
<<<<<<< HEAD
    DummyContext* context = DummyContext::create();
    Persistent<TestingObserver> observer = TestingObserver::create(context);
    TestingObserver* innerObserver = TestingObserver::create(context);
    // Attach the observer to the other. When 'observer' is notified
    // of destruction, it will remove & destroy 'innerObserver'.
    observer->setObserverToRemoveAndDestroy(innerObserver);

    EXPECT_EQ(observer->lifecycleContext(), context);
    EXPECT_EQ(observer->innerObserver()->lifecycleContext(), context);
=======
    // FIXME: Oilpan: this test can be removed when the LifecycleNotifier<T>::m_observers
    // hash set is on the heap and membership is handled implicitly by the garbage collector.
    OwnPtrWillBeRawPtr<DummyContext> context = DummyContext::create();
    OwnPtrWillBePersistent<TestingObserver> observer = TestingObserver::create(context.get());
    OwnPtrWillBeRawPtr<TestingObserver> innerObserver = TestingObserver::create(context.get());
    // Attach the observer to the other. When 'observer' is notified
    // of destruction, it will remove & destroy 'innerObserver'.
    observer->setObserverToRemoveAndDestroy(innerObserver.release());

    EXPECT_EQ(observer->lifecycleContext(), context.get());
    EXPECT_EQ(observer->innerObserver()->lifecycleContext(), context.get());
>>>>>>> miniblink49
    EXPECT_FALSE(observer->contextDestroyedCalled());
    EXPECT_FALSE(observer->innerObserver()->contextDestroyedCalled());

    context->notifyContextDestroyed();
    EXPECT_EQ(observer->innerObserver(), nullptr);
    context = nullptr;
<<<<<<< HEAD
    ThreadState::current()->collectAllGarbage();
=======
    Heap::collectAllGarbage();
>>>>>>> miniblink49
    EXPECT_EQ(observer->lifecycleContext(), static_cast<DummyContext*>(0));
    EXPECT_TRUE(observer->contextDestroyedCalled());
}

} // namespace blink

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FetchManager_h
#define FetchManager_h

#include "bindings/core/v8/ScriptPromise.h"
<<<<<<< HEAD
#include "core/dom/ContextLifecycleObserver.h"
#include "platform/heap/Handle.h"
=======
#include "wtf/HashSet.h"
#include "wtf/OwnPtr.h"
>>>>>>> miniblink49

namespace blink {

class ExecutionContext;
class FetchRequestData;
class ScriptState;

<<<<<<< HEAD
class FetchManager final : public GarbageCollected<FetchManager>,
                           public ContextLifecycleObserver {
    USING_GARBAGE_COLLECTED_MIXIN(FetchManager);

public:
    static FetchManager* create(ExecutionContext*);
    ScriptPromise fetch(ScriptState*, FetchRequestData*);
    void contextDestroyed(ExecutionContext*) override;
=======
class FetchManager final : public NoBaseWillBeGarbageCollectedFinalized<FetchManager> {
public:
    static PassOwnPtrWillBeRawPtr<FetchManager> create(ExecutionContext* executionContext)
    {
        return adoptPtrWillBeNoop(new FetchManager(executionContext));
    }
    ~FetchManager();
    ScriptPromise fetch(ScriptState*, FetchRequestData*);
    void stop();
    bool isStopped() const { return m_isStopped; }
>>>>>>> miniblink49

    DECLARE_TRACE();

private:
<<<<<<< HEAD
    explicit FetchManager(ExecutionContext*);

    class Loader;

    // Removes loader from |m_loaders|.
    void onLoaderFinished(Loader*);

    HeapHashSet<Member<Loader>> m_loaders;
=======
    class Loader;

    explicit FetchManager(ExecutionContext*);
    // Removes loader from |m_loaders|.
    void onLoaderFinished(Loader*);

    RawPtrWillBeMember<ExecutionContext> m_executionContext;
    WillBeHeapHashSet<OwnPtrWillBeMember<Loader>> m_loaders;
    bool m_isStopped;
>>>>>>> miniblink49
};

} // namespace blink

#endif // FetchManager_h

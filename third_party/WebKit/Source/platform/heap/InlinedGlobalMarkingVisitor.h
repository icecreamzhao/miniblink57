// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef InlinedGlobalMarkingVisitor_h
#define InlinedGlobalMarkingVisitor_h

#include "platform/heap/MarkingVisitorImpl.h"

namespace blink {

<<<<<<< HEAD
class InlinedGlobalMarkingVisitor final
    : public VisitorHelper<InlinedGlobalMarkingVisitor>,
      public MarkingVisitorImpl<InlinedGlobalMarkingVisitor> {
=======
class InlinedGlobalMarkingVisitor final : public VisitorHelper<InlinedGlobalMarkingVisitor>, public MarkingVisitorImpl<InlinedGlobalMarkingVisitor> {
>>>>>>> miniblink49
public:
    friend class VisitorHelper<InlinedGlobalMarkingVisitor>;
    using Helper = VisitorHelper<InlinedGlobalMarkingVisitor>;
    friend class MarkingVisitorImpl<InlinedGlobalMarkingVisitor>;
    using Impl = MarkingVisitorImpl<InlinedGlobalMarkingVisitor>;

<<<<<<< HEAD
    InlinedGlobalMarkingVisitor(ThreadState* state,
        VisitorMarkingMode markingMode)
        : VisitorHelper(state, markingMode)
    {
=======
    explicit InlinedGlobalMarkingVisitor(Visitor* visitor)
        : m_visitor(visitor)
    {
        ASSERT(visitor->markingMode() == Visitor::GlobalMarking);
>>>>>>> miniblink49
    }

    // Hack to unify interface to visitor->trace().
    // Without this hack, we need to use visitor.trace() for
<<<<<<< HEAD
    // trace(InlinedGlobalMarkingVisitor) and visitor->trace() for
    // trace(Visitor*).
    InlinedGlobalMarkingVisitor* operator->() { return this; }

    using Impl::ensureMarked;
    using Impl::mark;
    using Impl::registerDelayedMarkNoTracing;
    using Impl::registerWeakMembers;
    using Impl::registerWeakTable;
#if DCHECK_IS_ON()
    using Impl::weakTableRegistered;
#endif

    template <typename T>
=======
    // trace(InlinedGlobalMarkingVisitor) and visitor->trace() for trace(Visitor*).
    InlinedGlobalMarkingVisitor* operator->() { return this; }

    using Impl::mark;
    using Impl::ensureMarked;
    using Impl::registerDelayedMarkNoTracing;
    using Impl::registerWeakTable;
    using Impl::registerWeakMembers;
#if ENABLE(ASSERT)
    using Impl::weakTableRegistered;
#endif

    template<typename T>
>>>>>>> miniblink49
    void mark(T* t)
    {
        Helper::mark(t);
    }

<<<<<<< HEAD
    template <typename T, void (T::*method)(Visitor*)>
=======
    template<typename T, void (T::*method)(Visitor*)>
>>>>>>> miniblink49
    void registerWeakMembers(const T* obj)
    {
        Helper::template registerWeakMembers<T, method>(obj);
    }

<<<<<<< HEAD
=======
    Visitor* getUninlined() { return m_visitor; }
protected:
    // Methods to be called from MarkingVisitorImpl.

    inline bool shouldMarkObject(const void*)
    {
        // As this is global marking visitor, we need to mark all objects.
        return true;
    }

    inline Visitor::MarkingMode markingMode() const
    {
        return m_visitor->markingMode();
    }

>>>>>>> miniblink49
private:
    static InlinedGlobalMarkingVisitor fromHelper(Helper* helper)
    {
        return *static_cast<InlinedGlobalMarkingVisitor*>(helper);
    }
<<<<<<< HEAD
};

inline void GarbageCollectedMixin::trace(InlinedGlobalMarkingVisitor) { }
=======

    Visitor* m_visitor;
};

inline void GarbageCollectedMixin::trace(InlinedGlobalMarkingVisitor)
{
}
>>>>>>> miniblink49

} // namespace blink

#endif

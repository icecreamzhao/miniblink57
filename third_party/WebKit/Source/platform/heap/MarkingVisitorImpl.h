// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MarkingVisitorImpl_h
#define MarkingVisitorImpl_h

#include "platform/heap/Heap.h"
#include "platform/heap/ThreadState.h"
#include "platform/heap/Visitor.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
#include "wtf/Functional.h"
#include "wtf/HashFunctions.h"
#include "wtf/Locker.h"
#include "wtf/RawPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/TypeTraits.h"
>>>>>>> miniblink49

namespace blink {

template <typename Derived>
class MarkingVisitorImpl {
<<<<<<< HEAD
    USING_FAST_MALLOC(MarkingVisitorImpl);

protected:
    inline void markHeader(HeapObjectHeader* header,
        const void* objectPointer,
        TraceCallback callback)
    {
        ASSERT(header);
        ASSERT(objectPointer);
=======
protected:
    inline void markHeader(HeapObjectHeader* header, const void* objectPointer, TraceCallback callback)
    {
        ASSERT(header);
        ASSERT(objectPointer);
        if (!toDerived()->shouldMarkObject(objectPointer))
            return;
>>>>>>> miniblink49

        // If you hit this ASSERT, it means that there is a dangling pointer
        // from a live thread heap to a dead thread heap.  We must eliminate
        // the dangling pointer.
        // Release builds don't have the ASSERT, but it is OK because
        // release builds will crash in the following header->isMarked()
<<<<<<< HEAD
        // because all the entries of the orphaned arenas are zapped.
=======
        // because all the entries of the orphaned heaps are zapped.
>>>>>>> miniblink49
        ASSERT(!pageFromObject(objectPointer)->orphaned());

        if (header->isMarked())
            return;

<<<<<<< HEAD
        ASSERT(ThreadState::current()->isInGC());
        DCHECK(toDerived()->getMarkingMode() != VisitorMarkingMode::WeakProcessing);

        // A GC should only mark the objects that belong in its heap.
        DCHECK(&pageFromObject(objectPointer)->arena()->getThreadState()->heap() == &toDerived()->heap());

        header->mark();

        if (callback)
            toDerived()->heap().pushTraceCallback(const_cast<void*>(objectPointer),
                callback);
=======
#if ENABLE(ASSERT)
        ASSERT(ThreadState::current()->isInGC());
        ASSERT(Heap::findPageFromAddress(header));
        ASSERT(toDerived()->markingMode() != Visitor::WeakProcessing);
#endif
        header->mark();

        if (callback)
            Heap::pushTraceCallback(const_cast<void*>(objectPointer), callback);
>>>>>>> miniblink49
    }

    inline void mark(const void* objectPointer, TraceCallback callback)
    {
        if (!objectPointer)
            return;
        HeapObjectHeader* header = HeapObjectHeader::fromPayload(objectPointer);
        markHeader(header, header->payload(), callback);
    }

    inline void registerDelayedMarkNoTracing(const void* objectPointer)
    {
<<<<<<< HEAD
        DCHECK(toDerived()->getMarkingMode() != VisitorMarkingMode::WeakProcessing);
        toDerived()->heap().pushPostMarkingCallback(
            const_cast<void*>(objectPointer), &markNoTracingCallback);
    }

    inline void registerWeakMembers(const void* closure,
        const void* objectPointer,
        WeakCallback callback)
    {
        DCHECK(toDerived()->getMarkingMode() != VisitorMarkingMode::WeakProcessing);
        // We don't want to run weak processings when taking a snapshot.
        if (toDerived()->getMarkingMode() == VisitorMarkingMode::SnapshotMarking)
            return;
        toDerived()->heap().pushThreadLocalWeakCallback(
            const_cast<void*>(closure), const_cast<void*>(objectPointer), callback);
    }

    inline void registerWeakTable(const void* closure,
        EphemeronCallback iterationCallback,
        EphemeronCallback iterationDoneCallback)
    {
        DCHECK(toDerived()->getMarkingMode() != VisitorMarkingMode::WeakProcessing);
        toDerived()->heap().registerWeakTable(
            const_cast<void*>(closure), iterationCallback, iterationDoneCallback);
    }

#if DCHECK_IS_ON()
    inline bool weakTableRegistered(const void* closure)
    {
        return toDerived()->heap().weakTableRegistered(closure);
    }
#endif

    inline void registerMovingObjectReference(MovableReference* slot)
    {
        DCHECK(toDerived()->getMarkingMode() == VisitorMarkingMode::GlobalMarkingWithCompaction);
        toDerived()->heap().registerMovingObjectReference(slot);
    }

    inline void registerMovingObjectCallback(MovableReference reference,
        MovingObjectCallback callback,
        void* callbackData)
    {
        DCHECK(toDerived()->getMarkingMode() == VisitorMarkingMode::GlobalMarkingWithCompaction);
        toDerived()->heap().registerMovingObjectCallback(reference, callback,
            callbackData);
    }

=======
        ASSERT(toDerived()->markingMode() != Visitor::WeakProcessing);
        Heap::pushPostMarkingCallback(const_cast<void*>(objectPointer), &markNoTracingCallback);
    }

    inline void registerWeakMembers(const void* closure, const void* objectPointer, WeakCallback callback)
    {
        ASSERT(toDerived()->markingMode() != Visitor::WeakProcessing);
        // We don't want to run weak processings when taking a snapshot.
        if (toDerived()->markingMode() == Visitor::SnapshotMarking)
            return;
        Heap::pushThreadLocalWeakCallback(const_cast<void*>(closure), const_cast<void*>(objectPointer), callback);
    }

    inline void registerWeakTable(const void* closure, EphemeronCallback iterationCallback, EphemeronCallback iterationDoneCallback)
    {
        ASSERT(toDerived()->markingMode() != Visitor::WeakProcessing);
        Heap::registerWeakTable(const_cast<void*>(closure), iterationCallback, iterationDoneCallback);
    }

#if ENABLE(ASSERT)
    inline bool weakTableRegistered(const void* closure)
    {
        return Heap::weakTableRegistered(closure);
    }
#endif

>>>>>>> miniblink49
    inline bool ensureMarked(const void* objectPointer)
    {
        if (!objectPointer)
            return false;
<<<<<<< HEAD

        HeapObjectHeader* header = HeapObjectHeader::fromPayload(objectPointer);
        if (header->isMarked())
            return false;
#if DCHECK_IS_ON()
        toDerived()->markNoTracing(objectPointer);
#else
        // Inline what the above markNoTracing() call expands to,
        // so as to make sure that we do get all the benefits (asserts excepted.)
=======
        if (!toDerived()->shouldMarkObject(objectPointer))
            return false;
#if ENABLE(ASSERT)
        if (HeapObjectHeader::fromPayload(objectPointer)->isMarked())
            return false;

        toDerived()->markNoTracing(objectPointer);
#else
        // Inline what the above markNoTracing() call expands to,
        // so as to make sure that we do get all the benefits.
        HeapObjectHeader* header = HeapObjectHeader::fromPayload(objectPointer);
        if (header->isMarked())
            return false;
>>>>>>> miniblink49
        header->mark();
#endif
        return true;
    }

<<<<<<< HEAD
    inline void registerWeakCellWithCallback(void** cell, WeakCallback callback)
    {
        DCHECK(toDerived()->getMarkingMode() != VisitorMarkingMode::WeakProcessing);
        // We don't want to run weak processings when taking a snapshot.
        if (toDerived()->getMarkingMode() == VisitorMarkingMode::SnapshotMarking)
            return;
        toDerived()->heap().pushGlobalWeakCallback(cell, callback);
    }

    Derived* toDerived() { return static_cast<Derived*>(this); }
=======
    Derived* toDerived()
    {
        return static_cast<Derived*>(this);
    }

protected:
    inline void registerWeakCellWithCallback(void** cell, WeakCallback callback)
    {
        ASSERT(toDerived()->markingMode() != Visitor::WeakProcessing);
        // We don't want to run weak processings when taking a snapshot.
        if (toDerived()->markingMode() == Visitor::SnapshotMarking)
            return;
        Heap::pushGlobalWeakCallback(cell, callback);
    }
>>>>>>> miniblink49

private:
    static void markNoTracingCallback(Visitor* visitor, void* object)
    {
        visitor->markNoTracing(object);
    }
};

} // namespace blink

#endif

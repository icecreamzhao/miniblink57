// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HeapAllocator_h
#define HeapAllocator_h

#include "platform/heap/Heap.h"
<<<<<<< HEAD
#include "platform/heap/Persistent.h"
#include "platform/heap/TraceTraits.h"
#include "wtf/Allocator.h"
#include "wtf/Assertions.h"
=======
#include "platform/heap/TraceTraits.h"
#include "wtf/Assertions.h"
#include "wtf/Atomics.h"
>>>>>>> miniblink49
#include "wtf/Deque.h"
#include "wtf/HashCountedSet.h"
#include "wtf/HashMap.h"
#include "wtf/HashSet.h"
#include "wtf/HashTable.h"
#include "wtf/LinkedHashSet.h"
#include "wtf/ListHashSet.h"
#include "wtf/TypeTraits.h"
#include "wtf/Vector.h"

namespace blink {

<<<<<<< HEAD
template <typename T, typename Traits = WTF::VectorTraits<T>>
class HeapVectorBacking {
    DISALLOW_NEW();
    IS_GARBAGE_COLLECTED_TYPE();

public:
    static void finalize(void* pointer);
    void finalizeGarbageCollectedObject() { finalize(this); }
};

template <typename Table>
class HeapHashTableBacking {
    DISALLOW_NEW();
    IS_GARBAGE_COLLECTED_TYPE();

public:
    static void finalize(void* pointer);
    void finalizeGarbageCollectedObject() { finalize(this); }
};

// This is a static-only class used as a trait on collections to make them heap
// allocated.  However see also HeapListHashSetAllocator.
class PLATFORM_EXPORT HeapAllocator {
    STATIC_ONLY(HeapAllocator);

=======
// This is a static-only class used as a trait on collections to make them heap
// allocated.  However see also HeapListHashSetAllocator.
class PLATFORM_EXPORT HeapAllocator {
>>>>>>> miniblink49
public:
    using Visitor = blink::Visitor;
    static const bool isGarbageCollected = true;

<<<<<<< HEAD
    template <typename T>
    static size_t quantizedSize(size_t count)
    {
        RELEASE_ASSERT(count <= maxHeapObjectSize / sizeof(T));
        return ThreadHeap::allocationSizeFromSize(count * sizeof(T)) - sizeof(HeapObjectHeader);
=======
    template<typename T>
    static size_t quantizedSize(size_t count)
    {
        RELEASE_ASSERT(count <= maxHeapObjectSize / sizeof(T));
        return Heap::allocationSizeFromSize(count * sizeof(T)) - sizeof(HeapObjectHeader);
>>>>>>> miniblink49
    }
    template <typename T>
    static T* allocateVectorBacking(size_t size)
    {
        ThreadState* state = ThreadStateFor<ThreadingTrait<T>::Affinity>::state();
        ASSERT(state->isAllocationAllowed());
<<<<<<< HEAD
        size_t gcInfoIndex = GCInfoTrait<HeapVectorBacking<T>>::index();
        NormalPageArena* arena = static_cast<NormalPageArena*>(state->vectorBackingArena(gcInfoIndex));
        return reinterpret_cast<T*>(arena->allocateObject(
            ThreadHeap::allocationSizeFromSize(size), gcInfoIndex));
=======
        size_t gcInfoIndex = GCInfoTrait<HeapVectorBacking<T, VectorTraits<T>>>::index();
        NormalPageHeap* heap = static_cast<NormalPageHeap*>(state->vectorBackingHeap(gcInfoIndex));
        return reinterpret_cast<T*>(heap->allocateObject(Heap::allocationSizeFromSize(size), gcInfoIndex));
>>>>>>> miniblink49
    }
    template <typename T>
    static T* allocateExpandedVectorBacking(size_t size)
    {
        ThreadState* state = ThreadStateFor<ThreadingTrait<T>::Affinity>::state();
        ASSERT(state->isAllocationAllowed());
<<<<<<< HEAD
        size_t gcInfoIndex = GCInfoTrait<HeapVectorBacking<T>>::index();
        NormalPageArena* arena = static_cast<NormalPageArena*>(
            state->expandedVectorBackingArena(gcInfoIndex));
        return reinterpret_cast<T*>(arena->allocateObject(
            ThreadHeap::allocationSizeFromSize(size), gcInfoIndex));
    }
    static void freeVectorBacking(void*);
    static bool expandVectorBacking(void*, size_t);
    static bool shrinkVectorBacking(void* address,
        size_t quantizedCurrentSize,
        size_t quantizedShrunkSize);
    template <typename T>
    static T* allocateInlineVectorBacking(size_t size)
    {
        size_t gcInfoIndex = GCInfoTrait<HeapVectorBacking<T>>::index();
        ThreadState* state = ThreadStateFor<ThreadingTrait<T>::Affinity>::state();
        const char* typeName = WTF_HEAP_PROFILER_TYPE_NAME(HeapVectorBacking<T>);
        return reinterpret_cast<T*>(ThreadHeap::allocateOnArenaIndex(
            state, size, BlinkGC::InlineVectorArenaIndex, gcInfoIndex, typeName));
    }
    static void freeInlineVectorBacking(void*);
    static bool expandInlineVectorBacking(void*, size_t);
    static bool shrinkInlineVectorBacking(void* address,
        size_t quantizedCurrentSize,
        size_t quantizedShrunkSize);
=======
        size_t gcInfoIndex = GCInfoTrait<HeapVectorBacking<T, VectorTraits<T>>>::index();
        NormalPageHeap* heap = static_cast<NormalPageHeap*>(state->expandedVectorBackingHeap(gcInfoIndex));
        return reinterpret_cast<T*>(heap->allocateObject(Heap::allocationSizeFromSize(size), gcInfoIndex));
    }
    static void freeVectorBacking(void*);
    static bool expandVectorBacking(void*, size_t);
    static bool shrinkVectorBacking(void* address, size_t quantizedCurrentSize, size_t quantizedShrunkSize);
    template <typename T>
    static T* allocateInlineVectorBacking(size_t size)
    {
        size_t gcInfoIndex = GCInfoTrait<HeapVectorBacking<T, VectorTraits<T>>>::index();
        ThreadState* state = ThreadStateFor<ThreadingTrait<T>::Affinity>::state();
        return reinterpret_cast<T*>(Heap::allocateOnHeapIndex(state, size, ThreadState::InlineVectorHeapIndex, gcInfoIndex));
    }
    static void freeInlineVectorBacking(void*);
    static bool expandInlineVectorBacking(void*, size_t);
    static bool shrinkInlineVectorBacking(void* address, size_t quantizedCurrentSize, size_t quantizedShrunkSize);
>>>>>>> miniblink49

    template <typename T, typename HashTable>
    static T* allocateHashTableBacking(size_t size)
    {
        size_t gcInfoIndex = GCInfoTrait<HeapHashTableBacking<HashTable>>::index();
        ThreadState* state = ThreadStateFor<ThreadingTrait<T>::Affinity>::state();
<<<<<<< HEAD
        const char* typeName = WTF_HEAP_PROFILER_TYPE_NAME(HeapHashTableBacking<HashTable>);
        return reinterpret_cast<T*>(ThreadHeap::allocateOnArenaIndex(
            state, size, BlinkGC::HashTableArenaIndex, gcInfoIndex, typeName));
=======
        return reinterpret_cast<T*>(Heap::allocateOnHeapIndex(state, size, ThreadState::HashTableHeapIndex, gcInfoIndex));
>>>>>>> miniblink49
    }
    template <typename T, typename HashTable>
    static T* allocateZeroedHashTableBacking(size_t size)
    {
        return allocateHashTableBacking<T, HashTable>(size);
    }
    static void freeHashTableBacking(void* address);
    static bool expandHashTableBacking(void*, size_t);

    template <typename Return, typename Metadata>
<<<<<<< HEAD
    static Return malloc(size_t size, const char* typeName)
    {
        return reinterpret_cast<Return>(ThreadHeap::allocate<Metadata>(
            size, IsEagerlyFinalizedType<Metadata>::value));
    }

#if OS(WIN) && COMPILER(MSVC) || defined(OS_LINUX)
    // MSVC eagerly instantiates the unused 'operator delete',
    // provide a version that asserts and fails at run-time if
    // used.
    // Elsewhere we expect compilation to fail if 'delete' is
    // attempted used and instantiated with a HeapAllocator-based
    // object, as HeapAllocator::free is not provided.
    static void free(void*) { NOTREACHED(); }
#endif

    template <typename T>
=======
    static Return malloc(size_t size)
    {
        return reinterpret_cast<Return>(Heap::allocate<Metadata>(size, IsEagerlyFinalizedType<Metadata>::value));
    }
    static void free(void* address) { }
    template<typename T>
>>>>>>> miniblink49
    static void* newArray(size_t bytes)
    {
        ASSERT_NOT_REACHED();
        return 0;
    }

<<<<<<< HEAD
    static void deleteArray(void* ptr) { ASSERT_NOT_REACHED(); }
=======
    static void deleteArray(void* ptr)
    {
        ASSERT_NOT_REACHED();
    }
>>>>>>> miniblink49

    static bool isAllocationAllowed()
    {
        return ThreadState::current()->isAllocationAllowed();
    }

<<<<<<< HEAD
    template <typename T>
    static bool isHeapObjectAlive(T* object)
    {
        return ThreadHeap::isHeapObjectAlive(object);
    }

    template <typename VisitorDispatcher>
    static void markNoTracing(VisitorDispatcher visitor, const void* t)
    {
        visitor->markNoTracing(t);
    }

    template <typename VisitorDispatcher, typename T, typename Traits>
    static void trace(VisitorDispatcher visitor, T& t)
    {
        TraceCollectionIfEnabled<WTF::IsTraceableInCollectionTrait<Traits>::value,
            Traits::weakHandlingFlag, WTF::WeakPointersActWeak,
            T, Traits>::trace(visitor, t);
    }

    template <typename VisitorDispatcher>
    static void registerDelayedMarkNoTracing(VisitorDispatcher visitor,
        const void* object)
=======
    template<typename T>
    static bool isHeapObjectAlive(T* object)
    {
        return Heap::isHeapObjectAlive(object);
    }

    template<typename VisitorDispatcher>
    static void markNoTracing(VisitorDispatcher visitor, const void* t) { visitor->markNoTracing(t); }

    template<typename VisitorDispatcher, typename T, typename Traits>
    static void trace(VisitorDispatcher visitor, T& t)
    {
        TraceCollectionIfEnabled<WTF::ShouldBeTraced<Traits>::value, Traits::weakHandlingFlag, WTF::WeakPointersActWeak, T, Traits>::trace(visitor, t);
    }

    template<typename VisitorDispatcher>
    static void registerDelayedMarkNoTracing(VisitorDispatcher visitor, const void* object)
>>>>>>> miniblink49
    {
        visitor->registerDelayedMarkNoTracing(object);
    }

<<<<<<< HEAD
    template <typename VisitorDispatcher>
    static void registerWeakMembers(VisitorDispatcher visitor,
        const void* closure,
        const void* object,
        WeakCallback callback)
=======
    template<typename VisitorDispatcher>
    static void registerWeakMembers(VisitorDispatcher visitor, const void* closure, const void* object, WeakCallback callback)
>>>>>>> miniblink49
    {
        visitor->registerWeakMembers(closure, object, callback);
    }

<<<<<<< HEAD
    template <typename VisitorDispatcher>
    static void registerWeakTable(VisitorDispatcher visitor,
        const void* closure,
        EphemeronCallback iterationCallback,
        EphemeronCallback iterationDoneCallback)
    {
        visitor->registerWeakTable(closure, iterationCallback,
            iterationDoneCallback);
    }

#if DCHECK_IS_ON()
    template <typename VisitorDispatcher>
    static bool weakTableRegistered(VisitorDispatcher visitor,
        const void* closure)
=======
    template<typename VisitorDispatcher>
    static void registerWeakTable(VisitorDispatcher visitor, const void* closure, EphemeronCallback iterationCallback, EphemeronCallback iterationDoneCallback)
    {
        visitor->registerWeakTable(closure, iterationCallback, iterationDoneCallback);
    }

#if ENABLE(ASSERT)
    template<typename VisitorDispatcher>
    static bool weakTableRegistered(VisitorDispatcher visitor, const void* closure)
>>>>>>> miniblink49
    {
        return visitor->weakTableRegistered(closure);
    }
#endif

<<<<<<< HEAD
    template <typename T, typename VisitorDispatcher>
    static void registerBackingStoreReference(VisitorDispatcher visitor,
        T** slot)
    {
        visitor->registerBackingStoreReference(slot);
    }

    template <typename T, typename VisitorDispatcher>
    static void registerBackingStoreCallback(VisitorDispatcher visitor,
        T* backingStore,
        MovingObjectCallback callback,
        void* callbackData)
    {
        visitor->registerBackingStoreCallback(backingStore, callback, callbackData);
=======
    template<typename T>
    struct ResultType {
        using Type = T*;
    };

    template<typename T>
    struct OtherType {
        using Type = T*;
    };

    template<typename T>
    static T& getOther(T* other)
    {
        return *other;
    }

    static void enterNoAllocationScope()
    {
#if ENABLE(ASSERT)
        ThreadState::current()->enterNoAllocationScope();
#endif
    }

    static void leaveNoAllocationScope()
    {
#if ENABLE(ASSERT)
        ThreadState::current()->leaveNoAllocationScope();
#endif
>>>>>>> miniblink49
    }

    static void enterGCForbiddenScope()
    {
        ThreadState::current()->enterGCForbiddenScope();
    }

    static void leaveGCForbiddenScope()
    {
        ThreadState::current()->leaveGCForbiddenScope();
    }

private:
    static void backingFree(void*);
    static bool backingExpand(void*, size_t);
<<<<<<< HEAD
    static bool backingShrink(void*,
        size_t quantizedCurrentSize,
        size_t quantizedShrunkSize);

    template <typename T, size_t u, typename V>
    friend class WTF::Vector;
    template <typename T, typename U, typename V, typename W>
    friend class WTF::HashSet;
    template <typename T,
        typename U,
        typename V,
        typename W,
        typename X,
        typename Y>
    friend class WTF::HashMap;
};

template <typename VisitorDispatcher, typename Value>
=======
    static bool backingShrink(void*, size_t quantizedCurrentSize, size_t quantizedShrunkSize);

    template<typename T, size_t u, typename V> friend class WTF::Vector;
    template<typename T, typename U, typename V, typename W> friend class WTF::HashSet;
    template<typename T, typename U, typename V, typename W, typename X, typename Y> friend class WTF::HashMap;
};

template<typename VisitorDispatcher, typename Value>
>>>>>>> miniblink49
static void traceListHashSetValue(VisitorDispatcher visitor, Value& value)
{
    // We use the default hash traits for the value in the node, because
    // ListHashSet does not let you specify any specific ones.
    // We don't allow ListHashSet of WeakMember, so we set that one false
    // (there's an assert elsewhere), but we have to specify some value for the
    // strongify template argument, so we specify WTF::WeakPointersActWeak,
    // arbitrarily.
<<<<<<< HEAD
    TraceCollectionIfEnabled<
        WTF::IsTraceableInCollectionTrait<WTF::HashTraits<Value>>::value,
        WTF::NoWeakHandlingInCollections, WTF::WeakPointersActWeak, Value,
        WTF::HashTraits<Value>>::trace(visitor, value);
=======
    TraceCollectionIfEnabled<WTF::ShouldBeTraced<WTF::HashTraits<Value>>::value, WTF::NoWeakHandlingInCollections, WTF::WeakPointersActWeak, Value, WTF::HashTraits<Value>>::trace(visitor, value);
>>>>>>> miniblink49
}

// The inline capacity is just a dummy template argument to match the off-heap
// allocator.
// This inherits from the static-only HeapAllocator trait class, but we do
// declare pointers to instances.  These pointers are always null, and no
// objects are instantiated.
<<<<<<< HEAD
template <typename ValueArg, size_t inlineCapacity>
class HeapListHashSetAllocator : public HeapAllocator {
    DISALLOW_NEW();

=======
template<typename ValueArg, size_t inlineCapacity>
class HeapListHashSetAllocator : public HeapAllocator {
>>>>>>> miniblink49
public:
    using TableAllocator = HeapAllocator;
    using Node = WTF::ListHashSetNode<ValueArg, HeapListHashSetAllocator>;

    class AllocatorProvider {
<<<<<<< HEAD
        DISALLOW_NEW();

=======
>>>>>>> miniblink49
    public:
        // For the heap allocation we don't need an actual allocator object, so
        // we just return null.
        HeapListHashSetAllocator* get() const { return 0; }

        // No allocator object is needed.
        void createAllocatorIfNeeded() { }
        void releaseAllocator() { }

        // There is no allocator object in the HeapListHashSet (unlike in the
        // regular ListHashSet) so there is nothing to swap.
        void swap(AllocatorProvider& other) { }
    };

    void deallocate(void* dummy) { }

    // This is not a static method even though it could be, because it needs to
    // match the one that the (off-heap) ListHashSetAllocator has.  The 'this'
    // pointer will always be null.
    void* allocateNode()
    {
        // Consider using a LinkedHashSet instead if this compile-time assert fails:
<<<<<<< HEAD
        static_assert(!WTF::IsWeak<ValueArg>::value,
            "weak pointers in a ListHashSet will result in null entries "
            "in the set");

        return malloc<void*, Node>(
            sizeof(Node),
            nullptr /* Oilpan does not use the heap profiler at the moment. */);
    }

    template <typename VisitorDispatcher>
=======
        static_assert(!WTF::IsWeak<ValueArg>::value, "weak pointers in a ListHashSet will result in null entries in the set");

        return malloc<void*, Node>(sizeof(Node));
    }

    template<typename VisitorDispatcher>
>>>>>>> miniblink49
    static void traceValue(VisitorDispatcher visitor, Node* node)
    {
        traceListHashSetValue(visitor, node->m_value);
    }
};

<<<<<<< HEAD
template <typename T, typename Traits>
void HeapVectorBacking<T, Traits>::finalize(void* pointer)
{
    static_assert(Traits::needsDestruction,
        "Only vector buffers with items requiring destruction should "
        "be finalized");
    // See the comment in HeapVectorBacking::trace.
    static_assert(
        Traits::canClearUnusedSlotsWithMemset || std::is_polymorphic<T>::value,
        "HeapVectorBacking doesn't support objects that cannot be cleared as "
        "unused with memset or don't have a vtable");
=======
template<typename T, typename Traits = WTF::VectorTraits<T>> class HeapVectorBacking {
public:
    static void finalize(void* pointer);
    void finalizeGarbageCollectedObject() { finalize(this); }
};

template<typename T, typename Traits>
void HeapVectorBacking<T, Traits>::finalize(void* pointer)
{
    static_assert(Traits::needsDestruction, "Only vector buffers with items requiring destruction should be finalized");
    // See the comment in HeapVectorBacking::trace.
    static_assert(Traits::canClearUnusedSlotsWithMemset || WTF::IsPolymorphic<T>::value, "HeapVectorBacking doesn't support objects that cannot be cleared as unused with memset or don't have a vtable");
>>>>>>> miniblink49

    ASSERT(!WTF::IsTriviallyDestructible<T>::value);
    HeapObjectHeader* header = HeapObjectHeader::fromPayload(pointer);
    ASSERT(header->checkHeader());
    // Use the payload size as recorded by the heap to determine how many
    // elements to finalize.
    size_t length = header->payloadSize() / sizeof(T);
    T* buffer = reinterpret_cast<T*>(pointer);
#ifdef ANNOTATE_CONTIGUOUS_CONTAINER
    // As commented above, HeapVectorBacking calls finalizers for unused slots
    // (which are already zeroed out).
    ANNOTATE_CHANGE_SIZE(buffer, length, 0, length);
#endif
<<<<<<< HEAD
    if (std::is_polymorphic<T>::value) {
        char* pointer = reinterpret_cast<char*>(buffer);
        for (unsigned i = 0; i < length; ++i) {
            char* element = pointer + i * sizeof(T);
            if (blink::vTableInitialized(element))
                reinterpret_cast<T*>(element)->~T();
=======
    if (WTF::IsPolymorphic<T>::value) {
        for (unsigned i = 0; i < length; ++i) {
            if (blink::vTableInitialized(&buffer[i]))
                buffer[i].~T();
>>>>>>> miniblink49
        }
    } else {
        for (unsigned i = 0; i < length; ++i) {
            buffer[i].~T();
        }
    }
}

<<<<<<< HEAD
template <typename Table>
=======
template<typename Table> class HeapHashTableBacking {
public:
    static void finalize(void* pointer);
    void finalizeGarbageCollectedObject() { finalize(this); }
};

template<typename Table>
>>>>>>> miniblink49
void HeapHashTableBacking<Table>::finalize(void* pointer)
{
    using Value = typename Table::ValueType;
    ASSERT(!WTF::IsTriviallyDestructible<Value>::value);
    HeapObjectHeader* header = HeapObjectHeader::fromPayload(pointer);
    ASSERT(header->checkHeader());
    // Use the payload size as recorded by the heap to determine how many
    // elements to finalize.
    size_t length = header->payloadSize() / sizeof(Value);
    Value* table = reinterpret_cast<Value*>(pointer);
    for (unsigned i = 0; i < length; ++i) {
        if (!Table::isEmptyOrDeletedBucket(table[i]))
            table[i].~Value();
    }
}

<<<<<<< HEAD
template <typename KeyArg,
=======
// FIXME: These should just be template aliases:
//
// template<typename T, size_t inlineCapacity = 0>
// using HeapVector = Vector<T, inlineCapacity, HeapAllocator>;
//
// as soon as all the compilers we care about support that.
// MSVC supports it only in MSVC 2013.
template<
    typename KeyArg,
>>>>>>> miniblink49
    typename MappedArg,
    typename HashArg = typename DefaultHash<KeyArg>::Hash,
    typename KeyTraitsArg = HashTraits<KeyArg>,
    typename MappedTraitsArg = HashTraits<MappedArg>>
<<<<<<< HEAD
class HeapHashMap : public HashMap<KeyArg,
                        MappedArg,
                        HashArg,
                        KeyTraitsArg,
                        MappedTraitsArg,
                        HeapAllocator> {
    IS_GARBAGE_COLLECTED_TYPE();
    static_assert(WTF::IsTraceable<KeyArg>::value || WTF::IsTraceable<MappedArg>::value,
        "For hash maps without traceable elements, use HashMap<> "
        "instead of HeapHashMap<>");
};

template <typename ValueArg,
    typename HashArg = typename DefaultHash<ValueArg>::Hash,
    typename TraitsArg = HashTraits<ValueArg>>
class HeapHashSet
    : public HashSet<ValueArg, HashArg, TraitsArg, HeapAllocator> {
    IS_GARBAGE_COLLECTED_TYPE();
    static_assert(WTF::IsTraceable<ValueArg>::value,
        "For hash sets without traceable elements, use HashSet<> "
        "instead of HeapHashSet<>");
};

template <typename ValueArg,
    typename HashArg = typename DefaultHash<ValueArg>::Hash,
    typename TraitsArg = HashTraits<ValueArg>>
class HeapLinkedHashSet
    : public LinkedHashSet<ValueArg, HashArg, TraitsArg, HeapAllocator> {
    IS_GARBAGE_COLLECTED_TYPE();
    static_assert(WTF::IsTraceable<ValueArg>::value,
        "For sets without traceable elements, use LinkedHashSet<> "
        "instead of HeapLinkedHashSet<>");
};

template <typename ValueArg,
    size_t inlineCapacity = 0, // The inlineCapacity is just a dummy to
    // match ListHashSet (off-heap).
    typename HashArg = typename DefaultHash<ValueArg>::Hash>
class HeapListHashSet
    : public ListHashSet<ValueArg,
          inlineCapacity,
          HashArg,
          HeapListHashSetAllocator<ValueArg, inlineCapacity>> {
    IS_GARBAGE_COLLECTED_TYPE();
    static_assert(WTF::IsTraceable<ValueArg>::value,
        "For sets without traceable elements, use ListHashSet<> "
        "instead of HeapListHashSet<>");
};

template <typename Value,
    typename HashFunctions = typename DefaultHash<Value>::Hash,
    typename Traits = HashTraits<Value>>
class HeapHashCountedSet
    : public HashCountedSet<Value, HashFunctions, Traits, HeapAllocator> {
    IS_GARBAGE_COLLECTED_TYPE();
    static_assert(WTF::IsTraceable<Value>::value,
        "For counted sets without traceable elements, use "
        "HashCountedSet<> instead of HeapHashCountedSet<>");
};

template <typename T, size_t inlineCapacity = 0>
class HeapVector : public Vector<T, inlineCapacity, HeapAllocator> {
    IS_GARBAGE_COLLECTED_TYPE();

public:
    HeapVector()
    {
        static_assert(WTF::IsTraceable<T>::value,
            "For vectors without traceable elements, use Vector<> "
            "instead of HeapVector<>");
    }

    explicit HeapVector(size_t size)
        : Vector<T, inlineCapacity, HeapAllocator>(size)
    {
    }

    HeapVector(size_t size, const T& val)
        : Vector<T, inlineCapacity, HeapAllocator>(size, val)
    {
    }

    template <size_t otherCapacity>
=======
class HeapHashMap : public HashMap<KeyArg, MappedArg, HashArg, KeyTraitsArg, MappedTraitsArg, HeapAllocator> { };

template<
    typename ValueArg,
    typename HashArg = typename DefaultHash<ValueArg>::Hash,
    typename TraitsArg = HashTraits<ValueArg>>
class HeapHashSet : public HashSet<ValueArg, HashArg, TraitsArg, HeapAllocator> { };

template<
    typename ValueArg,
    typename HashArg = typename DefaultHash<ValueArg>::Hash,
    typename TraitsArg = HashTraits<ValueArg>>
class HeapLinkedHashSet : public LinkedHashSet<ValueArg, HashArg, TraitsArg, HeapAllocator> { };

template<
    typename ValueArg,
    size_t inlineCapacity = 0, // The inlineCapacity is just a dummy to match ListHashSet (off-heap).
    typename HashArg = typename DefaultHash<ValueArg>::Hash>
class HeapListHashSet : public ListHashSet<ValueArg, inlineCapacity, HashArg, HeapListHashSetAllocator<ValueArg, inlineCapacity>> { };

template<
    typename Value,
    typename HashFunctions = typename DefaultHash<Value>::Hash,
    typename Traits = HashTraits<Value>>
class HeapHashCountedSet : public HashCountedSet<Value, HashFunctions, Traits, HeapAllocator> { };

template<typename T, size_t inlineCapacity = 0>
class HeapVector : public Vector<T, inlineCapacity, HeapAllocator> {
public:
    HeapVector() { }

    explicit HeapVector(size_t size) : Vector<T, inlineCapacity, HeapAllocator>(size)
    {
    }

    HeapVector(size_t size, const T& val) : Vector<T, inlineCapacity, HeapAllocator>(size, val)
    {
    }

    template<size_t otherCapacity>
>>>>>>> miniblink49
    HeapVector(const HeapVector<T, otherCapacity>& other)
        : Vector<T, inlineCapacity, HeapAllocator>(other)
    {
    }
<<<<<<< HEAD
};

template <typename T, size_t inlineCapacity = 0>
class HeapDeque : public Deque<T, inlineCapacity, HeapAllocator> {
    IS_GARBAGE_COLLECTED_TYPE();

public:
    HeapDeque()
    {
        static_assert(WTF::IsTraceable<T>::value,
            "For vectors without traceable elements, use Deque<> instead "
            "of HeapDeque<>");
    }

    explicit HeapDeque(size_t size)
        : Deque<T, inlineCapacity, HeapAllocator>(size)
    {
    }

    HeapDeque(size_t size, const T& val)
        : Deque<T, inlineCapacity, HeapAllocator>(size, val)
    {
    }

    HeapDeque& operator=(const HeapDeque& other)
    {
        HeapDeque<T> copy(other);
        Deque<T, inlineCapacity, HeapAllocator>::swap(copy);
        return *this;
    }

    template <size_t otherCapacity>
=======

    template<typename U>
    void append(const U* data, size_t dataSize)
    {
        Vector<T, inlineCapacity, HeapAllocator>::append(data, dataSize);
    }

    template<typename U>
    void append(const U& other)
    {
        Vector<T, inlineCapacity, HeapAllocator>::append(other);
    }

    template<typename U, size_t otherCapacity>
    void appendVector(const HeapVector<U, otherCapacity>& other)
    {
        const Vector<U, otherCapacity, HeapAllocator>& otherVector = other;
        Vector<T, inlineCapacity, HeapAllocator>::appendVector(otherVector);
    }
};

template<typename T, size_t inlineCapacity = 0>
class HeapDeque : public Deque<T, inlineCapacity, HeapAllocator> {
public:
    HeapDeque() { }

    explicit HeapDeque(size_t size) : Deque<T, inlineCapacity, HeapAllocator>(size)
    {
    }

    HeapDeque(size_t size, const T& val) : Deque<T, inlineCapacity, HeapAllocator>(size, val)
    {
    }

    // FIXME: Doesn't work if there is an inline buffer, due to crbug.com/360572
    HeapDeque<T, 0>& operator=(const HeapDeque& other)
    {
        HeapDeque<T> copy(other);
        swap(copy);
        return *this;
    }

    // FIXME: Doesn't work if there is an inline buffer, due to crbug.com/360572
    void swap(HeapDeque& other)
    {
        Deque<T, inlineCapacity, HeapAllocator>::swap(other);
    }

    template<size_t otherCapacity>
>>>>>>> miniblink49
    HeapDeque(const HeapDeque<T, otherCapacity>& other)
        : Deque<T, inlineCapacity, HeapAllocator>(other)
    {
    }
<<<<<<< HEAD
};

} // namespace blink

namespace WTF {

template <typename T>
struct VectorTraits<blink::Member<T>> : VectorTraitsBase<blink::Member<T>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = false;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = true;
    static const bool canMoveWithMemcpy = true;
};

template <typename T>
struct VectorTraits<blink::SameThreadCheckedMember<T>>
    : VectorTraitsBase<blink::SameThreadCheckedMember<T>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = false;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = true;
    static const bool canMoveWithMemcpy = true;
    static const bool canSwapUsingCopyOrMove = false;
};

template <typename T>
struct VectorTraits<blink::TraceWrapperMember<T>>
    : VectorTraitsBase<blink::TraceWrapperMember<T>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = false;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = true;
    static const bool canMoveWithMemcpy = true;
    static const bool canSwapUsingCopyOrMove = false;
};

template <typename T>
struct VectorTraits<blink::WeakMember<T>>
    : VectorTraitsBase<blink::WeakMember<T>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = false;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = true;
    static const bool canMoveWithMemcpy = true;
};

template <typename T>
struct VectorTraits<blink::UntracedMember<T>>
    : VectorTraitsBase<blink::UntracedMember<T>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = false;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = true;
    static const bool canMoveWithMemcpy = true;
};

template <
    typename T,
    blink::WeaknessPersistentConfiguration weaknessConfiguration,
    blink::CrossThreadnessPersistentConfiguration crossThreadnessConfiguration>
struct VectorTraits<blink::PersistentBase<T,
    weaknessConfiguration,
    crossThreadnessConfiguration>>
    : VectorTraitsBase<blink::PersistentBase<T,
          weaknessConfiguration,
          crossThreadnessConfiguration>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = true;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = false;
    static const bool canMoveWithMemcpy = true;
};

template <typename T>
struct VectorTraits<blink::HeapVector<T, 0>>
    : VectorTraitsBase<blink::HeapVector<T, 0>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = false;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = true;
    static const bool canMoveWithMemcpy = true;
};

template <typename T>
struct VectorTraits<blink::HeapDeque<T, 0>>
    : VectorTraitsBase<blink::HeapDeque<T, 0>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = false;
    static const bool canInitializeWithMemset = true;
    static const bool canClearUnusedSlotsWithMemset = true;
    static const bool canMoveWithMemcpy = true;
};

template <typename T, size_t inlineCapacity>
struct VectorTraits<blink::HeapVector<T, inlineCapacity>>
    : VectorTraitsBase<blink::HeapVector<T, inlineCapacity>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = VectorTraits<T>::needsDestruction;
    static const bool canInitializeWithMemset = VectorTraits<T>::canInitializeWithMemset;
    static const bool canClearUnusedSlotsWithMemset = VectorTraits<T>::canClearUnusedSlotsWithMemset;
    static const bool canMoveWithMemcpy = VectorTraits<T>::canMoveWithMemcpy;
};

template <typename T, size_t inlineCapacity>
struct VectorTraits<blink::HeapDeque<T, inlineCapacity>>
    : VectorTraitsBase<blink::HeapDeque<T, inlineCapacity>> {
    STATIC_ONLY(VectorTraits);
    static const bool needsDestruction = VectorTraits<T>::needsDestruction;
    static const bool canInitializeWithMemset = VectorTraits<T>::canInitializeWithMemset;
    static const bool canClearUnusedSlotsWithMemset = VectorTraits<T>::canClearUnusedSlotsWithMemset;
    static const bool canMoveWithMemcpy = VectorTraits<T>::canMoveWithMemcpy;
};

template <typename T>
struct HashTraits<blink::Member<T>> : SimpleClassHashTraits<blink::Member<T>> {
    STATIC_ONLY(HashTraits);
    // FIXME: Implement proper const'ness for iterator types. Requires support
    // in the marking Visitor.
    using PeekInType = T*;
    using IteratorGetType = blink::Member<T>*;
    using IteratorConstGetType = const blink::Member<T>*;
    using IteratorReferenceType = blink::Member<T>&;
    using IteratorConstReferenceType = const blink::Member<T>&;
    static IteratorReferenceType getToReferenceConversion(IteratorGetType x)
    {
        return *x;
    }
    static IteratorConstReferenceType getToReferenceConstConversion(
        IteratorConstGetType x)
    {
        return *x;
    }

    using PeekOutType = T*;

    template <typename U>
    static void store(const U& value, blink::Member<T>& storage)
    {
        storage = value;
    }

    static PeekOutType peek(const blink::Member<T>& value) { return value; }
};

template <typename T>
struct HashTraits<blink::SameThreadCheckedMember<T>>
    : SimpleClassHashTraits<blink::SameThreadCheckedMember<T>> {
    STATIC_ONLY(HashTraits);
    // FIXME: Implement proper const'ness for iterator types. Requires support
    // in the marking Visitor.
    using PeekInType = T*;
    using IteratorGetType = blink::SameThreadCheckedMember<T>*;
    using IteratorConstGetType = const blink::SameThreadCheckedMember<T>*;
    using IteratorReferenceType = blink::SameThreadCheckedMember<T>&;
    using IteratorConstReferenceType = const blink::SameThreadCheckedMember<T>&;
    static IteratorReferenceType getToReferenceConversion(IteratorGetType x)
    {
        return *x;
    }
    static IteratorConstReferenceType getToReferenceConstConversion(
        IteratorConstGetType x)
    {
        return *x;
    }

    using PeekOutType = T*;

    template <typename U>
    static void store(const U& value,
        blink::SameThreadCheckedMember<T>& storage)
    {
        storage = value;
    }

    static PeekOutType peek(const blink::SameThreadCheckedMember<T>& value)
    {
        return value;
    }

    static blink::SameThreadCheckedMember<T> emptyValue()
    {
        return blink::SameThreadCheckedMember<T>(nullptr, nullptr);
    }
};

template <typename T>
struct HashTraits<blink::TraceWrapperMember<T>>
    : SimpleClassHashTraits<blink::TraceWrapperMember<T>> {
    STATIC_ONLY(HashTraits);
    // FIXME: Implement proper const'ness for iterator types. Requires support
    // in the marking Visitor.
    using PeekInType = T*;
    using IteratorGetType = blink::TraceWrapperMember<T>*;
    using IteratorConstGetType = const blink::TraceWrapperMember<T>*;
    using IteratorReferenceType = blink::TraceWrapperMember<T>&;
    using IteratorConstReferenceType = const blink::TraceWrapperMember<T>&;
    static IteratorReferenceType getToReferenceConversion(IteratorGetType x)
    {
        return *x;
    }
    static IteratorConstReferenceType getToReferenceConstConversion(
        IteratorConstGetType x)
    {
        return *x;
    }

    using PeekOutType = T*;

    template <typename U>
    static void store(const U& value, blink::TraceWrapperMember<T>& storage)
    {
        storage = value;
    }

    static PeekOutType peek(const blink::TraceWrapperMember<T>& value)
    {
        return value;
    }

    static blink::TraceWrapperMember<T> emptyValue()
    {
        return blink::TraceWrapperMember<T>(nullptr, nullptr);
    }
};

template <typename T>
struct HashTraits<blink::WeakMember<T>>
    : SimpleClassHashTraits<blink::WeakMember<T>> {
    STATIC_ONLY(HashTraits);
    static const bool needsDestruction = false;
    // FIXME: Implement proper const'ness for iterator types. Requires support
    // in the marking Visitor.
    using PeekInType = T*;
    using IteratorGetType = blink::WeakMember<T>*;
    using IteratorConstGetType = const blink::WeakMember<T>*;
    using IteratorReferenceType = blink::WeakMember<T>&;
    using IteratorConstReferenceType = const blink::WeakMember<T>&;
    static IteratorReferenceType getToReferenceConversion(IteratorGetType x)
    {
        return *x;
    }
    static IteratorConstReferenceType getToReferenceConstConversion(
        IteratorConstGetType x)
    {
        return *x;
    }

    using PeekOutType = T*;

    template <typename U>
    static void store(const U& value, blink::WeakMember<T>& storage)
    {
        storage = value;
    }

    static PeekOutType peek(const blink::WeakMember<T>& value) { return value; }

    template <typename VisitorDispatcher>
    static bool traceInCollection(VisitorDispatcher visitor,
        blink::WeakMember<T>& weakMember,
        ShouldWeakPointersBeMarkedStrongly strongify)
    {
        if (strongify == WeakPointersActStrong) {
            visitor->trace(weakMember.get()); // Strongified visit.
            return false;
        }
        return !blink::ThreadHeap::isHeapObjectAlive(weakMember);
    }
};

template <typename T>
struct HashTraits<blink::UntracedMember<T>>
    : SimpleClassHashTraits<blink::UntracedMember<T>> {
    STATIC_ONLY(HashTraits);
    static const bool needsDestruction = false;
    // FIXME: Implement proper const'ness for iterator types.
    using PeekInType = T*;
    using IteratorGetType = blink::UntracedMember<T>*;
    using IteratorConstGetType = const blink::UntracedMember<T>*;
    using IteratorReferenceType = blink::UntracedMember<T>&;
    using IteratorConstReferenceType = const blink::UntracedMember<T>&;
    static IteratorReferenceType getToReferenceConversion(IteratorGetType x)
    {
        return *x;
    }
    static IteratorConstReferenceType getToReferenceConstConversion(
        IteratorConstGetType x)
    {
        return *x;
    }
    using PeekOutType = T*;

    template <typename U>
    static void store(const U& value, blink::UntracedMember<T>& storage)
    {
        storage = value;
    }

    static PeekOutType peek(const blink::UntracedMember<T>& value)
    {
        return value;
    }
};

template <typename T, size_t inlineCapacity>
struct IsTraceable<
    ListHashSetNode<T, blink::HeapListHashSetAllocator<T, inlineCapacity>>*> {
    STATIC_ONLY(IsTraceable);
    static_assert(sizeof(T), "T must be fully defined");
    // All heap allocated node pointers need visiting to keep the nodes alive,
    // regardless of whether they contain pointers to other heap allocated
    // objects.
    static const bool value = true;
};

template <typename T, size_t inlineCapacity>
struct IsGarbageCollectedType<
    ListHashSetNode<T, blink::HeapListHashSetAllocator<T, inlineCapacity>>> {
    static const bool value = true;
};

template <typename Set>
struct IsGarbageCollectedType<ListHashSetIterator<Set>> {
    static const bool value = IsGarbageCollectedType<Set>::value;
};

template <typename Set>
struct IsGarbageCollectedType<ListHashSetConstIterator<Set>> {
    static const bool value = IsGarbageCollectedType<Set>::value;
};

template <typename Set>
struct IsGarbageCollectedType<ListHashSetReverseIterator<Set>> {
    static const bool value = IsGarbageCollectedType<Set>::value;
};

template <typename Set>
struct IsGarbageCollectedType<ListHashSetConstReverseIterator<Set>> {
    static const bool value = IsGarbageCollectedType<Set>::value;
};

template <typename T, typename H>
struct HandleHashTraits : SimpleClassHashTraits<H> {
    STATIC_ONLY(HandleHashTraits);
    // TODO: Implement proper const'ness for iterator types. Requires support
    // in the marking Visitor.
    using PeekInType = T*;
    using IteratorGetType = H*;
    using IteratorConstGetType = const H*;
    using IteratorReferenceType = H&;
    using IteratorConstReferenceType = const H&;
    static IteratorReferenceType getToReferenceConversion(IteratorGetType x)
    {
        return *x;
    }
    static IteratorConstReferenceType getToReferenceConstConversion(
        IteratorConstGetType x)
    {
        return *x;
    }

    using PeekOutType = T*;

    template <typename U>
    static void store(const U& value, H& storage)
    {
        storage = value;
    }

    static PeekOutType peek(const H& value) { return value; }
};

template <typename T>
struct HashTraits<blink::Persistent<T>>
    : HandleHashTraits<T, blink::Persistent<T>> {
};

template <typename T>
struct HashTraits<blink::CrossThreadPersistent<T>>
    : HandleHashTraits<T, blink::CrossThreadPersistent<T>> {
};

template <typename Value,
    typename HashFunctions,
    typename Traits,
    typename VectorType>
inline void copyToVector(
    const blink::HeapHashCountedSet<Value, HashFunctions, Traits>& set,
    VectorType& vector)
{
    copyToVector(static_cast<const HashCountedSet<Value, HashFunctions, Traits,
                     blink::HeapAllocator>&>(set),
        vector);
}

} // namespace WTF

=======

    template<typename U>
    void append(const U& other)
    {
        Deque<T, inlineCapacity, HeapAllocator>::append(other);
    }
};

template<typename T, size_t i>
inline void swap(HeapVector<T, i>& a, HeapVector<T, i>& b) { a.swap(b); }
template<typename T, size_t i>
inline void swap(HeapDeque<T, i>& a, HeapDeque<T, i>& b) { a.swap(b); }
template<typename T, typename U, typename V>
inline void swap(HeapHashSet<T, U, V>& a, HeapHashSet<T, U, V>& b) { a.swap(b); }
template<typename T, typename U, typename V, typename W, typename X>
inline void swap(HeapHashMap<T, U, V, W, X>& a, HeapHashMap<T, U, V, W, X>& b) { a.swap(b); }
template<typename T, size_t i, typename U>
inline void swap(HeapListHashSet<T, i, U>& a, HeapListHashSet<T, i, U>& b) { a.swap(b); }
template<typename T, typename U, typename V>
inline void swap(HeapLinkedHashSet<T, U, V>& a, HeapLinkedHashSet<T, U, V>& b) { a.swap(b); }
template<typename T, typename U, typename V>
inline void swap(HeapHashCountedSet<T, U, V>& a, HeapHashCountedSet<T, U, V>& b) { a.swap(b); }

} // namespace blink

>>>>>>> miniblink49
#endif

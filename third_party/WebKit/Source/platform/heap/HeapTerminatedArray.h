// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HeapTerminatedArray_h
#define HeapTerminatedArray_h

#include "platform/heap/Heap.h"
#include "wtf/TerminatedArray.h"
#include "wtf/TerminatedArrayBuilder.h"

namespace blink {

<<<<<<< HEAD
template <typename T>
class HeapTerminatedArray : public TerminatedArray<T> {
    DISALLOW_NEW();
    IS_GARBAGE_COLLECTED_TYPE();

=======
template<typename T>
class HeapTerminatedArray : public TerminatedArray<T> {
    DISALLOW_ALLOCATION();
>>>>>>> miniblink49
public:
    using TerminatedArray<T>::begin;
    using TerminatedArray<T>::end;

    DEFINE_INLINE_TRACE()
    {
        for (typename TerminatedArray<T>::iterator it = begin(); it != end(); ++it)
            visitor->trace(*it);
    }

private:
<<<<<<< HEAD
    // Allocator describes how HeapTerminatedArrayBuilder should create new
    // instances of HeapTerminatedArray and manage their lifetimes.
    struct Allocator final {
        STATIC_ONLY(Allocator);
        using PassPtr = HeapTerminatedArray*;
        using Ptr = Member<HeapTerminatedArray>;

        static PassPtr release(Ptr& ptr) { return ptr; }

        static PassPtr create(size_t capacity)
        {
            return reinterpret_cast<HeapTerminatedArray*>(
                ThreadHeap::allocate<HeapTerminatedArray>(
                    capacity * sizeof(T), IsEagerlyFinalizedType<T>::value));
=======
    // Allocator describes how HeapTerminatedArrayBuilder should create new intances
    // of TerminateArray and manage their lifetimes.
    struct Allocator {
        typedef HeapTerminatedArray* PassPtr;
        typedef RawPtr<HeapTerminatedArray> Ptr;

        static PassPtr create(size_t capacity)
        {
            return reinterpret_cast<HeapTerminatedArray*>(Heap::allocate<HeapTerminatedArray>(capacity * sizeof(T), IsEagerlyFinalizedType<T>::value));
>>>>>>> miniblink49
        }

        static PassPtr resize(PassPtr ptr, size_t capacity)
        {
<<<<<<< HEAD
            return reinterpret_cast<HeapTerminatedArray*>(
                ThreadHeap::reallocate<HeapTerminatedArray>(ptr,
                    capacity * sizeof(T)));
=======
            return reinterpret_cast<HeapTerminatedArray*>(Heap::reallocate<HeapTerminatedArray>(ptr, capacity * sizeof(T)));
>>>>>>> miniblink49
        }
    };

    // Prohibit construction. Allocator makes HeapTerminatedArray instances for
    // HeapTerminatedArrayBuilder by pointer casting.
    HeapTerminatedArray();

<<<<<<< HEAD
    template <typename U, template <typename> class>
    friend class WTF::TerminatedArrayBuilder;
};

template <typename T>
=======
    template<typename U, template <typename> class> friend class WTF::TerminatedArrayBuilder;
};

template<typename T>
>>>>>>> miniblink49
class TraceEagerlyTrait<HeapTerminatedArray<T>> {
public:
    static const bool value = TraceEagerlyTrait<T>::value;
};

} // namespace blink

#endif // HeapTerminatedArray_h

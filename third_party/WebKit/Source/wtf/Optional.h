// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef Optional_h
#define Optional_h

<<<<<<< HEAD
#include "base/optional.h"
#include "wtf/TypeTraits.h"

namespace WTF {

// WTF::Optional is base::Optional. See base/optional.h for documentation.
//
// A clang plugin enforces that garbage collected types are not allocated
// outside of the heap, similarly we enforce that one doesn't create garbage
// collected types nested inside an Optional.
template <typename T>
using Optional = typename std::enable_if<!IsGarbageCollectedType<T>::value,
    base::Optional<T>>::type;

const base::nullopt_t nullopt = base::nullopt;
const base::in_place_t in_place = base::in_place;
=======
#include "wtf/Alignment.h"
#include "wtf/Assertions.h"
#include "wtf/Noncopyable.h"
#include "wtf/StdLibExtras.h"
#include "wtf/Utility.h"

namespace WTF {

// This is a lightweight template similar to std::experimental::optional.
// It currently does not support assignment, swapping, comparison, etc.
//
// Use this instead of OwnPtr for cases where you only want to conditionally
// construct a "scope" object.
//
// Example:
//   Optional<DrawingRecorder> recorder;
//   if (shouldDraw)
//       recorder.emplace(constructor, args, here);
//   // recorder destroyed at end of scope
//
// Note in particular that unlike a pointer, though, dereferencing a const
// optional yields a const reference.

template <typename T>
class Optional {
    WTF_MAKE_NONCOPYABLE(Optional);
public:
    Optional() : m_ptr(nullptr) { }
    ~Optional()
    {
        if (m_ptr)
            m_ptr->~T();
    }

    typedef T* Optional::*UnspecifiedBoolType;
    operator UnspecifiedBoolType() const { return m_ptr ? &Optional::m_ptr : nullptr; }

    T& operator*() { ASSERT_WITH_SECURITY_IMPLICATION(m_ptr); return *m_ptr; }
    const T& operator*() const { ASSERT_WITH_SECURITY_IMPLICATION(m_ptr); return *m_ptr; }
    T* operator->() { ASSERT_WITH_SECURITY_IMPLICATION(m_ptr); return m_ptr; }
    const T* operator->() const { ASSERT_WITH_SECURITY_IMPLICATION(m_ptr); return m_ptr; }

    template <typename... Args>
    void emplace(Args&&... args)
    {
        RELEASE_ASSERT(!m_ptr);
        m_ptr = reinterpret_cast_ptr<T*>(&m_storage.buffer);
        new (m_ptr) T(forward<Args>(args)...);
    }

private:
    T* m_ptr;
    AlignedBuffer<sizeof(T), WTF_ALIGN_OF(T)> m_storage;
};
>>>>>>> miniblink49

} // namespace WTF

using WTF::Optional;

#endif // Optional_h

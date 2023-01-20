// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef TerminatedArrayBuilder_h
#define TerminatedArrayBuilder_h

<<<<<<< HEAD
#include "wtf/Allocator.h"

namespace WTF {

template <typename T, template <typename> class ArrayType = TerminatedArray>
class TerminatedArrayBuilder {
    STACK_ALLOCATED();
    WTF_MAKE_NONCOPYABLE(TerminatedArrayBuilder);

public:
    explicit TerminatedArrayBuilder(
        typename ArrayType<T>::Allocator::PassPtr array)
=======
#include "wtf/OwnPtr.h"

namespace WTF {

template<typename T, template <typename> class ArrayType = TerminatedArray>
class TerminatedArrayBuilder {
    DISALLOW_ALLOCATION();
    WTF_MAKE_NONCOPYABLE(TerminatedArrayBuilder);
public:
    explicit TerminatedArrayBuilder(typename ArrayType<T>::Allocator::PassPtr array)
>>>>>>> miniblink49
        : m_array(array)
        , m_count(0)
        , m_capacity(0)
    {
        if (!m_array)
            return;
        m_capacity = m_count = m_array->size();
<<<<<<< HEAD
        DCHECK(m_array->at(m_count - 1).isLastInArray());
=======
>>>>>>> miniblink49
    }

    void grow(size_t count)
    {
<<<<<<< HEAD
        DCHECK(count);
        if (!m_array) {
            DCHECK(!m_count);
            DCHECK(!m_capacity);
            m_capacity = count;
            m_array = ArrayType<T>::Allocator::create(m_capacity);
        } else {
            DCHECK(m_array->at(m_count - 1).isLastInArray());
            m_capacity += count;
            m_array = ArrayType<T>::Allocator::resize(
                ArrayType<T>::Allocator::release(m_array), m_capacity);
            m_array->at(m_count - 1).setLastInArray(false);
        }
        m_array->at(m_capacity - 1).setLastInArray(true);
=======
        ASSERT(count);
        if (!m_array) {
            ASSERT(!m_count);
            ASSERT(!m_capacity);
            m_capacity = count;
            m_array = ArrayType<T>::Allocator::create(m_capacity);
            return;
        }
        m_capacity += count;
        m_array = ArrayType<T>::Allocator::resize(m_array.release(), m_capacity);
        m_array->at(m_count - 1).setLastInArray(false);
>>>>>>> miniblink49
    }

    void append(const T& item)
    {
        RELEASE_ASSERT(m_count < m_capacity);
<<<<<<< HEAD
        DCHECK(!item.isLastInArray());
        m_array->at(m_count++) = item;
        if (m_count == m_capacity)
            m_array->at(m_capacity - 1).setLastInArray(true);
=======
        ASSERT(!item.isLastInArray());
        m_array->at(m_count++) = item;
>>>>>>> miniblink49
    }

    typename ArrayType<T>::Allocator::PassPtr release()
    {
        RELEASE_ASSERT(m_count == m_capacity);
<<<<<<< HEAD
        assertValid();
        return ArrayType<T>::Allocator::release(m_array);
    }

private:
#if DCHECK_IS_ON()
=======
        if (m_array)
            m_array->at(m_count - 1).setLastInArray(true);
        assertValid();
        return m_array.release();
    }

private:
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    void assertValid()
    {
        for (size_t i = 0; i < m_count; ++i) {
            bool isLastInArray = (i + 1 == m_count);
<<<<<<< HEAD
            DCHECK_EQ(m_array->at(i).isLastInArray(), isLastInArray);
        }
    }
#else
    void assertValid()
    {
    }
=======
            ASSERT(m_array->at(i).isLastInArray() == isLastInArray);
        }
    }
#else
    void assertValid() { }
>>>>>>> miniblink49
#endif

    typename ArrayType<T>::Allocator::Ptr m_array;
    size_t m_count;
    size_t m_capacity;
};

} // namespace WTF

using WTF::TerminatedArrayBuilder;

#endif // TerminatedArrayBuilder_h

/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebVector_h
#define WebVector_h

#include "WebCommon.h"
<<<<<<< HEAD
#include "base/logging.h"

#include <algorithm>
#include <vector>

namespace blink {

// A simple vector class that wraps a std::vector.
=======

#include <algorithm>
#include <limits>
#include <stdlib.h>

namespace blink {

// A simple vector class.
>>>>>>> miniblink49
//
// Sample usage:
//
//   void Foo(WebVector<int>& result)
//   {
//       WebVector<int> data(10);
//       for (size_t i = 0; i < data.size(); ++i)
//           data[i] = ...
//       result.swap(data);
//   }
//
<<<<<<< HEAD
// It is also possible to assign from any container that implements begin()
// and end().
=======
// It is also possible to assign from other types of random access
// containers:
>>>>>>> miniblink49
//
//   void Foo(const std::vector<std::string>& input)
//   {
//       WebVector<WebCString> cstrings = input;
//       ...
//   }
//
template <typename T>
class WebVector {
public:
<<<<<<< HEAD
    using value_type = typename std::vector<T>::value_type;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    ~WebVector() { }

    explicit WebVector(size_t size = 0)
        : m_data(size)
    {
=======
    using ValueType = T;
    using iterator = T*;
    using const_iterator = const T*;

    ~WebVector()
    {
        destroy();
    }

    explicit WebVector(size_t size = 0)
    {
        initialize(size);
>>>>>>> miniblink49
    }

    template <typename U>
    WebVector(const U* values, size_t size)
<<<<<<< HEAD
        : m_data(values, values + size)
    {
    }

    WebVector(const WebVector<T>& other)
        : m_data(other.m_data)
    {
=======
    {
        initializeFrom(values, size);
    }

    WebVector(const WebVector<T>& other)
    {
        initializeFrom(other.m_ptr, other.m_size);
>>>>>>> miniblink49
    }

    template <typename C>
    WebVector(const C& other)
<<<<<<< HEAD
        : m_data(other.begin(), other.end())
    {
    }

    WebVector(WebVector<T>&& other) { swap(other); }

=======
    {
        initializeFrom(other.size() ? &other[0] : 0, other.size());
    }

>>>>>>> miniblink49
    WebVector& operator=(const WebVector& other)
    {
        if (this != &other)
            assign(other);
        return *this;
    }

<<<<<<< HEAD
    WebVector& operator=(WebVector&& other)
    {
        if (this != &other)
            swap(other);
        return *this;
    }

=======
>>>>>>> miniblink49
    template <typename C>
    WebVector<T>& operator=(const C& other)
    {
        if (this != reinterpret_cast<const WebVector<T>*>(&other))
            assign(other);
        return *this;
    }

    template <typename C>
    void assign(const C& other)
    {
<<<<<<< HEAD
        m_data.assign(other.begin(), other.end());
=======
        assign(other.size() ? &other[0] : 0, other.size());
>>>>>>> miniblink49
    }

    template <typename U>
    void assign(const U* values, size_t size)
    {
<<<<<<< HEAD
        m_data.assign(values, values + size);
    }

    size_t size() const { return m_data.size(); }
    bool isEmpty() const { return m_data.empty(); }

    T& operator[](size_t i)
    {
        DCHECK_LT(i, m_data.size());
        return m_data[i];
    }

    const T& operator[](size_t i) const
    {
        DCHECK_LT(i, m_data.size());
        return m_data[i];
    }

    T* data() { return m_data.data(); }
    const T* data() const { return m_data.data(); }

    iterator begin() { return m_data.begin(); }
    iterator end() { return m_data.end(); }
    const_iterator begin() const { return m_data.begin(); }
    const_iterator end() const { return m_data.end(); }

    void swap(WebVector<T>& other) { m_data.swap(other.m_data); }

private:
    std::vector<T> m_data;
=======
        destroy();
        initializeFrom(values, size);
    }

    size_t size() const { return m_size; }
    bool isEmpty() const { return !m_size; }

    T& operator[](size_t i)
    {
        BLINK_ASSERT(i < m_size);
        return m_ptr[i];
    }
    const T& operator[](size_t i) const
    {
        BLINK_ASSERT(i < m_size);
        return m_ptr[i];
    }

    bool contains(const T& value) const
    {
        for (size_t i = 0; i < m_size; i++) {
            if (m_ptr[i] == value)
                return true;
        }
        return false;
    }

    T* data() { return m_ptr; }
    const T* data() const { return m_ptr; }

    iterator begin() { return data(); }
    iterator end() { return begin() + m_size; }
    const_iterator begin() const { return data(); }
    const_iterator end() const { return begin() + m_size; }

    void swap(WebVector<T>& other)
    {
        std::swap(m_ptr, other.m_ptr);
        std::swap(m_size, other.m_size);
    }

private:
    void initialize(size_t size)
    {
        validateSize(size);
        m_size = size;
        if (!m_size)
            m_ptr = 0;
        else {
            char* cptr = static_cast<char*>(::operator new(sizeof(T) * m_size));
            for (size_t i = 0; i < m_size; ++i)
                new (&cptr[sizeof(T) * i]) T();
            m_ptr = reinterpret_cast<T*>(cptr);
        }
    }

    template <typename U>
    void initializeFrom(const U* values, size_t size)
    {
        validateSize(size);
        m_size = size;
        if (!m_size)
            m_ptr = 0;
        else {
            char* cptr = static_cast<char*>(::operator new(sizeof(T) * m_size));
            for (size_t i = 0; i < m_size; ++i)
                new (&cptr[sizeof(T) * i]) T(values[i]);
            m_ptr = reinterpret_cast<T*>(cptr);
        }
    }

    void validateSize(size_t size)
    {
        if (std::numeric_limits<size_t>::max() / sizeof(T) < size)
            abort();
    }

    void destroy()
    {
        for (size_t i = 0; i < m_size; ++i)
            m_ptr[i].~T();
        ::operator delete(m_ptr);
    }

    T* m_ptr;
    size_t m_size;
>>>>>>> miniblink49
};

} // namespace blink

#endif

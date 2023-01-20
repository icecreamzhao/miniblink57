/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
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

#ifndef LinkedStack_h
#define LinkedStack_h

<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "wtf/FastAllocBase.h"
#include "wtf/OwnPtr.h"
>>>>>>> miniblink49

namespace WTF {

template <typename T>
class LinkedStack {
<<<<<<< HEAD
    USING_FAST_MALLOC(LinkedStack);

public:
    LinkedStack()
        : m_size(0)
    {
    }

    // Iterative cleanup to prevent stack overflow problems.
    ~LinkedStack()
    {
        std::unique_ptr<Node> ptr = m_head.release();
        while (ptr)
            ptr = ptr->m_next.release();
    }
=======
    WTF_MAKE_FAST_ALLOCATED(LinkedStack);
public:
    LinkedStack() : m_size(0) { }
>>>>>>> miniblink49

    bool isEmpty();

    void push(const T&);
    const T& peek();
    void pop();

    size_t size();

<<<<<<< HEAD
private:
    class Node {
        USING_FAST_MALLOC(LinkedStack::Node);

    public:
        Node(const T&, std::unique_ptr<Node> next);

        T m_data;
        std::unique_ptr<Node> m_next;
    };

    std::unique_ptr<Node> m_head;
=======
    // This inner class used to be private but is now public on account of a
    // possible MSVC bug. It can be made private again if we get rid of
    // WTF_MAKE_FAST_ALLOCATED ever.
    class Node {
        WTF_MAKE_FAST_ALLOCATED(LinkedStack::Node);
    public:
        Node(const T&, PassOwnPtr<Node> next);

        T m_data;
        OwnPtr<Node> m_next;
    };

private:
    OwnPtr<Node> m_head;
>>>>>>> miniblink49
    size_t m_size;
};

template <typename T>
<<<<<<< HEAD
LinkedStack<T>::Node::Node(const T& data, std::unique_ptr<Node> next)
=======
LinkedStack<T>::Node::Node(const T& data, PassOwnPtr<Node> next)
>>>>>>> miniblink49
    : m_data(data)
    , m_next(next)
{
}

template <typename T>
inline bool LinkedStack<T>::isEmpty()
{
    return !m_head;
}

template <typename T>
inline void LinkedStack<T>::push(const T& data)
{
<<<<<<< HEAD
    m_head = WTF::wrapUnique(new Node(data, m_head.release()));
=======
    m_head = adoptPtr(new Node(data, m_head.release()));
>>>>>>> miniblink49
    ++m_size;
}

template <typename T>
inline const T& LinkedStack<T>::peek()
{
    return m_head->m_data;
}

template <typename T>
inline void LinkedStack<T>::pop()
{
<<<<<<< HEAD
    DCHECK(m_head);
    DCHECK(m_size);
=======
    ASSERT(m_head && m_size);
>>>>>>> miniblink49
    m_head = m_head->m_next.release();
    --m_size;
}

template <typename T>
inline size_t LinkedStack<T>::size()
{
    return m_size;
}

<<<<<<< HEAD
} // namespace WTF
=======
}
>>>>>>> miniblink49

using WTF::LinkedStack;

#endif

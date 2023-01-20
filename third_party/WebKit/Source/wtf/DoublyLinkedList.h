/*
 * Copyright (C) 2011 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

<<<<<<< HEAD
#include "wtf/Allocator.h"

namespace WTF {

// This class allows nodes to share code without dictating data member layout.
template <typename T>
class DoublyLinkedListNode {
=======
namespace WTF {

// This class allows nodes to share code without dictating data member layout.
template<typename T> class DoublyLinkedListNode {
>>>>>>> miniblink49
public:
    DoublyLinkedListNode();

    void setPrev(T*);
    void setNext(T*);

    T* prev() const;
    T* next() const;
};

<<<<<<< HEAD
template <typename T>
inline DoublyLinkedListNode<T>::DoublyLinkedListNode()
=======
template<typename T> inline DoublyLinkedListNode<T>::DoublyLinkedListNode()
>>>>>>> miniblink49
{
    setPrev(0);
    setNext(0);
}

<<<<<<< HEAD
template <typename T>
inline void DoublyLinkedListNode<T>::setPrev(T* prev)
=======
template<typename T> inline void DoublyLinkedListNode<T>::setPrev(T* prev)
>>>>>>> miniblink49
{
    static_cast<T*>(this)->m_prev = prev;
}

<<<<<<< HEAD
template <typename T>
inline void DoublyLinkedListNode<T>::setNext(T* next)
=======
template<typename T> inline void DoublyLinkedListNode<T>::setNext(T* next)
>>>>>>> miniblink49
{
    static_cast<T*>(this)->m_next = next;
}

<<<<<<< HEAD
template <typename T>
inline T* DoublyLinkedListNode<T>::prev() const
=======
template<typename T> inline T* DoublyLinkedListNode<T>::prev() const
>>>>>>> miniblink49
{
    return static_cast<const T*>(this)->m_prev;
}

<<<<<<< HEAD
template <typename T>
inline T* DoublyLinkedListNode<T>::next() const
=======
template<typename T> inline T* DoublyLinkedListNode<T>::next() const
>>>>>>> miniblink49
{
    return static_cast<const T*>(this)->m_next;
}

<<<<<<< HEAD
template <typename T>
class DoublyLinkedList {
    USING_FAST_MALLOC(DoublyLinkedList);

=======
template<typename T> class DoublyLinkedList {
>>>>>>> miniblink49
public:
    DoublyLinkedList();

    bool isEmpty() const;
    size_t size() const; // This is O(n).
    void clear();

    T* head() const;
    T* removeHead();

    T* tail() const;

    void push(T*);
    void append(T*);
    void remove(T*);

private:
    T* m_head;
    T* m_tail;
};

<<<<<<< HEAD
template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
=======
template<typename T> inline DoublyLinkedList<T>::DoublyLinkedList()
>>>>>>> miniblink49
    : m_head(0)
    , m_tail(0)
{
}

<<<<<<< HEAD
template <typename T>
inline bool DoublyLinkedList<T>::isEmpty() const
=======
template<typename T> inline bool DoublyLinkedList<T>::isEmpty() const
>>>>>>> miniblink49
{
    return !m_head;
}

<<<<<<< HEAD
template <typename T>
inline size_t DoublyLinkedList<T>::size() const
=======
template<typename T> inline size_t DoublyLinkedList<T>::size() const
>>>>>>> miniblink49
{
    size_t size = 0;
    for (T* node = m_head; node; node = node->next())
        ++size;
    return size;
}

<<<<<<< HEAD
template <typename T>
inline void DoublyLinkedList<T>::clear()
=======
template<typename T> inline void DoublyLinkedList<T>::clear()
>>>>>>> miniblink49
{
    m_head = 0;
    m_tail = 0;
}

<<<<<<< HEAD
template <typename T>
inline T* DoublyLinkedList<T>::head() const
=======
template<typename T> inline T* DoublyLinkedList<T>::head() const
>>>>>>> miniblink49
{
    return m_head;
}

<<<<<<< HEAD
template <typename T>
inline T* DoublyLinkedList<T>::tail() const
=======
template<typename T> inline T* DoublyLinkedList<T>::tail() const
>>>>>>> miniblink49
{
    return m_tail;
}

<<<<<<< HEAD
template <typename T>
inline void DoublyLinkedList<T>::push(T* node)
{
    if (!m_head) {
        DCHECK(!m_tail);
=======
template<typename T> inline void DoublyLinkedList<T>::push(T* node)
{
    if (!m_head) {
        ASSERT(!m_tail);
>>>>>>> miniblink49
        m_head = node;
        m_tail = node;
        node->setPrev(0);
        node->setNext(0);
        return;
    }

<<<<<<< HEAD
    DCHECK(m_tail);
=======
    ASSERT(m_tail);
>>>>>>> miniblink49
    m_head->setPrev(node);
    node->setNext(m_head);
    node->setPrev(0);
    m_head = node;
}

<<<<<<< HEAD
template <typename T>
inline void DoublyLinkedList<T>::append(T* node)
{
    if (!m_tail) {
        DCHECK(!m_head);
=======
template<typename T> inline void DoublyLinkedList<T>::append(T* node)
{
    if (!m_tail) {
        ASSERT(!m_head);
>>>>>>> miniblink49
        m_head = node;
        m_tail = node;
        node->setPrev(0);
        node->setNext(0);
        return;
    }

<<<<<<< HEAD
    DCHECK(m_head);
=======
    ASSERT(m_head);
>>>>>>> miniblink49
    m_tail->setNext(node);
    node->setPrev(m_tail);
    node->setNext(0);
    m_tail = node;
}

<<<<<<< HEAD
template <typename T>
inline void DoublyLinkedList<T>::remove(T* node)
{
    if (node->prev()) {
        DCHECK_NE(node, m_head);
        node->prev()->setNext(node->next());
    } else {
        DCHECK_EQ(node, m_head);
=======
template<typename T> inline void DoublyLinkedList<T>::remove(T* node)
{
    if (node->prev()) {
        ASSERT(node != m_head);
        node->prev()->setNext(node->next());
    } else {
        ASSERT(node == m_head);
>>>>>>> miniblink49
        m_head = node->next();
    }

    if (node->next()) {
<<<<<<< HEAD
        DCHECK_NE(node, m_tail);
        node->next()->setPrev(node->prev());
    } else {
        DCHECK_EQ(node, m_tail);
=======
        ASSERT(node != m_tail);
        node->next()->setPrev(node->prev());
    } else {
        ASSERT(node == m_tail);
>>>>>>> miniblink49
        m_tail = node->prev();
    }
}

<<<<<<< HEAD
template <typename T>
inline T* DoublyLinkedList<T>::removeHead()
=======
template<typename T> inline T* DoublyLinkedList<T>::removeHead()
>>>>>>> miniblink49
{
    T* node = head();
    if (node)
        remove(node);
    return node;
}

} // namespace WTF

<<<<<<< HEAD
using WTF::DoublyLinkedList;
using WTF::DoublyLinkedListNode;
=======
using WTF::DoublyLinkedListNode;
using WTF::DoublyLinkedList;
>>>>>>> miniblink49

#endif

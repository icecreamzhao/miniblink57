/*
 * Copyright (C) 2009 Jian Li <jianli@chromium.org>
 * Copyright (C) 2012 Patrick Gansterer <paroga@paroga.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "ThreadSpecific.h"

#if OS(WIN)

#include "StdLibExtras.h"
#include "ThreadingPrimitives.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/DoublyLinkedList.h"

namespace WTF {

static DoublyLinkedList<PlatformThreadSpecificKey>& destructorsList()
{
<<<<<<< HEAD
    DEFINE_STATIC_LOCAL(DoublyLinkedList<PlatformThreadSpecificKey>, staticList,
        ());
=======
    DEFINE_STATIC_LOCAL(DoublyLinkedList<PlatformThreadSpecificKey>, staticList, ());
>>>>>>> miniblink49
    return staticList;
}

static Mutex& destructorsMutex()
{
    DEFINE_STATIC_LOCAL(Mutex, staticMutex, ());
    return staticMutex;
}

<<<<<<< HEAD
class PlatformThreadSpecificKey
    : public DoublyLinkedListNode<PlatformThreadSpecificKey> {
    USING_FAST_MALLOC(PlatformThreadSpecificKey);
    WTF_MAKE_NONCOPYABLE(PlatformThreadSpecificKey);

public:
    friend class DoublyLinkedListNode<PlatformThreadSpecificKey>;

    PlatformThreadSpecificKey(void (*destructor)(void*))
=======
class PlatformThreadSpecificKey : public DoublyLinkedListNode<PlatformThreadSpecificKey> {
public:
    friend class DoublyLinkedListNode<PlatformThreadSpecificKey>;

    PlatformThreadSpecificKey(void (*destructor)(void *))
>>>>>>> miniblink49
        : m_destructor(destructor)
    {
        m_tlsKey = TlsAlloc();
        if (m_tlsKey == TLS_OUT_OF_INDEXES)
            CRASH();
    }

<<<<<<< HEAD
    ~PlatformThreadSpecificKey() { TlsFree(m_tlsKey); }
=======
    ~PlatformThreadSpecificKey()
    {
        TlsFree(m_tlsKey);
    }
>>>>>>> miniblink49

    void setValue(void* data) { TlsSetValue(m_tlsKey, data); }
    void* value() { return TlsGetValue(m_tlsKey); }

    void callDestructor()
    {
<<<<<<< HEAD
        if (void* data = value())
=======
       if (void* data = value())
>>>>>>> miniblink49
            m_destructor(data);
    }

private:
<<<<<<< HEAD
    void (*m_destructor)(void*);
=======
    void (*m_destructor)(void *);
>>>>>>> miniblink49
    DWORD m_tlsKey;
    PlatformThreadSpecificKey* m_prev;
    PlatformThreadSpecificKey* m_next;
};

long& tlsKeyCount()
{
    static long count;
    return count;
}

DWORD* tlsKeys()
{
    static DWORD keys[kMaxTlsKeySize];
    return keys;
}

<<<<<<< HEAD
void threadSpecificKeyCreate(ThreadSpecificKey* key,
    void (*destructor)(void*))
=======
void threadSpecificKeyCreate(ThreadSpecificKey* key, void (*destructor)(void *))
>>>>>>> miniblink49
{
    *key = new PlatformThreadSpecificKey(destructor);

    MutexLocker locker(destructorsMutex());
    destructorsList().push(*key);
}

void threadSpecificKeyDelete(ThreadSpecificKey key)
{
    MutexLocker locker(destructorsMutex());
    destructorsList().remove(key);
    delete key;
}

void threadSpecificSet(ThreadSpecificKey key, void* data)
{
    key->setValue(data);
}

void* threadSpecificGet(ThreadSpecificKey key)
{
    return key->value();
}

void ThreadSpecificThreadExit()
{
    for (long i = 0; i < tlsKeyCount(); i++) {
<<<<<<< HEAD
        // The layout of ThreadSpecific<T>::Data does not depend on T. So we are
        // safe to do the static cast to ThreadSpecific<int> in order to access its
        // data member.
=======
        // The layout of ThreadSpecific<T>::Data does not depend on T. So we are safe to do the static cast to ThreadSpecific<int> in order to access its data member.
>>>>>>> miniblink49
        ThreadSpecific<int>::Data* data = static_cast<ThreadSpecific<int>::Data*>(TlsGetValue(tlsKeys()[i]));
        if (data)
            data->destructor(data);
    }

    MutexLocker locker(destructorsMutex());
    PlatformThreadSpecificKey* key = destructorsList().head();
    while (key) {
        PlatformThreadSpecificKey* nextKey = key->next();
        key->callDestructor();
        key = nextKey;
    }
}

} // namespace WTF

#endif // OS(WIN)

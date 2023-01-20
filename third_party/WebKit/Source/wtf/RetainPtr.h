/*
 *  Copyright (C) 2005, 2006, 2007, 2008, 2010 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 *
 */

#ifndef RetainPtr_h
#define RetainPtr_h

<<<<<<< HEAD
#include "wtf/Compiler.h"
#include "wtf/HashTableDeletedValueType.h"
#include "wtf/HashTraits.h"
#include "wtf/TypeTraits.h"
#include <algorithm>
#include <type_traits>
=======
#include "wtf/HashTableDeletedValueType.h"
#include "wtf/HashTraits.h"
#include "wtf/NullPtr.h"
#include "wtf/TypeTraits.h"
#include <algorithm>
>>>>>>> miniblink49
#include <utility>

#if USE(CF)
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#endif

#ifndef CF_RELEASES_ARGUMENT
#define CF_RELEASES_ARGUMENT
#endif

#ifndef NS_RELEASES_ARGUMENT
#define NS_RELEASES_ARGUMENT
#endif

namespace WTF {

<<<<<<< HEAD
// Unlike most most of our smart pointers, RetainPtr can take either the pointer
// type or the pointed-to type, so both RetainPtr<NSDictionary> and
// RetainPtr<CFDictionaryRef> will work.

enum AdoptCFTag { AdoptCF };
enum AdoptNSTag { AdoptNS };

#ifdef __OBJC__
inline void adoptNSReference(id ptr)
{
    if (ptr) {
        CFRetain(ptr);
        [ptr release];
    }
}
#endif

template <typename T>
class RetainPtr {
public:
    typedef typename std::remove_pointer<T>::type ValueType;
    typedef ValueType* PtrType;

    RetainPtr()
        : m_ptr(nullptr)
    {
    }
    RetainPtr(PtrType ptr)
        : m_ptr(ptr)
    {
        if (ptr)
            CFRetain(ptr);
    }

    RetainPtr(AdoptCFTag, PtrType ptr)
        : m_ptr(ptr)
    {
    }
    RetainPtr(AdoptNSTag, PtrType ptr)
        : m_ptr(ptr)
    {
        adoptNSReference(ptr);
    }

    RetainPtr(const RetainPtr& o)
        : m_ptr(o.m_ptr)
=======
    // Unlike most most of our smart pointers, RetainPtr can take either the pointer type or the pointed-to type,
    // so both RetainPtr<NSDictionary> and RetainPtr<CFDictionaryRef> will work.

    enum AdoptCFTag { AdoptCF };
    enum AdoptNSTag { AdoptNS };

#ifdef __OBJC__
    inline void adoptNSReference(id ptr)
    {
        if (ptr) {
            CFRetain(ptr);
            [ptr release];
        }
    }
#endif

    template<typename T> class RetainPtr {
    public:
        typedef typename RemovePointer<T>::Type ValueType;
        typedef ValueType* PtrType;

        RetainPtr() : m_ptr(0) {}
        RetainPtr(PtrType ptr) : m_ptr(ptr) { if (ptr) CFRetain(ptr); }

        RetainPtr(AdoptCFTag, PtrType ptr) : m_ptr(ptr) { }
        RetainPtr(AdoptNSTag, PtrType ptr) : m_ptr(ptr) { adoptNSReference(ptr); }

        RetainPtr(const RetainPtr& o) : m_ptr(o.m_ptr) { if (PtrType ptr = m_ptr) CFRetain(ptr); }

        RetainPtr(RetainPtr&& o) : m_ptr(o.leakRef()) { }

        // Hash table deleted values, which are only constructed and never copied or destroyed.
        RetainPtr(HashTableDeletedValueType) : m_ptr(hashTableDeletedValue()) { }
        bool isHashTableDeletedValue() const { return m_ptr == hashTableDeletedValue(); }

        ~RetainPtr() { if (PtrType ptr = m_ptr) CFRelease(ptr); }

        template<typename U> RetainPtr(const RetainPtr<U>&);

        void clear();
        PtrType leakRef() WARN_UNUSED_RETURN;

        PtrType get() const { return m_ptr; }
        PtrType operator->() const { return m_ptr; }
#if COMPILER_SUPPORTS(CXX_EXPLICIT_CONVERSIONS)
        explicit operator PtrType() const { return m_ptr; }
#endif

        bool operator!() const { return !m_ptr; }

        // This conversion operator allows implicit conversion to bool but not to other integer types.
        typedef PtrType RetainPtr::*UnspecifiedBoolType;
        operator UnspecifiedBoolType() const { return m_ptr ? &RetainPtr::m_ptr : 0; }

        RetainPtr& operator=(const RetainPtr&);
        template<typename U> RetainPtr& operator=(const RetainPtr<U>&);
        RetainPtr& operator=(PtrType);
        template<typename U> RetainPtr& operator=(U*);

        RetainPtr& operator=(RetainPtr&&);
        template<typename U> RetainPtr& operator=(RetainPtr<U>&&);

#if !COMPILER_SUPPORTS(CXX_NULLPTR)
        RetainPtr& operator=(std::nullptr_t) { clear(); return *this; }
#endif

        void adoptCF(PtrType);
        void adoptNS(PtrType);

        void swap(RetainPtr&);

    private:
        static PtrType hashTableDeletedValue() { return reinterpret_cast<PtrType>(-1); }

        PtrType m_ptr;
    };

    template<typename T> template<typename U> inline RetainPtr<T>::RetainPtr(const RetainPtr<U>& o)
        : m_ptr(o.get())
>>>>>>> miniblink49
    {
        if (PtrType ptr = m_ptr)
            CFRetain(ptr);
    }

<<<<<<< HEAD
    RetainPtr(RetainPtr&& o)
        : m_ptr(o.leakRef())
    {
    }

    // Hash table deleted values, which are only constructed and never copied or
    // destroyed.
    RetainPtr(HashTableDeletedValueType)
        : m_ptr(hashTableDeletedValue())
    {
    }
    bool isHashTableDeletedValue() const
    {
        return m_ptr == hashTableDeletedValue();
    }

    ~RetainPtr()
    {
        if (PtrType ptr = m_ptr)
            CFRelease(ptr);
    }

    template <typename U>
    RetainPtr(const RetainPtr<U>&);

    void clear();
    WARN_UNUSED_RESULT PtrType leakRef();

    PtrType get() const { return m_ptr; }
    PtrType operator->() const { return m_ptr; }

    bool operator!() const { return !m_ptr; }
    explicit operator bool() const { return m_ptr; }

    RetainPtr& operator=(const RetainPtr&);
    template <typename U>
    RetainPtr& operator=(const RetainPtr<U>&);
    RetainPtr& operator=(PtrType);
    template <typename U>
    RetainPtr& operator=(U*);

    RetainPtr& operator=(RetainPtr&&);
    template <typename U>
    RetainPtr& operator=(RetainPtr<U>&&);

    RetainPtr& operator=(std::nullptr_t)
    {
        clear();
        return *this;
    }

    void adoptCF(PtrType);
    void adoptNS(PtrType);

    void swap(RetainPtr&);

private:
    static PtrType hashTableDeletedValue()
    {
        return reinterpret_cast<PtrType>(-1);
    }

    PtrType m_ptr;
};

template <typename T>
template <typename U>
inline RetainPtr<T>::RetainPtr(const RetainPtr<U>& o)
    : m_ptr(o.get())
{
    if (PtrType ptr = m_ptr)
        CFRetain(ptr);
}

template <typename T>
inline void RetainPtr<T>::clear()
{
    if (PtrType ptr = m_ptr) {
        m_ptr = nullptr;
        CFRelease(ptr);
    }
}

template <typename T>
inline typename RetainPtr<T>::PtrType RetainPtr<T>::leakRef()
{
    PtrType ptr = m_ptr;
    m_ptr = nullptr;
    return ptr;
}

template <typename T>
inline RetainPtr<T>& RetainPtr<T>::operator=(const RetainPtr<T>& o)
{
    PtrType optr = o.get();
    if (optr)
        CFRetain(optr);
    PtrType ptr = m_ptr;
    m_ptr = optr;
    if (ptr)
        CFRelease(ptr);
    return *this;
}

template <typename T>
template <typename U>
inline RetainPtr<T>& RetainPtr<T>::operator=(const RetainPtr<U>& o)
{
    PtrType optr = o.get();
    if (optr)
        CFRetain(optr);
    PtrType ptr = m_ptr;
    m_ptr = optr;
    if (ptr)
        CFRelease(ptr);
    return *this;
}

template <typename T>
inline RetainPtr<T>& RetainPtr<T>::operator=(PtrType optr)
{
    if (optr)
        CFRetain(optr);
    PtrType ptr = m_ptr;
    m_ptr = optr;
    if (ptr)
        CFRelease(ptr);
    return *this;
}

template <typename T>
template <typename U>
inline RetainPtr<T>& RetainPtr<T>::operator=(U* optr)
{
    if (optr)
        CFRetain(optr);
    PtrType ptr = m_ptr;
    m_ptr = optr;
    if (ptr)
        CFRelease(ptr);
    return *this;
}

template <typename T>
inline RetainPtr<T>& RetainPtr<T>::operator=(RetainPtr<T>&& o)
{
    adoptCF(o.leakRef());
    return *this;
}

template <typename T>
template <typename U>
inline RetainPtr<T>& RetainPtr<T>::operator=(RetainPtr<U>&& o)
{
    adoptCF(o.leakRef());
    return *this;
}

template <typename T>
inline void RetainPtr<T>::adoptCF(PtrType optr)
{
    PtrType ptr = m_ptr;
    m_ptr = optr;
    if (ptr)
        CFRelease(ptr);
}

template <typename T>
inline void RetainPtr<T>::adoptNS(PtrType optr)
{
    adoptNSReference(optr);

    PtrType ptr = m_ptr;
    m_ptr = optr;
    if (ptr)
        CFRelease(ptr);
}

template <typename T>
inline void RetainPtr<T>::swap(RetainPtr<T>& o)
{
    std::swap(m_ptr, o.m_ptr);
}

template <typename T>
inline void swap(RetainPtr<T>& a, RetainPtr<T>& b)
{
    a.swap(b);
}

template <typename T, typename U>
inline bool operator==(const RetainPtr<T>& a, const RetainPtr<U>& b)
{
    return a.get() == b.get();
}

template <typename T, typename U>
inline bool operator==(const RetainPtr<T>& a, U* b)
{
    return a.get() == b;
}

template <typename T, typename U>
inline bool operator==(T* a, const RetainPtr<U>& b)
{
    return a == b.get();
}

template <typename T, typename U>
inline bool operator!=(const RetainPtr<T>& a, const RetainPtr<U>& b)
{
    return a.get() != b.get();
}

template <typename T, typename U>
inline bool operator!=(const RetainPtr<T>& a, U* b)
{
    return a.get() != b;
}

template <typename T, typename U>
inline bool operator!=(T* a, const RetainPtr<U>& b)
{
    return a != b.get();
}

template <typename T>
WARN_UNUSED_RESULT inline RetainPtr<T> adoptCF(T CF_RELEASES_ARGUMENT);
template <typename T>
inline RetainPtr<T> adoptCF(T o)
{
    return RetainPtr<T>(AdoptCF, o);
}

template <typename T>
WARN_UNUSED_RESULT inline RetainPtr<T> adoptNS(T NS_RELEASES_ARGUMENT);
template <typename T>
inline RetainPtr<T> adoptNS(T o)
{
    return RetainPtr<T>(AdoptNS, o);
}

// Helper function for creating a RetainPtr using template argument deduction.
template <typename T>
WARN_UNUSED_RESULT inline RetainPtr<T> retainPtr(T);
template <typename T>
inline RetainPtr<T> retainPtr(T o)
{
    return RetainPtr<T>(o);
}

template <typename T>
struct HashTraits<RetainPtr<T>> : SimpleClassHashTraits<RetainPtr<T>> {
};

template <typename T>
struct RetainPtrHash
    : PtrHash<
          typename std::remove_pointer<typename RetainPtr<T>::PtrType>::type> {
    using Base = PtrHash<
        typename std::remove_pointer<typename RetainPtr<T>::PtrType>::type>;
    using Base::hash;
    static unsigned hash(const RetainPtr<T>& key) { return hash(key.get()); }
    using Base::equal;
    static bool equal(const RetainPtr<T>& a, const RetainPtr<T>& b)
    {
        return a == b;
    }
    static bool equal(typename RetainPtr<T>::PtrType a, const RetainPtr<T>& b)
    {
        return a == b;
    }
    static bool equal(const RetainPtr<T>& a, typename RetainPtr<T>::PtrType b)
    {
        return a == b;
    }
};

template <typename T>
struct DefaultHash<RetainPtr<T>> {
    using Hash = RetainPtrHash<T>;
};

=======
    template<typename T> inline void RetainPtr<T>::clear()
    {
        if (PtrType ptr = m_ptr) {
            m_ptr = 0;
            CFRelease(ptr);
        }
    }

    template<typename T> inline typename RetainPtr<T>::PtrType RetainPtr<T>::leakRef()
    {
        PtrType ptr = m_ptr;
        m_ptr = 0;
        return ptr;
    }

    template<typename T> inline RetainPtr<T>& RetainPtr<T>::operator=(const RetainPtr<T>& o)
    {
        PtrType optr = o.get();
        if (optr)
            CFRetain(optr);
        PtrType ptr = m_ptr;
        m_ptr = optr;
        if (ptr)
            CFRelease(ptr);
        return *this;
    }

    template<typename T> template<typename U> inline RetainPtr<T>& RetainPtr<T>::operator=(const RetainPtr<U>& o)
    {
        PtrType optr = o.get();
        if (optr)
            CFRetain(optr);
        PtrType ptr = m_ptr;
        m_ptr = optr;
        if (ptr)
            CFRelease(ptr);
        return *this;
    }

    template<typename T> inline RetainPtr<T>& RetainPtr<T>::operator=(PtrType optr)
    {
        if (optr)
            CFRetain(optr);
        PtrType ptr = m_ptr;
        m_ptr = optr;
        if (ptr)
            CFRelease(ptr);
        return *this;
    }

    template<typename T> template<typename U> inline RetainPtr<T>& RetainPtr<T>::operator=(U* optr)
    {
        if (optr)
            CFRetain(optr);
        PtrType ptr = m_ptr;
        m_ptr = optr;
        if (ptr)
            CFRelease(ptr);
        return *this;
    }

    template<typename T> inline RetainPtr<T>& RetainPtr<T>::operator=(RetainPtr<T>&& o)
    {
        adoptCF(o.leakRef());
        return *this;
    }

    template<typename T> template<typename U> inline RetainPtr<T>& RetainPtr<T>::operator=(RetainPtr<U>&& o)
    {
        adoptCF(o.leakRef());
        return *this;
    }

    template<typename T> inline void RetainPtr<T>::adoptCF(PtrType optr)
    {
        PtrType ptr = m_ptr;
        m_ptr = optr;
        if (ptr)
            CFRelease(ptr);
    }

    template<typename T> inline void RetainPtr<T>::adoptNS(PtrType optr)
    {
        adoptNSReference(optr);

        PtrType ptr = m_ptr;
        m_ptr = optr;
        if (ptr)
            CFRelease(ptr);
    }

    template<typename T> inline void RetainPtr<T>::swap(RetainPtr<T>& o)
    {
        std::swap(m_ptr, o.m_ptr);
    }

    template<typename T> inline void swap(RetainPtr<T>& a, RetainPtr<T>& b)
    {
        a.swap(b);
    }

    template<typename T, typename U> inline bool operator==(const RetainPtr<T>& a, const RetainPtr<U>& b)
    {
        return a.get() == b.get();
    }

    template<typename T, typename U> inline bool operator==(const RetainPtr<T>& a, U* b)
    {
        return a.get() == b;
    }

    template<typename T, typename U> inline bool operator==(T* a, const RetainPtr<U>& b)
    {
        return a == b.get();
    }

    template<typename T, typename U> inline bool operator!=(const RetainPtr<T>& a, const RetainPtr<U>& b)
    {
        return a.get() != b.get();
    }

    template<typename T, typename U> inline bool operator!=(const RetainPtr<T>& a, U* b)
    {
        return a.get() != b;
    }

    template<typename T, typename U> inline bool operator!=(T* a, const RetainPtr<U>& b)
    {
        return a != b.get();
    }

    template<typename T> inline RetainPtr<T> adoptCF(T CF_RELEASES_ARGUMENT) WARN_UNUSED_RETURN;
    template<typename T> inline RetainPtr<T> adoptCF(T o)
    {
        return RetainPtr<T>(AdoptCF, o);
    }

    template<typename T> inline RetainPtr<T> adoptNS(T NS_RELEASES_ARGUMENT) WARN_UNUSED_RETURN;
    template<typename T> inline RetainPtr<T> adoptNS(T o)
    {
        return RetainPtr<T>(AdoptNS, o);
    }

    // Helper function for creating a RetainPtr using template argument deduction.
    template<typename T> inline RetainPtr<T> retainPtr(T) WARN_UNUSED_RETURN;
    template<typename T> inline RetainPtr<T> retainPtr(T o)
    {
        return RetainPtr<T>(o);
    }

    template<typename P> struct HashTraits<RetainPtr<P>> : SimpleClassHashTraits<RetainPtr<P>> { };

    template<typename P> struct PtrHash<RetainPtr<P>> : PtrHash<typename RetainPtr<P>::PtrType> {
        using PtrHash<typename RetainPtr<P>::PtrType>::hash;
        static unsigned hash(const RetainPtr<P>& key) { return hash(key.get()); }
        using PtrHash<typename RetainPtr<P>::PtrType>::equal;
        static bool equal(const RetainPtr<P>& a, const RetainPtr<P>& b) { return a == b; }
        static bool equal(typename RetainPtr<P>::PtrType a, const RetainPtr<P>& b) { return a == b; }
        static bool equal(const RetainPtr<P>& a, typename RetainPtr<P>::PtrType b) { return a == b; }
    };

    template<typename P> struct DefaultHash<RetainPtr<P>> { typedef PtrHash<RetainPtr<P>> Hash; };
>>>>>>> miniblink49
} // namespace WTF

using WTF::AdoptCF;
using WTF::AdoptNS;
using WTF::adoptCF;
using WTF::adoptNS;
using WTF::RetainPtr;
using WTF::retainPtr;

#endif // WTF_RetainPtr_h

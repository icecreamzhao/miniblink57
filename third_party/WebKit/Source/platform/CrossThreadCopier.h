/*
 * Copyright (C) 2009, 2010 Google Inc. All rights reserved.
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

#ifndef CrossThreadCopier_h
#define CrossThreadCopier_h

#include "platform/PlatformExport.h"
<<<<<<< HEAD
#include "third_party/skia/include/core/SkRefCnt.h"
#include "wtf/Assertions.h"
#include "wtf/Forward.h"
#include "wtf/Functional.h" // FunctionThreadAffinity
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"
#include "wtf/ThreadSafeRefCounted.h"
#include "wtf/TypeTraits.h"
#include "wtf/WeakPtr.h"
#include <memory>

class SkRefCnt;

namespace WTF {

template <typename T>
class PassedWrapper;
}

namespace blink {

class IntRect;
class IntSize;
class KURL;
class ResourceError;
class ResourceRequest;
class ResourceResponse;
struct CrossThreadResourceResponseData;
struct CrossThreadResourceRequestData;
template <typename T>
class CrossThreadPersistent;
template <typename T>
class CrossThreadWeakPersistent;

template <typename T>
struct CrossThreadCopierPassThrough {
    STATIC_ONLY(CrossThreadCopierPassThrough);
    typedef T Type;
    static Type copy(const T& parameter) { return parameter; }
};

template <typename T, bool isArithmeticOrEnum>
struct CrossThreadCopierBase;

// Arithmetic values (integers or floats) and enums can be safely copied.
template <typename T>
struct CrossThreadCopierBase<T, true> : public CrossThreadCopierPassThrough<T> {
    STATIC_ONLY(CrossThreadCopierBase);
};

template <typename T>
struct CrossThreadCopier
    : public CrossThreadCopierBase<T,
          std::is_arithmetic<T>::value || std::is_enum<T>::value> {
    STATIC_ONLY(CrossThreadCopier);
};

// CrossThreadCopier specializations follow.
template <typename T>
struct CrossThreadCopier<PassRefPtr<T>> {
    STATIC_ONLY(CrossThreadCopier);
    typedef PassRefPtr<T> Type;
    static_assert(WTF::IsSubclassOfTemplate<T, ThreadSafeRefCounted>::value,
        "PassRefPtr<T> can be passed across threads only if T is "
        "ThreadSafeRefCounted.");
    static PassRefPtr<T> copy(PassRefPtr<T>&& pointer)
    {
        return std::move(pointer);
    }
};
template <typename T>
struct CrossThreadCopier<RefPtr<T>>
    : public CrossThreadCopierPassThrough<RefPtr<T>> {
    STATIC_ONLY(CrossThreadCopier);
    static_assert(WTF::IsSubclassOfTemplate<T, ThreadSafeRefCounted>::value,
        "RefPtr<T> can be passed across threads only if T is "
        "ThreadSafeRefCounted.");
};
template <typename T>
struct CrossThreadCopier<sk_sp<T>>
    : public CrossThreadCopierPassThrough<sk_sp<T>> {
    STATIC_ONLY(CrossThreadCopier);
    static_assert(std::is_base_of<SkRefCnt, T>::value,
        "sk_sp<T> can be passed across threads only if T is SkRefCnt.");
};

// nullptr_t can be passed through without any changes.
template <>
struct CrossThreadCopier<std::nullptr_t>
    : public CrossThreadCopierPassThrough<std::nullptr_t> {
    STATIC_ONLY(CrossThreadCopier);
};

// To allow a type to be passed across threads using its copy constructor, add a
// forward declaration of the type and provide a specialization of
// CrossThreadCopier<T> in this file, like IntRect below.
template <>
struct CrossThreadCopier<IntRect>
    : public CrossThreadCopierPassThrough<IntRect> {
    STATIC_ONLY(CrossThreadCopier);
};

template <>
struct CrossThreadCopier<IntSize>
    : public CrossThreadCopierPassThrough<IntSize> {
    STATIC_ONLY(CrossThreadCopier);
};

template <typename T, typename Deleter>
struct CrossThreadCopier<std::unique_ptr<T, Deleter>> {
    STATIC_ONLY(CrossThreadCopier);
    using Type = std::unique_ptr<T, Deleter>;
    static std::unique_ptr<T, Deleter> copy(std::unique_ptr<T, Deleter> pointer)
    {
        return pointer; // This is in fact a move.
    }
};

template <typename T>
struct CrossThreadCopier<CrossThreadPersistent<T>>
    : public CrossThreadCopierPassThrough<CrossThreadPersistent<T>> {
    STATIC_ONLY(CrossThreadCopier);
};

template <typename T>
struct CrossThreadCopier<CrossThreadWeakPersistent<T>>
    : public CrossThreadCopierPassThrough<CrossThreadWeakPersistent<T>> {
    STATIC_ONLY(CrossThreadCopier);
};

template <typename T>
struct CrossThreadCopier<WTF::UnretainedWrapper<T, WTF::CrossThreadAffinity>>
    : public CrossThreadCopierPassThrough<
          WTF::UnretainedWrapper<T, WTF::CrossThreadAffinity>> {
    STATIC_ONLY(CrossThreadCopier);
};

template <typename T>
struct CrossThreadCopier<WeakPtr<T>>
    : public CrossThreadCopierPassThrough<WeakPtr<T>> {
    STATIC_ONLY(CrossThreadCopier);
};

template <typename T>
struct CrossThreadCopier<WTF::PassedWrapper<T>> {
    STATIC_ONLY(CrossThreadCopier);
    using Type = WTF::PassedWrapper<typename CrossThreadCopier<T>::Type>;
    static Type copy(WTF::PassedWrapper<T>&& value)
    {
        return WTF::passed(CrossThreadCopier<T>::copy(value.moveOut()));
    }
};

template <>
struct CrossThreadCopier<KURL> {
    STATIC_ONLY(CrossThreadCopier);
    typedef KURL Type;
    PLATFORM_EXPORT static Type copy(const KURL&);
};

template <>
struct CrossThreadCopier<String> {
    STATIC_ONLY(CrossThreadCopier);
    typedef String Type;
    PLATFORM_EXPORT static Type copy(const String&);
};

template <>
struct CrossThreadCopier<ResourceError> {
    STATIC_ONLY(CrossThreadCopier);
    typedef ResourceError Type;
    PLATFORM_EXPORT static Type copy(const ResourceError&);
};

template <>
struct CrossThreadCopier<ResourceRequest> {
    STATIC_ONLY(CrossThreadCopier);
    typedef WTF::PassedWrapper<std::unique_ptr<CrossThreadResourceRequestData>>
        Type;
    PLATFORM_EXPORT static Type copy(const ResourceRequest&);
};

template <>
struct CrossThreadCopier<ResourceResponse> {
    STATIC_ONLY(CrossThreadCopier);
    typedef WTF::PassedWrapper<std::unique_ptr<CrossThreadResourceResponseData>>
        Type;
    PLATFORM_EXPORT static Type copy(const ResourceResponse&);
};
=======
#include "platform/heap/Handle.h"
#include "wtf/Assertions.h"
#include "wtf/Forward.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RawPtr.h"
#include "wtf/RefPtr.h"
#include "wtf/ThreadSafeRefCounted.h"
#include "wtf/TypeTraits.h"

namespace blink {

    class IntRect;
    class IntSize;
    class KURL;
    class ResourceError;
    class ResourceRequest;
    class ResourceResponse;
    struct CrossThreadResourceResponseData;
    struct CrossThreadResourceRequestData;

    template<typename T> struct CrossThreadCopierPassThrough {
        typedef T Type;
        static Type copy(const T& parameter)
        {
            return parameter;
        }
    };

    template<bool isConvertibleToInteger, bool isThreadSafeRefCounted, bool isGarbageCollected, typename T> struct CrossThreadCopierBase;

    // Integers get passed through without any changes.
    template<typename T> struct CrossThreadCopierBase<true, false, false, T> : public CrossThreadCopierPassThrough<T> {
    };

    // To allow a type to be passed across threads using its copy constructor, add a forward declaration of the type and
    // a CopyThreadCopierBase<false, false, TypeName> : public CrossThreadCopierPassThrough<TypeName> { }; to this file.
    template<> struct CrossThreadCopierBase<false, false, false, IntRect> : public CrossThreadCopierPassThrough<IntRect> {
    };

    template<> struct CrossThreadCopierBase<false, false, false, IntSize> : public CrossThreadCopierPassThrough<IntSize> {
    };

    // Custom copy methods.
    template<typename T> struct CrossThreadCopierBase<false, true, false, T> {
        typedef typename WTF::RemoveTemplate<T, RefPtr>::Type TypeWithoutRefPtr;
        typedef typename WTF::RemoveTemplate<TypeWithoutRefPtr, PassRefPtr>::Type TypeWithoutPassRefPtr;
        typedef typename WTF::RemovePointer<TypeWithoutPassRefPtr>::Type RefCountedType;

        // Verify that only one of the above did a change.
        static_assert((WTF::IsSameType<RefPtr<RefCountedType>, T>::value
                        || WTF::IsSameType<PassRefPtr<RefCountedType>, T>::value
                        || WTF::IsSameType<RefCountedType*, T>::value),
                        "only one type modification should be allowed");

        typedef PassRefPtr<RefCountedType> Type;
        static Type copy(const T& refPtr)
        {
            return refPtr;
        }
    };

    template<typename T> struct CrossThreadCopierBase<false, false, false, PassOwnPtr<T>> {
        typedef PassOwnPtr<T> Type;
        static Type copy(Type ownPtr)
        {
            return ownPtr;
        }
    };

    template<typename T> struct CrossThreadCopierBase<false, false, false, WeakMember<T>*> {
        typedef WeakMember<T>* Type;
        static Type copy(Type ptr)
        {
            return ptr;
        }
    };

    template<> struct CrossThreadCopierBase<false, false, false, KURL> {
        typedef KURL Type;
        PLATFORM_EXPORT static Type copy(const KURL&);
    };

    template<> struct CrossThreadCopierBase<false, false, false, String> {
        typedef String Type;
        PLATFORM_EXPORT static Type copy(const String&);
    };

    template<> struct CrossThreadCopierBase<false, false, false, ResourceError> {
        typedef ResourceError Type;
        PLATFORM_EXPORT static Type copy(const ResourceError&);
    };

    template<> struct CrossThreadCopierBase<false, false, false, ResourceRequest> {
        typedef PassOwnPtr<CrossThreadResourceRequestData> Type;
        PLATFORM_EXPORT static Type copy(const ResourceRequest&);
    };

    template<> struct CrossThreadCopierBase<false, false, false, ResourceResponse> {
        typedef PassOwnPtr<CrossThreadResourceResponseData> Type;
        PLATFORM_EXPORT static Type copy(const ResourceResponse&);
    };

    template<typename T> struct CrossThreadCopierBase<false, false, true, T> {
        typedef typename WTF::RemovePointer<T>::Type TypeWithoutPointer;
        typedef RawPtr<TypeWithoutPointer> Type;
        static Type copy(const T& ptr)
        {
            return ptr;
        }
    };

    template<typename T> struct CrossThreadCopierBase<false, false, true, RawPtr<T>> {
        typedef RawPtr<T> Type;
        static Type copy(const Type& ptr)
        {
            return ptr;
        }
    };

    template<typename T> struct CrossThreadCopierBase<false, false, true, Member<T>> {
        typedef RawPtr<T> Type;
        static Type copy(const Member<T>& ptr)
        {
            return ptr;
        }
    };

    template<typename T> struct CrossThreadCopierBase<false, false, true, WeakMember<T>> {
        typedef RawPtr<T> Type;
        static Type copy(const WeakMember<T>& ptr)
        {
            return ptr;
        }
    };

    template<typename T> struct CrossThreadCopier : public CrossThreadCopierBase<WTF::IsConvertibleToInteger<T>::value,
        WTF::IsSubclassOfTemplate<typename WTF::RemoveTemplate<T, RefPtr>::Type, ThreadSafeRefCounted>::value
            || WTF::IsSubclassOfTemplate<typename WTF::RemovePointer<T>::Type, ThreadSafeRefCounted>::value
            || WTF::IsSubclassOfTemplate<typename WTF::RemoveTemplate<T, PassRefPtr>::Type, ThreadSafeRefCounted>::value,
        WTF::IsSubclassOfTemplate<typename WTF::RemovePointer<T>::Type, GarbageCollected>::value
            || WTF::IsSubclassOfTemplate<typename WTF::RemoveTemplate<T, RawPtr>::Type, GarbageCollected>::value
            || WTF::IsSubclassOfTemplate<typename WTF::RemoveTemplate<T, Member>::Type, GarbageCollected>::value
            || WTF::IsSubclassOfTemplate<typename WTF::RemoveTemplate<T, WeakMember>::Type, GarbageCollected>::value,
        T> {
    };

    // |T| is |C*| or |const WeakPtr<C>&|.
    template<typename T> struct AllowCrossThreadAccessWrapper {
        STACK_ALLOCATED();
    public:
        explicit AllowCrossThreadAccessWrapper(T value) : m_value(value) { }
        T value() const { return m_value; }
    private:
        // This raw pointer is safe since AllowCrossThreadAccessWrapper is
        // always stack-allocated. Ideally this should be Member<T> if T is
        // garbage-collected and T* otherwise, but we don't want to introduce
        // another template magic just for distinguishing Member<T> from T*.
        // From the perspective of GC, T* always works correctly.
        GC_PLUGIN_IGNORE("")
        T m_value;
    };

    template<typename T> struct CrossThreadCopierBase<false, false, false, AllowCrossThreadAccessWrapper<T>> {
        typedef T Type;
        static Type copy(const AllowCrossThreadAccessWrapper<T>& wrapper) { return wrapper.value(); }
    };

    template<typename T> AllowCrossThreadAccessWrapper<T*> AllowCrossThreadAccess(T* value)
    {
        return AllowCrossThreadAccessWrapper<T*>(value);
    }

    template<typename T> AllowCrossThreadAccessWrapper<const WeakPtr<T>&> AllowCrossThreadAccess(const WeakPtr<T>& value)
    {
        return AllowCrossThreadAccessWrapper<const WeakPtr<T>&>(value);
    }

    // FIXME: Move to a different header file. AllowAccessLater is for cross-thread access
    // that is not cross-thread (tasks posted to a queue guaranteed to run on the same thread).
    template<typename T> struct AllowAccessLaterWrapper {
    public:
        explicit AllowAccessLaterWrapper(T* value) : m_value(value) { }
        T* value() const { return m_value; }
    private:
        // This raw pointer is safe since AllowAccessLaterWrapper is
        // always stack-allocated. Ideally this should be Member<T> if T is
        // garbage-collected and T* otherwise, but we don't want to introduce
        // another template magic just for distinguishing Member<T> from T*.
        // From the perspective of GC, T* always works correctly.
        GC_PLUGIN_IGNORE("")
        T* m_value;
    };

    template<typename T> struct CrossThreadCopierBase<false, false, false, AllowAccessLaterWrapper<T>> {
        typedef T* Type;
        static Type copy(const AllowAccessLaterWrapper<T>& wrapper) { return wrapper.value(); }
    };

    template<typename T> AllowAccessLaterWrapper<T> AllowAccessLater(T* value)
    {
        return AllowAccessLaterWrapper<T>(value);
    }

>>>>>>> miniblink49

} // namespace blink

#endif // CrossThreadCopier_h

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

#ifndef WTF_Functional_h
#define WTF_Functional_h

<<<<<<< HEAD
#include "base/bind.h"
#include "base/threading/thread_checker.h"
#include "wtf/Allocator.h"
#include "wtf/Assertions.h"
#include "wtf/PassRefPtr.h"
#include "wtf/PtrUtil.h"
#include "wtf/RefPtr.h"
#include "wtf/ThreadSafeRefCounted.h"
#include "wtf/TypeTraits.h"
#include <utility>

namespace blink {
template <typename T>
class Member;
template <typename T>
class WeakMember;
}

namespace WTF {

// Functional.h provides a very simple way to bind a function pointer and
// arguments together into a function object that can be stored, copied and
// invoked, similar to boost::bind and std::bind in C++11.

// Thread Safety:
//
// WTF::bind() and WTF::Closure should be used for same-thread closures
// only, i.e. the closures must be created, executed and destructed on
// the same thread.
// Use crossThreadBind() and CrossThreadClosure if the function/task is called
// or destructed on a (potentially) different thread from the current thread.

// WTF::bind() and move semantics
// ==============================
//
// For unbound parameters (arguments supplied later on the bound functor
// directly), there are two ways to pass movable arguments:
//
//     1) Pass by rvalue reference.
//
//            void yourFunction(Argument&& argument) { ... }
//            std::unique_ptr<Function<void(Argument&&)>> functor =
//                bind<Argument&&>(yourFunction);
//
//     2) Pass by value.
//
//            void yourFunction(Argument argument) { ... }
//            std::unique_ptr<Function<void(Argument)>> functor =
//                bind<Argument>(yourFunction);
//
// Note that with the latter there will be *two* move constructions happening,
// because there needs to be at least one intermediary function call taking an
// argument of type "Argument" (i.e. passed by value). The former case does not
// require any move constructions inbetween.
//
// For bound parameters (arguments supplied on the creation of a functor), you
// can move your argument into the internal storage of the functor by supplying
// an rvalue to that argument (this is done in wrap() of ParamStorageTraits).
// However, to make the functor be able to get called multiple times, the
// stored object does not get moved out automatically when the underlying
// function is actually invoked. If you want to make an argument "auto-passed",
// you can do so by wrapping your bound argument with WTF::passed() function, as
// shown below:
//
//     void yourFunction(Argument argument)
//     {
//         // |argument| is passed from the internal storage of functor.
//         ...
//     }
//
//     ...
//     std::unique_ptr<Function<void()>> functor = bind(yourFunction,
//         WTF::passed(Argument()));
//     ...
//     (*functor)();
//
// The underlying function must receive the argument wrapped by WTF::passed() by
// rvalue reference or by value.
//
// Obviously, if you create a functor this way, you shouldn't call the functor
// twice or more; after the second call, the passed argument may be invalid.

enum FunctionThreadAffinity { CrossThreadAffinity,
    SameThreadAffinity };

template <typename T>
class PassedWrapper final {
public:
    explicit PassedWrapper(T&& scoper)
        : m_scoper(std::move(scoper))
    {
    }
    PassedWrapper(PassedWrapper&& other)
        : m_scoper(std::move(other.m_scoper))
    {
    }
    T moveOut() const { return std::move(m_scoper); }

private:
    mutable T m_scoper;
};

template <typename T>
PassedWrapper<T> passed(T&& value)
{
    static_assert(
        !std::is_reference<T>::value,
        "You must pass an rvalue to WTF::passed() so it can be moved. Add "
        "std::move() if necessary.");
    static_assert(!std::is_const<T>::value,
        "|value| must not be const so it can be moved.");
    return PassedWrapper<T>(std::move(value));
}

template <typename T, FunctionThreadAffinity threadAffinity>
class UnretainedWrapper final {
public:
    explicit UnretainedWrapper(T* ptr)
        : m_ptr(ptr)
    {
    }
    T* value() const { return m_ptr; }

private:
    T* m_ptr;
};

template <typename T>
UnretainedWrapper<T, SameThreadAffinity> unretained(T* value)
{
    static_assert(!WTF::IsGarbageCollectedType<T>::value, "WTF::unretained() + GCed type is forbidden");
    return UnretainedWrapper<T, SameThreadAffinity>(value);
}

template <typename T>
UnretainedWrapper<T, CrossThreadAffinity> crossThreadUnretained(T* value)
{
    static_assert(!WTF::IsGarbageCollectedType<T>::value, "crossThreadUnretained() + GCed type is forbidden");
    return UnretainedWrapper<T, CrossThreadAffinity>(value);
}

template <typename T>
struct ParamStorageTraits {
    typedef T StorageType;

    static_assert(!std::is_pointer<T>::value,
        "Raw pointers are not allowed to bind into WTF::Function. Wrap "
        "it with either wrapPersistent, wrapWeakPersistent, "
        "wrapCrossThreadPersistent, wrapCrossThreadWeakPersistent, "
        "RefPtr or unretained.");
    static_assert(!IsSubclassOfTemplate<T, blink::Member>::value && !IsSubclassOfTemplate<T, blink::WeakMember>::value,
        "Member and WeakMember are not allowed to bind into "
        "WTF::Function. Wrap it with either wrapPersistent, "
        "wrapWeakPersistent, wrapCrossThreadPersistent or "
        "wrapCrossThreadWeakPersistent.");
};

template <typename T>
struct ParamStorageTraits<PassRefPtr<T>> {
    typedef RefPtr<T> StorageType;
};

template <typename T>
struct ParamStorageTraits<RefPtr<T>> {
    typedef RefPtr<T> StorageType;
};

template <typename>
class RetainPtr;

template <typename T>
struct ParamStorageTraits<RetainPtr<T>> {
    typedef RetainPtr<T> StorageType;
};

template <typename T>
struct ParamStorageTraits<PassedWrapper<T>> {
    typedef PassedWrapper<T> StorageType;
};

template <typename T, FunctionThreadAffinity threadAffinity>
struct ParamStorageTraits<UnretainedWrapper<T, threadAffinity>> {
    typedef UnretainedWrapper<T, threadAffinity> StorageType;
};

template <typename Signature, FunctionThreadAffinity threadAffinity = SameThreadAffinity>
class Function;

template <typename R, typename... Args, FunctionThreadAffinity threadAffinity>
class Function<R(Args...), threadAffinity> {
    USING_FAST_MALLOC(Function);
    WTF_MAKE_NONCOPYABLE(Function);

public:
    Function(base::Callback<R(Args...)> callback)
        : m_callback(std::move(callback))
    {
    }

    ~Function() { DCHECK(m_threadChecker.CalledOnValidThread()); }

    R operator()(Args... args)
    {
        DCHECK(m_threadChecker.CalledOnValidThread());
        return m_callback.Run(std::forward<Args>(args)...);
    }

    bool isCancelled() const { return m_callback.IsCancelled(); }

    friend base::Callback<R(Args...)> convertToBaseCallback(std::unique_ptr<Function> function)
    {
        if (function)
            return std::move(function->m_callback);
        return base::Callback<R(Args...)>();
    }

private:
    using MaybeThreadChecker =
        typename std::conditional<threadAffinity == SameThreadAffinity,
            base::ThreadChecker,
            base::ThreadCheckerDoNothing>::type;
    MaybeThreadChecker m_threadChecker;
    base::Callback<R(Args...)> m_callback;
};

template <FunctionThreadAffinity threadAffinity, typename FunctionType, typename... BoundParameters>
std::unique_ptr<Function<base::MakeUnboundRunType<FunctionType, BoundParameters...>, threadAffinity> >
bindInternal(FunctionType function, BoundParameters&&... boundParameters)
{
    using UnboundRunType = base::MakeUnboundRunType<FunctionType, BoundParameters...>;
    return WTF::wrapUnique(new Function<UnboundRunType, threadAffinity>(
        base::Bind(function, typename ParamStorageTraits<typename std::decay<BoundParameters>::type>::StorageType(std::forward<BoundParameters>(boundParameters))...)));
}

template <typename FunctionType, typename... BoundParameters>
std::unique_ptr<Function<base::MakeUnboundRunType<FunctionType, BoundParameters...>, SameThreadAffinity>>
bind(FunctionType function, BoundParameters&&... boundParameters)
{
    return bindInternal<SameThreadAffinity>(function, std::forward<BoundParameters>(boundParameters)...);
}

typedef Function<void(), SameThreadAffinity> Closure;
typedef Function<void(), CrossThreadAffinity> CrossThreadClosure;

} // namespace WTF

namespace base {

template <typename T>
struct BindUnwrapTraits<WTF::RefPtr<T>> {
    static T* Unwrap(const WTF::RefPtr<T>& wrapped) { return wrapped.get(); }
};

template <typename T>
struct BindUnwrapTraits<WTF::PassedWrapper<T>> {
    static T Unwrap(const WTF::PassedWrapper<T>& wrapped)
    {
        return wrapped.moveOut();
    }
};

template <typename T, WTF::FunctionThreadAffinity threadAffinity>
struct BindUnwrapTraits<WTF::UnretainedWrapper<T, threadAffinity>> {
    static T* Unwrap(const WTF::UnretainedWrapper<T, threadAffinity>& wrapped)
    {
        return wrapped.value();
    }
};

} // namespace base

using WTF::crossThreadUnretained;

using WTF::CrossThreadClosure;
using WTF::Function;
=======
#include "wtf/Assertions.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"
#include "wtf/ThreadSafeRefCounted.h"
#include "wtf/WeakPtr.h"

namespace WTF {

// Functional.h provides a very simple way to bind a function pointer and arguments together into a function object
// that can be stored, copied and invoked, similar to how boost::bind and std::bind in C++11.

// Use threadSafeBind() or createCrossThreadTask() if the function/task is
// called on a (potentially) different thread from the current thread.

// A FunctionWrapper is a class template that can wrap a function pointer or a member function pointer and
// provide a unified interface for calling that function.
template<typename>
class FunctionWrapper;

// Bound static functions:
template<typename R, typename... Params>
class FunctionWrapper<R(*)(Params...)> {
public:
    typedef R ResultType;

    explicit FunctionWrapper(R(*function)(Params...))
        : m_function(function)
    {
    }

    R operator()(Params... params)
    {
        return m_function(params...);
    }

private:
    R(*m_function)(Params...);
};

// Bound member functions:

template<typename R, typename C, typename... Params>
class FunctionWrapper<R(C::*)(Params...)> {
public:
    typedef R ResultType;

    explicit FunctionWrapper(R(C::*function)(Params...))
        : m_function(function)
    {
    }

    R operator()(C* c, Params... params)
    {
        return (c->*m_function)(params...);
    }

    R operator()(PassOwnPtr<C> c, Params... params)
    {
        return (c.get()->*m_function)(params...);
    }

    R operator()(const WeakPtr<C>& c, Params... params)
    {
        C* obj = c.get();
        if (!obj)
            return R();
        return (obj->*m_function)(params...);
    }

private:
    R(C::*m_function)(Params...);
};

template<typename T> struct ParamStorageTraits {
    typedef T StorageType;

    static StorageType wrap(const T& value) { return value; }
    static const T& unwrap(const StorageType& value) { return value; }
};

template<typename T> struct ParamStorageTraits<PassRefPtr<T>> {
    typedef RefPtr<T> StorageType;

    static StorageType wrap(PassRefPtr<T> value) { return value; }
    static T* unwrap(const StorageType& value) { return value.get(); }
};

template<typename T> struct ParamStorageTraits<RefPtr<T>> {
    typedef RefPtr<T> StorageType;

    static StorageType wrap(RefPtr<T> value) { return value.release(); }
    static T* unwrap(const StorageType& value) { return value.get(); }
};

template<typename> class RetainPtr;

template<typename T> struct ParamStorageTraits<RetainPtr<T>> {
    typedef RetainPtr<T> StorageType;

    static StorageType wrap(const RetainPtr<T>& value) { return value; }
    static typename RetainPtr<T>::PtrType unwrap(const StorageType& value) { return value.get(); }
};

template<typename>
class Function;

template<typename R, typename... Args>
class Function<R(Args...)> {
    WTF_MAKE_NONCOPYABLE(Function);
public:
    virtual ~Function() { }
    virtual R operator()(Args... args) = 0;
protected:
    Function() = default;
};

template<int boundArgsCount, typename FunctionWrapper, typename FunctionType>
class PartBoundFunctionImpl;

// Specialization for unbound functions.
template<typename FunctionWrapper, typename R, typename... UnboundParams>
class PartBoundFunctionImpl<0, FunctionWrapper, R(UnboundParams...)> final : public Function<typename FunctionWrapper::ResultType(UnboundParams...)> {
public:
    PartBoundFunctionImpl(FunctionWrapper functionWrapper)
        : m_functionWrapper(functionWrapper)
    {
    }

    typename FunctionWrapper::ResultType operator()(UnboundParams... params) override
    {
        return m_functionWrapper(params...);
    }

private:
    FunctionWrapper m_functionWrapper;
};

template<typename FunctionWrapper, typename R, typename P1, typename... UnboundParams>
class PartBoundFunctionImpl<1, FunctionWrapper, R(P1, UnboundParams...)> final : public Function<typename FunctionWrapper::ResultType(UnboundParams...)> {
public:
    PartBoundFunctionImpl(FunctionWrapper functionWrapper, const P1& p1)
        : m_functionWrapper(functionWrapper)
        , m_p1(ParamStorageTraits<P1>::wrap(p1))
    {
    }

    typename FunctionWrapper::ResultType operator()(UnboundParams... params) override
    {
        return m_functionWrapper(ParamStorageTraits<P1>::unwrap(m_p1), params...);
    }

private:
    FunctionWrapper m_functionWrapper;
    typename ParamStorageTraits<P1>::StorageType m_p1;
};

template<typename FunctionWrapper, typename R, typename P1, typename P2, typename... UnboundParams>
class PartBoundFunctionImpl<2, FunctionWrapper, R(P1, P2, UnboundParams...)> final : public Function<typename FunctionWrapper::ResultType(UnboundParams...)> {
public:
    PartBoundFunctionImpl(FunctionWrapper functionWrapper, const P1& p1, const P2& p2)
        : m_functionWrapper(functionWrapper)
        , m_p1(ParamStorageTraits<P1>::wrap(p1))
        , m_p2(ParamStorageTraits<P2>::wrap(p2))
    {
    }

    typename FunctionWrapper::ResultType operator()(UnboundParams... params) override
    {
        return m_functionWrapper(ParamStorageTraits<P1>::unwrap(m_p1), ParamStorageTraits<P2>::unwrap(m_p2), params...);
    }

private:
    FunctionWrapper m_functionWrapper;
    typename ParamStorageTraits<P1>::StorageType m_p1;
    typename ParamStorageTraits<P2>::StorageType m_p2;
};

template<typename FunctionWrapper, typename R, typename P1, typename P2, typename P3, typename... UnboundParams>
class PartBoundFunctionImpl<3, FunctionWrapper, R(P1, P2, P3, UnboundParams...)> final : public Function<typename FunctionWrapper::ResultType(UnboundParams...)> {
public:
    PartBoundFunctionImpl(FunctionWrapper functionWrapper, const P1& p1, const P2& p2, const P3& p3)
        : m_functionWrapper(functionWrapper)
        , m_p1(ParamStorageTraits<P1>::wrap(p1))
        , m_p2(ParamStorageTraits<P2>::wrap(p2))
        , m_p3(ParamStorageTraits<P3>::wrap(p3))
    {
    }

    typename FunctionWrapper::ResultType operator()(UnboundParams... params) override
    {
        return m_functionWrapper(ParamStorageTraits<P1>::unwrap(m_p1), ParamStorageTraits<P2>::unwrap(m_p2), ParamStorageTraits<P3>::unwrap(m_p3), params...);
    }

private:
    FunctionWrapper m_functionWrapper;
    typename ParamStorageTraits<P1>::StorageType m_p1;
    typename ParamStorageTraits<P2>::StorageType m_p2;
    typename ParamStorageTraits<P3>::StorageType m_p3;
};

template<typename FunctionWrapper, typename R, typename P1, typename P2, typename P3, typename P4, typename... UnboundParams>
class PartBoundFunctionImpl<4, FunctionWrapper, R(P1, P2, P3, P4, UnboundParams...)> final : public Function<typename FunctionWrapper::ResultType(UnboundParams...)> {
public:
    PartBoundFunctionImpl(FunctionWrapper functionWrapper, const P1& p1, const P2& p2, const P3& p3, const P4& p4)
        : m_functionWrapper(functionWrapper)
        , m_p1(ParamStorageTraits<P1>::wrap(p1))
        , m_p2(ParamStorageTraits<P2>::wrap(p2))
        , m_p3(ParamStorageTraits<P3>::wrap(p3))
        , m_p4(ParamStorageTraits<P4>::wrap(p4))
    {
    }

    typename FunctionWrapper::ResultType operator()(UnboundParams... params) override
    {
        return m_functionWrapper(ParamStorageTraits<P1>::unwrap(m_p1), ParamStorageTraits<P2>::unwrap(m_p2), ParamStorageTraits<P3>::unwrap(m_p3), ParamStorageTraits<P4>::unwrap(m_p4), params...);
    }

private:
    FunctionWrapper m_functionWrapper;
    typename ParamStorageTraits<P1>::StorageType m_p1;
    typename ParamStorageTraits<P2>::StorageType m_p2;
    typename ParamStorageTraits<P3>::StorageType m_p3;
    typename ParamStorageTraits<P4>::StorageType m_p4;
};

template<typename FunctionWrapper, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename... UnboundParams>
class PartBoundFunctionImpl<5, FunctionWrapper, R(P1, P2, P3, P4, P5, UnboundParams...)> final : public Function<typename FunctionWrapper::ResultType(UnboundParams...)> {
public:
    PartBoundFunctionImpl(FunctionWrapper functionWrapper, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5)
        : m_functionWrapper(functionWrapper)
        , m_p1(ParamStorageTraits<P1>::wrap(p1))
        , m_p2(ParamStorageTraits<P2>::wrap(p2))
        , m_p3(ParamStorageTraits<P3>::wrap(p3))
        , m_p4(ParamStorageTraits<P4>::wrap(p4))
        , m_p5(ParamStorageTraits<P5>::wrap(p5))
    {
    }

    typename FunctionWrapper::ResultType operator()(UnboundParams... params) override
    {
        return m_functionWrapper(ParamStorageTraits<P1>::unwrap(m_p1), ParamStorageTraits<P2>::unwrap(m_p2), ParamStorageTraits<P3>::unwrap(m_p3), ParamStorageTraits<P4>::unwrap(m_p4), ParamStorageTraits<P5>::unwrap(m_p5), params...);
    }

private:
    FunctionWrapper m_functionWrapper;
    typename ParamStorageTraits<P1>::StorageType m_p1;
    typename ParamStorageTraits<P2>::StorageType m_p2;
    typename ParamStorageTraits<P3>::StorageType m_p3;
    typename ParamStorageTraits<P4>::StorageType m_p4;
    typename ParamStorageTraits<P5>::StorageType m_p5;
};

template<typename FunctionWrapper, typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename... UnboundParams>
class PartBoundFunctionImpl<6, FunctionWrapper, R(P1, P2, P3, P4, P5, P6, UnboundParams...)> final : public Function<typename FunctionWrapper::ResultType(UnboundParams...)> {
public:
    PartBoundFunctionImpl(FunctionWrapper functionWrapper, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6)
        : m_functionWrapper(functionWrapper)
        , m_p1(ParamStorageTraits<P1>::wrap(p1))
        , m_p2(ParamStorageTraits<P2>::wrap(p2))
        , m_p3(ParamStorageTraits<P3>::wrap(p3))
        , m_p4(ParamStorageTraits<P4>::wrap(p4))
        , m_p5(ParamStorageTraits<P5>::wrap(p5))
        , m_p6(ParamStorageTraits<P6>::wrap(p6))
    {
    }

    typename FunctionWrapper::ResultType operator()(UnboundParams... params) override
    {
        return m_functionWrapper(ParamStorageTraits<P1>::unwrap(m_p1), ParamStorageTraits<P2>::unwrap(m_p2), ParamStorageTraits<P3>::unwrap(m_p3), ParamStorageTraits<P4>::unwrap(m_p4), ParamStorageTraits<P5>::unwrap(m_p5), ParamStorageTraits<P6>::unwrap(m_p6), params...);
    }

private:
    FunctionWrapper m_functionWrapper;
    typename ParamStorageTraits<P1>::StorageType m_p1;
    typename ParamStorageTraits<P2>::StorageType m_p2;
    typename ParamStorageTraits<P3>::StorageType m_p3;
    typename ParamStorageTraits<P4>::StorageType m_p4;
    typename ParamStorageTraits<P5>::StorageType m_p5;
    typename ParamStorageTraits<P6>::StorageType m_p6;
};

template<typename... UnboundArgs, typename FunctionType, typename... BoundArgs>
PassOwnPtr<Function<typename FunctionWrapper<FunctionType>::ResultType(UnboundArgs...)>> bind(FunctionType function, const BoundArgs&... boundArgs)
{
    const int boundArgsCount = sizeof...(BoundArgs);
    using BoundFunctionType = PartBoundFunctionImpl<boundArgsCount, FunctionWrapper<FunctionType>, typename FunctionWrapper<FunctionType>::ResultType(BoundArgs..., UnboundArgs...)>;
    return adoptPtr(new BoundFunctionType(FunctionWrapper<FunctionType>(function), boundArgs...));
}

typedef Function<void()> Closure;

}

using WTF::Function;
using WTF::bind;
using WTF::Closure;
>>>>>>> miniblink49

#endif // WTF_Functional_h

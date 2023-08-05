// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/barrier_closure.h"

#include "base/atomic_ref_count.h"
#include "base/bind.h"
#include "base/atomic_mb.h"

namespace {

// Maintains state for a BarrierClosure.
class BarrierInfo {
public:
    BarrierInfo(int num_callbacks_left, const base::Closure& done_closure);
    void Run();

private:
    base::AtomicRefCount num_callbacks_left_;
    base::Closure done_closure_;
};

BarrierInfo::BarrierInfo(int num_callbacks, const base::Closure& done_closure)
    : num_callbacks_left_(num_callbacks)
    , done_closure_(done_closure)
{
}

void BarrierInfo::Run()
{
    DCHECK(!base::AtomicRefCountIsZero(&num_callbacks_left_));
    if (!base::AtomicRefCountDec(&num_callbacks_left_)) {
        base::Closure done_closure = done_closure_;
        done_closure_.Reset();
        done_closure.Run();
    }
}

} // namespace

namespace base {

base::Closure BarrierClosure(int num_callbacks_left,
    const base::Closure& done_closure)
{
    DCHECK_GE(num_callbacks_left, 0);

    if (num_callbacks_left == 0)
        done_closure.Run();

    return base::Bind(&BarrierInfo::Run,
        base::Owned(
            new BarrierInfo(num_callbacks_left, done_closure)));
}

} // namespace base

#if 0//!defined(WIN32)
long MB_InterlockedIncrement(long volatile* _Target)
{
    return _InterlockedIncrement((int volatile*) _Target);
}

long MB_InterlockedExchange(long volatile* _Target, long _Value)
{
    return _InterlockedExchange((int volatile*)_Target, _Value);
}

long MB_InterlockedExchangeAdd(long volatile* _Addend, long _Value)
{
    return _InterlockedExchangeAdd((int volatile*)_Addend, _Value);
}

long MB_InterlockedDecrement(long volatile* _Target)
{
    return _InterlockedDecrement((int volatile*)_Target);
}

long MB_InterlockedCompareExchange(long volatile* _Destination, long _Exchange, long _Comparand)
{
    return _InterlockedCompareExchange((int volatile*)_Destination, _Exchange, _Comparand);
}
#else
long MB_InterlockedIncrement(long volatile* _Target)
{
    return _InterlockedIncrement((long volatile*)_Target);
}

long MB_InterlockedExchange(long volatile* _Target, long _Value)
{
    return _InterlockedExchange((long volatile*)_Target, _Value);
}

long MB_InterlockedExchangeAdd(long volatile* _Addend, long _Value)
{
    return _InterlockedExchangeAdd((long volatile*)_Addend, _Value);
}

long MB_InterlockedDecrement(long volatile* _Target)
{
    return _InterlockedDecrement((long volatile*)_Target);
}

long MB_InterlockedCompareExchange(long volatile* _Destination, long _Exchange, long _Comparand)
{
    return _InterlockedCompareExchange((long volatile*)_Destination, _Exchange, _Comparand);
}
#endif


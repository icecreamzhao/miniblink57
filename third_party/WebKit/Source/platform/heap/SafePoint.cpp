// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "platform/heap/SafePoint.h"

#include "platform/heap/Heap.h"
#include "wtf/Atomics.h"
#include "wtf/CurrentTime.h"

namespace blink {

using PushAllRegistersCallback = void (*)(SafePointBarrier*,
    ThreadState*,
    intptr_t*);
extern "C" void pushAllRegisters(SafePointBarrier*,
    ThreadState*,
    PushAllRegistersCallback);

static double lockingTimeout()
{
    // Wait time for parking all threads is at most 100 ms.
    return 0.100;
}

SafePointBarrier::SafePointBarrier()
    : m_unparkedThreadCount(0)
    , m_parkingRequested(0)
{
}

SafePointBarrier::~SafePointBarrier() { }

bool SafePointBarrier::parkOthers()
{
    ASSERT(ThreadState::current()->isAtSafePoint());

    ThreadState* current = ThreadState::current();
    // Lock threadAttachMutex() to prevent threads from attaching.
    current->lockThreadAttachMutex();
    const ThreadStateSet& threads = current->heap().threads();

    MutexLocker locker(m_mutex);
    atomicAdd(&m_unparkedThreadCount, threads.size());
    releaseStore(&m_parkingRequested, 1);

    for (ThreadState* state : threads) {
        if (state == current)
            continue;

        for (auto& interruptor : state->interruptors())
            interruptor->requestInterrupt();
    }

    while (acquireLoad(&m_unparkedThreadCount) > 0) {
        double expirationTime = currentTime() + lockingTimeout();
        if (!m_parked.timedWait(m_mutex, expirationTime)) {
            // One of the other threads did not return to a safepoint within the
            // maximum time we allow for threads to be parked. Abandon the GC and
            // resume the currently parked threads.
            resumeOthers(true);
            return false;
        }
    }
    return true;
}

void SafePointBarrier::resumeOthers(bool barrierLocked)
{
    ThreadState* current = ThreadState::current();
    const ThreadStateSet& threads = current->heap().threads();
    atomicSubtract(&m_unparkedThreadCount, threads.size());
    releaseStore(&m_parkingRequested, 0);

    if (UNLIKELY(barrierLocked)) {
        m_resume.broadcast();
    } else {
        // FIXME: Resumed threads will all contend for m_mutex just
        // to unlock it later which is a waste of resources.
        MutexLocker locker(m_mutex);
        m_resume.broadcast();
    }

    current->unlockThreadAttachMutex();
    ASSERT(ThreadState::current()->isAtSafePoint());
}

// unsigned char pushAllRegistersShellCodeX64[] = {
//     //;; Push all callee - saves registers to get them
//     //;; on the stack for conservative stack scanning.
//     //;; We maintain 16 - byte alignment at calls(required on Mac).
//     //;; There is an 8 - byte return address on the stack and we push
//     //;; 56 bytes which maintains 16 - byte stack alignment
//     //;; at the call.
//     0x6A, 0x00, // push 0    
//     0x53,       // push rbx 
//     0x55,       // push rbp
//     0x41, 0x54, // push r12
//     0x41, 0x55, // push r13
//     0x41, 0x56, // push r14
//     0x41, 0x57, // push r15
//     //;; Pass the two first arguments unchanged(rdi, rsi)
//     //;; and the stack pointer after pushing callee - saved
//     //;; registers to the callback.
//     0x4C, 0x8B, 0xC2, // mov r8, rdx  
//     0x48, 0x8B, 0xD4, // mov rdx, rsp  
//     0x41, 0xFF, 0xD0, // call r8
//     0x48, 0x83, 0xC4, 0x38, // add rsp, 38h  
//     0xC3, // ret
// };
// 
// using PushAllRegistersFN = void(*)(SafePointBarrier*, ThreadState*, intptr_t*);
// static blink::PushAllRegistersCallback s_cb = nullptr;
// 
// static void initPushAllRegisters()
// {
//     if (!s_cb) {
//         void* pushAllRegistersPtr = (void*)pushAllRegistersShellCodeX64;
//         const size_t length = sizeof(pushAllRegistersShellCodeX64);
//         s_cb = (blink::PushAllRegistersCallback)mmap(0, length, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
//         memcpy((void*)s_cb, pushAllRegistersPtr, length);
//     }
// }

void SafePointBarrier::checkAndPark(ThreadState* state,
    SafePointAwareMutexLocker* locker)
{
    ASSERT(!state->sweepForbidden());
    if (acquireLoad(&m_parkingRequested)) {
        // If we are leaving the safepoint from a SafePointAwareMutexLocker
        // call out to release the lock before going to sleep. This enables the
        // lock to be acquired in the sweep phase, e.g. during weak processing
        // or finalization. The SafePointAwareLocker will reenter the safepoint
        // and reacquire the lock after leaving this safepoint.
        if (locker)
            locker->reset();
        pushAllRegisters(this, state, parkAfterPushRegisters);
//         initPushAllRegisters();
//         s_cb(this, state, (intptr_t*)parkAfterPushRegisters);
    }
}

void SafePointBarrier::enterSafePoint(ThreadState* state)
{
    ASSERT(!state->sweepForbidden());
    pushAllRegisters(this, state, enterSafePointAfterPushRegisters);
//     initPushAllRegisters();
//     s_cb(this, state, (intptr_t*)enterSafePointAfterPushRegisters);
}

void SafePointBarrier::leaveSafePoint(ThreadState* state,
    SafePointAwareMutexLocker* locker)
{
    if (atomicIncrement(&m_unparkedThreadCount) > 0)
        checkAndPark(state, locker);
}

void SafePointBarrier::doPark(ThreadState* state, intptr_t* stackEnd)
{
    state->recordStackEnd(stackEnd);
    MutexLocker locker(m_mutex);
    if (!atomicDecrement(&m_unparkedThreadCount))
        m_parked.signal();
    while (acquireLoad(&m_parkingRequested))
        m_resume.wait(m_mutex);
    atomicIncrement(&m_unparkedThreadCount);
}

void SafePointBarrier::doEnterSafePoint(ThreadState* state,
    intptr_t* stackEnd)
{
    state->recordStackEnd(stackEnd);
    state->copyStackUntilSafePointScope();
    if (!atomicDecrement(&m_unparkedThreadCount)) {
        MutexLocker locker(m_mutex);
        m_parked.signal(); // Safe point reached.
    }
}

} // namespace blink

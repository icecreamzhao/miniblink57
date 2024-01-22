﻿
#ifndef patch_code_sync_xp_h
#define patch_code_sync_xp_h

//#pragma optimize("", off)
//#pragma clang optimize off
#pragma pack(push, 4)
#pragma GCC diagnostic ignored "-Wunused-variable"

#if defined(__i386__) || defined(_M_IX86) || defined(__x86_64__) || defined(_M_X64)

#include <windows.h>
#include <intrin.h>
//#include "undef.h"

#ifdef _WIN64
#define InterlockedBitTestAndSetPointer(ptr,val) InterlockedBitTestAndSet64((PLONGLONG)ptr,(LONGLONG)val)
#define InterlockedAddPointer(ptr,val) InterlockedAdd64((PLONGLONG)ptr,(LONGLONG)val)
#define InterlockedAndPointer(ptr,val) InterlockedAnd64((PLONGLONG)ptr,(LONGLONG)val)
#define InterlockedOrPointer(ptr,val) InterlockedOr64((PLONGLONG)ptr,(LONGLONG)val)
#error "not support x64
#else
#define InterlockedBitTestAndSetPointer(ptr,val) InterlockedBitTestAndSet((PLONG)ptr,(LONG)val)
#define InterlockedAddPointer(ptr,val) InterlockedAdd((PLONG)ptr,(LONG)val)
#define InterlockedAndPointer(ptr,val) InterlockedAnd((PLONG)ptr,(LONG)val)
#define InterlockedOrPointer(ptr,val) InterlockedOr((PLONG)ptr,(LONG)val)
#endif

inline BOOL SleepConditionVariableCSXp(PCONDITION_VARIABLE condVar, PCRITICAL_SECTION criticalSection, DWORD timeout);
inline BOOL SleepConditionVariableSRWXp(PCONDITION_VARIABLE condVar, PSRWLOCK SRWLock, DWORD dwMilliseconds, ULONG Flags);
inline void WakeAllConditionVariableXp(PCONDITION_VARIABLE condVar);
inline void WakeConditionVariableXp(PCONDITION_VARIABLE condVar);
inline void InitializeConditionVariableXp(PCONDITION_VARIABLE condVar);
inline void AcquireSRWLockSharedXp(PRTL_SRWLOCK SRWLock);
inline void InitializeSRWLockXp(PRTL_SRWLOCK SRWLock);
inline void ReleaseSRWLockExclusiveXp(PRTL_SRWLOCK SRWLock);
inline void AcquireSRWLockExclusiveXp(PRTL_SRWLOCK SRWLock);
inline void ReleaseSRWLockSharedXp(PRTL_SRWLOCK SRWLock);
inline BOOL TryAcquireSRWLockExclusiveXp(PSRWLOCK SRWLock);
inline void DeleteConditionVariableXp(PCONDITION_VARIABLE condVar) {}
inline BOOL InitializeCriticalSectionExXp(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags);

inline void CV_ASSERT(BOOL b, const char* debugString)
{
    if (b)
        return;
    OutputDebugStringA(debugString);
    DebugBreak();
}

BOOL InitializeCriticalSectionExXp(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags)
{
    if (0 != dwSpinCount || 0 != Flags)
        DebugBreak();
    InitializeCriticalSection(lpCriticalSection);
    return TRUE;
}

static inline HRESULT runOnceBeginInitialize(INIT_ONCE* once, ULONG flags, void** context)
{
    if (flags & RTL_RUN_ONCE_CHECK_ONLY) {
        ULONG_PTR val = (ULONG_PTR)once->Ptr;

        if (flags & RTL_RUN_ONCE_ASYNC)
            return ((HRESULT)0xC000000DL);// STATUS_INVALID_PARAMETER;
        if ((val & 3) != 2)
            return E_FAIL;
        if (context)
            *context = (void*)(val & (~(ULONG_PTR)3));
        return S_OK;
    }

    for (;;) {
        //ULONG_PTR next = 0;
        ULONG_PTR val = (ULONG_PTR)once->Ptr;

        switch (val & 3) {
        case 0:  /* first time */
            if (0 == InterlockedCompareExchange((long*)&once->Ptr, ((flags & RTL_RUN_ONCE_ASYNC) ? 3 : 1), 0))
                return ((HRESULT)0x00000103L); // STATUS_PENDING;
            break;

        case 1:  /* in progress, wait */
            if (flags & RTL_RUN_ONCE_ASYNC)
                return ((HRESULT)0xC000000DL); // STATUS_INVALID_PARAMETER;
            //             next = val & ~3; // low 2 bit to 0, get ptr
            //             if (InterlockedCompareExchange((long  *)&once->Ptr, ((ULONG_PTR)&next | 1), val) == (long)val) {
            //                 CV_ASSERT(FALSE, "runOnceBegin~Initialize fail\n");
            //                 NtWaitForKeyedEvent(keyed_event, &next, FALSE, NULL);
            //             }
                        //OutputDebugStringA("wait\n");
            Sleep(10);
            break;
        case 2:  /* done */
            if (context)
                *context = (void*)(val & (~(ULONG_PTR)3));
            return S_OK;

        case 3:  /* in progress, async */
            if (!(flags & RTL_RUN_ONCE_ASYNC))
                return ((HRESULT)0xC000000DL); //  STATUS_INVALID_PARAMETER;
            return ((HRESULT)0x00000103L); // STATUS_PENDING;
        }
    }
}

static inline HRESULT runOnceComplete(INIT_ONCE* once, ULONG flags, void* context)
{
    if ((ULONG_PTR)context & 3)
        return ((HRESULT)0xC000000DL); //  STATUS_INVALID_PARAMETER;

    if (flags & RTL_RUN_ONCE_INIT_FAILED) {
        if (context)
            return ((HRESULT)0xC000000DL); //  STATUS_INVALID_PARAMETER;
        if (flags & RTL_RUN_ONCE_ASYNC)
            return ((HRESULT)0xC000000DL); //  STATUS_INVALID_PARAMETER;
    } else
        context = (void*)((ULONG_PTR)context | 2);

    for (;;) {
        ULONG_PTR val = (ULONG_PTR)once->Ptr;

        switch (val & 3) { // get low 2 bit
        case 1:  /* in progress */
            if (InterlockedCompareExchange((long*)&once->Ptr, (long)context, (long)val) != (long)val)
                break;

            //             val &= ~3;// low 2 bit to 0, get ptr
            //             while (val) {
            //                 ULONG_PTR next = *(ULONG_PTR *)val;
            //                 NtReleaseKeyedEvent(keyed_event, (void *)val, FALSE, NULL);
            //                 CV_ASSERT(FALSE, "runOnceComplete fail\n");
            //                 val = next;
            //             }
                        //OutputDebugStringA("in progress\n");
            return S_OK;

        case 3:  /* in progress, async */
            if (!(flags & RTL_RUN_ONCE_ASYNC))
                return ((HRESULT)0xC000000DL); //  STATUS_INVALID_PARAMETER;
            if (InterlockedCompareExchange((long*)&once->Ptr, (long)context, (long)val) != (long)val)
                break;
            return S_OK;

        default:
            return E_FAIL;
        }
    }
}

static inline HRESULT runOnceExecuteOnce(INIT_ONCE* once, PINIT_ONCE_FN func, void* param, void** context)
{
    HRESULT ret = runOnceBeginInitialize(once, 0, context);

    if (ret != ((HRESULT)0x00000103L)) // STATUS_PENDING
        return ret;

    if (!func(once, param, context)) {
        runOnceComplete(once, RTL_RUN_ONCE_INIT_FAILED, NULL);
        return E_FAIL;
    }

    return runOnceComplete(once, 0, context ? *context : NULL);
}

inline BOOL InitOnceExecuteOnceXp(INIT_ONCE* once, PINIT_ONCE_FN func, void* param, void** context)
{
    return 0 == runOnceExecuteOnce(once, func, param, context);
}

inline BOOL InitOnceBeginInitializeXp(LPINIT_ONCE lpInitOnce, DWORD dwFlags, PBOOL fPending, LPVOID* lpContext)
{
    HRESULT hr = S_OK;
    BOOL result = FALSE;

    hr = runOnceBeginInitialize(lpInitOnce, dwFlags, lpContext);
    if (hr >= 0) {
        *fPending = (hr == ((HRESULT)0x00000103L)); // STATUS_PENDING
        result = TRUE;
    } else {
        SetLastError((DWORD)hr);
        result = FALSE;
    }
    return result;
}

inline BOOL InitOnceCompleteXp(LPINIT_ONCE lpInitOnce, DWORD dwFlags, LPVOID lpContext)
{
    long hr = S_OK;
    BOOL result = FALSE;

    hr = runOnceComplete(lpInitOnce, dwFlags, lpContext);
    if (hr >= 0) {
        result = TRUE;
    } else {
        SetLastError((DWORD)hr);
        result = FALSE;
    }
    return result;
}

#define XP_SRWLOCK_OWNED_BIT   0
#define XP_SRWLOCK_CONTENDED_BIT   1
#define XP_SRWLOCK_SHARED_BIT  2
#define XP_SRWLOCK_CONTENTION_LOCK_BIT 3
#define XP_SRWLOCK_OWNED   (1 << XP_SRWLOCK_OWNED_BIT)
#define XP_SRWLOCK_CONTENDED   (1 << XP_SRWLOCK_CONTENDED_BIT)
#define XP_SRWLOCK_SHARED  (1 << XP_SRWLOCK_SHARED_BIT)
#define XP_SRWLOCK_CONTENTION_LOCK (1 << XP_SRWLOCK_CONTENTION_LOCK_BIT)
#define XP_SRWLOCK_MASK    (XP_SRWLOCK_OWNED | XP_SRWLOCK_CONTENDED | \
                             XP_SRWLOCK_SHARED | XP_SRWLOCK_CONTENTION_LOCK)
#define XP_SRWLOCK_BITS    4

typedef struct _XP_SRWLOCK_SHARED_WAKE {
    LONG Wake;
    struct _XP_SRWLOCK_SHARED_WAKE* Next;
}  XP_SRWLOCK_SHARED_WAKE, * PXP_SRWLOCK_SHARED_WAKE;

typedef struct _XP_SRWLOCK_WAITBLOCK {
    /* SharedCount is the number of shared acquirers. */
    LONG SharedCount;

    /* Last points to the last wait block in the chain. The value
    is only valid when read from the first wait block. */
    struct _XP_SRWLOCK_WAITBLOCK* Last;

    /* Next points to the next wait block in the chain. */
    struct _XP_SRWLOCK_WAITBLOCK* Next;

    union {
        /* Wake is only valid for exclusive wait blocks */
        LONG Wake;
        /* The wake chain is only valid for shared wait blocks */
        struct {
            PXP_SRWLOCK_SHARED_WAKE SharedWakeChain;
            PXP_SRWLOCK_SHARED_WAKE LastSharedWake;
        };
    };

    BOOLEAN Exclusive;
}  XP_SRWLOCK_WAITBLOCK, * PXP_SRWLOCK_WAITBLOCK;

static void releaseWaitBlockLockExclusiveImpl(PRTL_SRWLOCK SRWLock, PXP_SRWLOCK_WAITBLOCK FirstWaitBlock)
{
    PXP_SRWLOCK_WAITBLOCK Next;
    LONG_PTR NewValue;

    /* NOTE: We're currently in an exclusive lock in contended mode. */
    Next = FirstWaitBlock->Next;
    if (Next != NULL) {
        /* There's more blocks chained, we need to update the pointers
        in the next wait block and update the wait block pointer. */
        NewValue = (LONG_PTR)Next | XP_SRWLOCK_OWNED | XP_SRWLOCK_CONTENDED;
        if (!FirstWaitBlock->Exclusive) {
            /* The next wait block has to be an exclusive lock! */
            CV_ASSERT(!!(Next->Exclusive), "releaseWaitBlockLockExclusiveImpl 1\n");

            /* Save the shared count */
            Next->SharedCount = FirstWaitBlock->SharedCount;

            NewValue |= XP_SRWLOCK_SHARED;
        }

        Next->Last = FirstWaitBlock->Last;
    } else {
        /* Convert the lock to a simple lock. */
        if (FirstWaitBlock->Exclusive)
            NewValue = XP_SRWLOCK_OWNED;
        else {
            CV_ASSERT(FirstWaitBlock->SharedCount > 0, "releaseWaitBlockLockExclusiveImpl 2\n");

            NewValue = ((LONG_PTR)FirstWaitBlock->SharedCount << XP_SRWLOCK_BITS) | XP_SRWLOCK_SHARED | XP_SRWLOCK_OWNED;
        }
    }

    (void)InterlockedExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue);

    if (FirstWaitBlock->Exclusive) {
        (void)_InterlockedOr(&FirstWaitBlock->Wake, TRUE);
    } else {
        PXP_SRWLOCK_SHARED_WAKE WakeChain, NextWake;

        /* If we were the first one to acquire the shared
        lock, we now need to wake all others... */
        WakeChain = FirstWaitBlock->SharedWakeChain;
        do {
            NextWake = WakeChain->Next;

            (void)_InterlockedOr((PLONG)&WakeChain->Wake, TRUE);

            WakeChain = NextWake;
        } while (WakeChain != NULL);
    }
}

static inline void releaseWaitBlockLockLastSharedImpl(PRTL_SRWLOCK SRWLock, PXP_SRWLOCK_WAITBLOCK FirstWaitBlock)
{
    PXP_SRWLOCK_WAITBLOCK Next;
    LONG_PTR NewValue;

    /* NOTE: We're currently in a shared lock in contended mode. */

    /* The next acquirer to be unwaited *must* be an exclusive lock! */
    CV_ASSERT(!!(FirstWaitBlock->Exclusive), "releaseWaitBlockLockLastSharedImpl fail 1\n");

    Next = FirstWaitBlock->Next;
    if (Next != NULL) {
        /* There's more blocks chained, we need to update the pointers
        in the next wait block and update the wait block pointer. */
        NewValue = (LONG_PTR)Next | XP_SRWLOCK_OWNED | XP_SRWLOCK_CONTENDED;

        Next->Last = FirstWaitBlock->Last;
    } else {
        /* Convert the lock to a simple exclusive lock. */
        NewValue = XP_SRWLOCK_OWNED;
    }

    (void)InterlockedExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue);

    (void)_InterlockedOr(&FirstWaitBlock->Wake, TRUE);
}

static inline void releaseWaitBlockLockImpl(PRTL_SRWLOCK SRWLock)
{
    _InterlockedAnd((long*)&SRWLock->Ptr, ~XP_SRWLOCK_CONTENTION_LOCK);
}

static inline PXP_SRWLOCK_WAITBLOCK acquireWaitBlockLockImpl(PRTL_SRWLOCK SRWLock)
{
    LONG_PTR PrevValue;
    PXP_SRWLOCK_WAITBLOCK WaitBlock;

    while (1) {
        PrevValue = _InterlockedOr((long*)&SRWLock->Ptr, XP_SRWLOCK_CONTENTION_LOCK);

        if (!(PrevValue & XP_SRWLOCK_CONTENTION_LOCK))
            break;

        YieldProcessor();
    }

    if (!(PrevValue & XP_SRWLOCK_CONTENDED) || (PrevValue & ~XP_SRWLOCK_MASK) == 0) {
        /* Too bad, looks like the wait block was removed in the
        meanwhile, unlock again */
        releaseWaitBlockLockImpl(SRWLock);
        return NULL;
    }

    WaitBlock = (PXP_SRWLOCK_WAITBLOCK)(PrevValue & ~XP_SRWLOCK_MASK);

    return WaitBlock;
}

static inline void acquireSRWLockExclusiveWaitImpl(PRTL_SRWLOCK SRWLock, PXP_SRWLOCK_WAITBLOCK WaitBlock)
{
    LONG_PTR CurrentValue;

    while (1) {
        CurrentValue = *(LONG_PTR*)&SRWLock->Ptr;
        if (!(CurrentValue & XP_SRWLOCK_SHARED)) {
            if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                if (WaitBlock->Wake != 0) {
                    /* Our wait block became the first one
                    in the chain, we own the lock now! */
                    break;
                }
            } else {
                /* The last wait block was removed and/or we're
                finally a simple exclusive lock. This means we
                don't need to wait anymore, we acquired the lock! */
                break;
            }
        }

        YieldProcessor();
    }
}

static inline void acquireSRWLockSharedWaitImpl(PRTL_SRWLOCK SRWLock, PXP_SRWLOCK_WAITBLOCK FirstWait, PXP_SRWLOCK_SHARED_WAKE WakeChain)
{
    if (FirstWait != NULL) {
        while (WakeChain->Wake == 0) {
            YieldProcessor();
        }
    } else {
        LONG_PTR CurrentValue;

        while (1) {
            CurrentValue = *(LONG_PTR*)&SRWLock->Ptr;
            if (CurrentValue & XP_SRWLOCK_SHARED) {
                /* The XP_SRWLOCK_OWNED bit always needs to be set when
                XP_SRWLOCK_SHARED is set! */
                CV_ASSERT(CurrentValue & XP_SRWLOCK_OWNED, "acquireSRWLockSharedWaitImpl fail 1\n");

                if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                    if (WakeChain->Wake != 0) {
                        /* Our wait block became the first one
                        in the chain, we own the lock now! */
                        break;
                    }
                } else {
                    /* The last wait block was removed and/or we're
                    finally a simple shared lock. This means we
                    don't need to wait anymore, we acquired the lock! */
                    break;
                }
            }

            YieldProcessor();
        }
    }
}

static inline void acquireSRWLockShared(PRTL_SRWLOCK SRWLock)
{
    __declspec(align(16)) XP_SRWLOCK_WAITBLOCK StackWaitBlock;
    XP_SRWLOCK_SHARED_WAKE SharedWake;
    ULONG_PTR CurrentValue;
    ULONG_PTR NewValue;
    PXP_SRWLOCK_WAITBLOCK First, Shared, FirstWait;

    unsigned int addr = (unsigned int)(&StackWaitBlock);
    CV_ASSERT((addr & 0xf) == 0, "acquireSRWLockShared StackWaitBlock is not align\n");

    while (1) {
        CurrentValue = *(ULONG_PTR*)&SRWLock->Ptr;

        if (CurrentValue & XP_SRWLOCK_SHARED) {
            /* NOTE: It is possible that the XP_SRWLOCK_OWNED bit is set! */

            if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                /* There's other waiters already, lock the wait blocks and
                increment the shared count */
                First = acquireWaitBlockLockImpl(SRWLock);
                if (First != NULL) {
                    FirstWait = NULL;

                    if (First->Exclusive) {
                        /* We need to setup a new wait block! Although
                        we're currently in a shared lock and we're acquiring
                        a shared lock, there are exclusive locks queued. We need
                        to wait until those are released. */
                        Shared = First->Last;

                        if (Shared->Exclusive) {
                            StackWaitBlock.Exclusive = FALSE;
                            StackWaitBlock.SharedCount = 1;
                            StackWaitBlock.Next = NULL;
                            StackWaitBlock.Last = &StackWaitBlock;
                            StackWaitBlock.SharedWakeChain = &SharedWake;

                            Shared->Next = &StackWaitBlock;
                            First->Last = &StackWaitBlock;

                            Shared = &StackWaitBlock;
                            FirstWait = &StackWaitBlock;
                        } else {
                            Shared->LastSharedWake->Next = &SharedWake;
                            Shared->SharedCount++;
                        }
                    } else {
                        Shared = First;
                        Shared->LastSharedWake->Next = &SharedWake;
                        Shared->SharedCount++;
                    }

                    SharedWake.Next = NULL;
                    SharedWake.Wake = 0;

                    Shared->LastSharedWake = &SharedWake;

                    releaseWaitBlockLockImpl(SRWLock);

                    acquireSRWLockSharedWaitImpl(SRWLock, FirstWait, &SharedWake);

                    /* Successfully incremented the shared count, we acquired the lock */
                    break;
                }
            } else {
                /* This is a fastest path, just increment the number of
                current shared locks */

                /* Since the XP_SRWLOCK_SHARED bit is set, the XP_SRWLOCK_OWNED bit also has
                to be set! */

                CV_ASSERT(CurrentValue & XP_SRWLOCK_OWNED, "acquireSRWLockShared fail 1\n");

                NewValue = (CurrentValue >> XP_SRWLOCK_BITS) + 1;
                NewValue = (NewValue << XP_SRWLOCK_BITS) | (CurrentValue & XP_SRWLOCK_MASK);

                if ((ULONG_PTR)InterlockedCompareExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue, (LONG)CurrentValue) == CurrentValue) {
                    /* Successfully incremented the shared count, we acquired the lock */
                    break;
                }
            }
        } else {
            if (CurrentValue & XP_SRWLOCK_OWNED) {
                /* The resource is currently acquired exclusively */
                if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                    SharedWake.Next = NULL;
                    SharedWake.Wake = 0;

                    /* There's other waiters already, lock the wait blocks and
                    increment the shared count. If the last block in the chain
                    is an exclusive lock, add another block. */

                    StackWaitBlock.Exclusive = FALSE;
                    StackWaitBlock.SharedCount = 0;
                    StackWaitBlock.Next = NULL;
                    StackWaitBlock.Last = &StackWaitBlock;
                    StackWaitBlock.SharedWakeChain = &SharedWake;

                    First = acquireWaitBlockLockImpl(SRWLock);
                    if (First != NULL) {
                        Shared = First->Last;
                        if (Shared->Exclusive) {
                            Shared->Next = &StackWaitBlock;
                            First->Last = &StackWaitBlock;

                            Shared = &StackWaitBlock;
                            FirstWait = &StackWaitBlock;
                        } else {
                            FirstWait = NULL;
                            Shared->LastSharedWake->Next = &SharedWake;
                        }

                        Shared->SharedCount++;
                        Shared->LastSharedWake = &SharedWake;

                        releaseWaitBlockLockImpl(SRWLock);

                        acquireSRWLockSharedWaitImpl(SRWLock,
                            FirstWait,
                            &SharedWake);

                        /* Successfully incremented the shared count, we acquired the lock */
                        break;
                    }
                } else {
                    SharedWake.Next = NULL;
                    SharedWake.Wake = 0;

                    /* We need to setup the first wait block. Currently an exclusive lock is
                    held, change the lock to contended mode. */
                    StackWaitBlock.Exclusive = FALSE;
                    StackWaitBlock.SharedCount = 1;
                    StackWaitBlock.Next = NULL;
                    StackWaitBlock.Last = &StackWaitBlock;
                    StackWaitBlock.SharedWakeChain = &SharedWake;
                    StackWaitBlock.LastSharedWake = &SharedWake;

                    NewValue = ((ULONG_PTR)&StackWaitBlock) | XP_SRWLOCK_OWNED | XP_SRWLOCK_CONTENDED;
                    if ((ULONG_PTR)InterlockedCompareExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue, (LONG)CurrentValue) == CurrentValue) {
                        acquireSRWLockSharedWaitImpl(SRWLock,
                            &StackWaitBlock,
                            &SharedWake);

                        /* Successfully set the shared count, we acquired the lock */
                        break;
                    }
                }
            } else {
                /* This is a fast path, we can simply try to set the shared count to 1 */
                NewValue = (1 << XP_SRWLOCK_BITS) | XP_SRWLOCK_SHARED | XP_SRWLOCK_OWNED;

                /* The XP_SRWLOCK_CONTENDED bit should never be set if neither the
                XP_SRWLOCK_SHARED nor the XP_SRWLOCK_OWNED bit is set */
                CV_ASSERT(!(CurrentValue & XP_SRWLOCK_CONTENDED), "acquireSRWLockShared fail 2\n");

                if ((ULONG_PTR)InterlockedCompareExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue, (LONG)CurrentValue) == CurrentValue) {
                    /* Successfully set the shared count, we acquired the lock */
                    break;
                }
            }
        }

        YieldProcessor();
    }
}

static inline void releaseSRWLockShared(PRTL_SRWLOCK SRWLock)
{
    ULONG_PTR CurrentValue, NewValue;
    PXP_SRWLOCK_WAITBLOCK WaitBlock;
    BOOLEAN LastShared;

    while (1) {
        CurrentValue = *(ULONG_PTR*)&SRWLock->Ptr;

        if (CurrentValue & XP_SRWLOCK_SHARED) {
            if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                /* There's a wait block, we need to wake a pending
                exclusive acquirer if this is the last shared release */
                WaitBlock = acquireWaitBlockLockImpl(SRWLock);
                if (WaitBlock != NULL) {
                    LastShared = (--WaitBlock->SharedCount == 0);

                    if (LastShared)
                        releaseWaitBlockLockLastSharedImpl(SRWLock, WaitBlock);
                    else
                        releaseWaitBlockLockImpl(SRWLock);

                    /* We released the lock */
                    break;
                }
            } else {
                /* This is a fast path, we can simply decrement the shared
                count and store the pointer */
                NewValue = CurrentValue >> XP_SRWLOCK_BITS;

                if (--NewValue != 0) {
                    NewValue = (NewValue << XP_SRWLOCK_BITS) | XP_SRWLOCK_SHARED | XP_SRWLOCK_OWNED;
                }

                if ((ULONG_PTR)InterlockedCompareExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue, (LONG)CurrentValue) == CurrentValue) {
                    /* Successfully released the lock */
                    break;
                }
            }
        } else {
            /* The XP_SRWLOCK_SHARED bit has to be present now,
            even in the contended case! */
            //RtlRaiseStatus(STATUS_RESOURCE_NOT_OWNED);
            CV_ASSERT(FALSE, "releaseSRWLockShared fail\n");
        }

        YieldProcessor();
    }
}

static inline void acquireSRWLockExclusive(PRTL_SRWLOCK SRWLock)
{
    __declspec(align(16)) XP_SRWLOCK_WAITBLOCK StackWaitBlock;
    PXP_SRWLOCK_WAITBLOCK First, Last;

    unsigned int addr = (unsigned int)(&StackWaitBlock);
    CV_ASSERT((addr & 0xf) == 0, "acquireSRWLockExclusive StackWaitBlock is not align\n");

    if (InterlockedBitTestAndSet((LONG*)&SRWLock->Ptr, XP_SRWLOCK_OWNED_BIT)) {
        ULONG_PTR CurrentValue;
        ULONG_PTR NewValue;

        while (1) {
            CurrentValue = *(ULONG_PTR*)&SRWLock->Ptr;

            if (CurrentValue & XP_SRWLOCK_SHARED) {
                /* A shared lock is being held right now. We need to add a wait block! */

                if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                    goto AddWaitBlock;
                } else {
                    /* There are no wait blocks so far, we need to add ourselves as the first
                    wait block. We need to keep the shared count! */
                    StackWaitBlock.Exclusive = TRUE;
                    StackWaitBlock.SharedCount = (LONG)(CurrentValue >> XP_SRWLOCK_BITS);
                    StackWaitBlock.Next = NULL;
                    StackWaitBlock.Last = &StackWaitBlock;
                    StackWaitBlock.Wake = 0;

                    NewValue = (ULONG_PTR)&StackWaitBlock | XP_SRWLOCK_SHARED | XP_SRWLOCK_CONTENDED | XP_SRWLOCK_OWNED;

                    if ((ULONG_PTR)InterlockedCompareExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue, (LONG)CurrentValue) == CurrentValue) {
                        acquireSRWLockExclusiveWaitImpl(SRWLock, &StackWaitBlock);

                        /* Successfully acquired the exclusive lock */
                        break;
                    }
                }
            } else {
                if (CurrentValue & XP_SRWLOCK_OWNED) {
                    /* An exclusive lock is being held right now. We need to add a wait block! */

                    if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                    AddWaitBlock:
                        StackWaitBlock.Exclusive = TRUE;
                        StackWaitBlock.SharedCount = 0;
                        StackWaitBlock.Next = NULL;
                        StackWaitBlock.Last = &StackWaitBlock;
                        StackWaitBlock.Wake = 0;

                        First = acquireWaitBlockLockImpl(SRWLock);
                        if (First != NULL) {
                            Last = First->Last;
                            Last->Next = &StackWaitBlock;
                            First->Last = &StackWaitBlock;

                            releaseWaitBlockLockImpl(SRWLock);

                            acquireSRWLockExclusiveWaitImpl(SRWLock, &StackWaitBlock);

                            /* Successfully acquired the exclusive lock */
                            break;
                        }
                    } else {
                        /* There are no wait blocks so far, we need to add ourselves as the first
                        wait block. We need to keep the shared count! */
                        StackWaitBlock.Exclusive = TRUE;
                        StackWaitBlock.SharedCount = 0;
                        StackWaitBlock.Next = NULL;
                        StackWaitBlock.Last = &StackWaitBlock;
                        StackWaitBlock.Wake = 0;

                        NewValue = (ULONG_PTR)&StackWaitBlock | XP_SRWLOCK_OWNED | XP_SRWLOCK_CONTENDED;
                        if ((ULONG_PTR)InterlockedCompareExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue, (LONG)CurrentValue) == CurrentValue) {
                            acquireSRWLockExclusiveWaitImpl(SRWLock, &StackWaitBlock);

                            /* Successfully acquired the exclusive lock */
                            break;
                        }
                    }
                } else {
                    if (!InterlockedBitTestAndSet((LONG*)&SRWLock->Ptr, XP_SRWLOCK_OWNED_BIT)) {
                        /* We managed to get hold of a simple exclusive lock! */
                        break;
                    }
                }
            }

            YieldProcessor();
        }
    }
}

static inline void releaseSRWLockExclusive(PRTL_SRWLOCK SRWLock)
{
    ULONG_PTR CurrentValue, NewValue;
    PXP_SRWLOCK_WAITBLOCK WaitBlock;

    while (1) {
        CurrentValue = *(ULONG_PTR*)&SRWLock->Ptr;

        if (!(CurrentValue & XP_SRWLOCK_OWNED)) {
            //RtlRaiseStatus(STATUS_RESOURCE_NOT_OWNED);
            CV_ASSERT(FALSE, "releaseSRWLockExclusive fail\n");
        }

        if (!(CurrentValue & XP_SRWLOCK_SHARED)) {
            if (CurrentValue & XP_SRWLOCK_CONTENDED) {
                /* There's a wait block, we need to wake the next pending
                acquirer (exclusive or shared) */
                WaitBlock = acquireWaitBlockLockImpl(SRWLock);
                if (WaitBlock != NULL) {
                    releaseWaitBlockLockExclusiveImpl(SRWLock, WaitBlock);

                    /* We released the lock */
                    break;
                }
            } else {
                /* This is a fast path, we can simply clear the XP_SRWLOCK_OWNED
                bit. All other bits should be 0 now because this is a simple
                exclusive lock and no one is waiting. */

                CV_ASSERT(!(CurrentValue & ((ULONG_PTR)(~XP_SRWLOCK_OWNED))), "releaseSRWLockExclusive fail 2\n");

                NewValue = 0;
                if ((ULONG_PTR)InterlockedCompareExchange((LONG*)&SRWLock->Ptr, (LONG)NewValue, (LONG)CurrentValue) == CurrentValue) {
                    /* We released the lock */
                    break;
                }
            }
        } else {
            /* The XP_SRWLOCK_SHARED bit must not be present now,
            not even in the contended case! */
            //RtlRaiseStatus(STATUS_RESOURCE_NOT_OWNED);
            CV_ASSERT(FALSE, "releaseSRWLockExclusive fail 3\n");
        }

        YieldProcessor();
    }
}

//////////////////////////////////////////////////////////////////////////

#define USE_WIN7_RWLOCK 0
#define USE_WIN7_CV 0

static inline void unlockCriticalSectionOrSRWLock(PCRITICAL_SECTION criticalSection, PSRWLOCK SRWLock, ULONG SRWFlags)
{
    if (criticalSection == NULL) {
        if (0 == (RTL_CONDITION_VARIABLE_LOCKMODE_SHARED & SRWFlags)) {
#if USE_WIN7_RWLOCK
            ReleaseSRWLockExclusive(SRWLock);
#else
            ReleaseSRWLockExclusiveXp(SRWLock);
#endif
        } else {
#if USE_WIN7_RWLOCK
            ReleaseSRWLockShared(SRWLock);
#else
            ReleaseSRWLockSharedXp(SRWLock);
#endif
        }
    } else {
        LeaveCriticalSection(criticalSection);
    }
}

static inline void lockCriticalSectionOrSRWLock(PCRITICAL_SECTION criticalSection, PSRWLOCK SRWLock, ULONG SRWFlags)
{
    if (criticalSection == NULL) {
        if (0 == (RTL_CONDITION_VARIABLE_LOCKMODE_SHARED & SRWFlags)) {
#if USE_WIN7_RWLOCK
            AcquireSRWLockExclusive(SRWLock);
#else
            AcquireSRWLockExclusiveXp(SRWLock);
#endif
        } else {
#if USE_WIN7_RWLOCK
            AcquireSRWLockShared(SRWLock);
#else
            AcquireSRWLockSharedXp(SRWLock);
#endif
        }
    } else {
        EnterCriticalSection(criticalSection);
    }
}

#define kCondVarLockedFlag ((ULONG_PTR)2)
#define kCondVarLockedAddr ((ULONG_PTR)3)

typedef struct _CondVarWaitEntry {
    int evt;
    DWORD debugCount;
    struct _CondVarWaitEntry* nextPtr;
    struct _CondVarWaitEntry* lastPtr;
} CondVarWaitEntry;

static inline BOOL waitCondVar(CondVarWaitEntry* entry, DWORD timeout)
{
    const int waitOneTimeInMs = 5;
    DWORD count = 0;
    while (TRUE) {
        count *= waitOneTimeInMs;
        if (0 != entry->evt)
            break;
        if (0xffffffff == timeout) {
            Sleep(5);
        } else if (count > timeout)
            return FALSE;
        else
            Sleep(waitOneTimeInMs);
    }

    return TRUE;
}

#if 0

CondVarWaitEntry* g_origEntrysTest = nullptr;
CondVarWaitEntry* g_entrysTest = nullptr;
int g_entryCount = 0;
const int kMaxEntrys = 900000;
static void initEntrysTest()
{
    g_origEntrysTest = (CondVarWaitEntry*)malloc(kMaxEntrys * sizeof(CondVarWaitEntry));
    memset(g_origEntrysTest, 0, kMaxEntrys * sizeof(CondVarWaitEntry));
    g_entrysTest = g_origEntrysTest;

    while (0 != ((ULONG_PTR)(g_entrysTest) & 0xf)) {
        g_entrysTest = (CondVarWaitEntry*)((unsigned char*)g_entrysTest + 1);
    }
}

static void checkAddr(void* addr)
{
    CV_ASSERT(!addr || (g_origEntrysTest <= addr && addr <= g_origEntrysTest + kMaxEntrys), "checkAddr fail\n");
}
#endif

static inline CondVarWaitEntry* lockAndGetRealAddr(PCONDITION_VARIABLE condVar)
{
    PVOID temp = NULL;
    PVOID ptr = condVar->Ptr;
    CV_ASSERT(ptr != (PVOID)kCondVarLockedFlag, "lockAndGetRealAddr fail 1\n");

    PVOID randAddr = (PVOID)((GetCurrentThreadId() << 5) | kCondVarLockedFlag);
    PVOID lockedAddr = NULL;
    PVOID realUnlockedAddr = NULL;
    //PVOID debugRec = NULL;

    while (TRUE) {
        ptr = condVar->Ptr;
        lockedAddr = (PVOID)((ULONG_PTR)ptr | kCondVarLockedFlag);
        realUnlockedAddr = (PVOID)((ULONG_PTR)lockedAddr & 0xfffffff0);
        CV_ASSERT(randAddr != realUnlockedAddr, "lockAndGetRealAddr fail 2\n");

        temp = (PVOID)InterlockedCompareExchange((long*)&condVar->Ptr, (long)randAddr, (long)realUnlockedAddr);
        //debugRec = condVar->Ptr;
        if (condVar->Ptr == randAddr)
            break;

        YieldProcessor();
    }

    CondVarWaitEntry* unlockAddr = (CondVarWaitEntry*)((ULONG_PTR)temp & 0xfffffff0);
    CV_ASSERT(unlockAddr == temp, "lockAndGetRealAddr fail 3\n");
    //checkAddr(unlockAddr);

    InterlockedExchange((long*)&condVar->Ptr, kCondVarLockedAddr);

    return unlockAddr;
}

static inline void checkEntrysIsValid(CondVarWaitEntry* head, CondVarWaitEntry* target)
{
    CondVarWaitEntry* ptr = head;
    CondVarWaitEntry* temp = head;
    while (ptr) {
        temp = ptr;
        ptr = ptr->lastPtr;
    }

    while (temp) {
        if (temp == target)
            DebugBreak();
        temp = temp->nextPtr;
    }
}

static inline CondVarWaitEntry* removeCondVarEntryFromList(CondVarWaitEntry* head, CondVarWaitEntry* target, int count)
{
    CondVarWaitEntry* ptr = head;
    BOOL isFound = FALSE;
    CondVarWaitEntry* newHead = head;
    if (newHead == target) {
        if (newHead->nextPtr)
            newHead = newHead->nextPtr;
        else if (newHead->lastPtr)
            newHead = newHead->lastPtr;
        else
            return NULL;
    }

    CondVarWaitEntry* temp = head;
    while (ptr) {
        temp = ptr;
        ptr = ptr->lastPtr;
    }

    while (temp) {
        if (temp == target) {
            isFound = TRUE;
            if (target->lastPtr)
                target->lastPtr->nextPtr = target->nextPtr;
            if (target->nextPtr)
                target->nextPtr->lastPtr = target->lastPtr;
            break;
        }
        temp = temp->nextPtr;
    }

    CV_ASSERT(isFound, "removeCondVarEntryFromList not found");
    return newHead;
}

static inline BOOL internalSleep(PCONDITION_VARIABLE condVar, PCRITICAL_SECTION criticalSection, PSRWLOCK SRWLock, ULONG SRWFlags, DWORD timeout)
{
    static int g_count = 0;
    InterlockedIncrement((LONG*)&g_count);
    int count = g_count;
#if 0
    // if (count > kMaxEntrys)
    //     DebugBreak();

    CondVarWaitEntry* entry = &g_entrysTest[g_entryCount++];
    memset(entry, 0, sizeof(CondVarWaitEntry));
#else
    __declspec(align(16)) CondVarWaitEntry entryStruct = { 0, GetCurrentThreadId(), (CondVarWaitEntry*)0, (CondVarWaitEntry*)0 };
    CondVarWaitEntry* entry = &entryStruct;
#endif
    CV_ASSERT(!((ULONG_PTR)(entry) & 0xf), "internalSleep is not align\n");
    entry->debugCount = (DWORD)count;

    CondVarWaitEntry* ptr = lockAndGetRealAddr(condVar);
    CV_ASSERT(!ptr || (condVar->Ptr == (PVOID)(kCondVarLockedAddr)), "internalSleep fail, lock var is error\n");

    if (ptr) {
        if (ptr->lastPtr) {
            CV_ASSERT(ptr->lastPtr->nextPtr == ptr, "internalSleep fail, lastPtr->nextPtr != ptr");
            ptr->lastPtr->nextPtr = entry;
        }
        ptr->lastPtr = entry;
        entry->nextPtr = ptr;
    }

    InterlockedExchange((long*)&condVar->Ptr, (long)entry);
    unlockCriticalSectionOrSRWLock(criticalSection, SRWLock, SRWFlags);

    if (!waitCondVar(entry, timeout)) {
        DebugBreak();
        return FALSE;
    }

    lockCriticalSectionOrSRWLock(criticalSection, SRWLock, SRWFlags);
    ptr = lockAndGetRealAddr(condVar);

    CV_ASSERT(!!ptr && condVar->Ptr == (PVOID)(kCondVarLockedAddr), "internalSleep fail 3\n");

    CondVarWaitEntry* newHead = removeCondVarEntryFromList(ptr, entry, count);

    //     char* output = (char*)malloc(0x100);
    //     sprintf_s(output, 0x99, "internalSleep end========: newHead:%p condVar->Ptr:%p entry:%p, %d\n", newHead, condVar->Ptr, entry, count);
    //     OutputDebugStringA(output);
    //     free(output);

    CV_ASSERT(1 == entry->evt, "internalSleep fail 4\n");
    CV_ASSERT(!((ULONG_PTR)(newHead) & 0xf), "internalSleep, newHead is not align\n");
    checkEntrysIsValid(newHead, entry);

    InterlockedExchange((long*)&condVar->Ptr, (long)newHead);

    entry->evt = (int)0xebebebeb;
    entry->lastPtr = (CondVarWaitEntry*)0xebebebeb;
    entry->nextPtr = (CondVarWaitEntry*)0xebebebeb;

    return TRUE;
}

static inline void wakeAllConditionVariable(PCONDITION_VARIABLE condVar)
{
    if (!condVar->Ptr)
        return;

    CondVarWaitEntry* ptr = lockAndGetRealAddr(condVar);
    CV_ASSERT(!!ptr, "wakeAllConditionVariable fail 1\n");

    CondVarWaitEntry* head = ptr;
    do {
        InterlockedExchange((long*)&head->evt, 1);

        head = head->nextPtr;
    } while (head);

    InterlockedExchange((long*)&condVar->Ptr, (long)ptr);
}

static inline void wakeConditionVariable(PCONDITION_VARIABLE condVar)
{
    if (!condVar->Ptr)
        return;

    CondVarWaitEntry* ptr = lockAndGetRealAddr(condVar);
    CV_ASSERT(!!ptr, "wakeConditionVariable fail 1\n");

    CondVarWaitEntry* head = ptr;
    InterlockedExchange((long*)&head->evt, 1);

    InterlockedExchange((long*)&condVar->Ptr, (long)ptr);
}

//////////////////////////////////////////////////////////////////////////

#define DEFINE_THREAD_SAFE_LOCAL(dllname, func) \
static long runOnce = 0; \
do { \
    long old_var = _InterlockedCompareExchange((long*)&(runOnce), 2, 0); \
    if (0 == old_var) { \
        HMODULE handle = GetModuleHandleW(dllname); \
        s_##func = (PFN_##func)GetProcAddress(handle, #func); \
 \
        _InterlockedExchange((long*)&(runOnce), 1); \
        break; \
    } else if (1 == old_var) { \
        break; \
    } else if (2 == old_var) { \
        continue; \
    } else { \
        DebugBreak(); \
    } \
} while (1);

inline BOOL SleepConditionVariableCSXp(PCONDITION_VARIABLE condVar, PCRITICAL_SECTION criticalSection, DWORD timeout)
{
#if USE_WIN7_CV
    return SleepConditionVariableCS(condVar, criticalSection, timeout);
#else
    typedef BOOL(__stdcall* PFN_SleepConditionVariableCS)(PCONDITION_VARIABLE condVar, PCRITICAL_SECTION criticalSection, DWORD timeout);
    static PFN_SleepConditionVariableCS s_SleepConditionVariableCS = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", SleepConditionVariableCS)

    if (s_SleepConditionVariableCS)
        return s_SleepConditionVariableCS(condVar, criticalSection, timeout);

    return internalSleep(condVar, criticalSection, (PSRWLOCK)0, 0, timeout);
#endif
}

inline BOOL SleepConditionVariableSRWXp(PCONDITION_VARIABLE condVar, PSRWLOCK SRWLock, DWORD dwMilliseconds, ULONG Flags)
{
#if USE_WIN7_CV
    return SleepConditionVariableSRW(condVar, SRWLock, dwMilliseconds, Flags);
#else
    typedef BOOL(__stdcall* PFN_SleepConditionVariableSRW)(PCONDITION_VARIABLE condVar, PSRWLOCK SRWLock, DWORD dwMilliseconds, ULONG Flags);
    static PFN_SleepConditionVariableSRW s_SleepConditionVariableSRW = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", SleepConditionVariableSRW)

    if (s_SleepConditionVariableSRW)
        return s_SleepConditionVariableSRW(condVar, SRWLock, dwMilliseconds, Flags);

    return internalSleep(condVar, (PCRITICAL_SECTION)0, SRWLock, Flags, dwMilliseconds);
#endif
}

inline void WakeAllConditionVariableXp(PCONDITION_VARIABLE condVar)
{
#if USE_WIN7_CV
    WakeAllConditionVariable(condVar);
#else
    typedef void(__stdcall* PFN_WakeAllConditionVariable)(PCONDITION_VARIABLE condVar);
    static PFN_WakeAllConditionVariable s_WakeAllConditionVariable = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", WakeAllConditionVariable)

    if (s_WakeAllConditionVariable)
        return s_WakeAllConditionVariable(condVar);

    wakeAllConditionVariable(condVar);
#endif
}

inline void WakeConditionVariableXp(PCONDITION_VARIABLE condVar)
{
#if USE_WIN7_CV
    WakeConditionVariable(condVar);
#else
    typedef void(__stdcall* PFN_WakeConditionVariable)(PCONDITION_VARIABLE condVar);
    static PFN_WakeConditionVariable s_WakeConditionVariable = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", WakeConditionVariable)

    if (s_WakeConditionVariable)
        return s_WakeConditionVariable(condVar);

    wakeConditionVariable(condVar);
#endif
}

inline void InitializeConditionVariableXp(PCONDITION_VARIABLE condVar)
{
#if USE_WIN7_CV
    InitializeConditionVariable(condVar);
#else
    typedef void(__stdcall* PFN_InitializeConditionVariable)(PCONDITION_VARIABLE condVar);
    static PFN_InitializeConditionVariable s_InitializeConditionVariable = NULL;
//     static long run_once = 0;
//     do {
//         long old_var = _InterlockedCompareExchange((long*)&(run_once), 2, 0);
//         if (0 == old_var) {
//             HMODULE handle = GetModuleHandleW(L"Kernel32.dll");
//             s_InitializeConditionVariable = (PFN_InitializeConditionVariable)GetProcAddress(handle, "InitializeConditionVariable");
// 
//             _InterlockedExchange((long*)&(run_once), 1);
//             break;
//         } else if (1 == old_var) {
//             break;
//         } else if (2 == old_var) {
//             continue;
//         } else {
//             DebugBreak();
//         }
//     } while (1);
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", InitializeConditionVariable)

    if (s_InitializeConditionVariable)
        return s_InitializeConditionVariable(condVar);

    condVar->Ptr = NULL;
#endif
}

//////////////////////////////////////////////////////////////////////////

inline void InitializeSRWLockXp(PRTL_SRWLOCK SRWLock)
{
    typedef void(__stdcall* PFN_InitializeSRWLock)(PRTL_SRWLOCK SRWLock);
    static PFN_InitializeSRWLock s_InitializeSRWLock = (PFN_InitializeSRWLock)(-1);
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", InitializeSRWLock)

    if (s_InitializeSRWLock)
        return s_InitializeSRWLock(SRWLock);

    SRWLock->Ptr = NULL;
}

inline void AcquireSRWLockSharedXp(PRTL_SRWLOCK SRWLock)
{
#if USE_WIN7_RWLOCK
    AcquireSRWLockShared(SRWLock);
#else
    typedef void(__stdcall* PFN_AcquireSRWLockShared)(PRTL_SRWLOCK SRWLock);
    static PFN_AcquireSRWLockShared s_AcquireSRWLockShared = (PFN_AcquireSRWLockShared)(-1);
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", AcquireSRWLockShared)

    if (s_AcquireSRWLockShared)
        return s_AcquireSRWLockShared(SRWLock);

    while (TRUE) {
        long temp = (long)InterlockedCompareExchange((long*)&SRWLock->Ptr, (long)1, (long)0);
        if (temp == 0)
            break;

        Sleep(1);
    }
#endif
}

inline void ReleaseSRWLockExclusiveXp(PRTL_SRWLOCK SRWLock)
{
#if USE_WIN7_RWLOCK
    //releaseSRWLockExclusive(SRWLock);
    ReleaseSRWLockExclusive(SRWLock);
#else
    typedef void(__stdcall* PFN_ReleaseSRWLockExclusive)(PRTL_SRWLOCK SRWLock);
    static PFN_ReleaseSRWLockExclusive s_ReleaseSRWLockExclusive = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", ReleaseSRWLockExclusive)

    if (s_ReleaseSRWLockExclusive)
        return s_ReleaseSRWLockExclusive(SRWLock);

    InterlockedExchange((long*)&SRWLock->Ptr, 0);
#endif
}

inline void AcquireSRWLockExclusiveXp(PRTL_SRWLOCK SRWLock)
{
#if USE_WIN7_RWLOCK
    AcquireSRWLockExclusive(SRWLock);
#else
    typedef void(__stdcall* PFN_AcquireSRWLockExclusive)(PRTL_SRWLOCK SRWLock);
    static PFN_AcquireSRWLockExclusive s_AcquireSRWLockExclusive = NULL;

//     do {
//         long old_var = _InterlockedCompareExchange((long*)&(runOnce), 2, 0);
//         if (0 == old_var) {
//             HMODULE handle = GetModuleHandleW(L"Kernel32.dll");
//             s_AcquireSRWLockExclusive = (PFN_AcquireSRWLockExclusive)GetProcAddress(handle, "AcquireSRWLockExclusive");
// 
//             _InterlockedExchange((long*)&(runOnce), 1);
//             break;
//         } else if (1 == old_var) {
//             break;
//         } else if (2 == old_var) {
//             continue;
//         } else {
//             DebugBreak();
//         }
//     } while (1);
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", AcquireSRWLockExclusive)

    if (s_AcquireSRWLockExclusive)
        return s_AcquireSRWLockExclusive(SRWLock);

    AcquireSRWLockSharedXp(SRWLock);
#endif
}

inline void ReleaseSRWLockSharedXp(PRTL_SRWLOCK SRWLock)
{
#if USE_WIN7_RWLOCK
    //releaseSRWLockShared(SRWLock);
    ReleaseSRWLockShared(SRWLock);
#else
    typedef void(__stdcall* PFN_ReleaseSRWLockShared)(PRTL_SRWLOCK SRWLock);
    static PFN_ReleaseSRWLockShared s_ReleaseSRWLockShared = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", ReleaseSRWLockShared)

    if (s_ReleaseSRWLockShared)
        return s_ReleaseSRWLockShared(SRWLock);

    ReleaseSRWLockExclusiveXp(SRWLock);
#endif
}

inline BOOL TryAcquireSRWLockExclusiveXp(PSRWLOCK SRWLock)
{
#if USE_WIN7_RWLOCK
    return TryAcquireSRWLockExclusive(SRWLock);
#else
    typedef char(__stdcall* PFN_TryAcquireSRWLockExclusive)(PSRWLOCK SRWLock);
    static PFN_TryAcquireSRWLockExclusive s_TryAcquireSRWLockExclusive = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", TryAcquireSRWLockExclusive)

    if (s_TryAcquireSRWLockExclusive)
        return s_TryAcquireSRWLockExclusive(SRWLock) != 0 ? 1 : 0;

    return _interlockedbittestandset((long*)SRWLock, 0) == 0;
#endif
}

inline BOOL TryAcquireSRWLockSharedXp(PSRWLOCK SRWLock)
{
#if USE_WIN7_RWLOCK
    return TryAcquireSRWLockShared(SRWLock);
#else
    typedef char(__stdcall* PFN_TryAcquireSRWLockShared)(PSRWLOCK SRWLock);
    static PFN_TryAcquireSRWLockShared s_TryAcquireSRWLockShared = NULL;
    DEFINE_THREAD_SAFE_LOCAL(L"Kernel32.dll", TryAcquireSRWLockShared)

    if (s_TryAcquireSRWLockShared)
        return s_TryAcquireSRWLockShared(SRWLock) != 0 ? 1 : 0;

    return _interlockedbittestandset((long*)SRWLock, 0) == 0;
#endif
}


// BOOL InitOnceExecuteOnceXP(INIT_ONCE * once, PINIT_ONCE_FN init_fn, PVOID parameter, LPVOID* context)
// {
//     LONG* once_control = (LONG*)(&(once->Ptr));
//     // xp_compatible
//     // Try for a fast path first. Note: this should be an acquire semantics read
//     // It is on x86 and x64, where Windows runs.
//     if (*once_control != 1) {
//         while (1) {
//             switch (InterlockedCompareExchange(once_control, 2, 0)) {
//             case 0:
//                 init_fn(NULL, parameter, context);
//                 InterlockedExchange(once_control, 1);
//                 return 0;
//             case 1:
//                 // The initializer has already been executed
//                 return 0;
//             default:
//                 // The initializer is being processed by another thread
//                 SwitchToThread();
//             }
//         }
//     }
//     return TRUE;
// }

// inline BOOL InitOnceExecuteOnceXp(PINIT_ONCE inOnce, PINIT_ONCE_FN initFunc, PVOID arg, LPVOID* context)
// {
//      LONG* once = (LONG *)inOnce;
// 
//     CV_ASSERT((((uintptr_t)once) & 3) == 0, "Values must be aligned.");
// 
//     /* This assumes that reading *once has acquire semantics. This should be TRUE
//     * on x86 and x86-64, where we expect Windows to run. */
// // #if !defined(OPENSSL_X86) && !defined(OPENSSL_X86_64)
// // #error "Windows once code may not work on other platforms. You can use InitOnceBeginInitialize on >= Vista"
// // #endif
//     if (*once == 1)
//         return TRUE;
// 
//     for (;;) {
//         switch (InterlockedCompareExchange(once, 2, 0)) {
//         case 0:
//             /* The value was zero so we are the first thread to call |CRYPTO_once|
//             * on it. */
//             initFunc(inOnce, arg, context);
//             /* Write one to indicate that initialisation is complete. */
//             InterlockedExchange(once, 1);
//             return;
// 
//         case 1:
//             /* Another thread completed initialisation between our fast-path check
//             * and |InterlockedCompareExchange|. */
//             return FALSE;
// 
//         case 2:
//             /* Another thread is running the initialisation. Switch to it then try
//             * again. */
//             SwitchToThread();
//             break;
// 
//         default:
//             abort();
//             return FALSE;
//         }
//     }
// 
//     return TRUE;
// }

#else

#define SleepConditionVariableCSXp SleepConditionVariableCS
#define SleepConditionVariableSRWXp SleepConditionVariableSRW
#define WakeAllConditionVariableXp WakeAllConditionVariable
#define WakeConditionVariableXp WakeConditionVariable
#define InitializeConditionVariableXp InitializeConditionVariable
#define InitializeSRWLockXp InitializeSRWLock
#define AcquireSRWLockSharedXp AcquireSRWLockShared
#define ReleaseSRWLockExclusiveXp ReleaseSRWLockExclusive
#define AcquireSRWLockExclusiveXp AcquireSRWLockExclusive
#define ReleaseSRWLockSharedXp ReleaseSRWLockShared
#define TryAcquireSRWLockExclusiveXp TryAcquireSRWLockExclusive
#define TryAcquireSRWLockSharedXp TryAcquireSRWLockShared
#define InitOnceExecuteOnceXp InitOnceExecuteOnce
#define InitializeCriticalSectionExXp InitializeCriticalSectionEx
#define InitOnceBeginInitializeXp InitOnceBeginInitialize
#define InitOnceCompleteXp InitOnceComplete
#define DeleteConditionVariableXp DeleteConditionVariable

#endif // SUPPORT_XP_CODE

#pragma pack(pop)

#endif // patch_code_sync_xp_h

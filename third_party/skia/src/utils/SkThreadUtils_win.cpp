/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTypes.h"
<<<<<<< HEAD
#if defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49

#include "SkThreadUtils.h"
#include "SkThreadUtils_win.h"

SkThread_WinData::SkThread_WinData(SkThread::entryPointProc entryPoint, void* data)
<<<<<<< HEAD
    : fHandle(nullptr)
=======
    : fHandle(NULL)
>>>>>>> miniblink49
    , fParam(data)
    , fThreadId(0)
    , fEntryPoint(entryPoint)
    , fStarted(false)
{
    fCancelEvent = CreateEvent(
<<<<<<< HEAD
        nullptr, // default security attributes
        false, //auto reset
        false, //not signaled
        nullptr); //no name
}

SkThread_WinData::~SkThread_WinData()
{
    CloseHandle(fCancelEvent);
}

static DWORD WINAPI thread_start(LPVOID data)
{
=======
        NULL,  // default security attributes
        false, //auto reset
        false, //not signaled
        NULL); //no name
}

SkThread_WinData::~SkThread_WinData() {
    CloseHandle(fCancelEvent);
}

static DWORD WINAPI thread_start(LPVOID data) {
>>>>>>> miniblink49
    SkThread_WinData* winData = static_cast<SkThread_WinData*>(data);

    //See if this thread was canceled before starting.
    if (WaitForSingleObject(winData->fCancelEvent, 0) == WAIT_OBJECT_0) {
        return 0;
    }

    winData->fEntryPoint(winData->fParam);
    return 0;
}

<<<<<<< HEAD
SkThread::SkThread(entryPointProc entryPoint, void* data)
{
    SkThread_WinData* winData = new SkThread_WinData(entryPoint, data);
    fData = winData;

    if (nullptr == winData->fCancelEvent) {
=======
SkThread::SkThread(entryPointProc entryPoint, void* data) {
    SkThread_WinData* winData = new SkThread_WinData(entryPoint, data);
    fData = winData;

    if (NULL == winData->fCancelEvent) {
>>>>>>> miniblink49
        return;
    }

    winData->fHandle = CreateThread(
<<<<<<< HEAD
        nullptr, // default security attributes
        0, // use default stack size
        thread_start, // thread function name (proxy)
        winData, // argument to thread function (proxy args)
        CREATE_SUSPENDED, // we used to set processor affinity, which needed this
        &winData->fThreadId); // returns the thread identifier
}

SkThread::~SkThread()
{
    if (fData != nullptr) {
        SkThread_WinData* winData = static_cast<SkThread_WinData*>(fData);
        // If created thread but start was never called, kill the thread.
        if (winData->fHandle != nullptr && !winData->fStarted) {
=======
        NULL,                   // default security attributes
        0,                      // use default stack size
        thread_start,           // thread function name (proxy)
        winData,                // argument to thread function (proxy args)
        CREATE_SUSPENDED,       // create suspended so affinity can be set
        &winData->fThreadId);   // returns the thread identifier
}

SkThread::~SkThread() {
    if (fData != NULL) {
        SkThread_WinData* winData = static_cast<SkThread_WinData*>(fData);
        // If created thread but start was never called, kill the thread.
        if (winData->fHandle != NULL && !winData->fStarted) {
>>>>>>> miniblink49
            if (SetEvent(winData->fCancelEvent) != 0) {
                if (this->start()) {
                    this->join();
                }
            } else {
                //kill with prejudice
                TerminateThread(winData->fHandle, -1);
            }
        }
        delete winData;
    }
}

<<<<<<< HEAD
bool SkThread::start()
{
    SkThread_WinData* winData = static_cast<SkThread_WinData*>(fData);
    if (nullptr == winData->fHandle) {
=======
bool SkThread::start() {
    SkThread_WinData* winData = static_cast<SkThread_WinData*>(fData);
    if (NULL == winData->fHandle) {
>>>>>>> miniblink49
        return false;
    }

    if (winData->fStarted) {
        return false;
    }
    winData->fStarted = -1 != ResumeThread(winData->fHandle);
    return winData->fStarted;
}

<<<<<<< HEAD
void SkThread::join()
{
    SkThread_WinData* winData = static_cast<SkThread_WinData*>(fData);
    if (nullptr == winData->fHandle || !winData->fStarted) {
=======
void SkThread::join() {
    SkThread_WinData* winData = static_cast<SkThread_WinData*>(fData);
    if (NULL == winData->fHandle || !winData->fStarted) {
>>>>>>> miniblink49
        return;
    }

    WaitForSingleObject(winData->fHandle, INFINITE);
}

<<<<<<< HEAD
#endif //defined(SK_BUILD_FOR_WIN32)
=======
static unsigned int num_bits_set(DWORD_PTR mask) {
    unsigned int count;
    for (count = 0; mask; ++count) {
        mask &= mask - 1;
    }
    return count;
}

static unsigned int nth_set_bit(unsigned int n, DWORD_PTR mask) {
    n %= num_bits_set(mask);
    for (unsigned int setBitsSeen = 0, currentBit = 0; true; ++currentBit) {
        if (mask & (static_cast<DWORD_PTR>(1) << currentBit)) {
            ++setBitsSeen;
            if (setBitsSeen > n) {
                return currentBit;
            }
        }
    }
}

bool SkThread::setProcessorAffinity(unsigned int processor) {
    SkThread_WinData* winData = static_cast<SkThread_WinData*>(fData);
    if (NULL == winData->fHandle) {
        return false;
    }

    DWORD_PTR processAffinityMask;
    DWORD_PTR systemAffinityMask;
    if (0 == GetProcessAffinityMask(GetCurrentProcess(),
                                    &processAffinityMask,
                                    &systemAffinityMask)) {
        return false;
    }

    DWORD_PTR threadAffinityMask = 1 << nth_set_bit(processor, processAffinityMask);
    return 0 != SetThreadAffinityMask(winData->fHandle, threadAffinityMask);
}
>>>>>>> miniblink49

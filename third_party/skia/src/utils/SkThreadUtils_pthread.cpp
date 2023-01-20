/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTypes.h"

#include "SkThreadUtils.h"
#include "SkThreadUtils_pthread.h"

#include <pthread.h>
#include <signal.h>

<<<<<<< HEAD
PThreadEvent::PThreadEvent()
    : fConditionFlag(false)
{
    pthread_cond_init(&fCondition, nullptr);
    pthread_mutex_init(&fConditionMutex, nullptr);
}
PThreadEvent::~PThreadEvent()
{
    pthread_mutex_destroy(&fConditionMutex);
    pthread_cond_destroy(&fCondition);
}
void PThreadEvent::trigger()
{
=======
PThreadEvent::PThreadEvent() : fConditionFlag(false) {
    pthread_cond_init(&fCondition, NULL);
    pthread_mutex_init(&fConditionMutex, NULL);
}
PThreadEvent::~PThreadEvent() {
    pthread_mutex_destroy(&fConditionMutex);
    pthread_cond_destroy(&fCondition);
}
void PThreadEvent::trigger() {
>>>>>>> miniblink49
    pthread_mutex_lock(&fConditionMutex);
    fConditionFlag = true;
    pthread_cond_signal(&fCondition);
    pthread_mutex_unlock(&fConditionMutex);
}
<<<<<<< HEAD
void PThreadEvent::wait()
{
=======
void PThreadEvent::wait() {
>>>>>>> miniblink49
    pthread_mutex_lock(&fConditionMutex);
    while (!fConditionFlag) {
        pthread_cond_wait(&fCondition, &fConditionMutex);
    }
    pthread_mutex_unlock(&fConditionMutex);
}
<<<<<<< HEAD
bool PThreadEvent::isTriggered()
{
=======
bool PThreadEvent::isTriggered() {
>>>>>>> miniblink49
    bool currentFlag;
    pthread_mutex_lock(&fConditionMutex);
    currentFlag = fConditionFlag;
    pthread_mutex_unlock(&fConditionMutex);
    return currentFlag;
}

SkThread_PThreadData::SkThread_PThreadData(SkThread::entryPointProc entryPoint, void* data)
    : fPThread()
    , fValidPThread(false)
    , fParam(data)
    , fEntryPoint(entryPoint)
{
    pthread_attr_init(&fAttr);
    pthread_attr_setdetachstate(&fAttr, PTHREAD_CREATE_JOINABLE);
}

<<<<<<< HEAD
SkThread_PThreadData::~SkThread_PThreadData()
{
    pthread_attr_destroy(&fAttr);
}

static void* thread_start(void* arg)
{
=======
SkThread_PThreadData::~SkThread_PThreadData() {
    pthread_attr_destroy(&fAttr);
}

static void* thread_start(void* arg) {
>>>>>>> miniblink49
    SkThread_PThreadData* pthreadData = static_cast<SkThread_PThreadData*>(arg);
    // Wait for start signal
    pthreadData->fStarted.wait();

    // Call entry point only if thread was not canceled before starting.
    if (!pthreadData->fCanceled.isTriggered()) {
        pthreadData->fEntryPoint(pthreadData->fParam);
    }
<<<<<<< HEAD
    return nullptr;
}

SkThread::SkThread(entryPointProc entryPoint, void* data)
{
=======
    return NULL;
}

SkThread::SkThread(entryPointProc entryPoint, void* data) {
>>>>>>> miniblink49
    SkThread_PThreadData* pthreadData = new SkThread_PThreadData(entryPoint, data);
    fData = pthreadData;

    int ret = pthread_create(&(pthreadData->fPThread),
<<<<<<< HEAD
        &(pthreadData->fAttr),
        thread_start,
        pthreadData);
=======
                             &(pthreadData->fAttr),
                             thread_start,
                             pthreadData);
>>>>>>> miniblink49

    pthreadData->fValidPThread = (0 == ret);
}

<<<<<<< HEAD
SkThread::~SkThread()
{
    if (fData != nullptr) {
=======
SkThread::~SkThread() {
    if (fData != NULL) {
>>>>>>> miniblink49
        SkThread_PThreadData* pthreadData = static_cast<SkThread_PThreadData*>(fData);
        // If created thread but start was never called, kill the thread.
        if (pthreadData->fValidPThread && !pthreadData->fStarted.isTriggered()) {
            pthreadData->fCanceled.trigger();
            if (this->start()) {
                this->join();
            }
        }
        delete pthreadData;
    }
}

<<<<<<< HEAD
bool SkThread::start()
{
=======
bool SkThread::start() {
>>>>>>> miniblink49
    SkThread_PThreadData* pthreadData = static_cast<SkThread_PThreadData*>(fData);
    if (!pthreadData->fValidPThread) {
        return false;
    }

    if (pthreadData->fStarted.isTriggered()) {
        return false;
    }
    pthreadData->fStarted.trigger();
    return true;
}

<<<<<<< HEAD
void SkThread::join()
{
=======
void SkThread::join() {
>>>>>>> miniblink49
    SkThread_PThreadData* pthreadData = static_cast<SkThread_PThreadData*>(fData);
    if (!pthreadData->fValidPThread || !pthreadData->fStarted.isTriggered()) {
        return;
    }

<<<<<<< HEAD
    pthread_join(pthreadData->fPThread, nullptr);
=======
    pthread_join(pthreadData->fPThread, NULL);
>>>>>>> miniblink49
}

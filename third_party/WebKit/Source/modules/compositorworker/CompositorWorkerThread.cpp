// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/compositorworker/CompositorWorkerThread.h"

#include "core/workers/InProcessWorkerObjectProxy.h"
#include "core/workers/WorkerThreadStartupData.h"
#include "modules/compositorworker/CompositorWorkerGlobalScope.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
#include "wtf/Assertions.h"
#include <memory>

namespace blink {

std::unique_ptr<CompositorWorkerThread> CompositorWorkerThread::create(
    PassRefPtr<WorkerLoaderProxy> workerLoaderProxy,
    InProcessWorkerObjectProxy& workerObjectProxy,
    double timeOrigin)
{
    TRACE_EVENT0(TRACE_DISABLED_BY_DEFAULT("compositor-worker"),
        "CompositorWorkerThread::create");
    ASSERT(isMainThread());
    return WTF::wrapUnique(new CompositorWorkerThread(
        std::move(workerLoaderProxy), workerObjectProxy, timeOrigin));
}

CompositorWorkerThread::CompositorWorkerThread(
    PassRefPtr<WorkerLoaderProxy> workerLoaderProxy,
    InProcessWorkerObjectProxy& workerObjectProxy,
    double timeOrigin)
    : AbstractAnimationWorkletThread(std::move(workerLoaderProxy),
        workerObjectProxy)
=======
#include "config.h"
#include "modules/compositorworker/CompositorWorkerThread.h"

#include "bindings/core/v8/V8Initializer.h"
#include "core/workers/WorkerObjectProxy.h"
#include "core/workers/WorkerThreadStartupData.h"
#include "modules/compositorworker/CompositorWorkerGlobalScope.h"
#include "modules/compositorworker/CompositorWorkerManager.h"
#include "public/platform/Platform.h"

namespace blink {

PassRefPtr<CompositorWorkerThread> CompositorWorkerThread::create(PassRefPtr<WorkerLoaderProxy> workerLoaderProxy, WorkerObjectProxy& workerObjectProxy, double timeOrigin)
{
    ASSERT(isMainThread());
    return adoptRef(new CompositorWorkerThread(workerLoaderProxy, workerObjectProxy, timeOrigin));
}

CompositorWorkerThread::CompositorWorkerThread(PassRefPtr<WorkerLoaderProxy> workerLoaderProxy, WorkerObjectProxy& workerObjectProxy, double timeOrigin)
    : WorkerThread(workerLoaderProxy, workerObjectProxy)
>>>>>>> miniblink49
    , m_workerObjectProxy(workerObjectProxy)
    , m_timeOrigin(timeOrigin)
{
}

<<<<<<< HEAD
CompositorWorkerThread::~CompositorWorkerThread() { }

WorkerOrWorkletGlobalScope* CompositorWorkerThread::createWorkerGlobalScope(
    std::unique_ptr<WorkerThreadStartupData> startupData)
{
    TRACE_EVENT0(TRACE_DISABLED_BY_DEFAULT("compositor-worker"),
        "CompositorWorkerThread::createWorkerGlobalScope");
    return CompositorWorkerGlobalScope::create(this, std::move(startupData),
        m_timeOrigin);
=======
CompositorWorkerThread::~CompositorWorkerThread()
{
}

PassRefPtrWillBeRawPtr<WorkerGlobalScope> CompositorWorkerThread::createWorkerGlobalScope(PassOwnPtr<WorkerThreadStartupData> startupData)
{
    return CompositorWorkerGlobalScope::create(this, startupData, m_timeOrigin);
}

WebThreadSupportingGC& CompositorWorkerThread::backingThread()
{
    return CompositorWorkerManager::instance()->compositorWorkerThread();
}

void CompositorWorkerThread::initializeBackingThread()
{
    CompositorWorkerManager::instance()->initializeBackingThread();
}

void CompositorWorkerThread::shutdownBackingThread()
{
    CompositorWorkerManager::instance()->shutdownBackingThread();
}

v8::Isolate* CompositorWorkerThread::initializeIsolate()
{
    return CompositorWorkerManager::instance()->initializeIsolate();
}

void CompositorWorkerThread::willDestroyIsolate()
{
    CompositorWorkerManager::instance()->willDestroyIsolate();
}

void CompositorWorkerThread::destroyIsolate()
{
    CompositorWorkerManager::instance()->destroyIsolate();
}

void CompositorWorkerThread::terminateV8Execution()
{
    CompositorWorkerManager::instance()->terminateV8Execution();
>>>>>>> miniblink49
}

} // namespace blink

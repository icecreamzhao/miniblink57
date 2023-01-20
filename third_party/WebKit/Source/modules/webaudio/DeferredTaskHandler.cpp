/*
 * Copyright (C) 2010, Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
<<<<<<< HEAD
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#include "modules/webaudio/DeferredTaskHandler.h"
#include "modules/webaudio/AudioNode.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "modules/webaudio/OfflineAudioContext.h"
#include "platform/CrossThreadFunctional.h"
#include "public/platform/Platform.h"
=======
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#if ENABLE(WEB_AUDIO)
#include "modules/webaudio/DeferredTaskHandler.h"

#include "modules/webaudio/AudioContext.h"
#include "modules/webaudio/AudioNode.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "platform/ThreadSafeFunctional.h"
#include "public/platform/Platform.h"
#include "wtf/MainThread.h"
>>>>>>> miniblink49

namespace blink {

void DeferredTaskHandler::lock()
{
    // Don't allow regular lock in real-time audio thread.
<<<<<<< HEAD
    DCHECK(!isAudioThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    m_contextGraphMutex.lock();
}

bool DeferredTaskHandler::tryLock()
{
    // Try to catch cases of using try lock on main thread
    // - it should use regular lock.
<<<<<<< HEAD
    DCHECK(isAudioThread());
    if (!isAudioThread()) {
        // In release build treat tryLock() as lock() (since above
        // DCHECK(isAudioThread) never fires) - this is the best we can do.
=======
    ASSERT(isAudioThread());
    if (!isAudioThread()) {
        // In release build treat tryLock() as lock() (since above
        // ASSERT(isAudioThread) never fires) - this is the best we can do.
>>>>>>> miniblink49
        lock();
        return true;
    }
    return m_contextGraphMutex.tryLock();
}

void DeferredTaskHandler::unlock()
{
    m_contextGraphMutex.unlock();
}

<<<<<<< HEAD
void DeferredTaskHandler::offlineLock()
{
    // CHECK is here to make sure to explicitly crash if this is called from
    // other than the offline render thread, which is considered as the audio
    // thread in OfflineAudioContext.
    CHECK(isAudioThread()) << "DeferredTaskHandler::offlineLock() must be called "
                              "within the offline audio thread.";

    m_contextGraphMutex.lock();
}

#if DCHECK_IS_ON()
=======
bool DeferredTaskHandler::isAudioThread() const
{
    return currentThread() == m_audioThread;
}

#if ENABLE(ASSERT)
>>>>>>> miniblink49
bool DeferredTaskHandler::isGraphOwner()
{
    return m_contextGraphMutex.locked();
}
#endif

void DeferredTaskHandler::addDeferredBreakConnection(AudioHandler& node)
{
<<<<<<< HEAD
    DCHECK(isAudioThread());
    m_deferredBreakConnectionList.push_back(&node);
=======
    ASSERT(isAudioThread());
    m_deferredBreakConnectionList.append(&node);
>>>>>>> miniblink49
}

void DeferredTaskHandler::breakConnections()
{
<<<<<<< HEAD
    DCHECK(isAudioThread());
=======
    ASSERT(isAudioThread());
>>>>>>> miniblink49
    ASSERT(isGraphOwner());

    for (unsigned i = 0; i < m_deferredBreakConnectionList.size(); ++i)
        m_deferredBreakConnectionList[i]->breakConnectionWithLock();
    m_deferredBreakConnectionList.clear();
}

<<<<<<< HEAD
void DeferredTaskHandler::markSummingJunctionDirty(
    AudioSummingJunction* summingJunction)
=======
void DeferredTaskHandler::markSummingJunctionDirty(AudioSummingJunction* summingJunction)
>>>>>>> miniblink49
{
    ASSERT(isGraphOwner());
    m_dirtySummingJunctions.add(summingJunction);
}

<<<<<<< HEAD
void DeferredTaskHandler::removeMarkedSummingJunction(
    AudioSummingJunction* summingJunction)
{
    DCHECK(isMainThread());
=======
void DeferredTaskHandler::removeMarkedSummingJunction(AudioSummingJunction* summingJunction)
{
    ASSERT(isMainThread());
>>>>>>> miniblink49
    AutoLocker locker(*this);
    m_dirtySummingJunctions.remove(summingJunction);
}

void DeferredTaskHandler::markAudioNodeOutputDirty(AudioNodeOutput* output)
{
    ASSERT(isGraphOwner());
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    m_dirtyAudioNodeOutputs.add(output);
}

void DeferredTaskHandler::removeMarkedAudioNodeOutput(AudioNodeOutput* output)
{
    ASSERT(isGraphOwner());
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    m_dirtyAudioNodeOutputs.remove(output);
}

void DeferredTaskHandler::handleDirtyAudioSummingJunctions()
{
    ASSERT(isGraphOwner());

    for (AudioSummingJunction* junction : m_dirtySummingJunctions)
        junction->updateRenderingState();
    m_dirtySummingJunctions.clear();
}

void DeferredTaskHandler::handleDirtyAudioNodeOutputs()
{
    ASSERT(isGraphOwner());

<<<<<<< HEAD
    HashSet<AudioNodeOutput*> dirtyOutputs;
    m_dirtyAudioNodeOutputs.swap(dirtyOutputs);

    // Note: the updating of rendering state may cause output nodes
    // further down the chain to be marked as dirty. These will not
    // be processed in this render quantum.
    for (AudioNodeOutput* output : dirtyOutputs)
        output->updateRenderingState();
=======
    for (AudioNodeOutput* output : m_dirtyAudioNodeOutputs)
        output->updateRenderingState();
    m_dirtyAudioNodeOutputs.clear();
>>>>>>> miniblink49
}

void DeferredTaskHandler::addAutomaticPullNode(AudioHandler* node)
{
    ASSERT(isGraphOwner());

    if (!m_automaticPullNodes.contains(node)) {
        m_automaticPullNodes.add(node);
        m_automaticPullNodesNeedUpdating = true;
    }
}

void DeferredTaskHandler::removeAutomaticPullNode(AudioHandler* node)
{
    ASSERT(isGraphOwner());

    if (m_automaticPullNodes.contains(node)) {
        m_automaticPullNodes.remove(node);
        m_automaticPullNodesNeedUpdating = true;
    }
}

void DeferredTaskHandler::updateAutomaticPullNodes()
{
    ASSERT(isGraphOwner());

    if (m_automaticPullNodesNeedUpdating) {
        copyToVector(m_automaticPullNodes, m_renderingAutomaticPullNodes);
        m_automaticPullNodesNeedUpdating = false;
    }
}

void DeferredTaskHandler::processAutomaticPullNodes(size_t framesToProcess)
{
<<<<<<< HEAD
    DCHECK(isAudioThread());
=======
    ASSERT(isAudioThread());
>>>>>>> miniblink49

    for (unsigned i = 0; i < m_renderingAutomaticPullNodes.size(); ++i)
        m_renderingAutomaticPullNodes[i]->processIfNecessary(framesToProcess);
}

void DeferredTaskHandler::addChangedChannelCountMode(AudioHandler* node)
{
    ASSERT(isGraphOwner());
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    m_deferredCountModeChange.add(node);
}

void DeferredTaskHandler::removeChangedChannelCountMode(AudioHandler* node)
{
    ASSERT(isGraphOwner());

    m_deferredCountModeChange.remove(node);
}

<<<<<<< HEAD
void DeferredTaskHandler::addChangedChannelInterpretation(AudioHandler* node)
{
    ASSERT(isGraphOwner());
    DCHECK(isMainThread());
    m_deferredChannelInterpretationChange.add(node);
}

void DeferredTaskHandler::removeChangedChannelInterpretation(
    AudioHandler* node)
{
    ASSERT(isGraphOwner());

    m_deferredChannelInterpretationChange.remove(node);
}

=======
>>>>>>> miniblink49
void DeferredTaskHandler::updateChangedChannelCountMode()
{
    ASSERT(isGraphOwner());

    for (AudioHandler* node : m_deferredCountModeChange)
        node->updateChannelCountMode();
    m_deferredCountModeChange.clear();
}

<<<<<<< HEAD
void DeferredTaskHandler::updateChangedChannelInterpretation()
{
    ASSERT(isGraphOwner());

    for (AudioHandler* node : m_deferredChannelInterpretationChange)
        node->updateChannelInterpretation();
    m_deferredChannelInterpretationChange.clear();
}

=======
>>>>>>> miniblink49
DeferredTaskHandler::DeferredTaskHandler()
    : m_automaticPullNodesNeedUpdating(false)
    , m_audioThread(0)
{
}

PassRefPtr<DeferredTaskHandler> DeferredTaskHandler::create()
{
    return adoptRef(new DeferredTaskHandler());
}

DeferredTaskHandler::~DeferredTaskHandler()
{
<<<<<<< HEAD
    DCHECK(!m_automaticPullNodes.size());
    if (m_automaticPullNodesNeedUpdating)
        m_renderingAutomaticPullNodes.resize(m_automaticPullNodes.size());
    DCHECK(!m_renderingAutomaticPullNodes.size());
=======
    ASSERT(!m_automaticPullNodes.size());
    if (m_automaticPullNodesNeedUpdating)
        m_renderingAutomaticPullNodes.resize(m_automaticPullNodes.size());
    ASSERT(!m_renderingAutomaticPullNodes.size());
>>>>>>> miniblink49
}

void DeferredTaskHandler::handleDeferredTasks()
{
    updateChangedChannelCountMode();
<<<<<<< HEAD
    updateChangedChannelInterpretation();
=======
>>>>>>> miniblink49
    handleDirtyAudioSummingJunctions();
    handleDirtyAudioNodeOutputs();
    updateAutomaticPullNodes();
}

void DeferredTaskHandler::contextWillBeDestroyed()
{
    for (auto& handler : m_renderingOrphanHandlers)
        handler->clearContext();
    for (auto& handler : m_deletableOrphanHandlers)
        handler->clearContext();
    clearHandlersToBeDeleted();
    // Some handlers might live because of their cross thread tasks.
}

<<<<<<< HEAD
DeferredTaskHandler::AutoLocker::AutoLocker(BaseAudioContext* context)
=======
DeferredTaskHandler::AutoLocker::AutoLocker(AudioContext* context)
>>>>>>> miniblink49
    : m_handler(context->deferredTaskHandler())
{
    m_handler.lock();
}

<<<<<<< HEAD
DeferredTaskHandler::OfflineGraphAutoLocker::OfflineGraphAutoLocker(
    OfflineAudioContext* context)
    : m_handler(context->deferredTaskHandler())
{
    m_handler.offlineLock();
}

void DeferredTaskHandler::addRenderingOrphanHandler(
    PassRefPtr<AudioHandler> handler)
{
    DCHECK(handler);
    DCHECK(!m_renderingOrphanHandlers.contains(handler));
    m_renderingOrphanHandlers.push_back(handler);
=======
void DeferredTaskHandler::addRenderingOrphanHandler(PassRefPtr<AudioHandler> handler)
{
    ASSERT(handler);
    ASSERT(!m_renderingOrphanHandlers.contains(handler));
    m_renderingOrphanHandlers.append(handler);
>>>>>>> miniblink49
}

void DeferredTaskHandler::requestToDeleteHandlersOnMainThread()
{
    ASSERT(isGraphOwner());
<<<<<<< HEAD
    DCHECK(isAudioThread());
=======
    ASSERT(isAudioThread());
>>>>>>> miniblink49
    if (m_renderingOrphanHandlers.isEmpty())
        return;
    m_deletableOrphanHandlers.appendVector(m_renderingOrphanHandlers);
    m_renderingOrphanHandlers.clear();
<<<<<<< HEAD
    Platform::current()->mainThread()->getWebTaskRunner()->postTask(
        BLINK_FROM_HERE,
        crossThreadBind(&DeferredTaskHandler::deleteHandlersOnMainThread,
            PassRefPtr<DeferredTaskHandler>(this)));
=======
    Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&DeferredTaskHandler::deleteHandlersOnMainThread, PassRefPtr<DeferredTaskHandler>(this)));
>>>>>>> miniblink49
}

void DeferredTaskHandler::deleteHandlersOnMainThread()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    AutoLocker locker(*this);
    m_deletableOrphanHandlers.clear();
}

void DeferredTaskHandler::clearHandlersToBeDeleted()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    AutoLocker locker(*this);
    m_renderingOrphanHandlers.clear();
    m_deletableOrphanHandlers.clear();
}

<<<<<<< HEAD
void DeferredTaskHandler::setAudioThreadToCurrentThread()
{
    DCHECK(!isMainThread());
    ThreadIdentifier thread = currentThread();
    releaseStore(&m_audioThread, thread);
}

} // namespace blink
=======
} // namespace blink

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49

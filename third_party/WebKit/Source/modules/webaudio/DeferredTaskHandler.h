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
>>>>>>> miniblink49
 */

#ifndef DeferredTaskHandler_h
#define DeferredTaskHandler_h

#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/HashSet.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"
#include "wtf/ThreadSafeRefCounted.h"
#include "wtf/Threading.h"
#include "wtf/ThreadingPrimitives.h"
#include "wtf/Vector.h"
<<<<<<< HEAD
#include "wtf/build_config.h"

namespace blink {

class BaseAudioContext;
class OfflineAudioContext;
=======

namespace blink {

class AudioContext;
>>>>>>> miniblink49
class AudioHandler;
class AudioNodeOutput;
class AudioSummingJunction;

// DeferredTaskHandler manages the major part of pre- and post- rendering tasks,
// and provides a lock mechanism against the audio rendering graph. A
<<<<<<< HEAD
// DeferredTaskHandler object is created when an BaseAudioContext object is
// created.
//
// DeferredTaskHandler outlives the BaseAudioContext only if all of the
// following conditions match:
=======
// DeferredTaskHandler object is created when an AudioContext object is created.
//
// DeferredTaskHandler outlives the AudioContext only if all of the following
// conditions match:
>>>>>>> miniblink49
// - An audio rendering thread is running,
// - It is requested to stop,
// - The audio rendering thread calls requestToDeleteHandlersOnMainThread(),
// - It posts a task of deleteHandlersOnMainThread(), and
<<<<<<< HEAD
// - GC happens and it collects the BaseAudioContext before the task execution.
//
class MODULES_EXPORT DeferredTaskHandler final
    : public ThreadSafeRefCounted<DeferredTaskHandler> {
=======
// - GC happens and it collects the AudioContext before the task execution.
//
class MODULES_EXPORT DeferredTaskHandler final : public ThreadSafeRefCounted<DeferredTaskHandler> {
>>>>>>> miniblink49
public:
    static PassRefPtr<DeferredTaskHandler> create();
    ~DeferredTaskHandler();

    void handleDeferredTasks();
    void contextWillBeDestroyed();

<<<<<<< HEAD
    // BaseAudioContext can pull node(s) at the end of each render quantum even
    // when they are not connected to any downstream nodes.  These two methods are
=======
    // AudioContext can pull node(s) at the end of each render quantum even when
    // they are not connected to any downstream nodes.  These two methods are
>>>>>>> miniblink49
    // called by the nodes who want to add/remove themselves into/from the
    // automatic pull lists.
    void addAutomaticPullNode(AudioHandler*);
    void removeAutomaticPullNode(AudioHandler*);
    // Called right before handlePostRenderTasks() to handle nodes which need to
    // be pulled even when they are not connected to anything.
    void processAutomaticPullNodes(size_t framesToProcess);

    // Keep track of AudioNode's that have their channel count mode changed. We
    // process the changes in the post rendering phase.
    void addChangedChannelCountMode(AudioHandler*);
    void removeChangedChannelCountMode(AudioHandler*);

<<<<<<< HEAD
    // Keep track of AudioNode's that have their channel interpretation
    // changed. We process the changes in the post rendering phase.
    void addChangedChannelInterpretation(AudioHandler*);
    void removeChangedChannelInterpretation(AudioHandler*);

    // Only accessed when the graph lock is held.
    void markSummingJunctionDirty(AudioSummingJunction*);
    // Only accessed when the graph lock is held. Must be called on the main
    // thread.
=======
    // Only accessed when the graph lock is held.
    void markSummingJunctionDirty(AudioSummingJunction*);
    // Only accessed when the graph lock is held. Must be called on the main thread.
>>>>>>> miniblink49
    void removeMarkedSummingJunction(AudioSummingJunction*);

    void markAudioNodeOutputDirty(AudioNodeOutput*);
    void removeMarkedAudioNodeOutput(AudioNodeOutput*);

    // In AudioNode::breakConnection() and deref(), a tryLock() is used for
    // calling actual processing, but if it fails keep track here.
    void addDeferredBreakConnection(AudioHandler&);
    void breakConnections();

    void addRenderingOrphanHandler(PassRefPtr<AudioHandler>);
    void requestToDeleteHandlersOnMainThread();
    void clearHandlersToBeDeleted();

    //
    // Thread Safety and Graph Locking:
    //
<<<<<<< HEAD
    void setAudioThreadToCurrentThread();
    ThreadIdentifier audioThread() const { return acquireLoad(&m_audioThread); }

    // TODO(hongchan): Use no-barrier load here. (crbug.com/247328)
    //
    // It is okay to use a relaxed (no-barrier) load here. Because the data
    // referenced by m_audioThread is not actually being used, thus we do not
    // need a barrier between the load of m_audioThread and of that data.
    bool isAudioThread() const
    {
        return currentThread() == acquireLoad(&m_audioThread);
    }
=======
    void setAudioThread(ThreadIdentifier thread) { m_audioThread = thread; } // FIXME: check either not initialized or the same
    ThreadIdentifier audioThread() const { return m_audioThread; }
    bool isAudioThread() const;
>>>>>>> miniblink49

    void lock();
    bool tryLock();
    void unlock();
<<<<<<< HEAD

    // This locks the audio render thread for OfflineAudioContext rendering.
    // MUST NOT be used in the real-time audio context.
    void offlineLock();

#if DCHECK_IS_ON()
=======
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    // Returns true if this thread owns the context's lock.
    bool isGraphOwner();
#endif

    class MODULES_EXPORT AutoLocker {
        STACK_ALLOCATED();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
    public:
        explicit AutoLocker(DeferredTaskHandler& handler)
            : m_handler(handler)
        {
            m_handler.lock();
        }
<<<<<<< HEAD
        explicit AutoLocker(BaseAudioContext*);
=======
        explicit AutoLocker(AudioContext*);
>>>>>>> miniblink49

        ~AutoLocker() { m_handler.unlock(); }

    private:
        DeferredTaskHandler& m_handler;
    };

<<<<<<< HEAD
    // This is for locking offline render thread (which is considered as the
    // audio thread) with unlocking on self-destruction at the end of the scope.
    // Also note that it uses lock() rather than tryLock() because the timing
    // MUST be accurate on offline rendering.
    class MODULES_EXPORT OfflineGraphAutoLocker {
        STACK_ALLOCATED();

    public:
        explicit OfflineGraphAutoLocker(OfflineAudioContext*);

        ~OfflineGraphAutoLocker() { m_handler.unlock(); }

    private:
        DeferredTaskHandler& m_handler;
    };

=======
>>>>>>> miniblink49
private:
    DeferredTaskHandler();
    void updateAutomaticPullNodes();
    void updateChangedChannelCountMode();
<<<<<<< HEAD
    void updateChangedChannelInterpretation();
=======
>>>>>>> miniblink49
    void handleDirtyAudioSummingJunctions();
    void handleDirtyAudioNodeOutputs();
    void deleteHandlersOnMainThread();

    // For the sake of thread safety, we maintain a seperate Vector of automatic
    // pull nodes for rendering in m_renderingAutomaticPullNodes.  It will be
    // copied from m_automaticPullNodes by updateAutomaticPullNodes() at the
    // very start or end of the rendering quantum.
    HashSet<AudioHandler*> m_automaticPullNodes;
    Vector<AudioHandler*> m_renderingAutomaticPullNodes;
<<<<<<< HEAD
    // m_automaticPullNodesNeedUpdating keeps track if m_automaticPullNodes is
    // modified.
=======
    // m_automaticPullNodesNeedUpdating keeps track if m_automaticPullNodes is modified.
>>>>>>> miniblink49
    bool m_automaticPullNodesNeedUpdating;

    // Collection of nodes where the channel count mode has changed. We want the
    // channel count mode to change in the pre- or post-rendering phase so as
    // not to disturb the running audio thread.
    HashSet<AudioHandler*> m_deferredCountModeChange;

<<<<<<< HEAD
    HashSet<AudioHandler*> m_deferredChannelInterpretationChange;

=======
>>>>>>> miniblink49
    // These two HashSet must be accessed only when the graph lock is held.
    // These raw pointers are safe because their destructors unregister them.
    HashSet<AudioSummingJunction*> m_dirtySummingJunctions;
    HashSet<AudioNodeOutput*> m_dirtyAudioNodeOutputs;

    // Only accessed in the audio thread.
    Vector<AudioHandler*> m_deferredBreakConnectionList;

    Vector<RefPtr<AudioHandler>> m_renderingOrphanHandlers;
    Vector<RefPtr<AudioHandler>> m_deletableOrphanHandlers;

    // Graph locking.
    RecursiveMutex m_contextGraphMutex;
    volatile ThreadIdentifier m_audioThread;
};

} // namespace blink

#endif // DeferredTaskHandler_h

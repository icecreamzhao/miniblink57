/*
 * Copyright (C) 2011, Google Inc. All rights reserved.
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

#include "modules/webaudio/OfflineAudioDestinationNode.h"

#include "core/dom/ExecutionContextTask.h"
#include "core/dom/TaskRunnerHelper.h"
#include "modules/webaudio/AudioNodeInput.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "modules/webaudio/BaseAudioContext.h"
#include "modules/webaudio/OfflineAudioContext.h"
#include "platform/audio/AudioBus.h"
#include "platform/audio/AudioUtilities.h"
#include "platform/audio/DenormalDisabler.h"
#include "platform/audio/HRTFDatabaseLoader.h"
#include "public/platform/Platform.h"
#include "wtf/PtrUtil.h"
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
#include "modules/webaudio/OfflineAudioDestinationNode.h"

#include "core/dom/CrossThreadTask.h"
#include "modules/webaudio/AudioContext.h"
#include "platform/Task.h"
#include "platform/audio/AudioBus.h"
#include "platform/audio/HRTFDatabaseLoader.h"
#include "public/platform/Platform.h"
>>>>>>> miniblink49
#include <algorithm>

namespace blink {

<<<<<<< HEAD
OfflineAudioDestinationHandler::OfflineAudioDestinationHandler(
    AudioNode& node,
    AudioBuffer* renderTarget)
    : AudioDestinationHandler(node, renderTarget->sampleRate())
    , m_renderTarget(renderTarget)
    , m_renderThread(WTF::wrapUnique(
          Platform::current()->createThread("offline audio renderer")))
    , m_framesProcessed(0)
    , m_framesToProcess(0)
    , m_isRenderingStarted(false)
    , m_shouldSuspend(false)
{
    m_renderBus = AudioBus::create(renderTarget->numberOfChannels(),
        AudioUtilities::kRenderQuantumFrames);
    m_framesToProcess = m_renderTarget->length();

    // Node-specific defaults.
    m_channelCount = m_renderTarget->numberOfChannels();
    setInternalChannelCountMode(Explicit);
    setInternalChannelInterpretation(AudioBus::Speakers);
}

PassRefPtr<OfflineAudioDestinationHandler>
OfflineAudioDestinationHandler::create(AudioNode& node,
    AudioBuffer* renderTarget)
=======
const size_t renderQuantumSize = 128;

OfflineAudioDestinationHandler::OfflineAudioDestinationHandler(AudioNode& node, AudioBuffer* renderTarget)
    : AudioDestinationHandler(node, renderTarget->sampleRate())
    , m_renderTarget(renderTarget)
    , m_startedRendering(false)
{
    m_renderBus = AudioBus::create(renderTarget->numberOfChannels(), renderQuantumSize);
}

PassRefPtr<OfflineAudioDestinationHandler> OfflineAudioDestinationHandler::create(AudioNode& node, AudioBuffer* renderTarget)
>>>>>>> miniblink49
{
    return adoptRef(new OfflineAudioDestinationHandler(node, renderTarget));
}

OfflineAudioDestinationHandler::~OfflineAudioDestinationHandler()
{
<<<<<<< HEAD
    DCHECK(!isInitialized());
=======
    ASSERT(!isInitialized());
>>>>>>> miniblink49
}

void OfflineAudioDestinationHandler::dispose()
{
    uninitialize();
    AudioDestinationHandler::dispose();
}

void OfflineAudioDestinationHandler::initialize()
{
    if (isInitialized())
        return;

    AudioHandler::initialize();
}

void OfflineAudioDestinationHandler::uninitialize()
{
    if (!isInitialized())
        return;

    if (m_renderThread)
<<<<<<< HEAD
        m_renderThread.reset();
=======
        m_renderThread.clear();
>>>>>>> miniblink49

    AudioHandler::uninitialize();
}

<<<<<<< HEAD
OfflineAudioContext* OfflineAudioDestinationHandler::context() const
{
    return static_cast<OfflineAudioContext*>(AudioDestinationHandler::context());
}

unsigned long OfflineAudioDestinationHandler::maxChannelCount() const
{
    return m_channelCount;
}

void OfflineAudioDestinationHandler::startRendering()
{
    DCHECK(isMainThread());
    DCHECK(m_renderThread);
    DCHECK(m_renderTarget);

    if (!m_renderTarget)
        return;

    // Rendering was not started. Starting now.
    if (!m_isRenderingStarted) {
        m_isRenderingStarted = true;
        m_renderThread->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE,
            crossThreadBind(&OfflineAudioDestinationHandler::startOfflineRendering,
                wrapPassRefPtr(this)));
        return;
    }

    // Rendering is already started, which implicitly means we resume the
    // rendering by calling |doOfflineRendering| on the render thread.
    m_renderThread->getWebTaskRunner()->postTask(
        BLINK_FROM_HERE,
        crossThreadBind(&OfflineAudioDestinationHandler::doOfflineRendering,
            wrapPassRefPtr(this)));
=======
void OfflineAudioDestinationHandler::startRendering()
{
    ASSERT(isMainThread());
    ASSERT(m_renderTarget);
    if (!m_renderTarget)
        return;

    if (!m_startedRendering) {
        m_startedRendering = true;
        m_renderThread = adoptPtr(Platform::current()->createThread("Offline Audio Renderer"));
        m_renderThread->postTask(FROM_HERE, new Task(threadSafeBind(&OfflineAudioDestinationHandler::offlineRender, PassRefPtr<OfflineAudioDestinationHandler>(this))));
    }
>>>>>>> miniblink49
}

void OfflineAudioDestinationHandler::stopRendering()
{
<<<<<<< HEAD
    // offline audio rendering CANNOT BE stopped by JavaScript.
    ASSERT_NOT_REACHED();
}

size_t OfflineAudioDestinationHandler::callbackBufferSize() const
{
    // The callback buffer size has no meaning for an offline context.
    NOTREACHED();
    return 0;
}
WebThread* OfflineAudioDestinationHandler::offlineRenderThread()
{
    DCHECK(m_renderThread);

    return m_renderThread.get();
}

void OfflineAudioDestinationHandler::startOfflineRendering()
{
    DCHECK(!isMainThread());

    DCHECK(m_renderBus);
    if (!m_renderBus)
        return;

    bool isAudioContextInitialized = context()->isDestinationInitialized();
    DCHECK(isAudioContextInitialized);
=======
    ASSERT_NOT_REACHED();
}

void OfflineAudioDestinationHandler::offlineRender()
{
    offlineRenderInternal();
    context()->handlePostRenderTasks();
}

void OfflineAudioDestinationHandler::offlineRenderInternal()
{
    ASSERT(!isMainThread());
    ASSERT(m_renderBus);
    if (!m_renderBus)
        return;

    bool isAudioContextInitialized = context()->isInitialized();
    ASSERT(isAudioContextInitialized);
>>>>>>> miniblink49
    if (!isAudioContextInitialized)
        return;

    bool channelsMatch = m_renderBus->numberOfChannels() == m_renderTarget->numberOfChannels();
<<<<<<< HEAD
    DCHECK(channelsMatch);
    if (!channelsMatch)
        return;

    bool isRenderBusAllocated = m_renderBus->length() >= AudioUtilities::kRenderQuantumFrames;
    DCHECK(isRenderBusAllocated);
    if (!isRenderBusAllocated)
        return;

    // Start rendering.
    doOfflineRendering();
}

void OfflineAudioDestinationHandler::doOfflineRendering()
{
    DCHECK(!isMainThread());

    unsigned numberOfChannels = m_renderTarget->numberOfChannels();

    // Reset the suspend flag.
    m_shouldSuspend = false;

    // If there is more to process and there is no suspension at the moment,
    // do continue to render quanta. Then calling OfflineAudioContext.resume()
    // will pick up the render loop again from where it was suspended.
    while (m_framesToProcess > 0 && !m_shouldSuspend) {
        // Suspend the rendering and update m_shouldSuspend if a scheduled
        // suspend found at the current sample frame. Otherwise render one
        // quantum and return false.
        m_shouldSuspend = renderIfNotSuspended(
            0, m_renderBus.get(), AudioUtilities::kRenderQuantumFrames);

        if (m_shouldSuspend)
            return;

        size_t framesAvailableToCopy = std::min(m_framesToProcess,
            static_cast<size_t>(AudioUtilities::kRenderQuantumFrames));

        for (unsigned channelIndex = 0; channelIndex < numberOfChannels;
             ++channelIndex) {
            const float* source = m_renderBus->channel(channelIndex)->data();
            float* destination = m_renderTarget->getChannelData(channelIndex)->data();
            memcpy(destination + m_framesProcessed, source,
                sizeof(float) * framesAvailableToCopy);
        }

        m_framesProcessed += framesAvailableToCopy;

        DCHECK_GE(m_framesToProcess, framesAvailableToCopy);
        m_framesToProcess -= framesAvailableToCopy;
    }

    // Finish up the rendering loop if there is no more to process.
    if (!m_framesToProcess)
        finishOfflineRendering();
}

void OfflineAudioDestinationHandler::suspendOfflineRendering()
{
    DCHECK(!isMainThread());

    // The actual rendering has been suspended. Notify the context.
    if (context()->getExecutionContext()) {
        context()->getExecutionContext()->postTask(
            TaskType::MediaElementEvent, BLINK_FROM_HERE,
            createCrossThreadTask(&OfflineAudioDestinationHandler::notifySuspend,
                PassRefPtr<OfflineAudioDestinationHandler>(this),
                context()->currentSampleFrame()));
    }
}

void OfflineAudioDestinationHandler::finishOfflineRendering()
{
    DCHECK(!isMainThread());

    // The actual rendering has been completed. Notify the context.
    if (context()->getExecutionContext()) {
        context()->getExecutionContext()->postTask(
            TaskType::MediaElementEvent, BLINK_FROM_HERE,
            createCrossThreadTask(&OfflineAudioDestinationHandler::notifyComplete,
                wrapPassRefPtr(this)));
    }
}

void OfflineAudioDestinationHandler::notifySuspend(size_t frame)
{
    DCHECK(isMainThread());

    if (context())
        context()->resolveSuspendOnMainThread(frame);
=======
    ASSERT(channelsMatch);
    if (!channelsMatch)
        return;

    bool isRenderBusAllocated = m_renderBus->length() >= renderQuantumSize;
    ASSERT(isRenderBusAllocated);
    if (!isRenderBusAllocated)
        return;

    // Break up the render target into smaller "render quantize" sized pieces.
    // Render until we're finished.
    size_t framesToProcess = m_renderTarget->length();
    unsigned numberOfChannels = m_renderTarget->numberOfChannels();

    unsigned n = 0;
    while (framesToProcess > 0) {
        // Render one render quantum.
        render(0, m_renderBus.get(), renderQuantumSize);

        size_t framesAvailableToCopy = std::min(framesToProcess, renderQuantumSize);

        for (unsigned channelIndex = 0; channelIndex < numberOfChannels; ++channelIndex) {
            const float* source = m_renderBus->channel(channelIndex)->data();
            float* destination = m_renderTarget->getChannelData(channelIndex)->data();
            memcpy(destination + n, source, sizeof(float) * framesAvailableToCopy);
        }

        n += framesAvailableToCopy;
        framesToProcess -= framesAvailableToCopy;
    }

    // Our work is done. Let the AudioContext know.
    if (context()->executionContext())
        context()->executionContext()->postTask(FROM_HERE, createCrossThreadTask(&OfflineAudioDestinationHandler::notifyComplete, PassRefPtr<OfflineAudioDestinationHandler>(this)));
>>>>>>> miniblink49
}

void OfflineAudioDestinationHandler::notifyComplete()
{
<<<<<<< HEAD
    // The OfflineAudioContext might be gone.
=======
    // The AudioContext might be gone.
>>>>>>> miniblink49
    if (context())
        context()->fireCompletionEvent();
}

<<<<<<< HEAD
bool OfflineAudioDestinationHandler::renderIfNotSuspended(
    AudioBus* sourceBus,
    AudioBus* destinationBus,
    size_t numberOfFrames)
{
    // We don't want denormals slowing down any of the audio processing
    // since they can very seriously hurt performance.
    // This will take care of all AudioNodes because they all process within this
    // scope.
    DenormalDisabler denormalDisabler;

    // Need to check if the context actually alive. Otherwise the subsequent
    // steps will fail. If the context is not alive somehow, return immediately
    // and do nothing.
    //
    // TODO(hongchan): because the context can go away while rendering, so this
    // check cannot guarantee the safe execution of the following steps.
    DCHECK(context());
    if (!context())
        return false;

    context()->deferredTaskHandler().setAudioThreadToCurrentThread();

    // If the destination node is not initialized, pass the silence to the final
    // audio destination (one step before the FIFO). This check is for the case
    // where the destination is in the middle of tearing down process.
    if (!isInitialized()) {
        destinationBus->zero();
        return false;
    }

    // Take care pre-render tasks at the beginning of each render quantum. Then
    // it will stop the rendering loop if the context needs to be suspended
    // at the beginning of the next render quantum.
    if (context()->handlePreOfflineRenderTasks()) {
        suspendOfflineRendering();
        return true;
    }

    // Prepare the local audio input provider for this render quantum.
    if (sourceBus)
        m_localAudioInputProvider.set(sourceBus);

    DCHECK_GE(numberOfInputs(), 1u);
    if (numberOfInputs() < 1) {
        destinationBus->zero();
        return false;
    }
    // This will cause the node(s) connected to us to process, which in turn will
    // pull on their input(s), all the way backwards through the rendering graph.
    AudioBus* renderedBus = input(0).pull(destinationBus, numberOfFrames);

    if (!renderedBus) {
        destinationBus->zero();
    } else if (renderedBus != destinationBus) {
        // in-place processing was not possible - so copy
        destinationBus->copyFrom(*renderedBus);
    }

    // Process nodes which need a little extra help because they are not connected
    // to anything, but still need to process.
    context()->deferredTaskHandler().processAutomaticPullNodes(numberOfFrames);

    // Let the context take care of any business at the end of each render
    // quantum.
    context()->handlePostOfflineRenderTasks();

    // Advance current sample-frame.
    size_t newSampleFrame = m_currentSampleFrame + numberOfFrames;
    releaseStore(&m_currentSampleFrame, newSampleFrame);

    return false;
}

// ----------------------------------------------------------------

OfflineAudioDestinationNode::OfflineAudioDestinationNode(
    BaseAudioContext& context,
    AudioBuffer* renderTarget)
=======
// ----------------------------------------------------------------

OfflineAudioDestinationNode::OfflineAudioDestinationNode(AudioContext& context, AudioBuffer* renderTarget)
>>>>>>> miniblink49
    : AudioDestinationNode(context)
{
    setHandler(OfflineAudioDestinationHandler::create(*this, renderTarget));
}

<<<<<<< HEAD
OfflineAudioDestinationNode* OfflineAudioDestinationNode::create(
    BaseAudioContext* context,
    AudioBuffer* renderTarget)
=======
OfflineAudioDestinationNode* OfflineAudioDestinationNode::create(AudioContext* context, AudioBuffer* renderTarget)
>>>>>>> miniblink49
{
    return new OfflineAudioDestinationNode(*context, renderTarget);
}

} // namespace blink
<<<<<<< HEAD
=======

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49

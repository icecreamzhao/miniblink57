// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CompositorWorkerGlobalScope_h
#define CompositorWorkerGlobalScope_h

<<<<<<< HEAD
#include "core/dom/CompositorProxyClient.h"
#include "core/dom/FrameRequestCallbackCollection.h"
#include "core/dom/MessagePort.h"
#include "core/workers/WorkerGlobalScope.h"
#include "modules/ModulesExport.h"
#include <memory>
=======
#include "core/dom/FrameRequestCallbackCollection.h"
#include "core/dom/MessagePort.h"
#include "core/workers/WorkerGlobalScope.h"
>>>>>>> miniblink49

namespace blink {

class CompositorWorkerThread;
<<<<<<< HEAD
class InProcessWorkerObjectProxy;
class WorkerThreadStartupData;

class MODULES_EXPORT CompositorWorkerGlobalScope final
    : public WorkerGlobalScope {
    DEFINE_WRAPPERTYPEINFO();

public:
    static CompositorWorkerGlobalScope* create(
        CompositorWorkerThread*,
        std::unique_ptr<WorkerThreadStartupData>,
        double timeOrigin);
    ~CompositorWorkerGlobalScope() override;

    void dispose() override;

    // EventTarget
    const AtomicString& interfaceName() const override;

    void postMessage(ExecutionContext*,
        PassRefPtr<SerializedScriptValue>,
        const MessagePortArray&,
        ExceptionState&);
    static bool canTransferArrayBuffersAndImageBitmaps() { return true; }
=======
class WorkerThreadStartupData;

class CompositorWorkerGlobalScope final : public WorkerGlobalScope {
    DEFINE_WRAPPERTYPEINFO();
public:
    static PassRefPtrWillBeRawPtr<CompositorWorkerGlobalScope> create(CompositorWorkerThread*, PassOwnPtr<WorkerThreadStartupData>, double timeOrigin);
    ~CompositorWorkerGlobalScope() override;

    // EventTarget
    const AtomicString& interfaceName() const override;

    void postMessage(ExecutionContext*, PassRefPtr<SerializedScriptValue>, const MessagePortArray*, ExceptionState&);
>>>>>>> miniblink49
    DEFINE_ATTRIBUTE_EVENT_LISTENER(message);

    int requestAnimationFrame(FrameRequestCallback*);
    void cancelAnimationFrame(int id);
<<<<<<< HEAD
    bool executeAnimationFrameCallbacks(double highResTimeMs);
=======
    void executeAnimationFrameCallbacks(double highResTimeNow);
>>>>>>> miniblink49

    // ExecutionContext:
    bool isCompositorWorkerGlobalScope() const override { return true; }

    DECLARE_VIRTUAL_TRACE();

private:
<<<<<<< HEAD
    CompositorWorkerGlobalScope(const KURL&,
        const String& userAgent,
        CompositorWorkerThread*,
        double timeOrigin,
        std::unique_ptr<SecurityOrigin::PrivilegeData>,
        WorkerClients*);

    InProcessWorkerObjectProxy& workerObjectProxy() const;

    bool m_executingAnimationFrameCallbacks;
=======
    CompositorWorkerGlobalScope(const KURL&, const String& userAgent, CompositorWorkerThread*, double timeOrigin, const SecurityOrigin*, PassOwnPtrWillBeRawPtr<WorkerClients>);
    CompositorWorkerThread* thread() const;

>>>>>>> miniblink49
    FrameRequestCallbackCollection m_callbackCollection;
};

} // namespace blink

#endif // CompositorWorkerGlobalScope_h

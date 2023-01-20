// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CompositorWorkerMessagingProxy_h
#define CompositorWorkerMessagingProxy_h

<<<<<<< HEAD
#include "core/workers/InProcessWorkerMessagingProxy.h"
#include "wtf/Allocator.h"
#include <memory>

namespace blink {

class CompositorWorkerMessagingProxy final
    : public InProcessWorkerMessagingProxy {
    USING_FAST_MALLOC(CompositorWorkerMessagingProxy);

public:
    CompositorWorkerMessagingProxy(InProcessWorkerBase*, WorkerClients*);
=======
#include "core/workers/WorkerMessagingProxy.h"

namespace blink {

class CompositorWorkerMessagingProxy final : public WorkerMessagingProxy {
public:
    explicit CompositorWorkerMessagingProxy(InProcessWorkerBase*);
>>>>>>> miniblink49

protected:
    ~CompositorWorkerMessagingProxy() override;

<<<<<<< HEAD
    std::unique_ptr<WorkerThread> createWorkerThread(double originTime) override;
=======
    PassRefPtr<WorkerThread> createWorkerThread(double originTime) override;
>>>>>>> miniblink49
};

} // namespace blink

#endif // CompositorWorkerMessagingProxy_h

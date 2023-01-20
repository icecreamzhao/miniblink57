// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/netinfo/WorkerNavigatorNetworkInformation.h"

#include "core/workers/WorkerNavigator.h"
#include "modules/netinfo/NetworkInformation.h"

namespace blink {

<<<<<<< HEAD
WorkerNavigatorNetworkInformation::WorkerNavigatorNetworkInformation(
    WorkerNavigator& navigator,
    ExecutionContext* context) { }

WorkerNavigatorNetworkInformation& WorkerNavigatorNetworkInformation::from(
    WorkerNavigator& navigator,
    ExecutionContext* context)
=======
WorkerNavigatorNetworkInformation::WorkerNavigatorNetworkInformation(WorkerNavigator& navigator, ExecutionContext* context)
{
}

WorkerNavigatorNetworkInformation& WorkerNavigatorNetworkInformation::from(WorkerNavigator& navigator, ExecutionContext* context)
>>>>>>> miniblink49
{
    WorkerNavigatorNetworkInformation* supplement = toWorkerNavigatorNetworkInformation(navigator, context);
    if (!supplement) {
        supplement = new WorkerNavigatorNetworkInformation(navigator, context);
        provideTo(navigator, supplementName(), supplement);
    }
    return *supplement;
}

<<<<<<< HEAD
WorkerNavigatorNetworkInformation*
WorkerNavigatorNetworkInformation::toWorkerNavigatorNetworkInformation(
    WorkerNavigator& navigator,
    ExecutionContext* context)
{
    return static_cast<WorkerNavigatorNetworkInformation*>(
        Supplement<WorkerNavigator>::from(navigator, supplementName()));
=======
WorkerNavigatorNetworkInformation* WorkerNavigatorNetworkInformation::toWorkerNavigatorNetworkInformation(WorkerNavigator& navigator, ExecutionContext* context)
{
    return static_cast<WorkerNavigatorNetworkInformation*>(HeapSupplement<WorkerNavigator>::from(navigator, supplementName()));
>>>>>>> miniblink49
}

const char* WorkerNavigatorNetworkInformation::supplementName()
{
    return "WorkerNavigatorNetworkInformation";
}

<<<<<<< HEAD
NetworkInformation* WorkerNavigatorNetworkInformation::connection(
    ScriptState* scriptState,
    WorkerNavigator& navigator)
{
    ExecutionContext* context = scriptState->getExecutionContext();
    return WorkerNavigatorNetworkInformation::from(navigator, context)
        .connection(context);
=======
NetworkInformation* WorkerNavigatorNetworkInformation::connection(ExecutionContext* context, WorkerNavigator& navigator)
{
    return WorkerNavigatorNetworkInformation::from(navigator, context).connection(context);
>>>>>>> miniblink49
}

DEFINE_TRACE(WorkerNavigatorNetworkInformation)
{
    visitor->trace(m_connection);
<<<<<<< HEAD
    Supplement<WorkerNavigator>::trace(visitor);
}

NetworkInformation* WorkerNavigatorNetworkInformation::connection(
    ExecutionContext* context)
=======
    HeapSupplement<WorkerNavigator>::trace(visitor);
}

NetworkInformation* WorkerNavigatorNetworkInformation::connection(ExecutionContext* context)
>>>>>>> miniblink49
{
    ASSERT(context);
    if (!m_connection)
        m_connection = NetworkInformation::create(context);
    return m_connection.get();
}

} // namespace blink

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/public/browser/devtools_agent_host_observer.h"

namespace content {

DevToolsAgentHostObserver::~DevToolsAgentHostObserver()
{
}

bool DevToolsAgentHostObserver::ShouldForceDevToolsAgentHostCreation()
{
    return false;
}

void DevToolsAgentHostObserver::DevToolsAgentHostCreated(
    DevToolsAgentHost* agent_host)
{
}

void DevToolsAgentHostObserver::DevToolsAgentHostAttached(
    DevToolsAgentHost* agent_host)
{
}

void DevToolsAgentHostObserver::DevToolsAgentHostDetached(
    DevToolsAgentHost* agent_host)
{
}

void DevToolsAgentHostObserver::DevToolsAgentHostDestroyed(
    DevToolsAgentHost* agent_host)
{
}

} // namespace content

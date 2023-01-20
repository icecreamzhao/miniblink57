// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/device_orientation/DeviceOrientationInspectorAgent.h"

#include "core/frame/LocalFrame.h"
#include "core/page/Page.h"
#include "modules/device_orientation/DeviceOrientationController.h"
#include "modules/device_orientation/DeviceOrientationData.h"
#include "wtf/Assertions.h"
=======
#include "config.h"
#include "modules/device_orientation/DeviceOrientationInspectorAgent.h"

#include "core/frame/LocalFrame.h"
#include "core/inspector/InspectorState.h"
#include "core/page/Page.h"

#include "modules/device_orientation/DeviceOrientationController.h"
#include "modules/device_orientation/DeviceOrientationData.h"
>>>>>>> miniblink49

namespace blink {

namespace DeviceOrientationInspectorAgentState {
<<<<<<< HEAD
    static const char alpha[] = "alpha";
    static const char beta[] = "beta";
    static const char gamma[] = "gamma";
    static const char overrideEnabled[] = "overrideEnabled";
}

// static
DeviceOrientationInspectorAgent* DeviceOrientationInspectorAgent::create(
    Page* page)
{
    return new DeviceOrientationInspectorAgent(*page);
}

DeviceOrientationInspectorAgent::~DeviceOrientationInspectorAgent() { }

DeviceOrientationInspectorAgent::DeviceOrientationInspectorAgent(Page& page)
    : m_page(&page)
{
}

DEFINE_TRACE(DeviceOrientationInspectorAgent)
{
    visitor->trace(m_page);
    InspectorBaseAgent::trace(visitor);
}

DeviceOrientationController& DeviceOrientationInspectorAgent::controller()
{
    DCHECK(toLocalFrame(m_page->mainFrame())->document());
    return DeviceOrientationController::from(
        *m_page->deprecatedLocalMainFrame()->document());
}

Response DeviceOrientationInspectorAgent::setDeviceOrientationOverride(
    double alpha,
    double beta,
    double gamma)
{
    m_state->setBoolean(DeviceOrientationInspectorAgentState::overrideEnabled,
        true);
    m_state->setDouble(DeviceOrientationInspectorAgentState::alpha, alpha);
    m_state->setDouble(DeviceOrientationInspectorAgentState::beta, beta);
    m_state->setDouble(DeviceOrientationInspectorAgentState::gamma, gamma);
    controller().setOverride(
        DeviceOrientationData::create(alpha, beta, gamma, false));
    return Response::OK();
}

Response DeviceOrientationInspectorAgent::clearDeviceOrientationOverride()
{
    m_state->setBoolean(DeviceOrientationInspectorAgentState::overrideEnabled,
        false);
    controller().clearOverride();
    return Response::OK();
}

Response DeviceOrientationInspectorAgent::disable()
{
    m_state->setBoolean(DeviceOrientationInspectorAgentState::overrideEnabled,
        false);
    controller().clearOverride();
    return Response::OK();
=======
static const char alpha[] = "alpha";
static const char beta[] = "beta";
static const char gamma[] = "gamma";
static const char overrideEnabled[] = "overrideEnabled";
}

// static
PassOwnPtrWillBeRawPtr<DeviceOrientationInspectorAgent> DeviceOrientationInspectorAgent::create(Page* page)
{
    return adoptPtrWillBeNoop(new DeviceOrientationInspectorAgent(*page));
}

DeviceOrientationInspectorAgent::~DeviceOrientationInspectorAgent()
{
}

DeviceOrientationInspectorAgent::DeviceOrientationInspectorAgent(Page& page)
    : InspectorBaseAgent<DeviceOrientationInspectorAgent, InspectorFrontend::DeviceOrientation>("DeviceOrientation")
    , m_page(page)
{
}

DeviceOrientationController& DeviceOrientationInspectorAgent::controller()
{
    ASSERT(toLocalFrame(m_page.mainFrame())->document());
    return DeviceOrientationController::from(*m_page.deprecatedLocalMainFrame()->document());
}

void DeviceOrientationInspectorAgent::setDeviceOrientationOverride(ErrorString* error, double alpha, double beta, double gamma)
{
    m_state->setBoolean(DeviceOrientationInspectorAgentState::overrideEnabled, true);
    m_state->setDouble(DeviceOrientationInspectorAgentState::alpha, alpha);
    m_state->setDouble(DeviceOrientationInspectorAgentState::beta, beta);
    m_state->setDouble(DeviceOrientationInspectorAgentState::gamma, gamma);
    controller().setOverride(DeviceOrientationData::create(alpha, beta, gamma));
}

void DeviceOrientationInspectorAgent::clearDeviceOrientationOverride(ErrorString* error)
{
    m_state->setBoolean(DeviceOrientationInspectorAgentState::overrideEnabled, false);
    controller().clearOverride();
}

void DeviceOrientationInspectorAgent::disable(ErrorString*)
{
    m_state->setBoolean(DeviceOrientationInspectorAgentState::overrideEnabled, false);
    controller().clearOverride();
>>>>>>> miniblink49
}

void DeviceOrientationInspectorAgent::restore()
{
<<<<<<< HEAD
    if (m_state->booleanProperty(
            DeviceOrientationInspectorAgentState::overrideEnabled, false)) {
        double alpha = 0;
        m_state->getDouble(DeviceOrientationInspectorAgentState::alpha, &alpha);
        double beta = 0;
        m_state->getDouble(DeviceOrientationInspectorAgentState::beta, &beta);
        double gamma = 0;
        m_state->getDouble(DeviceOrientationInspectorAgentState::gamma, &gamma);
        controller().setOverride(
            DeviceOrientationData::create(alpha, beta, gamma, false));
    }
}

void DeviceOrientationInspectorAgent::didCommitLoadForLocalFrame(
    LocalFrame* frame)
{
    // FIXME(dgozman): adapt this for out-of-process iframes.
    if (frame != m_page->mainFrame())
=======
    if (m_state->getBoolean(DeviceOrientationInspectorAgentState::overrideEnabled)) {
        double alpha = m_state->getDouble(DeviceOrientationInspectorAgentState::alpha);
        double beta = m_state->getDouble(DeviceOrientationInspectorAgentState::beta);
        double gamma = m_state->getDouble(DeviceOrientationInspectorAgentState::gamma);
        controller().setOverride(DeviceOrientationData::create(alpha, beta, gamma));
    }
}

void DeviceOrientationInspectorAgent::didCommitLoadForLocalFrame(LocalFrame* frame)
{
    // FIXME(dgozman): adapt this for out-of-process iframes.
    if (frame != m_page.mainFrame())
>>>>>>> miniblink49
        return;

    // New document in main frame - apply override there.
    // No need to cleanup previous one, as it's already gone.
    restore();
}

} // namespace blink

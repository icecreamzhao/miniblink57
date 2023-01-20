// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "web/InspectorRenderingAgent.h"

#include "core/frame/FrameView.h"
#include "core/frame/Settings.h"
<<<<<<< HEAD
#include "core/page/Page.h"
#include "web/InspectorOverlay.h"
=======
#include "core/inspector/InspectorState.h"
#include "core/page/Page.h"
>>>>>>> miniblink49
#include "web/WebLocalFrameImpl.h"
#include "web/WebViewImpl.h"

namespace blink {

namespace RenderingAgentState {
<<<<<<< HEAD
    static const char showDebugBorders[] = "showDebugBorders";
    static const char showFPSCounter[] = "showFPSCounter";
    static const char showPaintRects[] = "showPaintRects";
    static const char showScrollBottleneckRects[] = "showScrollBottleneckRects";
    static const char showSizeOnResize[] = "showSizeOnResize";
}

InspectorRenderingAgent* InspectorRenderingAgent::create(
    WebLocalFrameImpl* webLocalFrameImpl,
    InspectorOverlay* overlay)
{
    return new InspectorRenderingAgent(webLocalFrameImpl, overlay);
}

InspectorRenderingAgent::InspectorRenderingAgent(
    WebLocalFrameImpl* webLocalFrameImpl,
    InspectorOverlay* overlay)
    : m_webLocalFrameImpl(webLocalFrameImpl)
    , m_overlay(overlay)
{
}

WebViewImpl* InspectorRenderingAgent::webViewImpl()
{
    return m_webLocalFrameImpl->viewImpl();
}

void InspectorRenderingAgent::restore()
{
    setShowDebugBorders(
        m_state->booleanProperty(RenderingAgentState::showDebugBorders, false));
    setShowFPSCounter(
        m_state->booleanProperty(RenderingAgentState::showFPSCounter, false));
    setShowPaintRects(
        m_state->booleanProperty(RenderingAgentState::showPaintRects, false));
    setShowScrollBottleneckRects(m_state->booleanProperty(
        RenderingAgentState::showScrollBottleneckRects, false));
    setShowViewportSizeOnResize(
        m_state->booleanProperty(RenderingAgentState::showSizeOnResize, false));
}

Response InspectorRenderingAgent::disable()
{
    setShowDebugBorders(false);
    setShowFPSCounter(false);
    setShowPaintRects(false);
    setShowScrollBottleneckRects(false);
    setShowViewportSizeOnResize(false);
    return Response::OK();
}

Response InspectorRenderingAgent::setShowDebugBorders(bool show)
{
    m_state->setBoolean(RenderingAgentState::showDebugBorders, show);
    if (show) {
        Response response = compositingEnabled();
        if (!response.isSuccess())
            return response;
    }
    webViewImpl()->setShowDebugBorders(show);
    return Response::OK();
}

Response InspectorRenderingAgent::setShowFPSCounter(bool show)
{
    m_state->setBoolean(RenderingAgentState::showFPSCounter, show);
    if (show) {
        Response response = compositingEnabled();
        if (!response.isSuccess())
            return response;
    }
    webViewImpl()->setShowFPSCounter(show);
    return Response::OK();
}

Response InspectorRenderingAgent::setShowPaintRects(bool show)
{
    m_state->setBoolean(RenderingAgentState::showPaintRects, show);
    webViewImpl()->setShowPaintRects(show);
    if (!show && m_webLocalFrameImpl->frameView())
        m_webLocalFrameImpl->frameView()->invalidate();
    return Response::OK();
}

Response InspectorRenderingAgent::setShowScrollBottleneckRects(bool show)
{
    m_state->setBoolean(RenderingAgentState::showScrollBottleneckRects, show);
    if (show) {
        Response response = compositingEnabled();
        if (!response.isSuccess())
            return response;
    }
    webViewImpl()->setShowScrollBottleneckRects(show);
    return Response::OK();
}

Response InspectorRenderingAgent::setShowViewportSizeOnResize(bool show)
{
    m_state->setBoolean(RenderingAgentState::showSizeOnResize, show);
    if (m_overlay)
        m_overlay->setShowViewportSizeOnResize(show);
    return Response::OK();
}

Response InspectorRenderingAgent::compositingEnabled()
{
    if (!webViewImpl()->page()->settings().getAcceleratedCompositingEnabled())
        return Response::Error("Compositing mode is not supported");
    return Response::OK();
=======
static const char continuousPaintingEnabled[] = "continuousPaintingEnabled";
static const char showDebugBorders[] = "showDebugBorders";
static const char showFPSCounter[] = "showFPSCounter";
static const char showPaintRects[] = "showPaintRects";
static const char showScrollBottleneckRects[] = "showScrollBottleneckRects";
}

PassOwnPtrWillBeRawPtr<InspectorRenderingAgent> InspectorRenderingAgent::create(WebViewImpl* webViewImpl)
{
    return adoptPtrWillBeNoop(new InspectorRenderingAgent(webViewImpl));
}

InspectorRenderingAgent::InspectorRenderingAgent(WebViewImpl* webViewImpl)
    : InspectorBaseAgent<InspectorRenderingAgent, InspectorFrontend::Rendering>("Rendering")
    , m_webViewImpl(webViewImpl)
{
}

void InspectorRenderingAgent::restore()
{
    ErrorString error;
    setContinuousPaintingEnabled(&error, m_state->getBoolean(RenderingAgentState::continuousPaintingEnabled));
    setShowDebugBorders(&error, m_state->getBoolean(RenderingAgentState::showDebugBorders));
    setShowFPSCounter(&error, m_state->getBoolean(RenderingAgentState::showFPSCounter));
    setShowPaintRects(&error, m_state->getBoolean(RenderingAgentState::showPaintRects));
    setShowScrollBottleneckRects(&error, m_state->getBoolean(RenderingAgentState::showScrollBottleneckRects));
}

void InspectorRenderingAgent::disable(ErrorString*)
{
    ErrorString error;
    if (m_state->getBoolean(RenderingAgentState::continuousPaintingEnabled))
        setContinuousPaintingEnabled(&error, false);
    setShowDebugBorders(&error, false);
    setShowFPSCounter(&error, false);
    setShowPaintRects(&error, false);
    setShowScrollBottleneckRects(&error, false);
}

void InspectorRenderingAgent::setContinuousPaintingEnabled(ErrorString* errorString, bool enabled)
{
    m_state->setBoolean(RenderingAgentState::continuousPaintingEnabled, enabled);
    if (enabled && !compositingEnabled(errorString))
        return;
    m_webViewImpl->setContinuousPaintingEnabled(enabled);
}

void InspectorRenderingAgent::setShowDebugBorders(ErrorString* errorString, bool show)
{
    m_state->setBoolean(RenderingAgentState::showDebugBorders, show);
    if (show && !compositingEnabled(errorString))
        return;
    m_webViewImpl->setShowDebugBorders(show);
}

void InspectorRenderingAgent::setShowFPSCounter(ErrorString* errorString, bool show)
{
    m_state->setBoolean(RenderingAgentState::showFPSCounter, show);
    if (show && !compositingEnabled(errorString))
        return;
    m_webViewImpl->setShowFPSCounter(show);
}

void InspectorRenderingAgent::setShowPaintRects(ErrorString*, bool show)
{
    m_state->setBoolean(RenderingAgentState::showPaintRects, show);
    m_webViewImpl->setShowPaintRects(show);
    if (!show && m_webViewImpl->mainFrameImpl()->frameView())
        m_webViewImpl->mainFrameImpl()->frameView()->invalidate();
}

void InspectorRenderingAgent::setShowScrollBottleneckRects(ErrorString* errorString, bool show)
{
    m_state->setBoolean(RenderingAgentState::showScrollBottleneckRects, show);
    if (show && !compositingEnabled(errorString))
        return;
    m_webViewImpl->setShowScrollBottleneckRects(show);
}

bool InspectorRenderingAgent::compositingEnabled(ErrorString* errorString)
{
    if (!m_webViewImpl->page()->settings().acceleratedCompositingEnabled()) {
        if (errorString)
            *errorString = "Compositing mode is not supported";
        return false;
    }
    return true;
>>>>>>> miniblink49
}

DEFINE_TRACE(InspectorRenderingAgent)
{
<<<<<<< HEAD
    visitor->trace(m_webLocalFrameImpl);
    visitor->trace(m_overlay);
=======
>>>>>>> miniblink49
    InspectorBaseAgent::trace(visitor);
}

} // namespace blink

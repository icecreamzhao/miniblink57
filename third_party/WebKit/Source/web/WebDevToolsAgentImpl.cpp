/*
 * Copyright (C) 2010-2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "web/WebDevToolsAgentImpl.h"

#include "bindings/core/v8/ScriptController.h"
#include "bindings/core/v8/V8Binding.h"
<<<<<<< HEAD
#include "core/InstrumentingAgents.h"
#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Settings.h"
#include "core/inspector/InspectedFrames.h"
=======
#include "core/InspectorBackendDispatcher.h"
#include "core/InspectorFrontend.h"
#include "core/frame/FrameConsole.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Settings.h"
#include "core/inspector/AsyncCallTracker.h"
#include "core/inspector/IdentifiersFactory.h"
#include "core/inspector/InjectedScriptHost.h"
#include "core/inspector/InjectedScriptManager.h"
>>>>>>> miniblink49
#include "core/inspector/InspectorAnimationAgent.h"
#include "core/inspector/InspectorApplicationCacheAgent.h"
#include "core/inspector/InspectorCSSAgent.h"
#include "core/inspector/InspectorDOMAgent.h"
#include "core/inspector/InspectorDOMDebuggerAgent.h"
<<<<<<< HEAD
#include "core/inspector/InspectorInputAgent.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/inspector/InspectorLayerTreeAgent.h"
#include "core/inspector/InspectorLogAgent.h"
#include "core/inspector/InspectorMemoryAgent.h"
#include "core/inspector/InspectorNetworkAgent.h"
#include "core/inspector/InspectorPageAgent.h"
#include "core/inspector/InspectorResourceContainer.h"
#include "core/inspector/InspectorResourceContentLoader.h"
#include "core/inspector/InspectorTaskRunner.h"
#include "core/inspector/InspectorTracingAgent.h"
#include "core/inspector/InspectorWorkerAgent.h"
#include "core/inspector/MainThreadDebugger.h"
#include "core/layout/api/LayoutViewItem.h"
#include "core/page/FocusController.h"
#include "core/page/Page.h"
// #include "modules/accessibility/InspectorAccessibilityAgent.h"
// #include "modules/cachestorage/InspectorCacheStorageAgent.h"
// #include "modules/device_orientation/DeviceOrientationInspectorAgent.h"
// #include "modules/indexeddb/InspectorIndexedDBAgent.h"
// #include "modules/storage/InspectorDOMStorageAgent.h"
// #include "modules/webdatabase/InspectorDatabaseAgent.h"
#include "platform/CrossThreadFunctional.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/paint/PaintController.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
=======
#include "core/inspector/InspectorDebuggerAgent.h"
#include "core/inspector/InspectorHeapProfilerAgent.h"
#include "core/inspector/InspectorInputAgent.h"
#include "core/inspector/InspectorInspectorAgent.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/inspector/InspectorLayerTreeAgent.h"
#include "core/inspector/InspectorMemoryAgent.h"
#include "core/inspector/InspectorOverlay.h"
#include "core/inspector/InspectorPageAgent.h"
#include "core/inspector/InspectorProfilerAgent.h"
#include "core/inspector/InspectorResourceAgent.h"
#include "core/inspector/InspectorResourceContentLoader.h"
#include "core/inspector/InspectorState.h"
#include "core/inspector/InspectorTaskRunner.h"
#include "core/inspector/InspectorTimelineAgent.h"
#include "core/inspector/InspectorTracingAgent.h"
#include "core/inspector/InspectorWorkerAgent.h"
#include "core/inspector/InstrumentingAgents.h"
#include "core/inspector/LayoutEditor.h"
#include "core/inspector/MainThreadDebugger.h"
#include "core/inspector/PageConsoleAgent.h"
#include "core/inspector/PageDebuggerAgent.h"
#include "core/inspector/PageRuntimeAgent.h"
#include "core/layout/LayoutView.h"
#include "core/page/FocusController.h"
#include "core/page/Page.h"
#include "modules/accessibility/InspectorAccessibilityAgent.h"
#include "modules/cachestorage/InspectorCacheStorageAgent.h"
#include "modules/device_orientation/DeviceOrientationInspectorAgent.h"
#include "modules/filesystem/InspectorFileSystemAgent.h"
#include "modules/indexeddb/InspectorIndexedDBAgent.h"
#include "modules/screen_orientation/ScreenOrientationInspectorAgent.h"
#include "modules/storage/InspectorDOMStorageAgent.h"
#include "modules/webdatabase/InspectorDatabaseAgent.h"
#include "platform/JSONValues.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/paint/DisplayItemList.h"
>>>>>>> miniblink49
#include "public/platform/Platform.h"
#include "public/platform/WebLayerTreeView.h"
#include "public/platform/WebRect.h"
#include "public/platform/WebString.h"
#include "public/web/WebDevToolsAgentClient.h"
#include "public/web/WebSettings.h"
#include "web/DevToolsEmulator.h"
#include "web/InspectorEmulationAgent.h"
<<<<<<< HEAD
#include "web/InspectorOverlay.h"
=======
>>>>>>> miniblink49
#include "web/InspectorRenderingAgent.h"
#include "web/WebFrameWidgetImpl.h"
#include "web/WebInputEventConversion.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WebSettingsImpl.h"
#include "web/WebViewImpl.h"
#include "wtf/MathExtras.h"
#include "wtf/Noncopyable.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include "wtf/text/WTFString.h"
#include <memory>
#include <v8-inspector.h>

namespace blink {

namespace {

    bool isMainFrame(WebLocalFrameImpl* frame)
    {
        // TODO(dgozman): sometimes view->mainFrameImpl() does return null, even
        // though |frame| is meant to be main frame.  See http://crbug.com/526162.
        return frame->viewImpl() && !frame->parent();
    }
}

class ClientMessageLoopAdapter : public MainThreadDebugger::ClientMessageLoop {
public:
    ~ClientMessageLoopAdapter() override { s_instance = nullptr; }
=======
#include "wtf/text/WTFString.h"

namespace blink {

class ClientMessageLoopAdapter : public MainThreadDebugger::ClientMessageLoop {
public:
    ~ClientMessageLoopAdapter() override
    {
        s_instance = nullptr;
    }
>>>>>>> miniblink49

    static void ensureMainThreadDebuggerCreated(WebDevToolsAgentClient* client)
    {
        if (s_instance)
            return;
<<<<<<< HEAD
        std::unique_ptr<ClientMessageLoopAdapter> instance = WTF::wrapUnique(new ClientMessageLoopAdapter(
            WTF::wrapUnique(client->createClientMessageLoop())));
        s_instance = instance.get();
        MainThreadDebugger::instance()->setClientMessageLoop(std::move(instance));
=======
        OwnPtr<ClientMessageLoopAdapter> instance = adoptPtr(new ClientMessageLoopAdapter(adoptPtr(client->createClientMessageLoop())));
        s_instance = instance.get();
        v8::Isolate* isolate = V8PerIsolateData::mainThreadIsolate();
        V8PerIsolateData* data = V8PerIsolateData::from(isolate);
        data->setScriptDebugger(MainThreadDebugger::create(instance.release(), isolate));
    }

    static void webViewImplClosed(WebViewImpl* view)
    {
        if (s_instance)
            s_instance->m_frozenViews.remove(view);
    }

    static void webFrameWidgetImplClosed(WebFrameWidgetImpl* widget)
    {
        if (s_instance)
            s_instance->m_frozenWidgets.remove(widget);
>>>>>>> miniblink49
    }

    static void continueProgram()
    {
        // Release render thread if necessary.
<<<<<<< HEAD
        if (s_instance)
            s_instance->quitNow();
    }

    static void pauseForCreateWindow(WebLocalFrameImpl* frame)
    {
        if (s_instance)
            s_instance->runForCreateWindow(frame);
    }

    static bool resumeForCreateWindow()
    {
        return s_instance ? s_instance->quitForCreateWindow() : false;
    }

private:
    ClientMessageLoopAdapter(
        std::unique_ptr<WebDevToolsAgentClient::WebKitClientMessageLoop>
            messageLoop)
        : m_runningForDebugBreak(false)
        , m_runningForCreateWindow(false)
        , m_messageLoop(std::move(messageLoop))
    {
        DCHECK(m_messageLoop.get());
    }

    void run(LocalFrame* frame) override
    {
        if (m_runningForDebugBreak)
            return;

        m_runningForDebugBreak = true;
        if (!m_runningForCreateWindow)
            runLoop(WebLocalFrameImpl::fromFrame(frame));
    }

    void runForCreateWindow(WebLocalFrameImpl* frame)
    {
        if (m_runningForCreateWindow)
            return;

        m_runningForCreateWindow = true;
        if (!m_runningForDebugBreak)
            runLoop(frame);
    }

    void runLoop(WebLocalFrameImpl* frame)
    {
        // 0. Flush pending frontend messages.
        WebDevToolsAgentImpl* agent = frame->devToolsAgentImpl();
        agent->flushProtocolNotifications();

        // 1. Disable input events.
        WebFrameWidgetBase::setIgnoreInputEvents(true);
        for (const auto view : WebViewImpl::allInstances())
            view->chromeClient().notifyPopupOpeningObservers();

        // 2. Notify embedder about pausing.
        if (agent->client())
            agent->client()->willEnterDebugLoop();
=======
        if (s_instance && s_instance->m_running)
            MainThreadDebugger::instance()->debugger()->continueProgram();
    }

private:
    ClientMessageLoopAdapter(PassOwnPtr<WebDevToolsAgentClient::WebKitClientMessageLoop> messageLoop)
        : m_running(false)
        , m_messageLoop(messageLoop) { }

    void run(LocalFrame* frame) override
    {
        if (m_running)
            return;
        m_running = true;

        // 0. Flush pending frontend messages.
        WebLocalFrameImpl* frameImpl = WebLocalFrameImpl::fromFrame(frame);
        WebDevToolsAgentImpl* agent = frameImpl->devToolsAgentImpl();
        agent->flushPendingProtocolNotifications();

        Vector<WebViewImpl*> views;
        Vector<WebFrameWidgetImpl*> widgets;

        // 1. Disable input events.
        const HashSet<WebViewImpl*>& viewImpls = WebViewImpl::allInstances();
        HashSet<WebViewImpl*>::const_iterator viewImplsEnd = viewImpls.end();
        for (HashSet<WebViewImpl*>::const_iterator it =  viewImpls.begin(); it != viewImplsEnd; ++it) {
            WebViewImpl* view = *it;
            m_frozenViews.add(view);
            views.append(view);
            view->setIgnoreInputEvents(true);
        }

        const HashSet<WebFrameWidgetImpl*>& widgetImpls = WebFrameWidgetImpl::allInstances();
        HashSet<WebFrameWidgetImpl*>::const_iterator widgetImplsEnd = widgetImpls.end();
        for (HashSet<WebFrameWidgetImpl*>::const_iterator it =  widgetImpls.begin(); it != widgetImplsEnd; ++it) {
            WebFrameWidgetImpl* widget = *it;
            m_frozenWidgets.add(widget);
            widgets.append(widget);
            widget->setIgnoreInputEvents(true);
        }

        // 2. Notify embedder about pausing.
        agent->client()->willEnterDebugLoop();
>>>>>>> miniblink49

        // 3. Disable active objects
        WebView::willEnterModalLoop();

        // 4. Process messages until quitNow is called.
        m_messageLoop->run();

        // 5. Resume active objects
        WebView::didExitModalLoop();

<<<<<<< HEAD
        WebFrameWidgetBase::setIgnoreInputEvents(false);

        // 7. Notify embedder about resuming.
        if (agent->client())
            agent->client()->didExitDebugLoop();
=======
        // 6. Resume input events.
        for (Vector<WebViewImpl*>::iterator it = views.begin(); it != views.end(); ++it) {
            if (m_frozenViews.contains(*it)) {
                // The view was not closed during the dispatch.
                (*it)->setIgnoreInputEvents(false);
            }
        }
        for (Vector<WebFrameWidgetImpl*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
            if (m_frozenWidgets.contains(*it)) {
                // The widget was not closed during the dispatch.
                (*it)->setIgnoreInputEvents(false);
            }
        }

        // 7. Notify embedder about resuming.
        agent->client()->didExitDebugLoop();

        // 8. All views have been resumed, clear the set.
        m_frozenViews.clear();
        m_frozenWidgets.clear();

        m_running = false;
>>>>>>> miniblink49
    }

    void quitNow() override
    {
<<<<<<< HEAD
        if (m_runningForDebugBreak) {
            m_runningForDebugBreak = false;
            if (!m_runningForCreateWindow)
                m_messageLoop->quitNow();
        }
    }

    bool quitForCreateWindow()
    {
        if (m_runningForCreateWindow) {
            m_runningForCreateWindow = false;
            if (!m_runningForDebugBreak)
                m_messageLoop->quitNow();
            return true;
        }
        return false;
    }

    void runIfWaitingForDebugger(LocalFrame* frame) override
    {
        // If we've paused for createWindow, handle it ourselves.
        if (quitForCreateWindow())
            return;
        // Otherwise, pass to the client (embedded workers do it differently).
        WebDevToolsAgentImpl* agent = WebLocalFrameImpl::fromFrame(frame)->devToolsAgentImpl();
        if (agent && agent->client())
            agent->client()->resumeStartup();
    }

    bool m_runningForDebugBreak;
    bool m_runningForCreateWindow;
    std::unique_ptr<WebDevToolsAgentClient::WebKitClientMessageLoop>
        m_messageLoop;

=======
        m_messageLoop->quitNow();
    }

    bool m_running;
    OwnPtr<WebDevToolsAgentClient::WebKitClientMessageLoop> m_messageLoop;
    typedef HashSet<WebViewImpl*> FrozenViewsSet;
    FrozenViewsSet m_frozenViews;
    typedef HashSet<WebFrameWidgetImpl*> FrozenWidgetsSet;
    FrozenWidgetsSet m_frozenWidgets;
>>>>>>> miniblink49
    static ClientMessageLoopAdapter* s_instance;
};

ClientMessageLoopAdapter* ClientMessageLoopAdapter::s_instance = nullptr;

<<<<<<< HEAD
// static
WebDevToolsAgentImpl* WebDevToolsAgentImpl::create(
    WebLocalFrameImpl* frame,
    WebDevToolsAgentClient* client)
{
    InspectorOverlay* overlay = new InspectorOverlay(frame);

    if (!isMainFrame(frame)) {
        WebDevToolsAgentImpl* agent = new WebDevToolsAgentImpl(frame, client, overlay, false);
        if (frame->frameWidget())
            agent->layerTreeViewChanged(
                toWebFrameWidgetImpl(frame->frameWidget())->layerTreeView());
        return agent;
    }

    WebViewImpl* view = frame->viewImpl();
    WebDevToolsAgentImpl* agent = new WebDevToolsAgentImpl(frame, client, overlay, true);
    agent->layerTreeViewChanged(view->layerTreeView());
    return agent;
}

WebDevToolsAgentImpl::WebDevToolsAgentImpl(WebLocalFrameImpl* webLocalFrameImpl,
    WebDevToolsAgentClient* client,
    InspectorOverlay* overlay,
    bool includeViewAgents)
    : m_client(client)
    , m_webLocalFrameImpl(webLocalFrameImpl)
    , m_instrumentingAgents(
          m_webLocalFrameImpl->frame()->instrumentingAgents())
    , m_resourceContentLoader(
          InspectorResourceContentLoader::create(m_webLocalFrameImpl->frame()))
    , m_overlay(overlay)
    , m_inspectedFrames(InspectedFrames::create(m_webLocalFrameImpl->frame()))
    , m_resourceContainer(new InspectorResourceContainer(m_inspectedFrames))
    , m_domAgent(nullptr)
    , m_pageAgent(nullptr)
    , m_networkAgent(nullptr)
    , m_layerTreeAgent(nullptr)
    , m_tracingAgent(nullptr)
    , m_includeViewAgents(includeViewAgents)
    , m_layerTreeId(0)
{
    DCHECK(isMainThread());
    DCHECK(m_webLocalFrameImpl->frame());
=======
class PageInjectedScriptHostClient: public InjectedScriptHostClient {
public:
    PageInjectedScriptHostClient() { }

    ~PageInjectedScriptHostClient() override { }

    void muteWarningsAndDeprecations()
    {
        FrameConsole::mute();
        UseCounter::muteForInspector();
    }

    void unmuteWarningsAndDeprecations()
    {
        FrameConsole::unmute();
        UseCounter::unmuteForInspector();
    }
};

class DebuggerTask : public InspectorTaskRunner::Task {
public:
    DebuggerTask(PassOwnPtr<WebDevToolsAgent::MessageDescriptor> descriptor)
        : m_descriptor(descriptor)
    {
    }

    ~DebuggerTask() override {}
    virtual void run()
    {
        WebDevToolsAgent* webagent = m_descriptor->agent();
        if (!webagent)
            return;

        WebDevToolsAgentImpl* agentImpl = static_cast<WebDevToolsAgentImpl*>(webagent);
        if (agentImpl->m_attached)
            agentImpl->dispatchMessageFromFrontend(m_descriptor->message());
    }

private:
    OwnPtr<WebDevToolsAgent::MessageDescriptor> m_descriptor;
};

// static
PassOwnPtrWillBeRawPtr<WebDevToolsAgentImpl> WebDevToolsAgentImpl::create(WebLocalFrameImpl* frame, WebDevToolsAgentClient* client)
{
    WebViewImpl* view = frame->viewImpl();
    bool isMainFrame = view && view->mainFrameImpl() == frame;
    if (!isMainFrame) {
        WebDevToolsAgentImpl* agent = new WebDevToolsAgentImpl(frame, client, frame->inspectorOverlay());
        if (frame->frameWidget())
            agent->layerTreeViewChanged(frame->frameWidget()->layerTreeView());
        return adoptPtrWillBeNoop(agent);
    }

    WebDevToolsAgentImpl* agent = new WebDevToolsAgentImpl(frame, client, view->inspectorOverlay());
    agent->registerAgent(InspectorRenderingAgent::create(view));
    //agent->registerAgent(InspectorEmulationAgent::create(view));
    // TODO(dgozman): migrate each of the following agents to frame once module is ready.
    //agent->registerAgent(InspectorDatabaseAgent::create(view->page()));
    //agent->registerAgent(DeviceOrientationInspectorAgent::create(view->page()));
    //agent->registerAgent(InspectorFileSystemAgent::create(view->page()));
    //agent->registerAgent(InspectorIndexedDBAgent::create(view->page()));
    //agent->registerAgent(InspectorAccessibilityAgent::create(view->page())); // weolar
    agent->registerAgent(InspectorDOMStorageAgent::create(view->page()));
    //agent->registerAgent(InspectorCacheStorageAgent::create());
    agent->layerTreeViewChanged(view->layerTreeView());
    return adoptPtrWillBeNoop(agent);
}

WebDevToolsAgentImpl::WebDevToolsAgentImpl(
    WebLocalFrameImpl* webLocalFrameImpl,
    WebDevToolsAgentClient* client,
    InspectorOverlay* overlay)
    : m_client(client)
    , m_webLocalFrameImpl(webLocalFrameImpl)
    , m_attached(false)
#if ENABLE(ASSERT)
    , m_hasBeenDisposed(false)
#endif
    , m_instrumentingAgents(m_webLocalFrameImpl->frame()->instrumentingAgents())
    , m_injectedScriptManager(InjectedScriptManager::createForPage())
    , m_resourceContentLoader(InspectorResourceContentLoader::create(m_webLocalFrameImpl->frame()))
    , m_state(adoptPtrWillBeNoop(new InspectorCompositeState(this)))
    , m_overlay(overlay)
    , m_cssAgent(nullptr)
    , m_resourceAgent(nullptr)
    , m_layerTreeAgent(nullptr)
    , m_agents(m_instrumentingAgents.get(), m_state.get())
    , m_deferredAgentsInitialized(false)
{
    ASSERT(isMainThread());
    ASSERT(m_webLocalFrameImpl->frame());

    long processId = Platform::current()->getUniqueIdForProcess();
    ASSERT(processId > 0);
    IdentifiersFactory::setProcessId(processId);
    InjectedScriptManager* injectedScriptManager = m_injectedScriptManager.get();

    OwnPtrWillBeRawPtr<InspectorInspectorAgent> inspectorAgentPtr(InspectorInspectorAgent::create(injectedScriptManager));
    m_inspectorAgent = inspectorAgentPtr.get();
    m_agents.append(inspectorAgentPtr.release());

    OwnPtrWillBeRawPtr<InspectorPageAgent> pageAgentPtr(InspectorPageAgent::create(m_webLocalFrameImpl->frame(), m_overlay, m_resourceContentLoader.get()));
    m_pageAgent = pageAgentPtr.get();
    m_agents.append(pageAgentPtr.release());

    OwnPtrWillBeRawPtr<InspectorDOMAgent> domAgentPtr(InspectorDOMAgent::create(m_pageAgent, injectedScriptManager, m_overlay));
    m_domAgent = domAgentPtr.get();
    m_agents.append(domAgentPtr.release());

    OwnPtrWillBeRawPtr<InspectorLayerTreeAgent> layerTreeAgentPtr(InspectorLayerTreeAgent::create(m_pageAgent));
    m_layerTreeAgent = layerTreeAgentPtr.get();
    m_agents.append(layerTreeAgentPtr.release());

    m_agents.append(InspectorTimelineAgent::create());

    ClientMessageLoopAdapter::ensureMainThreadDebuggerCreated(m_client);
    MainThreadDebugger* mainThreadDebugger = MainThreadDebugger::instance();

    OwnPtrWillBeRawPtr<PageRuntimeAgent> pageRuntimeAgentPtr(PageRuntimeAgent::create(injectedScriptManager, this, mainThreadDebugger->debugger(), m_pageAgent));
    m_pageRuntimeAgent = pageRuntimeAgentPtr.get();
    m_agents.append(pageRuntimeAgentPtr.release());

    OwnPtrWillBeRawPtr<PageConsoleAgent> pageConsoleAgentPtr = PageConsoleAgent::create(injectedScriptManager, m_domAgent, m_pageAgent);
    m_pageConsoleAgent = pageConsoleAgentPtr.get();

    OwnPtrWillBeRawPtr<InspectorWorkerAgent> workerAgentPtr = InspectorWorkerAgent::create(pageConsoleAgentPtr.get());

    OwnPtrWillBeRawPtr<InspectorTracingAgent> tracingAgentPtr = InspectorTracingAgent::create(this, workerAgentPtr.get(), m_pageAgent);
    m_tracingAgent = tracingAgentPtr.get();
    m_agents.append(tracingAgentPtr.release());

    m_agents.append(workerAgentPtr.release());
    m_agents.append(pageConsoleAgentPtr.release());

    //m_agents.append(ScreenOrientationInspectorAgent::create(*m_webLocalFrameImpl->frame())); // weolar
>>>>>>> miniblink49
}

WebDevToolsAgentImpl::~WebDevToolsAgentImpl()
{
<<<<<<< HEAD
    DCHECK(!m_client);
=======
    ASSERT(m_hasBeenDisposed);
}

void WebDevToolsAgentImpl::dispose()
{
    // Explicitly dispose of the agent before destructing to ensure
    // same behavior (and correctness) with and without Oilpan.
    if (m_attached)
        Platform::current()->currentThread()->removeTaskObserver(this);
#if ENABLE(ASSERT)
    ASSERT(!m_hasBeenDisposed);
    m_hasBeenDisposed = true;
#endif
}

// static
void WebDevToolsAgentImpl::webViewImplClosed(WebViewImpl* webViewImpl)
{
    ClientMessageLoopAdapter::webViewImplClosed(webViewImpl);
}

// static
void WebDevToolsAgentImpl::webFrameWidgetImplClosed(WebFrameWidgetImpl* webFrameWidgetImpl)
{
    ClientMessageLoopAdapter::webFrameWidgetImplClosed(webFrameWidgetImpl);
>>>>>>> miniblink49
}

DEFINE_TRACE(WebDevToolsAgentImpl)
{
<<<<<<< HEAD
    visitor->trace(m_webLocalFrameImpl);
    visitor->trace(m_instrumentingAgents);
    visitor->trace(m_resourceContentLoader);
    visitor->trace(m_overlay);
    visitor->trace(m_inspectedFrames);
    visitor->trace(m_resourceContainer);
    visitor->trace(m_domAgent);
    visitor->trace(m_pageAgent);
    visitor->trace(m_networkAgent);
    visitor->trace(m_layerTreeAgent);
    visitor->trace(m_tracingAgent);
    visitor->trace(m_session);
=======
    visitor->trace(m_instrumentingAgents);
    visitor->trace(m_injectedScriptManager);
    visitor->trace(m_resourceContentLoader);
    visitor->trace(m_state);
    visitor->trace(m_overlay);
    visitor->trace(m_asyncCallTracker);
    visitor->trace(m_inspectorAgent);
    visitor->trace(m_domAgent);
    visitor->trace(m_pageAgent);
    visitor->trace(m_cssAgent);
    visitor->trace(m_resourceAgent);
    visitor->trace(m_layerTreeAgent);
    visitor->trace(m_tracingAgent);
    visitor->trace(m_pageRuntimeAgent);
    visitor->trace(m_pageConsoleAgent);
    visitor->trace(m_inspectorBackendDispatcher);
    visitor->trace(m_agents);
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::willBeDestroyed()
{
<<<<<<< HEAD
    DCHECK(m_webLocalFrameImpl->frame());
    DCHECK(m_inspectedFrames->root()->view());
    detach();
    m_resourceContentLoader->dispose();
    m_client = nullptr;
}

void WebDevToolsAgentImpl::initializeSession(int sessionId,
    const String& hostId,
    String* state)
{
    DCHECK(m_client);
    ClientMessageLoopAdapter::ensureMainThreadDebuggerCreated(m_client);
    MainThreadDebugger* mainThreadDebugger = MainThreadDebugger::instance();
    v8::Isolate* isolate = V8PerIsolateData::mainThreadIsolate();

    m_session = new InspectorSession(
        this, m_instrumentingAgents.get(), sessionId,
        mainThreadDebugger->v8Inspector(),
        mainThreadDebugger->contextGroupId(m_inspectedFrames->root()), state);

    InspectorDOMAgent* domAgent = new InspectorDOMAgent(isolate, m_inspectedFrames.get(),
        m_session->v8Session(), m_overlay.get());
    m_domAgent = domAgent;
    m_session->append(domAgent);

    InspectorLayerTreeAgent* layerTreeAgent = InspectorLayerTreeAgent::create(m_inspectedFrames.get());
    m_layerTreeAgent = layerTreeAgent;
    m_session->append(layerTreeAgent);

    InspectorNetworkAgent* networkAgent = InspectorNetworkAgent::create(m_inspectedFrames.get());
    m_networkAgent = networkAgent;
    m_session->append(networkAgent);

    InspectorCSSAgent* cssAgent = InspectorCSSAgent::create(
        m_domAgent, m_inspectedFrames.get(), m_networkAgent,
        m_resourceContentLoader.get(), m_resourceContainer.get());
    m_session->append(cssAgent);

    m_session->append(new InspectorAnimationAgent(
        m_inspectedFrames.get(), cssAgent, m_session->v8Session()));

    m_session->append(InspectorMemoryAgent::create());

    m_session->append(
        InspectorApplicationCacheAgent::create(m_inspectedFrames.get()));

    //m_session->append(new InspectorIndexedDBAgent(m_inspectedFrames.get(), m_session->v8Session()));

    InspectorWorkerAgent* workerAgent = new InspectorWorkerAgent(m_inspectedFrames.get());
    m_session->append(workerAgent);

    InspectorTracingAgent* tracingAgent = InspectorTracingAgent::create(this, workerAgent, m_inspectedFrames.get());
    m_tracingAgent = tracingAgent;
    m_session->append(tracingAgent);

    m_session->append(new InspectorDOMDebuggerAgent(isolate, m_domAgent,
        m_session->v8Session()));

    m_session->append(InspectorInputAgent::create(m_inspectedFrames.get()));

    InspectorPageAgent* pageAgent = InspectorPageAgent::create(
        m_inspectedFrames.get(), this, m_resourceContentLoader.get(),
        m_session->v8Session());
    m_pageAgent = pageAgent;
    m_session->append(pageAgent);

    m_session->append(new InspectorLogAgent(
        &m_inspectedFrames->root()->host()->consoleMessageStorage(),
        m_inspectedFrames->root()->performanceMonitor()));

    m_tracingAgent->setLayerTreeId(m_layerTreeId);
    m_networkAgent->setHostId(hostId);

    if (m_includeViewAgents) {
        // TODO(dgozman): we should actually pass the view instead of frame, but
        // during remote->local transition we cannot access mainFrameImpl() yet, so
        // we have to store the frame which will become the main frame later.
        m_session->append(
            InspectorRenderingAgent::create(m_webLocalFrameImpl, m_overlay.get()));
        m_session->append(
            InspectorEmulationAgent::create(m_webLocalFrameImpl, this));
        // TODO(dgozman): migrate each of the following agents to frame once module
        // is ready.
        Page* page = m_webLocalFrameImpl->viewImpl()->page();
//         m_session->append(InspectorDatabaseAgent::create(page));
//         m_session->append(DeviceOrientationInspectorAgent::create(page));
//         m_session->append(new InspectorAccessibilityAgent(page, m_domAgent));
//         m_session->append(InspectorDOMStorageAgent::create(page));
//         m_session->append(InspectorCacheStorageAgent::create());
    }

    if (m_overlay)
        m_overlay->init(m_session->v8Session(), m_domAgent);
=======
#if ENABLE(ASSERT)
    Frame* frame = m_webLocalFrameImpl->frame();
    ASSERT(frame);
    ASSERT(m_pageAgent->inspectedFrame()->view());
#endif

    detach();
    m_injectedScriptManager->disconnect();
    m_resourceContentLoader->stop();
    m_agents.discardAgents();
    m_instrumentingAgents->reset();
}

void WebDevToolsAgentImpl::initializeDeferredAgents()
{
    if (m_deferredAgentsInitialized)
        return;
    m_deferredAgentsInitialized = true;

    InjectedScriptManager* injectedScriptManager = m_injectedScriptManager.get();

    OwnPtrWillBeRawPtr<InspectorResourceAgent> resourceAgentPtr(InspectorResourceAgent::create(m_pageAgent));
    m_resourceAgent = resourceAgentPtr.get();
    m_agents.append(resourceAgentPtr.release());

    OwnPtrWillBeRawPtr<InspectorCSSAgent> cssAgentPtr(InspectorCSSAgent::create(m_domAgent, m_pageAgent, m_resourceAgent, m_resourceContentLoader.get()));
    m_cssAgent = cssAgentPtr.get();
    m_agents.append(cssAgentPtr.release());

    m_agents.append(InspectorAnimationAgent::create(m_pageAgent, m_domAgent));

    m_agents.append(InspectorMemoryAgent::create());

    m_agents.append(InspectorApplicationCacheAgent::create(m_pageAgent));

    OwnPtrWillBeRawPtr<InspectorDebuggerAgent> debuggerAgentPtr(PageDebuggerAgent::create(MainThreadDebugger::instance(), m_pageAgent, injectedScriptManager, m_overlay));
    InspectorDebuggerAgent* debuggerAgent = debuggerAgentPtr.get();
    m_agents.append(debuggerAgentPtr.release());
    m_asyncCallTracker = adoptPtrWillBeNoop(new AsyncCallTracker(debuggerAgent, m_instrumentingAgents.get()));

    m_agents.append(InspectorDOMDebuggerAgent::create(injectedScriptManager, m_domAgent, debuggerAgent));

    m_agents.append(InspectorInputAgent::create(m_pageAgent));

    m_agents.append(InspectorProfilerAgent::create(injectedScriptManager, m_overlay));

    m_agents.append(InspectorHeapProfilerAgent::create(injectedScriptManager));

    m_pageAgent->setDeferredAgents(debuggerAgent, m_cssAgent);
    m_pageConsoleAgent->setDebuggerAgent(debuggerAgent);

    MainThreadDebugger* mainThreadDebugger = MainThreadDebugger::instance();
    m_injectedScriptManager->injectedScriptHost()->init(
        m_pageConsoleAgent.get(),
        debuggerAgent,
        bind<PassRefPtr<TypeBuilder::Runtime::RemoteObject>, PassRefPtr<JSONObject>>(&InspectorInspectorAgent::inspect, m_inspectorAgent.get()),
        mainThreadDebugger->debugger(),
        adoptPtr(new PageInjectedScriptHostClient()));
}

void WebDevToolsAgentImpl::registerAgent(PassOwnPtrWillBeRawPtr<InspectorAgent> agent)
{
    m_agents.append(agent);
}

void WebDevToolsAgentImpl::attach(const WebString& hostId)
{
    if (m_attached)
        return;

    // Set the attached bit first so that sync notifications were delivered.
    m_attached = true;

    initializeDeferredAgents();
    m_resourceAgent->setHostId(hostId);
    m_overlay->setLayoutEditor(LayoutEditor::create(m_cssAgent.get()));

    m_inspectorFrontend = adoptPtr(new InspectorFrontend(this));
    // We can reconnect to existing front-end -> unmute state.
    m_state->unmute();
    m_agents.setFrontend(m_inspectorFrontend.get());

    InspectorInstrumentation::registerInstrumentingAgents(m_instrumentingAgents.get());
    InspectorInstrumentation::frontendCreated();

    m_inspectorBackendDispatcher = InspectorBackendDispatcher::create(this);
    m_agents.registerInDispatcher(m_inspectorBackendDispatcher.get());
>>>>>>> miniblink49

    Platform::current()->currentThread()->addTaskObserver(this);
}

<<<<<<< HEAD
void WebDevToolsAgentImpl::destroySession()
{
    if (m_overlay)
        m_overlay->clear();

    m_tracingAgent.clear();
    m_layerTreeAgent.clear();
    m_networkAgent.clear();
    m_pageAgent.clear();
    m_domAgent.clear();

    m_session->dispose();
    m_session.clear();

    Platform::current()->currentThread()->removeTaskObserver(this);
}

void WebDevToolsAgentImpl::attach(const WebString& hostId, int sessionId)
{
    if (attached())
        return;
    initializeSession(sessionId, hostId, nullptr);
}

void WebDevToolsAgentImpl::reattach(const WebString& hostId,
    int sessionId,
    const WebString& savedState)
{
    if (attached())
        return;
    String state = savedState;
    initializeSession(sessionId, hostId, &state);
    m_session->restore();
=======
void WebDevToolsAgentImpl::reattach(const WebString& hostId, const WebString& savedState)
{
    if (m_attached)
        return;

    attach(hostId);
    m_state->loadFromCookie(savedState);
    m_agents.restore();
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::detach()
{
<<<<<<< HEAD
    if (!attached())
        return;
    destroySession();
=======
    if (!m_attached)
        return;

    Platform::current()->currentThread()->removeTaskObserver(this);

    m_inspectorBackendDispatcher->clearFrontend();
    m_inspectorBackendDispatcher.clear();

    // Destroying agents would change the state, but we don't want that.
    // Pre-disconnect state will be used to restore inspector agents.
    m_state->mute();
    m_agents.clearFrontend();
    m_inspectorFrontend.clear();

    // Release overlay resources.
    m_overlay->clear();
    m_overlay->setLayoutEditor(nullptr);
    InspectorInstrumentation::frontendDeleted();
    InspectorInstrumentation::unregisterInstrumentingAgents(m_instrumentingAgents.get());

    m_attached = false;
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::continueProgram()
{
    ClientMessageLoopAdapter::continueProgram();
}

<<<<<<< HEAD
void WebDevToolsAgentImpl::didCommitLoadForLocalFrame(LocalFrame* frame)
{
    m_resourceContainer->didCommitLoadForLocalFrame(frame);
    m_resourceContentLoader->didCommitLoadForLocalFrame(frame);
    if (m_session)
        m_session->didCommitLoadForLocalFrame(frame);
}

void WebDevToolsAgentImpl::didStartProvisionalLoad(LocalFrame* frame)
{
    if (m_session && m_inspectedFrames->root() == frame)
        m_session->v8Session()->resume();
=======
bool WebDevToolsAgentImpl::handleInputEvent(const WebInputEvent& inputEvent)
{
    if (!m_attached)
        return false;

    if (WebInputEvent::isGestureEventType(inputEvent.type) && inputEvent.type == WebInputEvent::GestureTap) {
        // Only let GestureTab in (we only need it and we know PlatformGestureEventBuilder supports it).
        PlatformGestureEvent gestureEvent = PlatformGestureEventBuilder(m_webLocalFrameImpl->frameView(), static_cast<const WebGestureEvent&>(inputEvent));
        return handleGestureEvent(m_webLocalFrameImpl->frame(), gestureEvent);
    }
    if (WebInputEvent::isMouseEventType(inputEvent.type) && inputEvent.type != WebInputEvent::MouseEnter) {
        // PlatformMouseEventBuilder does not work with MouseEnter type, so we filter it out manually.
        PlatformMouseEvent mouseEvent = PlatformMouseEventBuilder(m_webLocalFrameImpl->frameView(), static_cast<const WebMouseEvent&>(inputEvent));
        return handleMouseEvent(m_webLocalFrameImpl->frame(), mouseEvent);
    }
    if (WebInputEvent::isTouchEventType(inputEvent.type)) {
        PlatformTouchEvent touchEvent = PlatformTouchEventBuilder(m_webLocalFrameImpl->frameView(), static_cast<const WebTouchEvent&>(inputEvent));
        return handleTouchEvent(m_webLocalFrameImpl->frame(), touchEvent);
    }
    return false;
}

bool WebDevToolsAgentImpl::handleGestureEvent(LocalFrame* frame, const PlatformGestureEvent& event)
{
    if (InspectorDOMAgent* domAgent = m_instrumentingAgents->inspectorDOMAgent())
        return domAgent->handleGestureEvent(frame, event);
    return false;
}

bool WebDevToolsAgentImpl::handleMouseEvent(LocalFrame* frame, const PlatformMouseEvent& event)
{
    if (event.type() == PlatformEvent::MouseMoved) {
        if (InspectorDOMAgent* domAgent = m_instrumentingAgents->inspectorDOMAgent())
            return domAgent->handleMouseMove(frame, event);
        return false;
    }
    if (event.type() == PlatformEvent::MousePressed) {
        if (InspectorDOMAgent* domAgent = m_instrumentingAgents->inspectorDOMAgent())
            return domAgent->handleMousePress();
    }
    return false;
}

bool WebDevToolsAgentImpl::handleTouchEvent(LocalFrame* frame, const PlatformTouchEvent& event)
{
    if (InspectorDOMAgent* domAgent = m_instrumentingAgents->inspectorDOMAgent())
        return domAgent->handleTouchEvent(frame, event);
    return false;
}

void WebDevToolsAgentImpl::didCommitLoadForLocalFrame(LocalFrame* frame)
{
    m_resourceContentLoader->didCommitLoadForLocalFrame(frame);
    m_agents.didCommitLoadForLocalFrame(frame);
>>>>>>> miniblink49
}

bool WebDevToolsAgentImpl::screencastEnabled()
{
<<<<<<< HEAD
    return m_pageAgent && m_pageAgent->screencastEnabled();
=======
    return m_pageAgent->screencastEnabled();
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::willAddPageOverlay(const GraphicsLayer* layer)
{
<<<<<<< HEAD
    if (m_layerTreeAgent)
        m_layerTreeAgent->willAddPageOverlay(layer);
=======
    m_layerTreeAgent->willAddPageOverlay(layer);
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::didRemovePageOverlay(const GraphicsLayer* layer)
{
<<<<<<< HEAD
    if (m_layerTreeAgent)
        m_layerTreeAgent->didRemovePageOverlay(layer);
}

void WebDevToolsAgentImpl::rootLayerCleared()
{
    if (m_tracingAgent)
        m_tracingAgent->rootLayerCleared();
}

void WebDevToolsAgentImpl::layerTreeViewChanged(
    WebLayerTreeView* layerTreeView)
{
    m_layerTreeId = layerTreeView ? layerTreeView->layerTreeId() : 0;
    if (m_tracingAgent)
        m_tracingAgent->setLayerTreeId(m_layerTreeId);
=======
    m_layerTreeAgent->didRemovePageOverlay(layer);
}

void WebDevToolsAgentImpl::layerTreeViewChanged(WebLayerTreeView* layerTreeView)
{
    m_tracingAgent->setLayerTreeId(layerTreeView ? layerTreeView->layerTreeId() : 0);
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::enableTracing(const String& categoryFilter)
{
<<<<<<< HEAD
    if (m_client)
        m_client->enableTracing(categoryFilter);
=======
    m_client->enableTracing(categoryFilter);
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::disableTracing()
{
<<<<<<< HEAD
    if (m_client)
        m_client->disableTracing();
}

void WebDevToolsAgentImpl::showReloadingBlanket()
{
    if (m_overlay)
        m_overlay->showReloadingBlanket();
}

void WebDevToolsAgentImpl::hideReloadingBlanket()
{
    if (m_overlay)
        m_overlay->hideReloadingBlanket();
}

void WebDevToolsAgentImpl::setCPUThrottlingRate(double rate)
{
    if (m_client)
        m_client->setCPUThrottlingRate(rate);
}

void WebDevToolsAgentImpl::dispatchOnInspectorBackend(
    int sessionId,
    int callId,
    const WebString& method,
    const WebString& message)
{
    if (!attached())
        return;
    if (WebDevToolsAgent::shouldInterruptForMethod(method))
        MainThreadDebugger::instance()->taskRunner()->runAllTasksDontWait();
    else
        dispatchMessageFromFrontend(sessionId, method, message);
}

void WebDevToolsAgentImpl::dispatchMessageFromFrontend(int sessionId,
    const String& method,
    const String& message)
{
    if (!attached() || sessionId != m_session->sessionId())
        return;
    InspectorTaskRunner::IgnoreInterruptsScope scope(
        MainThreadDebugger::instance()->taskRunner());
    m_session->dispatchProtocolMessage(method, message);
}

void WebDevToolsAgentImpl::inspectElementAt(int sessionId,
    const WebPoint& pointInRootFrame)
{
    if (!m_domAgent || !m_session || m_session->sessionId() != sessionId)
        return;
    HitTestRequest::HitTestRequestType hitType = HitTestRequest::Move | HitTestRequest::ReadOnly | HitTestRequest::AllowChildFrameContent;
    HitTestRequest request(hitType);
    WebMouseEvent dummyEvent(WebInputEvent::MouseDown, WebInputEvent::NoModifiers,
        WTF::monotonicallyIncreasingTimeMS());
    dummyEvent.x = pointInRootFrame.x;
    dummyEvent.y = pointInRootFrame.y;
    IntPoint transformedPoint = PlatformMouseEventBuilder(m_webLocalFrameImpl->frameView(), dummyEvent)
                                    .position();
    HitTestResult result(
        request,
        m_webLocalFrameImpl->frameView()->rootFrameToContents(transformedPoint));
    m_webLocalFrameImpl->frame()->contentLayoutItem().hitTest(result);
=======
    m_client->disableTracing();
}

void WebDevToolsAgentImpl::dispatchOnInspectorBackend(const WebString& message)
{
    if (!m_attached)
        return;
    if (WebDevToolsAgent::shouldInterruptForMessage(message))
        MainThreadDebugger::instance()->taskRunner()->runPendingTasks();
    else
        dispatchMessageFromFrontend(message);
}

void WebDevToolsAgentImpl::dispatchMessageFromFrontend(const String& message)
{
    InspectorTaskRunner::IgnoreInterruptsScope scope(MainThreadDebugger::instance()->taskRunner());
    if (m_inspectorBackendDispatcher)
        m_inspectorBackendDispatcher->dispatch(message);
}

void WebDevToolsAgentImpl::inspectElementAt(const WebPoint& pointInRootFrame)
{
    HitTestRequest::HitTestRequestType hitType = HitTestRequest::Move | HitTestRequest::ReadOnly | HitTestRequest::AllowChildFrameContent;
    HitTestRequest request(hitType);
    WebMouseEvent dummyEvent;
    dummyEvent.type = WebInputEvent::MouseDown;
    dummyEvent.x = pointInRootFrame.x;
    dummyEvent.y = pointInRootFrame.y;
    IntPoint transformedPoint = PlatformMouseEventBuilder(m_webLocalFrameImpl->frameView(), dummyEvent).position();
    HitTestResult result(request, m_webLocalFrameImpl->frameView()->rootFrameToContents(transformedPoint));
    m_webLocalFrameImpl->frame()->contentLayoutObject()->hitTest(result);
>>>>>>> miniblink49
    Node* node = result.innerNode();
    if (!node && m_webLocalFrameImpl->frame()->document())
        node = m_webLocalFrameImpl->frame()->document()->documentElement();
    m_domAgent->inspect(node);
}

<<<<<<< HEAD
void WebDevToolsAgentImpl::failedToRequestDevTools()
{
    ClientMessageLoopAdapter::resumeForCreateWindow();
}

void WebDevToolsAgentImpl::sendProtocolMessage(int sessionId,
    int callId,
    const String& response,
    const String& state)
{
    ASSERT(attached());
    if (m_client)
        m_client->sendProtocolMessage(sessionId, callId, response, state);
}

void WebDevToolsAgentImpl::pageLayoutInvalidated(bool resized)
{
    if (m_overlay)
        m_overlay->pageLayoutInvalidated(resized);
}

void WebDevToolsAgentImpl::configureOverlay(bool suspended,
    const String& message)
{
    if (!m_overlay)
        return;
    m_overlay->setPausedInDebuggerMessage(message);
    if (suspended)
        m_overlay->suspend();
    else
        m_overlay->resume();
}

void WebDevToolsAgentImpl::waitForCreateWindow(LocalFrame* frame)
{
    if (!attached())
        return;
    if (m_client && m_client->requestDevToolsForFrame(WebLocalFrameImpl::fromFrame(frame)))
        ClientMessageLoopAdapter::pauseForCreateWindow(m_webLocalFrameImpl);
}

WebString WebDevToolsAgentImpl::evaluateInWebInspectorOverlay(
    const WebString& script)
{
    if (!m_overlay)
        return WebString();

    return m_overlay->evaluateInOverlayForTest(script);
}

bool WebDevToolsAgentImpl::cacheDisabled()
{
    if (!m_networkAgent)
        return false;
    return m_networkAgent->cacheDisabled();
}

void WebDevToolsAgentImpl::flushProtocolNotifications()
{
    if (m_session)
        m_session->flushProtocolNotifications();
=======
void WebDevToolsAgentImpl::sendProtocolResponse(int callId, PassRefPtr<JSONObject> message)
{
    if (!m_attached)
        return;
    flushPendingProtocolNotifications();
    m_client->sendProtocolMessage(callId, message->toJSONString(), m_stateCookie);
    m_stateCookie = String();
}

void WebDevToolsAgentImpl::sendProtocolNotification(PassRefPtr<JSONObject> message)
{
    if (!m_attached)
        return;
    m_notificationQueue.append(message);
}

void WebDevToolsAgentImpl::flush()
{
    flushPendingProtocolNotifications();
}

void WebDevToolsAgentImpl::updateInspectorStateCookie(const String& state)
{
    m_stateCookie = state;
}

void WebDevToolsAgentImpl::resumeStartup()
{
    m_client->resumeStartup();
}

void WebDevToolsAgentImpl::evaluateInWebInspector(long callId, const WebString& script)
{
    m_inspectorAgent->evaluateForTestInFrontend(callId, script);
}

void WebDevToolsAgentImpl::flushPendingProtocolNotifications()
{
    if (!m_attached)
        return;

    m_agents.flushPendingProtocolNotifications();
    for (size_t i = 0; i < m_notificationQueue.size(); ++i)
        m_client->sendProtocolMessage(0, m_notificationQueue[i]->toJSONString(), WebString());
    m_notificationQueue.clear();
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::willProcessTask()
{
<<<<<<< HEAD
    if (!attached())
        return;
    ThreadDebugger::idleFinished(V8PerIsolateData::mainThreadIsolate());
=======
    if (!m_attached)
        return;
    if (InspectorProfilerAgent* profilerAgent = m_instrumentingAgents->inspectorProfilerAgent())
        profilerAgent->willProcessTask();
>>>>>>> miniblink49
}

void WebDevToolsAgentImpl::didProcessTask()
{
<<<<<<< HEAD
    if (!attached())
        return;
    ThreadDebugger::idleStarted(V8PerIsolateData::mainThreadIsolate());
    flushProtocolNotifications();
}

void WebDevToolsAgentImpl::runDebuggerTask(
    int sessionId,
    std::unique_ptr<WebDevToolsAgent::MessageDescriptor> descriptor)
{
    WebDevToolsAgent* webagent = descriptor->agent();
    if (!webagent)
        return;

    WebDevToolsAgentImpl* agentImpl = static_cast<WebDevToolsAgentImpl*>(webagent);
    if (agentImpl->attached())
        agentImpl->dispatchMessageFromFrontend(sessionId, descriptor->method(),
            descriptor->message());
}

void WebDevToolsAgent::interruptAndDispatch(int sessionId,
    MessageDescriptor* rawDescriptor)
{
    // rawDescriptor can't be a std::unique_ptr because interruptAndDispatch is a
    // WebKit API function.
    MainThreadDebugger::interruptMainThreadAndRun(
        crossThreadBind(WebDevToolsAgentImpl::runDebuggerTask, sessionId,
            WTF::passed(WTF::wrapUnique(rawDescriptor))));
}

bool WebDevToolsAgent::shouldInterruptForMethod(const WebString& method)
{
    return method == "Debugger.pause" || method == "Debugger.setBreakpoint" || method == "Debugger.setBreakpointByUrl" || method == "Debugger.removeBreakpoint" || method == "Debugger.setBreakpointsActive";
=======
    if (!m_attached)
        return;
    if (InspectorProfilerAgent* profilerAgent = m_instrumentingAgents->inspectorProfilerAgent())
        profilerAgent->didProcessTask();
    flushPendingProtocolNotifications();
}

void WebDevToolsAgent::interruptAndDispatch(MessageDescriptor* rawDescriptor)
{
    // rawDescriptor can't be a PassOwnPtr because interruptAndDispatch is a WebKit API function.
    OwnPtr<MessageDescriptor> descriptor = adoptPtr(rawDescriptor);
    OwnPtr<DebuggerTask> task = adoptPtr(new DebuggerTask(descriptor.release()));
    MainThreadDebugger::interruptMainThreadAndRun(task.release());
}

bool WebDevToolsAgent::shouldInterruptForMessage(const WebString& message)
{
    String commandName;
    if (!InspectorBackendDispatcher::getCommandName(message, &commandName))
        return false;
    return commandName == InspectorBackendDispatcher::commandName(InspectorBackendDispatcher::kDebugger_pauseCmd)
        || commandName == InspectorBackendDispatcher::commandName(InspectorBackendDispatcher::kDebugger_setBreakpointCmd)
        || commandName == InspectorBackendDispatcher::commandName(InspectorBackendDispatcher::kDebugger_setBreakpointByUrlCmd)
        || commandName == InspectorBackendDispatcher::commandName(InspectorBackendDispatcher::kDebugger_removeBreakpointCmd)
        || commandName == InspectorBackendDispatcher::commandName(InspectorBackendDispatcher::kDebugger_setBreakpointsActiveCmd);
>>>>>>> miniblink49
}

} // namespace blink

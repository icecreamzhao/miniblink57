/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
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
#include "web/WebEmbeddedWorkerImpl.h"

#include "bindings/core/v8/SourceLocation.h"
#include "core/dom/Document.h"
#include "core/dom/ExecutionContextTask.h"
#include "core/dom/SecurityContext.h"
#include "core/fetch/SubstituteData.h"
#include "core/frame/csp/ContentSecurityPolicy.h"
#include "core/inspector/ConsoleMessage.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/loader/FrameLoadRequest.h"
#include "core/workers/ParentFrameTaskRunners.h"
=======
#include "config.h"
#include "web/WebEmbeddedWorkerImpl.h"

#include "core/dom/CrossThreadTask.h"
#include "core/dom/Document.h"
#include "core/fetch/SubstituteData.h"
#include "core/frame/csp/ContentSecurityPolicy.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/inspector/WorkerDebuggerAgent.h"
#include "core/inspector/WorkerInspectorController.h"
#include "core/loader/FrameLoadRequest.h"
>>>>>>> miniblink49
#include "core/workers/WorkerClients.h"
#include "core/workers/WorkerGlobalScope.h"
#include "core/workers/WorkerInspectorProxy.h"
#include "core/workers/WorkerLoaderProxy.h"
#include "core/workers/WorkerScriptLoader.h"
#include "core/workers/WorkerThreadStartupData.h"
#include "modules/serviceworkers/ServiceWorkerContainerClient.h"
#include "modules/serviceworkers/ServiceWorkerThread.h"
<<<<<<< HEAD
#include "platform/Histogram.h"
=======
>>>>>>> miniblink49
#include "platform/SharedBuffer.h"
#include "platform/heap/Handle.h"
#include "platform/network/ContentSecurityPolicyParsers.h"
#include "platform/network/ContentSecurityPolicyResponseHeaders.h"
<<<<<<< HEAD
#include "platform/network/NetworkUtils.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
#include "public/platform/WebURLRequest.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerProvider.h"
#include "public/web/WebConsoleMessage.h"
#include "public/web/WebDevToolsAgent.h"
#include "public/web/WebSettings.h"
#include "public/web/WebView.h"
#include "public/web/WebWorkerContentSettingsClientProxy.h"
#include "public/web/modules/serviceworker/WebServiceWorkerContextClient.h"
#include "public/web/modules/serviceworker/WebServiceWorkerNetworkProvider.h"
#include "web/IndexedDBClientImpl.h"
=======
#include "public/platform/Platform.h"
#include "public/platform/WebServiceWorkerProvider.h"
#include "public/platform/WebURLRequest.h"
#include "public/web/WebDevToolsAgent.h"
#include "public/web/WebServiceWorkerContextClient.h"
#include "public/web/WebServiceWorkerNetworkProvider.h"
#include "public/web/WebSettings.h"
#include "public/web/WebView.h"
#include "public/web/WebWorkerContentSettingsClientProxy.h"
>>>>>>> miniblink49
#include "web/ServiceWorkerGlobalScopeClientImpl.h"
#include "web/ServiceWorkerGlobalScopeProxy.h"
#include "web/WebDataSourceImpl.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WorkerContentSettingsClient.h"
#include "wtf/Functional.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

WebEmbeddedWorker* WebEmbeddedWorker::create(
    WebServiceWorkerContextClient* client,
    WebWorkerContentSettingsClientProxy* contentSettingsClient)
{
    return new WebEmbeddedWorkerImpl(WTF::wrapUnique(client),
        WTF::wrapUnique(contentSettingsClient));
=======

namespace blink {

WebEmbeddedWorker* WebEmbeddedWorker::create(WebServiceWorkerContextClient* client, WebWorkerContentSettingsClientProxy* contentSettingsClient)
{
    return new WebEmbeddedWorkerImpl(adoptPtr(client), adoptPtr(contentSettingsClient));
>>>>>>> miniblink49
}

static HashSet<WebEmbeddedWorkerImpl*>& runningWorkerInstances()
{
    DEFINE_STATIC_LOCAL(HashSet<WebEmbeddedWorkerImpl*>, set, ());
    return set;
}

<<<<<<< HEAD
WebEmbeddedWorkerImpl::WebEmbeddedWorkerImpl(
    std::unique_ptr<WebServiceWorkerContextClient> client,
    std::unique_ptr<WebWorkerContentSettingsClientProxy> contentSettingsClient)
    : m_workerContextClient(std::move(client))
    , m_contentSettingsClient(std::move(contentSettingsClient))
    , m_workerInspectorProxy(WorkerInspectorProxy::create())
    , m_webView(nullptr)
    , m_mainFrame(nullptr)
=======
WebEmbeddedWorkerImpl::WebEmbeddedWorkerImpl(PassOwnPtr<WebServiceWorkerContextClient> client, PassOwnPtr<WebWorkerContentSettingsClientProxy> ContentSettingsClient)
    : m_workerContextClient(client)
    , m_contentSettingsClient(ContentSettingsClient)
    , m_workerInspectorProxy(WorkerInspectorProxy::create())
    , m_webView(0)
    , m_mainFrame(0)
>>>>>>> miniblink49
    , m_loadingShadowPage(false)
    , m_askedToTerminate(false)
    , m_pauseAfterDownloadState(DontPauseAfterDownload)
    , m_waitingForDebuggerState(NotWaitingForDebugger)
{
    runningWorkerInstances().add(this);
}

WebEmbeddedWorkerImpl::~WebEmbeddedWorkerImpl()
{
    // Prevent onScriptLoaderFinished from deleting 'this'.
    m_askedToTerminate = true;

    if (m_workerThread)
        m_workerThread->terminateAndWait();

<<<<<<< HEAD
    DCHECK(runningWorkerInstances().contains(this));
    runningWorkerInstances().remove(this);
    DCHECK(m_webView);
=======
    ASSERT(runningWorkerInstances().contains(this));
    runningWorkerInstances().remove(this);
    ASSERT(m_webView);
>>>>>>> miniblink49

    // Detach the client before closing the view to avoid getting called back.
    m_mainFrame->setClient(0);

<<<<<<< HEAD
    if (m_workerGlobalScopeProxy) {
        m_workerGlobalScopeProxy->detach();
        m_workerGlobalScopeProxy.clear();
    }

=======
>>>>>>> miniblink49
    m_webView->close();
    m_mainFrame->close();
    if (m_loaderProxy)
        m_loaderProxy->detachProvider(this);
}

<<<<<<< HEAD
void WebEmbeddedWorkerImpl::startWorkerContext(
    const WebEmbeddedWorkerStartData& data)
{
    DCHECK(!m_askedToTerminate);
    DCHECK(!m_mainScriptLoader);
    DCHECK_EQ(m_pauseAfterDownloadState, DontPauseAfterDownload);
    m_workerStartData = data;

    // TODO(mkwst): This really needs to be piped through from the requesting
    // document, like we're doing for SharedWorkers. That turns out to be
    // incredibly convoluted, and since ServiceWorkers are locked to the same
    // origin as the page which requested them, the only time it would come
    // into play is a DNS poisoning attack after the page load. It's something
    // we should fix, but we're taking this shortcut for the prototype.
    //
    // https://crbug.com/590714
    KURL scriptURL = m_workerStartData.scriptURL;
    m_workerStartData.addressSpace = WebAddressSpacePublic;
    if (NetworkUtils::isReservedIPAddress(scriptURL.host()))
        m_workerStartData.addressSpace = WebAddressSpacePrivate;
    if (SecurityOrigin::create(scriptURL)->isLocalhost())
        m_workerStartData.addressSpace = WebAddressSpaceLocal;

=======
void WebEmbeddedWorkerImpl::terminateAll()
{
    HashSet<WebEmbeddedWorkerImpl*> instances = runningWorkerInstances();
    for (HashSet<WebEmbeddedWorkerImpl*>::iterator it = instances.begin(), itEnd = instances.end(); it != itEnd; ++it) {
        (*it)->terminateWorkerContext();
    }
}

void WebEmbeddedWorkerImpl::startWorkerContext(
    const WebEmbeddedWorkerStartData& data)
{
    ASSERT(!m_askedToTerminate);
    ASSERT(!m_mainScriptLoader);
    ASSERT(m_pauseAfterDownloadState == DontPauseAfterDownload);
    m_workerStartData = data;
>>>>>>> miniblink49
    if (data.pauseAfterDownloadMode == WebEmbeddedWorkerStartData::PauseAfterDownload)
        m_pauseAfterDownloadState = DoPauseAfterDownload;
    prepareShadowPageForLoader();
}

void WebEmbeddedWorkerImpl::terminateWorkerContext()
{
    if (m_askedToTerminate)
        return;
    m_askedToTerminate = true;
    if (m_loadingShadowPage) {
        // This deletes 'this'.
        m_workerContextClient->workerContextFailedToStart();
        return;
    }
    if (m_mainScriptLoader) {
        m_mainScriptLoader->cancel();
        m_mainScriptLoader.clear();
        // This deletes 'this'.
        m_workerContextClient->workerContextFailedToStart();
        return;
    }
<<<<<<< HEAD
    if (!m_workerThread) {
        // The worker thread has not been created yet if the worker is asked to
        // terminate during waiting for debugger or paused after download.
        DCHECK(m_workerStartData.waitForDebuggerMode == WebEmbeddedWorkerStartData::WaitForDebugger || m_pauseAfterDownloadState == IsPausedAfterDownload);
=======
    if (m_pauseAfterDownloadState == IsPausedAfterDownload) {
>>>>>>> miniblink49
        // This deletes 'this'.
        m_workerContextClient->workerContextFailedToStart();
        return;
    }
<<<<<<< HEAD
    m_workerThread->terminate();
=======
    if (m_workerThread)
        m_workerThread->terminate();
>>>>>>> miniblink49
    m_workerInspectorProxy->workerThreadTerminated();
}

void WebEmbeddedWorkerImpl::resumeAfterDownload()
{
<<<<<<< HEAD
    DCHECK(!m_askedToTerminate);
    DCHECK_EQ(m_pauseAfterDownloadState, IsPausedAfterDownload);

    m_pauseAfterDownloadState = DontPauseAfterDownload;
    startWorkerThread();
}

void WebEmbeddedWorkerImpl::attachDevTools(const WebString& hostId,
    int sessionId)
{
    WebDevToolsAgent* devtoolsAgent = m_mainFrame->devToolsAgent();
    if (devtoolsAgent)
        devtoolsAgent->attach(hostId, sessionId);
}

void WebEmbeddedWorkerImpl::reattachDevTools(const WebString& hostId,
    int sessionId,
    const WebString& savedState)
{
    WebDevToolsAgent* devtoolsAgent = m_mainFrame->devToolsAgent();
    if (devtoolsAgent)
        devtoolsAgent->reattach(hostId, sessionId, savedState);
=======
    ASSERT(!m_askedToTerminate);
    bool wasPaused = (m_pauseAfterDownloadState == IsPausedAfterDownload);
    m_pauseAfterDownloadState = DontPauseAfterDownload;

    // If we were asked to wait for debugger while updating service worker version then it is good time now.
    m_workerContextClient->workerReadyForInspection();
    if (m_workerStartData.waitForDebuggerMode == WebEmbeddedWorkerStartData::WaitForDebugger)
        m_waitingForDebuggerState = WaitingForDebuggerAfterScriptLoaded;
    else if (wasPaused)
        startWorkerThread();
}

void WebEmbeddedWorkerImpl::attachDevTools(const WebString& hostId)
{
    WebDevToolsAgent* devtoolsAgent = m_mainFrame->devToolsAgent();
    if (devtoolsAgent)
        devtoolsAgent->attach(hostId);
}

void WebEmbeddedWorkerImpl::reattachDevTools(const WebString& hostId, const WebString& savedState)
{
    WebDevToolsAgent* devtoolsAgent = m_mainFrame->devToolsAgent();
    if (devtoolsAgent)
        devtoolsAgent->reattach(hostId, savedState);
>>>>>>> miniblink49
    resumeStartup();
}

void WebEmbeddedWorkerImpl::detachDevTools()
{
    WebDevToolsAgent* devtoolsAgent = m_mainFrame->devToolsAgent();
    if (devtoolsAgent)
        devtoolsAgent->detach();
}

<<<<<<< HEAD
void WebEmbeddedWorkerImpl::dispatchDevToolsMessage(int sessionId,
    int callId,
    const WebString& method,
    const WebString& message)
=======
void WebEmbeddedWorkerImpl::dispatchDevToolsMessage(const WebString& message)
>>>>>>> miniblink49
{
    if (m_askedToTerminate)
        return;
    WebDevToolsAgent* devtoolsAgent = m_mainFrame->devToolsAgent();
    if (devtoolsAgent)
<<<<<<< HEAD
        devtoolsAgent->dispatchOnInspectorBackend(sessionId, callId, method,
            message);
}

void WebEmbeddedWorkerImpl::addMessageToConsole(
    const WebConsoleMessage& message)
{
    MessageLevel webCoreMessageLevel;
    switch (message.level) {
    case WebConsoleMessage::LevelDebug:
        webCoreMessageLevel = DebugMessageLevel;
        break;
    case WebConsoleMessage::LevelLog:
        webCoreMessageLevel = LogMessageLevel;
        break;
    case WebConsoleMessage::LevelWarning:
        webCoreMessageLevel = WarningMessageLevel;
        break;
    case WebConsoleMessage::LevelError:
        webCoreMessageLevel = ErrorMessageLevel;
        break;
    default:
        NOTREACHED();
        return;
    }

    m_mainFrame->frame()->document()->addConsoleMessage(ConsoleMessage::create(
        OtherMessageSource, webCoreMessageLevel, message.text,
        SourceLocation::create(message.url, message.lineNumber,
            message.columnNumber, nullptr)));
=======
        devtoolsAgent->dispatchOnInspectorBackend(message);
>>>>>>> miniblink49
}

void WebEmbeddedWorkerImpl::postMessageToPageInspector(const String& message)
{
<<<<<<< HEAD
    m_workerInspectorProxy->dispatchMessageFromWorker(message);
}

void WebEmbeddedWorkerImpl::postTaskToLoader(
    const WebTraceLocation& location,
    std::unique_ptr<ExecutionContextTask> task)
{
    m_mainThreadTaskRunners->get(TaskType::Networking)
        ->postTask(
            BLINK_FROM_HERE,
            crossThreadBind(
                &ExecutionContextTask::performTaskIfContextIsValid,
                WTF::passed(std::move(task)),
                wrapCrossThreadWeakPersistent(m_mainFrame->frame()->document())));
}

void WebEmbeddedWorkerImpl::postTaskToWorkerGlobalScope(
    const WebTraceLocation& location,
    std::unique_ptr<WTF::CrossThreadClosure> task)
{
    if (m_askedToTerminate || !m_workerThread)
        return;
    m_workerThread->postTask(location, std::move(task));
=======
    WorkerInspectorProxy::PageInspector* pageInspector = m_workerInspectorProxy->pageInspector();
    if (!pageInspector)
        return;
    pageInspector->dispatchMessageFromWorker(message);
}

void WebEmbeddedWorkerImpl::postTaskToLoader(PassOwnPtr<ExecutionContextTask> task)
{
    m_mainFrame->frame()->document()->postTask(FROM_HERE, task);
}

bool WebEmbeddedWorkerImpl::postTaskToWorkerGlobalScope(PassOwnPtr<ExecutionContextTask> task)
{
    if (m_askedToTerminate || !m_workerThread)
        return false;

    m_workerThread->postTask(FROM_HERE, task);
    return !m_workerThread->terminated();
>>>>>>> miniblink49
}

void WebEmbeddedWorkerImpl::prepareShadowPageForLoader()
{
    // Create 'shadow page', which is never displayed and is used mainly to
    // provide a context for loading on the main thread.
    //
    // FIXME: This does mostly same as WebSharedWorkerImpl::initializeLoader.
    // This code, and probably most of the code in this class should be shared
    // with SharedWorker.
<<<<<<< HEAD
    DCHECK(!m_webView);
    m_webView = WebView::create(nullptr, WebPageVisibilityStateVisible);
=======
    ASSERT(!m_webView);
    m_webView = WebView::create(0);
>>>>>>> miniblink49
    WebSettings* settings = m_webView->settings();
    // FIXME: http://crbug.com/363843. This needs to find a better way to
    // not create graphics layers.
    settings->setAcceleratedCompositingEnabled(false);
    // Currently we block all mixed-content requests from a ServiceWorker.
    // FIXME: When we support FetchEvent.default(), we should relax this
    // restriction.
    settings->setStrictMixedContentChecking(true);
<<<<<<< HEAD
    settings->setAllowRunningOfInsecureContent(false);
    settings->setDataSaverEnabled(m_workerStartData.dataSaverEnabled);
    m_mainFrame = toWebLocalFrameImpl(
        WebLocalFrame::create(WebTreeScopeType::Document, this));
    m_webView->setMainFrame(m_mainFrame.get());
    m_mainFrame->setDevToolsAgentClient(this);

    // If we were asked to wait for debugger then it is the good time to do that.
    m_workerContextClient->workerReadyForInspection();
    if (m_workerStartData.waitForDebuggerMode == WebEmbeddedWorkerStartData::WaitForDebugger) {
        m_waitingForDebuggerState = WaitingForDebugger;
        return;
=======
    settings->setAllowDisplayOfInsecureContent(false);
    settings->setAllowRunningOfInsecureContent(false);
    m_mainFrame = toWebLocalFrameImpl(WebLocalFrame::create(WebTreeScopeType::Document, this));
    m_webView->setMainFrame(m_mainFrame);
    m_mainFrame->setDevToolsAgentClient(this);

    // If we were asked to wait for debugger then it is the good time to do that.
    // However if we are updating service worker version (m_pauseAfterDownloadState is set)
    // Then we need to load the worker script to check the version, so in this case we wait for debugger
    // later in ::resumeAfterDownload().
    if (m_pauseAfterDownloadState != DoPauseAfterDownload) {
        m_workerContextClient->workerReadyForInspection();
        if (m_workerStartData.waitForDebuggerMode == WebEmbeddedWorkerStartData::WaitForDebugger) {
            m_waitingForDebuggerState = WaitingForDebuggerBeforeLoadingScript;
            return;
        }
>>>>>>> miniblink49
    }

    loadShadowPage();
}

void WebEmbeddedWorkerImpl::loadShadowPage()
{
    // Construct substitute data source for the 'shadow page'. We only need it
    // to have same origin as the worker so the loading checks work correctly.
    CString content("");
<<<<<<< HEAD
    RefPtr<SharedBuffer> buffer(
        SharedBuffer::create(content.data(), content.length()));
    m_loadingShadowPage = true;
    m_mainFrame->frame()->loader().load(
        FrameLoadRequest(0, ResourceRequest(m_workerStartData.scriptURL),
            SubstituteData(buffer, "text/html", "UTF-8", KURL())));
}

void WebEmbeddedWorkerImpl::willSendRequest(WebLocalFrame* frame,
    WebURLRequest& request)
=======
    int length = static_cast<int>(content.length());
    RefPtr<SharedBuffer> buffer(SharedBuffer::create(content.data(), length));
    m_loadingShadowPage = true;
    m_mainFrame->frame()->loader().load(FrameLoadRequest(0, ResourceRequest(m_workerStartData.scriptURL), SubstituteData(buffer, "text/html", "UTF-8", KURL())));
}

void WebEmbeddedWorkerImpl::willSendRequest(
    WebLocalFrame* frame, unsigned, WebURLRequest& request,
    const WebURLResponse& redirectResponse)
>>>>>>> miniblink49
{
    if (m_networkProvider)
        m_networkProvider->willSendRequest(frame->dataSource(), request);
}

void WebEmbeddedWorkerImpl::didFinishDocumentLoad(WebLocalFrame* frame)
{
<<<<<<< HEAD
    DCHECK(!m_mainScriptLoader);
    DCHECK(!m_networkProvider);
    DCHECK(m_mainFrame);
    DCHECK(m_workerContextClient);
    DCHECK(m_loadingShadowPage);
    DCHECK(!m_askedToTerminate);
    m_loadingShadowPage = false;
    m_networkProvider = WTF::wrapUnique(m_workerContextClient->createServiceWorkerNetworkProvider(
        frame->dataSource()));
    m_mainScriptLoader = WorkerScriptLoader::create();
    m_mainScriptLoader->setRequestContext(
        WebURLRequest::RequestContextServiceWorker);
    m_mainScriptLoader->loadAsynchronously(
        *m_mainFrame->frame()->document(), m_workerStartData.scriptURL,
        DenyCrossOriginRequests, m_workerStartData.addressSpace, nullptr,
        bind(&WebEmbeddedWorkerImpl::onScriptLoaderFinished,
            WTF::unretained(this)));
=======
    ASSERT(!m_mainScriptLoader);
    ASSERT(!m_networkProvider);
    ASSERT(m_mainFrame);
    ASSERT(m_workerContextClient);
    ASSERT(m_loadingShadowPage);
    ASSERT(!m_askedToTerminate);
    m_loadingShadowPage = false;
    m_networkProvider = adoptPtr(m_workerContextClient->createServiceWorkerNetworkProvider(frame->dataSource()));
    m_mainScriptLoader = adoptPtr(new WorkerScriptLoader());
    m_mainScriptLoader->setRequestContext(WebURLRequest::RequestContextServiceWorker);
    m_mainScriptLoader->loadAsynchronously(
        *m_mainFrame->frame()->document(),
        m_workerStartData.scriptURL,
        DenyCrossOriginRequests,
        nullptr,
        bind(&WebEmbeddedWorkerImpl::onScriptLoaderFinished, this));
>>>>>>> miniblink49
    // Do nothing here since onScriptLoaderFinished() might have been already
    // invoked and |this| might have been deleted at this point.
}

<<<<<<< HEAD
void WebEmbeddedWorkerImpl::sendProtocolMessage(int sessionId,
    int callId,
    const WebString& message,
    const WebString& state)
{
    m_workerContextClient->sendDevToolsMessage(sessionId, callId, message, state);
=======
void WebEmbeddedWorkerImpl::sendProtocolMessage(int callId, const WebString& message, const WebString& state)
{
    m_workerContextClient->sendDevToolsMessage(callId, message, state);
>>>>>>> miniblink49
}

void WebEmbeddedWorkerImpl::resumeStartup()
{
<<<<<<< HEAD
    bool wasWaiting = (m_waitingForDebuggerState == WaitingForDebugger);
    m_waitingForDebuggerState = NotWaitingForDebugger;
    if (wasWaiting)
        loadShadowPage();
}

WebDevToolsAgentClient::WebKitClientMessageLoop*
WebEmbeddedWorkerImpl::createClientMessageLoop()
{
    return m_workerContextClient->createDevToolsMessageLoop();
=======
    WaitingForDebuggerState waitingForDebuggerState = m_waitingForDebuggerState;
    m_waitingForDebuggerState = NotWaitingForDebugger;
    if (waitingForDebuggerState == WaitingForDebuggerBeforeLoadingScript)
        loadShadowPage();
    else if (waitingForDebuggerState == WaitingForDebuggerAfterScriptLoaded)
        startWorkerThread();
>>>>>>> miniblink49
}

void WebEmbeddedWorkerImpl::onScriptLoaderFinished()
{
<<<<<<< HEAD
    DCHECK(m_mainScriptLoader);
    if (m_askedToTerminate)
        return;

    // The browser is expected to associate a registration and then load the
    // script. If there's no associated registration, the browser could not
    // successfully handle the SetHostedVersionID IPC, and the script load came
    // through the normal network stack rather than through service worker
    // loading code.
    if (!m_workerContextClient->hasAssociatedRegistration() || m_mainScriptLoader->failed()) {
=======
    ASSERT(m_mainScriptLoader);

    if (m_askedToTerminate)
        return;

    if (m_mainScriptLoader->failed()) {
>>>>>>> miniblink49
        m_mainScriptLoader.clear();
        // This deletes 'this'.
        m_workerContextClient->workerContextFailedToStart();
        return;
    }
<<<<<<< HEAD
    m_workerContextClient->workerScriptLoaded();

    DEFINE_STATIC_LOCAL(CustomCountHistogram, scriptSizeHistogram,
        ("ServiceWorker.ScriptSize", 1000, 5000000, 50));
    scriptSizeHistogram.count(m_mainScriptLoader->script().length());
    if (m_mainScriptLoader->cachedMetadata()) {
        DEFINE_STATIC_LOCAL(
            CustomCountHistogram, scriptCachedMetadataSizeHistogram,
            ("ServiceWorker.ScriptCachedMetadataSize", 1000, 50000000, 50));
        scriptCachedMetadataSizeHistogram.count(
            m_mainScriptLoader->cachedMetadata()->size());
    }

    if (m_pauseAfterDownloadState == DoPauseAfterDownload) {
        m_pauseAfterDownloadState = IsPausedAfterDownload;
=======

    Platform::current()->histogramCustomCounts("ServiceWorker.ScriptSize", m_mainScriptLoader->script().length(), 1000, 5000000, 50);
    if (m_mainScriptLoader->cachedMetadata())
        Platform::current()->histogramCustomCounts("ServiceWorker.ScriptCachedMetadataSize", m_mainScriptLoader->cachedMetadata()->size(), 1000, 50000000, 50);

    if (m_pauseAfterDownloadState == DoPauseAfterDownload) {
        m_pauseAfterDownloadState = IsPausedAfterDownload;
        m_workerContextClient->didPauseAfterDownload();
>>>>>>> miniblink49
        return;
    }
    startWorkerThread();
}

void WebEmbeddedWorkerImpl::startWorkerThread()
{
<<<<<<< HEAD
    DCHECK_EQ(m_pauseAfterDownloadState, DontPauseAfterDownload);
    DCHECK(!m_askedToTerminate);

    Document* document = m_mainFrame->frame()->document();

    // FIXME: this document's origin is pristine and without any extra privileges.
    // (crbug.com/254993)
    SecurityOrigin* starterOrigin = document->getSecurityOrigin();

    WorkerClients* workerClients = WorkerClients::create();
    provideContentSettingsClientToWorker(workerClients,
        std::move(m_contentSettingsClient));
    provideIndexedDBClientToWorker(workerClients,
        IndexedDBClientImpl::create(*workerClients));
    provideServiceWorkerGlobalScopeClientToWorker(
        workerClients,
        ServiceWorkerGlobalScopeClientImpl::create(*m_workerContextClient));
    provideServiceWorkerContainerClientToWorker(
        workerClients,
        WTF::wrapUnique(m_workerContextClient->createServiceWorkerProvider()));

    // We need to set the CSP to both the shadow page's document and the
    // ServiceWorkerGlobalScope.
    document->initContentSecurityPolicy(
        m_mainScriptLoader->releaseContentSecurityPolicy());
    if (!m_mainScriptLoader->getReferrerPolicy().isNull()) {
        document->parseAndSetReferrerPolicy(
            m_mainScriptLoader->getReferrerPolicy());
    }

    KURL scriptURL = m_mainScriptLoader->url();
    WorkerThreadStartMode startMode = m_workerInspectorProxy->workerStartMode(document);
    std::unique_ptr<WorkerSettings> workerSettings = WTF::wrapUnique(new WorkerSettings(document->settings()));

    WorkerV8Settings workerV8Settings = WorkerV8Settings::Default();
    workerV8Settings.m_v8CacheOptions = static_cast<V8CacheOptions>(m_workerStartData.v8CacheOptions);

    std::unique_ptr<WorkerThreadStartupData> startupData = WorkerThreadStartupData::create(
        scriptURL, m_workerStartData.userAgent, m_mainScriptLoader->script(),
        m_mainScriptLoader->releaseCachedMetadata(), startMode,
        document->contentSecurityPolicy()->headers().get(),
        m_mainScriptLoader->getReferrerPolicy(), starterOrigin, workerClients,
        m_mainScriptLoader->responseAddressSpace(),
        m_mainScriptLoader->originTrialTokens(), std::move(workerSettings),
        workerV8Settings);

    m_mainScriptLoader.clear();

    // We have a dummy document here for loading but it doesn't really represent
    // the document/frame of associated document(s) for this worker. Here we
    // populate the task runners with null document not to confuse the frame
    // scheduler (which will end up using the thread's default task runner).
    m_mainThreadTaskRunners = ParentFrameTaskRunners::create(nullptr);

    m_workerGlobalScopeProxy = ServiceWorkerGlobalScopeProxy::create(
        *this, *document, *m_workerContextClient);
    m_loaderProxy = WorkerLoaderProxy::create(this);
    m_workerThread = ServiceWorkerThread::create(m_loaderProxy, *m_workerGlobalScopeProxy);
    m_workerThread->start(std::move(startupData));
    m_workerInspectorProxy->workerThreadCreated(document, m_workerThread.get(),
        scriptURL);
=======
    ASSERT(m_pauseAfterDownloadState == DontPauseAfterDownload);
    ASSERT(!m_askedToTerminate);

    Document* document = m_mainFrame->frame()->document();

    WorkerThreadStartMode startMode = DontPauseWorkerGlobalScopeOnStart;
    if (InspectorInstrumentation::shouldPauseDedicatedWorkerOnStart(document))
        startMode = PauseWorkerGlobalScopeOnStart;

    // FIXME: this document's origin is pristine and without any extra privileges. (crbug.com/254993)
    SecurityOrigin* starterOrigin = document->securityOrigin();

    OwnPtrWillBeRawPtr<WorkerClients> workerClients = WorkerClients::create();
    provideContentSettingsClientToWorker(workerClients.get(), m_contentSettingsClient.release());
    provideServiceWorkerGlobalScopeClientToWorker(workerClients.get(), ServiceWorkerGlobalScopeClientImpl::create(*m_workerContextClient));
    provideServiceWorkerContainerClientToWorker(workerClients.get(), adoptPtr(m_workerContextClient->createServiceWorkerProvider()));

    // We need to set the CSP to both the shadow page's document and the ServiceWorkerGlobalScope.
    document->initContentSecurityPolicy(m_mainScriptLoader->releaseContentSecurityPolicy());

    KURL scriptURL = m_mainScriptLoader->url();
    OwnPtr<WorkerThreadStartupData> startupData = WorkerThreadStartupData::create(
        scriptURL,
        m_workerStartData.userAgent,
        m_mainScriptLoader->script(),
        m_mainScriptLoader->releaseCachedMetadata(),
        startMode,
        document->contentSecurityPolicy()->headers(),
        starterOrigin,
        workerClients.release(),
        static_cast<V8CacheOptions>(m_workerStartData.v8CacheOptions));

    m_mainScriptLoader.clear();

    m_workerGlobalScopeProxy = ServiceWorkerGlobalScopeProxy::create(*this, *document, *m_workerContextClient);
    m_loaderProxy = WorkerLoaderProxy::create(this);
    m_workerThread = ServiceWorkerThread::create(m_loaderProxy, *m_workerGlobalScopeProxy);
    m_workerThread->start(startupData.release());
    m_workerInspectorProxy->workerThreadCreated(document, m_workerThread.get(), scriptURL);
>>>>>>> miniblink49
}

} // namespace blink

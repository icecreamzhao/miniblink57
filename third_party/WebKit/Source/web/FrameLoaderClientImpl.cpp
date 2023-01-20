/*
 * Copyright (C) 2009, 2012 Google Inc. All rights reserved.
 * Copyright (C) 2011 Apple Inc. All rights reserved.
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
#include "web/FrameLoaderClientImpl.h"

#include "bindings/core/v8/ScriptController.h"
#include "core/HTMLNames.h"
#include "core/dom/Document.h"
#include "core/dom/Fullscreen.h"
#include "core/events/MessageEvent.h"
#include "core/events/MouseEvent.h"
#include "core/events/UIEventWithKeyState.h"
#include "core/frame/FrameView.h"
#include "core/frame/Settings.h"
<<<<<<< HEAD
#include "core/html/HTMLFrameElementBase.h"
#include "core/html/HTMLMediaElement.h"
#include "core/html/HTMLPlugInElement.h"
=======
#include "core/html/HTMLAppletElement.h"
>>>>>>> miniblink49
#include "core/input/EventHandler.h"
#include "core/layout/HitTestResult.h"
#include "core/loader/DocumentLoader.h"
#include "core/loader/FrameLoadRequest.h"
#include "core/loader/FrameLoader.h"
#include "core/loader/HistoryItem.h"
<<<<<<< HEAD
#include "core/origin_trials/OriginTrials.h"
#include "core/page/Page.h"
#include "core/page/WindowFeatures.h"
#include "modules/audio_output_devices/HTMLMediaElementAudioOutputDevice.h"
#include "modules/device_light/DeviceLightController.h"
#include "modules/device_orientation/DeviceMotionController.h"
#include "modules/device_orientation/DeviceOrientationAbsoluteController.h"
#include "modules/device_orientation/DeviceOrientationController.h"
#include "modules/encryptedmedia/HTMLMediaElementEncryptedMedia.h"
#include "modules/gamepad/NavigatorGamepad.h"
#include "modules/remoteplayback/HTMLMediaElementRemotePlayback.h"
#include "modules/remoteplayback/RemotePlayback.h"
#include "modules/serviceworkers/NavigatorServiceWorker.h"
#include "modules/serviceworkers/ServiceWorkerLinkResource.h"
#include "modules/storage/DOMWindowStorageController.h"
//#include "modules/vr/NavigatorVR.h"
#include "platform/Histogram.h"
=======
#include "core/page/Page.h"
#include "core/page/WindowFeatures.h"
#include "modules/device_light/DeviceLightController.h"
#include "modules/device_orientation/DeviceMotionController.h"
#include "modules/device_orientation/DeviceOrientationController.h"
#include "modules/gamepad/NavigatorGamepad.h"
#include "modules/serviceworkers/NavigatorServiceWorker.h"
#include "modules/storage/DOMWindowStorageController.h"
#include "modules/vr/NavigatorVRDevice.h"
#include "platform/MIMETypeRegistry.h"
>>>>>>> miniblink49
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/UserGestureIndicator.h"
#include "platform/exported/WrappedResourceRequest.h"
#include "platform/exported/WrappedResourceResponse.h"
#include "platform/network/HTTPParsers.h"
<<<<<<< HEAD
#include "platform/network/mime/MIMETypeRegistry.h"
#include "platform/plugins/PluginData.h"
#include "public/platform/Platform.h"
#include "public/platform/WebApplicationCacheHost.h"
#include "public/platform/WebMediaPlayerSource.h"
#include "public/platform/WebRTCPeerConnectionHandler.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/WebURL.h"
#include "public/platform/WebURLError.h"
#include "public/platform/WebVector.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerProvider.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerProviderClient.h"
#include "public/web/WebAutofillClient.h"
=======
#include "platform/plugins/PluginData.h"
#include "public/platform/Platform.h"
#include "public/platform/WebApplicationCacheHost.h"
#include "public/platform/WebMimeRegistry.h"
#include "public/platform/WebRTCPeerConnectionHandler.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/WebServiceWorkerProvider.h"
#include "public/platform/WebServiceWorkerProviderClient.h"
#include "public/platform/WebURL.h"
#include "public/platform/WebURLError.h"
#include "public/platform/WebVector.h"
#include "public/web/WebAutofillClient.h"
#include "public/web/WebCachedURLRequest.h"
>>>>>>> miniblink49
#include "public/web/WebContentSettingsClient.h"
#include "public/web/WebDOMEvent.h"
#include "public/web/WebDocument.h"
#include "public/web/WebFormElement.h"
#include "public/web/WebFrameClient.h"
#include "public/web/WebNode.h"
#include "public/web/WebPlugin.h"
#include "public/web/WebPluginParams.h"
<<<<<<< HEAD
#include "public/web/WebViewClient.h"
#include "web/DevToolsEmulator.h"
=======
#include "public/web/WebPluginPlaceholder.h"
#include "public/web/WebViewClient.h"
#include "web/DevToolsEmulator.h"
#include "web/PluginPlaceholderImpl.h"
>>>>>>> miniblink49
#include "web/SharedWorkerRepositoryClientImpl.h"
#include "web/WebDataSourceImpl.h"
#include "web/WebDevToolsAgentImpl.h"
#include "web/WebDevToolsFrontendImpl.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WebPluginContainerImpl.h"
<<<<<<< HEAD
#include "web/WebViewImpl.h"
#include "wtf/PtrUtil.h"
#include "wtf/StringExtras.h"
#include "wtf/text/CString.h"
#include "wtf/text/WTFString.h"
#include <memory>
=======
#include "web/WebPluginLoadObserver.h"
#include "web/WebViewImpl.h"
#include "wtf/StringExtras.h"
#include "wtf/text/CString.h"
#include "wtf/text/WTFString.h"
>>>>>>> miniblink49
#include <v8.h>

namespace blink {

FrameLoaderClientImpl::FrameLoaderClientImpl(WebLocalFrameImpl* frame)
    : m_webFrame(frame)
{
}

<<<<<<< HEAD
FrameLoaderClientImpl* FrameLoaderClientImpl::create(WebLocalFrameImpl* frame)
{
    return new FrameLoaderClientImpl(frame);
}

FrameLoaderClientImpl::~FrameLoaderClientImpl() { }

DEFINE_TRACE(FrameLoaderClientImpl)
{
    visitor->trace(m_webFrame);
    FrameLoaderClient::trace(visitor);
=======
FrameLoaderClientImpl::~FrameLoaderClientImpl()
{
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::didCreateNewDocument()
{
    if (m_webFrame->client())
        m_webFrame->client()->didCreateNewDocument(m_webFrame);
}

void FrameLoaderClientImpl::dispatchDidClearWindowObjectInMainWorld()
{
    if (m_webFrame->client()) {
        m_webFrame->client()->didClearWindowObject(m_webFrame);
        Document* document = m_webFrame->frame()->document();
        if (document) {
<<<<<<< HEAD
            //       DeviceMotionController::from(*document);
            //       DeviceOrientationController::from(*document);
            //       DeviceOrientationAbsoluteController::from(*document);
            //       if (RuntimeEnabledFeatures::deviceLightEnabled())
            //         DeviceLightController::from(*document);
            //       NavigatorGamepad::from(*document);
            //       NavigatorServiceWorker::from(*document);
            //       DOMWindowStorageController::from(*document);
            //       if (RuntimeEnabledFeatures::webVREnabled() ||
            //           OriginTrials::webVREnabled(document->getExecutionContext()))
            //         NavigatorVR::from(*document);
        }
    }
    // FIXME: when extensions go out of process, this whole concept stops working.
    WebDevToolsFrontendImpl* devToolsFrontend = m_webFrame->top()->isWebLocalFrame()
        ? toWebLocalFrameImpl(m_webFrame->top())->devToolsFrontend()
        : nullptr;
    if (devToolsFrontend)
        devToolsFrontend->didClearWindowObject(m_webFrame);
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
            DeviceMotionController::from(*document);
            DeviceOrientationController::from(*document);
            if (RuntimeEnabledFeatures::deviceLightEnabled())
                DeviceLightController::from(*document);
            NavigatorGamepad::from(*document);
            NavigatorServiceWorker::from(*document);
            if (RuntimeEnabledFeatures::webVREnabled())
                NavigatorVRDevice::from(*document);
#endif // MINIBLINK_NOT_IMPLEMENTED
            DOMWindowStorageController::from(*document);
        }
    }

#ifndef MINIBLINK_NO_DEVTOOLS
    // FIXME: when extensions go out of process, this whole concept stops working.
    WebDevToolsFrontendImpl* devToolsFrontend = m_webFrame->top()->isWebLocalFrame() ? toWebLocalFrameImpl(m_webFrame->top())->devToolsFrontend() : nullptr;
    if (devToolsFrontend)
        devToolsFrontend->didClearWindowObject(m_webFrame);
#endif // MINIBLINK_NOT_IMPLEMENTED
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::documentElementAvailable()
{
    if (m_webFrame->client())
        m_webFrame->client()->didCreateDocumentElement(m_webFrame);
}

<<<<<<< HEAD
void FrameLoaderClientImpl::runScriptsAtDocumentElementAvailable()
{
    if (m_webFrame->client())
        m_webFrame->client()->runScriptsAtDocumentElementAvailable(m_webFrame);
    // The callback might have deleted the frame, do not use |this|!
}

void FrameLoaderClientImpl::runScriptsAtDocumentReady(bool documentIsEmpty)
{
    if (m_webFrame->client())
        m_webFrame->client()->runScriptsAtDocumentReady(m_webFrame,
            documentIsEmpty);
    // The callback might have deleted the frame, do not use |this|!
}

void FrameLoaderClientImpl::didCreateScriptContext(
    v8::Local<v8::Context> context,
    int worldId)
{
    if (m_webFrame->client())
        m_webFrame->client()->didCreateScriptContext(m_webFrame, context, worldId);
}

void FrameLoaderClientImpl::willReleaseScriptContext(
    v8::Local<v8::Context> context,
    int worldId)
{
    if (m_webFrame->client())
        m_webFrame->client()->willReleaseScriptContext(m_webFrame, context,
            worldId);
}

bool FrameLoaderClientImpl::allowScriptExtensions()
{
=======
void FrameLoaderClientImpl::didCreateScriptContext(v8::Local<v8::Context> context, int extensionGroup, int worldId)
{
    if (m_webFrame->client())
        m_webFrame->client()->didCreateScriptContext(m_webFrame, context, extensionGroup, worldId);
}

void FrameLoaderClientImpl::willReleaseScriptContext(v8::Local<v8::Context> context, int worldId)
{
    if (m_webFrame->client())
        m_webFrame->client()->willReleaseScriptContext(m_webFrame, context, worldId);
}

bool FrameLoaderClientImpl::allowScriptExtension(const String& extensionName,
                                                 int extensionGroup,
                                                 int worldId)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowScriptExtension(extensionName, extensionGroup, worldId);

>>>>>>> miniblink49
    return true;
}

void FrameLoaderClientImpl::didChangeScrollOffset()
{
    if (m_webFrame->client())
        m_webFrame->client()->didChangeScrollOffset(m_webFrame);
<<<<<<< HEAD
=======

    if (WebViewImpl* webview = m_webFrame->viewImpl())
        webview->devToolsEmulator()->viewportChanged();
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::didUpdateCurrentHistoryItem()
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->didUpdateCurrentHistoryItem();
=======
        m_webFrame->client()->didUpdateCurrentHistoryItem(m_webFrame);
}

void FrameLoaderClientImpl::didRemoveAllPendingStylesheet()
{
    WebViewImpl* webview = m_webFrame->viewImpl();
    if (webview)
        webview->didRemoveAllPendingStylesheet(m_webFrame);
>>>>>>> miniblink49
}

bool FrameLoaderClientImpl::allowScript(bool enabledPerSettings)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowScript(enabledPerSettings);

    return enabledPerSettings;
}

<<<<<<< HEAD
bool FrameLoaderClientImpl::allowScriptFromSource(bool enabledPerSettings,
    const KURL& scriptURL)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowScriptFromSource(
            enabledPerSettings, scriptURL);
=======
bool FrameLoaderClientImpl::allowScriptFromSource(bool enabledPerSettings, const KURL& scriptURL)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowScriptFromSource(enabledPerSettings, scriptURL);
>>>>>>> miniblink49

    return enabledPerSettings;
}

bool FrameLoaderClientImpl::allowPlugins(bool enabledPerSettings)
{
    if (m_webFrame->contentSettingsClient())
<<<<<<< HEAD
        return m_webFrame->contentSettingsClient()->allowPlugins(
            enabledPerSettings);
=======
        return m_webFrame->contentSettingsClient()->allowPlugins(enabledPerSettings);
>>>>>>> miniblink49

    return enabledPerSettings;
}

<<<<<<< HEAD
bool FrameLoaderClientImpl::allowImage(bool enabledPerSettings,
    const KURL& imageURL)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowImage(enabledPerSettings,
            imageURL);
=======
bool FrameLoaderClientImpl::allowImage(bool enabledPerSettings, const KURL& imageURL)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowImage(enabledPerSettings, imageURL);
>>>>>>> miniblink49

    return enabledPerSettings;
}

<<<<<<< HEAD
bool FrameLoaderClientImpl::allowRunningInsecureContent(bool enabledPerSettings,
    SecurityOrigin* context,
    const KURL& url)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowRunningInsecureContent(
            enabledPerSettings, WebSecurityOrigin(context), WebURL(url));
=======
bool FrameLoaderClientImpl::allowMedia(const KURL& mediaURL)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowMedia(mediaURL);

    return true;
}

bool FrameLoaderClientImpl::allowDisplayingInsecureContent(bool enabledPerSettings, SecurityOrigin* context, const KURL& url)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowDisplayingInsecureContent(enabledPerSettings, WebSecurityOrigin(context), WebURL(url));
>>>>>>> miniblink49

    return enabledPerSettings;
}

<<<<<<< HEAD
bool FrameLoaderClientImpl::allowAutoplay(bool defaultValue)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowAutoplay(defaultValue);

    return defaultValue;
}

void FrameLoaderClientImpl::passiveInsecureContentFound(const KURL& url)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->passiveInsecureContentFound(
            WebURL(url));
=======
bool FrameLoaderClientImpl::allowRunningInsecureContent(bool enabledPerSettings, SecurityOrigin* context, const KURL& url)
{
    if (m_webFrame->contentSettingsClient())
        return m_webFrame->contentSettingsClient()->allowRunningInsecureContent(enabledPerSettings, WebSecurityOrigin(context), WebURL(url));

    return enabledPerSettings;
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::didNotAllowScript()
{
    if (m_webFrame->contentSettingsClient())
        m_webFrame->contentSettingsClient()->didNotAllowScript();
}

void FrameLoaderClientImpl::didNotAllowPlugins()
{
    if (m_webFrame->contentSettingsClient())
        m_webFrame->contentSettingsClient()->didNotAllowPlugins();
<<<<<<< HEAD
=======

>>>>>>> miniblink49
}

bool FrameLoaderClientImpl::hasWebView() const
{
    return m_webFrame->viewImpl();
}

bool FrameLoaderClientImpl::inShadowTree() const
{
    return m_webFrame->inShadowTree();
}

Frame* FrameLoaderClientImpl::opener() const
{
    return toCoreFrame(m_webFrame->opener());
}

void FrameLoaderClientImpl::setOpener(Frame* opener)
{
<<<<<<< HEAD
    WebFrame* openerFrame = WebFrame::fromFrame(opener);
    if (m_webFrame->client() && m_webFrame->opener() != openerFrame)
        m_webFrame->client()->didChangeOpener(openerFrame);
    m_webFrame->setOpener(openerFrame);
=======
    m_webFrame->setOpener(WebFrame::fromFrame(opener));
>>>>>>> miniblink49
}

Frame* FrameLoaderClientImpl::parent() const
{
    return toCoreFrame(m_webFrame->parent());
}

Frame* FrameLoaderClientImpl::top() const
{
    return toCoreFrame(m_webFrame->top());
}

<<<<<<< HEAD
=======
Frame* FrameLoaderClientImpl::previousSibling() const
{
    return toCoreFrame(m_webFrame->previousSibling());
}

>>>>>>> miniblink49
Frame* FrameLoaderClientImpl::nextSibling() const
{
    return toCoreFrame(m_webFrame->nextSibling());
}

Frame* FrameLoaderClientImpl::firstChild() const
{
    return toCoreFrame(m_webFrame->firstChild());
}

<<<<<<< HEAD
=======
Frame* FrameLoaderClientImpl::lastChild() const
{
    return toCoreFrame(m_webFrame->lastChild());
}

>>>>>>> miniblink49
void FrameLoaderClientImpl::willBeDetached()
{
    m_webFrame->willBeDetached();
}

void FrameLoaderClientImpl::detached(FrameDetachType type)
{
    // Alert the client that the frame is being detached. This is the last
    // chance we have to communicate with the client.
<<<<<<< HEAD
=======
    RefPtrWillBeRawPtr<WebLocalFrameImpl> protector(m_webFrame);

>>>>>>> miniblink49
    WebFrameClient* client = m_webFrame->client();
    if (!client)
        return;

    m_webFrame->willDetachParent();

    // Signal that no further communication with WebFrameClient should take
    // place at this point since we are no longer associated with the Page.
    m_webFrame->setClient(0);

<<<<<<< HEAD
    client->frameDetached(m_webFrame,
        static_cast<WebFrameClient::DetachType>(type));
=======
    client->frameDetached(m_webFrame, static_cast<WebFrameClient::DetachType>(type));
>>>>>>> miniblink49
    // Clear our reference to LocalFrame at the very end, in case the client
    // refers to it.
    m_webFrame->setCoreFrame(nullptr);
}

<<<<<<< HEAD
void FrameLoaderClientImpl::dispatchWillSendRequest(ResourceRequest& request)
=======
void FrameLoaderClientImpl::dispatchWillSendRequest(
    DocumentLoader* loader, unsigned long identifier, ResourceRequest& request,
    const ResourceResponse& redirectResponse)
>>>>>>> miniblink49
{
    // Give the WebFrameClient a crack at the request.
    if (m_webFrame->client()) {
        WrappedResourceRequest webreq(request);
<<<<<<< HEAD
        m_webFrame->client()->willSendRequest(m_webFrame, webreq);
    }
}

void FrameLoaderClientImpl::dispatchDidReceiveResponse(
    const ResourceResponse& response)
{
    if (m_webFrame->client()) {
        WrappedResourceResponse webresp(response);
        m_webFrame->client()->didReceiveResponse(webresp);
    }
}

void FrameLoaderClientImpl::dispatchDidFinishDocumentLoad()
{
    // TODO(dglazkov): Sadly, workers are WebFrameClients, and they can totally
    // destroy themselves when didFinishDocumentLoad is invoked, and in turn
    // destroy the fake WebLocalFrame that they create, which means that you
    // should not put any code touching `this` after the two lines below.
=======
        WrappedResourceResponse webresp(redirectResponse);
        m_webFrame->client()->willSendRequest(
            m_webFrame, identifier, webreq, webresp);
    }
}

void FrameLoaderClientImpl::dispatchDidReceiveResponse(DocumentLoader* loader,
                                                       unsigned long identifier,
                                                       const ResourceResponse& response)
{
    if (m_webFrame->client()) {
        WrappedResourceResponse webresp(response);
        m_webFrame->client()->didReceiveResponse(m_webFrame, identifier, webresp);
    }
}

void FrameLoaderClientImpl::dispatchDidChangeResourcePriority(unsigned long identifier, ResourceLoadPriority priority, int intraPriorityValue)
{
    if (m_webFrame->client())
        m_webFrame->client()->didChangeResourcePriority(m_webFrame, identifier, static_cast<WebURLRequest::Priority>(priority), intraPriorityValue);
}

// Called when a particular resource load completes
void FrameLoaderClientImpl::dispatchDidFinishLoading(DocumentLoader* loader,
                                                    unsigned long identifier)
{
    if (m_webFrame->client())
        m_webFrame->client()->didFinishResourceLoad(m_webFrame, identifier);
}

void FrameLoaderClientImpl::dispatchDidFinishDocumentLoad()
{
>>>>>>> miniblink49
    if (m_webFrame->client())
        m_webFrame->client()->didFinishDocumentLoad(m_webFrame);
}

<<<<<<< HEAD
void FrameLoaderClientImpl::dispatchDidLoadResourceFromMemoryCache(
    const ResourceRequest& request,
    const ResourceResponse& response)
{
    if (m_webFrame->client())
        m_webFrame->client()->didLoadResourceFromMemoryCache(
            WrappedResourceRequest(request), WrappedResourceResponse(response));
=======
void FrameLoaderClientImpl::dispatchDidLoadResourceFromMemoryCache(const ResourceRequest& request, const ResourceResponse& response)
{
    if (m_webFrame->client())
        m_webFrame->client()->didLoadResourceFromMemoryCache(m_webFrame, WrappedResourceRequest(request), WrappedResourceResponse(response));
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::dispatchDidHandleOnloadEvents()
{
    if (m_webFrame->client())
        m_webFrame->client()->didHandleOnloadEvents(m_webFrame);
}

<<<<<<< HEAD
void FrameLoaderClientImpl::
    dispatchDidReceiveServerRedirectForProvisionalLoad()
{
    if (m_webFrame->client())
        m_webFrame->client()->didReceiveServerRedirectForProvisionalLoad(
            m_webFrame);
}

void FrameLoaderClientImpl::dispatchDidNavigateWithinPage(
    HistoryItem* item,
    HistoryCommitType commitType,
    bool contentInitiated)
{
    bool shouldCreateHistoryEntry = commitType == StandardCommit;
    // TODO(dglazkov): Does this need to be called for subframes?
    m_webFrame->viewImpl()->didCommitLoad(shouldCreateHistoryEntry, true);
    if (m_webFrame->client())
        m_webFrame->client()->didNavigateWithinPage(
            m_webFrame, WebHistoryItem(item),
            static_cast<WebHistoryCommitType>(commitType), contentInitiated);
}

void FrameLoaderClientImpl::dispatchWillCommitProvisionalLoad()
{
    if (m_webFrame->client())
        m_webFrame->client()->willCommitProvisionalLoad(m_webFrame);
}

void FrameLoaderClientImpl::dispatchDidStartProvisionalLoad()
{
    if (m_webFrame->client())
        m_webFrame->client()->didStartProvisionalLoad(m_webFrame);
    if (WebDevToolsAgentImpl* devTools = devToolsAgent())
        devTools->didStartProvisionalLoad(m_webFrame->frame());
=======
void FrameLoaderClientImpl::dispatchDidReceiveServerRedirectForProvisionalLoad()
{
    if (m_webFrame->client())
        m_webFrame->client()->didReceiveServerRedirectForProvisionalLoad(m_webFrame);
}

void FrameLoaderClientImpl::dispatchDidNavigateWithinPage(HistoryItem* item, HistoryCommitType commitType)
{
    bool shouldCreateHistoryEntry = commitType == StandardCommit;
    m_webFrame->viewImpl()->didCommitLoad(shouldCreateHistoryEntry, true);
    if (m_webFrame->client())
        m_webFrame->client()->didNavigateWithinPage(m_webFrame, WebHistoryItem(item), static_cast<WebHistoryCommitType>(commitType));
}

void FrameLoaderClientImpl::dispatchWillClose()
{
    if (m_webFrame->client())
        m_webFrame->client()->willClose(m_webFrame);
}

void FrameLoaderClientImpl::dispatchDidStartProvisionalLoad(double triggeringEventTime)
{
    if (m_webFrame->client())
        m_webFrame->client()->didStartProvisionalLoad(m_webFrame, triggeringEventTime);
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::dispatchDidReceiveTitle(const String& title)
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->didReceiveTitle(m_webFrame, title,
            WebTextDirectionLeftToRight);
=======
        m_webFrame->client()->didReceiveTitle(m_webFrame, title, WebTextDirectionLeftToRight);
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::dispatchDidChangeIcons(IconType type)
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->didChangeIcon(m_webFrame,
            static_cast<WebIconURL::Type>(type));
}

void FrameLoaderClientImpl::dispatchDidCommitLoad(
    HistoryItem* item,
    HistoryCommitType commitType)
{
    if (!m_webFrame->parent()) {
        m_webFrame->viewImpl()->didCommitLoad(commitType == StandardCommit, false);
    }

    if (m_webFrame->client())
        m_webFrame->client()->didCommitProvisionalLoad(
            m_webFrame, WebHistoryItem(item),
            static_cast<WebHistoryCommitType>(commitType));
    if (WebDevToolsAgentImpl* devTools = devToolsAgent())
        devTools->didCommitLoadForLocalFrame(m_webFrame->frame());
}

void FrameLoaderClientImpl::dispatchDidFailProvisionalLoad(
    const ResourceError& error,
    HistoryCommitType commitType)
{
    m_webFrame->didFail(error, true, commitType);
}

void FrameLoaderClientImpl::dispatchDidFailLoad(const ResourceError& error,
    HistoryCommitType commitType)
{
    m_webFrame->didFail(error, false, commitType);
=======
        m_webFrame->client()->didChangeIcon(m_webFrame, static_cast<WebIconURL::Type>(type));
}

void FrameLoaderClientImpl::dispatchDidCommitLoad(HistoryItem* item, HistoryCommitType commitType)
{
    m_webFrame->viewImpl()->didCommitLoad(commitType == StandardCommit, false);
    if (m_webFrame->client())
        m_webFrame->client()->didCommitProvisionalLoad(m_webFrame, WebHistoryItem(item), static_cast<WebHistoryCommitType>(commitType));
#ifndef MINIBLINK_NO_DEVTOOLS
    WebDevToolsAgentImpl* devToolsAgent = WebLocalFrameImpl::fromFrame(m_webFrame->frame()->localFrameRoot())->devToolsAgentImpl();
    if (devToolsAgent)
        devToolsAgent->didCommitLoadForLocalFrame(m_webFrame->frame());
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void FrameLoaderClientImpl::dispatchDidFailProvisionalLoad(
    const ResourceError& error, HistoryCommitType commitType)
{
    OwnPtr<WebPluginLoadObserver> observer = pluginLoadObserver(m_webFrame->frame()->loader().provisionalDocumentLoader());
    m_webFrame->didFail(error, true, commitType);
    if (observer)
        observer->didFailLoading(error);
}

void FrameLoaderClientImpl::dispatchDidFailLoad(const ResourceError& error, HistoryCommitType commitType)
{
    OwnPtr<WebPluginLoadObserver> observer = pluginLoadObserver(m_webFrame->frame()->loader().documentLoader());
    m_webFrame->didFail(error, false, commitType);
    if (observer)
        observer->didFailLoading(error);

    // Don't clear the redirect chain, this will happen in the middle of client
    // redirects, and we need the context. The chain will be cleared when the
    // provisional load succeeds or fails, not the "real" one.
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::dispatchDidFinishLoad()
{
<<<<<<< HEAD
    m_webFrame->didFinish();
=======
    OwnPtr<WebPluginLoadObserver> observer = pluginLoadObserver(m_webFrame->frame()->loader().documentLoader());

    if (m_webFrame->client())
        m_webFrame->client()->didFinishLoad(m_webFrame);

    if (observer)
        observer->didFinishLoading();

    // Don't clear the redirect chain, this will happen in the middle of client
    // redirects, and we need the context. The chain will be cleared when the
    // provisional load succeeds or fails, not the "real" one.
}

void FrameLoaderClientImpl::dispatchDidFirstVisuallyNonEmptyLayout()
{
    if (m_webFrame->client())
        m_webFrame->client()->didFirstVisuallyNonEmptyLayout(m_webFrame);
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::dispatchDidChangeThemeColor()
{
    if (m_webFrame->client())
        m_webFrame->client()->didChangeThemeColor();
}

static bool allowCreatingBackgroundTabs()
{
<<<<<<< HEAD
    const WebInputEvent* inputEvent = WebViewImpl::currentInputEvent();
    if (!inputEvent || (inputEvent->type() != WebInputEvent::MouseUp && (inputEvent->type() != WebInputEvent::RawKeyDown && inputEvent->type() != WebInputEvent::KeyDown) && inputEvent->type() != WebInputEvent::GestureTap))
        return false;

    unsigned short buttonNumber;
    if (WebInputEvent::isMouseEventType(inputEvent->type())) {
        const WebMouseEvent* mouseEvent = static_cast<const WebMouseEvent*>(inputEvent);

        switch (mouseEvent->button) {
        case WebMouseEvent::Button::Left:
            buttonNumber = 0;
            break;
        case WebMouseEvent::Button::Middle:
            buttonNumber = 1;
            break;
        case WebMouseEvent::Button::Right:
=======

    const WebInputEvent* inputEvent = WebViewImpl::currentInputEvent();
    if (!inputEvent || (inputEvent->type != WebInputEvent::MouseUp && (inputEvent->type != WebInputEvent::RawKeyDown && inputEvent->type != WebInputEvent::KeyDown)
        && inputEvent->type != WebInputEvent::GestureTap))
        return false;

    unsigned short buttonNumber;
    if (WebInputEvent::isMouseEventType(inputEvent->type)) {
        const WebMouseEvent* mouseEvent = static_cast<const WebMouseEvent*>(inputEvent);

        switch (mouseEvent->button) {
        case WebMouseEvent::ButtonLeft:
            buttonNumber = 0;
            break;
        case WebMouseEvent::ButtonMiddle:
            buttonNumber = 1;
            break;
        case WebMouseEvent::ButtonRight:
>>>>>>> miniblink49
            buttonNumber = 2;
            break;
        default:
            return false;
        }
    } else {
        // The click is simulated when triggering the keypress event.
        buttonNumber = 0;
    }
<<<<<<< HEAD
    bool ctrl = inputEvent->modifiers() & WebMouseEvent::ControlKey;
    bool shift = inputEvent->modifiers() & WebMouseEvent::ShiftKey;
    bool alt = inputEvent->modifiers() & WebMouseEvent::AltKey;
    bool meta = inputEvent->modifiers() & WebMouseEvent::MetaKey;

    NavigationPolicy userPolicy;
    if (!navigationPolicyFromMouseEvent(buttonNumber, ctrl, shift, alt, meta,
            &userPolicy))
=======
    bool ctrl = inputEvent->modifiers & WebMouseEvent::ControlKey;
    bool shift = inputEvent->modifiers & WebMouseEvent::ShiftKey;
    bool alt = inputEvent->modifiers & WebMouseEvent::AltKey;
    bool meta = inputEvent->modifiers & WebMouseEvent::MetaKey;

    NavigationPolicy userPolicy;
    if (!navigationPolicyFromMouseEvent(buttonNumber, ctrl, shift, alt, meta, &userPolicy))
>>>>>>> miniblink49
        return false;
    return userPolicy == NavigationPolicyNewBackgroundTab;
}

<<<<<<< HEAD
NavigationPolicy FrameLoaderClientImpl::decidePolicyForNavigation(
    const ResourceRequest& request,
    DocumentLoader* loader,
    NavigationType type,
    NavigationPolicy policy,
    bool replacesCurrentHistoryItem,
    bool isClientRedirect,
    HTMLFormElement* form)
=======
NavigationPolicy FrameLoaderClientImpl::decidePolicyForNavigation(const ResourceRequest& request, DocumentLoader* loader, NavigationPolicy policy)
>>>>>>> miniblink49
{
    if (!m_webFrame->client())
        return NavigationPolicyIgnore;

    if (policy == NavigationPolicyNewBackgroundTab && !allowCreatingBackgroundTabs() && !UIEventWithKeyState::newTabModifierSetFromIsolatedWorld())
        policy = NavigationPolicyNewForegroundTab;

    WebDataSourceImpl* ds = WebDataSourceImpl::fromDocumentLoader(loader);

<<<<<<< HEAD
    // Newly created child frames may need to be navigated to a history item
    // during a back/forward navigation. This will only happen when the parent
    // is a LocalFrame doing a back/forward navigation that has not completed.
    // (If the load has completed and the parent later adds a frame with script,
    // we do not want to use a history item for it.)
    bool isHistoryNavigationInNewChildFrame = m_webFrame->parent() && m_webFrame->parent()->isWebLocalFrame() && isBackForwardLoadType(toWebLocalFrameImpl(m_webFrame->parent())->frame()->loader().loadType()) && !toWebLocalFrameImpl(m_webFrame->parent())->frame()->document()->loadEventFinished();

    WrappedResourceRequest wrappedResourceRequest(request);
    WebFrameClient::NavigationPolicyInfo navigationInfo(wrappedResourceRequest);
    navigationInfo.navigationType = static_cast<WebNavigationType>(type);
    navigationInfo.defaultPolicy = static_cast<WebNavigationPolicy>(policy);
    navigationInfo.extraData = ds ? ds->getExtraData() : nullptr;
    navigationInfo.replacesCurrentHistoryItem = replacesCurrentHistoryItem;
    navigationInfo.isHistoryNavigationInNewChildFrame = isHistoryNavigationInNewChildFrame;
    navigationInfo.isClientRedirect = isClientRedirect;
    // Caching could be disabled for requests initiated by DevTools.
    // TODO(ananta)
    // We should extract the network cache state into a global component which
    // can be queried here and wherever necessary.
    navigationInfo.isCacheDisabled = devToolsAgent() ? devToolsAgent()->cacheDisabled() : false;
    if (form)
        navigationInfo.form = WebFormElement(form);

    WebNavigationPolicy webPolicy = m_webFrame->client()->decidePolicyForNavigation(navigationInfo);
    return static_cast<NavigationPolicy>(webPolicy);
}

void FrameLoaderClientImpl::dispatchWillSendSubmitEvent(HTMLFormElement* form)
{
    if (m_webFrame->client())
        m_webFrame->client()->willSendSubmitEvent(WebFormElement(form));
=======
    WrappedResourceRequest wrappedResourceRequest(request);
    WebFrameClient::NavigationPolicyInfo navigationInfo(wrappedResourceRequest);
    navigationInfo.frame = m_webFrame;
    navigationInfo.extraData = ds->extraData();
    navigationInfo.navigationType = ds->navigationType();
    navigationInfo.defaultPolicy = static_cast<WebNavigationPolicy>(policy);
    navigationInfo.isRedirect = ds->isRedirect();

    WebNavigationPolicy webPolicy = m_webFrame->client()->decidePolicyForNavigation(navigationInfo);
    ((blink::ResourceRequest &)loader->request()).setURL(KURL(request.url()));
    return static_cast<NavigationPolicy>(webPolicy);
}

void FrameLoaderClientImpl::dispatchWillRequestResource(FetchRequest* request)
{
    if (m_webFrame->client()) {
        WebCachedURLRequest urlRequest(request);
        m_webFrame->client()->willRequestResource(m_webFrame, urlRequest);
    }
}

void FrameLoaderClientImpl::dispatchWillSendSubmitEvent(HTMLFormElement* form)
{
    if (m_webFrame->client())
        m_webFrame->client()->willSendSubmitEvent(m_webFrame, WebFormElement(form));
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::dispatchWillSubmitForm(HTMLFormElement* form)
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->willSubmitForm(WebFormElement(form));
=======
        m_webFrame->client()->willSubmitForm(m_webFrame, WebFormElement(form));
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::didStartLoading(LoadStartType loadStartType)
{
    if (m_webFrame->client())
        m_webFrame->client()->didStartLoading(loadStartType == NavigationToDifferentDocument);
}

void FrameLoaderClientImpl::progressEstimateChanged(double progressEstimate)
{
    if (m_webFrame->client())
        m_webFrame->client()->didChangeLoadProgress(progressEstimate);
}

void FrameLoaderClientImpl::didStopLoading()
{
    if (m_webFrame->client())
        m_webFrame->client()->didStopLoading();
}

<<<<<<< HEAD
void FrameLoaderClientImpl::loadURLExternally(const ResourceRequest& request,
    NavigationPolicy policy,
    const String& suggestedName,
    bool shouldReplaceCurrentEntry)
{
    if (!m_webFrame->client())
        return;
    DCHECK(m_webFrame->frame()->document());
    Fullscreen::fullyExitFullscreen(*m_webFrame->frame()->document());
    m_webFrame->client()->loadURLExternally(
        WrappedResourceRequest(request), static_cast<WebNavigationPolicy>(policy),
        suggestedName, shouldReplaceCurrentEntry);
}

void FrameLoaderClientImpl::loadErrorPage(int reason)
{
    if (m_webFrame->client())
        m_webFrame->client()->loadErrorPage(reason);
=======
void FrameLoaderClientImpl::loadURLExternally(const ResourceRequest& request, NavigationPolicy policy, const String& suggestedName)
{
    if (m_webFrame->client()) {
        ASSERT(m_webFrame->frame()->document());
        Fullscreen::fullyExitFullscreen(*m_webFrame->frame()->document());
        WrappedResourceRequest webreq(request);
        m_webFrame->client()->loadURLExternally(
            m_webFrame, webreq, static_cast<WebNavigationPolicy>(policy), suggestedName);
    }
>>>>>>> miniblink49
}

bool FrameLoaderClientImpl::navigateBackForward(int offset) const
{
    WebViewImpl* webview = m_webFrame->viewImpl();
    if (!webview->client())
        return false;

<<<<<<< HEAD
    DCHECK(offset);
=======
    ASSERT(offset);
>>>>>>> miniblink49
    if (offset > webview->client()->historyForwardListCount())
        return false;
    if (offset < -webview->client()->historyBackListCount())
        return false;
    webview->client()->navigateBackForwardSoon(offset);
    return true;
}

void FrameLoaderClientImpl::didAccessInitialDocument()
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->didAccessInitialDocument();
=======
        m_webFrame->client()->didAccessInitialDocument(m_webFrame);
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::didDisplayInsecureContent()
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->didDisplayInsecureContent();
}

void FrameLoaderClientImpl::didRunInsecureContent(SecurityOrigin* origin,
    const KURL& insecureURL)
{
    if (m_webFrame->client())
        m_webFrame->client()->didRunInsecureContent(WebSecurityOrigin(origin),
            insecureURL);
}

void FrameLoaderClientImpl::didDetectXSS(const KURL& insecureURL,
    bool didBlockEntirePage)
{
    if (m_webFrame->client())
        m_webFrame->client()->didDetectXSS(insecureURL, didBlockEntirePage);
=======
        m_webFrame->client()->didDisplayInsecureContent(m_webFrame);
}

void FrameLoaderClientImpl::didRunInsecureContent(SecurityOrigin* origin, const KURL& insecureURL)
{
    if (m_webFrame->client())
        m_webFrame->client()->didRunInsecureContent(m_webFrame, WebSecurityOrigin(origin), insecureURL);
}

void FrameLoaderClientImpl::didDetectXSS(const KURL& insecureURL, bool didBlockEntirePage)
{
    if (m_webFrame->client())
        m_webFrame->client()->didDetectXSS(m_webFrame, insecureURL, didBlockEntirePage);
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::didDispatchPingLoader(const KURL& url)
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->didDispatchPingLoader(url);
}

void FrameLoaderClientImpl::didDisplayContentWithCertificateErrors(
    const KURL& url)
{
    if (m_webFrame->client())
        m_webFrame->client()->didDisplayContentWithCertificateErrors(url);
}

void FrameLoaderClientImpl::didRunContentWithCertificateErrors(
    const KURL& url)
{
    if (m_webFrame->client())
        m_webFrame->client()->didRunContentWithCertificateErrors(url);
}

void FrameLoaderClientImpl::didChangePerformanceTiming()
{
    if (m_webFrame->client())
        m_webFrame->client()->didChangePerformanceTiming();
}

void FrameLoaderClientImpl::didObserveLoadingBehavior(
    WebLoadingBehaviorFlag behavior)
{
    if (m_webFrame->client())
        m_webFrame->client()->didObserveLoadingBehavior(behavior);
}

void FrameLoaderClientImpl::selectorMatchChanged(
    const Vector<String>& addedSelectors,
    const Vector<String>& removedSelectors)
{
    if (WebFrameClient* client = m_webFrame->client())
        client->didMatchCSS(m_webFrame, WebVector<WebString>(addedSelectors),
            WebVector<WebString>(removedSelectors));
}

DocumentLoader* FrameLoaderClientImpl::createDocumentLoader(
    LocalFrame* frame,
    const ResourceRequest& request,
    const SubstituteData& data,
    ClientRedirectPolicy clientRedirectPolicy)
{
    DCHECK(frame);

    WebDataSourceImpl* ds = WebDataSourceImpl::create(frame, request, data, clientRedirectPolicy);
    if (m_webFrame->client())
        m_webFrame->client()->didCreateDataSource(m_webFrame, ds);
    return ds;
}

String FrameLoaderClientImpl::userAgent()
{
    WebString override = m_webFrame->client() ? m_webFrame->client()->userAgentOverride() : "";
    if (!override.isEmpty())
        return override;

    if (m_userAgent.isEmpty())
        m_userAgent = Platform::current()->userAgent();
    return m_userAgent;
=======
        m_webFrame->client()->didDispatchPingLoader(m_webFrame, url);
}

void FrameLoaderClientImpl::selectorMatchChanged(const Vector<String>& addedSelectors, const Vector<String>& removedSelectors)
{
    if (WebFrameClient* client = m_webFrame->client())
        client->didMatchCSS(m_webFrame, WebVector<WebString>(addedSelectors), WebVector<WebString>(removedSelectors));
}

PassRefPtrWillBeRawPtr<DocumentLoader> FrameLoaderClientImpl::createDocumentLoader(LocalFrame* frame, const ResourceRequest& request, const SubstituteData& data)
{
    RefPtrWillBeRawPtr<WebDataSourceImpl> ds = WebDataSourceImpl::create(frame, request, data);
    if (m_webFrame->client())
        m_webFrame->client()->didCreateDataSource(m_webFrame, ds.get());
    return ds.release();
}

String FrameLoaderClientImpl::userAgent(const KURL& url)
{
    if (WebFrameClient* client = m_webFrame->client()) {
        WebString override = client->userAgentOverride(m_webFrame, WebURL(url));
        if (!override.isEmpty())
            return override;
    }

    return Platform::current()->userAgent();
>>>>>>> miniblink49
}

String FrameLoaderClientImpl::doNotTrackValue()
{
<<<<<<< HEAD
    WebString doNotTrack = m_webFrame->client()->doNotTrackValue();
=======
    if (!m_webFrame->client())
        return String();

    WebString doNotTrack = m_webFrame->client()->doNotTrackValue(m_webFrame);
>>>>>>> miniblink49
    if (!doNotTrack.isEmpty())
        return doNotTrack;
    return String();
}

// Called when the FrameLoader goes into a state in which a new page load
// will occur.
void FrameLoaderClientImpl::transitionToCommittedForNewPage()
{
    m_webFrame->createFrameView();
}

<<<<<<< HEAD
LocalFrame* FrameLoaderClientImpl::createFrame(
=======
PassRefPtrWillBeRawPtr<LocalFrame> FrameLoaderClientImpl::createFrame(
>>>>>>> miniblink49
    const FrameLoadRequest& request,
    const AtomicString& name,
    HTMLFrameOwnerElement* ownerElement)
{
    return m_webFrame->createChildFrame(request, name, ownerElement);
}

<<<<<<< HEAD
bool FrameLoaderClientImpl::canCreatePluginWithoutRenderer(
    const String& mimeType) const
=======
bool FrameLoaderClientImpl::canCreatePluginWithoutRenderer(const String& mimeType) const
>>>>>>> miniblink49
{
    if (!m_webFrame->client())
        return false;

    return m_webFrame->client()->canCreatePluginWithoutRenderer(mimeType);
}

<<<<<<< HEAD
Widget* FrameLoaderClientImpl::createPlugin(HTMLPlugInElement* element,
=======
PassOwnPtrWillBeRawPtr<PluginPlaceholder> FrameLoaderClientImpl::createPluginPlaceholder(
    Document& document,
    const KURL& url,
    const Vector<String>& paramNames,
    const Vector<String>& paramValues,
    const String& mimeType,
    bool loadManually)
{
    if (!m_webFrame->client())
        return nullptr;

    WebPluginParams params;
    params.url = url;
    params.mimeType = mimeType;
    params.attributeNames = paramNames;
    params.attributeValues = paramValues;
    params.loadManually = loadManually;

    OwnPtr<WebPluginPlaceholder> webPluginPlaceholder = adoptPtr(
        m_webFrame->client()->createPluginPlaceholder(m_webFrame, params));
    if (!webPluginPlaceholder)
        return nullptr;

    return PluginPlaceholderImpl::create(webPluginPlaceholder.release(), document);
}

PassRefPtrWillBeRawPtr<Widget> FrameLoaderClientImpl::createPlugin(
    HTMLPlugInElement* element,
>>>>>>> miniblink49
    const KURL& url,
    const Vector<String>& paramNames,
    const Vector<String>& paramValues,
    const String& mimeType,
    bool loadManually,
    DetachedPluginPolicy policy)
{
    if (!m_webFrame->client())
        return nullptr;

    WebPluginParams params;
    params.url = url;
    params.mimeType = mimeType;
    params.attributeNames = paramNames;
    params.attributeValues = paramValues;
    params.loadManually = loadManually;

    WebPlugin* webPlugin = m_webFrame->client()->createPlugin(m_webFrame, params);
    if (!webPlugin)
        return nullptr;

    // The container takes ownership of the WebPlugin.
<<<<<<< HEAD
    WebPluginContainerImpl* container = WebPluginContainerImpl::create(element, webPlugin);

    if (!webPlugin->initialize(container))
        return nullptr;

    if (policy != AllowDetachedPlugin && !element->layoutObject())
        return nullptr;
=======
    RefPtrWillBeRawPtr<WebPluginContainerImpl> container =
        WebPluginContainerImpl::create(element, webPlugin);

    if (!webPlugin->initialize(container.get())) {
#if ENABLE(OILPAN)
        container->dispose();
#endif
        return nullptr;
    }

    if (policy != AllowDetachedPlugin && !element->layoutObject()) {
#if ENABLE(OILPAN)
        container->dispose();
#endif
        return nullptr;
    }
>>>>>>> miniblink49

    return container;
}

<<<<<<< HEAD
std::unique_ptr<WebMediaPlayer> FrameLoaderClientImpl::createWebMediaPlayer(
    HTMLMediaElement& htmlMediaElement,
    const WebMediaPlayerSource& source,
    WebMediaPlayerClient* client)
{
    WebLocalFrameImpl* webFrame = WebLocalFrameImpl::fromFrame(htmlMediaElement.document().frame());

    if (!webFrame || !webFrame->client())
        return nullptr;

    WebString sinkId(HTMLMediaElementAudioOutputDevice::sinkId(htmlMediaElement));
//     HTMLMediaElementEncryptedMedia& encryptedMedia = HTMLMediaElementEncryptedMedia::from(htmlMediaElement);
//     return WTF::wrapUnique(webFrame->client()->createMediaPlayer(source, client, &encryptedMedia, encryptedMedia.contentDecryptionModule(), sinkId));
    return WTF::wrapUnique(webFrame->client()->createMediaPlayer(source, client, nullptr, nullptr, sinkId));
}

WebRemotePlaybackClient* FrameLoaderClientImpl::createWebRemotePlaybackClient(HTMLMediaElement& htmlMediaElement)
{
    //return HTMLMediaElementRemotePlayback::remote(htmlMediaElement);
    //DebugBreak();
    return nullptr;
}

ObjectContentType FrameLoaderClientImpl::getObjectContentType(
=======
PassRefPtrWillBeRawPtr<Widget> FrameLoaderClientImpl::createJavaAppletWidget(
    HTMLAppletElement* element,
    const KURL& /* baseURL */,
    const Vector<String>& paramNames,
    const Vector<String>& paramValues)
{
    return createPlugin(element, KURL(), paramNames, paramValues,
        "application/x-java-applet", false, FailOnDetachedPlugin);
}

ObjectContentType FrameLoaderClientImpl::objectContentType(
>>>>>>> miniblink49
    const KURL& url,
    const String& explicitMimeType,
    bool shouldPreferPlugInsForImages)
{
    // This code is based on Apple's implementation from
    // WebCoreSupport/WebFrameBridge.mm.

    String mimeType = explicitMimeType;
    if (mimeType.isEmpty()) {
        // Try to guess the MIME type based off the extension.
        String filename = url.lastPathComponent();
        int extensionPos = filename.reverseFind('.');
        if (extensionPos >= 0) {
            String extension = filename.substring(extensionPos + 1);
<<<<<<< HEAD
            mimeType = MIMETypeRegistry::getWellKnownMIMETypeForExtension(extension);
=======
            mimeType = MIMETypeRegistry::getMIMETypeForExtension(extension);
            if (mimeType.isEmpty()) {
                // If there's no mimetype registered for the extension, check to see
                // if a plugin can handle the extension.
                mimeType = getPluginMimeTypeFromExtension(extension);
            }
>>>>>>> miniblink49
        }

        if (mimeType.isEmpty())
            return ObjectContentFrame;
    }

    // If Chrome is started with the --disable-plugins switch, pluginData is 0.
<<<<<<< HEAD
    PluginData* pluginData = m_webFrame->frame()->pluginData();
    bool plugInSupportsMIMEType = pluginData && pluginData->supportsMimeType(mimeType);

    if (MIMETypeRegistry::isSupportedImageMIMEType(mimeType))
        return shouldPreferPlugInsForImages && plugInSupportsMIMEType
            ? ObjectContentNetscapePlugin
            : ObjectContentImage;
=======
    PluginData* pluginData = m_webFrame->frame()->page()->pluginData();
    bool plugInSupportsMIMEType = pluginData && pluginData->supportsMimeType(mimeType);

    if (MIMETypeRegistry::isSupportedImageMIMEType(mimeType))
        return shouldPreferPlugInsForImages && plugInSupportsMIMEType ? ObjectContentNetscapePlugin : ObjectContentImage;
>>>>>>> miniblink49

    if (plugInSupportsMIMEType)
        return ObjectContentNetscapePlugin;

    if (MIMETypeRegistry::isSupportedNonImageMIMEType(mimeType))
        return ObjectContentFrame;

    return ObjectContentNone;
}

<<<<<<< HEAD
=======
PassOwnPtr<WebPluginLoadObserver> FrameLoaderClientImpl::pluginLoadObserver(DocumentLoader* loader)
{
    return WebDataSourceImpl::fromDocumentLoader(loader)->releasePluginLoadObserver();
}

>>>>>>> miniblink49
WebCookieJar* FrameLoaderClientImpl::cookieJar() const
{
    if (!m_webFrame->client())
        return 0;
<<<<<<< HEAD
    return m_webFrame->client()->cookieJar();
}

void FrameLoaderClientImpl::frameFocused() const
{
    if (m_webFrame->client())
        m_webFrame->client()->frameFocused();
}

void FrameLoaderClientImpl::didChangeName(const String& name,
    const String& uniqueName)
{
    if (!m_webFrame->client())
        return;
    m_webFrame->client()->didChangeName(name, uniqueName);
}

void FrameLoaderClientImpl::didEnforceInsecureRequestPolicy(
    WebInsecureRequestPolicy policy)
{
    if (!m_webFrame->client())
        return;
    m_webFrame->client()->didEnforceInsecureRequestPolicy(policy);
}

void FrameLoaderClientImpl::didUpdateToUniqueOrigin()
{
    if (!m_webFrame->client())
        return;
    DCHECK(m_webFrame->getSecurityOrigin().isUnique());
    m_webFrame->client()->didUpdateToUniqueOrigin(
        m_webFrame->getSecurityOrigin().isPotentiallyTrustworthy());
}

void FrameLoaderClientImpl::didChangeSandboxFlags(Frame* childFrame,
    SandboxFlags flags)
{
    if (!m_webFrame->client())
        return;
    m_webFrame->client()->didChangeSandboxFlags(
        WebFrame::fromFrame(childFrame), static_cast<WebSandboxFlags>(flags));
}

void FrameLoaderClientImpl::didSetFeaturePolicyHeader(
    const WebParsedFeaturePolicy& parsedHeader)
{
    if (m_webFrame->client())
        m_webFrame->client()->didSetFeaturePolicyHeader(parsedHeader);
}

void FrameLoaderClientImpl::didAddContentSecurityPolicy(
    const String& headerValue,
    ContentSecurityPolicyHeaderType type,
    ContentSecurityPolicyHeaderSource source)
{
    if (m_webFrame->client()) {
        m_webFrame->client()->didAddContentSecurityPolicy(
            headerValue, static_cast<WebContentSecurityPolicyType>(type),
            static_cast<WebContentSecurityPolicySource>(source));
    }
}

void FrameLoaderClientImpl::didChangeFrameOwnerProperties(
    HTMLFrameElementBase* frameElement)
{
    if (!m_webFrame->client())
        return;

    m_webFrame->client()->didChangeFrameOwnerProperties(
        WebFrame::fromFrame(frameElement->contentFrame()),
        WebFrameOwnerProperties(
            frameElement->browsingContextContainerName(),
            frameElement->scrollingMode(), frameElement->marginWidth(),
            frameElement->marginHeight(), frameElement->allowFullscreen(),
            frameElement->allowPaymentRequest(), frameElement->csp(),
            frameElement->delegatedPermissions()));
}

void FrameLoaderClientImpl::dispatchWillStartUsingPeerConnectionHandler(
    WebRTCPeerConnectionHandler* handler)
{
    m_webFrame->client()->willStartUsingPeerConnectionHandler(handler);
=======
    return m_webFrame->client()->cookieJar(m_webFrame);
}

bool FrameLoaderClientImpl::willCheckAndDispatchMessageEvent(
    SecurityOrigin* target, MessageEvent* event, LocalFrame* sourceFrame) const
{
    if (!m_webFrame->client())
        return false;
    return m_webFrame->client()->willCheckAndDispatchMessageEvent(
        WebLocalFrameImpl::fromFrame(sourceFrame), m_webFrame, WebSecurityOrigin(target), WebDOMMessageEvent(event));
}

void FrameLoaderClientImpl::didChangeName(const String& name)
{
    if (!m_webFrame->client())
        return;
    m_webFrame->client()->didChangeName(m_webFrame, name);
}

void FrameLoaderClientImpl::didChangeSandboxFlags(Frame* childFrame, SandboxFlags flags)
{
    if (!m_webFrame->client())
        return;
    m_webFrame->client()->didChangeSandboxFlags(WebFrame::fromFrame(childFrame), static_cast<WebSandboxFlags>(flags));
}

void FrameLoaderClientImpl::dispatchWillOpenWebSocket(WebSocketHandle* handle)
{
    m_webFrame->client()->willOpenWebSocket(handle);
}

void FrameLoaderClientImpl::dispatchWillStartUsingPeerConnectionHandler(WebRTCPeerConnectionHandler* handler)
{
    m_webFrame->client()->willStartUsingPeerConnectionHandler(webFrame(), handler);
}

void FrameLoaderClientImpl::didRequestAutocomplete(HTMLFormElement* form)
{
    if (m_webFrame->autofillClient())
        m_webFrame->autofillClient()->didRequestAutocomplete(WebFormElement(form));
>>>>>>> miniblink49
}

bool FrameLoaderClientImpl::allowWebGL(bool enabledPerSettings)
{
    if (m_webFrame->client())
<<<<<<< HEAD
        return m_webFrame->client()->allowWebGL(enabledPerSettings);
=======
        return m_webFrame->client()->allowWebGL(m_webFrame, enabledPerSettings);
>>>>>>> miniblink49

    return enabledPerSettings;
}

<<<<<<< HEAD
=======
void FrameLoaderClientImpl::didLoseWebGLContext(int arbRobustnessContextLostReason)
{
    if (m_webFrame->client())
        m_webFrame->client()->didLoseWebGLContext(m_webFrame, arbRobustnessContextLostReason);
}

>>>>>>> miniblink49
void FrameLoaderClientImpl::dispatchWillInsertBody()
{
    if (m_webFrame->client())
        m_webFrame->client()->willInsertBody(m_webFrame);
<<<<<<< HEAD
}

std::unique_ptr<WebServiceWorkerProvider>
FrameLoaderClientImpl::createServiceWorkerProvider()
{
    if (!m_webFrame->client())
        return nullptr;
    return WTF::wrapUnique(m_webFrame->client()->createServiceWorkerProvider());
}

bool FrameLoaderClientImpl::isControlledByServiceWorker(
    DocumentLoader& loader)
=======

    if (m_webFrame->viewImpl())
        m_webFrame->viewImpl()->willInsertBody(m_webFrame);
}

v8::Local<v8::Value> FrameLoaderClientImpl::createTestInterface(const AtomicString& name)
{
    return m_webFrame->createTestInterface(name);
}

PassOwnPtr<WebServiceWorkerProvider> FrameLoaderClientImpl::createServiceWorkerProvider()
{
    if (!m_webFrame->client())
        return nullptr;
    return adoptPtr(m_webFrame->client()->createServiceWorkerProvider(m_webFrame));
}

bool FrameLoaderClientImpl::isControlledByServiceWorker(DocumentLoader& loader)
>>>>>>> miniblink49
{
    return m_webFrame->client() && m_webFrame->client()->isControlledByServiceWorker(*WebDataSourceImpl::fromDocumentLoader(&loader));
}

int64_t FrameLoaderClientImpl::serviceWorkerID(DocumentLoader& loader)
{
    if (!m_webFrame->client())
        return -1;
<<<<<<< HEAD
    return m_webFrame->client()->serviceWorkerID(
        *WebDataSourceImpl::fromDocumentLoader(&loader));
}

SharedWorkerRepositoryClient*
FrameLoaderClientImpl::sharedWorkerRepositoryClient()
=======
    return m_webFrame->client()->serviceWorkerID(*WebDataSourceImpl::fromDocumentLoader(&loader));
}

SharedWorkerRepositoryClient* FrameLoaderClientImpl::sharedWorkerRepositoryClient()
>>>>>>> miniblink49
{
    return m_webFrame->sharedWorkerRepositoryClient();
}

<<<<<<< HEAD
std::unique_ptr<WebApplicationCacheHost>
FrameLoaderClientImpl::createApplicationCacheHost(
    WebApplicationCacheHostClient* client)
{
    if (!m_webFrame->client())
        return nullptr;
    return WTF::wrapUnique(
        m_webFrame->client()->createApplicationCacheHost(client));
=======
PassOwnPtr<WebApplicationCacheHost> FrameLoaderClientImpl::createApplicationCacheHost(WebApplicationCacheHostClient* client)
{
    if (!m_webFrame->client())
        return nullptr;
    return adoptPtr(m_webFrame->client()->createApplicationCacheHost(m_webFrame, client));
}

void FrameLoaderClientImpl::didStopAllLoaders()
{
    if (m_webFrame->client())
        m_webFrame->client()->didAbortLoading(m_webFrame);
>>>>>>> miniblink49
}

void FrameLoaderClientImpl::dispatchDidChangeManifest()
{
    if (m_webFrame->client())
<<<<<<< HEAD
        m_webFrame->client()->didChangeManifest();
=======
        m_webFrame->client()->didChangeManifest(m_webFrame);
}

void FrameLoaderClientImpl::dispatchDidChangeDefaultPresentation()
{
    if (m_webFrame->client())
        m_webFrame->client()->didChangeDefaultPresentation(m_webFrame);
>>>>>>> miniblink49
}

unsigned FrameLoaderClientImpl::backForwardLength()
{
    WebViewImpl* webview = m_webFrame->viewImpl();
    if (!webview || !webview->client())
        return 0;
    return webview->client()->historyBackListCount() + 1 + webview->client()->historyForwardListCount();
}

<<<<<<< HEAD
void FrameLoaderClientImpl::suddenTerminationDisablerChanged(
    bool present,
    SuddenTerminationDisablerType type)
{
    if (m_webFrame->client()) {
        m_webFrame->client()->suddenTerminationDisablerChanged(
            present,
            static_cast<WebFrameClient::SuddenTerminationDisablerType>(type));
    }
}

BlameContext* FrameLoaderClientImpl::frameBlameContext()
{
    if (!m_webFrame->client())
        return nullptr;
    return m_webFrame->client()->frameBlameContext();
}

LinkResource* FrameLoaderClientImpl::createServiceWorkerLinkResource(
    HTMLLinkElement* owner)
{
    //return ServiceWorkerLinkResource::create(owner);
    DebugBreak();
    return nullptr;
}

WebEffectiveConnectionType FrameLoaderClientImpl::getEffectiveConnectionType()
{
    if (m_webFrame->client())
        return m_webFrame->client()->getEffectiveConnectionType();
    return WebEffectiveConnectionType::TypeUnknown;
}

WebDevToolsAgentImpl* FrameLoaderClientImpl::devToolsAgent()
{
    return WebLocalFrameImpl::fromFrame(m_webFrame->frame()->localFrameRoot())->devToolsAgentImpl();
}

KURL FrameLoaderClientImpl::overrideFlashEmbedWithHTML(const KURL& url)
{
    return m_webFrame->client()->overrideFlashEmbedWithHTML(WebURL(url));
}

void FrameLoaderClientImpl::setHasReceivedUserGesture()
{
    if (m_webFrame->client())
        m_webFrame->client()->setHasReceivedUserGesture();
}

=======
void FrameLoaderClientImpl::suddenTerminationDisablerChanged(bool present, SuddenTerminationDisablerType type)
{
    if (m_webFrame->client()) {
        m_webFrame->client()->suddenTerminationDisablerChanged(
            present, static_cast<WebFrameClient::SuddenTerminationDisablerType>(type));
    }
}

>>>>>>> miniblink49
} // namespace blink

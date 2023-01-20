/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
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

// How ownership works
// -------------------
//
// Big oh represents a refcounted relationship: owner O--- ownee
//
// WebView (for the toplevel frame only)
//    O
//    |           WebFrame
//    |              O
//    |              |
//   Page O------- LocalFrame (m_mainFrame) O-------O FrameView
//                   ||
//                   ||
//               FrameLoader
//
<<<<<<< HEAD
// FrameLoader and LocalFrame are formerly one object that was split apart
// because it got too big. They basically have the same lifetime, hence the
// double line.
=======
// FrameLoader and LocalFrame are formerly one object that was split apart because
// it got too big. They basically have the same lifetime, hence the double line.
>>>>>>> miniblink49
//
// From the perspective of the embedder, WebFrame is simply an object that it
// allocates by calling WebFrame::create() and must be freed by calling close().
// Internally, WebFrame is actually refcounted and it holds a reference to its
// corresponding LocalFrame in blink.
//
<<<<<<< HEAD
// Oilpan: the middle objects + Page in the above diagram are Oilpan heap
// allocated, WebView and FrameView are currently not. In terms of ownership
// and control, the relationships stays the same, but the references from the
// off-heap WebView to the on-heap Page is handled by a Persistent<>, not a
// RefPtr<>. Similarly, the mutual strong references between the on-heap
// LocalFrame and the off-heap FrameView is through a RefPtr (from LocalFrame
// to FrameView), and a Persistent refers to the LocalFrame in the other
// direction.
//
// From the embedder's point of view, the use of Oilpan brings no changes.
// close() must still be used to signal that the embedder is through with the
// WebFrame.  Calling it will bring about the release and finalization of the
// frame object, and everything underneath.
=======
// Oilpan: the middle objects + Page in the above diagram are Oilpan heap allocated,
// WebView and FrameView are currently not. In terms of ownership and control, the
// relationships stays the same, but the references from the off-heap WebView to the
// on-heap Page is handled by a Persistent<>, not a RefPtr<>. Similarly, the mutual
// strong references between the on-heap LocalFrame and the off-heap FrameView
// is through a RefPtr (from LocalFrame to FrameView), and a Persistent refers
// to the LocalFrame in the other direction.
//
// From the embedder's point of view, the use of Oilpan brings no changes. close()
// must still be used to signal that the embedder is through with the WebFrame.
// Calling it will bring about the release and finalization of the frame object,
// and everything underneath.
>>>>>>> miniblink49
//
// How frames are destroyed
// ------------------------
//
// The main frame is never destroyed and is re-used. The FrameLoader is re-used
// and a reference to the main frame is kept by the Page.
//
// When frame content is replaced, all subframes are destroyed. This happens
<<<<<<< HEAD
// in Frame::detachChildren for each subframe in a pre-order depth-first
// traversal. Note that child node order may not match DOM node order!
// detachChildren() (virtually) calls Frame::detach(), which again calls
// FrameLoaderClient::detached(). This triggers WebFrame to clear its reference
// to LocalFrame. FrameLoaderClient::detached() also notifies the embedder via
// WebFrameClient that the frame is detached. Most embedders will invoke
// close() on the WebFrame at this point, triggering its deletion unless
// something else is still retaining a reference.
//
// The client is expected to be set whenever the WebLocalFrameImpl is attached
// to the DOM.

=======
// in FrameLoader::detachFromParent for each subframe in a pre-order depth-first
// traversal. Note that child node order may not match DOM node order!
// detachFromParent() calls FrameLoaderClient::detachedFromParent(), which calls
// WebFrame::frameDetached(). This triggers WebFrame to clear its reference to
// LocalFrame, and also notifies the embedder via WebFrameClient that the frame is
// detached. Most embedders will invoke close() on the WebFrame at this point,
// triggering its deletion unless something else is still retaining a reference.
//
// The client is expected to be set whenever the WebLocalFrameImpl is attached to
// the DOM.

#include "config.h"
>>>>>>> miniblink49
#include "web/WebLocalFrameImpl.h"

#include "bindings/core/v8/BindingSecurity.h"
#include "bindings/core/v8/DOMWrapperWorld.h"
#include "bindings/core/v8/ExceptionState.h"
<<<<<<< HEAD
#include "bindings/core/v8/ScriptController.h"
#include "bindings/core/v8/ScriptSourceCode.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/SourceLocation.h"
=======
#include "bindings/core/v8/ExceptionStatePlaceholder.h"
#include "bindings/core/v8/ScriptController.h"
#include "bindings/core/v8/ScriptSourceCode.h"
#include "bindings/core/v8/ScriptValue.h"
>>>>>>> miniblink49
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8GCController.h"
#include "bindings/core/v8/V8PerIsolateData.h"
#include "core/HTMLNames.h"
#include "core/dom/Document.h"
<<<<<<< HEAD
#include "core/dom/DocumentUserGestureToken.h"
=======
>>>>>>> miniblink49
#include "core/dom/IconURL.h"
#include "core/dom/MessagePort.h"
#include "core/dom/Node.h"
#include "core/dom/NodeTraversal.h"
<<<<<<< HEAD
#include "core/dom/shadow/ShadowRoot.h"
#include "core/editing/EditingUtilities.h"
=======
#include "core/dom/SuspendableTask.h"
#include "core/dom/shadow/ShadowRoot.h"
>>>>>>> miniblink49
#include "core/editing/Editor.h"
#include "core/editing/FrameSelection.h"
#include "core/editing/InputMethodController.h"
#include "core/editing/PlainTextRange.h"
<<<<<<< HEAD
#include "core/editing/TextAffinity.h"
#include "core/editing/iterators/TextIterator.h"
#include "core/editing/serializers/Serialization.h"
#include "core/editing/spellcheck/SpellChecker.h"
#include "core/fetch/ResourceFetcher.h"
#include "core/fetch/SubstituteData.h"
#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/PageScaleConstraintsSet.h"
#include "core/frame/RemoteFrame.h"
#include "core/frame/Settings.h"
#include "core/frame/UseCounter.h"
#include "core/frame/VisualViewport.h"
=======
#include "core/editing/SpellChecker.h"
#include "core/editing/TextAffinity.h"
#include "core/editing/htmlediting.h"
#include "core/editing/iterators/TextIterator.h"
#include "core/editing/markup.h"
#include "core/fetch/ResourceFetcher.h"
#include "core/fetch/SubstituteData.h"
#include "core/frame/Console.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/Settings.h"
>>>>>>> miniblink49
#include "core/html/HTMLAnchorElement.h"
#include "core/html/HTMLCollection.h"
#include "core/html/HTMLFormElement.h"
#include "core/html/HTMLFrameElementBase.h"
#include "core/html/HTMLFrameOwnerElement.h"
#include "core/html/HTMLHeadElement.h"
#include "core/html/HTMLImageElement.h"
#include "core/html/HTMLInputElement.h"
#include "core/html/HTMLLinkElement.h"
#include "core/html/PluginDocument.h"
#include "core/input/EventHandler.h"
#include "core/inspector/ConsoleMessage.h"
<<<<<<< HEAD
#include "core/layout/HitTestResult.h"
#include "core/layout/LayoutObject.h"
#include "core/layout/api/LayoutPartItem.h"
#include "core/layout/api/LayoutViewItem.h"
=======
#include "core/inspector/ScriptCallStack.h"
#include "core/layout/HitTestResult.h"
#include "core/layout/LayoutBox.h"
#include "core/layout/LayoutObject.h"
#include "core/layout/LayoutPart.h"
#include "core/layout/LayoutTreeAsText.h"
#include "core/layout/LayoutView.h"
#include "core/style/StyleInheritedData.h"
>>>>>>> miniblink49
#include "core/loader/DocumentLoader.h"
#include "core/loader/FrameLoadRequest.h"
#include "core/loader/FrameLoader.h"
#include "core/loader/HistoryItem.h"
#include "core/loader/MixedContentChecker.h"
<<<<<<< HEAD
#include "core/loader/NavigationScheduler.h"
=======
>>>>>>> miniblink49
#include "core/page/FocusController.h"
#include "core/page/FrameTree.h"
#include "core/page/Page.h"
#include "core/page/PrintContext.h"
<<<<<<< HEAD
#include "core/paint/PaintLayer.h"
#include "core/paint/TransformRecorder.h"
#include "core/style/StyleInheritedData.h"
#include "core/timing/DOMWindowPerformance.h"
#include "core/timing/Performance.h"
// #include "modules/app_banner/AppBannerController.h"
// #include "modules/installation/InstallationServiceImpl.h"
// #include "modules/screen_orientation/ScreenOrientationControllerImpl.h"
#include "platform/ScriptForbiddenScope.h"
#include "platform/UserGestureIndicator.h"
#include "platform/WebFrameScheduler.h"
=======
#include "core/paint/DeprecatedPaintLayer.h"
#include "core/paint/ScopeRecorder.h"
#include "core/paint/TransformRecorder.h"
#include "core/timing/DOMWindowPerformance.h"
#include "core/timing/Performance.h"
#include "modules/app_banner/AppBannerController.h"
#include "modules/geolocation/GeolocationController.h"
#include "modules/notifications/NotificationPermissionClient.h"
#include "modules/permissions/PermissionController.h"
#include "modules/presentation/PresentationController.h"
#include "modules/push_messaging/PushController.h"
#include "modules/screen_orientation/ScreenOrientationController.h"
#include "modules/vr/VRController.h"
#include "platform/ScriptForbiddenScope.h"
#include "platform/TraceEvent.h"
#include "platform/UserGestureIndicator.h"
>>>>>>> miniblink49
#include "platform/clipboard/ClipboardUtilities.h"
#include "platform/fonts/FontCache.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/GraphicsLayerClient.h"
#include "platform/graphics/paint/ClipRecorder.h"
<<<<<<< HEAD
#include "platform/graphics/paint/DisplayItemCacheSkipper.h"
=======
>>>>>>> miniblink49
#include "platform/graphics/paint/DrawingRecorder.h"
#include "platform/graphics/paint/SkPictureBuilder.h"
#include "platform/graphics/skia/SkiaUtils.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "platform/instrumentation/tracing/TraceEvent.h"
=======
>>>>>>> miniblink49
#include "platform/network/ResourceRequest.h"
#include "platform/scroll/ScrollTypes.h"
#include "platform/scroll/ScrollbarTheme.h"
#include "platform/weborigin/KURL.h"
#include "platform/weborigin/SchemeRegistry.h"
#include "platform/weborigin/SecurityPolicy.h"
<<<<<<< HEAD
// #include "public/platform/InterfaceProvider.h"
// #include "public/platform/InterfaceRegistry.h"
#include "public/platform/WebDoubleSize.h"
=======
#include "public/platform/Platform.h"
>>>>>>> miniblink49
#include "public/platform/WebFloatPoint.h"
#include "public/platform/WebFloatRect.h"
#include "public/platform/WebLayer.h"
#include "public/platform/WebPoint.h"
#include "public/platform/WebRect.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/WebSize.h"
<<<<<<< HEAD
#include "public/platform/WebURLError.h"
#include "public/platform/WebVector.h"
#include "public/web/WebAssociatedURLLoaderOptions.h"
=======
#include "public/platform/WebSuspendableTask.h"
#include "public/platform/WebURLError.h"
#include "public/platform/WebVector.h"
>>>>>>> miniblink49
#include "public/web/WebAutofillClient.h"
#include "public/web/WebConsoleMessage.h"
#include "public/web/WebDOMEvent.h"
#include "public/web/WebDocument.h"
#include "public/web/WebFindOptions.h"
#include "public/web/WebFormElement.h"
#include "public/web/WebFrameClient.h"
<<<<<<< HEAD
#include "public/web/WebFrameOwnerProperties.h"
=======
>>>>>>> miniblink49
#include "public/web/WebHistoryItem.h"
#include "public/web/WebIconURL.h"
#include "public/web/WebInputElement.h"
#include "public/web/WebKit.h"
#include "public/web/WebNode.h"
#include "public/web/WebPerformance.h"
#include "public/web/WebPlugin.h"
#include "public/web/WebPrintParams.h"
#include "public/web/WebPrintPresetOptions.h"
#include "public/web/WebRange.h"
#include "public/web/WebScriptSource.h"
#include "public/web/WebSerializedScriptValue.h"
<<<<<<< HEAD
#include "public/web/WebTreeScopeType.h"
#include "skia/ext/platform_canvas.h"
#include "web/CompositionUnderlineVectorBuilder.h"
#include "web/FindInPageCoordinates.h"
#include "web/RemoteFrameOwner.h"
#include "web/SharedWorkerRepositoryClientImpl.h"
#include "web/SuspendableScriptExecutor.h"
#include "web/TextFinder.h"
#include "web/WebAssociatedURLLoaderImpl.h"
=======
#include "public/web/WebTestInterfaceFactory.h"
#include "public/web/WebTreeScopeType.h"
#include "skia/ext/platform_device.h"
#include "web/AssociatedURLLoader.h"
#include "web/CompositionUnderlineVectorBuilder.h"
#include "web/FindInPageCoordinates.h"
#include "web/GeolocationClientProxy.h"
#include "web/InspectorOverlayImpl.h"
#include "web/LocalFileSystemClient.h"
#include "web/MIDIClientProxy.h"
#include "web/NavigatorContentUtilsClientImpl.h"
#include "web/NotificationPermissionClientImpl.h"
#include "web/PageOverlay.h"
#include "web/RemoteBridgeFrameOwner.h"
//#include "web/SharedWorkerRepositoryClientImpl.h"
#include "web/SuspendableScriptExecutor.h"
#include "web/TextFinder.h"
>>>>>>> miniblink49
#include "web/WebDataSourceImpl.h"
#include "web/WebDevToolsAgentImpl.h"
#include "web/WebFrameWidgetImpl.h"
#include "web/WebPluginContainerImpl.h"
#include "web/WebRemoteFrameImpl.h"
#include "web/WebViewImpl.h"
#include "wtf/CurrentTime.h"
#include "wtf/HashMap.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include <algorithm>
#include <memory>
#include <utility>
=======
#include "wtf/RefCountedLeakCounter.h"
#include <algorithm>
>>>>>>> miniblink49

namespace blink {

static int frameCount = 0;

<<<<<<< HEAD
static HeapVector<ScriptSourceCode> createSourcesVector(
    const WebScriptSource* sourcesIn,
    unsigned numSources)
{
    HeapVector<ScriptSourceCode> sources;
=======
// Key for a StatsCounter tracking how many WebFrames are active.
static const char webFrameActiveCount[] = "WebFrameActiveCount";

static void frameContentAsPlainText(size_t maxChars, LocalFrame* frame, StringBuilder& output)
{
    Document* document = frame->document();
    if (!document)
        return;

    if (!frame->view())
        return;

    // Select the document body.
    RefPtrWillBeRawPtr<Range> range(document->createRange());
    TrackExceptionState exceptionState;
    range->selectNodeContents(document->body(), exceptionState);

    if (!exceptionState.hadException()) {
        // The text iterator will walk nodes giving us text. This is similar to
        // the plainText() function in core/editing/TextIterator.h, but we implement the maximum
        // size and also copy the results directly into a wstring, avoiding the
        // string conversion.
        for (TextIterator it(range->startPosition(), range->endPosition()); !it.atEnd(); it.advance()) {
            it.text().appendTextToStringBuilder(output, 0, maxChars - output.length());
            if (output.length() >= maxChars)
                return; // Filled up the buffer.
        }
    }

    // The separator between frames when the frames are converted to plain text.
    const LChar frameSeparator[] = { '\n', '\n' };
    const size_t frameSeparatorLength = WTF_ARRAY_LENGTH(frameSeparator);

    // Recursively walk the children.
    const FrameTree& frameTree = frame->tree();
    for (Frame* curChild = frameTree.firstChild(); curChild; curChild = curChild->tree().nextSibling()) {
        if (!curChild->isLocalFrame())
            continue;
        LocalFrame* curLocalChild = toLocalFrame(curChild);
        // Ignore the text of non-visible frames.
        LayoutView* contentLayoutObject = curLocalChild->contentLayoutObject();
        LayoutPart* ownerLayoutObject = curLocalChild->ownerLayoutObject();
        if (!contentLayoutObject || !contentLayoutObject->size().width() || !contentLayoutObject->size().height()
            || (contentLayoutObject->location().x() + contentLayoutObject->size().width() <= 0) || (contentLayoutObject->location().y() + contentLayoutObject->size().height() <= 0)
            || (ownerLayoutObject && ownerLayoutObject->style() && ownerLayoutObject->style()->visibility() != VISIBLE)) {
            continue;
        }

        // Make sure the frame separator won't fill up the buffer, and give up if
        // it will. The danger is if the separator will make the buffer longer than
        // maxChars. This will cause the computation above:
        //   maxChars - output->size()
        // to be a negative number which will crash when the subframe is added.
        if (output.length() >= maxChars - frameSeparatorLength)
            return;

        output.append(frameSeparator, frameSeparatorLength);
        frameContentAsPlainText(maxChars, curLocalChild, output);
        if (output.length() >= maxChars)
            return; // Filled up the buffer.
    }
}

static WillBeHeapVector<ScriptSourceCode> createSourcesVector(const WebScriptSource* sourcesIn, unsigned numSources)
{
    WillBeHeapVector<ScriptSourceCode> sources;
>>>>>>> miniblink49
    sources.append(sourcesIn, numSources);
    return sources;
}

<<<<<<< HEAD
WebPluginContainerImpl* WebLocalFrameImpl::pluginContainerFromFrame(
    LocalFrame* frame)
=======
WebPluginContainerImpl* WebLocalFrameImpl::pluginContainerFromFrame(LocalFrame* frame)
>>>>>>> miniblink49
{
    if (!frame)
        return 0;
    if (!frame->document() || !frame->document()->isPluginDocument())
        return 0;
    PluginDocument* pluginDocument = toPluginDocument(frame->document());
    return toWebPluginContainerImpl(pluginDocument->pluginWidget());
}

<<<<<<< HEAD
WebPluginContainerImpl* WebLocalFrameImpl::currentPluginContainer(
    LocalFrame* frame,
    Node* node)
=======
WebPluginContainerImpl* WebLocalFrameImpl::pluginContainerFromNode(LocalFrame* frame, const WebNode& node)
>>>>>>> miniblink49
{
    WebPluginContainerImpl* pluginContainer = pluginContainerFromFrame(frame);
    if (pluginContainer)
        return pluginContainer;
<<<<<<< HEAD

    if (!node) {
        DCHECK(frame->document());
        node = frame->document()->focusedElement();
    }
    return toWebPluginContainerImpl(WebNode::pluginContainerFromNode(node));
=======
    return toWebPluginContainerImpl(node.pluginContainer());
>>>>>>> miniblink49
}

// Simple class to override some of PrintContext behavior. Some of the methods
// made virtual so that they can be overridden by ChromePluginPrintContext.
class ChromePrintContext : public PrintContext {
    WTF_MAKE_NONCOPYABLE(ChromePrintContext);
<<<<<<< HEAD

=======
>>>>>>> miniblink49
public:
    ChromePrintContext(LocalFrame* frame)
        : PrintContext(frame)
        , m_printedPageWidth(0)
    {
    }

<<<<<<< HEAD
    ~ChromePrintContext() override { }

    virtual void begin(float width, float height)
    {
        DCHECK(!m_printedPageWidth);
=======
    ~ChromePrintContext() override {}

    virtual void begin(float width, float height)
    {
        ASSERT(!m_printedPageWidth);
>>>>>>> miniblink49
        m_printedPageWidth = width;
        PrintContext::begin(m_printedPageWidth, height);
    }

    virtual float getPageShrink(int pageNumber) const
    {
        IntRect pageRect = m_pageRects[pageNumber];
        return m_printedPageWidth / pageRect.width();
    }

    float spoolSinglePage(WebCanvas* canvas, int pageNumber)
    {
        dispatchEventsForPrintingOnAllFrames();
<<<<<<< HEAD
        if (!frame()->document() || frame()->document()->layoutViewItem().isNull())
            return 0;

        frame()->view()->updateAllLifecyclePhasesExceptPaint();
        if (!frame()->document() || frame()->document()->layoutViewItem().isNull())
            return 0;

        IntRect pageRect = m_pageRects[pageNumber];
        SkPictureBuilder pictureBuilder(pageRect, &skia::GetMetaData(*canvas));
        pictureBuilder.context().setPrinting(true);

        float scale = spoolPage(pictureBuilder, pageNumber);
        pictureBuilder.endRecording()->playback(canvas);
        return scale;
    }

    void spoolAllPagesWithBoundaries(WebCanvas* canvas,
        const FloatSize& pageSizeInPixels)
    {
        dispatchEventsForPrintingOnAllFrames();
        if (!frame()->document() || frame()->document()->layoutViewItem().isNull())
            return;

        frame()->view()->updateAllLifecyclePhasesExceptPaint();
        if (!frame()->document() || frame()->document()->layoutViewItem().isNull())
            return;

        float pageHeight;
        computePageRects(FloatRect(FloatPoint(0, 0), pageSizeInPixels), 0, 0, 1,
            pageHeight);
=======
        if (!frame()->document() || !frame()->document()->layoutView())
            return 0;

        frame()->view()->updateAllLifecyclePhases();
        if (!frame()->document() || !frame()->document()->layoutView())
            return 0;

        IntRect pageRect = m_pageRects[pageNumber];
        SkPictureBuilder pictureBuilder(pageRect, &skia::getMetaData(*canvas));
        pictureBuilder.context().setPrinting(true);

        float scale = spoolPage(pictureBuilder.context(), pageNumber);
        pictureBuilder.endRecording()->playback(canvas);
        outputLinkedDestinations(canvas, pageRect);
        return scale;
    }

    void spoolAllPagesWithBoundaries(WebCanvas* canvas, const FloatSize& pageSizeInPixels)
    {
        dispatchEventsForPrintingOnAllFrames();
        if (!frame()->document() || !frame()->document()->layoutView())
            return;

        frame()->view()->updateAllLifecyclePhases();
        if (!frame()->document() || !frame()->document()->layoutView())
            return;

        float pageHeight;
        computePageRects(FloatRect(FloatPoint(0, 0), pageSizeInPixels), 0, 0, 1, pageHeight);
>>>>>>> miniblink49

        const float pageWidth = pageSizeInPixels.width();
        size_t numPages = pageRects().size();
        int totalHeight = numPages * (pageSizeInPixels.height() + 1) - 1;
        IntRect allPagesRect(0, 0, pageWidth, totalHeight);

<<<<<<< HEAD
        SkPictureBuilder pictureBuilder(allPagesRect, &skia::GetMetaData(*canvas));
        pictureBuilder.context().setPrinting(true);

        {
            GraphicsContext& context = pictureBuilder.context();
            DisplayItemCacheSkipper skipper(context);

            // Fill the whole background by white.
            {
                DrawingRecorder backgroundRecorder(
                    context, pictureBuilder, DisplayItem::kPrintedContentBackground,
                    allPagesRect);
                context.fillRect(FloatRect(0, 0, pageWidth, totalHeight), Color::white);
            }

            int currentHeight = 0;
            for (size_t pageIndex = 0; pageIndex < numPages; pageIndex++) {
                // Draw a line for a page boundary if this isn't the first page.
                if (pageIndex > 0) {
                    DrawingRecorder lineBoundaryRecorder(
                        context, pictureBuilder, DisplayItem::kPrintedContentLineBoundary,
                        allPagesRect);
                    context.save();
                    context.setStrokeColor(Color(0, 0, 255));
                    context.setFillColor(Color(0, 0, 255));
                    context.drawLine(IntPoint(0, currentHeight),
                        IntPoint(pageWidth, currentHeight));
                    context.restore();
                }

                AffineTransform transform;
                transform.translate(0, currentHeight);
#if OS(WIN) || OS(MACOSX)
                // Account for the disabling of scaling in spoolPage. In the context
                // of spoolAllPagesWithBoundaries the scale HAS NOT been pre-applied.
                float scale = getPageShrink(pageIndex);
                transform.scale(scale, scale);
#endif
                TransformRecorder transformRecorder(context, pictureBuilder, transform);
                spoolPage(pictureBuilder, pageIndex);

                currentHeight += pageSizeInPixels.height() + 1;
            }
        }
        pictureBuilder.endRecording()->playback(canvas);
    }

=======
        SkPictureBuilder pictureBuilder(allPagesRect, &skia::getMetaData(*canvas));
        pictureBuilder.context().setPrinting(true);

        GraphicsContext& context = pictureBuilder.context();

        // Fill the whole background by white.
        if (!DrawingRecorder::useCachedDrawingIfPossible(context, *this, DisplayItem::PrintedContentBackground)) {
            DrawingRecorder backgroundRecorder(context, *this, DisplayItem::PrintedContentBackground, allPagesRect);
            context.fillRect(FloatRect(0, 0, pageWidth, totalHeight), Color::white);
        }

        int currentHeight = 0;
        for (size_t pageIndex = 0; pageIndex < numPages; pageIndex++) {
            ScopeRecorder scopeRecorder(context, *this);
            // Draw a line for a page boundary if this isn't the first page.
            if (pageIndex > 0 && !DrawingRecorder::useCachedDrawingIfPossible(context, *this, DisplayItem::PrintedContentLineBoundary)) {
                DrawingRecorder lineBoundaryRecorder(context, *this, DisplayItem::PrintedContentLineBoundary, allPagesRect);
                context.save();
                context.setStrokeColor(Color(0, 0, 255));
                context.setFillColor(Color(0, 0, 255));
                context.drawLine(IntPoint(0, currentHeight), IntPoint(pageWidth, currentHeight));
                context.restore();
            }

            AffineTransform transform;
            transform.translate(0, currentHeight);
#if OS(WIN) || OS(MACOSX)
            // Account for the disabling of scaling in spoolPage. In the context
            // of spoolAllPagesWithBoundaries the scale HAS NOT been pre-applied.
            float scale = getPageShrink(pageIndex);
            transform.scale(scale, scale);
#endif
            TransformRecorder transformRecorder(context, *this, transform);
            spoolPage(context, pageIndex);

            currentHeight += pageSizeInPixels.height() + 1;
        }
        pictureBuilder.endRecording()->playback(canvas);
        outputLinkedDestinations(canvas, allPagesRect);
    }

    DisplayItemClient displayItemClient() const { return toDisplayItemClient(this); }

    String debugName() const { return "ChromePrintContext"; }

>>>>>>> miniblink49
protected:
    // Spools the printed page, a subrect of frame(). Skip the scale step.
    // NativeTheme doesn't play well with scaling. Scaling is done browser side
    // instead. Returns the scale to be applied.
    // On Linux, we don't have the problem with NativeTheme, hence we let WebKit
    // do the scaling and ignore the return value.
<<<<<<< HEAD
    virtual float spoolPage(SkPictureBuilder& pictureBuilder, int pageNumber)
    {
        IntRect pageRect = m_pageRects[pageNumber];
        float scale = m_printedPageWidth / pageRect.width();
        GraphicsContext& context = pictureBuilder.context();
=======
    virtual float spoolPage(GraphicsContext& context, int pageNumber)
    {
        IntRect pageRect = m_pageRects[pageNumber];
        float scale = m_printedPageWidth / pageRect.width();
>>>>>>> miniblink49

        AffineTransform transform;
#if OS(POSIX) && !OS(MACOSX)
        transform.scale(scale);
#endif
<<<<<<< HEAD
        transform.translate(static_cast<float>(-pageRect.x()),
            static_cast<float>(-pageRect.y()));
        TransformRecorder transformRecorder(context, pictureBuilder, transform);

        ClipRecorder clipRecorder(context, pictureBuilder,
            DisplayItem::kClipPrintedPage, pageRect);

        frame()->view()->paintContents(context, GlobalPaintNormalPhase, pageRect);

        {
            DrawingRecorder lineBoundaryRecorder(
                context, pictureBuilder,
                DisplayItem::kPrintedContentDestinationLocations, pageRect);
            outputLinkedDestinations(context, pageRect);
        }
=======
        transform.translate(static_cast<float>(-pageRect.x()), static_cast<float>(-pageRect.y()));
        TransformRecorder transformRecorder(context, *this, transform);

        ClipRecorder clipRecorder(context, *this, DisplayItem::ClipPrintedPage, LayoutRect(pageRect));

        frame()->view()->paintContents(&context, pageRect);
>>>>>>> miniblink49

        return scale;
    }

private:
    void dispatchEventsForPrintingOnAllFrames()
    {
<<<<<<< HEAD
        HeapVector<Member<Document>> documents;
        for (Frame* currentFrame = frame(); currentFrame;
             currentFrame = currentFrame->tree().traverseNext(frame())) {
            if (currentFrame->isLocalFrame())
                documents.push_back(toLocalFrame(currentFrame)->document());
=======
        WillBeHeapVector<RefPtrWillBeMember<Document>> documents;
        for (Frame* currentFrame = frame(); currentFrame; currentFrame = currentFrame->tree().traverseNext(frame())) {
            if (currentFrame->isLocalFrame())
                documents.append(toLocalFrame(currentFrame)->document());
>>>>>>> miniblink49
        }

        for (auto& doc : documents)
            doc->dispatchEventsForPrinting();
    }

    // Set when printing.
    float m_printedPageWidth;
};

// Simple class to override some of PrintContext behavior. This is used when
// the frame hosts a plugin that supports custom printing. In this case, we
// want to delegate all printing related calls to the plugin.
class ChromePluginPrintContext final : public ChromePrintContext {
public:
<<<<<<< HEAD
    ChromePluginPrintContext(LocalFrame* frame,
        WebPluginContainerImpl* plugin,
        const WebPrintParams& printParams)
        : ChromePrintContext(frame)
        , m_plugin(plugin)
        , m_printParams(printParams)
    {
    }

    ~ChromePluginPrintContext() override { }

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        visitor->trace(m_plugin);
        ChromePrintContext::trace(visitor);
    }

    void begin(float width, float height) override { }

    void end() override { m_plugin->printEnd(); }
=======
    ChromePluginPrintContext(LocalFrame* frame, WebPluginContainerImpl* plugin, const WebPrintParams& printParams)
        : ChromePrintContext(frame), m_plugin(plugin), m_printParams(printParams)
    {
    }

    ~ChromePluginPrintContext() override {}

    void begin(float width, float height) override
    {
    }

    void end() override
    {
        m_plugin->printEnd();
    }
>>>>>>> miniblink49

    float getPageShrink(int pageNumber) const override
    {
        // We don't shrink the page (maybe we should ask the widget ??)
        return 1.0;
    }

<<<<<<< HEAD
    void computePageRects(const FloatRect& printRect,
        float headerHeight,
        float footerHeight,
        float userScaleFactor,
        float& outPageHeight) override
=======
    void computePageRects(const FloatRect& printRect, float headerHeight, float footerHeight, float userScaleFactor, float& outPageHeight) override
>>>>>>> miniblink49
    {
        m_printParams.printContentArea = IntRect(printRect);
        m_pageRects.fill(IntRect(printRect), m_plugin->printBegin(m_printParams));
    }

<<<<<<< HEAD
    void computePageRectsWithPageSize(
        const FloatSize& pageSizeInPixels) override
    {
        NOTREACHED();
=======
    void computePageRectsWithPageSize(const FloatSize& pageSizeInPixels) override
    {
        ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    }

protected:
    // Spools the printed page, a subrect of frame(). Skip the scale step.
    // NativeTheme doesn't play well with scaling. Scaling is done browser side
    // instead. Returns the scale to be applied.
<<<<<<< HEAD
    float spoolPage(SkPictureBuilder& pictureBuilder, int pageNumber) override
    {
        IntRect pageRect = m_pageRects[pageNumber];
        m_plugin->printPage(pageNumber, pictureBuilder.context(), pageRect);
=======
    float spoolPage(GraphicsContext& context, int pageNumber) override
    {
        IntRect pageRect = m_pageRects[pageNumber];
        m_plugin->printPage(pageNumber, &context, pageRect);
>>>>>>> miniblink49

        return 1.0;
    }

private:
    // Set when printing.
<<<<<<< HEAD
    Member<WebPluginContainerImpl> m_plugin;
=======
    WebPluginContainerImpl* m_plugin;
>>>>>>> miniblink49
    WebPrintParams m_printParams;
};

static WebDataSource* DataSourceForDocLoader(DocumentLoader* loader)
{
    return loader ? WebDataSourceImpl::fromDocumentLoader(loader) : 0;
}

<<<<<<< HEAD
=======
// WebSuspendableTaskWrapper --------------------------------------------------

class WebSuspendableTaskWrapper: public SuspendableTask {
public:
    static PassOwnPtr<WebSuspendableTaskWrapper> create(PassOwnPtr<WebSuspendableTask> task)
    {
        return adoptPtr(new WebSuspendableTaskWrapper(task));
    }

    void run() override
    {
        m_task->run();
    }

    void contextDestroyed() override
    {
        m_task->contextDestroyed();
    }

private:
    explicit WebSuspendableTaskWrapper(PassOwnPtr<WebSuspendableTask> task)
        : m_task(task)
    {
    }

    OwnPtr<WebSuspendableTask> m_task;
};

>>>>>>> miniblink49
// WebFrame -------------------------------------------------------------------

int WebFrame::instanceCount()
{
    return frameCount;
}

WebLocalFrame* WebLocalFrame::frameForCurrentContext()
{
    v8::Local<v8::Context> context = v8::Isolate::GetCurrent()->GetCurrentContext();
    if (context.IsEmpty())
        return 0;
    return frameForContext(context);
}

WebLocalFrame* WebLocalFrame::frameForContext(v8::Local<v8::Context> context)
{
<<<<<<< HEAD
    return WebLocalFrameImpl::fromFrame(
        toLocalFrame(toFrameIfNotDetached(context)));
=======
    return WebLocalFrameImpl::fromFrame(toLocalFrame(toFrameIfNotDetached(context)));
>>>>>>> miniblink49
}

WebLocalFrame* WebLocalFrame::fromFrameOwnerElement(const WebElement& element)
{
<<<<<<< HEAD
    return WebLocalFrameImpl::fromFrameOwnerElement(element);
=======
    return WebLocalFrameImpl::fromFrameOwnerElement(PassRefPtrWillBeRawPtr<Element>(element).get());
>>>>>>> miniblink49
}

bool WebLocalFrameImpl::isWebLocalFrame() const
{
    return true;
}

WebLocalFrame* WebLocalFrameImpl::toWebLocalFrame()
{
    return this;
}

bool WebLocalFrameImpl::isWebRemoteFrame() const
{
    return false;
}

WebRemoteFrame* WebLocalFrameImpl::toWebRemoteFrame()
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return 0;
}

void WebLocalFrameImpl::close()
{
<<<<<<< HEAD
    WebLocalFrame::close();

    m_client = nullptr;

    if (m_devToolsAgent)
        m_devToolsAgent.clear();

    m_selfKeepAlive.clear();
=======
    m_client = nullptr;

    if (m_devToolsAgent) {
        m_devToolsAgent->dispose();
        m_devToolsAgent.clear();
    }

#if ENABLE(OILPAN)
    m_selfKeepAlive.clear();
#else
    deref(); // Balances ref() acquired in WebFrame::create
#endif
>>>>>>> miniblink49
}

WebString WebLocalFrameImpl::uniqueName() const
{
    return frame()->tree().uniqueName();
}

WebString WebLocalFrameImpl::assignedName() const
{
    return frame()->tree().name();
}

void WebLocalFrameImpl::setName(const WebString& name)
{
    frame()->tree().setName(name);
}

WebVector<WebIconURL> WebLocalFrameImpl::iconURLs(int iconTypesMask) const
{
    // The URL to the icon may be in the header. As such, only
    // ask the loader for the icon if it's finished loading.
    if (frame()->document()->loadEventFinished())
        return frame()->document()->iconURLs(iconTypesMask);
    return WebVector<WebIconURL>();
}

<<<<<<< HEAD
void WebLocalFrameImpl::setContentSettingsClient(
    WebContentSettingsClient* contentSettingsClient)
=======
void WebLocalFrameImpl::setRemoteWebLayer(WebLayer* webLayer)
{
    ASSERT_NOT_REACHED();
}

void WebLocalFrameImpl::setContentSettingsClient(WebContentSettingsClient* contentSettingsClient)
>>>>>>> miniblink49
{
    m_contentSettingsClient = contentSettingsClient;
}

<<<<<<< HEAD
void WebLocalFrameImpl::setSharedWorkerRepositoryClient(
    WebSharedWorkerRepositoryClient* client)
{
    m_sharedWorkerRepositoryClient = SharedWorkerRepositoryClientImpl::create(client);
=======
void WebLocalFrameImpl::setSharedWorkerRepositoryClient(WebSharedWorkerRepositoryClient* client)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    m_sharedWorkerRepositoryClient = SharedWorkerRepositoryClientImpl::create(client);
#endif // MINIBLINK_NOT_IMPLEMENTED
    notImplemented();
>>>>>>> miniblink49
}

ScrollableArea* WebLocalFrameImpl::layoutViewportScrollableArea() const
{
    if (FrameView* view = frameView())
        return view->layoutViewportScrollableArea();
    return nullptr;
}

<<<<<<< HEAD
bool WebLocalFrameImpl::isFocused() const
{
    if (!viewImpl() || !viewImpl()->page())
        return false;

    return this == WebFrame::fromFrame(viewImpl()->page()->focusController().focusedFrame());
}

WebSize WebLocalFrameImpl::getScrollOffset() const
{
    if (ScrollableArea* scrollableArea = layoutViewportScrollableArea())
        return scrollableArea->scrollOffsetInt();
=======
WebSize WebLocalFrameImpl::scrollOffset() const
{
    if (ScrollableArea* scrollableArea = layoutViewportScrollableArea())
        return toIntSize(scrollableArea->scrollPosition());
    return WebSize();
}

WebSize WebLocalFrameImpl::minimumScrollOffset() const
{
    if (ScrollableArea* scrollableArea = layoutViewportScrollableArea())
        return toIntSize(scrollableArea->minimumScrollPosition());
    return WebSize();
}

WebSize WebLocalFrameImpl::maximumScrollOffset() const
{
    if (ScrollableArea* scrollableArea = layoutViewportScrollableArea())
        return toIntSize(scrollableArea->maximumScrollPosition());
>>>>>>> miniblink49
    return WebSize();
}

void WebLocalFrameImpl::setScrollOffset(const WebSize& offset)
{
<<<<<<< HEAD
    if (ScrollableArea* scrollableArea = layoutViewportScrollableArea()) {
        scrollableArea->setScrollOffset(ScrollOffset(offset.width, offset.height),
            ProgrammaticScroll);
    }
=======
    if (ScrollableArea* scrollableArea = layoutViewportScrollableArea())
        scrollableArea->setScrollPosition(IntPoint(offset.width, offset.height), ProgrammaticScroll);
>>>>>>> miniblink49
}

WebSize WebLocalFrameImpl::contentsSize() const
{
    if (FrameView* view = frameView())
        return view->contentsSize();
    return WebSize();
}

bool WebLocalFrameImpl::hasVisibleContent() const
{
<<<<<<< HEAD
    LayoutPartItem layoutItem = frame()->ownerLayoutItem();
    if (!layoutItem.isNull() && layoutItem.style()->visibility() != EVisibility::kVisible) {
        return false;
=======
    if (LayoutPart* layoutObject = frame()->ownerLayoutObject()) {
        if (layoutObject->style()->visibility() != VISIBLE)
            return false;
>>>>>>> miniblink49
    }

    if (FrameView* view = frameView())
        return view->visibleWidth() > 0 && view->visibleHeight() > 0;
    return false;
}

WebRect WebLocalFrameImpl::visibleContentRect() const
{
    if (FrameView* view = frameView())
        return view->visibleContentRect();
    return WebRect();
}

bool WebLocalFrameImpl::hasHorizontalScrollbar() const
{
    return frame() && frame()->view() && frame()->view()->horizontalScrollbar();
}

bool WebLocalFrameImpl::hasVerticalScrollbar() const
{
    return frame() && frame()->view() && frame()->view()->verticalScrollbar();
}

WebView* WebLocalFrameImpl::view() const
{
    return viewImpl();
}

<<<<<<< HEAD
=======
void WebLocalFrameImpl::setOpener(WebFrame* opener)
{
    // FIXME: Does this need to move up into WebFrame too?
    if (WebFrame::opener() && !opener && m_client)
        m_client->didDisownOpener(this);

    WebFrame::setOpener(opener);

    ASSERT(m_frame);
    if (m_frame && m_frame->document())
        m_frame->document()->initSecurityContext();
}

>>>>>>> miniblink49
WebDocument WebLocalFrameImpl::document() const
{
    if (!frame() || !frame()->document())
        return WebDocument();
    return WebDocument(frame()->document());
}

<<<<<<< HEAD
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
>>>>>>> miniblink49
WebPerformance WebLocalFrameImpl::performance() const
{
    if (!frame())
        return WebPerformance();
<<<<<<< HEAD
    return WebPerformance(
        DOMWindowPerformance::performance(*(frame()->domWindow())));
=======
    return WebPerformance(DOMWindowPerformance::performance(*(frame()->domWindow())));
}
#endif // MINIBLINK_NOT_IMPLEMENTED

bool WebLocalFrameImpl::dispatchBeforeUnloadEvent()
{
    if (!frame())
        return true;
    return frame()->loader().shouldClose();
>>>>>>> miniblink49
}

void WebLocalFrameImpl::dispatchUnloadEvent()
{
    if (!frame())
        return;
<<<<<<< HEAD
    SubframeLoadingDisabler disabler(frame()->document());
    frame()->loader().dispatchUnloadEvent();
}

void WebLocalFrameImpl::executeScript(const WebScriptSource& source)
{
    DCHECK(frame());
    TextPosition position(OrdinalNumber::fromOneBasedInt(source.startLine),
        OrdinalNumber::first());
    v8::HandleScope handleScope(toIsolate(frame()));
    frame()->script().executeScriptInMainWorld(
        ScriptSourceCode(source.code, source.url, position));
}

void WebLocalFrameImpl::executeScriptInIsolatedWorld(
    int worldID,
    const WebScriptSource* sourcesIn,
    unsigned numSources)
{
    DCHECK(frame());
    CHECK_GT(worldID, 0);
    CHECK_LT(worldID, EmbedderWorldIdLimit);

    HeapVector<ScriptSourceCode> sources = createSourcesVector(sourcesIn, numSources);
    v8::HandleScope handleScope(toIsolate(frame()));
    frame()->script().executeScriptInIsolatedWorld(worldID, sources, 0);
}

void WebLocalFrameImpl::setIsolatedWorldSecurityOrigin(
    int worldID,
    const WebSecurityOrigin& securityOrigin)
{
    DCHECK(frame());
    DOMWrapperWorld::setIsolatedWorldSecurityOrigin(worldID,
        securityOrigin.get());
}

void WebLocalFrameImpl::setIsolatedWorldContentSecurityPolicy(
    int worldID,
    const WebString& policy)
{
    DCHECK(frame());
    DOMWrapperWorld::setIsolatedWorldContentSecurityPolicy(worldID, policy);
}

void WebLocalFrameImpl::setIsolatedWorldHumanReadableName(
    int worldID,
    const WebString& humanReadableName)
{
    DCHECK(frame());
    DOMWrapperWorld::setIsolatedWorldHumanReadableName(worldID,
        humanReadableName);
=======
    frame()->loader().dispatchUnloadEvent();
}

NPObject* WebLocalFrameImpl::windowObject() const
{
    if (!frame() || ScriptForbiddenScope::isScriptForbidden())
        return 0;
    return frame()->script().windowScriptNPObject();
}

void WebLocalFrameImpl::bindToWindowObject(const WebString& name, NPObject* object)
{
    bindToWindowObject(name, object, 0);
}

void WebLocalFrameImpl::bindToWindowObject(const WebString& name, NPObject* object, void*)
{
    if (!frame() || !frame()->script().canExecuteScripts(NotAboutToExecuteScript))
        return;
    frame()->script().bindToWindowObject(frame(), String(name), object);
}

void WebLocalFrameImpl::executeScript(const WebScriptSource& source)
{
    ASSERT(frame());
    TextPosition position(OrdinalNumber::fromOneBasedInt(source.startLine), OrdinalNumber::first());
    v8::HandleScope handleScope(toIsolate(frame()));
    frame()->script().executeScriptInMainWorld(ScriptSourceCode(source.code, source.url, position));
}

void WebLocalFrameImpl::executeScriptInIsolatedWorld(int worldID, const WebScriptSource* sourcesIn, unsigned numSources, int extensionGroup)
{
    ASSERT(frame());
    RELEASE_ASSERT(worldID > 0);
    RELEASE_ASSERT(worldID < EmbedderWorldIdLimit);

    WillBeHeapVector<ScriptSourceCode> sources = createSourcesVector(sourcesIn, numSources);
    v8::HandleScope handleScope(toIsolate(frame()));
    frame()->script().executeScriptInIsolatedWorld(worldID, sources, extensionGroup, 0);
}

void WebLocalFrameImpl::setIsolatedWorldSecurityOrigin(int worldID, const WebSecurityOrigin& securityOrigin)
{
    ASSERT(frame());
    DOMWrapperWorld::setIsolatedWorldSecurityOrigin(worldID, securityOrigin.get());
}

void WebLocalFrameImpl::setIsolatedWorldContentSecurityPolicy(int worldID, const WebString& policy)
{
    ASSERT(frame());
    DOMWrapperWorld::setIsolatedWorldContentSecurityPolicy(worldID, policy);
}

void WebLocalFrameImpl::setIsolatedWorldHumanReadableName(int worldID, const WebString& humanReadableName)
{
    ASSERT(frame());
    DOMWrapperWorld::setIsolatedWorldHumanReadableName(worldID, humanReadableName);
>>>>>>> miniblink49
}

void WebLocalFrameImpl::addMessageToConsole(const WebConsoleMessage& message)
{
<<<<<<< HEAD
    DCHECK(frame());

    MessageLevel webCoreMessageLevel = LogMessageLevel;
=======
    ASSERT(frame());

    MessageLevel webCoreMessageLevel;
>>>>>>> miniblink49
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
<<<<<<< HEAD
    // Unsupported values.
    case WebConsoleMessage::LevelInfo:
        break;
    }

    frame()->document()->addConsoleMessage(ConsoleMessage::create(
        OtherMessageSource, webCoreMessageLevel, message.text,
        SourceLocation::create(message.url, message.lineNumber,
            message.columnNumber, nullptr)));
=======
    default:
        ASSERT_NOT_REACHED();
        return;
    }

    frame()->document()->addConsoleMessage(ConsoleMessage::create(OtherMessageSource, webCoreMessageLevel, message.text));
>>>>>>> miniblink49
}

void WebLocalFrameImpl::collectGarbage()
{
    if (!frame())
        return;
<<<<<<< HEAD
    if (!frame()->settings()->getScriptEnabled())
=======
    if (!frame()->settings()->scriptEnabled())
>>>>>>> miniblink49
        return;
    V8GCController::collectGarbage(v8::Isolate::GetCurrent());
}

<<<<<<< HEAD
v8::Local<v8::Value> WebLocalFrameImpl::executeScriptAndReturnValue(
    const WebScriptSource& source)
{
    DCHECK(frame());

    TextPosition position(OrdinalNumber::fromOneBasedInt(source.startLine),
        OrdinalNumber::first());
    return frame()->script().executeScriptInMainWorldAndReturnValue(
        ScriptSourceCode(source.code, source.url, position));
}

void WebLocalFrameImpl::requestExecuteScriptAndReturnValue(
    const WebScriptSource& source,
    bool userGesture,
    WebScriptExecutionCallback* callback)
{
    DCHECK(frame());

    SuspendableScriptExecutor::createAndRun(
        frame(), 0, createSourcesVector(&source, 1), userGesture, callback);
}

void WebLocalFrameImpl::requestExecuteV8Function(
    v8::Local<v8::Context> context,
    v8::Local<v8::Function> function,
    v8::Local<v8::Value> receiver,
    int argc,
    v8::Local<v8::Value> argv[],
    WebScriptExecutionCallback* callback)
{
    DCHECK(frame());
    SuspendableScriptExecutor::createAndRun(frame(), toIsolate(frame()), context,
        function, receiver, argc, argv,
        callback);
}

void WebLocalFrameImpl::executeScriptInIsolatedWorld(
    int worldID,
    const WebScriptSource* sourcesIn,
    unsigned numSources,
    WebVector<v8::Local<v8::Value>>* results)
{
    DCHECK(frame());
    CHECK_GT(worldID, 0);
    CHECK_LT(worldID, EmbedderWorldIdLimit);

    HeapVector<ScriptSourceCode> sources = createSourcesVector(sourcesIn, numSources);

    if (results) {
        Vector<v8::Local<v8::Value>> scriptResults;
        frame()->script().executeScriptInIsolatedWorld(worldID, sources,
            &scriptResults);
=======
bool WebLocalFrameImpl::checkIfRunInsecureContent(const WebURL& url) const
{
    ASSERT(frame());

    // This is only called (eventually, through proxies and delegates and IPC) from
    // PluginURLFetcher::OnReceivedRedirect for redirects of NPAPI resources.
    //
    // FIXME: Remove this method entirely once we smother NPAPI.
    return !MixedContentChecker::shouldBlockFetch(frame(), WebURLRequest::RequestContextObject, WebURLRequest::FrameTypeNested, url);
}

v8::Local<v8::Value> WebLocalFrameImpl::executeScriptAndReturnValue(const WebScriptSource& source)
{
    ASSERT(frame());

    TextPosition position(OrdinalNumber::fromOneBasedInt(source.startLine), OrdinalNumber::first());
    return frame()->script().executeScriptInMainWorldAndReturnValue(ScriptSourceCode(source.code, source.url, position));
}

void WebLocalFrameImpl::requestExecuteScriptAndReturnValue(const WebScriptSource& source, bool userGesture, WebScriptExecutionCallback* callback)
{
    ASSERT(frame());
    SuspendableScriptExecutor::createAndRun(frame(), 0, createSourcesVector(&source, 1), 0, userGesture, callback);
}

void WebLocalFrameImpl::executeScriptInIsolatedWorld(int worldID, const WebScriptSource* sourcesIn, unsigned numSources, int extensionGroup, WebVector<v8::Local<v8::Value>>* results)
{
    ASSERT(frame());
    RELEASE_ASSERT(worldID > 0);
    RELEASE_ASSERT(worldID < EmbedderWorldIdLimit);

    WillBeHeapVector<ScriptSourceCode> sources = createSourcesVector(sourcesIn, numSources);

    if (results) {
        Vector<v8::Local<v8::Value>> scriptResults;
        frame()->script().executeScriptInIsolatedWorld(worldID, sources, extensionGroup, &scriptResults);
>>>>>>> miniblink49
        WebVector<v8::Local<v8::Value>> v8Results(scriptResults.size());
        for (unsigned i = 0; i < scriptResults.size(); i++)
            v8Results[i] = v8::Local<v8::Value>::New(toIsolate(frame()), scriptResults[i]);
        results->swap(v8Results);
    } else {
        v8::HandleScope handleScope(toIsolate(frame()));
<<<<<<< HEAD
        frame()->script().executeScriptInIsolatedWorld(worldID, sources, 0);
    }
}

void WebLocalFrameImpl::requestExecuteScriptInIsolatedWorld(
    int worldID,
    const WebScriptSource* sourcesIn,
    unsigned numSources,
    bool userGesture,
    WebScriptExecutionCallback* callback)
{
    DCHECK(frame());
    CHECK_GT(worldID, 0);
    CHECK_LT(worldID, EmbedderWorldIdLimit);

    SuspendableScriptExecutor::createAndRun(
        frame(), worldID, createSourcesVector(sourcesIn, numSources), userGesture,
        callback);
}

// TODO(bashi): Consider returning MaybeLocal.
v8::Local<v8::Value> WebLocalFrameImpl::callFunctionEvenIfScriptDisabled(
    v8::Local<v8::Function> function,
    v8::Local<v8::Value> receiver,
    int argc,
    v8::Local<v8::Value> argv[])
{
    DCHECK(frame());
    v8::Local<v8::Value> result;
    if (!V8ScriptRunner::callFunction(
            function, frame()->document(), receiver, argc,
            static_cast<v8::Local<v8::Value>*>(argv), toIsolate(frame()))
             .ToLocal(&result))
=======
        frame()->script().executeScriptInIsolatedWorld(worldID, sources, extensionGroup, 0);
    }
}

void WebLocalFrameImpl::requestExecuteScriptInIsolatedWorld(int worldID, const WebScriptSource* sourcesIn, unsigned numSources, int extensionGroup, bool userGesture, WebScriptExecutionCallback* callback)
{
    ASSERT(frame());
    RELEASE_ASSERT(worldID > 0);
    RELEASE_ASSERT(worldID < EmbedderWorldIdLimit);
    SuspendableScriptExecutor::createAndRun(frame(), worldID, createSourcesVector(sourcesIn, numSources), extensionGroup, userGesture, callback);
}

// TODO(bashi): Consider returning MaybeLocal.
v8::Local<v8::Value> WebLocalFrameImpl::callFunctionEvenIfScriptDisabled(v8::Local<v8::Function> function, v8::Local<v8::Value> receiver, int argc, v8::Local<v8::Value> argv[])
{
    ASSERT(frame());
    v8::Local<v8::Value> result;
    if (!frame()->script().callFunction(function, receiver, argc, static_cast<v8::Local<v8::Value>*>(argv)).ToLocal(&result))
>>>>>>> miniblink49
        return v8::Local<v8::Value>();
    return result;
}

v8::Local<v8::Context> WebLocalFrameImpl::mainWorldScriptContext() const
{
    ScriptState* scriptState = ScriptState::forMainWorld(frame());
<<<<<<< HEAD
    DCHECK(scriptState);
=======
    ASSERT(scriptState->contextIsValid());
>>>>>>> miniblink49
    return scriptState->context();
}

bool WebFrame::scriptCanAccess(WebFrame* target)
{
<<<<<<< HEAD
    return BindingSecurity::shouldAllowAccessToFrame(
        currentDOMWindow(mainThreadIsolate()), target->toImplBase()->frame(),
        BindingSecurity::ErrorReportOption::DoNotReport);
}

void WebLocalFrameImpl::reload(WebFrameLoadType loadType)
{
    // TODO(clamy): Remove this function once RenderFrame calls load for all
    // requests.
    reloadWithOverrideURL(KURL(), loadType);
}

void WebLocalFrameImpl::reloadWithOverrideURL(const WebURL& overrideUrl,
    WebFrameLoadType loadType)
{
    // TODO(clamy): Remove this function once RenderFrame calls load for all
    // requests.
    DCHECK(frame());
    DCHECK(isReloadLoadType(static_cast<FrameLoadType>(loadType)));
    WebURLRequest request = requestForReload(loadType, overrideUrl);
    if (request.isNull())
        return;
    load(request, loadType, WebHistoryItem(), WebHistoryDifferentDocumentLoad,
        false);
=======
    return BindingSecurity::shouldAllowAccessToFrame(mainThreadIsolate(), toCoreFrame(target), DoNotReportSecurityError);
}

void WebLocalFrameImpl::reload(bool ignoreCache)
{
    // TODO(clamy): Remove this function once RenderFrame calls load for all
    // requests.
    reloadWithOverrideURL(KURL(), ignoreCache);
}

void WebLocalFrameImpl::reloadWithOverrideURL(const WebURL& overrideUrl, bool ignoreCache)
{
    // TODO(clamy): Remove this function once RenderFrame calls load for all
    // requests.
    ASSERT(frame());
    WebFrameLoadType loadType = ignoreCache ?
        WebFrameLoadType::ReloadFromOrigin : WebFrameLoadType::Reload;
    WebURLRequest request = requestForReload(loadType, overrideUrl);
    if (request.isNull())
        return;
    load(request, loadType, WebHistoryItem(), WebHistoryDifferentDocumentLoad);
>>>>>>> miniblink49
}

void WebLocalFrameImpl::reloadImage(const WebNode& webNode)
{
    const Node* node = webNode.constUnwrap<Node>();
    if (isHTMLImageElement(*node)) {
        const HTMLImageElement& imageElement = toHTMLImageElement(*node);
        imageElement.forceReload();
    }
}

<<<<<<< HEAD
void WebLocalFrameImpl::reloadLoFiImages()
{
    frame()->document()->fetcher()->reloadLoFiImages();
}

=======
>>>>>>> miniblink49
void WebLocalFrameImpl::loadRequest(const WebURLRequest& request)
{
    // TODO(clamy): Remove this function once RenderFrame calls load for all
    // requests.
<<<<<<< HEAD
    load(request, WebFrameLoadType::Standard, WebHistoryItem(),
        WebHistoryDifferentDocumentLoad, false);
}

void WebLocalFrameImpl::loadHTMLString(const WebData& data,
    const WebURL& baseURL,
    const WebURL& unreachableURL,
    bool replace)
{
    DCHECK(frame());
    loadData(data, WebString::fromUTF8("text/html"), WebString::fromUTF8("UTF-8"),
        baseURL, unreachableURL, replace, WebFrameLoadType::Standard,
        WebHistoryItem(), WebHistoryDifferentDocumentLoad, false);
=======
    load(request, WebFrameLoadType::Standard, WebHistoryItem(), WebHistoryDifferentDocumentLoad);
}

void WebLocalFrameImpl::loadHistoryItem(const WebHistoryItem& item, WebHistoryLoadType loadType,
    WebURLRequest::CachePolicy cachePolicy)
{
    // TODO(clamy): Remove this function once RenderFrame calls load for all
    // requests.
    WebURLRequest request = requestFromHistoryItem(item, cachePolicy);
    load(request, WebFrameLoadType::BackForward, item, loadType);
}

void WebLocalFrameImpl::loadData(const WebData& data, const WebString& mimeType, const WebString& textEncoding, const WebURL& baseURL, const WebURL& unreachableURL, bool replace)
{
    ASSERT(frame());

    // If we are loading substitute data to replace an existing load, then
    // inherit all of the properties of that original request. This way,
    // reload will re-attempt the original request. It is essential that
    // we only do this when there is an unreachableURL since a non-empty
    // unreachableURL informs FrameLoader::reload to load unreachableURL
    // instead of the currently loaded URL.
    ResourceRequest request;
    if (replace && !unreachableURL.isEmpty() && frame()->loader().provisionalDocumentLoader())
        request = frame()->loader().provisionalDocumentLoader()->originalRequest();
    request.setURL(baseURL);
    request.setCheckForBrowserSideNavigation(false);

    FrameLoadRequest frameRequest(0, request, SubstituteData(data, mimeType, textEncoding, unreachableURL));
    ASSERT(frameRequest.substituteData().isValid());
    frameRequest.setLockBackForwardList(replace);
    frame()->loader().load(frameRequest);
}

void WebLocalFrameImpl::loadHTMLString(const WebData& data, const WebURL& baseURL, const WebURL& unreachableURL, bool replace)
{
    ASSERT(frame());
    loadData(data, WebString::fromUTF8("text/html"), WebString::fromUTF8("UTF-8"), baseURL, unreachableURL, replace);
>>>>>>> miniblink49
}

void WebLocalFrameImpl::stopLoading()
{
    if (!frame())
        return;
    // FIXME: Figure out what we should really do here. It seems like a bug
    // that FrameLoader::stopLoading doesn't call stopAllLoaders.
    frame()->loader().stopAllLoaders();
}

WebDataSource* WebLocalFrameImpl::provisionalDataSource() const
{
<<<<<<< HEAD
    DCHECK(frame());
    return DataSourceForDocLoader(frame()->loader().provisionalDocumentLoader());
=======
    ASSERT(frame());

    // We regard the policy document loader as still provisional.
    DocumentLoader* documentLoader = frame()->loader().provisionalDocumentLoader();
    if (!documentLoader)
        documentLoader = frame()->loader().policyDocumentLoader();

    return DataSourceForDocLoader(documentLoader);
>>>>>>> miniblink49
}

WebDataSource* WebLocalFrameImpl::dataSource() const
{
<<<<<<< HEAD
    DCHECK(frame());
=======
    ASSERT(frame());
>>>>>>> miniblink49
    return DataSourceForDocLoader(frame()->loader().documentLoader());
}

void WebLocalFrameImpl::enableViewSourceMode(bool enable)
{
    if (frame())
        frame()->setInViewSourceMode(enable);
}

bool WebLocalFrameImpl::isViewSourceModeEnabled() const
{
    if (!frame())
        return false;
    return frame()->inViewSourceMode();
}

<<<<<<< HEAD
void WebLocalFrameImpl::setReferrerForRequest(WebURLRequest& request,
    const WebURL& referrerURL)
{
    String referrer = referrerURL.isEmpty()
        ? frame()->document()->outgoingReferrer()
        : String(referrerURL.string());
    request.toMutableResourceRequest().setHTTPReferrer(
        SecurityPolicy::generateReferrer(frame()->document()->getReferrerPolicy(),
            request.url(), referrer));
=======
void WebLocalFrameImpl::setReferrerForRequest(WebURLRequest& request, const WebURL& referrerURL)
{
    String referrer = referrerURL.isEmpty() ? frame()->document()->outgoingReferrer() : String(referrerURL.spec().utf16());
    request.toMutableResourceRequest().setHTTPReferrer(SecurityPolicy::generateReferrer(frame()->document()->referrerPolicy(), request.url(), referrer));
>>>>>>> miniblink49
}

void WebLocalFrameImpl::dispatchWillSendRequest(WebURLRequest& request)
{
<<<<<<< HEAD
    frame()->loader().client()->dispatchWillSendRequest(
        request.toMutableResourceRequest());
}

WebAssociatedURLLoader* WebLocalFrameImpl::createAssociatedURLLoader(
    const WebAssociatedURLLoaderOptions& options)
{
    return new WebAssociatedURLLoaderImpl(this, options);
=======
    ResourceResponse response;
    frame()->loader().client()->dispatchWillSendRequest(0, 0, request.toMutableResourceRequest(), response);
}

WebURLLoader* WebLocalFrameImpl::createAssociatedURLLoader(const WebURLLoaderOptions& options)
{
    return new AssociatedURLLoader(this, options);
>>>>>>> miniblink49
}

unsigned WebLocalFrameImpl::unloadListenerCount() const
{
<<<<<<< HEAD
    return frame()->domWindow()->pendingUnloadEventListeners();
=======
    return frame()->localDOMWindow()->pendingUnloadEventListeners();
>>>>>>> miniblink49
}

void WebLocalFrameImpl::replaceSelection(const WebString& text)
{
<<<<<<< HEAD
    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    frame()->editor().replaceSelection(text);
}

void WebLocalFrameImpl::setMarkedText(const WebString& text,
    unsigned location,
    unsigned length)
{
    Vector<CompositionUnderline> decorations;
    frame()->inputMethodController().setComposition(text, decorations, location,
        length);
=======
    bool selectReplacement = false;
    bool smartReplace = true;
    frame()->editor().replaceSelectionWithText(text, selectReplacement, smartReplace);
}

void WebLocalFrameImpl::insertText(const WebString& text)
{
    if (frame()->inputMethodController().hasComposition())
        frame()->inputMethodController().confirmComposition(text);
    else
        frame()->editor().insertText(text, 0);
}

void WebLocalFrameImpl::setMarkedText(const WebString& text, unsigned location, unsigned length)
{
    Vector<CompositionUnderline> decorations;
    frame()->inputMethodController().setComposition(text, decorations, location, length);
>>>>>>> miniblink49
}

void WebLocalFrameImpl::unmarkText()
{
    frame()->inputMethodController().cancelComposition();
}

bool WebLocalFrameImpl::hasMarkedText() const
{
    return frame()->inputMethodController().hasComposition();
}

WebRange WebLocalFrameImpl::markedRange() const
{
<<<<<<< HEAD
    return frame()->inputMethodController().compositionEphemeralRange();
}

bool WebLocalFrameImpl::firstRectForCharacterRange(
    unsigned location,
    unsigned length,
    WebRect& rectInViewport) const
=======
    return frame()->inputMethodController().compositionRange();
}

bool WebLocalFrameImpl::firstRectForCharacterRange(unsigned location, unsigned length, WebRect& rectInViewport) const
>>>>>>> miniblink49
{
    if ((location + length < location) && (location + length))
        length = 0;

    Element* editable = frame()->selection().rootEditableElementOrDocumentElement();
    if (!editable)
        return false;
<<<<<<< HEAD

    // TODO(dglazkov): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  see http://crbug.com/590369 for more details.
    editable->document().updateStyleAndLayoutIgnorePendingStylesheets();

    const EphemeralRange range = PlainTextRange(location, location + length).createRange(*editable);
    if (range.isNull())
        return false;
    IntRect intRect = frame()->editor().firstRectForRange(range);
=======
    RefPtrWillBeRawPtr<Range> range = PlainTextRange(location, location + length).createRange(*editable);
    if (!range)
        return false;
    IntRect intRect = frame()->editor().firstRectForRange(range.get());
>>>>>>> miniblink49
    rectInViewport = WebRect(intRect);
    rectInViewport = frame()->view()->contentsToViewport(rectInViewport);
    return true;
}

<<<<<<< HEAD
size_t WebLocalFrameImpl::characterIndexForPoint(
    const WebPoint& pointInViewport) const
=======
size_t WebLocalFrameImpl::characterIndexForPoint(const WebPoint& pointInViewport) const
>>>>>>> miniblink49
{
    if (!frame())
        return kNotFound;

    IntPoint point = frame()->view()->viewportToContents(pointInViewport);
<<<<<<< HEAD
    HitTestResult result = frame()->eventHandler().hitTestResultAtPoint(
        point, HitTestRequest::ReadOnly | HitTestRequest::Active);
    const EphemeralRange range = frame()->rangeForPoint(result.roundedPointInInnerNodeFrame());
    if (range.isNull())
        return kNotFound;
    Element* editable = frame()->selection().rootEditableElementOrDocumentElement();
    DCHECK(editable);
    return PlainTextRange::create(*editable, range).start();
}

bool WebLocalFrameImpl::executeCommand(const WebString& name)
{
    DCHECK(frame());
=======
    HitTestResult result = frame()->eventHandler().hitTestResultAtPoint(point, HitTestRequest::ReadOnly | HitTestRequest::Active);
    RefPtrWillBeRawPtr<Range> range = frame()->rangeForPoint(result.roundedPointInInnerNodeFrame());
    if (!range)
        return kNotFound;
    Element* editable = frame()->selection().rootEditableElementOrDocumentElement();
    ASSERT(editable);
    return PlainTextRange::create(*editable, *range.get()).start();
}

bool WebLocalFrameImpl::executeCommand(const WebString& name, const WebNode& node)
{
    ASSERT(frame());
>>>>>>> miniblink49

    if (name.length() <= 2)
        return false;

    // Since we don't have NSControl, we will convert the format of command
    // string and call the function on Editor directly.
    String command = name;

    // Make sure the first letter is upper case.
    command.replace(0, 1, command.substring(0, 1).upper());

    // Remove the trailing ':' if existing.
    if (command[command.length() - 1] == UChar(':'))
        command = command.substring(0, command.length() - 1);

<<<<<<< HEAD
    Node* pluginLookupContextNode = m_contextMenuNode && name == "Copy" ? m_contextMenuNode : nullptr;
    WebPluginContainerImpl* pluginContainer = currentPluginContainer(frame(), pluginLookupContextNode);
=======
    WebPluginContainerImpl* pluginContainer = pluginContainerFromNode(frame(), node);
>>>>>>> miniblink49
    if (pluginContainer && pluginContainer->executeEditCommand(name))
        return true;

    return frame()->editor().executeCommand(command);
}

<<<<<<< HEAD
bool WebLocalFrameImpl::executeCommand(const WebString& name,
    const WebString& value)
{
    DCHECK(frame());

    WebPluginContainerImpl* pluginContainer = currentPluginContainer(frame());
=======
bool WebLocalFrameImpl::executeCommand(const WebString& name, const WebString& value, const WebNode& node)
{
    ASSERT(frame());

    WebPluginContainerImpl* pluginContainer = pluginContainerFromNode(frame(), node);
>>>>>>> miniblink49
    if (pluginContainer && pluginContainer->executeEditCommand(name, value))
        return true;

    return frame()->editor().executeCommand(name, value);
}

bool WebLocalFrameImpl::isCommandEnabled(const WebString& name) const
{
<<<<<<< HEAD
    DCHECK(frame());
    return frame()->editor().createCommand(name).isEnabled();
}

void WebLocalFrameImpl::enableSpellChecking(bool enable)
{
    if (enable == isSpellCheckingEnabled())
        return;
    frame()->spellChecker().toggleSpellCheckingEnabled();
}

bool WebLocalFrameImpl::isSpellCheckingEnabled() const
{
    return frame()->spellChecker().isSpellCheckingEnabled();
=======
    ASSERT(frame());
    return frame()->editor().command(name).isEnabled();
}

void WebLocalFrameImpl::enableContinuousSpellChecking(bool enable)
{
    if (enable == isContinuousSpellCheckingEnabled())
        return;
    frame()->spellChecker().toggleContinuousSpellChecking();
}

bool WebLocalFrameImpl::isContinuousSpellCheckingEnabled() const
{
    return frame()->spellChecker().isContinuousSpellCheckingEnabled();
}

void WebLocalFrameImpl::requestTextChecking(const WebElement& webElement)
{
    if (webElement.isNull())
        return;
    frame()->spellChecker().requestTextChecking(*webElement.constUnwrap<Element>());
>>>>>>> miniblink49
}

void WebLocalFrameImpl::replaceMisspelledRange(const WebString& text)
{
<<<<<<< HEAD
    // If this caret selection has two or more markers, this function replace the
    // range covered by the first marker with the specified word as Microsoft Word
    // does.
    if (pluginContainerFromFrame(frame()))
        return;

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  see http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

=======
    // If this caret selection has two or more markers, this function replace the range covered by the first marker with the specified word as Microsoft Word does.
    if (pluginContainerFromFrame(frame()))
        return;
>>>>>>> miniblink49
    frame()->spellChecker().replaceMisspelledRange(text);
}

void WebLocalFrameImpl::removeSpellingMarkers()
{
    frame()->spellChecker().removeSpellingMarkers();
}

bool WebLocalFrameImpl::hasSelection() const
{
    WebPluginContainerImpl* pluginContainer = pluginContainerFromFrame(frame());
    if (pluginContainer)
        return pluginContainer->plugin()->hasSelection();

    // frame()->selection()->isNone() never returns true.
    return frame()->selection().start() != frame()->selection().end();
}

WebRange WebLocalFrameImpl::selectionRange() const
{
<<<<<<< HEAD
    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    return frame()->selection().selection().toNormalizedEphemeralRange();
=======
    return frame()->selection().toNormalizedRange();
>>>>>>> miniblink49
}

WebString WebLocalFrameImpl::selectionAsText() const
{
    WebPluginContainerImpl* pluginContainer = pluginContainerFromFrame(frame());
    if (pluginContainer)
        return pluginContainer->plugin()->selectionAsText();

<<<<<<< HEAD
    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    String text = frame()->selection().selectedText(
        TextIteratorEmitsObjectReplacementCharacter);
=======
    RefPtrWillBeRawPtr<Range> range = frame()->selection().toNormalizedRange();
    if (!range)
        return WebString();

    String text = range->text();
>>>>>>> miniblink49
#if OS(WIN)
    replaceNewlinesWithWindowsStyleNewlines(text);
#endif
    replaceNBSPWithSpace(text);
    return text;
}

WebString WebLocalFrameImpl::selectionAsMarkup() const
{
    WebPluginContainerImpl* pluginContainer = pluginContainerFromFrame(frame());
    if (pluginContainer)
        return pluginContainer->plugin()->selectionAsMarkup();

<<<<<<< HEAD
    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    // Selection normalization and markup generation require clean layout.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    return frame()->selection().selectedHTMLForClipboard();
}

void WebLocalFrameImpl::selectWordAroundPosition(LocalFrame* frame,
    VisiblePosition position)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::selectWordAroundPosition");

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  see http://crbug.com/590369 for more details.
    frame->document()->updateStyleAndLayoutIgnorePendingStylesheets();

=======
    Position startPosition;
    Position endPosition;
    if (!frame()->selection().selection().toNormalizedPositions(startPosition, endPosition))
        return WebString();

    return createMarkup(startPosition, endPosition, AnnotateForInterchange, ConvertBlocksToInlines::NotConvert, ResolveNonLocalURLs);
}

void WebLocalFrameImpl::selectWordAroundPosition(LocalFrame* frame, VisiblePosition position)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::selectWordAroundPosition");
>>>>>>> miniblink49
    frame->selection().selectWordAroundPosition(position);
}

bool WebLocalFrameImpl::selectWordAroundCaret()
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::selectWordAroundCaret");
    FrameSelection& selection = frame()->selection();
    if (selection.isNone() || selection.isRange())
        return false;
<<<<<<< HEAD

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  see http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    return frame()->selection().selectWordAroundPosition(
        selection.selection().visibleStart());
}

void WebLocalFrameImpl::selectRange(const WebPoint& baseInViewport,
    const WebPoint& extentInViewport)
=======
    return frame()->selection().selectWordAroundPosition(selection.selection().visibleStart());
}

void WebLocalFrameImpl::selectRange(const WebPoint& baseInViewport, const WebPoint& extentInViewport)
>>>>>>> miniblink49
{
    moveRangeSelection(baseInViewport, extentInViewport);
}

void WebLocalFrameImpl::selectRange(const WebRange& webRange)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::selectRange");
<<<<<<< HEAD

    // TODO(dglazkov): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  see http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    frame()->selection().setSelectedRange(
        webRange.createEphemeralRange(frame()), VP_DEFAULT_AFFINITY,
        SelectionDirectionalMode::NonDirectional, NotUserTriggered);
}

WebString WebLocalFrameImpl::rangeAsText(const WebRange& webRange)
{
    // TODO(dglazkov): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  see http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    DocumentLifecycle::DisallowTransitionScope disallowTransition(
        frame()->document()->lifecycle());

    return plainText(webRange.createEphemeralRange(frame()),
        TextIteratorEmitsObjectReplacementCharacter);
=======
    if (RefPtrWillBeRawPtr<Range> range = static_cast<PassRefPtrWillBeRawPtr<Range>>(webRange))
        frame()->selection().setSelectedRange(range.get(), VP_DEFAULT_AFFINITY, FrameSelection::NonDirectional, NotUserTriggered);
>>>>>>> miniblink49
}

void WebLocalFrameImpl::moveRangeSelectionExtent(const WebPoint& point)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::moveRangeSelectionExtent");
<<<<<<< HEAD

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    frame()->selection().moveRangeSelectionExtent(
        frame()->view()->viewportToContents(point));
}

void WebLocalFrameImpl::moveRangeSelection(
    const WebPoint& baseInViewport,
    const WebPoint& extentInViewport,
    WebFrame::TextGranularity granularity)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::moveRangeSelection");

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

=======
    frame()->selection().moveRangeSelectionExtent(frame()->view()->viewportToContents(point));
}

void WebLocalFrameImpl::moveRangeSelection(const WebPoint& baseInViewport, const WebPoint& extentInViewport, WebFrame::TextGranularity granularity)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::moveRangeSelection");
>>>>>>> miniblink49
    blink::TextGranularity blinkGranularity = blink::CharacterGranularity;
    if (granularity == WebFrame::WordGranularity)
        blinkGranularity = blink::WordGranularity;
    frame()->selection().moveRangeSelection(
        visiblePositionForViewportPoint(baseInViewport),
<<<<<<< HEAD
        visiblePositionForViewportPoint(extentInViewport), blinkGranularity);
=======
        visiblePositionForViewportPoint(extentInViewport),
        blinkGranularity);
>>>>>>> miniblink49
}

void WebLocalFrameImpl::moveCaretSelection(const WebPoint& pointInViewport)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::moveCaretSelection");
<<<<<<< HEAD

    // TODO(editing-dev): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  see http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();
    const IntPoint pointInContents = frame()->view()->viewportToContents(pointInViewport);
    frame()->selection().moveCaretSelection(pointInContents);
=======
    Element* editable = frame()->selection().rootEditableElement();
    if (!editable)
        return;

    VisiblePosition position = visiblePositionForViewportPoint(pointInViewport);
    frame()->selection().moveTo(position, UserTriggered);
>>>>>>> miniblink49
}

bool WebLocalFrameImpl::setEditableSelectionOffsets(int start, int end)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::setEditableSelectionOffsets");
<<<<<<< HEAD

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    return frame()->inputMethodController().setEditableSelectionOffsets(
        PlainTextRange(start, end));
}

bool WebLocalFrameImpl::setCompositionFromExistingText(
    int compositionStart,
    int compositionEnd,
    const WebVector<WebCompositionUnderline>& underlines)
=======
    return frame()->inputMethodController().setEditableSelectionOffsets(PlainTextRange(start, end));
}

bool WebLocalFrameImpl::setCompositionFromExistingText(int compositionStart, int compositionEnd, const WebVector<WebCompositionUnderline>& underlines)
>>>>>>> miniblink49
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::setCompositionFromExistingText");
    if (!frame()->editor().canEdit())
        return false;

    InputMethodController& inputMethodController = frame()->inputMethodController();
    inputMethodController.cancelComposition();

    if (compositionStart == compositionEnd)
        return true;

<<<<<<< HEAD
    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    inputMethodController.setCompositionFromExistingText(
        CompositionUnderlineVectorBuilder(underlines), compositionStart,
        compositionEnd);
=======
    inputMethodController.setCompositionFromExistingText(CompositionUnderlineVectorBuilder(underlines), compositionStart, compositionEnd);
>>>>>>> miniblink49

    return true;
}

void WebLocalFrameImpl::extendSelectionAndDelete(int before, int after)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::extendSelectionAndDelete");
    if (WebPlugin* plugin = focusedPluginIfInputMethodSupported()) {
        plugin->extendSelectionAndDelete(before, after);
        return;
    }
<<<<<<< HEAD

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    frame()->inputMethodController().extendSelectionAndDelete(before, after);
}

void WebLocalFrameImpl::deleteSurroundingText(int before, int after)
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::deleteSurroundingText");
    if (WebPlugin* plugin = focusedPluginIfInputMethodSupported()) {
        plugin->deleteSurroundingText(before, after);
        return;
    }

    // TODO(editing-dev): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    frame()->inputMethodController().deleteSurroundingText(before, after);
}

=======
    frame()->inputMethodController().extendSelectionAndDelete(before, after);
}

>>>>>>> miniblink49
void WebLocalFrameImpl::setCaretVisible(bool visible)
{
    frame()->selection().setCaretVisible(visible);
}

<<<<<<< HEAD
VisiblePosition WebLocalFrameImpl::visiblePositionForViewportPoint(
    const WebPoint& pointInViewport)
{
    return visiblePositionForContentsPoint(
        frame()->view()->viewportToContents(pointInViewport), frame());
=======
VisiblePosition WebLocalFrameImpl::visiblePositionForViewportPoint(const WebPoint& pointInViewport)
{
    return visiblePositionForContentsPoint(frame()->view()->viewportToContents(pointInViewport), frame());
>>>>>>> miniblink49
}

WebPlugin* WebLocalFrameImpl::focusedPluginIfInputMethodSupported()
{
<<<<<<< HEAD
    WebPluginContainerImpl* container = WebLocalFrameImpl::currentPluginContainer(frame());
=======
    WebPluginContainerImpl* container = WebLocalFrameImpl::pluginContainerFromNode(frame(), WebNode(frame()->document()->focusedElement()));
>>>>>>> miniblink49
    if (container && container->supportsInputMethod())
        return container->plugin();
    return 0;
}

<<<<<<< HEAD
int WebLocalFrameImpl::printBegin(const WebPrintParams& printParams,
    const WebNode& constrainToNode)
{
    DCHECK(!frame()->document()->isFrameSet());
=======
int WebLocalFrameImpl::printBegin(const WebPrintParams& printParams, const WebNode& constrainToNode)
{
    ASSERT(!frame()->document()->isFrameSet());
>>>>>>> miniblink49
    WebPluginContainerImpl* pluginContainer = nullptr;
    if (constrainToNode.isNull()) {
        // If this is a plugin document, check if the plugin supports its own
        // printing. If it does, we will delegate all printing to that.
        pluginContainer = pluginContainerFromFrame(frame());
    } else {
        // We only support printing plugin nodes for now.
        pluginContainer = toWebPluginContainerImpl(constrainToNode.pluginContainer());
    }

    if (pluginContainer && pluginContainer->supportsPaginatedPrint())
<<<<<<< HEAD
        m_printContext = new ChromePluginPrintContext(frame(), pluginContainer, printParams);
    else
        m_printContext = new ChromePrintContext(frame());

    FloatRect rect(0, 0, static_cast<float>(printParams.printContentArea.width),
        static_cast<float>(printParams.printContentArea.height));
=======
        m_printContext = adoptPtrWillBeNoop(new ChromePluginPrintContext(frame(), pluginContainer, printParams));
    else
        m_printContext = adoptPtrWillBeNoop(new ChromePrintContext(frame()));

    FloatRect rect(0, 0, static_cast<float>(printParams.printContentArea.width), static_cast<float>(printParams.printContentArea.height));
>>>>>>> miniblink49
    m_printContext->begin(rect.width(), rect.height());
    float pageHeight;
    // We ignore the overlays calculation for now since they are generated in the
    // browser. pageHeight is actually an output parameter.
    m_printContext->computePageRects(rect, 0, 0, 1.0, pageHeight);

    return static_cast<int>(m_printContext->pageCount());
}

float WebLocalFrameImpl::getPrintPageShrink(int page)
{
<<<<<<< HEAD
    DCHECK(m_printContext);
    DCHECK_GE(page, 0);
=======
    ASSERT(m_printContext && page >= 0);
>>>>>>> miniblink49
    return m_printContext->getPageShrink(page);
}

float WebLocalFrameImpl::printPage(int page, WebCanvas* canvas)
{
<<<<<<< HEAD
    DCHECK(m_printContext);
    DCHECK_GE(page, 0);
    DCHECK(frame());
    DCHECK(frame()->document());

    return m_printContext->spoolSinglePage(canvas, page);
=======
#if 1 // ENABLE(PRINTING)

    ASSERT(m_printContext && page >= 0 && frame() && frame()->document());

    return m_printContext->spoolSinglePage(canvas, page);
#else
    return 0;
#endif
>>>>>>> miniblink49
}

void WebLocalFrameImpl::printEnd()
{
<<<<<<< HEAD
    DCHECK(m_printContext);
=======
    ASSERT(m_printContext);
>>>>>>> miniblink49
    m_printContext->end();
    m_printContext.clear();
}

bool WebLocalFrameImpl::isPrintScalingDisabledForPlugin(const WebNode& node)
{
<<<<<<< HEAD
    WebPluginContainerImpl* pluginContainer = node.isNull() ? pluginContainerFromFrame(frame())
                                                            : toWebPluginContainerImpl(node.pluginContainer());
=======
    WebPluginContainerImpl* pluginContainer =  node.isNull() ? pluginContainerFromFrame(frame()) : toWebPluginContainerImpl(node.pluginContainer());
>>>>>>> miniblink49

    if (!pluginContainer || !pluginContainer->supportsPaginatedPrint())
        return false;

    return pluginContainer->isPrintScalingDisabled();
}

<<<<<<< HEAD
bool WebLocalFrameImpl::getPrintPresetOptionsForPlugin(
    const WebNode& node,
    WebPrintPresetOptions* presetOptions)
{
    WebPluginContainerImpl* pluginContainer = node.isNull() ? pluginContainerFromFrame(frame())
                                                            : toWebPluginContainerImpl(node.pluginContainer());
=======
bool WebLocalFrameImpl::getPrintPresetOptionsForPlugin(const WebNode& node, WebPrintPresetOptions* presetOptions)
{
    WebPluginContainerImpl* pluginContainer = node.isNull() ? pluginContainerFromFrame(frame()) : toWebPluginContainerImpl(node.pluginContainer());
>>>>>>> miniblink49

    if (!pluginContainer || !pluginContainer->supportsPaginatedPrint())
        return false;

    return pluginContainer->getPrintPresetOptionsFromDocument(presetOptions);
}

bool WebLocalFrameImpl::hasCustomPageSizeStyle(int pageIndex)
{
<<<<<<< HEAD
    return frame()->document()->styleForPage(pageIndex)->getPageSizeType() != PAGE_SIZE_AUTO;
=======
    return frame()->document()->styleForPage(pageIndex)->pageSizeType() != PAGE_SIZE_AUTO;
>>>>>>> miniblink49
}

bool WebLocalFrameImpl::isPageBoxVisible(int pageIndex)
{
    return frame()->document()->isPageBoxVisible(pageIndex);
}

<<<<<<< HEAD
void WebLocalFrameImpl::pageSizeAndMarginsInPixels(int pageIndex,
    WebDoubleSize& pageSize,
    int& marginTop,
    int& marginRight,
    int& marginBottom,
    int& marginLeft)
{
    DoubleSize size = pageSize;
    frame()->document()->pageSizeAndMarginsInPixels(
        pageIndex, size, marginTop, marginRight, marginBottom, marginLeft);
    pageSize = size;
}

WebString WebLocalFrameImpl::pageProperty(const WebString& propertyName,
    int pageIndex)
{
    DCHECK(m_printContext);
    return m_printContext->pageProperty(frame(), propertyName.utf8().data(),
        pageIndex);
}

void WebLocalFrameImpl::printPagesWithBoundaries(
    WebCanvas* canvas,
    const WebSize& pageSizeInPixels)
{
    DCHECK(m_printContext);

    m_printContext->spoolAllPagesWithBoundaries(
        canvas, FloatSize(pageSizeInPixels.width, pageSizeInPixels.height));
=======
void WebLocalFrameImpl::pageSizeAndMarginsInPixels(int pageIndex, WebSize& pageSize, int& marginTop, int& marginRight, int& marginBottom, int& marginLeft)
{
    IntSize size = pageSize;
    frame()->document()->pageSizeAndMarginsInPixels(pageIndex, size, marginTop, marginRight, marginBottom, marginLeft);
    pageSize = size;
}

WebString WebLocalFrameImpl::pageProperty(const WebString& propertyName, int pageIndex)
{
    ASSERT(m_printContext);
    return m_printContext->pageProperty(frame(), propertyName.utf8().data(), pageIndex);
}

bool WebLocalFrameImpl::find(int identifier, const WebString& searchText, const WebFindOptions& options, bool wrapWithinFrame, WebRect* selectionRect)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    return ensureTextFinder().find(identifier, searchText, options, wrapWithinFrame, selectionRect);
#endif // MINIBLINK_NOT_IMPLEMENTED
    return false;
}

void WebLocalFrameImpl::stopFinding(bool clearSelection)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (m_textFinder) {
        if (!clearSelection)
            setFindEndstateFocusAndSelection();
        m_textFinder->stopFindingAndClearSelection();
    }
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::scopeStringMatches(int identifier, const WebString& searchText, const WebFindOptions& options, bool reset)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    ensureTextFinder().scopeStringMatches(identifier, searchText, options, reset);
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::cancelPendingScopingEffort()
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (m_textFinder)
        m_textFinder->cancelPendingScopingEffort();
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::increaseMatchCount(int count, int identifier)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    // This function should only be called on the mainframe.
    ASSERT(!parent());
    ensureTextFinder().increaseMatchCount(identifier, count);
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::resetMatchCount()
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    ensureTextFinder().resetMatchCount();
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::dispatchMessageEventWithOriginCheck(const WebSecurityOrigin& intendedTargetOrigin, const WebDOMEvent& event)
{
    ASSERT(!event.isNull());
    frame()->localDOMWindow()->dispatchMessageEventWithOriginCheck(intendedTargetOrigin.get(), event, nullptr);
}

int WebLocalFrameImpl::findMatchMarkersVersion() const
{
    ASSERT(!parent());
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (m_textFinder)
        return m_textFinder->findMatchMarkersVersion();
#endif // MINIBLINK_NOT_IMPLEMENTED
    return 0;
}

int WebLocalFrameImpl::selectNearestFindMatch(const WebFloatPoint& point, WebRect* selectionRect)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    ASSERT(!parent());
    return ensureTextFinder().selectNearestFindMatch(point, selectionRect);
#endif // MINIBLINK_NOT_IMPLEMENTED
    return -1;
}

WebFloatRect WebLocalFrameImpl::activeFindMatchRect()
{
    ASSERT(!parent());
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (m_textFinder)
        return m_textFinder->activeFindMatchRect();
#endif // MINIBLINK_NOT_IMPLEMENTED
    return WebFloatRect();
}

void WebLocalFrameImpl::findMatchRects(WebVector<WebFloatRect>& outputRects)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    ASSERT(!parent());
    ensureTextFinder().findMatchRects(outputRects);
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::setTickmarks(const WebVector<WebRect>& tickmarks)
{
    if (frameView()) {
        Vector<IntRect> tickmarksConverted(tickmarks.size());
        for (size_t i = 0; i < tickmarks.size(); ++i)
            tickmarksConverted[i] = tickmarks[i];
        frameView()->setTickmarks(tickmarksConverted);
    }
}

WebString WebLocalFrameImpl::contentAsText(size_t maxChars) const
{
    if (!frame())
        return WebString();
    StringBuilder text;
    frameContentAsPlainText(maxChars, frame(), text);
    return text.toString();
}

WebString WebLocalFrameImpl::contentAsMarkup() const
{
    if (!frame())
        return WebString();
    return createMarkup(frame()->document());
}

WebString WebLocalFrameImpl::layoutTreeAsText(LayoutAsTextControls toShow) const
{
    LayoutAsTextBehavior behavior = LayoutAsTextShowAllLayers;

    if (toShow & LayoutAsTextWithLineTrees)
        behavior |= LayoutAsTextShowLineTrees;

    if (toShow & LayoutAsTextDebug)
        behavior |= LayoutAsTextShowCompositedLayers | LayoutAsTextShowAddresses | LayoutAsTextShowIDAndClass | LayoutAsTextShowLayerNesting;

    if (toShow & LayoutAsTextPrinting)
        behavior |= LayoutAsTextPrintingMode;

    return externalRepresentation(frame(), behavior);
}

void WebLocalFrameImpl::registerTestInterface(const WebString& name, WebTestInterfaceFactory* factory)
{
    m_testInterfaces.set(name, adoptPtr(factory));
}

v8::Local<v8::Value> WebLocalFrameImpl::createTestInterface(const AtomicString& name)
{
    if (WebTestInterfaceFactory* factory = m_testInterfaces.get(name)) {
        ScriptState* scriptState = ScriptState::forMainWorld(frame());
        ASSERT(scriptState->contextIsValid());
        v8::EscapableHandleScope handleScope(scriptState->isolate());
        ScriptState::Scope scope(scriptState);
        return handleScope.Escape(factory->createInstance(scriptState->context()));
    }
    return v8::Local<v8::Value>();
}

WebString WebLocalFrameImpl::markerTextForListItem(const WebElement& webElement) const
{
    return blink::markerTextForListItem(const_cast<Element*>(webElement.constUnwrap<Element>()));
}

void WebLocalFrameImpl::printPagesWithBoundaries(WebCanvas* canvas, const WebSize& pageSizeInPixels)
{
    ASSERT(m_printContext);

    m_printContext->spoolAllPagesWithBoundaries(canvas, FloatSize(pageSizeInPixels.width, pageSizeInPixels.height));
>>>>>>> miniblink49
}

WebRect WebLocalFrameImpl::selectionBoundsRect() const
{
<<<<<<< HEAD
    return hasSelection() ? WebRect(IntRect(frame()->selection().bounds()))
                          : WebRect();
=======
    return hasSelection() ? WebRect(IntRect(frame()->selection().bounds())) : WebRect();
}

bool WebLocalFrameImpl::selectionStartHasSpellingMarkerFor(int from, int length) const
{
    if (!frame())
        return false;
    return frame()->spellChecker().selectionStartHasSpellingMarkerFor(from, length);
>>>>>>> miniblink49
}

WebString WebLocalFrameImpl::layerTreeAsText(bool showDebugInfo) const
{
    if (!frame())
        return WebString();

<<<<<<< HEAD
    return WebString(frame()->layerTreeAsText(
        showDebugInfo ? LayerTreeIncludesDebugInfo : LayerTreeNormal));
}

// WebLocalFrameImpl public --------------------------------------------------

WebLocalFrame* WebLocalFrame::create(WebTreeScopeType scope,
    WebFrameClient* client,
    WebFrame* opener)
{
    return WebLocalFrameImpl::create(scope, client, opener);
}

WebLocalFrame* WebLocalFrame::createProvisional(WebFrameClient* client,
    WebRemoteFrame* oldWebFrame,
    WebSandboxFlags flags)
{
    return WebLocalFrameImpl::createProvisional(client, oldWebFrame, flags);
}

WebLocalFrameImpl* WebLocalFrameImpl::create(WebTreeScopeType scope,
    WebFrameClient* client,
    WebFrame* opener)
{
    WebLocalFrameImpl* frame = new WebLocalFrameImpl(scope, client);
    frame->setOpener(opener);
    return frame;
}

WebLocalFrameImpl* WebLocalFrameImpl::createProvisional(
    WebFrameClient* client,
    WebRemoteFrame* oldWebFrame,
    WebSandboxFlags flags)
{
    DCHECK(client);
    WebLocalFrameImpl* webFrame = new WebLocalFrameImpl(oldWebFrame, client);
    Frame* oldFrame = oldWebFrame->toImplBase()->frame();
    webFrame->setParent(oldWebFrame->parent());
    webFrame->setOpener(oldWebFrame->opener());
    // Note: this *always* temporarily sets a frame owner, even for main frames!
    // When a core Frame is created with no owner, it attempts to set itself as
    // the main frame of the Page. However, this is a provisional frame, and may
    // disappear, so Page::m_mainFrame can't be updated just yet.
    FrameOwner* tempOwner = DummyFrameOwner::create();
    // TODO(dcheng): This block is very similar to initializeCoreFrame. Try to
    // reuse it here.
    LocalFrame* frame = LocalFrame::create(
        webFrame->m_frameLoaderClientImpl.get(), oldFrame->host(), tempOwner,
        client->interfaceProvider(), client->interfaceRegistry());
    // Set the name and unique name directly, bypassing any of the normal logic
    // to calculate unique name.
    frame->tree().setPrecalculatedName(
        toWebRemoteFrameImpl(oldWebFrame)->frame()->tree().name(),
        toWebRemoteFrameImpl(oldWebFrame)->frame()->tree().uniqueName());
    webFrame->setCoreFrame(frame);

    frame->setOwner(oldFrame->owner());

    if (frame->owner() && frame->owner()->isRemote())
        toRemoteFrameOwner(frame->owner())
            ->setSandboxFlags(static_cast<SandboxFlags>(flags));

    // We must call init() after m_frame is assigned because it is referenced
    // during init(). Note that this may dispatch JS events; the frame may be
    // detached after init() returns.
    frame->init();
    return webFrame;
}

WebLocalFrameImpl::WebLocalFrameImpl(WebTreeScopeType scope,
    WebFrameClient* client)
    : WebLocalFrame(scope)
    , m_frameLoaderClientImpl(FrameLoaderClientImpl::create(this))
=======
    return WebString(frame()->layerTreeAsText(showDebugInfo ? LayerTreeIncludesDebugInfo : LayerTreeNormal));
}

// WebLocalFrameImpl public ---------------------------------------------------------

WebLocalFrame* WebLocalFrame::create(WebTreeScopeType scope, WebFrameClient* client)
{
    return WebLocalFrameImpl::create(scope, client);
}

WebLocalFrameImpl* WebLocalFrameImpl::create(WebTreeScopeType scope, WebFrameClient* client)
{
    WebLocalFrameImpl* frame = new WebLocalFrameImpl(scope, client);
#if ENABLE(OILPAN)
    return frame;
#else
    return adoptRef(frame).leakRef();
#endif
}

#ifndef NDEBUG
DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, webLocalFrameImplCounter, ("WebLocalFrameImplCounter"));
#endif

WebLocalFrameImpl::WebLocalFrameImpl(WebTreeScopeType scope, WebFrameClient* client)
    : WebLocalFrame(scope)
    , m_frameLoaderClientImpl(this)
>>>>>>> miniblink49
    , m_frameWidget(0)
    , m_client(client)
    , m_autofillClient(0)
    , m_contentSettingsClient(0)
    , m_inputEventsScaleFactorForEmulation(1)
<<<<<<< HEAD
    , m_webDevToolsFrontend(0)
    , m_inputMethodController(new WebInputMethodControllerImpl(this))
    , m_selfKeepAlive(this)
{
    DCHECK(m_client);
    frameCount++;
}

WebLocalFrameImpl::WebLocalFrameImpl(WebRemoteFrame* oldWebFrame,
    WebFrameClient* client)
    : WebLocalFrameImpl(oldWebFrame->inShadowTree()
            ? WebTreeScopeType::Shadow
            : WebTreeScopeType::Document,
        client)
{
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
    , m_userMediaClientImpl(this)
    , m_geolocationClientProxy(GeolocationClientProxy::create(client ? client->geolocationClient() : 0))
#endif // MINIBLINK_NOT_IMPLEMENTED
    , m_webDevToolsFrontend(0)
#if ENABLE(OILPAN)
    , m_selfKeepAlive(this)
#endif
{
    Platform::current()->incrementStatsCounter(webFrameActiveCount);
    frameCount++;
#ifndef NDEBUG
    webLocalFrameImplCounter.increment();
#endif
>>>>>>> miniblink49
}

WebLocalFrameImpl::~WebLocalFrameImpl()
{
<<<<<<< HEAD
    // The widget for the frame, if any, must have already been closed.
    DCHECK(!m_frameWidget);
    frameCount--;
}

DEFINE_TRACE(WebLocalFrameImpl)
{
    visitor->trace(m_frameLoaderClientImpl);
    visitor->trace(m_frame);
    visitor->trace(m_devToolsAgent);
    visitor->trace(m_textFinder);
    visitor->trace(m_printContext);
    visitor->trace(m_contextMenuNode);
    WebFrame::traceFrames(visitor, this);
    WebFrameImplBase::trace(visitor);
}

void WebLocalFrameImpl::setCoreFrame(LocalFrame* frame)
{
    m_frame = frame;
}

void WebLocalFrameImpl::initializeCoreFrame(FrameHost* host,
    FrameOwner* owner,
    const AtomicString& name,
    const AtomicString& uniqueName)
{
    setCoreFrame(
        LocalFrame::create(m_frameLoaderClientImpl.get(), host, owner,
            client() ? client()->interfaceProvider() : nullptr,
            client() ? client()->interfaceRegistry() : nullptr));
    frame()->tree().setPrecalculatedName(name, uniqueName);
    // We must call init() after m_frame is assigned because it is referenced
    // during init(). Note that this may dispatch JS events; the frame may be
    // detached after init() returns.
    frame()->init();
    if (frame()) {
        if (frame()->loader().stateMachine()->isDisplayingInitialEmptyDocument() && !parent() && !opener() && frame()->settings()->getShouldReuseGlobalForUnownedMainFrame()) {
            frame()->document()->getSecurityOrigin()->grantUniversalAccess();
        }

        // TODO(dominickn): This interface should be document-scoped rather than
        // frame-scoped, as the resulting banner event is dispatched to
        // frame()->document().
        //     frame()->interfaceRegistry()->addInterface(WTF::bind(
        //         &AppBannerController::bindMojoRequest, wrapWeakPersistent(frame())));
        //
        //     frame()->interfaceRegistry()->addInterface(WTF::bind(
        //         &InstallationServiceImpl::create, wrapWeakPersistent(frame())));
    }
}

LocalFrame* WebLocalFrameImpl::createChildFrame(
    const FrameLoadRequest& request,
    const AtomicString& name,
    HTMLFrameOwnerElement* ownerElement)
{
    DCHECK(m_client);
    TRACE_EVENT0("blink", "WebLocalFrameImpl::createChildframe");
    WebTreeScopeType scope = frame()->document() == ownerElement->treeScope()
        ? WebTreeScopeType::Document
        : WebTreeScopeType::Shadow;
    WebFrameOwnerProperties ownerProperties(
        ownerElement->browsingContextContainerName(),
        ownerElement->scrollingMode(), ownerElement->marginWidth(),
        ownerElement->marginHeight(), ownerElement->allowFullscreen(),
        ownerElement->allowPaymentRequest(), ownerElement->csp(),
        ownerElement->delegatedPermissions());
=======
    Platform::current()->decrementStatsCounter(webFrameActiveCount);
    frameCount--;
#ifndef NDEBUG
    webLocalFrameImplCounter.decrement();
#endif

#if !ENABLE(OILPAN)
    cancelPendingScopingEffort();
#endif
}

#if ENABLE(OILPAN)
DEFINE_TRACE(WebLocalFrameImpl)
{
    visitor->trace(m_frame);
    visitor->trace(m_devToolsAgent);
    visitor->trace(m_inspectorOverlay);
    visitor->trace(m_printContext);
#ifdef MINIBLINK_NOT_IMPLEMENTED
    visitor->trace(m_textFinder);
    visitor->trace(m_geolocationClientProxy);
#endif // MINIBLINK_NOT_IMPLEMENTED
    visitor->template registerWeakMembers<WebFrame, &WebFrame::clearWeakFrames>(this);
    WebFrame::traceFrames(visitor, this);
}
#endif

void WebLocalFrameImpl::setCoreFrame(PassRefPtrWillBeRawPtr<LocalFrame> frame)
{
    m_frame = frame;

#ifdef MINIBLINK_NOT_IMPLEMENTED
    // FIXME: we shouldn't add overhead to every frame by registering these objects when they're not used.
    if (m_frame) {
        if (m_client)
            providePushControllerTo(*m_frame, m_client->pushClient());

        provideNotificationPermissionClientTo(*m_frame, NotificationPermissionClientImpl::create());
        provideUserMediaTo(*m_frame, &m_userMediaClientImpl);
        provideGeolocationTo(*m_frame, m_geolocationClientProxy.get());
        m_geolocationClientProxy->setController(GeolocationController::from(m_frame.get()));
        provideMIDITo(*m_frame, MIDIClientProxy::create(m_client ? m_client->webMIDIClient() : nullptr));
        provideLocalFileSystemTo(*m_frame, LocalFileSystemClient::create());
        provideNavigatorContentUtilsTo(*m_frame, NavigatorContentUtilsClientImpl::create(this));

        if (RuntimeEnabledFeatures::screenOrientationEnabled())
            ScreenOrientationController::provideTo(*m_frame, m_client ? m_client->webScreenOrientationClient() : nullptr);
        if (RuntimeEnabledFeatures::presentationEnabled())
            PresentationController::provideTo(*m_frame, m_client ? m_client->presentationClient() : nullptr);
        if (RuntimeEnabledFeatures::permissionsEnabled())
            PermissionController::provideTo(*m_frame, m_client ? m_client->permissionClient() : nullptr);
        if (RuntimeEnabledFeatures::webVREnabled())
            VRController::provideTo(*m_frame, m_client ? m_client->webVRClient() : nullptr);
    }
#endif // MINIBLINK_NOT_IMPLEMENTED
}

PassRefPtrWillBeRawPtr<LocalFrame> WebLocalFrameImpl::initializeCoreFrame(FrameHost* host, FrameOwner* owner, const AtomicString& name, const AtomicString& fallbackName)
{
    RefPtrWillBeRawPtr<LocalFrame> frame = LocalFrame::create(&m_frameLoaderClientImpl, host, owner);
    setCoreFrame(frame);
    frame->tree().setName(name, fallbackName);
    // We must call init() after m_frame is assigned because it is referenced
    // during init(). Note that this may dispatch JS events; the frame may be
    // detached after init() returns.
    frame->init();
    return frame;
}

PassRefPtrWillBeRawPtr<LocalFrame> WebLocalFrameImpl::createChildFrame(const FrameLoadRequest& request,
    const AtomicString& name, HTMLFrameOwnerElement* ownerElement)
{
    ASSERT(m_client);
    WebTreeScopeType scope = frame()->document() == ownerElement->treeScope()
        ? WebTreeScopeType::Document
        : WebTreeScopeType::Shadow;
    WebLocalFrameImpl* webframeChild = toWebLocalFrameImpl(m_client->createChildFrame(this, scope, name, static_cast<WebSandboxFlags>(ownerElement->sandboxFlags())));
    if (!webframeChild)
        return nullptr;

>>>>>>> miniblink49
    // FIXME: Using subResourceAttributeName as fallback is not a perfect
    // solution. subResourceAttributeName returns just one attribute name. The
    // element might not have the attribute, and there might be other attributes
    // which can identify the element.
<<<<<<< HEAD
    AtomicString uniqueName = frame()->tree().calculateUniqueNameForNewChildFrame(
        name,
        ownerElement->getAttribute(ownerElement->subResourceAttributeName()));
    WebLocalFrameImpl* webframeChild = toWebLocalFrameImpl(m_client->createChildFrame(
        this, scope, name, uniqueName,
        static_cast<WebSandboxFlags>(ownerElement->getSandboxFlags()),
        ownerProperties));
    if (!webframeChild)
        return nullptr;

    webframeChild->initializeCoreFrame(frame()->host(), ownerElement, name,
        uniqueName);
    // Initializing the core frame may cause the new child to be detached, since
    // it may dispatch a load event in the parent.
    if (!webframeChild->parent())
        return nullptr;

    // If we're moving in the back/forward list, we might want to replace the
    // content of this child frame with whatever was there at that point.
    HistoryItem* childItem = nullptr;
    if (isBackForwardLoadType(frame()->loader().loadType()) && !frame()->document()->loadEventFinished())
        childItem = webframeChild->client()->historyItemForNewChildFrame();
=======
    RefPtrWillBeRawPtr<LocalFrame> child = webframeChild->initializeCoreFrame(frame()->host(), ownerElement, name, ownerElement->getAttribute(ownerElement->subResourceAttributeName()));
    // Initializing the core frame may cause the new child to be detached, since
    // it may dispatch a load event in the parent.
    if (!child->tree().parent())
        return nullptr;

    // If we're moving in the back/forward list, we might want to replace the content
    // of this child frame with whatever was there at that point.
    RefPtrWillBeRawPtr<HistoryItem> childItem = nullptr;
    if (isBackForwardLoadType(frame()->loader().loadType()) && !frame()->document()->loadEventFinished())
        childItem = PassRefPtrWillBeRawPtr<HistoryItem>(webframeChild->client()->historyItemForNewChildFrame(webframeChild));
>>>>>>> miniblink49

    FrameLoadRequest newRequest = request;
    FrameLoadType loadType = FrameLoadTypeStandard;
    if (childItem) {
<<<<<<< HEAD
        newRequest = FrameLoadRequest(
            request.originDocument(),
            FrameLoader::resourceRequestFromHistoryItem(
                childItem, WebCachePolicy::UseProtocolCachePolicy));
        loadType = FrameLoadTypeInitialHistoryLoad;
    }
    webframeChild->frame()->loader().load(newRequest, loadType, childItem);
=======
        newRequest = FrameLoadRequest(request.originDocument(),
            FrameLoader::resourceRequestFromHistoryItem(childItem.get(), UseProtocolCachePolicy));
        loadType = FrameLoadTypeInitialHistoryLoad;
    }
    child->loader().load(newRequest, loadType, childItem.get());
>>>>>>> miniblink49

    // Note a synchronous navigation (about:blank) would have already processed
    // onload, so it is possible for the child frame to have already been
    // detached by script in the page.
<<<<<<< HEAD
    if (!webframeChild->parent())
        return nullptr;
    return webframeChild->frame();
=======
    if (!child->tree().parent())
        return nullptr;
    return child;
>>>>>>> miniblink49
}

void WebLocalFrameImpl::didChangeContentsSize(const IntSize& size)
{
<<<<<<< HEAD
    if (m_textFinder && m_textFinder->totalMatchCount() > 0)
        m_textFinder->increaseMarkerVersion();
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
    // This is only possible on the main frame.
    if (m_textFinder && m_textFinder->totalMatchCount() > 0) {
        ASSERT(!parent());
        m_textFinder->increaseMarkerVersion();
    }
#endif // MINIBLINK_NOT_IMPLEMENTED
>>>>>>> miniblink49
}

void WebLocalFrameImpl::createFrameView()
{
    TRACE_EVENT0("blink", "WebLocalFrameImpl::createFrameView");

<<<<<<< HEAD
    DCHECK(
        frame()); // If frame() doesn't exist, we probably didn't init properly.

    WebViewImpl* webView = viewImpl();

    // Check if we're shutting down.
    if (!webView->page())
        return;

    bool isMainFrame = !parent();
    IntSize initialSize = (isMainFrame || !frameWidget())
        ? webView->mainFrameSize()
        : (IntSize)frameWidget()->size();
    bool isTransparent = !isMainFrame && parent()->isWebRemoteFrame()
        ? true
        : webView->isTransparent();

    frame()->createView(initialSize, webView->baseBackgroundColor(),
        isTransparent);
    if (isMainFrame) {
        frame()->view()->setInitialViewportSize(
            webView->pageScaleConstraintsSet().initialViewportSize());
    }
    if (webView->shouldAutoResize() && frame()->isLocalRoot())
        frame()->view()->enableAutoSizeMode(webView->minAutoSize(),
            webView->maxAutoSize());

    frame()->view()->setInputEventsTransformForEmulation(
        m_inputEventsOffsetForEmulation, m_inputEventsScaleFactorForEmulation);
    frame()->view()->setDisplayMode(webView->displayMode());
=======
    ASSERT(frame()); // If frame() doesn't exist, we probably didn't init properly.

    WebViewImpl* webView = viewImpl();
    bool isLocalRoot = frame()->isLocalRoot();
    if (isLocalRoot)
        webView->suppressInvalidations(true);

    IntSize initialSize = frameWidget() ? (IntSize)frameWidget()->size() : webView->mainFrameSize();

    frame()->createView(initialSize, webView->baseBackgroundColor(), webView->isTransparent());
    if (webView->shouldAutoResize() && isLocalRoot)
        frame()->view()->enableAutoSizeMode(webView->minAutoSize(), webView->maxAutoSize());

    frame()->view()->setInputEventsTransformForEmulation(m_inputEventsOffsetForEmulation, m_inputEventsScaleFactorForEmulation);
    frame()->view()->setDisplayMode(webView->displayMode());
    frame()->view()->setTopContentInset(m_topContentInset);

    if (isLocalRoot)
        webView->suppressInvalidations(false);
>>>>>>> miniblink49
}

WebLocalFrameImpl* WebLocalFrameImpl::fromFrame(LocalFrame* frame)
{
    if (!frame)
<<<<<<< HEAD
        return nullptr;
=======
        return 0;
>>>>>>> miniblink49
    return fromFrame(*frame);
}

WebLocalFrameImpl* WebLocalFrameImpl::fromFrame(LocalFrame& frame)
{
    FrameLoaderClient* client = frame.loader().client();
    if (!client || !client->isFrameLoaderClientImpl())
<<<<<<< HEAD
        return nullptr;
=======
        return 0;
>>>>>>> miniblink49
    return toFrameLoaderClientImpl(client)->webFrame();
}

WebLocalFrameImpl* WebLocalFrameImpl::fromFrameOwnerElement(Element* element)
{
<<<<<<< HEAD
    if (!element->isFrameOwnerElement())
        return nullptr;
    return fromFrame(
        toLocalFrame(toHTMLFrameOwnerElement(element)->contentFrame()));
=======
    // FIXME: Why do we check specifically for <iframe> and <frame> here? Why can't we get the WebLocalFrameImpl from an <object> element, for example.
    if (!isHTMLFrameElementBase(element))
        return 0;
    return fromFrame(toLocalFrame(toHTMLFrameElementBase(element)->contentFrame()));
>>>>>>> miniblink49
}

WebViewImpl* WebLocalFrameImpl::viewImpl() const
{
    if (!frame())
<<<<<<< HEAD
        return nullptr;
=======
        return 0;
>>>>>>> miniblink49
    return WebViewImpl::fromPage(frame()->page());
}

WebDataSourceImpl* WebLocalFrameImpl::dataSourceImpl() const
{
    return static_cast<WebDataSourceImpl*>(dataSource());
}

WebDataSourceImpl* WebLocalFrameImpl::provisionalDataSourceImpl() const
{
    return static_cast<WebDataSourceImpl*>(provisionalDataSource());
}

void WebLocalFrameImpl::setFindEndstateFocusAndSelection()
{
<<<<<<< HEAD
    if (!m_textFinder || !m_textFinder->activeMatchFrame())
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
    WebLocalFrameImpl* mainFrameImpl = viewImpl()->mainFrameImpl();

    if (this != mainFrameImpl->activeMatchFrame())
>>>>>>> miniblink49
        return;

    if (Range* activeMatch = m_textFinder->activeMatch()) {
        // If the user has set the selection since the match was found, we
        // don't focus anything.
        VisibleSelection selection(frame()->selection().selection());
        if (!selection.isNone())
            return;

<<<<<<< HEAD
        // Need to clean out style and layout state before querying
        // Element::isFocusable().
        frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();
=======
        // Need to clean out style and layout state before querying Element::isFocusable().
        frame()->document()->updateLayoutIgnorePendingStylesheets();
>>>>>>> miniblink49

        // Try to find the first focusable node up the chain, which will, for
        // example, focus links if we have found text within the link.
        Node* node = activeMatch->firstNode();
        if (node && node->isInShadowTree()) {
<<<<<<< HEAD
            if (Node* host = node->ownerShadowHost()) {
=======
            if (Node* host = node->shadowHost()) {
>>>>>>> miniblink49
                if (isHTMLInputElement(*host) || isHTMLTextAreaElement(*host))
                    node = host;
            }
        }
<<<<<<< HEAD
        const EphemeralRange activeMatchRange(activeMatch);
        if (node) {
            for (Node& runner : NodeTraversal::inclusiveAncestorsOf(*node)) {
                if (!runner.isElementNode())
                    continue;
                Element& element = toElement(runner);
                if (element.isFocusable()) {
                    // Found a focusable parent node. Set the active match as the
                    // selection and focus to the focusable node.
                    frame()->selection().setSelection(
                        SelectionInDOMTree::Builder()
                            .setBaseAndExtent(activeMatchRange)
                            .build());
                    frame()->document()->setFocusedElement(
                        &element, FocusParams(SelectionBehaviorOnFocus::None, WebFocusTypeNone, nullptr));
                    return;
                }
=======
        for (; node; node = node->parentNode()) {
            if (!node->isElementNode())
                continue;
            Element* element = toElement(node);
            if (element->isFocusable()) {
                // Found a focusable parent node. Set the active match as the
                // selection and focus to the focusable node.
                frame()->selection().setSelection(VisibleSelection(activeMatch));
                frame()->document()->setFocusedElement(element);
                return;
>>>>>>> miniblink49
            }
        }

        // Iterate over all the nodes in the range until we find a focusable node.
        // This, for example, sets focus to the first link if you search for
        // text and text that is within one or more links.
<<<<<<< HEAD
        for (Node& runner : activeMatchRange.nodes()) {
            if (!runner.isElementNode())
                continue;
            Element& element = toElement(runner);
            if (element.isFocusable()) {
                frame()->document()->setFocusedElement(
                    &element, FocusParams(SelectionBehaviorOnFocus::None, WebFocusTypeNone, nullptr));
=======
        node = activeMatch->firstNode();
        for (; node && node != activeMatch->pastLastNode(); node = NodeTraversal::next(*node)) {
            if (!node->isElementNode())
                continue;
            Element* element = toElement(node);
            if (element->isFocusable()) {
                frame()->document()->setFocusedElement(element);
>>>>>>> miniblink49
                return;
            }
        }

        // No node related to the active match was focusable, so set the
        // active match as the selection (so that when you end the Find session,
        // you'll have the last thing you found highlighted) and make sure that
        // we have nothing focused (otherwise you might have text selected but
        // a link focused, which is weird).
<<<<<<< HEAD
        frame()->selection().setSelection(SelectionInDOMTree::Builder()
                                              .setBaseAndExtent(activeMatchRange)
                                              .build());
        frame()->document()->clearFocusedElement();
=======
        frame()->selection().setSelection(VisibleSelection(activeMatch));
        frame()->document()->setFocusedElement(nullptr);
>>>>>>> miniblink49

        // Finally clear the active match, for two reasons:
        // We just finished the find 'session' and we don't want future (potentially
        // unrelated) find 'sessions' operations to start at the same place.
<<<<<<< HEAD
        // The WebLocalFrameImpl could get reused and the activeMatch could end up
        // pointing to a document that is no longer valid. Keeping an invalid
        // reference around is just asking for trouble.
        m_textFinder->resetActiveMatch();
    }
}

void WebLocalFrameImpl::didFail(const ResourceError& error,
    bool wasProvisional,
    HistoryCommitType commitType)
=======
        // The WebLocalFrameImpl could get reused and the activeMatch could end up pointing
        // to a document that is no longer valid. Keeping an invalid reference around
        // is just asking for trouble.
        m_textFinder->resetActiveMatch();
    }
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::didFail(const ResourceError& error, bool wasProvisional, HistoryCommitType commitType)
>>>>>>> miniblink49
{
    if (!client())
        return;
    WebURLError webError = error;
    WebHistoryCommitType webCommitType = static_cast<WebHistoryCommitType>(commitType);
<<<<<<< HEAD

    if (WebPluginContainerImpl* plugin = pluginContainerFromFrame(frame()))
        plugin->didFailLoading(error);

=======
>>>>>>> miniblink49
    if (wasProvisional)
        client()->didFailProvisionalLoad(this, webError, webCommitType);
    else
        client()->didFailLoad(this, webError, webCommitType);
}

<<<<<<< HEAD
void WebLocalFrameImpl::didFinish()
{
    if (!client())
        return;

    if (WebPluginContainerImpl* plugin = pluginContainerFromFrame(frame()))
        plugin->didFinishLoading();

    client()->didFinishLoad(this);
}

=======
>>>>>>> miniblink49
void WebLocalFrameImpl::setCanHaveScrollbars(bool canHaveScrollbars)
{
    frame()->view()->setCanHaveScrollbars(canHaveScrollbars);
}

<<<<<<< HEAD
void WebLocalFrameImpl::setInputEventsTransformForEmulation(
    const IntSize& offset,
    float contentScaleFactor)
=======
void WebLocalFrameImpl::setInputEventsTransformForEmulation(const IntSize& offset, float contentScaleFactor)
>>>>>>> miniblink49
{
    m_inputEventsOffsetForEmulation = offset;
    m_inputEventsScaleFactorForEmulation = contentScaleFactor;
    if (frame()->view())
<<<<<<< HEAD
        frame()->view()->setInputEventsTransformForEmulation(
            m_inputEventsOffsetForEmulation, m_inputEventsScaleFactorForEmulation);
=======
        frame()->view()->setInputEventsTransformForEmulation(m_inputEventsOffsetForEmulation, m_inputEventsScaleFactorForEmulation);
>>>>>>> miniblink49
}

void WebLocalFrameImpl::loadJavaScriptURL(const KURL& url)
{
    // This is copied from ScriptController::executeScriptIfJavaScriptURL.
    // Unfortunately, we cannot just use that method since it is private, and
    // it also doesn't quite behave as we require it to for bookmarklets. The
    // key difference is that we need to suppress loading the string result
    // from evaluating the JS URL if executing the JS URL resulted in a
    // location change. We also allow a JS URL to be loaded even if scripts on
    // the page are otherwise disabled.

    if (!frame()->document() || !frame()->page())
        return;

<<<<<<< HEAD
    Document* ownerDocument(frame()->document());

    // Protect privileged pages against bookmarklets and other javascript
    // manipulations.
    if (SchemeRegistry::shouldTreatURLSchemeAsNotAllowingJavascriptURLs(
            frame()->document()->url().protocol()))
        return;

    String script = decodeURLEscapeSequences(
        url.getString().substring(strlen("javascript:")));
    UserGestureIndicator gestureIndicator(DocumentUserGestureToken::create(
        frame()->document(), UserGestureToken::NewGesture));
    v8::HandleScope handleScope(toIsolate(frame()));
    v8::Local<v8::Value> result = frame()->script().executeScriptInMainWorldAndReturnValue(
        ScriptSourceCode(script));
=======
    RefPtrWillBeRawPtr<Document> ownerDocument(frame()->document());

    // Protect privileged pages against bookmarklets and other javascript manipulations.
    if (SchemeRegistry::shouldTreatURLSchemeAsNotAllowingJavascriptURLs(frame()->document()->url().protocol()))
        return;

    String script = decodeURLEscapeSequences(url.string().substring(strlen("javascript:")));
    UserGestureIndicator gestureIndicator(DefinitelyProcessingNewUserGesture);
    v8::HandleScope handleScope(toIsolate(frame()));
    v8::Local<v8::Value> result = frame()->script().executeScriptInMainWorldAndReturnValue(ScriptSourceCode(script));
>>>>>>> miniblink49
    if (result.IsEmpty() || !result->IsString())
        return;
    String scriptResult = toCoreString(v8::Local<v8::String>::Cast(result));
    if (!frame()->navigationScheduler().locationChangePending())
<<<<<<< HEAD
        frame()->loader().replaceDocumentWhileExecutingJavaScriptURL(scriptResult,
            ownerDocument);
}

HitTestResult WebLocalFrameImpl::hitTestResultForVisualViewportPos(
    const IntPoint& posInViewport)
{
    IntPoint rootFramePoint(
        frame()->host()->visualViewport().viewportToRootFrame(posInViewport));
    IntPoint docPoint(frame()->view()->rootFrameToContents(rootFramePoint));
    HitTestResult result = frame()->eventHandler().hitTestResultAtPoint(
        docPoint, HitTestRequest::ReadOnly | HitTestRequest::Active);
    result.setToShadowHostIfInUserAgentShadowRoot();
    return result;
=======
        frame()->loader().replaceDocumentWhileExecutingJavaScriptURL(scriptResult, ownerDocument.get());
>>>>>>> miniblink49
}

static void ensureFrameLoaderHasCommitted(FrameLoader& frameLoader)
{
    // Internally, Blink uses CommittedMultipleRealLoads to track whether the
    // next commit should create a new history item or not. Ensure we have
    // reached that state.
    if (frameLoader.stateMachine()->committedMultipleRealLoads())
        return;
<<<<<<< HEAD
    frameLoader.stateMachine()->advanceTo(
        FrameLoaderStateMachine::CommittedMultipleRealLoads);
=======
    frameLoader.stateMachine()->advanceTo(FrameLoaderStateMachine::CommittedMultipleRealLoads);
}

void WebLocalFrameImpl::initializeToReplaceRemoteFrame(WebRemoteFrame* oldWebFrame, const WebString& name, WebSandboxFlags flags)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    Frame* oldFrame = toCoreFrame(oldWebFrame);
    // Note: this *always* temporarily sets a frame owner, even for main frames!
    // When a core Frame is created with no owner, it attempts to set itself as
    // the main frame of the Page. However, this is a provisional frame, and may
    // disappear, so Page::m_mainFrame can't be updated just yet.
    OwnPtrWillBeRawPtr<FrameOwner> tempOwner = RemoteBridgeFrameOwner::create(nullptr, SandboxNone);
    m_frame = LocalFrame::create(&m_frameLoaderClientImpl, oldFrame->host(), tempOwner.get());
    m_frame->setOwner(oldFrame->owner());
    if (m_frame->owner() && !m_frame->owner()->isLocal())
        toRemoteBridgeFrameOwner(m_frame->owner())->setSandboxFlags(static_cast<SandboxFlags>(flags));
    m_frame->tree().setName(name);
    setParent(oldWebFrame->parent());
    // We must call init() after m_frame is assigned because it is referenced
    // during init(). Note that this may dispatch JS events; the frame may be
    // detached after init() returns.
    m_frame->init();
#endif // MINIBLINK_NOT_IMPLEMENTED
>>>>>>> miniblink49
}

void WebLocalFrameImpl::setAutofillClient(WebAutofillClient* autofillClient)
{
    m_autofillClient = autofillClient;
}

WebAutofillClient* WebLocalFrameImpl::autofillClient()
{
    return m_autofillClient;
}

<<<<<<< HEAD
void WebLocalFrameImpl::setDevToolsAgentClient(
    WebDevToolsAgentClient* devToolsClient)
{
    DCHECK(devToolsClient);
    m_devToolsAgent = WebDevToolsAgentImpl::create(this, devToolsClient);
=======
void WebLocalFrameImpl::setDevToolsAgentClient(WebDevToolsAgentClient* devToolsClient)
{
#ifndef MINIBLINK_NO_DEVTOOLS
    if (devToolsClient) {
        m_devToolsAgent = WebDevToolsAgentImpl::create(this, devToolsClient);
    } else {
        m_devToolsAgent->willBeDestroyed();
        m_devToolsAgent->dispose();
        m_devToolsAgent.clear();
    }
#endif // MINIBLINK_NO_DEVTOOLSLINK_NOT_IMPLEMENTED
}

InspectorOverlay* WebLocalFrameImpl::inspectorOverlay()
{
    if (!m_inspectorOverlay)
        m_inspectorOverlay = InspectorOverlayImpl::createEmpty();
    return m_inspectorOverlay.get();
>>>>>>> miniblink49
}

WebDevToolsAgent* WebLocalFrameImpl::devToolsAgent()
{
    return m_devToolsAgent.get();
}

<<<<<<< HEAD
WebLocalFrameImpl* WebLocalFrameImpl::localRoot()
{
    // This can't use the LocalFrame::localFrameRoot, since it may be called
    // when the WebLocalFrame exists but the core LocalFrame does not.
    // TODO(alexmos, dcheng): Clean this up to only calculate this in one place.
    WebLocalFrameImpl* localRoot = this;
    while (localRoot->parent() && localRoot->parent()->isWebLocalFrame())
        localRoot = toWebLocalFrameImpl(localRoot->parent());
    return localRoot;
}

void WebLocalFrameImpl::sendPings(const WebURL& destinationURL)
{
    DCHECK(frame());
    DCHECK(m_contextMenuNode.get());
    Element* anchor = m_contextMenuNode->enclosingLinkEventParentOrSelf();
=======
void WebLocalFrameImpl::sendPings(const WebNode& contextNode, const WebURL& destinationURL)
{
    ASSERT(frame());
    Element* anchor = contextNode.constUnwrap<Node>()->enclosingLinkEventParentOrSelf();
>>>>>>> miniblink49
    if (isHTMLAnchorElement(anchor))
        toHTMLAnchorElement(anchor)->sendPings(destinationURL);
}

<<<<<<< HEAD
bool WebLocalFrameImpl::dispatchBeforeUnloadEvent(bool isReload)
{
    if (!frame())
        return true;

    return frame()->loader().shouldClose(isReload);
}

WebURLRequest WebLocalFrameImpl::requestFromHistoryItem(
    const WebHistoryItem& item,
    WebCachePolicy cachePolicy) const
{
    HistoryItem* historyItem = item;
    ResourceRequest request = FrameLoader::resourceRequestFromHistoryItem(historyItem, cachePolicy);
    return WrappedResourceRequest(request);
}

WebURLRequest WebLocalFrameImpl::requestForReload(
    WebFrameLoadType loadType,
    const WebURL& overrideUrl) const
{
    DCHECK(frame());
=======
WebURLRequest WebLocalFrameImpl::requestFromHistoryItem(const WebHistoryItem& item,
    WebURLRequest::CachePolicy cachePolicy) const
{
    RefPtrWillBeRawPtr<HistoryItem> historyItem = PassRefPtrWillBeRawPtr<HistoryItem>(item);
    ResourceRequest request = FrameLoader::resourceRequestFromHistoryItem(
        historyItem.get(), static_cast<ResourceRequestCachePolicy>(cachePolicy));
    return WrappedResourceRequest(request);
}

WebURLRequest WebLocalFrameImpl::requestForReload(WebFrameLoadType loadType,
    const WebURL& overrideUrl) const
{
    ASSERT(frame());
>>>>>>> miniblink49
    ResourceRequest request = frame()->loader().resourceRequestForReload(
        static_cast<FrameLoadType>(loadType), overrideUrl);
    return WrappedResourceRequest(request);
}

<<<<<<< HEAD
void WebLocalFrameImpl::load(const WebURLRequest& request,
    WebFrameLoadType webFrameLoadType,
    const WebHistoryItem& item,
    WebHistoryLoadType webHistoryLoadType,
    bool isClientRedirect)
{
    DCHECK(frame());
    DCHECK(!request.isNull());
    const ResourceRequest& resourceRequest = request.toResourceRequest();

    if (resourceRequest.url().protocolIs("javascript") && webFrameLoadType == WebFrameLoadType::Standard) {
=======
void WebLocalFrameImpl::load(const WebURLRequest& request, WebFrameLoadType webFrameLoadType,
    const WebHistoryItem& item, WebHistoryLoadType webHistoryLoadType)
{
    ASSERT(frame());
    ASSERT(!request.isNull());
    const ResourceRequest& resourceRequest = request.toResourceRequest();

    if (resourceRequest.url().protocolIs("javascript")
        && webFrameLoadType == WebFrameLoadType::Standard) {
>>>>>>> miniblink49
        loadJavaScriptURL(resourceRequest.url());
        return;
    }

    FrameLoadRequest frameRequest = FrameLoadRequest(nullptr, resourceRequest);
<<<<<<< HEAD
    if (isClientRedirect)
        frameRequest.setClientRedirect(ClientRedirectPolicy::ClientRedirect);
    HistoryItem* historyItem = item;
    frame()->loader().load(
        frameRequest, static_cast<FrameLoadType>(webFrameLoadType), historyItem,
        static_cast<HistoryLoadType>(webHistoryLoadType));
}

void WebLocalFrameImpl::loadData(const WebData& data,
    const WebString& mimeType,
    const WebString& textEncoding,
    const WebURL& baseURL,
    const WebURL& unreachableURL,
    bool replace,
    WebFrameLoadType webFrameLoadType,
    const WebHistoryItem& item,
    WebHistoryLoadType webHistoryLoadType,
    bool isClientRedirect)
{
    DCHECK(frame());

    // If we are loading substitute data to replace an existing load, then
    // inherit all of the properties of that original request. This way,
    // reload will re-attempt the original request. It is essential that
    // we only do this when there is an unreachableURL since a non-empty
    // unreachableURL informs FrameLoader::reload to load unreachableURL
    // instead of the currently loaded URL.
    ResourceRequest request;
    if (replace && !unreachableURL.isEmpty() && frame()->loader().provisionalDocumentLoader())
        request = frame()->loader().provisionalDocumentLoader()->originalRequest();
    request.setURL(baseURL);
    request.setCheckForBrowserSideNavigation(false);

    FrameLoadRequest frameRequest(
        0, request, SubstituteData(data, mimeType, textEncoding, unreachableURL));
    DCHECK(frameRequest.substituteData().isValid());
    frameRequest.setReplacesCurrentItem(replace);
    if (isClientRedirect)
        frameRequest.setClientRedirect(ClientRedirectPolicy::ClientRedirect);

    HistoryItem* historyItem = item;
    frame()->loader().load(
        frameRequest, static_cast<FrameLoadType>(webFrameLoadType), historyItem,
        static_cast<HistoryLoadType>(webHistoryLoadType));
}

bool WebLocalFrameImpl::maybeRenderFallbackContent(
    const WebURLError& error) const
{
    DCHECK(frame());

    if (!frame()->owner() || !frame()->owner()->canRenderFallbackContent())
        return false;

    FrameLoader& frameloader = frame()->loader();
    frameloader.loadFailed(frameloader.documentLoader(), error);
    return true;
}

=======
    RefPtrWillBeRawPtr<HistoryItem> historyItem = PassRefPtrWillBeRawPtr<HistoryItem>(item);
    frame()->loader().load(
        frameRequest, static_cast<FrameLoadType>(webFrameLoadType), historyItem.get(),
        static_cast<HistoryLoadType>(webHistoryLoadType));
}

>>>>>>> miniblink49
bool WebLocalFrameImpl::isLoading() const
{
    if (!frame() || !frame()->document())
        return false;
<<<<<<< HEAD
    return frame()->loader().stateMachine()->isDisplayingInitialEmptyDocument() || frame()->loader().hasProvisionalNavigation() || !frame()->document()->loadEventFinished();
}

bool WebLocalFrameImpl::isNavigationScheduledWithin(
    double intervalInSeconds) const
{
    return frame() && frame()->navigationScheduler().isNavigationScheduledWithin(intervalInSeconds);
=======
    return frame()->loader().stateMachine()->isDisplayingInitialEmptyDocument() || frame()->loader().provisionalDocumentLoader() || !frame()->document()->loadEventFinished();
}

bool WebLocalFrameImpl::isResourceLoadInProgress() const
{
    if (!frame() || !frame()->document())
        return false;
    return frame()->document()->fetcher()->requestCount();
>>>>>>> miniblink49
}

void WebLocalFrameImpl::setCommittedFirstRealLoad()
{
<<<<<<< HEAD
    DCHECK(frame());
    ensureFrameLoaderHasCommitted(frame()->loader());
}

void WebLocalFrameImpl::setHasReceivedUserGesture()
{
    if (frame())
        frame()->setDocumentHasReceivedUserGesture();
}

=======
    ASSERT(frame());
    ensureFrameLoaderHasCommitted(frame()->loader());
}

>>>>>>> miniblink49
void WebLocalFrameImpl::sendOrientationChangeEvent()
{
    if (!frame())
        return;

<<<<<<< HEAD
    // Screen Orientation API
    //   if (ScreenOrientationControllerImpl::from(*frame()))
    //     ScreenOrientationControllerImpl::from(*frame())->notifyOrientationChanged();

    // Legacy window.orientation API
    if (RuntimeEnabledFeatures::orientationEventEnabled() && frame()->domWindow())
        frame()->domWindow()->sendOrientationChangeEvent();
}

void WebLocalFrameImpl::didCallAddSearchProvider()
{
    UseCounter::count(frame(), UseCounter::ExternalAddSearchProvider);
}

void WebLocalFrameImpl::didCallIsSearchProviderInstalled()
{
    UseCounter::count(frame(), UseCounter::ExternalIsSearchProviderInstalled);
}

void WebLocalFrameImpl::requestFind(int identifier,
    const WebString& searchText,
    const WebFindOptions& options)
{
    // Send "no results" if this frame has no visible content.
    if (!hasVisibleContent() && !options.force) {
        client()->reportFindInPageMatchCount(identifier, 0 /* count */,
            true /* finalUpdate */);
        return;
    }

    WebRange currentSelection = selectionRange();
    bool result = false;
    bool activeNow = false;

    // Search for an active match only if this frame is focused or if this is a
    // find next request.
    if (isFocused() || options.findNext) {
        result = find(identifier, searchText, options, false /* wrapWithinFrame */,
            &activeNow);
    }

    if (result && !options.findNext) {
        // Indicate that at least one match has been found. 1 here means
        // possibly more matches could be coming.
        client()->reportFindInPageMatchCount(identifier, 1 /* count */,
            false /* finalUpdate */);
    }

    // There are three cases in which scoping is needed:
    //
    // (1) This is an initial find request (|options.findNext| is false). This
    // will be the first scoping effort for this find session.
    //
    // (2) Something has been selected since the last search. This means that we
    // cannot just increment the current match ordinal; we need to re-generate
    // it.
    //
    // (3) TextFinder::Find() found what should be the next match (|result| is
    // true), but was unable to activate it (|activeNow| is false). This means
    // that the text containing this match was dynamically added since the last
    // scope of the frame. The frame needs to be re-scoped so that any matches
    // in the new text can be highlighted and included in the reported number of
    // matches.
    //
    // If none of these cases are true, then we just report the current match
    // count without scoping.
    if (/* (1) */ options.findNext && /* (2) */ currentSelection.isNull() &&
        /* (3) */ !(result && !activeNow)) {
        // Force report of the actual count.
        increaseMatchCount(0, identifier);
        return;
    }

    // Start a new scoping request. If the scoping function determines that it
    // needs to scope, it will defer until later.
    ensureTextFinder().startScopingStringMatches(identifier, searchText, options);
}

bool WebLocalFrameImpl::find(int identifier,
    const WebString& searchText,
    const WebFindOptions& options,
    bool wrapWithinFrame,
    bool* activeNow)
{
    if (!frame())
        return false;

    // Unlikely, but just in case we try to find-in-page on a detached frame.
    DCHECK(frame()->host());

    // Up-to-date, clean tree is required for finding text in page, since it
    // relies on TextIterator to look over the text.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    return ensureTextFinder().find(identifier, searchText, options,
        wrapWithinFrame, activeNow);
}

void WebLocalFrameImpl::stopFinding(StopFindAction action)
{
    bool clearSelection = action == StopFindActionClearSelection;
    if (clearSelection)
        executeCommand(WebString::fromUTF8("Unselect"));

    if (m_textFinder) {
        if (!clearSelection)
            setFindEndstateFocusAndSelection();
        m_textFinder->stopFindingAndClearSelection();
    }

    if (action == StopFindActionActivateSelection && isFocused()) {
        WebDocument doc = document();
        if (!doc.isNull()) {
            WebElement element = doc.focusedElement();
            if (!element.isNull())
                element.simulateClick();
        }
    }
}

void WebLocalFrameImpl::increaseMatchCount(int count, int identifier)
{
    ensureTextFinder().increaseMatchCount(identifier, count);
}

void WebLocalFrameImpl::dispatchMessageEventWithOriginCheck(
    const WebSecurityOrigin& intendedTargetOrigin,
    const WebDOMEvent& event)
{
    DCHECK(!event.isNull());
    frame()->domWindow()->dispatchMessageEventWithOriginCheck(
        intendedTargetOrigin.get(), event,
        SourceLocation::create(String(), 0, 0, nullptr));
}

int WebLocalFrameImpl::findMatchMarkersVersion() const
{
    if (m_textFinder)
        return m_textFinder->findMatchMarkersVersion();
    return 0;
}

int WebLocalFrameImpl::selectNearestFindMatch(const WebFloatPoint& point,
    WebRect* selectionRect)
{
    return ensureTextFinder().selectNearestFindMatch(point, selectionRect);
}

float WebLocalFrameImpl::distanceToNearestFindMatch(
    const WebFloatPoint& point)
{
    float nearestDistance;
    ensureTextFinder().nearestFindMatch(point, &nearestDistance);
    return nearestDistance;
}

WebFloatRect WebLocalFrameImpl::activeFindMatchRect()
{
    if (m_textFinder)
        return m_textFinder->activeFindMatchRect();
    return WebFloatRect();
}

void WebLocalFrameImpl::findMatchRects(WebVector<WebFloatRect>& outputRects)
{
    ensureTextFinder().findMatchRects(outputRects);
}

void WebLocalFrameImpl::setTickmarks(const WebVector<WebRect>& tickmarks)
{
    if (frameView()) {
        Vector<IntRect> tickmarksConverted(tickmarks.size());
        for (size_t i = 0; i < tickmarks.size(); ++i)
            tickmarksConverted[i] = tickmarks[i];
        frameView()->setTickmarks(tickmarksConverted);
    }
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
    // Screen Orientation API
    if (ScreenOrientationController::from(*frame()))
        ScreenOrientationController::from(*frame())->notifyOrientationChanged();
#endif // MINIBLINK_NOT_IMPLEMENTED

    // Legacy window.orientation API
    if (RuntimeEnabledFeatures::orientationEventEnabled() && frame()->domWindow())
        frame()->localDOMWindow()->sendOrientationChangeEvent();
}

void WebLocalFrameImpl::willShowInstallBannerPrompt(int requestId, const WebVector<WebString>& platforms, WebAppBannerPromptReply* reply)
{
    if (!RuntimeEnabledFeatures::appBannerEnabled() || !frame())
        return;
#ifdef MINIBLINK_NOT_IMPLEMENTED
    AppBannerController::willShowInstallBannerPrompt(requestId, client()->appBannerClient(), frame(), platforms, reply);
#endif // MINIBLINK_NOT_IMPLEMENTED
}

void WebLocalFrameImpl::requestRunTask(WebSuspendableTask* task) const
{
    ASSERT(frame());
    ASSERT(frame()->document());
    frame()->document()->postSuspendableTask(WebSuspendableTaskWrapper::create(adoptPtr(task)));
>>>>>>> miniblink49
}

void WebLocalFrameImpl::willBeDetached()
{
    if (m_devToolsAgent)
        m_devToolsAgent->willBeDestroyed();
}

void WebLocalFrameImpl::willDetachParent()
{
<<<<<<< HEAD
    // Do not expect string scoping results from any frames that got detached
    // in the middle of the operation.
    if (m_textFinder && m_textFinder->scopingInProgress()) {
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
    // Do not expect string scoping results from any frames that got detached
    // in the middle of the operation.
    if (m_textFinder && m_textFinder->scopingInProgress()) {

>>>>>>> miniblink49
        // There is a possibility that the frame being detached was the only
        // pending one. We need to make sure final replies can be sent.
        m_textFinder->flushCurrentScoping();

        m_textFinder->cancelPendingScopingEffort();
    }
<<<<<<< HEAD
}

TextFinder* WebLocalFrameImpl::textFinder() const
{
    return m_textFinder;
}

=======
#endif // MINIBLINK_NOT_IMPLEMENTED
}

WebLocalFrameImpl* WebLocalFrameImpl::activeMatchFrame() const
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    ASSERT(!parent());

    if (m_textFinder)
        return m_textFinder->activeMatchFrame();
#endif // MINIBLINK_NOT_IMPLEMENTED
    return 0;
}

Range* WebLocalFrameImpl::activeMatch() const
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (m_textFinder)
        return m_textFinder->activeMatch();
#endif // MINIBLINK_NOT_IMPLEMENTED
    return 0;
}

#ifdef MINIBLINK_NOT_IMPLEMENTED
>>>>>>> miniblink49
TextFinder& WebLocalFrameImpl::ensureTextFinder()
{
    if (!m_textFinder)
        m_textFinder = TextFinder::create(*this);

    return *m_textFinder;
}
<<<<<<< HEAD

void WebLocalFrameImpl::setFrameWidget(WebFrameWidgetBase* frameWidget)
=======
#endif // MINIBLINK_NOT_IMPLEMENTED

void WebLocalFrameImpl::setFrameWidget(WebFrameWidgetImpl* frameWidget)
>>>>>>> miniblink49
{
    m_frameWidget = frameWidget;
}

<<<<<<< HEAD
WebFrameWidgetBase* WebLocalFrameImpl::frameWidget() const
=======
WebFrameWidgetImpl* WebLocalFrameImpl::frameWidget() const
>>>>>>> miniblink49
{
    return m_frameWidget;
}

<<<<<<< HEAD
void WebLocalFrameImpl::copyImageAt(const WebPoint& posInViewport)
{
    HitTestResult result = hitTestResultForVisualViewportPos(posInViewport);
    if (!isHTMLCanvasElement(result.innerNodeOrImageMapImage()) && result.absoluteImageURL().isEmpty()) {
        // There isn't actually an image at these coordinates.  Might be because
        // the window scrolled while the context menu was open or because the page
        // changed itself between when we thought there was an image here and when
        // we actually tried to retreive the image.
        //
        // FIXME: implement a cache of the most recent HitTestResult to avoid having
        //        to do two hit tests.
        return;
    }

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame()->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    frame()->editor().copyImage(result);
}

void WebLocalFrameImpl::saveImageAt(const WebPoint& posInViewport)
{
    Node* node = hitTestResultForVisualViewportPos(posInViewport)
                     .innerNodeOrImageMapImage();
    if (!node || !(isHTMLCanvasElement(*node) || isHTMLImageElement(*node)))
        return;

    String url = toElement(*node).imageSourceURL();
    if (!KURL(KURL(), url).protocolIsData())
        return;

    m_client->saveImageFromDataURL(url);
}

void WebLocalFrameImpl::setEngagementLevel(mojom::EngagementLevel level)
{
    //frame()->document()->setEngagementLevel(level);
    DebugBreak();
}

=======
>>>>>>> miniblink49
WebSandboxFlags WebLocalFrameImpl::effectiveSandboxFlags() const
{
    if (!frame())
        return WebSandboxFlags::None;
<<<<<<< HEAD
    return static_cast<WebSandboxFlags>(
        frame()->loader().effectiveSandboxFlags());
}

void WebLocalFrameImpl::forceSandboxFlags(WebSandboxFlags flags)
{
    frame()->loader().forceSandboxFlags(static_cast<SandboxFlags>(flags));
}

void WebLocalFrameImpl::clearActiveFindMatch()
{
    ensureTextFinder().clearActiveFindMatch();
}

void WebLocalFrameImpl::usageCountChromeLoadTimes(const WebString& metric)
{
    UseCounter::Feature feature = UseCounter::ChromeLoadTimesUnknown;
    if (metric == "requestTime") {
        feature = UseCounter::ChromeLoadTimesRequestTime;
    } else if (metric == "startLoadTime") {
        feature = UseCounter::ChromeLoadTimesStartLoadTime;
    } else if (metric == "commitLoadTime") {
        feature = UseCounter::ChromeLoadTimesCommitLoadTime;
    } else if (metric == "finishDocumentLoadTime") {
        feature = UseCounter::ChromeLoadTimesFinishDocumentLoadTime;
    } else if (metric == "finishLoadTime") {
        feature = UseCounter::ChromeLoadTimesFinishLoadTime;
    } else if (metric == "firstPaintTime") {
        feature = UseCounter::ChromeLoadTimesFirstPaintTime;
    } else if (metric == "firstPaintAfterLoadTime") {
        feature = UseCounter::ChromeLoadTimesFirstPaintAfterLoadTime;
    } else if (metric == "navigationType") {
        feature = UseCounter::ChromeLoadTimesNavigationType;
    } else if (metric == "wasFetchedViaSpdy") {
        feature = UseCounter::ChromeLoadTimesWasFetchedViaSpdy;
    } else if (metric == "wasNpnNegotiated") {
        feature = UseCounter::ChromeLoadTimesWasNpnNegotiated;
    } else if (metric == "npnNegotiatedProtocol") {
        feature = UseCounter::ChromeLoadTimesNpnNegotiatedProtocol;
    } else if (metric == "wasAlternateProtocolAvailable") {
        feature = UseCounter::ChromeLoadTimesWasAlternateProtocolAvailable;
    } else if (metric == "connectionInfo") {
        feature = UseCounter::ChromeLoadTimesConnectionInfo;
    }
    UseCounter::count(frame(), feature);
}

base::SingleThreadTaskRunner* WebLocalFrameImpl::timerTaskRunner()
{
    return frame()
        ->frameScheduler()
        ->timerTaskRunner()
        ->toSingleThreadTaskRunner();
}

base::SingleThreadTaskRunner* WebLocalFrameImpl::loadingTaskRunner()
{
    return frame()
        ->frameScheduler()
        ->loadingTaskRunner()
        ->toSingleThreadTaskRunner();
}

base::SingleThreadTaskRunner* WebLocalFrameImpl::unthrottledTaskRunner()
{
    return frame()
        ->frameScheduler()
        ->unthrottledTaskRunner()
        ->toSingleThreadTaskRunner();
}

WebInputMethodControllerImpl* WebLocalFrameImpl::inputMethodController() const
{
    return m_inputMethodController.get();
=======
    return static_cast<WebSandboxFlags>(frame()->loader().effectiveSandboxFlags());
}

int WebLocalFrameImpl::topContentInset() const
{
    if (frame() && frame()->view()) {
        return frame()->view()->topContentInset();
    }
    return 0;
}

void WebLocalFrameImpl::setTopContentInset(int offset)
{
    m_topContentInset = offset;
    if (frame() && frame()->view()) {
        frame()->view()->setTopContentInset(m_topContentInset);
        WebViewImpl* webView = viewImpl();
        if (webView)
            webView->layout();
    }
    return;
}

static void collectAllFrames(Vector<const LocalFrame*>* list, const LocalFrame* frame)
{
    list->append(frame);

    for (auto childFrame = frame->tree().firstChild(); childFrame; childFrame = childFrame->tree().nextSibling()) {
        if (!childFrame->isLocalFrame())
            continue;

        collectAllFrames(list, toLocalFrame(childFrame));
    }
}

class CanvasPainterContext {
    void paintToGraphicsContext(GraphicsContext& context, FrameView* view, const FloatRect& floatRect)
    {
        // Enter a translation transform
        AffineTransform transform;
        transform.translate(static_cast<float>(-floatRect.x()), static_cast<float>(-floatRect.y()));
        TransformRecorder transformRecorder(context, *this, transform);

        // Enter a clipped region
        ClipRecorder clipRecorder(context, *this, DisplayItem::ClipPrintedPage, LayoutRect(floatRect));

        view->updateAllLifecyclePhases();

        PaintBehavior oldPaintBehavior = view->paintBehavior();

        view->setPaintBehavior(oldPaintBehavior | PaintBehaviorFlattenCompositingLayers);
        view->paintContents(&context, IntRect(floatRect));
        view->setPaintBehavior(oldPaintBehavior);
    }

public:
    void paint(WebCanvas* canvas, FrameView* view, const FloatRect& floatRect)
    {
        SkPictureBuilder pictureBuilder(floatRect, &skia::getMetaData(*canvas));
        paintToGraphicsContext(pictureBuilder.context(), view, floatRect);
        pictureBuilder.endRecording()->playback(canvas);
    }

    DisplayItemClient displayItemClient() const
    {
        return toDisplayItemClient(this);
    }

    String debugName() const
    {
        return "CanvasPainterContext";
    }
};

void WebLocalFrameImpl::drawInCanvas(const WebRect& rect, const WebString& customCSS, WebCanvas* canvas) const
{
    Vector<const LocalFrame*> frames;
    collectAllFrames(&frames, frame());

    // Set the new "style" attribute if specified
    const blink::WebString classAttribute("class");
    std::vector<WTF::String> originalStyleClasses;

    if (!customCSS.isEmpty()) {
        for (auto localFrame : frames) {
            auto htmlBody = localFrame->document()->body();

            // Some documents (ie. SVG documents) do not have body elements
            if (!htmlBody)
                continue;

            auto webBody = WebElement(htmlBody);
            if (webBody.hasAttribute(classAttribute)) {
                WTF::String originalStyleClass = webBody.getAttribute(classAttribute);
                originalStyleClasses.push_back(originalStyleClass);
                webBody.setAttribute(classAttribute, WTF::String(originalStyleClass + " " + WTF::String(customCSS)));
            } else {
                originalStyleClasses.push_back(WTF::String());
                webBody.setAttribute(classAttribute, customCSS);
            }
        }
    }

    CanvasPainterContext painterContext;
    painterContext.paint(canvas, frameView(), FloatRect(rect));

    // Restore the original "style" attribute
    if (!originalStyleClasses.empty()) {
        int index = -1;
        for (auto localFrame : frames) {
            auto htmlBody = localFrame->document()->body();
            if (!htmlBody)
                continue;

            const auto& originalStyleClass = originalStyleClasses[++index];
            auto webBody = WebElement(htmlBody);

            if (!originalStyleClass.isEmpty()) {
                webBody.setAttribute(classAttribute, originalStyleClass);
            } else {
                webBody.removeAttribute(classAttribute);
            }
        }
    }
>>>>>>> miniblink49
}

} // namespace blink

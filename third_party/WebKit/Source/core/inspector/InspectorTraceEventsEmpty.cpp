#include "InspectorTraceEvents.h"
#include "config.h"
#include "core/css/invalidation/InvalidationSet.h"
#include "core/page/ChromeClient.h"
#include "platform/instrumentation/tracing/TracedValue.h"
#include <inttypes.h>

namespace blink {

class HTMLSlotElement;
class ConsoleMessage;
class DocumentLoader;
class ResourceResponse;
class Resource;

static const unsigned maxInvalidationTrackingCallstackSize = 5;

String toHexString(const void* p)
{
    return String::format("0x%" PRIx64, static_cast<uint64_t>(reinterpret_cast<intptr_t>(p)));
}

// String descendantInvalidationSetToIdString(const DescendantInvalidationSet& set)
// {
//     return toHexString(&set);
// }

String descendantInvalidationSetToIdString(const InvalidationSet& set)
{
    return toHexString(&set);
}

const char InspectorStyleInvalidatorInvalidateEvent::ElementHasPendingInvalidationList[] = "Element has pending invalidation list";
const char InspectorStyleInvalidatorInvalidateEvent::InvalidateCustomPseudo[] = "Invalidate custom pseudo element";
const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedAttribute[] = "Invalidation set matched attribute";
const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedClass[] = "Invalidation set matched class";
const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedId[] = "Invalidation set matched id";
const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedTagName[] = "Invalidation set matched tagName";
const char InspectorStyleInvalidatorInvalidateEvent::PreventStyleSharingForParent[] = "Prevent style sharing for parent";

namespace LayoutInvalidationReason {
    const char Unknown[] = "Unknown";
    const char SizeChanged[] = "Size changed";
    const char AncestorMoved[] = "Ancestor moved";
    const char StyleChange[] = "Style changed";
    const char DomChanged[] = "DOM changed";
    const char TextChanged[] = "Text changed";
    const char PrintingChanged[] = "Printing changed";
    const char AttributeChanged[] = "Attribute changed";
    const char ColumnsChanged[] = "Attribute changed";
    const char ChildAnonymousBlockChanged[] = "Child anonymous block changed";
    const char AnonymousBlockChange[] = "Anonymous block change";
    const char Fullscreen[] = "Fullscreen change";
    const char ChildChanged[] = "Child changed";
    const char ListValueChange[] = "List value change";
    const char ImageChanged[] = "Image changed";
    const char LineBoxesChanged[] = "Line boxes changed";
    const char SliderValueChanged[] = "Slider value changed";
    const char AncestorMarginCollapsing[] = "Ancestor margin collapsing";
    const char FieldsetChanged[] = "Fieldset changed";
    const char TextAutosizing[] = "Text autosizing (font boosting)";
    const char SvgResourceInvalidated[] = "SVG resource invalidated";
    const char FloatDescendantChanged[] = "Floating descendant changed";
    const char CountersChanged[] = "Counters changed";
    const char GridChanged[] = "Grid changed";
    const char MenuOptionsChanged[] = "Menu options changed";
    const char RemovedFromLayout[] = "Removed from layout";
    const char AddedToLayout[] = "Added to layout";
    const char TableChanged[] = "Table changed";
    const char PaddingChanged[] = "Padding changed";
    const char TextControlChanged[] = "Text control changed";
    const char SvgChanged[] = "SVG changed";
    const char ScrollbarChanged[] = "Scrollbar changed";
} // namespace LayoutInvalidationReason

std::unique_ptr<TracedValue> InspectorXhrReadyStateChangeEvent::data(ExecutionContext* context, XMLHttpRequest* request)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorXhrLoadEvent::data(ExecutionContext* context, XMLHttpRequest* request)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorParseHtmlEvent::beginData(Document* document, unsigned startLine)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorParseHtmlEvent::endData(unsigned endLine)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorLayoutEvent::beginData(FrameView* frameView)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorLayoutEvent::endData(LayoutObject* rootForThisLayout)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorParseAuthorStyleSheetEvent::data(const CSSStyleSheetResource* cachedStyleSheet)
{
    notImplemented();
    return nullptr;
}

// PassRefPtr<TracedValue> InspectorStyleInvalidatorInvalidateEvent::fillCommonPart(Element& element, const char* reason)
// {
//     notImplemented();
//     return nullptr;
// }

std::unique_ptr<TracedValue> InspectorStyleInvalidatorInvalidateEvent::data(Element& element, const char* reason)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorStyleInvalidatorInvalidateEvent::selectorPart(Element&,
    const char* reason,
    const InvalidationSet&,
    const String&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorStyleInvalidatorInvalidateEvent::invalidationList(ContainerNode&,
    const Vector<RefPtr<InvalidationSet>>&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorLayerInvalidationTrackingEvent::data(const PaintLayer*, const char* reason)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorPaintEvent::data(LayoutObject* layoutObject, const LayoutRect& clipRect, const GraphicsLayer* graphicsLayer)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> frameEventData(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorCommitLoadEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorMarkLoadEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorScrollLayerEvent::data(LayoutObject* layoutObject)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorUpdateLayerTreeEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorEvaluateScriptEvent::data(LocalFrame*,
    const String& url,
    const WTF::TextPosition&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorFunctionCallEvent::data(ExecutionContext*,
    const v8::Local<v8::Function>&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorPaintImageEvent::data(const LayoutImage& layoutImage)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorPaintImageEvent::data(const LayoutObject& owningLayoutObject, const StyleImage& styleImage)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorPaintImageEvent::data(const LayoutObject* owningLayoutObject, const ImageResourceContent& imageResource)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorUpdateCountersEvent::data()
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorInvalidateLayoutEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorRecalculateStylesEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorEventDispatchEvent::data(const Event& event)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorTimeStampEvent::data(ExecutionContext* context, const String& message)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorTracingSessionIdForWorkerEvent::data(const String& sessionId, const String& workerId, WorkerThread* workerThread)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorTracingStartedInFrame::data(const String& sessionId, LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorSetLayerTreeId::data(const String& sessionId, int layerTreeId)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorAnimationEvent::data(const Animation& player)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorAnimationStateEvent::data(const Animation& player)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorHitTestEvent::endData(const HitTestRequest& request, const HitTestLocation& location, const HitTestResult& result)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorTimerInstallEvent::data(ExecutionContext* context, int timerId, int timeout, bool singleShot)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorTimerRemoveEvent::data(ExecutionContext* context, int timerId)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorTimerFireEvent::data(ExecutionContext* context, int timerId)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorAnimationFrameEvent::data(ExecutionContext* context, int callbackId)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorStyleRecalcInvalidationTrackingEvent::data(Node*, const StyleChangeReasonForTracing&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorCompileScriptEvent::data(const String& url, const WTF::TextPosition&)
{
    DebugBreak();
    return nullptr;
}

namespace InspectorIdleCallbackRequestEvent {
    std::unique_ptr<TracedValue> data(ExecutionContext*, int id, double timeout)
    {
        DebugBreak();
        return nullptr;
    }
}

namespace InspectorIdleCallbackCancelEvent {
    std::unique_ptr<TracedValue> data(ExecutionContext*, int id)
    {
        DebugBreak();
        return nullptr;
    }
}

namespace InspectorIdleCallbackFireEvent {
    std::unique_ptr<TracedValue> data(ExecutionContext*,
        int id,
        double allottedMilliseconds,
        bool timedOut)
    {
        DebugBreak();
        return nullptr;
    }
}

namespace InspectorChangeResourcePriorityEvent {
    std::unique_ptr<TracedValue> data(unsigned long identifier,
        const ResourceLoadPriority&)
    {
        DebugBreak();
        return nullptr;
    }
}

const char InspectorLayerInvalidationTrackingEvent::SquashingLayerGeometryWasUpdated[] = "Squashing layer geometry was updated";
const char InspectorLayerInvalidationTrackingEvent::AddedToSquashingLayer[] = "The layer may have been added to an already-existing squashing layer";
const char InspectorLayerInvalidationTrackingEvent::RemovedFromSquashingLayer[] = "Removed the layer from a squashing layer";
const char InspectorLayerInvalidationTrackingEvent::ReflectionLayerChanged[] = "Reflection layer change";
const char InspectorLayerInvalidationTrackingEvent::NewCompositedLayer[] = "Assigned a new composited layer";

namespace InspectorInstrumentation {

    void fontsUpdated(Document*)
    {
        //DebugBreak();
    }

    void didPerformSlotDistribution(HTMLSlotElement*)
    {
        //DebugBreak();
    }

    void consoleMessageAdded(ExecutionContext*, ConsoleMessage*)
    {
        //DebugBreak();
    }

    void canceledAfterReceivedResourceResponse(LocalFrame*,
        DocumentLoader*,
        unsigned long identifier,
        const ResourceResponse&,
        Resource*)
    {
        //DebugBreak();
    }

    void didReceiveData(LocalFrame*, unsigned long, const char*, int)
    {
        //DebugBreak();
    }

    void didReceiveEncodedDataLength(LocalFrame*, unsigned long, int)
    {
        //DebugBreak();
    }

    void willRunJavaScriptDialog(LocalFrame*, const String&, ChromeClient::DialogType)
    {
        //DebugBreak();
    }

    void didRunJavaScriptDialog(LocalFrame*, bool)
    {
        //DebugBreak();
    }

}

} // namespace blink
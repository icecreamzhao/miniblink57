
#define ENABLE_MB 1
#include "mbvip/core/mb.h"
#include "wke/wkedefine.h"
#include "wke/wkeWebView.h"
#include "mbvip/core/MbWebView.h"
#include "mbvip/common/LiveIdDetect.h"
#include "content/browser/WebPage.h"
#include "third_party/WebKit/public/web/WebLocalFrame.h"
#include "third_party/WebKit/public/web/WebElement.h"
#include "third_party/WebKit/Source/bindings/core/v8/ToV8.h"
#include "gen/blink/bindings/core/v8/V8Element.h"
#include "v8.h"

BOOL MB_CALL_TYPE mbGetContextByV8Object(void* isolate, void* obj, int worldID, v8ContextPtr cxtOut)
{
//     v8::Local<v8::Object>* object = (v8::Local<v8::Object>*)obj;
// 
//     v8::Local<v8::Context> context = (*object)->CreationContext();
//     if (context.IsEmpty())
//         return false;
//     blink::WebLocalFrame* frame = blink::WebLocalFrame::frameForContext(context);
//     if (!frame)
//         return false;
// 
//     *(v8::Local<v8::Context>*)cxtOut = frame->getScriptContextFromWorldId((v8::Isolate*)isolate, worldID);
//     return true;

    return false;
}

// static blink::Element* webElementFromV8Value(v8::Local<v8::Value> value)
// {
//     if (value.IsEmpty())
//         return nullptr;
//     blink::Element* element = blink::V8Element::toImplWithTypeCheck(v8::Isolate::GetCurrent(), value);
//     return element;
// }
// 
// static v8::Local<v8::Value> nodeToV8Value(blink::Element* elem, v8::Local<v8::Object> creation_context, v8::Isolate* isolate)
// {
//     // We no longer use |creation_context| because it's often misused and points
//     // to a context faked by user script.
//     ASSERT(creation_context->CreationContext() == isolate->GetCurrentContext());
//     if (!elem)
//         return v8::Local<v8::Value>();
//     return toV8(elem, isolate->GetCurrentContext()->Global(), isolate);
// }

BOOL MB_CALL_TYPE mbPassWebElementValueToOtherContext(void* val, void* destCtx, void* outVal)
{
//     v8::Local<v8::Value>* value = (v8::Local<v8::Value>*)val;
//     v8::Local<v8::Context>* destContext = (v8::Local<v8::Context>*)destCtx;
// 
//     blink::Element* elem = webElementFromV8Value(*value);
//     if (!elem)
//         return false;
// 
//     v8::Context::Scope destination_context_scope(*destContext);
//     *(v8::Local<v8::Value>*)outVal = nodeToV8Value(elem, (*destContext)->Global(), (*destContext)->GetIsolate());
//     return true;
    return false;
}

void MB_CALL_TYPE mbGetWorldScriptContextByWebFrame(mbWebView webviewHandle, mbWebFrameHandle frameId, int worldID, v8ContextPtr contextOut)
{
//     mb::MbWebView* webview = (mb::MbWebView*)common::LiveIdDetect::get()->getPtr(webviewHandle);
//     if (!webview)
//         return;
// 
//     wkeWebFrameHandle wkeFrameId = (wkeWebFrameHandle)frameId;
//     if ((mbWebFrameHandle)-2 == frameId)
//         wkeFrameId = wkeWebFrameGetMainFrame(webview->getWkeWebView());
// 
//     //return wkeWebFrameGetMainWorldScriptContext(webview->getWkeWebView(), wkeFrameId, contextOut);
//     content::WebPage* page = webview->getWkeWebView()->webPage();
//     if (!page)
//         return;
//     blink::WebFrame* webFrame = page->getWebFrameFromFrameId(wke::CWebView::wkeWebFrameHandleToFrameId(page, wkeFrameId));
//     if (!webFrame)
//         return;
//     v8::Local<v8::Context> result = webFrame->getScriptContextFromWorldId(v8::Isolate::GetCurrent(), worldID);
//     v8::Local<v8::Context>* contextOutPtr = (v8::Local<v8::Context>*)contextOut;
//     *contextOutPtr = result;
}

void* MB_CALL_TYPE mbGetProcAddr(const char* name)
{
    if (0 == strcmp(name, "mbGetContextByV8Object"))
        return (void*)&mbGetContextByV8Object;
    if (0 == strcmp(name, "mbPassWebElementValueToOtherContext"))
        return (void*)&mbPassWebElementValueToOtherContext;
    if (0 == strcmp(name, "mbGetWorldScriptContextByWebFrame"))
        return (void*)&mbGetWorldScriptContextByWebFrame;
    return nullptr;
}
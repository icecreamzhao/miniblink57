
#include "content/web_impl_win/BlinkPlatformImpl.h"
#include "base/rand_util.h"
#include "base/synchronization/waitable_event.h"
#include "base/thread_task_runner_handle.h"
#include "cc/blink/web_compositor_support_impl.h"
#include "config.h"
#include "content/resources/MissingImageData.h"
#include "content/resources/TextAreaResizeCornerData.h"
#include "content/resources/ViewportAndroidData.h"
#include "content/web_impl_win/CurrentTimeImpl.h"
#include "content/web_impl_win/WebStorageNamespaceImpl.h"
#include "content/web_impl_win/WebThemeEngineImpl.h"
#include "content/web_impl_win/WebURLLoaderImpl.h"
#include "content/web_impl_win/WebURLLoaderImplCurl.h"
#include "gen/blink/core/UserAgentStyleSheets.h"
#include "third_party/WebKit/Source/platform/scheduler/renderer/webthread_impl_for_renderer_scheduler.h"
#include "third_party/WebKit/public/platform/WebScrollbarBehavior.h"
#include "third_party/WebKit/public/platform/scheduler/child/webthread_impl_for_worker_scheduler.h"
#include "third_party/WebKit/public/platform/scheduler/renderer/renderer_scheduler.h"

namespace content {

BlinkPlatformImpl::BlinkPlatformImpl()
{
    m_mainThreadId = -1;
    m_webThemeEngine = nullptr;
    //m_mimeRegistry = nullptr;
    m_webCompositorSupport = nullptr;
    m_webScrollbarBehavior = nullptr;
    m_localStorageStorageMap = nullptr;
    m_sessionStorageStorageMap = nullptr;
    m_storageNamespaceIdCount = 1;
}

BlinkPlatformImpl::~BlinkPlatformImpl()
{
    // TODO delete
}

blink::WebThread* BlinkPlatformImpl::createThread(const char* name)
{
    std::unique_ptr<blink::scheduler::WebThreadImplForWorkerScheduler> threadImpl(new blink::scheduler::WebThreadImplForWorkerScheduler(name));

    threadImpl->Init();
    waitUntilWebThreadTLSUpdate(threadImpl.get());
    return threadImpl.release();
}

blink::WebThread* BlinkPlatformImpl::createBlinkThread()
{
    m_rendererScheduler = blink::scheduler::RendererScheduler::Create();
    m_mainThread = m_rendererScheduler->CreateMainThread();
    return m_mainThread.get();
}

void BlinkPlatformImpl::waitUntilWebThreadTLSUpdate(blink::scheduler::WebThreadBase* thread)
{
    base::WaitableEvent event(base::WaitableEvent::ResetPolicy::AUTOMATIC,
        base::WaitableEvent::InitialState::NOT_SIGNALED);
    thread->GetTaskRunner()->PostTask(
        FROM_HERE,
        base::Bind(&BlinkPlatformImpl::updateWebThreadTLS, base::Unretained(this),
            base::Unretained(thread), base::Unretained(&event)));
    event.Wait();
}

void BlinkPlatformImpl::updateWebThreadTLS(blink::WebThread* webThread, base::WaitableEvent* event)
{
    DCHECK(!current_thread_slot_.Get());
    current_thread_slot_.Set(webThread);
    event->Signal();
}

blink::WebThread* BlinkPlatformImpl::currentThread()
{
    if (m_mainThread->isCurrentThread())
        return m_mainThread.get();
    return static_cast<blink::WebThread*>(current_thread_slot_.Get());
}

// void BlinkPlatformImpl::cryptographicallyRandomValues(unsigned char* buffer, size_t length)
// {
//     base::RandBytes(buffer, length);
// }

blink::WebURLLoader* BlinkPlatformImpl::createURLLoader()
{
    return new content::WebURLLoaderImpl();
    //return new content::WebURLLoaderImplCurl();
}

blink::WebString BlinkPlatformImpl::defaultLocale()
{
    return blink::WebString::fromUTF8("zh-CN");
}

// double BlinkPlatformImpl::currentTime()
// {
//     return currentTimeImpl();
// }

// double BlinkPlatformImpl::monotonicallyIncreasingTime()
// {
//     LARGE_INTEGER qpc;
//     QueryPerformanceCounter(&qpc);
//     return qpc.QuadPart / (1000 * 1000);
// }

// double BlinkPlatformImpl::systemTraceTime()
// {
//     DebugBreak();
//     return 0;
// }

blink::WebString BlinkPlatformImpl::userAgent()
{
    return blink::WebString(
        "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36");
}

blink::WebData BlinkPlatformImpl::loadResource(const char* name)
{
    if (0 == strcmp("html.css", name)) {
        return blink::WebData(blink::htmlUserAgentStyleSheet, sizeof(blink::htmlUserAgentStyleSheet));
        //return blink::WebData((const char*)data, 18233);
    } else if (0 == strcmp("quirks.css", name))
        return blink::WebData(blink::quirksUserAgentStyleSheet, sizeof(blink::quirksUserAgentStyleSheet));
    else if (0 == strcmp("themeWin.css", name))
        return blink::WebData(blink::themeWinUserAgentStyleSheet, sizeof(blink::themeWinUserAgentStyleSheet));
    else if (0 == strcmp("svg.css", name)) {
        return blink::WebData(blink::svgUserAgentStyleSheet, sizeof(blink::svgUserAgentStyleSheet));
    } else if (0 == strcmp("themeChromiumSkia.css", name)) {
        //return blink::WebData(blink::themeChromiumSkiaUserAgentStyleSheet, sizeof(blink::themeChromiumSkiaUserAgentStyleSheet));
    } else if (0 == strcmp("themeChromium.css", name)) {
        //return blink::WebData(blink::themeChromiumUserAgentStyleSheet, sizeof(blink::themeChromiumUserAgentStyleSheet));
    } else if (0 == strcmp("themeWinQuirks.css", name)) {
        return blink::WebData(blink::themeWinQuirksUserAgentStyleSheet, sizeof(blink::themeWinQuirksUserAgentStyleSheet));
    } else if (0 == strcmp("missingImage", name))
        return blink::WebData((const char*)content::gMissingImageData, sizeof(content::gMissingImageData));
    else if (0 == strcmp("textAreaResizeCorner", name))
        return blink::WebData((const char*)content::gTextAreaResizeCornerData, sizeof(content::gTextAreaResizeCornerData));
    else if (0 == strcmp("textAreaResizeCorner@2x", name))
        return blink::WebData((const char*)content::gTextAreaResizeCornerData, sizeof(content::gTextAreaResizeCornerData));
    else if (0 == strcmp("themeInputMultipleFields.css", name))
        return blink::WebData((const char*)blink::themeInputMultipleFieldsUserAgentStyleSheet, sizeof(blink::themeInputMultipleFieldsUserAgentStyleSheet));
    else if (0 == strcmp("viewportAndroid.css", name))
        return blink::WebData((const char*)content::viewportAndroid, sizeof(content::viewportAndroid));

    notImplemented();
    return blink::WebData("  ", 1);
}

blink::WebThemeEngine* BlinkPlatformImpl::themeEngine()
{
    if (nullptr == m_webThemeEngine)
        m_webThemeEngine = new WebThemeEngineImpl();
    return m_webThemeEngine;
}

// blink::WebMimeRegistry* BlinkPlatformImpl::mimeRegistry()
// {
//     if (nullptr == m_mimeRegistry)
//         m_mimeRegistry = new WebMimeRegistryImpl();
//     return m_mimeRegistry;
// }

blink::WebCompositorSupport* BlinkPlatformImpl::compositorSupport()
{
    if (!m_webCompositorSupport)
        m_webCompositorSupport = new cc_blink::WebCompositorSupportImpl();
    return m_webCompositorSupport;
}

blink::WebScrollbarBehavior* BlinkPlatformImpl::scrollbarBehavior()
{
    if (!m_webScrollbarBehavior)
        m_webScrollbarBehavior = new blink::WebScrollbarBehavior();
    return m_webScrollbarBehavior;
}

blink::WebURLError BlinkPlatformImpl::cancelledError(const blink::WebURL& url) const
{
    blink::WebURLError error;
    error.reason = -1;
    error.domain = blink::WebString(url.string());
    error.localizedDescription = blink::WebString::fromUTF8("url cancelledError\n");

    WTF::String outError = "url cancelledError:";
    outError.append((WTF::String)url.string());
    outError.append("\n");
    OutputDebugStringW(outError.charactersWithNullTermination().data());

    return error;
}

class DOMStorageMapWrap {
public:
    DOMStorageMapWrap()
    {
    }
    DOMStorageMap map;
};

blink::WebStorageNamespace* BlinkPlatformImpl::createLocalStorageNamespace()
{
    if (!m_localStorageStorageMap)
        m_localStorageStorageMap = new DOMStorageMapWrap();
    return new content::WebStorageNamespaceImpl(kLocalStorageNamespaceId, m_localStorageStorageMap->map);
}

blink::WebStorageNamespace* BlinkPlatformImpl::createSessionStorageNamespace()
{
    if (!m_sessionStorageStorageMap)
        m_sessionStorageStorageMap = new DOMStorageMapWrap();
    return new content::WebStorageNamespaceImpl(m_storageNamespaceIdCount++, m_sessionStorageStorageMap->map);
}

} // namespace content
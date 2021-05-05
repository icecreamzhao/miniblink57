#include "base/compiler_specific.h"
#include "third_party/WebKit/public/platform/Platform.h"

namespace base {
class WaitableEvent;
}

namespace blink {
namespace scheduler {
    class WebThreadBase;
    class RendererScheduler;
}
}

namespace content {

class DOMStorageMapWrap;

class BlinkPlatformImpl
    : NON_EXPORTED_BASE(public blink::Platform) {
public:
    BlinkPlatformImpl();
    virtual ~BlinkPlatformImpl();

    //virtual void cryptographicallyRandomValues(unsigned char* buffer, size_t length) override;

    // Threads -------------------------------------------------------

    // Creates an embedder-defined thread.
    virtual blink::WebThread* createThread(const char* name) override;
    blink::WebThread* createBlinkThread();

    // Returns an interface to the current thread. This is owned by the
    // embedder.
    virtual blink::WebThread* currentThread() override;

    //    virtual const unsigned char* getTraceCategoryEnabledFlag(const char* categoryName) override;

    // System --------------------------------------------------------------
    virtual blink::WebString defaultLocale() override;
    //virtual double currentTime() override;
    //virtual double monotonicallyIncreasingTime() override;
    //virtual double systemTraceTime() override;

    virtual blink::WebString userAgent() override;

    virtual blink::WebData BlinkPlatformImpl::loadResource(const char* name) override;

    virtual blink::WebThemeEngine* BlinkPlatformImpl::themeEngine() override;

    //virtual blink::WebMimeRegistry* mimeRegistry() override;

    virtual blink::WebCompositorSupport* compositorSupport() override;

    // Scrollbar ----------------------------------------------------------
    virtual blink::WebScrollbarBehavior* scrollbarBehavior() override;

    // Network -------------------------------------------------------------
    blink::WebURLLoader* createURLLoader() override;
    virtual blink::WebURLError cancelledError(const blink::WebURL&) const override;

    // DOM Storage --------------------------------------------------
    virtual blink::WebStorageNamespace* createLocalStorageNamespace() override;
    blink::WebStorageNamespace* createSessionStorageNamespace();

private:
    void waitUntilWebThreadTLSUpdate(blink::scheduler::WebThreadBase* thread);
    void updateWebThreadTLS(blink::WebThread* webThread, base::WaitableEvent* event);

    base::ThreadLocalStorage::Slot current_thread_slot_;
    ThreadIdentifier m_mainThreadId;
    std::unique_ptr<blink::WebThread> m_mainThread;
    std::unique_ptr<blink::scheduler::RendererScheduler> m_rendererScheduler;

    blink::WebThemeEngine* m_webThemeEngine;
    //blink::WebMimeRegistry* m_mimeRegistry;
    blink::WebCompositorSupport* m_webCompositorSupport;
    blink::WebScrollbarBehavior* m_webScrollbarBehavior;
    DOMStorageMapWrap* m_localStorageStorageMap;
    DOMStorageMapWrap* m_sessionStorageStorageMap;
    int64 m_storageNamespaceIdCount;
};

} // namespace content
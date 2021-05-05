
#include "content/web_impl_win/WebURLLoaderImpl.h"
#include "config.h"
#include "net/WebURLLoaderWinINet.h"
#include <windows.h>
#include <wininet.h>

namespace content {

WebURLLoaderImpl::WebURLLoaderImpl()
{
    m_loaderWinINet = nullptr;
}

WebURLLoaderImpl::~WebURLLoaderImpl()
{
    if (m_loaderWinINet)
        m_loaderWinINet->onLoaderWillBeDelete();
    m_loaderWinINet = nullptr;
}

// WebURLLoader methods:
void WebURLLoaderImpl::loadSynchronously(
    const blink::WebURLRequest& request,
    blink::WebURLResponse& response,
    blink::WebURLError& error,
    blink::WebData& data,
    int64_t& encodedDataLength,
    int64_t& encodedBodyLength)
{
    m_loaderWinINet = new net::WebURLLoaderWinINet(this);
    m_loaderWinINet->loadSynchronously(request, response, error, data);
}

void WebURLLoaderImpl::loadAsynchronously(
    const blink::WebURLRequest& request,
    blink::WebURLLoaderClient* client)
{
    m_loaderWinINet = new net::WebURLLoaderWinINet(this);
    m_loaderWinINet->loadAsynchronously(request, client);
}

void WebURLLoaderImpl::cancel()
{
    ASSERT(m_loaderWinINet);
    m_loaderWinINet->cancel();
}

void WebURLLoaderImpl::setDefersLoading(bool value)
{
    m_loaderWinINet->setDefersLoading(value);
}

void WebURLLoaderImpl::didChangePriority(blink::WebURLRequest::Priority newPriority, int intraPriorityValue)
{
}

// bool WebURLLoaderImpl::attachThreadedDataReceiver(blink::WebThreadedDataReceiver* threadedDataReceiver)
// {
//     DebugBreak();
//     return false;
// }

void WebURLLoaderImpl::setLoadingTaskRunner(base::SingleThreadTaskRunner*)
{
    ;
}

void WebURLLoaderImpl::onWinINetWillBeDelete()
{
    m_loaderWinINet = nullptr;
}

} // namespace content
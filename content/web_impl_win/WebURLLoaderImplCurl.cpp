#include "content/web_impl_win/WebURLLoaderImplCurl.h"
#include "config.h"
#include "net/WebURLLoaderInternal.h"
#include "net/WebURLLoaderManager.h"
#include "third_party/WebKit/Source/wtf/text/WTFStringUtil.h"
#include "third_party/WebKit/public/platform/WebURLError.h"
#include <windows.h>
#include <wininet.h>

namespace content {

WebURLLoaderImplCurl::WebURLLoaderImplCurl()
{
    m_webURLLoaderInternal = nullptr;
}

WebURLLoaderImplCurl::~WebURLLoaderImplCurl()
{
}

void WebURLLoaderImplCurl::init()
{
    m_hadDestroied = false;
    m_webURLLoaderInternal = nullptr;
}

void WebURLLoaderImplCurl::loadSynchronously(
    const blink::WebURLRequest& request,
    blink::WebURLResponse& response,
    blink::WebURLError& error,
    blink::WebData& data,
    int64_t& encodedDataLength,
    int64_t& encodedBodyLength)
{
    notImplemented();
}

void WebURLLoaderImplCurl::loadAsynchronously(const blink::WebURLRequest& request_old, blink::WebURLLoaderClient* client)
{
    init();

    WebURLRequest request = request_old;
    //     KURL kurl = request.url();
    //     if (-1 != kurl.string().find(".js") || -1 != kurl.string().find("getdatabyids")) {
    //         //kurl = KURL(ParsedURLString, "https://api.m.taobao.com/h5/mtop.mt.getdatabyids/2.0/?api=mtop.mt.getDataByIds&v=1.0&type=originaljson&dataType=json&H5Request=true&data=%7B%22dataids%22%3A%22137%2C217%22%7D");
    //         kurl = KURL(ParsedURLString, "http://www.kdgui.com/");
    //     } else if (-1 != kurl.string().find("loadpagecontent")) {
    //         kurl = KURL(ParsedURLString, "https://api.m.taobao.com/h5/mtop.taobao.wireless.homepage.ac.loadpagecontent/5.0/?appKey=12574478&t=1454216031656&sign=5383f167013b3d330fa71e9b9ec85818&api=mtop.taobao.wireless.homepage.ac.loadPageContent&v=5.0&H5Request=true&type=jsonp&dataType=jsonp&callback=mtopjsonp1&data=%7B%22platform%22%3A%22h5%22%2C%22acookie%22%3A%22%22%2C%22userInfoFrom%22%3A%22cache%22%2C%22isPosition%22%3Afalse%7D");
    //         //kurl = KURL(ParsedURLString, "https://api.m.taobao.com/");
    //     } else if (-1 != kurl.string().find(".jpg")) {
    //         kurl = KURL(ParsedURLString, "http://www.kdgui.com/");
    //     } else if (-1 != kurl.string().find(".png")) {
    //         kurl = KURL(ParsedURLString, "http://www.kdgui.com/");
    //     }
    //     request.setURL(kurl);

    m_webURLLoaderInternal = net::WebURLLoaderManager::sharedInstance()->add(this, request, client);

    blink::KURL url = (blink::KURL)request.url();
    Vector<UChar> host = WTF::ensureStringToUChars(url.host());

    if (!url.isValid() || !url.protocolIsData()) {
        WTF::String outstr = String::format("WebURLLoaderImpl.loadAsynchronously: %p %ws\n", this, ensureStringToUChars(url.string()).data());
        OutputDebugStringW(outstr.charactersWithNullTermination().data());
    }

    return;
}

void WebURLLoaderImplCurl::cancel()
{
    net::WebURLLoaderManager::sharedInstance()->cancel(this);
    m_webURLLoaderInternal = nullptr;
}

void WebURLLoaderImplCurl::fileLoadImpl(const blink::KURL& url)
{
}

void WebURLLoaderImplCurl::setDefersLoading(bool value)
{
    notImplemented();
}

void WebURLLoaderImplCurl::didChangePriority(blink::WebURLRequest::Priority new_priority, int intra_priority_value)
{
    //notImplemented();
}

} // content

#include "content/web_impl_win/WebStorageAreaImpl.h"
#include "third_party/WebKit/public/platform/WebURL.h"

namespace content {

WebStorageAreaImpl::WebStorageAreaImpl(DOMStorageMap& cachedArea, const blink::WebSecurityOrigin& origin)
    : m_cachedArea(cachedArea)
{
    m_origin = origin;
}

WebStorageAreaImpl::~WebStorageAreaImpl()
{
}

unsigned WebStorageAreaImpl::length()
{
    DOMStorageMap::iterator it = m_cachedArea.find((String)m_origin.toString());
    if (it == m_cachedArea.end())
        return 0;

    return it->value->size();
}

blink::WebString WebStorageAreaImpl::key(unsigned index)
{
    notImplemented();
    return blink::WebString();
}

blink::WebString WebStorageAreaImpl::getItem(const blink::WebString& key)
{
    DOMStorageMap::iterator it = m_cachedArea.find((String)m_origin.toString());
    if (it == m_cachedArea.end())
        return blink::WebString();

    HashMap<String, String>::iterator keyValueIt = (it->value)->find((String)key);
    if (keyValueIt == (it->value)->end())
        return blink::WebString();
    return blink::WebString(keyValueIt->value);
}

void WebStorageAreaImpl::setItem(const blink::WebString& key, const blink::WebString& value,
    const blink::WebURL& pageUrl, blink::WebStorageArea::Result& result)
{
    String pageString = (String)pageUrl.string();
    DOMStorageMap::iterator it = m_cachedArea.find(pageString);
    HashMap<String, String>* pageStorageArea;
    if (it == m_cachedArea.end()) {
        pageStorageArea = new HashMap<String, String>();
        m_cachedArea.set(pageString, pageStorageArea);
    } else
        pageStorageArea = it->value;

    pageStorageArea->set(key, value);
    result = blink::WebStorageArea::ResultOK;
}

void WebStorageAreaImpl::removeItem(const blink::WebString& key, const blink::WebURL& pageUrl)
{
    String pageString = (String)pageUrl.string();
    DOMStorageMap::iterator it = m_cachedArea.find(pageString);
    if (it == m_cachedArea.end())
        return;

    it->value->remove((String)key);

    if (0 == it->value->size()) {
        delete it->value;
        m_cachedArea.remove(it);
    }
}

void WebStorageAreaImpl::clear(const blink::WebURL& url)
{
    String pageString = (String)url.string();
    DOMStorageMap::iterator it = m_cachedArea.find(pageString);
    if (it == m_cachedArea.end())
        return;

    delete it->value;
    m_cachedArea.remove(it);
}

size_t WebStorageAreaImpl::memoryBytesUsedByCache() const
{
    return 100;
}

} // content
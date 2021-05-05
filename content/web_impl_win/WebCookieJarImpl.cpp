
#include "content/web_impl_win/WebCookieJarImpl.h"
#include "third_party/WebKit/Source/wtf/text/WTFStringUtil.h"
#include "third_party/WebKit/public/platform/WebURL.h"
#include <WinInet.h>
#include <windows.h>

extern "C" {

extern long curl_cookies_count(void* curl);
extern void* curl_first_cookie(void* curl);
extern void* curl_next_cookie(void* cookie);
extern const char* curl_cookie_name(void* cookie);
extern const char* curl_cookie_value(void* cookie);
extern const char* curl_cookie_domain(void* cookie);
extern const char* curl_cookie_path(void* cookie);
extern bool curl_cookie_secure(void* cookie);
extern int64_t curl_cookie_expires(void* c);
extern void* curl_cookie_add(void* curl, const char* value, const char* domain, const char* path);
}

namespace content {

WebCookieJarImpl* WebCookieJarImpl::m_inst = nullptr;

class HttpCookie {
public:
    HttpCookie()
    {
        reset();
    }

    void reset()
    {
        m_expires = 0;
        m_domain = String();
        m_path = String();
        m_name = String();
        m_value = String();
        m_secure = false;
        m_httpOnly = false;
    }

    bool isSecure()
    {
        return m_secure;
    }

    void setSecure(bool enable)
    {
        m_secure = enable;
    }

    bool isHttpOnly() const
    {
        return m_httpOnly;
    }

    void setHttpOnly(bool enable)
    {
        m_httpOnly = enable;
    }

    bool isSessionCookie() const
    {
        return m_expires == 0;
    }

    int64_t expires() const
    {
        return m_expires;
    }

    void setExpires(int64_t expires)
    {
        m_expires = expires;
    }

    const String& domain() const
    {
        return m_domain;
    }

    void setDomain(const String& domain)
    {
        if (!domain.isEmpty() && domain[0] != L'.') {
            m_domain = String(L".") + domain;
            return;
        }

        m_domain = domain;
    }

    const String& path() const
    {
        return m_path;
    }

    void setPath(const String& path)
    {
        m_path = path;
    }

    const String& name() const
    {
        return m_name;
    }

    void setName(const String& name)
    {
        m_name = name;
    }

    const String& value() const
    {
        return m_value;
    }

    void setValue(const String& value)
    {
        m_value = value;
    }

private:
    int64_t m_expires;
    String m_domain;
    String m_path;
    String m_name;
    String m_value;
    bool m_secure;
    bool m_httpOnly;
};

inline bool isParentDomain(const String& domain, const String& reference)
{
    if (reference.isEmpty())
        return reference.isEmpty();

    if (domain.endsWith(reference))
        return true;

    if (domain.length() + 1 == reference.length())
        return reference.endsWith(domain);

    return false;
}

inline bool isParentPath(const String& path, const String& reference)
{
    return path.startsWith(reference);
}

void WebCookieJarImpl::setRecordFromCurl(void* curl)
{
    //     void* cookie = curl_first_cookie(curl);
    //     while (cookie) {
    //         HttpCookie c;
    //
    // //         if (true
    // //             && nullptr == strstr(curl_cookie_name(cookie), "cna")
    // //             && nullptr == strstr(curl_cookie_name(cookie), "sca")
    // //             && nullptr == strstr(curl_cookie_name(cookie), "tbsa")
    // //             && nullptr == strstr(curl_cookie_name(cookie), "atpsida")
    // //             //&& 0 != strcmp(curl_cookie_name(cookie), "_m_h5_tk")
    // //             ) {
    //             c.setName(curl_cookie_name(cookie));
    //             c.setValue(curl_cookie_value(cookie));
    //             c.setDomain(curl_cookie_domain(cookie));
    //             c.setPath(curl_cookie_path(cookie));
    //
    // //             if (1) {
    // //                 String d = "setRecordFromCurl domain:";
    // //                 d.append(c.domain());
    // //                 d.append(" name: ");
    // //                 d.append(c.name());
    // //                 d.append("\n");
    // //                 OutputDebugStringW(d.charactersWithNullTermination().data());
    // //                 if ("cna" == c.name())
    // //                     curl = curl;
    // //             }
    //
    //             addToReord(c);
    //         //}
    //
    //         cookie = curl_next_cookie(cookie);
    //     }
}

void WebCookieJarImpl::setToCurlAndRecord(void* handle, const KURL& url, const String& value)
{
    String host = url.host();
    String path = url.path();

    if (handle) {
        //         void* cookie = curl_cookie_add(handle, value.utf8().data(), host.utf8().data(), path.utf8().data());
        //         if (cookie)
        //         {
        //             HttpCookie c;
        //             c.setName(curl_cookie_name(cookie));
        //             c.setValue(curl_cookie_value(cookie));
        //             c.setDomain(curl_cookie_domain(cookie));
        //             c.setPath(curl_cookie_path(cookie));
        //
        // //             if (1) {
        // //                 String d = "setToCurlAndRecord domain:";
        // //                 d.append(c.domain());
        // //                 d.append(" name: ");
        // //                 d.append(c.name());
        // //                 d.append("\n");
        // //                 OutputDebugStringW(d.charactersWithNullTermination().data());
        // //             }
        //             addToReord(c);
        //             return;
        //         }
    }

    size_t pos = value.find(L'=');
    if (pos != WTF::kNotFound) {
        size_t end = value.find(L';');
        if (end == WTF::kNotFound)
            end = value.length();

        HttpCookie c;
        c.setName(value.substring(0, pos));
        c.setValue(value.substring(pos + 1, end - pos - 1));
        c.setDomain(host);
        c.setPath(path);
        addToReord(c);
    }
}

String WebCookieJarImpl::getFromRecord(const KURL& url)
{
    Vector<HttpCookie> cookies;
    String domain = url.host();
    String path = url.path();

    for (unsigned int i = 0; i < m_recordCookies.size(); ++i) {
        if (!isParentDomain(domain, m_recordCookies[i].domain()))
            continue;

        if (!isParentPath(path, m_recordCookies[i].path()))
            continue;

        cookies.append(m_recordCookies[i]);
    }

    String res;
    for (unsigned int i = 0; i < cookies.size(); ++i) {
        if (i > 0)
            res.append("; ");

        res.append(cookies[i].name());
        res.append("=");
        res.append(cookies[i].value());
    }

    //     OutputDebugStringW(L"getFromRecord:");
    //     OutputDebugStringW(res.charactersWithNullTermination().data());
    //     OutputDebugStringW(L"\n");

    return res;
}

void WebCookieJarImpl::addToReord(const HttpCookie& c)
{
    for (unsigned int i = 0; i < m_recordCookies.size(); ++i) {
        if (m_recordCookies[i].name() == c.name() && m_recordCookies[i].domain() == c.domain() && m_recordCookies[i].path() == c.path()) {
            m_recordCookies[i] = c;
            return;
        }
    }

    m_recordCookies.append(c);
}

WebCookieJarImpl::CookieInfo::CookieInfo(const KURL& url, const KURL& firstPartyForCookies, const WebString& cookie)
{
    this->url = url;
    this->firstPartyForCookies = firstPartyForCookies;
    this->cookie = (String)cookie;
}

//----WebCookieJar----
void WebCookieJarImpl::setCookie(const WebURL& webUrl, const WebURL& webFirstPartyForCookies, const WebString& webCookie)
{
#if 0
    KURL url = webUrl;
    KURL firstPartyForCookies = webFirstPartyForCookies;
    for (size_t i = 0; i < m_tempCacheCookie.size(); ++i) {
        if (m_tempCacheCookie[i]->url != url || m_tempCacheCookie[i]->firstPartyForCookies != firstPartyForCookies)
            continue;
        m_tempCacheCookie[i]->cookie = webCookie;
    }

    m_tempCacheCookie.append(new CookieInfo(url, firstPartyForCookies, cookie));
#else
    String url = (String)(webUrl.string());
    String cookie = (String)webCookie;
    //     size_t pos = cookie.find(L'=');
    //     size_t end = 0;
    //     if (pos == WTF::kNotFound)
    //         return;
    //
    //     end = cookie.find(L';');
    //     if (WTF::kNotFound == end)
    //         end = cookie.length();
    //
    //     InternetSetCookieA(WTF::ensureStringToUTF8(url).data(),
    //         WTF::ensureStringToUTF8(cookie.substring(0, pos)).data(),
    //         WTF::ensureStringToUTF8(cookie.substring(pos + 1, end - pos - 1)).data());
    Vector<char> urlBuffer = WTF::ensureStringToUTF8(url);
    Vector<char> cookieBuffer = WTF::ensureStringToUTF8(cookie);
    InternetSetCookieA(urlBuffer.data(), NULL, cookieBuffer.data());

    String rawCookiesHeads = "Set-Cookie: ";
    rawCookiesHeads.append(cookieBuffer.data());
    setToRecordFromRawHeads(KURL(ParsedURLString, urlBuffer.data()), rawCookiesHeads);
#endif
}

WebString WebCookieJarImpl::cookies(const WebURL& webUrl, const WebURL& webFirstPartyForCookies)
{
    KURL url = webUrl;
    KURL firstPartyForCookies = webFirstPartyForCookies;
#if 1
    //return WebString::fromLatin1("v=0; t=5f004cfb854088c7910e80c3e62c0dc0"); // weolar
    String cookies = getFromRecord(url);
    //     OutputDebugStringW(L"WebCookieJarImpl::cookies:");
    //     OutputDebugStringW(cookies.charactersWithNullTermination().data());
    //     OutputDebugStringW(L"\n");
    return WebString(cookies);
#else
    Vector<char> cookies;
    DWORD dwSize = 1024;
    cookies.resize(dwSize + 1);
    memset(cookies.data(), 0, dwSize + 1);

    if (!InternetGetCookieExA(WTF::ensureStringToUTF8(url.string()).data(), NULL, cookies.data(), &dwSize, INTERNET_COOKIE_HTTPONLY, NULL))
        return WebString();
    OutputDebugStringW(L"WebCookieJarImpl::cookies:");
    OutputDebugStringA(cookies.data());
    OutputDebugStringW(L"\n");
    return WebString::fromUTF8(cookies.data(), dwSize);
#endif
}

// WebString WebCookieJarImpl::cookieRequestHeaderFieldValue(const WebURL& url, const WebURL& firstPartyForCookies)
// {
//     notImplemented();
//     return WebString();
// }

//////////////////////////////////////////////////////////////////////////

void WebCookieJarImpl::applyCookieAndRecordRealCookies(void* curl)
{
    for (size_t i = 0; i < m_tempCacheCookie.size(); ++i) {
        setToCurlAndRecord(curl, m_tempCacheCookie[i]->url, m_tempCacheCookie[i]->cookie);
    }
    setRecordFromCurl(curl);
}

static bool isNameValueString(const String& s)
{
    return !equalIgnoringCase(s, "Domain") && !equalIgnoringCase(s, "Expires") && !equalIgnoringCase(s, "Path");
}

static size_t forwardOneToken(const String& string, const char* token, size_t pos)
{
    pos = string.find(token, pos);
    if (WTF::kNotFound != pos)
        pos += strlen(token);
    return pos;
}

static bool getOneKeyValuePair(String& rawHeads, size_t& pos, const size_t& endPos, String& key, String& value, bool& isEnd)
{
    for (; pos < endPos && ' ' == rawHeads[pos]; ++pos) { }
    if (endPos == pos)
        return false;

    size_t posTemp = forwardOneToken(rawHeads, "=", pos + 1);
    if (WTF::kNotFound == posTemp)
        return false;
    String tempString((rawHeads.characters8() + pos), posTemp - pos - 1);
    tempString.stripWhiteSpace();

    key = tempString;

    for (pos = posTemp; pos < endPos; ++pos) {
        char c = rawHeads[pos];
        if (';' == c)
            break;
        if ('\r' == c || '\n' == c) {
            isEnd = true;
            break;
        }
    }

    if (pos == posTemp)
        return true;

    if (endPos == pos)
        isEnd = true;

    tempString = String(rawHeads.characters8() + posTemp, pos - posTemp);
    tempString.stripWhiteSpace();
    value = tempString;

    ++pos;

    return true;
}

// void WebCookieJarImpl::setToRecordFromRawHeads(const KURL& url, const String& rawHeadsString)
// {
//     String rawHeads = ensureStringToUTF8String(rawHeadsString);
//     size_t pos = 0;
//     size_t endPos = rawHeads.length();
//
//     while (true) {
//         pos = forwardOneToken(rawHeads, "Set-Cookie:", pos);
//         if (WTF::kNotFound == pos)
//             break;
//
//         HttpCookie cookie;
//         while (true) {
//             String key;
//             String value;
//             bool isEnd = false;
//             if (!getOneKeyValuePair(rawHeads, pos, endPos, key, value, isEnd))
//                 break;
//
//             if (equalIgnoringCase(key, "Domain")) {
//                 cookie.setDomain(value);
//             }
//             else if (equalIgnoringCase(key, "Path")) {
//                 cookie.setPath(value);
//             }
//             else if (!equalIgnoringCase(key, "Expires")) {
//                 cookie.setName(key);
//                 cookie.setValue(value);
//             }
//             if (isEnd)
//                 break;
//         }
//         addToReord(cookie);
//     }
// }

// HTTP/1.1 200 OK
// Cache-Control: private,no-cache, no-store, must-revalidate
// Pragma: no-cache,no-cache
// Content-Length: 39336
// Content-Type: text/html; charset=utf-8
// Expires: 0
// X-AspNet-Version: 2.0.50727
// X-b365-ScriptVersion: 4.2.25.0|2.1.49.0|1.6.18.0
// X-UA-Compatible: requiresActiveX=true
// X-b365-AppStatus: Ok
// Set-Cookie: session=processform=0; path=/; secure
// Set-Cookie: pstk=F2045B52B9A04D0BAC692ECD32B0AEB0000003; domain=.48-365365.com; path=/; secure
// Set-Cookie: Hm_lvt_90056b3f84f90da57dc0f40150f005d5=1462436025; domain=passport.baidu.com; path=/; expires=Fri, 05 May 2017 08:13:45 GMT
// Date: Mon, 14 Mar 2016 12:18:39 GMT
void WebCookieJarImpl::setToRecordFromRawHeads(const KURL& url, const String& rawHeadsString)
{
    String rawHeads = ensureStringToUTF8String(rawHeadsString);
    size_t pos = 0;
    size_t endPos = rawHeads.length();

    WTF::Vector<String> items; // 分离出Expires: 0这样的一项
    WTF::splitStringToVector(rawHeads, '\n', true, items);
    for (size_t i = 0; i < items.size(); ++i) {
        size_t findPos = items[i].find("Set-Cookie:");
        if (WTF::kNotFound == findPos)
            continue;

        //         WTF::Vector<String> cookieItems; // 分离出以":"为分割的两段，一段是Set-Cookie
        //         WTF::splitStringToVector(items[i], ':', true, cookieItems);
        //         if (cookieItems.size() != 2)
        //             continue;
        String cookieItems = items[i].right(items[i].length() - findPos - sizeof("Set-Cookie:"));
        if (cookieItems.isNull() || cookieItems.isEmpty())
            continue;

        WTF::Vector<String> names;
        String value;
        HttpCookie cookie;
        WTF::Vector<String> cookieString; // 分离出domain=.48-65365.com
        WTF::splitStringToVector(cookieItems, ';', true, cookieString);
        for (size_t j = 0; j < cookieString.size(); ++j) {
            WTF::Vector<String> cookiePair; // 分离出domain和.48-65365.com
            WTF::splitStringToVector(cookieString[j], '=', true, cookiePair);
            if (cookiePair.size() <= 1)
                continue;

            if (2 == cookiePair.size()) {
                if (equalIgnoringCase(cookiePair[0], "Domain")) {
                    cookie.setDomain(cookiePair[1]);
                } else if (equalIgnoringCase(cookiePair[0], "Path")) {
                    cookie.setPath(cookiePair[1]);
                } else if (!equalIgnoringCase(cookiePair[0], "Expires")) {
                    names.append(cookiePair[0]);
                    value = cookiePair[1];
                }
            } else if (3 <= cookiePair.size()) { // session = processform = 0 这种
                for (size_t keyIt = 0; keyIt < cookiePair.size() - 1; ++keyIt)
                    names.append(cookiePair[keyIt]);
                value = cookiePair[cookiePair.size() - 1];
            }
        }

        for (size_t k = 0; k < names.size(); ++k) {
            HttpCookie cookieCopy = cookie;
            cookieCopy.setName(names[k]);
            cookieCopy.setValue(value);
            addToReord(cookieCopy);
        }
    }
}

WebCookieJarImpl* WebCookieJarImpl::inst()
{
    if (!m_inst)
        m_inst = new WebCookieJarImpl();
    return m_inst;
}

} // namespace content
#ifndef WebCookieJarImph_h
#define WebCookieJarImph_h

#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/public/platform/WebCookieJar.h"

using namespace blink;

namespace content {

class HttpCookie;

class WebCookieJarImpl : public WebCookieJar {
public:
    virtual void setCookie(const WebURL&, const WebURL& firstPartyForCookies, const WebString& cookie) override;
    virtual WebString cookies(const WebURL&, const WebURL& firstPartyForCookies) override;
    //virtual WebString cookieRequestHeaderFieldValue(const WebURL&, const WebURL& firstPartyForCookies) override;
    virtual bool cookiesEnabled(const WebURL&, const WebURL& firstPartyForCookies) override { return true; }

    void applyCookieAndRecordRealCookies(void* curl);

    void setRecordFromCurl(void* curl);
    void setToCurlAndRecord(void* handle, const KURL& url, const String& value);
    String getFromRecord(const KURL& url);
    void addToReord(const HttpCookie& c);

    void setToRecordFromRawHeads(const KURL& url, const String& rawHeadsString);

    static WebCookieJarImpl* inst();

private:
    Vector<HttpCookie> m_recordCookies;

    struct CookieInfo {
        CookieInfo(const KURL&, const KURL& firstPartyForCookies, const WebString& cookie);

        KURL url;
        KURL firstPartyForCookies;
        String cookie;
    };
    Vector<CookieInfo*> m_tempCacheCookie;

    static WebCookieJarImpl* m_inst;
};

} // content

#endif // WebCookieJarImph_h
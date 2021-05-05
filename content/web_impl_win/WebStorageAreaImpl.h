// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_RENDERER_DOM_STORAGE_WEBSTORAGEAREA_IMPL_H_
#define CONTENT_RENDERER_DOM_STORAGE_WEBSTORAGEAREA_IMPL_H_

#include "content/web_impl_win/WebStorageNamespaceImpl.h"
#include "third_party/WebKit/public/platform/WebSecurityOrigin.h"
#include "third_party/WebKit/public/platform/WebStorageArea.h"
#include "third_party/WebKit/public/platform/WebString.h"
#include "wtf/HashMap.h"

namespace blink {
class KURL;
class DOMStorageCachedArea;
}

namespace content {

class WebStorageAreaImpl : public blink::WebStorageArea {
public:
    WebStorageAreaImpl(DOMStorageMap& cachedArea, const blink::WebSecurityOrigin& origin);
    virtual ~WebStorageAreaImpl();

    // See WebStorageArea.h for documentation on these functions.
    virtual unsigned length();

    virtual blink::WebString key(unsigned index);

    virtual blink::WebString getItem(const blink::WebString& key);

    virtual void setItem(const blink::WebString& key, const blink::WebString& value,
        const blink::WebURL& page_url, blink::WebStorageArea::Result& result);

    virtual void removeItem(const blink::WebString& key, const blink::WebURL& page_url);

    virtual void clear(const blink::WebURL& url);

    virtual size_t memoryBytesUsedByCache() const;

private:
    blink::WebSecurityOrigin m_origin;
    DOMStorageMap& m_cachedArea;
};

} // namespace content

#endif // CONTENT_RENDERER_DOM_STORAGE_WEBSTORAGEAREA_IMPL_H_

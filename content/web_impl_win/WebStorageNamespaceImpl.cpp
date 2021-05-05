// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/web_impl_win/WebStorageNamespaceImpl.h"
#include "content/web_impl_win/WebStorageAreaImpl.h"

#include "third_party/WebKit/public/platform/WebString.h"

using blink::WebStorageArea;
using blink::WebStorageNamespace;
using blink::WebString;

namespace content {

WebStorageNamespaceImpl::WebStorageNamespaceImpl(int64 namespaceId, DOMStorageMap& cachedArea)
    : m_cachedArea(cachedArea)
    , m_namespaceId(namespaceId)
{
}

WebStorageNamespaceImpl::~WebStorageNamespaceImpl()
{
}

blink::WebStorageArea* WebStorageNamespaceImpl::createStorageArea(const blink::WebSecurityOrigin& origin)
{
    return new WebStorageAreaImpl(m_cachedArea, origin);
}

blink::WebStorageNamespace* WebStorageNamespaceImpl::copy()
{
    // By returning NULL, we're telling WebKit to lazily fetch it the next time
    // session storage is used.  In the WebViewClient::createView, we do the
    // book-keeping necessary to make it a true copy-on-write despite not doing
    // anything here, now.
    return NULL;
}

bool WebStorageNamespaceImpl::isSameNamespace(const blink::WebStorageNamespace& other) const
{
    const WebStorageNamespaceImpl* other_impl = static_cast<const WebStorageNamespaceImpl*>(&other);
    return m_namespaceId == other_impl->m_namespaceId;
    return false;
}

} // namespace content

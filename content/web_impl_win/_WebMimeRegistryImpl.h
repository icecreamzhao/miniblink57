// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebMimeRegistryImpl_h
#define WebMimeRegistryImpl_h

#include <string>

#include "base/compiler_specific.h"
#include "third_party/WebKit/public/platform/WebMimeRegistry.h"

namespace content {

class WebMimeRegistryImpl : NON_EXPORTED_BASE(public blink::WebMimeRegistry) {
public:
    WebMimeRegistryImpl();
    virtual ~WebMimeRegistryImpl();

    // WebMimeRegistry methods:
    virtual blink::WebMimeRegistry::SupportsType supportsMIMEType(
        const blink::WebString&) override;

    virtual blink::WebMimeRegistry::SupportsType supportsImageMIMEType(
        const blink::WebString&) override;

    virtual blink::WebMimeRegistry::SupportsType supportsJavaScriptMIMEType(
        const blink::WebString&) override;

    virtual blink::WebMimeRegistry::SupportsType supportsMediaMIMEType(
        const blink::WebString&,
        const blink::WebString&) override;

    virtual bool supportsMediaSourceMIMEType(const blink::WebString&,
        const blink::WebString&) override;

    virtual blink::WebMimeRegistry::SupportsType supportsNonImageMIMEType(
        const blink::WebString&) override;

    virtual blink::WebString mimeTypeForExtension(const blink::WebString&) override;

    virtual blink::WebString wellKnownMimeTypeForExtension(
        const blink::WebString&) override;

    //virtual blink::WebString mimeTypeFromFile(const blink::WebString&) override;

    virtual blink::WebMimeRegistry::SupportsType supportsImagePrefixedMIMEType(const blink::WebString& mimeType) override;
};

} // namespace content

#endif // WebMimeRegistryImpl_h

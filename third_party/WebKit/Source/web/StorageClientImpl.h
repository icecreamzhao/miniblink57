// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StorageClientImpl_h
#define StorageClientImpl_h

#include "modules/storage/StorageClient.h"
#include <memory>

namespace blink {

class WebViewImpl;

class StorageClientImpl : public StorageClient {
public:
    explicit StorageClientImpl(WebViewImpl*);

    std::unique_ptr<StorageNamespace> createSessionStorageNamespace() override;
#ifndef MINIBLINK_NO_PAGE_LOCALSTORAGE
    std::unique_ptr<StorageNamespace> createLocalStorageNamespace() override;
#endif
    bool canAccessStorage(LocalFrame*, StorageType) const override;

private:
    WebViewImpl* m_webView;
};

} // namespace blink

#endif // StorageClientImpl_h

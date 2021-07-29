// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebURLLoaderImplCurl_h
#define WebURLLoaderImplCurl_h

#include "third_party/WebKit/public/platform/WebURLLoader.h"
#include "third_party/WebKit/Source/platform/Timer.h"

namespace blink {
class WebURLRequest;
class WebURLLoaderClient;
}

namespace net {
class WebURLLoaderInternal;
class BlobResourceLoader;
}

using namespace blink;

namespace content {

class WebURLLoaderImplCurl : public blink::WebURLLoader {
public:
    WebURLLoaderImplCurl();
    virtual ~WebURLLoaderImplCurl();

    void init();

    // WebURLLoader methods:
    virtual void loadSynchronously(
        const blink::WebURLRequest& request,
        blink::WebURLResponse& response,
        blink::WebURLError& error,
        blink::WebData& data,
        int64_t& encodedDataLength,
        int64_t& encodedBodyLength) override;
    virtual void loadAsynchronously(
        const blink::WebURLRequest& request,
        blink::WebURLLoaderClient* client) override;
    virtual void cancel() override;
    virtual void setDefersLoading(bool value) override;
    virtual void didChangePriority(blink::WebURLRequest::Priority new_priority, int intra_priority_value) override;
    //virtual bool attachThreadedDataReceiver(blink::WebThreadedDataReceiver* threaded_data_receiver) override;

    void fileLoadImpl(const blink::KURL& url);

    //void fireFailure(blink::Timer<WebURLLoaderImplCurl>*);
   
    //net::WebURLLoaderInternal* loaderInterna() { return m_webURLLoaderInternal; }
    void setLoadingTaskRunner(base::SingleThreadTaskRunner *) override;

private:
    bool* m_hadDestroied;
    int m_jobIds;

    net::BlobResourceLoader* m_blobLoader;
};

}  // namespace content

#endif  // WebURLLoaderImplCurl_h

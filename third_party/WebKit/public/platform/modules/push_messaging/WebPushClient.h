// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebPushClient_h
#define WebPushClient_h

#include "public/platform/WebCallbacks.h"
#include "public/platform/modules/push_messaging/WebPushError.h"
<<<<<<< HEAD
#include "public/platform/modules/push_messaging/WebPushProvider.h"
#include <memory>
=======
>>>>>>> miniblink49

namespace blink {

class WebServiceWorkerRegistration;
<<<<<<< HEAD
struct WebPushSubscriptionOptions;

=======
struct WebPushSubscription;
struct WebPushSubscriptionOptions;

using WebPushSubscriptionCallbacks = WebCallbacks<WebPushSubscription, WebPushError>;

>>>>>>> miniblink49
class WebPushClient {
public:
    virtual ~WebPushClient() { }

    // Ownership of the WebServiceWorkerRegistration is not transferred.
    // Ownership of the callbacks is transferred to the client.
<<<<<<< HEAD
    virtual void subscribe(WebServiceWorkerRegistration*,
        const WebPushSubscriptionOptions&,
        std::unique_ptr<WebPushSubscriptionCallbacks>)
        = 0;
=======
    virtual void subscribe(WebServiceWorkerRegistration*, const WebPushSubscriptionOptions&, WebPushSubscriptionCallbacks*) = 0;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebPushClient_h

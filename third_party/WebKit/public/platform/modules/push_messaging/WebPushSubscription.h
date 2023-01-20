// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebPushSubscription_h
#define WebPushSubscription_h

#include "public/platform/WebCommon.h"
<<<<<<< HEAD
#include "public/platform/WebURL.h"
#include "public/platform/WebVector.h"
#include "public/platform/modules/push_messaging/WebPushSubscriptionOptions.h"
=======
#include "public/platform/WebString.h"
#include "public/platform/WebURL.h"
>>>>>>> miniblink49

namespace blink {

struct WebPushSubscription {
<<<<<<< HEAD
    // The |endpoint|, |p256dh| and |auth| must all be unique for each
    // subscription.
    WebPushSubscription(const WebURL& endpoint,
        bool userVisibleOnly,
        const WebString& applicationServerKey,
        const WebVector<unsigned char>& p256dh,
        const WebVector<unsigned char>& auth)
        : endpoint(endpoint)
        , p256dh(p256dh)
        , auth(auth)
    {
        options.userVisibleOnly = userVisibleOnly;
        options.applicationServerKey = applicationServerKey;
    }

    WebURL endpoint;
    WebPushSubscriptionOptions options;
    WebVector<unsigned char> p256dh;
    WebVector<unsigned char> auth;
=======
    explicit WebPushSubscription(const WebURL& endpoint)
        : endpoint(endpoint)
    {
    }

    // TODO(peter): Remove this constructor when the embedder switched over to the one above.
    BLINK_PLATFORM_EXPORT WebPushSubscription(const WebString& endpointWithoutSubscriptionId, const WebString& subscriptionId);

    WebURL endpoint;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebPushSubscription_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebCredentialManagerClient_h
#define WebCredentialManagerClient_h

#include "public/platform/WebCallbacks.h"
#include "public/platform/WebCredentialManagerError.h"
#include "public/platform/WebVector.h"

<<<<<<< HEAD
#include <memory>

=======
>>>>>>> miniblink49
namespace blink {

class WebCredential;
class WebURL;

// WebCredentialManagerClient is an interface which allows an embedder to
// implement 'navigator.credential.*' calls which are defined in the
// 'credentialmanager' module.
class WebCredentialManagerClient {
public:
<<<<<<< HEAD
    typedef WebCallbacks<std::unique_ptr<WebCredential>,
        WebCredentialManagerError>
        RequestCallbacks;
=======
    typedef WebCallbacks<WebCredential, WebCredentialManagerError> RequestCallbacks;
>>>>>>> miniblink49
    typedef WebCallbacks<void, WebCredentialManagerError> NotificationCallbacks;

    // Ownership of the callback is transferred to the callee for each of
    // the following methods.
<<<<<<< HEAD
    virtual void dispatchFailedSignIn(const WebCredential&,
        NotificationCallbacks*) { }
    virtual void dispatchStore(const WebCredential&, NotificationCallbacks*) { }
    virtual void dispatchRequireUserMediation(NotificationCallbacks*) { }
    virtual void dispatchGet(bool zeroClickOnly,
        bool includePasswords,
        const WebVector<WebURL>& federations,
        RequestCallbacks*) { }
=======
    virtual void dispatchFailedSignIn(const WebCredential&, NotificationCallbacks*) { }
    virtual void dispatchSignedIn(const WebCredential&, NotificationCallbacks*) { }
    virtual void dispatchRequireUserMediation(NotificationCallbacks*) { }
    virtual void dispatchRequest(bool zeroClickOnly, const WebVector<WebURL>& federations, RequestCallbacks*) { }
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebCredentialManager_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/platform/WebFederatedCredential.h"

#include "platform/credentialmanager/PlatformFederatedCredential.h"

namespace blink {
<<<<<<< HEAD
WebFederatedCredential::WebFederatedCredential(
    const WebString& id,
    const WebSecurityOrigin& provider,
    const WebString& name,
    const WebURL& iconURL)
    : WebCredential(
        PlatformFederatedCredential::create(id, provider, name, iconURL))
=======
WebFederatedCredential::WebFederatedCredential(const WebString& id, const WebURL& provider, const WebString& name, const WebURL& iconURL)
    : WebCredential(PlatformFederatedCredential::create(id, provider, name, iconURL))
>>>>>>> miniblink49
{
}

void WebFederatedCredential::assign(const WebFederatedCredential& other)
{
    m_platformCredential = other.m_platformCredential;
}

<<<<<<< HEAD
WebSecurityOrigin WebFederatedCredential::provider() const
{
    return static_cast<PlatformFederatedCredential*>(m_platformCredential.get())
        ->provider();
=======
WebURL WebFederatedCredential::provider() const
{
    return static_cast<PlatformFederatedCredential*>(m_platformCredential.get())->provider();
>>>>>>> miniblink49
}

WebFederatedCredential::WebFederatedCredential(PlatformCredential* credential)
    : WebCredential(credential)
{
}

<<<<<<< HEAD
WebFederatedCredential& WebFederatedCredential::operator=(
    PlatformCredential* credential)
=======
WebFederatedCredential& WebFederatedCredential::operator=(PlatformCredential* credential)
>>>>>>> miniblink49
{
    m_platformCredential = credential;
    return *this;
}

} // namespace blink
<<<<<<< HEAD
=======

>>>>>>> miniblink49

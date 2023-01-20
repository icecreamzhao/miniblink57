// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/platform/WebCredential.h"

#include "platform/credentialmanager/PlatformCredential.h"
#include "public/platform/WebFederatedCredential.h"
#include "public/platform/WebPasswordCredential.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"

namespace blink {

std::unique_ptr<WebCredential> WebCredential::create(
    PlatformCredential* credential)
{
    if (credential->isPassword()) {
        return WTF::makeUnique<WebPasswordCredential>(credential);
    }

    if (credential->isFederated()) {
        return WTF::makeUnique<WebFederatedCredential>(credential);
    }

    ASSERT_NOT_REACHED();
    return nullptr;
}

WebCredential::WebCredential(const WebString& id,
    const WebString& name,
    const WebURL& iconURL)
=======

namespace blink {

WebCredential WebCredential::create(PlatformCredential* credential)
{
    if (credential->isPassword()) {
        WebPasswordCredential password(credential);
        return password;
    }

    if (credential->isFederated()) {
        WebFederatedCredential federated(credential);
        return federated;
    }

    ASSERT_NOT_REACHED();
    return WebCredential(credential);
}

WebCredential::WebCredential(const WebString& id, const WebString& name, const WebURL& iconURL)
>>>>>>> miniblink49
    : m_platformCredential(PlatformCredential::create(id, name, iconURL))
{
}

WebCredential::WebCredential(const WebCredential& other)
{
    assign(other);
}

void WebCredential::assign(const WebCredential& other)
{
    m_platformCredential = other.m_platformCredential;
}

WebCredential::WebCredential(PlatformCredential* credential)
    : m_platformCredential(credential)
{
}

WebCredential& WebCredential::operator=(PlatformCredential* credential)
{
    m_platformCredential = credential;
    return *this;
}

void WebCredential::reset()
{
    m_platformCredential.reset();
}

WebString WebCredential::id() const
{
    return m_platformCredential->id();
}

WebString WebCredential::name() const
{
    return m_platformCredential->name();
}

WebURL WebCredential::iconURL() const
{
    return m_platformCredential->iconURL();
}

WebString WebCredential::type() const
{
    return m_platformCredential->type();
}

bool WebCredential::isPasswordCredential() const
{
    return m_platformCredential->isPassword();
}

bool WebCredential::isFederatedCredential() const
{
    return m_platformCredential->isFederated();
}

} // namespace blink

// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/platform/WebPasswordCredential.h"

#include "platform/credentialmanager/PlatformPasswordCredential.h"

namespace blink {
<<<<<<< HEAD
WebPasswordCredential::WebPasswordCredential(const WebString& id,
    const WebString& password,
    const WebString& name,
    const WebURL& iconURL)
    : WebCredential(
        PlatformPasswordCredential::create(id, password, name, iconURL))
=======
WebPasswordCredential::WebPasswordCredential(const WebString& id, const WebString& password, const WebString& name, const WebURL& iconURL)
    : WebCredential(PlatformPasswordCredential::create(id, password, name, iconURL))
>>>>>>> miniblink49
{
}

void WebPasswordCredential::assign(const WebPasswordCredential& other)
{
    m_platformCredential = other.m_platformCredential;
}

WebString WebPasswordCredential::password() const
{
<<<<<<< HEAD
    return static_cast<PlatformPasswordCredential*>(m_platformCredential.get())
        ->password();
=======
    return static_cast<PlatformPasswordCredential*>(m_platformCredential.get())->password();
>>>>>>> miniblink49
}

WebPasswordCredential::WebPasswordCredential(PlatformCredential* credential)
    : WebCredential(credential)
{
}

<<<<<<< HEAD
WebPasswordCredential& WebPasswordCredential::operator=(
    PlatformCredential* credential)
=======
WebPasswordCredential& WebPasswordCredential::operator=(PlatformCredential* credential)
>>>>>>> miniblink49
{
    m_platformCredential = credential;
    return *this;
}

} // namespace blink
<<<<<<< HEAD
=======


>>>>>>> miniblink49

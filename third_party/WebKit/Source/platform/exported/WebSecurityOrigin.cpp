/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "public/platform/WebSecurityOrigin.h"

=======
#include "config.h"
#include "public/platform/WebSecurityOrigin.h"

#include "platform/weborigin/DatabaseIdentifier.h"
>>>>>>> miniblink49
#include "platform/weborigin/KURL.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/WebString.h"
#include "public/platform/WebURL.h"
#include "wtf/PassRefPtr.h"

namespace blink {

class WebSecurityOriginPrivate : public SecurityOrigin {
};

<<<<<<< HEAD
=======
WebSecurityOrigin WebSecurityOrigin::createFromDatabaseIdentifier(const WebString& databaseIdentifier)
{
    return WebSecurityOrigin(createSecurityOriginFromDatabaseIdentifier(databaseIdentifier));
}

>>>>>>> miniblink49
WebSecurityOrigin WebSecurityOrigin::createFromString(const WebString& origin)
{
    return WebSecurityOrigin(SecurityOrigin::createFromString(origin));
}

WebSecurityOrigin WebSecurityOrigin::create(const WebURL& url)
{
    return WebSecurityOrigin(SecurityOrigin::create(url));
}

<<<<<<< HEAD
WebSecurityOrigin WebSecurityOrigin::createFromTupleWithSuborigin(
    const WebString& protocol,
    const WebString& host,
    int port,
    const WebString& suborigin)
{
    return WebSecurityOrigin(
        SecurityOrigin::create(protocol, host, port, suborigin));
}

WebSecurityOrigin WebSecurityOrigin::createUnique()
{
    return WebSecurityOrigin(SecurityOrigin::createUnique());
}

=======
>>>>>>> miniblink49
void WebSecurityOrigin::reset()
{
    assign(0);
}

void WebSecurityOrigin::assign(const WebSecurityOrigin& other)
{
    WebSecurityOriginPrivate* p = const_cast<WebSecurityOriginPrivate*>(other.m_private);
    if (p)
        p->ref();
    assign(p);
}

WebString WebSecurityOrigin::protocol() const
{
<<<<<<< HEAD
    DCHECK(m_private);
=======
    ASSERT(m_private);
>>>>>>> miniblink49
    return m_private->protocol();
}

WebString WebSecurityOrigin::host() const
{
<<<<<<< HEAD
    DCHECK(m_private);
=======
    ASSERT(m_private);
>>>>>>> miniblink49
    return m_private->host();
}

unsigned short WebSecurityOrigin::port() const
{
<<<<<<< HEAD
    DCHECK(m_private);
    return m_private->port();
}

unsigned short WebSecurityOrigin::effectivePort() const
{
    DCHECK(m_private);
    return m_private->effectivePort();
}

WebString WebSecurityOrigin::suborigin() const
{
    DCHECK(m_private);
    return m_private->hasSuborigin() ? WebString(m_private->suborigin()->name())
                                     : WebString();
}

bool WebSecurityOrigin::isUnique() const
{
    DCHECK(m_private);
=======
    ASSERT(m_private);
    return m_private->port();
}

bool WebSecurityOrigin::isUnique() const
{
    ASSERT(m_private);
>>>>>>> miniblink49
    return m_private->isUnique();
}

bool WebSecurityOrigin::canAccess(const WebSecurityOrigin& other) const
{
<<<<<<< HEAD
    DCHECK(m_private);
    DCHECK(other.m_private);
=======
    ASSERT(m_private);
    ASSERT(other.m_private);
>>>>>>> miniblink49
    return m_private->canAccess(other.m_private);
}

bool WebSecurityOrigin::canRequest(const WebURL& url) const
{
<<<<<<< HEAD
    DCHECK(m_private);
    return m_private->canRequest(url);
}

bool WebSecurityOrigin::isPotentiallyTrustworthy() const
{
    DCHECK(m_private);
    return m_private->isPotentiallyTrustworthy();
=======
    ASSERT(m_private);
    return m_private->canRequest(url);
}

bool WebSecurityOrigin::isPotentiallyTrustworthy(WebString& errorMessage) const
{
    ASSERT(m_private);
    WTF::String message(errorMessage);
    bool result = m_private->isPotentiallyTrustworthy(message);
    errorMessage = message;
    return result;
>>>>>>> miniblink49
}

WebString WebSecurityOrigin::toString() const
{
<<<<<<< HEAD
    DCHECK(m_private);
    return m_private->toString();
}

bool WebSecurityOrigin::canAccessPasswordManager() const
{
    DCHECK(m_private);
    return m_private->canAccessPasswordManager();
}

WebSecurityOrigin::WebSecurityOrigin(WTF::PassRefPtr<SecurityOrigin> origin)
=======
    ASSERT(m_private);
    return m_private->toString();
}

WebString WebSecurityOrigin::databaseIdentifier() const
{
    ASSERT(m_private);
    return createDatabaseIdentifierFromSecurityOrigin(m_private);
}

bool WebSecurityOrigin::canAccessPasswordManager() const
{
    ASSERT(m_private);
    return m_private->canAccessPasswordManager();
}

WebSecurityOrigin::WebSecurityOrigin(const WTF::PassRefPtr<SecurityOrigin>& origin)
>>>>>>> miniblink49
    : m_private(static_cast<WebSecurityOriginPrivate*>(origin.leakRef()))
{
}

<<<<<<< HEAD
WebSecurityOrigin& WebSecurityOrigin::operator=(
    WTF::PassRefPtr<SecurityOrigin> origin)
=======
WebSecurityOrigin& WebSecurityOrigin::operator=(const WTF::PassRefPtr<SecurityOrigin>& origin)
>>>>>>> miniblink49
{
    assign(static_cast<WebSecurityOriginPrivate*>(origin.leakRef()));
    return *this;
}

WebSecurityOrigin::operator WTF::PassRefPtr<SecurityOrigin>() const
{
<<<<<<< HEAD
    return PassRefPtr<SecurityOrigin>(
        const_cast<WebSecurityOriginPrivate*>(m_private));
=======
    return PassRefPtr<SecurityOrigin>(const_cast<WebSecurityOriginPrivate*>(m_private));
>>>>>>> miniblink49
}

SecurityOrigin* WebSecurityOrigin::get() const
{
    return m_private;
}

void WebSecurityOrigin::assign(WebSecurityOriginPrivate* p)
{
    // p is already ref'd for us by the caller
    if (m_private)
        m_private->deref();
    m_private = p;
}

void WebSecurityOrigin::grantLoadLocalResources() const
{
    get()->grantLoadLocalResources();
}

} // namespace blink

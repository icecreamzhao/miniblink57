// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/credentialmanager/Credential.h"

#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"

namespace blink {

<<<<<<< HEAD
Credential::~Credential() { }
=======
Credential* Credential::create(const String& id, const String& name, const KURL& icon)
{
    return new Credential(id, name, icon);
}

Credential* Credential::create(const String& id, const String& name, const String& icon, ExceptionState& exceptionState)
{
    KURL iconURL = parseStringAsURL(icon, exceptionState);
    if (exceptionState.hadException())
        return nullptr;
    return new Credential(id, name, iconURL);
}
>>>>>>> miniblink49

Credential::Credential(PlatformCredential* credential)
    : m_platformCredential(credential)
{
}

Credential::Credential(const String& id, const String& name, const KURL& icon)
    : m_platformCredential(PlatformCredential::create(id, name, icon))
{
}

<<<<<<< HEAD
KURL Credential::parseStringAsURL(const String& url,
    ExceptionState& exceptionState)
=======
KURL Credential::parseStringAsURL(const String& url, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    if (url.isEmpty())
        return KURL();
    KURL parsedURL = KURL(KURL(), url);
    if (!parsedURL.isValid())
<<<<<<< HEAD
        exceptionState.throwDOMException(SyntaxError,
            "'" + url + "' is not a valid URL.");
=======
        exceptionState.throwDOMException(SyntaxError, "'" + url + "' is not a valid URL.");
>>>>>>> miniblink49
    return parsedURL;
}

DEFINE_TRACE(Credential)
{
    visitor->trace(m_platformCredential);
}

} // namespace blink

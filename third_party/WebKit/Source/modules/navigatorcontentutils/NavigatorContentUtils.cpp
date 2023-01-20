/*
 * Copyright (C) 2011, Google Inc. All rights reserved.
 * Copyright (C) 2014, Samsung Electronics. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/navigatorcontentutils/NavigatorContentUtils.h"

#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Navigator.h"
<<<<<<< HEAD
#include "core/frame/UseCounter.h"
=======
>>>>>>> miniblink49
#include "wtf/HashSet.h"
#include "wtf/text/StringBuilder.h"

namespace blink {

static HashSet<String>* schemeWhitelist;

static void initCustomSchemeHandlerWhitelist()
{
    schemeWhitelist = new HashSet<String>;
    static const char* const schemes[] = {
        "bitcoin",
        "geo",
        "im",
        "irc",
        "ircs",
        "magnet",
        "mailto",
        "mms",
        "news",
        "nntp",
        "openpgp4fpr",
        "sip",
        "sms",
        "smsto",
        "ssh",
        "tel",
        "urn",
        "webcal",
        "wtai",
        "xmpp",
    };
    for (size_t i = 0; i < WTF_ARRAY_LENGTH(schemes); ++i)
        schemeWhitelist->add(schemes[i]);
}

<<<<<<< HEAD
static bool verifyCustomHandlerURL(const Document& document,
    const String& url,
    ExceptionState& exceptionState)
=======
static bool verifyCustomHandlerURL(const Document& document, const String& url, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    // The specification requires that it is a SyntaxError if the "%s" token is
    // not present.
    static const char token[] = "%s";
    int index = url.find(token);
    if (-1 == index) {
<<<<<<< HEAD
        exceptionState.throwDOMException(
            SyntaxError, "The url provided ('" + url + "') does not contain '%s'.");
=======
        exceptionState.throwDOMException(SyntaxError, "The url provided ('" + url + "') does not contain '%s'.");
>>>>>>> miniblink49
        return false;
    }

    // It is also a SyntaxError if the custom handler URL, as created by removing
    // the "%s" token and prepending the base url, does not resolve.
    String newURL = url;
    newURL.remove(index, WTF_ARRAY_LENGTH(token) - 1);

    KURL kurl = document.completeURL(url);

    if (kurl.isEmpty() || !kurl.isValid()) {
<<<<<<< HEAD
        exceptionState.throwDOMException(
            SyntaxError,
            "The custom handler URL created by removing '%s' and prepending '" + document.baseURL().getString() + "' is invalid.");
=======
        exceptionState.throwDOMException(SyntaxError, "The custom handler URL created by removing '%s' and prepending '" + document.baseURL().string() + "' is invalid.");
>>>>>>> miniblink49
        return false;
    }

    // The specification says that the API throws SecurityError exception if the
    // URL's origin differs from the document's origin.
<<<<<<< HEAD
    if (!document.getSecurityOrigin()->canRequest(kurl)) {
        exceptionState.throwSecurityError(
            "Can only register custom handler in the document's origin.");
=======
    if (!document.securityOrigin()->canRequest(kurl)) {
        exceptionState.throwSecurityError("Can only register custom handler in the document's origin.");
>>>>>>> miniblink49
        return false;
    }

    return true;
}

static bool isSchemeWhitelisted(const String& scheme)
{
    if (!schemeWhitelist)
        initCustomSchemeHandlerWhitelist();

    StringBuilder builder;
<<<<<<< HEAD
    builder.append(scheme.lower().ascii().data());
=======
    unsigned length = scheme.length();
    for (unsigned i = 0; i < length; ++i)
        builder.append(toASCIILower(scheme[i]));
>>>>>>> miniblink49

    return schemeWhitelist->contains(builder.toString());
}

<<<<<<< HEAD
static bool verifyCustomHandlerScheme(const String& scheme,
    ExceptionState& exceptionState)
=======
static bool verifyCustomHandlerScheme(const String& scheme, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    if (!isValidProtocol(scheme)) {
        exceptionState.throwSecurityError("The scheme '" + scheme + "' is not valid protocol");
        return false;
    }

    if (scheme.startsWith("web+")) {
<<<<<<< HEAD
        // The specification requires that the length of scheme is at least five
        // characteres (including 'web+' prefix).
=======
        // The specification requires that the length of scheme is at least five characteres (including 'web+' prefix).
>>>>>>> miniblink49
        if (scheme.length() >= 5)
            return true;

        exceptionState.throwSecurityError("The scheme '" + scheme + "' is less than five characters long.");
        return false;
    }

    if (isSchemeWhitelisted(scheme))
        return true;

<<<<<<< HEAD
    exceptionState.throwSecurityError("The scheme '" + scheme + "' doesn't belong to the scheme whitelist. "
                                                                "Please prefix non-whitelisted schemes "
                                                                "with the string 'web+'.");
    return false;
}

NavigatorContentUtils* NavigatorContentUtils::from(Navigator& navigator)
{
    return static_cast<NavigatorContentUtils*>(
        Supplement<Navigator>::from(navigator, supplementName()));
}

NavigatorContentUtils::~NavigatorContentUtils() { }

void NavigatorContentUtils::registerProtocolHandler(
    Navigator& navigator,
    const String& scheme,
    const String& url,
    const String& title,
    ExceptionState& exceptionState)
=======
    exceptionState.throwSecurityError("The scheme '" + scheme + "' doesn't belong to the scheme whitelist. Please prefix non-whitelisted schemes with the string 'web+'.");
    return false;
}

NavigatorContentUtils* NavigatorContentUtils::from(LocalFrame& frame)
{
    return static_cast<NavigatorContentUtils*>(WillBeHeapSupplement<LocalFrame>::from(frame, supplementName()));
}

NavigatorContentUtils::~NavigatorContentUtils()
{
}

PassOwnPtrWillBeRawPtr<NavigatorContentUtils> NavigatorContentUtils::create(PassOwnPtr<NavigatorContentUtilsClient> client)
{
    return adoptPtrWillBeNoop(new NavigatorContentUtils(client));
}

void NavigatorContentUtils::registerProtocolHandler(Navigator& navigator, const String& scheme, const String& url, const String& title, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    if (!navigator.frame())
        return;

    Document* document = navigator.frame()->document();
    ASSERT(document);

    if (!verifyCustomHandlerURL(*document, url, exceptionState))
        return;

    if (!verifyCustomHandlerScheme(scheme, exceptionState))
        return;

<<<<<<< HEAD
    // Count usage; perhaps we can lock this to secure contexts.
    UseCounter::count(*document,
        document->isSecureContext()
            ? UseCounter::RegisterProtocolHandlerSecureOrigin
            : UseCounter::RegisterProtocolHandlerInsecureOrigin);

    NavigatorContentUtils::from(navigator)->client()->registerProtocolHandler(
        scheme, document->completeURL(url), title);
}

static String customHandlersStateString(
    const NavigatorContentUtilsClient::CustomHandlersState state)
=======
    NavigatorContentUtils::from(*navigator.frame())->client()->registerProtocolHandler(scheme, document->completeURL(url), title);
}

static String customHandlersStateString(const NavigatorContentUtilsClient::CustomHandlersState state)
>>>>>>> miniblink49
{
    DEFINE_STATIC_LOCAL(const String, newHandler, ("new"));
    DEFINE_STATIC_LOCAL(const String, registeredHandler, ("registered"));
    DEFINE_STATIC_LOCAL(const String, declinedHandler, ("declined"));

    switch (state) {
    case NavigatorContentUtilsClient::CustomHandlersNew:
        return newHandler;
    case NavigatorContentUtilsClient::CustomHandlersRegistered:
        return registeredHandler;
    case NavigatorContentUtilsClient::CustomHandlersDeclined:
        return declinedHandler;
    }

    ASSERT_NOT_REACHED();
    return String();
}

<<<<<<< HEAD
String NavigatorContentUtils::isProtocolHandlerRegistered(
    Navigator& navigator,
    const String& scheme,
    const String& url,
    ExceptionState& exceptionState)
=======
String NavigatorContentUtils::isProtocolHandlerRegistered(Navigator& navigator, const String& scheme, const String& url, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    DEFINE_STATIC_LOCAL(const String, declined, ("declined"));

    if (!navigator.frame())
        return declined;

    Document* document = navigator.frame()->document();
    ASSERT(document);
<<<<<<< HEAD
    if (document->isContextDestroyed())
=======
    if (document->activeDOMObjectsAreStopped())
>>>>>>> miniblink49
        return declined;

    if (!verifyCustomHandlerURL(*document, url, exceptionState))
        return declined;

    if (!verifyCustomHandlerScheme(scheme, exceptionState))
        return declined;

<<<<<<< HEAD
    return customHandlersStateString(
        NavigatorContentUtils::from(navigator)
            ->client()
            ->isProtocolHandlerRegistered(scheme, document->completeURL(url)));
}

void NavigatorContentUtils::unregisterProtocolHandler(
    Navigator& navigator,
    const String& scheme,
    const String& url,
    ExceptionState& exceptionState)
=======
    return customHandlersStateString(NavigatorContentUtils::from(*navigator.frame())->client()->isProtocolHandlerRegistered(scheme, document->completeURL(url)));
}

void NavigatorContentUtils::unregisterProtocolHandler(Navigator& navigator, const String& scheme, const String& url, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    if (!navigator.frame())
        return;

    Document* document = navigator.frame()->document();
    ASSERT(document);

    if (!verifyCustomHandlerURL(*document, url, exceptionState))
        return;

    if (!verifyCustomHandlerScheme(scheme, exceptionState))
        return;

<<<<<<< HEAD
    NavigatorContentUtils::from(navigator)->client()->unregisterProtocolHandler(
        scheme, document->completeURL(url));
}

DEFINE_TRACE(NavigatorContentUtils)
{
    visitor->trace(m_client);
    Supplement<Navigator>::trace(visitor);
=======
    NavigatorContentUtils::from(*navigator.frame())->client()->unregisterProtocolHandler(scheme, document->completeURL(url));
>>>>>>> miniblink49
}

const char* NavigatorContentUtils::supplementName()
{
    return "NavigatorContentUtils";
}

<<<<<<< HEAD
void NavigatorContentUtils::provideTo(Navigator& navigator,
    NavigatorContentUtilsClient* client)
{
    Supplement<Navigator>::provideTo(
        navigator, NavigatorContentUtils::supplementName(),
        new NavigatorContentUtils(navigator, client));
=======
void provideNavigatorContentUtilsTo(LocalFrame& frame, PassOwnPtr<NavigatorContentUtilsClient> client)
{
    NavigatorContentUtils::provideTo(frame, NavigatorContentUtils::supplementName(), NavigatorContentUtils::create(client));
>>>>>>> miniblink49
}

} // namespace blink

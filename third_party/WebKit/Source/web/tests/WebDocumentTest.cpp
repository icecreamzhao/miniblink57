// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/web/WebDocument.h"

#include "core/CSSPropertyNames.h"
#include "core/HTMLNames.h"
#include "core/dom/NodeComputedStyle.h"
#include "core/dom/StyleEngine.h"
#include "core/frame/LocalFrame.h"
#include "core/html/HTMLElement.h"
#include "core/html/HTMLLinkElement.h"
<<<<<<< HEAD
#include "core/page/Page.h"
#include "core/style/ComputedStyle.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/Color.h"
#include "platform/testing/URLTestHelpers.h"
#include "platform/weborigin/SchemeRegistry.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "web/tests/FrameTestHelpers.h"
=======
#include "core/style/ComputedStyle.h"
#include "core/page/Page.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/Color.h"
#include "platform/testing/URLTestHelpers.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "web/tests/FrameTestHelpers.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {

using blink::FrameTestHelpers::WebViewHelper;
using blink::URLTestHelpers::toKURL;

<<<<<<< HEAD
const char kDefaultOrigin[] = "https://example.test/";
const char kManifestDummyFilePath[] = "manifest-dummy.html";
=======
const char* kDefaultOrigin = "https://example.test/";
const char* kManifestDummyFilePath = "manifest-dummy.html";
>>>>>>> miniblink49

class WebDocumentTest : public ::testing::Test {
protected:
    static void SetUpTestCase();

    void loadURL(const std::string& url);
    Document* topDocument() const;
    WebDocument topWebDocument() const;

    WebViewHelper m_webViewHelper;
};

void WebDocumentTest::SetUpTestCase()
{
<<<<<<< HEAD
    URLTestHelpers::registerMockedURLLoad(
        toKURL(std::string(kDefaultOrigin) + kManifestDummyFilePath),
        WebString::fromUTF8(kManifestDummyFilePath));
=======
    URLTestHelpers::registerMockedURLLoad(toKURL(std::string(kDefaultOrigin) + kManifestDummyFilePath), WebString::fromUTF8(kManifestDummyFilePath));
>>>>>>> miniblink49
}

void WebDocumentTest::loadURL(const std::string& url)
{
    m_webViewHelper.initializeAndLoad(url);
}

Document* WebDocumentTest::topDocument() const
{
<<<<<<< HEAD
    return toLocalFrame(m_webViewHelper.webView()->page()->mainFrame())
        ->document();
=======
    return toLocalFrame(m_webViewHelper.webViewImpl()->page()->mainFrame())->document();
>>>>>>> miniblink49
}

WebDocument WebDocumentTest::topWebDocument() const
{
    return m_webViewHelper.webView()->mainFrame()->document();
}

TEST_F(WebDocumentTest, InsertStyleSheet)
{
    loadURL("about:blank");

    WebDocument webDoc = topWebDocument();
    Document* coreDoc = topDocument();

<<<<<<< HEAD
    unsigned startCount = coreDoc->styleEngine().styleForElementCount();

    webDoc.insertStyleSheet("body { color: green }");

    // Check insertStyleSheet did not cause a synchronous style recalc.
    unsigned elementCount = coreDoc->styleEngine().styleForElementCount() - startCount;
    ASSERT_EQ(0U, elementCount);

    HTMLElement* bodyElement = coreDoc->body();
    DCHECK(bodyElement);
=======
    webDoc.insertStyleSheet("body { color: green }");

    // Check insertStyleSheet did not cause a synchronous style recalc.
    unsigned accessCount = coreDoc->styleEngine().resolverAccessCount();
    ASSERT_EQ(0U, accessCount);

    HTMLElement* bodyElement = coreDoc->body();
    ASSERT(bodyElement);
>>>>>>> miniblink49

    const ComputedStyle& styleBeforeInsertion = bodyElement->computedStyleRef();

    // Inserted stylesheet not yet applied.
<<<<<<< HEAD
    ASSERT_EQ(Color(0, 0, 0),
        styleBeforeInsertion.visitedDependentColor(CSSPropertyColor));

    // Apply inserted stylesheet.
    coreDoc->updateStyleAndLayoutTree();
=======
    ASSERT_EQ(Color(0, 0, 0), styleBeforeInsertion.visitedDependentColor(CSSPropertyColor));

    // Apply inserted stylesheet.
    coreDoc->updateLayoutTreeIfNeeded();
>>>>>>> miniblink49

    const ComputedStyle& styleAfterInsertion = bodyElement->computedStyleRef();

    // Inserted stylesheet applied.
<<<<<<< HEAD
    ASSERT_EQ(Color(0, 128, 0),
        styleAfterInsertion.visitedDependentColor(CSSPropertyColor));
=======
    ASSERT_EQ(Color(0, 128, 0), styleAfterInsertion.visitedDependentColor(CSSPropertyColor));
>>>>>>> miniblink49
}

TEST_F(WebDocumentTest, ManifestURL)
{
    loadURL(std::string(kDefaultOrigin) + kManifestDummyFilePath);

    WebDocument webDoc = topWebDocument();
    Document* document = topDocument();
    HTMLLinkElement* linkManifest = document->linkManifest();

    // No href attribute was set.
    ASSERT_EQ(linkManifest->href(), static_cast<KURL>(webDoc.manifestURL()));

    // Set to some absolute url.
<<<<<<< HEAD
    linkManifest->setAttribute(HTMLNames::hrefAttr,
        "http://example.com/manifest.json");
=======
    linkManifest->setAttribute(HTMLNames::hrefAttr, "http://example.com/manifest.json");
>>>>>>> miniblink49
    ASSERT_EQ(linkManifest->href(), static_cast<KURL>(webDoc.manifestURL()));

    // Set to some relative url.
    linkManifest->setAttribute(HTMLNames::hrefAttr, "static/manifest.json");
    ASSERT_EQ(linkManifest->href(), static_cast<KURL>(webDoc.manifestURL()));
}

TEST_F(WebDocumentTest, ManifestUseCredentials)
{
    loadURL(std::string(kDefaultOrigin) + kManifestDummyFilePath);

    WebDocument webDoc = topWebDocument();
    Document* document = topDocument();
    HTMLLinkElement* linkManifest = document->linkManifest();

    // No crossorigin attribute was set so credentials shouldn't be used.
    ASSERT_FALSE(linkManifest->fastHasAttribute(HTMLNames::crossoriginAttr));
    ASSERT_FALSE(webDoc.manifestUseCredentials());

    // Crossorigin set to a random string shouldn't trigger using credentials.
    linkManifest->setAttribute(HTMLNames::crossoriginAttr, "foobar");
    ASSERT_FALSE(webDoc.manifestUseCredentials());

    // Crossorigin set to 'anonymous' shouldn't trigger using credentials.
    linkManifest->setAttribute(HTMLNames::crossoriginAttr, "anonymous");
    ASSERT_FALSE(webDoc.manifestUseCredentials());

    // Crossorigin set to 'use-credentials' should trigger using credentials.
    linkManifest->setAttribute(HTMLNames::crossoriginAttr, "use-credentials");
    ASSERT_TRUE(webDoc.manifestUseCredentials());
}

namespace {

<<<<<<< HEAD
    const char* baseURLOriginA = "http://example.test:0/";
    const char* baseURLOriginSubA = "http://subdomain.example.test:0/";
    const char* baseURLOriginSecureA = "https://example.test:0/";
    const char* baseURLOriginB = "http://not-example.test:0/";
    const char* emptyFile = "first_party/empty.html";
    const char* nestedData = "first_party/nested-data.html";
    const char* nestedOriginA = "first_party/nested-originA.html";
    const char* nestedOriginSubA = "first_party/nested-originSubA.html";
    const char* nestedOriginSecureA = "first_party/nested-originSecureA.html";
    const char* nestedOriginAInOriginA = "first_party/nested-originA-in-originA.html";
    const char* nestedOriginAInOriginB = "first_party/nested-originA-in-originB.html";
    const char* nestedOriginB = "first_party/nested-originB.html";
    const char* nestedOriginBInOriginA = "first_party/nested-originB-in-originA.html";
    const char* nestedOriginBInOriginB = "first_party/nested-originB-in-originB.html";
    const char* nestedSrcDoc = "first_party/nested-srcdoc.html";

    KURL toOriginA(const char* file)
    {
        return toKURL(std::string(baseURLOriginA) + file);
    }

    KURL toOriginSubA(const char* file)
    {
        return toKURL(std::string(baseURLOriginSubA) + file);
    }

    KURL toOriginSecureA(const char* file)
    {
        return toKURL(std::string(baseURLOriginSecureA) + file);
    }

    KURL toOriginB(const char* file)
    {
        return toKURL(std::string(baseURLOriginB) + file);
    }
=======
const char* baseURLOriginA = "http://example.test:0/";
const char* baseURLOriginSubA = "http://subdomain.example.test:0/";
const char* baseURLOriginB = "http://not-example.test:0/";
const char* emptyFile = "first_party/empty.html";
const char* nestedData = "first_party/nested-data.html";
const char* nestedOriginA = "first_party/nested-originA.html";
const char* nestedOriginSubA = "first_party/nested-originSubA.html";
const char* nestedOriginAInOriginA = "first_party/nested-originA-in-originA.html";
const char* nestedOriginAInOriginB = "first_party/nested-originA-in-originB.html";
const char* nestedOriginB = "first_party/nested-originB.html";
const char* nestedOriginBInOriginA = "first_party/nested-originB-in-originA.html";
const char* nestedOriginBInOriginB = "first_party/nested-originB-in-originB.html";
const char* nestedSrcDoc = "first_party/nested-srcdoc.html";

KURL toOriginA(const char* file)
{
    return toKURL(std::string(baseURLOriginA) + file);
}

KURL toOriginSubA(const char* file)
{
    return toKURL(std::string(baseURLOriginSubA) + file);
}

KURL toOriginB(const char* file)
{
    return toKURL(std::string(baseURLOriginB) + file);
}
>>>>>>> miniblink49

} // anonymous namespace

class WebDocumentFirstPartyTest : public WebDocumentTest {
public:
    static void SetUpTestCase();

protected:
    void load(const char*);
    Document* nestedDocument() const;
    Document* nestedNestedDocument() const;
};

void WebDocumentFirstPartyTest::SetUpTestCase()
{
<<<<<<< HEAD
    URLTestHelpers::registerMockedURLLoad(toOriginA(emptyFile),
        WebString::fromUTF8(emptyFile));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedData),
        WebString::fromUTF8(nestedData));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginA),
        WebString::fromUTF8(nestedOriginA));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginSubA),
        WebString::fromUTF8(nestedOriginSubA));
    URLTestHelpers::registerMockedURLLoad(
        toOriginA(nestedOriginSecureA), WebString::fromUTF8(nestedOriginSecureA));
    URLTestHelpers::registerMockedURLLoad(
        toOriginA(nestedOriginAInOriginA),
        WebString::fromUTF8(nestedOriginAInOriginA));
    URLTestHelpers::registerMockedURLLoad(
        toOriginA(nestedOriginAInOriginB),
        WebString::fromUTF8(nestedOriginAInOriginB));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginB),
        WebString::fromUTF8(nestedOriginB));
    URLTestHelpers::registerMockedURLLoad(
        toOriginA(nestedOriginBInOriginA),
        WebString::fromUTF8(nestedOriginBInOriginA));
    URLTestHelpers::registerMockedURLLoad(
        toOriginA(nestedOriginBInOriginB),
        WebString::fromUTF8(nestedOriginBInOriginB));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedSrcDoc),
        WebString::fromUTF8(nestedSrcDoc));

    URLTestHelpers::registerMockedURLLoad(toOriginSubA(emptyFile),
        WebString::fromUTF8(emptyFile));
    URLTestHelpers::registerMockedURLLoad(toOriginSecureA(emptyFile),
        WebString::fromUTF8(emptyFile));

    URLTestHelpers::registerMockedURLLoad(toOriginB(emptyFile),
        WebString::fromUTF8(emptyFile));
    URLTestHelpers::registerMockedURLLoad(toOriginB(nestedOriginA),
        WebString::fromUTF8(nestedOriginA));
    URLTestHelpers::registerMockedURLLoad(toOriginB(nestedOriginB),
        WebString::fromUTF8(nestedOriginB));
=======
    URLTestHelpers::registerMockedURLLoad(toOriginA(emptyFile), WebString::fromUTF8(emptyFile));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedData), WebString::fromUTF8(nestedData));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginA), WebString::fromUTF8(nestedOriginA));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginSubA), WebString::fromUTF8(nestedOriginSubA));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginAInOriginA), WebString::fromUTF8(nestedOriginAInOriginA));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginAInOriginB), WebString::fromUTF8(nestedOriginAInOriginB));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginB), WebString::fromUTF8(nestedOriginB));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginBInOriginA), WebString::fromUTF8(nestedOriginBInOriginA));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedOriginBInOriginB), WebString::fromUTF8(nestedOriginBInOriginB));
    URLTestHelpers::registerMockedURLLoad(toOriginA(nestedSrcDoc), WebString::fromUTF8(nestedSrcDoc));

    URLTestHelpers::registerMockedURLLoad(toOriginSubA(emptyFile), WebString::fromUTF8(emptyFile));

    URLTestHelpers::registerMockedURLLoad(toOriginB(emptyFile), WebString::fromUTF8(emptyFile));
    URLTestHelpers::registerMockedURLLoad(toOriginB(nestedOriginA), WebString::fromUTF8(nestedOriginA));
    URLTestHelpers::registerMockedURLLoad(toOriginB(nestedOriginB), WebString::fromUTF8(nestedOriginB));
>>>>>>> miniblink49
}

void WebDocumentFirstPartyTest::load(const char* file)
{
    m_webViewHelper.initializeAndLoad(std::string(baseURLOriginA) + file);
}

Document* WebDocumentFirstPartyTest::nestedDocument() const
{
<<<<<<< HEAD
    return toLocalFrame(m_webViewHelper.webView()
                            ->page()
                            ->mainFrame()
                            ->tree()
                            .firstChild())
        ->document();
=======
    return toLocalFrame(m_webViewHelper.webViewImpl()->page()->mainFrame()->tree().firstChild())->document();
>>>>>>> miniblink49
}

Document* WebDocumentFirstPartyTest::nestedNestedDocument() const
{
<<<<<<< HEAD
    return toLocalFrame(m_webViewHelper.webView()
                            ->page()
                            ->mainFrame()
                            ->tree()
                            .firstChild()
                            ->tree()
                            .firstChild())
        ->document();
=======
    return toLocalFrame(m_webViewHelper.webViewImpl()->page()->mainFrame()->tree().firstChild()->tree().firstChild())->document();
>>>>>>> miniblink49
}

TEST_F(WebDocumentFirstPartyTest, Empty)
{
    load(emptyFile);

    ASSERT_EQ(toOriginA(emptyFile), topDocument()->firstPartyForCookies());
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginA)
{
    load(nestedOriginA);

    ASSERT_EQ(toOriginA(nestedOriginA), topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginA), nestedDocument()->firstPartyForCookies());
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginSubA)
{
    load(nestedOriginSubA);

    ASSERT_EQ(toOriginA(nestedOriginSubA), topDocument()->firstPartyForCookies());
<<<<<<< HEAD
    ASSERT_EQ(toOriginA(nestedOriginSubA),
        nestedDocument()->firstPartyForCookies());
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginSecureA)
{
    load(nestedOriginSecureA);

    ASSERT_EQ(toOriginA(nestedOriginSecureA),
        topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginSecureA),
        nestedDocument()->firstPartyForCookies());
=======
    ASSERT_EQ(toOriginA(nestedOriginSubA), nestedDocument()->firstPartyForCookies());
>>>>>>> miniblink49
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginAInOriginA)
{
    load(nestedOriginAInOriginA);

<<<<<<< HEAD
    ASSERT_EQ(toOriginA(nestedOriginAInOriginA),
        topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginAInOriginA),
        nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginAInOriginA),
        nestedNestedDocument()->firstPartyForCookies());
=======
    ASSERT_EQ(toOriginA(nestedOriginAInOriginA), topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginAInOriginA), nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginAInOriginA), nestedNestedDocument()->firstPartyForCookies());
>>>>>>> miniblink49
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginAInOriginB)
{
    load(nestedOriginAInOriginB);

<<<<<<< HEAD
    ASSERT_EQ(toOriginA(nestedOriginAInOriginB),
        topDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(),
        nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(),
        nestedNestedDocument()->firstPartyForCookies());
=======
    ASSERT_EQ(toOriginA(nestedOriginAInOriginB), topDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(), nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(), nestedNestedDocument()->firstPartyForCookies());
>>>>>>> miniblink49
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginB)
{
    load(nestedOriginB);

    ASSERT_EQ(toOriginA(nestedOriginB), topDocument()->firstPartyForCookies());
<<<<<<< HEAD
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(),
        nestedDocument()->firstPartyForCookies());
=======
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(), nestedDocument()->firstPartyForCookies());
>>>>>>> miniblink49
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginBInOriginA)
{
    load(nestedOriginBInOriginA);

<<<<<<< HEAD
    ASSERT_EQ(toOriginA(nestedOriginBInOriginA),
        topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginBInOriginA),
        nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(),
        nestedNestedDocument()->firstPartyForCookies());
=======
    ASSERT_EQ(toOriginA(nestedOriginBInOriginA), topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginBInOriginA), nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(), nestedNestedDocument()->firstPartyForCookies());
>>>>>>> miniblink49
}

TEST_F(WebDocumentFirstPartyTest, NestedOriginBInOriginB)
{
    load(nestedOriginBInOriginB);

<<<<<<< HEAD
    ASSERT_EQ(toOriginA(nestedOriginBInOriginB),
        topDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(),
        nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(),
        nestedNestedDocument()->firstPartyForCookies());
=======
    ASSERT_EQ(toOriginA(nestedOriginBInOriginB), topDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(), nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(), nestedNestedDocument()->firstPartyForCookies());
>>>>>>> miniblink49
}

TEST_F(WebDocumentFirstPartyTest, NestedSrcdoc)
{
    load(nestedSrcDoc);

    ASSERT_EQ(toOriginA(nestedSrcDoc), topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedSrcDoc), nestedDocument()->firstPartyForCookies());
}

TEST_F(WebDocumentFirstPartyTest, NestedData)
{
    load(nestedData);

    ASSERT_EQ(toOriginA(nestedData), topDocument()->firstPartyForCookies());
<<<<<<< HEAD
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(),
        nestedDocument()->firstPartyForCookies());
}

TEST_F(WebDocumentFirstPartyTest,
    NestedOriginAInOriginBWithFirstPartyOverride)
{
    load(nestedOriginAInOriginB);

    SchemeRegistry::registerURLSchemeAsFirstPartyWhenTopLevel("http");

    ASSERT_EQ(toOriginA(nestedOriginAInOriginB),
        topDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginAInOriginB),
        nestedDocument()->firstPartyForCookies());
    ASSERT_EQ(toOriginA(nestedOriginAInOriginB),
        nestedNestedDocument()->firstPartyForCookies());
=======
    ASSERT_EQ(SecurityOrigin::urlWithUniqueSecurityOrigin(), nestedDocument()->firstPartyForCookies());
>>>>>>> miniblink49
}

} // namespace blink

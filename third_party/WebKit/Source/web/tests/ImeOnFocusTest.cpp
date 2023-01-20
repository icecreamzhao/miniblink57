// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "core/dom/Document.h"
#include "core/dom/Element.h"
#include "core/dom/Node.h"
#include "core/html/HTMLElement.h"
#include "platform/testing/URLTestHelpers.h"
#include "platform/testing/UnitTestHelpers.h"
#include "public/platform/Platform.h"
<<<<<<< HEAD
#include "public/platform/WebURLLoaderMockFactory.h"
#include "public/web/WebCache.h"
#include "public/web/WebDocument.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "web/WebLocalFrameImpl.h"
#include "web/tests/FrameTestHelpers.h"
=======
#include "public/platform/WebUnitTestSupport.h"
#include "public/web/WebDocument.h"
#include "web/WebLocalFrameImpl.h"
#include "web/tests/FrameTestHelpers.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

using blink::FrameTestHelpers::loadFrame;
using blink::testing::runPendingTasks;
using blink::URLTestHelpers::registerMockedURLFromBaseURL;

namespace blink {

<<<<<<< HEAD
class ImeRequestTrackingWebViewClient
    : public FrameTestHelpers::TestWebViewClient {
public:
    ImeRequestTrackingWebViewClient()
        : m_virtualKeyboardRequestCount(0)
=======
class ImeRequestTrackingWebViewClient : public FrameTestHelpers::TestWebViewClient {
public:
    ImeRequestTrackingWebViewClient() :
        m_imeRequestCount(0)
>>>>>>> miniblink49
    {
    }

    // WebWidgetClient methods
<<<<<<< HEAD
    void showVirtualKeyboard() override { ++m_virtualKeyboardRequestCount; }

    // Local methds
    void reset() { m_virtualKeyboardRequestCount = 0; }

    int virtualKeyboardRequestCount() { return m_virtualKeyboardRequestCount; }

private:
    int m_virtualKeyboardRequestCount;
=======
    void showImeIfNeeded() override
    {
        ++m_imeRequestCount;
    }

    // Local methds
    void reset()
    {
        m_imeRequestCount = 0;
    }

    int imeRequestCount()
    {
        return m_imeRequestCount;
    }

private:
    int m_imeRequestCount;
>>>>>>> miniblink49
};

class ImeOnFocusTest : public ::testing::Test {
public:
    ImeOnFocusTest()
        : m_baseURL("http://www.test.com/")
    {
    }

    void TearDown() override
    {
<<<<<<< HEAD
        Platform::current()->getURLLoaderMockFactory()->unregisterAllURLs();
        WebCache::clear();
=======
        Platform::current()->unitTestSupport()->unregisterAllMockedURLs();
>>>>>>> miniblink49
    }

protected:
    void sendGestureTap(WebView*, IntPoint);
    void focus(const AtomicString& element);
<<<<<<< HEAD
    void runImeOnFocusTest(std::string fileName,
        int,
        IntPoint tapPoint = IntPoint(-1, -1),
        const AtomicString& focusElement = nullAtom,
        std::string frame = "");

    std::string m_baseURL;
    FrameTestHelpers::WebViewHelper m_webViewHelper;
    Persistent<Document> m_document;
=======
    void runImeOnFocusTest(std::string fileName, int, IntPoint tapPoint = IntPoint(-1, -1), const AtomicString& focusElement = nullAtom, std::string frame = "");

    std::string m_baseURL;
    FrameTestHelpers::WebViewHelper m_webViewHelper;
    RefPtrWillBePersistent<Document> m_document;
>>>>>>> miniblink49
};

void ImeOnFocusTest::sendGestureTap(WebView* webView, IntPoint clientPoint)
{
<<<<<<< HEAD
    WebGestureEvent webGestureEvent(WebInputEvent::GestureTap,
        WebInputEvent::NoModifiers,
        WebInputEvent::TimeStampForTesting);
    // GestureTap is only ever from touch screens.
    webGestureEvent.sourceDevice = WebGestureDeviceTouchscreen;
=======
    WebGestureEvent webGestureEvent;
    webGestureEvent.type = WebInputEvent::GestureTap;
>>>>>>> miniblink49
    webGestureEvent.x = clientPoint.x();
    webGestureEvent.y = clientPoint.y();
    webGestureEvent.globalX = clientPoint.x();
    webGestureEvent.globalY = clientPoint.y();
    webGestureEvent.data.tap.tapCount = 1;
    webGestureEvent.data.tap.width = 10;
    webGestureEvent.data.tap.height = 10;

    webView->handleInputEvent(webGestureEvent);
    runPendingTasks();
}

void ImeOnFocusTest::focus(const AtomicString& element)
{
    m_document->body()->getElementById(element)->focus();
}

<<<<<<< HEAD
void ImeOnFocusTest::runImeOnFocusTest(std::string fileName,
    int expectedVirtualKeyboardRequestCount,
    IntPoint tapPoint,
    const AtomicString& focusElement,
    std::string frame)
{
    ImeRequestTrackingWebViewClient client;
    registerMockedURLFromBaseURL(WebString::fromUTF8(m_baseURL),
        WebString::fromUTF8(fileName));
    WebViewImpl* webView = m_webViewHelper.initialize(true, 0, &client);
    webView->resize(WebSize(800, 1200));
    loadFrame(webView->mainFrame(), m_baseURL + fileName);
    m_document = m_webViewHelper.webView()->mainFrameImpl()->document().unwrap<Document>();

    if (!focusElement.isNull())
        focus(focusElement);
    EXPECT_EQ(0, client.virtualKeyboardRequestCount());
=======
void ImeOnFocusTest::runImeOnFocusTest(std::string fileName, int expectedImeRequestCount, IntPoint tapPoint, const AtomicString& focusElement, std::string frame)
{
    ImeRequestTrackingWebViewClient client;
    registerMockedURLFromBaseURL(WebString::fromUTF8(m_baseURL), WebString::fromUTF8(fileName));
    WebViewImpl* webView = m_webViewHelper.initialize(true, 0, &client);
    webView->resize(WebSize(800, 1200));
    loadFrame(webView->mainFrame(), m_baseURL + fileName);
    m_document = m_webViewHelper.webViewImpl()->mainFrameImpl()->document().unwrap<Document>();

    if (!focusElement.isNull())
        focus(focusElement);
    EXPECT_EQ(0, client.imeRequestCount());
>>>>>>> miniblink49

    if (tapPoint.x() >= 0 && tapPoint.y() >= 0)
        sendGestureTap(webView, tapPoint);

    if (!frame.empty()) {
<<<<<<< HEAD
        registerMockedURLFromBaseURL(WebString::fromUTF8(m_baseURL),
            WebString::fromUTF8(frame));
=======
        registerMockedURLFromBaseURL(WebString::fromUTF8(m_baseURL), WebString::fromUTF8(frame));
>>>>>>> miniblink49
        WebFrame* childFrame = webView->mainFrame()->firstChild();
        loadFrame(childFrame, m_baseURL + frame);
    }

    if (!focusElement.isNull())
        focus(focusElement);
<<<<<<< HEAD
    EXPECT_EQ(expectedVirtualKeyboardRequestCount,
        client.virtualKeyboardRequestCount());
=======
    EXPECT_EQ(expectedImeRequestCount, client.imeRequestCount());
>>>>>>> miniblink49

    m_webViewHelper.reset();
}

TEST_F(ImeOnFocusTest, OnLoad)
{
    runImeOnFocusTest("ime-on-focus-on-load.html", 0);
}

TEST_F(ImeOnFocusTest, OnAutofocus)
{
    runImeOnFocusTest("ime-on-focus-on-autofocus.html", 0);
}

TEST_F(ImeOnFocusTest, OnUserGesture)
{
    runImeOnFocusTest("ime-on-focus-on-user-gesture.html", 1, IntPoint(50, 50));
}

TEST_F(ImeOnFocusTest, AfterFirstGesture)
{
<<<<<<< HEAD
    runImeOnFocusTest("ime-on-focus-after-first-gesture.html", 1,
        IntPoint(50, 50), "input");
=======
    runImeOnFocusTest("ime-on-focus-after-first-gesture.html", 1, IntPoint(50, 50), "input");
>>>>>>> miniblink49
}

TEST_F(ImeOnFocusTest, AfterNavigationWithinPage)
{
<<<<<<< HEAD
    runImeOnFocusTest("ime-on-focus-after-navigation-within-page.html", 1,
        IntPoint(50, 50), "input");
=======
    runImeOnFocusTest("ime-on-focus-after-navigation-within-page.html", 1, IntPoint(50, 50), "input");
>>>>>>> miniblink49
}

TEST_F(ImeOnFocusTest, AfterFrameLoadOnGesture)
{
<<<<<<< HEAD
    runImeOnFocusTest("ime-on-focus-after-frame-load-on-gesture.html", 1,
        IntPoint(50, 50), "input", "frame.html");
=======
    runImeOnFocusTest("ime-on-focus-after-frame-load-on-gesture.html", 1, IntPoint(50, 50), "input", "frame.html");
>>>>>>> miniblink49
}

} // namespace blink

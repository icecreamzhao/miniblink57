// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "web/ExternalPopupMenu.h"

#include "core/HTMLNames.h"
#include "core/dom/NodeComputedStyle.h"
#include "core/frame/FrameHost.h"
#include "core/frame/VisualViewport.h"
#include "core/html/HTMLSelectElement.h"
=======
#include "config.h"
#include "web/ExternalPopupMenu.h"

#include "core/HTMLNames.h"
#include "core/frame/FrameHost.h"
#include "core/frame/PinchViewport.h"
#include "core/html/HTMLSelectElement.h"
#include "core/html/forms/PopupMenuClient.h"
>>>>>>> miniblink49
#include "core/layout/LayoutMenuList.h"
#include "core/page/Page.h"
#include "core/testing/DummyPageHolder.h"
#include "platform/PopupMenu.h"
#include "platform/testing/URLTestHelpers.h"
#include "public/platform/Platform.h"
<<<<<<< HEAD
#include "public/platform/WebURLLoaderMockFactory.h"
#include "public/web/WebCache.h"
#include "public/web/WebExternalPopupMenu.h"
#include "public/web/WebPopupMenuInfo.h"
#include "public/web/WebSettings.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "web/WebLocalFrameImpl.h"
#include "web/tests/FrameTestHelpers.h"
#include <memory>

namespace blink {

=======
#include "public/platform/WebUnitTestSupport.h"
#include "public/web/WebExternalPopupMenu.h"
#include "public/web/WebPopupMenuInfo.h"
#include "public/web/WebSettings.h"
#include "web/WebLocalFrameImpl.h"
#include "web/tests/FrameTestHelpers.h"
#include <gtest/gtest.h>

namespace blink {

const size_t kListSize = 7;

class TestPopupMenuClient : public PopupMenuClient {
public:
    TestPopupMenuClient() : m_listSize(0) { }
    ~TestPopupMenuClient() override { }

    void valueChanged(unsigned listIndex, bool fireEvents = true) override { }
    void selectionChanged(unsigned listIndex, bool fireEvents = true) override { }
    void selectionCleared() override { }

    String itemText(unsigned listIndex) const override { return emptyString(); }
    String itemToolTip(unsigned listIndex) const override { return emptyString(); }
    String itemAccessibilityText(unsigned listIndex) const override { return emptyString(); }
    bool itemIsEnabled(unsigned listIndex) const override { return true; }
    PopupMenuStyle itemStyle(unsigned listIndex) const override
    {
        FontDescription fontDescription;
        fontDescription.setComputedSize(12.0);
        Font font(fontDescription);
        font.update(nullptr);
        bool displayNone = m_displayNoneIndexSet.find(listIndex) != m_displayNoneIndexSet.end();
        return PopupMenuStyle(Color::black, Color::white, font, true, displayNone, Length(), TextDirection(), false);
    }
    PopupMenuStyle menuStyle() const override { return itemStyle(0); }
    LayoutUnit clientPaddingLeft() const override { return 0; }
    LayoutUnit clientPaddingRight() const override { return 0; }
    int listSize() const override { return m_listSize; }
    int selectedIndex() const override { return 0; }
    void popupDidHide() override { }
    void popupDidCancel() override { }
    bool itemIsSeparator(unsigned listIndex) const override { return false;}
    bool itemIsLabel(unsigned listIndex) const override { return false; }
    bool itemIsSelected(unsigned listIndex) const override { return listIndex == 0;}
    void provisionalSelectionChanged(unsigned listIndex) override { }
    bool multiple() const override { return false; }
    IntRect elementRectRelativeToViewport() const override { return IntRect(); }
    Element& ownerElement() const override { return *m_ownerElement; }
    const ComputedStyle* computedStyleForItem(Element& element) const override { return nullptr; }

    void setListSize(size_t size) { m_listSize = size; }
    void setDisplayNoneIndex(unsigned index) { m_displayNoneIndexSet.insert(index); }
    void setOwnerElement(PassRefPtrWillBeRawPtr<Element> element) { m_ownerElement = element; }

private:
    size_t m_listSize;
    std::set<unsigned> m_displayNoneIndexSet;
    RefPtrWillBePersistent<Element> m_ownerElement;
};

>>>>>>> miniblink49
class ExternalPopupMenuDisplayNoneItemsTest : public testing::Test {
public:
    ExternalPopupMenuDisplayNoneItemsTest() { }

protected:
    void SetUp() override
    {
<<<<<<< HEAD
        m_dummyPageHolder = DummyPageHolder::create(IntSize(800, 600));
        HTMLSelectElement* element = HTMLSelectElement::create(m_dummyPageHolder->document());
        // Set the 4th an 5th items to have "display: none" property
        element->setInnerHTML(
            "<option><option><option><option style='display:none;'><option "
            "style='display:none;'><option><option>");
        m_dummyPageHolder->document().body()->appendChild(element,
            ASSERT_NO_EXCEPTION);
        m_ownerElement = element;
        m_dummyPageHolder->document()
            .updateStyleAndLayoutIgnorePendingStylesheets();
    }

    std::unique_ptr<DummyPageHolder> m_dummyPageHolder;
    Persistent<HTMLSelectElement> m_ownerElement;
=======
        m_popupMenuClient.setListSize(kListSize);

        // Set the 4th an 5th items to have "display: none" property
        m_popupMenuClient.setDisplayNoneIndex(3);
        m_popupMenuClient.setDisplayNoneIndex(4);

        OwnPtr<DummyPageHolder> dummyPageHolder = DummyPageHolder::create(IntSize(800, 600));
        m_popupMenuClient.setOwnerElement(HTMLSelectElement::create(dummyPageHolder->document()));
    }

    TestPopupMenuClient m_popupMenuClient;
>>>>>>> miniblink49
};

TEST_F(ExternalPopupMenuDisplayNoneItemsTest, PopupMenuInfoSizeTest)
{
    WebPopupMenuInfo info;
<<<<<<< HEAD
    ExternalPopupMenu::getPopupMenuInfo(info, *m_ownerElement);
=======
    ExternalPopupMenu::getPopupMenuInfo(info, m_popupMenuClient);
>>>>>>> miniblink49
    EXPECT_EQ(5U, info.items.size());
}

TEST_F(ExternalPopupMenuDisplayNoneItemsTest, IndexMappingTest)
{
    // 6th indexed item in popupmenu would be the 4th item in ExternalPopupMenu,
    // and vice-versa.
<<<<<<< HEAD
    EXPECT_EQ(
        4, ExternalPopupMenu::toExternalPopupMenuItemIndex(6, *m_ownerElement));
    EXPECT_EQ(6, ExternalPopupMenu::toPopupMenuItemIndex(4, *m_ownerElement));

    // Invalid index, methods should return -1.
    EXPECT_EQ(
        -1, ExternalPopupMenu::toExternalPopupMenuItemIndex(8, *m_ownerElement));
    EXPECT_EQ(-1, ExternalPopupMenu::toPopupMenuItemIndex(8, *m_ownerElement));
}

class ExternalPopupMenuWebFrameClient
    : public FrameTestHelpers::TestWebFrameClient {
public:
    WebExternalPopupMenu* createExternalPopupMenu(
        const WebPopupMenuInfo&,
        WebExternalPopupMenuClient*) override
=======
    EXPECT_EQ(4, ExternalPopupMenu::toExternalPopupMenuItemIndex(6, m_popupMenuClient));
    EXPECT_EQ(6, ExternalPopupMenu::toPopupMenuItemIndex(4, m_popupMenuClient));

    // Invalid index, methods should return -1.
    EXPECT_EQ(-1, ExternalPopupMenu::toExternalPopupMenuItemIndex(8, m_popupMenuClient));
    EXPECT_EQ(-1, ExternalPopupMenu::toPopupMenuItemIndex(8, m_popupMenuClient));
}

class ExternalPopupMenuWebFrameClient : public FrameTestHelpers::TestWebFrameClient {
public:
    WebExternalPopupMenu* createExternalPopupMenu(const WebPopupMenuInfo&, WebExternalPopupMenuClient*) override
>>>>>>> miniblink49
    {
        return &m_mockWebExternalPopupMenu;
    }
    WebRect shownBounds() const
    {
        return m_mockWebExternalPopupMenu.shownBounds();
    }
<<<<<<< HEAD

private:
    class MockWebExternalPopupMenu : public WebExternalPopupMenu {
        void show(const WebRect& bounds) override { m_shownBounds = bounds; }
        void close() override { }

    public:
        WebRect shownBounds() const { return m_shownBounds; }
=======
private:
    class MockWebExternalPopupMenu : public WebExternalPopupMenu {
        void show(const WebRect& bounds) override
        {
            m_shownBounds = bounds;
        }
        void close() override { }

    public:
        WebRect shownBounds() const
        {
            return m_shownBounds;
        }
>>>>>>> miniblink49

    private:
        WebRect m_shownBounds;
    };
    WebRect m_shownBounds;
    MockWebExternalPopupMenu m_mockWebExternalPopupMenu;
};

class ExternalPopupMenuTest : public testing::Test {
public:
<<<<<<< HEAD
    ExternalPopupMenuTest()
        : m_baseURL("http://www.test.com")
    {
    }
=======
    ExternalPopupMenuTest() : m_baseURL("http://www.test.com") { }
>>>>>>> miniblink49

protected:
    void SetUp() override
    {
        m_helper.initialize(false, &m_webFrameClient, &m_webViewClient);
        webView()->setUseExternalPopupMenus(true);
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

    void registerMockedURLLoad(const std::string& fileName)
    {
<<<<<<< HEAD
        URLTestHelpers::registerMockedURLLoad(
            URLTestHelpers::toKURL(m_baseURL + fileName),
            WebString::fromUTF8(fileName.c_str()), WebString::fromUTF8("popup/"),
            WebString::fromUTF8("text/html"));
=======
        URLTestHelpers::registerMockedURLLoad(URLTestHelpers::toKURL(m_baseURL + fileName), WebString::fromUTF8(fileName.c_str()), WebString::fromUTF8("popup/"), WebString::fromUTF8("text/html"));
>>>>>>> miniblink49
    }

    void loadFrame(const std::string& fileName)
    {
        FrameTestHelpers::loadFrame(mainFrame(), m_baseURL + fileName);
<<<<<<< HEAD
        webView()->resize(WebSize(800, 600));
        webView()->updateAllLifecyclePhases();
    }

    WebViewImpl* webView() const { return m_helper.webView(); }
    const ExternalPopupMenuWebFrameClient& client() const
    {
        return m_webFrameClient;
    }
    WebLocalFrameImpl* mainFrame() const
    {
        return m_helper.webView()->mainFrameImpl();
    }
=======
    }

    WebViewImpl* webView() const { return m_helper.webViewImpl(); }
    const ExternalPopupMenuWebFrameClient& client() const { return m_webFrameClient; }
    WebLocalFrameImpl* mainFrame() const { return m_helper.webViewImpl()->mainFrameImpl(); }
>>>>>>> miniblink49

private:
    std::string m_baseURL;
    FrameTestHelpers::TestWebViewClient m_webViewClient;
    ExternalPopupMenuWebFrameClient m_webFrameClient;
    FrameTestHelpers::WebViewHelper m_helper;
};

<<<<<<< HEAD
TEST_F(ExternalPopupMenuTest, PopupAccountsForVisualViewportTransform)
=======
TEST_F(ExternalPopupMenuTest, PopupAccountsForPinchViewportOffset)
>>>>>>> miniblink49
{
    registerMockedURLLoad("select_mid_screen.html");
    loadFrame("select_mid_screen.html");

    webView()->resize(WebSize(100, 100));
<<<<<<< HEAD
    webView()->updateAllLifecyclePhases();

    HTMLSelectElement* select = toHTMLSelectElement(
        mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    VisualViewport& visualViewport = webView()->page()->frameHost().visualViewport();

    IntRect rectInDocument = menuList->absoluteBoundingBoxRect();

    constexpr int scaleFactor = 2;
    ScrollOffset scrollDelta(20, 30);

    const int expectedX = (rectInDocument.x() - scrollDelta.width()) * scaleFactor;
    const int expectedY = (rectInDocument.y() - scrollDelta.height()) * scaleFactor;

    webView()->setPageScaleFactor(scaleFactor);
    visualViewport.move(scrollDelta);
    select->showPopup();

    EXPECT_EQ(expectedX, client().shownBounds().x);
    EXPECT_EQ(expectedY, client().shownBounds().y);
=======
    webView()->layout();

    HTMLSelectElement* select = toHTMLSelectElement(mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    PinchViewport& pinchViewport = webView()->page()->frameHost().pinchViewport();

    IntRect rectInDocument = menuList->absoluteBoundingBoxRect();

    webView()->setPageScaleFactor(2);
    IntPoint scrollDelta(20, 30);
    pinchViewport.move(scrollDelta);

    menuList->showPopup();

    EXPECT_EQ(rectInDocument.x() - scrollDelta.x(), client().shownBounds().x);
    EXPECT_EQ(rectInDocument.y() - scrollDelta.y(), client().shownBounds().y);
>>>>>>> miniblink49
}

TEST_F(ExternalPopupMenuTest, DidAcceptIndex)
{
    registerMockedURLLoad("select.html");
    loadFrame("select.html");

<<<<<<< HEAD
    HTMLSelectElement* select = toHTMLSelectElement(
        mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    select->showPopup();
    ASSERT_TRUE(select->popupIsVisible());

    WebExternalPopupMenuClient* client = static_cast<ExternalPopupMenu*>(select->popup());
    client->didAcceptIndex(2);
    EXPECT_FALSE(select->popupIsVisible());
=======
    HTMLSelectElement* select = toHTMLSelectElement(mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    menuList->showPopup();
    ASSERT_TRUE(menuList->popupIsVisible());

    WebExternalPopupMenuClient* client = static_cast<ExternalPopupMenu*>(menuList->popup());
    client->didAcceptIndex(2);
    EXPECT_FALSE(menuList->popupIsVisible());
>>>>>>> miniblink49
    ASSERT_STREQ("2", menuList->text().utf8().data());
    EXPECT_EQ(2, select->selectedIndex());
}

TEST_F(ExternalPopupMenuTest, DidAcceptIndices)
{
    registerMockedURLLoad("select.html");
    loadFrame("select.html");

<<<<<<< HEAD
    HTMLSelectElement* select = toHTMLSelectElement(
        mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    select->showPopup();
    ASSERT_TRUE(select->popupIsVisible());

    WebExternalPopupMenuClient* client = static_cast<ExternalPopupMenu*>(select->popup());
    int indices[] = { 2 };
    WebVector<int> indicesVector(indices, 1);
    client->didAcceptIndices(indicesVector);
    EXPECT_FALSE(select->popupIsVisible());
=======
    HTMLSelectElement* select = toHTMLSelectElement(mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    menuList->showPopup();
    ASSERT_TRUE(menuList->popupIsVisible());

    WebExternalPopupMenuClient* client = static_cast<ExternalPopupMenu*>(menuList->popup());
    int indices[] = { 2 };
    WebVector<int> indicesVector(indices, 1);
    client->didAcceptIndices(indicesVector);
    EXPECT_FALSE(menuList->popupIsVisible());
>>>>>>> miniblink49
    EXPECT_STREQ("2", menuList->text().utf8().data());
    EXPECT_EQ(2, select->selectedIndex());
}

TEST_F(ExternalPopupMenuTest, DidAcceptIndicesClearSelect)
{
    registerMockedURLLoad("select.html");
    loadFrame("select.html");

<<<<<<< HEAD
    HTMLSelectElement* select = toHTMLSelectElement(
        mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    select->showPopup();
    ASSERT_TRUE(select->popupIsVisible());

    WebExternalPopupMenuClient* client = static_cast<ExternalPopupMenu*>(select->popup());
    WebVector<int> indices;
    client->didAcceptIndices(indices);
    EXPECT_FALSE(select->popupIsVisible());
=======
    HTMLSelectElement* select = toHTMLSelectElement(mainFrame()->frame()->document()->getElementById("select"));
    LayoutMenuList* menuList = toLayoutMenuList(select->layoutObject());
    ASSERT_TRUE(menuList);

    menuList->showPopup();
    ASSERT_TRUE(menuList->popupIsVisible());

    WebExternalPopupMenuClient* client = static_cast<ExternalPopupMenu*>(menuList->popup());
    WebVector<int> indices;
    client->didAcceptIndices(indices);
    EXPECT_FALSE(menuList->popupIsVisible());
>>>>>>> miniblink49
    EXPECT_EQ(-1, select->selectedIndex());
}

} // namespace blink

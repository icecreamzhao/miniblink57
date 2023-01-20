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
#include "web/ExternalPopupMenu.h"

#include "core/dom/ExecutionContextTask.h"
#include "core/dom/NodeComputedStyle.h"
#include "core/dom/TaskRunnerHelper.h"
#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/LocalFrame.h"
#include "core/html/HTMLOptionElement.h"
#include "core/html/HTMLSelectElement.h"
#include "core/layout/LayoutBox.h"
#include "core/page/Page.h"
#include "core/style/ComputedStyle.h"
#include "platform/geometry/FloatQuad.h"
#include "platform/geometry/IntPoint.h"
#include "platform/text/TextDirection.h"
#include "public/platform/WebMouseEvent.h"
=======
#include "config.h"
#include "web/ExternalPopupMenu.h"

#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/PinchViewport.h"
#include "core/html/forms/PopupMenuClient.h"
#include "core/page/Page.h"
#include "platform/geometry/FloatQuad.h"
#include "platform/geometry/IntPoint.h"
#include "platform/text/TextDirection.h"
>>>>>>> miniblink49
#include "public/platform/WebVector.h"
#include "public/web/WebExternalPopupMenu.h"
#include "public/web/WebFrameClient.h"
#include "public/web/WebMenuItemInfo.h"
#include "public/web/WebPopupMenuInfo.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WebViewImpl.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"

namespace blink {

ExternalPopupMenu::ExternalPopupMenu(LocalFrame& frame,
    HTMLSelectElement& ownerElement,
    WebViewImpl& webView)
    : m_ownerElement(ownerElement)
=======

namespace blink {

ExternalPopupMenu::ExternalPopupMenu(LocalFrame& frame, PopupMenuClient* popupMenuClient, WebViewImpl& webView)
    : m_popupMenuClient(popupMenuClient)
>>>>>>> miniblink49
    , m_localFrame(frame)
    , m_webView(webView)
    , m_dispatchEventTimer(this, &ExternalPopupMenu::dispatchEvent)
    , m_webExternalPopupMenu(0)
{
}

<<<<<<< HEAD
ExternalPopupMenu::~ExternalPopupMenu() { }

DEFINE_TRACE(ExternalPopupMenu)
{
    visitor->trace(m_ownerElement);
=======
ExternalPopupMenu::~ExternalPopupMenu()
{
}

DEFINE_TRACE(ExternalPopupMenu)
{
>>>>>>> miniblink49
    visitor->trace(m_localFrame);
    PopupMenu::trace(visitor);
}

<<<<<<< HEAD
bool ExternalPopupMenu::showInternal()
{
    // Blink core reuses the PopupMenu of an element.  For simplicity, we do
    // recreate the actual external popup everytime.
=======
void ExternalPopupMenu::show(const FloatQuad& controlPosition, const IntSize&, int index)
{
    IntRect rect(controlPosition.enclosingBoundingBox());
    // WebCore reuses the PopupMenu of an element.
    // For simplicity, we do recreate the actual external popup everytime.
>>>>>>> miniblink49
    if (m_webExternalPopupMenu) {
        m_webExternalPopupMenu->close();
        m_webExternalPopupMenu = 0;
    }

    WebPopupMenuInfo info;
<<<<<<< HEAD
    getPopupMenuInfo(info, *m_ownerElement);
    if (info.items.isEmpty())
        return false;
    WebLocalFrameImpl* webframe = WebLocalFrameImpl::fromFrame(m_localFrame.get());
    m_webExternalPopupMenu = webframe->client()->createExternalPopupMenu(info, this);
    if (m_webExternalPopupMenu) {
        LayoutObject* layoutObject = m_ownerElement->layoutObject();
        if (!layoutObject || !layoutObject->isBox())
            return false;
        FloatQuad quad(toLayoutBox(layoutObject)
                           ->localToAbsoluteQuad(FloatQuad(
                               toLayoutBox(layoutObject)->borderBoundingBox())));
        IntRect rect(quad.enclosingBoundingBox());
        IntRect rectInViewport = m_localFrame->view()->contentsToViewport(rect);
        m_webExternalPopupMenu->show(rectInViewport);
        return true;
    } else {
        // The client might refuse to create a popup (when there is already one
        // pending to be shown for example).
        didCancel();
        return false;
    }
}

void ExternalPopupMenu::show()
{
    if (!showInternal())
        return;
#if OS(MACOSX)
    const WebInputEvent* currentEvent = WebViewImpl::currentInputEvent();
    if (currentEvent && currentEvent->type() == WebInputEvent::MouseDown) {
        m_syntheticEvent = WTF::wrapUnique(new WebMouseEvent);
        *m_syntheticEvent = *static_cast<const WebMouseEvent*>(currentEvent);
        m_syntheticEvent->setType(WebInputEvent::MouseUp);
        m_dispatchEventTimer.startOneShot(0, BLINK_FROM_HERE);
        // FIXME: show() is asynchronous. If preparing a popup is slow and a
        // user released the mouse button before showing the popup, mouseup and
        // click events are correctly dispatched. Dispatching the synthetic
        // mouseup event is redundant in this case.
    }
#endif
}

void ExternalPopupMenu::dispatchEvent(TimerBase*)
{
    m_webView.handleInputEvent(*m_syntheticEvent);
    m_syntheticEvent.reset();
=======
    getPopupMenuInfo(info, *m_popupMenuClient);
    if (info.items.isEmpty())
        return;
    WebLocalFrameImpl* webframe = WebLocalFrameImpl::fromFrame(m_localFrame.get());
    m_webExternalPopupMenu = webframe->client()->createExternalPopupMenu(info, this);
    if (m_webExternalPopupMenu) {
        IntRect rectInViewport = m_localFrame->view()->soonToBeRemovedContentsToUnscaledViewport(rect);
        m_webExternalPopupMenu->show(rectInViewport);
#if OS(MACOSX)
        const WebInputEvent* currentEvent = WebViewImpl::currentInputEvent();
        if (currentEvent && currentEvent->type == WebInputEvent::MouseDown) {
            m_syntheticEvent = adoptPtr(new WebMouseEvent);
            *m_syntheticEvent = *static_cast<const WebMouseEvent*>(currentEvent);
            m_syntheticEvent->type = WebInputEvent::MouseUp;
            m_dispatchEventTimer.startOneShot(0, FROM_HERE);
            // FIXME: show() is asynchronous. If preparing a popup is slow and
            // a user released the mouse button before showing the popup,
            // mouseup and click events are correctly dispatched. Dispatching
            // the synthetic mouseup event is redundant in this case.
        }
#endif
    } else {
        // The client might refuse to create a popup (when there is already one pending to be shown for example).
        didCancel();
    }
}

void ExternalPopupMenu::dispatchEvent(Timer<ExternalPopupMenu>*)
{
    m_webView.handleInputEvent(*m_syntheticEvent);
    m_syntheticEvent.clear();
>>>>>>> miniblink49
}

void ExternalPopupMenu::hide()
{
<<<<<<< HEAD
    if (m_ownerElement)
        m_ownerElement->popupDidHide();
=======
    if (m_popupMenuClient)
        m_popupMenuClient->popupDidHide();
>>>>>>> miniblink49
    if (!m_webExternalPopupMenu)
        return;
    m_webExternalPopupMenu->close();
    m_webExternalPopupMenu = 0;
}

<<<<<<< HEAD
void ExternalPopupMenu::updateFromElement(UpdateReason reason)
{
    switch (reason) {
    case BySelectionChange:
    case ByDOMChange:
        if (m_needsUpdate)
            return;
        m_needsUpdate = true;
        m_ownerElement->document().postTask(
            TaskType::UserInteraction, BLINK_FROM_HERE,
            createSameThreadTask(&ExternalPopupMenu::update,
                wrapPersistent(this)));
        break;

    case ByStyleChange:
        // TOOD(tkent): We should update the popup location/content in some
        // cases.  e.g. Updating ComputedStyle of the SELECT element affects
        // popup position and OPTION style.
        break;
    }
}

void ExternalPopupMenu::update()
{
    if (!m_webExternalPopupMenu || !m_ownerElement)
        return;
    m_ownerElement->document().updateStyleAndLayoutTree();
    // disconnectClient() might have been called.
    if (!m_ownerElement)
        return;
    m_needsUpdate = false;

    if (showInternal())
        return;
    // We failed to show a popup.  Notify it to the owner.
    hide();
=======
void ExternalPopupMenu::updateFromElement()
{
>>>>>>> miniblink49
}

void ExternalPopupMenu::disconnectClient()
{
    hide();
<<<<<<< HEAD
    m_ownerElement = nullptr;
}

void ExternalPopupMenu::didChangeSelection(int index) { }

void ExternalPopupMenu::didAcceptIndex(int index)
{
    // Calling methods on the HTMLSelectElement might lead to this object being
    // derefed. This ensures it does not get deleted while we are running this
    // method.
    int popupMenuItemIndex = toPopupMenuItemIndex(index, *m_ownerElement);

    if (m_ownerElement) {
        m_ownerElement->popupDidHide();
        m_ownerElement->selectOptionByPopup(popupMenuItemIndex);
=======
    m_popupMenuClient = 0;
}

void ExternalPopupMenu::didChangeSelection(int index)
{
    if (m_popupMenuClient)
        m_popupMenuClient->selectionChanged(toPopupMenuItemIndex(index, *m_popupMenuClient));
}

void ExternalPopupMenu::didAcceptIndex(int index)
{
    // Calling methods on the PopupMenuClient might lead to this object being
    // derefed. This ensures it does not get deleted while we are running this
    // method.
    int popupMenuItemIndex = toPopupMenuItemIndex(index, *m_popupMenuClient);
    RefPtrWillBeRawPtr<ExternalPopupMenu> guard(this);

    if (m_popupMenuClient) {
        m_popupMenuClient->popupDidHide();
        m_popupMenuClient->valueChanged(popupMenuItemIndex);
>>>>>>> miniblink49
    }
    m_webExternalPopupMenu = 0;
}

<<<<<<< HEAD
// Android uses this function even for single SELECT.
void ExternalPopupMenu::didAcceptIndices(const WebVector<int>& indices)
{
    if (!m_ownerElement) {
=======
void ExternalPopupMenu::didAcceptIndices(const WebVector<int>& indices)
{
    if (!m_popupMenuClient) {
>>>>>>> miniblink49
        m_webExternalPopupMenu = 0;
        return;
    }

<<<<<<< HEAD
    HTMLSelectElement* ownerElement = m_ownerElement;
    ownerElement->popupDidHide();

    if (indices.size() == 0) {
        ownerElement->selectOptionByPopup(-1);
    } else if (!ownerElement->isMultiple()) {
        ownerElement->selectOptionByPopup(
            toPopupMenuItemIndex(indices[indices.size() - 1], *ownerElement));
    } else {
        Vector<int> listIndices;
        listIndices.reserveCapacity(indices.size());
        for (size_t i = 0; i < indices.size(); ++i)
            listIndices.push_back(toPopupMenuItemIndex(indices[i], *ownerElement));
        ownerElement->selectMultipleOptionsByPopup(listIndices);
=======
    // Calling methods on the PopupMenuClient might lead to this object being
    // derefed. This ensures it does not get deleted while we are running this
    // method.
    RefPtrWillBeRawPtr<ExternalPopupMenu> protect(this);

    m_popupMenuClient->popupDidHide();

    if (!indices.size())
        m_popupMenuClient->valueChanged(static_cast<unsigned>(-1), true);
    else {
        for (size_t i = 0; i < indices.size(); ++i)
            m_popupMenuClient->listBoxSelectItem(toPopupMenuItemIndex(indices[i], *m_popupMenuClient), (i > 0), false, (i == indices.size() - 1));
>>>>>>> miniblink49
    }

    m_webExternalPopupMenu = 0;
}

void ExternalPopupMenu::didCancel()
{
<<<<<<< HEAD
    if (m_ownerElement)
        m_ownerElement->popupDidHide();
    m_webExternalPopupMenu = 0;
}

void ExternalPopupMenu::getPopupMenuInfo(WebPopupMenuInfo& info,
    HTMLSelectElement& ownerElement)
{
    const HeapVector<Member<HTMLElement>>& listItems = ownerElement.listItems();
    size_t itemCount = listItems.size();
    size_t count = 0;
    Vector<WebMenuItemInfo> items(itemCount);
    for (size_t i = 0; i < itemCount; ++i) {
        if (ownerElement.itemIsDisplayNone(*listItems[i]))
            continue;

        Element& itemElement = *listItems[i];
        WebMenuItemInfo& popupItem = items[count++];
        popupItem.label = ownerElement.itemText(itemElement);
        popupItem.toolTip = itemElement.title();
        popupItem.checked = false;
        if (isHTMLHRElement(itemElement)) {
            popupItem.type = WebMenuItemInfo::Separator;
        } else if (isHTMLOptGroupElement(itemElement)) {
            popupItem.type = WebMenuItemInfo::Group;
        } else {
            popupItem.type = WebMenuItemInfo::Option;
            popupItem.checked = toHTMLOptionElement(itemElement).selected();
        }
        popupItem.enabled = !itemElement.isDisabledFormControl();
        const ComputedStyle& style = *ownerElement.itemComputedStyle(itemElement);
        popupItem.textDirection = toWebTextDirection(style.direction());
        popupItem.hasTextDirectionOverride = isOverride(style.getUnicodeBidi());
    }

    const ComputedStyle& menuStyle = ownerElement.computedStyle()
        ? *ownerElement.computedStyle()
        : *ownerElement.ensureComputedStyle();
    const SimpleFontData* fontData = menuStyle.font().primaryFont();
    DCHECK(fontData);
    info.itemHeight = fontData ? fontData->getFontMetrics().height() : 0;
    info.itemFontSize = static_cast<int>(menuStyle.font().getFontDescription().computedSize());
    info.selectedIndex = toExternalPopupMenuItemIndex(
        ownerElement.selectedListIndex(), ownerElement);
    info.rightAligned = menuStyle.direction() == TextDirection::kRtl;
    info.allowMultipleSelection = ownerElement.isMultiple();
    if (count < itemCount)
        items.shrink(count);
    info.items = items;
}

int ExternalPopupMenu::toPopupMenuItemIndex(int externalPopupMenuItemIndex,
    HTMLSelectElement& ownerElement)
=======
    // See comment in didAcceptIndex on why we need this.
    RefPtrWillBeRawPtr<ExternalPopupMenu> guard(this);

    if (m_popupMenuClient)
        m_popupMenuClient->popupDidHide();
    m_webExternalPopupMenu = 0;
}

void ExternalPopupMenu::getPopupMenuInfo(WebPopupMenuInfo& info, PopupMenuClient& popupMenuClient)
{
    int itemCount = popupMenuClient.listSize();
    int count = 0;
    Vector<WebMenuItemInfo> items(static_cast<size_t>(itemCount));
    for (int i = 0; i < itemCount; ++i) {
        PopupMenuStyle style = popupMenuClient.itemStyle(i);
        if (style.isDisplayNone())
            continue;

        WebMenuItemInfo& popupItem = items[count++];
        popupItem.label = popupMenuClient.itemText(i);
        popupItem.toolTip = popupMenuClient.itemToolTip(i);
        if (popupMenuClient.itemIsSeparator(i))
            popupItem.type = WebMenuItemInfo::Separator;
        else if (popupMenuClient.itemIsLabel(i))
            popupItem.type = WebMenuItemInfo::Group;
        else
            popupItem.type = WebMenuItemInfo::Option;
        popupItem.enabled = popupMenuClient.itemIsEnabled(i);
        popupItem.checked = popupMenuClient.itemIsSelected(i);
        popupItem.textDirection = toWebTextDirection(style.textDirection());
        popupItem.hasTextDirectionOverride = style.hasTextDirectionOverride();
    }

    info.itemHeight = popupMenuClient.menuStyle().font().fontMetrics().height();
    info.itemFontSize = static_cast<int>(popupMenuClient.menuStyle().font().fontDescription().computedSize());
    info.selectedIndex = toExternalPopupMenuItemIndex(popupMenuClient.selectedIndex(), popupMenuClient);
    info.rightAligned = popupMenuClient.menuStyle().textDirection() == RTL;
    info.allowMultipleSelection = popupMenuClient.multiple();
    if (count < itemCount)
        items.shrink(count);
    info.items = items;

}

int ExternalPopupMenu::toPopupMenuItemIndex(int externalPopupMenuItemIndex, PopupMenuClient& popupMenuClient)
>>>>>>> miniblink49
{
    if (externalPopupMenuItemIndex < 0)
        return externalPopupMenuItemIndex;

<<<<<<< HEAD
    int indexTracker = 0;
    const HeapVector<Member<HTMLElement>>& items = ownerElement.listItems();
    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        if (ownerElement.itemIsDisplayNone(*items[i]))
=======
    int itemCount = popupMenuClient.listSize();
    int indexTracker = 0;
    for (int i = 0; i < itemCount ; ++i) {
        if (popupMenuClient.itemStyle(i).isDisplayNone())
>>>>>>> miniblink49
            continue;
        if (indexTracker++ == externalPopupMenuItemIndex)
            return i;
    }
    return -1;
}

<<<<<<< HEAD
int ExternalPopupMenu::toExternalPopupMenuItemIndex(
    int popupMenuItemIndex,
    HTMLSelectElement& ownerElement)
=======
int ExternalPopupMenu::toExternalPopupMenuItemIndex(int popupMenuItemIndex, PopupMenuClient& popupMenuClient)
>>>>>>> miniblink49
{
    if (popupMenuItemIndex < 0)
        return popupMenuItemIndex;

<<<<<<< HEAD
    size_t indexTracker = 0;
    const HeapVector<Member<HTMLElement>>& items = ownerElement.listItems();
    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        if (ownerElement.itemIsDisplayNone(*items[i]))
=======
    int itemCount = popupMenuClient.listSize();
    int indexTracker = 0;
    for (int i = 0; i < itemCount; ++i) {
        if (popupMenuClient.itemStyle(i).isDisplayNone())
>>>>>>> miniblink49
            continue;
        if (popupMenuItemIndex == i)
            return indexTracker;
        ++indexTracker;
    }
    return -1;
}

} // namespace blink

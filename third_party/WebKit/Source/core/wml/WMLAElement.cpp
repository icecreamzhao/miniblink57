/**
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 *
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Simon Hausmann <hausmann@kde.org>
 * Copyright (C) 2003, 2006, 2007, 2008, 2010 Apple Inc. All rights reserved.
 *           (C) 2006 Graham Dennis (graham.dennis@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"

#if ENABLE_WML
#include "WMLAElement.h"

#include "WMLVariables.h"
#include "core/EventNames.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"
#include "core/dom/StyleChangeReason.h"
#include "core/events/Event.h"
#include "core/events/KeyboardEvent.h"
#include "core/events/MouseEvent.h"
#include "core/frame/FrameHost.h"
#include "core/frame/LocalFrame.h"
#include "core/html/HTMLAnchorElement.h"
#include "core/html/parser/HTMLParserIdioms.h"
#include "core/input/EventHandler.h"
#include "core/layout/LayoutBox.h"
#include "core/loader/FrameLoadRequest.h"
#include "core/loader/FrameLoader.h"
#include "core/page/ChromeClient.h"
#include "core/page/Page.h"

//TODO update to 112327
//In 112327, the ResourceHandle::prepareForURL is removed
//The original ResourceHandle::prepareForURL is implemented by calling prefetchDNS
//So, here calling prefetchDNS directly. The 'prefetchDNS' is declared in DNS.h
#ifdef TENCENT_CHANGES
#include "platform/network/NetworkHints.h"
#endif

namespace blink {

using namespace WMLNames;

template <>
bool isElementOfType<const WMLAElement>(Node const& element)
{
    //return isWMLAOrAnchorElement(element);
    return false;
}

WMLAElement::WMLAElement(Document& doc)
    : WMLElement(aTag, doc)
    , m_cachedVisitedLinkHash(0)
{
}

WMLAElement::WMLAElement(const QualifiedName& tagName, Document& doc)
    : WMLElement(tagName, doc)
{
}

DEFINE_NODE_FACTORY(WMLAElement)

void WMLAElement::parseAttribute(const AttributeModificationParams& params)
{
    if (params.name == HTMLNames::hrefAttr) {
        bool wasLink = isLink();
        setIsLink(!params.newValue.isNull());
        if (wasLink != isLink())
            setNeedsStyleRecalc(NeedsReattachStyleChange, StyleChangeReasonForTracing::create(StyleChangeReason::StyleInvalidator));
        if (isLink() && document().isDNSPrefetchEnabled()) {
            if (protocolIs(params.newValue, "http") || protocolIs(params.newValue, "https") || params.newValue.startsWith("//"))
            // TODO update to 112327
            // In 112327, the ResourceHandle::prepareForURL is removed
            // The original ResourceHandle::prepareForURL is implemented by calling prefetchDNS
            // So, here calling prefetchDNS directly
#ifdef TENCENT_CHANGES
                prefetchDNS(document().completeURL(params.newValue));
#else
                ResourceHandle::prepareForURL(document().completeURL(value));
#endif
        }
    } else if (params.name == HTMLNames::nameAttr
        || params.name == HTMLNames::titleAttr
        || params.name == HTMLNames::relAttr) {
        // Do nothing.
    } else
        WMLElement::parseAttribute(params);
}

bool WMLAElement::supportsFocus() const
{
    return isLink() || WMLElement::supportsFocus();
}

bool WMLAElement::isMouseFocusable() const
{
    return false;
}

bool WMLAElement::isKeyboardFocusable() const
{
    if (!isFocusable())
        return false;

    if (!document().frame())
        return false;

    if (isLink() && document().page()->chromeClient().tabsToLinks())
        return false;

    if (!layoutObject() || !layoutObject()->isBoxModelObject())
        return false;

    // Before calling absoluteRects, check for the common case where the renderer
    // is non-empty, since this is a faster check and almost always returns true.
    LayoutBoxModelObject* box = toLayoutBoxModelObject(layoutObject());
    if (!box->borderBoundingBox().isEmpty())
        return true;

    Vector<IntRect> rects;
    FloatPoint absPos = layoutObject()->localToAbsolute();
    //renderer()->absoluteRects(rects, absPos.x(), absPos.y());
    layoutObject()->absoluteRects(rects, roundedIntPoint(absPos));
    size_t n = rects.size();
    for (size_t i = 0; i < n; ++i)
        if (!rects[i].isEmpty())
            return true;

    return false;
}

void handleLinkClick(Event* event, Document* document, const String& url, const AtomicString& target)
{
    LocalFrame* frame = document->frame();
    if (!frame)
        return;
    FrameLoadRequest frameRequest(document, ResourceRequest(document->completeURL(url)), target);
    frameRequest.setTriggeringEvent(event);
    frame->loader().load(frameRequest);
    return;
}

void WMLAElement::defaultEventHandler(Event* event)
{
    if (isLink()) {
        if (isFocused() && isEnterKeyKeydownEvent(event)) {
            event->setDefaultHandled();
            dispatchSimulatedClick(event);
            return;
        }

        if (isLinkClick(event))
            handleLinkClick(event, &document(), stripLeadingAndTrailingHTMLSpaces(getAttribute(HTMLNames::hrefAttr)), WTF::AtomicString(target()));
    }

    WMLElement::defaultEventHandler(event);
}

void WMLAElement::accessKeyAction(bool sendToAnyElement)
{
    // send the mouse button events if the caller specified sendToAnyElement
    dispatchSimulatedClick(0, sendToAnyElement ? SendMouseUpDownEvents : SendNoEvents);
}

bool WMLAElement::isURLAttribute(const Attribute& attr) const
{
    return attr.name() == HTMLNames::hrefAttr;
}

String WMLAElement::target() const
{
    return getAttribute(HTMLNames::targetAttr);
}

KURL WMLAElement::href() const
{
    // Substitute variables within target url attribute value.
    String href = substituteVariableReferences(getAttribute(HTMLNames::hrefAttr), &document(), WMLVariableEscapingEscape);
    return document().completeURL(href);
}

LinkHash WMLAElement::visitedLinkHash() const
{
    if (!m_cachedVisitedLinkHash)
        m_cachedVisitedLinkHash = blink::visitedLinkHash(document().baseURL(), fastGetAttribute(HTMLNames::hrefAttr));
    return m_cachedVisitedLinkHash;
}

DEFINE_TRACE(WMLAElement)
{
    WMLElement::trace(visitor);
}

bool isWMLAOrAnchorElement(const Element& element)
{
    return element.isWMLElement() && (element.hasLocalName((WMLNames::aTag).localName()) || element.hasLocalName((WMLNames::anchorTag).localName()));
}

}

#endif

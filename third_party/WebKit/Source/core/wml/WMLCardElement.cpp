/*
 * Copyright (C) 2008, 2009 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
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
#include "WMLCardElement.h"

#include "WMLDoElement.h"
#include "WMLDocument.h"
#include "WMLInputElement.h"
#include "WMLIntrinsicEventHandler.h"
#include "WMLOnEventElement.h" // SAMSUNG_WML_FIXES+
#include "WMLSelectElement.h"
#include "WMLTemplateElement.h"
#include "WMLTimerElement.h"
#include "WMLVariables.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"
#include "core/dom/NodeList.h"
#include "core/dom/NodeTraversal.h"
#include "core/dom/TagCollection.h"
#include "core/frame/Frame.h"
#include "core/frame/Settings.h"
#include "core/layout/LayoutObject.h"
#include "core/loader/FrameLoader.h"
#include "core/page/Page.h"
#include "core/style/ComputedStyle.h"

namespace blink {

using namespace WMLNames;

WMLCardElement::WMLCardElement(Document& doc)
    : WMLElement(cardTag, doc)
    , m_isNewContext(false)
    , m_isOrdered(false)
    , m_isVisible(false)
    , m_eventTimer(0)
    , m_template(0)
{
    ASSERT(hasTagName(cardTag));
}

DEFINE_NODE_FACTORY(WMLCardElement)

WMLCardElement::~WMLCardElement()
{
}

void WMLCardElement::showCard()
{
    //ASSERT(attached());

    if (m_isVisible) {
        ASSERT(layoutObject());
        return;
    }

    m_isVisible = true;
    ASSERT(!layoutObject());

    detachLayoutTree();
    attachLayoutTree();

    //ASSERT(attached());
    ASSERT(layoutObject());
}

void WMLCardElement::hideCard()
{
    //ASSERT(attached());

    if (!m_isVisible) {
        ASSERT(!layoutObject());
        return;
    }

    m_isVisible = false;
    ASSERT(layoutObject());

    detachLayoutTree();
    attachLayoutTree();

    //ASSERT(attached());
    ASSERT(!layoutObject());
}

void WMLCardElement::setTemplateElement(WMLTemplateElement* temp)
{
    // Only one template is allowed to be attached to a card
    if (m_template) {
        reportWMLError(&document(), WMLErrorMultipleTemplateElements);
        return;
    }

    m_template = temp;
}

void WMLCardElement::setIntrinsicEventTimer(WMLTimerElement* timer)
{
    // Only one timer is allowed in a card
    if (m_eventTimer) {
        reportWMLError(&document(), WMLErrorMultipleTimerElements);
        return;
    }

    m_eventTimer = timer;
}

void WMLCardElement::handleIntrinsicEventIfNeeded()
{
    WMLPageState* pageState = wmlPageStateForDocument(&document());
    if (!pageState)
        return;

    LocalFrame* frame = document().frame();
    if (!frame)
        return;

    FrameLoader* loader = &frame->loader();
    if (!loader)
        return;

    // TODO
    // Calculate the entry method of current card
    WMLIntrinsicEventType eventType = WMLIntrinsicEventUnknown;
    switch (loader->loadType()) {
    case FrameLoadTypeReload:
        break;
    case FrameLoadTypeBackForward:
        eventType = WMLIntrinsicEventOnEnterBackward;
        break;
        //     case FrameLoadTypeBackWMLDeckNotAccessible:
        //         reportWMLError(&document(), WMLErrorDeckNotAccessible);
        //         return;
    default:
        eventType = WMLIntrinsicEventOnEnterForward;
        break;
    }

    // Figure out target event handler
    WMLIntrinsicEventHandler* eventHandler = this->eventHandler();
    bool hasIntrinsicEvent = false;

    if (eventType != WMLIntrinsicEventUnknown) {
        if (eventHandler && eventHandler->hasIntrinsicEvent(eventType))
            hasIntrinsicEvent = true;
        else if (m_template) {
            eventHandler = m_template->eventHandler();
            if (eventHandler && eventHandler->hasIntrinsicEvent(eventType))
                hasIntrinsicEvent = true;
        }
    }

    // SAMSUNG_WML_FIXES+
    // http://spe.mobilephone.net/wit/wmlv2/structemp.wml
    if (hasIntrinsicEvent) {
        NodeList* children = childNodes();

        if (children) {
            unsigned length = children->length();
            for (unsigned i = 0; i < length; ++i) {
                Node* child = children->item(i);
                if (!child->isElementNode())
                    continue;

                Element* element = (Element*)child;
                if (element->hasLocalName((oneventTag).localName())) {
                    WMLOnEventElement* onEventElement = static_cast<WMLOnEventElement*>(child);
                    if (onEventElement->eventType() == eventType && onEventElement->isNoop()) {
                        hasIntrinsicEvent = false;
                        break;
                    }
                }
            }
        }
    }
    // SAMSUNG_WML_FIXES-
    if (hasIntrinsicEvent)
        eventHandler->triggerIntrinsicEvent(eventType);

    // Start the timer if it exists in current card
    if (m_eventTimer)
        m_eventTimer->start();

    //for (Node* node = traverseNextNode(); node != 0; node = node->traverseNextNode()) {
    for (Node* node = NodeTraversal::nextSkippingChildren(*this); node != 0; node = NodeTraversal::nextSkippingChildren(*node)) {
        if (!node->isElementNode())
            continue;

        /*if (node->hasTagName(inputTag))
            static_cast<WMLInputElement*>(node)->initialize();
        else if (node->hasTagName(selectTag))
            static_cast<WMLSelectElement*>(node)->selectInitialOptions();*/
    }
}

void WMLCardElement::handleDeckLevelTaskOverridesIfNeeded()
{
    // Spec: The event-handling element may appear inside a template element and specify
    // event-processing behaviour for all cards in the deck. A deck-level event-handling
    // element is equivalent to specifying the event-handling element in each card.
    if (!m_template)
        return;

    HeapVector<Member<WMLDoElement>>& templateDoElements = m_template->doElements();
    if (templateDoElements.isEmpty())
        return;

    HeapVector<Member<WMLDoElement>>& cardDoElements = doElements();
    HeapVector<Member<WMLDoElement>>::iterator it = cardDoElements.begin();
    HeapVector<Member<WMLDoElement>>::iterator end = cardDoElements.end();

    HashSet<String> cardDoElementNames;
    for (; it != end; ++it)
        cardDoElementNames.add((*it)->name());

    it = templateDoElements.begin();
    end = templateDoElements.end();

    // SAMSUNG_WML_FIXES+
    // http://spe.mobilephone.net/wit/wmlv2/navdo.wml
    //for (; it != end; ++it)
    //    (*it)->setActive(!cardDoElementNames.contains((*it)->name()));
    for (; it != end; ++it) {
        bool active = !cardDoElementNames.contains((*it)->name());
        if ((*it)->isActive() != active) {
            (*it)->setActive(active);
            if (!(*it)->needsAttach())
                (*it)->detachLayoutTree();

            ASSERT((*it)->needsAttach());
            (*it)->attachLayoutTree();
        }
    }
    // SAMSUNG_WML_FIXES-
}

void WMLCardElement::parseAttribute(const AttributeModificationParams& params)
{
    WMLIntrinsicEventType eventType = WMLIntrinsicEventUnknown;

    if (params.name == onenterforwardAttr)
        eventType = WMLIntrinsicEventOnEnterForward;
    else if (params.name == onenterbackwardAttr)
        eventType = WMLIntrinsicEventOnEnterBackward;
    else if (params.name == ontimerAttr)
        eventType = WMLIntrinsicEventOnTimer;
    else if (params.name == newcontextAttr)
        m_isNewContext = (params.newValue == "true");
    else if (params.name == orderedAttr)
        m_isOrdered = (params.newValue == "true");
    else {
        WMLElement::parseAttribute(params);
        return;
    }

    if (eventType == WMLIntrinsicEventUnknown)
        return;

#ifdef TENCENT_CHANGES
    WMLDocument* doc = static_cast<WMLDocument*>(&this->document());
    if (eventType == WMLIntrinsicEventOnEnterForward) {
        m_onenterforwardUrl = doc->completeURL(substituteVariableReferences(params.newValue, doc, WMLVariableEscapingEscape));

        if (!m_ontimerUrl.isEmpty() && m_ontimerUrl == m_onenterforwardUrl) {
            eventHandler()->deregisterIntrinsicEvent(WMLIntrinsicEventOnTimer);
        }
    } else if (eventType == WMLIntrinsicEventOnEnterBackward) {
        m_onenterbackwardUrl = doc->completeURL(substituteVariableReferences(params.newValue, doc, WMLVariableEscapingEscape));
        if (!m_ontimerUrl.isEmpty() && m_ontimerUrl == m_onenterbackwardUrl) {
            eventHandler()->deregisterIntrinsicEvent(WMLIntrinsicEventOnTimer);
        }
    } else if (eventType == WMLIntrinsicEventOnTimer) {
        m_ontimerUrl = doc->completeURL(substituteVariableReferences(params.newValue, doc, WMLVariableEscapingEscape));
        if ((!m_onenterforwardUrl.isEmpty() && m_ontimerUrl == m_onenterforwardUrl) || (!m_onenterbackwardUrl.isEmpty() && m_ontimerUrl == m_onenterbackwardUrl)) {
            return;
        }
    }
#endif
    // Register intrinsic event in card
    WMLIntrinsicEvent* event = WMLIntrinsicEvent::create(&document(), params.newValue);

    createEventHandlerIfNeeded();
    eventHandler()->registerIntrinsicEvent(eventType, event);
}

Node::InsertionNotificationRequest WMLCardElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);
    Document* document = &this->document();

    // The first card inserted into a document, is visible by default.
    if (!m_isVisible) {
        TagCollection* nodeList = document->getElementsByTagName("card");
        if (nodeList && nodeList->length() == 1 && nodeList->item(0) == this)
            m_isVisible = true;
            // SAMSUNG_WML_FIXES+
#ifdef ANDROID_META_SUPPORT
#ifndef TENCENT_CHANGES
        // fit wml sites directly in the screen
        if (Page* p = document->page())
            p->settings()->setMetadataSettings("width", "device-width");
        if (FrameView* frameView = document->view())
            tencent::WebRendering::getWebRendering(frameView)->updateViewport();
#endif
#endif
#ifdef TENCENT_CHANGES // TODO
            //FrameView* view = document->view();
            //if (view)
            //	view->updateViewport();
#endif
        // SAMSUNG_WML_FIXES+
    }

    // For the WML layout tests we embed WML content in a XHTML document. Navigating to different cards
    // within the same deck has a different behaviour in HTML than in WML. HTML wants to "scroll to anchor"
    // (see FrameLoader) but WML wants a reload. Notify the root document of the layout test that we want
    // to mimic WML behaviour. This is rather tricky, but has been tested extensively. Usually it's not possible
    // at all to embed WML in HTML, it's not designed that way, we're just "abusing" it for dynamically created layout tests.
    // TODO
    /*if (document->page() && document->page()->mainFrame()) {
        Document* rootDocument = document->page()->mainFrame()->document();
        if (rootDocument && rootDocument != document)
            rootDocument->setContainsWMLContent(true);
    }*/
    // harryguo: wml:newcontext tag requires clearing navigation history, which is obsolete and will cause problems
    // so we decide not supporting it.
    // #ifdef TENCENT_CHANGES
    //     if(isNewContext())
    //     	wmlPageStateForDocument(document)->reset();
    // #endif

    return InsertionDone;
}

LayoutObject* WMLCardElement::createLayoutObject(const ComputedStyle& style)
{
    LayoutObject* result = WMLElement::createLayoutObject(style);
    if (!m_isVisible) {
        result->setStyle((ComputedStyle*)&style);
        result->mutableStyle()->setUnique();
        result->mutableStyle()->setDisplay(EDisplay::None);
    }

    return result;
}

WMLCardElement* WMLCardElement::findNamedCardInDocument(Document* doc, const String& cardName)
{
    if (cardName.isEmpty())
        return 0;

    TagCollection* nodeList = doc->getElementsByTagName("card");
    if (!nodeList)
        return 0;

    unsigned length = nodeList->length();
    if (length < 1)
        return 0;

    for (unsigned i = 0; i < length; ++i) {
        WMLCardElement* card = static_cast<WMLCardElement*>(nodeList->item(i));
        if (card->getIdAttribute() != cardName)
            continue;

        return card;
    }

    return 0;
}

WMLCardElement* WMLCardElement::determineActiveCard(Document* doc)
{
    WMLPageState* pageState = wmlPageStateForDocument(doc);
    if (!pageState)
        return 0;

    TagCollection* nodeList = doc->getElementsByTagName("card");
    if (!nodeList)
        return 0;

    unsigned length = nodeList->length();
    if (length < 1)
        return 0;

    // Figure out the new target card
    String cardName = doc->url().fragmentIdentifier();

    WMLCardElement* activeCard = findNamedCardInDocument(doc, cardName);
    if (activeCard) {
        // Hide all cards - except the destination card - in document
        for (unsigned i = 0; i < length; ++i) {
            WMLCardElement* card = static_cast<WMLCardElement*>(nodeList->item(i));

            if (card == activeCard)
                card->showCard();
            else
                card->hideCard();
        }
    } else {
        // If the target URL didn't contain a fragment identifier, activeCard
        // is 0, and has to be set to the first card element in the deck.
        activeCard = static_cast<WMLCardElement*>(nodeList->item(0));
        activeCard->showCard();
    }

    // Assure destination card is visible
    ASSERT(activeCard->isVisible());
    //ASSERT(activeCard->attached());
    ASSERT(activeCard->layoutObject());

    // Update the document title
    doc->setTitle(activeCard->title());

    // SAMSUNG_WML_FIXES+
    // Set the active activeCard in the Document object
    static_cast<WMLDocument*>(doc)->setActiveCard(activeCard);

    // Set the active activeCard in the WMLPageState object
    //pageState->setActiveCard(activeCard);
    // SAMSUNG_WML_FIXES-
    return activeCard;
}

DEFINE_TRACE(WMLCardElement)
{
    WMLElement::trace(visitor);
}

}

#endif

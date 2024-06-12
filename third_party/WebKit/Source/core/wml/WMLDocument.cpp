/*
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
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
#include "WMLDocument.h"

#include "WMLCardElement.h"
#include "WMLErrorHandling.h"
#include "WMLInputElement.h"
#include "WMLPageState.h"
#include "WMLTemplateElement.h"
#include "core/dom/ScriptableDocumentParser.h"
#include "core/frame/Frame.h"
#include "core/page/Page.h"

namespace blink {

WMLDocument::WMLDocument(const DocumentInit& initializer)
    : XMLDocument(initializer, XMLDocumentClass | WMLDocumentClass)
    , m_activeCard(0)
    , m_intrinsicEventTimer(this, &WMLDocument::intrinsicEventTimerFired) // SAMSUNG_WML_FIXES
{
    clearXMLVersion();
}

WMLDocument::~WMLDocument()
{
}

void WMLDocument::finishedParsing()
{
    Document::finishedParsing();
    if (ScriptableDocumentParser* parser = this->scriptableDocumentParser()) {
        if (!parser->wellFormed()) {
            //Document::finishedParsing();
            return;
        }
    }

    /*bool hasAccess = */ initialize(true);
    /*
    if (!hasAccess) {
        m_activeCard = 0;

        WMLPageState* wmlPageState = wmlPageStateForDocument(this);
        if (!wmlPageState)
            return;

        Page* page = wmlPageState->page();
        if (!page)
            return;
		
        HistoryItem* item = page->backForward()->backItem();
        if (!item)
            return;
        // SAMSUNG_WML_FIXES+
        // http://spe.mobilephone.net/wit/wmlv2/strucaccess.wml
        wmlPageState->resetAccessControlData();
        // SAMSUNG_WML_FIXES-
        page->goToItem(item, FrameLoadTypeBackWMLDeckNotAccessible);
        return;
    }
*/

    //elikong, must use time todo it for solve the dead loop download
    if (m_activeCard && !m_intrinsicEventTimer.isActive())
        m_intrinsicEventTimer.startOneShot(0.0f, FROM_HERE); // SAMSUNG_WML_FIXES
    //    if (m_activeCard)
    //        m_activeCard->handleIntrinsicEventIfNeeded();
}

// SAMSUNG_WML_FIXES+
void WMLDocument::intrinsicEventTimerFired(TimerBase*)
{
    if (m_activeCard)
        m_activeCard->handleIntrinsicEventIfNeeded();

    // elikong move here for select(mulselect) die
    //Document::finishedParsing();
}
// SAMSUNG_WML_FIXES-

bool WMLDocument::initialize(bool aboutToFinishParsing)
{
    WMLPageState* wmlPageState = wmlPageStateForDocument(this);
    if (!wmlPageState || !wmlPageState->canAccessDeck())
        return false;

    // Remember that we'e successfully entered the deck
    wmlPageState->resetAccessControlData();

    // Notify the existance of templates to all cards of the current deck
    WMLTemplateElement::registerTemplatesInDocument(this);

    // Set destination card
    m_activeCard = WMLCardElement::determineActiveCard(this);
    if (!m_activeCard) {
        reportWMLError(this, WMLErrorNoCardInDocument);
        return true;
    }

    // Handle deck-level task overrides
    m_activeCard->handleDeckLevelTaskOverridesIfNeeded();

    // Handle card-level intrinsic event
    if (!aboutToFinishParsing)
        m_activeCard->handleIntrinsicEventIfNeeded();

    return true;
}

WMLPageState* wmlPageStateForDocument(Document* doc)
{
    //SAMSUNG WML FIX >>
    //ASSERT(doc);
    if (!doc)
        return 0;

    Page* page = doc->page();

    //ASSERT(page);
    if (page)
        return page->wmlPageState();

    return 0;
    //SAMSUNG WML FIX <<
}

void WMLDocument::registerInputElement(WMLInputElement* ie)
{
    size_t pos = m_inputElements.find(ie);
    if (pos == WTF::kNotFound)
        m_inputElements.append(ie);
}

void WMLDocument::degisterInputElement(WMLInputElement* ie)
{
    size_t pos = m_inputElements.find(ie);
    if (pos != WTF::kNotFound)
        m_inputElements.remove(pos);
}

DEFINE_TRACE(WMLDocument)
{
    visitor->trace(m_inputElements);
    XMLDocument::trace(visitor);
}

}

#endif

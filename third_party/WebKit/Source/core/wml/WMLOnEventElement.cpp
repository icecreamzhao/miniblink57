/**
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
#include "WMLOnEventElement.h"

#include "WMLErrorHandling.h"
#include "WMLEventHandlingElement.h"
#include "WMLIntrinsicEventHandler.h"
#include "WMLVariables.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"

namespace blink {

using namespace WMLNames;

WMLOnEventElement::WMLOnEventElement(Document& doc)
    : WMLElement(oneventTag, doc)
    , m_type(WMLIntrinsicEventUnknown)
    , m_isNoop(false) // SAMSUNG_WML_FIXES+

{
}

DEFINE_NODE_FACTORY(WMLOnEventElement)

void WMLOnEventElement::parseAttribute(const AttributeModificationParams& params)
{
    if (params.name == HTMLNames::typeAttr) {
        String parsedValue = parseValueForbiddingVariableReferences(params.newValue);
        if (parsedValue.isEmpty())
            return;

        if (parsedValue == WMLNames::onenterforwardAttr.localName())
            m_type = WMLIntrinsicEventOnEnterForward;
        else if (parsedValue == WMLNames::onenterbackwardAttr.localName())
            m_type = WMLIntrinsicEventOnEnterBackward;
        else if (parsedValue == WMLNames::ontimerAttr.localName())
            m_type = WMLIntrinsicEventOnTimer;
        else if (parsedValue == WMLNames::onpickAttr.localName())
            m_type = WMLIntrinsicEventOnPick;
    } else
        WMLElement::parseAttribute(params);
}

// SAMSUNG_WML_FIXES+
//static inline WMLEventHandlingElement* eventHandlingParent(Node* parent)
WMLEventHandlingElement* WMLOnEventElement::eventHandlingParent(Node* parent)
// SAMSUNG_WML_FIXES-
{
    if (!parent || !parent->isWMLElement())
        return 0;

    return toWMLEventHandlingElement(static_cast<WMLElement*>(parent));
}

void WMLOnEventElement::registerTask(WMLTaskElement* task)
{
    if (m_type == WMLIntrinsicEventUnknown || m_isNoop) // SAMSUNG_WML_FIXES+
        return;

    // Register intrinsic event to the event handler of the owner of onevent element
    WMLEventHandlingElement* eventHandlingElement = eventHandlingParent(parentNode());
    if (!eventHandlingElement)
        return;

    eventHandlingElement->createEventHandlerIfNeeded();

    WMLIntrinsicEvent* event = WMLIntrinsicEvent::createWithTask(task);
    if (!eventHandlingElement->eventHandler()->registerIntrinsicEvent(m_type, event))
        reportWMLError(&document(), WMLErrorConflictingEventBinding);
}

void WMLOnEventElement::deregisterTask(WMLTaskElement*)
{
    WMLEventHandlingElement* eventHandlingElement = eventHandlingParent(parentNode());
    if (!eventHandlingElement)
        return;

    eventHandlingElement->eventHandler()->deregisterIntrinsicEvent(m_type);
}

DEFINE_TRACE(WMLOnEventElement)
{
    WMLElement::trace(visitor);
}

}

#endif

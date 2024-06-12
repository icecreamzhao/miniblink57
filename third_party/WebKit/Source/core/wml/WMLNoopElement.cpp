/**
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
#include "WMLNoopElement.h"

#include "WMLDoElement.h"
#include "WMLErrorHandling.h"
#include "WMLOnEventElement.h"
#include "core/WMLNames.h"

namespace blink {

using namespace WMLNames;

WMLNoopElement::WMLNoopElement(Document& doc)
    : WMLElement(noopTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLNoopElement)

WMLNoopElement::~WMLNoopElement()
{
}

Node::InsertionNotificationRequest WMLNoopElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    ContainerNode* parent = parentNode();
    if (!parent || !parent->isWMLElement())
        return InsertionDone;

    if (hasWMLTagName(parent, (doTag))) {
        WMLDoElement* doElement = static_cast<WMLDoElement*>(parent);
        doElement->setNoop(true);
#if 0 // attach will crash when running in blink, since Element::attach -> document().styleResolver(), the styleResolver not create
        if (!doElement->needsAttach())
            doElement->detach();

        ASSERT(doElement->needsAttach());
        doElement->attach();
#endif
        // SAMSUNG_WML_FIXES+
    } else if (hasWMLTagName(parent, (oneventTag))) {
        WMLOnEventElement* onEventElement = static_cast<WMLOnEventElement*>(parent);
        WMLIntrinsicEventType eventType = onEventElement->eventType();

        onEventElement->setNoop(true);

        if (eventType != WMLIntrinsicEventUnknown) {
            WMLEventHandlingElement* eventHandlingElement = WMLOnEventElement::eventHandlingParent(onEventElement->parentNode());
            if (!eventHandlingElement)
                return InsertionDone;

            WMLIntrinsicEventHandler* eventHandler = eventHandlingElement->eventHandler();
            if (!eventHandler)
                return InsertionDone;

            eventHandler->deregisterIntrinsicEvent(eventType);
        }
        // SAMSUNG_WML_FIXES-
    } else if (hasWMLTagName(parent, (anchorTag)))
        reportWMLError(&document(), WMLErrorForbiddenTaskInAnchorElement);

    return InsertionDone;
}

DEFINE_TRACE(WMLNoopElement)
{
    WMLElement::trace(visitor);
}

}

#endif

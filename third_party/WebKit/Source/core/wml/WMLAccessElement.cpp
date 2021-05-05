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
#include "WMLAccessElement.h"

#include "WMLDocument.h"
#include "WMLNames.h"
#include "WMLVariables.h"
#include "core/dom/Attribute.h"

namespace blink {

using namespace WMLNames;

WMLAccessElement::WMLAccessElement(Document& doc)
    : WMLElement(accessTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLAccessElement)

void WMLAccessElement::parseAttribute(const AttributeModificationParams& params)
{
    if (params.name == domainAttr) {
        String biddingVariableReferencesValue = parseValueForbiddingVariableReferences(params.newValue);
        if (biddingVariableReferencesValue.isEmpty())
            return;

        m_domain = biddingVariableReferencesValue;
    } else if (params.name == pathAttr) {
        String biddingVariableReferencesValue = parseValueForbiddingVariableReferences(params.newValue);
        if (biddingVariableReferencesValue.isEmpty())
            return;

        m_path = biddingVariableReferencesValue;
    } else
        WMLElement::parseAttribute(params);
}

Node::InsertionNotificationRequest WMLAccessElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    WMLPageState* pageState = wmlPageStateForDocument(&document());
    if (!pageState || pageState->processAccessControlData(m_domain, m_path))
        return InsertionDone;

    pageState->resetAccessControlData();
    reportWMLError(&document(), WMLErrorMultipleAccessElements);

    return InsertionDone;
}

DEFINE_TRACE(WMLAccessElement)
{
    WMLElement::trace(visitor);
}

}

#endif

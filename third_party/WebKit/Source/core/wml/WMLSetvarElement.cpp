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
#include "WMLSetvarElement.h"

#include "WMLErrorHandling.h"
#include "WMLTaskElement.h"
#include "WMLVariables.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"

namespace blink {

WMLSetvarElement::WMLSetvarElement(Document& doc)
    : WMLElement(WMLNames::setvarTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLSetvarElement)

WMLSetvarElement::~WMLSetvarElement()
{
}

void WMLSetvarElement::parseAttribute(const AttributeModificationParams& params)
{
    if (params.name == HTMLNames::nameAttr) {
        if (!isValidVariableName(parseValueSubstitutingVariableReferences(params.newValue, WMLErrorInvalidVariableName))) {
            reportWMLError(&document(), WMLErrorInvalidVariableName);
            return;
        }
    } else
        WMLElement::parseAttribute(params);
}

Node::InsertionNotificationRequest WMLSetvarElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    ContainerNode* parent = parentNode();
    if (!parent || !parent->isWMLElement())
        return InsertionDone;

    if (static_cast<WMLElement*>(parent)->isWMLTaskElement())
        static_cast<WMLTaskElement*>(parent)->registerVariableSetter(this);

    return InsertionDone;
}

void WMLSetvarElement::removedFrom(ContainerNode* node)
{
    ContainerNode* parent = parentNode();
    if (parent && parent->isWMLElement()) {
        if (static_cast<WMLElement*>(parent)->isWMLTaskElement())
            static_cast<WMLTaskElement*>(parent)->deregisterVariableSetter(this);
    }

    WMLElement::removedFrom(node);
}

String WMLSetvarElement::name() const
{
    return parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::nameAttr), WMLErrorInvalidVariableName);
}

String WMLSetvarElement::value() const
{
    return parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::valueAttr));
}

DEFINE_TRACE(WMLSetvarElement)
{
    WMLElement::trace(visitor);
}

}

#endif

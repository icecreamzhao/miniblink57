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
#include "WMLFieldSetElement.h"

#include "core/HTMLNames.h"
#include "core/WMLElementFactory.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"
#include "core/dom/Text.h"
#include "core/layout/LayoutFieldset.h"

namespace blink {

using namespace WMLNames;

WMLFieldSetElement::WMLFieldSetElement(Document& doc)
    : WMLElement(fieldsetTag, doc)
    , m_insertedLegendElement(nullptr)
{
}

DEFINE_NODE_FACTORY(WMLFieldSetElement)

WMLFieldSetElement::~WMLFieldSetElement()
{
}

Node::InsertionNotificationRequest WMLFieldSetElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    String title = parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::titleAttr));
    if (title.isEmpty())
        return InsertionDone;

    m_insertedLegendElement = WMLElementFactory::createWMLElement(insertedLegendTag.localName(), document());

    // Insert <dummyLegend> element, as RenderFieldset expect it to be present
    // to layout it's child text content, when rendering <fieldset> elements
    //ExceptionCode ec = 0;
    appendChild(m_insertedLegendElement);
    //ASSERT(ec == 0);

    // Create text node holding the 'title' attribute value
    m_insertedLegendElement->appendChild(document().createTextNode(title));
    //ASSERT(ec == 0);

    return InsertionDone;
}

void WMLFieldSetElement::removedFrom(ContainerNode* node)
{
    m_insertedLegendElement.clear();
    WMLElement::removedFrom(node);
}

LayoutObject* WMLFieldSetElement::createLayoutObject(const ComputedStyle&)
{
    return new LayoutFieldset(this);
}

DEFINE_TRACE(WMLFieldSetElement)
{
    visitor->trace(m_insertedLegendElement);
    WMLElement::trace(visitor);
}

}

#endif

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
#include "WMLMetaElement.h"

#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Document.h"
#include "core/loader/HttpEquiv.h"

namespace blink {

WMLMetaElement::WMLMetaElement(Document& doc)
    : WMLElement(WMLNames::metaTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLMetaElement)

WMLMetaElement::~WMLMetaElement()
{
}

void WMLMetaElement::parseAttribute(const AttributeModificationParams& params)
{
    if (params.name == HTMLNames::http_equivAttr)
        m_equiv = parseValueForbiddingVariableReferences(params.newValue);
    else if (params.name == HTMLNames::contentAttr)
        m_content = parseValueForbiddingVariableReferences(params.newValue);
    else if (params.name == HTMLNames::nameAttr) {
        // FIXME: The user agent must ignore any meta-data named with this attribute.
    } else
        WMLElement::parseAttribute(params);
}

static bool inWMLDocumentHead(WMLMetaElement* element)
{
    //     if (!element->isConnected())
    //         return false;
    //
    //     return Traversal<HTMLHeadElement>::firstAncestor(*element);
    return false;
}

Node::InsertionNotificationRequest WMLMetaElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    if (m_equiv.isNull() || m_content.isNull())
        return InsertionDone;

    // TODO
    //document().processHttpEquiv(WTF::AtomicString(m_equiv), WTF::AtomicString(m_content), true);

    const AtomicString& httpEquivValue = fastGetAttribute(HTMLNames::http_equivAttr);
    if (httpEquivValue.isEmpty())
        return InsertionDone;

    const AtomicString& contentValue = fastGetAttribute(HTMLNames::contentAttr);
    if (contentValue.isNull())
        return InsertionDone;

    HttpEquiv::process(document(), httpEquivValue, contentValue, inWMLDocumentHead(this), this);

    return InsertionDone;
}

DEFINE_TRACE(WMLMetaElement)
{
    WMLElement::trace(visitor);
}

}

#endif

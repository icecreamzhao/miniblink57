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
#include "WMLPostfieldElement.h"

#include "WMLDocument.h"
#include "WMLGoElement.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include <wtf/text/CString.h>
#include <wtf/text/TextEncoding.h>

namespace blink {

using namespace WMLNames;

WMLPostfieldElement::WMLPostfieldElement(Document& doc)
    : WMLElement(postfieldTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLPostfieldElement)

Node::InsertionNotificationRequest WMLPostfieldElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    ContainerNode* parent = parentNode();
    if (parent && hasWMLTagName(parent, goTag))
        static_cast<WMLGoElement*>(parent)->registerPostfieldElement(this);

    return InsertionDone;
}

void WMLPostfieldElement::removedFrom(ContainerNode* node)
{
    ContainerNode* parent = parentNode();
    if (parent && hasWMLTagName(parent, goTag))
        static_cast<WMLGoElement*>(parent)->deregisterPostfieldElement(this);

    WMLElement::removedFrom(node);
}

String WMLPostfieldElement::name() const
{
    return parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::nameAttr));
}

String WMLPostfieldElement::value() const
{
    return parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::valueAttr));
}

static inline CString encodedString(const WTF::TextEncoding& encoding, const String& data)
{
    return encoding.encode(data, WTF::EntitiesForUnencodables);
}

void WMLPostfieldElement::encodeData(const WTF::TextEncoding& encoding, CString& name, CString& value)
{
    name = encodedString(encoding, this->name());
    value = encodedString(encoding, this->value());
}

DEFINE_TRACE(WMLPostfieldElement)
{
    WMLElement::trace(visitor);
}

}

#endif

/**
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 *
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Simon Hausmann <hausmann@kde.org>
 * Copyright (C) 2003, 2006 Apple Computer, Inc.
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
#include "WMLBRElement.h"

#include "core/CSSPropertyNames.h"
#include "core/CSSValueKeywords.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/css/StylePropertySet.h"
#include "core/dom/Attribute.h"
#include "core/layout/LayoutBR.h"

namespace blink {

WMLBRElement::WMLBRElement(Document& doc)
    : WMLElement(WMLNames::brTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLBRElement)

//hurleyzhang comment it ,because it should not set AttributeStyle Dirty here, it's attribute parsed by base class's function.
//otherwise,may lead to infinite loop.

bool WMLBRElement::isPresentationAttribute(const QualifiedName& name) const
{
    if (name == HTMLNames::clearAttr)
        return true;
    return WMLElement::isPresentationAttribute(name);
}

void WMLBRElement::collectStyleForPresentationAttribute(const QualifiedName& name, const AtomicString& value, MutableStylePropertySet* style)
{
    if (name == HTMLNames::clearAttr) {
        // If the string is empty, then don't add the clear property.
        // <br clear> and <br clear=""> are just treated like <br> by Gecko, Mac IE, etc. -dwh
        if (value.isEmpty())
            return;

        if (equalIgnoringCase(value, "all"))
            addPropertyToAttributeStyle(style, CSSPropertyClear, CSSValueBoth);
        else
            addPropertyToAttributeStyle(style, CSSPropertyClear, value);
    }
}

LayoutObject* WMLBRElement::createLayoutObject(const ComputedStyle&)
{
    return new LayoutBR(this);
}

DEFINE_TRACE(WMLBRElement)
{
    WMLElement::trace(visitor);
}

}

#endif

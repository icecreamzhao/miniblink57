/**
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 *
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
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
#include "WMLPElement.h"

#include "core/CSSPropertyNames.h"
#include "core/CSSValueKeywords.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"
#include "core/dom/Document.h"
#include "core/dom/TagCollection.h"

namespace blink {

using namespace WMLNames;

WMLPElement::WMLPElement(Document& doc)
    : WMLElement(pTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLPElement)

void WMLPElement::parseAttribute(const AttributeModificationParams& params)
{
    //totrit: call of 'setAttributeStyleDirty' is necessary, will provoke calling 'collectStyleForAttribute' indirectly.
    //setAttributeStyleDirty();
    WMLElement::parseAttribute(params);
}

void WMLPElement::collectStyleForPresentationAttribute(const QualifiedName& name, const AtomicString& value, MutableStylePropertySet* style)
{
    if (name == HTMLNames::alignAttr) {
        if (equalIgnoringCase(value, "middle") || equalIgnoringCase(value, "center"))
            addPropertyToAttributeStyle(style, CSSPropertyTextAlign, CSSValueWebkitCenter);
        else if (equalIgnoringCase(value, "left"))
            addPropertyToAttributeStyle(style, CSSPropertyTextAlign, CSSValueWebkitLeft);
        else if (equalIgnoringCase(value, "right"))
            addPropertyToAttributeStyle(style, CSSPropertyTextAlign, CSSValueWebkitRight);
        else
            addPropertyToAttributeStyle(style, CSSPropertyTextAlign, value);
    } else if (name == modeAttr) {
        m_mode = value;
        if (m_mode == "wrap")
            addPropertyToAttributeStyle(style, CSSPropertyWordWrap, CSSValueBreakWord);
        else if (m_mode == "nowrap")
            addPropertyToAttributeStyle(style, CSSPropertyWhiteSpace, CSSValueNowrap);
    }
}

Node::InsertionNotificationRequest WMLPElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    // If not explicitly specified, the linewrap mode is identical to
    // the line-wrap mode of the previous paragraph in the text flow of
    // a card. The default mode for the first paragraph in a card is wrap.
    if (!m_mode.isEmpty())
        return InsertionDone;

    TagCollection* nodeList = document().getElementsByTagName("p");
    if (!nodeList)
        return InsertionDone;

    unsigned length = nodeList->length();
    if (length < 2)
        return InsertionDone;

    // Assure we're the last inserted paragraph element
    // This only works while parsing, otherwhise this statement is never true.
    if (nodeList->item(length - 1) != this)
        return InsertionDone;

    WMLPElement* lastParagraph = static_cast<WMLPElement*>(nodeList->item(length - 2));
    ASSERT(lastParagraph);

    String lastMode = lastParagraph->getAttribute(modeAttr);
    if (lastMode.isEmpty() || lastMode == "wrap") // Default value, do nothing.
        return InsertionDone;

    setAttribute(modeAttr, WTF::AtomicString(lastMode));

    return InsertionDone;
}

DEFINE_TRACE(WMLPElement)
{
    WMLElement::trace(visitor);
}

}

#endif

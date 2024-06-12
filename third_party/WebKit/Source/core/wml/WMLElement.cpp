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
#include "WMLElement.h"

#include "WMLErrorHandling.h"
#include "WMLVariables.h"
#include "core/CSSPropertyNames.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/css/StylePropertySet.h"
#include "core/dom/Attribute.h"
#include "core/dom/Document.h"
#include "core/html/parser/HTMLParserIdioms.h"
#include "core/layout/LayoutObject.h"

using std::max;
using std::min;

namespace blink {

using namespace WMLNames;

WMLElement::WMLElement(const QualifiedName& tagName, Document& document)
    : Element(tagName, &document, CreateElement)
{
}

WMLElement* WMLElement::create(const QualifiedName& tagName, Document& document)
{
    return new WMLElement(tagName, document);
}

//bool WMLElement::mapToEntry(const QualifiedName& attrName, MappedAttributeEntry& result) const
//{
//	//TODO update to 112327
//	//In 112327, base class StyleElement has removed 'mapToEntry' method
//	//so here, just disable it to make compile pass
//	/*
//    if (attrName == HTMLNames::alignAttr) {
//        result = eUniversal;
//        return false;
//    }
//
//    return StyledElement::mapToEntry(attrName, result);
//	 */
//	return false;
//}

bool WMLElement::isPresentationAttribute(const QualifiedName& name) const
{
    //if (name == HTMLNames::alignAttr || name == HTMLNames::contenteditableAttr || name == HTMLNames::hiddenAttr || name == HTMLNames::langAttr || name.matches(XMLNames::langAttr) || name == HTMLNames::draggableAttr || name == HTMLNames::dirAttr)
    //    return true;
    return Element::isPresentationAttribute(name);
}

inline bool isIdAttributeName(const QualifiedName& attributeName)
{
    // FIXME: This check is probably not correct for the case where the document has an id attribute
    // with a non-null namespace, because it will return false, a false negative, if the prefixes
    // don't match but the local name and namespace both do. However, since this has been like this
    // for a while and the code paths may be hot, we'll have to measure performance if we fix it.
    return attributeName == HTMLNames::idAttr;
}

void WMLElement::parseAttribute(const AttributeModificationParams& params)
{
    if (isIdAttributeName(params.name)
        || params.name == HTMLNames::classAttr
        || params.name == HTMLNames::styleAttr)
        return Element::parseAttribute(params);

    /*if (attr->name() == HTMLNames::alignAttr) {
        if (equalIgnoringCase(attr->value(), "middle"))
            addCSSProperty(attr, CSSPropertyTextAlign, "center");
        else
            addCSSProperty(attr, CSSPropertyTextAlign, attr->value());
    } else */
    if (params.name == HTMLNames::tabindexAttr) {
        //         String indexstring = params.newValue;
        //         int tabindex = 0;
        //         if (parseHTMLInteger(indexstring, tabindex)) {
        //             // Clamp tabindex to the range of 'short' to match Firefox's behavior.
        //             setTabIndexExplicitly(std::max(static_cast<int>(std::numeric_limits<short>::min()), std::min(tabindex, static_cast<int>(std::numeric_limits<short>::max()))));
        //         }
        setTabIndexExplicitly();
    } else
        Element::parseAttribute(params);
}

String WMLElement::title() const
{
    return parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::titleAttr));
}

bool WMLElement::layoutObjectIsNeeded(const ComputedStyle& style)
{
    return document().documentElement() == this || style.display() != EDisplay::None;
}

LayoutObject* WMLElement::createLayoutObject(const ComputedStyle& style)
{
    return Element::createLayoutObject(style);
}

String WMLElement::parseValueSubstitutingVariableReferencesHelp(Document* document, const AtomicString& value, WMLErrorCode defaultErrorCode)
{
    bool isValid = false;
    if (!containsVariableReference(value, isValid))
        return value;

    if (!isValid) {
        reportWMLError(document, defaultErrorCode);
        return String();
    }

    return substituteVariableReferences(value, document);
}

String WMLElement::parseValueSubstitutingVariableReferences(const AtomicString& value, WMLErrorCode defaultErrorCode) const
{
    return parseValueSubstitutingVariableReferencesHelp(&document(), value, defaultErrorCode);
}

String WMLElement::parseValueForbiddingVariableReferences(const AtomicString& value) const
{
    bool isValid = false;
    if (containsVariableReference(value, isValid)) {
        reportWMLError(&document(), WMLErrorInvalidVariableReferenceLocation);
        return String();
    }

    return value;
}

void WMLElement::addPropertyToAttributeStyle(MutableStylePropertySet* style, CSSPropertyID propertyID, const String& value)
{
    style->setProperty(propertyID, value, false, document().elementSheet().contents());
}

void WMLElement::addPropertyToAttributeStyle(MutableStylePropertySet* style, CSSPropertyID propertyID, CSSValueID value)
{
    style->setProperty(propertyID, value, false);
}

void WMLElement::addWMLLengthToStyle(MutableStylePropertySet* style, CSSPropertyID propertyID, const String& value)
{
    // FIXME: This function should not spin up the CSS parser, but should instead just figure out the correct
    // length unit and make the appropriate parsed value.

    // strip attribute garbage..
    StringImpl* v = value.impl();
    if (v) {
        unsigned int l = 0;

        while (l < v->length() && (*v)[l] <= ' ')
            l++;

        for (; l < v->length(); l++) {
            UChar cc = (*v)[l];
            if (cc > '9')
                break;
            if (cc < '0') {
                if (cc == '%' || cc == '*')
                    l++;
                if (cc != '.')
                    break;
            }
        }

        if (l != v->length()) {
            addPropertyToAttributeStyle(style, propertyID, v->substring(0, l));
            return;
        }
    }

    addPropertyToAttributeStyle(style, propertyID, value);
}

DEFINE_TRACE(WMLElement)
{
    Element::trace(visitor);
}

bool isWMLImageElement(const Element& element)
{
    return element.isWMLElement() && element.hasLocalName((WMLNames::imgTag).localName());
}

}

#endif

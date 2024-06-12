/*
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

#ifndef WMLElement_h
#define WMLElement_h

#if ENABLE_WML

#include "WMLErrorHandling.h"
#include "WMLNames.h"
#include "core/css/CSSValue.h"
#include "core/dom/Element.h"

//TODO update to 112327
//In 112327 'MappedAttributeEntry.h' is removed, and StyledElement's mapToEntry virtual method also
//remove, however, our WML will use it. So, restore the 'MappedAttributeEntry.h' and include it ourself
//Here I do this, just for compiling pass.
//#include "MappedAttributeEntry.h"

namespace blink {

class MutableStylePropertySet;

class WMLElement : public Element {
public:
    static WMLElement* create(const QualifiedName& tagName, Document&);

    virtual bool isWMLElement() const override { return true; }
    virtual bool isWMLTaskElement() const { return false; }

    //virtual bool mapToEntry(const QualifiedName& attrName, MappedAttributeEntry& result) const;
    virtual void parseAttribute(const AttributeModificationParams& params) override;

    virtual String title() const;

    virtual bool layoutObjectIsNeeded(const ComputedStyle& style) override;
    virtual LayoutObject* createLayoutObject(const ComputedStyle& style) override;

    virtual bool isPresentationAttribute(const QualifiedName& name) const override;

    void addWMLLengthToStyle(MutableStylePropertySet*, CSSPropertyID propertyID, const String& value);
    void addPropertyToAttributeStyle(MutableStylePropertySet* style, CSSPropertyID propertyID, const String& value);
    void addPropertyToAttributeStyle(MutableStylePropertySet* style, CSSPropertyID propertyID, CSSValueID value);

    static String parseValueSubstitutingVariableReferencesHelp(Document*, const AtomicString&, WMLErrorCode defaultErrorCode = WMLErrorInvalidVariableReference);

    DECLARE_VIRTUAL_TRACE();

protected:
    WMLElement(const QualifiedName& tagName, Document&);

    // Helper function for derived classes
    String parseValueSubstitutingVariableReferences(const AtomicString&, WMLErrorCode defaultErrorCode = WMLErrorInvalidVariableReference) const;
    String parseValueForbiddingVariableReferences(const AtomicString&) const;
};

bool isWMLImageElement(const Element& element);
DEFINE_ELEMENT_TYPE_CASTS(WMLElement, isWMLElement());

inline bool hasWMLTagName(const Node* node, const WMLQualifiedName& name)
{
    return node->isWMLElement() && ((WMLElement*)node)->hasLocalName(name.localName());
}

}

#endif
#endif

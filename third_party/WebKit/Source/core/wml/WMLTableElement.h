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

#ifndef WMLTableElement_h
#define WMLTableElement_h

#if ENABLE_WML
#include "WMLElement.h"

namespace blink {

class HTMLCollection;

class WMLTableElement : public WMLElement {
public:
    DECLARE_NODE_FACTORY(WMLTableElement);

    WMLTableElement(Document&);
    virtual ~WMLTableElement() override;

    virtual void parseAttribute(const AttributeModificationParams& params) override;

    virtual void finishParsingChildren() override;

    DECLARE_VIRTUAL_TRACE();

private:
    HeapVector<Member<WMLElement>> scanTableChildElements(WMLElement* startElement, const WMLQualifiedName& tagName) const;

    bool tryMergeAdjacentTextCells(Node* item, Node* nextItem) const;
    void transferAllChildrenOfElementToTargetElement(WMLElement* sourceElement, WMLElement* targetElement, unsigned startOffset) const;
    void joinSuperflousColumns(HeapVector<Member<WMLElement>>& columnElements, WMLElement* rowElement) const;
    void padWithEmptyColumns(HeapVector<Member<WMLElement>>& columnElements, WMLElement* rowElement) const;
    void alignCells(HeapVector<Member<WMLElement>>& columnElements, WMLElement* rowElement) const;

    unsigned m_columns;
    String m_alignment;
};

}

#endif
#endif

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

#ifndef WMLFieldSetElement_h
#define WMLFieldSetElement_h

#if ENABLE_WML
#include "WMLElement.h"

namespace blink {

class WMLFieldSetElement : public WMLElement {
public:
    DECLARE_NODE_FACTORY(WMLFieldSetElement);

    WMLFieldSetElement(Document&);
    virtual ~WMLFieldSetElement();

    virtual Node::InsertionNotificationRequest insertedInto(ContainerNode* node) override;
    virtual void removedFrom(ContainerNode* node) override;

    virtual LayoutObject* createLayoutObject(const ComputedStyle&) override;

    DECLARE_VIRTUAL_TRACE();

private:
    Member<WMLElement> m_insertedLegendElement;
};

}

#endif
#endif

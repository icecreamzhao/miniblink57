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

#ifndef WMLSetvarElement_h
#define WMLSetvarElement_h

#if ENABLE_WML
#include "WMLElement.h"

namespace blink {

class WMLSetvarElement : public WMLElement {
public:
    DECLARE_NODE_FACTORY(WMLSetvarElement);

    WMLSetvarElement(Document&);
    virtual ~WMLSetvarElement();

    virtual void parseAttribute(const AttributeModificationParams& params) override;

    virtual Node::InsertionNotificationRequest insertedInto(ContainerNode* node) override;
    virtual void removedFrom(ContainerNode* node) override;

    String name() const;
    String value() const;

    DECLARE_VIRTUAL_TRACE();
};

}

#endif
#endif

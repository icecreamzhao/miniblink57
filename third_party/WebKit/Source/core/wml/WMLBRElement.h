/**
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 *
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Simon Hausmann <hausmann@kde.org>
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

#ifndef WMLBRElement_h
#define WMLBRElement_h

#if ENABLE_WML
#include "WMLElement.h"

namespace blink {

class WMLBRElement : public WMLElement {
public:
    DECLARE_NODE_FACTORY(WMLBRElement);

    WMLBRElement(Document&);
    virtual void collectStyleForPresentationAttribute(const QualifiedName& name, const AtomicString& value, MutableStylePropertySet* style) override;
    virtual bool isPresentationAttribute(const QualifiedName& name) const override;

    virtual LayoutObject* createLayoutObject(const ComputedStyle&) override;

    DECLARE_VIRTUAL_TRACE();
};

}

#endif
#endif

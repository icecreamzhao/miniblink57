/**
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 *
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Simon Hausmann <hausmann@kde.org>
 * Copyright (C) 2007, 2008 Apple Inc. All rights reserved.
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

#ifndef WMLAElement_h
#define WMLAElement_h

#if ENABLE_WML
#include "WMLElement.h"
#include "platform/LinkHash.h"

namespace blink {
class KURL;

class WMLAElement : public WMLElement {
public:
    DECLARE_NODE_FACTORY(WMLAElement);

    WMLAElement(Document&);
    WMLAElement(const QualifiedName& tagName, Document&);

    virtual bool supportsFocus() const override;
    virtual bool isMouseFocusable() const override;
    virtual bool isKeyboardFocusable() const override;

    virtual void parseAttribute(const AttributeModificationParams& params) override;
    virtual void defaultEventHandler(Event*) override;

    virtual void accessKeyAction(bool fullAction) override;
    virtual bool isURLAttribute(const Attribute&) const override;

    /*virtual*/ String target() const;

    /*virtual*/ KURL href() const;

    LinkHash visitedLinkHash() const;
    void invalidateCachedVisitedLinkHash() { m_cachedVisitedLinkHash = 0; }

    DECLARE_VIRTUAL_TRACE();

private:
    mutable LinkHash m_cachedVisitedLinkHash;
};

bool isWMLAOrAnchorElement(const Element& element);
#define toWMLAElement(x) blink::toElement<blink::WMLAElement>(x)
//template <> inline bool isElementOfType<const WMLAElement>(const Element& element) { return isWMLAOrAnchorElement(element); }

}

#endif
#endif

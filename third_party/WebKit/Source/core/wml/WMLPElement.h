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

#ifndef WMLPElement_h
#define WMLPElement_h

#if ENABLE_WML
#include "WMLElement.h"
#ifdef TENCENT_CHANGES
#include "WMLEventHandlingElement.h" // add by harry guo. support do tag that's in p tag
#endif // TENCENT_CHANGES

namespace blink {

#ifdef TENCENT_CHANGES
class WMLPElement : public WMLElement, public WMLEventHandlingElement { // modified by harry guo. support do tag that's in p tag
#else
class WMLPElement : public WMLElement {
#endif // TENCENT_CHANGES
public:
    DECLARE_NODE_FACTORY(WMLPElement);

    WMLPElement(Document&);

    virtual void parseAttribute(const AttributeModificationParams& params) override;

    virtual void collectStyleForPresentationAttribute(const QualifiedName&, const AtomicString&, MutableStylePropertySet*) override;

    virtual Node::InsertionNotificationRequest insertedInto(ContainerNode* node) override;

    DECLARE_VIRTUAL_TRACE();

private:
    String m_mode;
};

}

#endif
#endif

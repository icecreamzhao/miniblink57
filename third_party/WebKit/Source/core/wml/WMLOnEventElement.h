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

#ifndef WMLOnEventElement_h
#define WMLOnEventElement_h

#if ENABLE_WML
#include "WMLElement.h"
#include "WMLIntrinsicEventHandler.h"

namespace blink {

class WMLTaskElement;
class WMLEventHandlingElement; // SAMSUNG_WML_FIXES+

class WMLOnEventElement : public WMLElement {
public:
    DECLARE_NODE_FACTORY(WMLOnEventElement);

    WMLOnEventElement(Document&);

    virtual void parseAttribute(const AttributeModificationParams& params) override;

    void registerTask(WMLTaskElement*);
    void deregisterTask(WMLTaskElement*);

    // SAMSUNG_WML_FIXES+
    static WMLEventHandlingElement* eventHandlingParent(Node* parent);

    void setNoop(bool noop) { m_isNoop = noop; }
    bool isNoop() const { return m_isNoop; }

    WMLIntrinsicEventType eventType() const { return m_type; }
    // SAMSUNG_WML_FIXES-

    DECLARE_VIRTUAL_TRACE();

private:
    WMLIntrinsicEventType m_type;
    bool m_isNoop; // SAMSUNG_WML_FIXES+
};

}

#endif
#endif

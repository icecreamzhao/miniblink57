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

#ifndef WMLTaskElement_h
#define WMLTaskElement_h

#if ENABLE_WML
#include "WMLElement.h"

#include <wtf/Vector.h>

namespace blink {

class WMLPageState;
class WMLSetvarElement;

class WMLTaskElement : public WMLElement {
public:
    virtual bool isWMLTaskElement() const override { return true; }

    virtual Node::InsertionNotificationRequest insertedInto(ContainerNode* node) override;
    virtual void removedFrom(ContainerNode* node) override;

    virtual void executeTask() = 0;

    void registerVariableSetter(WMLSetvarElement*);
    void deregisterVariableSetter(WMLSetvarElement*);

    DECLARE_VIRTUAL_TRACE();

protected:
    WMLTaskElement(const QualifiedName& tagName, Document&);
    virtual ~WMLTaskElement();

    void storeVariableState(WMLPageState*);

private:
    HeapVector<Member<WMLSetvarElement>> m_variableSetterElements;
};

}

#endif
#endif

/**
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

#ifndef WMLEventHandlingElement_h
#define WMLEventHandlingElement_h

#if ENABLE_WML
#include "WMLIntrinsicEventHandler.h"

#include <wtf/PtrUtil.h>
#include <wtf/Vector.h>

namespace blink {

class WMLElement;
class WMLDoElement;

class WMLEventHandlingElement {
public:
    WMLEventHandlingElement();
    ~WMLEventHandlingElement();

    WMLIntrinsicEventHandler* eventHandler() const { return m_eventHandler.get(); }
    void createEventHandlerIfNeeded();

    HeapVector<Member<WMLDoElement>>& doElements() { return m_doElements; }
    void registerDoElement(WMLDoElement*, Document*);
    void deregisterDoElement(WMLDoElement*);

    DECLARE_VIRTUAL_TRACE();

private:
    Member<WMLIntrinsicEventHandler> m_eventHandler;
    HeapVector<Member<WMLDoElement>> m_doElements;
};

WMLEventHandlingElement* toWMLEventHandlingElement(WMLElement*);

}

#endif
#endif

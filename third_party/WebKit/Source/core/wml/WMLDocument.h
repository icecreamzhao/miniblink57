/*
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

#ifndef WMLDocument_h
#define WMLDocument_h

#if ENABLE_WML
#include "WMLErrorHandling.h"
#include "WMLPageState.h"
#include "core/dom/XMLDocument.h"
#include "platform/Timer.h"

namespace blink {

class WMLCardElement;

class WMLDocument : public XMLDocument {
public:
    static WMLDocument* create(const DocumentInit& initializer = DocumentInit())
    {
        return new WMLDocument(initializer);
    }

    virtual ~WMLDocument();

    //virtual bool isWMLDocument() const override { return true; }
    virtual void finishedParsing() override;

    //virtual void defaultEventHandler(Event*) OVERRIDE;

    bool initialize(bool aboutToFinishParsing = false);

    // SAMSUNG_WML_FIXES+
    void intrinsicEventTimerFired(TimerBase*);
    void setActiveCard(WMLCardElement* card) { m_activeCard = card; }
    // SAMSUNG_WML_FIXES-
    WMLCardElement* activeCard() const { return m_activeCard; }
    //totrit: manage input-elements.
    void registerInputElement(WMLInputElement* ie);
    void degisterInputElement(WMLInputElement* ie);

    DECLARE_VIRTUAL_TRACE();

private:
    WMLDocument(const DocumentInit& initializer);
    WMLCardElement* m_activeCard;
    // SAMSUNG_WML_FIXES+
    Timer<WMLDocument> m_intrinsicEventTimer;
    // SAMSUNG_WML_FIXES-
    friend class WMLPageState;
    //Vector<WMLInputElement*> m_inputElements;
    HeapVector<Member<WMLInputElement>> m_inputElements;
};

WMLPageState* wmlPageStateForDocument(Document*);

}

#endif
#endif

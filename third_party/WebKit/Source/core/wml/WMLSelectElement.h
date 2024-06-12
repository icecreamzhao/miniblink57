/**
 * Copyright (C) 2009 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
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

#ifndef WMLSelectElement_h
#define WMLSelectElement_h

#if ENABLE_WML

#include "core/html/HTMLSelectElement.h"
#include "wtf/PassRefPtr.h"

namespace blink {

class WMLSelectElement : public HTMLSelectElement {
public:
    DECLARE_NODE_FACTORY(WMLSelectElement);

    WMLSelectElement(Document& document)
        : HTMLSelectElement(document)
    {
    }

    bool multiple() const;
    int optionToListIndex(int optionIndex) const;

    void selectInitialOptions();
    void initializeVariables();
    void calculateDefaultOptionIndices();
    Vector<unsigned> parseIndexValueString(const String& indexValue) const;
    Vector<unsigned> valueStringToOptionIndices(const String& value) const;
    String optionIndicesToValueString() const;
    String optionIndicesToString() const;
    void updateVariables();

    DECLARE_VIRTUAL_TRACE();

private:
    AtomicString m_name; //SAMSUNG_WML_FIX
    Vector<unsigned> m_defaultOptionIndices;
};

WMLSelectElement* toWMLSelectElement(Element* element);
bool isWMLSelectElement(Element* element);

};

#endif
#endif

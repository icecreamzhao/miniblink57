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

#include "config.h"

#if ENABLE_WML

#include "core/WMLNames.h"
#include "core/wml/WMLDocument.h"
#include "core/wml/WMLElement.h"
#include "core/wml/WMLOptionElement.h"
#include "core/wml/WMLPageState.h"
#include "core/wml/WMLSelectElement.h"

namespace blink {

DEFINE_NODE_FACTORY(WMLSelectElement)

WMLSelectElement* toWMLSelectElement(Element* element)
{
    if (element->isHTMLElement() && element->hasTagName(HTMLNames::selectTag))
        return static_cast<WMLSelectElement*>(element);

    //     if (element->isWMLElement() && element->hasTagName(WMLNames::selectTag))
    //         return static_cast<WMLSelectElement*>(element);

    return 0;
}

bool isWMLSelectElement(Element* element)
{
    return element->hasLocalName((HTMLNames::selectTag).localName());
}

bool WMLSelectElement::multiple() const
{
    return fastHasAttribute(HTMLNames::multipleAttr);
}

int WMLSelectElement::optionToListIndex(int optionIndex) const
{
    const ListItems& items = listItems();
    int listSize = static_cast<int>(items.size());
    if (optionIndex < 0 || optionIndex >= listSize)
        return -1;

    int optionIndex2 = -1;
    for (int listIndex = 0; listIndex < listSize; ++listIndex) {
        if (isHTMLOptionElement(*items[listIndex])) {
            ++optionIndex2;
            if (optionIndex2 == optionIndex)
                return listIndex;
        }
    }

    return -1;
}

void WMLSelectElement::selectInitialOptions()
{
    m_defaultOptionIndices.clear();

    // Spec: Step 1 - the default option index is determined using iname and ivalue
    calculateDefaultOptionIndices();

    if (m_defaultOptionIndices.isEmpty())
        return;

    // Spec: Step 2 initialise variables
    initializeVariables();

    // Spec: Step 3 pre-select option(s) specified by the default option index
    // ingrone
    updateVariables();
}

void WMLSelectElement::initializeVariables()
{
    ASSERT(!m_defaultOptionIndices.isEmpty());
    if (m_defaultOptionIndices.isEmpty())
        return;

    WMLPageState* pageState = wmlPageStateForDocument(&document());
    if (!pageState)
        return;

    const ListItems& items = listItems();
    if (items.isEmpty())
        return;

    String name = this->name();
    if (name.isEmpty())
        return;

    if (multiple()) {
        // Spec: If the 'name' attribute is specified and the select is a multiple-choice element,
        // then for each index greater than zero, the value of the 'value' attribute on the option
        // element at the index is added to the name variable.
        pageState->storeVariable(name, optionIndicesToValueString());
        return;
    }

    // Spec: If the 'name' attribute is specified and the select is a single-choice element,
    // then the named variable is set with the value of the 'value' attribute on the option
    // element at the default option index.
    unsigned optionIndex = m_defaultOptionIndices.at(0);
    ASSERT(optionIndex >= 1);

    int listIndex = optionToListIndex(optionIndex - 1);
    ASSERT(listIndex >= 0);
    ASSERT(listIndex < (int)items.size());

    if (WMLOptionElement* WMLOptionElement = toWMLOptionElement(items[listIndex]))
        pageState->storeVariable(name, WMLOptionElement->value());
}

void WMLSelectElement::calculateDefaultOptionIndices()
{
    WMLPageState* pageState = wmlPageStateForDocument(&document());
    if (!pageState)
        return;

    String variable;

    // Spec: If the default option index is empty, and the 'name' attribute is specified
    // and the 'name' ttribute names a variable that is set, then for each value in the 'name'
    // variable that is present as a value in the select's option elements, the index of the
    // first option element containing that value is added to the default index if that
    // index has not been previously added.
    String name = this->name();
    if (m_defaultOptionIndices.isEmpty() && !name.isEmpty()) {
        variable = pageState->getVariable(name);
        if (!variable.isEmpty())
            m_defaultOptionIndices = valueStringToOptionIndices(variable);
    }

    String value = WMLElement::parseValueSubstitutingVariableReferencesHelp(&document(), getAttribute(HTMLNames::valueAttr));

    // Spec: If the default option index is empty and the 'value' attribute is specified then
    // for each  value in the 'value' attribute that is present as a value in the select's
    // option elements, the index of the first option element containing that value is added
    // to the default index if that index has not been previously added.
    if (m_defaultOptionIndices.isEmpty() && !value.isEmpty())
        m_defaultOptionIndices = valueStringToOptionIndices(value);

    // Spec: If the default option index is empty and the select is a multi-choice, then the
    // default option index is set to zero. If the select is single-choice, then the default
    // option index is set to one.
    if (m_defaultOptionIndices.isEmpty())
        m_defaultOptionIndices.append((unsigned)!multiple());
}

Vector<unsigned> WMLSelectElement::parseIndexValueString(const String& indexValue) const
{
    Vector<unsigned> indices;
    if (indexValue.isEmpty())
        return indices;

    Vector<String> indexStrings;
    indexValue.split(';', indexStrings);

    bool ok = false;
    unsigned optionNum = optionCount();

    Vector<String>::const_iterator end = indexStrings.end();
    for (Vector<String>::const_iterator it = indexStrings.begin(); it != end; ++it) {
        unsigned parsedValue = (*it).toUIntStrict(&ok);
        // Spec: Remove all non-integer indices from the value. Remove all out-of-range indices
        // from the value, where out-of-range is defined as any index with a value greater than
        // the number of options in the select or with a value less than one.
        if (!ok || parsedValue < 1 || parsedValue > optionNum)
            continue;

        // Spec: Remove duplicate indices.
        if (indices.find(parsedValue) == WTF::kNotFound)
            indices.append(parsedValue);
    }

    return indices;
}

Vector<unsigned> WMLSelectElement::valueStringToOptionIndices(const String& value) const
{
    Vector<unsigned> indices;
    if (value.isEmpty())
        return indices;

    const ListItems& items = listItems();
    if (items.isEmpty())
        return indices;

    Vector<String> indexStrings;
    value.split(';', indexStrings);

    //unsigned optionIndex = 0;

    Vector<String>::const_iterator end = indexStrings.end();
    for (Vector<String>::const_iterator it = indexStrings.begin(); it != end; ++it) {
        String value = *it;
        // SAMSUNG_WML_FIXES+
        // wml/struct/control/select/element/value/3
        // reset the optionIndex = 0
        for (unsigned i = 0, optionIndex = 0; i < items.size(); ++i) {
            // SAMSUNG_WML_FIXES-
            if (!isWMLOptionElement(items[i]))
                continue;

            ++optionIndex;
            if (WMLOptionElement* WMLOptionElement = toWMLOptionElement(items[i])) {
                if (WMLOptionElement->value() == value) {
                    indices.append(optionIndex);
                    break;
                }
            }
        }
    }

    return indices;
}

String WMLSelectElement::optionIndicesToValueString() const
{
    String valueString;
    if (m_defaultOptionIndices.isEmpty())
        return valueString;

    const ListItems& items = listItems();
    if (items.isEmpty())
        return valueString;

    Vector<unsigned>::const_iterator end = m_defaultOptionIndices.end();
    for (Vector<unsigned>::const_iterator it = m_defaultOptionIndices.begin(); it != end; ++it) {
        unsigned optionIndex = (*it);
        if (optionIndex < 1 || optionIndex > items.size())
            continue;

        int listIndex = optionToListIndex((*it) - 1);
        ASSERT(listIndex >= 0);
        ASSERT(listIndex < (int)items.size());

        if (WMLOptionElement* WMLOptionElement = toWMLOptionElement(items[listIndex])) {
            if (!valueString.isEmpty())
                valueString.append(";");

            valueString.append(WMLOptionElement->value());
        }
    }

    return valueString;
}

String WMLSelectElement::optionIndicesToString() const
{
    String valueString;
    if (m_defaultOptionIndices.isEmpty())
        return valueString;

    Vector<unsigned>::const_iterator end = m_defaultOptionIndices.end();
    for (Vector<unsigned>::const_iterator it = m_defaultOptionIndices.begin(); it != end; ++it) {
        if (!valueString.isEmpty())
            valueString.append(";");

        valueString.append(String::number(*it));
    }

    return valueString;
}

void WMLSelectElement::updateVariables()
{
    WMLPageState* pageState = wmlPageStateForDocument(&document());
    if (!pageState)
        return;

    String name = this->name();
    //String iname = this->iname();
    if (/*iname.isEmpty() &&*/ name.isEmpty())
        return;

    String nameString;
    //String inameString;

    unsigned optionIndex = 0;
    const ListItems& items = listItems();

    for (unsigned i = 0; i < items.size(); ++i) {
        WMLOptionElement* WMLOptionElement = toWMLOptionElement(items[i]);
        if (!WMLOptionElement)
            continue;

        ++optionIndex;
        if (!WMLOptionElement->selected())
            continue;

        if (!nameString.isEmpty())
            nameString.append(";");

        //         if (!inameString.isEmpty())
        //             inameString += ";";

        nameString.append(WMLOptionElement->value());
        //inameString += String::number(optionIndex);
    }

    if (!name.isEmpty())
        pageState->storeVariable(name, nameString);

    //     if (!iname.isEmpty())
    //         pageState->storeVariable(iname, inameString);
}

DEFINE_TRACE(WMLSelectElement)
{
    HTMLSelectElement::trace(visitor);
}

} // blink

#endif

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

#include "config.h"

#if ENABLE_WML
#include "WMLTaskElement.h"

#include "WMLAnchorElement.h"
#include "WMLDoElement.h"
#include "WMLOnEventElement.h"
#include "WMLPageState.h"
#include "WMLSetvarElement.h"
#include "core/WMLNames.h"

namespace blink {

using namespace WMLNames;

WMLTaskElement::WMLTaskElement(const QualifiedName& tagName, Document& doc)
    : WMLElement(tagName, doc)
{
}

WMLTaskElement::~WMLTaskElement()
{
}

Node::InsertionNotificationRequest WMLTaskElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    ContainerNode* parent = parentNode();
    if (!parent || !parent->isWMLElement())
        return InsertionDone;

    if (hasWMLTagName(parent, anchorTag))
        static_cast<WMLAnchorElement*>(parent)->registerTask(this);
    else if (hasWMLTagName(parent, doTag))
        static_cast<WMLDoElement*>(parent)->registerTask(this);
    else if (hasWMLTagName(parent, oneventTag))
        static_cast<WMLOnEventElement*>(parent)->registerTask(this);

    return InsertionDone;
}

void WMLTaskElement::removedFrom(ContainerNode* node)
{
    ContainerNode* parent = parentNode();
    if (parent && parent->isWMLElement()) {
        if (hasWMLTagName(parent, anchorTag))
            static_cast<WMLAnchorElement*>(parent)->deregisterTask(this);
        else if (hasWMLTagName(parent, doTag))
            static_cast<WMLDoElement*>(parent)->deregisterTask(this);
        else if (hasWMLTagName(parent, oneventTag))
            static_cast<WMLOnEventElement*>(parent)->deregisterTask(this);
    }

    WMLElement::removedFrom(node);
}

void WMLTaskElement::registerVariableSetter(WMLSetvarElement* element)
{
    ASSERT(m_variableSetterElements.find(element) == WTF::kNotFound);
    m_variableSetterElements.append(element);
}

void WMLTaskElement::deregisterVariableSetter(WMLSetvarElement* element)
{
    size_t position = m_variableSetterElements.find(element);
    ASSERT(position != WTF::kNotFound);
    m_variableSetterElements.remove(position);
}

void WMLTaskElement::storeVariableState(WMLPageState* pageState)
{
    if (!pageState || m_variableSetterElements.isEmpty())
        return;

    WMLVariableMap variables;
    HeapVector<Member<WMLSetvarElement>>::iterator it = m_variableSetterElements.begin();
    HeapVector<Member<WMLSetvarElement>>::iterator end = m_variableSetterElements.end();

    for (; it != end; ++it) {
        WMLSetvarElement* setterElement = (*it);

        String name = setterElement->name();
        if (name.isEmpty())
            continue;

        String value = setterElement->value();
        variables.set(name, value);

        // The next setvar element may depend on this variable value. It's safe to store the current
        // name value pair in the page state, as the whole page state is replaced soon by this new map
        pageState->storeVariable(name, value);
    }
    // SAMSUNG_WML_FIXES+
    // http://spe.mobilephone.net/wit/wmlv2/strucvar.wml
    // [0] In the go task we set a variable and go to another card.
    // [1] On the second card we have a refresh element. and we call  storeVariableState for intresic event and overwrite the variable set in [0]
    // [2] So do not overwrite with the new map.
    // pageState->storeVariables(variables);
    // SAMSUNG_WML_FIXES-
}

DEFINE_TRACE(WMLTaskElement)
{
    visitor->trace(m_variableSetterElements);
    WMLElement::trace(visitor);
}

}

#endif

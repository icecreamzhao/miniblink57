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

#include "config.h"

#if ENABLE_WML
#include "WMLEventHandlingElement.h"

#include "WMLCardElement.h"
#include "WMLDoElement.h"
#include "WMLIntrinsicEventHandler.h"
#include "WMLOptionElement.h"
#include "WMLTaskElement.h"
#include "WMLTemplateElement.h"
#include "core/WMLNames.h"
#ifdef TENCENT_CHANGES
#include "WMLPElement.h" // add by harry guo. support the do tag when it's in p tag
#endif // TENCENT_CHANGES

namespace blink {

using namespace WMLNames;

WMLEventHandlingElement::WMLEventHandlingElement()
{
    m_eventHandler = nullptr;
    m_doElements.clear();
}

WMLEventHandlingElement::~WMLEventHandlingElement()
{
}

void WMLEventHandlingElement::createEventHandlerIfNeeded()
{
    if (!m_eventHandler)
        m_eventHandler = new WMLIntrinsicEventHandler();
}

void WMLEventHandlingElement::registerDoElement(WMLDoElement* doElement, Document* document)
{
    HeapVector<Member<WMLDoElement>>::iterator it = m_doElements.begin();
    HeapVector<Member<WMLDoElement>>::iterator end = m_doElements.end();

    for (; it != end; ++it) {
        if ((*it)->name() == doElement->name()) {
            reportWMLError(document, WMLErrorDuplicatedDoElement);
            return;
        }
    }

    ASSERT(m_doElements.find(doElement) == WTF::kNotFound);
    m_doElements.append(doElement);
    doElement->setActive(true);
}

void WMLEventHandlingElement::deregisterDoElement(WMLDoElement* doElement)
{
    doElement->setActive(false);

    size_t position = m_doElements.find(doElement);
    if (position == WTF::kNotFound)
        return;

    m_doElements.remove(position);
}

WMLEventHandlingElement* toWMLEventHandlingElement(WMLElement* element)
{
    if (!element->isWMLElement())
        return 0;

    if (element->hasTagName(cardTag))
        return static_cast<WMLCardElement*>(element);
    //else if (element->hasTagName(optionTag))
    //    return static_cast<WMLOptionElement*>(element);
    else if (element->hasTagName(templateTag))
        return static_cast<WMLTemplateElement*>(element);
#ifdef TENCENT_CHANGES
    //add surport wml do tag modified by xiaobohu
    else if (element->hasTagName(doTag))
        return static_cast<WMLDoElement*>(element);
    //  add by harry guo. support the do tag when it's in p tag
    else if (element->hasTagName(pTag))
        return static_cast<WMLPElement*>(element);
#endif // TENCENT_CHANGES
    // SAMSUNG_WML_FIXES+
    // http://spe.mobilephone.net/wit/wmlv2/navdo.wml
    else
        return toWMLEventHandlingElement(static_cast<WMLElement*>(element->parentElement()));

    return 0;
}

DEFINE_TRACE(WMLEventHandlingElement)
{
    visitor->trace(m_eventHandler);
    visitor->trace(m_doElements);
}

}

#endif

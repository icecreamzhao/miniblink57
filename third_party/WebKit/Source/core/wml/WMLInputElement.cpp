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
#include "WMLInputElement.h"

#include "WMLDocument.h"
#include "WMLPageState.h"
#include "core/EventNames.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"
#include "core/events/KeyboardEvent.h"
#include "core/events/TextEvent.h"
#include "core/frame/Frame.h"

namespace blink {

WMLInputElement::WMLInputElement(Document& doc, bool createdByParser)
    : HTMLInputElement(doc, createdByParser)
{
}

WMLInputElement* WMLInputElement::create(Document& document)
{
    WMLInputElement* inputElement = new WMLInputElement(document, true);
    //inputElement->ensureUserAgentShadowRoot();

    //totrit: register the input-element to page-state.
    ((WMLDocument*)&document)->registerInputElement(inputElement);
    //over.
    return inputElement;
}

WMLInputElement::~WMLInputElement()
{
    //((WMLDocument*)&document())->degisterInputElement(this);
}

void WMLInputElement::attachLayoutTree(const AttachContext& attachContext)
{
    ((WMLDocument*)&document())->registerInputElement(this);
    HTMLInputElement::attachLayoutTree(attachContext);
}

void WMLInputElement::detachLayoutTree(const AttachContext& attachContext)
{
    ((WMLDocument*)&document())->degisterInputElement(this);
    HTMLInputElement::detachLayoutTree(attachContext);
}

DEFINE_TRACE(WMLInputElement)
{
    HTMLInputElement::trace(visitor);
}

}
#endif

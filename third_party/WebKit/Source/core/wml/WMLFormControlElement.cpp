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
#include "WMLFormControlElement.h"
#include "core/HTMLNames.h"
#include "core/layout/LayoutBox.h"
#include "core/layout/LayoutObject.h"
#include "core/style/ComputedStyle.h"

namespace blink {

WMLFormControlElement::WMLFormControlElement(const QualifiedName& tagName, Document& document)
    : WMLElement(tagName, document)
    , m_valueMatchesRenderer(false)
{
}

WMLFormControlElement::~WMLFormControlElement()
{
}

bool WMLFormControlElement::supportsFocus() const
{
    return true;
}

bool WMLFormControlElement::isFocusable() const
{
    if (!layoutObject() || !layoutObject()->isBox())
        return false;

    if (toLayoutBox(layoutObject())->size().isEmpty())
        return false;

    return WMLElement::isFocusable();
}

void WMLFormControlElement::attachLayoutTree(const AttachContext& attachContext)
{
    //ASSERT(!attached());
    WMLElement::attachLayoutTree(attachContext);

    // The call to updateFromElement() needs to go after the call through
    // to the base class's attach() because that can sometimes do a close
    // on the renderer.
    if (layoutObject())
        layoutObject()->updateFromElement();
}

void WMLFormControlElement::recalcStyle(StyleRecalcChange change, Text* nextTextSibling)
{
    WMLElement::recalcStyle(change);

    if (layoutObject())
        layoutObject()->updateFromElement();
}

//SAMSUNG_WML_FIX +
String WMLFormControlElement::name() const
{
    return parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::nameAttr));
}
//SAMSUNG_WML_FIX -

DEFINE_TRACE(WMLFormControlElement)
{
    WMLElement::trace(visitor);
}

}
#endif

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
#include "WMLImageElement.h"

#include "WMLVariables.h"
#include "core/CSSPropertyNames.h"
#include "core/CSSValueKeywords.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/css/StylePropertySet.h"
#include "core/dom/Attribute.h"
#include "core/html/HTMLElement.h"
#include "core/layout/LayoutImage.h"

namespace blink {

using namespace WMLNames;

WMLImageElement::WMLImageElement(Document& doc)
    : WMLElement(WMLNames::imgTag, doc)
    , m_imageLoader(this)
    , m_useFallbackAttribute(false)
{
}

DEFINE_NODE_FACTORY(WMLImageElement)

WMLImageElement::~WMLImageElement()
{
}

void WMLImageElement::parseAttribute(const AttributeModificationParams& params)
{
    // totrit: TODO: 'addCSSProperty' was 'addCSSLength'.
    const QualifiedName& attrName = params.name;
    //RefPtr<StylePropertySet> style;
    if (attrName == HTMLNames::altAttr) {
        //         if (layoutObject() && layoutObject()->isImage())
        //             toLayoutImage(layoutObject())->updateAltText();
    } else if (attrName == HTMLNames::srcAttr || attrName == localsrcAttr) {
        m_imageLoader.updateFromElement(ImageLoader::UpdateIgnorePreviousError);
    }
    /*  else if (attrName == HTMLNames::vspaceAttr) {
    	addCSSLength(attr, CSSPropertyMarginTop, attr->value());
    	addCSSLength(attr, CSSPropertyMarginBottom, attr->value());
    } else if (attrName == HTMLNames::hspaceAttr) {
    	addCSSLength(attr, CSSPropertyMarginLeft, attr->value());
    	addCSSLength(attr, CSSPropertyMarginRight, attr->value());
    } else if (attrName == HTMLNames::alignAttr)
        HTMLElement::applyAlignmentAttributeToStyle(attr, attributeStyle());*/

    /*if (name == HTMLNames::widthAttr){
    	style = MutableStylePropertySet::create();
    	addWMLLengthToStyle(style.get(), CSSPropertyWidth, String(value()));
    	if (style->isEmpty())
    		elementData()->setAttributeStyle(0);
    	else {
    		style->shrinkToFit();
    		elementData()->setAttributeStyle(style);
    	}
    }
    else if (name == HTMLNames::heightAttr){
    	style = MutableStylePropertySet::create();
    	addWMLLengthToStyle(style.get(), CSSPropertyHeight, String(value()));
    	if (style->isEmpty())
    		elementData()->setAttributeStyle(0);
    	else {
    		style->shrinkToFit();
    		elementData()->setAttributeStyle(style);
    	}
    }
    else*/
    WMLElement::parseAttribute(params);
}

void WMLImageElement::attachLayoutTree(const AttachContext& attachContext)
{
    WMLElement::attachLayoutTree(attachContext);

    if (layoutObject() && layoutObject()->isImage() /*&& !m_imageLoader.hasPendingBeforeLoadEvent()*/) {
        LayoutImage* imageObj = toLayoutImage(layoutObject());
        LayoutImageResource* renderImageResource = imageObj->imageResource();
        if (renderImageResource->hasImage())
            return;
        renderImageResource->setImageResource(m_imageLoader.image());

        // If we have no image at all because we have no src attribute, set
        // image height and width for the alt text instead.
        //         if (!m_imageLoader.image() && !imageObj->cachedImage())
        //             imageObj->setImageSizeForAltText();
    }
}

LayoutObject* WMLImageElement::createLayoutObject(const ComputedStyle&)
{
    LayoutImage* image = new LayoutImage(this);
    image->setImageResource(LayoutImageResource::create());
    return image;
}

Node::InsertionNotificationRequest WMLImageElement::insertedInto(ContainerNode* node)
{
    // If we have been inserted from a renderer-less document,
    // our loader may have not fetched the image, so do it now.
    if (!m_imageLoader.image())
        m_imageLoader.updateFromElement();

    return WMLElement::insertedInto(node);
}

bool WMLImageElement::isURLAttribute(const Attribute& attr) const
{
    return attr.name() == HTMLNames::srcAttr
        || attr.name() == localsrcAttr;
}

const QualifiedName& WMLImageElement::imageSourceAttributeName() const
{
    // Spec: Any 'localsrc' parameter specified takes precedence over the
    // image specified in the src parameter.
    if (hasAttribute(localsrcAttr) && !m_useFallbackAttribute)
        return localsrcAttr;

    return HTMLNames::srcAttr;
}

String WMLImageElement::altText() const
{
    return substituteVariableReferences(getAttribute(HTMLNames::altAttr), &document());
}

DEFINE_TRACE(WMLImageElement)
{
    WMLElement::trace(visitor);
}

}

#endif

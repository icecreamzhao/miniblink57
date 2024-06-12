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

#ifndef WMLImageElement_h
#define WMLImageElement_h

#if ENABLE_WML
#include "WMLElement.h"
#include "WMLImageLoader.h"
#include "core/dom/Document.h"

namespace blink {
#ifdef TENCENT_CHANGES
class CachedImage;
#endif

class WMLImageElement : public WMLElement {
public:
    DECLARE_NODE_FACTORY(WMLImageElement);

    WMLImageElement(Document&);
    virtual ~WMLImageElement() override;

    virtual void parseAttribute(const AttributeModificationParams& params) override;

    virtual void attachLayoutTree(const AttachContext& = AttachContext()) override;
    virtual LayoutObject* createLayoutObject(const ComputedStyle&) override;

    virtual Node::InsertionNotificationRequest insertedInto(ContainerNode*) override;
    virtual bool isURLAttribute(const Attribute&) const override;
    /*virtual*/ const QualifiedName& imageSourceAttributeName() const /*override*/;

    String altText() const;
    //totrit: the src-url of the image.
    inline KURL src() { return document().completeURL(getAttribute(imageSourceAttributeName())); }

    bool useFallbackAttribute() { return m_useFallbackAttribute; }
    void setUseFallbackAttribute(bool value) { m_useFallbackAttribute = value; }

#ifdef TENCENT_CHANGES
    ImageResource* cachedImage() const
    {
        return m_imageLoader.imageResourceForImageDocument();
    }
#endif

    DECLARE_VIRTUAL_TRACE();

private:
    WMLImageLoader m_imageLoader;
    bool m_useFallbackAttribute;
};

}

#endif
#endif

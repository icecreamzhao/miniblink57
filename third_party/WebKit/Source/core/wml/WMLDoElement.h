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

#ifndef WMLDoElement_h
#define WMLDoElement_h

#if ENABLE_WML
#include "WMLElement.h"
#ifdef TENCENT_CHANGES
#include "WMLEventHandlingElement.h"
#endif

namespace blink {

class LayoutTextFragment;
class LayoutButton;
class WMLTaskElement;

#ifdef TENCENT_CHANGES
//add surport wml do tag modified by xiaobohu
class WMLDoElement : public WMLElement, public WMLEventHandlingElement {
#else
class WMLDoElement : public WMLElement {
#endif
public:
    DECLARE_NODE_FACTORY(WMLDoElement);

    WMLDoElement(Document&);

#ifdef TENCENT_CHANGES
    virtual bool canContainRangeEndPoint() const
    {
        return false;
    }
#endif

    virtual void defaultEventHandler(Event*) override;
    virtual void parseAttribute(const AttributeModificationParams& params) override;
    virtual Node::InsertionNotificationRequest insertedInto(ContainerNode* node) override;
    virtual void removedFrom(ContainerNode* node) override;

    virtual void attachLayoutTree(const AttachContext& attachContext = AttachContext()) override;
    virtual void detachLayoutTree(const AttachContext& attachContext = AttachContext()) override;

    virtual LayoutObject* createLayoutObject(const ComputedStyle& style) override;
    virtual void recalcStyle(StyleRecalcChange, Text* nextTextSibling = nullptr) override;

    void registerTask(WMLTaskElement*);
    void deregisterTask(WMLTaskElement*);

    bool isActive() const { return m_isActive; }
    String label() const;
    String name() const { return m_name; }

    void setActive(bool active) { m_isActive = active; }
    void setNoop(bool noop) { m_isNoop = noop; }

    DECLARE_VIRTUAL_TRACE();

private:
    void setText(const String& str, LayoutButton* renderButton);

    WMLTaskElement* m_task;
    bool m_isActive;
    bool m_isNoop;
    bool m_isOptional;
    String m_name;
    String m_type;
    LayoutTextFragment* m_buttonText;
};

}

#endif
#endif

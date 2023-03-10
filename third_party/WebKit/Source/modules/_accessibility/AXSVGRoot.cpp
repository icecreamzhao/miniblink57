/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "modules/accessibility/AXSVGRoot.h"

#include "modules/accessibility/AXObjectCacheImpl.h"

namespace blink {

AXSVGRoot::AXSVGRoot(LayoutObject* layoutObject,
    AXObjectCacheImpl& axObjectCache)
    : AXLayoutObject(layoutObject, axObjectCache)
{
}

AXSVGRoot::~AXSVGRoot() { }

AXSVGRoot* AXSVGRoot::create(LayoutObject* layoutObject,
    AXObjectCacheImpl& axObjectCache)
{
    return new AXSVGRoot(layoutObject, axObjectCache);
}

void AXSVGRoot::setParent(AXObject* parent)
{
    // Only update the parent to another objcet if it wasn't already set to
    // something. Multiple elements in an HTML document can reference
    // the same remote SVG document, and in that case the parent should just
    // stay with the first one.
    if (!m_parent || !parent)
        m_parent = parent;
}

AXObject* AXSVGRoot::computeParent() const
{
    ASSERT(!isDetached());
    // If a parent was set because this is a remote SVG resource, use that
    // but otherwise, we should rely on the standard layout tree for the parent.
    if (m_parent)
        return m_parent;

    return AXLayoutObject::computeParent();
}

// SVG AAM 1.0 S8.2: the default role for an SVG root is "group".
AccessibilityRole AXSVGRoot::determineAccessibilityRole()
{
    AccessibilityRole role = AXLayoutObject::determineAccessibilityRole();
    if (role == UnknownRole)
        role = GroupRole;
    return role;
}

// SVG elements are only ignored when a generic element would also be ignored.
bool AXSVGRoot::computeAccessibilityIsIgnored(IgnoredReasons* reasons) const
{
    return accessibilityIsIgnoredByDefault(reasons);
}

} // namespace blink

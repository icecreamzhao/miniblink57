// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/paint/TransformDisplayItem.h"

#include "platform/graphics/GraphicsContext.h"
#include "platform/transforms/AffineTransform.h"
#include "public/platform/WebDisplayItemList.h"

namespace blink {

<<<<<<< HEAD
void BeginTransformDisplayItem::replay(GraphicsContext& context) const
=======
void BeginTransformDisplayItem::replay(GraphicsContext& context)
>>>>>>> miniblink49
{
    context.save();
    context.concatCTM(m_transform);
}

<<<<<<< HEAD
void BeginTransformDisplayItem::appendToWebDisplayItemList(
    const IntRect& visualRect,
    WebDisplayItemList* list) const
=======
void BeginTransformDisplayItem::appendToWebDisplayItemList(WebDisplayItemList* list) const
>>>>>>> miniblink49
{
    list->appendTransformItem(affineTransformToSkMatrix(m_transform));
}

#ifndef NDEBUG
<<<<<<< HEAD
void BeginTransformDisplayItem::dumpPropertiesAsDebugString(
    WTF::StringBuilder& stringBuilder) const
{
    PairedBeginDisplayItem::dumpPropertiesAsDebugString(stringBuilder);
    stringBuilder.append(
        WTF::String::format(", transform: [%lf,%lf,%lf,%lf,%lf,%lf]",
            m_transform.a(), m_transform.b(), m_transform.c(),
            m_transform.d(), m_transform.e(), m_transform.f()));
}
#endif

void EndTransformDisplayItem::replay(GraphicsContext& context) const
=======
void BeginTransformDisplayItem::dumpPropertiesAsDebugString(WTF::StringBuilder& stringBuilder) const
{
    PairedBeginDisplayItem::dumpPropertiesAsDebugString(stringBuilder);
    stringBuilder.append(WTF::String::format(", transform: [%lf,%lf,%lf,%lf,%lf,%lf]",
        m_transform.a(), m_transform.b(), m_transform.c(), m_transform.d(), m_transform.e(), m_transform.f()));
}
#endif

void EndTransformDisplayItem::replay(GraphicsContext& context)
>>>>>>> miniblink49
{
    context.restore();
}

<<<<<<< HEAD
void EndTransformDisplayItem::appendToWebDisplayItemList(
    const IntRect& visualRect,
    WebDisplayItemList* list) const
=======
void EndTransformDisplayItem::appendToWebDisplayItemList(WebDisplayItemList* list) const
>>>>>>> miniblink49
{
    list->appendEndTransformItem();
}

} // namespace blink

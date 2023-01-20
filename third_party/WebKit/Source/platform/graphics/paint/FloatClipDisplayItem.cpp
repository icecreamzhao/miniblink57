// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/paint/FloatClipDisplayItem.h"

#include "platform/graphics/GraphicsContext.h"
#include "public/platform/WebDisplayItemList.h"
#include "third_party/skia/include/core/SkScalar.h"

namespace blink {

<<<<<<< HEAD
void FloatClipDisplayItem::replay(GraphicsContext& context) const
=======
void FloatClipDisplayItem::replay(GraphicsContext& context)
>>>>>>> miniblink49
{
    context.save();
    context.clip(m_clipRect);
}

<<<<<<< HEAD
void FloatClipDisplayItem::appendToWebDisplayItemList(
    const IntRect& visualRect,
    WebDisplayItemList* list) const
=======
void FloatClipDisplayItem::appendToWebDisplayItemList(WebDisplayItemList* list) const
>>>>>>> miniblink49
{
    list->appendFloatClipItem(m_clipRect);
}

<<<<<<< HEAD
void EndFloatClipDisplayItem::replay(GraphicsContext& context) const
=======
void EndFloatClipDisplayItem::replay(GraphicsContext& context)
>>>>>>> miniblink49
{
    context.restore();
}

<<<<<<< HEAD
void EndFloatClipDisplayItem::appendToWebDisplayItemList(
    const IntRect& visualRect,
    WebDisplayItemList* list) const
=======
void EndFloatClipDisplayItem::appendToWebDisplayItemList(WebDisplayItemList* list) const
>>>>>>> miniblink49
{
    list->appendEndFloatClipItem();
}

#ifndef NDEBUG
<<<<<<< HEAD
void FloatClipDisplayItem::dumpPropertiesAsDebugString(
    WTF::StringBuilder& stringBuilder) const
{
    DisplayItem::dumpPropertiesAsDebugString(stringBuilder);
    stringBuilder.append(WTF::String::format(
        ", floatClipRect: [%f,%f,%f,%f]}", m_clipRect.x(), m_clipRect.y(),
        m_clipRect.width(), m_clipRect.height()));
=======
void FloatClipDisplayItem::dumpPropertiesAsDebugString(WTF::StringBuilder& stringBuilder) const
{
    DisplayItem::dumpPropertiesAsDebugString(stringBuilder);
    stringBuilder.append(WTF::String::format(", floatClipRect: [%f,%f,%f,%f]}",
        m_clipRect.x(), m_clipRect.y(), m_clipRect.width(), m_clipRect.height()));
>>>>>>> miniblink49
}

#endif

} // namespace blink

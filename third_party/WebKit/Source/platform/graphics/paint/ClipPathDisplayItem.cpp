// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/paint/ClipPathDisplayItem.h"

#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/Path.h"
#include "public/platform/WebDisplayItemList.h"
<<<<<<< HEAD
#include "third_party/skia/include/core/SkPictureAnalyzer.h"
=======
>>>>>>> miniblink49
#include "third_party/skia/include/core/SkScalar.h"

namespace blink {

<<<<<<< HEAD
void BeginClipPathDisplayItem::replay(GraphicsContext& context) const
=======
void BeginClipPathDisplayItem::replay(GraphicsContext& context)
>>>>>>> miniblink49
{
    context.save();
    context.clipPath(m_clipPath, AntiAliased);
}

<<<<<<< HEAD
void BeginClipPathDisplayItem::appendToWebDisplayItemList(
    const IntRect& visualRect,
    WebDisplayItemList* list) const
{
    list->appendClipPathItem(m_clipPath, true);
}

void BeginClipPathDisplayItem::analyzeForGpuRasterization(
    SkPictureGpuAnalyzer& analyzer) const
{
    // Temporarily disabled (pref regressions due to GPU veto stickiness:
    // http://crbug.com/603969).
    // analyzer.analyzeClipPath(m_clipPath, SkRegion::kIntersect_Op, true);
}

void EndClipPathDisplayItem::replay(GraphicsContext& context) const
=======
void BeginClipPathDisplayItem::appendToWebDisplayItemList(WebDisplayItemList* list) const
{
    list->appendClipPathItem(m_clipPath, SkRegion::kIntersect_Op, true);
}

void EndClipPathDisplayItem::replay(GraphicsContext& context)
>>>>>>> miniblink49
{
    context.restore();
}

<<<<<<< HEAD
void EndClipPathDisplayItem::appendToWebDisplayItemList(
    const IntRect& visualRect,
    WebDisplayItemList* list) const
=======
void EndClipPathDisplayItem::appendToWebDisplayItemList(WebDisplayItemList* list) const
>>>>>>> miniblink49
{
    list->appendEndClipPathItem();
}

#ifndef NDEBUG
<<<<<<< HEAD
void BeginClipPathDisplayItem::dumpPropertiesAsDebugString(
    WTF::StringBuilder& stringBuilder) const
{
    DisplayItem::dumpPropertiesAsDebugString(stringBuilder);
    stringBuilder.append(WTF::String::format(
        ", pathVerbs: %d, pathPoints: %d, windRule: \"%s\"",
        m_clipPath.countVerbs(), m_clipPath.countPoints(),
        m_clipPath.getFillType() == SkPath::kWinding_FillType ? "nonzero"
                                                              : "evenodd"));
=======
void BeginClipPathDisplayItem::dumpPropertiesAsDebugString(WTF::StringBuilder& stringBuilder) const
{
    DisplayItem::dumpPropertiesAsDebugString(stringBuilder);
    stringBuilder.append(WTF::String::format(", pathVerbs: %d, pathPoints: %d, windRule: \"%s\"",
        m_clipPath.countVerbs(), m_clipPath.countPoints(),
        m_clipPath.getFillType() == SkPath::kWinding_FillType ? "nonzero" : "evenodd"));
>>>>>>> miniblink49
}

#endif

} // namespace blink

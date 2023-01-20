// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ClipDisplayItem_h
#define ClipDisplayItem_h

#include "SkRegion.h"
#include "platform/PlatformExport.h"
#include "platform/geometry/FloatRoundedRect.h"
#include "platform/geometry/IntRect.h"
#include "platform/graphics/paint/DisplayItem.h"
<<<<<<< HEAD
=======
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49
#include "wtf/Vector.h"

namespace blink {

<<<<<<< HEAD
class PLATFORM_EXPORT ClipDisplayItem final : public PairedBeginDisplayItem {
public:
    ClipDisplayItem(const DisplayItemClient& client,
        Type type,
        const IntRect& clipRect)
        : PairedBeginDisplayItem(client, type, sizeof(*this))
=======
class PLATFORM_EXPORT ClipDisplayItem : public PairedBeginDisplayItem {
public:
    ClipDisplayItem(const DisplayItemClientWrapper& client, Type type, const IntRect& clipRect)
        : PairedBeginDisplayItem(client, type)
>>>>>>> miniblink49
        , m_clipRect(clipRect)
    {
        ASSERT(isClipType(type));
    }

<<<<<<< HEAD
    ClipDisplayItem(const DisplayItemClient& client,
        Type type,
        const IntRect& clipRect,
        Vector<FloatRoundedRect>& roundedRectClips)
=======
    ClipDisplayItem(const DisplayItemClientWrapper& client, Type type, const IntRect& clipRect, Vector<FloatRoundedRect>& roundedRectClips)
>>>>>>> miniblink49
        : ClipDisplayItem(client, type, clipRect)
    {
        m_roundedRectClips.swap(roundedRectClips);
    }

<<<<<<< HEAD
    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;
=======
    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;
>>>>>>> miniblink49

private:
#ifndef NDEBUG
    void dumpPropertiesAsDebugString(WTF::StringBuilder&) const override;
#endif
<<<<<<< HEAD
    bool equals(const DisplayItem& other) const final
    {
        return DisplayItem::equals(other) && m_clipRect == static_cast<const ClipDisplayItem&>(other).m_clipRect && m_roundedRectClips == static_cast<const ClipDisplayItem&>(other).m_roundedRectClips;
    }

=======
>>>>>>> miniblink49
    const IntRect m_clipRect;
    Vector<FloatRoundedRect> m_roundedRectClips;
};

<<<<<<< HEAD
class PLATFORM_EXPORT EndClipDisplayItem final : public PairedEndDisplayItem {
public:
    EndClipDisplayItem(const DisplayItemClient& client, Type type)
        : PairedEndDisplayItem(client, type, sizeof(*this))
=======
class PLATFORM_EXPORT EndClipDisplayItem : public PairedEndDisplayItem {
public:
    EndClipDisplayItem(const DisplayItemClientWrapper& client, Type type)
        : PairedEndDisplayItem(client, type)
>>>>>>> miniblink49
    {
        ASSERT(isEndClipType(type));
    }

<<<<<<< HEAD
    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

private:
#if DCHECK_IS_ON()
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final
    {
        return DisplayItem::isClipType(otherType);
    }
=======
    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;

private:
#if ENABLE(ASSERT)
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final { return DisplayItem::isClipType(otherType); }
>>>>>>> miniblink49
#endif
};

} // namespace blink

#endif // ClipDisplayItem_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FloatClipDisplayItem_h
#define FloatClipDisplayItem_h

#include "platform/PlatformExport.h"
#include "platform/geometry/FloatRect.h"
#include "platform/graphics/paint/DisplayItem.h"
<<<<<<< HEAD

namespace blink {

class PLATFORM_EXPORT FloatClipDisplayItem final
    : public PairedBeginDisplayItem {
public:
    FloatClipDisplayItem(const DisplayItemClient& client,
        Type type,
        const FloatRect& clipRect)
        : PairedBeginDisplayItem(client, type, sizeof(*this))
=======
#include "wtf/PassOwnPtr.h"

namespace blink {

class RoundedRect;

class PLATFORM_EXPORT FloatClipDisplayItem : public PairedBeginDisplayItem {
public:
    FloatClipDisplayItem(const DisplayItemClientWrapper& client, Type type, const FloatRect& clipRect)
        : PairedBeginDisplayItem(client, type)
>>>>>>> miniblink49
        , m_clipRect(clipRect)
    {
        ASSERT(isFloatClipType(type));
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
        return DisplayItem::equals(other) && m_clipRect == static_cast<const FloatClipDisplayItem&>(other).m_clipRect;
    }
=======
>>>>>>> miniblink49

    const FloatRect m_clipRect;
};

<<<<<<< HEAD
class PLATFORM_EXPORT EndFloatClipDisplayItem final
    : public PairedEndDisplayItem {
public:
    EndFloatClipDisplayItem(const DisplayItemClient& client, Type type)
        : PairedEndDisplayItem(client, type, sizeof(*this))
=======
class PLATFORM_EXPORT EndFloatClipDisplayItem : public PairedEndDisplayItem {
public:
    EndFloatClipDisplayItem(const DisplayItemClientWrapper& client, Type type)
        : PairedEndDisplayItem(client, type)
>>>>>>> miniblink49
    {
        ASSERT(isEndFloatClipType(type));
    }

<<<<<<< HEAD
    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

private:
#if DCHECK_IS_ON()
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final
    {
        return DisplayItem::isFloatClipType(otherType);
    }
=======
    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;

private:
#if ENABLE(ASSERT)
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final { return DisplayItem::isFloatClipType(otherType); }
>>>>>>> miniblink49
#endif
};

} // namespace blink

#endif // FloatClipDisplayItem_h

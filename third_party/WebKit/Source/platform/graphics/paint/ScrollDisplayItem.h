// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ScrollDisplayItem_h
#define ScrollDisplayItem_h

#include "platform/geometry/IntSize.h"
#include "platform/graphics/paint/DisplayItem.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"

namespace blink {

class PLATFORM_EXPORT BeginScrollDisplayItem final
    : public PairedBeginDisplayItem {
public:
    BeginScrollDisplayItem(const DisplayItemClient& client,
        Type type,
        const IntSize& currentOffset)
        : PairedBeginDisplayItem(client, type, sizeof(*this))
=======
#include "wtf/FastAllocBase.h"
#include "wtf/PassOwnPtr.h"

namespace blink {

class PLATFORM_EXPORT BeginScrollDisplayItem : public PairedBeginDisplayItem {
public:
    BeginScrollDisplayItem(const DisplayItemClientWrapper& client, Type type, const IntSize& currentOffset)
        : PairedBeginDisplayItem(client, type)
>>>>>>> miniblink49
        , m_currentOffset(currentOffset)
    {
        ASSERT(isScrollType(type));
    }

<<<<<<< HEAD
    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

    const IntSize& currentOffset() const { return m_currentOffset; }
=======
    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;
>>>>>>> miniblink49

private:
#ifndef NDEBUG
    void dumpPropertiesAsDebugString(WTF::StringBuilder&) const final;
#endif
<<<<<<< HEAD
    bool equals(const DisplayItem& other) const final
    {
        return DisplayItem::equals(other) && m_currentOffset == static_cast<const BeginScrollDisplayItem&>(other).m_currentOffset;
    }
=======
>>>>>>> miniblink49

    const IntSize m_currentOffset;
};

<<<<<<< HEAD
class PLATFORM_EXPORT EndScrollDisplayItem final : public PairedEndDisplayItem {
public:
    EndScrollDisplayItem(const DisplayItemClient& client, Type type)
        : PairedEndDisplayItem(client, type, sizeof(*this))
=======
class PLATFORM_EXPORT EndScrollDisplayItem : public PairedEndDisplayItem {
public:
    EndScrollDisplayItem(const DisplayItemClientWrapper& client, Type type)
        : PairedEndDisplayItem(client, type)
>>>>>>> miniblink49
    {
        ASSERT(isEndScrollType(type));
    }

<<<<<<< HEAD
    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

private:
#if DCHECK_IS_ON()
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final
    {
        return DisplayItem::isScrollType(otherType);
    }
=======
    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;

private:
#if ENABLE(ASSERT)
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final { return DisplayItem::isScrollType(otherType); }
>>>>>>> miniblink49
#endif
};

} // namespace blink

#endif // ScrollDisplayItem_h

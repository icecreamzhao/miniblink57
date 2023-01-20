// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TransformDisplayItem_h
#define TransformDisplayItem_h

#include "platform/graphics/paint/DisplayItem.h"
#include "platform/transforms/AffineTransform.h"
<<<<<<< HEAD

namespace blink {

class PLATFORM_EXPORT BeginTransformDisplayItem final
    : public PairedBeginDisplayItem {
public:
    BeginTransformDisplayItem(const DisplayItemClient& client,
        const AffineTransform& transform)
        : PairedBeginDisplayItem(client, kBeginTransform, sizeof(*this))
        , m_transform(transform)
    {
    }

    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

    const AffineTransform& transform() const { return m_transform; }
=======
#include "wtf/PassOwnPtr.h"

namespace blink {

class PLATFORM_EXPORT BeginTransformDisplayItem : public PairedBeginDisplayItem {
public:
    BeginTransformDisplayItem(const DisplayItemClientWrapper& client, const AffineTransform& transform)
        : PairedBeginDisplayItem(client, BeginTransform)
        , m_transform(transform) { }

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
        return DisplayItem::equals(other) && m_transform == static_cast<const BeginTransformDisplayItem&>(other).m_transform;
    }
=======
>>>>>>> miniblink49

    const AffineTransform m_transform;
};

<<<<<<< HEAD
class PLATFORM_EXPORT EndTransformDisplayItem final
    : public PairedEndDisplayItem {
public:
    EndTransformDisplayItem(const DisplayItemClient& client)
        : PairedEndDisplayItem(client, kEndTransform, sizeof(*this))
    {
    }

    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

private:
#if DCHECK_IS_ON()
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final
    {
        return otherType == kBeginTransform;
    }
=======
class PLATFORM_EXPORT EndTransformDisplayItem : public PairedEndDisplayItem {
public:
    EndTransformDisplayItem(const DisplayItemClientWrapper& client)
        : PairedEndDisplayItem(client, EndTransform) { }

    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;

private:
#if ENABLE(ASSERT)
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final { return otherType == BeginTransform; }
>>>>>>> miniblink49
#endif
};

} // namespace blink

#endif // TransformDisplayItem_h

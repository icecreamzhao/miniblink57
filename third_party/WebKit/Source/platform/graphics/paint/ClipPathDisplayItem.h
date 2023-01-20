// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ClipPathDisplayItem_h
#define ClipPathDisplayItem_h

#include "platform/PlatformExport.h"
#include "platform/graphics/Path.h"
#include "platform/graphics/paint/DisplayItem.h"
#include "third_party/skia/include/core/SkPath.h"
<<<<<<< HEAD

namespace blink {

class PLATFORM_EXPORT BeginClipPathDisplayItem final
    : public PairedBeginDisplayItem {
public:
    BeginClipPathDisplayItem(const DisplayItemClient& client,
        const Path& clipPath)
        : PairedBeginDisplayItem(client, kBeginClipPath, sizeof(*this))
        , m_clipPath(clipPath.getSkPath())
    {
    }

    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

    void analyzeForGpuRasterization(SkPictureGpuAnalyzer&) const override;

private:
#ifndef NDEBUG
    void dumpPropertiesAsDebugString(WTF::StringBuilder&) const override;
#endif
    bool equals(const DisplayItem& other) const final
    {
        return DisplayItem::equals(other) && m_clipPath == static_cast<const BeginClipPathDisplayItem&>(other).m_clipPath;
    }

    const SkPath m_clipPath;
};

class PLATFORM_EXPORT EndClipPathDisplayItem final
    : public PairedEndDisplayItem {
public:
    EndClipPathDisplayItem(const DisplayItemClient& client)
        : PairedEndDisplayItem(client, kEndClipPath, sizeof(*this))
    {
    }

    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;

private:
#if DCHECK_IS_ON()
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final
    {
        return otherType == kBeginClipPath;
    }
=======
#include "wtf/PassOwnPtr.h"

namespace blink {

class PLATFORM_EXPORT BeginClipPathDisplayItem : public PairedBeginDisplayItem {
public:
    BeginClipPathDisplayItem(const DisplayItemClientWrapper& client, const Path& clipPath)
        : PairedBeginDisplayItem(client, BeginClipPath)
        , m_clipPath(clipPath.skPath()) { }

    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;

private:
    const SkPath m_clipPath;
#ifndef NDEBUG
    void dumpPropertiesAsDebugString(WTF::StringBuilder&) const override;
#endif
};

class PLATFORM_EXPORT EndClipPathDisplayItem : public PairedEndDisplayItem {
public:
    EndClipPathDisplayItem(const DisplayItemClientWrapper& client)
        : PairedEndDisplayItem(client, EndClipPath) { }

    void replay(GraphicsContext&) override;
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;

private:
#if ENABLE(ASSERT)
    bool isEndAndPairedWith(DisplayItem::Type otherType) const final { return otherType == BeginClipPath; }
>>>>>>> miniblink49
#endif
};

} // namespace blink

#endif // ClipPathDisplayItem_h

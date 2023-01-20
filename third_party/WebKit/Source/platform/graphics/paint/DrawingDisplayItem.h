// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DrawingDisplayItem_h
#define DrawingDisplayItem_h

<<<<<<< HEAD
#include "base/compiler_specific.h"
#include "platform/PlatformExport.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/geometry/FloatPoint.h"
#include "platform/graphics/paint/DisplayItem.h"
#include "third_party/skia/include/core/SkPicture.h"
#include "third_party/skia/include/core/SkRefCnt.h"

namespace blink {

class PLATFORM_EXPORT DrawingDisplayItem final : public DisplayItem {
public:
    DISABLE_CFI_PERF
    DrawingDisplayItem(const DisplayItemClient& client,
        Type type,
        sk_sp<const SkPicture> picture,
        bool knownToBeOpaque = false)
        : DisplayItem(client, type, sizeof(*this))
        , m_picture(picture && picture->approximateOpCount() ? std::move(picture)
                                                             : nullptr)
        , m_knownToBeOpaque(knownToBeOpaque)
    {
        DCHECK(isDrawingType(type));
    }

    void replay(GraphicsContext&) const override;
    void appendToWebDisplayItemList(const IntRect&,
        WebDisplayItemList*) const override;
=======
#include "platform/PlatformExport.h"
#include "platform/geometry/FloatPoint.h"
#include "platform/graphics/paint/DisplayItem.h"
#include "third_party/skia/include/core/SkPicture.h"
#include "wtf/PassOwnPtr.h"

namespace blink {

class PLATFORM_EXPORT DrawingDisplayItem : public DisplayItem {
public:
#if ENABLE(ASSERT)
    enum UnderInvalidationCheckingMode {
        CheckPicture, // Check if the new picture and the old picture are the same
        CheckBitmap, // Check if the new picture and the old picture produce the same bitmap
    };
#endif

    DrawingDisplayItem(const DisplayItemClientWrapper& client
        , Type type
        , PassRefPtr<const SkPicture> picture
#if ENABLE(ASSERT)
        , UnderInvalidationCheckingMode underInvalidationCheckingMode = CheckPicture
#endif
        )
        : DisplayItem(client, type)
        , m_picture(picture && picture->approximateOpCount() ? picture : nullptr)
#if ENABLE(ASSERT)
        , m_underInvalidationCheckingMode(underInvalidationCheckingMode)
#endif
    {
        ASSERT(isDrawingType(type));
    }

    virtual void replay(GraphicsContext&);
    void appendToWebDisplayItemList(WebDisplayItemList*) const override;
>>>>>>> miniblink49
    bool drawsContent() const override;

    const SkPicture* picture() const { return m_picture.get(); }

<<<<<<< HEAD
    bool knownToBeOpaque() const
    {
        DCHECK(RuntimeEnabledFeatures::slimmingPaintV2Enabled());
        return m_knownToBeOpaque;
    }

    void analyzeForGpuRasterization(SkPictureGpuAnalyzer&) const override;
=======
#if ENABLE(ASSERT)
    UnderInvalidationCheckingMode underInvalidationCheckingMode() const { return m_underInvalidationCheckingMode; }
#endif
>>>>>>> miniblink49

private:
#ifndef NDEBUG
    void dumpPropertiesAsDebugString(WTF::StringBuilder&) const override;
#endif
<<<<<<< HEAD
    bool equals(const DisplayItem& other) const final;

    sk_sp<const SkPicture> m_picture;

    // True if there are no transparent areas. Only used for SlimmingPaintV2.
    const bool m_knownToBeOpaque;
=======

    RefPtr<const SkPicture> m_picture;

#if ENABLE(ASSERT)
    UnderInvalidationCheckingMode m_underInvalidationCheckingMode;
#endif
>>>>>>> miniblink49
};

} // namespace blink

#endif // DrawingDisplayItem_h

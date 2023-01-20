// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SkPictureBuilder_h
#define SkPictureBuilder_h

<<<<<<< HEAD
#include "platform/PlatformExport.h"
#include "platform/geometry/FloatRect.h"
#include "platform/graphics/paint/DisplayItemClient.h"
#include "third_party/skia/include/core/SkRefCnt.h"
#include "wtf/Noncopyable.h"
#include <memory>

class SkMetaData;
class SkPicture;

namespace blink {

class GraphicsContext;
class PaintController;

// When slimming paint ships we can remove this SkPicture abstraction and
// rely on PaintController here.
class PLATFORM_EXPORT SkPictureBuilder final : public DisplayItemClient {
    WTF_MAKE_NONCOPYABLE(SkPictureBuilder);

public:
    // Constructs a new builder with the given bounds for the resulting recorded
    // picture. If |metadata| is specified, that metadata is propagated to the
    // builder's internal canvas. If |containingContext| is specified, the device
    // scale factor, printing, and disabled state are propagated to the builder's
    // internal context.
    // If a PaintController is passed, it is used as the PaintController for
    // painting the picture (and hence we can use its cache). Otherwise, a new
    // PaintController is used for the duration of the picture building, which
    // therefore has no caching.
    SkPictureBuilder(const FloatRect& bounds,
        SkMetaData* = nullptr,
        GraphicsContext* containingContext = nullptr,
        PaintController* = nullptr);
    ~SkPictureBuilder();

    GraphicsContext& context() { return *m_context; }

    // Returns a picture capturing all drawing performed on the builder's context
    // since construction.
    sk_sp<SkPicture> endRecording();

    // DisplayItemClient methods
    String debugName() const final { return "SkPictureBuilder"; }
    LayoutRect visualRect() const final { return LayoutRect(); }

private:
    PaintController* m_paintController;
    std::unique_ptr<PaintController> m_paintControllerPtr;
    std::unique_ptr<GraphicsContext> m_context;
=======
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/paint/DisplayItemList.h"
#include "wtf/OwnPtr.h"

namespace blink {

// When slimming paint ships we can remove this SkPicture abstraction and
// rely on DisplayItemList here.
class SkPictureBuilder {
    WTF_MAKE_NONCOPYABLE(SkPictureBuilder);
    STACK_ALLOCATED();
public:
    SkPictureBuilder(const FloatRect& bounds, SkMetaData* metaData = 0, GraphicsContext* containingContext = 0)
        : m_bounds(bounds)
    {
        GraphicsContext::DisabledMode disabledMode = GraphicsContext::NothingDisabled;
        if (containingContext && containingContext->contextDisabled())
            disabledMode = GraphicsContext::FullyDisabled;

        if (RuntimeEnabledFeatures::slimmingPaintEnabled()) {
            m_displayItemList = DisplayItemList::create();
            m_context = adoptPtr(new GraphicsContext(m_displayItemList.get(), disabledMode, metaData));
        } else {
            m_context = GraphicsContext::deprecatedCreateWithCanvas(nullptr, disabledMode, metaData);
            m_context->beginRecording(m_bounds);
        }

        if (containingContext) {
            m_context->setDeviceScaleFactor(containingContext->deviceScaleFactor());
            m_context->setPrinting(containingContext->printing());
        }
    }

    GraphicsContext& context() { return *m_context; }

    PassRefPtr<const SkPicture> endRecording()
    {
        if (!RuntimeEnabledFeatures::slimmingPaintEnabled())
            return m_context->endRecording();

        m_context->beginRecording(m_bounds);
        m_displayItemList->commitNewDisplayItemsAndReplay(*m_context);
        return m_context->endRecording();
    }

private:
    OwnPtr<DisplayItemList> m_displayItemList;
    OwnPtr<GraphicsContext> m_context;
>>>>>>> miniblink49
    FloatRect m_bounds;
};

} // namespace blink

#endif // SkPictureBuilder_h

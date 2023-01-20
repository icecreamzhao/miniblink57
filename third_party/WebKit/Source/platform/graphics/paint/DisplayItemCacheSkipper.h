// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DisplayItemCacheSkipper_h
#define DisplayItemCacheSkipper_h

<<<<<<< HEAD
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/paint/PaintController.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"

namespace blink {

class DisplayItemCacheSkipper final {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
    WTF_MAKE_NONCOPYABLE(DisplayItemCacheSkipper);

=======
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/paint/DisplayItemList.h"

namespace blink {

class DisplayItemCacheSkipper {
>>>>>>> miniblink49
public:
    DisplayItemCacheSkipper(GraphicsContext& context)
        : m_context(context)
    {
<<<<<<< HEAD
        context.getPaintController().beginSkippingCache();
    }
    ~DisplayItemCacheSkipper()
    {
        m_context.getPaintController().endSkippingCache();
=======
        if (RuntimeEnabledFeatures::slimmingPaintEnabled())
            context.displayItemList()->beginSkippingCache();
    }
    ~DisplayItemCacheSkipper()
    {
        if (RuntimeEnabledFeatures::slimmingPaintEnabled())
            m_context.displayItemList()->endSkippingCache();
>>>>>>> miniblink49
    }

private:
    GraphicsContext& m_context;
};

} // namespace blink

#endif // DisplayItemCacheSkipper_h

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebDisplayItemList_h
#define WebDisplayItemList_h

#include "WebBlendMode.h"
#include "WebFloatPoint.h"
#include "WebFloatRect.h"
#include "WebRect.h"
#include "WebSize.h"
#include "WebVector.h"

<<<<<<< HEAD
#include "third_party/skia/include/core/SkBlendMode.h"
#include "third_party/skia/include/core/SkRefCnt.h"

class SkColorFilter;
class SkMatrix44;
class SkPath;
class SkPicture;
struct SkRect;
class SkRRect;

namespace cc {
class FilterOperations;
}

namespace gfx {
class ColorSpace;
}

namespace blink {
=======
#include "third_party/skia/include/core/SkColorFilter.h"
#include "third_party/skia/include/core/SkRRect.h"
#include "third_party/skia/include/core/SkRegion.h"
#include "third_party/skia/include/core/SkXfermode.h"
#include "third_party/skia/include/utils/SkMatrix44.h"

class SkImageFilter;
class SkMatrix44;
class SkPicture;

namespace blink {
class WebFilterOperations;
>>>>>>> miniblink49

// An ordered list of items representing content to be rendered (stored in
// 'drawing' items) and operations to be performed when rendering this content
// (stored in 'clip', 'transform', 'filter', etc...). For more details see:
// http://dev.chromium.org/blink/slimming-paint.
class WebDisplayItemList {
public:
    virtual ~WebDisplayItemList() { }

<<<<<<< HEAD
    virtual void appendDrawingItem(const WebRect& visualRect,
        sk_sp<const SkPicture>) { }

    virtual void appendClipItem(const WebRect& clipRect,
        const WebVector<SkRRect>& roundedClipRects) { }
    virtual void appendEndClipItem() { }
    virtual void appendClipPathItem(const SkPath&, bool antialias) { }
    virtual void appendEndClipPathItem() { }
    virtual void appendFloatClipItem(const WebFloatRect& clipRect) { }
    virtual void appendEndFloatClipItem() { }
    virtual void appendTransformItem(const SkMatrix44&) { }
    virtual void appendEndTransformItem() { }
    virtual void appendCompositingItem(float opacity,
        SkBlendMode,
        SkRect* bounds,
        SkColorFilter*) { }
    virtual void appendEndCompositingItem() { }

    // TODO(loyso): This should use CompositorFilterOperation. crbug.com/584551
    virtual void appendFilterItem(const cc::FilterOperations&,
        const WebFloatRect& filter_bounds,
        const WebFloatPoint& origin) { }
    virtual void appendEndFilterItem() { }

    // Scroll containers are identified by an opaque pointer.
    using ScrollContainerId = const void*;
    virtual void appendScrollItem(const WebSize& scrollOffset,
        ScrollContainerId) { }
    virtual void appendEndScrollItem() { }

    virtual void setIsSuitableForGpuRasterization(bool isSuitable) { }

    // Specifies the color space that the inputs of this display list were
    // pre-converted into. If this is specified, then rasterization must not
    // perform any color correction, and the result must be interpreted as being
    // in this color space.
    virtual void setImpliedColorSpace(const gfx::ColorSpace&) { }
=======
    // This grabs a ref on the passed-in SkPicture.
    virtual void appendDrawingItem(const SkPicture*) = 0;

    virtual void appendClipItem(const WebRect&, const WebVector<SkRRect>&) = 0;
    virtual void appendEndClipItem() = 0;
    virtual void appendClipPathItem(const SkPath&, SkRegion::Op, bool antialias) = 0;
    virtual void appendEndClipPathItem() = 0;
    virtual void appendFloatClipItem(const WebFloatRect&) = 0;
    virtual void appendEndFloatClipItem() = 0;
    virtual void appendTransformItem(const SkMatrix44&) = 0;
    virtual void appendEndTransformItem() = 0;
    virtual void appendCompositingItem(float opacity,
        SkXfermode::Mode, SkRect* bounds, SkColorFilter*) = 0;
    virtual void appendEndCompositingItem() = 0;

    virtual void appendFilterItem(const WebFilterOperations&, const WebFloatRect& bounds) = 0;
    virtual void appendEndFilterItem() = 0;

    // Scroll containers are identified by an opaque pointer.
    using ScrollContainerId = const void*;
    virtual void appendScrollItem(const WebSize& scrollOffset, ScrollContainerId) = 0;
    virtual void appendEndScrollItem() = 0;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebDisplayItemList_h
<<<<<<< HEAD
=======

>>>>>>> miniblink49

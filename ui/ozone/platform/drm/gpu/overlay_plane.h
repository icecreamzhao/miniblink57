// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_OZONE_PLATFORM_DRM_GPU_OVERLAY_PLANE_H_
#define UI_OZONE_PLATFORM_DRM_GPU_OVERLAY_PLANE_H_

#include <vector>

#include "base/bind.h"
#include "base/memory/ref_counted.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/overlay_transform.h"
#include "ui/ozone/ozone_export.h"

namespace ui {

class ScanoutBuffer;

struct OverlayPlane;
typedef std::vector<OverlayPlane> OverlayPlaneList;

struct OZONE_EXPORT OverlayPlane {
    // Simpler constructor for the primary plane.
    explicit OverlayPlane(const scoped_refptr<ScanoutBuffer>& buffer);

    OverlayPlane(const scoped_refptr<ScanoutBuffer>& buffer,
        int z_order,
        gfx::OverlayTransform plane_transform,
        const gfx::Rect& display_bounds,
        const gfx::RectF& crop_rect);

    // This represents a callback function which can handle post processing
    // operations like scaling, format conversion etc of the buffer bound to this
    // plane and return the processed buffer.
    typedef base::Callback<scoped_refptr<ScanoutBuffer>(const gfx::Size& size,
        uint32_t format)>
        ProcessBufferCallback;
    OverlayPlane(const scoped_refptr<ScanoutBuffer>& buffer,
        int z_order,
        gfx::OverlayTransform plane_transform,
        const gfx::Rect& display_bounds,
        const gfx::RectF& crop_rect,
        const ProcessBufferCallback& processing_callback);

    bool operator<(const OverlayPlane& plane) const;

    ~OverlayPlane();

    // Returns the primary plane in |overlays|.
    static const OverlayPlane* GetPrimaryPlane(const OverlayPlaneList& overlays);

    scoped_refptr<ScanoutBuffer> buffer;
    int z_order = 0;
    gfx::OverlayTransform plane_transform;
    gfx::Rect display_bounds;
    gfx::RectF crop_rect;
    ProcessBufferCallback processing_callback;
};

} // namespace ui

#endif // UI_OZONE_PLATFORM_DRM_GPU_OVERLAY_PLANE_H_

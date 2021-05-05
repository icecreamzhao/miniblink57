// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_OZONE_PLATFORM_DRM_GPU_DRM_WINDOW_H_
#define UI_OZONE_PLATFORM_DRM_GPU_DRM_WINDOW_H_

#include <vector>

#include "base/macros.h"
#include "base/timer/timer.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/swap_result.h"
#include "ui/gfx/vsync_provider.h"
#include "ui/ozone/ozone_export.h"
#include "ui/ozone/platform/drm/gpu/overlay_plane.h"
#include "ui/ozone/platform/drm/gpu/page_flip_request.h"
#include "ui/ozone/public/surface_ozone_egl.h"

class SkBitmap;

namespace gfx {
class Point;
class Rect;
} // namespace gfx

namespace ui {

class DrmBuffer;
class DrmDevice;
class DrmDeviceManager;
class DrmOverlayValidator;
class HardwareDisplayController;
struct OverlayCheck_Params;
class ScanoutBufferGenerator;
class ScreenManager;

// The GPU object representing a window.
//
// The main purpose of this object is to associate drawing surfaces with
// displays. A surface created with the same id as the window (from
// GetAcceleratedWidget()) will paint onto that window. A window with
// the same bounds as a display will paint onto that display.
//
// If there's no display whose bounds match the window's, the window is
// disconnected and its contents will not be visible to the user.
class OZONE_EXPORT DrmWindow {
public:
    DrmWindow(gfx::AcceleratedWidget widget,
        DrmDeviceManager* device_manager,
        ScreenManager* screen_manager);

    ~DrmWindow();

    gfx::Rect bounds() const { return bounds_; }

    void Initialize(ScanoutBufferGenerator* buffer_generator);

    void Shutdown();

    // Returns the accelerated widget associated with the window.
    gfx::AcceleratedWidget GetAcceleratedWidget();

    // Returns the current controller the window is displaying on. Callers should
    // not cache the result as the controller may change as the window is moved.
    HardwareDisplayController* GetController();

    void SetController(HardwareDisplayController* controller);

    // Called when the window is resized/moved.
    void SetBounds(const gfx::Rect& bounds);

    // Update the HW cursor bitmap & move to specified location. If
    // the bitmap is empty, the cursor is hidden.
    void SetCursor(const std::vector<SkBitmap>& bitmaps,
        const gfx::Point& location,
        int frame_delay_ms);

    // Update the HW cursor bitmap & move to specified location. If
    // the bitmap is empty, the cursor is hidden.
    void SetCursorWithoutAnimations(const std::vector<SkBitmap>& bitmaps,
        const gfx::Point& location);

    // Move the HW cursor to the specified location.
    void MoveCursor(const gfx::Point& location);

    void SchedulePageFlip(const std::vector<OverlayPlane>& planes,
        const SwapCompletionCallback& callback);
    std::vector<OverlayCheck_Params> TestPageFlip(
        const std::vector<OverlayCheck_Params>& overlay_params);

    // Returns the last buffer associated with this window.
    const OverlayPlane* GetLastModesetBuffer();

    void GetVSyncParameters(
        const gfx::VSyncProvider::UpdateVSyncCallback& callback) const;

private:
    // Draw the last set cursor & update the cursor plane.
    void ResetCursor(bool bitmap_only);

    // Draw next frame in an animated cursor.
    void OnCursorAnimationTimeout();

    // When |controller_| changes this is called to reallocate the cursor buffers
    // since the allocation DRM device may have changed.
    void UpdateCursorBuffers();

    gfx::AcceleratedWidget widget_;

    DrmDeviceManager* device_manager_; // Not owned.
    ScreenManager* screen_manager_; // Not owned.

    // The current bounds of the window.
    gfx::Rect bounds_;

    // The controller associated with the current window. This may be nullptr if
    // the window isn't over an active display.
    HardwareDisplayController* controller_ = nullptr;
    scoped_ptr<DrmOverlayValidator> overlay_validator_;

    base::RepeatingTimer cursor_timer_;

    scoped_refptr<DrmBuffer> cursor_buffers_[2];
    int cursor_frontbuffer_ = 0;

    std::vector<SkBitmap> cursor_bitmaps_;
    gfx::Point cursor_location_;
    int cursor_frame_ = 0;
    int cursor_frame_delay_ms_ = 0;

    OverlayPlaneList last_submitted_planes_;

    bool force_buffer_reallocation_ = false;

    DISALLOW_COPY_AND_ASSIGN(DrmWindow);
};

} // namespace ui

#endif // UI_OZONE_PLATFORM_DRM_GPU_DRM_WINDOW_H_

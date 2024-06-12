// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/views/mus/screen_mus.h"

// #include "components/mus/public/interfaces/window_manager_constants.mojom.h"
#include "mojo/converters/geometry/geometry_type_converters.h"
#include "mojo/shell/public/cpp/connection.h"
#include "mojo/shell/public/cpp/shell.h"
#include "ui/gfx/display_finder.h"
#include "ui/gfx/display_observer.h"
#include "ui/views/mus/screen_mus_delegate.h"
#include "ui/views/mus/window_manager_frame_values.h"

namespace mojo {

template <>
struct TypeConverter<gfx::Display, mus::mojom::DisplayPtr> {
    static gfx::Display Convert(const mus::mojom::DisplayPtr& input)
    {
        gfx::Display result(input->id, input->bounds.To<gfx::Rect>());
        result.set_work_area(input->work_area.To<gfx::Rect>());
        result.set_device_scale_factor(input->device_pixel_ratio);
        switch (input->rotation) {
        case mus::mojom::Rotation::VALUE_0:
            result.set_rotation(gfx::Display::ROTATE_0);
            break;
        case mus::mojom::Rotation::VALUE_90:
            result.set_rotation(gfx::Display::ROTATE_90);
            break;
        case mus::mojom::Rotation::VALUE_180:
            result.set_rotation(gfx::Display::ROTATE_180);
            break;
        case mus::mojom::Rotation::VALUE_270:
            result.set_rotation(gfx::Display::ROTATE_270);
            break;
        }
        switch (input->touch_support) {
        case mus::mojom::TouchSupport::UNKNOWN:
            result.set_touch_support(gfx::Display::TOUCH_SUPPORT_UNKNOWN);
            break;
        case mus::mojom::TouchSupport::AVAILABLE:
            result.set_touch_support(gfx::Display::TOUCH_SUPPORT_AVAILABLE);
            break;
        case mus::mojom::TouchSupport::UNAVAILABLE:
            result.set_touch_support(gfx::Display::TOUCH_SUPPORT_UNAVAILABLE);
            break;
        }
        return result;
    }
};

template <>
struct TypeConverter<views::WindowManagerFrameValues,
    mus::mojom::FrameDecorationValuesPtr> {
    static views::WindowManagerFrameValues Convert(
        const mus::mojom::FrameDecorationValuesPtr& input)
    {
        views::WindowManagerFrameValues result;
        result.normal_insets = input->normal_client_area_insets.To<gfx::Insets>();
        result.maximized_insets = input->maximized_client_area_insets.To<gfx::Insets>();
        result.max_title_bar_button_width = input->max_title_bar_button_width;
        return result;
    }
};

} // namespace mojo

namespace views {

ScreenMus::ScreenMus(ScreenMusDelegate* delegate)
    : delegate_(delegate)
    , primary_display_index_(0)
    , display_manager_observer_binding_(this)
{
}

ScreenMus::~ScreenMus() { }

void ScreenMus::Init(mojo::Shell* shell)
{
    gfx::Screen::SetScreenInstance(this);

    shell->ConnectToInterface("mojo:mus", &display_manager_);

    display_manager_->AddObserver(
        display_manager_observer_binding_.CreateInterfacePtrAndBind());
    // We need the set of displays before we can continue. Wait for it.
    display_manager_observer_binding_.WaitForIncomingMethodCall();

    // The WaitForIncomingMethodCall() should have supplied the set of Displays.
    DCHECK(displays_.size());
}

int ScreenMus::FindDisplayIndexById(int64_t id) const
{
    for (size_t i = 0; i < displays_.size(); ++i) {
        if (displays_[i].id() == id)
            return static_cast<int>(i);
    }
    return -1;
}

void ScreenMus::ProcessDisplayChanged(const gfx::Display& changed_display,
    bool is_primary)
{
    const int display_index = FindDisplayIndexById(changed_display.id());
    if (display_index == -1) {
        displays_.push_back(changed_display);
        if (is_primary)
            primary_display_index_ = static_cast<int>(displays_.size()) - 1;
        FOR_EACH_OBSERVER(gfx::DisplayObserver, observers_,
            OnDisplayAdded(changed_display));
        return;
    }

    gfx::Display* local_display = &displays_[display_index];
    uint32_t changed_values = 0;
    if (is_primary && display_index != primary_display_index_) {
        primary_display_index_ = display_index;
        // ash::DisplayManager only notifies for the Display gaining primary, not
        // the one losing it.
        changed_values |= gfx::DisplayObserver::DISPLAY_METRIC_PRIMARY;
    }
    if (local_display->bounds() != changed_display.bounds()) {
        local_display->set_bounds(changed_display.bounds());
        changed_values |= gfx::DisplayObserver::DISPLAY_METRIC_BOUNDS;
    }
    if (local_display->work_area() != changed_display.work_area()) {
        local_display->set_work_area(changed_display.work_area());
        changed_values |= gfx::DisplayObserver::DISPLAY_METRIC_WORK_AREA;
    }
    if (local_display->rotation() != changed_display.rotation()) {
        local_display->set_rotation(changed_display.rotation());
        changed_values |= gfx::DisplayObserver::DISPLAY_METRIC_ROTATION;
    }
    if (local_display->device_scale_factor() != changed_display.device_scale_factor()) {
        local_display->set_device_scale_factor(
            changed_display.device_scale_factor());
        changed_values |= gfx::DisplayObserver::DISPLAY_METRIC_DEVICE_SCALE_FACTOR;
    }
    FOR_EACH_OBSERVER(gfx::DisplayObserver, observers_,
        OnDisplayMetricsChanged(*local_display, changed_values));
}

gfx::Point ScreenMus::GetCursorScreenPoint()
{
    NOTIMPLEMENTED();
    return gfx::Point();
}

gfx::NativeWindow ScreenMus::GetWindowUnderCursor()
{
    NOTIMPLEMENTED();
    return nullptr;
}

gfx::NativeWindow ScreenMus::GetWindowAtScreenPoint(const gfx::Point& point)
{
    NOTIMPLEMENTED();
    return nullptr;
}

gfx::Display ScreenMus::GetPrimaryDisplay() const
{
    return displays_[primary_display_index_];
}

gfx::Display ScreenMus::GetDisplayNearestWindow(gfx::NativeView view) const
{
    NOTIMPLEMENTED();
    return GetPrimaryDisplay();
}

gfx::Display ScreenMus::GetDisplayNearestPoint(const gfx::Point& point) const
{
    return *gfx::FindDisplayNearestPoint(displays_, point);
}

int ScreenMus::GetNumDisplays() const
{
    return static_cast<int>(displays_.size());
}

std::vector<gfx::Display> ScreenMus::GetAllDisplays() const
{
    return displays_;
}

gfx::Display ScreenMus::GetDisplayMatching(const gfx::Rect& match_rect) const
{
    const gfx::Display* match = gfx::FindDisplayWithBiggestIntersection(displays_, match_rect);
    return match ? *match : GetPrimaryDisplay();
}

void ScreenMus::AddObserver(gfx::DisplayObserver* observer)
{
    observers_.AddObserver(observer);
}

void ScreenMus::RemoveObserver(gfx::DisplayObserver* observer)
{
    observers_.RemoveObserver(observer);
}

void ScreenMus::OnDisplays(mojo::Array<mus::mojom::DisplayPtr> displays)
{
    // This should only be called once from Init() before any observers have been
    // added.
    DCHECK(displays_.empty());
    displays_ = displays.To<std::vector<gfx::Display>>();
    for (size_t i = 0; i < displays.size(); ++i) {
        if (displays[i]->is_primary) {
            primary_display_index_ = static_cast<int>(i);
            // TODO(sky): Make WindowManagerFrameValues per display.
            WindowManagerFrameValues frame_values = displays[i]->frame_decoration_values.To<WindowManagerFrameValues>();
            WindowManagerFrameValues::SetInstance(frame_values);
        }
    }
}

void ScreenMus::OnDisplaysChanged(
    mojo::Array<mus::mojom::DisplayPtr> transport_displays)
{
    for (size_t i = 0; i < transport_displays.size(); ++i) {
        const bool is_primary = transport_displays[i]->is_primary;
        ProcessDisplayChanged(transport_displays[i].To<gfx::Display>(), is_primary);
        if (is_primary) {
            WindowManagerFrameValues frame_values = transport_displays[i]
                                                        ->frame_decoration_values.To<WindowManagerFrameValues>();
            WindowManagerFrameValues::SetInstance(frame_values);
            delegate_->OnWindowManagerFrameValuesChanged();
        }
    }
}

void ScreenMus::OnDisplayRemoved(int64_t id)
{
    const int index = FindDisplayIndexById(id);
    DCHECK_NE(-1, index);
    // Another display must become primary before the existing primary is
    // removed.
    DCHECK_NE(index, primary_display_index_);
    const gfx::Display display = displays_[index];
    FOR_EACH_OBSERVER(gfx::DisplayObserver, observers_,
        OnDisplayRemoved(display));
}

} // namespace views

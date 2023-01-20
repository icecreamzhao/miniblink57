// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebDeviceEmulationParams_h
#define WebDeviceEmulationParams_h

#include "../platform/WebFloatPoint.h"
#include "../platform/WebPoint.h"
#include "../platform/WebRect.h"
#include "../platform/WebSize.h"
<<<<<<< HEAD
#include "../platform/modules/screen_orientation/WebScreenOrientationType.h"
=======
>>>>>>> miniblink49

namespace blink {

// All sizes are measured in device independent pixels.
struct WebDeviceEmulationParams {
    // For mobile, |screenSize| and |viewPosition| are used.
    // For desktop, screen size and view position are preserved.
<<<<<<< HEAD
    enum ScreenPosition { Desktop,
        Mobile,
        ScreenPositionLast = Mobile };
=======
    enum ScreenPosition {
        Desktop,
        Mobile,
        ScreenPositionLast = Mobile
    };
>>>>>>> miniblink49

    ScreenPosition screenPosition;

    // Emulated screen size. Used with |screenPosition == Mobile|.
    WebSize screenSize;

    // Position of view on the screen. Used with |screenPosition == Mobile|.
    WebPoint viewPosition;

    // If zero, the original device scale factor is preserved.
    float deviceScaleFactor;

    // Emulated view size. Empty size means no override.
    WebSize viewSize;

<<<<<<< HEAD
    // Whether emulated view should be scaled down if necessary to fit into
    // available space.
=======
    // Whether emulated view should be scaled down if necessary to fit into available space.
>>>>>>> miniblink49
    bool fitToView;

    // Offset of emulated view inside available space, not in fit to view mode.
    WebFloatPoint offset;

    // Scale of emulated view inside available space, not in fit to view mode.
    float scale;

<<<<<<< HEAD
    // Optional screen orientation type, with WebScreenOrientationUndefined
    // value meaning no emulation necessary.
    WebScreenOrientationType screenOrientationType;

    // Screen orientation angle, used together with screenOrientationType.
    int screenOrientationAngle;

=======
>>>>>>> miniblink49
    WebDeviceEmulationParams()
        : screenPosition(Desktop)
        , deviceScaleFactor(0)
        , fitToView(false)
<<<<<<< HEAD
        , scale(1)
        , screenOrientationType(WebScreenOrientationUndefined)
        , screenOrientationAngle(0)
    {
    }
};

inline bool operator==(const WebDeviceEmulationParams& a,
    const WebDeviceEmulationParams& b)
{
    return a.screenPosition == b.screenPosition && a.screenSize == b.screenSize && a.viewPosition == b.viewPosition && a.deviceScaleFactor == b.deviceScaleFactor && a.viewSize == b.viewSize && a.fitToView == b.fitToView && a.offset == b.offset && a.scale == b.scale && a.screenOrientationType == b.screenOrientationType && a.screenOrientationAngle == b.screenOrientationAngle;
}

inline bool operator!=(const WebDeviceEmulationParams& a,
    const WebDeviceEmulationParams& b)
=======
        , scale(1) { }
};

inline bool operator==(const WebDeviceEmulationParams& a, const WebDeviceEmulationParams& b)
{
    return a.screenPosition == b.screenPosition && a.screenSize == b.screenSize && a.viewPosition == b.viewPosition && a.deviceScaleFactor == b.deviceScaleFactor && a.viewSize == b.viewSize && a.fitToView == b.fitToView && a.offset == b.offset && a.scale == b.scale;
}

inline bool operator!=(const WebDeviceEmulationParams& a, const WebDeviceEmulationParams& b)
>>>>>>> miniblink49
{
    return !(a == b);
}

} // namespace blink

#endif

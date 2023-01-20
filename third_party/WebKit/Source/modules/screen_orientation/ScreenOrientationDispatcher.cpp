// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/screen_orientation/ScreenOrientationDispatcher.h"

#include "public/platform/Platform.h"

namespace blink {

ScreenOrientationDispatcher& ScreenOrientationDispatcher::instance()
{
<<<<<<< HEAD
    DEFINE_STATIC_LOCAL(ScreenOrientationDispatcher, screenOrientationDispatcher,
        (new ScreenOrientationDispatcher));
    return screenOrientationDispatcher;
}

ScreenOrientationDispatcher::ScreenOrientationDispatcher() { }
=======
    DEFINE_STATIC_LOCAL(Persistent<ScreenOrientationDispatcher>, screenOrientationDispatcher, (new ScreenOrientationDispatcher()));
    return *screenOrientationDispatcher;
}

ScreenOrientationDispatcher::ScreenOrientationDispatcher()
{
}
>>>>>>> miniblink49

DEFINE_TRACE(ScreenOrientationDispatcher)
{
    PlatformEventDispatcher::trace(visitor);
}

void ScreenOrientationDispatcher::startListening()
{
<<<<<<< HEAD
    Platform::current()->startListening(WebPlatformEventTypeScreenOrientation, 0);
=======
    Platform::current()->startListening(WebPlatformEventScreenOrientation, 0);
>>>>>>> miniblink49
}

void ScreenOrientationDispatcher::stopListening()
{
<<<<<<< HEAD
    Platform::current()->stopListening(WebPlatformEventTypeScreenOrientation);
=======
    Platform::current()->stopListening(WebPlatformEventScreenOrientation);
>>>>>>> miniblink49
}

} // namespace blink

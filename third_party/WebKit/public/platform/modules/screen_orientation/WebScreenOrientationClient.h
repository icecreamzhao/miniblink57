// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebScreenOrientationClient_h
#define WebScreenOrientationClient_h

#include "public/platform/modules/screen_orientation/WebScreenOrientationLockType.h"
<<<<<<< HEAD
#include <memory>
=======
>>>>>>> miniblink49

namespace blink {

class WebLockOrientationCallback;

// Client handling screen orientation locking for a given WebFrame.
class WebScreenOrientationClient {
public:
    virtual ~WebScreenOrientationClient() { }

<<<<<<< HEAD
    // Request a screen orientation lock. The implementation will own the
    // callback.
    virtual void lockOrientation(WebScreenOrientationLockType,
        std::unique_ptr<WebLockOrientationCallback>)
        = 0;

    // Unlock the screen orientation. No-op if the screen orientation was not
    // locked.
=======
    // Request a screen orientation lock. The implementation will own the callback.
    virtual void lockOrientation(WebScreenOrientationLockType, WebLockOrientationCallback*) = 0;

    // Unlock the screen orientation. No-op if the screen orientation was not locked.
>>>>>>> miniblink49
    virtual void unlockOrientation() = 0;
};

} // namespace blink

#endif // WebScreenOrientationClient_h

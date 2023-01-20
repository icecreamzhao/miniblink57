// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebScrollbarBehavior_h
#define WebScrollbarBehavior_h

<<<<<<< HEAD
#include "WebPointerProperties.h"

=======
>>>>>>> miniblink49
namespace blink {

struct WebPoint;
struct WebRect;

class WebScrollbarBehavior {
public:
<<<<<<< HEAD
    virtual ~WebScrollbarBehavior() { }
    virtual bool shouldCenterOnThumb(WebPointerProperties::Button,
        bool shiftKeyPressed,
        bool altKeyPressed)
    {
        return false;
    }
    virtual bool shouldSnapBackToDragOrigin(const WebPoint& eventPoint,
        const WebRect& scrollbarRect,
        bool isHorizontal)
    {
        return false;
    }
=======
    enum Button {
        ButtonNone = -1,
        ButtonLeft,
        ButtonMiddle,
        ButtonRight
    };
    virtual ~WebScrollbarBehavior() { }
    virtual bool shouldCenterOnThumb(Button, bool shiftKeyPressed, bool altKeyPressed) { return false; }
    virtual bool shouldSnapBackToDragOrigin(const WebPoint& eventPoint, const WebRect& scrollbarRect, bool isHorizontal) { return false; }
>>>>>>> miniblink49
};

} // namespace blink

#endif

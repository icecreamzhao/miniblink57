/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebInputEventConversion_h
#define WebInputEventConversion_h

<<<<<<< HEAD
#include "platform/PlatformMouseEvent.h"
#include "platform/PlatformTouchEvent.h"
#include "platform/scroll/ScrollTypes.h"
#include "public/platform/WebInputEvent.h"
#include "public/platform/WebMouseWheelEvent.h"
#include "web/WebExport.h"
#include "wtf/Compiler.h"
#include <vector>

namespace blink {

class KeyboardEvent;
class MouseEvent;
class LayoutItem;
class TouchEvent;
class WebGestureEvent;
class WebMouseEvent;
class WebKeyboardEvent;
class WebTouchEvent;
=======
#include "platform/PlatformGestureEvent.h"
#include "platform/PlatformKeyboardEvent.h"
#include "platform/PlatformMouseEvent.h"
#include "platform/PlatformTouchEvent.h"
#include "platform/PlatformWheelEvent.h"
#include "public/web/WebInputEvent.h"

namespace blink {

class GestureEvent;
class KeyboardEvent;
class MouseEvent;
class LayoutObject;
class TouchEvent;
class WebMouseEvent;
class WebMouseWheelEvent;
class WebKeyboardEvent;
class WebTouchEvent;
class WebGestureEvent;
class WheelEvent;
>>>>>>> miniblink49
class Widget;

// These classes are used to convert from WebInputEvent subclasses to
// corresponding WebCore events.

<<<<<<< HEAD
class WEB_EXPORT PlatformMouseEventBuilder
    : NON_EXPORTED_BASE(public PlatformMouseEvent) {
=======
class PlatformMouseEventBuilder : public PlatformMouseEvent {
>>>>>>> miniblink49
public:
    PlatformMouseEventBuilder(Widget*, const WebMouseEvent&);
};

<<<<<<< HEAD
// Converts a WebTouchPoint to a PlatformTouchPoint.
class WEB_EXPORT PlatformTouchPointBuilder
    : NON_EXPORTED_BASE(public PlatformTouchPoint) {
=======
class PlatformWheelEventBuilder : public PlatformWheelEvent {
public:
    PlatformWheelEventBuilder(Widget*, const WebMouseWheelEvent&);
};

class PlatformGestureEventBuilder : public PlatformGestureEvent {
public:
    PlatformGestureEventBuilder(Widget*, const WebGestureEvent&);
};

class PlatformKeyboardEventBuilder : public PlatformKeyboardEvent {
public:
    PlatformKeyboardEventBuilder(const WebKeyboardEvent&);
    void setKeyType(Type);
    bool isCharacterKey() const;
};

// Converts a WebTouchPoint to a PlatformTouchPoint.
class PlatformTouchPointBuilder : public PlatformTouchPoint {
>>>>>>> miniblink49
public:
    PlatformTouchPointBuilder(Widget*, const WebTouchPoint&);
};

// Converts a WebTouchEvent to a PlatformTouchEvent.
<<<<<<< HEAD
class WEB_EXPORT PlatformTouchEventBuilder
    : NON_EXPORTED_BASE(public PlatformTouchEvent) {
=======
class PlatformTouchEventBuilder : public PlatformTouchEvent {
>>>>>>> miniblink49
public:
    PlatformTouchEventBuilder(Widget*, const WebTouchEvent&);
};

<<<<<<< HEAD
class WEB_EXPORT WebMouseEventBuilder
    : NON_EXPORTED_BASE(public WebMouseEvent) {
=======
class WebMouseEventBuilder : public WebMouseEvent {
>>>>>>> miniblink49
public:
    // Converts a MouseEvent to a corresponding WebMouseEvent.
    // NOTE: This is only implemented for mousemove, mouseover, mouseout,
    // mousedown and mouseup. If the event mapping fails, the event type will
    // be set to Undefined.
<<<<<<< HEAD
    WebMouseEventBuilder(const Widget*, const LayoutItem, const MouseEvent&);
    WebMouseEventBuilder(const Widget*, const LayoutItem, const TouchEvent&);
};

// Converts a KeyboardEvent to a corresponding WebKeyboardEvent.
// NOTE: For KeyboardEvent, this is only implemented for keydown,
// keyup, and keypress. If the event mapping fails, the event type will be set
// to Undefined.
class WEB_EXPORT WebKeyboardEventBuilder
    : NON_EXPORTED_BASE(public WebKeyboardEvent) {
=======
    WebMouseEventBuilder(const Widget*, const LayoutObject*, const MouseEvent&);
    WebMouseEventBuilder(const Widget*, const LayoutObject*, const TouchEvent&);
};

// Converts a WheelEvent to a corresponding WebMouseWheelEvent.
// If the event mapping fails, the event type will be set to Undefined.
class WebMouseWheelEventBuilder : public WebMouseWheelEvent {
public:
    WebMouseWheelEventBuilder(const Widget*, const LayoutObject*, const WheelEvent&);
};

// Converts a KeyboardEvent or PlatformKeyboardEvent to a
// corresponding WebKeyboardEvent.
// NOTE: For KeyboardEvent, this is only implemented for keydown,
// keyup, and keypress. If the event mapping fails, the event type will be set
// to Undefined.
class WebKeyboardEventBuilder : public WebKeyboardEvent {
>>>>>>> miniblink49
public:
    WebKeyboardEventBuilder(const KeyboardEvent&);
};

// Converts a TouchEvent to a corresponding WebTouchEvent.
// NOTE: WebTouchEvents have a cap on the number of WebTouchPoints. Any points
// exceeding that cap will be dropped.
<<<<<<< HEAD
class WEB_EXPORT WebTouchEventBuilder
    : NON_EXPORTED_BASE(public WebTouchEvent) {
public:
    WebTouchEventBuilder(const LayoutItem, const TouchEvent&);
};

// Return a new transformed WebGestureEvent by applying the Widget's scale
// and translation.
WEB_EXPORT WebGestureEvent TransformWebGestureEvent(Widget*,
    const WebGestureEvent&);
WEB_EXPORT WebMouseWheelEvent
TransformWebMouseWheelEvent(Widget*, const WebMouseWheelEvent&);

Vector<PlatformMouseEvent> WEB_EXPORT
createPlatformMouseEventVector(Widget*,
    const std::vector<const WebInputEvent*>&);
Vector<PlatformTouchEvent> WEB_EXPORT
createPlatformTouchEventVector(Widget*,
    const std::vector<const WebInputEvent*>&);
=======
class WebTouchEventBuilder : public WebTouchEvent {
public:
    WebTouchEventBuilder(const LayoutObject*, const TouchEvent&);
};

// Converts GestureEvent to a corresponding WebGestureEvent.
// NOTE: If event mapping fails, the type will be set to Undefined.
class WebGestureEventBuilder : public WebGestureEvent {
public:
    WebGestureEventBuilder(const LayoutObject*, const GestureEvent&);
};

unsigned toPlatformMouseEventModifiers(int webModifiers);
>>>>>>> miniblink49

} // namespace blink

#endif

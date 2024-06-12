// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/events/EventFactory.h"

#include "EventHeaders.h"
#include "core/frame/Deprecation.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {

Event* EventFactory::create(ExecutionContext* executionContext, const String& type)
{
    if (type == "AnimationEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventAnimationEvent);
        return AnimationEvent::create();
    }
    if (type == "BeforeUnloadEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventBeforeUnloadEvent);
        return BeforeUnloadEvent::create();
    }
    if (type == "CompositionEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventCompositionEvent);
        return CompositionEvent::create();
    }
    if (equalIgnoringCase(type, "CustomEvent")) {
        return CustomEvent::create();
    }
    if (type == "DragEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventDragEvent);
        return DragEvent::create();
    }
    if (type == "ErrorEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventErrorEvent);
        return ErrorEvent::create();
    }
    if (equalIgnoringCase(type, "Event")) {
        return Event::create();
    }
    if (type == "FocusEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventFocusEvent);
        return FocusEvent::create();
    }
    if (type == "HashChangeEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventHashChangeEvent);
        return HashChangeEvent::create();
    }
    if (equalIgnoringCase(type, "KeyboardEvent")) {
        return KeyboardEvent::create();
    }
    if (equalIgnoringCase(type, "MessageEvent")) {
        return MessageEvent::create();
    }
    if (equalIgnoringCase(type, "MouseEvent")) {
        return MouseEvent::create();
    }
    if (type == "MutationEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventMutationEvent);
        return MutationEvent::create();
    }
    if (type == "PageTransitionEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventPageTransitionEvent);
        return PageTransitionEvent::create();
    }
    if (type == "PopStateEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventPopStateEvent);
        return PopStateEvent::create();
    }
    if (type == "ProgressEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventProgressEvent);
        return ProgressEvent::create();
    }
    if (type == "TextEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventTextEvent);
        return TextEvent::create();
    }
    if (equalIgnoringCase(type, "TouchEvent") && RuntimeEnabledFeatures::touchEventFeatureDetectionEnabled()) {
        return TouchEvent::create();
    }
    if (type == "TransitionEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventTransitionEvent);
        return TransitionEvent::create();
    }
    if (equalIgnoringCase(type, "UIEvent")) {
        return UIEvent::create();
    }
    if (type == "WheelEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventWheelEvent);
        return WheelEvent::create();
    }
    if (type == "TrackEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventTrackEvent);
        return TrackEvent::create();
    }
    if (type == "WebKitAnimationEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventWebKitAnimationEvent);
        return AnimationEvent::create();
    }
    if (equalIgnoringCase(type, "Events")) {
        return Event::create();
    }
    if (equalIgnoringCase(type, "HTMLEvents")) {
        return Event::create();
    }
    if (type == "KeyboardEvents") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventKeyboardEvents);
        return KeyboardEvent::create();
    }
    if (equalIgnoringCase(type, "MouseEvents")) {
        return MouseEvent::create();
    }
    if (type == "MutationEvents") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventMutationEvents);
        return MutationEvent::create();
    }
    if (type == "SVGEvents") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventSVGEvents);
        return Event::create();
    }
    if (equalIgnoringCase(type, "UIEvents")) {
        return UIEvent::create();
    }
    if (type == "WebKitTransitionEvent") {
        UseCounter::count(executionContext, UseCounter::DocumentCreateEventWebKitTransitionEvent);
        return TransitionEvent::create();
    }
    return nullptr;
}

} // namespace blink

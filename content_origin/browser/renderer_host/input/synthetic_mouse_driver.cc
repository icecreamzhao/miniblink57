// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/renderer_host/input/synthetic_mouse_driver.h"

#include "content/browser/renderer_host/input/synthetic_gesture_target.h"

namespace content {

SyntheticMouseDriver::SyntheticMouseDriver()
    : last_modifiers_(0)
{
}

SyntheticMouseDriver::~SyntheticMouseDriver() { }

void SyntheticMouseDriver::DispatchEvent(SyntheticGestureTarget* target,
    const base::TimeTicks& timestamp)
{
    mouse_event_.setTimeStampSeconds(ConvertTimestampToSeconds(timestamp));
    target->DispatchInputEventToPlatform(mouse_event_);
}

void SyntheticMouseDriver::Press(float x,
    float y,
    int index,
    SyntheticPointerActionParams::Button button)
{
    DCHECK_EQ(index, 0);
    int modifiers = SyntheticPointerActionParams::GetWebMouseEventModifier(button);
    mouse_event_ = SyntheticWebMouseEventBuilder::Build(
        blink::WebInputEvent::MouseDown, x, y, modifiers | last_modifiers_);
    mouse_event_.clickCount = 1;
    mouse_event_.button = SyntheticPointerActionParams::GetWebMouseEventButton(button);
    last_modifiers_ = modifiers | last_modifiers_;
}

void SyntheticMouseDriver::Move(float x, float y, int index)
{
    DCHECK_EQ(index, 0);
    blink::WebMouseEvent::Button button = mouse_event_.button;
    int click_count = mouse_event_.clickCount;
    mouse_event_ = SyntheticWebMouseEventBuilder::Build(
        blink::WebInputEvent::MouseMove, x, y, last_modifiers_);
    mouse_event_.button = button;
    mouse_event_.clickCount = click_count;
}

void SyntheticMouseDriver::Release(
    int index,
    SyntheticPointerActionParams::Button button)
{
    DCHECK_EQ(index, 0);
    mouse_event_ = SyntheticWebMouseEventBuilder::Build(
        blink::WebInputEvent::MouseUp, mouse_event_.x, mouse_event_.y,
        last_modifiers_);
    mouse_event_.clickCount = 1;
    mouse_event_.button = SyntheticPointerActionParams::GetWebMouseEventButton(button);
    last_modifiers_ = last_modifiers_ & (~SyntheticPointerActionParams::GetWebMouseEventModifier(button));
}

bool SyntheticMouseDriver::UserInputCheck(
    const SyntheticPointerActionParams& params) const
{
    if (params.index() != 0)
        return false;

    if (params.pointer_action_type() == SyntheticPointerActionParams::PointerActionType::NOT_INITIALIZED) {
        return false;
    }

    if (params.pointer_action_type() == SyntheticPointerActionParams::PointerActionType::PRESS) {
        int modifiers = SyntheticPointerActionParams::GetWebMouseEventModifier(params.button());
        if (last_modifiers_ & modifiers)
            return false;
    }

    if (params.pointer_action_type() == SyntheticPointerActionParams::PointerActionType::RELEASE && mouse_event_.clickCount <= 0) {
        return false;
    }

    return true;
}

} // namespace content

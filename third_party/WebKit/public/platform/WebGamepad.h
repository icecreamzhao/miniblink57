// Copyright (C) 2011, Google Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.

#ifndef WebGamepad_h
#define WebGamepad_h

#include "WebCommon.h"

namespace blink {

#pragma pack(push, 4)

class WebGamepadButton {
public:
    WebGamepadButton()
        : pressed(false)
        , touched(false)
        , value(0.)
    {
    }
    WebGamepadButton(bool pressed, bool touched, double value)
        : pressed(pressed)
        , touched(touched)
        , value(value)
    {
    }
    bool pressed;
    bool touched;
    double value;
};

class WebGamepadVector {
public:
    WebGamepadVector()
        : notNull(false)
    {
    }

    bool notNull;
    float x, y, z;
};

class WebGamepadQuaternion {
public:
    WebGamepadQuaternion()
        : notNull(false)
    {
    }

    bool notNull;
    float x, y, z, w;
};

class WebGamepadPose {
public:
    WebGamepadPose()
        : notNull(false)
    {
    }

    bool notNull;

    bool hasOrientation;
    bool hasPosition;

    WebGamepadQuaternion orientation;
    WebGamepadVector position;
    WebGamepadVector angularVelocity;
    WebGamepadVector linearVelocity;
    WebGamepadVector angularAcceleration;
    WebGamepadVector linearAcceleration;
};

enum WebGamepadHand {
    GamepadHandNone = 0,
    GamepadHandLeft = 1,
    GamepadHandRight = 2
};

// This structure is intentionally POD and fixed size so that it can be shared
// memory between hardware polling threads and the rest of the browser. See
// also WebGamepads.h.
class WebGamepad {
public:
    static const size_t idLengthCap = 128;
    static const size_t mappingLengthCap = 16;
    static const size_t axesLengthCap = 16;
    static const size_t buttonsLengthCap = 32;

    WebGamepad()
        : connected(false)
        , timestamp(0)
        , axesLength(0)
        , buttonsLength(0)
        , displayId(0)
    {
        id[0] = 0;
        mapping[0] = 0;
    }

    // Is there a gamepad connected at this index?
    bool connected;

    // Device identifier (based on manufacturer, model, etc.).
    WebUChar id[idLengthCap];

    // Monotonically increasing value referring to when the data were last
    // updated.
    unsigned long long timestamp;

    // Number of valid entries in the axes array.
    unsigned axesLength;

    // Normalized values representing axes, in the range [-1..1].
    double axes[axesLengthCap];

    // Number of valid entries in the buttons array.
    unsigned buttonsLength;

    // Button states
    WebGamepadButton buttons[buttonsLengthCap];

    // Mapping type (for example "standard")
    WebUChar mapping[mappingLengthCap];

    WebGamepadPose pose;

    WebGamepadHand hand;

    unsigned displayId;
};

#pragma pack(pop)
}

#endif // WebGamepad_h

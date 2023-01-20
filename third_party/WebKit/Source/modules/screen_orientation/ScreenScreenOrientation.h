// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ScreenScreenOrientation_h
#define ScreenScreenOrientation_h

<<<<<<< HEAD
#include "core/frame/Screen.h"
=======
>>>>>>> miniblink49
#include "platform/Supplementable.h"
#include "platform/heap/Handle.h"

namespace blink {

class ScreenOrientation;
class Screen;
class ScriptState;

<<<<<<< HEAD
class ScreenScreenOrientation final
    : public GarbageCollected<ScreenScreenOrientation>,
      public Supplement<Screen> {
    USING_GARBAGE_COLLECTED_MIXIN(ScreenScreenOrientation);

=======
class ScreenScreenOrientation final : public GarbageCollected<ScreenScreenOrientation>, public HeapSupplement<Screen> {
    USING_GARBAGE_COLLECTED_MIXIN(ScreenScreenOrientation);
>>>>>>> miniblink49
public:
    static ScreenScreenOrientation& from(Screen&);

    static ScreenOrientation* orientation(ScriptState*, Screen&);

    DECLARE_VIRTUAL_TRACE();

private:
    static const char* supplementName();

    Member<ScreenOrientation> m_orientation;
};

} // namespace blink

#endif // ScreenScreenOrientation_h

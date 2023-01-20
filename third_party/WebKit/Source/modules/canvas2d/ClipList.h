// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ClipList_h
#define ClipList_h

#include "platform/graphics/GraphicsTypes.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/Vector.h"

class SkCanvas;
class SkPath;

namespace blink {

<<<<<<< HEAD
class ClipList {
    DISALLOW_NEW();

=======
class AffineTransform;

class ClipList {
>>>>>>> miniblink49
public:
    ClipList() { }
    ClipList(const ClipList&);
    ~ClipList() { }

    void clipPath(const SkPath&, AntiAliasingMode, const SkMatrix&);
    void playback(SkCanvas*) const;
<<<<<<< HEAD
    const SkPath& getCurrentClipPath() const;

private:
=======

private:

>>>>>>> miniblink49
    struct ClipOp {
        SkPath m_path;
        AntiAliasingMode m_antiAliasingMode;

        ClipOp();
        ClipOp(const ClipOp&);
    };

<<<<<<< HEAD
    // Number of clip ops that can be stored in a ClipList without resorting to
    // dynamic allocation
    static const size_t cInlineClipOpCapacity = 4;

    WTF::Vector<ClipOp, cInlineClipOpCapacity> m_clipList;
    SkPath m_currentClipPath;
=======
    // Number of clip ops that can be stored in a ClipList without resorting to dynamic allocation
    static const size_t cInlineClipOpCapacity = 4;

    WTF::Vector<ClipOp, cInlineClipOpCapacity> m_clipList;
>>>>>>> miniblink49
};

} // namespace blink

#endif

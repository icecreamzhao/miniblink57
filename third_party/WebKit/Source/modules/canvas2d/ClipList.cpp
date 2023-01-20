// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "modules/canvas2d/ClipList.h"

#include "platform/transforms/AffineTransform.h"
#include "third_party/skia/include/core/SkCanvas.h"
<<<<<<< HEAD
#include "third_party/skia/include/pathops/SkPathOps.h"

namespace blink {

ClipList::ClipList(const ClipList& other)
    : m_clipList(other.m_clipList)
{
}

void ClipList::clipPath(const SkPath& path,
    AntiAliasingMode antiAliasingMode,
    const SkMatrix& ctm)
=======

namespace blink {

ClipList::ClipList(const ClipList& other) : m_clipList(other.m_clipList) { }

void ClipList::clipPath(const SkPath& path, AntiAliasingMode antiAliasingMode, const SkMatrix& ctm)
>>>>>>> miniblink49
{
    ClipOp newClip;
    newClip.m_antiAliasingMode = antiAliasingMode;
    newClip.m_path = path;
    newClip.m_path.transform(ctm);
<<<<<<< HEAD
    if (m_clipList.isEmpty())
        m_currentClipPath = path;
    else
        Op(m_currentClipPath, path, SkPathOp::kIntersect_SkPathOp,
            &m_currentClipPath);
    m_clipList.push_back(newClip);
=======
    m_clipList.append(newClip);
>>>>>>> miniblink49
}

void ClipList::playback(SkCanvas* canvas) const
{
    for (const ClipOp* it = m_clipList.begin(); it < m_clipList.end(); it++) {
<<<<<<< HEAD
        canvas->clipPath(it->m_path, SkClipOp::kIntersect,
            it->m_antiAliasingMode == AntiAliased);
    }
}

const SkPath& ClipList::getCurrentClipPath() const
{
    return m_currentClipPath;
}

ClipList::ClipOp::ClipOp()
    : m_antiAliasingMode(AntiAliased)
{
}
=======
        canvas->clipPath(it->m_path, SkRegion::kIntersect_Op, it->m_antiAliasingMode == AntiAliased);
    }
}

ClipList::ClipOp::ClipOp()
    : m_antiAliasingMode(AntiAliased)
{ }
>>>>>>> miniblink49

ClipList::ClipOp::ClipOp(const ClipOp& other)
    : m_path(other.m_path)
    , m_antiAliasingMode(other.m_antiAliasingMode)
<<<<<<< HEAD
{
}
=======
{ }
>>>>>>> miniblink49

} // namespace blink

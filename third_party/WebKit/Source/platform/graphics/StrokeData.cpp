// Copyright (C) 2013 Google Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

<<<<<<< HEAD
#include "platform/graphics/StrokeData.h"
#include "third_party/skia/include/effects/SkDashPathEffect.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "config.h"
#include "platform/graphics/StrokeData.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {

static const int dashRatio = 3; // Ratio of the length of a dash to its width.

void StrokeData::setLineDash(const DashArray& dashes, float dashOffset)
{
    // FIXME: This is lifted directly off SkiaSupport, lines 49-74
    // so it is not guaranteed to work correctly.
    size_t dashLength = dashes.size();
    if (!dashLength) {
        // If no dash is set, revert to solid stroke
        // FIXME: do we need to set NoStroke in some cases?
        m_style = SolidStroke;
<<<<<<< HEAD
        m_dash.reset();
=======
        m_dash.clear();
>>>>>>> miniblink49
        return;
    }

    size_t count = !(dashLength % 2) ? dashLength : dashLength * 2;
<<<<<<< HEAD
    std::unique_ptr<SkScalar[]> intervals = wrapArrayUnique(new SkScalar[count]);
=======
    OwnPtr<SkScalar[]> intervals = adoptArrayPtr(new SkScalar[count]);
>>>>>>> miniblink49

    for (unsigned i = 0; i < count; i++)
        intervals[i] = dashes[i % dashLength];

<<<<<<< HEAD
    m_dash = SkDashPathEffect::Make(intervals.get(), count, dashOffset);
=======
    m_dash = adoptRef(SkDashPathEffect::Create(intervals.get(), count, dashOffset));
>>>>>>> miniblink49
}

void StrokeData::setupPaint(SkPaint* paint, int length) const
{
    paint->setStyle(SkPaint::kStroke_Style);
    paint->setStrokeWidth(SkFloatToScalar(m_thickness));
    paint->setStrokeCap(m_lineCap);
    paint->setStrokeJoin(m_lineJoin);
    paint->setStrokeMiter(SkFloatToScalar(m_miterLimit));

    setupPaintDashPathEffect(paint, length);
}

void StrokeData::setupPaintDashPathEffect(SkPaint* paint, int length) const
{
    float width = m_thickness;
    if (m_dash) {
<<<<<<< HEAD
        paint->setPathEffect(m_dash);
=======
        paint->setPathEffect(m_dash.get());
>>>>>>> miniblink49
    } else {
        switch (m_style) {
        case NoStroke:
        case SolidStroke:
        case DoubleStroke:
<<<<<<< HEAD
        case WavyStroke: // FIXME: https://crbug.com/229574
=======
        case WavyStroke: // FIXME: https://code.google.com/p/chromium/issues/detail?id=229574
>>>>>>> miniblink49
            paint->setPathEffect(0);
            return;
        case DashedStroke:
            width = dashRatio * width;
<<<<<<< HEAD
        // Fall through.
=======
            // Fall through.
>>>>>>> miniblink49
        case DottedStroke:
            // Truncate the width, since we don't want fuzzy dots or dashes.
            int dashLength = static_cast<int>(width);
            // Subtract off the endcaps, since they're rendered separately.
            int distance = length - 2 * static_cast<int>(m_thickness);
            int phase = 1;
            if (dashLength > 1) {
                // Determine how many dashes or dots we should have.
                int numDashes = distance / dashLength;
                int remainder = distance % dashLength;
                // Adjust the phase to center the dashes within the line.
                if (numDashes % 2) {
                    // Odd: shift right a full dash, minus half the remainder.
                    phase = dashLength - remainder / 2;
                } else {
                    // Even: shift right half a dash, minus half the remainder.
                    phase = (dashLength - remainder) / 2;
                }
            }
            SkScalar dashLengthSk = SkIntToScalar(dashLength);
            SkScalar intervals[2] = { dashLengthSk, dashLengthSk };
<<<<<<< HEAD
            paint->setPathEffect(
                SkDashPathEffect::Make(intervals, 2, SkIntToScalar(phase)));
=======
            RefPtr<SkDashPathEffect> pathEffect = adoptRef(SkDashPathEffect::Create(intervals, 2, SkIntToScalar(phase)));
            paint->setPathEffect(pathEffect.get());
>>>>>>> miniblink49
        }
    }
}

} // namespace blink

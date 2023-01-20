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

#ifndef GraphicsContextState_h
#define GraphicsContextState_h

#include "platform/graphics/DrawLooperBuilder.h"
<<<<<<< HEAD
#include "platform/graphics/GraphicsTypes.h"
#include "platform/graphics/StrokeData.h"
#include "third_party/skia/include/core/SkColorFilter.h"
#include "third_party/skia/include/core/SkPaint.h"
#include "third_party/skia/include/core/SkRefCnt.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "platform/graphics/Gradient.h"
#include "platform/graphics/GraphicsTypes.h"
#include "platform/graphics/Path.h"
#include "platform/graphics/StrokeData.h"
#include "platform/graphics/skia/SkiaUtils.h"
#include "third_party/skia/include/core/SkColorFilter.h"
#include "third_party/skia/include/core/SkPaint.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/RefPtr.h"
>>>>>>> miniblink49

namespace blink {

// Encapsulates the state information we store for each pushed graphics state.
// Only GraphicsContext can use this class.
class PLATFORM_EXPORT GraphicsContextState final {
<<<<<<< HEAD
    USING_FAST_MALLOC(GraphicsContextState);

public:
    static std::unique_ptr<GraphicsContextState> create()
    {
        return WTF::wrapUnique(new GraphicsContextState());
    }

    static std::unique_ptr<GraphicsContextState> createAndCopy(
        const GraphicsContextState& other)
    {
        return WTF::wrapUnique(new GraphicsContextState(other));
=======
public:
    static PassOwnPtr<GraphicsContextState> create()
    {
        return adoptPtr(new GraphicsContextState());
    }

    static PassOwnPtr<GraphicsContextState> createAndCopy(const GraphicsContextState& other)
    {
        return adoptPtr(new GraphicsContextState(other));
>>>>>>> miniblink49
    }

    void copy(const GraphicsContextState&);

    // SkPaint objects that reflect the current state. If the length of the
    // path to be stroked is known, pass it in for correct dash or dot placement.
    const SkPaint& strokePaint(int strokedPathLength = 0) const;
<<<<<<< HEAD
    const SkPaint& fillPaint() const { return m_fillPaint; }
=======
    const SkPaint& fillPaint() const;
>>>>>>> miniblink49

    uint16_t saveCount() const { return m_saveCount; }
    void incrementSaveCount() { ++m_saveCount; }
    void decrementSaveCount() { --m_saveCount; }

    // Stroke data
<<<<<<< HEAD
    Color strokeColor() const { return m_strokePaint.getColor(); }
    void setStrokeColor(const Color&);

    const StrokeData& getStrokeData() const { return m_strokeData; }
=======
    Color strokeColor() const { return m_strokeColor; }
    void setStrokeColor(const Color&);

    Gradient* strokeGradient() const { return m_strokeGradient.get(); }
    void setStrokeGradient(const PassRefPtr<Gradient>, float);

    const StrokeData& strokeData() const { return m_strokeData; }
>>>>>>> miniblink49
    void setStrokeStyle(StrokeStyle);
    void setStrokeThickness(float);
    void setLineCap(LineCap);
    void setLineJoin(LineJoin);
    void setMiterLimit(float);
    void setLineDash(const DashArray&, float);

    // Fill data
<<<<<<< HEAD
    Color fillColor() const { return m_fillPaint.getColor(); }
    void setFillColor(const Color&);

    // Shadow. (This will need tweaking if we use draw loopers for other things.)
    SkDrawLooper* drawLooper() const
    {
        DCHECK_EQ(m_fillPaint.getLooper(), m_strokePaint.getLooper());
        return m_fillPaint.getLooper();
    }
    void setDrawLooper(sk_sp<SkDrawLooper>);

    // Text. (See TextModeFill & friends.)
    TextDrawingModeFlags textDrawingMode() const { return m_textDrawingMode; }
    void setTextDrawingMode(TextDrawingModeFlags mode)
    {
        m_textDrawingMode = mode;
    }

    SkColorFilter* getColorFilter() const
    {
        DCHECK_EQ(m_fillPaint.getColorFilter(), m_strokePaint.getColorFilter());
        return m_fillPaint.getColorFilter();
    }
    void setColorFilter(sk_sp<SkColorFilter>);

    // Image interpolation control.
    InterpolationQuality getInterpolationQuality() const
    {
        return m_interpolationQuality;
    }
=======
    Color fillColor() const { return m_fillColor; }
    void setFillColor(const Color&);

    Gradient* fillGradient() const { return m_fillGradient.get(); }
    void setFillGradient(const PassRefPtr<Gradient>, float);

    // Shadow. (This will need tweaking if we use draw loopers for other things.)
    SkDrawLooper* drawLooper() const { return m_looper.get(); }
    void setDrawLooper(PassRefPtr<SkDrawLooper>);
    void clearDrawLooper();

    // Text. (See TextModeFill & friends.)
    TextDrawingModeFlags textDrawingMode() const { return m_textDrawingMode; }
    void setTextDrawingMode(TextDrawingModeFlags mode) { m_textDrawingMode = mode; }

    SkColorFilter* colorFilter() const { return m_colorFilter.get(); }
    void setColorFilter(PassRefPtr<SkColorFilter>);

    // Image interpolation control.
    InterpolationQuality interpolationQuality() const { return m_interpolationQuality; }
>>>>>>> miniblink49
    void setInterpolationQuality(InterpolationQuality);

    bool shouldAntialias() const { return m_shouldAntialias; }
    void setShouldAntialias(bool);

private:
    GraphicsContextState();
    explicit GraphicsContextState(const GraphicsContextState&);
    GraphicsContextState& operator=(const GraphicsContextState&);

<<<<<<< HEAD
    // This is mutable to enable dash path effect updates when the paint is
    // fetched for use.
    mutable SkPaint m_strokePaint;
    SkPaint m_fillPaint;

    StrokeData m_strokeData;

    TextDrawingModeFlags m_textDrawingMode;

=======
    // These are mutbale to enable gradient updates when the paints are fetched for use.
    mutable SkPaint m_strokePaint;
    mutable SkPaint m_fillPaint;

    StrokeData m_strokeData;

    Color m_strokeColor;
    RefPtr<Gradient> m_strokeGradient;

    Color m_fillColor;
    RefPtr<Gradient> m_fillGradient;

    RefPtr<SkDrawLooper> m_looper;

    TextDrawingModeFlags m_textDrawingMode;

    RefPtr<SkColorFilter> m_colorFilter;

>>>>>>> miniblink49
    InterpolationQuality m_interpolationQuality;

    uint16_t m_saveCount;

    bool m_shouldAntialias : 1;
};

} // namespace blink

#endif // GraphicsContextState_h

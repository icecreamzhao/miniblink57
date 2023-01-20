// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CanvasRenderingContext2DState_h
#define CanvasRenderingContext2DState_h

#include "core/css/CSSFontSelectorClient.h"
#include "modules/canvas2d/ClipList.h"
#include "platform/fonts/Font.h"
#include "platform/transforms/AffineTransform.h"
<<<<<<< HEAD
#include "third_party/skia/include/core/SkRefCnt.h"
=======
>>>>>>> miniblink49
#include "wtf/Vector.h"

namespace blink {

<<<<<<< HEAD
class CanvasRenderingContext2D;
=======
>>>>>>> miniblink49
class CanvasStyle;
class CSSValue;
class Element;

<<<<<<< HEAD
class CanvasRenderingContext2DState final
    : public GarbageCollectedFinalized<CanvasRenderingContext2DState>,
      public CSSFontSelectorClient {
    WTF_MAKE_NONCOPYABLE(CanvasRenderingContext2DState);
    USING_GARBAGE_COLLECTED_MIXIN(CanvasRenderingContext2DState);

public:
    static CanvasRenderingContext2DState* create()
    {
        return new CanvasRenderingContext2DState;
=======
class CanvasRenderingContext2DState final : public NoBaseWillBeGarbageCollectedFinalized<CanvasRenderingContext2DState>, public CSSFontSelectorClient {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(CanvasRenderingContext2DState);
public:
    static PassOwnPtrWillBeRawPtr<CanvasRenderingContext2DState> create()
    {
        return adoptPtrWillBeNoop(new CanvasRenderingContext2DState);
>>>>>>> miniblink49
    }

    ~CanvasRenderingContext2DState() override;

    DECLARE_VIRTUAL_TRACE();

<<<<<<< HEAD
    enum ClipListCopyMode { CopyClipList,
        DontCopyClipList };
=======
    enum ClipListCopyMode {
        CopyClipList,
        DontCopyClipList
    };
>>>>>>> miniblink49

    enum PaintType {
        FillPaintType,
        StrokePaintType,
        ImagePaintType,
    };

<<<<<<< HEAD
    static CanvasRenderingContext2DState* create(
        const CanvasRenderingContext2DState& other,
        ClipListCopyMode mode)
    {
        return new CanvasRenderingContext2DState(other, mode);
    }
=======
    static PassOwnPtrWillBeRawPtr<CanvasRenderingContext2DState> create(const CanvasRenderingContext2DState& other, ClipListCopyMode mode)
    {
        return adoptPtrWillBeNoop(new CanvasRenderingContext2DState(other, mode));
    }
    CanvasRenderingContext2DState& operator=(const CanvasRenderingContext2DState&);
>>>>>>> miniblink49

    // CSSFontSelectorClient implementation
    void fontsNeedUpdate(CSSFontSelector*) override;

    bool hasUnrealizedSaves() const { return m_unrealizedSaveCount; }
    void save() { ++m_unrealizedSaveCount; }
    void restore() { --m_unrealizedSaveCount; }
    void resetUnrealizedSaveCount() { m_unrealizedSaveCount = 0; }

<<<<<<< HEAD
    void setLineDash(const Vector<double>&);
    const Vector<double>& lineDash() const { return m_lineDash; }
=======
    void setLineDash(const Vector<float>&);
    const Vector<float>& lineDash() const { return m_lineDash; }
>>>>>>> miniblink49

    void setShouldAntialias(bool);
    bool shouldAntialias() const;

<<<<<<< HEAD
    void setLineDashOffset(double);
    double lineDashOffset() const { return m_lineDashOffset; }
=======
    void setLineDashOffset(float);
    float lineDashOffset() const { return m_lineDashOffset; }
>>>>>>> miniblink49

    // setTransform returns true iff transform is invertible;
    void setTransform(const AffineTransform&);
    void resetTransform();
    AffineTransform transform() const { return m_transform; }
    bool isTransformInvertible() const { return m_isTransformInvertible; }

    void clipPath(const SkPath&, AntiAliasingMode);
    bool hasClip() const { return m_hasClip; }
    bool hasComplexClip() const { return m_hasComplexClip; }
    void playbackClips(SkCanvas* canvas) const { m_clipList.playback(canvas); }
<<<<<<< HEAD
    const SkPath& getCurrentClipPath() const
    {
        return m_clipList.getCurrentClipPath();
    }
=======
>>>>>>> miniblink49

    void setFont(const Font&, CSSFontSelector*);
    const Font& font() const;
    bool hasRealizedFont() const { return m_realizedFont; }
    void setUnparsedFont(const String& font) { m_unparsedFont = font; }
    const String& unparsedFont() const { return m_unparsedFont; }

<<<<<<< HEAD
    void setFontForFilter(const Font& font) { m_fontForFilter = font; }

    void setFilter(const CSSValue*);
    void setUnparsedFilter(const String& filterString)
    {
        m_unparsedFilter = filterString;
    }
    const String& unparsedFilter() const { return m_unparsedFilter; }
    sk_sp<SkImageFilter> getFilter(Element*,
        IntSize canvasSize,
        CanvasRenderingContext2D*) const;
    bool hasFilter(Element*, IntSize canvasSize, CanvasRenderingContext2D*) const;
    void clearResolvedFilter() const;
=======
    void setFilter(PassRefPtrWillBeRawPtr<CSSValue>);
    void setUnparsedFilter(const String& filterString) { m_unparsedFilter = filterString; }
    const String& unparsedFilter() const { return m_unparsedFilter; }
    SkImageFilter* getFilter(Element*, const Font&) const;
    bool hasFilter() const { return m_filterValue; }
>>>>>>> miniblink49

    void setStrokeStyle(CanvasStyle*);
    CanvasStyle* strokeStyle() const { return m_strokeStyle.get(); }

    void setFillStyle(CanvasStyle*);
    CanvasStyle* fillStyle() const { return m_fillStyle.get(); }

    CanvasStyle* style(PaintType) const;

<<<<<<< HEAD
    enum Direction { DirectionInherit,
        DirectionRTL,
        DirectionLTR };

    void setDirection(Direction direction) { m_direction = direction; }
    Direction getDirection() const { return m_direction; }

    void setTextAlign(TextAlign align) { m_textAlign = align; }
    TextAlign getTextAlign() const { return m_textAlign; }

    void setTextBaseline(TextBaseline baseline) { m_textBaseline = baseline; }
    TextBaseline getTextBaseline() const { return m_textBaseline; }

    void setLineWidth(double lineWidth)
    {
        m_strokePaint.setStrokeWidth(lineWidth);
    }
    double lineWidth() const { return m_strokePaint.getStrokeWidth(); }

    void setLineCap(LineCap lineCap)
    {
        m_strokePaint.setStrokeCap(static_cast<SkPaint::Cap>(lineCap));
    }
    LineCap getLineCap() const
    {
        return static_cast<LineCap>(m_strokePaint.getStrokeCap());
    }

    void setLineJoin(LineJoin lineJoin)
    {
        m_strokePaint.setStrokeJoin(static_cast<SkPaint::Join>(lineJoin));
    }
    LineJoin getLineJoin() const
    {
        return static_cast<LineJoin>(m_strokePaint.getStrokeJoin());
    }

    void setMiterLimit(double miterLimit)
    {
        m_strokePaint.setStrokeMiter(miterLimit);
    }
    double miterLimit() const { return m_strokePaint.getStrokeMiter(); }

    void setShadowOffsetX(double);
    void setShadowOffsetY(double);
    const FloatSize& shadowOffset() const { return m_shadowOffset; }

    void setShadowBlur(double);
    double shadowBlur() const { return m_shadowBlur; }
=======
    enum Direction {
        DirectionInherit,
        DirectionRTL,
        DirectionLTR
    };

    void setDirection(Direction direction) { m_direction = direction; }
    Direction direction() const { return m_direction; }

    void setTextAlign(TextAlign align) { m_textAlign = align; }
    TextAlign textAlign() const { return m_textAlign; }

    void setTextBaseline(TextBaseline baseline) { m_textBaseline = baseline; }
    TextBaseline textBaseline() const { return m_textBaseline; }

    void setLineWidth(float lineWidth) { m_strokePaint.setStrokeWidth(lineWidth); }
    float lineWidth() const { return m_strokePaint.getStrokeWidth(); }

    void setLineCap(LineCap lineCap) { m_strokePaint.setStrokeCap(static_cast<SkPaint::Cap>(lineCap)); }
    LineCap lineCap() const { return static_cast<LineCap>(m_strokePaint.getStrokeCap()); }

    void setLineJoin(LineJoin lineJoin) { m_strokePaint.setStrokeJoin(static_cast<SkPaint::Join>(lineJoin)); }
    LineJoin lineJoin() const { return static_cast<LineJoin>(m_strokePaint.getStrokeJoin()); }

    void setMiterLimit(float miterLimit) { m_strokePaint.setStrokeMiter(miterLimit); }
    float miterLimit() const { return m_strokePaint.getStrokeMiter(); }

    void setShadowOffsetX(float);
    void setShadowOffsetY(float);
    const FloatSize& shadowOffset() const { return m_shadowOffset; }

    void setShadowBlur(float);
    float shadowBlur() const { return m_shadowBlur; }
>>>>>>> miniblink49

    void setShadowColor(SkColor);
    SkColor shadowColor() const { return m_shadowColor; }

<<<<<<< HEAD
    void setGlobalAlpha(double);
    double globalAlpha() const { return m_globalAlpha; }

    void setGlobalComposite(SkBlendMode);
    SkBlendMode globalComposite() const;

    void setImageSmoothingEnabled(bool);
    bool imageSmoothingEnabled() const;
    void setImageSmoothingQuality(const String&);
    String imageSmoothingQuality() const;

    void setUnparsedStrokeColor(const String& color)
    {
        m_unparsedStrokeColor = color;
    }
    const String& unparsedStrokeColor() const { return m_unparsedStrokeColor; }

    void setUnparsedFillColor(const String& color)
    {
        m_unparsedFillColor = color;
    }
=======
    void setGlobalAlpha(float);
    float globalAlpha() const { return m_globalAlpha; }

    void setGlobalComposite(SkXfermode::Mode);
    SkXfermode::Mode globalComposite() const;

    void setImageSmoothingEnabled(bool);
    bool imageSmoothingEnabled() const;

    void setUnparsedStrokeColor(const String& color) { m_unparsedStrokeColor = color; }
    const String& unparsedStrokeColor() const { return m_unparsedStrokeColor; }

    void setUnparsedFillColor(const String& color) { m_unparsedFillColor = color; }
>>>>>>> miniblink49
    const String& unparsedFillColor() const { return m_unparsedFillColor; }

    bool shouldDrawShadows() const;

<<<<<<< HEAD
    enum ImageType { NoImage,
        OpaqueImage,
        NonOpaqueImage };

    // If paint will not be used for painting a bitmap, set bitmapOpacity to
    // Opaque.
=======
    enum ImageType {
        NoImage,
        OpaqueImage,
        NonOpaqueImage
    };

    // If paint will not be used for painting a bitmap, set bitmapOpacity to Opaque
>>>>>>> miniblink49
    const SkPaint* getPaint(PaintType, ShadowMode, ImageType = NoImage) const;

private:
    CanvasRenderingContext2DState();
<<<<<<< HEAD
    CanvasRenderingContext2DState(const CanvasRenderingContext2DState&,
        ClipListCopyMode);
=======
    CanvasRenderingContext2DState(const CanvasRenderingContext2DState&, ClipListCopyMode = CopyClipList);
>>>>>>> miniblink49

    void updateLineDash() const;
    void updateStrokeStyle() const;
    void updateFillStyle() const;
<<<<<<< HEAD
    void updateFilterQuality() const;
    void updateFilterQualityWithSkFilterQuality(const SkFilterQuality&) const;
=======
>>>>>>> miniblink49
    void shadowParameterChanged();
    SkDrawLooper* emptyDrawLooper() const;
    SkDrawLooper* shadowOnlyDrawLooper() const;
    SkDrawLooper* shadowAndForegroundDrawLooper() const;
<<<<<<< HEAD
    sk_sp<SkImageFilter> shadowOnlyImageFilter() const;
    sk_sp<SkImageFilter> shadowAndForegroundImageFilter() const;
=======
    SkImageFilter* shadowOnlyImageFilter() const;
    SkImageFilter* shadowAndForegroundImageFilter() const;
>>>>>>> miniblink49

    unsigned m_unrealizedSaveCount;

    String m_unparsedStrokeColor;
    String m_unparsedFillColor;
<<<<<<< HEAD
    Member<CanvasStyle> m_strokeStyle;
    Member<CanvasStyle> m_fillStyle;
=======
    PersistentWillBeMember<CanvasStyle> m_strokeStyle;
    PersistentWillBeMember<CanvasStyle> m_fillStyle;
>>>>>>> miniblink49

    mutable SkPaint m_strokePaint;
    mutable SkPaint m_fillPaint;
    mutable SkPaint m_imagePaint;

    FloatSize m_shadowOffset;
<<<<<<< HEAD
    double m_shadowBlur;
    SkColor m_shadowColor;
    mutable sk_sp<SkDrawLooper> m_emptyDrawLooper;
    mutable sk_sp<SkDrawLooper> m_shadowOnlyDrawLooper;
    mutable sk_sp<SkDrawLooper> m_shadowAndForegroundDrawLooper;
    mutable sk_sp<SkImageFilter> m_shadowOnlyImageFilter;
    mutable sk_sp<SkImageFilter> m_shadowAndForegroundImageFilter;

    double m_globalAlpha;
    AffineTransform m_transform;
    Vector<double> m_lineDash;
    double m_lineDashOffset;

    String m_unparsedFont;
    Font m_font;
    Font m_fontForFilter;

    String m_unparsedFilter;
    Member<const CSSValue> m_filterValue;
    mutable sk_sp<SkImageFilter> m_resolvedFilter;
=======
    float m_shadowBlur;
    SkColor m_shadowColor;
    mutable RefPtr<SkDrawLooper> m_emptyDrawLooper;
    mutable RefPtr<SkDrawLooper> m_shadowOnlyDrawLooper;
    mutable RefPtr<SkDrawLooper> m_shadowAndForegroundDrawLooper;
    mutable RefPtr<SkImageFilter> m_shadowOnlyImageFilter;
    mutable RefPtr<SkImageFilter> m_shadowAndForegroundImageFilter;

    float m_globalAlpha;
    AffineTransform m_transform;
    Vector<float> m_lineDash;
    float m_lineDashOffset;

    String m_unparsedFont;
    Font m_font;

    String m_unparsedFilter;
    RefPtrWillBeMember<CSSValue> m_filterValue;
    mutable RefPtr<SkImageFilter> m_resolvedFilter;
>>>>>>> miniblink49

    // Text state.
    TextAlign m_textAlign;
    TextBaseline m_textBaseline;
    Direction m_direction;

    bool m_realizedFont : 1;
    bool m_isTransformInvertible : 1;
    bool m_hasClip : 1;
    bool m_hasComplexClip : 1;
    mutable bool m_fillStyleDirty : 1;
    mutable bool m_strokeStyleDirty : 1;
    mutable bool m_lineDashDirty : 1;

<<<<<<< HEAD
    bool m_imageSmoothingEnabled;
    SkFilterQuality m_imageSmoothingQuality;

    ClipList m_clipList;
};

} // namespace blink
=======
    ClipList m_clipList;
};

} // blink
>>>>>>> miniblink49

#endif

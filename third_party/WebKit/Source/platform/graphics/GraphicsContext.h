/*
 * Copyright (C) 2003, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2008-2009 Torch Mobile, Inc.
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GraphicsContext_h
#define GraphicsContext_h

#include "platform/PlatformExport.h"
#include "platform/fonts/Font.h"
<<<<<<< HEAD
#include "platform/graphics/ColorBehavior.h"
#include "platform/graphics/DashArray.h"
#include "platform/graphics/DrawLooperBuilder.h"
#include "platform/graphics/GraphicsContextState.h"
#include "platform/graphics/ImageOrientation.h"
#include "platform/graphics/skia/SkiaUtils.h"
//#include "third_party/skia/include/core/SkClipOp.h"
#include "third_party/skia/include/core/SkMetaData.h"
#include "third_party/skia/include/core/SkPictureRecorder.h"
#include "third_party/skia/include/core/SkRefCnt.h"
#include "wtf/Allocator.h"
#include "wtf/Forward.h"
#include "wtf/Noncopyable.h"
#include <memory>

class SkBitmap;
=======
#include "platform/geometry/FloatRect.h"
#include "platform/geometry/FloatRoundedRect.h"
#include "platform/graphics/DashArray.h"
#include "platform/graphics/DrawLooperBuilder.h"
#include "platform/graphics/ImageOrientation.h"
#include "platform/graphics/GraphicsContextState.h"
#include "platform/graphics/skia/SkiaUtils.h"
#include "third_party/skia/include/core/SkMetaData.h"
#include "third_party/skia/include/core/SkPictureRecorder.h"
#include "third_party/skia/include/core/SkRegion.h"
#include "wtf/FastAllocBase.h"
#include "wtf/Forward.h"
#include "wtf/Noncopyable.h"
#include "wtf/PassOwnPtr.h"

class SkBitmap;
class SkImage;
>>>>>>> miniblink49
class SkPaint;
class SkPath;
class SkPicture;
class SkRRect;
<<<<<<< HEAD
=======
class SkTextBlob;
struct SkImageInfo;
>>>>>>> miniblink49
struct SkRect;

namespace blink {

<<<<<<< HEAD
class FloatRect;
class FloatRoundedRect;
class KURL;
class PaintController;
class Path;

class PLATFORM_EXPORT GraphicsContext {
    WTF_MAKE_NONCOPYABLE(GraphicsContext);
    USING_FAST_MALLOC(GraphicsContext);

public:
    enum DisabledMode {
        NothingDisabled = 0, // Run as normal.
        FullyDisabled = 1 // Do absolutely minimal work to remove the cost of
        // the context from performance tests.
    };

    explicit GraphicsContext(
        PaintController&,
        DisabledMode = NothingDisabled,
        SkMetaData* = 0,
        ColorBehavior = ColorBehavior::transformToGlobalTarget());
=======
class DisplayItemList;
class ImageBuffer;
class KURL;

class PLATFORM_EXPORT GraphicsContext {
    WTF_MAKE_NONCOPYABLE(GraphicsContext); WTF_MAKE_FAST_ALLOCATED(GraphicsContext);
public:
    enum DisabledMode {
        NothingDisabled = 0, // Run as normal.
        FullyDisabled = 1 // Do absolutely minimal work to remove the cost of the context from performance tests.
    };

    explicit GraphicsContext(DisplayItemList*, DisabledMode = NothingDisabled, SkMetaData* = 0);

    // TODO(chrishtr): Once Slimming Paint launches this should be removed (crbug.com/471333).
    // A 0 canvas is allowed, but in such cases the context must only have canvas
    // related commands called when within a beginRecording/endRecording block.
    // Furthermore, save/restore calls must be balanced any time the canvas is 0.
    static PassOwnPtr<GraphicsContext> deprecatedCreateWithCanvas(SkCanvas*, DisabledMode = NothingDisabled, SkMetaData* = 0);
>>>>>>> miniblink49

    ~GraphicsContext();

    SkCanvas* canvas() { return m_canvas; }
    const SkCanvas* canvas() const { return m_canvas; }

<<<<<<< HEAD
    PaintController& getPaintController() { return m_paintController; }
    const ColorBehavior& getColorBehavior() const { return m_colorBehavior; }
=======
    DisplayItemList* displayItemList() { return m_displayItemList; }

    void resetCanvas(SkCanvas*);
>>>>>>> miniblink49

    bool contextDisabled() const { return m_disabledState; }

    // ---------- State management methods -----------------
    void save();
    void restore();

<<<<<<< HEAD
#if DCHECK_IS_ON()
    unsigned saveCount() const;
#endif

    float strokeThickness() const
    {
        return immutableState()->getStrokeData().thickness();
    }
    void setStrokeThickness(float thickness)
    {
        mutableState()->setStrokeThickness(thickness);
    }

    StrokeStyle getStrokeStyle() const
    {
        return immutableState()->getStrokeData().style();
    }
    void setStrokeStyle(StrokeStyle style)
    {
        mutableState()->setStrokeStyle(style);
    }

    Color strokeColor() const { return immutableState()->strokeColor(); }
    void setStrokeColor(const Color& color)
    {
        mutableState()->setStrokeColor(color);
    }

    void setLineCap(LineCap cap) { mutableState()->setLineCap(cap); }
    void setLineDash(const DashArray& dashes, float dashOffset)
    {
        mutableState()->setLineDash(dashes, dashOffset);
    }
=======
#if ENABLE(ASSERT)
    unsigned saveCount() const;
    void disableDestructionChecks() { m_disableDestructionChecks = true; }
#endif

    float strokeThickness() const { return immutableState()->strokeData().thickness(); }
    void setStrokeThickness(float thickness) { mutableState()->setStrokeThickness(thickness); }

    StrokeStyle strokeStyle() const { return immutableState()->strokeData().style(); }
    void setStrokeStyle(StrokeStyle style) { mutableState()->setStrokeStyle(style); }

    Color strokeColor() const { return immutableState()->strokeColor(); }
    void setStrokeColor(const Color& color) { mutableState()->setStrokeColor(color); }

    Gradient* strokeGradient() const { return immutableState()->strokeGradient(); }
    void setStrokeGradient(PassRefPtr<Gradient>, float alpha = 1);

    void setLineCap(LineCap cap) { mutableState()->setLineCap(cap); }
    void setLineDash(const DashArray& dashes, float dashOffset) { mutableState()->setLineDash(dashes, dashOffset); }
>>>>>>> miniblink49
    void setLineJoin(LineJoin join) { mutableState()->setLineJoin(join); }
    void setMiterLimit(float limit) { mutableState()->setMiterLimit(limit); }

    Color fillColor() const { return immutableState()->fillColor(); }
    void setFillColor(const Color& color) { mutableState()->setFillColor(color); }

<<<<<<< HEAD
    void setShouldAntialias(bool antialias)
    {
        mutableState()->setShouldAntialias(antialias);
    }
    bool shouldAntialias() const { return immutableState()->shouldAntialias(); }

    void setTextDrawingMode(TextDrawingModeFlags mode)
    {
        mutableState()->setTextDrawingMode(mode);
    }
    TextDrawingModeFlags textDrawingMode() const
    {
        return immutableState()->textDrawingMode();
    }

    void setImageInterpolationQuality(InterpolationQuality quality)
    {
        mutableState()->setInterpolationQuality(quality);
    }
    InterpolationQuality imageInterpolationQuality() const
    {
        return immutableState()->getInterpolationQuality();
    }
=======
    void setFillGradient(PassRefPtr<Gradient>, float alpha = 1);

    SkMatrix getTotalMatrix() const;

    void setShouldAntialias(bool antialias) { mutableState()->setShouldAntialias(antialias); }
    bool shouldAntialias() const { return immutableState()->shouldAntialias(); }

    void setTextDrawingMode(TextDrawingModeFlags mode) { mutableState()->setTextDrawingMode(mode); }
    TextDrawingModeFlags textDrawingMode() const { return immutableState()->textDrawingMode(); }

    void setImageInterpolationQuality(InterpolationQuality quality) { mutableState()->setInterpolationQuality(quality); }
    InterpolationQuality imageInterpolationQuality() const { return immutableState()->interpolationQuality(); }
>>>>>>> miniblink49

    // Specify the device scale factor which may change the way document markers
    // and fonts are rendered.
    void setDeviceScaleFactor(float factor) { m_deviceScaleFactor = factor; }
    float deviceScaleFactor() const { return m_deviceScaleFactor; }

    // Returns if the context is a printing context instead of a display
    // context. Bitmap shouldn't be resampled when printing to keep the best
    // possible quality.
    bool printing() const { return m_printing; }
    void setPrinting(bool printing) { m_printing = printing; }

<<<<<<< HEAD
    SkColorFilter* getColorFilter() const;
=======
    SkColorFilter* colorFilter() const;
>>>>>>> miniblink49
    void setColorFilter(ColorFilter);
    // ---------- End state management methods -----------------

    // These draw methods will do both stroking and filling.
    // FIXME: ...except drawRect(), which fills properly but always strokes
    // using a 1-pixel stroke inset from the rect borders (of the correct
    // stroke color).
    void drawRect(const IntRect&);
    void drawLine(const IntPoint&, const IntPoint&);

<<<<<<< HEAD
=======
    void fillPolygon(size_t numPoints, const FloatPoint*, const Color&, bool shouldAntialias);

>>>>>>> miniblink49
    void fillPath(const Path&);
    void strokePath(const Path&);

    void fillEllipse(const FloatRect&);
    void strokeEllipse(const FloatRect&);

    void fillRect(const FloatRect&);
<<<<<<< HEAD
    void fillRect(const FloatRect&,
        const Color&,
        SkBlendMode = SkBlendMode::kSrcOver);
    void fillRoundedRect(const FloatRoundedRect&, const Color&);
    void fillDRRect(const FloatRoundedRect&,
        const FloatRoundedRect&,
        const Color&);

    void strokeRect(const FloatRect&, float lineWidth);

    void drawPicture(const SkPicture*);
    void compositePicture(sk_sp<SkPicture>,
        const FloatRect& dest,
        const FloatRect& src,
        SkBlendMode);

    void drawImage(Image*,
        const FloatRect& destRect,
        const FloatRect* srcRect = nullptr,
        SkBlendMode = SkBlendMode::kSrcOver,
        RespectImageOrientationEnum = DoNotRespectImageOrientation);
    void drawImageRRect(
        Image*,
        const FloatRoundedRect& dest,
        const FloatRect& srcRect,
        SkBlendMode = SkBlendMode::kSrcOver,
        RespectImageOrientationEnum = DoNotRespectImageOrientation);
    void drawTiledImage(Image*,
        const FloatRect& destRect,
        const FloatPoint& srcPoint,
        const FloatSize& tileSize,
        SkBlendMode = SkBlendMode::kSrcOver,
        const FloatSize& repeatSpacing = FloatSize());
    void drawTiledImage(Image*,
        const FloatRect& destRect,
        const FloatRect& srcRect,
        const FloatSize& tileScaleFactor,
        Image::TileRule hRule = Image::StretchTile,
        Image::TileRule vRule = Image::StretchTile,
        SkBlendMode = SkBlendMode::kSrcOver);

    // These methods write to the canvas.
    // Also drawLine(const IntPoint& point1, const IntPoint& point2) and
    // fillRoundedRect().
    void drawOval(const SkRect&, const SkPaint&);
    void drawPath(const SkPath&, const SkPaint&);
    void drawRect(const SkRect&, const SkPaint&);
    void drawRRect(const SkRRect&, const SkPaint&);

    void clip(const IntRect& rect) { clipRect(rect); }
    void clip(const FloatRect& rect) { clipRect(rect); }
    void clipRoundedRect(const FloatRoundedRect&,
        SkClipOp = SkClipOp::kIntersect,
        AntiAliasingMode = AntiAliased);
    void clipOut(const IntRect& rect)
    {
        clipRect(rect, NotAntiAliased, SkClipOp::kDifference);
    }
    void clipOut(const FloatRect& rect)
    {
        clipRect(rect, NotAntiAliased, SkClipOp::kDifference);
    }
    void clipOut(const Path&);
    void clipOutRoundedRect(const FloatRoundedRect&);
    void clipPath(const SkPath&,
        AntiAliasingMode = NotAntiAliased,
        SkClipOp = SkClipOp::kIntersect);
    void clipRect(const SkRect&,
        AntiAliasingMode = NotAntiAliased,
        SkClipOp = SkClipOp::kIntersect);

    void drawText(const Font&, const TextRunPaintInfo&, const FloatPoint&);
    void drawText(const Font&,
        const TextRunPaintInfo&,
        const FloatPoint&,
        const SkPaint&);
    void drawEmphasisMarks(const Font&,
        const TextRunPaintInfo&,
        const AtomicString& mark,
        const FloatPoint&);
    void drawBidiText(
        const Font&,
        const TextRunPaintInfo&,
        const FloatPoint&,
        Font::CustomFontNotReadyAction = Font::DoNotPaintIfFontNotReady);
    void drawHighlightForText(const Font&,
        const TextRun&,
        const FloatPoint&,
        int h,
        const Color& backgroundColor,
        int from = 0,
        int to = -1);

    void drawLineForText(const FloatPoint&, float width);
=======
    void fillRect(const FloatRect&, const Color&, SkXfermode::Mode = SkXfermode::kSrcOver_Mode);
    void fillRoundedRect(const FloatRoundedRect&, const Color&);
    void fillDRRect(const FloatRoundedRect&, const FloatRoundedRect&, const Color&);

    void clearRect(const FloatRect&);

    void strokeRect(const FloatRect&);
    void strokeRect(const FloatRect&, float lineWidth);

    void drawPicture(const SkPicture*);
    void compositePicture(SkPicture*, const FloatRect& dest, const FloatRect& src, SkXfermode::Mode);

    void drawImage(Image*, const IntRect&, SkXfermode::Mode = SkXfermode::kSrcOver_Mode, RespectImageOrientationEnum = DoNotRespectImageOrientation);
    void drawImage(Image*, const FloatRect& destRect, const FloatRect& srcRect, SkXfermode::Mode = SkXfermode::kSrcOver_Mode, RespectImageOrientationEnum = DoNotRespectImageOrientation);

    void drawTiledImage(Image*, const IntRect& destRect, const IntPoint& srcPoint, const IntSize& tileSize,
        SkXfermode::Mode = SkXfermode::kSrcOver_Mode, const IntSize& repeatSpacing = IntSize());
    void drawTiledImage(Image*, const IntRect& destRect, const IntRect& srcRect,
        const FloatSize& tileScaleFactor, Image::TileRule hRule = Image::StretchTile, Image::TileRule vRule = Image::StretchTile,
        SkXfermode::Mode = SkXfermode::kSrcOver_Mode);

    // These methods write to the canvas.
    // Also drawLine(const IntPoint& point1, const IntPoint& point2) and fillRoundedRect
    void drawOval(const SkRect&, const SkPaint&);
    void drawPath(const SkPath&, const SkPaint&);
    void drawRect(const SkRect&, const SkPaint&);

    void clip(const IntRect& rect) { clipRect(rect); }
    void clip(const FloatRect& rect) { clipRect(rect); }
    void clipRoundedRect(const FloatRoundedRect&, SkRegion::Op = SkRegion::kIntersect_Op);
    void clipOut(const IntRect& rect) { clipRect(rect, NotAntiAliased, SkRegion::kDifference_Op); }
    void clipOut(const FloatRect& rect) { clipRect(rect, NotAntiAliased, SkRegion::kDifference_Op); }
    void clipOut(const Path&);
    void clipOutRoundedRect(const FloatRoundedRect&);
    void clipPath(const SkPath&, AntiAliasingMode = NotAntiAliased, SkRegion::Op = SkRegion::kIntersect_Op);
    void clipPolygon(size_t numPoints, const FloatPoint*, bool antialias);
    void clipRect(const SkRect&, AntiAliasingMode = NotAntiAliased, SkRegion::Op = SkRegion::kIntersect_Op);

    void drawText(const Font&, const TextRunPaintInfo&, const FloatPoint&);
    void drawText(const Font&, const TextRunPaintInfo&, const FloatPoint&, const SkPaint&);
    void drawEmphasisMarks(const Font&, const TextRunPaintInfo&, const AtomicString& mark, const FloatPoint&);
    void drawBidiText(const Font&, const TextRunPaintInfo&, const FloatPoint&, Font::CustomFontNotReadyAction = Font::DoNotPaintIfFontNotReady);
    void drawHighlightForText(const Font&, const TextRun&, const FloatPoint&, int h, const Color& backgroundColor, int from = 0, int to = -1);

    void drawLineForText(const FloatPoint&, float width, bool printing);
>>>>>>> miniblink49
    enum DocumentMarkerLineStyle {
        DocumentMarkerSpellingLineStyle,
        DocumentMarkerGrammarLineStyle
    };
<<<<<<< HEAD
    void drawLineForDocumentMarker(const FloatPoint&,
        float width,
        DocumentMarkerLineStyle);

    // beginLayer()/endLayer() behave like save()/restore() for CTM and clip
    // states. Apply SkBlendMode when the layer is composited on the backdrop
    // (i.e. endLayer()).
    void beginLayer(float opacity = 1.0f,
        SkBlendMode = SkBlendMode::kSrcOver,
        const FloatRect* = 0,
        ColorFilter = ColorFilterNone,
        sk_sp<SkImageFilter> = nullptr);
    void endLayer();

    // Instead of being dispatched to the active canvas, draw commands following
    // beginRecording() are stored in a display list that can be replayed at a
    // later time. Pass in the bounding rectangle for the content in the list.
    void beginRecording(const FloatRect&);

    // Returns a picture with any recorded draw commands since the prerequisite
    // call to beginRecording().  The picture is guaranteed to be non-null (but
    // not necessarily non-empty), even when the context is disabled.
    sk_sp<SkPicture> endRecording();

    void setShadow(const FloatSize& offset,
        float blur,
        const Color&,
        DrawLooperBuilder::ShadowTransformMode = DrawLooperBuilder::ShadowRespectsTransforms,
        DrawLooperBuilder::ShadowAlphaMode = DrawLooperBuilder::ShadowRespectsAlpha,
        ShadowMode = DrawShadowAndForeground);

    void setDrawLooper(sk_sp<SkDrawLooper>);

    void drawFocusRing(const Vector<IntRect>&,
        float width,
        int offset,
        const Color&);
    void drawFocusRing(const Path&, float width, int offset, const Color&);
=======
    void drawLineForDocumentMarker(const FloatPoint&, float width, DocumentMarkerLineStyle);

    // beginLayer()/endLayer() behaves like save()/restore() for CTM and clip states.
    // Apply SkXfermode::Mode when the layer is composited on the backdrop (i.e. endLayer()).
    void beginLayer(float opacity = 1.0f, SkXfermode::Mode = SkXfermode::kSrcOver_Mode,
        const FloatRect* = 0, ColorFilter = ColorFilterNone, SkImageFilter* = 0);
    void endLayer();

    // Instead of being dispatched to the active canvas, draw commands following beginRecording()
    // are stored in a display list that can be replayed at a later time. Pass in the bounding
    // rectangle for the content in the list.
    void beginRecording(const FloatRect&);
    PassRefPtr<const SkPicture> endRecording();

    void setShadow(const FloatSize& offset, float blur, const Color&,
        DrawLooperBuilder::ShadowTransformMode = DrawLooperBuilder::ShadowRespectsTransforms,
        DrawLooperBuilder::ShadowAlphaMode = DrawLooperBuilder::ShadowRespectsAlpha, ShadowMode = DrawShadowAndForeground);

    // It is assumed that this draw looper is used only for shadows
    // (i.e. a draw looper is set if and only if there is a shadow).
    // The builder passed into this method will be destroyed.
    void setDrawLooper(PassOwnPtr<DrawLooperBuilder>);
    void clearDrawLooper();

    void drawFocusRing(const Vector<IntRect>&, int width, int offset, const Color&);
    void drawFocusRing(const Path&, int width, int offset, const Color&);
>>>>>>> miniblink49

    enum Edge {
        NoEdge = 0,
        TopEdge = 1 << 1,
        RightEdge = 1 << 2,
        BottomEdge = 1 << 3,
        LeftEdge = 1 << 4
    };
    typedef unsigned Edges;
<<<<<<< HEAD
    void drawInnerShadow(const FloatRoundedRect&,
        const Color& shadowColor,
        const FloatSize& shadowOffset,
        float shadowBlur,
        float shadowSpread,
        Edges clippedEdges = NoEdge);

    const SkPaint& fillPaint() const { return immutableState()->fillPaint(); }
    const SkPaint& strokePaint() const { return immutableState()->strokePaint(); }

    // ---------- Transformation methods -----------------
=======
    void drawInnerShadow(const FloatRoundedRect&, const Color& shadowColor, const IntSize shadowOffset, int shadowBlur, int shadowSpread, Edges clippedEdges = NoEdge);

    const SkPaint& fillPaint() const { return immutableState()->fillPaint(); }

    // ---------- Transformation methods -----------------
    // Note that the getCTM method returns only the current transform from Blink's perspective,
    // which is not the final transform used to place content on screen. It cannot be relied upon
    // for testing where a point will appear on screen or how large it will be.
    AffineTransform getCTM() const;
>>>>>>> miniblink49
    void concatCTM(const AffineTransform&);

    void scale(float x, float y);
    void rotate(float angleInRadians);
    void translate(float x, float y);
    // ---------- End transformation methods -----------------

<<<<<<< HEAD
    SkFilterQuality computeFilterQuality(Image*,
        const FloatRect& dest,
        const FloatRect& src) const;

    // Sets target URL of a clickable area.
    void setURLForRect(const KURL&, const IntRect&);

    // Sets the destination of a clickable area of a URL fragment (in a URL
    // pointing to the same web page). When the area is clicked, the page should
    // be scrolled to the location set by setURLDestinationLocation() for the
    // destination whose name is |name|.
    void setURLFragmentForRect(const String& name, const IntRect&);

    // Sets location of a URL destination (a.k.a. anchor) in the page.
    void setURLDestinationLocation(const String& name, const IntPoint&);

    static void adjustLineToPixelBoundaries(FloatPoint& p1,
        FloatPoint& p2,
        float strokeWidth,
        StrokeStyle);

    static int focusRingOutsetExtent(int offset, int width)
    {
        // Unlike normal outlines (whole width is outside of the offset), focus
        // rings are drawn with the center of the path aligned with the offset, so
        // only half of the width is outside of the offset.
        return focusRingOffset(offset) + (width + 1) / 2;
    }

#if DCHECK_IS_ON()
    void setInDrawingRecorder(bool);
#endif

    static sk_sp<SkColorFilter> WebCoreColorFilterToSkiaColorFilter(ColorFilter);

private:
=======
    SkFilterQuality computeFilterQuality(Image*, const FloatRect& dest, const FloatRect& src) const;

    // URL drawing
    void setURLForRect(const KURL&, const IntRect&);
    void setURLFragmentForRect(const String& name, const IntRect&);

    static void adjustLineToPixelBoundaries(FloatPoint& p1, FloatPoint& p2, float strokeWidth, StrokeStyle);

    static int focusRingOutsetExtent(int offset, int width)
    {
        return focusRingOutset(offset) + (focusRingWidth(width) + 1) / 2;
    }

    // public decl needed for OwnPtr wrapper.
    class RecordingState;

#if ENABLE(ASSERT)
    void setInDrawingRecorder(bool);
#endif

    static PassRefPtr<SkColorFilter> WebCoreColorFilterToSkiaColorFilter(ColorFilter);

private:
    explicit GraphicsContext(SkCanvas*, DisplayItemList*, DisabledMode = NothingDisabled, SkMetaData* = 0);

>>>>>>> miniblink49
    const GraphicsContextState* immutableState() const { return m_paintState; }

    GraphicsContextState* mutableState()
    {
        realizePaintSave();
        return m_paintState;
    }

<<<<<<< HEAD
    template <typename DrawTextFunc>
    void drawTextPasses(const DrawTextFunc&);

#if OS(MACOSX)
    static inline int focusRingOffset(int offset)
    {
        return offset + 2;
    }
#else
    static inline int focusRingOffset(int offset)
    {
        return 0;
    }
=======
    template<typename DrawTextFunc>
    void drawTextPasses(const DrawTextFunc&);

    static void setPathFromPoints(SkPath*, size_t, const FloatPoint*);

#if OS(MACOSX)
    static inline int focusRingOutset(int offset) { return offset + 2; }
    static inline int focusRingWidth(int width) { return width; }
#else
    static inline int focusRingOutset(int offset) { return 0; }
    static inline int focusRingWidth(int width) { return 1; }
>>>>>>> miniblink49
    static SkPMColor lineColors(int);
    static SkPMColor antiColors1(int);
    static SkPMColor antiColors2(int);
    static void draw1xMarker(SkBitmap*, int);
    static void draw2xMarker(SkBitmap*, int);
#endif

    void saveLayer(const SkRect* bounds, const SkPaint*);
    void restoreLayer();

    // Helpers for drawing a focus ring (drawFocusRing)
<<<<<<< HEAD
    void drawFocusRingPath(const SkPath&, const Color&, float width);
    void drawFocusRingRect(const SkRect&, const Color&, float width);

    // SkCanvas wrappers.
    void clipRRect(const SkRRect&,
        AntiAliasingMode = NotAntiAliased,
        SkClipOp = SkClipOp::kIntersect);
    void concat(const SkMatrix&);
=======
    void drawFocusRingPath(const SkPath&, const Color&, int width);
    void drawFocusRingRect(const SkRect&, const Color&, int width);

    // SkCanvas wrappers.
    void clipRRect(const SkRRect&, AntiAliasingMode = NotAntiAliased, SkRegion::Op = SkRegion::kIntersect_Op);
    void concat(const SkMatrix&);
    void drawRRect(const SkRRect&, const SkPaint&);
>>>>>>> miniblink49

    // Apply deferred paint state saves
    void realizePaintSave()
    {
        if (contextDisabled())
            return;

        if (m_paintState->saveCount()) {
            m_paintState->decrementSaveCount();
            ++m_paintStateIndex;
            if (m_paintStateStack.size() == m_paintStateIndex) {
<<<<<<< HEAD
                m_paintStateStack.push_back(
                    GraphicsContextState::createAndCopy(*m_paintState));
=======
                m_paintStateStack.append(GraphicsContextState::createAndCopy(*m_paintState));
>>>>>>> miniblink49
                m_paintState = m_paintStateStack[m_paintStateIndex].get();
            } else {
                GraphicsContextState* priorPaintState = m_paintState;
                m_paintState = m_paintStateStack[m_paintStateIndex].get();
                m_paintState->copy(*priorPaintState);
            }
        }
    }

<<<<<<< HEAD
    void fillRectWithRoundedHole(const FloatRect&,
        const FloatRoundedRect& roundedHoleRect,
        const Color&);
=======
    void fillRectWithRoundedHole(const FloatRect&, const FloatRoundedRect& roundedHoleRect, const Color&);

    bool isRecording() const;
>>>>>>> miniblink49

    const SkMetaData& metaData() const { return m_metaData; }

    // null indicates painting is contextDisabled. Never delete this object.
    SkCanvas* m_canvas;

<<<<<<< HEAD
    PaintController& m_paintController;

    // Paint states stack. The state controls the appearance of drawn content, so
    // this stack enables local drawing state changes with save()/restore() calls.
    // We do not delete from this stack to avoid memory churn.
    Vector<std::unique_ptr<GraphicsContextState>> m_paintStateStack;

    // Current index on the stack. May not be the last thing on the stack.
    unsigned m_paintStateIndex;

    // Raw pointer to the current state.
    GraphicsContextState* m_paintState;

=======
    // This stores the canvas object used to construct the GraphicsContext, if any. It is only
    // used when Slimming Paint is active.
    SkCanvas* m_originalCanvas;

    // This being null indicates not to paint into a DisplayItemList, and instead directly into the canvas.
    DisplayItemList* m_displayItemList;

    // Paint states stack. Enables local drawing state change with save()/restore() calls.
    // This state controls the appearance of drawn content.
    // We do not delete from this stack to avoid memory churn.
    Vector<OwnPtr<GraphicsContextState>> m_paintStateStack;
    // Current index on the stack. May not be the last thing on the stack.
    unsigned m_paintStateIndex;
    // Raw pointer to the current state.
    GraphicsContextState* m_paintState;

    // Only used when Slimming Paint is off. When it is on, m_pictureRecorder is used instead.
    Vector<OwnPtr<RecordingState>> m_recordingStateStack;
>>>>>>> miniblink49
    SkPictureRecorder m_pictureRecorder;

    SkMetaData m_metaData;

<<<<<<< HEAD
    const ColorBehavior m_colorBehavior;

#if DCHECK_IS_ON()
    int m_layerCount;
=======
#if ENABLE(ASSERT)
    unsigned m_layerCount;
>>>>>>> miniblink49
    bool m_disableDestructionChecks;
    bool m_inDrawingRecorder;
#endif

    const DisabledMode m_disabledState;

    float m_deviceScaleFactor;

    unsigned m_printing : 1;
    unsigned m_hasMetaData : 1;
};

} // namespace blink

#endif // GraphicsContext_h

// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "modules/canvas2d/CanvasRenderingContext2DState.h"

#include "core/css/CSSFontSelector.h"
#include "core/css/resolver/FilterOperationResolver.h"
#include "core/css/resolver/StyleBuilder.h"
#include "core/css/resolver/StyleResolverState.h"
<<<<<<< HEAD
#include "core/html/HTMLCanvasElement.h"
#include "core/paint/FilterEffectBuilder.h"
#include "core/style/ComputedStyle.h"
#include "core/style/FilterOperation.h"
#include "core/svg/SVGFilterElement.h"
#include "modules/canvas2d/CanvasGradient.h"
#include "modules/canvas2d/CanvasPattern.h"
#include "modules/canvas2d/CanvasRenderingContext2D.h"
#include "modules/canvas2d/CanvasStyle.h"
#include "platform/graphics/DrawLooperBuilder.h"
#include "platform/graphics/filters/FilterEffect.h"
=======
#include "core/paint/FilterEffectBuilder.h"
#include "core/style/ComputedStyle.h"
#include "modules/canvas2d/CanvasGradient.h"
#include "modules/canvas2d/CanvasPattern.h"
#include "modules/canvas2d/CanvasStyle.h"
#include "platform/graphics/DrawLooperBuilder.h"
>>>>>>> miniblink49
#include "platform/graphics/filters/SkiaImageFilterBuilder.h"
#include "platform/graphics/skia/SkiaUtils.h"
#include "third_party/skia/include/effects/SkDashPathEffect.h"
#include "third_party/skia/include/effects/SkDropShadowImageFilter.h"
<<<<<<< HEAD
#include <memory>
=======
>>>>>>> miniblink49

static const char defaultFont[] = "10px sans-serif";
static const char defaultFilter[] = "none";

namespace blink {

CanvasRenderingContext2DState::CanvasRenderingContext2DState()
    : m_unrealizedSaveCount(0)
    , m_strokeStyle(CanvasStyle::createFromRGBA(SK_ColorBLACK))
    , m_fillStyle(CanvasStyle::createFromRGBA(SK_ColorBLACK))
    , m_shadowBlur(0)
    , m_shadowColor(Color::transparent)
    , m_globalAlpha(1)
    , m_lineDashOffset(0)
    , m_unparsedFont(defaultFont)
    , m_unparsedFilter(defaultFilter)
    , m_textAlign(StartTextAlign)
    , m_textBaseline(AlphabeticTextBaseline)
    , m_direction(DirectionInherit)
    , m_realizedFont(false)
    , m_isTransformInvertible(true)
    , m_hasClip(false)
    , m_hasComplexClip(false)
    , m_fillStyleDirty(true)
    , m_strokeStyleDirty(true)
    , m_lineDashDirty(false)
<<<<<<< HEAD
    , m_imageSmoothingQuality(kLow_SkFilterQuality)
=======
>>>>>>> miniblink49
{
    m_fillPaint.setStyle(SkPaint::kFill_Style);
    m_fillPaint.setAntiAlias(true);
    m_imagePaint.setStyle(SkPaint::kFill_Style);
    m_imagePaint.setAntiAlias(true);
    m_strokePaint.setStyle(SkPaint::kStroke_Style);
    m_strokePaint.setStrokeWidth(1);
    m_strokePaint.setStrokeCap(SkPaint::kButt_Cap);
    m_strokePaint.setStrokeMiter(10);
    m_strokePaint.setStrokeJoin(SkPaint::kMiter_Join);
    m_strokePaint.setAntiAlias(true);
    setImageSmoothingEnabled(true);
}

<<<<<<< HEAD
CanvasRenderingContext2DState::CanvasRenderingContext2DState(
    const CanvasRenderingContext2DState& other,
    ClipListCopyMode mode)
=======
CanvasRenderingContext2DState::CanvasRenderingContext2DState(const CanvasRenderingContext2DState& other, ClipListCopyMode mode)
>>>>>>> miniblink49
    : CSSFontSelectorClient()
    , m_unrealizedSaveCount(other.m_unrealizedSaveCount)
    , m_unparsedStrokeColor(other.m_unparsedStrokeColor)
    , m_unparsedFillColor(other.m_unparsedFillColor)
    , m_strokeStyle(other.m_strokeStyle)
    , m_fillStyle(other.m_fillStyle)
    , m_strokePaint(other.m_strokePaint)
    , m_fillPaint(other.m_fillPaint)
    , m_imagePaint(other.m_imagePaint)
    , m_shadowOffset(other.m_shadowOffset)
    , m_shadowBlur(other.m_shadowBlur)
    , m_shadowColor(other.m_shadowColor)
    , m_emptyDrawLooper(other.m_emptyDrawLooper)
    , m_shadowOnlyDrawLooper(other.m_shadowOnlyDrawLooper)
    , m_shadowAndForegroundDrawLooper(other.m_shadowAndForegroundDrawLooper)
    , m_shadowOnlyImageFilter(other.m_shadowOnlyImageFilter)
    , m_shadowAndForegroundImageFilter(other.m_shadowAndForegroundImageFilter)
    , m_globalAlpha(other.m_globalAlpha)
    , m_transform(other.m_transform)
    , m_lineDash(other.m_lineDash)
    , m_lineDashOffset(other.m_lineDashOffset)
    , m_unparsedFont(other.m_unparsedFont)
    , m_font(other.m_font)
<<<<<<< HEAD
    , m_fontForFilter(other.m_fontForFilter)
=======
>>>>>>> miniblink49
    , m_unparsedFilter(other.m_unparsedFilter)
    , m_filterValue(other.m_filterValue)
    , m_resolvedFilter(other.m_resolvedFilter)
    , m_textAlign(other.m_textAlign)
    , m_textBaseline(other.m_textBaseline)
    , m_direction(other.m_direction)
    , m_realizedFont(other.m_realizedFont)
    , m_isTransformInvertible(other.m_isTransformInvertible)
    , m_hasClip(other.m_hasClip)
    , m_hasComplexClip(other.m_hasComplexClip)
    , m_fillStyleDirty(other.m_fillStyleDirty)
    , m_strokeStyleDirty(other.m_strokeStyleDirty)
    , m_lineDashDirty(other.m_lineDashDirty)
<<<<<<< HEAD
    , m_imageSmoothingEnabled(other.m_imageSmoothingEnabled)
    , m_imageSmoothingQuality(other.m_imageSmoothingQuality)
=======
>>>>>>> miniblink49
{
    if (mode == CopyClipList) {
        m_clipList = other.m_clipList;
    }
    if (m_realizedFont)
<<<<<<< HEAD
        static_cast<CSSFontSelector*>(m_font.getFontSelector())
            ->registerForInvalidationCallbacks(this);
}

CanvasRenderingContext2DState::~CanvasRenderingContext2DState() { }

void CanvasRenderingContext2DState::fontsNeedUpdate(
    CSSFontSelector* fontSelector)
{
    DCHECK_EQ(fontSelector, m_font.getFontSelector());
=======
        static_cast<CSSFontSelector*>(m_font.fontSelector())->registerForInvalidationCallbacks(this);
}

CanvasRenderingContext2DState& CanvasRenderingContext2DState::operator=(const CanvasRenderingContext2DState& other)
{
    if (this == &other)
        return *this;

#if !ENABLE(OILPAN)
    if (m_realizedFont)
        static_cast<CSSFontSelector*>(m_font.fontSelector())->unregisterForInvalidationCallbacks(this);
#endif

    m_unrealizedSaveCount = other.m_unrealizedSaveCount;
    m_unparsedStrokeColor = other.m_unparsedStrokeColor;
    m_unparsedFillColor = other.m_unparsedFillColor;
    m_strokeStyle = other.m_strokeStyle;
    m_fillStyle = other.m_fillStyle;
    m_strokePaint = other.m_strokePaint;
    m_fillPaint = other.m_fillPaint;
    m_imagePaint = other.m_imagePaint;
    m_shadowOffset = other.m_shadowOffset;
    m_shadowBlur = other.m_shadowBlur;
    m_shadowColor = other.m_shadowColor;
    m_emptyDrawLooper = other.m_emptyDrawLooper;
    m_shadowOnlyDrawLooper = other.m_shadowOnlyDrawLooper;
    m_shadowAndForegroundDrawLooper = other.m_shadowAndForegroundDrawLooper;
    m_shadowOnlyImageFilter = other.m_shadowOnlyImageFilter;
    m_shadowAndForegroundImageFilter = other.m_shadowAndForegroundImageFilter;
    m_globalAlpha = other.m_globalAlpha;
    m_transform = other.m_transform;
    m_lineDash = other.m_lineDash;
    m_lineDashOffset = other.m_lineDashOffset;
    m_unparsedFont = other.m_unparsedFont;
    m_font = other.m_font;
    m_textAlign = other.m_textAlign;
    m_textBaseline = other.m_textBaseline;
    m_direction = other.m_direction;
    m_realizedFont = other.m_realizedFont;
    m_isTransformInvertible = other.m_isTransformInvertible;
    m_hasClip = other.m_hasClip;
    m_hasComplexClip = other.m_hasComplexClip;
    m_fillStyleDirty = other.m_fillStyleDirty;
    m_strokeStyleDirty = other.m_strokeStyleDirty;
    m_lineDashDirty = other.m_lineDashDirty;
    m_clipList = other.m_clipList;

    if (m_realizedFont)
        static_cast<CSSFontSelector*>(m_font.fontSelector())->registerForInvalidationCallbacks(this);

    return *this;
}

CanvasRenderingContext2DState::~CanvasRenderingContext2DState()
{
#if !ENABLE(OILPAN)
    if (m_realizedFont)
        static_cast<CSSFontSelector*>(m_font.fontSelector())->unregisterForInvalidationCallbacks(this);
#endif
}

void CanvasRenderingContext2DState::fontsNeedUpdate(CSSFontSelector* fontSelector)
{
    ASSERT_ARG(fontSelector, fontSelector == m_font.fontSelector());
>>>>>>> miniblink49
    ASSERT(m_realizedFont);

    m_font.update(fontSelector);
    // FIXME: We only really need to invalidate the resolved filter if the font
    // update above changed anything and the filter uses font-dependent units.
<<<<<<< HEAD
    m_resolvedFilter.reset();
=======
    m_resolvedFilter.clear();
>>>>>>> miniblink49
}

DEFINE_TRACE(CanvasRenderingContext2DState)
{
    visitor->trace(m_strokeStyle);
    visitor->trace(m_fillStyle);
    visitor->trace(m_filterValue);
    CSSFontSelectorClient::trace(visitor);
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setLineDashOffset(double offset)
=======
void CanvasRenderingContext2DState::setLineDashOffset(float offset)
>>>>>>> miniblink49
{
    m_lineDashOffset = offset;
    m_lineDashDirty = true;
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setLineDash(const Vector<double>& dash)
=======
void CanvasRenderingContext2DState::setLineDash(const Vector<float>& dash)
>>>>>>> miniblink49
{
    m_lineDash = dash;
    // Spec requires the concatenation of two copies the dash list when the
    // number of elements is odd
    if (dash.size() % 2)
        m_lineDash.appendVector(dash);

    m_lineDashDirty = true;
}

<<<<<<< HEAD
static bool hasANonZeroElement(const Vector<double>& lineDash)
{
    for (size_t i = 0; i < lineDash.size(); i++) {
        if (lineDash[i] != 0.0)
            return true;
    }
    return false;
}

=======
>>>>>>> miniblink49
void CanvasRenderingContext2DState::updateLineDash() const
{
    if (!m_lineDashDirty)
        return;

<<<<<<< HEAD
    if (!hasANonZeroElement(m_lineDash)) {
        m_strokePaint.setPathEffect(0);
    } else {
        Vector<float> lineDash(m_lineDash.size());
        std::copy(m_lineDash.begin(), m_lineDash.end(), lineDash.begin());
        m_strokePaint.setPathEffect(SkDashPathEffect::Make(
            lineDash.data(), lineDash.size(), m_lineDashOffset));
=======
    if (m_lineDash.size() == 0) {
        m_strokePaint.setPathEffect(0);
    } else {
        m_strokePaint.setPathEffect(SkDashPathEffect::Create(m_lineDash.data(), m_lineDash.size(), m_lineDashOffset));
>>>>>>> miniblink49
    }

    m_lineDashDirty = false;
}

void CanvasRenderingContext2DState::setStrokeStyle(CanvasStyle* style)
{
    m_strokeStyle = style;
    m_strokeStyleDirty = true;
}

void CanvasRenderingContext2DState::setFillStyle(CanvasStyle* style)
{
    m_fillStyle = style;
    m_fillStyleDirty = true;
}

void CanvasRenderingContext2DState::updateStrokeStyle() const
{
    if (!m_strokeStyleDirty)
        return;

    int clampedAlpha = clampedAlphaForBlending(m_globalAlpha);
    ASSERT(m_strokeStyle);
<<<<<<< HEAD
    m_strokeStyle->applyToPaint(m_strokePaint);
=======
    m_strokePaint.setShader(m_strokeStyle->shader());
>>>>>>> miniblink49
    m_strokePaint.setColor(scaleAlpha(m_strokeStyle->paintColor(), clampedAlpha));
    m_strokeStyleDirty = false;
}

void CanvasRenderingContext2DState::updateFillStyle() const
{
    if (!m_fillStyleDirty)
        return;

    int clampedAlpha = clampedAlphaForBlending(m_globalAlpha);
    ASSERT(m_fillStyle);
<<<<<<< HEAD
    m_fillStyle->applyToPaint(m_fillPaint);
=======
    m_fillPaint.setShader(m_fillStyle->shader());
>>>>>>> miniblink49
    m_fillPaint.setColor(scaleAlpha(m_fillStyle->paintColor(), clampedAlpha));
    m_fillStyleDirty = false;
}

CanvasStyle* CanvasRenderingContext2DState::style(PaintType paintType) const
{
    switch (paintType) {
    case FillPaintType:
        return fillStyle();
    case StrokePaintType:
        return strokeStyle();
    case ImagePaintType:
        return nullptr;
    }
    ASSERT_NOT_REACHED();
    return nullptr;
}

void CanvasRenderingContext2DState::setShouldAntialias(bool shouldAntialias)
{
    m_fillPaint.setAntiAlias(shouldAntialias);
    m_strokePaint.setAntiAlias(shouldAntialias);
    m_imagePaint.setAntiAlias(shouldAntialias);
}

bool CanvasRenderingContext2DState::shouldAntialias() const
{
    ASSERT(m_fillPaint.isAntiAlias() == m_strokePaint.isAntiAlias() && m_fillPaint.isAntiAlias() == m_imagePaint.isAntiAlias());
    return m_fillPaint.isAntiAlias();
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setGlobalAlpha(double alpha)
=======
void CanvasRenderingContext2DState::setGlobalAlpha(float alpha)
>>>>>>> miniblink49
{
    m_globalAlpha = alpha;
    m_strokeStyleDirty = true;
    m_fillStyleDirty = true;
    int imageAlpha = clampedAlphaForBlending(alpha);
    m_imagePaint.setAlpha(imageAlpha > 255 ? 255 : imageAlpha);
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::clipPath(
    const SkPath& path,
    AntiAliasingMode antiAliasingMode)
{
    m_clipList.clipPath(path, antiAliasingMode,
        affineTransformToSkMatrix(m_transform));
=======
void CanvasRenderingContext2DState::clipPath(const SkPath& path, AntiAliasingMode antiAliasingMode)
{
    m_clipList.clipPath(path, antiAliasingMode, affineTransformToSkMatrix(m_transform));
>>>>>>> miniblink49
    m_hasClip = true;
    if (!path.isRect(0))
        m_hasComplexClip = true;
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setFont(const Font& font,
    CSSFontSelector* selector)
{
=======
void CanvasRenderingContext2DState::setFont(const Font& font, CSSFontSelector* selector)
{
#if !ENABLE(OILPAN)
    if (m_realizedFont)
        static_cast<CSSFontSelector*>(m_font.fontSelector())->unregisterForInvalidationCallbacks(this);
#endif
>>>>>>> miniblink49
    m_font = font;
    m_font.update(selector);
    m_realizedFont = true;
    selector->registerForInvalidationCallbacks(this);
<<<<<<< HEAD
=======
    // FIXME: We only really need to invalidate the resolved filter if it
    // uses font-relative units.
    m_resolvedFilter.clear();
>>>>>>> miniblink49
}

const Font& CanvasRenderingContext2DState::font() const
{
    ASSERT(m_realizedFont);
    return m_font;
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setTransform(
    const AffineTransform& transform)
=======
void CanvasRenderingContext2DState::setTransform(const AffineTransform& transform)
>>>>>>> miniblink49
{
    m_isTransformInvertible = transform.isInvertible();
    m_transform = transform;
}

void CanvasRenderingContext2DState::resetTransform()
{
    m_transform.makeIdentity();
    m_isTransformInvertible = true;
}

<<<<<<< HEAD
sk_sp<SkImageFilter> CanvasRenderingContext2DState::getFilter(
    Element* styleResolutionHost,
    IntSize canvasSize,
    CanvasRenderingContext2D* context) const
=======
SkImageFilter* CanvasRenderingContext2DState::getFilter(Element* styleResolutionHost, const Font& font) const
>>>>>>> miniblink49
{
    if (!m_filterValue)
        return nullptr;

<<<<<<< HEAD
    // StyleResolverState cannot be used in frame-less documents.
    if (!styleResolutionHost->document().frame())
        return nullptr;

    if (!m_resolvedFilter) {
        // Update the filter value to the proper base URL if needed.
        if (m_filterValue->mayContainUrl())
            m_filterValue->reResolveUrl(styleResolutionHost->document());

        RefPtr<ComputedStyle> filterStyle = ComputedStyle::create();
        // Must set font in case the filter uses any font-relative units (em, ex)
        filterStyle->setFont(m_fontForFilter);

        StyleResolverState resolverState(styleResolutionHost->document(),
            styleResolutionHost, filterStyle.get());
        resolverState.setStyle(filterStyle);

        StyleBuilder::applyProperty(CSSPropertyFilter, resolverState,
            *m_filterValue);
        resolverState.loadPendingResources();

        // We can't reuse m_fillPaint and m_strokePaint for the filter, since these
        // incorporate the global alpha, which isn't applicable here.
        SkPaint fillPaintForFilter;
        m_fillStyle->applyToPaint(fillPaintForFilter);
        fillPaintForFilter.setColor(m_fillStyle->paintColor());
        SkPaint strokePaintForFilter;
        m_strokeStyle->applyToPaint(strokePaintForFilter);
        strokePaintForFilter.setColor(m_strokeStyle->paintColor());

        FilterEffectBuilder filterEffectBuilder(
            styleResolutionHost, FloatRect((FloatPoint()), FloatSize(canvasSize)),
            1.0f, // Deliberately ignore zoom on the canvas element.
            &fillPaintForFilter, &strokePaintForFilter);

        if (FilterEffect* lastEffect = filterEffectBuilder.buildFilterEffect(filterStyle->filter())) {
            m_resolvedFilter = SkiaImageFilterBuilder::build(lastEffect, ColorSpaceDeviceRGB);
            if (m_resolvedFilter) {
                context->updateFilterReferences(filterStyle->filter());
                if (lastEffect->originTainted())
                    context->setOriginTainted();
            }
        }
    }

    return m_resolvedFilter;
}

bool CanvasRenderingContext2DState::hasFilter(
    Element* styleResolutionHost,
    IntSize canvasSize,
    CanvasRenderingContext2D* context) const
{
    // Checking for a non-null m_filterValue isn't sufficient, since this value
    // might refer to a non-existent filter.
    return !!getFilter(styleResolutionHost, canvasSize, context);
}

void CanvasRenderingContext2DState::clearResolvedFilter() const
{
    m_resolvedFilter.reset();
=======
    if (!m_resolvedFilter) {
        RefPtr<ComputedStyle> filterStyle = ComputedStyle::create();
        // Must set font in case the filter uses any font-relative units (em, ex)
        filterStyle->setFont(font);

        StyleResolverState resolverState(styleResolutionHost->document(), styleResolutionHost, filterStyle.get());
        resolverState.setStyle(filterStyle);

        // TODO(junov): crbug.com/502877 Feed m_fillStyle and m_strokeStyle into FillPaint and
        // StrokePaint respectively for filters that reference SVG.
        StyleBuilder::applyProperty(CSSPropertyWebkitFilter, resolverState, m_filterValue.get());
        RefPtrWillBeRawPtr<FilterEffectBuilder> filterEffectBuilder = FilterEffectBuilder::create();
        const float effectiveZoom = 1.0f; // Deliberately ignore zoom on the canvas element
        filterEffectBuilder->build(styleResolutionHost, filterStyle->filter(), effectiveZoom);

        SkiaImageFilterBuilder imageFilterBuilder;
        RefPtrWillBeRawPtr<FilterEffect> lastEffect = filterEffectBuilder->lastEffect();
        m_resolvedFilter = imageFilterBuilder.build(lastEffect.get(), ColorSpaceDeviceRGB);
    }

    return m_resolvedFilter.get();
>>>>>>> miniblink49
}

SkDrawLooper* CanvasRenderingContext2DState::emptyDrawLooper() const
{
<<<<<<< HEAD
    if (!m_emptyDrawLooper)
        m_emptyDrawLooper = DrawLooperBuilder().detachDrawLooper();

=======
    if (!m_emptyDrawLooper) {
        OwnPtr<DrawLooperBuilder> drawLooperBuilder = DrawLooperBuilder::create();
        m_emptyDrawLooper = drawLooperBuilder->detachDrawLooper();
    }
>>>>>>> miniblink49
    return m_emptyDrawLooper.get();
}

SkDrawLooper* CanvasRenderingContext2DState::shadowOnlyDrawLooper() const
{
    if (!m_shadowOnlyDrawLooper) {
<<<<<<< HEAD
        DrawLooperBuilder drawLooperBuilder;
        drawLooperBuilder.addShadow(m_shadowOffset, m_shadowBlur, m_shadowColor,
            DrawLooperBuilder::ShadowIgnoresTransforms,
            DrawLooperBuilder::ShadowRespectsAlpha);
        m_shadowOnlyDrawLooper = drawLooperBuilder.detachDrawLooper();
=======
        OwnPtr<DrawLooperBuilder> drawLooperBuilder = DrawLooperBuilder::create();
        drawLooperBuilder->addShadow(m_shadowOffset, m_shadowBlur, m_shadowColor, DrawLooperBuilder::ShadowIgnoresTransforms, DrawLooperBuilder::ShadowRespectsAlpha);
        m_shadowOnlyDrawLooper = drawLooperBuilder->detachDrawLooper();
>>>>>>> miniblink49
    }
    return m_shadowOnlyDrawLooper.get();
}

<<<<<<< HEAD
SkDrawLooper* CanvasRenderingContext2DState::shadowAndForegroundDrawLooper()
    const
{
    if (!m_shadowAndForegroundDrawLooper) {
        DrawLooperBuilder drawLooperBuilder;
        drawLooperBuilder.addShadow(m_shadowOffset, m_shadowBlur, m_shadowColor,
            DrawLooperBuilder::ShadowIgnoresTransforms,
            DrawLooperBuilder::ShadowRespectsAlpha);
        drawLooperBuilder.addUnmodifiedContent();
        m_shadowAndForegroundDrawLooper = drawLooperBuilder.detachDrawLooper();
=======
SkDrawLooper* CanvasRenderingContext2DState::shadowAndForegroundDrawLooper() const
{
    if (!m_shadowAndForegroundDrawLooper) {
        OwnPtr<DrawLooperBuilder> drawLooperBuilder = DrawLooperBuilder::create();
        drawLooperBuilder->addShadow(m_shadowOffset, m_shadowBlur, m_shadowColor, DrawLooperBuilder::ShadowIgnoresTransforms, DrawLooperBuilder::ShadowRespectsAlpha);
        drawLooperBuilder->addUnmodifiedContent();
        m_shadowAndForegroundDrawLooper = drawLooperBuilder->detachDrawLooper();
>>>>>>> miniblink49
    }
    return m_shadowAndForegroundDrawLooper.get();
}

<<<<<<< HEAD
sk_sp<SkImageFilter> CanvasRenderingContext2DState::shadowOnlyImageFilter()
    const
{
    if (!m_shadowOnlyImageFilter) {
        double sigma = skBlurRadiusToSigma(m_shadowBlur);
        m_shadowOnlyImageFilter = SkDropShadowImageFilter::Make(
            m_shadowOffset.width(), m_shadowOffset.height(), sigma, sigma,
            m_shadowColor, SkDropShadowImageFilter::kDrawShadowOnly_ShadowMode,
            nullptr);
    }
    return m_shadowOnlyImageFilter;
}

sk_sp<SkImageFilter>
CanvasRenderingContext2DState::shadowAndForegroundImageFilter() const
{
    if (!m_shadowAndForegroundImageFilter) {
        double sigma = skBlurRadiusToSigma(m_shadowBlur);
        m_shadowAndForegroundImageFilter = SkDropShadowImageFilter::Make(
            m_shadowOffset.width(), m_shadowOffset.height(), sigma, sigma,
            m_shadowColor,
            SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, nullptr);
    }
    return m_shadowAndForegroundImageFilter;
=======
SkImageFilter* CanvasRenderingContext2DState::shadowOnlyImageFilter() const
{
    if (!m_shadowOnlyImageFilter) {
        float sigma = skBlurRadiusToSigma(m_shadowBlur);
        m_shadowOnlyImageFilter = adoptRef(SkDropShadowImageFilter::Create(m_shadowOffset.width(), m_shadowOffset.height(), sigma, sigma, m_shadowColor, SkDropShadowImageFilter::kDrawShadowOnly_ShadowMode));
    }
    return m_shadowOnlyImageFilter.get();
}

SkImageFilter* CanvasRenderingContext2DState::shadowAndForegroundImageFilter() const
{
    if (!m_shadowAndForegroundImageFilter) {
        float sigma = skBlurRadiusToSigma(m_shadowBlur);
        m_shadowAndForegroundImageFilter = adoptRef(SkDropShadowImageFilter::Create(m_shadowOffset.width(), m_shadowOffset.height(), sigma, sigma, m_shadowColor, SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode));
    }
    return m_shadowAndForegroundImageFilter.get();
>>>>>>> miniblink49
}

void CanvasRenderingContext2DState::shadowParameterChanged()
{
<<<<<<< HEAD
    m_shadowOnlyDrawLooper.reset();
    m_shadowAndForegroundDrawLooper.reset();
    m_shadowOnlyImageFilter.reset();
    m_shadowAndForegroundImageFilter.reset();
}

void CanvasRenderingContext2DState::setShadowOffsetX(double x)
=======
    m_shadowOnlyDrawLooper.clear();
    m_shadowAndForegroundDrawLooper.clear();
    m_shadowOnlyImageFilter.clear();
    m_shadowAndForegroundImageFilter.clear();
}

void CanvasRenderingContext2DState::setShadowOffsetX(float x)
>>>>>>> miniblink49
{
    m_shadowOffset.setWidth(x);
    shadowParameterChanged();
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setShadowOffsetY(double y)
=======
void CanvasRenderingContext2DState::setShadowOffsetY(float y)
>>>>>>> miniblink49
{
    m_shadowOffset.setHeight(y);
    shadowParameterChanged();
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setShadowBlur(double shadowBlur)
=======
void CanvasRenderingContext2DState::setShadowBlur(float shadowBlur)
>>>>>>> miniblink49
{
    m_shadowBlur = shadowBlur;
    shadowParameterChanged();
}

void CanvasRenderingContext2DState::setShadowColor(SkColor shadowColor)
{
    m_shadowColor = shadowColor;
    shadowParameterChanged();
}

<<<<<<< HEAD
void CanvasRenderingContext2DState::setFilter(const CSSValue* filterValue)
{
    m_filterValue = filterValue;
    m_resolvedFilter.reset();
}

void CanvasRenderingContext2DState::setGlobalComposite(SkBlendMode mode)
{
    m_strokePaint.setBlendMode(mode);
    m_fillPaint.setBlendMode(mode);
    m_imagePaint.setBlendMode(mode);

    //m_strokePaint.setXfermodeMode(SkXfermode::kDstOut_Mode);
    //m_fillPaint.setXfermodeMode(SkXfermode::kDstOut_Mode);
    //m_imagePaint.setXfermodeMode(SkXfermode::kDstOut_Mode);
}

SkBlendMode CanvasRenderingContext2DState::globalComposite() const
{
    return m_strokePaint.getBlendMode();
=======
void CanvasRenderingContext2DState::setFilter(PassRefPtrWillBeRawPtr<CSSValue> filterValue)
{
    m_filterValue = filterValue;
    m_resolvedFilter.clear();
}

void CanvasRenderingContext2DState::setGlobalComposite(SkXfermode::Mode mode)
{
    m_strokePaint.setXfermodeMode(mode);
    m_fillPaint.setXfermodeMode(mode);
    m_imagePaint.setXfermodeMode(mode);
}

SkXfermode::Mode CanvasRenderingContext2DState::globalComposite() const
{
    SkXfermode* xferMode = m_strokePaint.getXfermode();
    SkXfermode::Mode mode;
    if (!xferMode || !xferMode->asMode(&mode))
        return SkXfermode::kSrcOver_Mode;
    return mode;
>>>>>>> miniblink49
}

void CanvasRenderingContext2DState::setImageSmoothingEnabled(bool enabled)
{
<<<<<<< HEAD
    m_imageSmoothingEnabled = enabled;
    updateFilterQuality();
=======
    SkFilterQuality filterQuality = enabled ? kLow_SkFilterQuality : kNone_SkFilterQuality;
    m_strokePaint.setFilterQuality(filterQuality);
    m_fillPaint.setFilterQuality(filterQuality);
    m_imagePaint.setFilterQuality(filterQuality);
>>>>>>> miniblink49
}

bool CanvasRenderingContext2DState::imageSmoothingEnabled() const
{
<<<<<<< HEAD
    return m_imageSmoothingEnabled;
}

void CanvasRenderingContext2DState::setImageSmoothingQuality(
    const String& qualityString)
{
    if (qualityString == "low") {
        m_imageSmoothingQuality = kLow_SkFilterQuality;
    } else if (qualityString == "medium") {
        m_imageSmoothingQuality = kMedium_SkFilterQuality;
    } else if (qualityString == "high") {
        m_imageSmoothingQuality = kHigh_SkFilterQuality;
    } else {
        return;
    }
    updateFilterQuality();
}

String CanvasRenderingContext2DState::imageSmoothingQuality() const
{
    switch (m_imageSmoothingQuality) {
    case kLow_SkFilterQuality:
        return "low";
    case kMedium_SkFilterQuality:
        return "medium";
    case kHigh_SkFilterQuality:
        return "high";
    default:
        ASSERT_NOT_REACHED();
        return "low";
    }
}

void CanvasRenderingContext2DState::updateFilterQuality() const
{
    if (!m_imageSmoothingEnabled) {
        updateFilterQualityWithSkFilterQuality(kNone_SkFilterQuality);
    } else {
        updateFilterQualityWithSkFilterQuality(m_imageSmoothingQuality);
    }
}

void CanvasRenderingContext2DState::updateFilterQualityWithSkFilterQuality(
    const SkFilterQuality& filterQuality) const
{
    m_strokePaint.setFilterQuality(filterQuality);
    m_fillPaint.setFilterQuality(filterQuality);
    m_imagePaint.setFilterQuality(filterQuality);
=======
    return m_imagePaint.getFilterQuality() == kLow_SkFilterQuality;
>>>>>>> miniblink49
}

bool CanvasRenderingContext2DState::shouldDrawShadows() const
{
    return alphaChannel(m_shadowColor) && (m_shadowBlur || !m_shadowOffset.isZero());
}

<<<<<<< HEAD
const SkPaint* CanvasRenderingContext2DState::getPaint(
    PaintType paintType,
    ShadowMode shadowMode,
    ImageType imageType) const
=======
const SkPaint* CanvasRenderingContext2DState::getPaint(PaintType paintType, ShadowMode shadowMode, ImageType imageType) const
>>>>>>> miniblink49
{
    SkPaint* paint;
    switch (paintType) {
    case StrokePaintType:
        updateLineDash();
        updateStrokeStyle();
        paint = &m_strokePaint;
        break;
    default:
        ASSERT_NOT_REACHED();
<<<<<<< HEAD
    // no break on purpose: paint needs to be assigned to avoid compiler warning
    // about uninitialized variable.
=======
        // no break on purpose: paint needs to be assigned to avoid compiler warning about uninitialized variable
>>>>>>> miniblink49
    case FillPaintType:
        updateFillStyle();
        paint = &m_fillPaint;
        break;
    case ImagePaintType:
        paint = &m_imagePaint;
        break;
    }

    if ((!shouldDrawShadows() && shadowMode == DrawShadowAndForeground) || shadowMode == DrawForegroundOnly) {
        paint->setLooper(0);
        paint->setImageFilter(0);
        return paint;
    }

    if (!shouldDrawShadows() && shadowMode == DrawShadowOnly) {
<<<<<<< HEAD
        paint->setLooper(sk_ref_sp(emptyDrawLooper())); // draw nothing
=======
        paint->setLooper(emptyDrawLooper()); // draw nothing
>>>>>>> miniblink49
        paint->setImageFilter(0);
        return paint;
    }

    if (shadowMode == DrawShadowOnly) {
        if (imageType == NonOpaqueImage || m_filterValue) {
            paint->setLooper(0);
            paint->setImageFilter(shadowOnlyImageFilter());
            return paint;
        }
<<<<<<< HEAD
        paint->setLooper(sk_ref_sp(shadowOnlyDrawLooper()));
=======
        paint->setLooper(shadowOnlyDrawLooper());
>>>>>>> miniblink49
        paint->setImageFilter(0);
        return paint;
    }

    ASSERT(shadowMode == DrawShadowAndForeground);
    if (imageType == NonOpaqueImage) {
        paint->setLooper(0);
        paint->setImageFilter(shadowAndForegroundImageFilter());
        return paint;
    }
<<<<<<< HEAD
    paint->setLooper(sk_ref_sp(shadowAndForegroundDrawLooper()));
=======
    paint->setLooper(shadowAndForegroundDrawLooper());
>>>>>>> miniblink49
    paint->setImageFilter(0);
    return paint;
}

<<<<<<< HEAD
} // namespace blink
=======
} // blink
>>>>>>> miniblink49

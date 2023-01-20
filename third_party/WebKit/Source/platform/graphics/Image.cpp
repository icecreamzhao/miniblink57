/*
 * Copyright (C) 2006 Samuel Weinig (sam.weinig@gmail.com)
 * Copyright (C) 2004, 2005, 2006 Apple Computer, Inc.  All rights reserved.
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

<<<<<<< HEAD
#include "platform/graphics/Image.h"

#include "platform/Length.h"
#include "platform/PlatformInstrumentation.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/SharedBuffer.h"
=======
#include "config.h"
#include "platform/graphics/Image.h"

#include "platform/Length.h"
#include "platform/MIMETypeRegistry.h"
#include "platform/PlatformInstrumentation.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/SharedBuffer.h"
#include "platform/TraceEvent.h"
>>>>>>> miniblink49
#include "platform/geometry/FloatPoint.h"
#include "platform/geometry/FloatRect.h"
#include "platform/geometry/FloatSize.h"
#include "platform/graphics/BitmapImage.h"
#include "platform/graphics/DeferredImageDecoder.h"
#include "platform/graphics/GraphicsContext.h"
<<<<<<< HEAD
#include "platform/instrumentation/tracing/TraceEvent.h"
#include "platform/network/mime/MIMETypeRegistry.h"
=======
>>>>>>> miniblink49
#include "public/platform/Platform.h"
#include "public/platform/WebData.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "third_party/skia/include/core/SkImage.h"
#include "third_party/skia/include/core/SkPictureRecorder.h"
<<<<<<< HEAD
#include "wtf/StdLibExtras.h"

#include <math.h>
#include <tuple>
=======
#include "wtf/MainThread.h"
#include "wtf/StdLibExtras.h"

#include <math.h>
>>>>>>> miniblink49

namespace blink {

Image::Image(ImageObserver* observer)
    : m_imageObserver(observer)
<<<<<<< HEAD
    , m_imageObserverDisabled(false)
{
}

Image::~Image() { }
=======
{
}

Image::~Image()
{
}
>>>>>>> miniblink49

Image* Image::nullImage()
{
    ASSERT(isMainThread());
    DEFINE_STATIC_REF(Image, nullImage, (BitmapImage::create()));
    return nullImage;
}

<<<<<<< HEAD
PassRefPtr<Image> Image::loadPlatformResource(const char* name)
=======
PassRefPtr<Image> Image::loadPlatformResource(const char *name)
>>>>>>> miniblink49
{
    const WebData& resource = Platform::current()->loadResource(name);
    if (resource.isEmpty())
        return Image::nullImage();

    RefPtr<Image> image = BitmapImage::create();
    image->setData(resource, true);
    return image.release();
}

bool Image::supportsType(const String& type)
{
    return MIMETypeRegistry::isSupportedImageResourceMIMEType(type);
}

<<<<<<< HEAD
Image::SizeAvailability Image::setData(PassRefPtr<SharedBuffer> data,
    bool allDataReceived)
{
    m_encodedImageData = data;
    if (!m_encodedImageData.get())
        return SizeAvailable;

    int length = m_encodedImageData->size();
    if (!length)
        return SizeAvailable;
=======
bool Image::setData(PassRefPtr<SharedBuffer> data, bool allDataReceived)
{
    m_encodedImageData = data;
    if (!m_encodedImageData.get())
        return true;

    int length = m_encodedImageData->size();
    if (!length)
        return true;
>>>>>>> miniblink49

    return dataChanged(allDataReceived);
}

<<<<<<< HEAD
void Image::drawTiledBackground(GraphicsContext& ctxt,
    const FloatRect& destRect,
    const FloatPoint& srcPoint,
    const FloatSize& scaledTileSize,
    SkBlendMode op,
    const FloatSize& repeatSpacing)
{
    FloatSize intrinsicTileSize(size());
    if (hasRelativeSize()) {
        intrinsicTileSize.setWidth(scaledTileSize.width());
        intrinsicTileSize.setHeight(scaledTileSize.height());
    }

    const FloatSize scale(scaledTileSize.width() / intrinsicTileSize.width(),
        scaledTileSize.height() / intrinsicTileSize.height());

    const FloatRect oneTileRect = computeTileContaining(
        destRect.location(), scaledTileSize, srcPoint, repeatSpacing);

    // Check and see if a single draw of the image can cover the entire area we
    // are supposed to tile.
    if (oneTileRect.contains(destRect)) {
        const FloatRect visibleSrcRect = computeSubsetForTile(oneTileRect, destRect, intrinsicTileSize);
        ctxt.drawImage(this, destRect, &visibleSrcRect, op,
            DoNotRespectImageOrientation);
=======
void Image::fillWithSolidColor(GraphicsContext* ctxt, const FloatRect& dstRect, const Color& color, SkXfermode::Mode op)
{
    if (!color.alpha())
        return;

    SkXfermode::Mode xferMode = !color.hasAlpha() && op == SkXfermode::kSrcOver_Mode ?
        SkXfermode::kSrc_Mode : op;
    ctxt->fillRect(dstRect, color, xferMode);
}

void Image::drawTiled(GraphicsContext* ctxt, const FloatRect& destRect, const FloatPoint& srcPoint, const FloatSize& scaledTileSize, SkXfermode::Mode op, const IntSize& repeatSpacing)
{
    if (mayFillWithSolidColor()) {
        fillWithSolidColor(ctxt, destRect, solidColor(), op);
        return;
    }

    // See <https://webkit.org/b/59043>.
    ASSERT(!isBitmapImage() || notSolidColor());

    FloatSize intrinsicTileSize = size();
    if (hasRelativeWidth())
        intrinsicTileSize.setWidth(scaledTileSize.width());
    if (hasRelativeHeight())
        intrinsicTileSize.setHeight(scaledTileSize.height());

    FloatSize scale(scaledTileSize.width() / intrinsicTileSize.width(),
                    scaledTileSize.height() / intrinsicTileSize.height());

    FloatSize actualTileSize(scaledTileSize.width() + repeatSpacing.width(), scaledTileSize.height() + repeatSpacing.height());
    FloatRect oneTileRect;
    oneTileRect.setX(destRect.x() + fmodf(fmodf(-srcPoint.x(), actualTileSize.width()) - actualTileSize.width(), actualTileSize.width()));
    oneTileRect.setY(destRect.y() + fmodf(fmodf(-srcPoint.y(), actualTileSize.height()) - actualTileSize.height(), actualTileSize.height()));
    oneTileRect.setSize(scaledTileSize);

    // Check and see if a single draw of the image can cover the entire area we are supposed to tile.
    if (oneTileRect.contains(destRect)) {
        FloatRect visibleSrcRect;
        visibleSrcRect.setX((destRect.x() - oneTileRect.x()) / scale.width());
        visibleSrcRect.setY((destRect.y() - oneTileRect.y()) / scale.height());
        visibleSrcRect.setWidth(destRect.width() / scale.width());
        visibleSrcRect.setHeight(destRect.height() / scale.height());
        ctxt->drawImage(this, destRect, visibleSrcRect, op, DoNotRespectImageOrientation);
>>>>>>> miniblink49
        return;
    }

    FloatRect tileRect(FloatPoint(), intrinsicTileSize);
<<<<<<< HEAD
    drawPattern(ctxt, tileRect, scale, oneTileRect.location(), op, destRect,
        repeatSpacing);
=======
    drawPattern(ctxt, tileRect, scale, oneTileRect.location(), op, destRect, repeatSpacing);
>>>>>>> miniblink49

    startAnimation();
}

<<<<<<< HEAD
void Image::drawTiledBorder(GraphicsContext& ctxt,
    const FloatRect& dstRect,
    const FloatRect& srcRect,
    const FloatSize& providedTileScaleFactor,
    TileRule hRule,
    TileRule vRule,
    SkBlendMode op)
{
    // TODO(cavalcantii): see crbug.com/662513.
    FloatSize tileScaleFactor = providedTileScaleFactor;
=======
// FIXME: Merge with the other drawTiled eventually, since we need a combination of both for some things.
void Image::drawTiled(GraphicsContext* ctxt, const FloatRect& dstRect, const FloatRect& srcRect,
    const FloatSize& providedTileScaleFactor, TileRule hRule, TileRule vRule, SkXfermode::Mode op)
{
    if (mayFillWithSolidColor()) {
        fillWithSolidColor(ctxt, dstRect, solidColor(), op);
        return;
    }

    // FIXME: We do not support 'space' yet. For now just map it to 'repeat'.
    if (hRule == SpaceTile)
        hRule = RepeatTile;
    if (vRule == SpaceTile)
        vRule = RepeatTile;

    // FIXME: if this code is used for background-repeat: round (in addition to
    // border-image-repeat), then add logic to deal with the background-size: auto
    // special case. The aspect ratio should be maintained in this case.
    FloatSize tileScaleFactor = providedTileScaleFactor;
    bool useLowInterpolationQuality = false;
    if (hRule == RoundTile) {
        float hRepetitions = std::max(1.0f, roundf(dstRect.width() / (tileScaleFactor.width() * srcRect.width())));
        tileScaleFactor.setWidth(dstRect.width() / (srcRect.width() * hRepetitions));
    }
>>>>>>> miniblink49
    if (vRule == RoundTile) {
        float vRepetitions = std::max(1.0f, roundf(dstRect.height() / (tileScaleFactor.height() * srcRect.height())));
        tileScaleFactor.setHeight(dstRect.height() / (srcRect.height() * vRepetitions));
    }
<<<<<<< HEAD

    if (hRule == RoundTile) {
        float hRepetitions = std::max(
            1.0f,
            roundf(dstRect.width() / (tileScaleFactor.width() * srcRect.width())));
        tileScaleFactor.setWidth(dstRect.width() / (srcRect.width() * hRepetitions));
    }

    // We want to construct the phase such that the pattern is centered (when
    // stretch is not set for a particular rule).
    float vPhase = tileScaleFactor.height() * srcRect.y();
    float hPhase = tileScaleFactor.width() * srcRect.x();
    if (vRule == RepeatTile) {
        float scaledTileHeight = tileScaleFactor.height() * srcRect.height();
        vPhase -= (dstRect.height() - scaledTileHeight) / 2;
    }

    if (hRule == RepeatTile) {
        float scaledTileWidth = tileScaleFactor.width() * srcRect.width();
        hPhase -= (dstRect.width() - scaledTileWidth) / 2;
    }

    FloatSize spacing;
    auto calculateSpaceNeeded = [](
                                    const float destination, const float source) -> std::tuple<bool, float> {
        DCHECK_GT(source, 0);
        DCHECK_GT(destination, 0);

        float repeatTilesCount = floorf(destination / source);
        if (!repeatTilesCount)
            return std::make_tuple(false, -1);

        float space = destination;
        space -= source * repeatTilesCount;
        space /= repeatTilesCount + 1.0;

        return std::make_tuple(true, space);
    };

    if (vRule == SpaceTile) {
        std::tuple<bool, float> space = calculateSpaceNeeded(dstRect.height(), srcRect.height());
        if (!std::get<0>(space))
            return;

        spacing.setHeight(std::get<1>(space));
        tileScaleFactor.setHeight(1.0);
        vPhase = srcRect.y();
        vPhase -= spacing.height();
    }

    if (hRule == SpaceTile) {
        std::tuple<bool, float> space = calculateSpaceNeeded(dstRect.width(), srcRect.width());
        if (!std::get<0>(space))
            return;

        spacing.setWidth(std::get<1>(space));
        tileScaleFactor.setWidth(1.0);
        hPhase = srcRect.x();
        hPhase -= spacing.width();
    }

    FloatPoint patternPhase(dstRect.x() - hPhase, dstRect.y() - vPhase);

    // TODO(cavalcantii): see crbug.com/662507.
    if ((hRule == RoundTile) || (vRule == RoundTile)) {
        InterpolationQuality previousInterpolationQuality = ctxt.imageInterpolationQuality();
        ctxt.setImageInterpolationQuality(InterpolationLow);
        drawPattern(ctxt, srcRect, tileScaleFactor, patternPhase, op, dstRect);
        ctxt.setImageInterpolationQuality(previousInterpolationQuality);
    } else {
        drawPattern(ctxt, srcRect, tileScaleFactor, patternPhase, op, dstRect,
            spacing);
=======
    if (hRule == RoundTile || vRule == RoundTile) {
        // High interpolation quality rounds the scaled tile to an integer size (see Image::drawPattern).
        // To avoid causing a visual problem, linear interpolation must be used instead.
        // FIXME: Allow using high-quality interpolation in this case, too.
        useLowInterpolationQuality = true;
    }

    // We want to construct the phase such that the pattern is centered (when stretch is not
    // set for a particular rule).
    float hPhase = tileScaleFactor.width() * srcRect.x();
    float vPhase = tileScaleFactor.height() * srcRect.y();
    float scaledTileWidth = tileScaleFactor.width() * srcRect.width();
    float scaledTileHeight = tileScaleFactor.height() * srcRect.height();
    if (hRule == Image::RepeatTile)
        hPhase -= (dstRect.width() - scaledTileWidth) / 2;
    if (vRule == Image::RepeatTile)
        vPhase -= (dstRect.height() - scaledTileHeight) / 2;
    FloatPoint patternPhase(dstRect.x() - hPhase, dstRect.y() - vPhase);

    if (useLowInterpolationQuality) {
        InterpolationQuality previousInterpolationQuality = ctxt->imageInterpolationQuality();
        ctxt->setImageInterpolationQuality(InterpolationLow);
        drawPattern(ctxt, srcRect, tileScaleFactor, patternPhase, op, dstRect);
        ctxt->setImageInterpolationQuality(previousInterpolationQuality);
    } else {
        drawPattern(ctxt, srcRect, tileScaleFactor, patternPhase, op, dstRect);
>>>>>>> miniblink49
    }

    startAnimation();
}

namespace {

<<<<<<< HEAD
    sk_sp<SkShader> createPatternShader(const SkImage* image,
        const SkMatrix& shaderMatrix,
        const SkPaint& paint,
        const FloatSize& spacing,
        SkShader::TileMode tmx,
        SkShader::TileMode tmy)
    {
        if (spacing.isZero())
            return image->makeShader(tmx, tmy, &shaderMatrix);

        // Arbitrary tiling is currently only supported for SkPictureShader, so we use
        // that instead of a plain bitmap shader to implement spacing.
        const SkRect tileRect = SkRect::MakeWH(image->width() + spacing.width(),
            image->height() + spacing.height());

        SkPictureRecorder recorder;
        SkCanvas* canvas = recorder.beginRecording(tileRect);
        canvas->drawImage(image, 0, 0, &paint);

        return SkShader::MakePictureShader(recorder.finishRecordingAsPicture(), tmx,
            tmy, &shaderMatrix, nullptr);
    }

    SkShader::TileMode computeTileMode(float left,
        float right,
        float min,
        float max)
    {
        DCHECK(left < right);
        return left >= min && right <= max ? SkShader::kClamp_TileMode
                                           : SkShader::kRepeat_TileMode;
    }

} // anonymous namespace

void Image::drawPattern(GraphicsContext& context,
    const FloatRect& floatSrcRect,
    const FloatSize& scale,
    const FloatPoint& phase,
    SkBlendMode compositeOp,
    const FloatRect& destRect,
    const FloatSize& repeatSpacing)
{
    TRACE_EVENT0("skia", "Image::drawPattern");

    sk_sp<SkImage> image = imageForCurrentFrame(context.getColorBehavior());
    if (!image)
=======
PassRefPtr<SkShader> createPatternShader(const SkBitmap& bitmap, const SkMatrix& shaderMatrix,
    const SkPaint& paint, const FloatSize& spacing)
{
    if (spacing.isZero()) {
        return adoptRef(SkShader::CreateBitmapShader(
            bitmap, SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode, &shaderMatrix));
    }

    // Arbitrary tiling is currently only supported for SkPictureShader - so we use it instead
    // of a plain bitmap shader to implement spacing.
    const SkRect tileRect = SkRect::MakeWH(
        bitmap.width() + spacing.width(),
        bitmap.height() + spacing.height());

    SkPictureRecorder recorder;
    SkCanvas* canvas = recorder.beginRecording(tileRect);
    canvas->drawBitmap(bitmap, 0, 0, &paint);
    RefPtr<const SkPicture> picture = adoptRef(recorder.endRecordingAsPicture());

    return adoptRef(SkShader::CreatePictureShader(
        picture.get(), SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode, &shaderMatrix, nullptr));
}

} // anonymous namespace

void Image::drawPattern(GraphicsContext* context, const FloatRect& floatSrcRect, const FloatSize& scale,
    const FloatPoint& phase, SkXfermode::Mode compositeOp, const FloatRect& destRect, const IntSize& repeatSpacing)
{
    TRACE_EVENT0("skia", "Image::drawPattern");
    SkBitmap bitmap;
    if (!bitmapForCurrentFrame(&bitmap))
>>>>>>> miniblink49
        return;

    FloatRect normSrcRect = floatSrcRect;

<<<<<<< HEAD
    normSrcRect.intersect(FloatRect(0, 0, image->width(), image->height()));
=======
    normSrcRect.intersect(FloatRect(0, 0, bitmap.width(), bitmap.height()));
>>>>>>> miniblink49
    if (destRect.isEmpty() || normSrcRect.isEmpty())
        return; // nothing to draw

    SkMatrix localMatrix;
    // We also need to translate it such that the origin of the pattern is the
    // origin of the destination rect, which is what WebKit expects. Skia uses
    // the coordinate system origin as the base for the pattern. If WebKit wants
    // a shifted image, it will shift it from there using the localMatrix.
    const float adjustedX = phase.x() + normSrcRect.x() * scale.width();
    const float adjustedY = phase.y() + normSrcRect.y() * scale.height();
<<<<<<< HEAD
    localMatrix.setTranslate(SkFloatToScalar(adjustedX),
        SkFloatToScalar(adjustedY));
=======
    localMatrix.setTranslate(SkFloatToScalar(adjustedX), SkFloatToScalar(adjustedY));
>>>>>>> miniblink49

    // Because no resizing occurred, the shader transform should be
    // set to the pattern's transform, which just includes scale.
    localMatrix.preScale(scale.width(), scale.height());

<<<<<<< HEAD
    // Fetch this now as subsetting may swap the image.
    auto imageID = image->uniqueID();

    image = image->makeSubset(enclosingIntRect(normSrcRect));
    if (!image)
        return;

    const FloatSize tileSize(
        image->width() * scale.width() + repeatSpacing.width(),
        image->height() * scale.height() + repeatSpacing.height());
    const auto tmx = computeTileMode(destRect.x(), destRect.maxX(), adjustedX,
        adjustedX + tileSize.width());
    const auto tmy = computeTileMode(destRect.y(), destRect.maxY(), adjustedY,
        adjustedY + tileSize.height());

    {
        SkPaint paint = context.fillPaint();
        paint.setColor(SK_ColorBLACK);
        paint.setBlendMode(compositeOp);
        paint.setFilterQuality(
            context.computeFilterQuality(this, destRect, normSrcRect));
        paint.setAntiAlias(context.shouldAntialias());
        paint.setShader(
            createPatternShader(image.get(), localMatrix, paint,
                FloatSize(repeatSpacing.width() / scale.width(),
                    repeatSpacing.height() / scale.height()),
                tmx, tmy));
        context.drawRect(destRect, paint);
    }

    if (currentFrameIsLazyDecoded())
        PlatformInstrumentation::didDrawLazyPixelRef(imageID);
=======
    SkBitmap bitmapToPaint;
    bitmap.extractSubset(&bitmapToPaint, enclosingIntRect(normSrcRect));

    {
        SkPaint paint = context->fillPaint();
        paint.setColor(SK_ColorBLACK);
        paint.setXfermodeMode(compositeOp);
        paint.setFilterQuality(context->computeFilterQuality(this, destRect, normSrcRect));
        paint.setAntiAlias(context->shouldAntialias());
        RefPtr<SkShader> shader = createPatternShader(bitmapToPaint, localMatrix, paint,
            FloatSize(repeatSpacing.width() / scale.width(), repeatSpacing.height() / scale.height()));
        paint.setShader(shader.get());
        context->drawRect(destRect, paint);
    }

    if (DeferredImageDecoder::isLazyDecoded(bitmap))
        PlatformInstrumentation::didDrawLazyPixelRef(bitmap.getGenerationID());
}

void Image::computeIntrinsicDimensions(Length& intrinsicWidth, Length& intrinsicHeight, FloatSize& intrinsicRatio)
{
    intrinsicRatio = size();
    intrinsicWidth = Length(intrinsicRatio.width(), Fixed);
    intrinsicHeight = Length(intrinsicRatio.height(), Fixed);
>>>>>>> miniblink49
}

PassRefPtr<Image> Image::imageForDefaultFrame()
{
    RefPtr<Image> image(this);

    return image.release();
}

<<<<<<< HEAD
bool Image::applyShader(SkPaint& paint,
    const SkMatrix& localMatrix,
    const ColorBehavior& colorBehavior)
{
    // Default shader impl: attempt to build a shader based on the current frame
    // SkImage.
    sk_sp<SkImage> image = imageForCurrentFrame(colorBehavior);
    if (!image)
        return false;

    paint.setShader(image->makeShader(SkShader::kRepeat_TileMode,
        SkShader::kRepeat_TileMode, &localMatrix));

    // Animation is normally refreshed in draw() impls, which we don't call when
    // painting via shaders.
    startAnimation();

    return true;
}

FloatRect Image::computeTileContaining(const FloatPoint& point,
    const FloatSize& tileSize,
    const FloatPoint& tilePhase,
    const FloatSize& tileSpacing)
{
    const FloatSize actualTileSize(tileSize + tileSpacing);
    return FloatRect(
        FloatPoint(
            point.x() + fmodf(fmodf(-tilePhase.x(), actualTileSize.width()) - actualTileSize.width(), actualTileSize.width()),
            point.y() + fmodf(fmodf(-tilePhase.y(), actualTileSize.height()) - actualTileSize.height(), actualTileSize.height())),
        tileSize);
}

FloatRect Image::computeSubsetForTile(const FloatRect& tile,
    const FloatRect& dest,
    const FloatSize& imageSize)
{
    DCHECK(tile.contains(dest));

    const FloatSize scale(tile.width() / imageSize.width(),
        tile.height() / imageSize.height());

    FloatRect subset = dest;
    subset.setX((dest.x() - tile.x()) / scale.width());
    subset.setY((dest.y() - tile.y()) / scale.height());
    subset.setWidth(dest.width() / scale.width());
    subset.setHeight(dest.height() / scale.height());

    return subset;
=======
bool Image::bitmapForCurrentFrame(SkBitmap* bitmap)
{
    return false;
}

PassRefPtr<SkImage> Image::skImage()
{
    return nullptr;
>>>>>>> miniblink49
}

} // namespace blink

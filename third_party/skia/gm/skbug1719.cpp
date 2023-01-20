/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlurMaskFilter.h"
#include "SkColorFilter.h"
#include "SkPath.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkColorFilter.h"
#include "SkBlurMaskFilter.h"

namespace skiagm {
>>>>>>> miniblink49

/**
 * This test exercises bug 1719. An anti-aliased blurred path is rendered through a soft clip. On
 * the GPU a scratch texture was used to hold the original path mask as well as the blurred path
 * result. The same texture is then incorrectly used to generate the soft clip mask for the draw.
 * Thus the same texture is used for both the blur mask and soft mask in a single draw.
 *
 * The correct image should look like a thin stroked round rect.
 */
<<<<<<< HEAD
DEF_SIMPLE_GM_BG(skbug1719, canvas, 300, 100,
    sk_tool_utils::color_to_565(0xFF303030))
{
    canvas->translate(SkIntToScalar(-800), SkIntToScalar(-650));

    // The data is lifted from an SKP that exhibited the bug.

    // This is a round rect.
    SkPath clipPath;
    clipPath.moveTo(832.f, 654.f);
    clipPath.lineTo(1034.f, 654.f);
    clipPath.cubicTo(1038.4183f, 654.f, 1042.f, 657.58173f, 1042.f, 662.f);
    clipPath.lineTo(1042.f, 724.f);
    clipPath.cubicTo(1042.f, 728.41827f, 1038.4183f, 732.f, 1034.f, 732.f);
    clipPath.lineTo(832.f, 732.f);
    clipPath.cubicTo(827.58173f, 732.f, 824.f, 728.41827f, 824.f, 724.f);
    clipPath.lineTo(824.f, 662.f);
    clipPath.cubicTo(824.f, 657.58173f, 827.58173f, 654.f, 832.f, 654.f);
    clipPath.close();

    // This is a round rect nested inside a rect.
    SkPath drawPath;
    drawPath.moveTo(823.f, 653.f);
    drawPath.lineTo(1043.f, 653.f);
    drawPath.lineTo(1043.f, 733.f);
    drawPath.lineTo(823.f, 733.f);
    drawPath.lineTo(823.f, 653.f);
    drawPath.close();
    drawPath.moveTo(832.f, 654.f);
    drawPath.lineTo(1034.f, 654.f);
    drawPath.cubicTo(1038.4183f, 654.f, 1042.f, 657.58173f, 1042.f, 662.f);
    drawPath.lineTo(1042.f, 724.f);
    drawPath.cubicTo(1042.f, 728.41827f, 1038.4183f, 732.f, 1034.f, 732.f);
    drawPath.lineTo(832.f, 732.f);
    drawPath.cubicTo(827.58173f, 732.f, 824.f, 728.41827f, 824.f, 724.f);
    drawPath.lineTo(824.f, 662.f);
    drawPath.cubicTo(824.f, 657.58173f, 827.58173f, 654.f, 832.f, 654.f);
    drawPath.close();
    drawPath.setFillType(SkPath::kEvenOdd_FillType);

    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setColor(0xFF000000);
    paint.setMaskFilter(
        SkBlurMaskFilter::Make(kNormal_SkBlurStyle, 0.78867501f,
            SkBlurMaskFilter::kHighQuality_BlurFlag));
    paint.setColorFilter(SkColorFilter::MakeModeFilter(0xBFFFFFFF, SkXfermode::kSrcIn_Mode));

    canvas->clipPath(clipPath, SkRegion::kIntersect_Op, true);
    canvas->drawPath(drawPath, paint);
=======
class SkBug1719GM : public GM {
public:
    SkBug1719GM() {}

protected:
    SkString onShortName() override {
        return SkString("skbug1719");
    }

    SkISize onISize() override {
        return SkISize::Make(300, 100);
    }

    void onDrawBackground(SkCanvas* canvas) override {
        SkPaint bgPaint;
        bgPaint.setColor(0xFF303030);
        canvas->drawPaint(bgPaint);
    }

    void onDraw(SkCanvas* canvas) override {
        canvas->translate(SkIntToScalar(-800), SkIntToScalar(-650));

        // The data is lifted from an SKP that exhibited the bug.

        // This is a round rect.
        SkPath clipPath;
        clipPath.moveTo(832.f, 654.f);
        clipPath.lineTo(1034.f, 654.f);
        clipPath.cubicTo(1038.4183f, 654.f, 1042.f, 657.58173f, 1042.f, 662.f);
        clipPath.lineTo(1042.f, 724.f);
        clipPath.cubicTo(1042.f, 728.41827f, 1038.4183f, 732.f, 1034.f, 732.f);
        clipPath.lineTo(832.f, 732.f);
        clipPath.cubicTo(827.58173f, 732.f, 824.f, 728.41827f, 824.f, 724.f);
        clipPath.lineTo(824.f, 662.f);
        clipPath.cubicTo(824.f, 657.58173f, 827.58173f, 654.f, 832.f, 654.f);
        clipPath.close();

        // This is a round rect nested inside a rect.
        SkPath drawPath;
        drawPath.moveTo(823.f, 653.f);
        drawPath.lineTo(1043.f, 653.f);
        drawPath.lineTo(1043.f, 733.f);
        drawPath.lineTo(823.f, 733.f);
        drawPath.lineTo(823.f, 653.f);
        drawPath.close();
        drawPath.moveTo(832.f, 654.f);
        drawPath.lineTo(1034.f, 654.f);
        drawPath.cubicTo(1038.4183f, 654.f, 1042.f, 657.58173f, 1042.f, 662.f);
        drawPath.lineTo(1042.f, 724.f);
        drawPath.cubicTo(1042.f, 728.41827f, 1038.4183f, 732.f, 1034.f, 732.f);
        drawPath.lineTo(832.f, 732.f);
        drawPath.cubicTo(827.58173f, 732.f, 824.f, 728.41827f, 824.f, 724.f);
        drawPath.lineTo(824.f, 662.f);
        drawPath.cubicTo(824.f, 657.58173f, 827.58173f, 654.f, 832.f, 654.f);
        drawPath.close();
        drawPath.setFillType(SkPath::kEvenOdd_FillType);

        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setColor(0xFF000000);
        paint.setMaskFilter(
            SkBlurMaskFilter::Create(kNormal_SkBlurStyle,
                                     0.78867501f,
                                     SkBlurMaskFilter::kHighQuality_BlurFlag))->unref();
        paint.setColorFilter(
            SkColorFilter::CreateModeFilter(0xBFFFFFFF, SkXfermode::kSrcIn_Mode))->unref();

        canvas->clipPath(clipPath, SkRegion::kIntersect_Op, true);
        canvas->drawPath(drawPath, paint);
    }

private:

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

DEF_GM(return new SkBug1719GM;)

>>>>>>> miniblink49
}

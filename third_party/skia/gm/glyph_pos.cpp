/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkCanvas.h"
#include "SkTypeface.h"
#include "gm.h"

/* This test tries to define the effect of using hairline strokes on text.
 * Provides non-hairline images for reference and consistency checks.
 * glyph_pos_(h/n)_(s/f/b)
 *   -> test hairline/non-hairline stroke/fill/stroke+fill.
 */
static const SkScalar kTextHeight = 14.0f;
static const char kText[] = "Proportional Hamburgefons #% fi";

static void drawTestCase(SkCanvas* canvas,
    SkScalar textScale,
    SkScalar strokeWidth,
    SkPaint::Style strokeStyle);

static void draw_gm(SkCanvas* canvas,
    SkScalar strokeWidth,
    SkPaint::Style strokeStyle)
{
    // There's a black pixel at 40, 40 for reference.
    canvas->drawPoint(40.0f, 40.0f, SK_ColorBLACK);

    // Two reference images.
    canvas->translate(50.0f, 50.0f);
    drawTestCase(canvas, 1.0f, strokeWidth, strokeStyle);

    canvas->translate(0.0f, 50.0f);
    drawTestCase(canvas, 3.0f, strokeWidth, strokeStyle);

    // Uniform scaling test.
    canvas->translate(0.0f, 100.0f);
    canvas->save();
    canvas->scale(3.0f, 3.0f);
    drawTestCase(canvas, 1.0f, strokeWidth, strokeStyle);
    canvas->restore();

    // Non-uniform scaling test.
    canvas->translate(0.0f, 100.0f);
    canvas->save();
    canvas->scale(3.0f, 6.0f);
    drawTestCase(canvas, 1.0f, strokeWidth, strokeStyle);
    canvas->restore();

    // Skew test.
    canvas->translate(0.0f, 80.0f);
    canvas->save();
    canvas->scale(3.0f, 3.0f);
    SkMatrix skew;
    skew.setIdentity();
    skew.setSkewX(8.0f / 25.0f);
    skew.setSkewY(2.0f / 25.0f);
    canvas->concat(skew);
    drawTestCase(canvas, 1.0f, strokeWidth, strokeStyle);
    canvas->restore();

    // Perspective test.
    canvas->translate(0.0f, 80.0f);
    canvas->save();
    SkMatrix perspective;
    perspective.setIdentity();
    perspective.setPerspX(-SkScalarInvert(340));
    perspective.setSkewX(8.0f / 25.0f);
    perspective.setSkewY(2.0f / 25.0f);

    canvas->concat(perspective);
    drawTestCase(canvas, 1.0f, strokeWidth, strokeStyle);
    canvas->restore();
}

static void drawTestCase(SkCanvas* canvas,
    SkScalar textScale,
    SkScalar strokeWidth,
    SkPaint::Style strokeStyle)
{
    SkPaint paint;
    paint.setColor(SK_ColorBLACK);
    paint.setAntiAlias(true);
    paint.setTextSize(kTextHeight * textScale);
    sk_tool_utils::set_portable_typeface(&paint);
    paint.setStrokeWidth(strokeWidth);
    paint.setStyle(strokeStyle);

    // This demonstrates that we can not measure the text if
    // there's a device transform. The canvas total matrix will
    // end up being a device transform.
    bool drawRef = !(canvas->getTotalMatrix().getType() & ~(SkMatrix::kIdentity_Mask | SkMatrix::kTranslate_Mask));

    SkRect bounds;
    if (drawRef) {
        SkScalar advance = paint.measureText(kText, sizeof(kText) - 1, &bounds);

        paint.setStrokeWidth(0.0f);
        paint.setStyle(SkPaint::kStroke_Style);

        // Green box is the measured text bounds.
        paint.setColor(SK_ColorGREEN);
        canvas->drawRect(bounds, paint);

        // Red line is the measured advance from the 0,0 of the text position.
        paint.setColor(SK_ColorRED);
        canvas->drawLine(0.0f, 0.0f, advance, 0.0f, paint);
    }

    // Black text is the testcase, eg. the text.
    paint.setColor(SK_ColorBLACK);
    paint.setStrokeWidth(strokeWidth);
    paint.setStyle(strokeStyle);
    canvas->drawText(kText, sizeof(kText) - 1, 0.0f, 0.0f, paint);

    if (drawRef) {
        SkScalar widths[sizeof(kText) - 1];
        paint.getTextWidths(kText, sizeof(kText) - 1, widths, nullptr);

        paint.setStrokeWidth(0.0f);
        paint.setStyle(SkPaint::kStroke_Style);

        // Magenta lines are the positions for the characters.
        paint.setColor(SK_ColorMAGENTA);
        SkScalar w = bounds.x();
        for (size_t i = 0; i < sizeof(kText) - 1; ++i) {
            canvas->drawLine(w, 0.0f, w, 5.0f, paint);
            w += widths[i];
        }
    }
}

DEF_SIMPLE_GM(glyph_pos_h_b, c, 800, 600)
{
    draw_gm(c, 0.0f, SkPaint::kStrokeAndFill_Style);
}
DEF_SIMPLE_GM(glyph_pos_n_b, c, 800, 600)
{
    draw_gm(c, 1.2f, SkPaint::kStrokeAndFill_Style);
}
DEF_SIMPLE_GM(glyph_pos_h_s, c, 800, 600)
{
    draw_gm(c, 0.0f, SkPaint::kStroke_Style);
}
DEF_SIMPLE_GM(glyph_pos_n_s, c, 800, 600)
{
    draw_gm(c, 1.2f, SkPaint::kStroke_Style);
}
DEF_SIMPLE_GM(glyph_pos_h_f, c, 800, 600)
{
    draw_gm(c, 0.0f, SkPaint::kFill_Style);
}
DEF_SIMPLE_GM(glyph_pos_n_f, c, 800, 600)
{
    draw_gm(c, 1.2f, SkPaint::kFill_Style);
}

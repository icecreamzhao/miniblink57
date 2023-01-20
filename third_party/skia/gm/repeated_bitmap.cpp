/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "Resources.h"
#include "SkImage.h"
#include "gm.h"
#include "sk_tool_utils.h"

static void draw_rotated_image(SkCanvas* canvas, const SkImage* image)
{
    sk_tool_utils::draw_checkerboard(canvas, SkColorSetRGB(156, 154, 156),
        SK_ColorWHITE, 12);
    if (!image) {
        return;
    }
    SkRect rect = SkRect::MakeLTRB(-68.0f, -68.0f, 68.0f, 68.0f);
    SkPaint paint;
    paint.setColor(SkColorSetRGB(49, 48, 49));
    SkScalar scale = SkTMin(128.0f / image->width(),
        128.0f / image->height());
    SkScalar point[2] = { -0.5f * image->width(), -0.5f * image->height() };
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            SkAutoCanvasRestore autoCanvasRestore(canvas, true);
            canvas->translate(96.0f + 192.0f * i, 96.0f + 192.0f * j);
            canvas->rotate(18.0f * (i + 4 * j));
            canvas->drawRect(rect, paint);
            canvas->scale(scale, scale);
            canvas->drawImage(image, point[0], point[1]);
=======
#include "gm.h"
#include "sk_tool_utils.h"
#include "Resources.h"

DEF_SIMPLE_GM(repeated_bitmap, canvas, 576, 576) {
    sk_tool_utils::draw_checkerboard(canvas, 0xFF999999, SK_ColorWHITE, 12);
    SkRect rect = SkRect::MakeLTRB(-4.25f, -4.25f, 4.25f, 4.25f);
    SkPaint paint;
    paint.setColor(0xFF333333);
    SkBitmap bm;
    if (GetResourceAsBitmap("randPixels.png", &bm)) {
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                SkAutoCanvasRestore autoCanvasRestore(canvas, true);
                canvas->scale(12.0f, 12.0f);
                canvas->translate(6.0f + 12.0f * SkIntToScalar(i),
                                  6.0f + 12.0f * SkIntToScalar(j));
                canvas->rotate(18.0f * (i + 4 * j));
                canvas->drawRect(rect, paint);
                canvas->drawBitmap(bm, -4.0f, -4.0f);
            }
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
DEF_SIMPLE_GM(repeated_bitmap, canvas, 576, 576)
{
    draw_rotated_image(canvas, GetResourceAsImage("randPixels.png").get());
}

DEF_SIMPLE_GM(repeated_bitmap_jpg, canvas, 576, 576)
{
    draw_rotated_image(canvas, GetResourceAsImage("color_wheel.jpg").get());
=======
DEF_SIMPLE_GM(repeated_bitmap_jpg, canvas, 576, 576) {
    sk_tool_utils::draw_checkerboard(canvas, 0xFF999999, SK_ColorWHITE, 12);
    SkRect rect = SkRect::MakeLTRB(-68.0f, -68.0f, 68.0f, 68.0f);
    SkPaint paint;
    paint.setColor(0xFF333333);
    SkBitmap bm;
    if (GetResourceAsBitmap("color_wheel.jpg", &bm)) {
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                SkAutoCanvasRestore autoCanvasRestore(canvas, true);
                canvas->translate(96.0f + 192.0f * SkIntToScalar(i),
                                  96.0f + 192.0f * SkIntToScalar(j));
                canvas->rotate(18.0f * (i + 4 * j));
                canvas->drawRect(rect, paint);
                canvas->drawBitmap(bm, -64.0f, -64.0f);
            }
        }
    }
>>>>>>> miniblink49
}

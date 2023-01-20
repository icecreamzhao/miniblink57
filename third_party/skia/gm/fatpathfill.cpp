/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkPath.h"
#include "SkSurface.h"
#include "gm.h"

#define ZOOM 32
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkPath.h"
#include "SkSurface.h"

#define ZOOM    32
>>>>>>> miniblink49
#define SMALL_W 9
#define SMALL_H 3
#define REPEAT_LOOP 5

<<<<<<< HEAD
static sk_sp<SkSurface> new_surface(int width, int height)
{
    return SkSurface::MakeRasterN32Premul(width, height);
}

static void draw_pixel_centers(SkCanvas* canvas)
{
    SkPaint paint;
    paint.setColor(sk_tool_utils::color_to_565(0xFF0088FF));
=======
static SkSurface* new_surface(int width, int height) {
    return SkSurface::NewRasterN32Premul(width, height);
}

static void draw_pixel_centers(SkCanvas* canvas) {
    SkPaint paint;
    paint.setColor(0xFF0088FF);
>>>>>>> miniblink49
    paint.setAntiAlias(true);

    for (int y = 0; y < SMALL_H; ++y) {
        for (int x = 0; x < SMALL_W; ++x) {
            canvas->drawCircle(x + 0.5f, y + 0.5f, 1.5f / ZOOM, paint);
        }
    }
}

<<<<<<< HEAD
static void draw_fatpath(SkCanvas* canvas, SkSurface* surface, const SkPath& path)
{
=======
static void draw_fatpath(SkCanvas* canvas, SkSurface* surface, const SkPath& path) {
>>>>>>> miniblink49
    SkPaint paint;

    surface->getCanvas()->clear(SK_ColorTRANSPARENT);
    surface->getCanvas()->drawPath(path, paint);
<<<<<<< HEAD
    surface->draw(canvas, 0, 0, nullptr);
=======
    surface->draw(canvas, 0, 0, NULL);
>>>>>>> miniblink49

    paint.setAntiAlias(true);
    paint.setColor(SK_ColorRED);
    paint.setStyle(SkPaint::kStroke_Style);
    canvas->drawPath(path, paint);

    draw_pixel_centers(canvas);
}

<<<<<<< HEAD
DEF_SIMPLE_GM(fatpathfill, canvas,
    SMALL_W* ZOOM,
    SMALL_H* ZOOM* REPEAT_LOOP)
{
    auto surface(new_surface(SMALL_W, SMALL_H));

    canvas->scale(ZOOM, ZOOM);

    SkPaint paint;
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(SK_Scalar1);

    for (int i = 0; i < REPEAT_LOOP; ++i) {
        SkPath line, path;
        line.moveTo(1, 2);
        line.lineTo(SkIntToScalar(4 + i), 1);
        paint.getFillPath(line, &path);
        draw_fatpath(canvas, surface.get(), path);

        canvas->translate(0, SMALL_H);
    }
}
=======
class FatPathFillGM : public skiagm::GM {
public:
    FatPathFillGM() {}

protected:

    SkString onShortName() override {
        return SkString("fatpathfill");
    }

    SkISize onISize() override {
        return SkISize::Make(SMALL_W * ZOOM, SMALL_H * ZOOM * REPEAT_LOOP);
    }

    void onDraw(SkCanvas* canvas) override {
        SkAutoTUnref<SkSurface> surface(new_surface(SMALL_W, SMALL_H));

        canvas->scale(ZOOM, ZOOM);

        SkPaint paint;
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(SK_Scalar1);

        for (int i = 0; i < REPEAT_LOOP; ++i) {
            SkPath line, path;
            line.moveTo(1, 2);
            line.lineTo(SkIntToScalar(4 + i), 1);
            paint.getFillPath(line, &path);
            draw_fatpath(canvas, surface, path);

            canvas->translate(0, SMALL_H);
        }
    }

private:
    typedef skiagm::GM INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

DEF_GM(return new FatPathFillGM;)
>>>>>>> miniblink49

/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlurImageFilter.h"
#include "SkRandom.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkBlurImageFilter.h"
#include "SkRandom.h"
>>>>>>> miniblink49

#define WIDTH 640
#define HEIGHT 480

namespace skiagm {

class ImageBlurTiledGM : public GM {
public:
    ImageBlurTiledGM(SkScalar sigmaX, SkScalar sigmaY)
<<<<<<< HEAD
        : fSigmaX(sigmaX)
        , fSigmaY(sigmaY)
    {
    }

protected:
    SkString onShortName() override
    {
        return SkString("imageblurtiled");
    }

    SkISize onISize() override
    {
        return SkISize::Make(WIDTH, HEIGHT);
    }

    void onDraw(SkCanvas* canvas) override
    {
        SkPaint paint;
        paint.setImageFilter(SkBlurImageFilter::Make(fSigmaX, fSigmaY, nullptr));
        const SkScalar tileSize = SkIntToScalar(128);
=======
        : fSigmaX(sigmaX), fSigmaY(sigmaY) {
    }

protected:
    virtual SkString onShortName() {
        return SkString("imageblurtiled");
    }

    virtual SkISize onISize() {
        return SkISize::Make(WIDTH, HEIGHT);
    }

    virtual void onDraw(SkCanvas* canvas) {
        SkPaint paint;
        paint.setImageFilter(SkBlurImageFilter::Create(fSigmaX, fSigmaY))->unref();
        const SkScalar tile_size = SkIntToScalar(128);
>>>>>>> miniblink49
        SkRect bounds;
        if (!canvas->getClipBounds(&bounds)) {
            bounds.setEmpty();
        }
<<<<<<< HEAD
        for (SkScalar y = bounds.top(); y < bounds.bottom(); y += tileSize) {
            for (SkScalar x = bounds.left(); x < bounds.right(); x += tileSize) {
                canvas->save();
                canvas->clipRect(SkRect::MakeXYWH(x, y, tileSize, tileSize));
                canvas->saveLayer(nullptr, &paint);
=======
        for (SkScalar y = bounds.top(); y < bounds.bottom(); y += tile_size) {
            for (SkScalar x = bounds.left(); x < bounds.right(); x += tile_size) {
                canvas->save();
                canvas->clipRect(SkRect::MakeXYWH(x, y, tile_size, tile_size));
                canvas->saveLayer(NULL, &paint);
>>>>>>> miniblink49
                const char* str[] = {
                    "The quick",
                    "brown fox",
                    "jumped over",
                    "the lazy dog.",
                };
                SkPaint textPaint;
                textPaint.setAntiAlias(true);
                sk_tool_utils::set_portable_typeface(&textPaint);
                textPaint.setTextSize(SkIntToScalar(100));
                int posY = 0;
                for (unsigned i = 0; i < SK_ARRAY_COUNT(str); i++) {
                    posY += 100;
                    canvas->drawText(str[i], strlen(str[i]), SkIntToScalar(0),
<<<<<<< HEAD
                        SkIntToScalar(posY), textPaint);
=======
                                     SkIntToScalar(posY), textPaint);
>>>>>>> miniblink49
                }
                canvas->restore();
                canvas->restore();
            }
        }
    }

private:
    SkScalar fSigmaX;
    SkScalar fSigmaY;

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ImageBlurTiledGM(3.0f, 3.0f);)
=======
static GM* MyFactory1(void*) { return new ImageBlurTiledGM(3.0f, 3.0f); }
static GMRegistry reg1(MyFactory1);
>>>>>>> miniblink49

}

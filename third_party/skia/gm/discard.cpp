/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkSurface.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkColorShader.h"
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkSurface.h"
>>>>>>> miniblink49

#if SK_SUPPORT_GPU

namespace skiagm {

/*
 * This GM exercises SkCanvas::discard() by creating an offscreen SkSurface and repeatedly
 * discarding it, drawing to it, and then drawing it to the main canvas.
 */
class DiscardGM : public GM {

public:
<<<<<<< HEAD
    DiscardGM()
    {
    }

protected:
    SkString onShortName() override
    {
        return SkString("discard");
    }

    SkISize onISize() override
    {
        return SkISize::Make(100, 100);
    }

    void onDraw(SkCanvas* canvas) override
    {
        GrContext* context = canvas->getGrContext();
        if (nullptr == context) {
=======
    DiscardGM() {
    }

protected:
    SkString onShortName() override {
        return SkString("discard");
    }

    SkISize onISize() override {
        return SkISize::Make(100, 100);
    }

    void onDraw(SkCanvas* canvas) override {
        GrContext* context = canvas->getGrContext();
        if (NULL == context) {
>>>>>>> miniblink49
            return;
        }

        SkISize size = this->getISize();
        size.fWidth /= 10;
        size.fHeight /= 10;
        SkImageInfo info = SkImageInfo::MakeN32Premul(size);
<<<<<<< HEAD
        auto surface = SkSurface::MakeRenderTarget(context, SkBudgeted::kNo, info);
        if (nullptr == surface) {
=======
        SkSurface* surface = SkSurface::NewRenderTarget(context, SkSurface::kNo_Budgeted, info);

        if (NULL == surface) {
>>>>>>> miniblink49
            return;
        }

        canvas->clear(SK_ColorBLACK);

        SkRandom rand;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
<<<<<<< HEAD
                surface->getCanvas()->discard();
                // Make something that isn't too close to the background color, black.
                SkColor color = sk_tool_utils::color_to_565(rand.nextU() | 0xFF404040);
                switch (rand.nextULessThan(3)) {
                case 0:
                    surface->getCanvas()->drawColor(color);
                    break;
                case 1:
                    surface->getCanvas()->clear(color);
                    break;
                case 2:
                    SkPaint paint;
                    paint.setShader(SkShader::MakeColorShader(color));
                    surface->getCanvas()->drawPaint(paint);
                    break;
                }
                surface->draw(canvas, 10.f * x, 10.f * y, nullptr);
=======
              surface->getCanvas()->discard();
              // Make something that isn't too close to the background color, black.
              SkColor color = rand.nextU() | 0xFF404040;
              switch (rand.nextULessThan(3)) {
                  case 0:
                      surface->getCanvas()->drawColor(color);
                      break;
                  case 1:
                      surface->getCanvas()->clear(color);
                      break;
                  case 2:
                      SkColorShader shader(color);
                      SkPaint paint;
                      paint.setShader(&shader);
                      surface->getCanvas()->drawPaint(paint);
                      break;
              }
              surface->draw(canvas, 10.f*x, 10.f*y, NULL);
>>>>>>> miniblink49
            }
        }

        surface->getCanvas()->discard();
<<<<<<< HEAD
=======
        surface->unref();
>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new DiscardGM;)
=======
DEF_GM( return SkNEW(DiscardGM); )
>>>>>>> miniblink49

} // end namespace

#endif

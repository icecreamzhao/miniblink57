<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkBitmap.h"
#include "SkColorPriv.h"
#include "SkShader.h"
#include "SkXfermode.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkBitmap.h"
#include "SkShader.h"
#include "SkXfermode.h"
#include "SkColorPriv.h"
>>>>>>> miniblink49

namespace skiagm {

class Xfermodes2GM : public GM {
public:
<<<<<<< HEAD
    Xfermodes2GM() { }

protected:
    SkString onShortName() override
    {
        return SkString("xfermodes2");
    }

    SkISize onISize() override
    {
        return SkISize::Make(455, 475);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    Xfermodes2GM() {}

protected:
    SkString onShortName() override {
        return SkString("xfermodes2");
    }

    SkISize onISize() override {
        return SkISize::Make(455, 475);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->translate(SkIntToScalar(10), SkIntToScalar(20));

        const SkScalar w = SkIntToScalar(kSize);
        const SkScalar h = SkIntToScalar(kSize);

        SkPaint labelP;
        labelP.setAntiAlias(true);
        sk_tool_utils::set_portable_typeface(&labelP);
        labelP.setTextAlign(SkPaint::kCenter_Align);

        const int W = 6;

        SkScalar x = 0, y = 0;
        for (size_t m = 0; m <= SkXfermode::kLastMode; m++) {
            SkXfermode::Mode mode = static_cast<SkXfermode::Mode>(m);
<<<<<<< HEAD
=======
            SkXfermode* xm = SkXfermode::Create(mode);
            SkAutoUnref aur(xm);
>>>>>>> miniblink49

            canvas->save();

            canvas->translate(x, y);
            SkPaint p;
            p.setAntiAlias(false);
            p.setStyle(SkPaint::kFill_Style);
            p.setShader(fBG);
            SkRect r = SkRect::MakeWH(w, h);
            canvas->drawRect(r, p);

<<<<<<< HEAD
            canvas->saveLayer(&r, nullptr);
=======
            canvas->saveLayer(&r, NULL);
>>>>>>> miniblink49

            p.setShader(fDst);
            canvas->drawRect(r, p);
            p.setShader(fSrc);
<<<<<<< HEAD
            p.setXfermode(SkXfermode::Make(mode));
=======
            p.setXfermode(xm);
>>>>>>> miniblink49
            canvas->drawRect(r, p);

            canvas->restore();

            r.inset(-SK_ScalarHalf, -SK_ScalarHalf);
            p.setStyle(SkPaint::kStroke_Style);
<<<<<<< HEAD
            p.setShader(nullptr);
            p.setXfermode(nullptr);
=======
            p.setShader(NULL);
            p.setXfermode(NULL);
>>>>>>> miniblink49
            canvas->drawRect(r, p);

            canvas->restore();

#if 1
            canvas->drawText(SkXfermode::ModeName(mode), strlen(SkXfermode::ModeName(mode)),
<<<<<<< HEAD
                x + w / 2, y - labelP.getTextSize() / 2, labelP);
=======
                             x + w/2, y - labelP.getTextSize()/2, labelP);
>>>>>>> miniblink49
#endif
            x += w + SkIntToScalar(10);
            if ((m % W) == W - 1) {
                x = 0;
                y += h + SkIntToScalar(30);
            }
        }
    }

private:
<<<<<<< HEAD
    void onOnceBeforeDraw() override
    {
        static const uint32_t kCheckData[] = {
            SkPackARGB32(0xFF, 0x42, 0x41, 0x42),
            SkPackARGB32(0xFF, 0xD6, 0xD3, 0xD6),
            SkPackARGB32(0xFF, 0xD6, 0xD3, 0xD6),
            SkPackARGB32(0xFF, 0x42, 0x41, 0x42)
=======
    void onOnceBeforeDraw() override {
        static const uint32_t kCheckData[] = {
            SkPackARGB32(0xFF, 0x40, 0x40, 0x40),
            SkPackARGB32(0xFF, 0xD0, 0xD0, 0xD0),
            SkPackARGB32(0xFF, 0xD0, 0xD0, 0xD0),
            SkPackARGB32(0xFF, 0x40, 0x40, 0x40)
>>>>>>> miniblink49
        };
        SkBitmap bg;
        bg.allocN32Pixels(2, 2, true);
        memcpy(bg.getPixels(), kCheckData, sizeof(kCheckData));

        SkMatrix lm;
        lm.setScale(SkIntToScalar(16), SkIntToScalar(16));
<<<<<<< HEAD
        fBG = SkShader::MakeBitmapShader(bg, SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode,
            &lm);
=======
        fBG.reset(SkShader::CreateBitmapShader(bg,
                                               SkShader::kRepeat_TileMode,
                                               SkShader::kRepeat_TileMode,
                                               &lm));
>>>>>>> miniblink49

        SkBitmap srcBmp;
        srcBmp.allocN32Pixels(kSize, kSize);
        SkPMColor* pixels = reinterpret_cast<SkPMColor*>(srcBmp.getPixels());

        for (int y = 0; y < kSize; ++y) {
            int c = y * (1 << kShift);
<<<<<<< HEAD
            SkPMColor rowColor = SkPackARGB32(c, c, 0, c / 2);
=======
            SkPMColor rowColor = SkPackARGB32(c, c, 0, c/2);
>>>>>>> miniblink49
            for (int x = 0; x < kSize; ++x) {
                pixels[kSize * y + x] = rowColor;
            }
        }
<<<<<<< HEAD
        fSrc = SkShader::MakeBitmapShader(srcBmp, SkShader::kClamp_TileMode,
            SkShader::kClamp_TileMode);
=======
        fSrc.reset(SkShader::CreateBitmapShader(srcBmp,
                                                SkShader::kClamp_TileMode,
                                                SkShader::kClamp_TileMode));
>>>>>>> miniblink49
        SkBitmap dstBmp;
        dstBmp.allocN32Pixels(kSize, kSize);
        pixels = reinterpret_cast<SkPMColor*>(dstBmp.getPixels());

        for (int x = 0; x < kSize; ++x) {
            int c = x * (1 << kShift);
<<<<<<< HEAD
            SkPMColor colColor = SkPackARGB32(c, 0, c, c / 2);
=======
            SkPMColor colColor = SkPackARGB32(c, 0, c, c/2);
>>>>>>> miniblink49
            for (int y = 0; y < kSize; ++y) {
                pixels[kSize * y + x] = colColor;
            }
        }
<<<<<<< HEAD
        fDst = SkShader::MakeBitmapShader(dstBmp, SkShader::kClamp_TileMode,
            SkShader::kClamp_TileMode);
=======
        fDst.reset(SkShader::CreateBitmapShader(dstBmp,
                                                SkShader::kClamp_TileMode,
                                                SkShader::kClamp_TileMode));
>>>>>>> miniblink49
    }

    enum {
        kShift = 2,
        kSize = 256 >> kShift,
    };

<<<<<<< HEAD
    sk_sp<SkShader> fBG;
    sk_sp<SkShader> fSrc;
    sk_sp<SkShader> fDst;
=======
    SkAutoTUnref<SkShader> fBG;
    SkAutoTUnref<SkShader> fSrc;
    SkAutoTUnref<SkShader> fDst;
>>>>>>> miniblink49

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new Xfermodes2GM; }
static GMRegistry reg(MyFactory);

}

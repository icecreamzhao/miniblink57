/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "../src/fonts/SkGScalerContext.h"
=======
#include "gm.h"
>>>>>>> miniblink49
#include "SkBitmap.h"
#include "SkGradientShader.h"
#include "SkShader.h"
#include "SkXfermode.h"
<<<<<<< HEAD
#include "gm.h"
=======
#include "../src/fonts/SkGScalerContext.h"
>>>>>>> miniblink49

namespace skiagm {

static uint16_t gData[] = { 0xFFFF, 0xCCCF, 0xCCCF, 0xFFFF };

class ColorTypeXfermodeGM : public GM {
public:
    const static int W = 64;
    const static int H = 64;
<<<<<<< HEAD
    ColorTypeXfermodeGM() { }

protected:
    void onOnceBeforeDraw() override
    {
=======
    ColorTypeXfermodeGM()
        : fColorType(NULL) {
    }

    virtual ~ColorTypeXfermodeGM() {
        SkSafeUnref(fColorType);
    }

protected:
    void onOnceBeforeDraw() override {
>>>>>>> miniblink49
        const SkColor colors[] = {
            SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE,
            SK_ColorMAGENTA, SK_ColorCYAN, SK_ColorYELLOW
        };
        SkMatrix local;
        local.setRotate(180);
<<<<<<< HEAD
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setShader(SkGradientShader::MakeSweep(0, 0, colors, nullptr, SK_ARRAY_COUNT(colors),
            0, &local));

        sk_sp<SkTypeface> orig(sk_tool_utils::create_portable_typeface("serif",
            SkFontStyle::FromOldStyle(SkTypeface::kBold)));
        if (nullptr == orig) {
            orig = SkTypeface::MakeDefault();
        }
        fColorType = sk_make_sp<SkGTypeface>(orig, paint);

        fBG.installPixels(SkImageInfo::Make(2, 2, kARGB_4444_SkColorType,
                              kOpaque_SkAlphaType),
            gData, 4);
    }

    virtual SkString onShortName() override
    {
        return SkString("colortype_xfermodes");
    }

    virtual SkISize onISize() override
    {
        return SkISize::Make(400, 640);
    }

    virtual void onDraw(SkCanvas* canvas) override
    {
        canvas->translate(SkIntToScalar(10), SkIntToScalar(20));

        const struct {
            SkXfermode::Mode fMode;
            const char* fLabel;
        } gModes[] = {
            { SkXfermode::kClear_Mode, "Clear" },
            { SkXfermode::kSrc_Mode, "Src" },
            { SkXfermode::kDst_Mode, "Dst" },
            { SkXfermode::kSrcOver_Mode, "SrcOver" },
            { SkXfermode::kDstOver_Mode, "DstOver" },
            { SkXfermode::kSrcIn_Mode, "SrcIn" },
            { SkXfermode::kDstIn_Mode, "DstIn" },
            { SkXfermode::kSrcOut_Mode, "SrcOut" },
            { SkXfermode::kDstOut_Mode, "DstOut" },
            { SkXfermode::kSrcATop_Mode, "SrcATop" },
            { SkXfermode::kDstATop_Mode, "DstATop" },

            { SkXfermode::kXor_Mode, "Xor" },
            { SkXfermode::kPlus_Mode, "Plus" },
            { SkXfermode::kModulate_Mode, "Modulate" },
            { SkXfermode::kScreen_Mode, "Screen" },
            { SkXfermode::kOverlay_Mode, "Overlay" },
            { SkXfermode::kDarken_Mode, "Darken" },
            { SkXfermode::kLighten_Mode, "Lighten" },
            { SkXfermode::kColorDodge_Mode, "ColorDodge" },
            { SkXfermode::kColorBurn_Mode, "ColorBurn" },
            { SkXfermode::kHardLight_Mode, "HardLight" },
            { SkXfermode::kSoftLight_Mode, "SoftLight" },
            { SkXfermode::kDifference_Mode, "Difference" },
            { SkXfermode::kExclusion_Mode, "Exclusion" },
            { SkXfermode::kMultiply_Mode, "Multiply" },
            { SkXfermode::kHue_Mode, "Hue" },
            { SkXfermode::kSaturation_Mode, "Saturation" },
            { SkXfermode::kColor_Mode, "Color" },
            { SkXfermode::kLuminosity_Mode, "Luminosity" },
=======
        SkShader* s = SkGradientShader::CreateSweep(0,0, colors, NULL,
                                                    SK_ARRAY_COUNT(colors), 0, &local);

        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setShader(s)->unref();

        SkTypeface* orig = sk_tool_utils::create_portable_typeface("Times",
                                                            SkTypeface::kBold);
        if (NULL == orig) {
            orig = SkTypeface::RefDefault();
        }
        fColorType = SkNEW_ARGS(SkGTypeface, (orig, paint));
        orig->unref();

        fBG.installPixels(SkImageInfo::Make(2, 2, kARGB_4444_SkColorType,
                                            kOpaque_SkAlphaType), gData, 4);
    }

    virtual SkString onShortName() override {
        return SkString("colortype_xfermodes");
    }

    virtual SkISize onISize() override {
        return SkISize::Make(400, 640);
    }

    virtual void onDraw(SkCanvas* canvas) override {
        canvas->translate(SkIntToScalar(10), SkIntToScalar(20));

        const struct {
            SkXfermode::Mode  fMode;
            const char*       fLabel;
        } gModes[] = {
            { SkXfermode::kClear_Mode,        "Clear"       },
            { SkXfermode::kSrc_Mode,          "Src"         },
            { SkXfermode::kDst_Mode,          "Dst"         },
            { SkXfermode::kSrcOver_Mode,      "SrcOver"     },
            { SkXfermode::kDstOver_Mode,      "DstOver"     },
            { SkXfermode::kSrcIn_Mode,        "SrcIn"       },
            { SkXfermode::kDstIn_Mode,        "DstIn"       },
            { SkXfermode::kSrcOut_Mode,       "SrcOut"      },
            { SkXfermode::kDstOut_Mode,       "DstOut"      },
            { SkXfermode::kSrcATop_Mode,      "SrcATop"     },
            { SkXfermode::kDstATop_Mode,      "DstATop"     },

            { SkXfermode::kXor_Mode,          "Xor"         },
            { SkXfermode::kPlus_Mode,         "Plus"        },
            { SkXfermode::kModulate_Mode,     "Modulate"    },
            { SkXfermode::kScreen_Mode,       "Screen"      },
            { SkXfermode::kOverlay_Mode,      "Overlay"     },
            { SkXfermode::kDarken_Mode,       "Darken"      },
            { SkXfermode::kLighten_Mode,      "Lighten"     },
            { SkXfermode::kColorDodge_Mode,   "ColorDodge"  },
            { SkXfermode::kColorBurn_Mode,    "ColorBurn"   },
            { SkXfermode::kHardLight_Mode,    "HardLight"   },
            { SkXfermode::kSoftLight_Mode,    "SoftLight"   },
            { SkXfermode::kDifference_Mode,   "Difference"  },
            { SkXfermode::kExclusion_Mode,    "Exclusion"   },
            { SkXfermode::kMultiply_Mode,     "Multiply"    },
            { SkXfermode::kHue_Mode,          "Hue"         },
            { SkXfermode::kSaturation_Mode,   "Saturation"  },
            { SkXfermode::kColor_Mode,        "Color"       },
            { SkXfermode::kLuminosity_Mode,   "Luminosity"  },
>>>>>>> miniblink49
        };

        const SkScalar w = SkIntToScalar(W);
        const SkScalar h = SkIntToScalar(H);
        SkMatrix m;
        m.setScale(SkIntToScalar(6), SkIntToScalar(6));
<<<<<<< HEAD
        auto s = SkShader::MakeBitmapShader(fBG, SkShader::kRepeat_TileMode,
            SkShader::kRepeat_TileMode, &m);
=======
        SkShader* s = SkShader::CreateBitmapShader(fBG,
                                                   SkShader::kRepeat_TileMode,
                                                   SkShader::kRepeat_TileMode,
                                                   &m);
>>>>>>> miniblink49

        SkPaint labelP;
        labelP.setAntiAlias(true);
        sk_tool_utils::set_portable_typeface(&labelP);
        labelP.setTextAlign(SkPaint::kCenter_Align);

        SkPaint textP;
        textP.setAntiAlias(true);
        textP.setTypeface(fColorType);
        textP.setTextSize(SkIntToScalar(70));

        const int W = 5;

        SkScalar x0 = 0;
        SkScalar y0 = 0;
        SkScalar x = x0, y = y0;
        for (size_t i = 0; i < SK_ARRAY_COUNT(gModes); i++) {
<<<<<<< HEAD
            SkRect r;
            r.set(x, y, x + w, y + h);
=======
            SkXfermode* mode = SkXfermode::Create(gModes[i].fMode);
            SkAutoUnref aur(mode);
            SkRect r;
            r.set(x, y, x+w, y+h);
>>>>>>> miniblink49

            SkPaint p;
            p.setStyle(SkPaint::kFill_Style);
            p.setShader(s);
            canvas->drawRect(r, p);

            r.inset(-SK_ScalarHalf, -SK_ScalarHalf);
            p.setStyle(SkPaint::kStroke_Style);
<<<<<<< HEAD
            p.setShader(nullptr);
            canvas->drawRect(r, p);

            textP.setXfermode(SkXfermode::Make(gModes[i].fMode));
            canvas->drawText("H", 1, x + w / 10.f, y + 7.f * h / 8.f, textP);
#if 1
            canvas->drawText(gModes[i].fLabel, strlen(gModes[i].fLabel),
                x + w / 2, y - labelP.getTextSize() / 2, labelP);
=======
            p.setShader(NULL);
            canvas->drawRect(r, p);

            textP.setXfermode(mode);
            canvas->drawText("H", 1, x+ w/10.f, y + 7.f*h/8.f, textP);
#if 1
            canvas->drawText(gModes[i].fLabel, strlen(gModes[i].fLabel),
                             x + w/2, y - labelP.getTextSize()/2, labelP);
>>>>>>> miniblink49
#endif
            x += w + SkIntToScalar(10);
            if ((i % W) == W - 1) {
                x = x0;
                y += h + SkIntToScalar(30);
            }
        }
<<<<<<< HEAD
    }

private:
    SkBitmap fBG;
    sk_sp<SkTypeface> fColorType;
=======
        s->unref();
    }

private:
    SkBitmap    fBG;
    SkTypeface* fColorType;
>>>>>>> miniblink49

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new ColorTypeXfermodeGM; }
static GMRegistry reg(MyFactory);

}

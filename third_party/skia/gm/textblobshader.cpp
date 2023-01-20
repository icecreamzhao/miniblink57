/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gm.h"

#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkPoint.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "SkTDArray.h"
#include "SkTextBlob.h"
=======
#include "SkTextBlob.h"
#include "SkTDArray.h"
>>>>>>> miniblink49
#include "SkTypeface.h"

// This GM exercises drawTextBlob offset vs. shader space behavior.
class TextBlobShaderGM : public skiagm::GM {
public:
<<<<<<< HEAD
    TextBlobShaderGM(const char* txt)
    {
        SkPaint p;
        sk_tool_utils::set_portable_typeface(&p);
        size_t txtLen = strlen(txt);
        fGlyphs.append(p.textToGlyphs(txt, txtLen, nullptr));
=======
    TextBlobShaderGM(const char* txt) {
        SkPaint p;
        size_t txtLen = strlen(txt);
        fGlyphs.append(p.textToGlyphs(txt, txtLen, NULL));
>>>>>>> miniblink49
        p.textToGlyphs(txt, txtLen, fGlyphs.begin());
    }

protected:
<<<<<<< HEAD
    void onOnceBeforeDraw() override
    {
=======

    void onOnceBeforeDraw() override {
>>>>>>> miniblink49
        SkPaint p;
        p.setAntiAlias(true);
        p.setSubpixelText(true);
        p.setTextSize(30);
        p.setTextEncoding(SkPaint::kGlyphID_TextEncoding);
<<<<<<< HEAD
        sk_tool_utils::set_portable_typeface(&p);
=======
>>>>>>> miniblink49

        SkTextBlobBuilder builder;
        int glyphCount = fGlyphs.count();
        const SkTextBlobBuilder::RunBuffer* run;

<<<<<<< HEAD
        run = &builder.allocRun(p, glyphCount, 10, 10, nullptr);
        memcpy(run->glyphs, fGlyphs.begin(), glyphCount * sizeof(uint16_t));

        run = &builder.allocRunPosH(p, glyphCount, 80, nullptr);
=======
        run = &builder.allocRun(p, glyphCount, 10, 10, NULL);
        memcpy(run->glyphs, fGlyphs.begin(), glyphCount * sizeof(uint16_t));

        run = &builder.allocRunPosH(p, glyphCount,  80, NULL);
>>>>>>> miniblink49
        memcpy(run->glyphs, fGlyphs.begin(), glyphCount * sizeof(uint16_t));
        for (int i = 0; i < glyphCount; ++i) {
            run->pos[i] = p.getTextSize() * i * .75f;
        }

<<<<<<< HEAD
        run = &builder.allocRunPos(p, glyphCount, nullptr);
=======
        run = &builder.allocRunPos(p, glyphCount, NULL);
>>>>>>> miniblink49
        memcpy(run->glyphs, fGlyphs.begin(), glyphCount * sizeof(uint16_t));
        for (int i = 0; i < glyphCount; ++i) {
            run->pos[i * 2] = p.getTextSize() * i * .75f;
            run->pos[i * 2 + 1] = 150 + 5 * sinf((float)i * 8 / glyphCount);
        }

        fBlob.reset(builder.build());

<<<<<<< HEAD
        SkColor colors[2];
=======
        SkColor  colors[2];
>>>>>>> miniblink49
        colors[0] = SK_ColorRED;
        colors[1] = SK_ColorGREEN;

        SkScalar pos[SK_ARRAY_COUNT(colors)];
        for (unsigned i = 0; i < SK_ARRAY_COUNT(pos); ++i) {
            pos[i] = (float)i / (SK_ARRAY_COUNT(pos) - 1);
        }

        SkISize sz = this->onISize();
<<<<<<< HEAD
        fShader = SkGradientShader::MakeRadial(SkPoint::Make(SkIntToScalar(sz.width() / 2),
                                                   SkIntToScalar(sz.height() / 2)),
            sz.width() * .66f, colors, pos,
            SK_ARRAY_COUNT(colors),
            SkShader::kRepeat_TileMode);
    }

    SkString onShortName() override
    {
        return SkString("textblobshader");
    }

    SkISize onISize() override
    {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
        fShader.reset(SkGradientShader::CreateRadial(SkPoint::Make(SkIntToScalar(sz.width() / 2),
                                                                   SkIntToScalar(sz.height() / 2)),
                                                     sz.width() * .66f, colors, pos,
                                                     SK_ARRAY_COUNT(colors),
                                                     SkShader::kRepeat_TileMode));
    }

    SkString onShortName() override {
        return SkString("textblobshader");
    }

    SkISize onISize() override {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint p;
        p.setStyle(SkPaint::kFill_Style);
        p.setShader(fShader);

        SkISize sz = this->onISize();
        static const int kXCount = 4;
        static const int kYCount = 3;
        for (int i = 0; i < kXCount; ++i) {
            for (int j = 0; j < kYCount; ++j) {
                canvas->drawTextBlob(fBlob,
<<<<<<< HEAD
                    SkIntToScalar(i * sz.width() / kXCount),
                    SkIntToScalar(j * sz.height() / kYCount),
                    p);
=======
                                     SkIntToScalar(i * sz.width() / kXCount),
                                     SkIntToScalar(j * sz.height() / kYCount),
                                     p);
>>>>>>> miniblink49
            }
        }
    }

private:
<<<<<<< HEAD
    SkTDArray<uint16_t> fGlyphs;
    SkAutoTUnref<const SkTextBlob> fBlob;
    sk_sp<SkShader> fShader;
=======
    SkTDArray<uint16_t>            fGlyphs;
    SkAutoTUnref<const SkTextBlob> fBlob;
    SkAutoTUnref<SkShader>         fShader;
>>>>>>> miniblink49

    typedef skiagm::GM INHERITED;
};

<<<<<<< HEAD
DEF_GM(return new TextBlobShaderGM("Blobber");)
=======
DEF_GM( return SkNEW_ARGS(TextBlobShaderGM, ("Blobber")); )
>>>>>>> miniblink49

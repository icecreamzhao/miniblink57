/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "DecodeFile.h"
#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkTime.h"
#include "SkUtils.h"
#include "SkView.h"
#include "SkXfermode.h"
=======
#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkXfermode.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
>>>>>>> miniblink49

static const char* gNames[] = {
    "/skimages/background_01.png"
};

class Filter2View : public SampleView {
public:
<<<<<<< HEAD
    SkBitmap* fBitmaps;
    int fBitmapCount;
    int fCurrIndex;

    Filter2View()
    {
        fBitmapCount = SK_ARRAY_COUNT(gNames) * 2;
        fBitmaps = new SkBitmap[fBitmapCount];

        for (int i = 0; i < fBitmapCount / 2; i++) {
            decode_file(gNames[i], &fBitmaps[i]);
        }
        for (int i = fBitmapCount / 2; i < fBitmapCount; i++) {
            decode_file(gNames[i - fBitmapCount / 2], &fBitmaps[i], kRGB_565_SkColorType);
=======
    SkBitmap*   fBitmaps;
    int         fBitmapCount;
    int         fCurrIndex;

    Filter2View() {
        fBitmapCount = SK_ARRAY_COUNT(gNames)*2;
        fBitmaps = new SkBitmap[fBitmapCount];

        for (int i = 0; i < fBitmapCount/2; i++) {
            SkImageDecoder::DecodeFile(gNames[i], &fBitmaps[i], kN32_SkColorType,
                                       SkImageDecoder::kDecodePixels_Mode, NULL);
        }
        for (int i = fBitmapCount/2; i < fBitmapCount; i++) {
            SkImageDecoder::DecodeFile(gNames[i-fBitmapCount/2], &fBitmaps[i], kRGB_565_SkColorType,
                                       SkImageDecoder::kDecodePixels_Mode, NULL);
>>>>>>> miniblink49
        }
        fCurrIndex = 0;

        this->setBGColor(SK_ColorGRAY);
    }

<<<<<<< HEAD
    virtual ~Filter2View()
    {
=======
    virtual ~Filter2View() {
>>>>>>> miniblink49
        delete[] fBitmaps;
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    virtual bool onQuery(SkEvent* evt)
    {
=======
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SkString str("Filter/Dither ");
            str.append(gNames[fCurrIndex]);
            SampleCode::TitleR(evt, str.c_str());
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        canvas->translate(SkIntToScalar(10), SkIntToScalar(50));

        const SkScalar W = SkIntToScalar(fBitmaps[0].width() + 1);
        const SkScalar H = SkIntToScalar(fBitmaps[0].height() + 1);
        SkPaint paint;

        const SkScalar scale = 0.897917f;
        canvas->scale(SK_Scalar1, scale);

        for (int k = 0; k < 2; k++) {
            paint.setFilterQuality(k == 1 ? kLow_SkFilterQuality : kNone_SkFilterQuality);
            for (int j = 0; j < 2; j++) {
                paint.setDither(j == 1);
                for (int i = 0; i < fBitmapCount; i++) {
                    SkScalar x = (k * fBitmapCount + j) * W;
                    SkScalar y = i * H;
                    x = SkScalarRoundToScalar(x);
                    y = SkScalarRoundToScalar(y);
                    canvas->drawBitmap(fBitmaps[i], x, y, &paint);
                    if (i == 0) {
                        SkPaint p;
                        p.setAntiAlias(true);
                        p.setTextAlign(SkPaint::kCenter_Align);
                        p.setTextSize(SkIntToScalar(18));
                        SkString s("dither=");
                        s.appendS32(paint.isDither());
                        s.append(" filter=");
                        s.appendS32(paint.getFilterQuality() != kNone_SkFilterQuality);
<<<<<<< HEAD
                        canvas->drawText(s.c_str(), s.size(), x + W / 2,
                            y - p.getTextSize(), p);
                    }
                    if (k + j == 2) {
=======
                        canvas->drawText(s.c_str(), s.size(), x + W/2,
                                         y - p.getTextSize(), p);
                    }
                    if (k+j == 2) {
>>>>>>> miniblink49
                        SkPaint p;
                        p.setAntiAlias(true);
                        p.setTextSize(SkIntToScalar(18));
                        SkString s;
                        s.append(" depth=");
                        s.appendS32(fBitmaps[i].colorType() == kRGB_565_SkColorType ? 16 : 32);
                        canvas->drawText(s.c_str(), s.size(), x + W + SkIntToScalar(4),
<<<<<<< HEAD
                            y + H / 2, p);
=======
                                         y + H/2, p);
>>>>>>> miniblink49
                    }
                }
            }
        }
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new Filter2View; }
static SkViewRegister reg(MyFactory);

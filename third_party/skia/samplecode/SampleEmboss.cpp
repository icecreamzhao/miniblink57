/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SampleCode.h"
#include "SkBlurMask.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkEmbossMaskFilter.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkColorShader.h"
#include "SkEmbossMaskFilter.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
>>>>>>> miniblink49
#include "SkPath.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
#include "SkXfermode.h"

class EmbossView : public SampleView {
    SkEmbossMaskFilter::Light fLight;

public:
    EmbossView()
    {
=======
#include "SkUtils.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkXfermode.h"

class EmbossView : public SampleView {
    SkEmbossMaskFilter::Light   fLight;
public:
    EmbossView() {
>>>>>>> miniblink49
        fLight.fDirection[0] = SK_Scalar1;
        fLight.fDirection[1] = SK_Scalar1;
        fLight.fDirection[2] = SK_Scalar1;
        fLight.fAmbient = 128;
<<<<<<< HEAD
        fLight.fSpecular = 16 * 2;
=======
        fLight.fSpecular = 16*2;
>>>>>>> miniblink49
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
            SampleCode::TitleR(evt, "Emboss");
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
        SkPaint paint;

        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(SkIntToScalar(10));
<<<<<<< HEAD
        paint.setMaskFilter(SkEmbossMaskFilter::Make(SkBlurMask::ConvertRadiusToSigma(4), fLight));
        paint.setShader(SkShader::MakeColorShader(SK_ColorBLUE));
        paint.setDither(true);

        canvas->drawCircle(SkIntToScalar(50), SkIntToScalar(50),
            SkIntToScalar(30), paint);
    }

private:
=======
        paint.setMaskFilter(SkEmbossMaskFilter::Create(
            SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(4)), fLight))->unref();
        paint.setShader(new SkColorShader(SK_ColorBLUE))->unref();
        paint.setDither(true);

        canvas->drawCircle(SkIntToScalar(50), SkIntToScalar(50),
                           SkIntToScalar(30), paint);
    }

private:

>>>>>>> miniblink49
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new EmbossView; }
static SkViewRegister reg(MyFactory);

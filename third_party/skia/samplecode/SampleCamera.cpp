/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "DecodeFile.h"
#include "SampleCode.h"
#include "SkAnimTimer.h"
#include "SkCamera.h"
#include "SkCanvas.h"
#include "SkEmbossMaskFilter.h"
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkView.h"

class CameraView : public SampleView {
    SkTArray<sk_sp<SkShader>> fShaders;
    int fShaderIndex;
    bool fFrontFace;

public:
    CameraView()
    {
=======
#include "SampleCode.h"
#include "SkAnimTimer.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkCamera.h"
#include "SkEmbossMaskFilter.h"
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkRandom.h"
#include "SkImageDecoder.h"

class CameraView : public SampleView {
    SkTDArray<SkShader*> fShaders;
    int     fShaderIndex;
    bool    fFrontFace;
public:
    CameraView() {
>>>>>>> miniblink49
        fRX = fRY = fRZ = 0;
        fShaderIndex = 0;
        fFrontFace = false;

        for (int i = 0;; i++) {
            SkString str;
            str.printf("/skimages/elephant%d.jpeg", i);
            SkBitmap bm;
<<<<<<< HEAD
            if (decode_file(str.c_str(), &bm)) {
=======
            if (SkImageDecoder::DecodeFile(str.c_str(), &bm)) {
>>>>>>> miniblink49
                SkRect src = { 0, 0, SkIntToScalar(bm.width()), SkIntToScalar(bm.height()) };
                SkRect dst = { -150, -150, 150, 150 };
                SkMatrix matrix;
                matrix.setRectToRect(src, dst, SkMatrix::kFill_ScaleToFit);

<<<<<<< HEAD
                fShaders.push_back(SkShader::MakeBitmapShader(bm,
                    SkShader::kClamp_TileMode,
                    SkShader::kClamp_TileMode,
                    &matrix));
=======
                SkShader* s = SkShader::CreateBitmapShader(bm,
                                                           SkShader::kClamp_TileMode,
                                                           SkShader::kClamp_TileMode,
                                                           &matrix);
                *fShaders.append() = s;
>>>>>>> miniblink49
            } else {
                break;
            }
        }
        this->setBGColor(0xFFDDDDDD);
    }

<<<<<<< HEAD
protected:
    // overrides from SkEventSink
    bool onQuery(SkEvent* evt) override
    {
=======
    virtual ~CameraView() {
        fShaders.unrefAll();
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Camera");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
        canvas->translate(this->width() / 2, this->height() / 2);

        Sk3DView view;
=======
    virtual void onDrawContent(SkCanvas* canvas) {
        canvas->translate(this->width()/2, this->height()/2);

        Sk3DView    view;
>>>>>>> miniblink49
        view.rotateX(fRX);
        view.rotateY(fRY);
        view.applyToCanvas(canvas);

        SkPaint paint;
        if (fShaders.count() > 0) {
            bool frontFace = view.dotWithNormal(0, 0, SK_Scalar1) < 0;
            if (frontFace != fFrontFace) {
                fFrontFace = frontFace;
                fShaderIndex = (fShaderIndex + 1) % fShaders.count();
            }

            paint.setAntiAlias(true);
            paint.setShader(fShaders[fShaderIndex]);
            paint.setFilterQuality(kLow_SkFilterQuality);
            SkRect r = { -150, -150, 150, 150 };
            canvas->drawRoundRect(r, 30, 30, paint);
        }
    }

<<<<<<< HEAD
    bool onAnimate(const SkAnimTimer& timer) override
    {
=======
    bool onAnimate(const SkAnimTimer& timer) override {
>>>>>>> miniblink49
        if (timer.isStopped()) {
            fRY = 0;
        } else {
            fRY = timer.scaled(90, 360);
        }
        return true;
    }

private:
    SkScalar fRX, fRY, fRZ;
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new CameraView; }
static SkViewRegister reg(MyFactory);

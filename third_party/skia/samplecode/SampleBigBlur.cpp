<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SampleCode.h"
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
#include "SkView.h"

class BigBlurView : public SampleView {
public:
<<<<<<< HEAD
    BigBlurView()
    {
=======
    BigBlurView() {
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
            SampleCode::TitleR(evt, "BigBlur");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
        SkPaint paint;
        canvas->save();
        paint.setColor(SK_ColorBLUE);
        paint.setMaskFilter(SkBlurMaskFilter::Make(
            kNormal_SkBlurStyle,
            SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(128)),
            SkBlurMaskFilter::kHighQuality_BlurFlag));
=======
    virtual void onDrawContent(SkCanvas* canvas) {
        SkPaint paint;
        canvas->save();
        paint.setColor(SK_ColorBLUE);
        SkMaskFilter* mf = SkBlurMaskFilter::Create(
            kNormal_SkBlurStyle,
            SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(128)),
            SkBlurMaskFilter::kHighQuality_BlurFlag);
        paint.setMaskFilter(mf)->unref();
>>>>>>> miniblink49
        canvas->translate(200, 200);
        canvas->drawCircle(100, 100, 200, paint);
        canvas->restore();
    }

private:
    typedef SkView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new BigBlurView; }
static SkViewRegister reg(MyFactory);

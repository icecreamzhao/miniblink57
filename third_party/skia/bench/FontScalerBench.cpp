/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkString.h"

class FontScalerBench : public Benchmark {
    SkString fName;
    SkString fText;
<<<<<<< HEAD
    bool fDoLCD;

public:
    FontScalerBench(bool doLCD)
    {
=======
    bool     fDoLCD;
public:
    FontScalerBench(bool doLCD)  {
>>>>>>> miniblink49
        fName.printf("fontscaler_%s", doLCD ? "lcd" : "aa");
        fText.set("abcdefghijklmnopqrstuvwxyz01234567890");
        fDoLCD = doLCD;
    }

protected:
    virtual const char* onGetName() { return fName.c_str(); }
<<<<<<< HEAD
    virtual void onDraw(int loops, SkCanvas* canvas)
    {
=======
    virtual void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint paint;
        this->setupPaint(&paint);
        paint.setLCDRenderText(fDoLCD);

        for (int i = 0; i < loops; i++) {
            // this is critical - we want to time the creation process, so we
            // explicitly flush our cache before each run
            SkGraphics::PurgeFontCache();

            for (int ps = 9; ps <= 24; ps += 2) {
                paint.setTextSize(SkIntToScalar(ps));
                canvas->drawText(fText.c_str(), fText.size(),
<<<<<<< HEAD
                    0, SkIntToScalar(20), paint);
            }
        }
    }

=======
                        0, SkIntToScalar(20), paint);
            }
        }
    }
>>>>>>> miniblink49
private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new FontScalerBench(false);)
DEF_BENCH(return new FontScalerBench(true);)
=======
DEF_BENCH( return SkNEW_ARGS(FontScalerBench, (false)); )
DEF_BENCH( return SkNEW_ARGS(FontScalerBench, (true)); )
>>>>>>> miniblink49

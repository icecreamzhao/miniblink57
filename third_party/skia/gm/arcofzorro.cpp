/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkRandom.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkRandom.h"
>>>>>>> miniblink49

namespace skiagm {

// This GM draws a lot of arcs in a 'Z' shape. It particularly exercises
// the 'drawArc' code near a singularly of its processing (i.e., near the
// edge of one of its underlying quads).
class ArcOfZorroGM : public GM {
public:
<<<<<<< HEAD
    ArcOfZorroGM()
    {
=======
    ArcOfZorroGM() {
>>>>>>> miniblink49
        this->setBGColor(sk_tool_utils::color_to_565(0xFFCCCCCC));
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("arcofzorro");
    }

    SkISize onISize() override
    {
        return SkISize::Make(1000, 1000);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======

    SkString onShortName() override {
        return SkString("arcofzorro");
    }

    SkISize onISize() override {
        return SkISize::Make(1000, 1000);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkRandom rand;

        SkRect rect = SkRect::MakeXYWH(10, 10, 200, 200);

        SkPaint p;

        p.setStyle(SkPaint::kStroke_Style);
        p.setStrokeWidth(35);
        int xOffset = 0, yOffset = 0;
        int direction = 0;

        for (float arc = 134.0f; arc < 136.0f; arc += 0.01f) {
            SkColor color = rand.nextU();
            color |= 0xff000000;
            p.setColor(color);

            canvas->save();
            canvas->translate(SkIntToScalar(xOffset), SkIntToScalar(yOffset));
            canvas->drawArc(rect, 0, arc, false, p);
            canvas->restore();

            switch (direction) {
            case 0:
                xOffset += 10;
                if (xOffset >= 700) {
                    direction = 1;
                }
                break;
            case 1:
                xOffset -= 10;
                yOffset += 10;
                if (xOffset < 50) {
                    direction = 2;
                }
                break;
            case 2:
                xOffset += 10;
                break;
            }
        }
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ArcOfZorroGM;)
=======
DEF_GM( return SkNEW(ArcOfZorroGM); )

>>>>>>> miniblink49
}

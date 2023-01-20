/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkTypeface.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkTypeface.h"
>>>>>>> miniblink49

// GM to stress the GPU font cache

static SkScalar draw_string(SkCanvas* canvas, const SkString& text, SkScalar x,
<<<<<<< HEAD
    SkScalar y, const SkPaint& paint)
{
=======
                           SkScalar y, const SkPaint& paint) {
>>>>>>> miniblink49
    canvas->drawText(text.c_str(), text.size(), x, y, paint);
    return x + paint.measureText(text.c_str(), text.size());
}

class FontCacheGM : public skiagm::GM {
public:
<<<<<<< HEAD
    FontCacheGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("fontcache");
    }

    SkISize onISize() override
    {
        return SkISize::Make(1280, 640);
    }

    void onOnceBeforeDraw() override
    {
        fTypefaces[0] = sk_tool_utils::create_portable_typeface("serif",
            SkFontStyle::FromOldStyle(SkTypeface::kItalic));
        fTypefaces[1] = sk_tool_utils::create_portable_typeface("sans-serif",
            SkFontStyle::FromOldStyle(SkTypeface::kItalic));
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    FontCacheGM() {
        fTypefaces[0] = NULL;
        fTypefaces[1] = NULL;
    }

    virtual ~FontCacheGM() {
        SkSafeUnref(fTypefaces[0]);
        SkSafeUnref(fTypefaces[1]);
    }

protected:
    SkString onShortName() override {
        return SkString("fontcache");
    }

    SkISize onISize() override {
        return SkISize::Make(1280, 640);
    }

    void onOnceBeforeDraw() override {
        fTypefaces[0] = sk_tool_utils::create_portable_typeface("serif", SkTypeface::kItalic);
        fTypefaces[1] = sk_tool_utils::create_portable_typeface("sans-serif", SkTypeface::kItalic);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setLCDRenderText(true);
        paint.setSubpixelText(true);
        paint.setTypeface(fTypefaces[0]);
        paint.setTextSize(192);

        // Make sure the nul character does not cause problems.
        paint.measureText("\0", 1);

        SkScalar x = 20;
        SkScalar y = 128;
        SkString text("ABCDEFGHIJ");
        draw_string(canvas, text, x, y, paint);
        y += 100;
        SkString text2("KLMNOPQRS");
        draw_string(canvas, text2, x, y, paint);
        y += 100;
        SkString text3("TUVWXYZ012");
        draw_string(canvas, text3, x, y, paint);
        y += 100;
        paint.setTypeface(fTypefaces[1]);
        draw_string(canvas, text, x, y, paint);
        y += 100;
        draw_string(canvas, text2, x, y, paint);
        y += 100;
        draw_string(canvas, text3, x, y, paint);
        y += 100;
    }

private:
<<<<<<< HEAD
    sk_sp<SkTypeface> fTypefaces[2];
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

DEF_GM(return new FontCacheGM;)
=======
    SkTypeface* fTypefaces[2];
    typedef GM INHERITED;
};


//////////////////////////////////////////////////////////////////////////////

DEF_GM( return SkNEW(FontCacheGM); )
>>>>>>> miniblink49

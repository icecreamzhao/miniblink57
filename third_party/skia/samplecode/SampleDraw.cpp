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
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkRandom.h"
#include "SkView.h"

static void test_clearonlayers(SkCanvas* canvas)
{
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkRandom.h"

static void test_clearonlayers(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkCanvas& c = *canvas;

    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    paint.setStyle(SkPaint::kStrokeAndFill_Style);
    SkRect rect = SkRect::MakeXYWH(25, 25, 50, 50);
    c.drawRect(rect, paint);

    c.clipRect(rect);

<<<<<<< HEAD
    c.saveLayer(nullptr, nullptr);
=======
    c.saveLayer(NULL, NULL);
>>>>>>> miniblink49
    rect = SkRect::MakeXYWH(50, 10, 40, 80);
    c.clipRect(rect, SkRegion::kUnion_Op);

    rect = SkRect::MakeXYWH(50, 0, 50, 100);
    // You might draw something here, but it's not necessary.
    // paint.setColor(SK_ColorRED);
    // c.drawRect(rect, paint);
    paint.setXfermodeMode(SkXfermode::kClear_Mode);
    c.drawRect(rect, paint);
    c.restore();
}

<<<<<<< HEAD
static void test_strokerect(SkCanvas* canvas, const SkRect& r)
{
=======
static void test_strokerect(SkCanvas* canvas, const SkRect& r) {
>>>>>>> miniblink49
    SkPaint p;

    p.setAntiAlias(true);
    p.setStyle(SkPaint::kStroke_Style);
    p.setStrokeWidth(4);

    canvas->drawRect(r, p);

    SkPath path;
    SkRect r2(r);
    r2.offset(18, 0);
    path.addRect(r2);

    canvas->drawPath(path, p);
}

<<<<<<< HEAD
static void test_strokerect(SkCanvas* canvas)
{
=======
static void test_strokerect(SkCanvas* canvas) {
>>>>>>> miniblink49
    canvas->drawColor(SK_ColorWHITE);

    SkRect r;

    r.set(10, 10, 14, 14);
    r.offset(0.25f, 0.3333f);
    test_strokerect(canvas, r);
    canvas->translate(0, 20);

    r.set(10, 10, 14.5f, 14.5f);
    r.offset(0.25f, 0.3333f);
    test_strokerect(canvas, r);
    canvas->translate(0, 20);

    r.set(10, 10, 14.5f, 20);
    r.offset(0.25f, 0.3333f);
    test_strokerect(canvas, r);
    canvas->translate(0, 20);

    r.set(10, 10, 20, 14.5f);
    r.offset(0.25f, 0.3333f);
    test_strokerect(canvas, r);
    canvas->translate(0, 20);

    r.set(10, 10, 20, 20);
    r.offset(0.25f, 0.3333f);
    test_strokerect(canvas, r);
    canvas->translate(0, 20);
<<<<<<< HEAD
=======

>>>>>>> miniblink49
}

class Draw : public SkRefCnt {
public:
<<<<<<< HEAD
    Draw()
        : fFlags(0)
    {
    }

    enum Flags {
        kSelected_Flag = 1 << 0
=======
    Draw() : fFlags(0) {}

    enum Flags {
        kSelected_Flag  = 1 << 0
>>>>>>> miniblink49
    };
    int getFlags() const { return fFlags; }
    void setFlags(int flags);

    bool isSelected() const { return SkToBool(fFlags & kSelected_Flag); }
<<<<<<< HEAD
    void setSelected(bool pred)
    {
=======
    void setSelected(bool pred) {
>>>>>>> miniblink49
        if (pred) {
            fFlags |= kSelected_Flag;
        } else {
            fFlags &= ~kSelected_Flag;
        }
    }

<<<<<<< HEAD
    void draw(SkCanvas* canvas)
    {
=======
    void draw(SkCanvas* canvas) {
>>>>>>> miniblink49
        int sc = canvas->save();
        this->onDraw(canvas);
        canvas->restoreToCount(sc);

        if (this->isSelected()) {
            this->drawSelection(canvas);
        }
    }

<<<<<<< HEAD
    void drawSelection(SkCanvas* canvas)
    {
=======
    void drawSelection(SkCanvas* canvas) {
>>>>>>> miniblink49
        int sc = canvas->save();
        this->onDrawSelection(canvas);
        canvas->restoreToCount(sc);
    }

<<<<<<< HEAD
    void getBounds(SkRect* bounds)
    {
        this->onGetBounds(bounds);
    }

    bool hitTest(SkScalar x, SkScalar y)
    {
        return this->onHitTest(x, y);
    }

    void offset(SkScalar dx, SkScalar dy)
    {
=======
    void getBounds(SkRect* bounds) {
        this->onGetBounds(bounds);
    }

    bool hitTest(SkScalar x, SkScalar y) {
        return this->onHitTest(x, y);
    }

    void offset(SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
        if (dx || dy) {
            this->onOffset(dx, dy);
        }
    }

protected:
    virtual void onDraw(SkCanvas*) = 0;
    virtual void onGetBounds(SkRect*) = 0;
    virtual void onOffset(SkScalar dx, SkScalar dy) = 0;
<<<<<<< HEAD
    virtual void onDrawSelection(SkCanvas* canvas)
    {
=======
    virtual void onDrawSelection(SkCanvas* canvas) {
>>>>>>> miniblink49
        SkRect r;
        this->getBounds(&r);
        SkPaint paint;
        SkPoint pts[4];
        r.toQuad(pts);
        paint.setStrokeWidth(SkIntToScalar(10));
        paint.setColor(0x80FF8844);
        paint.setStrokeCap(SkPaint::kRound_Cap);
        canvas->drawPoints(SkCanvas::kPoints_PointMode, 4, pts, paint);
    }
<<<<<<< HEAD
    virtual bool onHitTest(SkScalar x, SkScalar y)
    {
=======
    virtual bool onHitTest(SkScalar x, SkScalar y) {
>>>>>>> miniblink49
        SkRect bounds;
        this->getBounds(&bounds);
        return bounds.contains(x, y);
    }

private:
    int fFlags;
};

class RDraw : public Draw {
public:
    enum Style {
        kRect_Style,
        kOval_Style,
        kRRect_Style,
        kFrame_Style
    };

<<<<<<< HEAD
    RDraw(const SkRect& r, Style s)
        : fRect(r)
        , fStyle(s)
    {
    }

    void setRect(const SkRect& r)
    {
        fRect = r;
    }

    void setPaint(const SkPaint& p)
    {
=======
    RDraw(const SkRect& r, Style s) : fRect(r), fStyle(s) {}

    void setRect(const SkRect& r) {
        fRect = r;
    }

    void setPaint(const SkPaint& p) {
>>>>>>> miniblink49
        fPaint = p;
    }

protected:
<<<<<<< HEAD
    virtual void onDraw(SkCanvas* canvas)
    {
        switch (fStyle) {
        case kRect_Style:
            canvas->drawRect(fRect, fPaint);
            break;
        case kOval_Style:
            canvas->drawOval(fRect, fPaint);
            break;
        case kRRect_Style: {
            SkScalar rx = fRect.width() / 5;
            SkScalar ry = fRect.height() / 5;
            if (rx < ry) {
                ry = rx;
            } else {
                rx = ry;
            }
            canvas->drawRoundRect(fRect, rx, ry, fPaint);
            break;
        }
        case kFrame_Style: {
            SkPath path;
            path.addOval(fRect, SkPath::kCW_Direction);
            SkRect r = fRect;
            r.inset(fRect.width() / 6, 0);
            path.addOval(r, SkPath::kCCW_Direction);
            canvas->drawPath(path, fPaint);
            break;
        }
        }
    }

    virtual void onGetBounds(SkRect* bounds)
    {
        *bounds = fRect;
    }

    virtual void onOffset(SkScalar dx, SkScalar dy)
    {
=======
    virtual void onDraw(SkCanvas* canvas) {
        switch (fStyle) {
            case kRect_Style:
                canvas->drawRect(fRect, fPaint);
                break;
            case kOval_Style:
                canvas->drawOval(fRect, fPaint);
                break;
            case kRRect_Style: {
                SkScalar rx = fRect.width() / 5;
                SkScalar ry = fRect.height() / 5;
                if (rx < ry) {
                    ry = rx;
                } else {
                    rx = ry;
                }
                canvas->drawRoundRect(fRect, rx, ry, fPaint);
                break;
            }
            case kFrame_Style: {
                SkPath path;
                path.addOval(fRect, SkPath::kCW_Direction);
                SkRect r = fRect;
                r.inset(fRect.width()/6, 0);
                path.addOval(r, SkPath::kCCW_Direction);
                canvas->drawPath(path, fPaint);
                break;
            }
        }
    }

    virtual void onGetBounds(SkRect* bounds) {
        *bounds = fRect;
    }

    virtual void onOffset(SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
        fRect.offset(dx, dy);
    }

private:
<<<<<<< HEAD
    SkRect fRect;
    SkPaint fPaint;
    Style fStyle;
=======
    SkRect  fRect;
    SkPaint fPaint;
    Style   fStyle;
>>>>>>> miniblink49
};

class DrawFactory {
public:
<<<<<<< HEAD
    DrawFactory()
    {
=======
    DrawFactory() {
>>>>>>> miniblink49
        fPaint.setAntiAlias(true);
    }

    const SkPaint& getPaint() const { return fPaint; }

<<<<<<< HEAD
    void setPaint(const SkPaint& p)
    {
=======
    void setPaint(const SkPaint& p) {
>>>>>>> miniblink49
        fPaint = p;
    }

    virtual Draw* create(const SkPoint&, const SkPoint&) = 0;

private:
    SkPaint fPaint;
};

class RectFactory : public DrawFactory {
public:
<<<<<<< HEAD
    virtual Draw* create(const SkPoint& p0, const SkPoint& p1)
    {
=======
    virtual Draw* create(const SkPoint& p0, const SkPoint& p1) {
>>>>>>> miniblink49
        SkRect r;
        r.set(p0.x(), p0.y(), p1.x(), p1.y());
        r.sort();

<<<<<<< HEAD
        //        RDraw* d = new RDraw(r, RDraw::kRRect_Style);
=======
//        RDraw* d = new RDraw(r, RDraw::kRRect_Style);
>>>>>>> miniblink49
        RDraw* d = new RDraw(r, RDraw::kFrame_Style);
        d->setPaint(this->getPaint());
        return d;
    }
};

class DrawView : public SkView {
<<<<<<< HEAD
    Draw* fDraw;
    DrawFactory* fFactory;
    SkRandom fRand;
    SkTDArray<Draw*> fList;

public:
    DrawView()
        : fDraw(nullptr)
    {
        fFactory = new RectFactory;
    }

    virtual ~DrawView()
    {
=======
    Draw*           fDraw;
    DrawFactory*    fFactory;
    SkRandom        fRand;
    SkTDArray<Draw*> fList;

public:
    DrawView() : fDraw(NULL) {
        fFactory = new RectFactory;
    }

    virtual ~DrawView() {
>>>>>>> miniblink49
        fList.unrefAll();
        SkSafeUnref(fDraw);
        delete fFactory;
    }

<<<<<<< HEAD
    Draw* setDraw(Draw* d)
    {
=======
    Draw* setDraw(Draw* d) {
>>>>>>> miniblink49
        SkRefCnt_SafeAssign(fDraw, d);
        return d;
    }

<<<<<<< HEAD
    SkColor randColor()
    {
        return (SkColor)fRand.nextU() | 0xFF000000;
    }

    Draw* hitTestList(SkScalar x, SkScalar y) const
    {
=======
    SkColor randColor() {
        return (SkColor)fRand.nextU() | 0xFF000000;
    }

    Draw* hitTestList(SkScalar x, SkScalar y) const {
>>>>>>> miniblink49
        Draw** first = fList.begin();
        for (Draw** iter = fList.end(); iter > first;) {
            --iter;
            if ((*iter)->hitTest(x, y)) {
                return *iter;
            }
        }
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
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
            SampleCode::TitleR(evt, "Draw");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void drawBG(SkCanvas* canvas)
    {
        canvas->drawColor(0xFFDDDDDD);
        //        canvas->drawColor(SK_ColorWHITE);
    }

    virtual void onDraw(SkCanvas* canvas)
    {
        this->drawBG(canvas);
        test_clearonlayers(canvas);
        return;
        //   test_strokerect(canvas); return;
=======
    void drawBG(SkCanvas* canvas) {
        canvas->drawColor(0xFFDDDDDD);
//        canvas->drawColor(SK_ColorWHITE);
    }

    virtual void onDraw(SkCanvas* canvas) {
        this->drawBG(canvas);
        test_clearonlayers(canvas); return;
     //   test_strokerect(canvas); return;
>>>>>>> miniblink49

        for (Draw** iter = fList.begin(); iter < fList.end(); iter++) {
            (*iter)->draw(canvas);
        }
        if (fDraw) {
            fDraw->draw(canvas);
        }
    }

<<<<<<< HEAD
    virtual SkView::Click* onFindClickHandler(SkScalar x, SkScalar y)
    {
=======
    virtual SkView::Click* onFindClickHandler(SkScalar x, SkScalar y) {
>>>>>>> miniblink49
        for (Draw** iter = fList.begin(); iter < fList.end(); iter++) {
            (*iter)->setSelected(false);
        }

        Click* c = new Click(this);
        Draw* d = this->hitTestList(x, y);
        if (d) {
            d->setSelected(true);
            c->setType("dragger");
        } else {
            c->setType("maker");
        }
        return c;
    }

<<<<<<< HEAD
    virtual bool onClick(Click* click)
    {
=======
    virtual bool onClick(Click* click) {
>>>>>>> miniblink49
        if (Click::kUp_State == click->fState) {
            if (click->isType("maker")) {
                if (SkPoint::Distance(click->fOrig, click->fCurr) > SkIntToScalar(3)) {
                    *fList.append() = fDraw;
                } else {
                    fDraw->unref();
                }
<<<<<<< HEAD
                fDraw = nullptr;
=======
                fDraw = NULL;
>>>>>>> miniblink49
            }
            return true;
        }

        if (Click::kDown_State == click->fState) {
            SkPaint p = fFactory->getPaint();
            p.setColor(this->randColor());
            fFactory->setPaint(p);
        }

        if (click->isType("maker")) {
            this->setDraw(fFactory->create(click->fOrig, click->fCurr))->unref();
        } else if (click->isType("dragger")) {
            for (Draw** iter = fList.begin(); iter < fList.end(); iter++) {
                if ((*iter)->isSelected()) {
                    (*iter)->offset(click->fCurr.x() - click->fPrev.x(),
<<<<<<< HEAD
                        click->fCurr.y() - click->fPrev.y());
                }
            }
        }
        this->inval(nullptr);
=======
                                    click->fCurr.y() - click->fPrev.y());
                }
            }
        }
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }

private:
    typedef SkView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new DrawView; }
static SkViewRegister reg(MyFactory);

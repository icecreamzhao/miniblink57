/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "OverView.h"
#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkView.h"

static const char gIsOverview[] = "is-overview";

<<<<<<< HEAD
static int to_lower(int c)
{
=======
static int to_lower(int c) {
>>>>>>> miniblink49
    if ('A' <= c && c <= 'Z') {
        c = c - 'A' + 'a';
    }
    return c;
}

<<<<<<< HEAD
static void make_lc(SkString* str)
{
=======
static void make_lc(SkString* str) {
>>>>>>> miniblink49
    char* ptr = str->writable_str();
    while (*ptr) {
        *ptr = to_lower(*ptr);
        ptr += 1;
    }
}

<<<<<<< HEAD
static bool case_insensitive_find(const SkString& base, const SkString& sub)
{
=======
static bool case_insensitive_find(const SkString& base, const SkString& sub) {
>>>>>>> miniblink49
    SkString lcBase(base);
    SkString lcSub(sub);
    make_lc(&lcBase);
    make_lc(&lcSub);
    return lcBase.find(lcSub.c_str()) >= 0;
}

<<<<<<< HEAD
static bool draw_this_name(const SkString& name, const SkString& filter)
{
=======
static bool draw_this_name(const SkString& name, const SkString& filter) {
>>>>>>> miniblink49
    if (filter.isEmpty()) {
        return true;
    }
    return case_insensitive_find(name, filter);
}

class OverView : public SkView {
public:
    OverView(int count, const SkViewFactory* factories[]);
    virtual ~OverView();

protected:
    bool onEvent(const SkEvent&) override;
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
=======
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Overview");
            return true;
        }
        if (evt->isType(gIsOverview)) {
            return true;
        }
        SkUnichar uni;
        if (SampleCode::CharQ(*evt, &uni)) {
<<<<<<< HEAD
            if (uni >= ' ') {
                fMatchStr.appendUnichar(uni);
            }
            this->inval(nullptr);
=======
            fMatchStr.appendUnichar(uni);
            this->inval(NULL);
>>>>>>> miniblink49
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    void onDraw(SkCanvas* canvas) override;

<<<<<<< HEAD
    bool onSendClickToChildren(SkScalar x, SkScalar y, unsigned modi) override
    {
        return false;
    }

    Click* onFindClickHandler(SkScalar cx, SkScalar cy, unsigned modi) override
    {
=======
    bool onSendClickToChildren(SkScalar x, SkScalar y, unsigned modi) override {
        return false;
    }

    Click* onFindClickHandler(SkScalar cx, SkScalar cy, unsigned modi) override {
>>>>>>> miniblink49
        const SkRect crect = SkRect::MakeXYWH(cx - 0.5f, cy - 0.5f, 1, 1);
        SkPoint loc = this->start();
        for (int i = 0; i < fCount; ++i) {
            if (draw_this_name(fNames[i], fMatchStr)) {
                if (this->bounds(loc).intersects(crect)) {
                    SkEvent evt("set-curr-index");
                    evt.setFast32(i);
                    this->sendEventToParents(evt);
                    break;
                }
                this->next(&loc);
            }
        }
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
>>>>>>> miniblink49
    }

private:
    int fCount;
    const SkViewFactory** fFactories;
    SkString* fNames;
    SkString fMatchStr;
    SkPaint fNamePaint;
    SkPaint::FontMetrics fNameMetrics;
    SkScalar fNameW;
    SkScalar fNameH;

<<<<<<< HEAD
    SkRect bounds(const SkPoint& loc) const
    {
        return SkRect::MakeXYWH(loc.x(), loc.y() + fNameMetrics.fAscent, fNameW, fNameH);
    }

    SkPoint start() const
    {
        return SkPoint::Make(10, -fNameMetrics.fTop);
    }

    void next(SkPoint* loc) const
    {
=======
    SkRect bounds(const SkPoint& loc) const {
        return SkRect::MakeXYWH(loc.x(), loc.y() + fNameMetrics.fAscent, fNameW, fNameH);
    }

    SkPoint start() const {
        return SkPoint::Make(10, -fNameMetrics.fTop);
    }

    void next(SkPoint* loc) const {
>>>>>>> miniblink49
        loc->fY += fNameH;
        if (loc->fY > this->height() - fNameMetrics.fBottom) {
            loc->fY = -fNameMetrics.fTop;
            loc->fX += fNameW;
        }
    }

    typedef SkView INHERITED;
};

<<<<<<< HEAD
SkView* create_overview(int count, const SkViewFactory* factories[])
{
    return new OverView(count, factories);
}

bool is_overview(SkView* view)
{
=======
SkView* create_overview(int count, const SkViewFactory* factories[]) {
    return SkNEW_ARGS(OverView, (count, factories));
}

bool is_overview(SkView* view) {
>>>>>>> miniblink49
    SkEvent isOverview(gIsOverview);
    return view->doQuery(&isOverview);
}

<<<<<<< HEAD
OverView::OverView(int count, const SkViewFactory* factories[])
{
=======
OverView::OverView(int count, const SkViewFactory* factories[]) {
>>>>>>> miniblink49
    fCount = count;
    fFactories = factories;

    fNames = new SkString[count];
    for (int i = 0; i < count; ++i) {
        SkView* view = (*fFactories[i])();
        if (view) {
            (void)SampleCode::RequestTitle(view, &fNames[i]);
            if (0 == fNames[i].find("GM:")) {
                fNames[i].remove(0, 3);
            }
        }
    }

    fNamePaint.setAntiAlias(true);
    fNamePaint.setTextSize(12);
    fNameW = 160;
    fNameH = fNamePaint.getFontMetrics(&fNameMetrics);
}

<<<<<<< HEAD
OverView::~OverView()
{
    delete[] fNames;
}

bool OverView::onEvent(const SkEvent& evt)
{
    return this->INHERITED::onEvent(evt);
}

void OverView::onDraw(SkCanvas* canvas)
{
=======
OverView::~OverView() {
    delete[] fNames;
}

bool OverView::onEvent(const SkEvent& evt) {
    return this->INHERITED::onEvent(evt);
}

void OverView::onDraw(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setColor(0xFFF8F8F8);
    canvas->drawPaint(paint);

    SkPoint loc = this->start();
    for (int i = 0; i < fCount; ++i) {
        if (draw_this_name(fNames[i], fMatchStr)) {
            canvas->drawRect(this->bounds(loc), paint);
            canvas->drawText(fNames[i].c_str(), fNames[i].size(), loc.x(), loc.y(), fNamePaint);
            this->next(&loc);
        }
    }
}
<<<<<<< HEAD
=======

>>>>>>> miniblink49

<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD

#include "SkView.h"
#include "SkCanvas.h"

static inline uint32_t SkSetClearShift(uint32_t bits, bool cond, unsigned shift)
{
    SkASSERT((int)cond == 0 || (int)cond == 1);
    return (bits & ~(1 << shift)) | ((int)cond << shift);
}

////////////////////////////////////////////////////////////////////////

SkView::SkView(uint32_t flags)
    : fFlags(SkToU8(flags))
{
    fWidth = fHeight = 0;
    fLoc.set(0, 0);
    fParent = fFirstChild = fNextSibling = fPrevSibling = nullptr;
=======
#include "SkView.h"
#include "SkCanvas.h"

////////////////////////////////////////////////////////////////////////

SkView::SkView(uint32_t flags) : fFlags(SkToU8(flags))
{
    fWidth = fHeight = 0;
    fLoc.set(0, 0);
    fParent = fFirstChild = fNextSibling = fPrevSibling = NULL;
>>>>>>> miniblink49
    fMatrix.setIdentity();
    fContainsFocus = 0;
}

SkView::~SkView()
{
    this->detachAllChildren();
}

void SkView::setFlags(uint32_t flags)
{
    SkASSERT((flags & ~kAllFlagMasks) == 0);

    uint32_t diff = fFlags ^ flags;

    if (diff & kVisible_Mask)
<<<<<<< HEAD
        this->inval(nullptr);

    fFlags = SkToU8(flags);

    if (diff & kVisible_Mask) {
        this->inval(nullptr);
=======
        this->inval(NULL);

    fFlags = SkToU8(flags);

    if (diff & kVisible_Mask)
    {
        this->inval(NULL);
>>>>>>> miniblink49
    }
}

void SkView::setVisibleP(bool pred)
{
    this->setFlags(SkSetClearShift(fFlags, pred, kVisible_Shift));
}

void SkView::setEnabledP(bool pred)
{
    this->setFlags(SkSetClearShift(fFlags, pred, kEnabled_Shift));
}

void SkView::setFocusableP(bool pred)
{
    this->setFlags(SkSetClearShift(fFlags, pred, kFocusable_Shift));
}

<<<<<<< HEAD
void SkView::setClipToBounds(bool pred)
{
=======
void SkView::setClipToBounds(bool pred) {
>>>>>>> miniblink49
    this->setFlags(SkSetClearShift(fFlags, !pred, kNoClip_Shift));
}

void SkView::setSize(SkScalar width, SkScalar height)
{
    width = SkMaxScalar(0, width);
    height = SkMaxScalar(0, height);

<<<<<<< HEAD
    if (fWidth != width || fHeight != height) {
        this->inval(nullptr);
        fWidth = width;
        fHeight = height;
        this->inval(nullptr);
=======
    if (fWidth != width || fHeight != height)
    {
        this->inval(NULL);
        fWidth = width;
        fHeight = height;
        this->inval(NULL);
>>>>>>> miniblink49
        this->onSizeChange();
        this->invokeLayout();
    }
}

void SkView::setLoc(SkScalar x, SkScalar y)
{
<<<<<<< HEAD
    if (fLoc.fX != x || fLoc.fY != y) {
        this->inval(nullptr);
        fLoc.set(x, y);
        this->inval(nullptr);
=======
    if (fLoc.fX != x || fLoc.fY != y)
    {
        this->inval(NULL);
        fLoc.set(x, y);
        this->inval(NULL);
>>>>>>> miniblink49
    }
}

void SkView::offset(SkScalar dx, SkScalar dy)
{
    if (dx || dy)
        this->setLoc(fLoc.fX + dx, fLoc.fY + dy);
}

void SkView::setLocalMatrix(const SkMatrix& matrix)
{
<<<<<<< HEAD
    this->inval(nullptr);
    fMatrix = matrix;
    this->inval(nullptr);
=======
    this->inval(NULL);
    fMatrix = matrix;
    this->inval(NULL);
>>>>>>> miniblink49
}

void SkView::draw(SkCanvas* canvas)
{
<<<<<<< HEAD
    if (fWidth && fHeight && this->isVisible()) {
        SkRect r;
        r.set(fLoc.fX, fLoc.fY, fLoc.fX + fWidth, fLoc.fY + fHeight);
        if (this->isClipToBounds() && canvas->quickReject(r)) {
            return;
        }

        SkAutoCanvasRestore as(canvas, true);
=======
    if (fWidth && fHeight && this->isVisible())
    {
        SkRect    r;
        r.set(fLoc.fX, fLoc.fY, fLoc.fX + fWidth, fLoc.fY + fHeight);
        if (this->isClipToBounds() &&
            canvas->quickReject(r)) {
                return;
        }

        SkAutoCanvasRestore    as(canvas, true);
>>>>>>> miniblink49

        if (this->isClipToBounds()) {
            canvas->clipRect(r);
        }

        canvas->translate(fLoc.fX, fLoc.fY);
        canvas->concat(fMatrix);

        if (fParent) {
            fParent->beforeChild(this, canvas);
        }

        int sc = canvas->save();
        this->onDraw(canvas);
        canvas->restoreToCount(sc);

        if (fParent) {
            fParent->afterChild(this, canvas);
        }

<<<<<<< HEAD
        B2FIter iter(this);
        SkView* child;

        SkCanvas* childCanvas = this->beforeChildren(canvas);

        while ((child = iter.next()) != nullptr)
=======
        B2FIter    iter(this);
        SkView*    child;

        SkCanvas* childCanvas = this->beforeChildren(canvas);

        while ((child = iter.next()) != NULL)
>>>>>>> miniblink49
            child->draw(childCanvas);

        this->afterChildren(canvas);
    }
}

<<<<<<< HEAD
void SkView::inval(SkRect* rect)
{
    SkView* view = this;
=======
void SkView::inval(SkRect* rect) {
    SkView*    view = this;
>>>>>>> miniblink49
    SkRect storage;

    for (;;) {
        if (!view->isVisible()) {
            return;
        }
        if (view->isClipToBounds()) {
            SkRect bounds;
            view->getLocalBounds(&bounds);
            if (rect && !bounds.intersect(*rect)) {
                return;
            }
            storage = bounds;
            rect = &storage;
        }
        if (view->handleInval(rect)) {
            return;
        }

        SkView* parent = view->fParent;
<<<<<<< HEAD
        if (parent == nullptr) {
=======
        if (parent == NULL) {
>>>>>>> miniblink49
            return;
        }

        if (rect) {
            rect->offset(view->fLoc.fX, view->fLoc.fY);
        }
        view = parent;
    }
}

////////////////////////////////////////////////////////////////////////////

bool SkView::setFocusView(SkView* fv)
{
    SkView* view = this;

    do {
<<<<<<< HEAD
        if (view->onSetFocusView(fv)) {
            return true;
        }
    } while ((view = view->fParent) != nullptr);
=======
        if (view->onSetFocusView(fv))
            return true;
    } while ((view = view->fParent) != NULL);
>>>>>>> miniblink49
    return false;
}

SkView* SkView::getFocusView() const
{
<<<<<<< HEAD
    SkView* focus = nullptr;
    const SkView* view = this;
    do {
        if (view->onGetFocusView(&focus)) {
            break;
        }
    } while ((view = view->fParent) != nullptr);
=======
    SkView*            focus = NULL;
    const SkView*    view = this;
    do {
        if (view->onGetFocusView(&focus))
            break;
    } while ((view = view->fParent) != NULL);
>>>>>>> miniblink49
    return focus;
}

bool SkView::hasFocus() const
{
    return this == this->getFocusView();
}

bool SkView::acceptFocus()
{
    return this->isFocusable() && this->setFocusView(this);
}

/*
    Try to give focus to this view, or its children
*/
SkView* SkView::acceptFocus(FocusDirection dir)
{
<<<<<<< HEAD
    if (dir == kNext_FocusDirection) {
        if (this->acceptFocus()) {
            return this;
        }
        B2FIter iter(this);
        SkView *child, *focus;
        while ((child = iter.next()) != nullptr) {
            if ((focus = child->acceptFocus(dir)) != nullptr) {
                return focus;
            }
        }
    } else { // prev
        F2BIter iter(this);
        SkView *child, *focus;
        while ((child = iter.next()) != nullptr) {
            if ((focus = child->acceptFocus(dir)) != nullptr) {
                return focus;
            }
        }
        if (this->acceptFocus()) {
            return this;
        }
    }
    return nullptr;
=======
    if (dir == kNext_FocusDirection)
    {
        if (this->acceptFocus())
            return this;

        B2FIter    iter(this);
        SkView*    child, *focus;
        while ((child = iter.next()) != NULL)
            if ((focus = child->acceptFocus(dir)) != NULL)
                return focus;
    }
    else // prev
    {
        F2BIter    iter(this);
        SkView*    child, *focus;
        while ((child = iter.next()) != NULL)
            if ((focus = child->acceptFocus(dir)) != NULL)
                return focus;

        if (this->acceptFocus())
            return this;
    }

    return NULL;
>>>>>>> miniblink49
}

SkView* SkView::moveFocus(FocusDirection dir)
{
    SkView* focus = this->getFocusView();

<<<<<<< HEAD
    if (focus == nullptr) { // start with the root
        focus = this;
        while (focus->fParent) {
            focus = focus->fParent;
        }
    }

    SkView *child, *parent;

    if (dir == kNext_FocusDirection) {
=======
    if (focus == NULL)
    {    // start with the root
        focus = this;
        while (focus->fParent)
            focus = focus->fParent;
    }

    SkView*    child, *parent;

    if (dir == kNext_FocusDirection)
    {
>>>>>>> miniblink49
        parent = focus;
        child = focus->fFirstChild;
        if (child)
            goto FIRST_CHILD;
        else
            goto NEXT_SIB;

        do {
<<<<<<< HEAD
            while (child != parent->fFirstChild) {
            FIRST_CHILD:
                if ((focus = child->acceptFocus(dir)) != nullptr)
                    return focus;
                child = child->fNextSibling;
            }
        NEXT_SIB:
            child = parent->fNextSibling;
            parent = parent->fParent;
        } while (parent != nullptr);
    } else { // prevfocus
        parent = focus->fParent;
        if (parent == nullptr) { // we're the root
            return focus->acceptFocus(dir);
        } else {
            child = focus;
            while (parent) {
                while (child != parent->fFirstChild) {
                    child = child->fPrevSibling;
                    if ((focus = child->acceptFocus(dir)) != nullptr) {
                        return focus;
                    }
                }
                if (parent->acceptFocus()) {
                    return parent;
                }
=======
            while (child != parent->fFirstChild)
            {
    FIRST_CHILD:
                if ((focus = child->acceptFocus(dir)) != NULL)
                    return focus;
                child = child->fNextSibling;
            }
    NEXT_SIB:
            child = parent->fNextSibling;
            parent = parent->fParent;
        } while (parent != NULL);
    }
    else    // prevfocus
    {
        parent = focus->fParent;
        if (parent == NULL)    // we're the root
            return focus->acceptFocus(dir);
        else
        {
            child = focus;
            while (parent)
            {
                while (child != parent->fFirstChild)
                {
                    child = child->fPrevSibling;
                    if ((focus = child->acceptFocus(dir)) != NULL)
                        return focus;
                }
                if (parent->acceptFocus())
                    return parent;

>>>>>>> miniblink49
                child = parent;
                parent = parent->fParent;
            }
        }
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

void SkView::onFocusChange(bool gainFocusP)
{
<<<<<<< HEAD
    this->inval(nullptr);
=======
    this->inval(NULL);
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////

SkView::Click::Click(SkView* target)
{
    SkASSERT(target);
    fTargetID = target->getSinkID();
<<<<<<< HEAD
    fType = nullptr;
    fWeOwnTheType = false;
    fOwner = nullptr;
=======
    fType = NULL;
    fWeOwnTheType = false;
    fOwner = NULL;
>>>>>>> miniblink49
}

SkView::Click::~Click()
{
    this->resetType();
}

void SkView::Click::resetType()
{
<<<<<<< HEAD
    if (fWeOwnTheType) {
        sk_free(fType);
        fWeOwnTheType = false;
    }
    fType = nullptr;
=======
    if (fWeOwnTheType)
    {
        sk_free(fType);
        fWeOwnTheType = false;
    }
    fType = NULL;
>>>>>>> miniblink49
}

bool SkView::Click::isType(const char type[]) const
{
    const char* t = fType;

<<<<<<< HEAD
    if (type == t) {
        return true;
    }
    if (type == nullptr) {
        type = "";
    }
    if (t == nullptr) {
        t = "";
    }
=======
    if (type == t)
        return true;

    if (type == NULL)
        type = "";
    if (t == NULL)
        t = "";
>>>>>>> miniblink49
    return !strcmp(t, type);
}

void SkView::Click::setType(const char type[])
{
    this->resetType();
    fType = (char*)type;
}

void SkView::Click::copyType(const char type[])
{
<<<<<<< HEAD
    if (fType != type) {
        this->resetType();
        if (type) {
            size_t len = strlen(type) + 1;
=======
    if (fType != type)
    {
        this->resetType();
        if (type)
        {
            size_t    len = strlen(type) + 1;
>>>>>>> miniblink49
            fType = (char*)sk_malloc_throw(len);
            memcpy(fType, type, len);
            fWeOwnTheType = true;
        }
    }
}

<<<<<<< HEAD
SkView::Click* SkView::findClickHandler(SkScalar x, SkScalar y, unsigned modi)
{
    if (x < 0 || y < 0 || x >= fWidth || y >= fHeight) {
        return nullptr;
    }

    if (this->onSendClickToChildren(x, y, modi)) {
        F2BIter iter(this);
        SkView* child;

        while ((child = iter.next()) != nullptr) {
            SkPoint p;
#if 0
            if (!child->globalToLocal(x, y, &p)) {
                continue;
            }
#else
            // the above seems broken, so just respecting fLoc for now <reed>
            p.set(x - child->fLoc.x(), y - child->fLoc.y());
#endif
=======
SkView::Click* SkView::findClickHandler(SkScalar x, SkScalar y, unsigned modi) {
    if (x < 0 || y < 0 || x >= fWidth || y >= fHeight) {
        return NULL;
    }

    if (this->onSendClickToChildren(x, y, modi)) {
        F2BIter    iter(this);
        SkView*    child;

        while ((child = iter.next()) != NULL)
        {
            SkPoint p;
            if (!child->globalToLocal(x, y, &p)) {
                continue;
            }
>>>>>>> miniblink49

            Click* click = child->findClickHandler(p.fX, p.fY, modi);

            if (click) {
                return click;
            }
        }
    }

    return this->onFindClickHandler(x, y, modi);
}

void SkView::DoClickDown(Click* click, int x, int y, unsigned modi)
{
    SkASSERT(click);

    SkView* target = (SkView*)SkEventSink::FindSink(click->fTargetID);
<<<<<<< HEAD
    if (nullptr == target) {
=======
    if (NULL == target) {
>>>>>>> miniblink49
        return;
    }

    click->fIOrig.set(x, y);
    click->fICurr = click->fIPrev = click->fIOrig;

    click->fOrig.iset(x, y);
    if (!target->globalToLocal(&click->fOrig)) {
        // no history to let us recover from this failure
        return;
    }
    click->fPrev = click->fCurr = click->fOrig;

    click->fState = Click::kDown_State;
    click->fModifierKeys = modi;
    target->onClick(click);
}

void SkView::DoClickMoved(Click* click, int x, int y, unsigned modi)
{
    SkASSERT(click);

    SkView* target = (SkView*)SkEventSink::FindSink(click->fTargetID);
<<<<<<< HEAD
    if (nullptr == target) {
=======
    if (NULL == target) {
>>>>>>> miniblink49
        return;
    }

    click->fIPrev = click->fICurr;
    click->fICurr.set(x, y);

    click->fPrev = click->fCurr;
    click->fCurr.iset(x, y);
    if (!target->globalToLocal(&click->fCurr)) {
        // on failure pretend the mouse didn't move
        click->fCurr = click->fPrev;
    }

    click->fState = Click::kMoved_State;
    click->fModifierKeys = modi;
    target->onClick(click);
}

void SkView::DoClickUp(Click* click, int x, int y, unsigned modi)
{
    SkASSERT(click);

    SkView* target = (SkView*)SkEventSink::FindSink(click->fTargetID);
<<<<<<< HEAD
    if (nullptr == target) {
=======
    if (NULL == target) {
>>>>>>> miniblink49
        return;
    }

    click->fIPrev = click->fICurr;
    click->fICurr.set(x, y);

    click->fPrev = click->fCurr;
    click->fCurr.iset(x, y);
    if (!target->globalToLocal(&click->fCurr)) {
        // on failure pretend the mouse didn't move
        click->fCurr = click->fPrev;
    }

    click->fState = Click::kUp_State;
    click->fModifierKeys = modi;
    target->onClick(click);
}

//////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkView::invokeLayout()
{
=======
void SkView::invokeLayout() {
>>>>>>> miniblink49
    SkView::Layout* layout = this->getLayout();

    if (layout) {
        layout->layoutChildren(this);
    }
}

<<<<<<< HEAD
void SkView::onDraw(SkCanvas* canvas)
{
=======
void SkView::onDraw(SkCanvas* canvas) {
>>>>>>> miniblink49
    Artist* artist = this->getArtist();

    if (artist) {
        artist->draw(this, canvas);
    }
}

<<<<<<< HEAD
void SkView::onSizeChange() { }

bool SkView::onSendClickToChildren(SkScalar x, SkScalar y, unsigned modi)
{
    return true;
}

SkView::Click* SkView::onFindClickHandler(SkScalar x, SkScalar y, unsigned modi)
{
    return nullptr;
}

bool SkView::onClick(Click*)
{
    return false;
}

bool SkView::handleInval(const SkRect*)
{
=======
void SkView::onSizeChange() {}

bool SkView::onSendClickToChildren(SkScalar x, SkScalar y, unsigned modi) {
    return true;
}

SkView::Click* SkView::onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) {
    return NULL;
}

bool SkView::onClick(Click*) {
    return false;
}

bool SkView::handleInval(const SkRect*) {
>>>>>>> miniblink49
    return false;
}

//////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkView::getLocalBounds(SkRect* bounds) const
{
=======
void SkView::getLocalBounds(SkRect* bounds) const {
>>>>>>> miniblink49
    if (bounds) {
        bounds->set(0, 0, fWidth, fHeight);
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkView::detachFromParent_NoLayout()
{
    this->validate();
    if (fParent == nullptr) {
=======
void SkView::detachFromParent_NoLayout() {
    this->validate();
    if (fParent == NULL) {
>>>>>>> miniblink49
        return;
    }

    if (fContainsFocus) {
<<<<<<< HEAD
        (void)this->setFocusView(nullptr);
    }

    this->inval(nullptr);

    SkView* next = nullptr;

    if (fNextSibling != this) { // do we have any siblings
=======
        (void)this->setFocusView(NULL);
    }

    this->inval(NULL);

    SkView* next = NULL;

    if (fNextSibling != this) {   // do we have any siblings
>>>>>>> miniblink49
        fNextSibling->fPrevSibling = fPrevSibling;
        fPrevSibling->fNextSibling = fNextSibling;
        next = fNextSibling;
    }

    if (fParent->fFirstChild == this) {
        fParent->fFirstChild = next;
    }

<<<<<<< HEAD
    fParent = fNextSibling = fPrevSibling = nullptr;
=======
    fParent = fNextSibling = fPrevSibling = NULL;
>>>>>>> miniblink49

    this->validate();
    this->unref();
}

<<<<<<< HEAD
void SkView::detachFromParent()
{
=======
void SkView::detachFromParent() {
>>>>>>> miniblink49
    this->validate();
    SkView* parent = fParent;

    if (parent) {
        this->detachFromParent_NoLayout();
        parent->invokeLayout();
    }
}

<<<<<<< HEAD
SkView* SkView::attachChildToBack(SkView* child)
{
    this->validate();
    SkASSERT(child != this);

    if (child == nullptr || fFirstChild == child)
=======
SkView* SkView::attachChildToBack(SkView* child) {
    this->validate();
    SkASSERT(child != this);

    if (child == NULL || fFirstChild == child)
>>>>>>> miniblink49
        goto DONE;

    child->ref();
    child->detachFromParent_NoLayout();

<<<<<<< HEAD
    if (fFirstChild == nullptr) {
=======
    if (fFirstChild == NULL) {
>>>>>>> miniblink49
        child->fNextSibling = child;
        child->fPrevSibling = child;
    } else {
        child->fNextSibling = fFirstChild;
        child->fPrevSibling = fFirstChild->fPrevSibling;
        fFirstChild->fPrevSibling->fNextSibling = child;
        fFirstChild->fPrevSibling = child;
    }

    fFirstChild = child;
    child->fParent = this;
<<<<<<< HEAD
    child->inval(nullptr);
=======
    child->inval(NULL);
>>>>>>> miniblink49

    this->validate();
    this->invokeLayout();
DONE:
    return child;
}

<<<<<<< HEAD
SkView* SkView::attachChildToFront(SkView* child)
{
    this->validate();
    SkASSERT(child != this);

    if (child == nullptr || (fFirstChild && fFirstChild->fPrevSibling == child))
=======
SkView* SkView::attachChildToFront(SkView* child) {
    this->validate();
    SkASSERT(child != this);

    if (child == NULL || (fFirstChild && fFirstChild->fPrevSibling == child))
>>>>>>> miniblink49
        goto DONE;

    child->ref();
    child->detachFromParent_NoLayout();

<<<<<<< HEAD
    if (fFirstChild == nullptr) {
=======
    if (fFirstChild == NULL) {
>>>>>>> miniblink49
        fFirstChild = child;
        child->fNextSibling = child;
        child->fPrevSibling = child;
    } else {
        child->fNextSibling = fFirstChild;
        child->fPrevSibling = fFirstChild->fPrevSibling;
        fFirstChild->fPrevSibling->fNextSibling = child;
        fFirstChild->fPrevSibling = child;
    }

    child->fParent = this;
<<<<<<< HEAD
    child->inval(nullptr);
=======
    child->inval(NULL);
>>>>>>> miniblink49

    this->validate();
    this->invokeLayout();
DONE:
    return child;
}

<<<<<<< HEAD
void SkView::detachAllChildren()
{
=======
void SkView::detachAllChildren() {
>>>>>>> miniblink49
    this->validate();
    while (fFirstChild)
        fFirstChild->detachFromParent_NoLayout();
}

<<<<<<< HEAD
void SkView::localToGlobal(SkMatrix* matrix) const
{
    if (matrix) {
        matrix->reset();
        const SkView* view = this;
        while (view) {
=======
void SkView::localToGlobal(SkMatrix* matrix) const {
    if (matrix) {
        matrix->reset();
        const SkView* view = this;
        while (view)
        {
>>>>>>> miniblink49
            matrix->preConcat(view->getLocalMatrix());
            matrix->preTranslate(-view->fLoc.fX, -view->fLoc.fY);
            view = view->fParent;
        }
    }
}
<<<<<<< HEAD

bool SkView::globalToLocal(SkScalar x, SkScalar y, SkPoint* local) const
{
=======
bool SkView::globalToLocal(SkScalar x, SkScalar y, SkPoint* local) const
{
    SkASSERT(this);

>>>>>>> miniblink49
    if (local) {
        SkMatrix m;
        this->localToGlobal(&m);
        if (!m.invert(&m)) {
            return false;
        }
        SkPoint p;
        m.mapXY(x, y, &p);
        local->set(p.fX, p.fY);
    }

    return true;
}

//////////////////////////////////////////////////////////////////

/*    Even if the subclass overrides onInflate, they should always be
    sure to call the inherited method, so that we get called.
*/
<<<<<<< HEAD
void SkView::onInflate(const SkDOM& dom, const SkDOM::Node* node)
{
=======
void SkView::onInflate(const SkDOM& dom, const SkDOM::Node* node) {
>>>>>>> miniblink49
    SkScalar x, y;

    x = this->locX();
    y = this->locY();
    (void)dom.findScalar(node, "x", &x);
    (void)dom.findScalar(node, "y", &y);
    this->setLoc(x, y);

    x = this->width();
    y = this->height();
    (void)dom.findScalar(node, "width", &x);
    (void)dom.findScalar(node, "height", &y);
    this->setSize(x, y);

    // inflate the flags

    static const char* gFlagNames[] = {
        "visible", "enabled", "focusable", "flexH", "flexV"
    };
    SkASSERT(SK_ARRAY_COUNT(gFlagNames) == kFlagShiftCount);

<<<<<<< HEAD
    bool b;
    uint32_t flags = this->getFlags();
    for (unsigned i = 0; i < SK_ARRAY_COUNT(gFlagNames); i++) {
        if (dom.findBool(node, gFlagNames[i], &b)) {
            flags = SkSetClearShift(flags, b, i);
        }
    }
    this->setFlags(flags);
}

void SkView::inflate(const SkDOM& dom, const SkDOM::Node* node)
{
    this->onInflate(dom, node);
}

void SkView::onPostInflate(const SkTDict<SkView*>&)
{
    // override in subclass as needed
}

void SkView::postInflate(const SkTDict<SkView*>& dict)
{
    this->onPostInflate(dict);

    B2FIter iter(this);
    SkView* child;
    while ((child = iter.next()) != nullptr)
=======
    bool     b;
    uint32_t flags = this->getFlags();
    for (unsigned i = 0; i < SK_ARRAY_COUNT(gFlagNames); i++)
        if (dom.findBool(node, gFlagNames[i], &b))
            flags = SkSetClearShift(flags, b, i);
    this->setFlags(flags);
}

void SkView::inflate(const SkDOM& dom, const SkDOM::Node* node) {
    this->onInflate(dom, node);
}

void SkView::onPostInflate(const SkTDict<SkView*>&) {
    // override in subclass as needed
}

void SkView::postInflate(const SkTDict<SkView*>& dict) {
    this->onPostInflate(dict);

    B2FIter    iter(this);
    SkView*    child;
    while ((child = iter.next()) != NULL)
>>>>>>> miniblink49
        child->postInflate(dict);
}

//////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkView* SkView::sendEventToParents(const SkEvent& evt)
{
=======
SkView* SkView::sendEventToParents(const SkEvent& evt) {
>>>>>>> miniblink49
    SkView* parent = fParent;

    while (parent) {
        if (parent->doEvent(evt)) {
            return parent;
        }
        parent = parent->fParent;
    }
<<<<<<< HEAD
    return nullptr;
}

SkView* SkView::sendQueryToParents(SkEvent* evt)
{
=======
    return NULL;
}

SkView* SkView::sendQueryToParents(SkEvent* evt) {
>>>>>>> miniblink49
    SkView* parent = fParent;

    while (parent) {
        if (parent->doQuery(evt)) {
            return parent;
        }
        parent = parent->fParent;
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkView::F2BIter::F2BIter(const SkView* parent)
{
    fFirstChild = parent ? parent->fFirstChild : nullptr;
    fChild = fFirstChild ? fFirstChild->fPrevSibling : nullptr;
}

SkView* SkView::F2BIter::next()
{
=======
SkView::F2BIter::F2BIter(const SkView* parent) {
    fFirstChild = parent ? parent->fFirstChild : NULL;
    fChild = fFirstChild ? fFirstChild->fPrevSibling : NULL;
}

SkView* SkView::F2BIter::next() {
>>>>>>> miniblink49
    SkView* curr = fChild;

    if (fChild) {
        if (fChild == fFirstChild) {
<<<<<<< HEAD
            fChild = nullptr;
=======
            fChild = NULL;
>>>>>>> miniblink49
        } else {
            fChild = fChild->fPrevSibling;
        }
    }
    return curr;
}

<<<<<<< HEAD
SkView::B2FIter::B2FIter(const SkView* parent)
{
    fFirstChild = parent ? parent->fFirstChild : nullptr;
    fChild = fFirstChild;
}

SkView* SkView::B2FIter::next()
{
=======
SkView::B2FIter::B2FIter(const SkView* parent) {
    fFirstChild = parent ? parent->fFirstChild : NULL;
    fChild = fFirstChild;
}

SkView* SkView::B2FIter::next() {
>>>>>>> miniblink49
    SkView* curr = fChild;

    if (fChild) {
        SkView* next = fChild->fNextSibling;
        if (next == fFirstChild)
<<<<<<< HEAD
            next = nullptr;
=======
            next = NULL;
>>>>>>> miniblink49
        fChild = next;
    }
    return curr;
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

#ifdef SK_DEBUG

<<<<<<< HEAD
void SkView::validate() const
{
    //    SkASSERT(this->getRefCnt() > 0 && this->getRefCnt() < 100);
=======
void SkView::validate() const {
//    SkASSERT(this->getRefCnt() > 0 && this->getRefCnt() < 100);
>>>>>>> miniblink49
    if (fParent) {
        SkASSERT(fNextSibling);
        SkASSERT(fPrevSibling);
    } else {
<<<<<<< HEAD
        bool nextNull = nullptr == fNextSibling;
        bool prevNull = nullptr == fNextSibling;
=======
        bool nextNull = NULL == fNextSibling;
        bool prevNull = NULL == fNextSibling;
>>>>>>> miniblink49
        SkASSERT(nextNull == prevNull);
    }
}

static inline void show_if_nonzero(const char name[], SkScalar value)
{
<<<<<<< HEAD
    if (value) {
        SkDebugf("%s=\"%g\"", name, value / 65536.);
    }
=======
    if (value)
        SkDebugf("%s=\"%g\"", name, value/65536.);
>>>>>>> miniblink49
}

static void tab(int level)
{
<<<<<<< HEAD
    for (int i = 0; i < level; i++) {
        SkDebugf("    ");
    }
=======
    for (int i = 0; i < level; i++)
        SkDebugf("    ");
>>>>>>> miniblink49
}

static void dumpview(const SkView* view, int level, bool recurse)
{
    tab(level);

    SkDebugf("<view");
    show_if_nonzero(" x", view->locX());
    show_if_nonzero(" y", view->locY());
    show_if_nonzero(" width", view->width());
    show_if_nonzero(" height", view->height());

<<<<<<< HEAD
    if (recurse) {
        SkView::B2FIter iter(view);
        SkView* child;
        bool noChildren = true;

        while ((child = iter.next()) != nullptr) {
            if (noChildren) {
                SkDebugf(">\n");
            }
=======
    if (recurse)
    {
        SkView::B2FIter    iter(view);
        SkView*            child;
        bool            noChildren = true;

        while ((child = iter.next()) != NULL)
        {
            if (noChildren)
                SkDebugf(">\n");
>>>>>>> miniblink49
            noChildren = false;
            dumpview(child, level + 1, true);
        }

<<<<<<< HEAD
        if (!noChildren) {
            tab(level);
            SkDebugf("</view>\n");
        } else {
            goto ONELINER;
        }
    } else {
=======
        if (!noChildren)
        {
            tab(level);
            SkDebugf("</view>\n");
        }
        else
            goto ONELINER;
    }
    else
    {
>>>>>>> miniblink49
    ONELINER:
        SkDebugf(" />\n");
    }
}

void SkView::dump(bool recurse) const
{
    dumpview(this, 0, recurse);
}

#endif

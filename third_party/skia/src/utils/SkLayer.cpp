<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkLayer.h"
#include "SkCanvas.h"

//#define DEBUG_DRAW_LAYER_BOUNDS
//#define DEBUG_TRACK_NEW_DELETE

#ifdef DEBUG_TRACK_NEW_DELETE
<<<<<<< HEAD
static int gLayerAllocCount;
=======
    static int gLayerAllocCount;
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkLayer::SkLayer()
{
    fParent = nullptr;
=======
SkLayer::SkLayer() {
    fParent = NULL;
>>>>>>> miniblink49
    m_opacity = SK_Scalar1;
    m_size.set(0, 0);
    m_position.set(0, 0);
    m_anchorPoint.set(SK_ScalarHalf, SK_ScalarHalf);

    fMatrix.reset();
    fChildrenMatrix.reset();
    fFlags = 0;

#ifdef DEBUG_TRACK_NEW_DELETE
    gLayerAllocCount += 1;
    SkDebugf("SkLayer new:    %d\n", gLayerAllocCount);
#endif
}

<<<<<<< HEAD
SkLayer::SkLayer(const SkLayer& src)
    : INHERITED()
{
    fParent = nullptr;
=======
SkLayer::SkLayer(const SkLayer& src) : INHERITED() {
    fParent = NULL;
>>>>>>> miniblink49
    m_opacity = src.m_opacity;
    m_size = src.m_size;
    m_position = src.m_position;
    m_anchorPoint = src.m_anchorPoint;

    fMatrix = src.fMatrix;
    fChildrenMatrix = src.fChildrenMatrix;
    fFlags = src.fFlags;

#ifdef DEBUG_TRACK_NEW_DELETE
    gLayerAllocCount += 1;
    SkDebugf("SkLayer copy:   %d\n", gLayerAllocCount);
#endif
}

<<<<<<< HEAD
SkLayer::~SkLayer()
{
=======
SkLayer::~SkLayer() {
>>>>>>> miniblink49
    this->removeChildren();

#ifdef DEBUG_TRACK_NEW_DELETE
    gLayerAllocCount -= 1;
    SkDebugf("SkLayer delete: %d\n", gLayerAllocCount);
#endif
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkLayer::isInheritFromRootTransform() const
{
    return (fFlags & kInheritFromRootTransform_Flag) != 0;
}

void SkLayer::setInheritFromRootTransform(bool doInherit)
{
=======
bool SkLayer::isInheritFromRootTransform() const {
    return (fFlags & kInheritFromRootTransform_Flag) != 0;
}

void SkLayer::setInheritFromRootTransform(bool doInherit) {
>>>>>>> miniblink49
    if (doInherit) {
        fFlags |= kInheritFromRootTransform_Flag;
    } else {
        fFlags &= ~kInheritFromRootTransform_Flag;
    }
}

<<<<<<< HEAD
void SkLayer::setMatrix(const SkMatrix& matrix)
{
    fMatrix = matrix;
}

void SkLayer::setChildrenMatrix(const SkMatrix& matrix)
{
=======
void SkLayer::setMatrix(const SkMatrix& matrix) {
    fMatrix = matrix;
}

void SkLayer::setChildrenMatrix(const SkMatrix& matrix) {
>>>>>>> miniblink49
    fChildrenMatrix = matrix;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
int SkLayer::countChildren() const
{
    return m_children.count();
}

SkLayer* SkLayer::getChild(int index) const
{
=======
int SkLayer::countChildren() const {
    return m_children.count();
}

SkLayer* SkLayer::getChild(int index) const {
>>>>>>> miniblink49
    if ((unsigned)index < (unsigned)m_children.count()) {
        SkASSERT(m_children[index]->fParent == this);
        return m_children[index];
    }
<<<<<<< HEAD
    return nullptr;
}

SkLayer* SkLayer::addChild(SkLayer* child)
{
    SkASSERT(this != child);
    child->ref();
    child->detachFromParent();
    SkASSERT(child->fParent == nullptr);
=======
    return NULL;
}

SkLayer* SkLayer::addChild(SkLayer* child) {
    SkASSERT(this != child);
    child->ref();
    child->detachFromParent();
    SkASSERT(child->fParent == NULL);
>>>>>>> miniblink49
    child->fParent = this;

    *m_children.append() = child;
    return child;
}

<<<<<<< HEAD
void SkLayer::detachFromParent()
{
=======
void SkLayer::detachFromParent() {
>>>>>>> miniblink49
    if (fParent) {
        int index = fParent->m_children.find(this);
        SkASSERT(index >= 0);
        fParent->m_children.remove(index);
<<<<<<< HEAD
        fParent = nullptr;
        this->unref(); // this call might delete us
    }
}

void SkLayer::removeChildren()
{
=======
        fParent = NULL;
        this->unref();  // this call might delete us
    }
}

void SkLayer::removeChildren() {
>>>>>>> miniblink49
    int count = m_children.count();
    for (int i = 0; i < count; i++) {
        SkLayer* child = m_children[i];
        SkASSERT(child->fParent == this);
<<<<<<< HEAD
        child->fParent = nullptr; // in case it has more than one owner
=======
        child->fParent = NULL;  // in case it has more than one owner
>>>>>>> miniblink49
        child->unref();
    }
    m_children.reset();
}

<<<<<<< HEAD
SkLayer* SkLayer::getRootLayer() const
{
    const SkLayer* root = this;
    while (root->fParent != nullptr) {
=======
SkLayer* SkLayer::getRootLayer() const {
    const SkLayer* root = this;
    while (root->fParent != NULL) {
>>>>>>> miniblink49
        root = root->fParent;
    }
    return const_cast<SkLayer*>(root);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkLayer::getLocalTransform(SkMatrix* matrix) const
{
=======
void SkLayer::getLocalTransform(SkMatrix* matrix) const {
>>>>>>> miniblink49
    matrix->setTranslate(m_position.fX, m_position.fY);

    SkScalar tx = SkScalarMul(m_anchorPoint.fX, m_size.width());
    SkScalar ty = SkScalarMul(m_anchorPoint.fY, m_size.height());
    matrix->preTranslate(tx, ty);
    matrix->preConcat(this->getMatrix());
    matrix->preTranslate(-tx, -ty);
}

<<<<<<< HEAD
void SkLayer::localToGlobal(SkMatrix* matrix) const
{
=======
void SkLayer::localToGlobal(SkMatrix* matrix) const {
>>>>>>> miniblink49
    this->getLocalTransform(matrix);

    if (this->isInheritFromRootTransform()) {
        matrix->postConcat(this->getRootLayer()->getMatrix());
        return;
    }

    const SkLayer* layer = this;
<<<<<<< HEAD
    while (layer->fParent != nullptr) {
=======
    while (layer->fParent != NULL) {
>>>>>>> miniblink49
        layer = layer->fParent;

        SkMatrix tmp;
        layer->getLocalTransform(&tmp);
        tmp.preConcat(layer->getChildrenMatrix());
        matrix->postConcat(tmp);
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkLayer::onDraw(SkCanvas*, SkScalar opacity)
{
    //    SkDebugf("----- no onDraw for %p\n", this);
=======
void SkLayer::onDraw(SkCanvas*, SkScalar opacity) {
//    SkDebugf("----- no onDraw for %p\n", this);
>>>>>>> miniblink49
}

#include "SkString.h"

<<<<<<< HEAD
void SkLayer::draw(SkCanvas* canvas, SkScalar opacity)
{
=======
void SkLayer::draw(SkCanvas* canvas, SkScalar opacity) {
>>>>>>> miniblink49
#if 0
    SkString str1, str2;
 //   this->getMatrix().toDumpString(&str1);
 //   this->getChildrenMatrix().toDumpString(&str2);
    SkDebugf("--- drawlayer %p opacity %g size [%g %g] pos [%g %g] matrix %s children %s\n",
             this, opacity * this->getOpacity(), m_size.width(), m_size.height(),
             m_position.fX, m_position.fY, str1.c_str(), str2.c_str());
#endif

    opacity = SkScalarMul(opacity, this->getOpacity());
    if (opacity <= 0) {
<<<<<<< HEAD
        //        SkDebugf("---- abort drawing %p opacity %g\n", this, opacity);
=======
//        SkDebugf("---- abort drawing %p opacity %g\n", this, opacity);
>>>>>>> miniblink49
        return;
    }

    SkAutoCanvasRestore acr(canvas, true);

    // apply our local transform
    {
        SkMatrix tmp;
        this->getLocalTransform(&tmp);
        if (this->isInheritFromRootTransform()) {
            // should we also apply the root's childrenMatrix?
            canvas->setMatrix(getRootLayer()->getMatrix());
        }
        canvas->concat(tmp);
    }

    this->onDraw(canvas, opacity);

#ifdef DEBUG_DRAW_LAYER_BOUNDS
    {
        SkRect r = SkRect::MakeSize(this->getSize());
        SkPaint p;
        p.setAntiAlias(true);
        p.setStyle(SkPaint::kStroke_Style);
        p.setStrokeWidth(SkIntToScalar(2));
        p.setColor(0xFFFF44DD);
        canvas->drawRect(r, p);
        canvas->drawLine(r.fLeft, r.fTop, r.fRight, r.fBottom, p);
        canvas->drawLine(r.fLeft, r.fBottom, r.fRight, r.fTop, p);
    }
#endif

    int count = this->countChildren();
    if (count > 0) {
        canvas->concat(this->getChildrenMatrix());
        for (int i = 0; i < count; i++) {
            this->getChild(i)->draw(canvas, opacity);
        }
    }
}

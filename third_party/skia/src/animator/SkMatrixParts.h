
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkMatrixParts_DEFINED
#define SkMatrixParts_DEFINED

#include "SkDisplayable.h"
#include "SkMemberInfo.h"
#include "SkPathMeasure.h"

class SkDrawPath;
class SkDrawRect;
class SkPolygon;

class SkDrawMatrix;
// class SkMatrix;

class SkMatrixPart : public SkDisplayable {
public:
    SkMatrixPart();
    virtual bool add() = 0;
    virtual void dirty();
    virtual SkDisplayable* getParent() const;
    virtual bool setParent(SkDisplayable* parent);
#ifdef SK_DEBUG
<<<<<<< HEAD
    virtual bool isMatrixPart() const
    {
        return true;
    }
=======
    virtual bool isMatrixPart() const { return true; }
>>>>>>> miniblink49
#endif
protected:
    SkDrawMatrix* fMatrix;
};

class SkRotate : public SkMatrixPart {
    DECLARE_MEMBER_INFO(Rotate);
    SkRotate();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    bool add() override;
    SkScalar degrees;
    SkPoint center;
};

class SkScale : public SkMatrixPart {
    DECLARE_MEMBER_INFO(Scale);
    SkScale();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    bool add() override;
    SkScalar x;
    SkScalar y;
    SkPoint center;
};

class SkSkew : public SkMatrixPart {
    DECLARE_MEMBER_INFO(Skew);
    SkSkew();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    bool add() override;
    SkScalar x;
    SkScalar y;
    SkPoint center;
};

class SkTranslate : public SkMatrixPart {
    DECLARE_MEMBER_INFO(Translate);
    SkTranslate();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    bool add() override;
    SkScalar x;
    SkScalar y;
};

class SkFromPath : public SkMatrixPart {
    DECLARE_MEMBER_INFO(FromPath);
    SkFromPath();
    virtual ~SkFromPath();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    bool add() override;
    int32_t mode;
    SkScalar offset;
    SkDrawPath* path;
    SkPathMeasure fPathMeasure;
};

class SkRectToRect : public SkMatrixPart {
    DECLARE_MEMBER_INFO(RectToRect);
    SkRectToRect();
    virtual ~SkRectToRect();
#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
    void dump(SkAnimateMaker*) override;
#endif
    const SkMemberInfo* preferredChild(SkDisplayTypes type) override;

=======
    void dump(SkAnimateMaker* ) override;
#endif
    const SkMemberInfo* preferredChild(SkDisplayTypes type) override;
>>>>>>> miniblink49
protected:
    bool add() override;
    SkDrawRect* source;
    SkDrawRect* destination;
};

class SkPolyToPoly : public SkMatrixPart {
    DECLARE_MEMBER_INFO(PolyToPoly);
    SkPolyToPoly();
    virtual ~SkPolyToPoly();
#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
    void dump(SkAnimateMaker*) override;
#endif
    void onEndElement(SkAnimateMaker&) override;
    const SkMemberInfo* preferredChild(SkDisplayTypes type) override;

=======
    void dump(SkAnimateMaker* ) override;
#endif
    void onEndElement(SkAnimateMaker& ) override;
    const SkMemberInfo* preferredChild(SkDisplayTypes type) override;
>>>>>>> miniblink49
protected:
    bool add() override;
    SkPolygon* source;
    SkPolygon* destination;
};

// !!! add concat matrix ?

#endif // SkMatrixParts_DEFINED

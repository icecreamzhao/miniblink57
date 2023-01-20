/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPaintPart_DEFINED
#define SkPaintPart_DEFINED

#include "SkDisplayable.h"
#include "SkMemberInfo.h"
#include "SkPaint.h"
#include "SkShader.h"
#include "SkTypeface.h"
#include "SkXfermode.h"

class SkDrawPaint;
class SkDrawMatrix;

class SkPaintPart : public SkDisplayable {
public:
    SkPaintPart();
    virtual bool add() = 0;
    virtual SkDisplayable* getParent() const;
    virtual bool setParent(SkDisplayable* parent);
#ifdef SK_DEBUG
<<<<<<< HEAD
    virtual bool isPaintPart() const
    {
        return true;
    }
=======
    virtual bool isPaintPart() const { return true; }
>>>>>>> miniblink49
#endif
protected:
    SkDrawPaint* fPaint;
};

class SkDrawMaskFilter : public SkPaintPart {
    DECLARE_EMPTY_MEMBER_INFO(MaskFilter);
    virtual SkMaskFilter* getMaskFilter();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    bool add() override;
};

class SkDrawPathEffect : public SkPaintPart {
    DECLARE_EMPTY_MEMBER_INFO(PathEffect);
    virtual SkPathEffect* getPathEffect();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    bool add() override;
};

class SkDrawShader : public SkPaintPart {
    DECLARE_DRAW_MEMBER_INFO(Shader);
    SkDrawShader();
    virtual SkShader* getShader();
<<<<<<< HEAD

protected:
    bool add() override;
    SkMatrix* getMatrix(); // returns nullptr if matrix is nullptr
=======
protected:
    bool add() override;
    SkMatrix* getMatrix(); // returns NULL if matrix is NULL
>>>>>>> miniblink49
    SkDrawMatrix* matrix;
    int /*SkShader::TileMode*/ tileMode;
};

<<<<<<< HEAD
class SkDrawTypeface : public SkPaintPart {
    DECLARE_DRAW_MEMBER_INFO(Typeface);
    SkDrawTypeface();
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
#endif
    sk_sp<SkTypeface> getTypeface()
    {
        return SkTypeface::MakeFromName(fontName.c_str(), style);
    }

=======
class SkDrawTypeface  : public SkPaintPart {
    DECLARE_DRAW_MEMBER_INFO(Typeface);
    SkDrawTypeface();
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker *) override;
#endif
    SkTypeface* getTypeface() {
        return SkTypeface::CreateFromName(fontName.c_str(), style); }
>>>>>>> miniblink49
protected:
    bool add() override;
    SkString fontName;
    SkTypeface::Style style;
};

#endif // SkPaintPart_DEFINED

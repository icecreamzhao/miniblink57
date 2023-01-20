
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkDraw3D_DEFINED
#define SkDraw3D_DEFINED

#include "SkADrawable.h"
#include "SkCamera.h"
=======

#ifndef SkDraw3D_DEFINED
#define SkDraw3D_DEFINED

#include "SkCamera.h"
#include "SkADrawable.h"
>>>>>>> miniblink49
#include "SkMemberInfo.h"

class Sk3D_Patch;

struct Sk3D_Point {
    DECLARE_NO_VIRTUALS_MEMBER_INFO(3D_Point);
    Sk3D_Point();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    SkPoint3D fPoint;
};

class Sk3D_Camera : public SkADrawable {
    DECLARE_MEMBER_INFO(3D_Camera);
    Sk3D_Camera();
    virtual ~Sk3D_Camera();
<<<<<<< HEAD
    bool draw(SkAnimateMaker&) override;

=======
    bool draw(SkAnimateMaker& ) override;
>>>>>>> miniblink49
private:
    SkScalar hackWidth;
    SkScalar hackHeight;
    SkCamera3D fCamera;
    Sk3D_Patch* patch;
};

class Sk3D_Patch : public SkDisplayable {
    DECLARE_MEMBER_INFO(3D_Patch);
<<<<<<< HEAD

private:
    void executeFunction(SkDisplayable*, int index,
        SkTDArray<SkScriptValue>& parameters, SkDisplayTypes type,
        SkScriptValue*) override;
    const SkFunctionParamType* getFunctionsParameters() override;
    SkPatch3D fPatch;
=======
private:
    void executeFunction(SkDisplayable* , int index,
        SkTDArray<SkScriptValue>& parameters, SkDisplayTypes type,
        SkScriptValue* ) override;
    const SkFunctionParamType* getFunctionsParameters() override;
    SkPatch3D  fPatch;
>>>>>>> miniblink49
    static const SkFunctionParamType fFunctionParameters[];
    friend class Sk3D_Camera;
};

#endif // SkDraw3D_DEFINED

/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkCornerPathEffect_DEFINED
#define SkCornerPathEffect_DEFINED

#include "SkPathEffect.h"

/** \class SkCornerPathEffect

    SkCornerPathEffect is a subclass of SkPathEffect that can turn sharp corners
    into various treatments (e.g. rounded corners)
*/
class SK_API SkCornerPathEffect : public SkPathEffect {
public:
    /** radius must be > 0 to have an effect. It specifies the distance from each corner
        that should be "rounded".
    */
<<<<<<< HEAD
    static sk_sp<SkPathEffect> Make(SkScalar radius)
    {
        return sk_sp<SkPathEffect>(new SkCornerPathEffect(radius));
    }

#ifdef SK_SUPPORT_LEGACY_PATHEFFECT_PTR
    static SkPathEffect* Create(SkScalar radius)
    {
        return Make(radius).release();
    }
#endif

    virtual bool filterPath(SkPath* dst, const SkPath& src,
        SkStrokeRec*, const SkRect*) const override;
=======
    static SkCornerPathEffect* Create(SkScalar radius) {
        return SkNEW_ARGS(SkCornerPathEffect, (radius));
    }
    virtual ~SkCornerPathEffect();

    virtual bool filterPath(SkPath* dst, const SkPath& src,
                            SkStrokeRec*, const SkRect*) const override;
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkCornerPathEffect)

#ifdef SK_BUILD_FOR_ANDROID_FRAMEWORK
<<<<<<< HEAD
    bool exposedInAndroidJavaAPI() const override
    {
        return true;
    }
#endif

protected:
    virtual ~SkCornerPathEffect();

=======
    bool exposedInAndroidJavaAPI() const override { return true; }
#endif

protected:
>>>>>>> miniblink49
    explicit SkCornerPathEffect(SkScalar radius);
    void flatten(SkWriteBuffer&) const override;

private:
<<<<<<< HEAD
    SkScalar fRadius;
=======
    SkScalar    fRadius;
>>>>>>> miniblink49

    typedef SkPathEffect INHERITED;
};

#endif

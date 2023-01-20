/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkLightingImageFilter.h"
#include "SkPoint3.h"

#define FILTER_WIDTH_SMALL SkIntToScalar(32)
#define FILTER_HEIGHT_SMALL SkIntToScalar(32)
#define FILTER_WIDTH_LARGE SkIntToScalar(256)
=======
#include "SkBitmapSource.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkLightingImageFilter.h"

#define FILTER_WIDTH_SMALL  SkIntToScalar(32)
#define FILTER_HEIGHT_SMALL SkIntToScalar(32)
#define FILTER_WIDTH_LARGE  SkIntToScalar(256)
>>>>>>> miniblink49
#define FILTER_HEIGHT_LARGE SkIntToScalar(256)

class LightingBaseBench : public Benchmark {
public:
<<<<<<< HEAD
    LightingBaseBench(bool small)
        : fIsSmall(small)
    {
    }

protected:
    void draw(int loops, SkCanvas* canvas, sk_sp<SkImageFilter> imageFilter) const
    {
        SkRect r = fIsSmall ? SkRect::MakeWH(FILTER_WIDTH_SMALL, FILTER_HEIGHT_SMALL) : SkRect::MakeWH(FILTER_WIDTH_LARGE, FILTER_HEIGHT_LARGE);
        SkPaint paint;
        paint.setImageFilter(std::move(imageFilter));
=======
    LightingBaseBench(bool small) : fIsSmall(small) { }

protected:
    void draw(const int loops, SkCanvas* canvas, SkImageFilter* imageFilter) const {
        SkRect r = fIsSmall ? SkRect::MakeWH(FILTER_WIDTH_SMALL, FILTER_HEIGHT_SMALL) :
                              SkRect::MakeWH(FILTER_WIDTH_LARGE, FILTER_HEIGHT_LARGE);
        SkPaint paint;
        paint.setImageFilter(imageFilter)->unref();
>>>>>>> miniblink49
        for (int i = 0; i < loops; i++) {
            canvas->drawRect(r, paint);
        }
    }

<<<<<<< HEAD
    static SkPoint3 GetPointLocation()
    {
        static SkPoint3 pointLocation = SkPoint3::Make(0, 0, SkIntToScalar(10));
        return pointLocation;
    }

    static SkPoint3 GetDistantDirection()
    {
        static SkScalar azimuthRad = SkDegreesToRadians(SkIntToScalar(225));
        static SkScalar elevationRad = SkDegreesToRadians(SkIntToScalar(5));
        static SkPoint3 distantDirection = SkPoint3::Make(SkScalarMul(SkScalarCos(azimuthRad),
                                                              SkScalarCos(elevationRad)),
            SkScalarMul(SkScalarSin(azimuthRad),
                SkScalarCos(elevationRad)),
            SkScalarSin(elevationRad));
        return distantDirection;
    }

    static SkPoint3 GetSpotLocation()
    {
        static SkPoint3 spotLocation = SkPoint3::Make(SkIntToScalar(-10),
            SkIntToScalar(-10),
            SkIntToScalar(20));
        return spotLocation;
    }

    static SkPoint3 GetSpotTarget()
    {
        static SkPoint3 spotTarget = SkPoint3::Make(SkIntToScalar(40), SkIntToScalar(40), 0);
        return spotTarget;
    }

    static SkScalar GetSpotExponent()
    {
=======
    static SkPoint3 getPointLocation() {
        static SkPoint3 pointLocation(0, 0, SkIntToScalar(10));
        return pointLocation;
    }

    static SkPoint3 getDistantDirection() {
        static SkScalar azimuthRad = SkDegreesToRadians(SkIntToScalar(225));
        static SkScalar elevationRad = SkDegreesToRadians(SkIntToScalar(5));
        static SkPoint3 distantDirection(SkScalarMul(SkScalarCos(azimuthRad),
                                                     SkScalarCos(elevationRad)),
                                         SkScalarMul(SkScalarSin(azimuthRad),
                                                     SkScalarCos(elevationRad)),
                                         SkScalarSin(elevationRad));
        return distantDirection;
    }

    static SkPoint3 getSpotLocation() {
        static SkPoint3 spotLocation(SkIntToScalar(-10), SkIntToScalar(-10), SkIntToScalar(20));
        return spotLocation;
    }

    static SkPoint3 getSpotTarget() {
        static SkPoint3 spotTarget(SkIntToScalar(40), SkIntToScalar(40), 0);
        return spotTarget;
    }

    static SkScalar getSpotExponent() {
>>>>>>> miniblink49
        static SkScalar spotExponent = SK_Scalar1;
        return spotExponent;
    }

<<<<<<< HEAD
    static SkScalar GetCutoffAngle()
    {
=======
    static SkScalar getCutoffAngle() {
>>>>>>> miniblink49
        static SkScalar cutoffAngle = SkIntToScalar(15);
        return cutoffAngle;
    }

<<<<<<< HEAD
    static SkScalar GetKd()
    {
=======
    static SkScalar getKd() {
>>>>>>> miniblink49
        static SkScalar kd = SkIntToScalar(2);
        return kd;
    }

<<<<<<< HEAD
    static SkScalar GetKs()
    {
=======
    static SkScalar getKs() {
>>>>>>> miniblink49
        static SkScalar ks = SkIntToScalar(1);
        return ks;
    }

<<<<<<< HEAD
    static SkScalar GetShininess()
    {
=======
    static SkScalar getShininess() {
>>>>>>> miniblink49
        static SkScalar shininess = SkIntToScalar(8);
        return shininess;
    }

<<<<<<< HEAD
    static SkScalar GetSurfaceScale()
    {
=======
    static SkScalar getSurfaceScale() {
>>>>>>> miniblink49
        static SkScalar surfaceScale = SkIntToScalar(1);
        return surfaceScale;
    }

<<<<<<< HEAD
    static SkColor GetWhite()
    {
=======
    static SkColor getWhite() {
>>>>>>> miniblink49
        static SkColor white(0xFFFFFFFF);
        return white;
    }

    bool fIsSmall;
    typedef Benchmark INHERITED;
};

class LightingPointLitDiffuseBench : public LightingBaseBench {
public:
<<<<<<< HEAD
    LightingPointLitDiffuseBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return fIsSmall ? "lightingpointlitdiffuse_small" : "lightingpointlitdiffuse_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        draw(loops, canvas, SkLightingImageFilter::MakePointLitDiffuse(GetPointLocation(), GetWhite(), GetSurfaceScale(), GetKd(), nullptr));
=======
    LightingPointLitDiffuseBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return fIsSmall ? "lightingpointlitdiffuse_small" : "lightingpointlitdiffuse_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        draw(loops, canvas, SkLightingImageFilter::CreatePointLitDiffuse(getPointLocation(),
                                                                         getWhite(),
                                                                         getSurfaceScale(),
                                                                         getKd()));
>>>>>>> miniblink49
    }

private:
    typedef LightingBaseBench INHERITED;
};

class LightingDistantLitDiffuseBench : public LightingBaseBench {
public:
<<<<<<< HEAD
    LightingDistantLitDiffuseBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return fIsSmall ? "lightingdistantlitdiffuse_small" : "lightingdistantlitdiffuse_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        draw(loops, canvas, SkLightingImageFilter::MakeDistantLitDiffuse(GetDistantDirection(), GetWhite(), GetSurfaceScale(), GetKd(), nullptr));
=======
    LightingDistantLitDiffuseBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return fIsSmall ? "lightingdistantlitdiffuse_small" : "lightingdistantlitdiffuse_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        draw(loops, canvas, SkLightingImageFilter::CreateDistantLitDiffuse(getDistantDirection(),
                                                                           getWhite(),
                                                                           getSurfaceScale(),
                                                                           getKd()));
>>>>>>> miniblink49
    }

private:
    typedef LightingBaseBench INHERITED;
};

class LightingSpotLitDiffuseBench : public LightingBaseBench {
public:
<<<<<<< HEAD
    LightingSpotLitDiffuseBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return fIsSmall ? "lightingspotlitdiffuse_small" : "lightingspotlitdiffuse_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        draw(loops, canvas, SkLightingImageFilter::MakeSpotLitDiffuse(GetSpotLocation(), GetSpotTarget(), GetSpotExponent(), GetCutoffAngle(), GetWhite(), GetSurfaceScale(), GetKd(), nullptr));
=======
    LightingSpotLitDiffuseBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return fIsSmall ? "lightingspotlitdiffuse_small" : "lightingspotlitdiffuse_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        draw(loops, canvas, SkLightingImageFilter::CreateSpotLitDiffuse(getSpotLocation(),
                                                                        getSpotTarget(),
                                                                        getSpotExponent(),
                                                                        getCutoffAngle(),
                                                                        getWhite(),
                                                                        getSurfaceScale(),
                                                                        getKd()));
>>>>>>> miniblink49
    }

private:
    typedef LightingBaseBench INHERITED;
};

class LightingPointLitSpecularBench : public LightingBaseBench {
public:
<<<<<<< HEAD
    LightingPointLitSpecularBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return fIsSmall ? "lightingpointlitspecular_small" : "lightingpointlitspecular_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        draw(loops, canvas, SkLightingImageFilter::MakePointLitSpecular(GetPointLocation(), GetWhite(), GetSurfaceScale(), GetKs(), GetShininess(), nullptr));
=======
    LightingPointLitSpecularBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return fIsSmall ? "lightingpointlitspecular_small" : "lightingpointlitspecular_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        draw(loops, canvas, SkLightingImageFilter::CreatePointLitSpecular(getPointLocation(),
                                                                          getWhite(),
                                                                          getSurfaceScale(),
                                                                          getKs(),
                                                                          getShininess()));
>>>>>>> miniblink49
    }

private:
    typedef LightingBaseBench INHERITED;
};

class LightingDistantLitSpecularBench : public LightingBaseBench {
public:
<<<<<<< HEAD
    LightingDistantLitSpecularBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return fIsSmall ? "lightingdistantlitspecular_small" : "lightingdistantlitspecular_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        draw(loops, canvas, SkLightingImageFilter::MakeDistantLitSpecular(GetDistantDirection(), GetWhite(), GetSurfaceScale(), GetKs(), GetShininess(), nullptr));
=======
    LightingDistantLitSpecularBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return fIsSmall ? "lightingdistantlitspecular_small" : "lightingdistantlitspecular_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        draw(loops, canvas, SkLightingImageFilter::CreateDistantLitSpecular(getDistantDirection(),
                                                                            getWhite(),
                                                                            getSurfaceScale(),
                                                                            getKs(),
                                                                            getShininess()));
>>>>>>> miniblink49
    }

private:
    typedef LightingBaseBench INHERITED;
};

class LightingSpotLitSpecularBench : public LightingBaseBench {
public:
<<<<<<< HEAD
    LightingSpotLitSpecularBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return fIsSmall ? "lightingspotlitspecular_small" : "lightingspotlitspecular_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        draw(loops, canvas, SkLightingImageFilter::MakeSpotLitSpecular(GetSpotLocation(), GetSpotTarget(), GetSpotExponent(), GetCutoffAngle(), GetWhite(), GetSurfaceScale(), GetKs(), GetShininess(), nullptr));
=======
    LightingSpotLitSpecularBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return fIsSmall ? "lightingspotlitspecular_small" : "lightingspotlitspecular_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        draw(loops, canvas, SkLightingImageFilter::CreateSpotLitSpecular(getSpotLocation(),
                                                                         getSpotTarget(),
                                                                         getSpotExponent(),
                                                                         getCutoffAngle(),
                                                                         getWhite(),
                                                                         getSurfaceScale(),
                                                                         getKs(),
                                                                         getShininess()));
>>>>>>> miniblink49
    }

private:
    typedef LightingBaseBench INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new LightingPointLitDiffuseBench(true);)
DEF_BENCH(return new LightingPointLitDiffuseBench(false);)
DEF_BENCH(return new LightingDistantLitDiffuseBench(true);)
DEF_BENCH(return new LightingDistantLitDiffuseBench(false);)
DEF_BENCH(return new LightingSpotLitDiffuseBench(true);)
DEF_BENCH(return new LightingSpotLitDiffuseBench(false);)
DEF_BENCH(return new LightingPointLitSpecularBench(true);)
DEF_BENCH(return new LightingPointLitSpecularBench(false);)
DEF_BENCH(return new LightingDistantLitSpecularBench(true);)
DEF_BENCH(return new LightingDistantLitSpecularBench(false);)
DEF_BENCH(return new LightingSpotLitSpecularBench(true);)
DEF_BENCH(return new LightingSpotLitSpecularBench(false);)
=======
DEF_BENCH( return new LightingPointLitDiffuseBench(true); )
DEF_BENCH( return new LightingPointLitDiffuseBench(false); )
DEF_BENCH( return new LightingDistantLitDiffuseBench(true); )
DEF_BENCH( return new LightingDistantLitDiffuseBench(false); )
DEF_BENCH( return new LightingSpotLitDiffuseBench(true); )
DEF_BENCH( return new LightingSpotLitDiffuseBench(false); )
DEF_BENCH( return new LightingPointLitSpecularBench(true); )
DEF_BENCH( return new LightingPointLitSpecularBench(false); )
DEF_BENCH( return new LightingDistantLitSpecularBench(true); )
DEF_BENCH( return new LightingDistantLitSpecularBench(false); )
DEF_BENCH( return new LightingSpotLitSpecularBench(true); )
DEF_BENCH( return new LightingSpotLitSpecularBench(false); )
>>>>>>> miniblink49

/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkPaint.h"
#include "SkPatchUtils.h"
#include "SkString.h"

/**
<<<<<<< HEAD
 * This bench measures the rendering time of the call SkCanvas::drawPatch with different types of
 * input patches (regular case, with loops, a square, with a big difference between "parallel"
 * sides). This bench also tests the different combination of optional parameters for the function
 * (passing texture coordinates and colors, only textures coordinates, only colors or none).
 * Finally, it applies a scale to test if the size affects the rendering time.
=======
 * This bench measures the rendering time of the call SkCanvas::drawPatch with different types of 
 * input patches (regular case, with loops, a square, with a big difference between "parallel" 
 * sides). This bench also tests the different combination of optional parameters for the function 
 * (passing texture coordinates and colors, only textures coordinates, only colors or none).
 * Finally, it applies a scale to test if the size affects the rendering time. 
>>>>>>> miniblink49
 */

class PatchBench : public Benchmark {

public:
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    enum VertexMode {
        kNone_VertexMode,
        kColors_VertexMode,
        kTexCoords_VertexMode,
        kBoth_VertexMode
    };

    PatchBench(SkPoint scale, VertexMode vertexMode)
<<<<<<< HEAD
        : fScale(scale)
        , fVertexMode(vertexMode)
    {
    }

    // to add name of specific class override this method
    virtual void appendName(SkString* name)
    {
=======
    : fScale(scale)
    , fVertexMode(vertexMode) { }

    // to add name of specific class override this method
    virtual void appendName(SkString* name) {
>>>>>>> miniblink49
        name->append("normal");
    }

    // to make other type of patches override this method
<<<<<<< HEAD
    virtual void setCubics()
    {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            { 100, 100 }, { 150, 50 }, { 250, 150 }, { 300, 100 },
            //right points
            { 350, 150 }, { 250, 200 },
            //bottom points
            { 300, 300 }, { 250, 250 }, { 150, 350 }, { 100, 300 },
            //left points
            { 50, 250 }, { 150, 50 }
=======
    virtual void setCubics() {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            {100,100},{150,50},{250,150}, {300,100},
            //right points
            {350, 150},{250,200},
            //bottom points
            {300,300},{250,250},{150,350},{100,300},
            //left points
            {50,250},{150,50}
>>>>>>> miniblink49
        };
        memcpy(fCubics, points, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
    }

<<<<<<< HEAD
    virtual void setColors()
    {
=======
    virtual void setColors() {
>>>>>>> miniblink49
        const SkColor colors[SkPatchUtils::kNumCorners] = {
            SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorCYAN
        };
        memcpy(fColors, colors, SkPatchUtils::kNumCorners * sizeof(SkColor));
    }

<<<<<<< HEAD
    virtual void setTexCoords()
    {
        const SkPoint texCoords[SkPatchUtils::kNumCorners] = {
            { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f }
=======
    virtual void setTexCoords() {
        const SkPoint texCoords[SkPatchUtils::kNumCorners] = {
            {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f,1.0f}, {0.0f, 1.0f}
>>>>>>> miniblink49
        };
        memcpy(fTexCoords, texCoords, SkPatchUtils::kNumCorners * sizeof(SkPoint));
    }

    // override this method to change the shader
<<<<<<< HEAD
    virtual sk_sp<SkShader> createShader()
    {
        const SkColor colors[] = {
            SK_ColorRED,
            SK_ColorCYAN,
            SK_ColorGREEN,
            SK_ColorWHITE,
            SK_ColorMAGENTA,
            SK_ColorBLUE,
            SK_ColorYELLOW,
        };
        const SkPoint pts[] = { { 200.f / 4.f, 0.f }, { 3.f * 200.f / 4, 200.f } };

        return SkGradientShader::MakeLinear(pts, colors, nullptr, SK_ARRAY_COUNT(colors),
            SkShader::kMirror_TileMode);
    }

protected:
    const char* onGetName() override
    {
        SkString vertexMode;
        switch (fVertexMode) {
        case kNone_VertexMode:
            vertexMode.set("meshlines");
            break;
        case kColors_VertexMode:
            vertexMode.set("colors");
            break;
        case kTexCoords_VertexMode:
            vertexMode.set("texs");
            break;
        case kBoth_VertexMode:
            vertexMode.set("colors_texs");
            break;
        default:
            break;
=======
    virtual SkShader* createShader() {
        const SkColor colors[] = {
            SK_ColorRED, SK_ColorCYAN, SK_ColorGREEN, SK_ColorWHITE,
            SK_ColorMAGENTA, SK_ColorBLUE, SK_ColorYELLOW,
        };
        const SkPoint pts[] = { { 200.f / 4.f, 0.f }, { 3.f * 200.f / 4, 200.f } };

        return SkGradientShader::CreateLinear(pts, colors, NULL,
                                              SK_ARRAY_COUNT(colors),
                                              SkShader::kMirror_TileMode);
    }

protected:
    const char* onGetName() override {
        SkString vertexMode;
        switch (fVertexMode) {
            case kNone_VertexMode:
                vertexMode.set("meshlines");
                break;
            case kColors_VertexMode:
                vertexMode.set("colors");
                break;
            case kTexCoords_VertexMode:
                vertexMode.set("texs");
                break;
            case kBoth_VertexMode:
                vertexMode.set("colors_texs");
                break;
            default:
                break;
>>>>>>> miniblink49
        }
        SkString type;
        this->appendName(&type);
        fName.printf("patch_%s_%s_[%f,%f]", type.c_str(), vertexMode.c_str(),
<<<<<<< HEAD
            fScale.x(), fScale.y());
        return fName.c_str();
    }

    void onDelayedSetup() override
    {
=======
                    fScale.x(), fScale.y());
        return fName.c_str();
    }

    void onPreDraw() override {
>>>>>>> miniblink49
        this->setCubics();
        this->setColors();
        this->setTexCoords();
        this->setupPaint(&fPaint);
        switch (fVertexMode) {
<<<<<<< HEAD
        case kTexCoords_VertexMode:
        case kBoth_VertexMode:
            fPaint.setShader(this->createShader());
            break;
        default:
            fPaint.setShader(nullptr);
            break;
        }
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        canvas->scale(fScale.x(), fScale.y());
        for (int i = 0; i < loops; i++) {
            switch (fVertexMode) {
            case kNone_VertexMode:
                canvas->drawPatch(fCubics, nullptr, nullptr, nullptr, fPaint);
                break;
            case kColors_VertexMode:
                canvas->drawPatch(fCubics, fColors, nullptr, nullptr, fPaint);
                break;
            case kTexCoords_VertexMode:
                canvas->drawPatch(fCubics, nullptr, fTexCoords, nullptr, fPaint);
                break;
            case kBoth_VertexMode:
                canvas->drawPatch(fCubics, fColors, fTexCoords, nullptr, fPaint);
                break;
            default:
                break;
=======
            case kTexCoords_VertexMode:
            case kBoth_VertexMode:
                fPaint.setShader(this->createShader())->unref();
                break;
            default:
                fPaint.setShader(NULL);
                break;
        }
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        canvas->scale(fScale.x(), fScale.y());
        for (int i = 0; i < loops; i++) {
            switch (fVertexMode) {
                case kNone_VertexMode:
                    canvas->drawPatch(fCubics, NULL, NULL, NULL, fPaint);
                    break;
                case kColors_VertexMode:
                    canvas->drawPatch(fCubics, fColors, NULL, NULL, fPaint);
                    break;
                case kTexCoords_VertexMode:
                    canvas->drawPatch(fCubics, NULL, fTexCoords, NULL, fPaint);
                    break;
                case kBoth_VertexMode:
                    canvas->drawPatch(fCubics, fColors, fTexCoords, NULL, fPaint);
                    break;
                default:
                    break;
>>>>>>> miniblink49
            }
        }
    }

<<<<<<< HEAD
    SkPaint fPaint;
    SkString fName;
    SkVector fScale;
    SkPoint fCubics[12];
    SkPoint fTexCoords[4];
    SkColor fColors[4];
    VertexMode fVertexMode;
=======
    SkPaint     fPaint;
    SkString    fName;
    SkVector    fScale;
    SkPoint     fCubics[12];
    SkPoint     fTexCoords[4];
    SkColor     fColors[4];
    VertexMode  fVertexMode;
>>>>>>> miniblink49

    typedef Benchmark INHERITED;
};

class SquarePatchBench : public PatchBench {
public:
    SquarePatchBench(SkPoint scale, VertexMode vertexMode)
<<<<<<< HEAD
        : INHERITED(scale, vertexMode)
    {
    }

    void appendName(SkString* name) override
    {
        name->append("square");
    }

    void setCubics() override
    {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            { 100, 100 }, { 150, 100 }, { 250, 100 }, { 300, 100 },
            //right points
            { 300, 150 }, { 300, 250 },
            //bottom points
            { 300, 300 }, { 250, 300 }, { 150, 300 }, { 100, 300 },
            //left points
            { 100, 250 }, { 100, 150 }
        };
        memcpy(fCubics, points, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
    }

=======
    : INHERITED(scale, vertexMode) { }

    void appendName(SkString* name) override {
        name->append("square");
    }

    void setCubics() override {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            {100,100},{150,100},{250,100}, {300,100},
            //right points
            {300, 150},{300,250},
            //bottom points
            {300,300},{250,300},{150,300},{100,300},
            //left points
            {100,250},{100,150}
        };
        memcpy(fCubics, points, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
    }
>>>>>>> miniblink49
private:
    typedef PatchBench INHERITED;
};

class LODDiffPatchBench : public PatchBench {
public:
    LODDiffPatchBench(SkPoint scale, VertexMode vertexMode)
<<<<<<< HEAD
        : INHERITED(scale, vertexMode)
    {
    }

    void appendName(SkString* name) override
    {
        name->append("LOD_Diff");
    }

    void setCubics() override
    {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            { 100, 175 }, { 150, 100 }, { 250, 100 }, { 300, 0 },
            //right points
            { 300, 150 }, { 300, 250 },
            //bottom points
            { 300, 400 }, { 250, 300 }, { 150, 300 }, { 100, 225 },
            //left points
            { 100, 215 }, { 100, 185 }
        };
        memcpy(fCubics, points, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
    }

=======
    : INHERITED(scale, vertexMode) { }

    void appendName(SkString* name) override {
        name->append("LOD_Diff");
    }

    void setCubics() override {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            {100,175},{150,100},{250,100}, {300,0},
            //right points
            {300, 150},{300,250},
            //bottom points
            {300,400},{250,300},{150,300},{100,225},
            //left points
            {100,215},{100,185}
        };
        memcpy(fCubics, points, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
    }
>>>>>>> miniblink49
private:
    typedef PatchBench INHERITED;
};

class LoopPatchBench : public PatchBench {
public:
    LoopPatchBench(SkPoint scale, VertexMode vertexMode)
<<<<<<< HEAD
        : INHERITED(scale, vertexMode)
    {
    }

    void appendName(SkString* name) override
    {
        name->append("loop");
    }

    void setCubics() override
    {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            { 100, 100 }, { 300, 200 }, { 100, 200 }, { 300, 100 },
            //right points
            { 380, 400 }, { 380, 0 },
            //bottom points
            { 300, 300 }, { 250, 250 }, { 30, 200 }, { 100, 300 },
            //left points
            { 140, 325 }, { 150, 150 }
        };
        memcpy(fCubics, points, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
    }

=======
    : INHERITED(scale, vertexMode) { }

    void appendName(SkString* name) override {
        name->append("loop");
    }

    void setCubics() override {
        const SkPoint points[SkPatchUtils::kNumCtrlPts] = {
            //top points
            {100,100},{300,200},{100,200}, {300,100},
            //right points
            {380, 400},{380,0},
            //bottom points
            {300,300},{250,250},{30,200},{100,300},
            //left points
            {140,325},{150,150}
        };
        memcpy(fCubics, points, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
    }
>>>>>>> miniblink49
private:
    typedef PatchBench INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kNone_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kColors_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(1.f, 1.0f), PatchBench::kNone_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(1.0f, 1.0f), PatchBench::kColors_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(1.0f, 1.0f), PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(1.0f, 1.0f), PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kNone_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kColors_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kBoth_VertexMode);)

DEF_BENCH(return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(1.f, 1.0f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kBoth_VertexMode);)

DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(1.f, 1.0f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kBoth_VertexMode);)

DEF_BENCH(return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
    PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(1.f, 1.0f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(1.0f, 1.0f),
    PatchBench::kBoth_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kNone_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kColors_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kTexCoords_VertexMode);)
DEF_BENCH(return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
    PatchBench::kBoth_VertexMode);)
=======
DEF_BENCH( return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kNone_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kColors_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(0.1f, 0.1f), PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(1.f, 1.0f), PatchBench::kNone_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(1.0f, 1.0f), PatchBench::kColors_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(1.0f, 1.0f), PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(1.0f, 1.0f), PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kNone_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kColors_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new PatchBench(SkVector::Make(3.0f, 3.0f), PatchBench::kBoth_VertexMode); )

DEF_BENCH( return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kNone_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kColors_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(1.f, 1.0f),
                                       PatchBench::kNone_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(1.0f, 1.0f),
                                       PatchBench::kColors_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(1.0f, 1.0f),
                                       PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(1.0f, 1.0f),
                                       PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kNone_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kColors_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new SquarePatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kBoth_VertexMode); )

DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kNone_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kColors_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(0.1f, 0.1f),
                                       PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(1.f, 1.0f),
                                       PatchBench::kNone_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(1.0f, 1.0f),
                                       PatchBench::kColors_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(1.0f, 1.0f),
                                       PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(1.0f, 1.0f),
                                       PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kNone_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kColors_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new LODDiffPatchBench(SkVector::Make(3.0f, 3.0f),
                                       PatchBench::kBoth_VertexMode); )

DEF_BENCH( return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
                                        PatchBench::kNone_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
                                        PatchBench::kColors_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
                                        PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(0.1f, 0.1f),
                                        PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(1.f, 1.0f),
                                        PatchBench::kNone_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(1.0f, 1.0f),
                                        PatchBench::kColors_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(1.0f, 1.0f),
                                        PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(1.0f, 1.0f),
                                        PatchBench::kBoth_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
                                        PatchBench::kNone_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
                                        PatchBench::kColors_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
                                        PatchBench::kTexCoords_VertexMode); )
DEF_BENCH( return new LoopPatchBench(SkVector::Make(3.0f, 3.0f),
                                        PatchBench::kBoth_VertexMode); )
>>>>>>> miniblink49

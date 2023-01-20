<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gm.h"
#if SK_SUPPORT_GPU
<<<<<<< HEAD
#include "GrCoordTransform.h"
#include "GrFragmentProcessor.h"
#include "GrInvariantOutput.h"
=======
#include "GrFragmentProcessor.h"
#include "GrCoordTransform.h"
#include "gl/GrGLProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"
>>>>>>> miniblink49
#include "Resources.h"
#include "SkReadBuffer.h"
#include "SkShader.h"
#include "SkStream.h"
#include "SkTypeface.h"
#include "SkWriteBuffer.h"
<<<<<<< HEAD
#include "effects/GrXfermodeFragmentProcessor.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
=======
>>>>>>> miniblink49

namespace skiagm {

///////////////////////////////////////////////////////////////////////////////

class DCShader : public SkShader {
public:
<<<<<<< HEAD
    DCShader(const SkMatrix& matrix)
        : fDeviceMatrix(matrix)
    {
    }

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(DCShader);

    void flatten(SkWriteBuffer& buf) const override
    {
        buf.writeMatrix(fDeviceMatrix);
    }

    sk_sp<GrFragmentProcessor> asFragmentProcessor(GrContext*,
        const SkMatrix& viewM,
        const SkMatrix* localMatrix,
        SkFilterQuality,
        SkSourceGammaTreatment) const override;

#ifndef SK_IGNORE_TO_STRING
    void toString(SkString* str) const override
    {
=======
    DCShader(const SkMatrix& matrix) : fDeviceMatrix(matrix) {}

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(DCShader);

    void flatten(SkWriteBuffer& buf) const override {
        buf.writeMatrix(fDeviceMatrix);
    }

    bool asFragmentProcessor(GrContext*, const SkPaint& paint, const SkMatrix& viewM,
                             const SkMatrix* localMatrix, GrColor* color, GrProcessorDataManager*,
                             GrFragmentProcessor** fp) const override;

#ifndef SK_IGNORE_TO_STRING
    void toString(SkString* str) const override {
>>>>>>> miniblink49
        str->appendf("DCShader: ()");
    }
#endif

private:
    const SkMatrix fDeviceMatrix;
};

<<<<<<< HEAD
sk_sp<SkFlattenable> DCShader::CreateProc(SkReadBuffer& buf)
{
    SkMatrix matrix;
    buf.readMatrix(&matrix);
    return sk_make_sp<DCShader>(matrix);
=======
SkFlattenable* DCShader::CreateProc(SkReadBuffer& buf) {
    SkMatrix matrix;
    buf.readMatrix(&matrix);
    return SkNEW_ARGS(DCShader, (matrix));
>>>>>>> miniblink49
}

class DCFP : public GrFragmentProcessor {
public:
<<<<<<< HEAD
    DCFP(const SkMatrix& m)
        : fDeviceTransform(kDevice_GrCoordSet, m)
    {
=======
    DCFP(GrProcessorDataManager*, const SkMatrix& m) : fDeviceTransform(kDevice_GrCoordSet, m) {
>>>>>>> miniblink49
        this->addCoordTransform(&fDeviceTransform);
        this->initClassID<DCFP>();
    }

<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override
    {
        class DCGLFP : public GrGLSLFragmentProcessor {
            void emitCode(EmitArgs& args) override
            {
                GrGLSLFragmentBuilder* fragBuilder = args.fFragBuilder;
                fragBuilder->codeAppendf("vec2 c = %s;",
                    fragBuilder->ensureFSCoords2D(args.fCoords, 0).c_str());
                fragBuilder->codeAppend("vec2 r = mod(c, vec2(20.0));");
                fragBuilder->codeAppend("vec4 color = vec4(0.5*sin(c.x / 15.0) + 0.5,"
                                        "0.5*cos((c.x + c.y) / 15.0) + 0.5,"
                                        "(r.x + r.y) / 20.0,"
                                        "distance(r, vec2(15.0)) / 20.0 + 0.2);");
                fragBuilder->codeAppendf("color.rgb *= color.a;"
                                         "%s = color * %s;",
                    args.fOutputColor, GrGLSLExpr4(args.fInputColor).c_str());
            }
            void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override { }
        };
        return new DCGLFP;
=======
    void getGLProcessorKey(const GrGLSLCaps& caps,
                            GrProcessorKeyBuilder* b) const override {}

    GrGLFragmentProcessor* createGLInstance() const override {
        class DCGLFP : public GrGLFragmentProcessor {
            void emitCode(GrGLFPBuilder* builder,
                            const GrFragmentProcessor& fp,
                            const char* outputColor,
                            const char* inputColor,
                            const TransformedCoordsArray& coords,
                            const TextureSamplerArray& samplers) {
                GrGLFragmentBuilder* fpb = builder->getFragmentShaderBuilder();
                fpb->codeAppendf("vec2 c = %s;", fpb->ensureFSCoords2D(coords, 0).c_str());
                fpb->codeAppend("vec2 r = mod(c, vec2(20.0));");
                fpb->codeAppend("vec4 color = vec4(0.5*sin(c.x / 15.0) + 0.5,"
                                                    "0.5*cos((c.x + c.y) / 15.0) + 0.5,"
                                                    "(r.x + r.y) / 20.0,"
                                                    "distance(r, vec2(15.0)) / 20.0 + 0.2);");
                fpb->codeAppendf("color.rgb *= color.a;"
                                    "%s = color * %s;",
                                    outputColor, GrGLSLExpr4(inputColor).c_str());
            }
            void setData(const GrGLProgramDataManager&, const GrProcessor&) override {}
        };
        return SkNEW(DCGLFP);
>>>>>>> miniblink49
    }

    const char* name() const override { return "DCFP"; }

<<<<<<< HEAD
    void onComputeInvariantOutput(GrInvariantOutput* inout) const override
    {
=======
    void onComputeInvariantOutput(GrInvariantOutput* inout) const override {
>>>>>>> miniblink49
        inout->mulByUnknownFourComponents();
    }

private:
<<<<<<< HEAD
    void onGetGLSLProcessorKey(const GrGLSLCaps& caps,
        GrProcessorKeyBuilder* b) const override { }

=======
>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override { return true; }

    GrCoordTransform fDeviceTransform;
};

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> DCShader::asFragmentProcessor(GrContext*,
    const SkMatrix& viewM,
    const SkMatrix* localMatrix,
    SkFilterQuality,
    SkSourceGammaTreatment) const
{
    sk_sp<GrFragmentProcessor> inner(new DCFP(fDeviceMatrix));
    return GrFragmentProcessor::MulOutputByInputAlpha(std::move(inner));
=======
bool DCShader::asFragmentProcessor(GrContext*, const SkPaint& paint, const SkMatrix& viewM,
                                   const SkMatrix* localMatrix, GrColor* color,
                                   GrProcessorDataManager* procDataManager,
                                   GrFragmentProcessor** fp) const {
    *fp = SkNEW_ARGS(DCFP, (procDataManager, fDeviceMatrix));
    *color = GrColorPackA4(paint.getAlpha());
    return true;
>>>>>>> miniblink49
}

class DCShaderGM : public GM {
public:
<<<<<<< HEAD
    DCShaderGM()
    {
        this->setBGColor(sk_tool_utils::color_to_565(0xFFAABBCC));
    }

    ~DCShaderGM() override
    {
        for (int i = 0; i < fPrims.count(); ++i) {
            delete fPrims[i];
=======
    DCShaderGM() {
        this->setBGColor(sk_tool_utils::color_to_565(0xFFAABBCC));
    }

    ~DCShaderGM() override {
        for (int i = 0; i < fPrims.count(); ++i) {
            SkDELETE(fPrims[i]);
>>>>>>> miniblink49
        }
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
=======

    SkString onShortName() override {
>>>>>>> miniblink49
        return SkString("dcshader");
    }

    SkISize onISize() override { return SkISize::Make(1000, 900); }

<<<<<<< HEAD
    void onOnceBeforeDraw() override
    {
        struct Rect : public Prim {
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override
            {
=======
    void onOnceBeforeDraw() override {
        struct Rect : public Prim {
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override {
>>>>>>> miniblink49
                SkRect rect = SkRect::MakeXYWH(0, 0, 50, 50);
                canvas->drawRect(rect, paint);
                return rect;
            }
        };

        struct Circle : public Prim {
<<<<<<< HEAD
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override
            {
=======
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override {
>>>>>>> miniblink49
                static const SkScalar radius = 25;
                canvas->drawCircle(radius, radius, radius, paint);
                return SkRect::MakeXYWH(0, 0, 2 * radius, 2 * radius);
            }
        };

        struct RRect : public Prim {
<<<<<<< HEAD
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override
            {
=======
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override {
>>>>>>> miniblink49
                SkRRect rrect;
                rrect.setRectXY(SkRect::MakeXYWH(0, 0, 50, 50), 10, 10);
                canvas->drawRRect(rrect, paint);
                return rrect.getBounds();
            }
        };

        struct DRRect : public Prim {
<<<<<<< HEAD
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override
            {
=======
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override {
>>>>>>> miniblink49
                SkRRect outerRRect;
                outerRRect.setRectXY(SkRect::MakeXYWH(0, 0, 50, 50), 5, 5);
                SkRRect innerRRect;
                innerRRect.setRectXY(SkRect::MakeXYWH(5, 8, 35, 30), 8, 3);
                canvas->drawDRRect(outerRRect, innerRRect, paint);
                return outerRRect.getBounds();
            }
        };
        struct Path : public Prim {
<<<<<<< HEAD
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override
            {
=======
            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override {
>>>>>>> miniblink49
                SkPath path;
                path.addCircle(15, 15, 10);
                path.addOval(SkRect::MakeXYWH(2, 2, 22, 37));
                path.setFillType(SkPath::kEvenOdd_FillType);
                canvas->drawPath(path, paint);
                return path.getBounds();
            }
        };

        struct Points : public Prim {
<<<<<<< HEAD
            Points(SkCanvas::PointMode mode)
                : fMode(mode)
            {
            }

            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override
            {
=======
            Points(SkCanvas::PointMode mode) : fMode(mode) {}

            SkRect draw(SkCanvas* canvas, const SkPaint& paint) override {
>>>>>>> miniblink49
                SkRandom random;
                SkPoint points[500];
                SkRect bounds = SkRect::MakeWH(50, 50);
                int count = SkToInt(SK_ARRAY_COUNT(points));
                if (SkCanvas::kPoints_PointMode != fMode) {
                    count = SkTMin(count, 10);
                }
                for (int p = 0; p < count; ++p) {
                    points[p].fX = random.nextUScalar1() * bounds.width();
                    points[p].fY = random.nextUScalar1() * bounds.width();
                }
                canvas->drawPoints(fMode, count, points, paint);
                return bounds;
            }
            SkCanvas::PointMode fMode;
        };

        struct Text : public Prim {
<<<<<<< HEAD
            SkRect draw(SkCanvas* canvas, const SkPaint& origPaint) override
            {
=======
            SkRect draw(SkCanvas* canvas, const SkPaint& origPaint) override {
>>>>>>> miniblink49
                SkPaint paint = origPaint;
                paint.setTextSize(30.f);
                this->setFont(&paint);
                const char* text = this->text();
                static const SkVector offset = SkVector::Make(10, 10);
                canvas->drawText(text, strlen(text), offset.fX, offset.fY, paint);
                SkRect bounds;
                paint.measureText(text, strlen(text), &bounds);
                bounds.offset(offset);
                return bounds;
            }

<<<<<<< HEAD
            virtual void setFont(SkPaint* paint)
            {
                sk_tool_utils::set_portable_typeface(paint);
=======
            virtual void setFont(SkPaint* paint) {
                sk_tool_utils::set_portable_typeface_always(paint);
>>>>>>> miniblink49
            }

            virtual const char* text() const { return "Hello, Skia!"; }
        };

<<<<<<< HEAD
        fPrims.push_back(new Rect);
        fPrims.push_back(new Circle);
        fPrims.push_back(new RRect);
        fPrims.push_back(new DRRect);
        fPrims.push_back(new Path);
        fPrims.push_back(new Points(SkCanvas::kPoints_PointMode));
        fPrims.push_back(new Points(SkCanvas::kLines_PointMode));
        fPrims.push_back(new Points(SkCanvas::kPolygon_PointMode));
        fPrims.push_back(new Text);
    }

    void onDraw(SkCanvas* canvas) override
    {
        // This GM exists to test a specific feature of the GPU backend. It does not work with the
        // sw rasterizer, tile modes, etc.
        if (nullptr == canvas->getGrContext()) {
            skiagm::GM::DrawGpuOnlyMessage(canvas);
=======
        struct BmpText : public Text {
           void setFont(SkPaint* paint) override {
               if (!fTypeface) {
                    fTypeface.reset(GetResourceAsTypeface("/fonts/Funkster.ttf"));
               }
               paint->setTypeface(fTypeface);
            }

            const char* text() const override { return "Hi, Skia!"; }

            SkAutoTUnref<SkTypeface> fTypeface;
        };
        fPrims.push_back(SkNEW(Rect));
        fPrims.push_back(SkNEW(Circle));
        fPrims.push_back(SkNEW(RRect));
        fPrims.push_back(SkNEW(DRRect));
        fPrims.push_back(SkNEW(Path));
        fPrims.push_back(SkNEW(Points(SkCanvas::kPoints_PointMode)));
        fPrims.push_back(SkNEW(Points(SkCanvas::kLines_PointMode)));
        fPrims.push_back(SkNEW(Points(SkCanvas::kPolygon_PointMode)));
        fPrims.push_back(SkNEW(Text));
        fPrims.push_back(SkNEW(BmpText));
    }

    void onDraw(SkCanvas* canvas) override {
        // This GM exists to test a specific feature of the GPU backend. It does not work with the
        // sw rasterizer, tile modes, etc.
        if (NULL == canvas->getGrContext()) {
            this->drawGpuOnlyMessage(canvas);
>>>>>>> miniblink49
            return;
        }
        SkPaint paint;
        SkTArray<SkMatrix> devMats;
        devMats.push_back().reset();
        devMats.push_back().setRotate(45, 500, 500);
        devMats.push_back().setRotate(-30, 200, 200);
        devMats.back().setPerspX(-SK_Scalar1 / 2000);
        devMats.back().setPerspY(SK_Scalar1 / 1000);

<<<<<<< HEAD
=======

>>>>>>> miniblink49
        SkTArray<SkMatrix> viewMats;
        viewMats.push_back().setScale(0.75f, 0.75f);
        viewMats.push_back().setRotate(45, 50, 50);
        viewMats.back().postScale(0.5f, 1.1f);

        canvas->translate(10, 20);
        canvas->save();
        SkScalar tx = 0, maxTy = 0;
        static const SkScalar kW = 900;

        for (int aa = 0; aa < 2; ++aa) {
            for (int i = 0; i < fPrims.count(); ++i) {
                for (int j = 0; j < devMats.count(); ++j) {
                    for (int k = 0; k < viewMats.count(); ++k) {
<<<<<<< HEAD
                        paint.setShader(sk_make_sp<DCShader>(devMats[j]));
=======
                        paint.setShader(SkNEW_ARGS(DCShader, (devMats[j])))->unref();
>>>>>>> miniblink49
                        paint.setAntiAlias(SkToBool(aa));
                        canvas->save();
                        canvas->concat(viewMats[k]);
                        SkRect bounds = fPrims[i]->draw(canvas, paint);
                        canvas->restore();
                        viewMats[k].mapRect(&bounds);
                        // add margins
                        bounds.fRight += 20;
                        bounds.fBottom += 20;
                        canvas->translate(bounds.fRight, 0);
                        tx += bounds.fRight;
                        maxTy = SkTMax(bounds.fBottom, maxTy);
                        if (tx > kW) {
                            tx = 0;
                            canvas->restore();
                            canvas->translate(0, maxTy);
                            canvas->save();
                            maxTy = 0;
                        }
                    }
                }
            }
        }
        canvas->restore();
    }

private:
    struct Prim {
<<<<<<< HEAD
        virtual ~Prim() { }
=======
        virtual ~Prim() {}
>>>>>>> miniblink49
        virtual SkRect draw(SkCanvas*, const SkPaint&) = 0;
    };

    SkTArray<Prim*> fPrims;

    typedef GM INHERITED;
};

<<<<<<< HEAD
DEF_GM(return new DCShaderGM;)
=======
DEF_GM( return SkNEW(DCShaderGM); )
>>>>>>> miniblink49
}
#endif

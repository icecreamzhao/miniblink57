/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMorphologyImageFilter.h"
<<<<<<< HEAD

#include "SkBitmap.h"
#include "SkColorPriv.h"
#include "SkOpts.h"
#include "SkReadBuffer.h"
#include "SkRect.h"
#include "SkSpecialImage.h"
#include "SkWriteBuffer.h"

=======
#include "SkBitmap.h"
#include "SkColorPriv.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkRect.h"
#include "SkMorphology_opts.h"
>>>>>>> miniblink49
#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrDrawContext.h"
#include "GrInvariantOutput.h"
#include "GrTexture.h"
<<<<<<< HEAD
#include "SkGr.h"
#include "effects/Gr1DKernelEffect.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
#endif

sk_sp<SkImageFilter> SkDilateImageFilter::Make(int radiusX, int radiusY,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    if (radiusX < 0 || radiusY < 0) {
        return nullptr;
    }
    return sk_sp<SkImageFilter>(new SkDilateImageFilter(radiusX, radiusY,
        std::move(input),
        cropRect));
}

sk_sp<SkImageFilter> SkErodeImageFilter::Make(int radiusX, int radiusY,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
{
    if (radiusX < 0 || radiusY < 0) {
        return nullptr;
    }
    return sk_sp<SkImageFilter>(new SkErodeImageFilter(radiusX, radiusY,
        std::move(input),
        cropRect));
}

SkMorphologyImageFilter::SkMorphologyImageFilter(int radiusX,
    int radiusY,
    sk_sp<SkImageFilter> input,
    const CropRect* cropRect)
    : INHERITED(&input, 1, cropRect)
    , fRadius(SkISize::Make(radiusX, radiusY))
{
}

void SkMorphologyImageFilter::flatten(SkWriteBuffer& buffer) const
{
=======
#include "effects/Gr1DKernelEffect.h"
#include "gl/GrGLProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"
#endif

SkMorphologyImageFilter::SkMorphologyImageFilter(int radiusX,
                                                 int radiusY,
                                                 SkImageFilter* input,
                                                 const CropRect* cropRect)
    : INHERITED(1, &input, cropRect), fRadius(SkISize::Make(radiusX, radiusY)) {
}

void SkMorphologyImageFilter::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    buffer.writeInt(fRadius.fWidth);
    buffer.writeInt(fRadius.fHeight);
}

<<<<<<< HEAD
static void call_proc_X(SkMorphologyImageFilter::Proc procX,
    const SkBitmap& src, SkBitmap* dst,
    int radiusX, const SkIRect& bounds)
{
    procX(src.getAddr32(bounds.left(), bounds.top()), dst->getAddr32(0, 0),
        radiusX, bounds.width(), bounds.height(),
        src.rowBytesAsPixels(), dst->rowBytesAsPixels());
}

static void call_proc_Y(SkMorphologyImageFilter::Proc procY,
    const SkPMColor* src, int srcRowBytesAsPixels, SkBitmap* dst,
    int radiusY, const SkIRect& bounds)
{
    procY(src, dst->getAddr32(0, 0),
        radiusY, bounds.height(), bounds.width(),
        srcRowBytesAsPixels, dst->rowBytesAsPixels());
}

SkRect SkMorphologyImageFilter::computeFastBounds(const SkRect& src) const
{
    SkRect bounds = this->getInput(0) ? this->getInput(0)->computeFastBounds(src) : src;
    bounds.outset(SkIntToScalar(fRadius.width()), SkIntToScalar(fRadius.height()));
    return bounds;
}

SkIRect SkMorphologyImageFilter::onFilterNodeBounds(const SkIRect& src, const SkMatrix& ctm,
    MapDirection) const
{
    SkVector radius = SkVector::Make(SkIntToScalar(this->radius().width()),
        SkIntToScalar(this->radius().height()));
    ctm.mapVectors(&radius, 1);
    return src.makeOutset(SkScalarCeilToInt(radius.x()), SkScalarCeilToInt(radius.y()));
}

sk_sp<SkFlattenable> SkErodeImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    const int width = buffer.readInt();
    const int height = buffer.readInt();
    return Make(width, height, common.getInput(0), &common.cropRect());
}

sk_sp<SkFlattenable> SkDilateImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    const int width = buffer.readInt();
    const int height = buffer.readInt();
    return Make(width, height, common.getInput(0), &common.cropRect());
}

#ifndef SK_IGNORE_TO_STRING
void SkErodeImageFilter::toString(SkString* str) const
{
=======
enum MorphDirection {
    kX, kY
};

template<MorphDirection direction>
static void erode(const SkPMColor* src, SkPMColor* dst,
                  int radius, int width, int height,
                  int srcStride, int dstStride)
{
    const int srcStrideX = direction == kX ? 1 : srcStride;
    const int dstStrideX = direction == kX ? 1 : dstStride;
    const int srcStrideY = direction == kX ? srcStride : 1;
    const int dstStrideY = direction == kX ? dstStride : 1;
    radius = SkMin32(radius, width - 1);
    const SkPMColor* upperSrc = src + radius * srcStrideX;
    for (int x = 0; x < width; ++x) {
        const SkPMColor* lp = src;
        const SkPMColor* up = upperSrc;
        SkPMColor* dptr = dst;
        for (int y = 0; y < height; ++y) {
            int minB = 255, minG = 255, minR = 255, minA = 255;
            for (const SkPMColor* p = lp; p <= up; p += srcStrideX) {
                int b = SkGetPackedB32(*p);
                int g = SkGetPackedG32(*p);
                int r = SkGetPackedR32(*p);
                int a = SkGetPackedA32(*p);
                if (b < minB) minB = b;
                if (g < minG) minG = g;
                if (r < minR) minR = r;
                if (a < minA) minA = a;
            }
            *dptr = SkPackARGB32(minA, minR, minG, minB);
            dptr += dstStrideY;
            lp += srcStrideY;
            up += srcStrideY;
        }
        if (x >= radius) src += srcStrideX;
        if (x + radius < width - 1) upperSrc += srcStrideX;
        dst += dstStrideX;
    }
}

template<MorphDirection direction>
static void dilate(const SkPMColor* src, SkPMColor* dst,
                   int radius, int width, int height,
                   int srcStride, int dstStride)
{
    const int srcStrideX = direction == kX ? 1 : srcStride;
    const int dstStrideX = direction == kX ? 1 : dstStride;
    const int srcStrideY = direction == kX ? srcStride : 1;
    const int dstStrideY = direction == kX ? dstStride : 1;
    radius = SkMin32(radius, width - 1);
    const SkPMColor* upperSrc = src + radius * srcStrideX;
    for (int x = 0; x < width; ++x) {
        const SkPMColor* lp = src;
        const SkPMColor* up = upperSrc;
        SkPMColor* dptr = dst;
        for (int y = 0; y < height; ++y) {
            int maxB = 0, maxG = 0, maxR = 0, maxA = 0;
            for (const SkPMColor* p = lp; p <= up; p += srcStrideX) {
                int b = SkGetPackedB32(*p);
                int g = SkGetPackedG32(*p);
                int r = SkGetPackedR32(*p);
                int a = SkGetPackedA32(*p);
                if (b > maxB) maxB = b;
                if (g > maxG) maxG = g;
                if (r > maxR) maxR = r;
                if (a > maxA) maxA = a;
            }
            *dptr = SkPackARGB32(maxA, maxR, maxG, maxB);
            dptr += dstStrideY;
            lp += srcStrideY;
            up += srcStrideY;
        }
        if (x >= radius) src += srcStrideX;
        if (x + radius < width - 1) upperSrc += srcStrideX;
        dst += dstStrideX;
    }
}

static void callProcX(SkMorphologyImageFilter::Proc procX, const SkBitmap& src, SkBitmap* dst, int radiusX, const SkIRect& bounds)
{
    procX(src.getAddr32(bounds.left(), bounds.top()), dst->getAddr32(0, 0),
          radiusX, bounds.width(), bounds.height(),
          src.rowBytesAsPixels(), dst->rowBytesAsPixels());
}

static void callProcY(SkMorphologyImageFilter::Proc procY, const SkBitmap& src, SkBitmap* dst, int radiusY, const SkIRect& bounds)
{
    procY(src.getAddr32(bounds.left(), bounds.top()), dst->getAddr32(0, 0),
          radiusY, bounds.height(), bounds.width(),
          src.rowBytesAsPixels(), dst->rowBytesAsPixels());
}

bool SkMorphologyImageFilter::filterImageGeneric(SkMorphologyImageFilter::Proc procX,
                                                 SkMorphologyImageFilter::Proc procY,
                                                 Proxy* proxy,
                                                 const SkBitmap& source,
                                                 const Context& ctx,
                                                 SkBitmap* dst,
                                                 SkIPoint* offset) const {
    SkBitmap src = source;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (getInput(0) && !getInput(0)->filterImage(proxy, source, ctx, &src, &srcOffset)) {
        return false;
    }

    if (src.colorType() != kN32_SkColorType) {
        return false;
    }

    SkIRect bounds;
    if (!this->applyCropRect(ctx, proxy, src, &srcOffset, &bounds, &src)) {
        return false;
    }

    SkAutoLockPixels alp(src);
    if (!src.getPixels()) {
        return false;
    }

    if (!dst->tryAllocPixels(src.info().makeWH(bounds.width(), bounds.height()))) {
        return false;
    }

    SkVector radius = SkVector::Make(SkIntToScalar(this->radius().width()),
                                     SkIntToScalar(this->radius().height()));
    ctx.ctm().mapVectors(&radius, 1);
    int width = SkScalarFloorToInt(radius.fX);
    int height = SkScalarFloorToInt(radius.fY);

    if (width < 0 || height < 0) {
        return false;
    }

    SkIRect srcBounds = bounds;
    srcBounds.offset(-srcOffset);

    if (width == 0 && height == 0) {
        src.extractSubset(dst, srcBounds);
        offset->fX = bounds.left();
        offset->fY = bounds.top();
        return true;
    }

    SkBitmap temp;
    if (!temp.tryAllocPixels(dst->info())) {
        return false;
    }

    if (width > 0 && height > 0) {
        callProcX(procX, src, &temp, width, srcBounds);
        SkIRect tmpBounds = SkIRect::MakeWH(srcBounds.width(), srcBounds.height());
        callProcY(procY, temp, dst, height, tmpBounds);
    } else if (width > 0) {
        callProcX(procX, src, dst, width, srcBounds);
    } else if (height > 0) {
        callProcY(procY, src, dst, height, srcBounds);
    }
    offset->fX = bounds.left();
    offset->fY = bounds.top();
    return true;
}

bool SkErodeImageFilter::onFilterImage(Proxy* proxy,
                                       const SkBitmap& source, const Context& ctx,
                                       SkBitmap* dst, SkIPoint* offset) const {
    Proc erodeXProc = SkMorphologyGetPlatformProc(kErodeX_SkMorphologyProcType);
    if (!erodeXProc) {
        erodeXProc = erode<kX>;
    }
    Proc erodeYProc = SkMorphologyGetPlatformProc(kErodeY_SkMorphologyProcType);
    if (!erodeYProc) {
        erodeYProc = erode<kY>;
    }
    return this->filterImageGeneric(erodeXProc, erodeYProc, proxy, source, ctx, dst, offset);
}

bool SkDilateImageFilter::onFilterImage(Proxy* proxy,
                                        const SkBitmap& source, const Context& ctx,
                                        SkBitmap* dst, SkIPoint* offset) const {
    Proc dilateXProc = SkMorphologyGetPlatformProc(kDilateX_SkMorphologyProcType);
    if (!dilateXProc) {
        dilateXProc = dilate<kX>;
    }
    Proc dilateYProc = SkMorphologyGetPlatformProc(kDilateY_SkMorphologyProcType);
    if (!dilateYProc) {
        dilateYProc = dilate<kY>;
    }
    return this->filterImageGeneric(dilateXProc, dilateYProc, proxy, source, ctx, dst, offset);
}

void SkMorphologyImageFilter::computeFastBounds(const SkRect& src, SkRect* dst) const {
    if (getInput(0)) {
        getInput(0)->computeFastBounds(src, dst);
    } else {
        *dst = src;
    }
    dst->outset(SkIntToScalar(fRadius.width()), SkIntToScalar(fRadius.height()));
}

bool SkMorphologyImageFilter::onFilterBounds(const SkIRect& src, const SkMatrix& ctm,
                                             SkIRect* dst) const {
    SkIRect bounds = src;
    SkVector radius = SkVector::Make(SkIntToScalar(this->radius().width()),
                                     SkIntToScalar(this->radius().height()));
    ctm.mapVectors(&radius, 1);
    bounds.outset(SkScalarCeilToInt(radius.x()), SkScalarCeilToInt(radius.y()));
    if (getInput(0) && !getInput(0)->filterBounds(bounds, ctm, &bounds)) {
        return false;
    }
    *dst = bounds;
    return true;
}

SkFlattenable* SkErodeImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    const int width = buffer.readInt();
    const int height = buffer.readInt();
    return Create(width, height, common.getInput(0), &common.cropRect());
}

SkFlattenable* SkDilateImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    const int width = buffer.readInt();
    const int height = buffer.readInt();
    return Create(width, height, common.getInput(0), &common.cropRect());
}

#ifndef SK_IGNORE_TO_STRING
void SkErodeImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkErodeImageFilter: (");
    str->appendf("radius: (%d,%d)", this->radius().fWidth, this->radius().fHeight);
    str->append(")");
}
#endif

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkDilateImageFilter::toString(SkString* str) const
{
=======
void SkDilateImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkDilateImageFilter: (");
    str->appendf("radius: (%d,%d)", this->radius().fWidth, this->radius().fHeight);
    str->append(")");
}
#endif

#if SK_SUPPORT_GPU

///////////////////////////////////////////////////////////////////////////////
/**
 * Morphology effects. Depending upon the type of morphology, either the
 * component-wise min (Erode_Type) or max (Dilate_Type) of all pixels in the
 * kernel is selected as the new color. The new color is modulated by the input
 * color.
 */
class GrMorphologyEffect : public Gr1DKernelEffect {

public:
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    enum MorphologyType {
        kErode_MorphologyType,
        kDilate_MorphologyType,
    };

<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* tex, Direction dir, int radius,
        MorphologyType type)
    {
        return sk_sp<GrFragmentProcessor>(new GrMorphologyEffect(tex, dir, radius, type));
    }

    static sk_sp<GrFragmentProcessor> Make(GrTexture* tex, Direction dir, int radius,
        MorphologyType type, float bounds[2])
    {
        return sk_sp<GrFragmentProcessor>(new GrMorphologyEffect(tex, dir, radius, type, bounds));
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager, GrTexture* tex,
                                       Direction dir, int radius, MorphologyType type) {
        return SkNEW_ARGS(GrMorphologyEffect, (procDataManager, tex, dir, radius, type));
    }

    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager, GrTexture* tex,
                                       Direction dir, int radius, MorphologyType type,
                                       float bounds[2]) {
        return SkNEW_ARGS(GrMorphologyEffect, (procDataManager, tex, dir, radius, type, bounds));
>>>>>>> miniblink49
    }

    virtual ~GrMorphologyEffect();

    MorphologyType type() const { return fType; }
    bool useRange() const { return fUseRange; }
    const float* range() const { return fRange; }

    const char* name() const override { return "Morphology"; }

<<<<<<< HEAD
protected:
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

protected:

>>>>>>> miniblink49
    MorphologyType fType;
    bool fUseRange;
    float fRange[2];

private:
<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

=======
>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

<<<<<<< HEAD
    GrMorphologyEffect(GrTexture*, Direction, int radius, MorphologyType);
    GrMorphologyEffect(GrTexture*, Direction, int radius, MorphologyType,
        float bounds[2]);
=======
    GrMorphologyEffect(GrProcessorDataManager*, GrTexture*, Direction, int radius, MorphologyType);
    GrMorphologyEffect(GrProcessorDataManager*, GrTexture*, Direction, int radius, MorphologyType,
                       float bounds[2]);
>>>>>>> miniblink49

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    typedef Gr1DKernelEffect INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLMorphologyEffect : public GrGLSLFragmentProcessor {
public:
    void emitCode(EmitArgs&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*);

protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

private:
    GrGLSLProgramDataManager::UniformHandle fPixelSizeUni;
    GrGLSLProgramDataManager::UniformHandle fRangeUni;

    typedef GrGLSLFragmentProcessor INHERITED;
};

void GrGLMorphologyEffect::emitCode(EmitArgs& args)
{
    const GrMorphologyEffect& me = args.fFp.cast<GrMorphologyEffect>();

    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    fPixelSizeUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "PixelSize");
    const char* pixelSizeInc = uniformHandler->getUniformCStr(fPixelSizeUni);
    fRangeUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec2f_GrSLType, kDefault_GrSLPrecision,
        "Range");
    const char* range = uniformHandler->getUniformCStr(fRangeUni);

    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    SkString coords2D = fragBuilder->ensureFSCoords2D(args.fCoords, 0);
    const char* func;
    switch (me.type()) {
    case GrMorphologyEffect::kErode_MorphologyType:
        fragBuilder->codeAppendf("\t\t%s = vec4(1, 1, 1, 1);\n", args.fOutputColor);
        func = "min";
        break;
    case GrMorphologyEffect::kDilate_MorphologyType:
        fragBuilder->codeAppendf("\t\t%s = vec4(0, 0, 0, 0);\n", args.fOutputColor);
        func = "max";
        break;
    default:
        SkFAIL("Unexpected type");
        func = ""; // suppress warning
        break;
    }

    const char* dir;
    switch (me.direction()) {
    case Gr1DKernelEffect::kX_Direction:
        dir = "x";
        break;
    case Gr1DKernelEffect::kY_Direction:
        dir = "y";
        break;
    default:
        SkFAIL("Unknown filter direction.");
        dir = ""; // suppress warning
    }

    int width = GrMorphologyEffect::WidthFromRadius(me.radius());

    // vec2 coord = coord2D;
    fragBuilder->codeAppendf("\t\tvec2 coord = %s;\n", coords2D.c_str());
    // coord.x -= radius * pixelSize;
    fragBuilder->codeAppendf("\t\tcoord.%s -= %d.0 * %s; \n", dir, me.radius(), pixelSizeInc);
    if (me.useRange()) {
        // highBound = min(highBound, coord.x + (width-1) * pixelSize);
        fragBuilder->codeAppendf("\t\tfloat highBound = min(%s.y, coord.%s + %f * %s);",
            range, dir, float(width - 1), pixelSizeInc);
        // coord.x = max(lowBound, coord.x);
        fragBuilder->codeAppendf("\t\tcoord.%s = max(%s.x, coord.%s);", dir, range, dir);
    }
    fragBuilder->codeAppendf("\t\tfor (int i = 0; i < %d; i++) {\n", width);
    fragBuilder->codeAppendf("\t\t\t%s = %s(%s, ", args.fOutputColor, func, args.fOutputColor);
    fragBuilder->appendTextureLookup(args.fTexSamplers[0], "coord");
    fragBuilder->codeAppend(");\n");
    // coord.x += pixelSize;
    fragBuilder->codeAppendf("\t\t\tcoord.%s += %s;\n", dir, pixelSizeInc);
    if (me.useRange()) {
        // coord.x = min(highBound, coord.x);
        fragBuilder->codeAppendf("\t\t\tcoord.%s = min(highBound, coord.%s);", dir, dir);
    }
    fragBuilder->codeAppend("\t\t}\n");
    SkString modulate;
    GrGLSLMulVarBy4f(&modulate, args.fOutputColor, args.fInputColor);
    fragBuilder->codeAppend(modulate.c_str());
}

void GrGLMorphologyEffect::GenKey(const GrProcessor& proc,
    const GrGLSLCaps&, GrProcessorKeyBuilder* b)
{
=======
class GrGLMorphologyEffect : public GrGLFragmentProcessor {
public:
    GrGLMorphologyEffect(const GrProcessor&);

    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder* b);

    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

private:
    int width() const { return GrMorphologyEffect::WidthFromRadius(fRadius); }

    int                                   fRadius;
    Gr1DKernelEffect::Direction           fDirection;
    bool                                  fUseRange;
    GrMorphologyEffect::MorphologyType    fType;
    GrGLProgramDataManager::UniformHandle fPixelSizeUni;
    GrGLProgramDataManager::UniformHandle fRangeUni;

    typedef GrGLFragmentProcessor INHERITED;
};

GrGLMorphologyEffect::GrGLMorphologyEffect(const GrProcessor& proc) {
    const GrMorphologyEffect& m = proc.cast<GrMorphologyEffect>();
    fRadius = m.radius();
    fDirection = m.direction();
    fUseRange = m.useRange();
    fType = m.type();
}

void GrGLMorphologyEffect::emitCode(GrGLFPBuilder* builder,
                                    const GrFragmentProcessor&,
                                    const char* outputColor,
                                    const char* inputColor,
                                    const TransformedCoordsArray& coords,
                                    const TextureSamplerArray& samplers) {
    fPixelSizeUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                            kFloat_GrSLType, kDefault_GrSLPrecision,
                                            "PixelSize");
    const char* pixelSizeInc = builder->getUniformCStr(fPixelSizeUni);
    fRangeUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                            kVec2f_GrSLType, kDefault_GrSLPrecision,
                                            "Range");
    const char* range = builder->getUniformCStr(fRangeUni);

    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    SkString coords2D = fsBuilder->ensureFSCoords2D(coords, 0);
    const char* func;
    switch (fType) {
        case GrMorphologyEffect::kErode_MorphologyType:
            fsBuilder->codeAppendf("\t\t%s = vec4(1, 1, 1, 1);\n", outputColor);
            func = "min";
            break;
        case GrMorphologyEffect::kDilate_MorphologyType:
            fsBuilder->codeAppendf("\t\t%s = vec4(0, 0, 0, 0);\n", outputColor);
            func = "max";
            break;
        default:
            SkFAIL("Unexpected type");
            func = ""; // suppress warning
            break;
    }

    const char* dir;
    switch (fDirection) {
        case Gr1DKernelEffect::kX_Direction:
            dir = "x";
            break;
        case Gr1DKernelEffect::kY_Direction:
            dir = "y";
            break;
        default:
            SkFAIL("Unknown filter direction.");
            dir = ""; // suppress warning
    }

    // vec2 coord = coord2D;
    fsBuilder->codeAppendf("\t\tvec2 coord = %s;\n", coords2D.c_str());
    // coord.x -= radius * pixelSize;
    fsBuilder->codeAppendf("\t\tcoord.%s -= %d.0 * %s; \n", dir, fRadius, pixelSizeInc);
    if (fUseRange) {
        // highBound = min(highBound, coord.x + (width-1) * pixelSize);
        fsBuilder->codeAppendf("\t\tfloat highBound = min(%s.y, coord.%s + %f * %s);",
                               range, dir, float(width() - 1), pixelSizeInc);
        // coord.x = max(lowBound, coord.x);
        fsBuilder->codeAppendf("\t\tcoord.%s = max(%s.x, coord.%s);", dir, range, dir);
    }
    fsBuilder->codeAppendf("\t\tfor (int i = 0; i < %d; i++) {\n", width());
    fsBuilder->codeAppendf("\t\t\t%s = %s(%s, ", outputColor, func, outputColor);
    fsBuilder->appendTextureLookup(samplers[0], "coord");
    fsBuilder->codeAppend(");\n");
    // coord.x += pixelSize;
    fsBuilder->codeAppendf("\t\t\tcoord.%s += %s;\n", dir, pixelSizeInc);
    if (fUseRange) {
        // coord.x = min(highBound, coord.x);
        fsBuilder->codeAppendf("\t\t\tcoord.%s = min(highBound, coord.%s);", dir, dir);
    }
    fsBuilder->codeAppend("\t\t}\n");
    SkString modulate;
    GrGLSLMulVarBy4f(&modulate, outputColor, inputColor);
    fsBuilder->codeAppend(modulate.c_str());
}

void GrGLMorphologyEffect::GenKey(const GrProcessor& proc,
                                  const GrGLSLCaps&, GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    const GrMorphologyEffect& m = proc.cast<GrMorphologyEffect>();
    uint32_t key = static_cast<uint32_t>(m.radius());
    key |= (m.type() << 8);
    key |= (m.direction() << 9);
<<<<<<< HEAD
    if (m.useRange()) {
        key |= 1 << 10;
    }
    b->add32(key);
}

void GrGLMorphologyEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& proc)
{
    const GrMorphologyEffect& m = proc.cast<GrMorphologyEffect>();
    GrTexture& texture = *m.texture(0);

    float pixelSize = 0.0f;
    switch (m.direction()) {
    case Gr1DKernelEffect::kX_Direction:
        pixelSize = 1.0f / texture.width();
        break;
    case Gr1DKernelEffect::kY_Direction:
        pixelSize = 1.0f / texture.height();
        break;
    default:
        SkFAIL("Unknown filter direction.");
    }
    pdman.set1f(fPixelSizeUni, pixelSize);

    if (m.useRange()) {
        const float* range = m.range();
        if (m.direction() && texture.origin() == kBottomLeft_GrSurfaceOrigin) {
=======
    if (m.useRange()) key |= 1 << 10;
    b->add32(key);
}

void GrGLMorphologyEffect::setData(const GrGLProgramDataManager& pdman,
                                   const GrProcessor& proc) {
    const GrMorphologyEffect& m = proc.cast<GrMorphologyEffect>();
    GrTexture& texture = *m.texture(0);
    // the code we generated was for a specific kernel radius, direction and bound usage
    SkASSERT(m.radius() == fRadius);
    SkASSERT(m.direction() == fDirection);
    SkASSERT(m.useRange() == fUseRange);

    float pixelSize = 0.0f;
    switch (fDirection) {
        case Gr1DKernelEffect::kX_Direction:
            pixelSize = 1.0f / texture.width();
            break;
        case Gr1DKernelEffect::kY_Direction:
            pixelSize = 1.0f / texture.height();
            break;
        default:
            SkFAIL("Unknown filter direction.");
    }
    pdman.set1f(fPixelSizeUni, pixelSize);

    if (fUseRange) {
        const float* range = m.range();
        if (fDirection && texture.origin() == kBottomLeft_GrSurfaceOrigin) {
>>>>>>> miniblink49
            pdman.set2f(fRangeUni, 1.0f - range[1], 1.0f - range[0]);
        } else {
            pdman.set2f(fRangeUni, range[0], range[1]);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrMorphologyEffect::GrMorphologyEffect(GrTexture* texture,
    Direction direction,
    int radius,
    MorphologyType type)
    : INHERITED(texture, direction, radius)
    , fType(type)
    , fUseRange(false)
{
    this->initClassID<GrMorphologyEffect>();
}

GrMorphologyEffect::GrMorphologyEffect(GrTexture* texture,
    Direction direction,
    int radius,
    MorphologyType type,
    float range[2])
    : INHERITED(texture, direction, radius)
    , fType(type)
    , fUseRange(true)
{
=======
GrMorphologyEffect::GrMorphologyEffect(GrProcessorDataManager* procDataManager,
                                       GrTexture* texture,
                                       Direction direction,
                                       int radius,
                                       MorphologyType type)
    : INHERITED(procDataManager, texture, direction, radius)
    , fType(type), fUseRange(false) {
    this->initClassID<GrMorphologyEffect>();
}

GrMorphologyEffect::GrMorphologyEffect(GrProcessorDataManager* procDataManager,
                                       GrTexture* texture,
                                       Direction direction,
                                       int radius,
                                       MorphologyType type,
                                       float range[2])
    : INHERITED(procDataManager, texture, direction, radius)
    , fType(type), fUseRange(true) {
>>>>>>> miniblink49
    this->initClassID<GrMorphologyEffect>();
    fRange[0] = range[0];
    fRange[1] = range[1];
}

<<<<<<< HEAD
GrMorphologyEffect::~GrMorphologyEffect()
{
}

void GrMorphologyEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLMorphologyEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrMorphologyEffect::onCreateGLSLInstance() const
{
    return new GrGLMorphologyEffect;
}
bool GrMorphologyEffect::onIsEqual(const GrFragmentProcessor& sBase) const
{
    const GrMorphologyEffect& s = sBase.cast<GrMorphologyEffect>();
    return (this->radius() == s.radius() && this->direction() == s.direction() && this->useRange() == s.useRange() && this->type() == s.type());
}

void GrMorphologyEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
GrMorphologyEffect::~GrMorphologyEffect() {
}

void GrMorphologyEffect::getGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const {
    GrGLMorphologyEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrMorphologyEffect::createGLInstance() const {
    return SkNEW_ARGS(GrGLMorphologyEffect, (*this));
}
bool GrMorphologyEffect::onIsEqual(const GrFragmentProcessor& sBase) const {
    const GrMorphologyEffect& s = sBase.cast<GrMorphologyEffect>();
    return (this->radius() == s.radius() &&
            this->direction() == s.direction() &&
            this->useRange() == s.useRange() &&
            this->type() == s.type());
}

void GrMorphologyEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    // This is valid because the color components of the result of the kernel all come
    // exactly from existing values in the source texture.
    this->updateInvariantOutputForModulation(inout);
}

///////////////////////////////////////////////////////////////////////////////

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrMorphologyEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrMorphologyEffect::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
    Direction dir = d->fRandom->nextBool() ? kX_Direction : kY_Direction;
    static const int kMaxRadius = 10;
    int radius = d->fRandom->nextRangeU(1, kMaxRadius);
    MorphologyType type = d->fRandom->nextBool() ? GrMorphologyEffect::kErode_MorphologyType : GrMorphologyEffect::kDilate_MorphologyType;

    return GrMorphologyEffect::Make(d->fTextures[texIdx], dir, radius, type);
}

static void apply_morphology_rect(GrDrawContext* drawContext,
    const GrClip& clip,
    GrTexture* texture,
    const SkIRect& srcRect,
    const SkIRect& dstRect,
    int radius,
    GrMorphologyEffect::MorphologyType morphType,
    float bounds[2],
    Gr1DKernelEffect::Direction direction)
{
    GrPaint paint;
    // SRGBTODO: AllowSRGBInputs?
    paint.addColorFragmentProcessor(GrMorphologyEffect::Make(texture,
        direction,
        radius,
        morphType,
        bounds));
    paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
    drawContext->fillRectToRect(clip, paint, SkMatrix::I(), SkRect::Make(dstRect),
        SkRect::Make(srcRect));
}

static void apply_morphology_rect_no_bounds(GrDrawContext* drawContext,
    const GrClip& clip,
    GrTexture* texture,
    const SkIRect& srcRect,
    const SkIRect& dstRect,
    int radius,
    GrMorphologyEffect::MorphologyType morphType,
    Gr1DKernelEffect::Direction direction)
{
    GrPaint paint;
    // SRGBTODO: AllowSRGBInputs?
    paint.addColorFragmentProcessor(GrMorphologyEffect::Make(texture, direction, radius,
        morphType));
    paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
    drawContext->fillRectToRect(clip, paint, SkMatrix::I(), SkRect::Make(dstRect),
        SkRect::Make(srcRect));
}

static void apply_morphology_pass(GrDrawContext* drawContext,
    const GrClip& clip,
    GrTexture* texture,
    const SkIRect& srcRect,
    const SkIRect& dstRect,
    int radius,
    GrMorphologyEffect::MorphologyType morphType,
    Gr1DKernelEffect::Direction direction)
{
=======
GrFragmentProcessor* GrMorphologyEffect::TestCreate(GrProcessorTestData* d) {
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx :
                                      GrProcessorUnitTest::kAlphaTextureIdx;
    Direction dir = d->fRandom->nextBool() ? kX_Direction : kY_Direction;
    static const int kMaxRadius = 10;
    int radius = d->fRandom->nextRangeU(1, kMaxRadius);
    MorphologyType type = d->fRandom->nextBool() ? GrMorphologyEffect::kErode_MorphologyType :
                                               GrMorphologyEffect::kDilate_MorphologyType;

    return GrMorphologyEffect::Create(d->fProcDataManager, d->fTextures[texIdx], dir, radius, type);
}

namespace {


void apply_morphology_rect(GrDrawContext* drawContext,
                           GrRenderTarget* rt,
                           const GrClip& clip,
                           GrTexture* texture,
                           const SkIRect& srcRect,
                           const SkIRect& dstRect,
                           int radius,
                           GrMorphologyEffect::MorphologyType morphType,
                           float bounds[2],
                           Gr1DKernelEffect::Direction direction) {
    GrPaint paint;
    paint.addColorProcessor(GrMorphologyEffect::Create(paint.getProcessorDataManager(),
                                                       texture,
                                                       direction,
                                                       radius,
                                                       morphType,
                                                       bounds))->unref();
    drawContext->drawNonAARectToRect(rt, clip, paint, SkMatrix::I(), SkRect::Make(dstRect),
                                     SkRect::Make(srcRect));
}

void apply_morphology_rect_no_bounds(GrDrawContext* drawContext,
                                     GrRenderTarget* rt,
                                     const GrClip& clip,
                                     GrTexture* texture,
                                     const SkIRect& srcRect,
                                     const SkIRect& dstRect,
                                     int radius,
                                     GrMorphologyEffect::MorphologyType morphType,
                                     Gr1DKernelEffect::Direction direction) {
    GrPaint paint;
    paint.addColorProcessor(GrMorphologyEffect::Create(paint.getProcessorDataManager(),
                                                       texture,
                                                       direction,
                                                       radius,
                                                       morphType))->unref();
    drawContext->drawNonAARectToRect(rt, clip, paint, SkMatrix::I(), SkRect::Make(dstRect),
                                     SkRect::Make(srcRect));
}

void apply_morphology_pass(GrDrawContext* drawContext,
                           GrRenderTarget* rt,
                           const GrClip& clip,
                           GrTexture* texture,
                           const SkIRect& srcRect,
                           const SkIRect& dstRect,
                           int radius,
                           GrMorphologyEffect::MorphologyType morphType,
                           Gr1DKernelEffect::Direction direction) {
>>>>>>> miniblink49
    float bounds[2] = { 0.0f, 1.0f };
    SkIRect lowerSrcRect = srcRect, lowerDstRect = dstRect;
    SkIRect middleSrcRect = srcRect, middleDstRect = dstRect;
    SkIRect upperSrcRect = srcRect, upperDstRect = dstRect;
    if (direction == Gr1DKernelEffect::kX_Direction) {
        bounds[0] = (SkIntToScalar(srcRect.left()) + 0.5f) / texture->width();
        bounds[1] = (SkIntToScalar(srcRect.right()) - 0.5f) / texture->width();
        lowerSrcRect.fRight = srcRect.left() + radius;
        lowerDstRect.fRight = dstRect.left() + radius;
        upperSrcRect.fLeft = srcRect.right() - radius;
        upperDstRect.fLeft = dstRect.right() - radius;
        middleSrcRect.inset(radius, 0);
        middleDstRect.inset(radius, 0);
    } else {
        bounds[0] = (SkIntToScalar(srcRect.top()) + 0.5f) / texture->height();
        bounds[1] = (SkIntToScalar(srcRect.bottom()) - 0.5f) / texture->height();
        lowerSrcRect.fBottom = srcRect.top() + radius;
        lowerDstRect.fBottom = dstRect.top() + radius;
        upperSrcRect.fTop = srcRect.bottom() - radius;
        upperDstRect.fTop = dstRect.bottom() - radius;
        middleSrcRect.inset(0, radius);
        middleDstRect.inset(0, radius);
    }
    if (middleSrcRect.fLeft - middleSrcRect.fRight >= 0) {
        // radius covers srcRect; use bounds over entire draw
<<<<<<< HEAD
        apply_morphology_rect(drawContext, clip, texture, srcRect, dstRect, radius,
            morphType, bounds, direction);
    } else {
        // Draw upper and lower margins with bounds; middle without.
        apply_morphology_rect(drawContext, clip, texture, lowerSrcRect, lowerDstRect, radius,
            morphType, bounds, direction);
        apply_morphology_rect(drawContext, clip, texture, upperSrcRect, upperDstRect, radius,
            morphType, bounds, direction);
        apply_morphology_rect_no_bounds(drawContext, clip, texture, middleSrcRect, middleDstRect,
            radius, morphType, direction);
    }
}

static sk_sp<SkSpecialImage> apply_morphology(GrContext* context,
    SkSpecialImage* input,
    const SkIRect& rect,
    GrMorphologyEffect::MorphologyType morphType,
    SkISize radius)
{
    sk_sp<GrTexture> srcTexture(input->asTextureRef(context));
    SkASSERT(srcTexture);

    // setup new clip
    const GrFixedClip clip(SkIRect::MakeWH(srcTexture->width(), srcTexture->height()));

    const SkIRect dstRect = SkIRect::MakeWH(rect.width(), rect.height());
    SkIRect srcRect = rect;

    SkASSERT(radius.width() > 0 || radius.height() > 0);

    if (radius.fWidth > 0) {
        sk_sp<GrDrawContext> dstDrawContext(context->newDrawContext(SkBackingFit::kApprox,
            rect.width(), rect.height(),
            kSkia8888_GrPixelConfig));
        if (!dstDrawContext) {
            return nullptr;
        }

        apply_morphology_pass(dstDrawContext.get(), clip, srcTexture.get(),
            srcRect, dstRect, radius.fWidth, morphType,
            Gr1DKernelEffect::kX_Direction);
        SkIRect clearRect = SkIRect::MakeXYWH(dstRect.fLeft, dstRect.fBottom,
            dstRect.width(), radius.fHeight);
        GrColor clearColor = GrMorphologyEffect::kErode_MorphologyType == morphType
            ? SK_ColorWHITE
            : SK_ColorTRANSPARENT;
        dstDrawContext->clear(&clearRect, clearColor, false);

        srcTexture = dstDrawContext->asTexture();
        srcRect = dstRect;
    }
    if (radius.fHeight > 0) {
        sk_sp<GrDrawContext> dstDrawContext(context->newDrawContext(SkBackingFit::kApprox,
            rect.width(), rect.height(),
            kSkia8888_GrPixelConfig));
        if (!dstDrawContext) {
            return nullptr;
        }

        apply_morphology_pass(dstDrawContext.get(), clip, srcTexture.get(),
            srcRect, dstRect, radius.fHeight, morphType,
            Gr1DKernelEffect::kY_Direction);

        srcTexture = dstDrawContext->asTexture();
    }

    return SkSpecialImage::MakeFromGpu(SkIRect::MakeWH(rect.width(), rect.height()),
        kNeedNewImageUniqueID_SpecialImage,
        std::move(srcTexture), &input->props());
}
#endif

sk_sp<SkSpecialImage> SkMorphologyImageFilter::onFilterImage(SkSpecialImage* source,
    const Context& ctx,
    SkIPoint* offset) const
{
    SkIPoint inputOffset = SkIPoint::Make(0, 0);
    sk_sp<SkSpecialImage> input(this->filterInput(0, source, ctx, &inputOffset));
    if (!input) {
        return nullptr;
    }

    SkIRect bounds;
    input = this->applyCropRect(this->mapContext(ctx), input.get(), &inputOffset, &bounds);
    if (!input) {
        return nullptr;
    }

    SkVector radius = SkVector::Make(SkIntToScalar(this->radius().width()),
        SkIntToScalar(this->radius().height()));
=======
        apply_morphology_rect(drawContext, rt, clip, texture, srcRect, dstRect, radius,
                              morphType, bounds, direction);
    } else {
        // Draw upper and lower margins with bounds; middle without.
        apply_morphology_rect(drawContext, rt, clip, texture, lowerSrcRect, lowerDstRect, radius,
                              morphType, bounds, direction);
        apply_morphology_rect(drawContext, rt, clip, texture, upperSrcRect, upperDstRect, radius,
                              morphType, bounds, direction);
        apply_morphology_rect_no_bounds(drawContext, rt, clip, texture, middleSrcRect, middleDstRect,
                                        radius, morphType, direction);
    }
}

bool apply_morphology(const SkBitmap& input,
                      const SkIRect& rect,
                      GrMorphologyEffect::MorphologyType morphType,
                      SkISize radius,
                      SkBitmap* dst) {
    SkAutoTUnref<GrTexture> srcTexture(SkRef(input.getTexture()));
    SkASSERT(srcTexture);
    GrContext* context = srcTexture->getContext();

    // setup new clip
    GrClip clip(SkRect::MakeWH(SkIntToScalar(srcTexture->width()),
                               SkIntToScalar(srcTexture->height())));

    SkIRect dstRect = SkIRect::MakeWH(rect.width(), rect.height());
    GrSurfaceDesc desc;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fWidth = rect.width();
    desc.fHeight = rect.height();
    desc.fConfig = kSkia8888_GrPixelConfig;
    SkIRect srcRect = rect;

    GrDrawContext* drawContext = context->drawContext();
    if (!drawContext) {
        return false;
    }

    if (radius.fWidth > 0) {
        GrTexture* texture = context->textureProvider()->refScratchTexture(
            desc, GrTextureProvider::kApprox_ScratchTexMatch);
        if (NULL == texture) {
            return false;
        }
        apply_morphology_pass(drawContext, texture->asRenderTarget(), clip, srcTexture,
                              srcRect, dstRect, radius.fWidth, morphType,
                              Gr1DKernelEffect::kX_Direction);
        SkIRect clearRect = SkIRect::MakeXYWH(dstRect.fLeft, dstRect.fBottom,
                                              dstRect.width(), radius.fHeight);
        GrColor clearColor = GrMorphologyEffect::kErode_MorphologyType == morphType ?
                                SK_ColorWHITE :
                                SK_ColorTRANSPARENT;
        drawContext->clear(texture->asRenderTarget(), &clearRect, clearColor, false);
        srcTexture.reset(texture);
        srcRect = dstRect;
    }
    if (radius.fHeight > 0) {
        GrTexture* texture = context->textureProvider()->refScratchTexture(desc,
            GrTextureProvider::kApprox_ScratchTexMatch);
        if (NULL == texture) {
            return false;
        }
        apply_morphology_pass(drawContext, texture->asRenderTarget(), clip, srcTexture,
                              srcRect, dstRect, radius.fHeight, morphType,
                              Gr1DKernelEffect::kY_Direction);
        srcTexture.reset(texture);
    }
    SkImageFilter::WrapTexture(srcTexture, rect.width(), rect.height(), dst);
    return true;
}

};

bool SkMorphologyImageFilter::filterImageGPUGeneric(bool dilate,
                                                    Proxy* proxy,
                                                    const SkBitmap& src,
                                                    const Context& ctx,
                                                    SkBitmap* result,
                                                    SkIPoint* offset) const {
    SkBitmap input = src;
    SkIPoint srcOffset = SkIPoint::Make(0, 0);
    if (getInput(0) && !getInput(0)->getInputResultGPU(proxy, src, ctx, &input, &srcOffset)) {
        return false;
    }
    SkIRect bounds;
    if (!this->applyCropRect(ctx, proxy, input, &srcOffset, &bounds, &input)) {
        return false;
    }
    SkVector radius = SkVector::Make(SkIntToScalar(this->radius().width()),
                                     SkIntToScalar(this->radius().height()));
>>>>>>> miniblink49
    ctx.ctm().mapVectors(&radius, 1);
    int width = SkScalarFloorToInt(radius.fX);
    int height = SkScalarFloorToInt(radius.fY);

    if (width < 0 || height < 0) {
<<<<<<< HEAD
        return nullptr;
    }

    SkIRect srcBounds = bounds;
    srcBounds.offset(-inputOffset);

    if (0 == width && 0 == height) {
        offset->fX = bounds.left();
        offset->fY = bounds.top();
        return input->makeSubset(srcBounds);
    }

#if SK_SUPPORT_GPU
    if (source->isTextureBacked()) {
        GrContext* context = source->getContext();

        auto type = (kDilate_Op == this->op()) ? GrMorphologyEffect::kDilate_MorphologyType
                                               : GrMorphologyEffect::kErode_MorphologyType;
        sk_sp<SkSpecialImage> result(apply_morphology(context, input.get(), srcBounds, type,
            SkISize::Make(width, height)));
        if (result) {
            offset->fX = bounds.left();
            offset->fY = bounds.top();
        }
        return result;
    }
#endif

    SkBitmap inputBM;

    if (!input->getROPixels(&inputBM)) {
        return nullptr;
    }

    if (inputBM.colorType() != kN32_SkColorType) {
        return nullptr;
    }

    SkImageInfo info = SkImageInfo::Make(bounds.width(), bounds.height(),
        inputBM.colorType(), inputBM.alphaType());

    SkBitmap dst;
    if (!dst.tryAllocPixels(info)) {
        return nullptr;
    }

    SkAutoLockPixels inputLock(inputBM), dstLock(dst);

    SkMorphologyImageFilter::Proc procX, procY;

    if (kDilate_Op == this->op()) {
        procX = SkOpts::dilate_x;
        procY = SkOpts::dilate_y;
    } else {
        procX = SkOpts::erode_x;
        procY = SkOpts::erode_y;
    }

    if (width > 0 && height > 0) {
        SkBitmap tmp;
        if (!tmp.tryAllocPixels(info)) {
            return nullptr;
        }

        SkAutoLockPixels tmpLock(tmp);

        call_proc_X(procX, inputBM, &tmp, width, srcBounds);
        SkIRect tmpBounds = SkIRect::MakeWH(srcBounds.width(), srcBounds.height());
        call_proc_Y(procY,
            tmp.getAddr32(tmpBounds.left(), tmpBounds.top()), tmp.rowBytesAsPixels(),
            &dst, height, tmpBounds);
    } else if (width > 0) {
        call_proc_X(procX, inputBM, &dst, width, srcBounds);
    } else if (height > 0) {
        call_proc_Y(procY,
            inputBM.getAddr32(srcBounds.left(), srcBounds.top()),
            inputBM.rowBytesAsPixels(),
            &dst, height, srcBounds);
    }
    offset->fX = bounds.left();
    offset->fY = bounds.top();

    return SkSpecialImage::MakeFromRaster(SkIRect::MakeWH(bounds.width(), bounds.height()),
        dst, &source->props());
}
=======
        return false;
    }

    SkIRect srcBounds = bounds;
    srcBounds.offset(-srcOffset);
    if (width == 0 && height == 0) {
        input.extractSubset(result, srcBounds);
        offset->fX = bounds.left();
        offset->fY = bounds.top();
        return true;
    }

    GrMorphologyEffect::MorphologyType type = dilate ? GrMorphologyEffect::kDilate_MorphologyType : GrMorphologyEffect::kErode_MorphologyType;
    if (!apply_morphology(input, srcBounds, type,
                          SkISize::Make(width, height), result)) {
        return false;
    }
    offset->fX = bounds.left();
    offset->fY = bounds.top();
    return true;
}

bool SkDilateImageFilter::filterImageGPU(Proxy* proxy, const SkBitmap& src, const Context& ctx,
                                         SkBitmap* result, SkIPoint* offset) const {
    return this->filterImageGPUGeneric(true, proxy, src, ctx, result, offset);
}

bool SkErodeImageFilter::filterImageGPU(Proxy* proxy, const SkBitmap& src, const Context& ctx,
                                        SkBitmap* result, SkIPoint* offset) const {
    return this->filterImageGPUGeneric(false, proxy, src, ctx, result, offset);
}

#endif
>>>>>>> miniblink49
